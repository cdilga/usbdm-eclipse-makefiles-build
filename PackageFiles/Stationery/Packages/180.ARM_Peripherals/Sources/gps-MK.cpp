/*
 *  gps.c (derived from gps-mk.cpp)
 *
 *  Created on: 29/11/2015
 *      Author: pgo
 */

#include <string.h>
#include <stdio.h>

#include "derivative.h"
#include "system.h"
#include "clock_configure.h"
#include "gps.h"

namespace USBDM {

/**
 * Sets the baud rate of the UART
 *
 * @param baudrate - the baud rate to use e.g. 9600
 */
void Gps::setBaud(int baudrate) {

   // Disable UART before changing registers
   uart->C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK);

   // Calculate UART clock setting (5-bit fraction at right)
   int scaledBaudValue = (2*uartClockFrequency)/(baudrate);

#ifdef UART_C4_BRFA_MASK
   // Set Baud rate register
   uart->BDH = (uart->BDH&~UART_BDH_SBR_MASK) | UART_BDH_SBR((scaledBaudValue>>(8+5)));
   uart->BDL = UART_BDL_SBR(scaledBaudValue>>5);
   // Fractional divider to get closer to the baud rate
   uart->C4 = (uart->C4&~UART_C4_BRFA_MASK) | UART_C4_BRFA(scaledBaudValue);
#else
   scaledBaudValue += 1<<4; // Round value
   // Set Baud rate register
   uart->BDH = (uart->BDH&~UART_BDH_SBR_MASK) | UART_BDH_SBR((scaledBaudValue>>(8+5)));
   uart->BDL = UART_BDL_SBR(scaledBaudValue>>5);
#endif

   uart->C1 = 0;

   // Enable UART Tx & Rx - with Rx IRQ
   uart->C2 = UART_C2_TE_MASK|UART_C2_RE_MASK|UART_C2_RIE_MASK;
}

/**
 * Transmits a single character over the UART (blocking)
 *
 * @param ch - character to send
 */
void Gps::putChar(int ch) {
   while ((uart->S1 & UART_S1_TDRE_MASK) == 0) {
      // Wait for Tx buffer empty
      __asm__("nop");
   }
   uart->D = ch;
}

/**
 * Start parsing a number
 */
void Gps::startNumber(Gps::State ps) {
   state          = S_number;
   pushState      = ps;
   integer        = 0;
   decimalCount   = 1;
   number         = 0.0;
   numberSign     = 1;
}

/**
 * Start parsing a unit e.g. K,N,S,E,W
 */
void Gps::startUnits(Gps::State ps) {
   state          = S_units;
   pushState      = ps;
   integer        = '?';
}

/**
 * Start parsing a string of characters
 */
void Gps::startString(Gps::State ps) {
   state          = S_string;
   pushState      = ps;
   bufferIndex    = 0;
}

/**
 * State machine to process received GPS data
 */
void Gps::stateMachine(char ch) {
   static char     idBuffer[20];

   if (ch == '$') {
      // Reset state machine on start of message '$'
      startString(S_id);
      return;
   }
   if (ch == ',') {
      switch (state) {

      case S_units:
         break;

      case S_number:
         number     = (double)(numberSign*integer);
         break;

      case S_numberFraction:
         number     = ((double)(numberSign*integer))/decimalCount;
         break;

      default:
         break;
      }
      state      = pushState;
      pushState  = S_idle;
   }

   switch (state) {

   case S_idle:
      break;

   case S_id:
      if (strncmp(idBuffer, "GPGGA", 5) == 0) {
         startNumber(S_utcTime);
         bufferIndex = 0;
      }
      else {
         state = S_idle;
      }
      break;

   case S_utcTime:
      gpsData.utcTime  = number;
      startNumber(S_gpggaLatitude);
      break;

   case S_gpggaLatitude:
      gpsData.latitude = number;
      startUnits(S_gpggaLatitudeNS);
      break;

   case S_gpggaLatitudeNS:
      gpsData.n_s_Indicator = integer;
      startNumber(S_gpggaLongitude);
      break;

   case S_gpggaLongitude:
      gpsData.longitude = number;
      startUnits(S_gpggaLongitudeEW);
      break;

   case S_gpggaLongitudeEW:
      gpsData.e_w_Indicator = integer;
      startNumber(S_fixIndicator);
      break;

   case S_fixIndicator:
      gpsData.fixIndicator = integer;
      startNumber(S_satelliteCount);
      break;

   case S_satelliteCount:
      gpsData.satCount = integer;
      startNumber(S_hdop);
      break;

   case S_hdop:
      gpsData.hdop = number;
      startNumber(S_altitude);
      break;

   case S_altitude:
      gpsData.altitude = number;
      startUnits(S_altitudeUnits);
      break;

   case S_altitudeUnits:
      gpsData.altitudeUnits = integer;
      startNumber(S_geod);
      break;

   case S_geod:
      gpsData.geoid  = number;
      startUnits(S_geodUnits);
      break;

   case S_geodUnits:
      gpsData.geoidUnits = integer;
      state = S_idle;
      newData = true;
      break;

   case S_string:
      if (bufferIndex < (sizeof(idBuffer)-2)) {
         idBuffer[bufferIndex++] = ch;
         idBuffer[bufferIndex]   = '\0';
      }
      else {
         state = S_idle;
      }
      break;

   case S_units:
      if ((ch == 'M') || (ch == 'K') || (ch == 'N') || (ch == 'S') || (ch == 'E') || (ch == 'W')) {
         integer = ch;
      }
      else {
         state = S_idle;
      }
      break;

   case S_number:
      if (ch == '-') {
         numberSign = -1;
      }
      else if (ch == '.') {
         state = S_numberFraction;
      }
      else if ((ch>='0') && (ch<='9')) {
         integer = (integer * 10) + (ch - '0');
      }
      else {
         state = S_idle;
      }
      break;

   case S_numberFraction:
      if ((ch>='0') && (ch<='9')) {
         decimalCount *= 10;
         integer       = (integer * 10) + (ch - '0');
      }
      else {
         state = S_idle;
      }
      break;


   default:
      break;
   }
}

/**
 * Prints GPS data to stdout (for debug)
 *
 * @param gpsData GPS Data to be reported
 */
void Gps::report(Gps::GpsData &gpsData) {
   if (gpsData.fixIndicator == 0) {
      printf("T=%f, Sats=%d : No fix yet\n", gpsData.utcTime, gpsData.satCount);
      return;
   }
   printf("T=%f, Position : Lat=%f:%c Long=%f:%c fix=%d sat=%d hdop=%f alt=%f:%c geod=%f:%c\n",
         gpsData.utcTime, gpsData.latitude, gpsData.n_s_Indicator, gpsData.longitude, gpsData.e_w_Indicator, gpsData.fixIndicator,
         gpsData.satCount, gpsData.hdop, gpsData.altitude, gpsData.altitudeUnits, gpsData.geoid, gpsData.geoidUnits);
}

//=========================================================================
//=========================================================================

#ifdef UART0_RX_GPIO

/**
 * Interrupt handler for UART0 Tx & Rx
 */
extern "C"
void UART0_RX_TX_IRQHandler() {
   // Clear & ignore pending errors
   if ((UART0->S1 & UART_S1_RDRF_MASK) != 0) {
      Gps0::thisPtr->stateMachine(UART0->D);
   }
}

/**
 * Interrupt handler for UART0 Error
 */
extern "C"
void UART0_ERR_IRQHandler() {
   // Clear & ignore any pending errors
   if ((UART0->S1 & (UART_S1_FE_MASK|UART_S1_OR_MASK|UART_S1_PF_MASK|UART_S1_NF_MASK)) != 0) {
      // Discard data (& clear status)
      (void)UART0->D;
   }
}

Gps *Gps0::thisPtr;

/**
 * Initialise the UART to default settings
 */
void Gps0::initUart() {
   // Configure pins
   UART0_RX_GPIO::Pcr::setPCR(PORT_PCR_MUX(UART0_RX_FN)|USBDM::DEFAULT_PCR);
#ifdef UART0_TX_GPIO
   UART0_TX_GPIO::Pcr::setPCR(PORT_PCR_MUX(UART0_RX_FN)|USBDM::DEFAULT_PCR);
#endif

   // Enable clock to UART
   SIM->UART0_CLOCK_REG |= UART0_CLOCK_MASK;

#if SIM_SOPT5_UART0RXSRC_MASK
   // Select Tx & Rx pins to use
   SIM->SOPT5 &= ~(SIM_SOPT5_UART0RXSRC_MASK|SIM_SOPT5_UART0TXSRC_MASK);
#endif

   setBaud();

   NVIC_EnableIRQ(UART0_RX_TX_IRQn);
   NVIC_EnableIRQ(UART0_ERR_IRQn);
}
#endif // UART0_RX_GPIO

//=========================================================================
//=========================================================================

#ifdef UART1_RX_GPIO

/**
 * Interrupt handler for UART1 Tx & Rx
 */
extern "C"
void UART1_RX_TX_IRQHandler() {
   // Clear & ignore pending errors
   if ((UART1->S1 & UART_S1_RDRF_MASK) != 0) {
      Gps1::thisPtr->stateMachine(UART1->D);
   }
}

/**
 * Interrupt handler for UART1 Error
 */
extern "C"
void UART1_ERR_IRQHandler() {
   // Clear & ignore any pending errors
   if ((UART1->S1 & (UART_S1_FE_MASK|UART_S1_OR_MASK|UART_S1_PF_MASK|UART_S1_NF_MASK)) != 0) {
      // Discard data (& clear status)
      (void)UART1->D;
   }
}

Gps *Gps1::thisPtr;

/**
 * Initialise the UART to default settings
 */
void Gps1::initUart() {
   // Configure pins
   UART1_RX_GPIO::Pcr::setPCR(PORT_PCR_MUX(UART1_RX_FN)|USBDM::DEFAULT_PCR);
#ifdef UART1_TX_GPIO
   UART1_TX_GPIO::Pcr::setPCR(PORT_PCR_MUX(UART1_RX_FN)|USBDM::DEFAULT_PCR);
#endif

   // Enable clock to UART
   SIM->UART1_CLOCK_REG |= UART1_CLOCK_MASK;

#ifdef SIM_SOPT5_UART1RXSRC_MASK
   // Select Tx & Rx pins to use
   SIM->SOPT5 &= ~(SIM_SOPT5_UART1RXSRC_MASK|SIM_SOPT5_UART1TXSRC_MASK);
#endif

   setBaud();

   NVIC_EnableIRQ(UART1_RX_TX_IRQn);
   NVIC_EnableIRQ(UART1_ERR_IRQn);
}

#endif // UART1_RX_GPIO

//=========================================================================
//=========================================================================

#ifdef UART2_RX_GPIO

/**
 * Interrupt handler for UART2 Tx & Rx
 */
extern "C"
void UART2_RX_TX_IRQHandler() {
   if ((UART2->S1 & UART_S1_RDRF_MASK) != 0) {
      Gps2::thisPtr->stateMachine(UART2->D);
   }
}

/**
 * Interrupt handler for UART2 Error
 */
extern "C"
void UART2_ERR_IRQHandler() {
   // Clear & ignore any pending errors
   if ((UART2->S1 & (UART_S1_FE_MASK|UART_S1_OR_MASK|UART_S1_PF_MASK|UART_S1_NF_MASK)) != 0) {
      // Discard data (& clear status)
      (void)UART2->D;
   }
}

Gps *Gps2::thisPtr;

/**
 * Initialise the UART to default settings
 */
void Gps2::initUart() {
   // Configure pins
   UART2_RX_GPIO::Pcr::setPCR(PORT_PCR_MUX(UART2_RX_FN)|USBDM::DEFAULT_PCR);
#ifdef UART2_TX_GPIO
   UART2_TX_GPIO::Pcr::setPCR(PORT_PCR_MUX(UART2_RX_FN)|USBDM::DEFAULT_PCR);
#endif

   // Enable clock to UART
   SIM->UART2_CLOCK_REG |= UART2_CLOCK_MASK;

#ifdef SIM_SOPT5_UART2RXSRC_MASK
   // Select Tx & Rx pins to use
   SIM->SOPT5 &= ~(SIM_SOPT5_UART2RXSRC_MASK|SIM_SOPT5_UART2TXSRC_MASK);
#endif

   setBaud();

   NVIC_EnableIRQ(UART2_RX_TX_IRQn);
   NVIC_EnableIRQ(UART2_ERR_IRQn);
}

#endif // UART2_RX_GPIO

} // End namespace USBDM
