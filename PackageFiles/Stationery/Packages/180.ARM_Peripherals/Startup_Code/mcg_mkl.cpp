/*
 * @file mcg.cpp (180.ARM_Peripherals/Startup_Code/mcg_mkl.cpp)
 *
 * Based on KL25
 *    1 FLL (FRDIV=/1-/128, /32-/1024, /1280, /1536)
 *    1 PLL (VCO PRDIV=/1-/24, VDIV=pll_vdiv_min+x) (pll_vdiv_min=x16,x24)
 *    RTC enable forces low range
 *    SIM_CLKDIV1_OUTDIV4_MASK divides core clock (post divider)
 *
 *  Created on: 04/03/2012
 *      Author: podonoghue
 */
#include "string.h"
#include "derivative.h" /* include peripheral declarations */
#include "system.h"
#include "utilities.h"
#include "stdbool.h"
#include "hardware.h"
#include "rtc.h"
#include "mcg.h"
#include "osc.h"
 /*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
extern "C" uint32_t SystemCoreClock;
extern "C" uint32_t SystemBusClock;

namespace USBDM {

#ifndef SIM_CLKDIV1_OUTDIV2
#define SIM_CLKDIV1_OUTDIV2(x) (0)
#endif

#ifndef SIM_CLKDIV1_OUTDIV3
#define SIM_CLKDIV1_OUTDIV3(x) (0)
#endif

   /**
    * Table of clock settings
    */
   const McgInfo::ClockInfo McgInfo::clockInfo[] = {
$(/MCG/McgClockInfoEntries:!!!!!!!Not found!!!!!!!)
   };

/** MCGFFCLK - Fixed frequency clock (input to FLL) */
volatile uint32_t SystemMcgffClock;

/** MCGOUTCLK - Primary output from MCG, various sources */
volatile uint32_t SystemMcgOutClock;

/** MCGFLLCLK - Output of FLL */
volatile uint32_t SystemMcgFllClock;

/** MCGPLLCLK - Output of PLL */
volatile uint32_t SystemMcgPllClock;

/** Core/System clock (from MCGOUTCLK/CLKDIV) */
volatile uint32_t SystemCoreClock;

/** Bus clock (from MCGOUTCLK/CLKDIV) */
volatile uint32_t SystemBusClock;

/** LPO - Low power oscillator 1kHz clock available in LP modes */
volatile uint32_t SystemLpoClock;

/** Callback for programmatically set handler */
MCGCallbackFunction Mcg::callback = {0};

/** Current clock mode (FEI out of reset) */
McgInfo::ClockMode Mcg::currentClockMode = McgInfo::ClockMode::ClockMode_FEI;

constexpr uint8_t clockTransitionTable[8][8] = {
         /*  from                 to =>   ClockMode_FEI,           ClockMode_FEE,           ClockMode_FBI,           ClockMode_BLPI,          ClockMode_FBE,           ClockMode_BLPE,          ClockMode_PBE,           ClockMode_PEE */
         /* ClockMode_FEI,  */ { McgInfo::ClockMode_FEI,  McgInfo::ClockMode_FEE,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE, },
         /* ClockMode_FEE,  */ { McgInfo::ClockMode_FEI,  McgInfo::ClockMode_FEI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE, },
         /* ClockMode_FBI,  */ { McgInfo::ClockMode_FEI,  McgInfo::ClockMode_FEE,  McgInfo::ClockMode_FEI,  McgInfo::ClockMode_BLPI, McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE, },
         /* ClockMode_BLPI, */ { McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI, },
         /* ClockMode_FBE,  */ { McgInfo::ClockMode_FEI,  McgInfo::ClockMode_FEE,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FBI,  McgInfo::ClockMode_FEI,  McgInfo::ClockMode_BLPE, McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE, },
         /* ClockMode_BLPE, */ { McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE, },
         /* ClockMode_PBE,  */ { McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_FBE,  McgInfo::ClockMode_BLPE, McgInfo::ClockMode_FBE,  McgInfo::ClockMode_PEE, },
         /* ClockMode_PEE,  */ { McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE,  McgInfo::ClockMode_PBE, },
   };

/**
 * Get name for clock mode
 *
 * @return Pointer to static string
 */
const char *Mcg::getClockModeName(McgInfo::ClockMode clockMode) {
   static const char *modeNames[] {
         "FEI",
         "FEE",
         "FBI",
         "BLPI",
         "FBE",
         "BLPE",
         "PBE",
         "PEE",
   };

   if (clockMode<0) {
      return "Not set";
   }
   if ((unsigned)clockMode>=(sizeof(modeNames)/sizeof(modeNames[0]))) {
      return "Illegal";
   }
   return modeNames[clockMode];
}
#ifndef SIM_CLKDIV1_OUTDIV3
#define SIM_CLKDIV1_OUTDIV3(x) 0
#endif

#ifndef SIM_CLKDIV1_OUTDIV2
#define SIM_CLKDIV1_OUTDIV2(x) 0
#endif

/**
 * Transition from current clock mode to mode given
 *
 * @param to Clock mode to transition to
 *
 * @return E_NO_ERROR on success
 */
int Mcg::clockTransition(const McgInfo::ClockInfo &clockInfo) {
   McgInfo::ClockMode to = clockInfo.clockMode;

   //TODO move!
#ifdef USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK
   if (clockInfo.c7&&MCG_C7_OSCSEL_MASK) {
      // Note IRC48M Internal Oscillator automatically enable if MCG_C7_OSCSEL = 2
      SIM->SCGC4 |= SIM_SCGC4_USBOTG_MASK;
      USB0->CLK_RECOVER_IRC_EN = USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK|USB_CLK_RECOVER_IRC_EN_REG_EN_MASK;
   }
#endif

   // Set conservative clock dividers
   setSysDividers(SIM_CLKDIV1_OUTDIV4(5)|SIM_CLKDIV1_OUTDIV3(5)|SIM_CLKDIV1_OUTDIV2(5)|SIM_CLKDIV1_OUTDIV1(5));

#ifdef MCG_C7_OSCSEL
   // Select OSCCLK Source
   mcg->C7 = clockInfo.c7; // OSCSEL = 0,1,2 -> XTAL/XTAL32/IRC48M
#endif

   // Set Fast Internal Clock divider
   mcg->SC = clockInfo.sc;

   // Disable clock monitors while clocks change
   mcg->C8 = 0;

   McgInfo::ClockMode next;
   if (currentClockMode == McgInfo::ClockMode_None) {
      next = McgInfo::ClockMode_FEI;
   }
   else {
      // Initial destination chosen to ensure that set-up occurs
      next = (McgInfo::ClockMode)clockTransitionTable[currentClockMode][currentClockMode];
   }
   if (to != McgInfo::ClockMode_None) {
      int transitionCount = 0;
      do {
         // Used to indicate that clock stabilisation wait is needed
         bool externalClockInUse = false;

         switch (next) {

         case McgInfo::ClockMode_None:
         case McgInfo::ClockMode_FEI: // From FEE, FBI, FBE or reset(FEI)

            // EREFS0 (for exit to FEE,FBE)
            mcg->C2 = clockInfo.c2|MCG_C2_LP(0);

            mcg->C1 =
                  MCG_C1_CLKS(0)   | // CLKS     = 0     -> MCGOUTCLK = Output of FLL/PLL (depends on mcg_c6.PLLS)
                  MCG_C1_IREFS(1)  | // IREFS    = 1     -> FLL source = Slow IRC
                  clockInfo.c1;      // FRDIV, IRCLKEN, IREFSTEN

            // Set FLL Parameters
            mcg->C4 = (mcg->C4&(MCG_C4_FCTRIM_MASK|MCG_C4_SCFTRIM_MASK))|clockInfo.c4;

            // Wait for S_IREFST to indicate FLL Reference has switched to IRC
            // Wait for S_CLKST to indicating that OUTCLK has switched to FLL
            do {
               __asm__("nop");
            } while ((mcg->S & (MCG_S_CLKST_MASK|MCG_S_IREFST_MASK)) != (MCG_S_CLKST(0)|MCG_S_IREFST(1)));
            break;

         case McgInfo::ClockMode_FEE: // from FEI, FBI or FBE
            mcg->C1 =
                  MCG_C1_CLKS(0)   | // CLKS     = 0     -> MCGOUTCLK = Output of FLL/PLL (depends on mcg_c6.PLLS)
                  MCG_C1_IREFS(0)  | // IREFS    = 0     -> FLL source = External reference clock
                  clockInfo.c1;      // FRDIV, IRCLKEN, IREFSTEN

            // Wait for S_CLKST to indicating that MCGOUTCLK has switched to FLL
            // Wait for S_IREFST to indicate FLL Reference has switched to ERC
            do {
               __asm__("nop");
            } while ((mcg->S & (MCG_S_CLKST_MASK|MCG_S_IREFST_MASK)) != (MCG_S_CLKST(0)|MCG_S_IREFST(0)));

            externalClockInUse = true;
            break;

         case McgInfo::ClockMode_FBI: // from BLPI, FEI, FEE, FBE

            // Clear LP
            mcg->C2 = clockInfo.c2|MCG_C2_LP(0);

            mcg->C1 =
                  MCG_C1_CLKS(1)   | // CLKS     = 1     -> MCGOUTCLK = Internal reference clock is selected
                  MCG_C1_IREFS(1)  | // IREFS    = 1     -> FLL source = Slow IRC
                  clockInfo.c1;      // FRDIV, IRCLKEN, IREFSTEN

            // Set FLL Parameters
            mcg->C4 = (mcg->C4&(MCG_C4_FCTRIM_MASK|MCG_C4_SCFTRIM_MASK))|clockInfo.c4;

            // Wait for S_CLKST to indicating that MCGOUTCLK has switched to IRC
            // Wait for S_IREFST to indicate FLL Reference has switched to IRC
            do {
               __asm__("nop");
            } while ((mcg->S & (MCG_S_CLKST_MASK|MCG_S_IREFST_MASK)) != (MCG_S_CLKST(1)|MCG_S_IREFST(1)));
            break;

         case McgInfo::ClockMode_FBE: // from FEI, FEE, FBI, PBE, BLPE
            // Clear LP
            mcg->C2 = clockInfo.c2|MCG_C2_LP(0);

            mcg->C1 =
                  MCG_C1_CLKS(2)   | // CLKS     = 2     -> MCGOUTCLK = External reference clock
                  MCG_C1_IREFS(0)  | // IREFS    = 0     -> FLL source = External reference clock
                  clockInfo.c1;      // FRDIV, IRCLKEN, IREFSTEN

            // Select FLL as MCG clock source
            mcg->C6  = clockInfo.c6;

            // Wait for S_CLKST to indicating that MCGOUTCLK has switched to ERC
            // Wait for S_IREFST to indicate FLL Reference has switched to ERC
            do {
               __asm__("nop");
            } while ((mcg->S & (MCG_S_CLKST_MASK|MCG_S_IREFST_MASK)) != (MCG_S_CLKST(2)|MCG_S_IREFST(0)));

            externalClockInUse = true;
            break;

         case McgInfo::ClockMode_PBE: // from FBE, BLPE, PEE
            // Clear LP
            mcg->C2 = clockInfo.c2|MCG_C2_LP(0);
            mcg->C5 = clockInfo.c5;
            // Select PLL as MCG clock source and set VDIV0
            mcg->C6 = clockInfo.c6|MCG_C6_PLLS_MASK;

            mcg->C1 =
                  MCG_C1_CLKS(2)   | // CLKS     = 2     -> MCGOUTCLK = External reference clock
                  MCG_C1_IREFS(0)  | // IREFS    = 1     -> FLL source = External reference clock
                  clockInfo.c1;      // FRDIV, IRCLKEN, IREFSTEN

            externalClockInUse = true;
            while ((mcg->S&MCG_S_PLLST_MASK) == 0) {
               __asm__("nop");
            }
            break;

         case McgInfo::ClockMode_PEE: // from PBE
            mcg->C1 =
                  MCG_C1_CLKS(0)   | // CLKS     = 0     -> MCGOUTCLK = Output of FLL/PLL (depends on mcg_c6.PLLS)
                  MCG_C1_IREFS(0)  | // IREFS    = 0     -> FLL source = External reference clock
                  clockInfo.c1;      // FRDIV, IRCLKEN, IREFSTEN

            externalClockInUse = true;
            break;

         case McgInfo::ClockMode_BLPE: // from FBE, PBE (registers differ depending on transition)
            externalClockInUse = true;
            //no break

         case McgInfo::ClockMode_BLPI: // from FBI
            // Set LP
            mcg->C2 = clockInfo.c2|MCG_C2_LP(1);
            break;
         }
         // Wait for oscillator stable (if used)
         if (externalClockInUse && (clockInfo.c2&MCG_C2_EREFS0_MASK)) {
            do {
               __asm__("nop");
            } while ((mcg->S & MCG_S_OSCINIT0_MASK) == 0);
         }
         currentClockMode = next;
         next = (McgInfo::ClockMode)clockTransitionTable[currentClockMode][to];
         if (transitionCount++>5) {
            return -1;
         }
      } while (currentClockMode != to);
   }

   // Main clock dividers
   setSysDividers(clockInfo.clkdiv1);

   // Clock sources
   SIM->SOPT2 = clockInfo.sopt2;

   SystemCoreClockUpdate();
   return 0;
}

/**
 * Update SystemCoreClock variable
 *
 * Updates the SystemCoreClock variable with current core Clock retrieved from CPU registers.
 */
void Mcg::SystemCoreClockUpdate(void) {

   uint32_t mcg_erc_clock = McgInfo::getErcClock();

   if ((mcg->C1&MCG_C1_IREFS_MASK) == 0) {
      // External reference clock is selected
      SystemMcgffClock = mcg_erc_clock/(1<<((mcg->C1&MCG_C1_FRDIV_MASK)>>MCG_C1_FRDIV_SHIFT));

      if (((mcg->C2&MCG_C2_RANGE0_MASK) != 0) && 
	     ((RtcInfo::rtc->CR&RTC_CR_OSCE_MASK) == 0)) {
         // High divisors - extra division
         if ((mcg->C1&MCG_C1_FRDIV_MASK) == MCG_C1_FRDIV(6)) {
            SystemMcgffClock /= 20;
         }
         else if ((mcg->C1&MCG_C1_FRDIV_MASK) == MCG_C1_FRDIV(7)) {
            SystemMcgffClock /= 12;
         }
         else {
            SystemMcgffClock /= 32;
         }
      }
   }
   else {
      // External reference clock is selected
      SystemMcgffClock = McgInfo::system_slow_irc_clock;
   }

   uint32_t systemFllClock = SystemMcgffClock * ((mcg->C4&MCG_C4_DMX32_MASK)?732:640) * (((mcg->C4&MCG_C4_DRST_DRS_MASK)>>MCG_C4_DRST_DRS_SHIFT)+1);

   uint32_t systemPllClock = 0;
   systemPllClock  = (mcg_erc_clock/10)*(((mcg->C6&MCG_C6_VDIV0_MASK)>>MCG_C6_VDIV0_SHIFT)+McgInfo::pll_vdiv_min);
   systemPllClock /= ((mcg->C5&MCG_C5_PRDIV0_MASK)>>MCG_C5_PRDIV0_SHIFT)+1;
   systemPllClock *= (10/McgInfo::pll_post_divider);

   SystemMcgPllClock = 0;
   SystemMcgFllClock = 0;
   switch (mcg->S&MCG_S_CLKST_MASK) {
      case MCG_S_CLKST(0) : // FLL
         SystemMcgOutClock = systemFllClock;
         SystemMcgFllClock = systemFllClock;
         break;
      case MCG_S_CLKST(1) : // Internal Reference Clock
         SystemMcgOutClock = McgInfo::getInternalIrcClock();
         break;
      case MCG_S_CLKST(2) : // External Reference Clock
         SystemMcgOutClock = McgInfo::getErcClock();
         break;
      case MCG_S_CLKST(3) : // PLL
         SystemMcgOutClock = systemPllClock;
         SystemMcgPllClock = systemPllClock;
         break;
   }
   if (mcg->C5&MCG_C5_PLLCLKEN0_MASK) {
      SystemMcgPllClock = systemPllClock;
   }
   SystemCoreClock   = SystemMcgOutClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV1_MASK)>>SIM_CLKDIV1_OUTDIV1_SHIFT)+1);
   SystemBusClock    = SystemCoreClock/(((SIM->CLKDIV1&SIM_CLKDIV1_OUTDIV4_MASK)>>SIM_CLKDIV1_OUTDIV4_SHIFT)+1);

   SystemLpoClock    = 1000;

   ::SystemBusClock  = SystemBusClock;
   ::SystemCoreClock = SystemCoreClock;
}

/**
 * Initialise MCG to default settings.
 */
void Mcg::defaultConfigure() {

   currentClockMode = McgInfo::ClockMode::ClockMode_None;

   // Transition to desired clock mode
   clockTransition(McgInfo::clockInfo[ClockConfig_default]);

   SimInfo::initRegs();

   enableNvicInterrupts();

   SystemCoreClockUpdate();
}

} // end namespace USBDM

/**
 * Sets up the clock out of RESET
 */
extern "C"
void clock_initialise(void) {

#ifdef USBDM_OSC0_IS_DEFINED
   USBDM::Osc0::initialise();
#endif

#ifdef USBDM_RTC_IS_DEFINED
   USBDM::Rtc::initialise();
#endif

#ifdef USBDM_MCG_IS_DEFINED
   USBDM::Mcg::initialise();
#endif

}

