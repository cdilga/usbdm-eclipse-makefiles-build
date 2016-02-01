// Copyright 2013 Pervasive Displays, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
// express or implied.  See the License for the specific language
// governing permissions and limitations under the License.

#include <limits.h>
#include <string.h>
#include "delay.h"
#include "epd.h"

namespace USBDM {

#define CHANNEL_SELECT_REG      0x01
#define OUTPUT_ENABLE_REG       0x02
#define DRIVER_LATCH_REG        0x03
#define GATE_SOURCE_REG         0x04
#define CHARGE_PUMP_REG         0x05
#define DC_DC_FREQUENCY_REG     0x06
#define HP_OSCILLATOR_REG       0x07
#define ADC_REG                 0x08
#define VCOM_LEVEL_REG          0x09

constexpr long SPI_FREQUENCY = 12000000;

/**
 *  Constructor
 *
 *  @param spi       SPI interface to use
 *  @param epdData   Data describing the EPD panel
 */
Epd::Epd(Spi *spi, const EpdData &epdData) : spi(spi), epdData(epdData) {
   uint32_t spiFequency = spi->getSpeed();

   if (spiFequency>SPI_FREQUENCY) {
      spi->setSpeed(SPI_FREQUENCY);
   }

   enableTimer();

   // Set default factor for 25 Celsius
   setDisplayTemperature(25);
}

/**
 * Power-on and Initialise COG driver
 */
void Epd::powerOnAndInitialise() {

   // Turn on hardware interface
   interfaceOn();

   // ===========================================
   // See Application Note Doc. No. 4P008-00
   // 4 Initialize COG Driver

   while (isBusy()) {
      __asm__("nop");
   }
   // Channel select
   static constexpr uint8_t channelSelect[] = {0x70, CHANNEL_SELECT_REG};
   txBytes(sizeof(channelSelect), channelSelect);
   txBytes(sizeof(epdData.channel_select), epdData.channel_select);

   // DC/DC frequency settings
   txWriteReg1Byte(DC_DC_FREQUENCY_REG, 0xFF);

   // High power mode oscillator setting
   txWriteReg1Byte(HP_OSCILLATOR_REG, 0x9d);

   // Disable ADC
   txWriteReg1Byte(ADC_REG, 0x00);

   // Set Vcom level
   constexpr uint8_t vCom[] = {0x70, VCOM_LEVEL_REG};
   constexpr uint8_t vComData[] = {0x72, 0xd0, 0x00};
   txBytes(sizeof(vCom), vCom);
   txBytes(sizeof(vComData), vComData);

   // Gate and source voltage levels
   txWriteReg1Byte(GATE_SOURCE_REG,  epdData.gate_source);

   // PWM toggle 5ms
   waitMS(5);

   // Driver latch on
   txWriteReg1Byte(DRIVER_LATCH_REG, 0x01);

   // Driver latch off
   txWriteReg1Byte(DRIVER_LATCH_REG, 0x00);

   // Start positive charge pump
   txWriteReg1Byte(CHARGE_PUMP_REG, 0x01);

   // PWM toggle 30ms
   waitMS(30);

   // Stop PWM & leave low
   pwmEnable(0);

   // Charge pump negative voltage on
   txWriteReg1Byte(CHARGE_PUMP_REG, 0x03);

   waitMS(30);

   // Vcom driver on
   txWriteReg1Byte(CHARGE_PUMP_REG, 0x0f);

   waitMS(30);

   // Output enable to disable
   txWriteReg1Byte(OUTPUT_ENABLE_REG,0x24);
}

/**
 * Power-off COG driver
 */
void Epd::powerOff() {
   // ===========================================
   // See Application Note Doc. No. 4P008-00
   // 6 Power Off COG Driver

   // dummy frame
   //frame_fixed(0x55, EPD_normal);

   // dummy line and border
   if (epdData.epdSize == EPD_1_44) {
      // Only for 1.44" EPD
      sendLine(0x7fffu, 0, 0xaa, EPD_normal);
      waitMS(300);
   }
   else {
      // Other display sizes
      sendLine(0x7fffu, 0, 0x55, EPD_normal);
      waitMS(25);
      pulseBorder();
   }
   // Latch reset turn on
   txWriteReg1Byte(DRIVER_LATCH_REG, 0x01);

   // Output enable off
   txWriteReg1Byte(OUTPUT_ENABLE_REG, 0x05);

   // Power off Vcom charge pump
   txWriteReg1Byte(CHARGE_PUMP_REG, 0x0e);

   // Power off negative charge pump
   txWriteReg1Byte(CHARGE_PUMP_REG, 0x02);

   // Discharge
   txWriteReg1Byte(GATE_SOURCE_REG, 0x0c);

   waitMS(120);

   // Turn off all charge pumps
   txWriteReg1Byte(CHARGE_PUMP_REG, 0x00);

   // Turn of oscillator
   txWriteReg1Byte(HP_OSCILLATOR_REG, 0x0d);

   // discharge internal - 1
   txWriteReg1Byte(GATE_SOURCE_REG, 0x50);

   waitMS(40);

   // Discharge internal - 2
   txWriteReg1Byte(GATE_SOURCE_REG, 0xA0);

   waitMS(40);

   // Discharge internal - 3
   txWriteReg1Byte(GATE_SOURCE_REG, 0x00);

   interfaceOff();
}

struct Pair {
   int16_t threshold;
   int16_t factor;
};
static constexpr Pair thresholds[] = {
      {-10, 170},
      { -5, 120},
      {  5,  80},
      { 10,  40},
      { 15,  30},
      { 20,  20},
      { 40,  10},
};

/**
 * Calculates the factored stage time for frame_*_repeat methods
 * from temperature.
 *
 *  @param  temperature Temperature in Celsius
 *
 *  @return Scaled stage time in ms
 */
int Epd::getFactoredStageTime(int temperature) {
   int factor_x10 = 7;
   for (const Pair *pair=thresholds; pair<thresholds+(sizeof(thresholds)/sizeof(thresholds[0])); pair++) {
      if (temperature <= pair->threshold) {
         factor_x10 = pair->factor;
         break;
      }
   }
   return (epdData.stage_time*(int32_t)factor_x10) / 10;
}

/* ==================================================================
 * One frame of data is the number of lines * rows. For example:
 * The 1.44" frame of data is 96 lines * 128 dots.
 * The 2" frame of data is 96 lines * 200 dots.
 * The 2.7" frame of data is 176 lines * 264 dots.
 *
 * The image is arranged by line which matches the display size
 * so smallest would have 96 * 32 bytes
 * ==================================================================*/

/**
 * Write full frame of fixed data value
 *
 * @param fixedValue Value to write
 * @param stage      Stage of update process
 */
void Epd::frame_fixed(uint8_t fixedValue, EpdStage stage) {
   for (uint8_t line = 0; line < epdData.lines_per_display ; ++line) {
      sendLine(line, 0, fixedValue, stage);
   }
}

/**
 * Write full frame from an image
 *
 * @param image  Image to write
 * @param stage  Stage of update process
 */
void Epd::frame_data( const uint8_t *image, EpdStage stage) {
   for (uint8_t line = 0; line < epdData.lines_per_display ; ++line) {
      sendLine(line, &image[line * epdData.bytes_per_line], 0, stage);
   }
}

/**
 * Write full frame of fixed data value multiple times (over repeat period)
 *
 * @param fixedValue Value to write
 * @param stage      Stage of update process
 */
void Epd::frame_fixed_repeat(uint8_t fixedValue, EpdStage stage) {
   // Convert duration to DWT ticks
   int64_t delayct = convertMSToTicks(factored_stage_time);

   // Get current tick
   uint32_t last = getTicks();

   do {
      frame_fixed(fixedValue, stage);

      // Decrement time elapsed
      // Note: This relies on the loop executing in less than the roll-over time
      // of the counter i.e. (TIMER_MASK+1)/SystemCoreClock
      uint32_t now = getTicks();
      delayct -= (uint32_t)(TIMER_MASK&(last-now));
      last = now;
      } while (delayct > 0);
}

/**
 * Write full frame from an image multiple times (over repeat period)
 *
 * @param image  Image to write
 * @param stage  Stage of update process
 */
void Epd::frame_data_repeat(const uint8_t *image, EpdStage stage) {
   // Convert duration to DWT ticks
   int64_t delayct = convertMSToTicks(factored_stage_time);

   // Get current tick
   uint32_t last = getTicks();

   do {
      frame_data(image, stage);

      // Decrement time elapsed
      // Note: This relies on the loop executing in less than the roll-over time
      // of the counter i.e. (TIMER_MASK+1)/SystemCoreClock
      uint32_t now = getTicks();
      delayct -= (uint32_t)(TIMER_MASK&(last-now));
      last = now;
      } while (delayct > 0);
}

/**
 * Send line of data to display
 *
 * @param   line        Which line of display
 * @param   data        Data to write (may be NULL)
 * @param   fixed_value Fixed value used if data == NULL
 * @param   stage       Stage of the screen rewrite
 */
void Epd::sendLine(uint16_t line, const uint8_t *data, uint8_t fixed_value, EpdStage stage) {

   // Charge pump voltage levels
   txWriteReg1Byte(GATE_SOURCE_REG, epdData.gate_source);

   // Send data
   constexpr uint8_t preamble[] = {0x70, 0x0a};
   txBytes(sizeof(preamble), preamble);

   csEnable(true);
   txByteAndWait(0x72);

   // Even pixels
   for (uint16_t b = epdData.bytes_per_line; b > 0; --b) {
      if (data != 0) {
         uint8_t pixels;
         pixels = data[b - 1] & 0xaa;

         switch(stage) {
         case EPD_compensate:  // B -> W, W -> B (Current Image)
            pixels = 0xaa | ((pixels ^ 0xaa) >> 1);
            break;

         case EPD_white:       // B -> N, W -> W (Current Image)
            pixels = 0x55 + ((pixels ^ 0xaa) >> 1);
            break;

         case EPD_inverse:     // B -> N, W -> B (New Image)
            pixels = 0x55 | (pixels ^ 0xaa);
            break;

         case EPD_normal:       // B -> B, W -> W (New Image)
            pixels = 0xaa | (pixels >> 1);
            break;
         }
         txByteAndWait(pixels);
      }
      else {
         txByteAndWait(fixed_value);
      }
   }
   // Scan line
   for (uint16_t b = 0; b < epdData.bytes_per_scan; ++b) {
      if (line / 4 == b) {
         txByteAndWait(0xc0 >> (2 * (line & 0x03)));
      }
      else {
         txByteAndWait(0x00);
      }
   }
   // Odd pixels
   for (uint16_t b = 0; b < epdData.bytes_per_line; ++b) {
      if (0 != data) {
         uint8_t pixels;
         pixels = data[b] & 0x55;

         switch(stage) {
         case EPD_compensate:  // B -> W, W -> B (Current Image)
            pixels = 0xaa | (pixels ^ 0x55);
            break;
         case EPD_white:       // B -> N, W -> W (Current Image)
            pixels = 0x55 + (pixels ^ 0x55);
            break;
         case EPD_inverse:     // B -> N, W -> B (New Image)
            pixels = 0x55 | ((pixels ^ 0x55) << 1);
            break;
         case EPD_normal:       // B -> B, W -> W (New Image)
            pixels = 0xaa | pixels;
            break;
         }
         uint8_t p1 = (pixels >> 6) & 0x03;
         uint8_t p2 = (pixels >> 4) & 0x03;
         uint8_t p3 = (pixels >> 2) & 0x03;
         uint8_t p4 = (pixels >> 0) & 0x03;
         pixels = (p1 << 0) | (p2 << 2) | (p3 << 4) | (p4 << 6);
         txByteAndWait(pixels);
      }
      else {
         txByteAndWait(fixed_value);
      }
   }
   if (epdData.filler) {
      txByteAndWait(0x00);
   }
   csEnable(false);
   waitUS(10);

   // Output data to panel
   txWriteReg1Byte(OUTPUT_ENABLE_REG,0x2f);
}

/**
 *  Send a single byte to EPD and wait for not busy
 *
 *  @param data Byte to send
 */
void Epd::txByteAndWait(uint8_t data) {
   spi->txRx(data);

   // Wait for EPD ready
   while(isBusy()) {
      __asm__("nop");
   }
}

/**
 *  Write byte to register
 *
 *  @param regNum    Register to write to
 *  @param data      Data byte for register
 */
void Epd::txWriteReg1Byte(const uint8_t regNum, uint8_t data) {
   uint8_t registerAddressCommand[] = {0x70, regNum};
   uint8_t registerDataValue[]      = {0x72, data};

   // Send register address
   txBytes(sizeof(registerAddressCommand), registerAddressCommand);

   // Send register value
   txBytes(sizeof(registerDataValue), registerDataValue);
}

/**
 *  Read 1 byte from register
 *
 *  @param regNum    Register to read from
 *
 *  @return          Data byte from register
 */
uint8_t Epd::rxReadReg1Byte(const uint8_t regNum) {
   uint8_t registerAddressCommand[] = {0x70, regNum};
   uint8_t registerDataValue[]      = {0x73, 0};

   // Send register address
   txBytes(sizeof(registerAddressCommand), registerAddressCommand);

   // CS low
   csEnable(true);

   // Send/Receive data
   spi->txRxBytes(sizeof(registerDataValue), registerDataValue, registerDataValue);

   // CS high
   csEnable(false);

   // Make sure CS remains high for at least 10us
   waitUS(10);

   return registerDataValue[1];
}

/**
 *  Driver ID
 *  Note: Only implemented on later e-Paper?
 *
 *  @return ID byte
 */
uint8_t Epd::rxReadId() {

   // CS low
   csEnable(true);

   // Send/Receive data
   uint8_t cogDriverId[]      = {0x71, 0};
   spi->txRxBytes(sizeof(cogDriverId), cogDriverId, cogDriverId);

   // CS high
   csEnable(false);

   // Make sure CS remains high for at least 10us
   waitUS(10);

   return cogDriverId[1];
}

/**
 *  Transmit bytes to EPD
 *
 *  @param dataSize  Number of bytes to transfer
 *  @param dataOut   Transmit bytes
 */
void Epd::txBytes(uint32_t dataSize, const uint8_t *dataOut) {
   // CS low
   csEnable(true);

   // Send data
   spi->txRxBytes(dataSize, dataOut);

   // CS high
   csEnable(false);

   // Make sure CS remains high for at least 10us
   waitUS(10);
}

} // End namespace USBDM
