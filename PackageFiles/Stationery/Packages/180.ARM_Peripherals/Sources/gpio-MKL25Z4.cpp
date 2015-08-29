 /**
  * @file     gpio.cpp (from gpio-MKL25Z4.cpp)
  *
  * @brief   Pin declarations for MKL25Z4
  */

#include "utilities.h"
#include "gpio.h"
#include "pin_mapping.h"

/**
 * @brief Create Timer Clock register name from timer number
 *
 * @param number Timer number e.g. 1 => TPM1_CLOCK_REG
 */
#define TPM_CLOCK_REG(number)  CONCAT3_(TPM,number,_CLOCK_REG)

/**
 * @brief Create Timer Clock register mask from timer number
 *
 * @param number Timer number e.g. 1 => TPM1_CLOCK_MASK
 */
#define TPM_CLOCK_MASK(number)  CONCAT3_(TPM,number,_CLOCK_MASK)

/**
 * @brief Create ADC Clock register name from ADC number
 *
 * @param number Timer number e.g. 1 => ADC1_CLOCK_REG
 */
#define ADC_CLOCK_REG(number)  CONCAT3_(ADC,number,_CLOCK_REG)

/**
 * @brief Create ADC Clock register mask from ADC number
 *
 * @param number Timer number e.g. 1 => ADC1_CLOCK_MASK
 */
#define ADC_CLOCK_MASK(number)  CONCAT3_(ADC,number,_CLOCK_MASK)

#define ADC(num)             CONCAT2_(ADC,num)   
#define FTM(num)             CONCAT2_(FTM,num)   
#define TPM(num)             CONCAT2_(TPM,num)   

const DigitalIO digitalIO_PTA0     = {&PCR(PTA0_GPIO_NAME,PTA0_GPIO_BIT),GPIO(PTA0_GPIO_NAME),PORT_CLOCK_MASK(PTA0_GPIO_NAME),(1UL<<PTA0_GPIO_BIT)};
const DigitalIO digitalIO_PTA1     = {&PCR(PTA1_GPIO_NAME,PTA1_GPIO_BIT),GPIO(PTA1_GPIO_NAME),PORT_CLOCK_MASK(PTA1_GPIO_NAME),(1UL<<PTA1_GPIO_BIT)};
const DigitalIO digitalIO_PTA2     = {&PCR(PTA2_GPIO_NAME,PTA2_GPIO_BIT),GPIO(PTA2_GPIO_NAME),PORT_CLOCK_MASK(PTA2_GPIO_NAME),(1UL<<PTA2_GPIO_BIT)};
const DigitalIO digitalIO_PTA3     = {&PCR(PTA3_GPIO_NAME,PTA3_GPIO_BIT),GPIO(PTA3_GPIO_NAME),PORT_CLOCK_MASK(PTA3_GPIO_NAME),(1UL<<PTA3_GPIO_BIT)};
const DigitalIO digitalIO_PTA4     = {&PCR(PTA4_GPIO_NAME,PTA4_GPIO_BIT),GPIO(PTA4_GPIO_NAME),PORT_CLOCK_MASK(PTA4_GPIO_NAME),(1UL<<PTA4_GPIO_BIT)};
const DigitalIO digitalIO_PTA5     = {&PCR(PTA5_GPIO_NAME,PTA5_GPIO_BIT),GPIO(PTA5_GPIO_NAME),PORT_CLOCK_MASK(PTA5_GPIO_NAME),(1UL<<PTA5_GPIO_BIT)};
const DigitalIO digitalIO_PTA12    = {&PCR(PTA12_GPIO_NAME,PTA12_GPIO_BIT),GPIO(PTA12_GPIO_NAME),PORT_CLOCK_MASK(PTA12_GPIO_NAME),(1UL<<PTA12_GPIO_BIT)};
const DigitalIO digitalIO_PTA13    = {&PCR(PTA13_GPIO_NAME,PTA13_GPIO_BIT),GPIO(PTA13_GPIO_NAME),PORT_CLOCK_MASK(PTA13_GPIO_NAME),(1UL<<PTA13_GPIO_BIT)};
const DigitalIO digitalIO_PTA14    = {&PCR(PTA14_GPIO_NAME,PTA14_GPIO_BIT),GPIO(PTA14_GPIO_NAME),PORT_CLOCK_MASK(PTA14_GPIO_NAME),(1UL<<PTA14_GPIO_BIT)};
const DigitalIO digitalIO_PTA15    = {&PCR(PTA15_GPIO_NAME,PTA15_GPIO_BIT),GPIO(PTA15_GPIO_NAME),PORT_CLOCK_MASK(PTA15_GPIO_NAME),(1UL<<PTA15_GPIO_BIT)};
const DigitalIO digitalIO_PTA16    = {&PCR(PTA16_GPIO_NAME,PTA16_GPIO_BIT),GPIO(PTA16_GPIO_NAME),PORT_CLOCK_MASK(PTA16_GPIO_NAME),(1UL<<PTA16_GPIO_BIT)};
const DigitalIO digitalIO_PTA17    = {&PCR(PTA17_GPIO_NAME,PTA17_GPIO_BIT),GPIO(PTA17_GPIO_NAME),PORT_CLOCK_MASK(PTA17_GPIO_NAME),(1UL<<PTA17_GPIO_BIT)};
const DigitalIO digitalIO_PTA18    = {&PCR(PTA18_GPIO_NAME,PTA18_GPIO_BIT),GPIO(PTA18_GPIO_NAME),PORT_CLOCK_MASK(PTA18_GPIO_NAME),(1UL<<PTA18_GPIO_BIT)};
const DigitalIO digitalIO_PTA19    = {&PCR(PTA19_GPIO_NAME,PTA19_GPIO_BIT),GPIO(PTA19_GPIO_NAME),PORT_CLOCK_MASK(PTA19_GPIO_NAME),(1UL<<PTA19_GPIO_BIT)};
const DigitalIO digitalIO_PTA20    = {&PCR(PTA20_GPIO_NAME,PTA20_GPIO_BIT),GPIO(PTA20_GPIO_NAME),PORT_CLOCK_MASK(PTA20_GPIO_NAME),(1UL<<PTA20_GPIO_BIT)};
const DigitalIO digitalIO_PTB0     = {&PCR(PTB0_GPIO_NAME,PTB0_GPIO_BIT),GPIO(PTB0_GPIO_NAME),PORT_CLOCK_MASK(PTB0_GPIO_NAME),(1UL<<PTB0_GPIO_BIT)};
const DigitalIO digitalIO_PTB1     = {&PCR(PTB1_GPIO_NAME,PTB1_GPIO_BIT),GPIO(PTB1_GPIO_NAME),PORT_CLOCK_MASK(PTB1_GPIO_NAME),(1UL<<PTB1_GPIO_BIT)};
const DigitalIO digitalIO_PTB2     = {&PCR(PTB2_GPIO_NAME,PTB2_GPIO_BIT),GPIO(PTB2_GPIO_NAME),PORT_CLOCK_MASK(PTB2_GPIO_NAME),(1UL<<PTB2_GPIO_BIT)};
const DigitalIO digitalIO_PTB3     = {&PCR(PTB3_GPIO_NAME,PTB3_GPIO_BIT),GPIO(PTB3_GPIO_NAME),PORT_CLOCK_MASK(PTB3_GPIO_NAME),(1UL<<PTB3_GPIO_BIT)};
const DigitalIO digitalIO_PTB8     = {&PCR(PTB8_GPIO_NAME,PTB8_GPIO_BIT),GPIO(PTB8_GPIO_NAME),PORT_CLOCK_MASK(PTB8_GPIO_NAME),(1UL<<PTB8_GPIO_BIT)};
const DigitalIO digitalIO_PTB9     = {&PCR(PTB9_GPIO_NAME,PTB9_GPIO_BIT),GPIO(PTB9_GPIO_NAME),PORT_CLOCK_MASK(PTB9_GPIO_NAME),(1UL<<PTB9_GPIO_BIT)};
const DigitalIO digitalIO_PTB10    = {&PCR(PTB10_GPIO_NAME,PTB10_GPIO_BIT),GPIO(PTB10_GPIO_NAME),PORT_CLOCK_MASK(PTB10_GPIO_NAME),(1UL<<PTB10_GPIO_BIT)};
const DigitalIO digitalIO_PTB11    = {&PCR(PTB11_GPIO_NAME,PTB11_GPIO_BIT),GPIO(PTB11_GPIO_NAME),PORT_CLOCK_MASK(PTB11_GPIO_NAME),(1UL<<PTB11_GPIO_BIT)};
const DigitalIO digitalIO_PTB16    = {&PCR(PTB16_GPIO_NAME,PTB16_GPIO_BIT),GPIO(PTB16_GPIO_NAME),PORT_CLOCK_MASK(PTB16_GPIO_NAME),(1UL<<PTB16_GPIO_BIT)};
const DigitalIO digitalIO_PTB17    = {&PCR(PTB17_GPIO_NAME,PTB17_GPIO_BIT),GPIO(PTB17_GPIO_NAME),PORT_CLOCK_MASK(PTB17_GPIO_NAME),(1UL<<PTB17_GPIO_BIT)};
const DigitalIO digitalIO_PTB18    = {&PCR(PTB18_GPIO_NAME,PTB18_GPIO_BIT),GPIO(PTB18_GPIO_NAME),PORT_CLOCK_MASK(PTB18_GPIO_NAME),(1UL<<PTB18_GPIO_BIT)};
const DigitalIO digitalIO_PTB19    = {&PCR(PTB19_GPIO_NAME,PTB19_GPIO_BIT),GPIO(PTB19_GPIO_NAME),PORT_CLOCK_MASK(PTB19_GPIO_NAME),(1UL<<PTB19_GPIO_BIT)};
const DigitalIO digitalIO_PTC0     = {&PCR(PTC0_GPIO_NAME,PTC0_GPIO_BIT),GPIO(PTC0_GPIO_NAME),PORT_CLOCK_MASK(PTC0_GPIO_NAME),(1UL<<PTC0_GPIO_BIT)};
const DigitalIO digitalIO_PTC1     = {&PCR(PTC1_GPIO_NAME,PTC1_GPIO_BIT),GPIO(PTC1_GPIO_NAME),PORT_CLOCK_MASK(PTC1_GPIO_NAME),(1UL<<PTC1_GPIO_BIT)};
const DigitalIO digitalIO_PTC2     = {&PCR(PTC2_GPIO_NAME,PTC2_GPIO_BIT),GPIO(PTC2_GPIO_NAME),PORT_CLOCK_MASK(PTC2_GPIO_NAME),(1UL<<PTC2_GPIO_BIT)};
const DigitalIO digitalIO_PTC3     = {&PCR(PTC3_GPIO_NAME,PTC3_GPIO_BIT),GPIO(PTC3_GPIO_NAME),PORT_CLOCK_MASK(PTC3_GPIO_NAME),(1UL<<PTC3_GPIO_BIT)};
const DigitalIO digitalIO_PTC4     = {&PCR(PTC4_GPIO_NAME,PTC4_GPIO_BIT),GPIO(PTC4_GPIO_NAME),PORT_CLOCK_MASK(PTC4_GPIO_NAME),(1UL<<PTC4_GPIO_BIT)};
const DigitalIO digitalIO_PTC5     = {&PCR(PTC5_GPIO_NAME,PTC5_GPIO_BIT),GPIO(PTC5_GPIO_NAME),PORT_CLOCK_MASK(PTC5_GPIO_NAME),(1UL<<PTC5_GPIO_BIT)};
const DigitalIO digitalIO_PTC6     = {&PCR(PTC6_GPIO_NAME,PTC6_GPIO_BIT),GPIO(PTC6_GPIO_NAME),PORT_CLOCK_MASK(PTC6_GPIO_NAME),(1UL<<PTC6_GPIO_BIT)};
const DigitalIO digitalIO_PTC7     = {&PCR(PTC7_GPIO_NAME,PTC7_GPIO_BIT),GPIO(PTC7_GPIO_NAME),PORT_CLOCK_MASK(PTC7_GPIO_NAME),(1UL<<PTC7_GPIO_BIT)};
const DigitalIO digitalIO_PTC8     = {&PCR(PTC8_GPIO_NAME,PTC8_GPIO_BIT),GPIO(PTC8_GPIO_NAME),PORT_CLOCK_MASK(PTC8_GPIO_NAME),(1UL<<PTC8_GPIO_BIT)};
const DigitalIO digitalIO_PTC9     = {&PCR(PTC9_GPIO_NAME,PTC9_GPIO_BIT),GPIO(PTC9_GPIO_NAME),PORT_CLOCK_MASK(PTC9_GPIO_NAME),(1UL<<PTC9_GPIO_BIT)};
const DigitalIO digitalIO_PTC10    = {&PCR(PTC10_GPIO_NAME,PTC10_GPIO_BIT),GPIO(PTC10_GPIO_NAME),PORT_CLOCK_MASK(PTC10_GPIO_NAME),(1UL<<PTC10_GPIO_BIT)};
const DigitalIO digitalIO_PTC11    = {&PCR(PTC11_GPIO_NAME,PTC11_GPIO_BIT),GPIO(PTC11_GPIO_NAME),PORT_CLOCK_MASK(PTC11_GPIO_NAME),(1UL<<PTC11_GPIO_BIT)};
const DigitalIO digitalIO_PTC12    = {&PCR(PTC12_GPIO_NAME,PTC12_GPIO_BIT),GPIO(PTC12_GPIO_NAME),PORT_CLOCK_MASK(PTC12_GPIO_NAME),(1UL<<PTC12_GPIO_BIT)};
const DigitalIO digitalIO_PTC13    = {&PCR(PTC13_GPIO_NAME,PTC13_GPIO_BIT),GPIO(PTC13_GPIO_NAME),PORT_CLOCK_MASK(PTC13_GPIO_NAME),(1UL<<PTC13_GPIO_BIT)};
const DigitalIO digitalIO_PTC16    = {&PCR(PTC16_GPIO_NAME,PTC16_GPIO_BIT),GPIO(PTC16_GPIO_NAME),PORT_CLOCK_MASK(PTC16_GPIO_NAME),(1UL<<PTC16_GPIO_BIT)};
const DigitalIO digitalIO_PTC17    = {&PCR(PTC17_GPIO_NAME,PTC17_GPIO_BIT),GPIO(PTC17_GPIO_NAME),PORT_CLOCK_MASK(PTC17_GPIO_NAME),(1UL<<PTC17_GPIO_BIT)};
const DigitalIO digitalIO_PTD0     = {&PCR(PTD0_GPIO_NAME,PTD0_GPIO_BIT),GPIO(PTD0_GPIO_NAME),PORT_CLOCK_MASK(PTD0_GPIO_NAME),(1UL<<PTD0_GPIO_BIT)};
const DigitalIO digitalIO_PTD1     = {&PCR(PTD1_GPIO_NAME,PTD1_GPIO_BIT),GPIO(PTD1_GPIO_NAME),PORT_CLOCK_MASK(PTD1_GPIO_NAME),(1UL<<PTD1_GPIO_BIT)};
const DigitalIO digitalIO_PTD2     = {&PCR(PTD2_GPIO_NAME,PTD2_GPIO_BIT),GPIO(PTD2_GPIO_NAME),PORT_CLOCK_MASK(PTD2_GPIO_NAME),(1UL<<PTD2_GPIO_BIT)};
const DigitalIO digitalIO_PTD3     = {&PCR(PTD3_GPIO_NAME,PTD3_GPIO_BIT),GPIO(PTD3_GPIO_NAME),PORT_CLOCK_MASK(PTD3_GPIO_NAME),(1UL<<PTD3_GPIO_BIT)};
const DigitalIO digitalIO_PTD4     = {&PCR(PTD4_GPIO_NAME,PTD4_GPIO_BIT),GPIO(PTD4_GPIO_NAME),PORT_CLOCK_MASK(PTD4_GPIO_NAME),(1UL<<PTD4_GPIO_BIT)};
const DigitalIO digitalIO_PTD5     = {&PCR(PTD5_GPIO_NAME,PTD5_GPIO_BIT),GPIO(PTD5_GPIO_NAME),PORT_CLOCK_MASK(PTD5_GPIO_NAME),(1UL<<PTD5_GPIO_BIT)};
const DigitalIO digitalIO_PTD6     = {&PCR(PTD6_GPIO_NAME,PTD6_GPIO_BIT),GPIO(PTD6_GPIO_NAME),PORT_CLOCK_MASK(PTD6_GPIO_NAME),(1UL<<PTD6_GPIO_BIT)};
const DigitalIO digitalIO_PTD7     = {&PCR(PTD7_GPIO_NAME,PTD7_GPIO_BIT),GPIO(PTD7_GPIO_NAME),PORT_CLOCK_MASK(PTD7_GPIO_NAME),(1UL<<PTD7_GPIO_BIT)};
const DigitalIO digitalIO_PTE0     = {&PCR(PTE0_GPIO_NAME,PTE0_GPIO_BIT),GPIO(PTE0_GPIO_NAME),PORT_CLOCK_MASK(PTE0_GPIO_NAME),(1UL<<PTE0_GPIO_BIT)};
const DigitalIO digitalIO_PTE1     = {&PCR(PTE1_GPIO_NAME,PTE1_GPIO_BIT),GPIO(PTE1_GPIO_NAME),PORT_CLOCK_MASK(PTE1_GPIO_NAME),(1UL<<PTE1_GPIO_BIT)};
const DigitalIO digitalIO_PTE2     = {&PCR(PTE2_GPIO_NAME,PTE2_GPIO_BIT),GPIO(PTE2_GPIO_NAME),PORT_CLOCK_MASK(PTE2_GPIO_NAME),(1UL<<PTE2_GPIO_BIT)};
const DigitalIO digitalIO_PTE3     = {&PCR(PTE3_GPIO_NAME,PTE3_GPIO_BIT),GPIO(PTE3_GPIO_NAME),PORT_CLOCK_MASK(PTE3_GPIO_NAME),(1UL<<PTE3_GPIO_BIT)};
const DigitalIO digitalIO_PTE4     = {&PCR(PTE4_GPIO_NAME,PTE4_GPIO_BIT),GPIO(PTE4_GPIO_NAME),PORT_CLOCK_MASK(PTE4_GPIO_NAME),(1UL<<PTE4_GPIO_BIT)};
const DigitalIO digitalIO_PTE5     = {&PCR(PTE5_GPIO_NAME,PTE5_GPIO_BIT),GPIO(PTE5_GPIO_NAME),PORT_CLOCK_MASK(PTE5_GPIO_NAME),(1UL<<PTE5_GPIO_BIT)};
const DigitalIO digitalIO_PTE20    = {&PCR(PTE20_GPIO_NAME,PTE20_GPIO_BIT),GPIO(PTE20_GPIO_NAME),PORT_CLOCK_MASK(PTE20_GPIO_NAME),(1UL<<PTE20_GPIO_BIT)};
const DigitalIO digitalIO_PTE21    = {&PCR(PTE21_GPIO_NAME,PTE21_GPIO_BIT),GPIO(PTE21_GPIO_NAME),PORT_CLOCK_MASK(PTE21_GPIO_NAME),(1UL<<PTE21_GPIO_BIT)};
const DigitalIO digitalIO_PTE22    = {&PCR(PTE22_GPIO_NAME,PTE22_GPIO_BIT),GPIO(PTE22_GPIO_NAME),PORT_CLOCK_MASK(PTE22_GPIO_NAME),(1UL<<PTE22_GPIO_BIT)};
const DigitalIO digitalIO_PTE23    = {&PCR(PTE23_GPIO_NAME,PTE23_GPIO_BIT),GPIO(PTE23_GPIO_NAME),PORT_CLOCK_MASK(PTE23_GPIO_NAME),(1UL<<PTE23_GPIO_BIT)};
const DigitalIO digitalIO_PTE24    = {&PCR(PTE24_GPIO_NAME,PTE24_GPIO_BIT),GPIO(PTE24_GPIO_NAME),PORT_CLOCK_MASK(PTE24_GPIO_NAME),(1UL<<PTE24_GPIO_BIT)};
const DigitalIO digitalIO_PTE25    = {&PCR(PTE25_GPIO_NAME,PTE25_GPIO_BIT),GPIO(PTE25_GPIO_NAME),PORT_CLOCK_MASK(PTE25_GPIO_NAME),(1UL<<PTE25_GPIO_BIT)};
const DigitalIO digitalIO_PTE29    = {&PCR(PTE29_GPIO_NAME,PTE29_GPIO_BIT),GPIO(PTE29_GPIO_NAME),PORT_CLOCK_MASK(PTE29_GPIO_NAME),(1UL<<PTE29_GPIO_BIT)};
const DigitalIO digitalIO_PTE30    = {&PCR(PTE30_GPIO_NAME,PTE30_GPIO_BIT),GPIO(PTE30_GPIO_NAME),PORT_CLOCK_MASK(PTE30_GPIO_NAME),(1UL<<PTE30_GPIO_BIT)};
const DigitalIO digitalIO_PTE31    = {&PCR(PTE31_GPIO_NAME,PTE31_GPIO_BIT),GPIO(PTE31_GPIO_NAME),PORT_CLOCK_MASK(PTE31_GPIO_NAME),(1UL<<PTE31_GPIO_BIT)};
const AnalogueIO analogueIO_PTB0        = {&digitalIO_PTB0,  ADC(PTB0_ADC_NUM),  &ADC_CLOCK_REG(PTB0_ADC_NUM),  ADC_CLOCK_MASK(PTB0_ADC_NUM),  PTB0_ADC_CH};
const AnalogueIO analogueIO_PTB1        = {&digitalIO_PTB1,  ADC(PTB1_ADC_NUM),  &ADC_CLOCK_REG(PTB1_ADC_NUM),  ADC_CLOCK_MASK(PTB1_ADC_NUM),  PTB1_ADC_CH};
const AnalogueIO analogueIO_PTB2        = {&digitalIO_PTB2,  ADC(PTB2_ADC_NUM),  &ADC_CLOCK_REG(PTB2_ADC_NUM),  ADC_CLOCK_MASK(PTB2_ADC_NUM),  PTB2_ADC_CH};
const AnalogueIO analogueIO_PTB3        = {&digitalIO_PTB3,  ADC(PTB3_ADC_NUM),  &ADC_CLOCK_REG(PTB3_ADC_NUM),  ADC_CLOCK_MASK(PTB3_ADC_NUM),  PTB3_ADC_CH};
const AnalogueIO analogueIO_PTC0        = {&digitalIO_PTC0,  ADC(PTC0_ADC_NUM),  &ADC_CLOCK_REG(PTC0_ADC_NUM),  ADC_CLOCK_MASK(PTC0_ADC_NUM),  PTC0_ADC_CH};
const AnalogueIO analogueIO_PTC1        = {&digitalIO_PTC1,  ADC(PTC1_ADC_NUM),  &ADC_CLOCK_REG(PTC1_ADC_NUM),  ADC_CLOCK_MASK(PTC1_ADC_NUM),  PTC1_ADC_CH};
const AnalogueIO analogueIO_PTC2        = {&digitalIO_PTC2,  ADC(PTC2_ADC_NUM),  &ADC_CLOCK_REG(PTC2_ADC_NUM),  ADC_CLOCK_MASK(PTC2_ADC_NUM),  PTC2_ADC_CH};
const AnalogueIO analogueIO_PTD1        = {&digitalIO_PTD1,  ADC(PTD1_ADC_NUM),  &ADC_CLOCK_REG(PTD1_ADC_NUM),  ADC_CLOCK_MASK(PTD1_ADC_NUM),  PTD1_ADC_CH};
const AnalogueIO analogueIO_PTD5        = {&digitalIO_PTD5,  ADC(PTD5_ADC_NUM),  &ADC_CLOCK_REG(PTD5_ADC_NUM),  ADC_CLOCK_MASK(PTD5_ADC_NUM),  PTD5_ADC_CH};
const AnalogueIO analogueIO_PTD6        = {&digitalIO_PTD6,  ADC(PTD6_ADC_NUM),  &ADC_CLOCK_REG(PTD6_ADC_NUM),  ADC_CLOCK_MASK(PTD6_ADC_NUM),  PTD6_ADC_CH};
const AnalogueIO analogueIO_PTE20       = {&digitalIO_PTE20, ADC(PTE20_ADC_NUM), &ADC_CLOCK_REG(PTE20_ADC_NUM), ADC_CLOCK_MASK(PTE20_ADC_NUM), PTE20_ADC_CH};
const AnalogueIO analogueIO_PTE22       = {&digitalIO_PTE22, ADC(PTE22_ADC_NUM), &ADC_CLOCK_REG(PTE22_ADC_NUM), ADC_CLOCK_MASK(PTE22_ADC_NUM), PTE22_ADC_CH};
const AnalogueIO analogueIO_PTE29       = {&digitalIO_PTE29, ADC(PTE29_ADC_NUM), &ADC_CLOCK_REG(PTE29_ADC_NUM), ADC_CLOCK_MASK(PTE29_ADC_NUM), PTE29_ADC_CH};
const AnalogueIO analogueIO_PTE30       = {&digitalIO_PTE30, ADC(PTE30_ADC_NUM), &ADC_CLOCK_REG(PTE30_ADC_NUM), ADC_CLOCK_MASK(PTE30_ADC_NUM), PTE30_ADC_CH};
#if TPM0_5_SEL == 1
const PwmIO  pwmIO_PTA0      = {&digitalIO_PTA0,   (volatile TPM_Type*)TPM(PTA0_TPM_NUM),  PTA0_TPM_CH,   PORT_PCR_MUX(PTA0_TPM_FN),  &TPM_CLOCK_REG(PTA0_TPM_NUM),  TPM_CLOCK_MASK(PTA0_TPM_NUM)};
#endif
#if TPM2_0_SEL == 1
const PwmIO  pwmIO_PTA1      = {&digitalIO_PTA1,   (volatile TPM_Type*)TPM(PTA1_TPM_NUM),  PTA1_TPM_CH,   PORT_PCR_MUX(PTA1_TPM_FN),  &TPM_CLOCK_REG(PTA1_TPM_NUM),  TPM_CLOCK_MASK(PTA1_TPM_NUM)};
#endif
#if TPM2_1_SEL == 1
const PwmIO  pwmIO_PTA2      = {&digitalIO_PTA2,   (volatile TPM_Type*)TPM(PTA2_TPM_NUM),  PTA2_TPM_CH,   PORT_PCR_MUX(PTA2_TPM_FN),  &TPM_CLOCK_REG(PTA2_TPM_NUM),  TPM_CLOCK_MASK(PTA2_TPM_NUM)};
#endif
#if TPM0_0_SEL == 1
const PwmIO  pwmIO_PTA3      = {&digitalIO_PTA3,   (volatile TPM_Type*)TPM(PTA3_TPM_NUM),  PTA3_TPM_CH,   PORT_PCR_MUX(PTA3_TPM_FN),  &TPM_CLOCK_REG(PTA3_TPM_NUM),  TPM_CLOCK_MASK(PTA3_TPM_NUM)};
#endif
#if TPM0_1_SEL == 1
const PwmIO  pwmIO_PTA4      = {&digitalIO_PTA4,   (volatile TPM_Type*)TPM(PTA4_TPM_NUM),  PTA4_TPM_CH,   PORT_PCR_MUX(PTA4_TPM_FN),  &TPM_CLOCK_REG(PTA4_TPM_NUM),  TPM_CLOCK_MASK(PTA4_TPM_NUM)};
#endif
#if TPM0_2_SEL == 1
const PwmIO  pwmIO_PTA5      = {&digitalIO_PTA5,   (volatile TPM_Type*)TPM(PTA5_TPM_NUM),  PTA5_TPM_CH,   PORT_PCR_MUX(PTA5_TPM_FN),  &TPM_CLOCK_REG(PTA5_TPM_NUM),  TPM_CLOCK_MASK(PTA5_TPM_NUM)};
#endif
#if TPM1_0_SEL == 1
const PwmIO  pwmIO_PTA12     = {&digitalIO_PTA12,  (volatile TPM_Type*)TPM(PTA12_TPM_NUM), PTA12_TPM_CH,  PORT_PCR_MUX(PTA12_TPM_FN), &TPM_CLOCK_REG(PTA12_TPM_NUM), TPM_CLOCK_MASK(PTA12_TPM_NUM)};
#endif
#if TPM1_1_SEL == 1
const PwmIO  pwmIO_PTA13     = {&digitalIO_PTA13,  (volatile TPM_Type*)TPM(PTA13_TPM_NUM), PTA13_TPM_CH,  PORT_PCR_MUX(PTA13_TPM_FN), &TPM_CLOCK_REG(PTA13_TPM_NUM), TPM_CLOCK_MASK(PTA13_TPM_NUM)};
#endif
#if TPM1_0_SEL == 2
const PwmIO  pwmIO_PTB0      = {&digitalIO_PTB0,   (volatile TPM_Type*)TPM(PTB0_TPM_NUM),  PTB0_TPM_CH,   PORT_PCR_MUX(PTB0_TPM_FN),  &TPM_CLOCK_REG(PTB0_TPM_NUM),  TPM_CLOCK_MASK(PTB0_TPM_NUM)};
#endif
#if TPM1_1_SEL == 2
const PwmIO  pwmIO_PTB1      = {&digitalIO_PTB1,   (volatile TPM_Type*)TPM(PTB1_TPM_NUM),  PTB1_TPM_CH,   PORT_PCR_MUX(PTB1_TPM_FN),  &TPM_CLOCK_REG(PTB1_TPM_NUM),  TPM_CLOCK_MASK(PTB1_TPM_NUM)};
#endif
#if TPM2_0_SEL == 2
const PwmIO  pwmIO_PTB2      = {&digitalIO_PTB2,   (volatile TPM_Type*)TPM(PTB2_TPM_NUM),  PTB2_TPM_CH,   PORT_PCR_MUX(PTB2_TPM_FN),  &TPM_CLOCK_REG(PTB2_TPM_NUM),  TPM_CLOCK_MASK(PTB2_TPM_NUM)};
#endif
#if TPM2_1_SEL == 2
const PwmIO  pwmIO_PTB3      = {&digitalIO_PTB3,   (volatile TPM_Type*)TPM(PTB3_TPM_NUM),  PTB3_TPM_CH,   PORT_PCR_MUX(PTB3_TPM_FN),  &TPM_CLOCK_REG(PTB3_TPM_NUM),  TPM_CLOCK_MASK(PTB3_TPM_NUM)};
#endif
#if TPM2_0_SEL == 3
const PwmIO  pwmIO_PTB18     = {&digitalIO_PTB18,  (volatile TPM_Type*)TPM(PTB18_TPM_NUM), PTB18_TPM_CH,  PORT_PCR_MUX(PTB18_TPM_FN), &TPM_CLOCK_REG(PTB18_TPM_NUM), TPM_CLOCK_MASK(PTB18_TPM_NUM)};
#endif
#if TPM2_1_SEL == 3
const PwmIO  pwmIO_PTB19     = {&digitalIO_PTB19,  (volatile TPM_Type*)TPM(PTB19_TPM_NUM), PTB19_TPM_CH,  PORT_PCR_MUX(PTB19_TPM_FN), &TPM_CLOCK_REG(PTB19_TPM_NUM), TPM_CLOCK_MASK(PTB19_TPM_NUM)};
#endif
#if TPM0_0_SEL == 2
const PwmIO  pwmIO_PTC1      = {&digitalIO_PTC1,   (volatile TPM_Type*)TPM(PTC1_TPM_NUM),  PTC1_TPM_CH,   PORT_PCR_MUX(PTC1_TPM_FN),  &TPM_CLOCK_REG(PTC1_TPM_NUM),  TPM_CLOCK_MASK(PTC1_TPM_NUM)};
#endif
#if TPM0_1_SEL == 2
const PwmIO  pwmIO_PTC2      = {&digitalIO_PTC2,   (volatile TPM_Type*)TPM(PTC2_TPM_NUM),  PTC2_TPM_CH,   PORT_PCR_MUX(PTC2_TPM_FN),  &TPM_CLOCK_REG(PTC2_TPM_NUM),  TPM_CLOCK_MASK(PTC2_TPM_NUM)};
#endif
#if TPM0_2_SEL == 2
const PwmIO  pwmIO_PTC3      = {&digitalIO_PTC3,   (volatile TPM_Type*)TPM(PTC3_TPM_NUM),  PTC3_TPM_CH,   PORT_PCR_MUX(PTC3_TPM_FN),  &TPM_CLOCK_REG(PTC3_TPM_NUM),  TPM_CLOCK_MASK(PTC3_TPM_NUM)};
#endif
#if TPM0_3_SEL == 1
const PwmIO  pwmIO_PTC4      = {&digitalIO_PTC4,   (volatile TPM_Type*)TPM(PTC4_TPM_NUM),  PTC4_TPM_CH,   PORT_PCR_MUX(PTC4_TPM_FN),  &TPM_CLOCK_REG(PTC4_TPM_NUM),  TPM_CLOCK_MASK(PTC4_TPM_NUM)};
#endif
#if TPM0_4_SEL == 1
const PwmIO  pwmIO_PTC8      = {&digitalIO_PTC8,   (volatile TPM_Type*)TPM(PTC8_TPM_NUM),  PTC8_TPM_CH,   PORT_PCR_MUX(PTC8_TPM_FN),  &TPM_CLOCK_REG(PTC8_TPM_NUM),  TPM_CLOCK_MASK(PTC8_TPM_NUM)};
#endif
#if TPM0_5_SEL == 2
const PwmIO  pwmIO_PTC9      = {&digitalIO_PTC9,   (volatile TPM_Type*)TPM(PTC9_TPM_NUM),  PTC9_TPM_CH,   PORT_PCR_MUX(PTC9_TPM_FN),  &TPM_CLOCK_REG(PTC9_TPM_NUM),  TPM_CLOCK_MASK(PTC9_TPM_NUM)};
#endif
#if TPM0_0_SEL == 3
const PwmIO  pwmIO_PTD0      = {&digitalIO_PTD0,   (volatile TPM_Type*)TPM(PTD0_TPM_NUM),  PTD0_TPM_CH,   PORT_PCR_MUX(PTD0_TPM_FN),  &TPM_CLOCK_REG(PTD0_TPM_NUM),  TPM_CLOCK_MASK(PTD0_TPM_NUM)};
#endif
#if TPM0_1_SEL == 3
const PwmIO  pwmIO_PTD1      = {&digitalIO_PTD1,   (volatile TPM_Type*)TPM(PTD1_TPM_NUM),  PTD1_TPM_CH,   PORT_PCR_MUX(PTD1_TPM_FN),  &TPM_CLOCK_REG(PTD1_TPM_NUM),  TPM_CLOCK_MASK(PTD1_TPM_NUM)};
#endif
#if TPM0_2_SEL == 3
const PwmIO  pwmIO_PTD2      = {&digitalIO_PTD2,   (volatile TPM_Type*)TPM(PTD2_TPM_NUM),  PTD2_TPM_CH,   PORT_PCR_MUX(PTD2_TPM_FN),  &TPM_CLOCK_REG(PTD2_TPM_NUM),  TPM_CLOCK_MASK(PTD2_TPM_NUM)};
#endif
#if TPM0_3_SEL == 2
const PwmIO  pwmIO_PTD3      = {&digitalIO_PTD3,   (volatile TPM_Type*)TPM(PTD3_TPM_NUM),  PTD3_TPM_CH,   PORT_PCR_MUX(PTD3_TPM_FN),  &TPM_CLOCK_REG(PTD3_TPM_NUM),  TPM_CLOCK_MASK(PTD3_TPM_NUM)};
#endif
#if TPM0_4_SEL == 2
const PwmIO  pwmIO_PTD4      = {&digitalIO_PTD4,   (volatile TPM_Type*)TPM(PTD4_TPM_NUM),  PTD4_TPM_CH,   PORT_PCR_MUX(PTD4_TPM_FN),  &TPM_CLOCK_REG(PTD4_TPM_NUM),  TPM_CLOCK_MASK(PTD4_TPM_NUM)};
#endif
#if TPM0_5_SEL == 3
const PwmIO  pwmIO_PTD5      = {&digitalIO_PTD5,   (volatile TPM_Type*)TPM(PTD5_TPM_NUM),  PTD5_TPM_CH,   PORT_PCR_MUX(PTD5_TPM_FN),  &TPM_CLOCK_REG(PTD5_TPM_NUM),  TPM_CLOCK_MASK(PTD5_TPM_NUM)};
#endif
#if TPM1_0_SEL == 3
const PwmIO  pwmIO_PTE20     = {&digitalIO_PTE20,  (volatile TPM_Type*)TPM(PTE20_TPM_NUM), PTE20_TPM_CH,  PORT_PCR_MUX(PTE20_TPM_FN), &TPM_CLOCK_REG(PTE20_TPM_NUM), TPM_CLOCK_MASK(PTE20_TPM_NUM)};
#endif
#if TPM1_1_SEL == 3
const PwmIO  pwmIO_PTE21     = {&digitalIO_PTE21,  (volatile TPM_Type*)TPM(PTE21_TPM_NUM), PTE21_TPM_CH,  PORT_PCR_MUX(PTE21_TPM_FN), &TPM_CLOCK_REG(PTE21_TPM_NUM), TPM_CLOCK_MASK(PTE21_TPM_NUM)};
#endif
#if TPM2_0_SEL == 4
const PwmIO  pwmIO_PTE22     = {&digitalIO_PTE22,  (volatile TPM_Type*)TPM(PTE22_TPM_NUM), PTE22_TPM_CH,  PORT_PCR_MUX(PTE22_TPM_FN), &TPM_CLOCK_REG(PTE22_TPM_NUM), TPM_CLOCK_MASK(PTE22_TPM_NUM)};
#endif
#if TPM2_1_SEL == 4
const PwmIO  pwmIO_PTE23     = {&digitalIO_PTE23,  (volatile TPM_Type*)TPM(PTE23_TPM_NUM), PTE23_TPM_CH,  PORT_PCR_MUX(PTE23_TPM_FN), &TPM_CLOCK_REG(PTE23_TPM_NUM), TPM_CLOCK_MASK(PTE23_TPM_NUM)};
#endif
#if TPM0_0_SEL == 4
const PwmIO  pwmIO_PTE24     = {&digitalIO_PTE24,  (volatile TPM_Type*)TPM(PTE24_TPM_NUM), PTE24_TPM_CH,  PORT_PCR_MUX(PTE24_TPM_FN), &TPM_CLOCK_REG(PTE24_TPM_NUM), TPM_CLOCK_MASK(PTE24_TPM_NUM)};
#endif
#if TPM0_1_SEL == 4
const PwmIO  pwmIO_PTE25     = {&digitalIO_PTE25,  (volatile TPM_Type*)TPM(PTE25_TPM_NUM), PTE25_TPM_CH,  PORT_PCR_MUX(PTE25_TPM_FN), &TPM_CLOCK_REG(PTE25_TPM_NUM), TPM_CLOCK_MASK(PTE25_TPM_NUM)};
#endif
#if TPM0_2_SEL == 4
const PwmIO  pwmIO_PTE29     = {&digitalIO_PTE29,  (volatile TPM_Type*)TPM(PTE29_TPM_NUM), PTE29_TPM_CH,  PORT_PCR_MUX(PTE29_TPM_FN), &TPM_CLOCK_REG(PTE29_TPM_NUM), TPM_CLOCK_MASK(PTE29_TPM_NUM)};
#endif
#if TPM0_3_SEL == 3
const PwmIO  pwmIO_PTE30     = {&digitalIO_PTE30,  (volatile TPM_Type*)TPM(PTE30_TPM_NUM), PTE30_TPM_CH,  PORT_PCR_MUX(PTE30_TPM_FN), &TPM_CLOCK_REG(PTE30_TPM_NUM), TPM_CLOCK_MASK(PTE30_TPM_NUM)};
#endif
#if TPM0_4_SEL == 3
const PwmIO  pwmIO_PTE31     = {&digitalIO_PTE31,  (volatile TPM_Type*)TPM(PTE31_TPM_NUM), PTE31_TPM_CH,  PORT_PCR_MUX(PTE31_TPM_FN), &TPM_CLOCK_REG(PTE31_TPM_NUM), TPM_CLOCK_MASK(PTE31_TPM_NUM)};
#endif