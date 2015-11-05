/**
 * @file      gpio.h (derived from gpio-MKL25Z4.h)
 * @version   1.0.0
 * @brief     Pin declarations for MKL25Z4
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "derivative.h"
#include "pin_mapping.h"
#include "gpio_defs.h"

/**
* @addtogroup DigitalIO_Group Digital Input/Output
* @brief Allows use of port pins as simple digital inputs or outputs
* @{
*/
extern const DigitalIO digitalIO_PTA0;          //!< DigitalIO on pin PTA0
extern const DigitalIO digitalIO_PTA1;          //!< DigitalIO on pin PTA1
#define digitalIO_D0         digitalIO_PTA1
extern const DigitalIO digitalIO_PTA2;          //!< DigitalIO on pin PTA2
#define digitalIO_D1         digitalIO_PTA2
extern const DigitalIO digitalIO_PTA3;          //!< DigitalIO on pin PTA3
extern const DigitalIO digitalIO_PTA4;          //!< DigitalIO on pin PTA4
#define digitalIO_D4         digitalIO_PTA4
extern const DigitalIO digitalIO_PTA5;          //!< DigitalIO on pin PTA5
#define digitalIO_D5         digitalIO_PTA5
extern const DigitalIO digitalIO_PTA12;         //!< DigitalIO on pin PTA12
#define digitalIO_D3         digitalIO_PTA12
extern const DigitalIO digitalIO_PTA13;         //!< DigitalIO on pin PTA13
#define digitalIO_D8         digitalIO_PTA13
extern const DigitalIO digitalIO_PTA14;         //!< DigitalIO on pin PTA14
extern const DigitalIO digitalIO_PTA15;         //!< DigitalIO on pin PTA15
extern const DigitalIO digitalIO_PTA16;         //!< DigitalIO on pin PTA16
#define digitalIO_D28        digitalIO_PTA16
extern const DigitalIO digitalIO_PTA17;         //!< DigitalIO on pin PTA17
#define digitalIO_D29        digitalIO_PTA17
extern const DigitalIO digitalIO_PTA18;         //!< DigitalIO on pin PTA18
extern const DigitalIO digitalIO_PTA19;         //!< DigitalIO on pin PTA19
extern const DigitalIO digitalIO_PTA20;         //!< DigitalIO on pin PTA20
extern const DigitalIO digitalIO_PTB0;          //!< DigitalIO on pin PTB0
#define digitalIO_A0         digitalIO_PTB0
extern const DigitalIO digitalIO_PTB1;          //!< DigitalIO on pin PTB1
#define digitalIO_A1         digitalIO_PTB1
extern const DigitalIO digitalIO_PTB2;          //!< DigitalIO on pin PTB2
#define digitalIO_A2         digitalIO_PTB2
extern const DigitalIO digitalIO_PTB3;          //!< DigitalIO on pin PTB3
#define digitalIO_A3         digitalIO_PTB3
extern const DigitalIO digitalIO_PTB8;          //!< DigitalIO on pin PTB8
#define digitalIO_A20        digitalIO_PTB8
extern const DigitalIO digitalIO_PTB9;          //!< DigitalIO on pin PTB9
#define digitalIO_A19        digitalIO_PTB9
extern const DigitalIO digitalIO_PTB10;         //!< DigitalIO on pin PTB10
#define digitalIO_A18        digitalIO_PTB10
extern const DigitalIO digitalIO_PTB11;         //!< DigitalIO on pin PTB11
#define digitalIO_A17        digitalIO_PTB11
extern const DigitalIO digitalIO_PTB16;         //!< DigitalIO on pin PTB16
extern const DigitalIO digitalIO_PTB17;         //!< DigitalIO on pin PTB17
extern const DigitalIO digitalIO_PTB18;         //!< DigitalIO on pin PTB18
#define digitalIO_LED_RED    digitalIO_PTB18
extern const DigitalIO digitalIO_PTB19;         //!< DigitalIO on pin PTB19
#define digitalIO_LED_GREEN  digitalIO_PTB19
extern const DigitalIO digitalIO_PTC0;          //!< DigitalIO on pin PTC0
#define digitalIO_D17        digitalIO_PTC0
extern const DigitalIO digitalIO_PTC1;          //!< DigitalIO on pin PTC1
#define digitalIO_A5         digitalIO_PTC1
extern const DigitalIO digitalIO_PTC2;          //!< DigitalIO on pin PTC2
#define digitalIO_A4         digitalIO_PTC2
extern const DigitalIO digitalIO_PTC3;          //!< DigitalIO on pin PTC3
#define digitalIO_D18        digitalIO_PTC3
extern const DigitalIO digitalIO_PTC4;          //!< DigitalIO on pin PTC4
#define digitalIO_D19        digitalIO_PTC4
extern const DigitalIO digitalIO_PTC5;          //!< DigitalIO on pin PTC5
#define digitalIO_D20        digitalIO_PTC5
extern const DigitalIO digitalIO_PTC6;          //!< DigitalIO on pin PTC6
#define digitalIO_D21        digitalIO_PTC6
extern const DigitalIO digitalIO_PTC7;          //!< DigitalIO on pin PTC7
#define digitalIO_D16        digitalIO_PTC7
extern const DigitalIO digitalIO_PTC8;          //!< DigitalIO on pin PTC8
#define digitalIO_D6         digitalIO_PTC8
extern const DigitalIO digitalIO_PTC9;          //!< DigitalIO on pin PTC9
#define digitalIO_D7         digitalIO_PTC9
extern const DigitalIO digitalIO_PTC10;         //!< DigitalIO on pin PTC10
#define digitalIO_D22        digitalIO_PTC10
extern const DigitalIO digitalIO_PTC11;         //!< DigitalIO on pin PTC11
#define digitalIO_D23        digitalIO_PTC11
extern const DigitalIO digitalIO_PTC12;         //!< DigitalIO on pin PTC12
#define digitalIO_D24        digitalIO_PTC12
extern const DigitalIO digitalIO_PTC13;         //!< DigitalIO on pin PTC13
#define digitalIO_D25        digitalIO_PTC13
extern const DigitalIO digitalIO_PTC16;         //!< DigitalIO on pin PTC16
#define digitalIO_D26        digitalIO_PTC16
extern const DigitalIO digitalIO_PTC17;         //!< DigitalIO on pin PTC17
#define digitalIO_D27        digitalIO_PTC17
extern const DigitalIO digitalIO_PTD0;          //!< DigitalIO on pin PTD0
#define digitalIO_D10        digitalIO_PTD0
extern const DigitalIO digitalIO_PTD1;          //!< DigitalIO on pin PTD1
#define digitalIO_D13        digitalIO_PTD1
#define digitalIO_LED_BLUE   digitalIO_PTD1
extern const DigitalIO digitalIO_PTD2;          //!< DigitalIO on pin PTD2
#define digitalIO_D11        digitalIO_PTD2
extern const DigitalIO digitalIO_PTD3;          //!< DigitalIO on pin PTD3
#define digitalIO_D12        digitalIO_PTD3
extern const DigitalIO digitalIO_PTD4;          //!< DigitalIO on pin PTD4
#define digitalIO_D2         digitalIO_PTD4
extern const DigitalIO digitalIO_PTD5;          //!< DigitalIO on pin PTD5
#define digitalIO_D9         digitalIO_PTD5
extern const DigitalIO digitalIO_PTD6;          //!< DigitalIO on pin PTD6
#define digitalIO_D32        digitalIO_PTD6
extern const DigitalIO digitalIO_PTD7;          //!< DigitalIO on pin PTD7
#define digitalIO_D33        digitalIO_PTD7
extern const DigitalIO digitalIO_PTE0;          //!< DigitalIO on pin PTE0
#define digitalIO_D15        digitalIO_PTE0
extern const DigitalIO digitalIO_PTE1;          //!< DigitalIO on pin PTE1
#define digitalIO_D14        digitalIO_PTE1
extern const DigitalIO digitalIO_PTE2;          //!< DigitalIO on pin PTE2
#define digitalIO_A16        digitalIO_PTE2
extern const DigitalIO digitalIO_PTE3;          //!< DigitalIO on pin PTE3
#define digitalIO_A15        digitalIO_PTE3
extern const DigitalIO digitalIO_PTE4;          //!< DigitalIO on pin PTE4
#define digitalIO_A14        digitalIO_PTE4
extern const DigitalIO digitalIO_PTE5;          //!< DigitalIO on pin PTE5
#define digitalIO_A13        digitalIO_PTE5
extern const DigitalIO digitalIO_PTE20;         //!< DigitalIO on pin PTE20
#define digitalIO_A11        digitalIO_PTE20
extern const DigitalIO digitalIO_PTE21;         //!< DigitalIO on pin PTE21
#define digitalIO_A10        digitalIO_PTE21
extern const DigitalIO digitalIO_PTE22;         //!< DigitalIO on pin PTE22
#define digitalIO_A9         digitalIO_PTE22
extern const DigitalIO digitalIO_PTE23;         //!< DigitalIO on pin PTE23
#define digitalIO_A8         digitalIO_PTE23
extern const DigitalIO digitalIO_PTE24;         //!< DigitalIO on pin PTE24
extern const DigitalIO digitalIO_PTE25;         //!< DigitalIO on pin PTE25
extern const DigitalIO digitalIO_PTE29;         //!< DigitalIO on pin PTE29
#define digitalIO_A7         digitalIO_PTE29
extern const DigitalIO digitalIO_PTE30;         //!< DigitalIO on pin PTE30
#define digitalIO_A6         digitalIO_PTE30
extern const DigitalIO digitalIO_PTE31;         //!< DigitalIO on pin PTE31
#define digitalIO_D30        digitalIO_PTE31
/**
 * @}
 */
/**
* @addtogroup AnalogueIO_Group Analogue Input
* @brief Allows use of port pins as analogue inputs
* @{
*/
#if (PTB0_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE8;     //!< AnalogueIO on pin PTB0
#define analogueIO_A0        analogueIO_ADC0_SE8
#endif
#if (PTB1_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE9;     //!< AnalogueIO on pin PTB1
#define analogueIO_A1        analogueIO_ADC0_SE9
#endif
#if (PTB2_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE12;    //!< AnalogueIO on pin PTB2
#define analogueIO_A2        analogueIO_ADC0_SE12
#endif
#if (PTB3_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE13;    //!< AnalogueIO on pin PTB3
#define analogueIO_A3        analogueIO_ADC0_SE13
#endif
#if (PTC0_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE14;    //!< AnalogueIO on pin PTC0
#define analogueIO_D17       analogueIO_ADC0_SE14
#endif
#if (PTC1_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE15;    //!< AnalogueIO on pin PTC1
#define analogueIO_A5        analogueIO_ADC0_SE15
#endif
#if (PTC2_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE11;    //!< AnalogueIO on pin PTC2
#define analogueIO_A4        analogueIO_ADC0_SE11
#endif
#if (PTD1_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE5b;    //!< AnalogueIO on pin PTD1
#define analogueIO_D13       analogueIO_ADC0_SE5b
#define analogueIO_LED_BLUE  analogueIO_ADC0_SE5b
#endif
#if (PTD5_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE6b;    //!< AnalogueIO on pin PTD5
#define analogueIO_D9        analogueIO_ADC0_SE6b
#endif
#if (PTD6_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE7b;    //!< AnalogueIO on pin PTD6
#define analogueIO_D32       analogueIO_ADC0_SE7b
#endif
#if (PTE20_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE0;     //!< AnalogueIO on pin PTE20
#define analogueIO_A11       analogueIO_ADC0_SE0
#endif
#if (PTE21_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE4a;    //!< AnalogueIO on pin PTE21
#define analogueIO_A10       analogueIO_ADC0_SE4a
#endif
#if (PTE22_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE3;     //!< AnalogueIO on pin PTE22
#define analogueIO_A9        analogueIO_ADC0_SE3
#endif
#if (PTE23_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE7a;    //!< AnalogueIO on pin PTE23
#define analogueIO_A8        analogueIO_ADC0_SE7a
#endif
#if (PTE29_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE4b;    //!< AnalogueIO on pin PTE29
#define analogueIO_A7        analogueIO_ADC0_SE4b
#endif
#if (PTE30_SIG_SEL == 0)
extern const AnalogueIO analogueIO_ADC0_SE23;    //!< AnalogueIO on pin PTE30
#define analogueIO_A6        analogueIO_ADC0_SE23
#endif
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
#if (PTA0_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM0_CH5;          //!< PwmIO on pin PTA0
#endif
#if (PTA1_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM2_CH0;          //!< PwmIO on pin PTA1
#define pwmIO_D0             pwmIO_TPM2_CH0
#endif
#if (PTA2_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM2_CH1;          //!< PwmIO on pin PTA2
#define pwmIO_D1             pwmIO_TPM2_CH1
#endif
#if (PTA3_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM0_CH0;          //!< PwmIO on pin PTA3
#endif
#if (PTA4_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM0_CH1;          //!< PwmIO on pin PTA4
#define pwmIO_D4             pwmIO_TPM0_CH1
#endif
#if (PTA5_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM0_CH2;          //!< PwmIO on pin PTA5
#define pwmIO_D5             pwmIO_TPM0_CH2
#endif
#if (PTA12_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM1_CH0;          //!< PwmIO on pin PTA12
#define pwmIO_D3             pwmIO_TPM1_CH0
#endif
#if (PTA13_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM1_CH1;          //!< PwmIO on pin PTA13
#define pwmIO_D8             pwmIO_TPM1_CH1
#endif
#if (PTB0_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM1_CH0;          //!< PwmIO on pin PTB0
#define pwmIO_A0             pwmIO_TPM1_CH0
#endif
#if (PTB1_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM1_CH1;          //!< PwmIO on pin PTB1
#define pwmIO_A1             pwmIO_TPM1_CH1
#endif
#if (PTB2_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM2_CH0;          //!< PwmIO on pin PTB2
#define pwmIO_A2             pwmIO_TPM2_CH0
#endif
#if (PTB3_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM2_CH1;          //!< PwmIO on pin PTB3
#define pwmIO_A3             pwmIO_TPM2_CH1
#endif
#if (PTB18_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM2_CH0;          //!< PwmIO on pin PTB18
#define pwmIO_LED_RED        pwmIO_TPM2_CH0
#endif
#if (PTB19_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM2_CH1;          //!< PwmIO on pin PTB19
#define pwmIO_LED_GREEN      pwmIO_TPM2_CH1
#endif
#if (PTC1_SIG_SEL == 4)
extern const PwmIO pwmIO_TPM0_CH0;          //!< PwmIO on pin PTC1
#define pwmIO_A5             pwmIO_TPM0_CH0
#endif
#if (PTC2_SIG_SEL == 4)
extern const PwmIO pwmIO_TPM0_CH1;          //!< PwmIO on pin PTC2
#define pwmIO_A4             pwmIO_TPM0_CH1
#endif
#if (PTC3_SIG_SEL == 4)
extern const PwmIO pwmIO_TPM0_CH2;          //!< PwmIO on pin PTC3
#define pwmIO_D18            pwmIO_TPM0_CH2
#endif
#if (PTC4_SIG_SEL == 4)
extern const PwmIO pwmIO_TPM0_CH3;          //!< PwmIO on pin PTC4
#define pwmIO_D19            pwmIO_TPM0_CH3
#endif
#if (PTC8_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM0_CH4;          //!< PwmIO on pin PTC8
#define pwmIO_D6             pwmIO_TPM0_CH4
#endif
#if (PTC9_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM0_CH5;          //!< PwmIO on pin PTC9
#define pwmIO_D7             pwmIO_TPM0_CH5
#endif
#if (PTD0_SIG_SEL == 4)
extern const PwmIO pwmIO_TPM0_CH0;          //!< PwmIO on pin PTD0
#define pwmIO_D10            pwmIO_TPM0_CH0
#endif
#if (PTD1_SIG_SEL == 4)
extern const PwmIO pwmIO_TPM0_CH1;          //!< PwmIO on pin PTD1
#define pwmIO_D13            pwmIO_TPM0_CH1
#define pwmIO_LED_BLUE       pwmIO_TPM0_CH1
#endif
#if (PTD2_SIG_SEL == 4)
extern const PwmIO pwmIO_TPM0_CH2;          //!< PwmIO on pin PTD2
#define pwmIO_D11            pwmIO_TPM0_CH2
#endif
#if (PTD3_SIG_SEL == 4)
extern const PwmIO pwmIO_TPM0_CH3;          //!< PwmIO on pin PTD3
#define pwmIO_D12            pwmIO_TPM0_CH3
#endif
#if (PTD4_SIG_SEL == 4)
extern const PwmIO pwmIO_TPM0_CH4;          //!< PwmIO on pin PTD4
#define pwmIO_D2             pwmIO_TPM0_CH4
#endif
#if (PTD5_SIG_SEL == 4)
extern const PwmIO pwmIO_TPM0_CH5;          //!< PwmIO on pin PTD5
#define pwmIO_D9             pwmIO_TPM0_CH5
#endif
#if (PTE20_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM1_CH0;          //!< PwmIO on pin PTE20
#define pwmIO_A11            pwmIO_TPM1_CH0
#endif
#if (PTE21_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM1_CH1;          //!< PwmIO on pin PTE21
#define pwmIO_A10            pwmIO_TPM1_CH1
#endif
#if (PTE22_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM2_CH0;          //!< PwmIO on pin PTE22
#define pwmIO_A9             pwmIO_TPM2_CH0
#endif
#if (PTE23_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM2_CH1;          //!< PwmIO on pin PTE23
#define pwmIO_A8             pwmIO_TPM2_CH1
#endif
#if (PTE24_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM0_CH0;          //!< PwmIO on pin PTE24
#endif
#if (PTE25_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM0_CH1;          //!< PwmIO on pin PTE25
#endif
#if (PTE29_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM0_CH2;          //!< PwmIO on pin PTE29
#define pwmIO_A7             pwmIO_TPM0_CH2
#endif
#if (PTE30_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM0_CH3;          //!< PwmIO on pin PTE30
#define pwmIO_A6             pwmIO_TPM0_CH3
#endif
#if (PTE31_SIG_SEL == 3)
extern const PwmIO pwmIO_TPM0_CH4;          //!< PwmIO on pin PTE31
#define pwmIO_D30            pwmIO_TPM0_CH4
#endif
/**
 * @}
 */
#if defined(DO_MAP_PINS_ON_RESET) && (DO_MAP_PINS_ON_RESET>0)
/**
 * Used to configure pin-mapping before 1st use of peripherals
 */
extern void usbdm_PinMapping();
#endif

/*
Clock Information 
ADC0       SIM->SCGC6   SIM_SCGC6_ADC0_MASK
CMP        SIM->SCGC4   SIM_SCGC4_CMP_MASK
DAC0       SIM->SCGC6   SIM_SCGC6_DAC0_MASK
DMA        SIM->SCGC7   SIM_SCGC7_DMA_MASK
DMAMUX     SIM->SCGC6   SIM_SCGC6_DMAMUX_MASK
I2C0       SIM->SCGC4   SIM_SCGC4_I2C0_MASK
I2C1       SIM->SCGC4   SIM_SCGC4_I2C1_MASK
LPTMR0     SIM->SCGC5   SIM_SCGC5_LPTMR_MASK
PIT        SIM->SCGC6   SIM_SCGC6_PIT_MASK
PORTA      SIM->SCGC5   SIM_SCGC5_PORTA_MASK
PORTB      SIM->SCGC5   SIM_SCGC5_PORTB_MASK
PORTC      SIM->SCGC5   SIM_SCGC5_PORTC_MASK
PORTD      SIM->SCGC5   SIM_SCGC5_PORTD_MASK
PORTE      SIM->SCGC5   SIM_SCGC5_PORTE_MASK
RTC        SIM->SCGC6   SIM_SCGC6_RTC_MASK
SPI0       SIM->SCGC4   SIM_SCGC4_SPI0_MASK
SPI1       SIM->SCGC4   SIM_SCGC4_SPI1_MASK
TPM0       SIM->SCGC6   SIM_SCGC6_TPM0_MASK
TPM1       SIM->SCGC6   SIM_SCGC6_TPM1_MASK
TPM2       SIM->SCGC6   SIM_SCGC6_TPM2_MASK
TSI        SIM->SCGC5   SIM_SCGC5_TSI_MASK
UART0      SIM->SCGC4   SIM_SCGC4_UART0_MASK
UART1      SIM->SCGC4   SIM_SCGC4_UART1_MASK
UART2      SIM->SCGC4   SIM_SCGC4_UART2_MASK
USBOTG     SIM->SCGC4   SIM_SCGC4_USBOTG_MASK
*/


#endif /* GPIO_H_ */
