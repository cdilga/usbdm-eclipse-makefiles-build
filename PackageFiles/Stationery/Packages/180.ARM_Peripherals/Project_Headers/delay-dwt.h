/**
 * @file delay.h derived from delay-dwt.h
 * @brief Simple busy-waiting delay routines using DWT counter
 *
 *  Created on: 5 Oct 2015
 *      Author: podonoghue
 */
#ifndef INCLUDE_USBDM_DELAY_H_
#define INCLUDE_USBDM_DELAY_H_

#include <stdint.h>
#include "derivative.h"

#ifdef __cplusplus
namespace USBDM {
#endif

// Mask for maximum timer value
static constexpr uint32_t TIMER_MASK = -1;

/**
 * Enable timer
 *
 * Note this is only required if getTicks() is used by itself
 */
static inline void enableTimer() {
#ifdef DEBUG_BUILD
   if ((DWT->CTRL&DWT_CTRL_NOCYCCNT_Msk) != 0) {
      // No CYCCNT
      __asm__("bkpt");
   }
#endif
   // Reload with maximum value 2^24
   SYST->RVR = -1;

   // Enable without interrupts
   SYST->CSR = SYST_CSR_CLKSOURCE_MASK| // Processor clock
               SYST_CSR_ENABLE_MASK;    // Enabled
}

/**
 * Gets the number of ticks since the timer was started
 *
 * @return Number of ticks
 */
static inline uint32_t getTicks() {
   return SYST->CVR;
}

/**
 * Simple delay routine
 *
 * @param usToWait How many microseconds to busy-wait
 */
void waitUS(uint32_t usToWait);

/**
 * Simple delay routine
 *
 * @param msToWait How many milliseconds to busy-wait
 */
void waitMS(uint32_t msToWait);

#ifdef __cplusplus
} // End namespace USBDM
#endif

#endif /* INCLUDE_USBDM_DELAY_H_ */
