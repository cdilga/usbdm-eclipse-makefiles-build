/*
 ============================================================================
 * @file main.cpp (100.ARM_DeviceOptions/main-stm.cpp)
 *
 *  Created on: 04/12/2012
 *      Author: podonoghue
 ============================================================================
 */

#include <stdio.h>
#include "system.h"
#include "derivative.h"

// Simple delay - not for real programs!
void delay(void) {
   volatile unsigned long i;
   for (i=400000; i>0; i--) {
      __asm__("nop");
   }
}

/* Example use of interrupt handler
 *
 * The standard ARM libraries provide basic support for the system timer
 * This function is used for the System Timer interrupt handler.
 *
 */
//void SysTick_Handler(void) {
//   __asm__("nop");
//}

int main(void) {

   volatile int count = 0;

//   SysTick_Config(1000);

//   printf("SystemBusClock  = %ld\n", SystemBusClock);

   // Real programs never die!
   for(;;) {
      count++;
//      printf("Count = %d\n", count);
      delay();
   }
   return 0;
}
