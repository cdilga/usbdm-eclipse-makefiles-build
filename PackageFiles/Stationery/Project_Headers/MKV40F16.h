/****************************************************************************************************//**
 * @file     MKV40F16.h
 *
 * @brief    CMSIS Cortex-M Peripheral Access Layer Header File for MKV40F16.
 *           Equivalent: 
 *
 * @version  V1.6
 * @date     2017/09
 *
 *******************************************************************************************************/

#ifndef MCU_MKV40F16
#define MCU_MKV40F16

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
* @addtogroup Interrupt_vector_numbers_GROUP Interrupt vector numbers
* @brief Vector numbers required for NVIC functions
* @{
*/
/* -------------------------  Interrupt Number Definition  ------------------------ */

/**
 * Interrupt vector numbers
 */
typedef enum {
/* ------------------------  Processor Exceptions Numbers  ------------------------- */
  Reset_IRQn                    = -15,   /**<   1 Reset Vector, invoked on Power up and warm reset                                 */
  NonMaskableInt_IRQn           = -14,   /**<   2 Non maskable Interrupt, cannot be stopped or preempted                           */
  HardFault_IRQn                = -13,   /**<   3 Hard Fault, all classes of Fault                                                 */
  MemoryManagement_IRQn         = -12,   /**<   4 Memory Management, MPU mismatch, including Access Violation and No Match         */
  BusFault_IRQn                 = -11,   /**<   5 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault   */
  UsageFault_IRQn               = -10,   /**<   6 Usage Fault, i.e. Undef Instruction, Illegal State Transition                    */
  SVCall_IRQn                   =  -5,   /**<  11 System Service Call via SVC instruction                                          */
  DebugMonitor_IRQn             =  -4,   /**<  12 Debug Monitor                                                                    */
  PendSV_IRQn                   =  -2,   /**<  14 Pendable request for system service                                              */
  SysTick_IRQn                  =  -1,   /**<  15 System Tick Timer                                                                */
/* ----------------------   MKV40F16 VectorTable                     ---------------------- */
  DMA0_IRQn                     =   0,   /**<  16 Direct memory access controller                                                  */
  DMA1_IRQn                     =   1,   /**<  17 Direct memory access controller                                                  */
  DMA2_IRQn                     =   2,   /**<  18 Direct memory access controller                                                  */
  DMA3_IRQn                     =   3,   /**<  19 Direct memory access controller                                                  */
  DMA4_IRQn                     =   4,   /**<  20 Direct memory access controller                                                  */
  DMA5_IRQn                     =   5,   /**<  21 Direct memory access controller                                                  */
  DMA6_IRQn                     =   6,   /**<  22 Direct memory access controller                                                  */
  DMA7_IRQn                     =   7,   /**<  23 Direct memory access controller                                                  */
  DMA8_IRQn                     =   8,   /**<  24 Direct memory access controller                                                  */
  DMA9_IRQn                     =   9,   /**<  25 Direct memory access controller                                                  */
  DMA10_IRQn                    =  10,   /**<  26 Direct memory access controller                                                  */
  DMA11_IRQn                    =  11,   /**<  27 Direct memory access controller                                                  */
  DMA12_IRQn                    =  12,   /**<  28 Direct memory access controller                                                  */
  DMA13_IRQn                    =  13,   /**<  29 Direct memory access controller                                                  */
  DMA14_IRQn                    =  14,   /**<  30 Direct memory access controller                                                  */
  DMA15_IRQn                    =  15,   /**<  31 Direct memory access controller                                                  */
  DMA_Error_IRQn                =  16,   /**<  32 Direct memory access controller                                                  */
  MCM_IRQn                      =  17,   /**<  33 Miscellaneous Control Module                                                     */
  FTF_Command_IRQn              =  18,   /**<  34 Flash Memory Interface                                                           */
  FTF_ReadCollision_IRQn        =  19,   /**<  35 Flash Memory Interface                                                           */
  PMC_IRQn                      =  20,   /**<  36 Power Management Controller                                                      */
  LLWU_IRQn                     =  21,   /**<  37 Low Leakage Wakeup                                                               */
  WDOG_IRQn                     =  22,   /**<  38 External Watchdog Monitor                                                        */
  I2C0_IRQn                     =  24,   /**<  40 Inter-Integrated Circuit                                                         */
  SPI_IRQn                      =  26,   /**<  42 Serial Peripheral Interface                                                      */
  UART0_RX_TX_IRQn              =  31,   /**<  47 Serial Communication Interface                                                   */
  UART0_ERR_IRQn                =  32,   /**<  48 Serial Communication Interface                                                   */
  UART1_RX_TX_IRQn              =  33,   /**<  49 Serial Communication Interface                                                   */
  UART1_ERR_IRQn                =  34,   /**<  50 Serial Communication Interface                                                   */
  ADC_ERR_IRQn                  =  38,   /**<  54 Analogue to digital converter                                                    */
  ADCA_IRQn                     =  39,   /**<  55 Analogue to digital converter                                                    */
  CMP0_IRQn                     =  40,   /**<  56 High-Speed Comparator                                                            */
  CMP1_IRQn                     =  41,   /**<  57 High-Speed Comparator                                                            */
  FTM0_IRQn                     =  42,   /**<  58 FlexTimer Module                                                                 */
  FTM1_IRQn                     =  43,   /**<  59 FlexTimer Module                                                                 */
  PIT0_IRQn                     =  48,   /**<  64 Periodic Interrupt Timer                                                         */
  PIT1_IRQn                     =  49,   /**<  65 Periodic Interrupt Timer                                                         */
  PIT2_IRQn                     =  50,   /**<  66 Periodic Interrupt Timer                                                         */
  PIT3_IRQn                     =  51,   /**<  67 Periodic Interrupt Timer                                                         */
  PDB0_IRQn                     =  52,   /**<  68 Programmable Delay Block                                                         */
  XBARA_IRQn                    =  54,   /**<  70 Crossbar Switch                                                                  */
  PDB1_IRQn                     =  55,   /**<  71 Programmable Delay Block                                                         */
  MCG_IRQn                      =  57,   /**<  73 Multipurpose Clock Generator                                                     */
  LPTMR0_IRQn                   =  58,   /**<  74 Low Power Timer                                                                  */
  PORTA_IRQn                    =  59,   /**<  75 General Purpose Input/Output                                                     */
  PORTB_IRQn                    =  60,   /**<  76 General Purpose Input/Output                                                     */
  PORTC_IRQn                    =  61,   /**<  77 General Purpose Input/Output                                                     */
  PORTD_IRQn                    =  62,   /**<  78 General Purpose Input/Output                                                     */
  PORTE_IRQn                    =  63,   /**<  79 General Purpose Input/Output                                                     */
  ENC_COMPARE_IRQn              =  66,   /**<  82 Quadrature Decoder                                                               */
  ENC_HOME_IRQn                 =  67,   /**<  83 Quadrature Decoder                                                               */
  ENC_WDOG_SAB_IRQn             =  68,   /**<  84 Quadrature Decoder                                                               */
  ENC_INDEX_IRQn                =  69,   /**<  85 Quadrature Decoder                                                               */
  CMP2_IRQn                     =  70,   /**<  86 High-Speed Comparator                                                            */
  FTM3_IRQn                     =  71,   /**<  87 FlexTimer Module                                                                 */
  ADCB_IRQn                     =  73,   /**<  89 Analogue to digital converter                                                    */
  CAN0_Message_IRQn             =  75,   /**<  91 Flex Controller Area Network module                                              */
  CAN0_BusOff_IRQn              =  76,   /**<  92 Flex Controller Area Network module                                              */
  CAN0_Error_IRQn               =  77,   /**<  93 Flex Controller Area Network module                                              */
  CAN0_Tx_IRQn                  =  78,   /**<  94 Flex Controller Area Network module                                              */
  CAN0_Rx_IRQn                  =  79,   /**<  95 Flex Controller Area Network module                                              */
  CAN0_WakeUp_IRQn              =  80,   /**<  96 Flex Controller Area Network module                                              */
  CMP3_IRQn                     =  92,   /**< 108 High-Speed Comparator                                                            */
  CAN1_Message_IRQn             =  94,   /**< 110 Flex Controller Area Network module                                              */
  CAN1_BusOff_IRQn              =  95,   /**< 111 Flex Controller Area Network module                                              */
  CAN1_Error_IRQn               =  96,   /**< 112 Flex Controller Area Network module                                              */
  CAN1_Tx_IRQn                  =  97,   /**< 113 Flex Controller Area Network module                                              */
  CAN1_Rx_IRQn                  =  98,   /**< 114 Flex Controller Area Network module                                              */
  CAN1_WakeUp_IRQn              =  99,   /**< 115 Flex Controller Area Network module                                              */
} IRQn_Type;

/**
 * @} */ /* End group Interrupt_vector_numbers_GROUP 
 */
/**
* @addtogroup Interrupt_handler_prototypes_GROUP Interrupt handler prototypes
* @brief Prototypes for interrupt handlers
* @{
*/
/* -------------------------  Exception Handlers  ------------------------ */
extern void NMI_Handler(void);                 /**< Non maskable Interrupt, cannot be stopped or preempted                           */
extern void HardFault_Handler(void);           /**< Hard Fault, all classes of Fault                                                 */
extern void MemManage_Handler(void);           /**< Memory Management, MPU mismatch, including Access Violation and No Match         */
extern void BusFault_Handler(void);            /**< Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault   */
extern void UsageFault_Handler(void);          /**< Usage Fault, i.e. Undef Instruction, Illegal State Transition                    */
extern void SVC_Handler(void);                 /**< System Service Call via SVC instruction                                          */
extern void DebugMon_Handler(void);            /**< Debug Monitor                                                                    */
extern void PendSV_Handler(void);              /**< Pendable request for system service                                              */
extern void SysTick_Handler(void);             /**< System Tick Timer                                                                */
extern void DMA0_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA1_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA2_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA3_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA4_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA5_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA6_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA7_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA8_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA9_IRQHandler(void);             /**< Direct memory access controller                                                  */
extern void DMA10_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA11_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA12_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA13_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA14_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA15_IRQHandler(void);            /**< Direct memory access controller                                                  */
extern void DMA_Error_IRQHandler(void);        /**< Direct memory access controller                                                  */
extern void MCM_IRQHandler(void);              /**< Miscellaneous Control Module                                                     */
extern void FTF_Command_IRQHandler(void);      /**< Flash Memory Interface                                                           */
extern void FTF_ReadCollision_IRQHandler(void);   /**< Flash Memory Interface                                                           */
extern void PMC_IRQHandler(void);              /**< Power Management Controller                                                      */
extern void LLWU_IRQHandler(void);             /**< Low Leakage Wakeup                                                               */
extern void WDOG_IRQHandler(void);             /**< External Watchdog Monitor                                                        */
extern void I2C0_IRQHandler(void);             /**< Inter-Integrated Circuit                                                         */
extern void SPI_IRQHandler(void);              /**< Serial Peripheral Interface                                                      */
extern void UART0_RX_TX_IRQHandler(void);      /**< Serial Communication Interface                                                   */
extern void UART0_ERR_IRQHandler(void);        /**< Serial Communication Interface                                                   */
extern void UART1_RX_TX_IRQHandler(void);      /**< Serial Communication Interface                                                   */
extern void UART1_ERR_IRQHandler(void);        /**< Serial Communication Interface                                                   */
extern void ADC_ERR_IRQHandler(void);          /**< Analogue to digital converter                                                    */
extern void ADCA_IRQHandler(void);             /**< Analogue to digital converter                                                    */
extern void CMP0_IRQHandler(void);             /**< High-Speed Comparator                                                            */
extern void CMP1_IRQHandler(void);             /**< High-Speed Comparator                                                            */
extern void FTM0_IRQHandler(void);             /**< FlexTimer Module                                                                 */
extern void FTM1_IRQHandler(void);             /**< FlexTimer Module                                                                 */
extern void PIT0_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void PIT1_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void PIT2_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void PIT3_IRQHandler(void);             /**< Periodic Interrupt Timer                                                         */
extern void PDB0_IRQHandler(void);             /**< Programmable Delay Block                                                         */
extern void XBARA_IRQHandler(void);            /**< Crossbar Switch                                                                  */
extern void PDB1_IRQHandler(void);             /**< Programmable Delay Block                                                         */
extern void MCG_IRQHandler(void);              /**< Multipurpose Clock Generator                                                     */
extern void LPTMR0_IRQHandler(void);           /**< Low Power Timer                                                                  */
extern void PORTA_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTB_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTC_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTD_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void PORTE_IRQHandler(void);            /**< General Purpose Input/Output                                                     */
extern void ENC_COMPARE_IRQHandler(void);      /**< Quadrature Decoder                                                               */
extern void ENC_HOME_IRQHandler(void);         /**< Quadrature Decoder                                                               */
extern void ENC_WDOG_SAB_IRQHandler(void);     /**< Quadrature Decoder                                                               */
extern void ENC_INDEX_IRQHandler(void);        /**< Quadrature Decoder                                                               */
extern void CMP2_IRQHandler(void);             /**< High-Speed Comparator                                                            */
extern void FTM3_IRQHandler(void);             /**< FlexTimer Module                                                                 */
extern void ADCB_IRQHandler(void);             /**< Analogue to digital converter                                                    */
extern void CAN0_Message_IRQHandler(void);     /**< Flex Controller Area Network module                                              */
extern void CAN0_BusOff_IRQHandler(void);      /**< Flex Controller Area Network module                                              */
extern void CAN0_Error_IRQHandler(void);       /**< Flex Controller Area Network module                                              */
extern void CAN0_Tx_IRQHandler(void);          /**< Flex Controller Area Network module                                              */
extern void CAN0_Rx_IRQHandler(void);          /**< Flex Controller Area Network module                                              */
extern void CAN0_WakeUp_IRQHandler(void);      /**< Flex Controller Area Network module                                              */
extern void CMP3_IRQHandler(void);             /**< High-Speed Comparator                                                            */
extern void CAN1_Message_IRQHandler(void);     /**< Flex Controller Area Network module                                              */
extern void CAN1_BusOff_IRQHandler(void);      /**< Flex Controller Area Network module                                              */
extern void CAN1_Error_IRQHandler(void);       /**< Flex Controller Area Network module                                              */
extern void CAN1_Tx_IRQHandler(void);          /**< Flex Controller Area Network module                                              */
extern void CAN1_Rx_IRQHandler(void);          /**< Flex Controller Area Network module                                              */
extern void CAN1_WakeUp_IRQHandler(void);      /**< Flex Controller Area Network module                                              */

/**
 * @} */ /* End group Interrupt_handler_prototypes_GROUP 
 */
/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/**
* @addtogroup Cortex_Core_Configuration_GROUP Cortex Core Configuration
* @brief Configuration of the cm4 Processor and Core Peripherals
* @{
*/
#define __CM4_REV                 0x0001     /**< CPU Revision                                        */
#define __MPU_PRESENT             0          /**< Whether MPU is present                              */
#define __NVIC_PRIO_BITS          4          /**< Number of implemented bits in NVIC PRIO register    */
#define __Vendor_SysTickConfig    0          /**< Whether Vendor implemented SYSTICK timer is present */
#define __FPU_PRESENT             1          /**< Whether FPU is present                              */
#define __VTOR_PRESENT            1          /**< Whether VTOR register is present                    */

/**
 * @} */ /* End group Cortex_Core_Configuration_GROUP 
 */
#include "core_cm4.h"           /* Processor and core peripherals     */
#include "system.h"             /* Device specific configuration file */

#ifndef __IO
#define __IO volatile 
#endif

#ifndef __I
#define __I volatile const
#endif

#ifndef __O
#define __O volatile
#endif


/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */



/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif
/**
* @addtogroup Peripheral_access_layer_GROUP Device Peripheral Access Layer
* @brief C structs allowing access to peripheral registers
* @{
*/
/**
* @addtogroup ADC_Peripheral_access_layer_GROUP ADC Peripheral Access Layer
* @brief C Struct for ADC
* @{
*/

/* ================================================================================ */
/* ================           ADC0 (file:ADC0_MKV)                 ================ */
/* ================================================================================ */

/**
 * @brief Analog to digital converter
 */
/**
* @addtogroup ADC_structs_GROUP ADC struct
* @brief Struct for ADC
* @{
*/
typedef struct {                                /*       ADC0 Structure                                               */
   __IO uint16_t  CTRL1;                        /**< 0000: ADC Control Register 1                                       */
   __IO uint16_t  CTRL2;                        /**< 0002: ADC Control Register 2                                       */
   __IO uint16_t  ZXCTRL1;                      /**< 0004: ADC Zero Crossing Control 1 Register                         */
   __IO uint16_t  ZXCTRL2;                      /**< 0006: ADC Zero Crossing Control 2 Register                         */
   __IO uint16_t  CLIST1;                       /**< 0008: ADC Channel List Register 1                                  */
   __IO uint16_t  CLIST2;                       /**< 000A: ADC Channel List Register 2                                  */
   __IO uint16_t  CLIST3;                       /**< 000C: ADC Channel List Register 3                                  */
   __IO uint16_t  CLIST4;                       /**< 000E: ADC Channel List Register 4                                  */
   __IO uint16_t  SDIS;                         /**< 0010: ADC Sample Disable Register                                  */
   __IO uint16_t  STAT;                         /**< 0012: ADC Status Register                                          */
   __I  uint16_t  RDY;                          /**< 0014: ADC Ready Register                                           */
   __IO uint16_t  LOLIMSTAT;                    /**< 0016: ADC Low Limit Status Register                                */
   __IO uint16_t  HILIMSTAT;                    /**< 0018: ADC High Limit Status Register                               */
   __IO uint16_t  ZXSTAT;                       /**< 001A: ADC Zero Crossing Status Register                            */
   __IO uint16_t  RSLT[16];                     /**< 001C: ADC Result Registers with sign extension                     */
   __IO uint16_t  LOLIM[16];                    /**< 003C: ADC Low Limit                                                */
   __IO uint16_t  HILIM[16];                    /**< 005C: ADC High Limit                                               */
   __IO uint16_t  OFFST[16];                    /**< 007C: ADC Offset                                                   */
   __IO uint16_t  PWR;                          /**< 009C: ADC Power Control Register                                   */
   __IO uint16_t  CAL;                          /**< 009E: ADC Calibration Register                                     */
   __IO uint16_t  GC1;                          /**< 00A0: Gain Control 1 Register                                      */
   __IO uint16_t  GC2;                          /**< 00A2: Gain Control 2 Register                                      */
   __IO uint16_t  SCTRL;                        /**< 00A4: ADC Scan Control Register                                    */
   __IO uint16_t  PWR2;                         /**< 00A6: ADC Power Control Register                                   */
   __IO uint16_t  CTRL3;                        /**< 00A8: ADC Control Register 3                                       */
   __IO uint16_t  SCHLTEN;                      /**< 00AA: ADC Scan Interrupt Enable Register                           */
} ADC_Type;

/**
 * @} */ /* End group ADC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'ADC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup ADC_Register_Masks_GROUP ADC Register Masks
* @brief Register Masks for ADC
* @{
*/
/* ------- CTRL1 Bit Fields                         ------ */
#define ADC_CTRL1_SMODE_MASK                     (0x7U)                                              /*!< ADC0_CTRL1.SMODE Mask                   */
#define ADC_CTRL1_SMODE_SHIFT                    (0U)                                                /*!< ADC0_CTRL1.SMODE Position               */
#define ADC_CTRL1_SMODE(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x7UL)           /*!< ADC0_CTRL1.SMODE Field                  */
#define ADC_CTRL1_CHNCFG_L_MASK                  (0xF0U)                                             /*!< ADC0_CTRL1.CHNCFG_L Mask                */
#define ADC_CTRL1_CHNCFG_L_SHIFT                 (4U)                                                /*!< ADC0_CTRL1.CHNCFG_L Position            */
#define ADC_CTRL1_CHNCFG_L(x)                    (((uint16_t)(((uint16_t)(x))<<4U))&0xF0UL)          /*!< ADC0_CTRL1.CHNCFG_L Field               */
#define ADC_CTRL1_HLMTIE_MASK                    (0x100U)                                            /*!< ADC0_CTRL1.HLMTIE Mask                  */
#define ADC_CTRL1_HLMTIE_SHIFT                   (8U)                                                /*!< ADC0_CTRL1.HLMTIE Position              */
#define ADC_CTRL1_HLMTIE(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x100UL)         /*!< ADC0_CTRL1.HLMTIE Field                 */
#define ADC_CTRL1_LLMTIE_MASK                    (0x200U)                                            /*!< ADC0_CTRL1.LLMTIE Mask                  */
#define ADC_CTRL1_LLMTIE_SHIFT                   (9U)                                                /*!< ADC0_CTRL1.LLMTIE Position              */
#define ADC_CTRL1_LLMTIE(x)                      (((uint16_t)(((uint16_t)(x))<<9U))&0x200UL)         /*!< ADC0_CTRL1.LLMTIE Field                 */
#define ADC_CTRL1_ZCIE_MASK                      (0x400U)                                            /*!< ADC0_CTRL1.ZCIE Mask                    */
#define ADC_CTRL1_ZCIE_SHIFT                     (10U)                                               /*!< ADC0_CTRL1.ZCIE Position                */
#define ADC_CTRL1_ZCIE(x)                        (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< ADC0_CTRL1.ZCIE Field                   */
#define ADC_CTRL1_EOSIE0_MASK                    (0x800U)                                            /*!< ADC0_CTRL1.EOSIE0 Mask                  */
#define ADC_CTRL1_EOSIE0_SHIFT                   (11U)                                               /*!< ADC0_CTRL1.EOSIE0 Position              */
#define ADC_CTRL1_EOSIE0(x)                      (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< ADC0_CTRL1.EOSIE0 Field                 */
#define ADC_CTRL1_SYNC0_MASK                     (0x1000U)                                           /*!< ADC0_CTRL1.SYNC0 Mask                   */
#define ADC_CTRL1_SYNC0_SHIFT                    (12U)                                               /*!< ADC0_CTRL1.SYNC0 Position               */
#define ADC_CTRL1_SYNC0(x)                       (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< ADC0_CTRL1.SYNC0 Field                  */
#define ADC_CTRL1_START0_MASK                    (0x2000U)                                           /*!< ADC0_CTRL1.START0 Mask                  */
#define ADC_CTRL1_START0_SHIFT                   (13U)                                               /*!< ADC0_CTRL1.START0 Position              */
#define ADC_CTRL1_START0(x)                      (((uint16_t)(((uint16_t)(x))<<13U))&0x2000UL)       /*!< ADC0_CTRL1.START0 Field                 */
#define ADC_CTRL1_STOP0_MASK                     (0x4000U)                                           /*!< ADC0_CTRL1.STOP0 Mask                   */
#define ADC_CTRL1_STOP0_SHIFT                    (14U)                                               /*!< ADC0_CTRL1.STOP0 Position               */
#define ADC_CTRL1_STOP0(x)                       (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< ADC0_CTRL1.STOP0 Field                  */
#define ADC_CTRL1_DMAEN0_MASK                    (0x8000U)                                           /*!< ADC0_CTRL1.DMAEN0 Mask                  */
#define ADC_CTRL1_DMAEN0_SHIFT                   (15U)                                               /*!< ADC0_CTRL1.DMAEN0 Position              */
#define ADC_CTRL1_DMAEN0(x)                      (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< ADC0_CTRL1.DMAEN0 Field                 */
/* ------- CTRL2 Bit Fields                         ------ */
#define ADC_CTRL2_DIV0_MASK                      (0x3FU)                                             /*!< ADC0_CTRL2.DIV0 Mask                    */
#define ADC_CTRL2_DIV0_SHIFT                     (0U)                                                /*!< ADC0_CTRL2.DIV0 Position                */
#define ADC_CTRL2_DIV0(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< ADC0_CTRL2.DIV0 Field                   */
#define ADC_CTRL2_SIMULT_MASK                    (0x40U)                                             /*!< ADC0_CTRL2.SIMULT Mask                  */
#define ADC_CTRL2_SIMULT_SHIFT                   (6U)                                                /*!< ADC0_CTRL2.SIMULT Position              */
#define ADC_CTRL2_SIMULT(x)                      (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< ADC0_CTRL2.SIMULT Field                 */
#define ADC_CTRL2_CHNCFG_H_MASK                  (0x780U)                                            /*!< ADC0_CTRL2.CHNCFG_H Mask                */
#define ADC_CTRL2_CHNCFG_H_SHIFT                 (7U)                                                /*!< ADC0_CTRL2.CHNCFG_H Position            */
#define ADC_CTRL2_CHNCFG_H(x)                    (((uint16_t)(((uint16_t)(x))<<7U))&0x780UL)         /*!< ADC0_CTRL2.CHNCFG_H Field               */
#define ADC_CTRL2_EOSIE1_MASK                    (0x800U)                                            /*!< ADC0_CTRL2.EOSIE1 Mask                  */
#define ADC_CTRL2_EOSIE1_SHIFT                   (11U)                                               /*!< ADC0_CTRL2.EOSIE1 Position              */
#define ADC_CTRL2_EOSIE1(x)                      (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< ADC0_CTRL2.EOSIE1 Field                 */
#define ADC_CTRL2_SYNC1_MASK                     (0x1000U)                                           /*!< ADC0_CTRL2.SYNC1 Mask                   */
#define ADC_CTRL2_SYNC1_SHIFT                    (12U)                                               /*!< ADC0_CTRL2.SYNC1 Position               */
#define ADC_CTRL2_SYNC1(x)                       (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< ADC0_CTRL2.SYNC1 Field                  */
#define ADC_CTRL2_START1_MASK                    (0x2000U)                                           /*!< ADC0_CTRL2.START1 Mask                  */
#define ADC_CTRL2_START1_SHIFT                   (13U)                                               /*!< ADC0_CTRL2.START1 Position              */
#define ADC_CTRL2_START1(x)                      (((uint16_t)(((uint16_t)(x))<<13U))&0x2000UL)       /*!< ADC0_CTRL2.START1 Field                 */
#define ADC_CTRL2_STOP1_MASK                     (0x4000U)                                           /*!< ADC0_CTRL2.STOP1 Mask                   */
#define ADC_CTRL2_STOP1_SHIFT                    (14U)                                               /*!< ADC0_CTRL2.STOP1 Position               */
#define ADC_CTRL2_STOP1(x)                       (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< ADC0_CTRL2.STOP1 Field                  */
#define ADC_CTRL2_DMAEN1_MASK                    (0x8000U)                                           /*!< ADC0_CTRL2.DMAEN1 Mask                  */
#define ADC_CTRL2_DMAEN1_SHIFT                   (15U)                                               /*!< ADC0_CTRL2.DMAEN1 Position              */
#define ADC_CTRL2_DMAEN1(x)                      (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< ADC0_CTRL2.DMAEN1 Field                 */
/* ------- ZXCTRL1 Bit Fields                       ------ */
#define ADC_ZXCTRL1_ZCE0_MASK                    (0x3U)                                              /*!< ADC0_ZXCTRL1.ZCE0 Mask                  */
#define ADC_ZXCTRL1_ZCE0_SHIFT                   (0U)                                                /*!< ADC0_ZXCTRL1.ZCE0 Position              */
#define ADC_ZXCTRL1_ZCE0(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< ADC0_ZXCTRL1.ZCE0 Field                 */
#define ADC_ZXCTRL1_ZCE1_MASK                    (0xCU)                                              /*!< ADC0_ZXCTRL1.ZCE1 Mask                  */
#define ADC_ZXCTRL1_ZCE1_SHIFT                   (2U)                                                /*!< ADC0_ZXCTRL1.ZCE1 Position              */
#define ADC_ZXCTRL1_ZCE1(x)                      (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< ADC0_ZXCTRL1.ZCE1 Field                 */
#define ADC_ZXCTRL1_ZCE2_MASK                    (0x30U)                                             /*!< ADC0_ZXCTRL1.ZCE2 Mask                  */
#define ADC_ZXCTRL1_ZCE2_SHIFT                   (4U)                                                /*!< ADC0_ZXCTRL1.ZCE2 Position              */
#define ADC_ZXCTRL1_ZCE2(x)                      (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< ADC0_ZXCTRL1.ZCE2 Field                 */
#define ADC_ZXCTRL1_ZCE3_MASK                    (0xC0U)                                             /*!< ADC0_ZXCTRL1.ZCE3 Mask                  */
#define ADC_ZXCTRL1_ZCE3_SHIFT                   (6U)                                                /*!< ADC0_ZXCTRL1.ZCE3 Position              */
#define ADC_ZXCTRL1_ZCE3(x)                      (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< ADC0_ZXCTRL1.ZCE3 Field                 */
#define ADC_ZXCTRL1_ZCE4_MASK                    (0x300U)                                            /*!< ADC0_ZXCTRL1.ZCE4 Mask                  */
#define ADC_ZXCTRL1_ZCE4_SHIFT                   (8U)                                                /*!< ADC0_ZXCTRL1.ZCE4 Position              */
#define ADC_ZXCTRL1_ZCE4(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< ADC0_ZXCTRL1.ZCE4 Field                 */
#define ADC_ZXCTRL1_ZCE5_MASK                    (0xC00U)                                            /*!< ADC0_ZXCTRL1.ZCE5 Mask                  */
#define ADC_ZXCTRL1_ZCE5_SHIFT                   (10U)                                               /*!< ADC0_ZXCTRL1.ZCE5 Position              */
#define ADC_ZXCTRL1_ZCE5(x)                      (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< ADC0_ZXCTRL1.ZCE5 Field                 */
#define ADC_ZXCTRL1_ZCE6_MASK                    (0x3000U)                                           /*!< ADC0_ZXCTRL1.ZCE6 Mask                  */
#define ADC_ZXCTRL1_ZCE6_SHIFT                   (12U)                                               /*!< ADC0_ZXCTRL1.ZCE6 Position              */
#define ADC_ZXCTRL1_ZCE6(x)                      (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< ADC0_ZXCTRL1.ZCE6 Field                 */
#define ADC_ZXCTRL1_ZCE7_MASK                    (0xC000U)                                           /*!< ADC0_ZXCTRL1.ZCE7 Mask                  */
#define ADC_ZXCTRL1_ZCE7_SHIFT                   (14U)                                               /*!< ADC0_ZXCTRL1.ZCE7 Position              */
#define ADC_ZXCTRL1_ZCE7(x)                      (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< ADC0_ZXCTRL1.ZCE7 Field                 */
/* ------- ZXCTRL2 Bit Fields                       ------ */
#define ADC_ZXCTRL2_ZCE8_MASK                    (0x3U)                                              /*!< ADC0_ZXCTRL2.ZCE8 Mask                  */
#define ADC_ZXCTRL2_ZCE8_SHIFT                   (0U)                                                /*!< ADC0_ZXCTRL2.ZCE8 Position              */
#define ADC_ZXCTRL2_ZCE8(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< ADC0_ZXCTRL2.ZCE8 Field                 */
#define ADC_ZXCTRL2_ZCE9_MASK                    (0xCU)                                              /*!< ADC0_ZXCTRL2.ZCE9 Mask                  */
#define ADC_ZXCTRL2_ZCE9_SHIFT                   (2U)                                                /*!< ADC0_ZXCTRL2.ZCE9 Position              */
#define ADC_ZXCTRL2_ZCE9(x)                      (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< ADC0_ZXCTRL2.ZCE9 Field                 */
#define ADC_ZXCTRL2_ZCE10_MASK                   (0x30U)                                             /*!< ADC0_ZXCTRL2.ZCE10 Mask                 */
#define ADC_ZXCTRL2_ZCE10_SHIFT                  (4U)                                                /*!< ADC0_ZXCTRL2.ZCE10 Position             */
#define ADC_ZXCTRL2_ZCE10(x)                     (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< ADC0_ZXCTRL2.ZCE10 Field                */
#define ADC_ZXCTRL2_ZCE11_MASK                   (0xC0U)                                             /*!< ADC0_ZXCTRL2.ZCE11 Mask                 */
#define ADC_ZXCTRL2_ZCE11_SHIFT                  (6U)                                                /*!< ADC0_ZXCTRL2.ZCE11 Position             */
#define ADC_ZXCTRL2_ZCE11(x)                     (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< ADC0_ZXCTRL2.ZCE11 Field                */
#define ADC_ZXCTRL2_ZCE12_MASK                   (0x300U)                                            /*!< ADC0_ZXCTRL2.ZCE12 Mask                 */
#define ADC_ZXCTRL2_ZCE12_SHIFT                  (8U)                                                /*!< ADC0_ZXCTRL2.ZCE12 Position             */
#define ADC_ZXCTRL2_ZCE12(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< ADC0_ZXCTRL2.ZCE12 Field                */
#define ADC_ZXCTRL2_ZCE13_MASK                   (0xC00U)                                            /*!< ADC0_ZXCTRL2.ZCE13 Mask                 */
#define ADC_ZXCTRL2_ZCE13_SHIFT                  (10U)                                               /*!< ADC0_ZXCTRL2.ZCE13 Position             */
#define ADC_ZXCTRL2_ZCE13(x)                     (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< ADC0_ZXCTRL2.ZCE13 Field                */
#define ADC_ZXCTRL2_ZCE14_MASK                   (0x3000U)                                           /*!< ADC0_ZXCTRL2.ZCE14 Mask                 */
#define ADC_ZXCTRL2_ZCE14_SHIFT                  (12U)                                               /*!< ADC0_ZXCTRL2.ZCE14 Position             */
#define ADC_ZXCTRL2_ZCE14(x)                     (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< ADC0_ZXCTRL2.ZCE14 Field                */
#define ADC_ZXCTRL2_ZCE15_MASK                   (0xC000U)                                           /*!< ADC0_ZXCTRL2.ZCE15 Mask                 */
#define ADC_ZXCTRL2_ZCE15_SHIFT                  (14U)                                               /*!< ADC0_ZXCTRL2.ZCE15 Position             */
#define ADC_ZXCTRL2_ZCE15(x)                     (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< ADC0_ZXCTRL2.ZCE15 Field                */
/* ------- CLIST1 Bit Fields                        ------ */
#define ADC_CLIST1_SAMPLE0_MASK                  (0xFU)                                              /*!< ADC0_CLIST1.SAMPLE0 Mask                */
#define ADC_CLIST1_SAMPLE0_SHIFT                 (0U)                                                /*!< ADC0_CLIST1.SAMPLE0 Position            */
#define ADC_CLIST1_SAMPLE0(x)                    (((uint16_t)(((uint16_t)(x))<<0U))&0xFUL)           /*!< ADC0_CLIST1.SAMPLE0 Field               */
#define ADC_CLIST1_SAMPLE1_MASK                  (0xF0U)                                             /*!< ADC0_CLIST1.SAMPLE1 Mask                */
#define ADC_CLIST1_SAMPLE1_SHIFT                 (4U)                                                /*!< ADC0_CLIST1.SAMPLE1 Position            */
#define ADC_CLIST1_SAMPLE1(x)                    (((uint16_t)(((uint16_t)(x))<<4U))&0xF0UL)          /*!< ADC0_CLIST1.SAMPLE1 Field               */
#define ADC_CLIST1_SAMPLE2_MASK                  (0xF00U)                                            /*!< ADC0_CLIST1.SAMPLE2 Mask                */
#define ADC_CLIST1_SAMPLE2_SHIFT                 (8U)                                                /*!< ADC0_CLIST1.SAMPLE2 Position            */
#define ADC_CLIST1_SAMPLE2(x)                    (((uint16_t)(((uint16_t)(x))<<8U))&0xF00UL)         /*!< ADC0_CLIST1.SAMPLE2 Field               */
#define ADC_CLIST1_SAMPLE3_MASK                  (0xF000U)                                           /*!< ADC0_CLIST1.SAMPLE3 Mask                */
#define ADC_CLIST1_SAMPLE3_SHIFT                 (12U)                                               /*!< ADC0_CLIST1.SAMPLE3 Position            */
#define ADC_CLIST1_SAMPLE3(x)                    (((uint16_t)(((uint16_t)(x))<<12U))&0xF000UL)       /*!< ADC0_CLIST1.SAMPLE3 Field               */
/* ------- CLIST2 Bit Fields                        ------ */
#define ADC_CLIST2_SAMPLE4_MASK                  (0xFU)                                              /*!< ADC0_CLIST2.SAMPLE4 Mask                */
#define ADC_CLIST2_SAMPLE4_SHIFT                 (0U)                                                /*!< ADC0_CLIST2.SAMPLE4 Position            */
#define ADC_CLIST2_SAMPLE4(x)                    (((uint16_t)(((uint16_t)(x))<<0U))&0xFUL)           /*!< ADC0_CLIST2.SAMPLE4 Field               */
#define ADC_CLIST2_SAMPLE5_MASK                  (0xF0U)                                             /*!< ADC0_CLIST2.SAMPLE5 Mask                */
#define ADC_CLIST2_SAMPLE5_SHIFT                 (4U)                                                /*!< ADC0_CLIST2.SAMPLE5 Position            */
#define ADC_CLIST2_SAMPLE5(x)                    (((uint16_t)(((uint16_t)(x))<<4U))&0xF0UL)          /*!< ADC0_CLIST2.SAMPLE5 Field               */
#define ADC_CLIST2_SAMPLE6_MASK                  (0xF00U)                                            /*!< ADC0_CLIST2.SAMPLE6 Mask                */
#define ADC_CLIST2_SAMPLE6_SHIFT                 (8U)                                                /*!< ADC0_CLIST2.SAMPLE6 Position            */
#define ADC_CLIST2_SAMPLE6(x)                    (((uint16_t)(((uint16_t)(x))<<8U))&0xF00UL)         /*!< ADC0_CLIST2.SAMPLE6 Field               */
#define ADC_CLIST2_SAMPLE7_MASK                  (0xF000U)                                           /*!< ADC0_CLIST2.SAMPLE7 Mask                */
#define ADC_CLIST2_SAMPLE7_SHIFT                 (12U)                                               /*!< ADC0_CLIST2.SAMPLE7 Position            */
#define ADC_CLIST2_SAMPLE7(x)                    (((uint16_t)(((uint16_t)(x))<<12U))&0xF000UL)       /*!< ADC0_CLIST2.SAMPLE7 Field               */
/* ------- CLIST3 Bit Fields                        ------ */
#define ADC_CLIST3_SAMPLE8_MASK                  (0xFU)                                              /*!< ADC0_CLIST3.SAMPLE8 Mask                */
#define ADC_CLIST3_SAMPLE8_SHIFT                 (0U)                                                /*!< ADC0_CLIST3.SAMPLE8 Position            */
#define ADC_CLIST3_SAMPLE8(x)                    (((uint16_t)(((uint16_t)(x))<<0U))&0xFUL)           /*!< ADC0_CLIST3.SAMPLE8 Field               */
#define ADC_CLIST3_SAMPLE9_MASK                  (0xF0U)                                             /*!< ADC0_CLIST3.SAMPLE9 Mask                */
#define ADC_CLIST3_SAMPLE9_SHIFT                 (4U)                                                /*!< ADC0_CLIST3.SAMPLE9 Position            */
#define ADC_CLIST3_SAMPLE9(x)                    (((uint16_t)(((uint16_t)(x))<<4U))&0xF0UL)          /*!< ADC0_CLIST3.SAMPLE9 Field               */
#define ADC_CLIST3_SAMPLE10_MASK                 (0xF00U)                                            /*!< ADC0_CLIST3.SAMPLE10 Mask               */
#define ADC_CLIST3_SAMPLE10_SHIFT                (8U)                                                /*!< ADC0_CLIST3.SAMPLE10 Position           */
#define ADC_CLIST3_SAMPLE10(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0xF00UL)         /*!< ADC0_CLIST3.SAMPLE10 Field              */
#define ADC_CLIST3_SAMPLE11_MASK                 (0xF000U)                                           /*!< ADC0_CLIST3.SAMPLE11 Mask               */
#define ADC_CLIST3_SAMPLE11_SHIFT                (12U)                                               /*!< ADC0_CLIST3.SAMPLE11 Position           */
#define ADC_CLIST3_SAMPLE11(x)                   (((uint16_t)(((uint16_t)(x))<<12U))&0xF000UL)       /*!< ADC0_CLIST3.SAMPLE11 Field              */
/* ------- CLIST4 Bit Fields                        ------ */
#define ADC_CLIST4_SAMPLE12_MASK                 (0xFU)                                              /*!< ADC0_CLIST4.SAMPLE12 Mask               */
#define ADC_CLIST4_SAMPLE12_SHIFT                (0U)                                                /*!< ADC0_CLIST4.SAMPLE12 Position           */
#define ADC_CLIST4_SAMPLE12(x)                   (((uint16_t)(((uint16_t)(x))<<0U))&0xFUL)           /*!< ADC0_CLIST4.SAMPLE12 Field              */
#define ADC_CLIST4_SAMPLE13_MASK                 (0xF0U)                                             /*!< ADC0_CLIST4.SAMPLE13 Mask               */
#define ADC_CLIST4_SAMPLE13_SHIFT                (4U)                                                /*!< ADC0_CLIST4.SAMPLE13 Position           */
#define ADC_CLIST4_SAMPLE13(x)                   (((uint16_t)(((uint16_t)(x))<<4U))&0xF0UL)          /*!< ADC0_CLIST4.SAMPLE13 Field              */
#define ADC_CLIST4_SAMPLE14_MASK                 (0xF00U)                                            /*!< ADC0_CLIST4.SAMPLE14 Mask               */
#define ADC_CLIST4_SAMPLE14_SHIFT                (8U)                                                /*!< ADC0_CLIST4.SAMPLE14 Position           */
#define ADC_CLIST4_SAMPLE14(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0xF00UL)         /*!< ADC0_CLIST4.SAMPLE14 Field              */
#define ADC_CLIST4_SAMPLE15_MASK                 (0xF000U)                                           /*!< ADC0_CLIST4.SAMPLE15 Mask               */
#define ADC_CLIST4_SAMPLE15_SHIFT                (12U)                                               /*!< ADC0_CLIST4.SAMPLE15 Position           */
#define ADC_CLIST4_SAMPLE15(x)                   (((uint16_t)(((uint16_t)(x))<<12U))&0xF000UL)       /*!< ADC0_CLIST4.SAMPLE15 Field              */
/* ------- SDIS Bit Fields                          ------ */
#define ADC_SDIS_DS_MASK                         (0xFFFFU)                                           /*!< ADC0_SDIS.DS Mask                       */
#define ADC_SDIS_DS_SHIFT                        (0U)                                                /*!< ADC0_SDIS.DS Position                   */
#define ADC_SDIS_DS(x)                           (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ADC0_SDIS.DS Field                      */
/* ------- STAT Bit Fields                          ------ */
#define ADC_STAT_UNDEFINED_MASK                  (0xFFU)                                             /*!< ADC0_STAT.UNDEFINED Mask                */
#define ADC_STAT_UNDEFINED_SHIFT                 (0U)                                                /*!< ADC0_STAT.UNDEFINED Position            */
#define ADC_STAT_UNDEFINED(x)                    (((uint16_t)(((uint16_t)(x))<<0U))&0xFFUL)          /*!< ADC0_STAT.UNDEFINED Field               */
#define ADC_STAT_HLMTI_MASK                      (0x100U)                                            /*!< ADC0_STAT.HLMTI Mask                    */
#define ADC_STAT_HLMTI_SHIFT                     (8U)                                                /*!< ADC0_STAT.HLMTI Position                */
#define ADC_STAT_HLMTI(x)                        (((uint16_t)(((uint16_t)(x))<<8U))&0x100UL)         /*!< ADC0_STAT.HLMTI Field                   */
#define ADC_STAT_LLMTI_MASK                      (0x200U)                                            /*!< ADC0_STAT.LLMTI Mask                    */
#define ADC_STAT_LLMTI_SHIFT                     (9U)                                                /*!< ADC0_STAT.LLMTI Position                */
#define ADC_STAT_LLMTI(x)                        (((uint16_t)(((uint16_t)(x))<<9U))&0x200UL)         /*!< ADC0_STAT.LLMTI Field                   */
#define ADC_STAT_ZCI_MASK                        (0x400U)                                            /*!< ADC0_STAT.ZCI Mask                      */
#define ADC_STAT_ZCI_SHIFT                       (10U)                                               /*!< ADC0_STAT.ZCI Position                  */
#define ADC_STAT_ZCI(x)                          (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< ADC0_STAT.ZCI Field                     */
#define ADC_STAT_EOSI0_MASK                      (0x800U)                                            /*!< ADC0_STAT.EOSI0 Mask                    */
#define ADC_STAT_EOSI0_SHIFT                     (11U)                                               /*!< ADC0_STAT.EOSI0 Position                */
#define ADC_STAT_EOSI0(x)                        (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< ADC0_STAT.EOSI0 Field                   */
#define ADC_STAT_EOSI1_MASK                      (0x1000U)                                           /*!< ADC0_STAT.EOSI1 Mask                    */
#define ADC_STAT_EOSI1_SHIFT                     (12U)                                               /*!< ADC0_STAT.EOSI1 Position                */
#define ADC_STAT_EOSI1(x)                        (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< ADC0_STAT.EOSI1 Field                   */
#define ADC_STAT_CIP1_MASK                       (0x4000U)                                           /*!< ADC0_STAT.CIP1 Mask                     */
#define ADC_STAT_CIP1_SHIFT                      (14U)                                               /*!< ADC0_STAT.CIP1 Position                 */
#define ADC_STAT_CIP1(x)                         (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< ADC0_STAT.CIP1 Field                    */
#define ADC_STAT_CIP0_MASK                       (0x8000U)                                           /*!< ADC0_STAT.CIP0 Mask                     */
#define ADC_STAT_CIP0_SHIFT                      (15U)                                               /*!< ADC0_STAT.CIP0 Position                 */
#define ADC_STAT_CIP0(x)                         (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< ADC0_STAT.CIP0 Field                    */
/* ------- RDY Bit Fields                           ------ */
#define ADC_RDY_RDY_MASK                         (0xFFFFU)                                           /*!< ADC0_RDY.RDY Mask                       */
#define ADC_RDY_RDY_SHIFT                        (0U)                                                /*!< ADC0_RDY.RDY Position                   */
#define ADC_RDY_RDY(x)                           (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ADC0_RDY.RDY Field                      */
/* ------- LOLIMSTAT Bit Fields                     ------ */
#define ADC_LOLIMSTAT_LLS_MASK                   (0xFFFFU)                                           /*!< ADC0_LOLIMSTAT.LLS Mask                 */
#define ADC_LOLIMSTAT_LLS_SHIFT                  (0U)                                                /*!< ADC0_LOLIMSTAT.LLS Position             */
#define ADC_LOLIMSTAT_LLS(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ADC0_LOLIMSTAT.LLS Field                */
/* ------- HILIMSTAT Bit Fields                     ------ */
#define ADC_HILIMSTAT_HLS_MASK                   (0xFFFFU)                                           /*!< ADC0_HILIMSTAT.HLS Mask                 */
#define ADC_HILIMSTAT_HLS_SHIFT                  (0U)                                                /*!< ADC0_HILIMSTAT.HLS Position             */
#define ADC_HILIMSTAT_HLS(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ADC0_HILIMSTAT.HLS Field                */
/* ------- ZXSTAT Bit Fields                        ------ */
#define ADC_ZXSTAT_ZCS_MASK                      (0xFFFFU)                                           /*!< ADC0_ZXSTAT.ZCS Mask                    */
#define ADC_ZXSTAT_ZCS_SHIFT                     (0U)                                                /*!< ADC0_ZXSTAT.ZCS Position                */
#define ADC_ZXSTAT_ZCS(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ADC0_ZXSTAT.ZCS Field                   */
/* ------- RSLT Bit Fields                          ------ */
#define ADC_RSLT_RSLT_MASK                       (0x7FF8U)                                           /*!< ADC0_RSLT.RSLT Mask                     */
#define ADC_RSLT_RSLT_SHIFT                      (3U)                                                /*!< ADC0_RSLT.RSLT Position                 */
#define ADC_RSLT_RSLT(x)                         (((uint16_t)(((uint16_t)(x))<<3U))&0x7FF8UL)        /*!< ADC0_RSLT.RSLT Field                    */
#define ADC_RSLT_SEXT_MASK                       (0x8000U)                                           /*!< ADC0_RSLT.SEXT Mask                     */
#define ADC_RSLT_SEXT_SHIFT                      (15U)                                               /*!< ADC0_RSLT.SEXT Position                 */
#define ADC_RSLT_SEXT(x)                         (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< ADC0_RSLT.SEXT Field                    */
/* ------- LOLIM Bit Fields                         ------ */
#define ADC_LOLIM_LLMT_MASK                      (0x7FF8U)                                           /*!< ADC0_LOLIM.LLMT Mask                    */
#define ADC_LOLIM_LLMT_SHIFT                     (3U)                                                /*!< ADC0_LOLIM.LLMT Position                */
#define ADC_LOLIM_LLMT(x)                        (((uint16_t)(((uint16_t)(x))<<3U))&0x7FF8UL)        /*!< ADC0_LOLIM.LLMT Field                   */
/* ------- HILIM Bit Fields                         ------ */
#define ADC_HILIM_HLMT_MASK                      (0x7FF8U)                                           /*!< ADC0_HILIM.HLMT Mask                    */
#define ADC_HILIM_HLMT_SHIFT                     (3U)                                                /*!< ADC0_HILIM.HLMT Position                */
#define ADC_HILIM_HLMT(x)                        (((uint16_t)(((uint16_t)(x))<<3U))&0x7FF8UL)        /*!< ADC0_HILIM.HLMT Field                   */
/* ------- OFFST Bit Fields                         ------ */
#define ADC_OFFST_OFFSET_MASK                    (0x7FF8U)                                           /*!< ADC0_OFFST.OFFSET Mask                  */
#define ADC_OFFST_OFFSET_SHIFT                   (3U)                                                /*!< ADC0_OFFST.OFFSET Position              */
#define ADC_OFFST_OFFSET(x)                      (((uint16_t)(((uint16_t)(x))<<3U))&0x7FF8UL)        /*!< ADC0_OFFST.OFFSET Field                 */
/* ------- PWR Bit Fields                           ------ */
#define ADC_PWR_PD0_MASK                         (0x1U)                                              /*!< ADC0_PWR.PD0 Mask                       */
#define ADC_PWR_PD0_SHIFT                        (0U)                                                /*!< ADC0_PWR.PD0 Position                   */
#define ADC_PWR_PD0(x)                           (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< ADC0_PWR.PD0 Field                      */
#define ADC_PWR_PD1_MASK                         (0x2U)                                              /*!< ADC0_PWR.PD1 Mask                       */
#define ADC_PWR_PD1_SHIFT                        (1U)                                                /*!< ADC0_PWR.PD1 Position                   */
#define ADC_PWR_PD1(x)                           (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< ADC0_PWR.PD1 Field                      */
#define ADC_PWR_APD_MASK                         (0x8U)                                              /*!< ADC0_PWR.APD Mask                       */
#define ADC_PWR_APD_SHIFT                        (3U)                                                /*!< ADC0_PWR.APD Position                   */
#define ADC_PWR_APD(x)                           (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< ADC0_PWR.APD Field                      */
#define ADC_PWR_PUDELAY_MASK                     (0x3F0U)                                            /*!< ADC0_PWR.PUDELAY Mask                   */
#define ADC_PWR_PUDELAY_SHIFT                    (4U)                                                /*!< ADC0_PWR.PUDELAY Position               */
#define ADC_PWR_PUDELAY(x)                       (((uint16_t)(((uint16_t)(x))<<4U))&0x3F0UL)         /*!< ADC0_PWR.PUDELAY Field                  */
#define ADC_PWR_PSTS0_MASK                       (0x400U)                                            /*!< ADC0_PWR.PSTS0 Mask                     */
#define ADC_PWR_PSTS0_SHIFT                      (10U)                                               /*!< ADC0_PWR.PSTS0 Position                 */
#define ADC_PWR_PSTS0(x)                         (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< ADC0_PWR.PSTS0 Field                    */
#define ADC_PWR_PSTS1_MASK                       (0x800U)                                            /*!< ADC0_PWR.PSTS1 Mask                     */
#define ADC_PWR_PSTS1_SHIFT                      (11U)                                               /*!< ADC0_PWR.PSTS1 Position                 */
#define ADC_PWR_PSTS1(x)                         (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< ADC0_PWR.PSTS1 Field                    */
#define ADC_PWR_ASB_MASK                         (0x8000U)                                           /*!< ADC0_PWR.ASB Mask                       */
#define ADC_PWR_ASB_SHIFT                        (15U)                                               /*!< ADC0_PWR.ASB Position                   */
#define ADC_PWR_ASB(x)                           (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< ADC0_PWR.ASB Field                      */
/* ------- CAL Bit Fields                           ------ */
#define ADC_CAL_SEL_VREFLO_A_MASK                (0x1000U)                                           /*!< ADC0_CAL.SEL_VREFLO_A Mask              */
#define ADC_CAL_SEL_VREFLO_A_SHIFT               (12U)                                               /*!< ADC0_CAL.SEL_VREFLO_A Position          */
#define ADC_CAL_SEL_VREFLO_A(x)                  (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< ADC0_CAL.SEL_VREFLO_A Field             */
#define ADC_CAL_SEL_VREFH_A_MASK                 (0x2000U)                                           /*!< ADC0_CAL.SEL_VREFH_A Mask               */
#define ADC_CAL_SEL_VREFH_A_SHIFT                (13U)                                               /*!< ADC0_CAL.SEL_VREFH_A Position           */
#define ADC_CAL_SEL_VREFH_A(x)                   (((uint16_t)(((uint16_t)(x))<<13U))&0x2000UL)       /*!< ADC0_CAL.SEL_VREFH_A Field              */
#define ADC_CAL_SEL_VREFLO_B_MASK                (0x4000U)                                           /*!< ADC0_CAL.SEL_VREFLO_B Mask              */
#define ADC_CAL_SEL_VREFLO_B_SHIFT               (14U)                                               /*!< ADC0_CAL.SEL_VREFLO_B Position          */
#define ADC_CAL_SEL_VREFLO_B(x)                  (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< ADC0_CAL.SEL_VREFLO_B Field             */
#define ADC_CAL_SEL_VREFH_B_MASK                 (0x8000U)                                           /*!< ADC0_CAL.SEL_VREFH_B Mask               */
#define ADC_CAL_SEL_VREFH_B_SHIFT                (15U)                                               /*!< ADC0_CAL.SEL_VREFH_B Position           */
#define ADC_CAL_SEL_VREFH_B(x)                   (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< ADC0_CAL.SEL_VREFH_B Field              */
/* ------- GC1 Bit Fields                           ------ */
#define ADC_GC1_GAIN0_MASK                       (0x3U)                                              /*!< ADC0_GC1.GAIN0 Mask                     */
#define ADC_GC1_GAIN0_SHIFT                      (0U)                                                /*!< ADC0_GC1.GAIN0 Position                 */
#define ADC_GC1_GAIN0(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< ADC0_GC1.GAIN0 Field                    */
#define ADC_GC1_GAIN1_MASK                       (0xCU)                                              /*!< ADC0_GC1.GAIN1 Mask                     */
#define ADC_GC1_GAIN1_SHIFT                      (2U)                                                /*!< ADC0_GC1.GAIN1 Position                 */
#define ADC_GC1_GAIN1(x)                         (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< ADC0_GC1.GAIN1 Field                    */
#define ADC_GC1_GAIN2_MASK                       (0x30U)                                             /*!< ADC0_GC1.GAIN2 Mask                     */
#define ADC_GC1_GAIN2_SHIFT                      (4U)                                                /*!< ADC0_GC1.GAIN2 Position                 */
#define ADC_GC1_GAIN2(x)                         (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< ADC0_GC1.GAIN2 Field                    */
#define ADC_GC1_GAIN3_MASK                       (0xC0U)                                             /*!< ADC0_GC1.GAIN3 Mask                     */
#define ADC_GC1_GAIN3_SHIFT                      (6U)                                                /*!< ADC0_GC1.GAIN3 Position                 */
#define ADC_GC1_GAIN3(x)                         (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< ADC0_GC1.GAIN3 Field                    */
#define ADC_GC1_GAIN4_MASK                       (0x300U)                                            /*!< ADC0_GC1.GAIN4 Mask                     */
#define ADC_GC1_GAIN4_SHIFT                      (8U)                                                /*!< ADC0_GC1.GAIN4 Position                 */
#define ADC_GC1_GAIN4(x)                         (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< ADC0_GC1.GAIN4 Field                    */
#define ADC_GC1_GAIN5_MASK                       (0xC00U)                                            /*!< ADC0_GC1.GAIN5 Mask                     */
#define ADC_GC1_GAIN5_SHIFT                      (10U)                                               /*!< ADC0_GC1.GAIN5 Position                 */
#define ADC_GC1_GAIN5(x)                         (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< ADC0_GC1.GAIN5 Field                    */
#define ADC_GC1_GAIN6_MASK                       (0x3000U)                                           /*!< ADC0_GC1.GAIN6 Mask                     */
#define ADC_GC1_GAIN6_SHIFT                      (12U)                                               /*!< ADC0_GC1.GAIN6 Position                 */
#define ADC_GC1_GAIN6(x)                         (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< ADC0_GC1.GAIN6 Field                    */
#define ADC_GC1_GAIN7_MASK                       (0xC000U)                                           /*!< ADC0_GC1.GAIN7 Mask                     */
#define ADC_GC1_GAIN7_SHIFT                      (14U)                                               /*!< ADC0_GC1.GAIN7 Position                 */
#define ADC_GC1_GAIN7(x)                         (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< ADC0_GC1.GAIN7 Field                    */
/* ------- GC2 Bit Fields                           ------ */
#define ADC_GC2_GAIN8_MASK                       (0x3U)                                              /*!< ADC0_GC2.GAIN8 Mask                     */
#define ADC_GC2_GAIN8_SHIFT                      (0U)                                                /*!< ADC0_GC2.GAIN8 Position                 */
#define ADC_GC2_GAIN8(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< ADC0_GC2.GAIN8 Field                    */
#define ADC_GC2_GAIN9_MASK                       (0xCU)                                              /*!< ADC0_GC2.GAIN9 Mask                     */
#define ADC_GC2_GAIN9_SHIFT                      (2U)                                                /*!< ADC0_GC2.GAIN9 Position                 */
#define ADC_GC2_GAIN9(x)                         (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< ADC0_GC2.GAIN9 Field                    */
#define ADC_GC2_GAIN10_MASK                      (0x30U)                                             /*!< ADC0_GC2.GAIN10 Mask                    */
#define ADC_GC2_GAIN10_SHIFT                     (4U)                                                /*!< ADC0_GC2.GAIN10 Position                */
#define ADC_GC2_GAIN10(x)                        (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< ADC0_GC2.GAIN10 Field                   */
#define ADC_GC2_GAIN11_MASK                      (0xC0U)                                             /*!< ADC0_GC2.GAIN11 Mask                    */
#define ADC_GC2_GAIN11_SHIFT                     (6U)                                                /*!< ADC0_GC2.GAIN11 Position                */
#define ADC_GC2_GAIN11(x)                        (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< ADC0_GC2.GAIN11 Field                   */
#define ADC_GC2_GAIN12_MASK                      (0x300U)                                            /*!< ADC0_GC2.GAIN12 Mask                    */
#define ADC_GC2_GAIN12_SHIFT                     (8U)                                                /*!< ADC0_GC2.GAIN12 Position                */
#define ADC_GC2_GAIN12(x)                        (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< ADC0_GC2.GAIN12 Field                   */
#define ADC_GC2_GAIN13_MASK                      (0xC00U)                                            /*!< ADC0_GC2.GAIN13 Mask                    */
#define ADC_GC2_GAIN13_SHIFT                     (10U)                                               /*!< ADC0_GC2.GAIN13 Position                */
#define ADC_GC2_GAIN13(x)                        (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< ADC0_GC2.GAIN13 Field                   */
#define ADC_GC2_GAIN14_MASK                      (0x3000U)                                           /*!< ADC0_GC2.GAIN14 Mask                    */
#define ADC_GC2_GAIN14_SHIFT                     (12U)                                               /*!< ADC0_GC2.GAIN14 Position                */
#define ADC_GC2_GAIN14(x)                        (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< ADC0_GC2.GAIN14 Field                   */
#define ADC_GC2_GAIN15_MASK                      (0xC000U)                                           /*!< ADC0_GC2.GAIN15 Mask                    */
#define ADC_GC2_GAIN15_SHIFT                     (14U)                                               /*!< ADC0_GC2.GAIN15 Position                */
#define ADC_GC2_GAIN15(x)                        (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< ADC0_GC2.GAIN15 Field                   */
/* ------- SCTRL Bit Fields                         ------ */
#define ADC_SCTRL_SC_MASK                        (0xFFFFU)                                           /*!< ADC0_SCTRL.SC Mask                      */
#define ADC_SCTRL_SC_SHIFT                       (0U)                                                /*!< ADC0_SCTRL.SC Position                  */
#define ADC_SCTRL_SC(x)                          (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ADC0_SCTRL.SC Field                     */
/* ------- PWR2 Bit Fields                          ------ */
#define ADC_PWR2_SPEEDA_MASK                     (0x3U)                                              /*!< ADC0_PWR2.SPEEDA Mask                   */
#define ADC_PWR2_SPEEDA_SHIFT                    (0U)                                                /*!< ADC0_PWR2.SPEEDA Position               */
#define ADC_PWR2_SPEEDA(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< ADC0_PWR2.SPEEDA Field                  */
#define ADC_PWR2_SPEEDB_MASK                     (0xCU)                                              /*!< ADC0_PWR2.SPEEDB Mask                   */
#define ADC_PWR2_SPEEDB_SHIFT                    (2U)                                                /*!< ADC0_PWR2.SPEEDB Position               */
#define ADC_PWR2_SPEEDB(x)                       (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< ADC0_PWR2.SPEEDB Field                  */
#define ADC_PWR2_DIV1_MASK                       (0x3F00U)                                           /*!< ADC0_PWR2.DIV1 Mask                     */
#define ADC_PWR2_DIV1_SHIFT                      (8U)                                                /*!< ADC0_PWR2.DIV1 Position                 */
#define ADC_PWR2_DIV1(x)                         (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< ADC0_PWR2.DIV1 Field                    */
/* ------- CTRL3 Bit Fields                         ------ */
#define ADC_CTRL3_SCNT0_MASK                     (0x7U)                                              /*!< ADC0_CTRL3.SCNT0 Mask                   */
#define ADC_CTRL3_SCNT0_SHIFT                    (0U)                                                /*!< ADC0_CTRL3.SCNT0 Position               */
#define ADC_CTRL3_SCNT0(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x7UL)           /*!< ADC0_CTRL3.SCNT0 Field                  */
#define ADC_CTRL3_SCNT1_MASK                     (0x38U)                                             /*!< ADC0_CTRL3.SCNT1 Mask                   */
#define ADC_CTRL3_SCNT1_SHIFT                    (3U)                                                /*!< ADC0_CTRL3.SCNT1 Position               */
#define ADC_CTRL3_SCNT1(x)                       (((uint16_t)(((uint16_t)(x))<<3U))&0x38UL)          /*!< ADC0_CTRL3.SCNT1 Field                  */
#define ADC_CTRL3_DMASRC_MASK                    (0x40U)                                             /*!< ADC0_CTRL3.DMASRC Mask                  */
#define ADC_CTRL3_DMASRC_SHIFT                   (6U)                                                /*!< ADC0_CTRL3.DMASRC Position              */
#define ADC_CTRL3_DMASRC(x)                      (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< ADC0_CTRL3.DMASRC Field                 */
/* ------- SCHLTEN Bit Fields                       ------ */
#define ADC_SCHLTEN_SCHLTEN_MASK                 (0xFFFFU)                                           /*!< ADC0_SCHLTEN.SCHLTEN Mask               */
#define ADC_SCHLTEN_SCHLTEN_SHIFT                (0U)                                                /*!< ADC0_SCHLTEN.SCHLTEN Position           */
#define ADC_SCHLTEN_SCHLTEN(x)                   (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ADC0_SCHLTEN.SCHLTEN Field              */
/**
 * @} */ /* End group ADC_Register_Masks_GROUP 
 */

/* ADC0 - Peripheral instance base addresses */
#define ADC0_BasePtr                   0x4005C000UL //!< Peripheral base address
#define ADC0                           ((ADC_Type *) ADC0_BasePtr) //!< Freescale base pointer
#define ADC0_BASE_PTR                  (ADC0) //!< Freescale style base pointer
/**
 * @} */ /* End group ADC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup AOI_Peripheral_access_layer_GROUP AOI Peripheral Access Layer
* @brief C Struct for AOI
* @{
*/

/* ================================================================================ */
/* ================           AOI (file:AOI_0)                     ================ */
/* ================================================================================ */

/**
 * @brief AND/OR/INVERT module
 */
/**
* @addtogroup AOI_structs_GROUP AOI struct
* @brief Struct for AOI
* @{
*/
typedef struct {                                /*       AOI Structure                                                */
   __IO uint16_t  BFCRT010;                     /**< 0000: Boolean Function Term 0 and 1 Configuration Register for EVENTn */
   __IO uint16_t  BFCRT230;                     /**< 0002: Boolean Function Term 2 and 3 Configuration Register for EVENTn */
   __IO uint16_t  BFCRT011;                     /**< 0004: Boolean Function Term 0 and 1 Configuration Register for EVENTn */
   __IO uint16_t  BFCRT231;                     /**< 0006: Boolean Function Term 2 and 3 Configuration Register for EVENTn */
   __IO uint16_t  BFCRT012;                     /**< 0008: Boolean Function Term 0 and 1 Configuration Register for EVENTn */
   __IO uint16_t  BFCRT232;                     /**< 000A: Boolean Function Term 2 and 3 Configuration Register for EVENTn */
   __IO uint16_t  BFCRT013;                     /**< 000C: Boolean Function Term 0 and 1 Configuration Register for EVENTn */
   __IO uint16_t  BFCRT233;                     /**< 000E: Boolean Function Term 2 and 3 Configuration Register for EVENTn */
} AOI_Type;

/**
 * @} */ /* End group AOI_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'AOI' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup AOI_Register_Masks_GROUP AOI Register Masks
* @brief Register Masks for AOI
* @{
*/
/* ------- BFCRT010 Bit Fields                      ------ */
#define AOI_BFCRT010_PT1_DC_MASK                 (0x3U)                                              /*!< AOI_BFCRT010.PT1_DC Mask                */
#define AOI_BFCRT010_PT1_DC_SHIFT                (0U)                                                /*!< AOI_BFCRT010.PT1_DC Position            */
#define AOI_BFCRT010_PT1_DC(x)                   (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< AOI_BFCRT010.PT1_DC Field               */
#define AOI_BFCRT010_PT1_CC_MASK                 (0xCU)                                              /*!< AOI_BFCRT010.PT1_CC Mask                */
#define AOI_BFCRT010_PT1_CC_SHIFT                (2U)                                                /*!< AOI_BFCRT010.PT1_CC Position            */
#define AOI_BFCRT010_PT1_CC(x)                   (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< AOI_BFCRT010.PT1_CC Field               */
#define AOI_BFCRT010_PT1_BC_MASK                 (0x30U)                                             /*!< AOI_BFCRT010.PT1_BC Mask                */
#define AOI_BFCRT010_PT1_BC_SHIFT                (4U)                                                /*!< AOI_BFCRT010.PT1_BC Position            */
#define AOI_BFCRT010_PT1_BC(x)                   (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< AOI_BFCRT010.PT1_BC Field               */
#define AOI_BFCRT010_PT1_AC_MASK                 (0xC0U)                                             /*!< AOI_BFCRT010.PT1_AC Mask                */
#define AOI_BFCRT010_PT1_AC_SHIFT                (6U)                                                /*!< AOI_BFCRT010.PT1_AC Position            */
#define AOI_BFCRT010_PT1_AC(x)                   (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< AOI_BFCRT010.PT1_AC Field               */
#define AOI_BFCRT010_PT0_DC_MASK                 (0x300U)                                            /*!< AOI_BFCRT010.PT0_DC Mask                */
#define AOI_BFCRT010_PT0_DC_SHIFT                (8U)                                                /*!< AOI_BFCRT010.PT0_DC Position            */
#define AOI_BFCRT010_PT0_DC(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< AOI_BFCRT010.PT0_DC Field               */
#define AOI_BFCRT010_PT0_CC_MASK                 (0xC00U)                                            /*!< AOI_BFCRT010.PT0_CC Mask                */
#define AOI_BFCRT010_PT0_CC_SHIFT                (10U)                                               /*!< AOI_BFCRT010.PT0_CC Position            */
#define AOI_BFCRT010_PT0_CC(x)                   (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< AOI_BFCRT010.PT0_CC Field               */
#define AOI_BFCRT010_PT0_BC_MASK                 (0x3000U)                                           /*!< AOI_BFCRT010.PT0_BC Mask                */
#define AOI_BFCRT010_PT0_BC_SHIFT                (12U)                                               /*!< AOI_BFCRT010.PT0_BC Position            */
#define AOI_BFCRT010_PT0_BC(x)                   (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< AOI_BFCRT010.PT0_BC Field               */
#define AOI_BFCRT010_PT0_AC_MASK                 (0xC000U)                                           /*!< AOI_BFCRT010.PT0_AC Mask                */
#define AOI_BFCRT010_PT0_AC_SHIFT                (14U)                                               /*!< AOI_BFCRT010.PT0_AC Position            */
#define AOI_BFCRT010_PT0_AC(x)                   (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< AOI_BFCRT010.PT0_AC Field               */
/* ------- BFCRT230 Bit Fields                      ------ */
#define AOI_BFCRT230_PT3_DC_MASK                 (0x3U)                                              /*!< AOI_BFCRT230.PT3_DC Mask                */
#define AOI_BFCRT230_PT3_DC_SHIFT                (0U)                                                /*!< AOI_BFCRT230.PT3_DC Position            */
#define AOI_BFCRT230_PT3_DC(x)                   (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< AOI_BFCRT230.PT3_DC Field               */
#define AOI_BFCRT230_PT3_CC_MASK                 (0xCU)                                              /*!< AOI_BFCRT230.PT3_CC Mask                */
#define AOI_BFCRT230_PT3_CC_SHIFT                (2U)                                                /*!< AOI_BFCRT230.PT3_CC Position            */
#define AOI_BFCRT230_PT3_CC(x)                   (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< AOI_BFCRT230.PT3_CC Field               */
#define AOI_BFCRT230_PT3_BC_MASK                 (0x30U)                                             /*!< AOI_BFCRT230.PT3_BC Mask                */
#define AOI_BFCRT230_PT3_BC_SHIFT                (4U)                                                /*!< AOI_BFCRT230.PT3_BC Position            */
#define AOI_BFCRT230_PT3_BC(x)                   (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< AOI_BFCRT230.PT3_BC Field               */
#define AOI_BFCRT230_PT3_AC_MASK                 (0xC0U)                                             /*!< AOI_BFCRT230.PT3_AC Mask                */
#define AOI_BFCRT230_PT3_AC_SHIFT                (6U)                                                /*!< AOI_BFCRT230.PT3_AC Position            */
#define AOI_BFCRT230_PT3_AC(x)                   (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< AOI_BFCRT230.PT3_AC Field               */
#define AOI_BFCRT230_PT2_DC_MASK                 (0x300U)                                            /*!< AOI_BFCRT230.PT2_DC Mask                */
#define AOI_BFCRT230_PT2_DC_SHIFT                (8U)                                                /*!< AOI_BFCRT230.PT2_DC Position            */
#define AOI_BFCRT230_PT2_DC(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< AOI_BFCRT230.PT2_DC Field               */
#define AOI_BFCRT230_PT2_CC_MASK                 (0xC00U)                                            /*!< AOI_BFCRT230.PT2_CC Mask                */
#define AOI_BFCRT230_PT2_CC_SHIFT                (10U)                                               /*!< AOI_BFCRT230.PT2_CC Position            */
#define AOI_BFCRT230_PT2_CC(x)                   (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< AOI_BFCRT230.PT2_CC Field               */
#define AOI_BFCRT230_PT2_BC_MASK                 (0x3000U)                                           /*!< AOI_BFCRT230.PT2_BC Mask                */
#define AOI_BFCRT230_PT2_BC_SHIFT                (12U)                                               /*!< AOI_BFCRT230.PT2_BC Position            */
#define AOI_BFCRT230_PT2_BC(x)                   (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< AOI_BFCRT230.PT2_BC Field               */
#define AOI_BFCRT230_PT2_AC_MASK                 (0xC000U)                                           /*!< AOI_BFCRT230.PT2_AC Mask                */
#define AOI_BFCRT230_PT2_AC_SHIFT                (14U)                                               /*!< AOI_BFCRT230.PT2_AC Position            */
#define AOI_BFCRT230_PT2_AC(x)                   (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< AOI_BFCRT230.PT2_AC Field               */
/* ------- BFCRT011 Bit Fields                      ------ */
#define AOI_BFCRT011_PT1_DC_MASK                 (0x3U)                                              /*!< AOI_BFCRT011.PT1_DC Mask                */
#define AOI_BFCRT011_PT1_DC_SHIFT                (0U)                                                /*!< AOI_BFCRT011.PT1_DC Position            */
#define AOI_BFCRT011_PT1_DC(x)                   (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< AOI_BFCRT011.PT1_DC Field               */
#define AOI_BFCRT011_PT1_CC_MASK                 (0xCU)                                              /*!< AOI_BFCRT011.PT1_CC Mask                */
#define AOI_BFCRT011_PT1_CC_SHIFT                (2U)                                                /*!< AOI_BFCRT011.PT1_CC Position            */
#define AOI_BFCRT011_PT1_CC(x)                   (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< AOI_BFCRT011.PT1_CC Field               */
#define AOI_BFCRT011_PT1_BC_MASK                 (0x30U)                                             /*!< AOI_BFCRT011.PT1_BC Mask                */
#define AOI_BFCRT011_PT1_BC_SHIFT                (4U)                                                /*!< AOI_BFCRT011.PT1_BC Position            */
#define AOI_BFCRT011_PT1_BC(x)                   (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< AOI_BFCRT011.PT1_BC Field               */
#define AOI_BFCRT011_PT1_AC_MASK                 (0xC0U)                                             /*!< AOI_BFCRT011.PT1_AC Mask                */
#define AOI_BFCRT011_PT1_AC_SHIFT                (6U)                                                /*!< AOI_BFCRT011.PT1_AC Position            */
#define AOI_BFCRT011_PT1_AC(x)                   (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< AOI_BFCRT011.PT1_AC Field               */
#define AOI_BFCRT011_PT0_DC_MASK                 (0x300U)                                            /*!< AOI_BFCRT011.PT0_DC Mask                */
#define AOI_BFCRT011_PT0_DC_SHIFT                (8U)                                                /*!< AOI_BFCRT011.PT0_DC Position            */
#define AOI_BFCRT011_PT0_DC(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< AOI_BFCRT011.PT0_DC Field               */
#define AOI_BFCRT011_PT0_CC_MASK                 (0xC00U)                                            /*!< AOI_BFCRT011.PT0_CC Mask                */
#define AOI_BFCRT011_PT0_CC_SHIFT                (10U)                                               /*!< AOI_BFCRT011.PT0_CC Position            */
#define AOI_BFCRT011_PT0_CC(x)                   (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< AOI_BFCRT011.PT0_CC Field               */
#define AOI_BFCRT011_PT0_BC_MASK                 (0x3000U)                                           /*!< AOI_BFCRT011.PT0_BC Mask                */
#define AOI_BFCRT011_PT0_BC_SHIFT                (12U)                                               /*!< AOI_BFCRT011.PT0_BC Position            */
#define AOI_BFCRT011_PT0_BC(x)                   (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< AOI_BFCRT011.PT0_BC Field               */
#define AOI_BFCRT011_PT0_AC_MASK                 (0xC000U)                                           /*!< AOI_BFCRT011.PT0_AC Mask                */
#define AOI_BFCRT011_PT0_AC_SHIFT                (14U)                                               /*!< AOI_BFCRT011.PT0_AC Position            */
#define AOI_BFCRT011_PT0_AC(x)                   (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< AOI_BFCRT011.PT0_AC Field               */
/* ------- BFCRT231 Bit Fields                      ------ */
#define AOI_BFCRT231_PT3_DC_MASK                 (0x3U)                                              /*!< AOI_BFCRT231.PT3_DC Mask                */
#define AOI_BFCRT231_PT3_DC_SHIFT                (0U)                                                /*!< AOI_BFCRT231.PT3_DC Position            */
#define AOI_BFCRT231_PT3_DC(x)                   (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< AOI_BFCRT231.PT3_DC Field               */
#define AOI_BFCRT231_PT3_CC_MASK                 (0xCU)                                              /*!< AOI_BFCRT231.PT3_CC Mask                */
#define AOI_BFCRT231_PT3_CC_SHIFT                (2U)                                                /*!< AOI_BFCRT231.PT3_CC Position            */
#define AOI_BFCRT231_PT3_CC(x)                   (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< AOI_BFCRT231.PT3_CC Field               */
#define AOI_BFCRT231_PT3_BC_MASK                 (0x30U)                                             /*!< AOI_BFCRT231.PT3_BC Mask                */
#define AOI_BFCRT231_PT3_BC_SHIFT                (4U)                                                /*!< AOI_BFCRT231.PT3_BC Position            */
#define AOI_BFCRT231_PT3_BC(x)                   (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< AOI_BFCRT231.PT3_BC Field               */
#define AOI_BFCRT231_PT3_AC_MASK                 (0xC0U)                                             /*!< AOI_BFCRT231.PT3_AC Mask                */
#define AOI_BFCRT231_PT3_AC_SHIFT                (6U)                                                /*!< AOI_BFCRT231.PT3_AC Position            */
#define AOI_BFCRT231_PT3_AC(x)                   (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< AOI_BFCRT231.PT3_AC Field               */
#define AOI_BFCRT231_PT2_DC_MASK                 (0x300U)                                            /*!< AOI_BFCRT231.PT2_DC Mask                */
#define AOI_BFCRT231_PT2_DC_SHIFT                (8U)                                                /*!< AOI_BFCRT231.PT2_DC Position            */
#define AOI_BFCRT231_PT2_DC(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< AOI_BFCRT231.PT2_DC Field               */
#define AOI_BFCRT231_PT2_CC_MASK                 (0xC00U)                                            /*!< AOI_BFCRT231.PT2_CC Mask                */
#define AOI_BFCRT231_PT2_CC_SHIFT                (10U)                                               /*!< AOI_BFCRT231.PT2_CC Position            */
#define AOI_BFCRT231_PT2_CC(x)                   (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< AOI_BFCRT231.PT2_CC Field               */
#define AOI_BFCRT231_PT2_BC_MASK                 (0x3000U)                                           /*!< AOI_BFCRT231.PT2_BC Mask                */
#define AOI_BFCRT231_PT2_BC_SHIFT                (12U)                                               /*!< AOI_BFCRT231.PT2_BC Position            */
#define AOI_BFCRT231_PT2_BC(x)                   (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< AOI_BFCRT231.PT2_BC Field               */
#define AOI_BFCRT231_PT2_AC_MASK                 (0xC000U)                                           /*!< AOI_BFCRT231.PT2_AC Mask                */
#define AOI_BFCRT231_PT2_AC_SHIFT                (14U)                                               /*!< AOI_BFCRT231.PT2_AC Position            */
#define AOI_BFCRT231_PT2_AC(x)                   (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< AOI_BFCRT231.PT2_AC Field               */
/* ------- BFCRT012 Bit Fields                      ------ */
#define AOI_BFCRT012_PT1_DC_MASK                 (0x3U)                                              /*!< AOI_BFCRT012.PT1_DC Mask                */
#define AOI_BFCRT012_PT1_DC_SHIFT                (0U)                                                /*!< AOI_BFCRT012.PT1_DC Position            */
#define AOI_BFCRT012_PT1_DC(x)                   (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< AOI_BFCRT012.PT1_DC Field               */
#define AOI_BFCRT012_PT1_CC_MASK                 (0xCU)                                              /*!< AOI_BFCRT012.PT1_CC Mask                */
#define AOI_BFCRT012_PT1_CC_SHIFT                (2U)                                                /*!< AOI_BFCRT012.PT1_CC Position            */
#define AOI_BFCRT012_PT1_CC(x)                   (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< AOI_BFCRT012.PT1_CC Field               */
#define AOI_BFCRT012_PT1_BC_MASK                 (0x30U)                                             /*!< AOI_BFCRT012.PT1_BC Mask                */
#define AOI_BFCRT012_PT1_BC_SHIFT                (4U)                                                /*!< AOI_BFCRT012.PT1_BC Position            */
#define AOI_BFCRT012_PT1_BC(x)                   (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< AOI_BFCRT012.PT1_BC Field               */
#define AOI_BFCRT012_PT1_AC_MASK                 (0xC0U)                                             /*!< AOI_BFCRT012.PT1_AC Mask                */
#define AOI_BFCRT012_PT1_AC_SHIFT                (6U)                                                /*!< AOI_BFCRT012.PT1_AC Position            */
#define AOI_BFCRT012_PT1_AC(x)                   (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< AOI_BFCRT012.PT1_AC Field               */
#define AOI_BFCRT012_PT0_DC_MASK                 (0x300U)                                            /*!< AOI_BFCRT012.PT0_DC Mask                */
#define AOI_BFCRT012_PT0_DC_SHIFT                (8U)                                                /*!< AOI_BFCRT012.PT0_DC Position            */
#define AOI_BFCRT012_PT0_DC(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< AOI_BFCRT012.PT0_DC Field               */
#define AOI_BFCRT012_PT0_CC_MASK                 (0xC00U)                                            /*!< AOI_BFCRT012.PT0_CC Mask                */
#define AOI_BFCRT012_PT0_CC_SHIFT                (10U)                                               /*!< AOI_BFCRT012.PT0_CC Position            */
#define AOI_BFCRT012_PT0_CC(x)                   (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< AOI_BFCRT012.PT0_CC Field               */
#define AOI_BFCRT012_PT0_BC_MASK                 (0x3000U)                                           /*!< AOI_BFCRT012.PT0_BC Mask                */
#define AOI_BFCRT012_PT0_BC_SHIFT                (12U)                                               /*!< AOI_BFCRT012.PT0_BC Position            */
#define AOI_BFCRT012_PT0_BC(x)                   (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< AOI_BFCRT012.PT0_BC Field               */
#define AOI_BFCRT012_PT0_AC_MASK                 (0xC000U)                                           /*!< AOI_BFCRT012.PT0_AC Mask                */
#define AOI_BFCRT012_PT0_AC_SHIFT                (14U)                                               /*!< AOI_BFCRT012.PT0_AC Position            */
#define AOI_BFCRT012_PT0_AC(x)                   (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< AOI_BFCRT012.PT0_AC Field               */
/* ------- BFCRT232 Bit Fields                      ------ */
#define AOI_BFCRT232_PT3_DC_MASK                 (0x3U)                                              /*!< AOI_BFCRT232.PT3_DC Mask                */
#define AOI_BFCRT232_PT3_DC_SHIFT                (0U)                                                /*!< AOI_BFCRT232.PT3_DC Position            */
#define AOI_BFCRT232_PT3_DC(x)                   (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< AOI_BFCRT232.PT3_DC Field               */
#define AOI_BFCRT232_PT3_CC_MASK                 (0xCU)                                              /*!< AOI_BFCRT232.PT3_CC Mask                */
#define AOI_BFCRT232_PT3_CC_SHIFT                (2U)                                                /*!< AOI_BFCRT232.PT3_CC Position            */
#define AOI_BFCRT232_PT3_CC(x)                   (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< AOI_BFCRT232.PT3_CC Field               */
#define AOI_BFCRT232_PT3_BC_MASK                 (0x30U)                                             /*!< AOI_BFCRT232.PT3_BC Mask                */
#define AOI_BFCRT232_PT3_BC_SHIFT                (4U)                                                /*!< AOI_BFCRT232.PT3_BC Position            */
#define AOI_BFCRT232_PT3_BC(x)                   (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< AOI_BFCRT232.PT3_BC Field               */
#define AOI_BFCRT232_PT3_AC_MASK                 (0xC0U)                                             /*!< AOI_BFCRT232.PT3_AC Mask                */
#define AOI_BFCRT232_PT3_AC_SHIFT                (6U)                                                /*!< AOI_BFCRT232.PT3_AC Position            */
#define AOI_BFCRT232_PT3_AC(x)                   (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< AOI_BFCRT232.PT3_AC Field               */
#define AOI_BFCRT232_PT2_DC_MASK                 (0x300U)                                            /*!< AOI_BFCRT232.PT2_DC Mask                */
#define AOI_BFCRT232_PT2_DC_SHIFT                (8U)                                                /*!< AOI_BFCRT232.PT2_DC Position            */
#define AOI_BFCRT232_PT2_DC(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< AOI_BFCRT232.PT2_DC Field               */
#define AOI_BFCRT232_PT2_CC_MASK                 (0xC00U)                                            /*!< AOI_BFCRT232.PT2_CC Mask                */
#define AOI_BFCRT232_PT2_CC_SHIFT                (10U)                                               /*!< AOI_BFCRT232.PT2_CC Position            */
#define AOI_BFCRT232_PT2_CC(x)                   (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< AOI_BFCRT232.PT2_CC Field               */
#define AOI_BFCRT232_PT2_BC_MASK                 (0x3000U)                                           /*!< AOI_BFCRT232.PT2_BC Mask                */
#define AOI_BFCRT232_PT2_BC_SHIFT                (12U)                                               /*!< AOI_BFCRT232.PT2_BC Position            */
#define AOI_BFCRT232_PT2_BC(x)                   (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< AOI_BFCRT232.PT2_BC Field               */
#define AOI_BFCRT232_PT2_AC_MASK                 (0xC000U)                                           /*!< AOI_BFCRT232.PT2_AC Mask                */
#define AOI_BFCRT232_PT2_AC_SHIFT                (14U)                                               /*!< AOI_BFCRT232.PT2_AC Position            */
#define AOI_BFCRT232_PT2_AC(x)                   (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< AOI_BFCRT232.PT2_AC Field               */
/* ------- BFCRT013 Bit Fields                      ------ */
#define AOI_BFCRT013_PT1_DC_MASK                 (0x3U)                                              /*!< AOI_BFCRT013.PT1_DC Mask                */
#define AOI_BFCRT013_PT1_DC_SHIFT                (0U)                                                /*!< AOI_BFCRT013.PT1_DC Position            */
#define AOI_BFCRT013_PT1_DC(x)                   (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< AOI_BFCRT013.PT1_DC Field               */
#define AOI_BFCRT013_PT1_CC_MASK                 (0xCU)                                              /*!< AOI_BFCRT013.PT1_CC Mask                */
#define AOI_BFCRT013_PT1_CC_SHIFT                (2U)                                                /*!< AOI_BFCRT013.PT1_CC Position            */
#define AOI_BFCRT013_PT1_CC(x)                   (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< AOI_BFCRT013.PT1_CC Field               */
#define AOI_BFCRT013_PT1_BC_MASK                 (0x30U)                                             /*!< AOI_BFCRT013.PT1_BC Mask                */
#define AOI_BFCRT013_PT1_BC_SHIFT                (4U)                                                /*!< AOI_BFCRT013.PT1_BC Position            */
#define AOI_BFCRT013_PT1_BC(x)                   (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< AOI_BFCRT013.PT1_BC Field               */
#define AOI_BFCRT013_PT1_AC_MASK                 (0xC0U)                                             /*!< AOI_BFCRT013.PT1_AC Mask                */
#define AOI_BFCRT013_PT1_AC_SHIFT                (6U)                                                /*!< AOI_BFCRT013.PT1_AC Position            */
#define AOI_BFCRT013_PT1_AC(x)                   (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< AOI_BFCRT013.PT1_AC Field               */
#define AOI_BFCRT013_PT0_DC_MASK                 (0x300U)                                            /*!< AOI_BFCRT013.PT0_DC Mask                */
#define AOI_BFCRT013_PT0_DC_SHIFT                (8U)                                                /*!< AOI_BFCRT013.PT0_DC Position            */
#define AOI_BFCRT013_PT0_DC(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< AOI_BFCRT013.PT0_DC Field               */
#define AOI_BFCRT013_PT0_CC_MASK                 (0xC00U)                                            /*!< AOI_BFCRT013.PT0_CC Mask                */
#define AOI_BFCRT013_PT0_CC_SHIFT                (10U)                                               /*!< AOI_BFCRT013.PT0_CC Position            */
#define AOI_BFCRT013_PT0_CC(x)                   (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< AOI_BFCRT013.PT0_CC Field               */
#define AOI_BFCRT013_PT0_BC_MASK                 (0x3000U)                                           /*!< AOI_BFCRT013.PT0_BC Mask                */
#define AOI_BFCRT013_PT0_BC_SHIFT                (12U)                                               /*!< AOI_BFCRT013.PT0_BC Position            */
#define AOI_BFCRT013_PT0_BC(x)                   (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< AOI_BFCRT013.PT0_BC Field               */
#define AOI_BFCRT013_PT0_AC_MASK                 (0xC000U)                                           /*!< AOI_BFCRT013.PT0_AC Mask                */
#define AOI_BFCRT013_PT0_AC_SHIFT                (14U)                                               /*!< AOI_BFCRT013.PT0_AC Position            */
#define AOI_BFCRT013_PT0_AC(x)                   (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< AOI_BFCRT013.PT0_AC Field               */
/* ------- BFCRT233 Bit Fields                      ------ */
#define AOI_BFCRT233_PT3_DC_MASK                 (0x3U)                                              /*!< AOI_BFCRT233.PT3_DC Mask                */
#define AOI_BFCRT233_PT3_DC_SHIFT                (0U)                                                /*!< AOI_BFCRT233.PT3_DC Position            */
#define AOI_BFCRT233_PT3_DC(x)                   (((uint16_t)(((uint16_t)(x))<<0U))&0x3UL)           /*!< AOI_BFCRT233.PT3_DC Field               */
#define AOI_BFCRT233_PT3_CC_MASK                 (0xCU)                                              /*!< AOI_BFCRT233.PT3_CC Mask                */
#define AOI_BFCRT233_PT3_CC_SHIFT                (2U)                                                /*!< AOI_BFCRT233.PT3_CC Position            */
#define AOI_BFCRT233_PT3_CC(x)                   (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< AOI_BFCRT233.PT3_CC Field               */
#define AOI_BFCRT233_PT3_BC_MASK                 (0x30U)                                             /*!< AOI_BFCRT233.PT3_BC Mask                */
#define AOI_BFCRT233_PT3_BC_SHIFT                (4U)                                                /*!< AOI_BFCRT233.PT3_BC Position            */
#define AOI_BFCRT233_PT3_BC(x)                   (((uint16_t)(((uint16_t)(x))<<4U))&0x30UL)          /*!< AOI_BFCRT233.PT3_BC Field               */
#define AOI_BFCRT233_PT3_AC_MASK                 (0xC0U)                                             /*!< AOI_BFCRT233.PT3_AC Mask                */
#define AOI_BFCRT233_PT3_AC_SHIFT                (6U)                                                /*!< AOI_BFCRT233.PT3_AC Position            */
#define AOI_BFCRT233_PT3_AC(x)                   (((uint16_t)(((uint16_t)(x))<<6U))&0xC0UL)          /*!< AOI_BFCRT233.PT3_AC Field               */
#define AOI_BFCRT233_PT2_DC_MASK                 (0x300U)                                            /*!< AOI_BFCRT233.PT2_DC Mask                */
#define AOI_BFCRT233_PT2_DC_SHIFT                (8U)                                                /*!< AOI_BFCRT233.PT2_DC Position            */
#define AOI_BFCRT233_PT2_DC(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0x300UL)         /*!< AOI_BFCRT233.PT2_DC Field               */
#define AOI_BFCRT233_PT2_CC_MASK                 (0xC00U)                                            /*!< AOI_BFCRT233.PT2_CC Mask                */
#define AOI_BFCRT233_PT2_CC_SHIFT                (10U)                                               /*!< AOI_BFCRT233.PT2_CC Position            */
#define AOI_BFCRT233_PT2_CC(x)                   (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< AOI_BFCRT233.PT2_CC Field               */
#define AOI_BFCRT233_PT2_BC_MASK                 (0x3000U)                                           /*!< AOI_BFCRT233.PT2_BC Mask                */
#define AOI_BFCRT233_PT2_BC_SHIFT                (12U)                                               /*!< AOI_BFCRT233.PT2_BC Position            */
#define AOI_BFCRT233_PT2_BC(x)                   (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< AOI_BFCRT233.PT2_BC Field               */
#define AOI_BFCRT233_PT2_AC_MASK                 (0xC000U)                                           /*!< AOI_BFCRT233.PT2_AC Mask                */
#define AOI_BFCRT233_PT2_AC_SHIFT                (14U)                                               /*!< AOI_BFCRT233.PT2_AC Position            */
#define AOI_BFCRT233_PT2_AC(x)                   (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< AOI_BFCRT233.PT2_AC Field               */
/**
 * @} */ /* End group AOI_Register_Masks_GROUP 
 */

/* AOI - Peripheral instance base addresses */
#define AOI_BasePtr                    0x4005B000UL //!< Peripheral base address
#define AOI                            ((AOI_Type *) AOI_BasePtr) //!< Freescale base pointer
#define AOI_BASE_PTR                   (AOI) //!< Freescale style base pointer
/**
 * @} */ /* End group AOI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CAN_Peripheral_access_layer_GROUP CAN Peripheral Access Layer
* @brief C Struct for CAN
* @{
*/

/* ================================================================================ */
/* ================           CAN0 (file:CAN0_MKV)                 ================ */
/* ================================================================================ */

/**
 * @brief Flex Controller Area Network module
 */
/**
* @addtogroup CAN_structs_GROUP CAN struct
* @brief Struct for CAN
* @{
*/
typedef struct {                                /*       CAN0 Structure                                               */
   __IO uint32_t  MCR;                          /**< 0000: Module Configuration Register                                */
   __IO uint32_t  CTRL1;                        /**< 0004: Control 1 Register                                           */
   __IO uint32_t  TIMER;                        /**< 0008: Free Running Timer                                           */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  RXMGMASK;                     /**< 0010: Rx Mailboxes Global Mask Register                            */
   __IO uint32_t  RX14MASK;                     /**< 0014: Rx 14 Mask register                                          */
   __IO uint32_t  RX15MASK;                     /**< 0018: Rx 15 Mask register                                          */
   __IO uint32_t  ECR;                          /**< 001C: Error Counter                                                */
   __IO uint32_t  ESR1;                         /**< 0020: Error and Status 1 register                                  */
   __IO uint32_t  IMASK2;                       /**< 0024: Interrupt Masks 2 Register                                   */
   __IO uint32_t  IMASK1;                       /**< 0028: Interrupt Masks 1 register                                   */
   __IO uint32_t  IFLAG2;                       /**< 002C: Interrupt Flags 2 Register                                   */
   __IO uint32_t  IFLAG1;                       /**< 0030: Interrupt Flags 1 register                                   */
   __IO uint32_t  CTRL2;                        /**< 0034: Control 2 Register                                           */
   __I  uint32_t  ESR2;                         /**< 0038: Error and Status 2 register                                  */
        uint8_t   RESERVED_1[8];               
   __I  uint32_t  CRCR;                         /**< 0044: CRC Register                                                 */
   __IO uint32_t  RXFGMASK;                     /**< 0048: Rx FIFO Global Mask register                                 */
   __I  uint32_t  RXFIR;                        /**< 004C: Rx FIFO Information Register                                 */
   __IO uint32_t  CBT;                          /**< 0050: CAN Bit Timing Register                                      */
        uint8_t   RESERVED_2[44];              
   struct {
      __IO uint32_t  CS;                        /**< 0080: Message Buffer 0 CS Register                                 */
      __IO uint32_t  ID;                        /**< 0084: Message Buffer 0 ID Register                                 */
      __IO uint32_t  WORD0;                     /**< 0088: Message Buffer 0 WORD0 Register                              */
      __IO uint32_t  WORD1;                     /**< 008C: Message Buffer 0 WORD1 Register                              */
   } MB[16];                                    /**< 0080: (cluster: size=0x0100, 256)                                  */
        uint8_t   RESERVED_4[1792];            
   __IO uint32_t  RXIMR[16];                    /**< 0880: Rx Individual Mask                                           */
} CAN_Type;

/**
 * @} */ /* End group CAN_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CAN0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CAN_Register_Masks_GROUP CAN Register Masks
* @brief Register Masks for CAN
* @{
*/
/* ------- MCR Bit Fields                           ------ */
#define CAN_MCR_MAXMB_MASK                       (0x7FU)                                             /*!< CAN0_MCR.MAXMB Mask                     */
#define CAN_MCR_MAXMB_SHIFT                      (0U)                                                /*!< CAN0_MCR.MAXMB Position                 */
#define CAN_MCR_MAXMB(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x7FUL)          /*!< CAN0_MCR.MAXMB Field                    */
#define CAN_MCR_IDAM_MASK                        (0x300U)                                            /*!< CAN0_MCR.IDAM Mask                      */
#define CAN_MCR_IDAM_SHIFT                       (8U)                                                /*!< CAN0_MCR.IDAM Position                  */
#define CAN_MCR_IDAM(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0x300UL)         /*!< CAN0_MCR.IDAM Field                     */
#define CAN_MCR_AEN_MASK                         (0x1000U)                                           /*!< CAN0_MCR.AEN Mask                       */
#define CAN_MCR_AEN_SHIFT                        (12U)                                               /*!< CAN0_MCR.AEN Position                   */
#define CAN_MCR_AEN(x)                           (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< CAN0_MCR.AEN Field                      */
#define CAN_MCR_LPRIOEN_MASK                     (0x2000U)                                           /*!< CAN0_MCR.LPRIOEN Mask                   */
#define CAN_MCR_LPRIOEN_SHIFT                    (13U)                                               /*!< CAN0_MCR.LPRIOEN Position               */
#define CAN_MCR_LPRIOEN(x)                       (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< CAN0_MCR.LPRIOEN Field                  */
#define CAN_MCR_DMA_MASK                         (0x8000U)                                           /*!< CAN0_MCR.DMA Mask                       */
#define CAN_MCR_DMA_SHIFT                        (15U)                                               /*!< CAN0_MCR.DMA Position                   */
#define CAN_MCR_DMA(x)                           (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< CAN0_MCR.DMA Field                      */
#define CAN_MCR_IRMQ_MASK                        (0x10000U)                                          /*!< CAN0_MCR.IRMQ Mask                      */
#define CAN_MCR_IRMQ_SHIFT                       (16U)                                               /*!< CAN0_MCR.IRMQ Position                  */
#define CAN_MCR_IRMQ(x)                          (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< CAN0_MCR.IRMQ Field                     */
#define CAN_MCR_SRXDIS_MASK                      (0x20000U)                                          /*!< CAN0_MCR.SRXDIS Mask                    */
#define CAN_MCR_SRXDIS_SHIFT                     (17U)                                               /*!< CAN0_MCR.SRXDIS Position                */
#define CAN_MCR_SRXDIS(x)                        (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< CAN0_MCR.SRXDIS Field                   */
#define CAN_MCR_DOZE_MASK                        (0x40000U)                                          /*!< CAN0_MCR.DOZE Mask                      */
#define CAN_MCR_DOZE_SHIFT                       (18U)                                               /*!< CAN0_MCR.DOZE Position                  */
#define CAN_MCR_DOZE(x)                          (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< CAN0_MCR.DOZE Field                     */
#define CAN_MCR_WAKSRC_MASK                      (0x80000U)                                          /*!< CAN0_MCR.WAKSRC Mask                    */
#define CAN_MCR_WAKSRC_SHIFT                     (19U)                                               /*!< CAN0_MCR.WAKSRC Position                */
#define CAN_MCR_WAKSRC(x)                        (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< CAN0_MCR.WAKSRC Field                   */
#define CAN_MCR_LPMACK_MASK                      (0x100000U)                                         /*!< CAN0_MCR.LPMACK Mask                    */
#define CAN_MCR_LPMACK_SHIFT                     (20U)                                               /*!< CAN0_MCR.LPMACK Position                */
#define CAN_MCR_LPMACK(x)                        (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< CAN0_MCR.LPMACK Field                   */
#define CAN_MCR_WRNEN_MASK                       (0x200000U)                                         /*!< CAN0_MCR.WRNEN Mask                     */
#define CAN_MCR_WRNEN_SHIFT                      (21U)                                               /*!< CAN0_MCR.WRNEN Position                 */
#define CAN_MCR_WRNEN(x)                         (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< CAN0_MCR.WRNEN Field                    */
#define CAN_MCR_SLFWAK_MASK                      (0x400000U)                                         /*!< CAN0_MCR.SLFWAK Mask                    */
#define CAN_MCR_SLFWAK_SHIFT                     (22U)                                               /*!< CAN0_MCR.SLFWAK Position                */
#define CAN_MCR_SLFWAK(x)                        (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< CAN0_MCR.SLFWAK Field                   */
#define CAN_MCR_SUPV_MASK                        (0x800000U)                                         /*!< CAN0_MCR.SUPV Mask                      */
#define CAN_MCR_SUPV_SHIFT                       (23U)                                               /*!< CAN0_MCR.SUPV Position                  */
#define CAN_MCR_SUPV(x)                          (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< CAN0_MCR.SUPV Field                     */
#define CAN_MCR_FRZACK_MASK                      (0x1000000U)                                        /*!< CAN0_MCR.FRZACK Mask                    */
#define CAN_MCR_FRZACK_SHIFT                     (24U)                                               /*!< CAN0_MCR.FRZACK Position                */
#define CAN_MCR_FRZACK(x)                        (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< CAN0_MCR.FRZACK Field                   */
#define CAN_MCR_SOFTRST_MASK                     (0x2000000U)                                        /*!< CAN0_MCR.SOFTRST Mask                   */
#define CAN_MCR_SOFTRST_SHIFT                    (25U)                                               /*!< CAN0_MCR.SOFTRST Position               */
#define CAN_MCR_SOFTRST(x)                       (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< CAN0_MCR.SOFTRST Field                  */
#define CAN_MCR_WAKMSK_MASK                      (0x4000000U)                                        /*!< CAN0_MCR.WAKMSK Mask                    */
#define CAN_MCR_WAKMSK_SHIFT                     (26U)                                               /*!< CAN0_MCR.WAKMSK Position                */
#define CAN_MCR_WAKMSK(x)                        (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< CAN0_MCR.WAKMSK Field                   */
#define CAN_MCR_NOTRDY_MASK                      (0x8000000U)                                        /*!< CAN0_MCR.NOTRDY Mask                    */
#define CAN_MCR_NOTRDY_SHIFT                     (27U)                                               /*!< CAN0_MCR.NOTRDY Position                */
#define CAN_MCR_NOTRDY(x)                        (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< CAN0_MCR.NOTRDY Field                   */
#define CAN_MCR_HALT_MASK                        (0x10000000U)                                       /*!< CAN0_MCR.HALT Mask                      */
#define CAN_MCR_HALT_SHIFT                       (28U)                                               /*!< CAN0_MCR.HALT Position                  */
#define CAN_MCR_HALT(x)                          (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< CAN0_MCR.HALT Field                     */
#define CAN_MCR_RFEN_MASK                        (0x20000000U)                                       /*!< CAN0_MCR.RFEN Mask                      */
#define CAN_MCR_RFEN_SHIFT                       (29U)                                               /*!< CAN0_MCR.RFEN Position                  */
#define CAN_MCR_RFEN(x)                          (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< CAN0_MCR.RFEN Field                     */
#define CAN_MCR_FRZ_MASK                         (0x40000000U)                                       /*!< CAN0_MCR.FRZ Mask                       */
#define CAN_MCR_FRZ_SHIFT                        (30U)                                               /*!< CAN0_MCR.FRZ Position                   */
#define CAN_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< CAN0_MCR.FRZ Field                      */
#define CAN_MCR_MDIS_MASK                        (0x80000000U)                                       /*!< CAN0_MCR.MDIS Mask                      */
#define CAN_MCR_MDIS_SHIFT                       (31U)                                               /*!< CAN0_MCR.MDIS Position                  */
#define CAN_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< CAN0_MCR.MDIS Field                     */
/* ------- CTRL1 Bit Fields                         ------ */
#define CAN_CTRL1_PROPSEG_MASK                   (0x7U)                                              /*!< CAN0_CTRL1.PROPSEG Mask                 */
#define CAN_CTRL1_PROPSEG_SHIFT                  (0U)                                                /*!< CAN0_CTRL1.PROPSEG Position             */
#define CAN_CTRL1_PROPSEG(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< CAN0_CTRL1.PROPSEG Field                */
#define CAN_CTRL1_LOM_MASK                       (0x8U)                                              /*!< CAN0_CTRL1.LOM Mask                     */
#define CAN_CTRL1_LOM_SHIFT                      (3U)                                                /*!< CAN0_CTRL1.LOM Position                 */
#define CAN_CTRL1_LOM(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< CAN0_CTRL1.LOM Field                    */
#define CAN_CTRL1_LBUF_MASK                      (0x10U)                                             /*!< CAN0_CTRL1.LBUF Mask                    */
#define CAN_CTRL1_LBUF_SHIFT                     (4U)                                                /*!< CAN0_CTRL1.LBUF Position                */
#define CAN_CTRL1_LBUF(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< CAN0_CTRL1.LBUF Field                   */
#define CAN_CTRL1_TSYN_MASK                      (0x20U)                                             /*!< CAN0_CTRL1.TSYN Mask                    */
#define CAN_CTRL1_TSYN_SHIFT                     (5U)                                                /*!< CAN0_CTRL1.TSYN Position                */
#define CAN_CTRL1_TSYN(x)                        (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< CAN0_CTRL1.TSYN Field                   */
#define CAN_CTRL1_BOFFREC_MASK                   (0x40U)                                             /*!< CAN0_CTRL1.BOFFREC Mask                 */
#define CAN_CTRL1_BOFFREC_SHIFT                  (6U)                                                /*!< CAN0_CTRL1.BOFFREC Position             */
#define CAN_CTRL1_BOFFREC(x)                     (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< CAN0_CTRL1.BOFFREC Field                */
#define CAN_CTRL1_SMP_MASK                       (0x80U)                                             /*!< CAN0_CTRL1.SMP Mask                     */
#define CAN_CTRL1_SMP_SHIFT                      (7U)                                                /*!< CAN0_CTRL1.SMP Position                 */
#define CAN_CTRL1_SMP(x)                         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< CAN0_CTRL1.SMP Field                    */
#define CAN_CTRL1_RWRNMSK_MASK                   (0x400U)                                            /*!< CAN0_CTRL1.RWRNMSK Mask                 */
#define CAN_CTRL1_RWRNMSK_SHIFT                  (10U)                                               /*!< CAN0_CTRL1.RWRNMSK Position             */
#define CAN_CTRL1_RWRNMSK(x)                     (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< CAN0_CTRL1.RWRNMSK Field                */
#define CAN_CTRL1_TWRNMSK_MASK                   (0x800U)                                            /*!< CAN0_CTRL1.TWRNMSK Mask                 */
#define CAN_CTRL1_TWRNMSK_SHIFT                  (11U)                                               /*!< CAN0_CTRL1.TWRNMSK Position             */
#define CAN_CTRL1_TWRNMSK(x)                     (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< CAN0_CTRL1.TWRNMSK Field                */
#define CAN_CTRL1_LPB_MASK                       (0x1000U)                                           /*!< CAN0_CTRL1.LPB Mask                     */
#define CAN_CTRL1_LPB_SHIFT                      (12U)                                               /*!< CAN0_CTRL1.LPB Position                 */
#define CAN_CTRL1_LPB(x)                         (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< CAN0_CTRL1.LPB Field                    */
#define CAN_CTRL1_CLKSRC_MASK                    (0x2000U)                                           /*!< CAN0_CTRL1.CLKSRC Mask                  */
#define CAN_CTRL1_CLKSRC_SHIFT                   (13U)                                               /*!< CAN0_CTRL1.CLKSRC Position              */
#define CAN_CTRL1_CLKSRC(x)                      (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< CAN0_CTRL1.CLKSRC Field                 */
#define CAN_CTRL1_ERRMSK_MASK                    (0x4000U)                                           /*!< CAN0_CTRL1.ERRMSK Mask                  */
#define CAN_CTRL1_ERRMSK_SHIFT                   (14U)                                               /*!< CAN0_CTRL1.ERRMSK Position              */
#define CAN_CTRL1_ERRMSK(x)                      (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< CAN0_CTRL1.ERRMSK Field                 */
#define CAN_CTRL1_BOFFMSK_MASK                   (0x8000U)                                           /*!< CAN0_CTRL1.BOFFMSK Mask                 */
#define CAN_CTRL1_BOFFMSK_SHIFT                  (15U)                                               /*!< CAN0_CTRL1.BOFFMSK Position             */
#define CAN_CTRL1_BOFFMSK(x)                     (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< CAN0_CTRL1.BOFFMSK Field                */
#define CAN_CTRL1_PSEG2_MASK                     (0x70000U)                                          /*!< CAN0_CTRL1.PSEG2 Mask                   */
#define CAN_CTRL1_PSEG2_SHIFT                    (16U)                                               /*!< CAN0_CTRL1.PSEG2 Position               */
#define CAN_CTRL1_PSEG2(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0x70000UL)      /*!< CAN0_CTRL1.PSEG2 Field                  */
#define CAN_CTRL1_PSEG1_MASK                     (0x380000U)                                         /*!< CAN0_CTRL1.PSEG1 Mask                   */
#define CAN_CTRL1_PSEG1_SHIFT                    (19U)                                               /*!< CAN0_CTRL1.PSEG1 Position               */
#define CAN_CTRL1_PSEG1(x)                       (((uint32_t)(((uint32_t)(x))<<19U))&0x380000UL)     /*!< CAN0_CTRL1.PSEG1 Field                  */
#define CAN_CTRL1_RJW_MASK                       (0xC00000U)                                         /*!< CAN0_CTRL1.RJW Mask                     */
#define CAN_CTRL1_RJW_SHIFT                      (22U)                                               /*!< CAN0_CTRL1.RJW Position                 */
#define CAN_CTRL1_RJW(x)                         (((uint32_t)(((uint32_t)(x))<<22U))&0xC00000UL)     /*!< CAN0_CTRL1.RJW Field                    */
#define CAN_CTRL1_PRESDIV_MASK                   (0xFF000000U)                                       /*!< CAN0_CTRL1.PRESDIV Mask                 */
#define CAN_CTRL1_PRESDIV_SHIFT                  (24U)                                               /*!< CAN0_CTRL1.PRESDIV Position             */
#define CAN_CTRL1_PRESDIV(x)                     (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< CAN0_CTRL1.PRESDIV Field                */
/* ------- TIMER Bit Fields                         ------ */
#define CAN_TIMER_TIMER_MASK                     (0xFFFFU)                                           /*!< CAN0_TIMER.TIMER Mask                   */
#define CAN_TIMER_TIMER_SHIFT                    (0U)                                                /*!< CAN0_TIMER.TIMER Position               */
#define CAN_TIMER_TIMER(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< CAN0_TIMER.TIMER Field                  */
/* ------- RXMGMASK Bit Fields                      ------ */
#define CAN_RXMGMASK_MG_MASK                     (0xFFFFFFFFU)                                       /*!< CAN0_RXMGMASK.MG Mask                   */
#define CAN_RXMGMASK_MG_SHIFT                    (0U)                                                /*!< CAN0_RXMGMASK.MG Position               */
#define CAN_RXMGMASK_MG(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CAN0_RXMGMASK.MG Field                  */
/* ------- RX14MASK Bit Fields                      ------ */
#define CAN_RX14MASK_RX14M_MASK                  (0xFFFFFFFFU)                                       /*!< CAN0_RX14MASK.RX14M Mask                */
#define CAN_RX14MASK_RX14M_SHIFT                 (0U)                                                /*!< CAN0_RX14MASK.RX14M Position            */
#define CAN_RX14MASK_RX14M(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CAN0_RX14MASK.RX14M Field               */
/* ------- RX15MASK Bit Fields                      ------ */
#define CAN_RX15MASK_RX15M_MASK                  (0xFFFFFFFFU)                                       /*!< CAN0_RX15MASK.RX15M Mask                */
#define CAN_RX15MASK_RX15M_SHIFT                 (0U)                                                /*!< CAN0_RX15MASK.RX15M Position            */
#define CAN_RX15MASK_RX15M(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CAN0_RX15MASK.RX15M Field               */
/* ------- ECR Bit Fields                           ------ */
#define CAN_ECR_TXERRCNT_MASK                    (0xFFU)                                             /*!< CAN0_ECR.TXERRCNT Mask                  */
#define CAN_ECR_TXERRCNT_SHIFT                   (0U)                                                /*!< CAN0_ECR.TXERRCNT Position              */
#define CAN_ECR_TXERRCNT(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< CAN0_ECR.TXERRCNT Field                 */
#define CAN_ECR_RXERRCNT_MASK                    (0xFF00U)                                           /*!< CAN0_ECR.RXERRCNT Mask                  */
#define CAN_ECR_RXERRCNT_SHIFT                   (8U)                                                /*!< CAN0_ECR.RXERRCNT Position              */
#define CAN_ECR_RXERRCNT(x)                      (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< CAN0_ECR.RXERRCNT Field                 */
/* ------- ESR1 Bit Fields                          ------ */
#define CAN_ESR1_WAKINT_MASK                     (0x1U)                                              /*!< CAN0_ESR1.WAKINT Mask                   */
#define CAN_ESR1_WAKINT_SHIFT                    (0U)                                                /*!< CAN0_ESR1.WAKINT Position               */
#define CAN_ESR1_WAKINT(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< CAN0_ESR1.WAKINT Field                  */
#define CAN_ESR1_ERRINT_MASK                     (0x2U)                                              /*!< CAN0_ESR1.ERRINT Mask                   */
#define CAN_ESR1_ERRINT_SHIFT                    (1U)                                                /*!< CAN0_ESR1.ERRINT Position               */
#define CAN_ESR1_ERRINT(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< CAN0_ESR1.ERRINT Field                  */
#define CAN_ESR1_BOFFINT_MASK                    (0x4U)                                              /*!< CAN0_ESR1.BOFFINT Mask                  */
#define CAN_ESR1_BOFFINT_SHIFT                   (2U)                                                /*!< CAN0_ESR1.BOFFINT Position              */
#define CAN_ESR1_BOFFINT(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< CAN0_ESR1.BOFFINT Field                 */
#define CAN_ESR1_RX_MASK                         (0x8U)                                              /*!< CAN0_ESR1.RX Mask                       */
#define CAN_ESR1_RX_SHIFT                        (3U)                                                /*!< CAN0_ESR1.RX Position                   */
#define CAN_ESR1_RX(x)                           (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< CAN0_ESR1.RX Field                      */
#define CAN_ESR1_FLTCONF_MASK                    (0x30U)                                             /*!< CAN0_ESR1.FLTCONF Mask                  */
#define CAN_ESR1_FLTCONF_SHIFT                   (4U)                                                /*!< CAN0_ESR1.FLTCONF Position              */
#define CAN_ESR1_FLTCONF(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< CAN0_ESR1.FLTCONF Field                 */
#define CAN_ESR1_TX_MASK                         (0x40U)                                             /*!< CAN0_ESR1.TX Mask                       */
#define CAN_ESR1_TX_SHIFT                        (6U)                                                /*!< CAN0_ESR1.TX Position                   */
#define CAN_ESR1_TX(x)                           (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< CAN0_ESR1.TX Field                      */
#define CAN_ESR1_IDLE_MASK                       (0x80U)                                             /*!< CAN0_ESR1.IDLE Mask                     */
#define CAN_ESR1_IDLE_SHIFT                      (7U)                                                /*!< CAN0_ESR1.IDLE Position                 */
#define CAN_ESR1_IDLE(x)                         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< CAN0_ESR1.IDLE Field                    */
#define CAN_ESR1_RXWRN_MASK                      (0x100U)                                            /*!< CAN0_ESR1.RXWRN Mask                    */
#define CAN_ESR1_RXWRN_SHIFT                     (8U)                                                /*!< CAN0_ESR1.RXWRN Position                */
#define CAN_ESR1_RXWRN(x)                        (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< CAN0_ESR1.RXWRN Field                   */
#define CAN_ESR1_TXWRN_MASK                      (0x200U)                                            /*!< CAN0_ESR1.TXWRN Mask                    */
#define CAN_ESR1_TXWRN_SHIFT                     (9U)                                                /*!< CAN0_ESR1.TXWRN Position                */
#define CAN_ESR1_TXWRN(x)                        (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< CAN0_ESR1.TXWRN Field                   */
#define CAN_ESR1_STFERR_MASK                     (0x400U)                                            /*!< CAN0_ESR1.STFERR Mask                   */
#define CAN_ESR1_STFERR_SHIFT                    (10U)                                               /*!< CAN0_ESR1.STFERR Position               */
#define CAN_ESR1_STFERR(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< CAN0_ESR1.STFERR Field                  */
#define CAN_ESR1_FRMERR_MASK                     (0x800U)                                            /*!< CAN0_ESR1.FRMERR Mask                   */
#define CAN_ESR1_FRMERR_SHIFT                    (11U)                                               /*!< CAN0_ESR1.FRMERR Position               */
#define CAN_ESR1_FRMERR(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< CAN0_ESR1.FRMERR Field                  */
#define CAN_ESR1_CRCERR_MASK                     (0x1000U)                                           /*!< CAN0_ESR1.CRCERR Mask                   */
#define CAN_ESR1_CRCERR_SHIFT                    (12U)                                               /*!< CAN0_ESR1.CRCERR Position               */
#define CAN_ESR1_CRCERR(x)                       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< CAN0_ESR1.CRCERR Field                  */
#define CAN_ESR1_ACKERR_MASK                     (0x2000U)                                           /*!< CAN0_ESR1.ACKERR Mask                   */
#define CAN_ESR1_ACKERR_SHIFT                    (13U)                                               /*!< CAN0_ESR1.ACKERR Position               */
#define CAN_ESR1_ACKERR(x)                       (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< CAN0_ESR1.ACKERR Field                  */
#define CAN_ESR1_BIT0ERR_MASK                    (0x4000U)                                           /*!< CAN0_ESR1.BIT0ERR Mask                  */
#define CAN_ESR1_BIT0ERR_SHIFT                   (14U)                                               /*!< CAN0_ESR1.BIT0ERR Position              */
#define CAN_ESR1_BIT0ERR(x)                      (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< CAN0_ESR1.BIT0ERR Field                 */
#define CAN_ESR1_BIT1ERR_MASK                    (0x8000U)                                           /*!< CAN0_ESR1.BIT1ERR Mask                  */
#define CAN_ESR1_BIT1ERR_SHIFT                   (15U)                                               /*!< CAN0_ESR1.BIT1ERR Position              */
#define CAN_ESR1_BIT1ERR(x)                      (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< CAN0_ESR1.BIT1ERR Field                 */
#define CAN_ESR1_RWRNINT_MASK                    (0x10000U)                                          /*!< CAN0_ESR1.RWRNINT Mask                  */
#define CAN_ESR1_RWRNINT_SHIFT                   (16U)                                               /*!< CAN0_ESR1.RWRNINT Position              */
#define CAN_ESR1_RWRNINT(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< CAN0_ESR1.RWRNINT Field                 */
#define CAN_ESR1_TWRNINT_MASK                    (0x20000U)                                          /*!< CAN0_ESR1.TWRNINT Mask                  */
#define CAN_ESR1_TWRNINT_SHIFT                   (17U)                                               /*!< CAN0_ESR1.TWRNINT Position              */
#define CAN_ESR1_TWRNINT(x)                      (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< CAN0_ESR1.TWRNINT Field                 */
#define CAN_ESR1_SYNCH_MASK                      (0x40000U)                                          /*!< CAN0_ESR1.SYNCH Mask                    */
#define CAN_ESR1_SYNCH_SHIFT                     (18U)                                               /*!< CAN0_ESR1.SYNCH Position                */
#define CAN_ESR1_SYNCH(x)                        (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< CAN0_ESR1.SYNCH Field                   */
#define CAN_ESR1_BOFFDONEINT_MASK                (0x80000U)                                          /*!< CAN0_ESR1.BOFFDONEINT Mask              */
#define CAN_ESR1_BOFFDONEINT_SHIFT               (19U)                                               /*!< CAN0_ESR1.BOFFDONEINT Position          */
#define CAN_ESR1_BOFFDONEINT(x)                  (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< CAN0_ESR1.BOFFDONEINT Field             */
#define CAN_ESR1_ERROVR_MASK                     (0x200000U)                                         /*!< CAN0_ESR1.ERROVR Mask                   */
#define CAN_ESR1_ERROVR_SHIFT                    (21U)                                               /*!< CAN0_ESR1.ERROVR Position               */
#define CAN_ESR1_ERROVR(x)                       (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< CAN0_ESR1.ERROVR Field                  */
/* ------- IMASK2 Bit Fields                        ------ */
#define CAN_IMASK2_BUFHM_MASK                    (0xFFFFFFFFU)                                       /*!< CAN0_IMASK2.BUFHM Mask                  */
#define CAN_IMASK2_BUFHM_SHIFT                   (0U)                                                /*!< CAN0_IMASK2.BUFHM Position              */
#define CAN_IMASK2_BUFHM(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CAN0_IMASK2.BUFHM Field                 */
/* ------- IMASK1 Bit Fields                        ------ */
#define CAN_IMASK1_BUFLM_MASK                    (0xFFFFFFFFU)                                       /*!< CAN0_IMASK1.BUFLM Mask                  */
#define CAN_IMASK1_BUFLM_SHIFT                   (0U)                                                /*!< CAN0_IMASK1.BUFLM Position              */
#define CAN_IMASK1_BUFLM(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CAN0_IMASK1.BUFLM Field                 */
/* ------- IFLAG2 Bit Fields                        ------ */
#define CAN_IFLAG2_BUFHI_MASK                    (0xFFFFFFFFU)                                       /*!< CAN0_IFLAG2.BUFHI Mask                  */
#define CAN_IFLAG2_BUFHI_SHIFT                   (0U)                                                /*!< CAN0_IFLAG2.BUFHI Position              */
#define CAN_IFLAG2_BUFHI(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CAN0_IFLAG2.BUFHI Field                 */
/* ------- IFLAG1 Bit Fields                        ------ */
#define CAN_IFLAG1_BUF4TO0I_MASK                 (0x1FU)                                             /*!< CAN0_IFLAG1.BUF4TO0I Mask               */
#define CAN_IFLAG1_BUF4TO0I_SHIFT                (0U)                                                /*!< CAN0_IFLAG1.BUF4TO0I Position           */
#define CAN_IFLAG1_BUF4TO0I(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1FUL)          /*!< CAN0_IFLAG1.BUF4TO0I Field              */
#define CAN_IFLAG1_BUF5I_MASK                    (0x20U)                                             /*!< CAN0_IFLAG1.BUF5I Mask                  */
#define CAN_IFLAG1_BUF5I_SHIFT                   (5U)                                                /*!< CAN0_IFLAG1.BUF5I Position              */
#define CAN_IFLAG1_BUF5I(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< CAN0_IFLAG1.BUF5I Field                 */
#define CAN_IFLAG1_BUF6I_MASK                    (0x40U)                                             /*!< CAN0_IFLAG1.BUF6I Mask                  */
#define CAN_IFLAG1_BUF6I_SHIFT                   (6U)                                                /*!< CAN0_IFLAG1.BUF6I Position              */
#define CAN_IFLAG1_BUF6I(x)                      (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< CAN0_IFLAG1.BUF6I Field                 */
#define CAN_IFLAG1_BUF7I_MASK                    (0x80U)                                             /*!< CAN0_IFLAG1.BUF7I Mask                  */
#define CAN_IFLAG1_BUF7I_SHIFT                   (7U)                                                /*!< CAN0_IFLAG1.BUF7I Position              */
#define CAN_IFLAG1_BUF7I(x)                      (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< CAN0_IFLAG1.BUF7I Field                 */
#define CAN_IFLAG1_BUF31TO8I_MASK                (0xFFFFFF00U)                                       /*!< CAN0_IFLAG1.BUF31TO8I Mask              */
#define CAN_IFLAG1_BUF31TO8I_SHIFT               (8U)                                                /*!< CAN0_IFLAG1.BUF31TO8I Position          */
#define CAN_IFLAG1_BUF31TO8I(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0xFFFFFF00UL)    /*!< CAN0_IFLAG1.BUF31TO8I Field             */
/* ------- CTRL2 Bit Fields                         ------ */
#define CAN_CTRL2_EACEN_MASK                     (0x10000U)                                          /*!< CAN0_CTRL2.EACEN Mask                   */
#define CAN_CTRL2_EACEN_SHIFT                    (16U)                                               /*!< CAN0_CTRL2.EACEN Position               */
#define CAN_CTRL2_EACEN(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< CAN0_CTRL2.EACEN Field                  */
#define CAN_CTRL2_RRS_MASK                       (0x20000U)                                          /*!< CAN0_CTRL2.RRS Mask                     */
#define CAN_CTRL2_RRS_SHIFT                      (17U)                                               /*!< CAN0_CTRL2.RRS Position                 */
#define CAN_CTRL2_RRS(x)                         (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< CAN0_CTRL2.RRS Field                    */
#define CAN_CTRL2_MRP_MASK                       (0x40000U)                                          /*!< CAN0_CTRL2.MRP Mask                     */
#define CAN_CTRL2_MRP_SHIFT                      (18U)                                               /*!< CAN0_CTRL2.MRP Position                 */
#define CAN_CTRL2_MRP(x)                         (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< CAN0_CTRL2.MRP Field                    */
#define CAN_CTRL2_TASD_MASK                      (0xF80000U)                                         /*!< CAN0_CTRL2.TASD Mask                    */
#define CAN_CTRL2_TASD_SHIFT                     (19U)                                               /*!< CAN0_CTRL2.TASD Position                */
#define CAN_CTRL2_TASD(x)                        (((uint32_t)(((uint32_t)(x))<<19U))&0xF80000UL)     /*!< CAN0_CTRL2.TASD Field                   */
#define CAN_CTRL2_RFFN_MASK                      (0xF000000U)                                        /*!< CAN0_CTRL2.RFFN Mask                    */
#define CAN_CTRL2_RFFN_SHIFT                     (24U)                                               /*!< CAN0_CTRL2.RFFN Position                */
#define CAN_CTRL2_RFFN(x)                        (((uint32_t)(((uint32_t)(x))<<24U))&0xF000000UL)    /*!< CAN0_CTRL2.RFFN Field                   */
#define CAN_CTRL2_BOFFDONEMSK_MASK               (0x40000000U)                                       /*!< CAN0_CTRL2.BOFFDONEMSK Mask             */
#define CAN_CTRL2_BOFFDONEMSK_SHIFT              (30U)                                               /*!< CAN0_CTRL2.BOFFDONEMSK Position         */
#define CAN_CTRL2_BOFFDONEMSK(x)                 (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< CAN0_CTRL2.BOFFDONEMSK Field            */
/* ------- ESR2 Bit Fields                          ------ */
#define CAN_ESR2_IMB_MASK                        (0x2000U)                                           /*!< CAN0_ESR2.IMB Mask                      */
#define CAN_ESR2_IMB_SHIFT                       (13U)                                               /*!< CAN0_ESR2.IMB Position                  */
#define CAN_ESR2_IMB(x)                          (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< CAN0_ESR2.IMB Field                     */
#define CAN_ESR2_VPS_MASK                        (0x4000U)                                           /*!< CAN0_ESR2.VPS Mask                      */
#define CAN_ESR2_VPS_SHIFT                       (14U)                                               /*!< CAN0_ESR2.VPS Position                  */
#define CAN_ESR2_VPS(x)                          (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< CAN0_ESR2.VPS Field                     */
#define CAN_ESR2_LPTM_MASK                       (0x7F0000U)                                         /*!< CAN0_ESR2.LPTM Mask                     */
#define CAN_ESR2_LPTM_SHIFT                      (16U)                                               /*!< CAN0_ESR2.LPTM Position                 */
#define CAN_ESR2_LPTM(x)                         (((uint32_t)(((uint32_t)(x))<<16U))&0x7F0000UL)     /*!< CAN0_ESR2.LPTM Field                    */
/* ------- CRCR Bit Fields                          ------ */
#define CAN_CRCR_TXCRC_MASK                      (0x7FFFU)                                           /*!< CAN0_CRCR.TXCRC Mask                    */
#define CAN_CRCR_TXCRC_SHIFT                     (0U)                                                /*!< CAN0_CRCR.TXCRC Position                */
#define CAN_CRCR_TXCRC(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x7FFFUL)        /*!< CAN0_CRCR.TXCRC Field                   */
#define CAN_CRCR_MBCRC_MASK                      (0x7F0000U)                                         /*!< CAN0_CRCR.MBCRC Mask                    */
#define CAN_CRCR_MBCRC_SHIFT                     (16U)                                               /*!< CAN0_CRCR.MBCRC Position                */
#define CAN_CRCR_MBCRC(x)                        (((uint32_t)(((uint32_t)(x))<<16U))&0x7F0000UL)     /*!< CAN0_CRCR.MBCRC Field                   */
/* ------- RXFGMASK Bit Fields                      ------ */
#define CAN_RXFGMASK_FGM_MASK                    (0xFFFFFFFFU)                                       /*!< CAN0_RXFGMASK.FGM Mask                  */
#define CAN_RXFGMASK_FGM_SHIFT                   (0U)                                                /*!< CAN0_RXFGMASK.FGM Position              */
#define CAN_RXFGMASK_FGM(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CAN0_RXFGMASK.FGM Field                 */
/* ------- RXFIR Bit Fields                         ------ */
#define CAN_RXFIR_IDHIT_MASK                     (0x1FFU)                                            /*!< CAN0_RXFIR.IDHIT Mask                   */
#define CAN_RXFIR_IDHIT_SHIFT                    (0U)                                                /*!< CAN0_RXFIR.IDHIT Position               */
#define CAN_RXFIR_IDHIT(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1FFUL)         /*!< CAN0_RXFIR.IDHIT Field                  */
/* ------- CBT Bit Fields                           ------ */
#define CAN_CBT_EPSEG2_MASK                      (0x1FU)                                             /*!< CAN0_CBT.EPSEG2 Mask                    */
#define CAN_CBT_EPSEG2_SHIFT                     (0U)                                                /*!< CAN0_CBT.EPSEG2 Position                */
#define CAN_CBT_EPSEG2(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1FUL)          /*!< CAN0_CBT.EPSEG2 Field                   */
#define CAN_CBT_EPSEG1_MASK                      (0x3E0U)                                            /*!< CAN0_CBT.EPSEG1 Mask                    */
#define CAN_CBT_EPSEG1_SHIFT                     (5U)                                                /*!< CAN0_CBT.EPSEG1 Position                */
#define CAN_CBT_EPSEG1(x)                        (((uint32_t)(((uint32_t)(x))<<5U))&0x3E0UL)         /*!< CAN0_CBT.EPSEG1 Field                   */
#define CAN_CBT_EPROPSEG_MASK                    (0xFC00U)                                           /*!< CAN0_CBT.EPROPSEG Mask                  */
#define CAN_CBT_EPROPSEG_SHIFT                   (10U)                                               /*!< CAN0_CBT.EPROPSEG Position              */
#define CAN_CBT_EPROPSEG(x)                      (((uint32_t)(((uint32_t)(x))<<10U))&0xFC00UL)       /*!< CAN0_CBT.EPROPSEG Field                 */
#define CAN_CBT_ERJW_MASK                        (0xF0000U)                                          /*!< CAN0_CBT.ERJW Mask                      */
#define CAN_CBT_ERJW_SHIFT                       (16U)                                               /*!< CAN0_CBT.ERJW Position                  */
#define CAN_CBT_ERJW(x)                          (((uint32_t)(((uint32_t)(x))<<16U))&0xF0000UL)      /*!< CAN0_CBT.ERJW Field                     */
#define CAN_CBT_EPRESDIV_MASK                    (0x7FE00000U)                                       /*!< CAN0_CBT.EPRESDIV Mask                  */
#define CAN_CBT_EPRESDIV_SHIFT                   (21U)                                               /*!< CAN0_CBT.EPRESDIV Position              */
#define CAN_CBT_EPRESDIV(x)                      (((uint32_t)(((uint32_t)(x))<<21U))&0x7FE00000UL)   /*!< CAN0_CBT.EPRESDIV Field                 */
#define CAN_CBT_BTF_MASK                         (0x80000000U)                                       /*!< CAN0_CBT.BTF Mask                       */
#define CAN_CBT_BTF_SHIFT                        (31U)                                               /*!< CAN0_CBT.BTF Position                   */
#define CAN_CBT_BTF(x)                           (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< CAN0_CBT.BTF Field                      */
/* ------- CS Bit Fields                            ------ */
#define CAN_CS_TIME_STAMP_MASK                   (0xFFFFU)                                           /*!< CAN0_CS.TIME_STAMP Mask                 */
#define CAN_CS_TIME_STAMP_SHIFT                  (0U)                                                /*!< CAN0_CS.TIME_STAMP Position             */
#define CAN_CS_TIME_STAMP(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< CAN0_CS.TIME_STAMP Field                */
#define CAN_CS_DLC_MASK                          (0xF0000U)                                          /*!< CAN0_CS.DLC Mask                        */
#define CAN_CS_DLC_SHIFT                         (16U)                                               /*!< CAN0_CS.DLC Position                    */
#define CAN_CS_DLC(x)                            (((uint32_t)(((uint32_t)(x))<<16U))&0xF0000UL)      /*!< CAN0_CS.DLC Field                       */
#define CAN_CS_RTR_MASK                          (0x100000U)                                         /*!< CAN0_CS.RTR Mask                        */
#define CAN_CS_RTR_SHIFT                         (20U)                                               /*!< CAN0_CS.RTR Position                    */
#define CAN_CS_RTR(x)                            (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< CAN0_CS.RTR Field                       */
#define CAN_CS_IDE_MASK                          (0x200000U)                                         /*!< CAN0_CS.IDE Mask                        */
#define CAN_CS_IDE_SHIFT                         (21U)                                               /*!< CAN0_CS.IDE Position                    */
#define CAN_CS_IDE(x)                            (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< CAN0_CS.IDE Field                       */
#define CAN_CS_SRR_MASK                          (0x400000U)                                         /*!< CAN0_CS.SRR Mask                        */
#define CAN_CS_SRR_SHIFT                         (22U)                                               /*!< CAN0_CS.SRR Position                    */
#define CAN_CS_SRR(x)                            (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< CAN0_CS.SRR Field                       */
#define CAN_CS_CODE_MASK                         (0xF000000U)                                        /*!< CAN0_CS.CODE Mask                       */
#define CAN_CS_CODE_SHIFT                        (24U)                                               /*!< CAN0_CS.CODE Position                   */
#define CAN_CS_CODE(x)                           (((uint32_t)(((uint32_t)(x))<<24U))&0xF000000UL)    /*!< CAN0_CS.CODE Field                      */
#define CAN_CS_ESI_MASK                          (0x20000000U)                                       /*!< CAN0_CS.ESI Mask                        */
#define CAN_CS_ESI_SHIFT                         (29U)                                               /*!< CAN0_CS.ESI Position                    */
#define CAN_CS_ESI(x)                            (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< CAN0_CS.ESI Field                       */
#define CAN_CS_BRS_MASK                          (0x40000000U)                                       /*!< CAN0_CS.BRS Mask                        */
#define CAN_CS_BRS_SHIFT                         (30U)                                               /*!< CAN0_CS.BRS Position                    */
#define CAN_CS_BRS(x)                            (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< CAN0_CS.BRS Field                       */
#define CAN_CS_EDL_MASK                          (0x80000000U)                                       /*!< CAN0_CS.EDL Mask                        */
#define CAN_CS_EDL_SHIFT                         (31U)                                               /*!< CAN0_CS.EDL Position                    */
#define CAN_CS_EDL(x)                            (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< CAN0_CS.EDL Field                       */
/* ------- ID Bit Fields                            ------ */
#define CAN_ID_EXT_MASK                          (0x3FFFFU)                                          /*!< CAN0_ID.EXT Mask                        */
#define CAN_ID_EXT_SHIFT                         (0U)                                                /*!< CAN0_ID.EXT Position                    */
#define CAN_ID_EXT(x)                            (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFFFUL)       /*!< CAN0_ID.EXT Field                       */
#define CAN_ID_STD_MASK                          (0x1FFC0000U)                                       /*!< CAN0_ID.STD Mask                        */
#define CAN_ID_STD_SHIFT                         (18U)                                               /*!< CAN0_ID.STD Position                    */
#define CAN_ID_STD(x)                            (((uint32_t)(((uint32_t)(x))<<18U))&0x1FFC0000UL)   /*!< CAN0_ID.STD Field                       */
#define CAN_ID_PRIO_MASK                         (0xE0000000U)                                       /*!< CAN0_ID.PRIO Mask                       */
#define CAN_ID_PRIO_SHIFT                        (29U)                                               /*!< CAN0_ID.PRIO Position                   */
#define CAN_ID_PRIO(x)                           (((uint32_t)(((uint32_t)(x))<<29U))&0xE0000000UL)   /*!< CAN0_ID.PRIO Field                      */
/* ------- WORD0 Bit Fields                         ------ */
#define CAN_WORD0_DATA_BYTE_3_MASK               (0xFFU)                                             /*!< CAN0_WORD0.DATA_BYTE_3 Mask             */
#define CAN_WORD0_DATA_BYTE_3_SHIFT              (0U)                                                /*!< CAN0_WORD0.DATA_BYTE_3 Position         */
#define CAN_WORD0_DATA_BYTE_3(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< CAN0_WORD0.DATA_BYTE_3 Field            */
#define CAN_WORD0_DATA_BYTE_2_MASK               (0xFF00U)                                           /*!< CAN0_WORD0.DATA_BYTE_2 Mask             */
#define CAN_WORD0_DATA_BYTE_2_SHIFT              (8U)                                                /*!< CAN0_WORD0.DATA_BYTE_2 Position         */
#define CAN_WORD0_DATA_BYTE_2(x)                 (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< CAN0_WORD0.DATA_BYTE_2 Field            */
#define CAN_WORD0_DATA_BYTE_1_MASK               (0xFF0000U)                                         /*!< CAN0_WORD0.DATA_BYTE_1 Mask             */
#define CAN_WORD0_DATA_BYTE_1_SHIFT              (16U)                                               /*!< CAN0_WORD0.DATA_BYTE_1 Position         */
#define CAN_WORD0_DATA_BYTE_1(x)                 (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< CAN0_WORD0.DATA_BYTE_1 Field            */
#define CAN_WORD0_DATA_BYTE_0_MASK               (0xFF000000U)                                       /*!< CAN0_WORD0.DATA_BYTE_0 Mask             */
#define CAN_WORD0_DATA_BYTE_0_SHIFT              (24U)                                               /*!< CAN0_WORD0.DATA_BYTE_0 Position         */
#define CAN_WORD0_DATA_BYTE_0(x)                 (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< CAN0_WORD0.DATA_BYTE_0 Field            */
/* ------- WORD1 Bit Fields                         ------ */
#define CAN_WORD1_DATA_BYTE_7_MASK               (0xFFU)                                             /*!< CAN0_WORD1.DATA_BYTE_7 Mask             */
#define CAN_WORD1_DATA_BYTE_7_SHIFT              (0U)                                                /*!< CAN0_WORD1.DATA_BYTE_7 Position         */
#define CAN_WORD1_DATA_BYTE_7(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< CAN0_WORD1.DATA_BYTE_7 Field            */
#define CAN_WORD1_DATA_BYTE_6_MASK               (0xFF00U)                                           /*!< CAN0_WORD1.DATA_BYTE_6 Mask             */
#define CAN_WORD1_DATA_BYTE_6_SHIFT              (8U)                                                /*!< CAN0_WORD1.DATA_BYTE_6 Position         */
#define CAN_WORD1_DATA_BYTE_6(x)                 (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< CAN0_WORD1.DATA_BYTE_6 Field            */
#define CAN_WORD1_DATA_BYTE_5_MASK               (0xFF0000U)                                         /*!< CAN0_WORD1.DATA_BYTE_5 Mask             */
#define CAN_WORD1_DATA_BYTE_5_SHIFT              (16U)                                               /*!< CAN0_WORD1.DATA_BYTE_5 Position         */
#define CAN_WORD1_DATA_BYTE_5(x)                 (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< CAN0_WORD1.DATA_BYTE_5 Field            */
#define CAN_WORD1_DATA_BYTE_4_MASK               (0xFF000000U)                                       /*!< CAN0_WORD1.DATA_BYTE_4 Mask             */
#define CAN_WORD1_DATA_BYTE_4_SHIFT              (24U)                                               /*!< CAN0_WORD1.DATA_BYTE_4 Position         */
#define CAN_WORD1_DATA_BYTE_4(x)                 (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< CAN0_WORD1.DATA_BYTE_4 Field            */
/* ------- RXIMR Bit Fields                         ------ */
#define CAN_RXIMR_MI_MASK                        (0xFFFFFFFFU)                                       /*!< CAN0_RXIMR.MI Mask                      */
#define CAN_RXIMR_MI_SHIFT                       (0U)                                                /*!< CAN0_RXIMR.MI Position                  */
#define CAN_RXIMR_MI(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< CAN0_RXIMR.MI Field                     */
/**
 * @} */ /* End group CAN_Register_Masks_GROUP 
 */

/* CAN0 - Peripheral instance base addresses */
#define CAN0_BasePtr                   0x40024000UL //!< Peripheral base address
#define CAN0                           ((CAN_Type *) CAN0_BasePtr) //!< Freescale base pointer
#define CAN0_BASE_PTR                  (CAN0) //!< Freescale style base pointer
/**
 * @} */ /* End group CAN_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CAN_Peripheral_access_layer_GROUP CAN Peripheral Access Layer
* @brief C Struct for CAN
* @{
*/

/* ================================================================================ */
/* ================           CAN1 (derived from CAN0)             ================ */
/* ================================================================================ */

/**
 * @brief Flex Controller Area Network module
 */

/* CAN1 - Peripheral instance base addresses */
#define CAN1_BasePtr                   0x40025000UL //!< Peripheral base address
#define CAN1                           ((CAN_Type *) CAN1_BasePtr) //!< Freescale base pointer
#define CAN1_BASE_PTR                  (CAN1) //!< Freescale style base pointer
/**
 * @} */ /* End group CAN_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP0 (file:CMP0_MKV)                 ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
 */
/**
* @addtogroup CMP_structs_GROUP CMP struct
* @brief Struct for CMP
* @{
*/
typedef struct {                                /*       CMP0 Structure                                               */
   __IO uint8_t   CR0;                          /**< 0000: CMP Control Register 0                                       */
   __IO uint8_t   CR1;                          /**< 0001: CMP Control Register 1                                       */
   __IO uint8_t   FPR;                          /**< 0002: CMP Filter Period Register                                   */
   __IO uint8_t   SCR;                          /**< 0003: CMP Status and Control Register                              */
   __IO uint8_t   DACCR;                        /**< 0004: DAC Control Register                                         */
   __IO uint8_t   MUXCR;                        /**< 0005: MUX Control Register                                         */
} CMP_Type;

/**
 * @} */ /* End group CMP_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CMP0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CMP_Register_Masks_GROUP CMP Register Masks
* @brief Register Masks for CMP
* @{
*/
/* ------- CR0 Bit Fields                           ------ */
#define CMP_CR0_HYSTCTR_MASK                     (0x3U)                                              /*!< CMP0_CR0.HYSTCTR Mask                   */
#define CMP_CR0_HYSTCTR_SHIFT                    (0U)                                                /*!< CMP0_CR0.HYSTCTR Position               */
#define CMP_CR0_HYSTCTR(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< CMP0_CR0.HYSTCTR Field                  */
#define CMP_CR0_FILTER_CNT_MASK                  (0x70U)                                             /*!< CMP0_CR0.FILTER_CNT Mask                */
#define CMP_CR0_FILTER_CNT_SHIFT                 (4U)                                                /*!< CMP0_CR0.FILTER_CNT Position            */
#define CMP_CR0_FILTER_CNT(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x70UL)            /*!< CMP0_CR0.FILTER_CNT Field               */
/* ------- CR1 Bit Fields                           ------ */
#define CMP_CR1_EN_MASK                          (0x1U)                                              /*!< CMP0_CR1.EN Mask                        */
#define CMP_CR1_EN_SHIFT                         (0U)                                                /*!< CMP0_CR1.EN Position                    */
#define CMP_CR1_EN(x)                            (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< CMP0_CR1.EN Field                       */
#define CMP_CR1_OPE_MASK                         (0x2U)                                              /*!< CMP0_CR1.OPE Mask                       */
#define CMP_CR1_OPE_SHIFT                        (1U)                                                /*!< CMP0_CR1.OPE Position                   */
#define CMP_CR1_OPE(x)                           (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< CMP0_CR1.OPE Field                      */
#define CMP_CR1_COS_MASK                         (0x4U)                                              /*!< CMP0_CR1.COS Mask                       */
#define CMP_CR1_COS_SHIFT                        (2U)                                                /*!< CMP0_CR1.COS Position                   */
#define CMP_CR1_COS(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< CMP0_CR1.COS Field                      */
#define CMP_CR1_INV_MASK                         (0x8U)                                              /*!< CMP0_CR1.INV Mask                       */
#define CMP_CR1_INV_SHIFT                        (3U)                                                /*!< CMP0_CR1.INV Position                   */
#define CMP_CR1_INV(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< CMP0_CR1.INV Field                      */
#define CMP_CR1_PMODE_MASK                       (0x10U)                                             /*!< CMP0_CR1.PMODE Mask                     */
#define CMP_CR1_PMODE_SHIFT                      (4U)                                                /*!< CMP0_CR1.PMODE Position                 */
#define CMP_CR1_PMODE(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< CMP0_CR1.PMODE Field                    */
#define CMP_CR1_TRIGM_MASK                       (0x20U)                                             /*!< CMP0_CR1.TRIGM Mask                     */
#define CMP_CR1_TRIGM_SHIFT                      (5U)                                                /*!< CMP0_CR1.TRIGM Position                 */
#define CMP_CR1_TRIGM(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< CMP0_CR1.TRIGM Field                    */
#define CMP_CR1_WE_MASK                          (0x40U)                                             /*!< CMP0_CR1.WE Mask                        */
#define CMP_CR1_WE_SHIFT                         (6U)                                                /*!< CMP0_CR1.WE Position                    */
#define CMP_CR1_WE(x)                            (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< CMP0_CR1.WE Field                       */
#define CMP_CR1_SE_MASK                          (0x80U)                                             /*!< CMP0_CR1.SE Mask                        */
#define CMP_CR1_SE_SHIFT                         (7U)                                                /*!< CMP0_CR1.SE Position                    */
#define CMP_CR1_SE(x)                            (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< CMP0_CR1.SE Field                       */
/* ------- FPR Bit Fields                           ------ */
#define CMP_FPR_FILT_PER_MASK                    (0xFFU)                                             /*!< CMP0_FPR.FILT_PER Mask                  */
#define CMP_FPR_FILT_PER_SHIFT                   (0U)                                                /*!< CMP0_FPR.FILT_PER Position              */
#define CMP_FPR_FILT_PER(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CMP0_FPR.FILT_PER Field                 */
/* ------- SCR Bit Fields                           ------ */
#define CMP_SCR_COUT_MASK                        (0x1U)                                              /*!< CMP0_SCR.COUT Mask                      */
#define CMP_SCR_COUT_SHIFT                       (0U)                                                /*!< CMP0_SCR.COUT Position                  */
#define CMP_SCR_COUT(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< CMP0_SCR.COUT Field                     */
#define CMP_SCR_CFF_MASK                         (0x2U)                                              /*!< CMP0_SCR.CFF Mask                       */
#define CMP_SCR_CFF_SHIFT                        (1U)                                                /*!< CMP0_SCR.CFF Position                   */
#define CMP_SCR_CFF(x)                           (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< CMP0_SCR.CFF Field                      */
#define CMP_SCR_CFR_MASK                         (0x4U)                                              /*!< CMP0_SCR.CFR Mask                       */
#define CMP_SCR_CFR_SHIFT                        (2U)                                                /*!< CMP0_SCR.CFR Position                   */
#define CMP_SCR_CFR(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< CMP0_SCR.CFR Field                      */
#define CMP_SCR_IEF_MASK                         (0x8U)                                              /*!< CMP0_SCR.IEF Mask                       */
#define CMP_SCR_IEF_SHIFT                        (3U)                                                /*!< CMP0_SCR.IEF Position                   */
#define CMP_SCR_IEF(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< CMP0_SCR.IEF Field                      */
#define CMP_SCR_IER_MASK                         (0x10U)                                             /*!< CMP0_SCR.IER Mask                       */
#define CMP_SCR_IER_SHIFT                        (4U)                                                /*!< CMP0_SCR.IER Position                   */
#define CMP_SCR_IER(x)                           (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< CMP0_SCR.IER Field                      */
#define CMP_SCR_DMAEN_MASK                       (0x40U)                                             /*!< CMP0_SCR.DMAEN Mask                     */
#define CMP_SCR_DMAEN_SHIFT                      (6U)                                                /*!< CMP0_SCR.DMAEN Position                 */
#define CMP_SCR_DMAEN(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< CMP0_SCR.DMAEN Field                    */
/* ------- DACCR Bit Fields                         ------ */
#define CMP_DACCR_VOSEL_MASK                     (0x3FU)                                             /*!< CMP0_DACCR.VOSEL Mask                   */
#define CMP_DACCR_VOSEL_SHIFT                    (0U)                                                /*!< CMP0_DACCR.VOSEL Position               */
#define CMP_DACCR_VOSEL(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3FUL)            /*!< CMP0_DACCR.VOSEL Field                  */
#define CMP_DACCR_VRSEL_MASK                     (0x40U)                                             /*!< CMP0_DACCR.VRSEL Mask                   */
#define CMP_DACCR_VRSEL_SHIFT                    (6U)                                                /*!< CMP0_DACCR.VRSEL Position               */
#define CMP_DACCR_VRSEL(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< CMP0_DACCR.VRSEL Field                  */
#define CMP_DACCR_DACEN_MASK                     (0x80U)                                             /*!< CMP0_DACCR.DACEN Mask                   */
#define CMP_DACCR_DACEN_SHIFT                    (7U)                                                /*!< CMP0_DACCR.DACEN Position               */
#define CMP_DACCR_DACEN(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< CMP0_DACCR.DACEN Field                  */
/* ------- MUXCR Bit Fields                         ------ */
#define CMP_MUXCR_MSEL_MASK                      (0x7U)                                              /*!< CMP0_MUXCR.MSEL Mask                    */
#define CMP_MUXCR_MSEL_SHIFT                     (0U)                                                /*!< CMP0_MUXCR.MSEL Position                */
#define CMP_MUXCR_MSEL(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< CMP0_MUXCR.MSEL Field                   */
#define CMP_MUXCR_PSEL_MASK                      (0x38U)                                             /*!< CMP0_MUXCR.PSEL Mask                    */
#define CMP_MUXCR_PSEL_SHIFT                     (3U)                                                /*!< CMP0_MUXCR.PSEL Position                */
#define CMP_MUXCR_PSEL(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x38UL)            /*!< CMP0_MUXCR.PSEL Field                   */
/**
 * @} */ /* End group CMP_Register_Masks_GROUP 
 */

/* CMP0 - Peripheral instance base addresses */
#define CMP0_BasePtr                   0x40073000UL //!< Peripheral base address
#define CMP0                           ((CMP_Type *) CMP0_BasePtr) //!< Freescale base pointer
#define CMP0_BASE_PTR                  (CMP0) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP1 (derived from CMP0)             ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
 */

/* CMP1 - Peripheral instance base addresses */
#define CMP1_BasePtr                   0x40073008UL //!< Peripheral base address
#define CMP1                           ((CMP_Type *) CMP1_BasePtr) //!< Freescale base pointer
#define CMP1_BASE_PTR                  (CMP1) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP2 (derived from CMP0)             ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
 */

/* CMP2 - Peripheral instance base addresses */
#define CMP2_BasePtr                   0x40073010UL //!< Peripheral base address
#define CMP2                           ((CMP_Type *) CMP2_BasePtr) //!< Freescale base pointer
#define CMP2_BASE_PTR                  (CMP2) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CMP_Peripheral_access_layer_GROUP CMP Peripheral Access Layer
* @brief C Struct for CMP
* @{
*/

/* ================================================================================ */
/* ================           CMP3 (derived from CMP0)             ================ */
/* ================================================================================ */

/**
 * @brief Comparator, Voltage Ref, D-to-A Converter and Analog Mux
 */

/* CMP3 - Peripheral instance base addresses */
#define CMP3_BasePtr                   0x40073018UL //!< Peripheral base address
#define CMP3                           ((CMP_Type *) CMP3_BasePtr) //!< Freescale base pointer
#define CMP3_BASE_PTR                  (CMP3) //!< Freescale style base pointer
/**
 * @} */ /* End group CMP_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup CRC_Peripheral_access_layer_GROUP CRC Peripheral Access Layer
* @brief C Struct for CRC
* @{
*/

/* ================================================================================ */
/* ================           CRC0 (file:CRC0_0x40032000)          ================ */
/* ================================================================================ */

/**
 * @brief Cyclic Redundancy Check
 */
/**
* @addtogroup CRC_structs_GROUP CRC struct
* @brief Struct for CRC
* @{
*/
typedef struct {                                /*       CRC0 Structure                                               */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  DATA;                      /**< 0000: Data register                                                */
      struct {                                  /**< 0000: (size=0004)                                                  */
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  DATAL;               /**< 0000: DATAL register                                               */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   DATALL;           /**< 0000: DATALL register                                              */
               __IO uint8_t   DATALU;           /**< 0001: DATALU register                                              */
            };
         };
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  DATAH;               /**< 0002: DATAH register                                               */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   DATAHL;           /**< 0002: DATAHL register                                              */
               __IO uint8_t   DATAHU;           /**< 0003: DATAHU register                                              */
            };
         };
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  GPOLY;                     /**< 0004: Polynomial register                                          */
      struct {                                  /**< 0000: (size=0004)                                                  */
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  GPOLYL;              /**< 0004: GPOLYL register                                              */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   GPOLYLL;          /**< 0004: GPOLYLL register                                             */
               __IO uint8_t   GPOLYLU;          /**< 0005: GPOLYLU register                                             */
            };
         };
         union {                                /**< 0000: (size=0002)                                                  */
            __IO uint16_t  GPOLYH;              /**< 0006: GPOLYH register                                              */
            struct {                            /**< 0000: (size=0002)                                                  */
               __IO uint8_t   GPOLYHL;          /**< 0006: GPOLYHL register                                             */
               __IO uint8_t   GPOLYHU;          /**< 0007: GPOLYHU register                                             */
            };
         };
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  CTRL;                      /**< 0008: Control register                                             */
      struct {                                  /**< 0000: (size=0004)                                                  */
              uint8_t   RESERVED_6[3];         
         __IO uint8_t   CTRLHU;                 /**< 000B: Control register (byte access)                               */
      };
   };
} CRC_Type;

/**
 * @} */ /* End group CRC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'CRC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup CRC_Register_Masks_GROUP CRC Register Masks
* @brief Register Masks for CRC
* @{
*/
/* ------- DATA Bit Fields                          ------ */
#define CRC_DATA_LL_MASK                         (0xFFU)                                             /*!< CRC0_DATA.LL Mask                       */
#define CRC_DATA_LL_SHIFT                        (0U)                                                /*!< CRC0_DATA.LL Position                   */
#define CRC_DATA_LL(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< CRC0_DATA.LL Field                      */
#define CRC_DATA_LU_MASK                         (0xFF00U)                                           /*!< CRC0_DATA.LU Mask                       */
#define CRC_DATA_LU_SHIFT                        (8U)                                                /*!< CRC0_DATA.LU Position                   */
#define CRC_DATA_LU(x)                           (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< CRC0_DATA.LU Field                      */
#define CRC_DATA_HL_MASK                         (0xFF0000U)                                         /*!< CRC0_DATA.HL Mask                       */
#define CRC_DATA_HL_SHIFT                        (16U)                                               /*!< CRC0_DATA.HL Position                   */
#define CRC_DATA_HL(x)                           (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< CRC0_DATA.HL Field                      */
#define CRC_DATA_HU_MASK                         (0xFF000000U)                                       /*!< CRC0_DATA.HU Mask                       */
#define CRC_DATA_HU_SHIFT                        (24U)                                               /*!< CRC0_DATA.HU Position                   */
#define CRC_DATA_HU(x)                           (((uint32_t)(((uint32_t)(x))<<24U))&0xFF000000UL)   /*!< CRC0_DATA.HU Field                      */
/* ------- DATAL Bit Fields                         ------ */
#define CRC_DATAL_DATAL_MASK                     (0xFFFFU)                                           /*!< CRC0_DATAL.DATAL Mask                   */
#define CRC_DATAL_DATAL_SHIFT                    (0U)                                                /*!< CRC0_DATAL.DATAL Position               */
#define CRC_DATAL_DATAL(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< CRC0_DATAL.DATAL Field                  */
/* ------- DATALL Bit Fields                        ------ */
#define CRC_DATALL_DATALL_MASK                   (0xFFU)                                             /*!< CRC0_DATALL.DATALL Mask                 */
#define CRC_DATALL_DATALL_SHIFT                  (0U)                                                /*!< CRC0_DATALL.DATALL Position             */
#define CRC_DATALL_DATALL(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_DATALL.DATALL Field                */
/* ------- DATALU Bit Fields                        ------ */
#define CRC_DATALU_DATALU_MASK                   (0xFFU)                                             /*!< CRC0_DATALU.DATALU Mask                 */
#define CRC_DATALU_DATALU_SHIFT                  (0U)                                                /*!< CRC0_DATALU.DATALU Position             */
#define CRC_DATALU_DATALU(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_DATALU.DATALU Field                */
/* ------- DATAH Bit Fields                         ------ */
#define CRC_DATAH_DATAH_MASK                     (0xFFFFU)                                           /*!< CRC0_DATAH.DATAH Mask                   */
#define CRC_DATAH_DATAH_SHIFT                    (0U)                                                /*!< CRC0_DATAH.DATAH Position               */
#define CRC_DATAH_DATAH(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< CRC0_DATAH.DATAH Field                  */
/* ------- DATAHL Bit Fields                        ------ */
#define CRC_DATAHL_DATAHL_MASK                   (0xFFU)                                             /*!< CRC0_DATAHL.DATAHL Mask                 */
#define CRC_DATAHL_DATAHL_SHIFT                  (0U)                                                /*!< CRC0_DATAHL.DATAHL Position             */
#define CRC_DATAHL_DATAHL(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_DATAHL.DATAHL Field                */
/* ------- DATAHU Bit Fields                        ------ */
#define CRC_DATAHU_DATAHU_MASK                   (0xFFU)                                             /*!< CRC0_DATAHU.DATAHU Mask                 */
#define CRC_DATAHU_DATAHU_SHIFT                  (0U)                                                /*!< CRC0_DATAHU.DATAHU Position             */
#define CRC_DATAHU_DATAHU(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_DATAHU.DATAHU Field                */
/* ------- GPOLY Bit Fields                         ------ */
#define CRC_GPOLY_LOW_MASK                       (0xFFFFU)                                           /*!< CRC0_GPOLY.LOW Mask                     */
#define CRC_GPOLY_LOW_SHIFT                      (0U)                                                /*!< CRC0_GPOLY.LOW Position                 */
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< CRC0_GPOLY.LOW Field                    */
#define CRC_GPOLY_HIGH_MASK                      (0xFFFF0000U)                                       /*!< CRC0_GPOLY.HIGH Mask                    */
#define CRC_GPOLY_HIGH_SHIFT                     (16U)                                               /*!< CRC0_GPOLY.HIGH Position                */
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< CRC0_GPOLY.HIGH Field                   */
/* ------- GPOLYL Bit Fields                        ------ */
#define CRC_GPOLYL_GPOLYL_MASK                   (0xFFFFU)                                           /*!< CRC0_GPOLYL.GPOLYL Mask                 */
#define CRC_GPOLYL_GPOLYL_SHIFT                  (0U)                                                /*!< CRC0_GPOLYL.GPOLYL Position             */
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< CRC0_GPOLYL.GPOLYL Field                */
/* ------- GPOLYLL Bit Fields                       ------ */
#define CRC_GPOLYLL_GPOLYLL_MASK                 (0xFFU)                                             /*!< CRC0_GPOLYLL.GPOLYLL Mask               */
#define CRC_GPOLYLL_GPOLYLL_SHIFT                (0U)                                                /*!< CRC0_GPOLYLL.GPOLYLL Position           */
#define CRC_GPOLYLL_GPOLYLL(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_GPOLYLL.GPOLYLL Field              */
/* ------- GPOLYLU Bit Fields                       ------ */
#define CRC_GPOLYLU_GPOLYLU_MASK                 (0xFFU)                                             /*!< CRC0_GPOLYLU.GPOLYLU Mask               */
#define CRC_GPOLYLU_GPOLYLU_SHIFT                (0U)                                                /*!< CRC0_GPOLYLU.GPOLYLU Position           */
#define CRC_GPOLYLU_GPOLYLU(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_GPOLYLU.GPOLYLU Field              */
/* ------- GPOLYH Bit Fields                        ------ */
#define CRC_GPOLYH_GPOLYH_MASK                   (0xFFFFU)                                           /*!< CRC0_GPOLYH.GPOLYH Mask                 */
#define CRC_GPOLYH_GPOLYH_SHIFT                  (0U)                                                /*!< CRC0_GPOLYH.GPOLYH Position             */
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< CRC0_GPOLYH.GPOLYH Field                */
/* ------- GPOLYHL Bit Fields                       ------ */
#define CRC_GPOLYHL_GPOLYHL_MASK                 (0xFFU)                                             /*!< CRC0_GPOLYHL.GPOLYHL Mask               */
#define CRC_GPOLYHL_GPOLYHL_SHIFT                (0U)                                                /*!< CRC0_GPOLYHL.GPOLYHL Position           */
#define CRC_GPOLYHL_GPOLYHL(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_GPOLYHL.GPOLYHL Field              */
/* ------- GPOLYHU Bit Fields                       ------ */
#define CRC_GPOLYHU_GPOLYHU_MASK                 (0xFFU)                                             /*!< CRC0_GPOLYHU.GPOLYHU Mask               */
#define CRC_GPOLYHU_GPOLYHU_SHIFT                (0U)                                                /*!< CRC0_GPOLYHU.GPOLYHU Position           */
#define CRC_GPOLYHU_GPOLYHU(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< CRC0_GPOLYHU.GPOLYHU Field              */
/* ------- CTRL Bit Fields                          ------ */
#define CRC_CTRL_TCRC_MASK                       (0x1000000U)                                        /*!< CRC0_CTRL.TCRC Mask                     */
#define CRC_CTRL_TCRC_SHIFT                      (24U)                                               /*!< CRC0_CTRL.TCRC Position                 */
#define CRC_CTRL_TCRC(x)                         (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< CRC0_CTRL.TCRC Field                    */
#define CRC_CTRL_WAS_MASK                        (0x2000000U)                                        /*!< CRC0_CTRL.WAS Mask                      */
#define CRC_CTRL_WAS_SHIFT                       (25U)                                               /*!< CRC0_CTRL.WAS Position                  */
#define CRC_CTRL_WAS(x)                          (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< CRC0_CTRL.WAS Field                     */
#define CRC_CTRL_FXOR_MASK                       (0x4000000U)                                        /*!< CRC0_CTRL.FXOR Mask                     */
#define CRC_CTRL_FXOR_SHIFT                      (26U)                                               /*!< CRC0_CTRL.FXOR Position                 */
#define CRC_CTRL_FXOR(x)                         (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< CRC0_CTRL.FXOR Field                    */
#define CRC_CTRL_TOTR_MASK                       (0x30000000U)                                       /*!< CRC0_CTRL.TOTR Mask                     */
#define CRC_CTRL_TOTR_SHIFT                      (28U)                                               /*!< CRC0_CTRL.TOTR Position                 */
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x))<<28U))&0x30000000UL)   /*!< CRC0_CTRL.TOTR Field                    */
#define CRC_CTRL_TOT_MASK                        (0xC0000000U)                                       /*!< CRC0_CTRL.TOT Mask                      */
#define CRC_CTRL_TOT_SHIFT                       (30U)                                               /*!< CRC0_CTRL.TOT Position                  */
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x))<<30U))&0xC0000000UL)   /*!< CRC0_CTRL.TOT Field                     */
/* ------- CTRLHU Bit Fields                        ------ */
#define CRC_CTRLHU_TCRC_MASK                     (0x1U)                                              /*!< CRC0_CTRLHU.TCRC Mask                   */
#define CRC_CTRLHU_TCRC_SHIFT                    (0U)                                                /*!< CRC0_CTRLHU.TCRC Position               */
#define CRC_CTRLHU_TCRC(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< CRC0_CTRLHU.TCRC Field                  */
#define CRC_CTRLHU_WAS_MASK                      (0x2U)                                              /*!< CRC0_CTRLHU.WAS Mask                    */
#define CRC_CTRLHU_WAS_SHIFT                     (1U)                                                /*!< CRC0_CTRLHU.WAS Position                */
#define CRC_CTRLHU_WAS(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< CRC0_CTRLHU.WAS Field                   */
#define CRC_CTRLHU_FXOR_MASK                     (0x4U)                                              /*!< CRC0_CTRLHU.FXOR Mask                   */
#define CRC_CTRLHU_FXOR_SHIFT                    (2U)                                                /*!< CRC0_CTRLHU.FXOR Position               */
#define CRC_CTRLHU_FXOR(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< CRC0_CTRLHU.FXOR Field                  */
#define CRC_CTRLHU_TOTR_MASK                     (0x30U)                                             /*!< CRC0_CTRLHU.TOTR Mask                   */
#define CRC_CTRLHU_TOTR_SHIFT                    (4U)                                                /*!< CRC0_CTRLHU.TOTR Position               */
#define CRC_CTRLHU_TOTR(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< CRC0_CTRLHU.TOTR Field                  */
#define CRC_CTRLHU_TOT_MASK                      (0xC0U)                                             /*!< CRC0_CTRLHU.TOT Mask                    */
#define CRC_CTRLHU_TOT_SHIFT                     (6U)                                                /*!< CRC0_CTRLHU.TOT Position                */
#define CRC_CTRLHU_TOT(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< CRC0_CTRLHU.TOT Field                   */
/**
 * @} */ /* End group CRC_Register_Masks_GROUP 
 */

/* CRC0 - Peripheral instance base addresses */
#define CRC0_BasePtr                   0x40032000UL //!< Peripheral base address
#define CRC0                           ((CRC_Type *) CRC0_BasePtr) //!< Freescale base pointer
#define CRC0_BASE_PTR                  (CRC0) //!< Freescale style base pointer
/**
 * @} */ /* End group CRC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMA0_Peripheral_access_layer_GROUP DMA0 Peripheral Access Layer
* @brief C Struct for DMA0
* @{
*/

/* ================================================================================ */
/* ================           DMA0 (file:DMA0_16CH_EARS16)         ================ */
/* ================================================================================ */

/**
 * @brief Enhanced direct memory access controller
 */
/**
* @addtogroup DMA0_structs_GROUP DMA0 struct
* @brief Struct for DMA0
* @{
*/
typedef struct {                                /*       DMA0 Structure                                               */
   __IO uint32_t  CR;                           /**< 0000: Control Register                                             */
   __I  uint32_t  ES;                           /**< 0004: Error Status Register                                        */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  ERQ;                          /**< 000C: Enable Request Register                                      */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  EEI;                          /**< 0014: Enable Error Interrupt Register                              */
   __O  uint8_t   CEEI;                         /**< 0018: Clear Enable Error Interrupt Register                        */
   __O  uint8_t   SEEI;                         /**< 0019: Set Enable Error Interrupt Register                          */
   __O  uint8_t   CERQ;                         /**< 001A: Clear Enable Request Register                                */
   __O  uint8_t   SERQ;                         /**< 001B: Set Enable Request Register                                  */
   __O  uint8_t   CDNE;                         /**< 001C: Clear DONE Status Bit Register                               */
   __O  uint8_t   SSRT;                         /**< 001D: Set START Bit Register                                       */
   __O  uint8_t   CERR;                         /**< 001E: Clear Error Register                                         */
   __O  uint8_t   CINT;                         /**< 001F: Clear Interrupt Request Register                             */
        uint8_t   RESERVED_2[4];               
   __IO uint32_t  INT;                          /**< 0024: Interrupt Request Register                                   */
        uint8_t   RESERVED_3[4];               
   __IO uint32_t  ERR;                          /**< 002C: Error Register                                               */
        uint8_t   RESERVED_4[4];               
   __I  uint32_t  HRS;                          /**< 0034: Hardware Request Status Register                             */
        uint8_t   RESERVED_5[12];              
   __IO uint32_t  EARS;                         /**< 0044: Enable Asynchronous Request in Stop Register                 */
        uint8_t   RESERVED_6[184];             
   __IO uint8_t   DCHPRI3;                      /**< 0100: Channel 3 Priority Register                                  */
   __IO uint8_t   DCHPRI2;                      /**< 0101: Channel 2 Priority Register                                  */
   __IO uint8_t   DCHPRI1;                      /**< 0102: Channel 1 Priority Register                                  */
   __IO uint8_t   DCHPRI0;                      /**< 0103: Channel 0 Priority Register                                  */
   __IO uint8_t   DCHPRI7;                      /**< 0104: Channel 7 Priority Register                                  */
   __IO uint8_t   DCHPRI6;                      /**< 0105: Channel 6 Priority Register                                  */
   __IO uint8_t   DCHPRI5;                      /**< 0106: Channel 5 Priority Register                                  */
   __IO uint8_t   DCHPRI4;                      /**< 0107: Channel 4 Priority Register                                  */
   __IO uint8_t   DCHPRI11;                     /**< 0108: Channel 11 Priority Register                                 */
   __IO uint8_t   DCHPRI10;                     /**< 0109: Channel 10 Priority Register                                 */
   __IO uint8_t   DCHPRI9;                      /**< 010A: Channel 9 Priority Register                                  */
   __IO uint8_t   DCHPRI8;                      /**< 010B: Channel 8 Priority Register                                  */
   __IO uint8_t   DCHPRI15;                     /**< 010C: Channel 15 Priority Register                                 */
   __IO uint8_t   DCHPRI14;                     /**< 010D: Channel 14 Priority Register                                 */
   __IO uint8_t   DCHPRI13;                     /**< 010E: Channel 13 Priority Register                                 */
   __IO uint8_t   DCHPRI12;                     /**< 010F: Channel 12 Priority Register                                 */
        uint8_t   RESERVED_7[3824];            
   struct {
      __IO uint32_t  SADDR;                     /**< 1000: Source Address                                               */
      __IO uint16_t  SOFF;                      /**< 1004: Signed Source Address Offset                                 */
      __IO uint16_t  ATTR;                      /**< 1006: Transfer Attributes                                          */
      union {                                   /**< 1000: (size=0004)                                                  */
         __IO uint32_t  NBYTES_MLNO;            /**< 1008: Minor Byte Count (Minor Loop Disabled)                       */
         __IO uint32_t  NBYTES_MLOFFNO;         /**< 1008: Signed Minor Loop Offset (Minor Loop Enabled and Offset Disabled) */
         __IO uint32_t  NBYTES_MLOFFYES;        /**< 1008: Signed Minor Loop Offset (Minor Loop and Offset Enabled)     */
      };
      __IO uint32_t  SLAST;                     /**< 100C: Last Source Address Adjustment                               */
      __IO uint32_t  DADDR;                     /**< 1010: Destination Address                                          */
      __IO uint16_t  DOFF;                      /**< 1014: Signed Destination Address Offset                            */
      union {                                   /**< 1000: (size=0002)                                                  */
         __IO uint16_t  CITER_ELINKNO;          /**< 1016: Current Minor Loop Link, Major Loop Count (Channel Linking Disabled) */
         __IO uint16_t  CITER_ELINKYES;         /**< 1016: Current Minor Loop Link, Major Loop Count (Channel Linking Enabled) */
      };
      __IO uint32_t  DLASTSGA;                  /**< 1018: Last Destination Address Adjustment/Scatter Gather Address   */
      __IO uint16_t  CSR;                       /**< 101C: Control and Status                                           */
      union {                                   /**< 1000: (size=0002)                                                  */
         __IO uint16_t  BITER_ELINKNO;          /**< 101E: Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled) */
         __IO uint16_t  BITER_ELINKYES;         /**< 101E: Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled) */
      };
   } TCD[16];                                   /**< 1000: (cluster: size=0x0200, 512)                                  */
} DMA_Type;

/**
 * @} */ /* End group DMA0_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMA0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMA0_Register_Masks_GROUP DMA0 Register Masks
* @brief Register Masks for DMA0
* @{
*/
/* ------- CR Bit Fields                            ------ */
#define DMA_CR_EDBG_MASK                         (0x2U)                                              /*!< DMA0_CR.EDBG Mask                       */
#define DMA_CR_EDBG_SHIFT                        (1U)                                                /*!< DMA0_CR.EDBG Position                   */
#define DMA_CR_EDBG(x)                           (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA0_CR.EDBG Field                      */
#define DMA_CR_ERCA_MASK                         (0x4U)                                              /*!< DMA0_CR.ERCA Mask                       */
#define DMA_CR_ERCA_SHIFT                        (2U)                                                /*!< DMA0_CR.ERCA Position                   */
#define DMA_CR_ERCA(x)                           (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA0_CR.ERCA Field                      */
#define DMA_CR_HOE_MASK                          (0x10U)                                             /*!< DMA0_CR.HOE Mask                        */
#define DMA_CR_HOE_SHIFT                         (4U)                                                /*!< DMA0_CR.HOE Position                    */
#define DMA_CR_HOE(x)                            (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA0_CR.HOE Field                       */
#define DMA_CR_HALT_MASK                         (0x20U)                                             /*!< DMA0_CR.HALT Mask                       */
#define DMA_CR_HALT_SHIFT                        (5U)                                                /*!< DMA0_CR.HALT Position                   */
#define DMA_CR_HALT(x)                           (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA0_CR.HALT Field                      */
#define DMA_CR_CLM_MASK                          (0x40U)                                             /*!< DMA0_CR.CLM Mask                        */
#define DMA_CR_CLM_SHIFT                         (6U)                                                /*!< DMA0_CR.CLM Position                    */
#define DMA_CR_CLM(x)                            (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA0_CR.CLM Field                       */
#define DMA_CR_EMLM_MASK                         (0x80U)                                             /*!< DMA0_CR.EMLM Mask                       */
#define DMA_CR_EMLM_SHIFT                        (7U)                                                /*!< DMA0_CR.EMLM Position                   */
#define DMA_CR_EMLM(x)                           (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA0_CR.EMLM Field                      */
#define DMA_CR_ECX_MASK                          (0x10000U)                                          /*!< DMA0_CR.ECX Mask                        */
#define DMA_CR_ECX_SHIFT                         (16U)                                               /*!< DMA0_CR.ECX Position                    */
#define DMA_CR_ECX(x)                            (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< DMA0_CR.ECX Field                       */
#define DMA_CR_CX_MASK                           (0x20000U)                                          /*!< DMA0_CR.CX Mask                         */
#define DMA_CR_CX_SHIFT                          (17U)                                               /*!< DMA0_CR.CX Position                     */
#define DMA_CR_CX(x)                             (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< DMA0_CR.CX Field                        */
/* ------- ES Bit Fields                            ------ */
#define DMA_ES_DBE_MASK                          (0x1U)                                              /*!< DMA0_ES.DBE Mask                        */
#define DMA_ES_DBE_SHIFT                         (0U)                                                /*!< DMA0_ES.DBE Position                    */
#define DMA_ES_DBE(x)                            (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< DMA0_ES.DBE Field                       */
#define DMA_ES_SBE_MASK                          (0x2U)                                              /*!< DMA0_ES.SBE Mask                        */
#define DMA_ES_SBE_SHIFT                         (1U)                                                /*!< DMA0_ES.SBE Position                    */
#define DMA_ES_SBE(x)                            (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA0_ES.SBE Field                       */
#define DMA_ES_SGE_MASK                          (0x4U)                                              /*!< DMA0_ES.SGE Mask                        */
#define DMA_ES_SGE_SHIFT                         (2U)                                                /*!< DMA0_ES.SGE Position                    */
#define DMA_ES_SGE(x)                            (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA0_ES.SGE Field                       */
#define DMA_ES_NCE_MASK                          (0x8U)                                              /*!< DMA0_ES.NCE Mask                        */
#define DMA_ES_NCE_SHIFT                         (3U)                                                /*!< DMA0_ES.NCE Position                    */
#define DMA_ES_NCE(x)                            (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< DMA0_ES.NCE Field                       */
#define DMA_ES_DOE_MASK                          (0x10U)                                             /*!< DMA0_ES.DOE Mask                        */
#define DMA_ES_DOE_SHIFT                         (4U)                                                /*!< DMA0_ES.DOE Position                    */
#define DMA_ES_DOE(x)                            (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA0_ES.DOE Field                       */
#define DMA_ES_DAE_MASK                          (0x20U)                                             /*!< DMA0_ES.DAE Mask                        */
#define DMA_ES_DAE_SHIFT                         (5U)                                                /*!< DMA0_ES.DAE Position                    */
#define DMA_ES_DAE(x)                            (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA0_ES.DAE Field                       */
#define DMA_ES_SOE_MASK                          (0x40U)                                             /*!< DMA0_ES.SOE Mask                        */
#define DMA_ES_SOE_SHIFT                         (6U)                                                /*!< DMA0_ES.SOE Position                    */
#define DMA_ES_SOE(x)                            (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA0_ES.SOE Field                       */
#define DMA_ES_SAE_MASK                          (0x80U)                                             /*!< DMA0_ES.SAE Mask                        */
#define DMA_ES_SAE_SHIFT                         (7U)                                                /*!< DMA0_ES.SAE Position                    */
#define DMA_ES_SAE(x)                            (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA0_ES.SAE Field                       */
#define DMA_ES_ERRCHN_MASK                       (0xF00U)                                            /*!< DMA0_ES.ERRCHN Mask                     */
#define DMA_ES_ERRCHN_SHIFT                      (8U)                                                /*!< DMA0_ES.ERRCHN Position                 */
#define DMA_ES_ERRCHN(x)                         (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< DMA0_ES.ERRCHN Field                    */
#define DMA_ES_CPE_MASK                          (0x4000U)                                           /*!< DMA0_ES.CPE Mask                        */
#define DMA_ES_CPE_SHIFT                         (14U)                                               /*!< DMA0_ES.CPE Position                    */
#define DMA_ES_CPE(x)                            (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< DMA0_ES.CPE Field                       */
#define DMA_ES_ECX_MASK                          (0x10000U)                                          /*!< DMA0_ES.ECX Mask                        */
#define DMA_ES_ECX_SHIFT                         (16U)                                               /*!< DMA0_ES.ECX Position                    */
#define DMA_ES_ECX(x)                            (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< DMA0_ES.ECX Field                       */
#define DMA_ES_VLD_MASK                          (0x80000000U)                                       /*!< DMA0_ES.VLD Mask                        */
#define DMA_ES_VLD_SHIFT                         (31U)                                               /*!< DMA0_ES.VLD Position                    */
#define DMA_ES_VLD(x)                            (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< DMA0_ES.VLD Field                       */
/* ------- ERQ Bit Fields                           ------ */
#define DMA_ERQ_ERQ0_MASK                        (0x1U)                                              /*!< DMA0_ERQ.ERQ0 Mask                      */
#define DMA_ERQ_ERQ0_SHIFT                       (0U)                                                /*!< DMA0_ERQ.ERQ0 Position                  */
#define DMA_ERQ_ERQ0(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< DMA0_ERQ.ERQ0 Field                     */
#define DMA_ERQ_ERQ1_MASK                        (0x2U)                                              /*!< DMA0_ERQ.ERQ1 Mask                      */
#define DMA_ERQ_ERQ1_SHIFT                       (1U)                                                /*!< DMA0_ERQ.ERQ1 Position                  */
#define DMA_ERQ_ERQ1(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA0_ERQ.ERQ1 Field                     */
#define DMA_ERQ_ERQ2_MASK                        (0x4U)                                              /*!< DMA0_ERQ.ERQ2 Mask                      */
#define DMA_ERQ_ERQ2_SHIFT                       (2U)                                                /*!< DMA0_ERQ.ERQ2 Position                  */
#define DMA_ERQ_ERQ2(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA0_ERQ.ERQ2 Field                     */
#define DMA_ERQ_ERQ3_MASK                        (0x8U)                                              /*!< DMA0_ERQ.ERQ3 Mask                      */
#define DMA_ERQ_ERQ3_SHIFT                       (3U)                                                /*!< DMA0_ERQ.ERQ3 Position                  */
#define DMA_ERQ_ERQ3(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< DMA0_ERQ.ERQ3 Field                     */
#define DMA_ERQ_ERQ4_MASK                        (0x10U)                                             /*!< DMA0_ERQ.ERQ4 Mask                      */
#define DMA_ERQ_ERQ4_SHIFT                       (4U)                                                /*!< DMA0_ERQ.ERQ4 Position                  */
#define DMA_ERQ_ERQ4(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA0_ERQ.ERQ4 Field                     */
#define DMA_ERQ_ERQ5_MASK                        (0x20U)                                             /*!< DMA0_ERQ.ERQ5 Mask                      */
#define DMA_ERQ_ERQ5_SHIFT                       (5U)                                                /*!< DMA0_ERQ.ERQ5 Position                  */
#define DMA_ERQ_ERQ5(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA0_ERQ.ERQ5 Field                     */
#define DMA_ERQ_ERQ6_MASK                        (0x40U)                                             /*!< DMA0_ERQ.ERQ6 Mask                      */
#define DMA_ERQ_ERQ6_SHIFT                       (6U)                                                /*!< DMA0_ERQ.ERQ6 Position                  */
#define DMA_ERQ_ERQ6(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA0_ERQ.ERQ6 Field                     */
#define DMA_ERQ_ERQ7_MASK                        (0x80U)                                             /*!< DMA0_ERQ.ERQ7 Mask                      */
#define DMA_ERQ_ERQ7_SHIFT                       (7U)                                                /*!< DMA0_ERQ.ERQ7 Position                  */
#define DMA_ERQ_ERQ7(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA0_ERQ.ERQ7 Field                     */
#define DMA_ERQ_ERQ8_MASK                        (0x100U)                                            /*!< DMA0_ERQ.ERQ8 Mask                      */
#define DMA_ERQ_ERQ8_SHIFT                       (8U)                                                /*!< DMA0_ERQ.ERQ8 Position                  */
#define DMA_ERQ_ERQ8(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< DMA0_ERQ.ERQ8 Field                     */
#define DMA_ERQ_ERQ9_MASK                        (0x200U)                                            /*!< DMA0_ERQ.ERQ9 Mask                      */
#define DMA_ERQ_ERQ9_SHIFT                       (9U)                                                /*!< DMA0_ERQ.ERQ9 Position                  */
#define DMA_ERQ_ERQ9(x)                          (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< DMA0_ERQ.ERQ9 Field                     */
#define DMA_ERQ_ERQ10_MASK                       (0x400U)                                            /*!< DMA0_ERQ.ERQ10 Mask                     */
#define DMA_ERQ_ERQ10_SHIFT                      (10U)                                               /*!< DMA0_ERQ.ERQ10 Position                 */
#define DMA_ERQ_ERQ10(x)                         (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< DMA0_ERQ.ERQ10 Field                    */
#define DMA_ERQ_ERQ11_MASK                       (0x800U)                                            /*!< DMA0_ERQ.ERQ11 Mask                     */
#define DMA_ERQ_ERQ11_SHIFT                      (11U)                                               /*!< DMA0_ERQ.ERQ11 Position                 */
#define DMA_ERQ_ERQ11(x)                         (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< DMA0_ERQ.ERQ11 Field                    */
#define DMA_ERQ_ERQ12_MASK                       (0x1000U)                                           /*!< DMA0_ERQ.ERQ12 Mask                     */
#define DMA_ERQ_ERQ12_SHIFT                      (12U)                                               /*!< DMA0_ERQ.ERQ12 Position                 */
#define DMA_ERQ_ERQ12(x)                         (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< DMA0_ERQ.ERQ12 Field                    */
#define DMA_ERQ_ERQ13_MASK                       (0x2000U)                                           /*!< DMA0_ERQ.ERQ13 Mask                     */
#define DMA_ERQ_ERQ13_SHIFT                      (13U)                                               /*!< DMA0_ERQ.ERQ13 Position                 */
#define DMA_ERQ_ERQ13(x)                         (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< DMA0_ERQ.ERQ13 Field                    */
#define DMA_ERQ_ERQ14_MASK                       (0x4000U)                                           /*!< DMA0_ERQ.ERQ14 Mask                     */
#define DMA_ERQ_ERQ14_SHIFT                      (14U)                                               /*!< DMA0_ERQ.ERQ14 Position                 */
#define DMA_ERQ_ERQ14(x)                         (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< DMA0_ERQ.ERQ14 Field                    */
#define DMA_ERQ_ERQ15_MASK                       (0x8000U)                                           /*!< DMA0_ERQ.ERQ15 Mask                     */
#define DMA_ERQ_ERQ15_SHIFT                      (15U)                                               /*!< DMA0_ERQ.ERQ15 Position                 */
#define DMA_ERQ_ERQ15(x)                         (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< DMA0_ERQ.ERQ15 Field                    */
/* ------- EEI Bit Fields                           ------ */
#define DMA_EEI_EEI0_MASK                        (0x1U)                                              /*!< DMA0_EEI.EEI0 Mask                      */
#define DMA_EEI_EEI0_SHIFT                       (0U)                                                /*!< DMA0_EEI.EEI0 Position                  */
#define DMA_EEI_EEI0(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< DMA0_EEI.EEI0 Field                     */
#define DMA_EEI_EEI1_MASK                        (0x2U)                                              /*!< DMA0_EEI.EEI1 Mask                      */
#define DMA_EEI_EEI1_SHIFT                       (1U)                                                /*!< DMA0_EEI.EEI1 Position                  */
#define DMA_EEI_EEI1(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA0_EEI.EEI1 Field                     */
#define DMA_EEI_EEI2_MASK                        (0x4U)                                              /*!< DMA0_EEI.EEI2 Mask                      */
#define DMA_EEI_EEI2_SHIFT                       (2U)                                                /*!< DMA0_EEI.EEI2 Position                  */
#define DMA_EEI_EEI2(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA0_EEI.EEI2 Field                     */
#define DMA_EEI_EEI3_MASK                        (0x8U)                                              /*!< DMA0_EEI.EEI3 Mask                      */
#define DMA_EEI_EEI3_SHIFT                       (3U)                                                /*!< DMA0_EEI.EEI3 Position                  */
#define DMA_EEI_EEI3(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< DMA0_EEI.EEI3 Field                     */
#define DMA_EEI_EEI4_MASK                        (0x10U)                                             /*!< DMA0_EEI.EEI4 Mask                      */
#define DMA_EEI_EEI4_SHIFT                       (4U)                                                /*!< DMA0_EEI.EEI4 Position                  */
#define DMA_EEI_EEI4(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA0_EEI.EEI4 Field                     */
#define DMA_EEI_EEI5_MASK                        (0x20U)                                             /*!< DMA0_EEI.EEI5 Mask                      */
#define DMA_EEI_EEI5_SHIFT                       (5U)                                                /*!< DMA0_EEI.EEI5 Position                  */
#define DMA_EEI_EEI5(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA0_EEI.EEI5 Field                     */
#define DMA_EEI_EEI6_MASK                        (0x40U)                                             /*!< DMA0_EEI.EEI6 Mask                      */
#define DMA_EEI_EEI6_SHIFT                       (6U)                                                /*!< DMA0_EEI.EEI6 Position                  */
#define DMA_EEI_EEI6(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA0_EEI.EEI6 Field                     */
#define DMA_EEI_EEI7_MASK                        (0x80U)                                             /*!< DMA0_EEI.EEI7 Mask                      */
#define DMA_EEI_EEI7_SHIFT                       (7U)                                                /*!< DMA0_EEI.EEI7 Position                  */
#define DMA_EEI_EEI7(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA0_EEI.EEI7 Field                     */
#define DMA_EEI_EEI8_MASK                        (0x100U)                                            /*!< DMA0_EEI.EEI8 Mask                      */
#define DMA_EEI_EEI8_SHIFT                       (8U)                                                /*!< DMA0_EEI.EEI8 Position                  */
#define DMA_EEI_EEI8(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< DMA0_EEI.EEI8 Field                     */
#define DMA_EEI_EEI9_MASK                        (0x200U)                                            /*!< DMA0_EEI.EEI9 Mask                      */
#define DMA_EEI_EEI9_SHIFT                       (9U)                                                /*!< DMA0_EEI.EEI9 Position                  */
#define DMA_EEI_EEI9(x)                          (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< DMA0_EEI.EEI9 Field                     */
#define DMA_EEI_EEI10_MASK                       (0x400U)                                            /*!< DMA0_EEI.EEI10 Mask                     */
#define DMA_EEI_EEI10_SHIFT                      (10U)                                               /*!< DMA0_EEI.EEI10 Position                 */
#define DMA_EEI_EEI10(x)                         (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< DMA0_EEI.EEI10 Field                    */
#define DMA_EEI_EEI11_MASK                       (0x800U)                                            /*!< DMA0_EEI.EEI11 Mask                     */
#define DMA_EEI_EEI11_SHIFT                      (11U)                                               /*!< DMA0_EEI.EEI11 Position                 */
#define DMA_EEI_EEI11(x)                         (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< DMA0_EEI.EEI11 Field                    */
#define DMA_EEI_EEI12_MASK                       (0x1000U)                                           /*!< DMA0_EEI.EEI12 Mask                     */
#define DMA_EEI_EEI12_SHIFT                      (12U)                                               /*!< DMA0_EEI.EEI12 Position                 */
#define DMA_EEI_EEI12(x)                         (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< DMA0_EEI.EEI12 Field                    */
#define DMA_EEI_EEI13_MASK                       (0x2000U)                                           /*!< DMA0_EEI.EEI13 Mask                     */
#define DMA_EEI_EEI13_SHIFT                      (13U)                                               /*!< DMA0_EEI.EEI13 Position                 */
#define DMA_EEI_EEI13(x)                         (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< DMA0_EEI.EEI13 Field                    */
#define DMA_EEI_EEI14_MASK                       (0x4000U)                                           /*!< DMA0_EEI.EEI14 Mask                     */
#define DMA_EEI_EEI14_SHIFT                      (14U)                                               /*!< DMA0_EEI.EEI14 Position                 */
#define DMA_EEI_EEI14(x)                         (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< DMA0_EEI.EEI14 Field                    */
#define DMA_EEI_EEI15_MASK                       (0x8000U)                                           /*!< DMA0_EEI.EEI15 Mask                     */
#define DMA_EEI_EEI15_SHIFT                      (15U)                                               /*!< DMA0_EEI.EEI15 Position                 */
#define DMA_EEI_EEI15(x)                         (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< DMA0_EEI.EEI15 Field                    */
/* ------- CEEI Bit Fields                          ------ */
#define DMA_CEEI_CEEI_MASK                       (0xFU)                                              /*!< DMA0_CEEI.CEEI Mask                     */
#define DMA_CEEI_CEEI_SHIFT                      (0U)                                                /*!< DMA0_CEEI.CEEI Position                 */
#define DMA_CEEI_CEEI(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< DMA0_CEEI.CEEI Field                    */
#define DMA_CEEI_CAEE_MASK                       (0x40U)                                             /*!< DMA0_CEEI.CAEE Mask                     */
#define DMA_CEEI_CAEE_SHIFT                      (6U)                                                /*!< DMA0_CEEI.CAEE Position                 */
#define DMA_CEEI_CAEE(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA0_CEEI.CAEE Field                    */
#define DMA_CEEI_NOP_MASK                        (0x80U)                                             /*!< DMA0_CEEI.NOP Mask                      */
#define DMA_CEEI_NOP_SHIFT                       (7U)                                                /*!< DMA0_CEEI.NOP Position                  */
#define DMA_CEEI_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA0_CEEI.NOP Field                     */
/* ------- SEEI Bit Fields                          ------ */
#define DMA_SEEI_SEEI_MASK                       (0xFU)                                              /*!< DMA0_SEEI.SEEI Mask                     */
#define DMA_SEEI_SEEI_SHIFT                      (0U)                                                /*!< DMA0_SEEI.SEEI Position                 */
#define DMA_SEEI_SEEI(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< DMA0_SEEI.SEEI Field                    */
#define DMA_SEEI_SAEE_MASK                       (0x40U)                                             /*!< DMA0_SEEI.SAEE Mask                     */
#define DMA_SEEI_SAEE_SHIFT                      (6U)                                                /*!< DMA0_SEEI.SAEE Position                 */
#define DMA_SEEI_SAEE(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA0_SEEI.SAEE Field                    */
#define DMA_SEEI_NOP_MASK                        (0x80U)                                             /*!< DMA0_SEEI.NOP Mask                      */
#define DMA_SEEI_NOP_SHIFT                       (7U)                                                /*!< DMA0_SEEI.NOP Position                  */
#define DMA_SEEI_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA0_SEEI.NOP Field                     */
/* ------- CERQ Bit Fields                          ------ */
#define DMA_CERQ_CERQ_MASK                       (0xFU)                                              /*!< DMA0_CERQ.CERQ Mask                     */
#define DMA_CERQ_CERQ_SHIFT                      (0U)                                                /*!< DMA0_CERQ.CERQ Position                 */
#define DMA_CERQ_CERQ(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< DMA0_CERQ.CERQ Field                    */
#define DMA_CERQ_CAER_MASK                       (0x40U)                                             /*!< DMA0_CERQ.CAER Mask                     */
#define DMA_CERQ_CAER_SHIFT                      (6U)                                                /*!< DMA0_CERQ.CAER Position                 */
#define DMA_CERQ_CAER(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA0_CERQ.CAER Field                    */
#define DMA_CERQ_NOP_MASK                        (0x80U)                                             /*!< DMA0_CERQ.NOP Mask                      */
#define DMA_CERQ_NOP_SHIFT                       (7U)                                                /*!< DMA0_CERQ.NOP Position                  */
#define DMA_CERQ_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA0_CERQ.NOP Field                     */
/* ------- SERQ Bit Fields                          ------ */
#define DMA_SERQ_SERQ_MASK                       (0xFU)                                              /*!< DMA0_SERQ.SERQ Mask                     */
#define DMA_SERQ_SERQ_SHIFT                      (0U)                                                /*!< DMA0_SERQ.SERQ Position                 */
#define DMA_SERQ_SERQ(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< DMA0_SERQ.SERQ Field                    */
#define DMA_SERQ_SAER_MASK                       (0x40U)                                             /*!< DMA0_SERQ.SAER Mask                     */
#define DMA_SERQ_SAER_SHIFT                      (6U)                                                /*!< DMA0_SERQ.SAER Position                 */
#define DMA_SERQ_SAER(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA0_SERQ.SAER Field                    */
#define DMA_SERQ_NOP_MASK                        (0x80U)                                             /*!< DMA0_SERQ.NOP Mask                      */
#define DMA_SERQ_NOP_SHIFT                       (7U)                                                /*!< DMA0_SERQ.NOP Position                  */
#define DMA_SERQ_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA0_SERQ.NOP Field                     */
/* ------- CDNE Bit Fields                          ------ */
#define DMA_CDNE_CDNE_MASK                       (0xFU)                                              /*!< DMA0_CDNE.CDNE Mask                     */
#define DMA_CDNE_CDNE_SHIFT                      (0U)                                                /*!< DMA0_CDNE.CDNE Position                 */
#define DMA_CDNE_CDNE(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< DMA0_CDNE.CDNE Field                    */
#define DMA_CDNE_CADN_MASK                       (0x40U)                                             /*!< DMA0_CDNE.CADN Mask                     */
#define DMA_CDNE_CADN_SHIFT                      (6U)                                                /*!< DMA0_CDNE.CADN Position                 */
#define DMA_CDNE_CADN(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA0_CDNE.CADN Field                    */
#define DMA_CDNE_NOP_MASK                        (0x80U)                                             /*!< DMA0_CDNE.NOP Mask                      */
#define DMA_CDNE_NOP_SHIFT                       (7U)                                                /*!< DMA0_CDNE.NOP Position                  */
#define DMA_CDNE_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA0_CDNE.NOP Field                     */
/* ------- SSRT Bit Fields                          ------ */
#define DMA_SSRT_SSRT_MASK                       (0xFU)                                              /*!< DMA0_SSRT.SSRT Mask                     */
#define DMA_SSRT_SSRT_SHIFT                      (0U)                                                /*!< DMA0_SSRT.SSRT Position                 */
#define DMA_SSRT_SSRT(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< DMA0_SSRT.SSRT Field                    */
#define DMA_SSRT_SAST_MASK                       (0x40U)                                             /*!< DMA0_SSRT.SAST Mask                     */
#define DMA_SSRT_SAST_SHIFT                      (6U)                                                /*!< DMA0_SSRT.SAST Position                 */
#define DMA_SSRT_SAST(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA0_SSRT.SAST Field                    */
#define DMA_SSRT_NOP_MASK                        (0x80U)                                             /*!< DMA0_SSRT.NOP Mask                      */
#define DMA_SSRT_NOP_SHIFT                       (7U)                                                /*!< DMA0_SSRT.NOP Position                  */
#define DMA_SSRT_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA0_SSRT.NOP Field                     */
/* ------- CERR Bit Fields                          ------ */
#define DMA_CERR_CERR_MASK                       (0xFU)                                              /*!< DMA0_CERR.CERR Mask                     */
#define DMA_CERR_CERR_SHIFT                      (0U)                                                /*!< DMA0_CERR.CERR Position                 */
#define DMA_CERR_CERR(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< DMA0_CERR.CERR Field                    */
#define DMA_CERR_CAEI_MASK                       (0x40U)                                             /*!< DMA0_CERR.CAEI Mask                     */
#define DMA_CERR_CAEI_SHIFT                      (6U)                                                /*!< DMA0_CERR.CAEI Position                 */
#define DMA_CERR_CAEI(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA0_CERR.CAEI Field                    */
#define DMA_CERR_NOP_MASK                        (0x80U)                                             /*!< DMA0_CERR.NOP Mask                      */
#define DMA_CERR_NOP_SHIFT                       (7U)                                                /*!< DMA0_CERR.NOP Position                  */
#define DMA_CERR_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA0_CERR.NOP Field                     */
/* ------- CINT Bit Fields                          ------ */
#define DMA_CINT_CINT_MASK                       (0xFU)                                              /*!< DMA0_CINT.CINT Mask                     */
#define DMA_CINT_CINT_SHIFT                      (0U)                                                /*!< DMA0_CINT.CINT Position                 */
#define DMA_CINT_CINT(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< DMA0_CINT.CINT Field                    */
#define DMA_CINT_CAIR_MASK                       (0x40U)                                             /*!< DMA0_CINT.CAIR Mask                     */
#define DMA_CINT_CAIR_SHIFT                      (6U)                                                /*!< DMA0_CINT.CAIR Position                 */
#define DMA_CINT_CAIR(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA0_CINT.CAIR Field                    */
#define DMA_CINT_NOP_MASK                        (0x80U)                                             /*!< DMA0_CINT.NOP Mask                      */
#define DMA_CINT_NOP_SHIFT                       (7U)                                                /*!< DMA0_CINT.NOP Position                  */
#define DMA_CINT_NOP(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA0_CINT.NOP Field                     */
/* ------- INT Bit Fields                           ------ */
#define DMA_INT_INT0_MASK                        (0x1U)                                              /*!< DMA0_INT.INT0 Mask                      */
#define DMA_INT_INT0_SHIFT                       (0U)                                                /*!< DMA0_INT.INT0 Position                  */
#define DMA_INT_INT0(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< DMA0_INT.INT0 Field                     */
#define DMA_INT_INT1_MASK                        (0x2U)                                              /*!< DMA0_INT.INT1 Mask                      */
#define DMA_INT_INT1_SHIFT                       (1U)                                                /*!< DMA0_INT.INT1 Position                  */
#define DMA_INT_INT1(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA0_INT.INT1 Field                     */
#define DMA_INT_INT2_MASK                        (0x4U)                                              /*!< DMA0_INT.INT2 Mask                      */
#define DMA_INT_INT2_SHIFT                       (2U)                                                /*!< DMA0_INT.INT2 Position                  */
#define DMA_INT_INT2(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA0_INT.INT2 Field                     */
#define DMA_INT_INT3_MASK                        (0x8U)                                              /*!< DMA0_INT.INT3 Mask                      */
#define DMA_INT_INT3_SHIFT                       (3U)                                                /*!< DMA0_INT.INT3 Position                  */
#define DMA_INT_INT3(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< DMA0_INT.INT3 Field                     */
#define DMA_INT_INT4_MASK                        (0x10U)                                             /*!< DMA0_INT.INT4 Mask                      */
#define DMA_INT_INT4_SHIFT                       (4U)                                                /*!< DMA0_INT.INT4 Position                  */
#define DMA_INT_INT4(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA0_INT.INT4 Field                     */
#define DMA_INT_INT5_MASK                        (0x20U)                                             /*!< DMA0_INT.INT5 Mask                      */
#define DMA_INT_INT5_SHIFT                       (5U)                                                /*!< DMA0_INT.INT5 Position                  */
#define DMA_INT_INT5(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA0_INT.INT5 Field                     */
#define DMA_INT_INT6_MASK                        (0x40U)                                             /*!< DMA0_INT.INT6 Mask                      */
#define DMA_INT_INT6_SHIFT                       (6U)                                                /*!< DMA0_INT.INT6 Position                  */
#define DMA_INT_INT6(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA0_INT.INT6 Field                     */
#define DMA_INT_INT7_MASK                        (0x80U)                                             /*!< DMA0_INT.INT7 Mask                      */
#define DMA_INT_INT7_SHIFT                       (7U)                                                /*!< DMA0_INT.INT7 Position                  */
#define DMA_INT_INT7(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA0_INT.INT7 Field                     */
#define DMA_INT_INT8_MASK                        (0x100U)                                            /*!< DMA0_INT.INT8 Mask                      */
#define DMA_INT_INT8_SHIFT                       (8U)                                                /*!< DMA0_INT.INT8 Position                  */
#define DMA_INT_INT8(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< DMA0_INT.INT8 Field                     */
#define DMA_INT_INT9_MASK                        (0x200U)                                            /*!< DMA0_INT.INT9 Mask                      */
#define DMA_INT_INT9_SHIFT                       (9U)                                                /*!< DMA0_INT.INT9 Position                  */
#define DMA_INT_INT9(x)                          (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< DMA0_INT.INT9 Field                     */
#define DMA_INT_INT10_MASK                       (0x400U)                                            /*!< DMA0_INT.INT10 Mask                     */
#define DMA_INT_INT10_SHIFT                      (10U)                                               /*!< DMA0_INT.INT10 Position                 */
#define DMA_INT_INT10(x)                         (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< DMA0_INT.INT10 Field                    */
#define DMA_INT_INT11_MASK                       (0x800U)                                            /*!< DMA0_INT.INT11 Mask                     */
#define DMA_INT_INT11_SHIFT                      (11U)                                               /*!< DMA0_INT.INT11 Position                 */
#define DMA_INT_INT11(x)                         (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< DMA0_INT.INT11 Field                    */
#define DMA_INT_INT12_MASK                       (0x1000U)                                           /*!< DMA0_INT.INT12 Mask                     */
#define DMA_INT_INT12_SHIFT                      (12U)                                               /*!< DMA0_INT.INT12 Position                 */
#define DMA_INT_INT12(x)                         (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< DMA0_INT.INT12 Field                    */
#define DMA_INT_INT13_MASK                       (0x2000U)                                           /*!< DMA0_INT.INT13 Mask                     */
#define DMA_INT_INT13_SHIFT                      (13U)                                               /*!< DMA0_INT.INT13 Position                 */
#define DMA_INT_INT13(x)                         (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< DMA0_INT.INT13 Field                    */
#define DMA_INT_INT14_MASK                       (0x4000U)                                           /*!< DMA0_INT.INT14 Mask                     */
#define DMA_INT_INT14_SHIFT                      (14U)                                               /*!< DMA0_INT.INT14 Position                 */
#define DMA_INT_INT14(x)                         (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< DMA0_INT.INT14 Field                    */
#define DMA_INT_INT15_MASK                       (0x8000U)                                           /*!< DMA0_INT.INT15 Mask                     */
#define DMA_INT_INT15_SHIFT                      (15U)                                               /*!< DMA0_INT.INT15 Position                 */
#define DMA_INT_INT15(x)                         (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< DMA0_INT.INT15 Field                    */
/* ------- ERR Bit Fields                           ------ */
#define DMA_ERR_ERR0_MASK                        (0x1U)                                              /*!< DMA0_ERR.ERR0 Mask                      */
#define DMA_ERR_ERR0_SHIFT                       (0U)                                                /*!< DMA0_ERR.ERR0 Position                  */
#define DMA_ERR_ERR0(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< DMA0_ERR.ERR0 Field                     */
#define DMA_ERR_ERR1_MASK                        (0x2U)                                              /*!< DMA0_ERR.ERR1 Mask                      */
#define DMA_ERR_ERR1_SHIFT                       (1U)                                                /*!< DMA0_ERR.ERR1 Position                  */
#define DMA_ERR_ERR1(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA0_ERR.ERR1 Field                     */
#define DMA_ERR_ERR2_MASK                        (0x4U)                                              /*!< DMA0_ERR.ERR2 Mask                      */
#define DMA_ERR_ERR2_SHIFT                       (2U)                                                /*!< DMA0_ERR.ERR2 Position                  */
#define DMA_ERR_ERR2(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA0_ERR.ERR2 Field                     */
#define DMA_ERR_ERR3_MASK                        (0x8U)                                              /*!< DMA0_ERR.ERR3 Mask                      */
#define DMA_ERR_ERR3_SHIFT                       (3U)                                                /*!< DMA0_ERR.ERR3 Position                  */
#define DMA_ERR_ERR3(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< DMA0_ERR.ERR3 Field                     */
#define DMA_ERR_ERR4_MASK                        (0x10U)                                             /*!< DMA0_ERR.ERR4 Mask                      */
#define DMA_ERR_ERR4_SHIFT                       (4U)                                                /*!< DMA0_ERR.ERR4 Position                  */
#define DMA_ERR_ERR4(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA0_ERR.ERR4 Field                     */
#define DMA_ERR_ERR5_MASK                        (0x20U)                                             /*!< DMA0_ERR.ERR5 Mask                      */
#define DMA_ERR_ERR5_SHIFT                       (5U)                                                /*!< DMA0_ERR.ERR5 Position                  */
#define DMA_ERR_ERR5(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA0_ERR.ERR5 Field                     */
#define DMA_ERR_ERR6_MASK                        (0x40U)                                             /*!< DMA0_ERR.ERR6 Mask                      */
#define DMA_ERR_ERR6_SHIFT                       (6U)                                                /*!< DMA0_ERR.ERR6 Position                  */
#define DMA_ERR_ERR6(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA0_ERR.ERR6 Field                     */
#define DMA_ERR_ERR7_MASK                        (0x80U)                                             /*!< DMA0_ERR.ERR7 Mask                      */
#define DMA_ERR_ERR7_SHIFT                       (7U)                                                /*!< DMA0_ERR.ERR7 Position                  */
#define DMA_ERR_ERR7(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA0_ERR.ERR7 Field                     */
#define DMA_ERR_ERR8_MASK                        (0x100U)                                            /*!< DMA0_ERR.ERR8 Mask                      */
#define DMA_ERR_ERR8_SHIFT                       (8U)                                                /*!< DMA0_ERR.ERR8 Position                  */
#define DMA_ERR_ERR8(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< DMA0_ERR.ERR8 Field                     */
#define DMA_ERR_ERR9_MASK                        (0x200U)                                            /*!< DMA0_ERR.ERR9 Mask                      */
#define DMA_ERR_ERR9_SHIFT                       (9U)                                                /*!< DMA0_ERR.ERR9 Position                  */
#define DMA_ERR_ERR9(x)                          (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< DMA0_ERR.ERR9 Field                     */
#define DMA_ERR_ERR10_MASK                       (0x400U)                                            /*!< DMA0_ERR.ERR10 Mask                     */
#define DMA_ERR_ERR10_SHIFT                      (10U)                                               /*!< DMA0_ERR.ERR10 Position                 */
#define DMA_ERR_ERR10(x)                         (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< DMA0_ERR.ERR10 Field                    */
#define DMA_ERR_ERR11_MASK                       (0x800U)                                            /*!< DMA0_ERR.ERR11 Mask                     */
#define DMA_ERR_ERR11_SHIFT                      (11U)                                               /*!< DMA0_ERR.ERR11 Position                 */
#define DMA_ERR_ERR11(x)                         (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< DMA0_ERR.ERR11 Field                    */
#define DMA_ERR_ERR12_MASK                       (0x1000U)                                           /*!< DMA0_ERR.ERR12 Mask                     */
#define DMA_ERR_ERR12_SHIFT                      (12U)                                               /*!< DMA0_ERR.ERR12 Position                 */
#define DMA_ERR_ERR12(x)                         (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< DMA0_ERR.ERR12 Field                    */
#define DMA_ERR_ERR13_MASK                       (0x2000U)                                           /*!< DMA0_ERR.ERR13 Mask                     */
#define DMA_ERR_ERR13_SHIFT                      (13U)                                               /*!< DMA0_ERR.ERR13 Position                 */
#define DMA_ERR_ERR13(x)                         (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< DMA0_ERR.ERR13 Field                    */
#define DMA_ERR_ERR14_MASK                       (0x4000U)                                           /*!< DMA0_ERR.ERR14 Mask                     */
#define DMA_ERR_ERR14_SHIFT                      (14U)                                               /*!< DMA0_ERR.ERR14 Position                 */
#define DMA_ERR_ERR14(x)                         (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< DMA0_ERR.ERR14 Field                    */
#define DMA_ERR_ERR15_MASK                       (0x8000U)                                           /*!< DMA0_ERR.ERR15 Mask                     */
#define DMA_ERR_ERR15_SHIFT                      (15U)                                               /*!< DMA0_ERR.ERR15 Position                 */
#define DMA_ERR_ERR15(x)                         (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< DMA0_ERR.ERR15 Field                    */
/* ------- HRS Bit Fields                           ------ */
#define DMA_HRS_HRS0_MASK                        (0x1U)                                              /*!< DMA0_HRS.HRS0 Mask                      */
#define DMA_HRS_HRS0_SHIFT                       (0U)                                                /*!< DMA0_HRS.HRS0 Position                  */
#define DMA_HRS_HRS0(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< DMA0_HRS.HRS0 Field                     */
#define DMA_HRS_HRS1_MASK                        (0x2U)                                              /*!< DMA0_HRS.HRS1 Mask                      */
#define DMA_HRS_HRS1_SHIFT                       (1U)                                                /*!< DMA0_HRS.HRS1 Position                  */
#define DMA_HRS_HRS1(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA0_HRS.HRS1 Field                     */
#define DMA_HRS_HRS2_MASK                        (0x4U)                                              /*!< DMA0_HRS.HRS2 Mask                      */
#define DMA_HRS_HRS2_SHIFT                       (2U)                                                /*!< DMA0_HRS.HRS2 Position                  */
#define DMA_HRS_HRS2(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA0_HRS.HRS2 Field                     */
#define DMA_HRS_HRS3_MASK                        (0x8U)                                              /*!< DMA0_HRS.HRS3 Mask                      */
#define DMA_HRS_HRS3_SHIFT                       (3U)                                                /*!< DMA0_HRS.HRS3 Position                  */
#define DMA_HRS_HRS3(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< DMA0_HRS.HRS3 Field                     */
#define DMA_HRS_HRS4_MASK                        (0x10U)                                             /*!< DMA0_HRS.HRS4 Mask                      */
#define DMA_HRS_HRS4_SHIFT                       (4U)                                                /*!< DMA0_HRS.HRS4 Position                  */
#define DMA_HRS_HRS4(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA0_HRS.HRS4 Field                     */
#define DMA_HRS_HRS5_MASK                        (0x20U)                                             /*!< DMA0_HRS.HRS5 Mask                      */
#define DMA_HRS_HRS5_SHIFT                       (5U)                                                /*!< DMA0_HRS.HRS5 Position                  */
#define DMA_HRS_HRS5(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA0_HRS.HRS5 Field                     */
#define DMA_HRS_HRS6_MASK                        (0x40U)                                             /*!< DMA0_HRS.HRS6 Mask                      */
#define DMA_HRS_HRS6_SHIFT                       (6U)                                                /*!< DMA0_HRS.HRS6 Position                  */
#define DMA_HRS_HRS6(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA0_HRS.HRS6 Field                     */
#define DMA_HRS_HRS7_MASK                        (0x80U)                                             /*!< DMA0_HRS.HRS7 Mask                      */
#define DMA_HRS_HRS7_SHIFT                       (7U)                                                /*!< DMA0_HRS.HRS7 Position                  */
#define DMA_HRS_HRS7(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA0_HRS.HRS7 Field                     */
#define DMA_HRS_HRS8_MASK                        (0x100U)                                            /*!< DMA0_HRS.HRS8 Mask                      */
#define DMA_HRS_HRS8_SHIFT                       (8U)                                                /*!< DMA0_HRS.HRS8 Position                  */
#define DMA_HRS_HRS8(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< DMA0_HRS.HRS8 Field                     */
#define DMA_HRS_HRS9_MASK                        (0x200U)                                            /*!< DMA0_HRS.HRS9 Mask                      */
#define DMA_HRS_HRS9_SHIFT                       (9U)                                                /*!< DMA0_HRS.HRS9 Position                  */
#define DMA_HRS_HRS9(x)                          (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< DMA0_HRS.HRS9 Field                     */
#define DMA_HRS_HRS10_MASK                       (0x400U)                                            /*!< DMA0_HRS.HRS10 Mask                     */
#define DMA_HRS_HRS10_SHIFT                      (10U)                                               /*!< DMA0_HRS.HRS10 Position                 */
#define DMA_HRS_HRS10(x)                         (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< DMA0_HRS.HRS10 Field                    */
#define DMA_HRS_HRS11_MASK                       (0x800U)                                            /*!< DMA0_HRS.HRS11 Mask                     */
#define DMA_HRS_HRS11_SHIFT                      (11U)                                               /*!< DMA0_HRS.HRS11 Position                 */
#define DMA_HRS_HRS11(x)                         (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< DMA0_HRS.HRS11 Field                    */
#define DMA_HRS_HRS12_MASK                       (0x1000U)                                           /*!< DMA0_HRS.HRS12 Mask                     */
#define DMA_HRS_HRS12_SHIFT                      (12U)                                               /*!< DMA0_HRS.HRS12 Position                 */
#define DMA_HRS_HRS12(x)                         (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< DMA0_HRS.HRS12 Field                    */
#define DMA_HRS_HRS13_MASK                       (0x2000U)                                           /*!< DMA0_HRS.HRS13 Mask                     */
#define DMA_HRS_HRS13_SHIFT                      (13U)                                               /*!< DMA0_HRS.HRS13 Position                 */
#define DMA_HRS_HRS13(x)                         (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< DMA0_HRS.HRS13 Field                    */
#define DMA_HRS_HRS14_MASK                       (0x4000U)                                           /*!< DMA0_HRS.HRS14 Mask                     */
#define DMA_HRS_HRS14_SHIFT                      (14U)                                               /*!< DMA0_HRS.HRS14 Position                 */
#define DMA_HRS_HRS14(x)                         (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< DMA0_HRS.HRS14 Field                    */
#define DMA_HRS_HRS15_MASK                       (0x8000U)                                           /*!< DMA0_HRS.HRS15 Mask                     */
#define DMA_HRS_HRS15_SHIFT                      (15U)                                               /*!< DMA0_HRS.HRS15 Position                 */
#define DMA_HRS_HRS15(x)                         (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< DMA0_HRS.HRS15 Field                    */
/* ------- EARS Bit Fields                          ------ */
#define DMA_EARS_EDREQ_0_MASK                    (0x1U)                                              /*!< DMA0_EARS.EDREQ_0 Mask                  */
#define DMA_EARS_EDREQ_0_SHIFT                   (0U)                                                /*!< DMA0_EARS.EDREQ_0 Position              */
#define DMA_EARS_EDREQ_0(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< DMA0_EARS.EDREQ_0 Field                 */
#define DMA_EARS_EDREQ_1_MASK                    (0x2U)                                              /*!< DMA0_EARS.EDREQ_1 Mask                  */
#define DMA_EARS_EDREQ_1_SHIFT                   (1U)                                                /*!< DMA0_EARS.EDREQ_1 Position              */
#define DMA_EARS_EDREQ_1(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< DMA0_EARS.EDREQ_1 Field                 */
#define DMA_EARS_EDREQ_2_MASK                    (0x4U)                                              /*!< DMA0_EARS.EDREQ_2 Mask                  */
#define DMA_EARS_EDREQ_2_SHIFT                   (2U)                                                /*!< DMA0_EARS.EDREQ_2 Position              */
#define DMA_EARS_EDREQ_2(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< DMA0_EARS.EDREQ_2 Field                 */
#define DMA_EARS_EDREQ_3_MASK                    (0x8U)                                              /*!< DMA0_EARS.EDREQ_3 Mask                  */
#define DMA_EARS_EDREQ_3_SHIFT                   (3U)                                                /*!< DMA0_EARS.EDREQ_3 Position              */
#define DMA_EARS_EDREQ_3(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< DMA0_EARS.EDREQ_3 Field                 */
#define DMA_EARS_EDREQ_4_MASK                    (0x10U)                                             /*!< DMA0_EARS.EDREQ_4 Mask                  */
#define DMA_EARS_EDREQ_4_SHIFT                   (4U)                                                /*!< DMA0_EARS.EDREQ_4 Position              */
#define DMA_EARS_EDREQ_4(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< DMA0_EARS.EDREQ_4 Field                 */
#define DMA_EARS_EDREQ_5_MASK                    (0x20U)                                             /*!< DMA0_EARS.EDREQ_5 Mask                  */
#define DMA_EARS_EDREQ_5_SHIFT                   (5U)                                                /*!< DMA0_EARS.EDREQ_5 Position              */
#define DMA_EARS_EDREQ_5(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< DMA0_EARS.EDREQ_5 Field                 */
#define DMA_EARS_EDREQ_6_MASK                    (0x40U)                                             /*!< DMA0_EARS.EDREQ_6 Mask                  */
#define DMA_EARS_EDREQ_6_SHIFT                   (6U)                                                /*!< DMA0_EARS.EDREQ_6 Position              */
#define DMA_EARS_EDREQ_6(x)                      (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< DMA0_EARS.EDREQ_6 Field                 */
#define DMA_EARS_EDREQ_7_MASK                    (0x80U)                                             /*!< DMA0_EARS.EDREQ_7 Mask                  */
#define DMA_EARS_EDREQ_7_SHIFT                   (7U)                                                /*!< DMA0_EARS.EDREQ_7 Position              */
#define DMA_EARS_EDREQ_7(x)                      (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< DMA0_EARS.EDREQ_7 Field                 */
#define DMA_EARS_EDREQ_8_MASK                    (0x100U)                                            /*!< DMA0_EARS.EDREQ_8 Mask                  */
#define DMA_EARS_EDREQ_8_SHIFT                   (8U)                                                /*!< DMA0_EARS.EDREQ_8 Position              */
#define DMA_EARS_EDREQ_8(x)                      (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< DMA0_EARS.EDREQ_8 Field                 */
#define DMA_EARS_EDREQ_9_MASK                    (0x200U)                                            /*!< DMA0_EARS.EDREQ_9 Mask                  */
#define DMA_EARS_EDREQ_9_SHIFT                   (9U)                                                /*!< DMA0_EARS.EDREQ_9 Position              */
#define DMA_EARS_EDREQ_9(x)                      (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< DMA0_EARS.EDREQ_9 Field                 */
#define DMA_EARS_EDREQ_10_MASK                   (0x400U)                                            /*!< DMA0_EARS.EDREQ_10 Mask                 */
#define DMA_EARS_EDREQ_10_SHIFT                  (10U)                                               /*!< DMA0_EARS.EDREQ_10 Position             */
#define DMA_EARS_EDREQ_10(x)                     (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< DMA0_EARS.EDREQ_10 Field                */
#define DMA_EARS_EDREQ_11_MASK                   (0x800U)                                            /*!< DMA0_EARS.EDREQ_11 Mask                 */
#define DMA_EARS_EDREQ_11_SHIFT                  (11U)                                               /*!< DMA0_EARS.EDREQ_11 Position             */
#define DMA_EARS_EDREQ_11(x)                     (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< DMA0_EARS.EDREQ_11 Field                */
#define DMA_EARS_EDREQ_12_MASK                   (0x1000U)                                           /*!< DMA0_EARS.EDREQ_12 Mask                 */
#define DMA_EARS_EDREQ_12_SHIFT                  (12U)                                               /*!< DMA0_EARS.EDREQ_12 Position             */
#define DMA_EARS_EDREQ_12(x)                     (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< DMA0_EARS.EDREQ_12 Field                */
#define DMA_EARS_EDREQ_13_MASK                   (0x2000U)                                           /*!< DMA0_EARS.EDREQ_13 Mask                 */
#define DMA_EARS_EDREQ_13_SHIFT                  (13U)                                               /*!< DMA0_EARS.EDREQ_13 Position             */
#define DMA_EARS_EDREQ_13(x)                     (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< DMA0_EARS.EDREQ_13 Field                */
#define DMA_EARS_EDREQ_14_MASK                   (0x4000U)                                           /*!< DMA0_EARS.EDREQ_14 Mask                 */
#define DMA_EARS_EDREQ_14_SHIFT                  (14U)                                               /*!< DMA0_EARS.EDREQ_14 Position             */
#define DMA_EARS_EDREQ_14(x)                     (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< DMA0_EARS.EDREQ_14 Field                */
#define DMA_EARS_EDREQ_15_MASK                   (0x8000U)                                           /*!< DMA0_EARS.EDREQ_15 Mask                 */
#define DMA_EARS_EDREQ_15_SHIFT                  (15U)                                               /*!< DMA0_EARS.EDREQ_15 Position             */
#define DMA_EARS_EDREQ_15(x)                     (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< DMA0_EARS.EDREQ_15 Field                */
/* ------- DCHPRI Bit Fields                        ------ */
#define DMA_DCHPRI_CHPRI_MASK                    (0xFU)                                              /*!< DMA0_DCHPRI.CHPRI Mask                  */
#define DMA_DCHPRI_CHPRI_SHIFT                   (0U)                                                /*!< DMA0_DCHPRI.CHPRI Position              */
#define DMA_DCHPRI_CHPRI(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< DMA0_DCHPRI.CHPRI Field                 */
#define DMA_DCHPRI_DPA_MASK                      (0x40U)                                             /*!< DMA0_DCHPRI.DPA Mask                    */
#define DMA_DCHPRI_DPA_SHIFT                     (6U)                                                /*!< DMA0_DCHPRI.DPA Position                */
#define DMA_DCHPRI_DPA(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMA0_DCHPRI.DPA Field                   */
#define DMA_DCHPRI_ECP_MASK                      (0x80U)                                             /*!< DMA0_DCHPRI.ECP Mask                    */
#define DMA_DCHPRI_ECP_SHIFT                     (7U)                                                /*!< DMA0_DCHPRI.ECP Position                */
#define DMA_DCHPRI_ECP(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMA0_DCHPRI.ECP Field                   */
/* ------- SADDR Bit Fields                         ------ */
#define DMA_SADDR_SADDR_MASK                     (0xFFFFFFFFU)                                       /*!< DMA0_SADDR.SADDR Mask                   */
#define DMA_SADDR_SADDR_SHIFT                    (0U)                                                /*!< DMA0_SADDR.SADDR Position               */
#define DMA_SADDR_SADDR(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DMA0_SADDR.SADDR Field                  */
/* ------- SOFF Bit Fields                          ------ */
#define DMA_SOFF_SOFF_MASK                       (0xFFFFU)                                           /*!< DMA0_SOFF.SOFF Mask                     */
#define DMA_SOFF_SOFF_SHIFT                      (0U)                                                /*!< DMA0_SOFF.SOFF Position                 */
#define DMA_SOFF_SOFF(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< DMA0_SOFF.SOFF Field                    */
/* ------- ATTR Bit Fields                          ------ */
#define DMA_ATTR_DSIZE_MASK                      (0x7U)                                              /*!< DMA0_ATTR.DSIZE Mask                    */
#define DMA_ATTR_DSIZE_SHIFT                     (0U)                                                /*!< DMA0_ATTR.DSIZE Position                */
#define DMA_ATTR_DSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0x7UL)           /*!< DMA0_ATTR.DSIZE Field                   */
#define DMA_ATTR_DMOD_MASK                       (0xF8U)                                             /*!< DMA0_ATTR.DMOD Mask                     */
#define DMA_ATTR_DMOD_SHIFT                      (3U)                                                /*!< DMA0_ATTR.DMOD Position                 */
#define DMA_ATTR_DMOD(x)                         (((uint16_t)(((uint16_t)(x))<<3U))&0xF8UL)          /*!< DMA0_ATTR.DMOD Field                    */
#define DMA_ATTR_SSIZE_MASK                      (0x700U)                                            /*!< DMA0_ATTR.SSIZE Mask                    */
#define DMA_ATTR_SSIZE_SHIFT                     (8U)                                                /*!< DMA0_ATTR.SSIZE Position                */
#define DMA_ATTR_SSIZE(x)                        (((uint16_t)(((uint16_t)(x))<<8U))&0x700UL)         /*!< DMA0_ATTR.SSIZE Field                   */
#define DMA_ATTR_SMOD_MASK                       (0xF800U)                                           /*!< DMA0_ATTR.SMOD Mask                     */
#define DMA_ATTR_SMOD_SHIFT                      (11U)                                               /*!< DMA0_ATTR.SMOD Position                 */
#define DMA_ATTR_SMOD(x)                         (((uint16_t)(((uint16_t)(x))<<11U))&0xF800UL)       /*!< DMA0_ATTR.SMOD Field                    */
/* ------- NBYTES_MLNO Bit Fields                   ------ */
#define DMA_NBYTES_MLNO_NBYTES_MASK              (0xFFFFFFFFU)                                       /*!< DMA0_NBYTES_MLNO.NBYTES Mask            */
#define DMA_NBYTES_MLNO_NBYTES_SHIFT             (0U)                                                /*!< DMA0_NBYTES_MLNO.NBYTES Position        */
#define DMA_NBYTES_MLNO_NBYTES(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DMA0_NBYTES_MLNO.NBYTES Field           */
/* ------- NBYTES_MLOFFNO Bit Fields                ------ */
#define DMA_NBYTES_MLOFFNO_NBYTES_MASK           (0x3FFFFFFFU)                                       /*!< DMA0_NBYTES_MLOFFNO.NBYTES Mask         */
#define DMA_NBYTES_MLOFFNO_NBYTES_SHIFT          (0U)                                                /*!< DMA0_NBYTES_MLOFFNO.NBYTES Position     */
#define DMA_NBYTES_MLOFFNO_NBYTES(x)             (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFFFFFFUL)    /*!< DMA0_NBYTES_MLOFFNO.NBYTES Field        */
#define DMA_NBYTES_MLOFFNO_DMLOE_MASK            (0x40000000U)                                       /*!< DMA0_NBYTES_MLOFFNO.DMLOE Mask          */
#define DMA_NBYTES_MLOFFNO_DMLOE_SHIFT           (30U)                                               /*!< DMA0_NBYTES_MLOFFNO.DMLOE Position      */
#define DMA_NBYTES_MLOFFNO_DMLOE(x)              (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< DMA0_NBYTES_MLOFFNO.DMLOE Field         */
#define DMA_NBYTES_MLOFFNO_SMLOE_MASK            (0x80000000U)                                       /*!< DMA0_NBYTES_MLOFFNO.SMLOE Mask          */
#define DMA_NBYTES_MLOFFNO_SMLOE_SHIFT           (31U)                                               /*!< DMA0_NBYTES_MLOFFNO.SMLOE Position      */
#define DMA_NBYTES_MLOFFNO_SMLOE(x)              (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< DMA0_NBYTES_MLOFFNO.SMLOE Field         */
/* ------- NBYTES_MLOFFYES Bit Fields               ------ */
#define DMA_NBYTES_MLOFFYES_NBYTES_MASK          (0x3FFU)                                            /*!< DMA0_NBYTES_MLOFFYES.NBYTES Mask        */
#define DMA_NBYTES_MLOFFYES_NBYTES_SHIFT         (0U)                                                /*!< DMA0_NBYTES_MLOFFYES.NBYTES Position    */
#define DMA_NBYTES_MLOFFYES_NBYTES(x)            (((uint32_t)(((uint32_t)(x))<<0U))&0x3FFUL)         /*!< DMA0_NBYTES_MLOFFYES.NBYTES Field       */
#define DMA_NBYTES_MLOFFYES_MLOFF_MASK           (0x3FFFFC00U)                                       /*!< DMA0_NBYTES_MLOFFYES.MLOFF Mask         */
#define DMA_NBYTES_MLOFFYES_MLOFF_SHIFT          (10U)                                               /*!< DMA0_NBYTES_MLOFFYES.MLOFF Position     */
#define DMA_NBYTES_MLOFFYES_MLOFF(x)             (((uint32_t)(((uint32_t)(x))<<10U))&0x3FFFFC00UL)   /*!< DMA0_NBYTES_MLOFFYES.MLOFF Field        */
#define DMA_NBYTES_MLOFFYES_DMLOE_MASK           (0x40000000U)                                       /*!< DMA0_NBYTES_MLOFFYES.DMLOE Mask         */
#define DMA_NBYTES_MLOFFYES_DMLOE_SHIFT          (30U)                                               /*!< DMA0_NBYTES_MLOFFYES.DMLOE Position     */
#define DMA_NBYTES_MLOFFYES_DMLOE(x)             (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< DMA0_NBYTES_MLOFFYES.DMLOE Field        */
#define DMA_NBYTES_MLOFFYES_SMLOE_MASK           (0x80000000U)                                       /*!< DMA0_NBYTES_MLOFFYES.SMLOE Mask         */
#define DMA_NBYTES_MLOFFYES_SMLOE_SHIFT          (31U)                                               /*!< DMA0_NBYTES_MLOFFYES.SMLOE Position     */
#define DMA_NBYTES_MLOFFYES_SMLOE(x)             (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< DMA0_NBYTES_MLOFFYES.SMLOE Field        */
/* ------- SLAST Bit Fields                         ------ */
#define DMA_SLAST_SLAST_MASK                     (0xFFFFFFFFU)                                       /*!< DMA0_SLAST.SLAST Mask                   */
#define DMA_SLAST_SLAST_SHIFT                    (0U)                                                /*!< DMA0_SLAST.SLAST Position               */
#define DMA_SLAST_SLAST(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DMA0_SLAST.SLAST Field                  */
/* ------- DADDR Bit Fields                         ------ */
#define DMA_DADDR_DADDR_MASK                     (0xFFFFFFFFU)                                       /*!< DMA0_DADDR.DADDR Mask                   */
#define DMA_DADDR_DADDR_SHIFT                    (0U)                                                /*!< DMA0_DADDR.DADDR Position               */
#define DMA_DADDR_DADDR(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DMA0_DADDR.DADDR Field                  */
/* ------- DOFF Bit Fields                          ------ */
#define DMA_DOFF_DOFF_MASK                       (0xFFFFU)                                           /*!< DMA0_DOFF.DOFF Mask                     */
#define DMA_DOFF_DOFF_SHIFT                      (0U)                                                /*!< DMA0_DOFF.DOFF Position                 */
#define DMA_DOFF_DOFF(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< DMA0_DOFF.DOFF Field                    */
/* ------- CITER_ELINKNO Bit Fields                 ------ */
#define DMA_CITER_ELINKNO_CITER_MASK             (0x7FFFU)                                           /*!< DMA0_CITER_ELINKNO.CITER Mask           */
#define DMA_CITER_ELINKNO_CITER_SHIFT            (0U)                                                /*!< DMA0_CITER_ELINKNO.CITER Position       */
#define DMA_CITER_ELINKNO_CITER(x)               (((uint16_t)(((uint16_t)(x))<<0U))&0x7FFFUL)        /*!< DMA0_CITER_ELINKNO.CITER Field          */
#define DMA_CITER_ELINKNO_ELINK_MASK             (0x8000U)                                           /*!< DMA0_CITER_ELINKNO.ELINK Mask           */
#define DMA_CITER_ELINKNO_ELINK_SHIFT            (15U)                                               /*!< DMA0_CITER_ELINKNO.ELINK Position       */
#define DMA_CITER_ELINKNO_ELINK(x)               (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< DMA0_CITER_ELINKNO.ELINK Field          */
/* ------- CITER_ELINKYES Bit Fields                ------ */
#define DMA_CITER_ELINKYES_CITER_MASK            (0x1FFU)                                            /*!< DMA0_CITER_ELINKYES.CITER Mask          */
#define DMA_CITER_ELINKYES_CITER_SHIFT           (0U)                                                /*!< DMA0_CITER_ELINKYES.CITER Position      */
#define DMA_CITER_ELINKYES_CITER(x)              (((uint16_t)(((uint16_t)(x))<<0U))&0x1FFUL)         /*!< DMA0_CITER_ELINKYES.CITER Field         */
#define DMA_CITER_ELINKYES_LINKCH_MASK           (0x1E00U)                                           /*!< DMA0_CITER_ELINKYES.LINKCH Mask         */
#define DMA_CITER_ELINKYES_LINKCH_SHIFT          (9U)                                                /*!< DMA0_CITER_ELINKYES.LINKCH Position     */
#define DMA_CITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<9U))&0x1E00UL)        /*!< DMA0_CITER_ELINKYES.LINKCH Field        */
#define DMA_CITER_ELINKYES_ELINK_MASK            (0x8000U)                                           /*!< DMA0_CITER_ELINKYES.ELINK Mask          */
#define DMA_CITER_ELINKYES_ELINK_SHIFT           (15U)                                               /*!< DMA0_CITER_ELINKYES.ELINK Position      */
#define DMA_CITER_ELINKYES_ELINK(x)              (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< DMA0_CITER_ELINKYES.ELINK Field         */
/* ------- DLASTSGA Bit Fields                      ------ */
#define DMA_DLASTSGA_DLASTSGA_MASK               (0xFFFFFFFFU)                                       /*!< DMA0_DLASTSGA.DLASTSGA Mask             */
#define DMA_DLASTSGA_DLASTSGA_SHIFT              (0U)                                                /*!< DMA0_DLASTSGA.DLASTSGA Position         */
#define DMA_DLASTSGA_DLASTSGA(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< DMA0_DLASTSGA.DLASTSGA Field            */
/* ------- CSR Bit Fields                           ------ */
#define DMA_CSR_START_MASK                       (0x1U)                                              /*!< DMA0_CSR.START Mask                     */
#define DMA_CSR_START_SHIFT                      (0U)                                                /*!< DMA0_CSR.START Position                 */
#define DMA_CSR_START(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< DMA0_CSR.START Field                    */
#define DMA_CSR_INTMAJOR_MASK                    (0x2U)                                              /*!< DMA0_CSR.INTMAJOR Mask                  */
#define DMA_CSR_INTMAJOR_SHIFT                   (1U)                                                /*!< DMA0_CSR.INTMAJOR Position              */
#define DMA_CSR_INTMAJOR(x)                      (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< DMA0_CSR.INTMAJOR Field                 */
#define DMA_CSR_INTHALF_MASK                     (0x4U)                                              /*!< DMA0_CSR.INTHALF Mask                   */
#define DMA_CSR_INTHALF_SHIFT                    (2U)                                                /*!< DMA0_CSR.INTHALF Position               */
#define DMA_CSR_INTHALF(x)                       (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< DMA0_CSR.INTHALF Field                  */
#define DMA_CSR_DREQ_MASK                        (0x8U)                                              /*!< DMA0_CSR.DREQ Mask                      */
#define DMA_CSR_DREQ_SHIFT                       (3U)                                                /*!< DMA0_CSR.DREQ Position                  */
#define DMA_CSR_DREQ(x)                          (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< DMA0_CSR.DREQ Field                     */
#define DMA_CSR_ESG_MASK                         (0x10U)                                             /*!< DMA0_CSR.ESG Mask                       */
#define DMA_CSR_ESG_SHIFT                        (4U)                                                /*!< DMA0_CSR.ESG Position                   */
#define DMA_CSR_ESG(x)                           (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< DMA0_CSR.ESG Field                      */
#define DMA_CSR_MAJORELINK_MASK                  (0x20U)                                             /*!< DMA0_CSR.MAJORELINK Mask                */
#define DMA_CSR_MAJORELINK_SHIFT                 (5U)                                                /*!< DMA0_CSR.MAJORELINK Position            */
#define DMA_CSR_MAJORELINK(x)                    (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< DMA0_CSR.MAJORELINK Field               */
#define DMA_CSR_ACTIVE_MASK                      (0x40U)                                             /*!< DMA0_CSR.ACTIVE Mask                    */
#define DMA_CSR_ACTIVE_SHIFT                     (6U)                                                /*!< DMA0_CSR.ACTIVE Position                */
#define DMA_CSR_ACTIVE(x)                        (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< DMA0_CSR.ACTIVE Field                   */
#define DMA_CSR_DONE_MASK                        (0x80U)                                             /*!< DMA0_CSR.DONE Mask                      */
#define DMA_CSR_DONE_SHIFT                       (7U)                                                /*!< DMA0_CSR.DONE Position                  */
#define DMA_CSR_DONE(x)                          (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< DMA0_CSR.DONE Field                     */
#define DMA_CSR_MAJORLINKCH_MASK                 (0xF00U)                                            /*!< DMA0_CSR.MAJORLINKCH Mask               */
#define DMA_CSR_MAJORLINKCH_SHIFT                (8U)                                                /*!< DMA0_CSR.MAJORLINKCH Position           */
#define DMA_CSR_MAJORLINKCH(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0xF00UL)         /*!< DMA0_CSR.MAJORLINKCH Field              */
#define DMA_CSR_BWC_MASK                         (0xC000U)                                           /*!< DMA0_CSR.BWC Mask                       */
#define DMA_CSR_BWC_SHIFT                        (14U)                                               /*!< DMA0_CSR.BWC Position                   */
#define DMA_CSR_BWC(x)                           (((uint16_t)(((uint16_t)(x))<<14U))&0xC000UL)       /*!< DMA0_CSR.BWC Field                      */
/* ------- BITER_ELINKNO Bit Fields                 ------ */
#define DMA_BITER_ELINKNO_BITER_MASK             (0x7FFFU)                                           /*!< DMA0_BITER_ELINKNO.BITER Mask           */
#define DMA_BITER_ELINKNO_BITER_SHIFT            (0U)                                                /*!< DMA0_BITER_ELINKNO.BITER Position       */
#define DMA_BITER_ELINKNO_BITER(x)               (((uint16_t)(((uint16_t)(x))<<0U))&0x7FFFUL)        /*!< DMA0_BITER_ELINKNO.BITER Field          */
#define DMA_BITER_ELINKNO_ELINK_MASK             (0x8000U)                                           /*!< DMA0_BITER_ELINKNO.ELINK Mask           */
#define DMA_BITER_ELINKNO_ELINK_SHIFT            (15U)                                               /*!< DMA0_BITER_ELINKNO.ELINK Position       */
#define DMA_BITER_ELINKNO_ELINK(x)               (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< DMA0_BITER_ELINKNO.ELINK Field          */
/* ------- BITER_ELINKYES Bit Fields                ------ */
#define DMA_BITER_ELINKYES_BITER_MASK            (0x1FFU)                                            /*!< DMA0_BITER_ELINKYES.BITER Mask          */
#define DMA_BITER_ELINKYES_BITER_SHIFT           (0U)                                                /*!< DMA0_BITER_ELINKYES.BITER Position      */
#define DMA_BITER_ELINKYES_BITER(x)              (((uint16_t)(((uint16_t)(x))<<0U))&0x1FFUL)         /*!< DMA0_BITER_ELINKYES.BITER Field         */
#define DMA_BITER_ELINKYES_LINKCH_MASK           (0x1E00U)                                           /*!< DMA0_BITER_ELINKYES.LINKCH Mask         */
#define DMA_BITER_ELINKYES_LINKCH_SHIFT          (9U)                                                /*!< DMA0_BITER_ELINKYES.LINKCH Position     */
#define DMA_BITER_ELINKYES_LINKCH(x)             (((uint16_t)(((uint16_t)(x))<<9U))&0x1E00UL)        /*!< DMA0_BITER_ELINKYES.LINKCH Field        */
#define DMA_BITER_ELINKYES_ELINK_MASK            (0x8000U)                                           /*!< DMA0_BITER_ELINKYES.ELINK Mask          */
#define DMA_BITER_ELINKYES_ELINK_SHIFT           (15U)                                               /*!< DMA0_BITER_ELINKYES.ELINK Position      */
#define DMA_BITER_ELINKYES_ELINK(x)              (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< DMA0_BITER_ELINKYES.ELINK Field         */
/**
 * @} */ /* End group DMA0_Register_Masks_GROUP 
 */

/* DMA0 - Peripheral instance base addresses */
#define DMA0_BasePtr                   0x40008000UL //!< Peripheral base address
#define DMA0                           ((DMA_Type *) DMA0_BasePtr) //!< Freescale base pointer
#define DMA0_BASE_PTR                  (DMA0) //!< Freescale style base pointer
/**
 * @} */ /* End group DMA0_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup DMAMUX_Peripheral_access_layer_GROUP DMAMUX Peripheral Access Layer
* @brief C Struct for DMAMUX
* @{
*/

/* ================================================================================ */
/* ================           DMAMUX0 (file:DMAMUX0_16CH_TRIG)       ================ */
/* ================================================================================ */

/**
 * @brief DMA channel multiplexor
 */
/**
* @addtogroup DMAMUX_structs_GROUP DMAMUX struct
* @brief Struct for DMAMUX
* @{
*/
typedef struct {                                /*       DMAMUX0 Structure                                            */
   __IO uint8_t   CHCFG[16];                    /**< 0000: Channel Configuration Register                               */
} DMAMUX_Type;

/**
 * @} */ /* End group DMAMUX_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'DMAMUX0' Position & Mask macros                     ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup DMAMUX_Register_Masks_GROUP DMAMUX Register Masks
* @brief Register Masks for DMAMUX
* @{
*/
/* ------- CHCFG Bit Fields                         ------ */
#define DMAMUX_CHCFG_SOURCE_MASK                 (0x3FU)                                             /*!< DMAMUX0_CHCFG.SOURCE Mask               */
#define DMAMUX_CHCFG_SOURCE_SHIFT                (0U)                                                /*!< DMAMUX0_CHCFG.SOURCE Position           */
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0x3FUL)            /*!< DMAMUX0_CHCFG.SOURCE Field              */
#define DMAMUX_CHCFG_TRIG_MASK                   (0x40U)                                             /*!< DMAMUX0_CHCFG.TRIG Mask                 */
#define DMAMUX_CHCFG_TRIG_SHIFT                  (6U)                                                /*!< DMAMUX0_CHCFG.TRIG Position             */
#define DMAMUX_CHCFG_TRIG(x)                     (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< DMAMUX0_CHCFG.TRIG Field                */
#define DMAMUX_CHCFG_ENBL_MASK                   (0x80U)                                             /*!< DMAMUX0_CHCFG.ENBL Mask                 */
#define DMAMUX_CHCFG_ENBL_SHIFT                  (7U)                                                /*!< DMAMUX0_CHCFG.ENBL Position             */
#define DMAMUX_CHCFG_ENBL(x)                     (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< DMAMUX0_CHCFG.ENBL Field                */
/**
 * @} */ /* End group DMAMUX_Register_Masks_GROUP 
 */

/* DMAMUX0 - Peripheral instance base addresses */
#define DMAMUX0_BasePtr                0x40021000UL //!< Peripheral base address
#define DMAMUX0                        ((DMAMUX_Type *) DMAMUX0_BasePtr) //!< Freescale base pointer
#define DMAMUX0_BASE_PTR               (DMAMUX0) //!< Freescale style base pointer
/**
 * @} */ /* End group DMAMUX_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup ENC_Peripheral_access_layer_GROUP ENC Peripheral Access Layer
* @brief C Struct for ENC
* @{
*/

/* ================================================================================ */
/* ================           ENC (file:ENC_0)                     ================ */
/* ================================================================================ */

/**
 * @brief Quadrature Decoder
 */
/**
* @addtogroup ENC_structs_GROUP ENC struct
* @brief Struct for ENC
* @{
*/
typedef struct {                                /*       ENC Structure                                                */
   __IO uint16_t  CTRL;                         /**< 0000: Control Register                                             */
   __IO uint16_t  FILT;                         /**< 0002: Input Filter Register                                        */
   __IO uint16_t  WTR;                          /**< 0004: Watchdog Timeout Register                                    */
   __IO uint16_t  POSD;                         /**< 0006: Position Difference Counter Register                         */
   __I  uint16_t  POSDH;                        /**< 0008: Position Difference Hold Register                            */
   __IO uint16_t  REV;                          /**< 000A: Revolution Counter Register                                  */
   __I  uint16_t  REVH;                         /**< 000C: Revolution Hold Register                                     */
   __IO uint16_t  UPOS;                         /**< 000E: Upper Position Counter Register                              */
   __IO uint16_t  LPOS;                         /**< 0010: Lower Position Counter Register                              */
   __I  uint16_t  UPOSH;                        /**< 0012: Upper Position Hold Register                                 */
   __I  uint16_t  LPOSH;                        /**< 0014: Lower Position Hold Register                                 */
   __IO uint16_t  UINIT;                        /**< 0016: Upper Initialization Register                                */
   __IO uint16_t  LINIT;                        /**< 0018: Lower Initialization Register                                */
   __I  uint16_t  IMR;                          /**< 001A: Input Monitor Register                                       */
   __IO uint16_t  TST;                          /**< 001C: Test Register                                                */
   __IO uint16_t  CTRL2;                        /**< 001E: Control 2 Register                                           */
   __IO uint16_t  UMOD;                         /**< 0020: Upper Modulus Register                                       */
   __IO uint16_t  LMOD;                         /**< 0022: Lower Modulus Register                                       */
   __IO uint16_t  UCOMP;                        /**< 0024: Upper Position Compare Register                              */
   __IO uint16_t  LCOMP;                        /**< 0026: Lower Position Compare Register                              */
} ENC_Type;

/**
 * @} */ /* End group ENC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'ENC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup ENC_Register_Masks_GROUP ENC Register Masks
* @brief Register Masks for ENC
* @{
*/
/* ------- CTRL Bit Fields                          ------ */
#define ENC_CTRL_CMPIE_MASK                      (0x1U)                                              /*!< ENC_CTRL.CMPIE Mask                     */
#define ENC_CTRL_CMPIE_SHIFT                     (0U)                                                /*!< ENC_CTRL.CMPIE Position                 */
#define ENC_CTRL_CMPIE(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< ENC_CTRL.CMPIE Field                    */
#define ENC_CTRL_CMPIRQ_MASK                     (0x2U)                                              /*!< ENC_CTRL.CMPIRQ Mask                    */
#define ENC_CTRL_CMPIRQ_SHIFT                    (1U)                                                /*!< ENC_CTRL.CMPIRQ Position                */
#define ENC_CTRL_CMPIRQ(x)                       (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< ENC_CTRL.CMPIRQ Field                   */
#define ENC_CTRL_WDE_MASK                        (0x4U)                                              /*!< ENC_CTRL.WDE Mask                       */
#define ENC_CTRL_WDE_SHIFT                       (2U)                                                /*!< ENC_CTRL.WDE Position                   */
#define ENC_CTRL_WDE(x)                          (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< ENC_CTRL.WDE Field                      */
#define ENC_CTRL_DIE_MASK                        (0x8U)                                              /*!< ENC_CTRL.DIE Mask                       */
#define ENC_CTRL_DIE_SHIFT                       (3U)                                                /*!< ENC_CTRL.DIE Position                   */
#define ENC_CTRL_DIE(x)                          (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< ENC_CTRL.DIE Field                      */
#define ENC_CTRL_DIRQ_MASK                       (0x10U)                                             /*!< ENC_CTRL.DIRQ Mask                      */
#define ENC_CTRL_DIRQ_SHIFT                      (4U)                                                /*!< ENC_CTRL.DIRQ Position                  */
#define ENC_CTRL_DIRQ(x)                         (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< ENC_CTRL.DIRQ Field                     */
#define ENC_CTRL_XNE_MASK                        (0x20U)                                             /*!< ENC_CTRL.XNE Mask                       */
#define ENC_CTRL_XNE_SHIFT                       (5U)                                                /*!< ENC_CTRL.XNE Position                   */
#define ENC_CTRL_XNE(x)                          (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< ENC_CTRL.XNE Field                      */
#define ENC_CTRL_XIP_MASK                        (0x40U)                                             /*!< ENC_CTRL.XIP Mask                       */
#define ENC_CTRL_XIP_SHIFT                       (6U)                                                /*!< ENC_CTRL.XIP Position                   */
#define ENC_CTRL_XIP(x)                          (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< ENC_CTRL.XIP Field                      */
#define ENC_CTRL_XIE_MASK                        (0x80U)                                             /*!< ENC_CTRL.XIE Mask                       */
#define ENC_CTRL_XIE_SHIFT                       (7U)                                                /*!< ENC_CTRL.XIE Position                   */
#define ENC_CTRL_XIE(x)                          (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< ENC_CTRL.XIE Field                      */
#define ENC_CTRL_XIRQ_MASK                       (0x100U)                                            /*!< ENC_CTRL.XIRQ Mask                      */
#define ENC_CTRL_XIRQ_SHIFT                      (8U)                                                /*!< ENC_CTRL.XIRQ Position                  */
#define ENC_CTRL_XIRQ(x)                         (((uint16_t)(((uint16_t)(x))<<8U))&0x100UL)         /*!< ENC_CTRL.XIRQ Field                     */
#define ENC_CTRL_PH1_MASK                        (0x200U)                                            /*!< ENC_CTRL.PH1 Mask                       */
#define ENC_CTRL_PH1_SHIFT                       (9U)                                                /*!< ENC_CTRL.PH1 Position                   */
#define ENC_CTRL_PH1(x)                          (((uint16_t)(((uint16_t)(x))<<9U))&0x200UL)         /*!< ENC_CTRL.PH1 Field                      */
#define ENC_CTRL_REV_MASK                        (0x400U)                                            /*!< ENC_CTRL.REV Mask                       */
#define ENC_CTRL_REV_SHIFT                       (10U)                                               /*!< ENC_CTRL.REV Position                   */
#define ENC_CTRL_REV(x)                          (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< ENC_CTRL.REV Field                      */
#define ENC_CTRL_SWIP_MASK                       (0x800U)                                            /*!< ENC_CTRL.SWIP Mask                      */
#define ENC_CTRL_SWIP_SHIFT                      (11U)                                               /*!< ENC_CTRL.SWIP Position                  */
#define ENC_CTRL_SWIP(x)                         (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< ENC_CTRL.SWIP Field                     */
#define ENC_CTRL_HNE_MASK                        (0x1000U)                                           /*!< ENC_CTRL.HNE Mask                       */
#define ENC_CTRL_HNE_SHIFT                       (12U)                                               /*!< ENC_CTRL.HNE Position                   */
#define ENC_CTRL_HNE(x)                          (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< ENC_CTRL.HNE Field                      */
#define ENC_CTRL_HIP_MASK                        (0x2000U)                                           /*!< ENC_CTRL.HIP Mask                       */
#define ENC_CTRL_HIP_SHIFT                       (13U)                                               /*!< ENC_CTRL.HIP Position                   */
#define ENC_CTRL_HIP(x)                          (((uint16_t)(((uint16_t)(x))<<13U))&0x2000UL)       /*!< ENC_CTRL.HIP Field                      */
#define ENC_CTRL_HIE_MASK                        (0x4000U)                                           /*!< ENC_CTRL.HIE Mask                       */
#define ENC_CTRL_HIE_SHIFT                       (14U)                                               /*!< ENC_CTRL.HIE Position                   */
#define ENC_CTRL_HIE(x)                          (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< ENC_CTRL.HIE Field                      */
#define ENC_CTRL_HIRQ_MASK                       (0x8000U)                                           /*!< ENC_CTRL.HIRQ Mask                      */
#define ENC_CTRL_HIRQ_SHIFT                      (15U)                                               /*!< ENC_CTRL.HIRQ Position                  */
#define ENC_CTRL_HIRQ(x)                         (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< ENC_CTRL.HIRQ Field                     */
/* ------- FILT Bit Fields                          ------ */
#define ENC_FILT_FILT_PER_MASK                   (0xFFU)                                             /*!< ENC_FILT.FILT_PER Mask                  */
#define ENC_FILT_FILT_PER_SHIFT                  (0U)                                                /*!< ENC_FILT.FILT_PER Position              */
#define ENC_FILT_FILT_PER(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0xFFUL)          /*!< ENC_FILT.FILT_PER Field                 */
#define ENC_FILT_FILT_CNT_MASK                   (0x700U)                                            /*!< ENC_FILT.FILT_CNT Mask                  */
#define ENC_FILT_FILT_CNT_SHIFT                  (8U)                                                /*!< ENC_FILT.FILT_CNT Position              */
#define ENC_FILT_FILT_CNT(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x700UL)         /*!< ENC_FILT.FILT_CNT Field                 */
/* ------- WTR Bit Fields                           ------ */
#define ENC_WTR_WDOG_MASK                        (0xFFFFU)                                           /*!< ENC_WTR.WDOG Mask                       */
#define ENC_WTR_WDOG_SHIFT                       (0U)                                                /*!< ENC_WTR.WDOG Position                   */
#define ENC_WTR_WDOG(x)                          (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_WTR.WDOG Field                      */
/* ------- POSD Bit Fields                          ------ */
#define ENC_POSD_POSD_MASK                       (0xFFFFU)                                           /*!< ENC_POSD.POSD Mask                      */
#define ENC_POSD_POSD_SHIFT                      (0U)                                                /*!< ENC_POSD.POSD Position                  */
#define ENC_POSD_POSD(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_POSD.POSD Field                     */
/* ------- POSDH Bit Fields                         ------ */
#define ENC_POSDH_POSDH_MASK                     (0xFFFFU)                                           /*!< ENC_POSDH.POSDH Mask                    */
#define ENC_POSDH_POSDH_SHIFT                    (0U)                                                /*!< ENC_POSDH.POSDH Position                */
#define ENC_POSDH_POSDH(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_POSDH.POSDH Field                   */
/* ------- REV Bit Fields                           ------ */
#define ENC_REV_REV_MASK                         (0xFFFFU)                                           /*!< ENC_REV.REV Mask                        */
#define ENC_REV_REV_SHIFT                        (0U)                                                /*!< ENC_REV.REV Position                    */
#define ENC_REV_REV(x)                           (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_REV.REV Field                       */
/* ------- REVH Bit Fields                          ------ */
#define ENC_REVH_REVH_MASK                       (0xFFFFU)                                           /*!< ENC_REVH.REVH Mask                      */
#define ENC_REVH_REVH_SHIFT                      (0U)                                                /*!< ENC_REVH.REVH Position                  */
#define ENC_REVH_REVH(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_REVH.REVH Field                     */
/* ------- UPOS Bit Fields                          ------ */
#define ENC_UPOS_POS_MASK                        (0xFFFFU)                                           /*!< ENC_UPOS.POS Mask                       */
#define ENC_UPOS_POS_SHIFT                       (0U)                                                /*!< ENC_UPOS.POS Position                   */
#define ENC_UPOS_POS(x)                          (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_UPOS.POS Field                      */
/* ------- LPOS Bit Fields                          ------ */
#define ENC_LPOS_POS_MASK                        (0xFFFFU)                                           /*!< ENC_LPOS.POS Mask                       */
#define ENC_LPOS_POS_SHIFT                       (0U)                                                /*!< ENC_LPOS.POS Position                   */
#define ENC_LPOS_POS(x)                          (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_LPOS.POS Field                      */
/* ------- UPOSH Bit Fields                         ------ */
#define ENC_UPOSH_POSH_MASK                      (0xFFFFU)                                           /*!< ENC_UPOSH.POSH Mask                     */
#define ENC_UPOSH_POSH_SHIFT                     (0U)                                                /*!< ENC_UPOSH.POSH Position                 */
#define ENC_UPOSH_POSH(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_UPOSH.POSH Field                    */
/* ------- LPOSH Bit Fields                         ------ */
#define ENC_LPOSH_POSH_MASK                      (0xFFFFU)                                           /*!< ENC_LPOSH.POSH Mask                     */
#define ENC_LPOSH_POSH_SHIFT                     (0U)                                                /*!< ENC_LPOSH.POSH Position                 */
#define ENC_LPOSH_POSH(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_LPOSH.POSH Field                    */
/* ------- UINIT Bit Fields                         ------ */
#define ENC_UINIT_INIT_MASK                      (0xFFFFU)                                           /*!< ENC_UINIT.INIT Mask                     */
#define ENC_UINIT_INIT_SHIFT                     (0U)                                                /*!< ENC_UINIT.INIT Position                 */
#define ENC_UINIT_INIT(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_UINIT.INIT Field                    */
/* ------- LINIT Bit Fields                         ------ */
#define ENC_LINIT_INIT_MASK                      (0xFFFFU)                                           /*!< ENC_LINIT.INIT Mask                     */
#define ENC_LINIT_INIT_SHIFT                     (0U)                                                /*!< ENC_LINIT.INIT Position                 */
#define ENC_LINIT_INIT(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_LINIT.INIT Field                    */
/* ------- IMR Bit Fields                           ------ */
#define ENC_IMR_HOME_MASK                        (0x1U)                                              /*!< ENC_IMR.HOME Mask                       */
#define ENC_IMR_HOME_SHIFT                       (0U)                                                /*!< ENC_IMR.HOME Position                   */
#define ENC_IMR_HOME(x)                          (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< ENC_IMR.HOME Field                      */
#define ENC_IMR_INDEX_MASK                       (0x2U)                                              /*!< ENC_IMR.INDEX Mask                      */
#define ENC_IMR_INDEX_SHIFT                      (1U)                                                /*!< ENC_IMR.INDEX Position                  */
#define ENC_IMR_INDEX(x)                         (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< ENC_IMR.INDEX Field                     */
#define ENC_IMR_PHB_MASK                         (0x4U)                                              /*!< ENC_IMR.PHB Mask                        */
#define ENC_IMR_PHB_SHIFT                        (2U)                                                /*!< ENC_IMR.PHB Position                    */
#define ENC_IMR_PHB(x)                           (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< ENC_IMR.PHB Field                       */
#define ENC_IMR_PHA_MASK                         (0x8U)                                              /*!< ENC_IMR.PHA Mask                        */
#define ENC_IMR_PHA_SHIFT                        (3U)                                                /*!< ENC_IMR.PHA Position                    */
#define ENC_IMR_PHA(x)                           (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< ENC_IMR.PHA Field                       */
#define ENC_IMR_FHOM_MASK                        (0x10U)                                             /*!< ENC_IMR.FHOM Mask                       */
#define ENC_IMR_FHOM_SHIFT                       (4U)                                                /*!< ENC_IMR.FHOM Position                   */
#define ENC_IMR_FHOM(x)                          (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< ENC_IMR.FHOM Field                      */
#define ENC_IMR_FIND_MASK                        (0x20U)                                             /*!< ENC_IMR.FIND Mask                       */
#define ENC_IMR_FIND_SHIFT                       (5U)                                                /*!< ENC_IMR.FIND Position                   */
#define ENC_IMR_FIND(x)                          (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< ENC_IMR.FIND Field                      */
#define ENC_IMR_FPHB_MASK                        (0x40U)                                             /*!< ENC_IMR.FPHB Mask                       */
#define ENC_IMR_FPHB_SHIFT                       (6U)                                                /*!< ENC_IMR.FPHB Position                   */
#define ENC_IMR_FPHB(x)                          (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< ENC_IMR.FPHB Field                      */
#define ENC_IMR_FPHA_MASK                        (0x80U)                                             /*!< ENC_IMR.FPHA Mask                       */
#define ENC_IMR_FPHA_SHIFT                       (7U)                                                /*!< ENC_IMR.FPHA Position                   */
#define ENC_IMR_FPHA(x)                          (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< ENC_IMR.FPHA Field                      */
/* ------- TST Bit Fields                           ------ */
#define ENC_TST_TEST_COUNT_MASK                  (0xFFU)                                             /*!< ENC_TST.TEST_COUNT Mask                 */
#define ENC_TST_TEST_COUNT_SHIFT                 (0U)                                                /*!< ENC_TST.TEST_COUNT Position             */
#define ENC_TST_TEST_COUNT(x)                    (((uint16_t)(((uint16_t)(x))<<0U))&0xFFUL)          /*!< ENC_TST.TEST_COUNT Field                */
#define ENC_TST_TEST_PERIOD_MASK                 (0x1F00U)                                           /*!< ENC_TST.TEST_PERIOD Mask                */
#define ENC_TST_TEST_PERIOD_SHIFT                (8U)                                                /*!< ENC_TST.TEST_PERIOD Position            */
#define ENC_TST_TEST_PERIOD(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0x1F00UL)        /*!< ENC_TST.TEST_PERIOD Field               */
#define ENC_TST_QDN_MASK                         (0x2000U)                                           /*!< ENC_TST.QDN Mask                        */
#define ENC_TST_QDN_SHIFT                        (13U)                                               /*!< ENC_TST.QDN Position                    */
#define ENC_TST_QDN(x)                           (((uint16_t)(((uint16_t)(x))<<13U))&0x2000UL)       /*!< ENC_TST.QDN Field                       */
#define ENC_TST_TCE_MASK                         (0x4000U)                                           /*!< ENC_TST.TCE Mask                        */
#define ENC_TST_TCE_SHIFT                        (14U)                                               /*!< ENC_TST.TCE Position                    */
#define ENC_TST_TCE(x)                           (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< ENC_TST.TCE Field                       */
#define ENC_TST_TEN_MASK                         (0x8000U)                                           /*!< ENC_TST.TEN Mask                        */
#define ENC_TST_TEN_SHIFT                        (15U)                                               /*!< ENC_TST.TEN Position                    */
#define ENC_TST_TEN(x)                           (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< ENC_TST.TEN Field                       */
/* ------- CTRL2 Bit Fields                         ------ */
#define ENC_CTRL2_UPDHLD_MASK                    (0x1U)                                              /*!< ENC_CTRL2.UPDHLD Mask                   */
#define ENC_CTRL2_UPDHLD_SHIFT                   (0U)                                                /*!< ENC_CTRL2.UPDHLD Position               */
#define ENC_CTRL2_UPDHLD(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< ENC_CTRL2.UPDHLD Field                  */
#define ENC_CTRL2_UPDPOS_MASK                    (0x2U)                                              /*!< ENC_CTRL2.UPDPOS Mask                   */
#define ENC_CTRL2_UPDPOS_SHIFT                   (1U)                                                /*!< ENC_CTRL2.UPDPOS Position               */
#define ENC_CTRL2_UPDPOS(x)                      (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< ENC_CTRL2.UPDPOS Field                  */
#define ENC_CTRL2_MOD_MASK                       (0x4U)                                              /*!< ENC_CTRL2.MOD Mask                      */
#define ENC_CTRL2_MOD_SHIFT                      (2U)                                                /*!< ENC_CTRL2.MOD Position                  */
#define ENC_CTRL2_MOD(x)                         (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< ENC_CTRL2.MOD Field                     */
#define ENC_CTRL2_DIR_MASK                       (0x8U)                                              /*!< ENC_CTRL2.DIR Mask                      */
#define ENC_CTRL2_DIR_SHIFT                      (3U)                                                /*!< ENC_CTRL2.DIR Position                  */
#define ENC_CTRL2_DIR(x)                         (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< ENC_CTRL2.DIR Field                     */
#define ENC_CTRL2_RUIE_MASK                      (0x10U)                                             /*!< ENC_CTRL2.RUIE Mask                     */
#define ENC_CTRL2_RUIE_SHIFT                     (4U)                                                /*!< ENC_CTRL2.RUIE Position                 */
#define ENC_CTRL2_RUIE(x)                        (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< ENC_CTRL2.RUIE Field                    */
#define ENC_CTRL2_RUIRQ_MASK                     (0x20U)                                             /*!< ENC_CTRL2.RUIRQ Mask                    */
#define ENC_CTRL2_RUIRQ_SHIFT                    (5U)                                                /*!< ENC_CTRL2.RUIRQ Position                */
#define ENC_CTRL2_RUIRQ(x)                       (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< ENC_CTRL2.RUIRQ Field                   */
#define ENC_CTRL2_ROIE_MASK                      (0x40U)                                             /*!< ENC_CTRL2.ROIE Mask                     */
#define ENC_CTRL2_ROIE_SHIFT                     (6U)                                                /*!< ENC_CTRL2.ROIE Position                 */
#define ENC_CTRL2_ROIE(x)                        (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< ENC_CTRL2.ROIE Field                    */
#define ENC_CTRL2_ROIRQ_MASK                     (0x80U)                                             /*!< ENC_CTRL2.ROIRQ Mask                    */
#define ENC_CTRL2_ROIRQ_SHIFT                    (7U)                                                /*!< ENC_CTRL2.ROIRQ Position                */
#define ENC_CTRL2_ROIRQ(x)                       (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< ENC_CTRL2.ROIRQ Field                   */
#define ENC_CTRL2_REVMOD_MASK                    (0x100U)                                            /*!< ENC_CTRL2.REVMOD Mask                   */
#define ENC_CTRL2_REVMOD_SHIFT                   (8U)                                                /*!< ENC_CTRL2.REVMOD Position               */
#define ENC_CTRL2_REVMOD(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x100UL)         /*!< ENC_CTRL2.REVMOD Field                  */
#define ENC_CTRL2_OUTCTL_MASK                    (0x200U)                                            /*!< ENC_CTRL2.OUTCTL Mask                   */
#define ENC_CTRL2_OUTCTL_SHIFT                   (9U)                                                /*!< ENC_CTRL2.OUTCTL Position               */
#define ENC_CTRL2_OUTCTL(x)                      (((uint16_t)(((uint16_t)(x))<<9U))&0x200UL)         /*!< ENC_CTRL2.OUTCTL Field                  */
#define ENC_CTRL2_SABIE_MASK                     (0x400U)                                            /*!< ENC_CTRL2.SABIE Mask                    */
#define ENC_CTRL2_SABIE_SHIFT                    (10U)                                               /*!< ENC_CTRL2.SABIE Position                */
#define ENC_CTRL2_SABIE(x)                       (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< ENC_CTRL2.SABIE Field                   */
#define ENC_CTRL2_SABIRQ_MASK                    (0x800U)                                            /*!< ENC_CTRL2.SABIRQ Mask                   */
#define ENC_CTRL2_SABIRQ_SHIFT                   (11U)                                               /*!< ENC_CTRL2.SABIRQ Position               */
#define ENC_CTRL2_SABIRQ(x)                      (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< ENC_CTRL2.SABIRQ Field                  */
/* ------- UMOD Bit Fields                          ------ */
#define ENC_UMOD_MOD_MASK                        (0xFFFFU)                                           /*!< ENC_UMOD.MOD Mask                       */
#define ENC_UMOD_MOD_SHIFT                       (0U)                                                /*!< ENC_UMOD.MOD Position                   */
#define ENC_UMOD_MOD(x)                          (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_UMOD.MOD Field                      */
/* ------- LMOD Bit Fields                          ------ */
#define ENC_LMOD_MOD_MASK                        (0xFFFFU)                                           /*!< ENC_LMOD.MOD Mask                       */
#define ENC_LMOD_MOD_SHIFT                       (0U)                                                /*!< ENC_LMOD.MOD Position                   */
#define ENC_LMOD_MOD(x)                          (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_LMOD.MOD Field                      */
/* ------- UCOMP Bit Fields                         ------ */
#define ENC_UCOMP_COMP_MASK                      (0xFFFFU)                                           /*!< ENC_UCOMP.COMP Mask                     */
#define ENC_UCOMP_COMP_SHIFT                     (0U)                                                /*!< ENC_UCOMP.COMP Position                 */
#define ENC_UCOMP_COMP(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_UCOMP.COMP Field                    */
/* ------- LCOMP Bit Fields                         ------ */
#define ENC_LCOMP_COMP_MASK                      (0xFFFFU)                                           /*!< ENC_LCOMP.COMP Mask                     */
#define ENC_LCOMP_COMP_SHIFT                     (0U)                                                /*!< ENC_LCOMP.COMP Position                 */
#define ENC_LCOMP_COMP(x)                        (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< ENC_LCOMP.COMP Field                    */
/**
 * @} */ /* End group ENC_Register_Masks_GROUP 
 */

/* ENC - Peripheral instance base addresses */
#define ENC_BasePtr                    0x40055000UL //!< Peripheral base address
#define ENC                            ((ENC_Type *) ENC_BasePtr) //!< Freescale base pointer
#define ENC_BASE_PTR                   (ENC) //!< Freescale style base pointer
/**
 * @} */ /* End group ENC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup EWM_Peripheral_access_layer_GROUP EWM Peripheral Access Layer
* @brief C Struct for EWM
* @{
*/

/* ================================================================================ */
/* ================           EWM (file:EWM_2)                     ================ */
/* ================================================================================ */

/**
 * @brief External Watchdog Monitor
 */
/**
* @addtogroup EWM_structs_GROUP EWM struct
* @brief Struct for EWM
* @{
*/
typedef struct {                                /*       EWM Structure                                                */
   __IO uint8_t   CTRL;                         /**< 0000: Control Register                                             */
   __O  uint8_t   SERV;                         /**< 0001: Service Register                                             */
   __IO uint8_t   CMPL;                         /**< 0002: Compare Low Register                                         */
   __IO uint8_t   CMPH;                         /**< 0003: Compare High Register                                        */
} EWM_Type;

/**
 * @} */ /* End group EWM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'EWM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup EWM_Register_Masks_GROUP EWM Register Masks
* @brief Register Masks for EWM
* @{
*/
/* ------- CTRL Bit Fields                          ------ */
#define EWM_CTRL_EWMEN_MASK                      (0x1U)                                              /*!< EWM_CTRL.EWMEN Mask                     */
#define EWM_CTRL_EWMEN_SHIFT                     (0U)                                                /*!< EWM_CTRL.EWMEN Position                 */
#define EWM_CTRL_EWMEN(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< EWM_CTRL.EWMEN Field                    */
#define EWM_CTRL_ASSIN_MASK                      (0x2U)                                              /*!< EWM_CTRL.ASSIN Mask                     */
#define EWM_CTRL_ASSIN_SHIFT                     (1U)                                                /*!< EWM_CTRL.ASSIN Position                 */
#define EWM_CTRL_ASSIN(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< EWM_CTRL.ASSIN Field                    */
#define EWM_CTRL_INEN_MASK                       (0x4U)                                              /*!< EWM_CTRL.INEN Mask                      */
#define EWM_CTRL_INEN_SHIFT                      (2U)                                                /*!< EWM_CTRL.INEN Position                  */
#define EWM_CTRL_INEN(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< EWM_CTRL.INEN Field                     */
#define EWM_CTRL_INTEN_MASK                      (0x8U)                                              /*!< EWM_CTRL.INTEN Mask                     */
#define EWM_CTRL_INTEN_SHIFT                     (3U)                                                /*!< EWM_CTRL.INTEN Position                 */
#define EWM_CTRL_INTEN(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< EWM_CTRL.INTEN Field                    */
/* ------- SERV Bit Fields                          ------ */
#define EWM_SERV_SERVICE_MASK                    (0xFFU)                                             /*!< EWM_SERV.SERVICE Mask                   */
#define EWM_SERV_SERVICE_SHIFT                   (0U)                                                /*!< EWM_SERV.SERVICE Position               */
#define EWM_SERV_SERVICE(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< EWM_SERV.SERVICE Field                  */
/* ------- CMPL Bit Fields                          ------ */
#define EWM_CMPL_COMPAREL_MASK                   (0xFFU)                                             /*!< EWM_CMPL.COMPAREL Mask                  */
#define EWM_CMPL_COMPAREL_SHIFT                  (0U)                                                /*!< EWM_CMPL.COMPAREL Position              */
#define EWM_CMPL_COMPAREL(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< EWM_CMPL.COMPAREL Field                 */
/* ------- CMPH Bit Fields                          ------ */
#define EWM_CMPH_COMPAREH_MASK                   (0xFFU)                                             /*!< EWM_CMPH.COMPAREH Mask                  */
#define EWM_CMPH_COMPAREH_SHIFT                  (0U)                                                /*!< EWM_CMPH.COMPAREH Position              */
#define EWM_CMPH_COMPAREH(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< EWM_CMPH.COMPAREH Field                 */
/**
 * @} */ /* End group EWM_Register_Masks_GROUP 
 */

/* EWM - Peripheral instance base addresses */
#define EWM_BasePtr                    0x40061000UL //!< Peripheral base address
#define EWM                            ((EWM_Type *) EWM_BasePtr) //!< Freescale base pointer
#define EWM_BASE_PTR                   (EWM) //!< Freescale style base pointer
/**
 * @} */ /* End group EWM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FMC_Peripheral_access_layer_GROUP FMC Peripheral Access Layer
* @brief C Struct for FMC
* @{
*/

/* ================================================================================ */
/* ================           FMC (file:FMC_MKV40F15)              ================ */
/* ================================================================================ */

/**
 * @brief Flash Memory Controller
 */
/**
* @addtogroup FMC_structs_GROUP FMC struct
* @brief Struct for FMC
* @{
*/
typedef struct {                                /*       FMC Structure                                                */
   __IO uint32_t  PFAPR;                        /**< 0000: Flash Access Protection Register                             */
   __IO uint32_t  PFB0CR;                       /**< 0004: Flash Bank 0 Control Register                                */
   __I  uint32_t  PFB1CR;                       /**< 0008: Flash Bank 1 Control Register                                */
        uint8_t   RESERVED_0[244];             
   struct {
      __IO uint32_t  S0;                        /**< 0100: Cache Tag Storage                                            */
      __IO uint32_t  S1;                        /**< 0104: Cache Tag Storage                                            */
   } TAGVDW[4];                                 /**< 0100: (cluster: size=0x0020, 32)                                   */
        uint8_t   RESERVED_2[224];             
   struct {
      __IO uint32_t  S0UM;                      /**< 0200: Cache Data Storage (uppermost word)                          */
      __IO uint32_t  S0MU;                      /**< 0204: Cache Data Storage (mid-upper word)                          */
      __IO uint32_t  S0ML;                      /**< 0208: Cache Data Storage (mid-lower word)                          */
      __IO uint32_t  S0LM;                      /**< 020C: Cache Data Storage (lowermost word)                          */
      __IO uint32_t  S1UM;                      /**< 0210: Cache Data Storage (uppermost word)                          */
      __IO uint32_t  S1MU;                      /**< 0214: Cache Data Storage (mid-upper word)                          */
      __IO uint32_t  S1ML;                      /**< 0218: Cache Data Storage (mid-lower word)                          */
      __IO uint32_t  S1LM;                      /**< 021C: Cache Data Storage (lowermost word)                          */
           uint8_t   RESERVED_3[32];           
   } DATAW[4];                                  /**< 0200: (cluster: size=0x0100, 256)                                  */
} FMC_Type;

/**
 * @} */ /* End group FMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FMC_Register_Masks_GROUP FMC Register Masks
* @brief Register Masks for FMC
* @{
*/
/* ------- PFAPR Bit Fields                         ------ */
#define FMC_PFAPR_M0AP_MASK                      (0x3U)                                              /*!< FMC_PFAPR.M0AP Mask                     */
#define FMC_PFAPR_M0AP_SHIFT                     (0U)                                                /*!< FMC_PFAPR.M0AP Position                 */
#define FMC_PFAPR_M0AP(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< FMC_PFAPR.M0AP Field                    */
#define FMC_PFAPR_M1AP_MASK                      (0xCU)                                              /*!< FMC_PFAPR.M1AP Mask                     */
#define FMC_PFAPR_M1AP_SHIFT                     (2U)                                                /*!< FMC_PFAPR.M1AP Position                 */
#define FMC_PFAPR_M1AP(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< FMC_PFAPR.M1AP Field                    */
#define FMC_PFAPR_M2AP_MASK                      (0x30U)                                             /*!< FMC_PFAPR.M2AP Mask                     */
#define FMC_PFAPR_M2AP_SHIFT                     (4U)                                                /*!< FMC_PFAPR.M2AP Position                 */
#define FMC_PFAPR_M2AP(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< FMC_PFAPR.M2AP Field                    */
#define FMC_PFAPR_M0PFD_MASK                     (0x10000U)                                          /*!< FMC_PFAPR.M0PFD Mask                    */
#define FMC_PFAPR_M0PFD_SHIFT                    (16U)                                               /*!< FMC_PFAPR.M0PFD Position                */
#define FMC_PFAPR_M0PFD(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< FMC_PFAPR.M0PFD Field                   */
#define FMC_PFAPR_M1PFD_MASK                     (0x20000U)                                          /*!< FMC_PFAPR.M1PFD Mask                    */
#define FMC_PFAPR_M1PFD_SHIFT                    (17U)                                               /*!< FMC_PFAPR.M1PFD Position                */
#define FMC_PFAPR_M1PFD(x)                       (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< FMC_PFAPR.M1PFD Field                   */
#define FMC_PFAPR_M2PFD_MASK                     (0x40000U)                                          /*!< FMC_PFAPR.M2PFD Mask                    */
#define FMC_PFAPR_M2PFD_SHIFT                    (18U)                                               /*!< FMC_PFAPR.M2PFD Position                */
#define FMC_PFAPR_M2PFD(x)                       (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< FMC_PFAPR.M2PFD Field                   */
/* ------- PFB0CR Bit Fields                        ------ */
#define FMC_PFB0CR_B0SEBE_MASK                   (0x1U)                                              /*!< FMC_PFB0CR.B0SEBE Mask                  */
#define FMC_PFB0CR_B0SEBE_SHIFT                  (0U)                                                /*!< FMC_PFB0CR.B0SEBE Position              */
#define FMC_PFB0CR_B0SEBE(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FMC_PFB0CR.B0SEBE Field                 */
#define FMC_PFB0CR_B0IPE_MASK                    (0x2U)                                              /*!< FMC_PFB0CR.B0IPE Mask                   */
#define FMC_PFB0CR_B0IPE_SHIFT                   (1U)                                                /*!< FMC_PFB0CR.B0IPE Position               */
#define FMC_PFB0CR_B0IPE(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FMC_PFB0CR.B0IPE Field                  */
#define FMC_PFB0CR_B0DPE_MASK                    (0x4U)                                              /*!< FMC_PFB0CR.B0DPE Mask                   */
#define FMC_PFB0CR_B0DPE_SHIFT                   (2U)                                                /*!< FMC_PFB0CR.B0DPE Position               */
#define FMC_PFB0CR_B0DPE(x)                      (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FMC_PFB0CR.B0DPE Field                  */
#define FMC_PFB0CR_B0ICE_MASK                    (0x8U)                                              /*!< FMC_PFB0CR.B0ICE Mask                   */
#define FMC_PFB0CR_B0ICE_SHIFT                   (3U)                                                /*!< FMC_PFB0CR.B0ICE Position               */
#define FMC_PFB0CR_B0ICE(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FMC_PFB0CR.B0ICE Field                  */
#define FMC_PFB0CR_B0DCE_MASK                    (0x10U)                                             /*!< FMC_PFB0CR.B0DCE Mask                   */
#define FMC_PFB0CR_B0DCE_SHIFT                   (4U)                                                /*!< FMC_PFB0CR.B0DCE Position               */
#define FMC_PFB0CR_B0DCE(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FMC_PFB0CR.B0DCE Field                  */
#define FMC_PFB0CR_CRC_MASK                      (0xE0U)                                             /*!< FMC_PFB0CR.CRC Mask                     */
#define FMC_PFB0CR_CRC_SHIFT                     (5U)                                                /*!< FMC_PFB0CR.CRC Position                 */
#define FMC_PFB0CR_CRC(x)                        (((uint32_t)(((uint32_t)(x))<<5U))&0xE0UL)          /*!< FMC_PFB0CR.CRC Field                    */
#define FMC_PFB0CR_B0MW_MASK                     (0x60000U)                                          /*!< FMC_PFB0CR.B0MW Mask                    */
#define FMC_PFB0CR_B0MW_SHIFT                    (17U)                                               /*!< FMC_PFB0CR.B0MW Position                */
#define FMC_PFB0CR_B0MW(x)                       (((uint32_t)(((uint32_t)(x))<<17U))&0x60000UL)      /*!< FMC_PFB0CR.B0MW Field                   */
#define FMC_PFB0CR_S_B_INV_MASK                  (0x80000U)                                          /*!< FMC_PFB0CR.S_B_INV Mask                 */
#define FMC_PFB0CR_S_B_INV_SHIFT                 (19U)                                               /*!< FMC_PFB0CR.S_B_INV Position             */
#define FMC_PFB0CR_S_B_INV(x)                    (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< FMC_PFB0CR.S_B_INV Field                */
#define FMC_PFB0CR_CINV_WAY_MASK                 (0xF00000U)                                         /*!< FMC_PFB0CR.CINV_WAY Mask                */
#define FMC_PFB0CR_CINV_WAY_SHIFT                (20U)                                               /*!< FMC_PFB0CR.CINV_WAY Position            */
#define FMC_PFB0CR_CINV_WAY(x)                   (((uint32_t)(((uint32_t)(x))<<20U))&0xF00000UL)     /*!< FMC_PFB0CR.CINV_WAY Field               */
#define FMC_PFB0CR_CLCK_WAY_MASK                 (0xF000000U)                                        /*!< FMC_PFB0CR.CLCK_WAY Mask                */
#define FMC_PFB0CR_CLCK_WAY_SHIFT                (24U)                                               /*!< FMC_PFB0CR.CLCK_WAY Position            */
#define FMC_PFB0CR_CLCK_WAY(x)                   (((uint32_t)(((uint32_t)(x))<<24U))&0xF000000UL)    /*!< FMC_PFB0CR.CLCK_WAY Field               */
#define FMC_PFB0CR_B0RWSC_MASK                   (0xF0000000U)                                       /*!< FMC_PFB0CR.B0RWSC Mask                  */
#define FMC_PFB0CR_B0RWSC_SHIFT                  (28U)                                               /*!< FMC_PFB0CR.B0RWSC Position              */
#define FMC_PFB0CR_B0RWSC(x)                     (((uint32_t)(((uint32_t)(x))<<28U))&0xF0000000UL)   /*!< FMC_PFB0CR.B0RWSC Field                 */
/* ------- PFB1CR Bit Fields                        ------ */
/* ------- S0 Bit Fields                            ------ */
#define FMC_S0_valid_MASK                        (0x1U)                                              /*!< FMC_S0.valid Mask                       */
#define FMC_S0_valid_SHIFT                       (0U)                                                /*!< FMC_S0.valid Position                   */
#define FMC_S0_valid(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FMC_S0.valid Field                      */
#define FMC_S0_tag_MASK                          (0xFFFE0U)                                          /*!< FMC_S0.tag Mask                         */
#define FMC_S0_tag_SHIFT                         (5U)                                                /*!< FMC_S0.tag Position                     */
#define FMC_S0_tag(x)                            (((uint32_t)(((uint32_t)(x))<<5U))&0xFFFE0UL)       /*!< FMC_S0.tag Field                        */
/* ------- S1 Bit Fields                            ------ */
#define FMC_S1_valid_MASK                        (0x1U)                                              /*!< FMC_S1.valid Mask                       */
#define FMC_S1_valid_SHIFT                       (0U)                                                /*!< FMC_S1.valid Position                   */
#define FMC_S1_valid(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FMC_S1.valid Field                      */
#define FMC_S1_tag_MASK                          (0xFFFE0U)                                          /*!< FMC_S1.tag Mask                         */
#define FMC_S1_tag_SHIFT                         (5U)                                                /*!< FMC_S1.tag Position                     */
#define FMC_S1_tag(x)                            (((uint32_t)(((uint32_t)(x))<<5U))&0xFFFE0UL)       /*!< FMC_S1.tag Field                        */
/* ------- S0UM Bit Fields                          ------ */
#define FMC_S0UM_data_MASK                       (0xFFFFFFFFU)                                       /*!< FMC_S0UM.data Mask                      */
#define FMC_S0UM_data_SHIFT                      (0U)                                                /*!< FMC_S0UM.data Position                  */
#define FMC_S0UM_data(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FMC_S0UM.data Field                     */
/* ------- S0MU Bit Fields                          ------ */
#define FMC_S0MU_data_MASK                       (0xFFFFFFFFU)                                       /*!< FMC_S0MU.data Mask                      */
#define FMC_S0MU_data_SHIFT                      (0U)                                                /*!< FMC_S0MU.data Position                  */
#define FMC_S0MU_data(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FMC_S0MU.data Field                     */
/* ------- S0ML Bit Fields                          ------ */
#define FMC_S0ML_data_MASK                       (0xFFFFFFFFU)                                       /*!< FMC_S0ML.data Mask                      */
#define FMC_S0ML_data_SHIFT                      (0U)                                                /*!< FMC_S0ML.data Position                  */
#define FMC_S0ML_data(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FMC_S0ML.data Field                     */
/* ------- S0LM Bit Fields                          ------ */
#define FMC_S0LM_data_MASK                       (0xFFFFFFFFU)                                       /*!< FMC_S0LM.data Mask                      */
#define FMC_S0LM_data_SHIFT                      (0U)                                                /*!< FMC_S0LM.data Position                  */
#define FMC_S0LM_data(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FMC_S0LM.data Field                     */
/* ------- S1UM Bit Fields                          ------ */
#define FMC_S1UM_data_MASK                       (0xFFFFFFFFU)                                       /*!< FMC_S1UM.data Mask                      */
#define FMC_S1UM_data_SHIFT                      (0U)                                                /*!< FMC_S1UM.data Position                  */
#define FMC_S1UM_data(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FMC_S1UM.data Field                     */
/* ------- S1MU Bit Fields                          ------ */
#define FMC_S1MU_data_MASK                       (0xFFFFFFFFU)                                       /*!< FMC_S1MU.data Mask                      */
#define FMC_S1MU_data_SHIFT                      (0U)                                                /*!< FMC_S1MU.data Position                  */
#define FMC_S1MU_data(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FMC_S1MU.data Field                     */
/* ------- S1ML Bit Fields                          ------ */
#define FMC_S1ML_data_MASK                       (0xFFFFFFFFU)                                       /*!< FMC_S1ML.data Mask                      */
#define FMC_S1ML_data_SHIFT                      (0U)                                                /*!< FMC_S1ML.data Position                  */
#define FMC_S1ML_data(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FMC_S1ML.data Field                     */
/* ------- S1LM Bit Fields                          ------ */
#define FMC_S1LM_data_MASK                       (0xFFFFFFFFU)                                       /*!< FMC_S1LM.data Mask                      */
#define FMC_S1LM_data_SHIFT                      (0U)                                                /*!< FMC_S1LM.data Position                  */
#define FMC_S1LM_data(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< FMC_S1LM.data Field                     */
/**
 * @} */ /* End group FMC_Register_Masks_GROUP 
 */

/* FMC - Peripheral instance base addresses */
#define FMC_BasePtr                    0x4001F000UL //!< Peripheral base address
#define FMC                            ((FMC_Type *) FMC_BasePtr) //!< Freescale base pointer
#define FMC_BASE_PTR                   (FMC) //!< Freescale style base pointer
/**
 * @} */ /* End group FMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTFA_Peripheral_access_layer_GROUP FTFA Peripheral Access Layer
* @brief C Struct for FTFA
* @{
*/

/* ================================================================================ */
/* ================           FTFA (file:FTFA_XACCH)               ================ */
/* ================================================================================ */

/**
 * @brief Flash Memory Interface
 */
/**
* @addtogroup FTFA_structs_GROUP FTFA struct
* @brief Struct for FTFA
* @{
*/
typedef struct {                                /*       FTFA Structure                                               */
   __IO uint8_t   FSTAT;                        /**< 0000: Flash Status Register                                        */
   __IO uint8_t   FCNFG;                        /**< 0001: Flash Configuration Register                                 */
   __I  uint8_t   FSEC;                         /**< 0002: Flash Security Register                                      */
   __I  uint8_t   FOPT;                         /**< 0003: Flash Option Register                                        */
   __IO uint8_t   FCCOB3;                       /**< 0004: FCCOB 3 - Usually Flash address [7..0]                       */
   __IO uint8_t   FCCOB2;                       /**< 0005: FCCOB 2 - Usually Flash address [15..8]                      */
   __IO uint8_t   FCCOB1;                       /**< 0006: FCCOB 1 - Usually Flash address [23..16]                     */
   __IO uint8_t   FCCOB0;                       /**< 0007: FCCOB 0 - Usually FCMD (Flash command)                       */
   __IO uint8_t   FCCOB7;                       /**< 0008: FCCOB 7 - Usually Data Byte 3                                */
   __IO uint8_t   FCCOB6;                       /**< 0009: FCCOB 6 - Usually Data Byte 2                                */
   __IO uint8_t   FCCOB5;                       /**< 000A: FCCOB 5 - Usually Data Byte 1                                */
   __IO uint8_t   FCCOB4;                       /**< 000B: FCCOB 4 - Usually Data Byte 0                                */
   __IO uint8_t   FCCOBB;                       /**< 000C: FCCOB B - Usually Data Byte 7                                */
   __IO uint8_t   FCCOBA;                       /**< 000D: FCCOB A - Usually Data Byte 6                                */
   __IO uint8_t   FCCOB9;                       /**< 000E: FCCOB 9 - Usually Data Byte 5                                */
   __IO uint8_t   FCCOB8;                       /**< 000F: FCCOB 8 - Usually Data Byte 4                                */
   __IO uint8_t   FPROT3;                       /**< 0010: Program Flash Protection                                     */
   __IO uint8_t   FPROT2;                       /**< 0011: Program Flash Protection                                     */
   __IO uint8_t   FPROT1;                       /**< 0012: Program Flash Protection                                     */
   __IO uint8_t   FPROT0;                       /**< 0013: Program Flash Protection                                     */
        uint8_t   RESERVED_0[4];               
   __I  uint8_t   XACCH3;                       /**< 0018: Execute-only Access Registers (high)                         */
   __I  uint8_t   XACCH2;                       /**< 0019: Execute-only Access Registers (high)                         */
   __I  uint8_t   XACCH1;                       /**< 001A: Execute-only Access Registers (high)                         */
   __I  uint8_t   XACCH0;                       /**< 001B: Execute-only Access Registers (high)                         */
   __I  uint8_t   XACCL3;                       /**< 001C: Execute-only Access Registers (low)                          */
   __I  uint8_t   XACCL2;                       /**< 001D: Execute-only Access Registers (low)                          */
   __I  uint8_t   XACCL1;                       /**< 001E: Execute-only Access Registers (low)                          */
   __I  uint8_t   XACCL0;                       /**< 001F: Execute-only Access Registers (low)                          */
   __I  uint8_t   SACCH3;                       /**< 0020: Supervisor-only Access Registers (high)                      */
   __I  uint8_t   SACCH2;                       /**< 0021: Supervisor-only Access Registers (high)                      */
   __I  uint8_t   SACCH1;                       /**< 0022: Supervisor-only Access Registers (high)                      */
   __I  uint8_t   SACCH0;                       /**< 0023: Supervisor-only Access Registers (high)                      */
   __I  uint8_t   SACCL3;                       /**< 0024: Supervisor-only Access Registers (low)                       */
   __I  uint8_t   SACCL2;                       /**< 0025: Supervisor-only Access Registers (low)                       */
   __I  uint8_t   SACCL1;                       /**< 0026: Supervisor-only Access Registers (low)                       */
   __I  uint8_t   SACCL0;                       /**< 0027: Supervisor-only Access Registers (low)                       */
   __I  uint8_t   FACSS;                        /**< 0028: Flash Access Segment Size Register                           */
        uint8_t   RESERVED_1[2];               
   __I  uint8_t   FACSN;                        /**< 002B: Flash Access Segment Number Register                         */
} FTFA_Type;

/**
 * @} */ /* End group FTFA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTFA' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTFA_Register_Masks_GROUP FTFA Register Masks
* @brief Register Masks for FTFA
* @{
*/
/* ------- FSTAT Bit Fields                         ------ */
#define FTFA_FSTAT_MGSTAT0_MASK                  (0x1U)                                              /*!< FTFA_FSTAT.MGSTAT0 Mask                 */
#define FTFA_FSTAT_MGSTAT0_SHIFT                 (0U)                                                /*!< FTFA_FSTAT.MGSTAT0 Position             */
#define FTFA_FSTAT_MGSTAT0(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< FTFA_FSTAT.MGSTAT0 Field                */
#define FTFA_FSTAT_FPVIOL_MASK                   (0x10U)                                             /*!< FTFA_FSTAT.FPVIOL Mask                  */
#define FTFA_FSTAT_FPVIOL_SHIFT                  (4U)                                                /*!< FTFA_FSTAT.FPVIOL Position              */
#define FTFA_FSTAT_FPVIOL(x)                     (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< FTFA_FSTAT.FPVIOL Field                 */
#define FTFA_FSTAT_ACCERR_MASK                   (0x20U)                                             /*!< FTFA_FSTAT.ACCERR Mask                  */
#define FTFA_FSTAT_ACCERR_SHIFT                  (5U)                                                /*!< FTFA_FSTAT.ACCERR Position              */
#define FTFA_FSTAT_ACCERR(x)                     (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< FTFA_FSTAT.ACCERR Field                 */
#define FTFA_FSTAT_RDCOLERR_MASK                 (0x40U)                                             /*!< FTFA_FSTAT.RDCOLERR Mask                */
#define FTFA_FSTAT_RDCOLERR_SHIFT                (6U)                                                /*!< FTFA_FSTAT.RDCOLERR Position            */
#define FTFA_FSTAT_RDCOLERR(x)                   (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< FTFA_FSTAT.RDCOLERR Field               */
#define FTFA_FSTAT_CCIF_MASK                     (0x80U)                                             /*!< FTFA_FSTAT.CCIF Mask                    */
#define FTFA_FSTAT_CCIF_SHIFT                    (7U)                                                /*!< FTFA_FSTAT.CCIF Position                */
#define FTFA_FSTAT_CCIF(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< FTFA_FSTAT.CCIF Field                   */
/* ------- FCNFG Bit Fields                         ------ */
#define FTFA_FCNFG_ERSSUSP_MASK                  (0x10U)                                             /*!< FTFA_FCNFG.ERSSUSP Mask                 */
#define FTFA_FCNFG_ERSSUSP_SHIFT                 (4U)                                                /*!< FTFA_FCNFG.ERSSUSP Position             */
#define FTFA_FCNFG_ERSSUSP(x)                    (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< FTFA_FCNFG.ERSSUSP Field                */
#define FTFA_FCNFG_ERSAREQ_MASK                  (0x20U)                                             /*!< FTFA_FCNFG.ERSAREQ Mask                 */
#define FTFA_FCNFG_ERSAREQ_SHIFT                 (5U)                                                /*!< FTFA_FCNFG.ERSAREQ Position             */
#define FTFA_FCNFG_ERSAREQ(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< FTFA_FCNFG.ERSAREQ Field                */
#define FTFA_FCNFG_RDCOLLIE_MASK                 (0x40U)                                             /*!< FTFA_FCNFG.RDCOLLIE Mask                */
#define FTFA_FCNFG_RDCOLLIE_SHIFT                (6U)                                                /*!< FTFA_FCNFG.RDCOLLIE Position            */
#define FTFA_FCNFG_RDCOLLIE(x)                   (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< FTFA_FCNFG.RDCOLLIE Field               */
#define FTFA_FCNFG_CCIE_MASK                     (0x80U)                                             /*!< FTFA_FCNFG.CCIE Mask                    */
#define FTFA_FCNFG_CCIE_SHIFT                    (7U)                                                /*!< FTFA_FCNFG.CCIE Position                */
#define FTFA_FCNFG_CCIE(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< FTFA_FCNFG.CCIE Field                   */
/* ------- FSEC Bit Fields                          ------ */
#define FTFA_FSEC_SEC_MASK                       (0x3U)                                              /*!< FTFA_FSEC.SEC Mask                      */
#define FTFA_FSEC_SEC_SHIFT                      (0U)                                                /*!< FTFA_FSEC.SEC Position                  */
#define FTFA_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< FTFA_FSEC.SEC Field                     */
#define FTFA_FSEC_FSLACC_MASK                    (0xCU)                                              /*!< FTFA_FSEC.FSLACC Mask                   */
#define FTFA_FSEC_FSLACC_SHIFT                   (2U)                                                /*!< FTFA_FSEC.FSLACC Position               */
#define FTFA_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< FTFA_FSEC.FSLACC Field                  */
#define FTFA_FSEC_MEEN_MASK                      (0x30U)                                             /*!< FTFA_FSEC.MEEN Mask                     */
#define FTFA_FSEC_MEEN_SHIFT                     (4U)                                                /*!< FTFA_FSEC.MEEN Position                 */
#define FTFA_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< FTFA_FSEC.MEEN Field                    */
#define FTFA_FSEC_KEYEN_MASK                     (0xC0U)                                             /*!< FTFA_FSEC.KEYEN Mask                    */
#define FTFA_FSEC_KEYEN_SHIFT                    (6U)                                                /*!< FTFA_FSEC.KEYEN Position                */
#define FTFA_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< FTFA_FSEC.KEYEN Field                   */
/* ------- FOPT Bit Fields                          ------ */
#define FTFA_FOPT_OPT_MASK                       (0xFFU)                                             /*!< FTFA_FOPT.OPT Mask                      */
#define FTFA_FOPT_OPT_SHIFT                      (0U)                                                /*!< FTFA_FOPT.OPT Position                  */
#define FTFA_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_FOPT.OPT Field                     */
/* ------- FCCOB Bit Fields                         ------ */
#define FTFA_FCCOB_CCOBn_MASK                    (0xFFU)                                             /*!< FTFA_FCCOB.CCOBn Mask                   */
#define FTFA_FCCOB_CCOBn_SHIFT                   (0U)                                                /*!< FTFA_FCCOB.CCOBn Position               */
#define FTFA_FCCOB_CCOBn(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_FCCOB.CCOBn Field                  */
/* ------- FPROT Bit Fields                         ------ */
#define FTFA_FPROT_PROT_MASK                     (0xFFU)                                             /*!< FTFA_FPROT.PROT Mask                    */
#define FTFA_FPROT_PROT_SHIFT                    (0U)                                                /*!< FTFA_FPROT.PROT Position                */
#define FTFA_FPROT_PROT(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_FPROT.PROT Field                   */
/* ------- XACCH Bit Fields                         ------ */
#define FTFA_XACCH_XA_MASK                       (0xFFU)                                             /*!< FTFA_XACCH.XA Mask                      */
#define FTFA_XACCH_XA_SHIFT                      (0U)                                                /*!< FTFA_XACCH.XA Position                  */
#define FTFA_XACCH_XA(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_XACCH.XA Field                     */
/* ------- XACCL Bit Fields                         ------ */
#define FTFA_XACCL_XA_MASK                       (0xFFU)                                             /*!< FTFA_XACCL.XA Mask                      */
#define FTFA_XACCL_XA_SHIFT                      (0U)                                                /*!< FTFA_XACCL.XA Position                  */
#define FTFA_XACCL_XA(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_XACCL.XA Field                     */
/* ------- SACCH Bit Fields                         ------ */
#define FTFA_SACCH_SA_MASK                       (0xFFU)                                             /*!< FTFA_SACCH.SA Mask                      */
#define FTFA_SACCH_SA_SHIFT                      (0U)                                                /*!< FTFA_SACCH.SA Position                  */
#define FTFA_SACCH_SA(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_SACCH.SA Field                     */
/* ------- SACCL Bit Fields                         ------ */
#define FTFA_SACCL_SA_MASK                       (0xFFU)                                             /*!< FTFA_SACCL.SA Mask                      */
#define FTFA_SACCL_SA_SHIFT                      (0U)                                                /*!< FTFA_SACCL.SA Position                  */
#define FTFA_SACCL_SA(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_SACCL.SA Field                     */
/* ------- FACSS Bit Fields                         ------ */
#define FTFA_FACSS_SGSIZE_MASK                   (0xFFU)                                             /*!< FTFA_FACSS.SGSIZE Mask                  */
#define FTFA_FACSS_SGSIZE_SHIFT                  (0U)                                                /*!< FTFA_FACSS.SGSIZE Position              */
#define FTFA_FACSS_SGSIZE(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_FACSS.SGSIZE Field                 */
/* ------- FACSN Bit Fields                         ------ */
#define FTFA_FACSN_NUMSG_MASK                    (0xFFU)                                             /*!< FTFA_FACSN.NUMSG Mask                   */
#define FTFA_FACSN_NUMSG_SHIFT                   (0U)                                                /*!< FTFA_FACSN.NUMSG Position               */
#define FTFA_FACSN_NUMSG(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< FTFA_FACSN.NUMSG Field                  */
/**
 * @} */ /* End group FTFA_Register_Masks_GROUP 
 */

/* FTFA - Peripheral instance base addresses */
#define FTFA_BasePtr                   0x40020000UL //!< Peripheral base address
#define FTFA                           ((FTFA_Type *) FTFA_BasePtr) //!< Freescale base pointer
#define FTFA_BASE_PTR                  (FTFA) //!< Freescale style base pointer
/**
 * @} */ /* End group FTFA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM0 (file:FTM0_8CH_ICRST)           ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (8 channels)
 */
/**
* @addtogroup FTM_structs_GROUP FTM struct
* @brief Struct for FTM
* @{
*/
typedef struct {                                /*       FTM0 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel  Status and Control                                  */
      __IO uint32_t  CnV;                       /**< 0010: Channel  Value                                               */
   } CONTROLS[8];                               /**< 000C: (cluster: size=0x0040, 64)                                   */
   __IO uint32_t  CNTIN;                        /**< 004C: Counter Initial Value                                        */
   __IO uint32_t  STATUS;                       /**< 0050: Capture and Compare Status                                   */
   __IO uint32_t  MODE;                         /**< 0054: Features Mode Selection                                      */
   __IO uint32_t  SYNC;                         /**< 0058: Synchronization                                              */
   __IO uint32_t  OUTINIT;                      /**< 005C: Initial State for Channels Output                            */
   __IO uint32_t  OUTMASK;                      /**< 0060: Output Mask                                                  */
   __IO uint32_t  COMBINE;                      /**< 0064: Function for Linked Channels                                 */
   __IO uint32_t  DEADTIME;                     /**< 0068: Deadtime Insertion Control                                   */
   __IO uint32_t  EXTTRIG;                      /**< 006C: FTM External Trigger                                         */
   __IO uint32_t  POL;                          /**< 0070: Channels Polarity                                            */
   __IO uint32_t  FMS;                          /**< 0074: Fault Mode Status                                            */
   __IO uint32_t  FILTER;                       /**< 0078: Input Capture Filter Control                                 */
   __IO uint32_t  FLTCTRL;                      /**< 007C: Fault Control                                                */
   __IO uint32_t  QDCTRL;                       /**< 0080: Quadrature Decoder Control and Status                        */
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
   __IO uint32_t  FLTPOL;                       /**< 0088: FTM Fault Input Polarity                                     */
   __IO uint32_t  SYNCONF;                      /**< 008C: Synchronization Configuration                                */
   __IO uint32_t  INVCTRL;                      /**< 0090: FTM Inverting Control                                        */
   __IO uint32_t  SWOCTRL;                      /**< 0094: FTM Software Output Control                                  */
   __IO uint32_t  PWMLOAD;                      /**< 0098: FTM PWM Load                                                 */
} FTM_Type;

/**
 * @} */ /* End group FTM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTM0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTM_Register_Masks_GROUP FTM Register Masks
* @brief Register Masks for FTM
* @{
*/
/* ------- SC Bit Fields                            ------ */
#define FTM_SC_PS_MASK                           (0x7U)                                              /*!< FTM0_SC.PS Mask                         */
#define FTM_SC_PS_SHIFT                          (0U)                                                /*!< FTM0_SC.PS Position                     */
#define FTM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< FTM0_SC.PS Field                        */
#define FTM_SC_CLKS_MASK                         (0x18U)                                             /*!< FTM0_SC.CLKS Mask                       */
#define FTM_SC_CLKS_SHIFT                        (3U)                                                /*!< FTM0_SC.CLKS Position                   */
#define FTM_SC_CLKS(x)                           (((uint32_t)(((uint32_t)(x))<<3U))&0x18UL)          /*!< FTM0_SC.CLKS Field                      */
#define FTM_SC_CPWMS_MASK                        (0x20U)                                             /*!< FTM0_SC.CPWMS Mask                      */
#define FTM_SC_CPWMS_SHIFT                       (5U)                                                /*!< FTM0_SC.CPWMS Position                  */
#define FTM_SC_CPWMS(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_SC.CPWMS Field                     */
#define FTM_SC_TOIE_MASK                         (0x40U)                                             /*!< FTM0_SC.TOIE Mask                       */
#define FTM_SC_TOIE_SHIFT                        (6U)                                                /*!< FTM0_SC.TOIE Position                   */
#define FTM_SC_TOIE(x)                           (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FTM0_SC.TOIE Field                      */
#define FTM_SC_TOF_MASK                          (0x80U)                                             /*!< FTM0_SC.TOF Mask                        */
#define FTM_SC_TOF_SHIFT                         (7U)                                                /*!< FTM0_SC.TOF Position                    */
#define FTM_SC_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_SC.TOF Field                       */
/* ------- CNT Bit Fields                           ------ */
#define FTM_CNT_COUNT_MASK                       (0xFFFFU)                                           /*!< FTM0_CNT.COUNT Mask                     */
#define FTM_CNT_COUNT_SHIFT                      (0U)                                                /*!< FTM0_CNT.COUNT Position                 */
#define FTM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< FTM0_CNT.COUNT Field                    */
/* ------- MOD Bit Fields                           ------ */
#define FTM_MOD_MOD_MASK                         (0xFFFFU)                                           /*!< FTM0_MOD.MOD Mask                       */
#define FTM_MOD_MOD_SHIFT                        (0U)                                                /*!< FTM0_MOD.MOD Position                   */
#define FTM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< FTM0_MOD.MOD Field                      */
/* ------- CnSC Bit Fields                          ------ */
#define FTM_CnSC_DMA_MASK                        (0x1U)                                              /*!< FTM0_CnSC.DMA Mask                      */
#define FTM_CnSC_DMA_SHIFT                       (0U)                                                /*!< FTM0_CnSC.DMA Position                  */
#define FTM_CnSC_DMA(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_CnSC.DMA Field                     */
#define FTM_CnSC_ICRST_MASK                      (0x2U)                                              /*!< FTM0_CnSC.ICRST Mask                    */
#define FTM_CnSC_ICRST_SHIFT                     (1U)                                                /*!< FTM0_CnSC.ICRST Position                */
#define FTM_CnSC_ICRST(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_CnSC.ICRST Field                   */
#define FTM_CnSC_ELS_MASK                        (0xCU)                                              /*!< FTM0_CnSC.ELS Mask                      */
#define FTM_CnSC_ELS_SHIFT                       (2U)                                                /*!< FTM0_CnSC.ELS Position                  */
#define FTM_CnSC_ELS(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< FTM0_CnSC.ELS Field                     */
#define FTM_CnSC_ELSA_MASK                       (0x4U)                                              /*!< FTM0_CnSC.ELSA Mask                     */
#define FTM_CnSC_ELSA_SHIFT                      (2U)                                                /*!< FTM0_CnSC.ELSA Position                 */
#define FTM_CnSC_ELSA(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_CnSC.ELSA Field                    */
#define FTM_CnSC_ELSB_MASK                       (0x8U)                                              /*!< FTM0_CnSC.ELSB Mask                     */
#define FTM_CnSC_ELSB_SHIFT                      (3U)                                                /*!< FTM0_CnSC.ELSB Position                 */
#define FTM_CnSC_ELSB(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_CnSC.ELSB Field                    */
#define FTM_CnSC_MS_MASK                         (0x30U)                                             /*!< FTM0_CnSC.MS Mask                       */
#define FTM_CnSC_MS_SHIFT                        (4U)                                                /*!< FTM0_CnSC.MS Position                   */
#define FTM_CnSC_MS(x)                           (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< FTM0_CnSC.MS Field                      */
#define FTM_CnSC_MSA_MASK                        (0x10U)                                             /*!< FTM0_CnSC.MSA Mask                      */
#define FTM_CnSC_MSA_SHIFT                       (4U)                                                /*!< FTM0_CnSC.MSA Position                  */
#define FTM_CnSC_MSA(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FTM0_CnSC.MSA Field                     */
#define FTM_CnSC_MSB_MASK                        (0x20U)                                             /*!< FTM0_CnSC.MSB Mask                      */
#define FTM_CnSC_MSB_SHIFT                       (5U)                                                /*!< FTM0_CnSC.MSB Position                  */
#define FTM_CnSC_MSB(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_CnSC.MSB Field                     */
#define FTM_CnSC_CHIE_MASK                       (0x40U)                                             /*!< FTM0_CnSC.CHIE Mask                     */
#define FTM_CnSC_CHIE_SHIFT                      (6U)                                                /*!< FTM0_CnSC.CHIE Position                 */
#define FTM_CnSC_CHIE(x)                         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FTM0_CnSC.CHIE Field                    */
#define FTM_CnSC_CHF_MASK                        (0x80U)                                             /*!< FTM0_CnSC.CHF Mask                      */
#define FTM_CnSC_CHF_SHIFT                       (7U)                                                /*!< FTM0_CnSC.CHF Position                  */
#define FTM_CnSC_CHF(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_CnSC.CHF Field                     */
/* ------- CnV Bit Fields                           ------ */
#define FTM_CnV_VAL_MASK                         (0xFFFFU)                                           /*!< FTM0_CnV.VAL Mask                       */
#define FTM_CnV_VAL_SHIFT                        (0U)                                                /*!< FTM0_CnV.VAL Position                   */
#define FTM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< FTM0_CnV.VAL Field                      */
/* ------- CNTIN Bit Fields                         ------ */
#define FTM_CNTIN_INIT_MASK                      (0xFFFFU)                                           /*!< FTM0_CNTIN.INIT Mask                    */
#define FTM_CNTIN_INIT_SHIFT                     (0U)                                                /*!< FTM0_CNTIN.INIT Position                */
#define FTM_CNTIN_INIT(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< FTM0_CNTIN.INIT Field                   */
/* ------- STATUS Bit Fields                        ------ */
#define FTM_STATUS_CH0F_MASK                     (0x1U)                                              /*!< FTM0_STATUS.CH0F Mask                   */
#define FTM_STATUS_CH0F_SHIFT                    (0U)                                                /*!< FTM0_STATUS.CH0F Position               */
#define FTM_STATUS_CH0F(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_STATUS.CH0F Field                  */
#define FTM_STATUS_CH1F_MASK                     (0x2U)                                              /*!< FTM0_STATUS.CH1F Mask                   */
#define FTM_STATUS_CH1F_SHIFT                    (1U)                                                /*!< FTM0_STATUS.CH1F Position               */
#define FTM_STATUS_CH1F(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_STATUS.CH1F Field                  */
#define FTM_STATUS_CH2F_MASK                     (0x4U)                                              /*!< FTM0_STATUS.CH2F Mask                   */
#define FTM_STATUS_CH2F_SHIFT                    (2U)                                                /*!< FTM0_STATUS.CH2F Position               */
#define FTM_STATUS_CH2F(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_STATUS.CH2F Field                  */
#define FTM_STATUS_CH3F_MASK                     (0x8U)                                              /*!< FTM0_STATUS.CH3F Mask                   */
#define FTM_STATUS_CH3F_SHIFT                    (3U)                                                /*!< FTM0_STATUS.CH3F Position               */
#define FTM_STATUS_CH3F(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_STATUS.CH3F Field                  */
#define FTM_STATUS_CH4F_MASK                     (0x10U)                                             /*!< FTM0_STATUS.CH4F Mask                   */
#define FTM_STATUS_CH4F_SHIFT                    (4U)                                                /*!< FTM0_STATUS.CH4F Position               */
#define FTM_STATUS_CH4F(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FTM0_STATUS.CH4F Field                  */
#define FTM_STATUS_CH5F_MASK                     (0x20U)                                             /*!< FTM0_STATUS.CH5F Mask                   */
#define FTM_STATUS_CH5F_SHIFT                    (5U)                                                /*!< FTM0_STATUS.CH5F Position               */
#define FTM_STATUS_CH5F(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_STATUS.CH5F Field                  */
#define FTM_STATUS_CH6F_MASK                     (0x40U)                                             /*!< FTM0_STATUS.CH6F Mask                   */
#define FTM_STATUS_CH6F_SHIFT                    (6U)                                                /*!< FTM0_STATUS.CH6F Position               */
#define FTM_STATUS_CH6F(x)                       (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FTM0_STATUS.CH6F Field                  */
#define FTM_STATUS_CH7F_MASK                     (0x80U)                                             /*!< FTM0_STATUS.CH7F Mask                   */
#define FTM_STATUS_CH7F_SHIFT                    (7U)                                                /*!< FTM0_STATUS.CH7F Position               */
#define FTM_STATUS_CH7F(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_STATUS.CH7F Field                  */
/* ------- MODE Bit Fields                          ------ */
#define FTM_MODE_FTMEN_MASK                      (0x1U)                                              /*!< FTM0_MODE.FTMEN Mask                    */
#define FTM_MODE_FTMEN_SHIFT                     (0U)                                                /*!< FTM0_MODE.FTMEN Position                */
#define FTM_MODE_FTMEN(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_MODE.FTMEN Field                   */
#define FTM_MODE_INIT_MASK                       (0x2U)                                              /*!< FTM0_MODE.INIT Mask                     */
#define FTM_MODE_INIT_SHIFT                      (1U)                                                /*!< FTM0_MODE.INIT Position                 */
#define FTM_MODE_INIT(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_MODE.INIT Field                    */
#define FTM_MODE_WPDIS_MASK                      (0x4U)                                              /*!< FTM0_MODE.WPDIS Mask                    */
#define FTM_MODE_WPDIS_SHIFT                     (2U)                                                /*!< FTM0_MODE.WPDIS Position                */
#define FTM_MODE_WPDIS(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_MODE.WPDIS Field                   */
#define FTM_MODE_PWMSYNC_MASK                    (0x8U)                                              /*!< FTM0_MODE.PWMSYNC Mask                  */
#define FTM_MODE_PWMSYNC_SHIFT                   (3U)                                                /*!< FTM0_MODE.PWMSYNC Position              */
#define FTM_MODE_PWMSYNC(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_MODE.PWMSYNC Field                 */
#define FTM_MODE_CAPTEST_MASK                    (0x10U)                                             /*!< FTM0_MODE.CAPTEST Mask                  */
#define FTM_MODE_CAPTEST_SHIFT                   (4U)                                                /*!< FTM0_MODE.CAPTEST Position              */
#define FTM_MODE_CAPTEST(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FTM0_MODE.CAPTEST Field                 */
#define FTM_MODE_FAULTM_MASK                     (0x60U)                                             /*!< FTM0_MODE.FAULTM Mask                   */
#define FTM_MODE_FAULTM_SHIFT                    (5U)                                                /*!< FTM0_MODE.FAULTM Position               */
#define FTM_MODE_FAULTM(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x60UL)          /*!< FTM0_MODE.FAULTM Field                  */
#define FTM_MODE_FAULTIE_MASK                    (0x80U)                                             /*!< FTM0_MODE.FAULTIE Mask                  */
#define FTM_MODE_FAULTIE_SHIFT                   (7U)                                                /*!< FTM0_MODE.FAULTIE Position              */
#define FTM_MODE_FAULTIE(x)                      (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_MODE.FAULTIE Field                 */
/* ------- SYNC Bit Fields                          ------ */
#define FTM_SYNC_CNTMIN_MASK                     (0x1U)                                              /*!< FTM0_SYNC.CNTMIN Mask                   */
#define FTM_SYNC_CNTMIN_SHIFT                    (0U)                                                /*!< FTM0_SYNC.CNTMIN Position               */
#define FTM_SYNC_CNTMIN(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_SYNC.CNTMIN Field                  */
#define FTM_SYNC_CNTMAX_MASK                     (0x2U)                                              /*!< FTM0_SYNC.CNTMAX Mask                   */
#define FTM_SYNC_CNTMAX_SHIFT                    (1U)                                                /*!< FTM0_SYNC.CNTMAX Position               */
#define FTM_SYNC_CNTMAX(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_SYNC.CNTMAX Field                  */
#define FTM_SYNC_REINIT_MASK                     (0x4U)                                              /*!< FTM0_SYNC.REINIT Mask                   */
#define FTM_SYNC_REINIT_SHIFT                    (2U)                                                /*!< FTM0_SYNC.REINIT Position               */
#define FTM_SYNC_REINIT(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_SYNC.REINIT Field                  */
#define FTM_SYNC_SYNCHOM_MASK                    (0x8U)                                              /*!< FTM0_SYNC.SYNCHOM Mask                  */
#define FTM_SYNC_SYNCHOM_SHIFT                   (3U)                                                /*!< FTM0_SYNC.SYNCHOM Position              */
#define FTM_SYNC_SYNCHOM(x)                      (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_SYNC.SYNCHOM Field                 */
#define FTM_SYNC_TRIG0_MASK                      (0x10U)                                             /*!< FTM0_SYNC.TRIG0 Mask                    */
#define FTM_SYNC_TRIG0_SHIFT                     (4U)                                                /*!< FTM0_SYNC.TRIG0 Position                */
#define FTM_SYNC_TRIG0(x)                        (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FTM0_SYNC.TRIG0 Field                   */
#define FTM_SYNC_TRIG1_MASK                      (0x20U)                                             /*!< FTM0_SYNC.TRIG1 Mask                    */
#define FTM_SYNC_TRIG1_SHIFT                     (5U)                                                /*!< FTM0_SYNC.TRIG1 Position                */
#define FTM_SYNC_TRIG1(x)                        (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_SYNC.TRIG1 Field                   */
#define FTM_SYNC_TRIG2_MASK                      (0x40U)                                             /*!< FTM0_SYNC.TRIG2 Mask                    */
#define FTM_SYNC_TRIG2_SHIFT                     (6U)                                                /*!< FTM0_SYNC.TRIG2 Position                */
#define FTM_SYNC_TRIG2(x)                        (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FTM0_SYNC.TRIG2 Field                   */
#define FTM_SYNC_SWSYNC_MASK                     (0x80U)                                             /*!< FTM0_SYNC.SWSYNC Mask                   */
#define FTM_SYNC_SWSYNC_SHIFT                    (7U)                                                /*!< FTM0_SYNC.SWSYNC Position               */
#define FTM_SYNC_SWSYNC(x)                       (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_SYNC.SWSYNC Field                  */
/* ------- OUTINIT Bit Fields                       ------ */
#define FTM_OUTINIT_CH0OI_MASK                   (0x1U)                                              /*!< FTM0_OUTINIT.CH0OI Mask                 */
#define FTM_OUTINIT_CH0OI_SHIFT                  (0U)                                                /*!< FTM0_OUTINIT.CH0OI Position             */
#define FTM_OUTINIT_CH0OI(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_OUTINIT.CH0OI Field                */
#define FTM_OUTINIT_CH1OI_MASK                   (0x2U)                                              /*!< FTM0_OUTINIT.CH1OI Mask                 */
#define FTM_OUTINIT_CH1OI_SHIFT                  (1U)                                                /*!< FTM0_OUTINIT.CH1OI Position             */
#define FTM_OUTINIT_CH1OI(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_OUTINIT.CH1OI Field                */
#define FTM_OUTINIT_CH2OI_MASK                   (0x4U)                                              /*!< FTM0_OUTINIT.CH2OI Mask                 */
#define FTM_OUTINIT_CH2OI_SHIFT                  (2U)                                                /*!< FTM0_OUTINIT.CH2OI Position             */
#define FTM_OUTINIT_CH2OI(x)                     (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_OUTINIT.CH2OI Field                */
#define FTM_OUTINIT_CH3OI_MASK                   (0x8U)                                              /*!< FTM0_OUTINIT.CH3OI Mask                 */
#define FTM_OUTINIT_CH3OI_SHIFT                  (3U)                                                /*!< FTM0_OUTINIT.CH3OI Position             */
#define FTM_OUTINIT_CH3OI(x)                     (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_OUTINIT.CH3OI Field                */
#define FTM_OUTINIT_CH4OI_MASK                   (0x10U)                                             /*!< FTM0_OUTINIT.CH4OI Mask                 */
#define FTM_OUTINIT_CH4OI_SHIFT                  (4U)                                                /*!< FTM0_OUTINIT.CH4OI Position             */
#define FTM_OUTINIT_CH4OI(x)                     (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FTM0_OUTINIT.CH4OI Field                */
#define FTM_OUTINIT_CH5OI_MASK                   (0x20U)                                             /*!< FTM0_OUTINIT.CH5OI Mask                 */
#define FTM_OUTINIT_CH5OI_SHIFT                  (5U)                                                /*!< FTM0_OUTINIT.CH5OI Position             */
#define FTM_OUTINIT_CH5OI(x)                     (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_OUTINIT.CH5OI Field                */
#define FTM_OUTINIT_CH6OI_MASK                   (0x40U)                                             /*!< FTM0_OUTINIT.CH6OI Mask                 */
#define FTM_OUTINIT_CH6OI_SHIFT                  (6U)                                                /*!< FTM0_OUTINIT.CH6OI Position             */
#define FTM_OUTINIT_CH6OI(x)                     (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FTM0_OUTINIT.CH6OI Field                */
#define FTM_OUTINIT_CH7OI_MASK                   (0x80U)                                             /*!< FTM0_OUTINIT.CH7OI Mask                 */
#define FTM_OUTINIT_CH7OI_SHIFT                  (7U)                                                /*!< FTM0_OUTINIT.CH7OI Position             */
#define FTM_OUTINIT_CH7OI(x)                     (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_OUTINIT.CH7OI Field                */
/* ------- OUTMASK Bit Fields                       ------ */
#define FTM_OUTMASK_CH0OM_MASK                   (0x1U)                                              /*!< FTM0_OUTMASK.CH0OM Mask                 */
#define FTM_OUTMASK_CH0OM_SHIFT                  (0U)                                                /*!< FTM0_OUTMASK.CH0OM Position             */
#define FTM_OUTMASK_CH0OM(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_OUTMASK.CH0OM Field                */
#define FTM_OUTMASK_CH1OM_MASK                   (0x2U)                                              /*!< FTM0_OUTMASK.CH1OM Mask                 */
#define FTM_OUTMASK_CH1OM_SHIFT                  (1U)                                                /*!< FTM0_OUTMASK.CH1OM Position             */
#define FTM_OUTMASK_CH1OM(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_OUTMASK.CH1OM Field                */
#define FTM_OUTMASK_CH2OM_MASK                   (0x4U)                                              /*!< FTM0_OUTMASK.CH2OM Mask                 */
#define FTM_OUTMASK_CH2OM_SHIFT                  (2U)                                                /*!< FTM0_OUTMASK.CH2OM Position             */
#define FTM_OUTMASK_CH2OM(x)                     (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_OUTMASK.CH2OM Field                */
#define FTM_OUTMASK_CH3OM_MASK                   (0x8U)                                              /*!< FTM0_OUTMASK.CH3OM Mask                 */
#define FTM_OUTMASK_CH3OM_SHIFT                  (3U)                                                /*!< FTM0_OUTMASK.CH3OM Position             */
#define FTM_OUTMASK_CH3OM(x)                     (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_OUTMASK.CH3OM Field                */
#define FTM_OUTMASK_CH4OM_MASK                   (0x10U)                                             /*!< FTM0_OUTMASK.CH4OM Mask                 */
#define FTM_OUTMASK_CH4OM_SHIFT                  (4U)                                                /*!< FTM0_OUTMASK.CH4OM Position             */
#define FTM_OUTMASK_CH4OM(x)                     (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FTM0_OUTMASK.CH4OM Field                */
#define FTM_OUTMASK_CH5OM_MASK                   (0x20U)                                             /*!< FTM0_OUTMASK.CH5OM Mask                 */
#define FTM_OUTMASK_CH5OM_SHIFT                  (5U)                                                /*!< FTM0_OUTMASK.CH5OM Position             */
#define FTM_OUTMASK_CH5OM(x)                     (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_OUTMASK.CH5OM Field                */
#define FTM_OUTMASK_CH6OM_MASK                   (0x40U)                                             /*!< FTM0_OUTMASK.CH6OM Mask                 */
#define FTM_OUTMASK_CH6OM_SHIFT                  (6U)                                                /*!< FTM0_OUTMASK.CH6OM Position             */
#define FTM_OUTMASK_CH6OM(x)                     (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FTM0_OUTMASK.CH6OM Field                */
#define FTM_OUTMASK_CH7OM_MASK                   (0x80U)                                             /*!< FTM0_OUTMASK.CH7OM Mask                 */
#define FTM_OUTMASK_CH7OM_SHIFT                  (7U)                                                /*!< FTM0_OUTMASK.CH7OM Position             */
#define FTM_OUTMASK_CH7OM(x)                     (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_OUTMASK.CH7OM Field                */
/* ------- COMBINE Bit Fields                       ------ */
#define FTM_COMBINE_COMBINE0_MASK                (0x1U)                                              /*!< FTM0_COMBINE.COMBINE0 Mask              */
#define FTM_COMBINE_COMBINE0_SHIFT               (0U)                                                /*!< FTM0_COMBINE.COMBINE0 Position          */
#define FTM_COMBINE_COMBINE0(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_COMBINE.COMBINE0 Field             */
#define FTM_COMBINE_COMP0_MASK                   (0x2U)                                              /*!< FTM0_COMBINE.COMP0 Mask                 */
#define FTM_COMBINE_COMP0_SHIFT                  (1U)                                                /*!< FTM0_COMBINE.COMP0 Position             */
#define FTM_COMBINE_COMP0(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_COMBINE.COMP0 Field                */
#define FTM_COMBINE_DECAPEN0_MASK                (0x4U)                                              /*!< FTM0_COMBINE.DECAPEN0 Mask              */
#define FTM_COMBINE_DECAPEN0_SHIFT               (2U)                                                /*!< FTM0_COMBINE.DECAPEN0 Position          */
#define FTM_COMBINE_DECAPEN0(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_COMBINE.DECAPEN0 Field             */
#define FTM_COMBINE_DECAP0_MASK                  (0x8U)                                              /*!< FTM0_COMBINE.DECAP0 Mask                */
#define FTM_COMBINE_DECAP0_SHIFT                 (3U)                                                /*!< FTM0_COMBINE.DECAP0 Position            */
#define FTM_COMBINE_DECAP0(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_COMBINE.DECAP0 Field               */
#define FTM_COMBINE_DTEN0_MASK                   (0x10U)                                             /*!< FTM0_COMBINE.DTEN0 Mask                 */
#define FTM_COMBINE_DTEN0_SHIFT                  (4U)                                                /*!< FTM0_COMBINE.DTEN0 Position             */
#define FTM_COMBINE_DTEN0(x)                     (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FTM0_COMBINE.DTEN0 Field                */
#define FTM_COMBINE_SYNCEN0_MASK                 (0x20U)                                             /*!< FTM0_COMBINE.SYNCEN0 Mask               */
#define FTM_COMBINE_SYNCEN0_SHIFT                (5U)                                                /*!< FTM0_COMBINE.SYNCEN0 Position           */
#define FTM_COMBINE_SYNCEN0(x)                   (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_COMBINE.SYNCEN0 Field              */
#define FTM_COMBINE_FAULTEN0_MASK                (0x40U)                                             /*!< FTM0_COMBINE.FAULTEN0 Mask              */
#define FTM_COMBINE_FAULTEN0_SHIFT               (6U)                                                /*!< FTM0_COMBINE.FAULTEN0 Position          */
#define FTM_COMBINE_FAULTEN0(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FTM0_COMBINE.FAULTEN0 Field             */
#define FTM_COMBINE_COMBINE1_MASK                (0x100U)                                            /*!< FTM0_COMBINE.COMBINE1 Mask              */
#define FTM_COMBINE_COMBINE1_SHIFT               (8U)                                                /*!< FTM0_COMBINE.COMBINE1 Position          */
#define FTM_COMBINE_COMBINE1(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< FTM0_COMBINE.COMBINE1 Field             */
#define FTM_COMBINE_COMP1_MASK                   (0x200U)                                            /*!< FTM0_COMBINE.COMP1 Mask                 */
#define FTM_COMBINE_COMP1_SHIFT                  (9U)                                                /*!< FTM0_COMBINE.COMP1 Position             */
#define FTM_COMBINE_COMP1(x)                     (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< FTM0_COMBINE.COMP1 Field                */
#define FTM_COMBINE_DECAPEN1_MASK                (0x400U)                                            /*!< FTM0_COMBINE.DECAPEN1 Mask              */
#define FTM_COMBINE_DECAPEN1_SHIFT               (10U)                                               /*!< FTM0_COMBINE.DECAPEN1 Position          */
#define FTM_COMBINE_DECAPEN1(x)                  (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< FTM0_COMBINE.DECAPEN1 Field             */
#define FTM_COMBINE_DECAP1_MASK                  (0x800U)                                            /*!< FTM0_COMBINE.DECAP1 Mask                */
#define FTM_COMBINE_DECAP1_SHIFT                 (11U)                                               /*!< FTM0_COMBINE.DECAP1 Position            */
#define FTM_COMBINE_DECAP1(x)                    (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< FTM0_COMBINE.DECAP1 Field               */
#define FTM_COMBINE_DTEN1_MASK                   (0x1000U)                                           /*!< FTM0_COMBINE.DTEN1 Mask                 */
#define FTM_COMBINE_DTEN1_SHIFT                  (12U)                                               /*!< FTM0_COMBINE.DTEN1 Position             */
#define FTM_COMBINE_DTEN1(x)                     (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< FTM0_COMBINE.DTEN1 Field                */
#define FTM_COMBINE_SYNCEN1_MASK                 (0x2000U)                                           /*!< FTM0_COMBINE.SYNCEN1 Mask               */
#define FTM_COMBINE_SYNCEN1_SHIFT                (13U)                                               /*!< FTM0_COMBINE.SYNCEN1 Position           */
#define FTM_COMBINE_SYNCEN1(x)                   (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< FTM0_COMBINE.SYNCEN1 Field              */
#define FTM_COMBINE_FAULTEN1_MASK                (0x4000U)                                           /*!< FTM0_COMBINE.FAULTEN1 Mask              */
#define FTM_COMBINE_FAULTEN1_SHIFT               (14U)                                               /*!< FTM0_COMBINE.FAULTEN1 Position          */
#define FTM_COMBINE_FAULTEN1(x)                  (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< FTM0_COMBINE.FAULTEN1 Field             */
#define FTM_COMBINE_COMBINE2_MASK                (0x10000U)                                          /*!< FTM0_COMBINE.COMBINE2 Mask              */
#define FTM_COMBINE_COMBINE2_SHIFT               (16U)                                               /*!< FTM0_COMBINE.COMBINE2 Position          */
#define FTM_COMBINE_COMBINE2(x)                  (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< FTM0_COMBINE.COMBINE2 Field             */
#define FTM_COMBINE_COMP2_MASK                   (0x20000U)                                          /*!< FTM0_COMBINE.COMP2 Mask                 */
#define FTM_COMBINE_COMP2_SHIFT                  (17U)                                               /*!< FTM0_COMBINE.COMP2 Position             */
#define FTM_COMBINE_COMP2(x)                     (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< FTM0_COMBINE.COMP2 Field                */
#define FTM_COMBINE_DECAPEN2_MASK                (0x40000U)                                          /*!< FTM0_COMBINE.DECAPEN2 Mask              */
#define FTM_COMBINE_DECAPEN2_SHIFT               (18U)                                               /*!< FTM0_COMBINE.DECAPEN2 Position          */
#define FTM_COMBINE_DECAPEN2(x)                  (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< FTM0_COMBINE.DECAPEN2 Field             */
#define FTM_COMBINE_DECAP2_MASK                  (0x80000U)                                          /*!< FTM0_COMBINE.DECAP2 Mask                */
#define FTM_COMBINE_DECAP2_SHIFT                 (19U)                                               /*!< FTM0_COMBINE.DECAP2 Position            */
#define FTM_COMBINE_DECAP2(x)                    (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< FTM0_COMBINE.DECAP2 Field               */
#define FTM_COMBINE_DTEN2_MASK                   (0x100000U)                                         /*!< FTM0_COMBINE.DTEN2 Mask                 */
#define FTM_COMBINE_DTEN2_SHIFT                  (20U)                                               /*!< FTM0_COMBINE.DTEN2 Position             */
#define FTM_COMBINE_DTEN2(x)                     (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< FTM0_COMBINE.DTEN2 Field                */
#define FTM_COMBINE_SYNCEN2_MASK                 (0x200000U)                                         /*!< FTM0_COMBINE.SYNCEN2 Mask               */
#define FTM_COMBINE_SYNCEN2_SHIFT                (21U)                                               /*!< FTM0_COMBINE.SYNCEN2 Position           */
#define FTM_COMBINE_SYNCEN2(x)                   (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< FTM0_COMBINE.SYNCEN2 Field              */
#define FTM_COMBINE_FAULTEN2_MASK                (0x400000U)                                         /*!< FTM0_COMBINE.FAULTEN2 Mask              */
#define FTM_COMBINE_FAULTEN2_SHIFT               (22U)                                               /*!< FTM0_COMBINE.FAULTEN2 Position          */
#define FTM_COMBINE_FAULTEN2(x)                  (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< FTM0_COMBINE.FAULTEN2 Field             */
#define FTM_COMBINE_COMBINE3_MASK                (0x1000000U)                                        /*!< FTM0_COMBINE.COMBINE3 Mask              */
#define FTM_COMBINE_COMBINE3_SHIFT               (24U)                                               /*!< FTM0_COMBINE.COMBINE3 Position          */
#define FTM_COMBINE_COMBINE3(x)                  (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< FTM0_COMBINE.COMBINE3 Field             */
#define FTM_COMBINE_COMP3_MASK                   (0x2000000U)                                        /*!< FTM0_COMBINE.COMP3 Mask                 */
#define FTM_COMBINE_COMP3_SHIFT                  (25U)                                               /*!< FTM0_COMBINE.COMP3 Position             */
#define FTM_COMBINE_COMP3(x)                     (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< FTM0_COMBINE.COMP3 Field                */
#define FTM_COMBINE_DECAPEN3_MASK                (0x4000000U)                                        /*!< FTM0_COMBINE.DECAPEN3 Mask              */
#define FTM_COMBINE_DECAPEN3_SHIFT               (26U)                                               /*!< FTM0_COMBINE.DECAPEN3 Position          */
#define FTM_COMBINE_DECAPEN3(x)                  (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< FTM0_COMBINE.DECAPEN3 Field             */
#define FTM_COMBINE_DECAP3_MASK                  (0x8000000U)                                        /*!< FTM0_COMBINE.DECAP3 Mask                */
#define FTM_COMBINE_DECAP3_SHIFT                 (27U)                                               /*!< FTM0_COMBINE.DECAP3 Position            */
#define FTM_COMBINE_DECAP3(x)                    (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< FTM0_COMBINE.DECAP3 Field               */
#define FTM_COMBINE_DTEN3_MASK                   (0x10000000U)                                       /*!< FTM0_COMBINE.DTEN3 Mask                 */
#define FTM_COMBINE_DTEN3_SHIFT                  (28U)                                               /*!< FTM0_COMBINE.DTEN3 Position             */
#define FTM_COMBINE_DTEN3(x)                     (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< FTM0_COMBINE.DTEN3 Field                */
#define FTM_COMBINE_SYNCEN3_MASK                 (0x20000000U)                                       /*!< FTM0_COMBINE.SYNCEN3 Mask               */
#define FTM_COMBINE_SYNCEN3_SHIFT                (29U)                                               /*!< FTM0_COMBINE.SYNCEN3 Position           */
#define FTM_COMBINE_SYNCEN3(x)                   (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< FTM0_COMBINE.SYNCEN3 Field              */
#define FTM_COMBINE_FAULTEN3_MASK                (0x40000000U)                                       /*!< FTM0_COMBINE.FAULTEN3 Mask              */
#define FTM_COMBINE_FAULTEN3_SHIFT               (30U)                                               /*!< FTM0_COMBINE.FAULTEN3 Position          */
#define FTM_COMBINE_FAULTEN3(x)                  (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< FTM0_COMBINE.FAULTEN3 Field             */
/* ------- DEADTIME Bit Fields                      ------ */
#define FTM_DEADTIME_DTVAL_MASK                  (0x3FU)                                             /*!< FTM0_DEADTIME.DTVAL Mask                */
#define FTM_DEADTIME_DTVAL_SHIFT                 (0U)                                                /*!< FTM0_DEADTIME.DTVAL Position            */
#define FTM_DEADTIME_DTVAL(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x3FUL)          /*!< FTM0_DEADTIME.DTVAL Field               */
#define FTM_DEADTIME_DTPS_MASK                   (0xC0U)                                             /*!< FTM0_DEADTIME.DTPS Mask                 */
#define FTM_DEADTIME_DTPS_SHIFT                  (6U)                                                /*!< FTM0_DEADTIME.DTPS Position             */
#define FTM_DEADTIME_DTPS(x)                     (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< FTM0_DEADTIME.DTPS Field                */
/* ------- EXTTRIG Bit Fields                       ------ */
#define FTM_EXTTRIG_CH2TRIG_MASK                 (0x1U)                                              /*!< FTM0_EXTTRIG.CH2TRIG Mask               */
#define FTM_EXTTRIG_CH2TRIG_SHIFT                (0U)                                                /*!< FTM0_EXTTRIG.CH2TRIG Position           */
#define FTM_EXTTRIG_CH2TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_EXTTRIG.CH2TRIG Field              */
#define FTM_EXTTRIG_CH3TRIG_MASK                 (0x2U)                                              /*!< FTM0_EXTTRIG.CH3TRIG Mask               */
#define FTM_EXTTRIG_CH3TRIG_SHIFT                (1U)                                                /*!< FTM0_EXTTRIG.CH3TRIG Position           */
#define FTM_EXTTRIG_CH3TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_EXTTRIG.CH3TRIG Field              */
#define FTM_EXTTRIG_CH4TRIG_MASK                 (0x4U)                                              /*!< FTM0_EXTTRIG.CH4TRIG Mask               */
#define FTM_EXTTRIG_CH4TRIG_SHIFT                (2U)                                                /*!< FTM0_EXTTRIG.CH4TRIG Position           */
#define FTM_EXTTRIG_CH4TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_EXTTRIG.CH4TRIG Field              */
#define FTM_EXTTRIG_CH5TRIG_MASK                 (0x8U)                                              /*!< FTM0_EXTTRIG.CH5TRIG Mask               */
#define FTM_EXTTRIG_CH5TRIG_SHIFT                (3U)                                                /*!< FTM0_EXTTRIG.CH5TRIG Position           */
#define FTM_EXTTRIG_CH5TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_EXTTRIG.CH5TRIG Field              */
#define FTM_EXTTRIG_CH0TRIG_MASK                 (0x10U)                                             /*!< FTM0_EXTTRIG.CH0TRIG Mask               */
#define FTM_EXTTRIG_CH0TRIG_SHIFT                (4U)                                                /*!< FTM0_EXTTRIG.CH0TRIG Position           */
#define FTM_EXTTRIG_CH0TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FTM0_EXTTRIG.CH0TRIG Field              */
#define FTM_EXTTRIG_CH1TRIG_MASK                 (0x20U)                                             /*!< FTM0_EXTTRIG.CH1TRIG Mask               */
#define FTM_EXTTRIG_CH1TRIG_SHIFT                (5U)                                                /*!< FTM0_EXTTRIG.CH1TRIG Position           */
#define FTM_EXTTRIG_CH1TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_EXTTRIG.CH1TRIG Field              */
#define FTM_EXTTRIG_INITTRIGEN_MASK              (0x40U)                                             /*!< FTM0_EXTTRIG.INITTRIGEN Mask            */
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             (6U)                                                /*!< FTM0_EXTTRIG.INITTRIGEN Position        */
#define FTM_EXTTRIG_INITTRIGEN(x)                (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FTM0_EXTTRIG.INITTRIGEN Field           */
#define FTM_EXTTRIG_TRIGF_MASK                   (0x80U)                                             /*!< FTM0_EXTTRIG.TRIGF Mask                 */
#define FTM_EXTTRIG_TRIGF_SHIFT                  (7U)                                                /*!< FTM0_EXTTRIG.TRIGF Position             */
#define FTM_EXTTRIG_TRIGF(x)                     (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_EXTTRIG.TRIGF Field                */
/* ------- POL Bit Fields                           ------ */
#define FTM_POL_POL0_MASK                        (0x1U)                                              /*!< FTM0_POL.POL0 Mask                      */
#define FTM_POL_POL0_SHIFT                       (0U)                                                /*!< FTM0_POL.POL0 Position                  */
#define FTM_POL_POL0(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_POL.POL0 Field                     */
#define FTM_POL_POL1_MASK                        (0x2U)                                              /*!< FTM0_POL.POL1 Mask                      */
#define FTM_POL_POL1_SHIFT                       (1U)                                                /*!< FTM0_POL.POL1 Position                  */
#define FTM_POL_POL1(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_POL.POL1 Field                     */
#define FTM_POL_POL2_MASK                        (0x4U)                                              /*!< FTM0_POL.POL2 Mask                      */
#define FTM_POL_POL2_SHIFT                       (2U)                                                /*!< FTM0_POL.POL2 Position                  */
#define FTM_POL_POL2(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_POL.POL2 Field                     */
#define FTM_POL_POL3_MASK                        (0x8U)                                              /*!< FTM0_POL.POL3 Mask                      */
#define FTM_POL_POL3_SHIFT                       (3U)                                                /*!< FTM0_POL.POL3 Position                  */
#define FTM_POL_POL3(x)                          (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_POL.POL3 Field                     */
#define FTM_POL_POL4_MASK                        (0x10U)                                             /*!< FTM0_POL.POL4 Mask                      */
#define FTM_POL_POL4_SHIFT                       (4U)                                                /*!< FTM0_POL.POL4 Position                  */
#define FTM_POL_POL4(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FTM0_POL.POL4 Field                     */
#define FTM_POL_POL5_MASK                        (0x20U)                                             /*!< FTM0_POL.POL5 Mask                      */
#define FTM_POL_POL5_SHIFT                       (5U)                                                /*!< FTM0_POL.POL5 Position                  */
#define FTM_POL_POL5(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_POL.POL5 Field                     */
#define FTM_POL_POL6_MASK                        (0x40U)                                             /*!< FTM0_POL.POL6 Mask                      */
#define FTM_POL_POL6_SHIFT                       (6U)                                                /*!< FTM0_POL.POL6 Position                  */
#define FTM_POL_POL6(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FTM0_POL.POL6 Field                     */
#define FTM_POL_POL7_MASK                        (0x80U)                                             /*!< FTM0_POL.POL7 Mask                      */
#define FTM_POL_POL7_SHIFT                       (7U)                                                /*!< FTM0_POL.POL7 Position                  */
#define FTM_POL_POL7(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_POL.POL7 Field                     */
/* ------- FMS Bit Fields                           ------ */
#define FTM_FMS_FAULTF0_MASK                     (0x1U)                                              /*!< FTM0_FMS.FAULTF0 Mask                   */
#define FTM_FMS_FAULTF0_SHIFT                    (0U)                                                /*!< FTM0_FMS.FAULTF0 Position               */
#define FTM_FMS_FAULTF0(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_FMS.FAULTF0 Field                  */
#define FTM_FMS_FAULTF1_MASK                     (0x2U)                                              /*!< FTM0_FMS.FAULTF1 Mask                   */
#define FTM_FMS_FAULTF1_SHIFT                    (1U)                                                /*!< FTM0_FMS.FAULTF1 Position               */
#define FTM_FMS_FAULTF1(x)                       (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_FMS.FAULTF1 Field                  */
#define FTM_FMS_FAULTF2_MASK                     (0x4U)                                              /*!< FTM0_FMS.FAULTF2 Mask                   */
#define FTM_FMS_FAULTF2_SHIFT                    (2U)                                                /*!< FTM0_FMS.FAULTF2 Position               */
#define FTM_FMS_FAULTF2(x)                       (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_FMS.FAULTF2 Field                  */
#define FTM_FMS_FAULTF3_MASK                     (0x8U)                                              /*!< FTM0_FMS.FAULTF3 Mask                   */
#define FTM_FMS_FAULTF3_SHIFT                    (3U)                                                /*!< FTM0_FMS.FAULTF3 Position               */
#define FTM_FMS_FAULTF3(x)                       (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_FMS.FAULTF3 Field                  */
#define FTM_FMS_FAULTIN_MASK                     (0x20U)                                             /*!< FTM0_FMS.FAULTIN Mask                   */
#define FTM_FMS_FAULTIN_SHIFT                    (5U)                                                /*!< FTM0_FMS.FAULTIN Position               */
#define FTM_FMS_FAULTIN(x)                       (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_FMS.FAULTIN Field                  */
#define FTM_FMS_WPEN_MASK                        (0x40U)                                             /*!< FTM0_FMS.WPEN Mask                      */
#define FTM_FMS_WPEN_SHIFT                       (6U)                                                /*!< FTM0_FMS.WPEN Position                  */
#define FTM_FMS_WPEN(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FTM0_FMS.WPEN Field                     */
#define FTM_FMS_FAULTF_MASK                      (0x80U)                                             /*!< FTM0_FMS.FAULTF Mask                    */
#define FTM_FMS_FAULTF_SHIFT                     (7U)                                                /*!< FTM0_FMS.FAULTF Position                */
#define FTM_FMS_FAULTF(x)                        (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_FMS.FAULTF Field                   */
/* ------- FILTER Bit Fields                        ------ */
#define FTM_FILTER_CH0FVAL_MASK                  (0xFU)                                              /*!< FTM0_FILTER.CH0FVAL Mask                */
#define FTM_FILTER_CH0FVAL_SHIFT                 (0U)                                                /*!< FTM0_FILTER.CH0FVAL Position            */
#define FTM_FILTER_CH0FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< FTM0_FILTER.CH0FVAL Field               */
#define FTM_FILTER_CH1FVAL_MASK                  (0xF0U)                                             /*!< FTM0_FILTER.CH1FVAL Mask                */
#define FTM_FILTER_CH1FVAL_SHIFT                 (4U)                                                /*!< FTM0_FILTER.CH1FVAL Position            */
#define FTM_FILTER_CH1FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<4U))&0xF0UL)          /*!< FTM0_FILTER.CH1FVAL Field               */
#define FTM_FILTER_CH2FVAL_MASK                  (0xF00U)                                            /*!< FTM0_FILTER.CH2FVAL Mask                */
#define FTM_FILTER_CH2FVAL_SHIFT                 (8U)                                                /*!< FTM0_FILTER.CH2FVAL Position            */
#define FTM_FILTER_CH2FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< FTM0_FILTER.CH2FVAL Field               */
#define FTM_FILTER_CH3FVAL_MASK                  (0xF000U)                                           /*!< FTM0_FILTER.CH3FVAL Mask                */
#define FTM_FILTER_CH3FVAL_SHIFT                 (12U)                                               /*!< FTM0_FILTER.CH3FVAL Position            */
#define FTM_FILTER_CH3FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< FTM0_FILTER.CH3FVAL Field               */
/* ------- FLTCTRL Bit Fields                       ------ */
#define FTM_FLTCTRL_FAULT0EN_MASK                (0x1U)                                              /*!< FTM0_FLTCTRL.FAULT0EN Mask              */
#define FTM_FLTCTRL_FAULT0EN_SHIFT               (0U)                                                /*!< FTM0_FLTCTRL.FAULT0EN Position          */
#define FTM_FLTCTRL_FAULT0EN(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_FLTCTRL.FAULT0EN Field             */
#define FTM_FLTCTRL_FAULT1EN_MASK                (0x2U)                                              /*!< FTM0_FLTCTRL.FAULT1EN Mask              */
#define FTM_FLTCTRL_FAULT1EN_SHIFT               (1U)                                                /*!< FTM0_FLTCTRL.FAULT1EN Position          */
#define FTM_FLTCTRL_FAULT1EN(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_FLTCTRL.FAULT1EN Field             */
#define FTM_FLTCTRL_FAULT2EN_MASK                (0x4U)                                              /*!< FTM0_FLTCTRL.FAULT2EN Mask              */
#define FTM_FLTCTRL_FAULT2EN_SHIFT               (2U)                                                /*!< FTM0_FLTCTRL.FAULT2EN Position          */
#define FTM_FLTCTRL_FAULT2EN(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_FLTCTRL.FAULT2EN Field             */
#define FTM_FLTCTRL_FAULT3EN_MASK                (0x8U)                                              /*!< FTM0_FLTCTRL.FAULT3EN Mask              */
#define FTM_FLTCTRL_FAULT3EN_SHIFT               (3U)                                                /*!< FTM0_FLTCTRL.FAULT3EN Position          */
#define FTM_FLTCTRL_FAULT3EN(x)                  (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_FLTCTRL.FAULT3EN Field             */
#define FTM_FLTCTRL_FFLTR0EN_MASK                (0x10U)                                             /*!< FTM0_FLTCTRL.FFLTR0EN Mask              */
#define FTM_FLTCTRL_FFLTR0EN_SHIFT               (4U)                                                /*!< FTM0_FLTCTRL.FFLTR0EN Position          */
#define FTM_FLTCTRL_FFLTR0EN(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FTM0_FLTCTRL.FFLTR0EN Field             */
#define FTM_FLTCTRL_FFLTR1EN_MASK                (0x20U)                                             /*!< FTM0_FLTCTRL.FFLTR1EN Mask              */
#define FTM_FLTCTRL_FFLTR1EN_SHIFT               (5U)                                                /*!< FTM0_FLTCTRL.FFLTR1EN Position          */
#define FTM_FLTCTRL_FFLTR1EN(x)                  (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_FLTCTRL.FFLTR1EN Field             */
#define FTM_FLTCTRL_FFLTR2EN_MASK                (0x40U)                                             /*!< FTM0_FLTCTRL.FFLTR2EN Mask              */
#define FTM_FLTCTRL_FFLTR2EN_SHIFT               (6U)                                                /*!< FTM0_FLTCTRL.FFLTR2EN Position          */
#define FTM_FLTCTRL_FFLTR2EN(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FTM0_FLTCTRL.FFLTR2EN Field             */
#define FTM_FLTCTRL_FFLTR3EN_MASK                (0x80U)                                             /*!< FTM0_FLTCTRL.FFLTR3EN Mask              */
#define FTM_FLTCTRL_FFLTR3EN_SHIFT               (7U)                                                /*!< FTM0_FLTCTRL.FFLTR3EN Position          */
#define FTM_FLTCTRL_FFLTR3EN(x)                  (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_FLTCTRL.FFLTR3EN Field             */
#define FTM_FLTCTRL_FFVAL_MASK                   (0xF00U)                                            /*!< FTM0_FLTCTRL.FFVAL Mask                 */
#define FTM_FLTCTRL_FFVAL_SHIFT                  (8U)                                                /*!< FTM0_FLTCTRL.FFVAL Position             */
#define FTM_FLTCTRL_FFVAL(x)                     (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< FTM0_FLTCTRL.FFVAL Field                */
/* ------- QDCTRL Bit Fields                        ------ */
#define FTM_QDCTRL_QUADEN_MASK                   (0x1U)                                              /*!< FTM0_QDCTRL.QUADEN Mask                 */
#define FTM_QDCTRL_QUADEN_SHIFT                  (0U)                                                /*!< FTM0_QDCTRL.QUADEN Position             */
#define FTM_QDCTRL_QUADEN(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_QDCTRL.QUADEN Field                */
#define FTM_QDCTRL_TOFDIR_MASK                   (0x2U)                                              /*!< FTM0_QDCTRL.TOFDIR Mask                 */
#define FTM_QDCTRL_TOFDIR_SHIFT                  (1U)                                                /*!< FTM0_QDCTRL.TOFDIR Position             */
#define FTM_QDCTRL_TOFDIR(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_QDCTRL.TOFDIR Field                */
#define FTM_QDCTRL_QUADIR_MASK                   (0x4U)                                              /*!< FTM0_QDCTRL.QUADIR Mask                 */
#define FTM_QDCTRL_QUADIR_SHIFT                  (2U)                                                /*!< FTM0_QDCTRL.QUADIR Position             */
#define FTM_QDCTRL_QUADIR(x)                     (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_QDCTRL.QUADIR Field                */
#define FTM_QDCTRL_QUADMODE_MASK                 (0x8U)                                              /*!< FTM0_QDCTRL.QUADMODE Mask               */
#define FTM_QDCTRL_QUADMODE_SHIFT                (3U)                                                /*!< FTM0_QDCTRL.QUADMODE Position           */
#define FTM_QDCTRL_QUADMODE(x)                   (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_QDCTRL.QUADMODE Field              */
#define FTM_QDCTRL_PHBPOL_MASK                   (0x10U)                                             /*!< FTM0_QDCTRL.PHBPOL Mask                 */
#define FTM_QDCTRL_PHBPOL_SHIFT                  (4U)                                                /*!< FTM0_QDCTRL.PHBPOL Position             */
#define FTM_QDCTRL_PHBPOL(x)                     (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FTM0_QDCTRL.PHBPOL Field                */
#define FTM_QDCTRL_PHAPOL_MASK                   (0x20U)                                             /*!< FTM0_QDCTRL.PHAPOL Mask                 */
#define FTM_QDCTRL_PHAPOL_SHIFT                  (5U)                                                /*!< FTM0_QDCTRL.PHAPOL Position             */
#define FTM_QDCTRL_PHAPOL(x)                     (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_QDCTRL.PHAPOL Field                */
#define FTM_QDCTRL_PHBFLTREN_MASK                (0x40U)                                             /*!< FTM0_QDCTRL.PHBFLTREN Mask              */
#define FTM_QDCTRL_PHBFLTREN_SHIFT               (6U)                                                /*!< FTM0_QDCTRL.PHBFLTREN Position          */
#define FTM_QDCTRL_PHBFLTREN(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FTM0_QDCTRL.PHBFLTREN Field             */
#define FTM_QDCTRL_PHAFLTREN_MASK                (0x80U)                                             /*!< FTM0_QDCTRL.PHAFLTREN Mask              */
#define FTM_QDCTRL_PHAFLTREN_SHIFT               (7U)                                                /*!< FTM0_QDCTRL.PHAFLTREN Position          */
#define FTM_QDCTRL_PHAFLTREN(x)                  (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_QDCTRL.PHAFLTREN Field             */
/* ------- CONF Bit Fields                          ------ */
#define FTM_CONF_NUMTOF_MASK                     (0x1FU)                                             /*!< FTM0_CONF.NUMTOF Mask                   */
#define FTM_CONF_NUMTOF_SHIFT                    (0U)                                                /*!< FTM0_CONF.NUMTOF Position               */
#define FTM_CONF_NUMTOF(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1FUL)          /*!< FTM0_CONF.NUMTOF Field                  */
#define FTM_CONF_BDMMODE_MASK                    (0xC0U)                                             /*!< FTM0_CONF.BDMMODE Mask                  */
#define FTM_CONF_BDMMODE_SHIFT                   (6U)                                                /*!< FTM0_CONF.BDMMODE Position              */
#define FTM_CONF_BDMMODE(x)                      (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< FTM0_CONF.BDMMODE Field                 */
#define FTM_CONF_GTBEEN_MASK                     (0x200U)                                            /*!< FTM0_CONF.GTBEEN Mask                   */
#define FTM_CONF_GTBEEN_SHIFT                    (9U)                                                /*!< FTM0_CONF.GTBEEN Position               */
#define FTM_CONF_GTBEEN(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< FTM0_CONF.GTBEEN Field                  */
#define FTM_CONF_GTBEOUT_MASK                    (0x400U)                                            /*!< FTM0_CONF.GTBEOUT Mask                  */
#define FTM_CONF_GTBEOUT_SHIFT                   (10U)                                               /*!< FTM0_CONF.GTBEOUT Position              */
#define FTM_CONF_GTBEOUT(x)                      (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< FTM0_CONF.GTBEOUT Field                 */
/* ------- FLTPOL Bit Fields                        ------ */
#define FTM_FLTPOL_FLT0POL_MASK                  (0x1U)                                              /*!< FTM0_FLTPOL.FLT0POL Mask                */
#define FTM_FLTPOL_FLT0POL_SHIFT                 (0U)                                                /*!< FTM0_FLTPOL.FLT0POL Position            */
#define FTM_FLTPOL_FLT0POL(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_FLTPOL.FLT0POL Field               */
#define FTM_FLTPOL_FLT1POL_MASK                  (0x2U)                                              /*!< FTM0_FLTPOL.FLT1POL Mask                */
#define FTM_FLTPOL_FLT1POL_SHIFT                 (1U)                                                /*!< FTM0_FLTPOL.FLT1POL Position            */
#define FTM_FLTPOL_FLT1POL(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_FLTPOL.FLT1POL Field               */
#define FTM_FLTPOL_FLT2POL_MASK                  (0x4U)                                              /*!< FTM0_FLTPOL.FLT2POL Mask                */
#define FTM_FLTPOL_FLT2POL_SHIFT                 (2U)                                                /*!< FTM0_FLTPOL.FLT2POL Position            */
#define FTM_FLTPOL_FLT2POL(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_FLTPOL.FLT2POL Field               */
#define FTM_FLTPOL_FLT3POL_MASK                  (0x8U)                                              /*!< FTM0_FLTPOL.FLT3POL Mask                */
#define FTM_FLTPOL_FLT3POL_SHIFT                 (3U)                                                /*!< FTM0_FLTPOL.FLT3POL Position            */
#define FTM_FLTPOL_FLT3POL(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_FLTPOL.FLT3POL Field               */
/* ------- SYNCONF Bit Fields                       ------ */
#define FTM_SYNCONF_HWTRIGMODE_MASK              (0x1U)                                              /*!< FTM0_SYNCONF.HWTRIGMODE Mask            */
#define FTM_SYNCONF_HWTRIGMODE_SHIFT             (0U)                                                /*!< FTM0_SYNCONF.HWTRIGMODE Position        */
#define FTM_SYNCONF_HWTRIGMODE(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_SYNCONF.HWTRIGMODE Field           */
#define FTM_SYNCONF_CNTINC_MASK                  (0x4U)                                              /*!< FTM0_SYNCONF.CNTINC Mask                */
#define FTM_SYNCONF_CNTINC_SHIFT                 (2U)                                                /*!< FTM0_SYNCONF.CNTINC Position            */
#define FTM_SYNCONF_CNTINC(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_SYNCONF.CNTINC Field               */
#define FTM_SYNCONF_INVC_MASK                    (0x10U)                                             /*!< FTM0_SYNCONF.INVC Mask                  */
#define FTM_SYNCONF_INVC_SHIFT                   (4U)                                                /*!< FTM0_SYNCONF.INVC Position              */
#define FTM_SYNCONF_INVC(x)                      (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FTM0_SYNCONF.INVC Field                 */
#define FTM_SYNCONF_SWOC_MASK                    (0x20U)                                             /*!< FTM0_SYNCONF.SWOC Mask                  */
#define FTM_SYNCONF_SWOC_SHIFT                   (5U)                                                /*!< FTM0_SYNCONF.SWOC Position              */
#define FTM_SYNCONF_SWOC(x)                      (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_SYNCONF.SWOC Field                 */
#define FTM_SYNCONF_SYNCMODE_MASK                (0x80U)                                             /*!< FTM0_SYNCONF.SYNCMODE Mask              */
#define FTM_SYNCONF_SYNCMODE_SHIFT               (7U)                                                /*!< FTM0_SYNCONF.SYNCMODE Position          */
#define FTM_SYNCONF_SYNCMODE(x)                  (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_SYNCONF.SYNCMODE Field             */
#define FTM_SYNCONF_SWRSTCNT_MASK                (0x100U)                                            /*!< FTM0_SYNCONF.SWRSTCNT Mask              */
#define FTM_SYNCONF_SWRSTCNT_SHIFT               (8U)                                                /*!< FTM0_SYNCONF.SWRSTCNT Position          */
#define FTM_SYNCONF_SWRSTCNT(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< FTM0_SYNCONF.SWRSTCNT Field             */
#define FTM_SYNCONF_SWWRBUF_MASK                 (0x200U)                                            /*!< FTM0_SYNCONF.SWWRBUF Mask               */
#define FTM_SYNCONF_SWWRBUF_SHIFT                (9U)                                                /*!< FTM0_SYNCONF.SWWRBUF Position           */
#define FTM_SYNCONF_SWWRBUF(x)                   (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< FTM0_SYNCONF.SWWRBUF Field              */
#define FTM_SYNCONF_SWOM_MASK                    (0x400U)                                            /*!< FTM0_SYNCONF.SWOM Mask                  */
#define FTM_SYNCONF_SWOM_SHIFT                   (10U)                                               /*!< FTM0_SYNCONF.SWOM Position              */
#define FTM_SYNCONF_SWOM(x)                      (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< FTM0_SYNCONF.SWOM Field                 */
#define FTM_SYNCONF_SWINVC_MASK                  (0x800U)                                            /*!< FTM0_SYNCONF.SWINVC Mask                */
#define FTM_SYNCONF_SWINVC_SHIFT                 (11U)                                               /*!< FTM0_SYNCONF.SWINVC Position            */
#define FTM_SYNCONF_SWINVC(x)                    (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< FTM0_SYNCONF.SWINVC Field               */
#define FTM_SYNCONF_SWSOC_MASK                   (0x1000U)                                           /*!< FTM0_SYNCONF.SWSOC Mask                 */
#define FTM_SYNCONF_SWSOC_SHIFT                  (12U)                                               /*!< FTM0_SYNCONF.SWSOC Position             */
#define FTM_SYNCONF_SWSOC(x)                     (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< FTM0_SYNCONF.SWSOC Field                */
#define FTM_SYNCONF_HWRSTCNT_MASK                (0x10000U)                                          /*!< FTM0_SYNCONF.HWRSTCNT Mask              */
#define FTM_SYNCONF_HWRSTCNT_SHIFT               (16U)                                               /*!< FTM0_SYNCONF.HWRSTCNT Position          */
#define FTM_SYNCONF_HWRSTCNT(x)                  (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< FTM0_SYNCONF.HWRSTCNT Field             */
#define FTM_SYNCONF_HWWRBUF_MASK                 (0x20000U)                                          /*!< FTM0_SYNCONF.HWWRBUF Mask               */
#define FTM_SYNCONF_HWWRBUF_SHIFT                (17U)                                               /*!< FTM0_SYNCONF.HWWRBUF Position           */
#define FTM_SYNCONF_HWWRBUF(x)                   (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< FTM0_SYNCONF.HWWRBUF Field              */
#define FTM_SYNCONF_HWOM_MASK                    (0x40000U)                                          /*!< FTM0_SYNCONF.HWOM Mask                  */
#define FTM_SYNCONF_HWOM_SHIFT                   (18U)                                               /*!< FTM0_SYNCONF.HWOM Position              */
#define FTM_SYNCONF_HWOM(x)                      (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< FTM0_SYNCONF.HWOM Field                 */
#define FTM_SYNCONF_HWINVC_MASK                  (0x80000U)                                          /*!< FTM0_SYNCONF.HWINVC Mask                */
#define FTM_SYNCONF_HWINVC_SHIFT                 (19U)                                               /*!< FTM0_SYNCONF.HWINVC Position            */
#define FTM_SYNCONF_HWINVC(x)                    (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< FTM0_SYNCONF.HWINVC Field               */
#define FTM_SYNCONF_HWSOC_MASK                   (0x100000U)                                         /*!< FTM0_SYNCONF.HWSOC Mask                 */
#define FTM_SYNCONF_HWSOC_SHIFT                  (20U)                                               /*!< FTM0_SYNCONF.HWSOC Position             */
#define FTM_SYNCONF_HWSOC(x)                     (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< FTM0_SYNCONF.HWSOC Field                */
/* ------- INVCTRL Bit Fields                       ------ */
#define FTM_INVCTRL_INV0EN_MASK                  (0x1U)                                              /*!< FTM0_INVCTRL.INV0EN Mask                */
#define FTM_INVCTRL_INV0EN_SHIFT                 (0U)                                                /*!< FTM0_INVCTRL.INV0EN Position            */
#define FTM_INVCTRL_INV0EN(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_INVCTRL.INV0EN Field               */
#define FTM_INVCTRL_INV1EN_MASK                  (0x2U)                                              /*!< FTM0_INVCTRL.INV1EN Mask                */
#define FTM_INVCTRL_INV1EN_SHIFT                 (1U)                                                /*!< FTM0_INVCTRL.INV1EN Position            */
#define FTM_INVCTRL_INV1EN(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_INVCTRL.INV1EN Field               */
#define FTM_INVCTRL_INV2EN_MASK                  (0x4U)                                              /*!< FTM0_INVCTRL.INV2EN Mask                */
#define FTM_INVCTRL_INV2EN_SHIFT                 (2U)                                                /*!< FTM0_INVCTRL.INV2EN Position            */
#define FTM_INVCTRL_INV2EN(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_INVCTRL.INV2EN Field               */
#define FTM_INVCTRL_INV3EN_MASK                  (0x8U)                                              /*!< FTM0_INVCTRL.INV3EN Mask                */
#define FTM_INVCTRL_INV3EN_SHIFT                 (3U)                                                /*!< FTM0_INVCTRL.INV3EN Position            */
#define FTM_INVCTRL_INV3EN(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_INVCTRL.INV3EN Field               */
/* ------- SWOCTRL Bit Fields                       ------ */
#define FTM_SWOCTRL_CH0OC_MASK                   (0x1U)                                              /*!< FTM0_SWOCTRL.CH0OC Mask                 */
#define FTM_SWOCTRL_CH0OC_SHIFT                  (0U)                                                /*!< FTM0_SWOCTRL.CH0OC Position             */
#define FTM_SWOCTRL_CH0OC(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_SWOCTRL.CH0OC Field                */
#define FTM_SWOCTRL_CH1OC_MASK                   (0x2U)                                              /*!< FTM0_SWOCTRL.CH1OC Mask                 */
#define FTM_SWOCTRL_CH1OC_SHIFT                  (1U)                                                /*!< FTM0_SWOCTRL.CH1OC Position             */
#define FTM_SWOCTRL_CH1OC(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_SWOCTRL.CH1OC Field                */
#define FTM_SWOCTRL_CH2OC_MASK                   (0x4U)                                              /*!< FTM0_SWOCTRL.CH2OC Mask                 */
#define FTM_SWOCTRL_CH2OC_SHIFT                  (2U)                                                /*!< FTM0_SWOCTRL.CH2OC Position             */
#define FTM_SWOCTRL_CH2OC(x)                     (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_SWOCTRL.CH2OC Field                */
#define FTM_SWOCTRL_CH3OC_MASK                   (0x8U)                                              /*!< FTM0_SWOCTRL.CH3OC Mask                 */
#define FTM_SWOCTRL_CH3OC_SHIFT                  (3U)                                                /*!< FTM0_SWOCTRL.CH3OC Position             */
#define FTM_SWOCTRL_CH3OC(x)                     (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_SWOCTRL.CH3OC Field                */
#define FTM_SWOCTRL_CH4OC_MASK                   (0x10U)                                             /*!< FTM0_SWOCTRL.CH4OC Mask                 */
#define FTM_SWOCTRL_CH4OC_SHIFT                  (4U)                                                /*!< FTM0_SWOCTRL.CH4OC Position             */
#define FTM_SWOCTRL_CH4OC(x)                     (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FTM0_SWOCTRL.CH4OC Field                */
#define FTM_SWOCTRL_CH5OC_MASK                   (0x20U)                                             /*!< FTM0_SWOCTRL.CH5OC Mask                 */
#define FTM_SWOCTRL_CH5OC_SHIFT                  (5U)                                                /*!< FTM0_SWOCTRL.CH5OC Position             */
#define FTM_SWOCTRL_CH5OC(x)                     (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_SWOCTRL.CH5OC Field                */
#define FTM_SWOCTRL_CH6OC_MASK                   (0x40U)                                             /*!< FTM0_SWOCTRL.CH6OC Mask                 */
#define FTM_SWOCTRL_CH6OC_SHIFT                  (6U)                                                /*!< FTM0_SWOCTRL.CH6OC Position             */
#define FTM_SWOCTRL_CH6OC(x)                     (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FTM0_SWOCTRL.CH6OC Field                */
#define FTM_SWOCTRL_CH7OC_MASK                   (0x80U)                                             /*!< FTM0_SWOCTRL.CH7OC Mask                 */
#define FTM_SWOCTRL_CH7OC_SHIFT                  (7U)                                                /*!< FTM0_SWOCTRL.CH7OC Position             */
#define FTM_SWOCTRL_CH7OC(x)                     (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_SWOCTRL.CH7OC Field                */
#define FTM_SWOCTRL_CH0OCV_MASK                  (0x100U)                                            /*!< FTM0_SWOCTRL.CH0OCV Mask                */
#define FTM_SWOCTRL_CH0OCV_SHIFT                 (8U)                                                /*!< FTM0_SWOCTRL.CH0OCV Position            */
#define FTM_SWOCTRL_CH0OCV(x)                    (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< FTM0_SWOCTRL.CH0OCV Field               */
#define FTM_SWOCTRL_CH1OCV_MASK                  (0x200U)                                            /*!< FTM0_SWOCTRL.CH1OCV Mask                */
#define FTM_SWOCTRL_CH1OCV_SHIFT                 (9U)                                                /*!< FTM0_SWOCTRL.CH1OCV Position            */
#define FTM_SWOCTRL_CH1OCV(x)                    (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< FTM0_SWOCTRL.CH1OCV Field               */
#define FTM_SWOCTRL_CH2OCV_MASK                  (0x400U)                                            /*!< FTM0_SWOCTRL.CH2OCV Mask                */
#define FTM_SWOCTRL_CH2OCV_SHIFT                 (10U)                                               /*!< FTM0_SWOCTRL.CH2OCV Position            */
#define FTM_SWOCTRL_CH2OCV(x)                    (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< FTM0_SWOCTRL.CH2OCV Field               */
#define FTM_SWOCTRL_CH3OCV_MASK                  (0x800U)                                            /*!< FTM0_SWOCTRL.CH3OCV Mask                */
#define FTM_SWOCTRL_CH3OCV_SHIFT                 (11U)                                               /*!< FTM0_SWOCTRL.CH3OCV Position            */
#define FTM_SWOCTRL_CH3OCV(x)                    (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< FTM0_SWOCTRL.CH3OCV Field               */
#define FTM_SWOCTRL_CH4OCV_MASK                  (0x1000U)                                           /*!< FTM0_SWOCTRL.CH4OCV Mask                */
#define FTM_SWOCTRL_CH4OCV_SHIFT                 (12U)                                               /*!< FTM0_SWOCTRL.CH4OCV Position            */
#define FTM_SWOCTRL_CH4OCV(x)                    (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< FTM0_SWOCTRL.CH4OCV Field               */
#define FTM_SWOCTRL_CH5OCV_MASK                  (0x2000U)                                           /*!< FTM0_SWOCTRL.CH5OCV Mask                */
#define FTM_SWOCTRL_CH5OCV_SHIFT                 (13U)                                               /*!< FTM0_SWOCTRL.CH5OCV Position            */
#define FTM_SWOCTRL_CH5OCV(x)                    (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< FTM0_SWOCTRL.CH5OCV Field               */
#define FTM_SWOCTRL_CH6OCV_MASK                  (0x4000U)                                           /*!< FTM0_SWOCTRL.CH6OCV Mask                */
#define FTM_SWOCTRL_CH6OCV_SHIFT                 (14U)                                               /*!< FTM0_SWOCTRL.CH6OCV Position            */
#define FTM_SWOCTRL_CH6OCV(x)                    (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< FTM0_SWOCTRL.CH6OCV Field               */
#define FTM_SWOCTRL_CH7OCV_MASK                  (0x8000U)                                           /*!< FTM0_SWOCTRL.CH7OCV Mask                */
#define FTM_SWOCTRL_CH7OCV_SHIFT                 (15U)                                               /*!< FTM0_SWOCTRL.CH7OCV Position            */
#define FTM_SWOCTRL_CH7OCV(x)                    (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< FTM0_SWOCTRL.CH7OCV Field               */
/* ------- PWMLOAD Bit Fields                       ------ */
#define FTM_PWMLOAD_CH0SEL_MASK                  (0x1U)                                              /*!< FTM0_PWMLOAD.CH0SEL Mask                */
#define FTM_PWMLOAD_CH0SEL_SHIFT                 (0U)                                                /*!< FTM0_PWMLOAD.CH0SEL Position            */
#define FTM_PWMLOAD_CH0SEL(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< FTM0_PWMLOAD.CH0SEL Field               */
#define FTM_PWMLOAD_CH1SEL_MASK                  (0x2U)                                              /*!< FTM0_PWMLOAD.CH1SEL Mask                */
#define FTM_PWMLOAD_CH1SEL_SHIFT                 (1U)                                                /*!< FTM0_PWMLOAD.CH1SEL Position            */
#define FTM_PWMLOAD_CH1SEL(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< FTM0_PWMLOAD.CH1SEL Field               */
#define FTM_PWMLOAD_CH2SEL_MASK                  (0x4U)                                              /*!< FTM0_PWMLOAD.CH2SEL Mask                */
#define FTM_PWMLOAD_CH2SEL_SHIFT                 (2U)                                                /*!< FTM0_PWMLOAD.CH2SEL Position            */
#define FTM_PWMLOAD_CH2SEL(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< FTM0_PWMLOAD.CH2SEL Field               */
#define FTM_PWMLOAD_CH3SEL_MASK                  (0x8U)                                              /*!< FTM0_PWMLOAD.CH3SEL Mask                */
#define FTM_PWMLOAD_CH3SEL_SHIFT                 (3U)                                                /*!< FTM0_PWMLOAD.CH3SEL Position            */
#define FTM_PWMLOAD_CH3SEL(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< FTM0_PWMLOAD.CH3SEL Field               */
#define FTM_PWMLOAD_CH4SEL_MASK                  (0x10U)                                             /*!< FTM0_PWMLOAD.CH4SEL Mask                */
#define FTM_PWMLOAD_CH4SEL_SHIFT                 (4U)                                                /*!< FTM0_PWMLOAD.CH4SEL Position            */
#define FTM_PWMLOAD_CH4SEL(x)                    (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< FTM0_PWMLOAD.CH4SEL Field               */
#define FTM_PWMLOAD_CH5SEL_MASK                  (0x20U)                                             /*!< FTM0_PWMLOAD.CH5SEL Mask                */
#define FTM_PWMLOAD_CH5SEL_SHIFT                 (5U)                                                /*!< FTM0_PWMLOAD.CH5SEL Position            */
#define FTM_PWMLOAD_CH5SEL(x)                    (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< FTM0_PWMLOAD.CH5SEL Field               */
#define FTM_PWMLOAD_CH6SEL_MASK                  (0x40U)                                             /*!< FTM0_PWMLOAD.CH6SEL Mask                */
#define FTM_PWMLOAD_CH6SEL_SHIFT                 (6U)                                                /*!< FTM0_PWMLOAD.CH6SEL Position            */
#define FTM_PWMLOAD_CH6SEL(x)                    (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< FTM0_PWMLOAD.CH6SEL Field               */
#define FTM_PWMLOAD_CH7SEL_MASK                  (0x80U)                                             /*!< FTM0_PWMLOAD.CH7SEL Mask                */
#define FTM_PWMLOAD_CH7SEL_SHIFT                 (7U)                                                /*!< FTM0_PWMLOAD.CH7SEL Position            */
#define FTM_PWMLOAD_CH7SEL(x)                    (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< FTM0_PWMLOAD.CH7SEL Field               */
#define FTM_PWMLOAD_LDOK_MASK                    (0x200U)                                            /*!< FTM0_PWMLOAD.LDOK Mask                  */
#define FTM_PWMLOAD_LDOK_SHIFT                   (9U)                                                /*!< FTM0_PWMLOAD.LDOK Position              */
#define FTM_PWMLOAD_LDOK(x)                      (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< FTM0_PWMLOAD.LDOK Field                 */
/**
 * @} */ /* End group FTM_Register_Masks_GROUP 
 */

/* FTM0 - Peripheral instance base addresses */
#define FTM0_BasePtr                   0x40038000UL //!< Peripheral base address
#define FTM0                           ((FTM_Type *) FTM0_BasePtr) //!< Freescale base pointer
#define FTM0_BASE_PTR                  (FTM0) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM1 (file:FTM1_2CH_ICRST)           ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (2 channels)
 */
/**
* @addtogroup FTM_structs_GROUP FTM struct
* @brief Struct for FTM
* @{
*/
typedef struct {                                /*       FTM1 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control                                           */
   __IO uint32_t  CNT;                          /**< 0004: Counter                                                      */
   __IO uint32_t  MOD;                          /**< 0008: Modulo                                                       */
   struct {
      __IO uint32_t  CnSC;                      /**< 000C: Channel  Status and Control                                  */
      __IO uint32_t  CnV;                       /**< 0010: Channel  Value                                               */
   } CONTROLS[2];                               /**< 000C: (cluster: size=0x0010, 16)                                   */
        uint8_t   RESERVED_1[48];              
   __IO uint32_t  CNTIN;                        /**< 004C: Counter Initial Value                                        */
   __IO uint32_t  STATUS;                       /**< 0050: Capture and Compare Status                                   */
   __IO uint32_t  MODE;                         /**< 0054: Features Mode Selection                                      */
   __IO uint32_t  SYNC;                         /**< 0058: Synchronization                                              */
   __IO uint32_t  OUTINIT;                      /**< 005C: Initial State for Channels Output                            */
   __IO uint32_t  OUTMASK;                      /**< 0060: Output Mask                                                  */
   __IO uint32_t  COMBINE;                      /**< 0064: Function for Linked Channels                                 */
   __IO uint32_t  DEADTIME;                     /**< 0068: Deadtime Insertion Control                                   */
   __IO uint32_t  EXTTRIG;                      /**< 006C: FTM External Trigger                                         */
   __IO uint32_t  POL;                          /**< 0070: Channels Polarity                                            */
   __IO uint32_t  FMS;                          /**< 0074: Fault Mode Status                                            */
   __IO uint32_t  FILTER;                       /**< 0078: Input Capture Filter Control                                 */
   __IO uint32_t  FLTCTRL;                      /**< 007C: Fault Control                                                */
   __IO uint32_t  QDCTRL;                       /**< 0080: Quadrature Decoder Control and Status                        */
   __IO uint32_t  CONF;                         /**< 0084: Configuration                                                */
   __IO uint32_t  FLTPOL;                       /**< 0088: FTM Fault Input Polarity                                     */
   __IO uint32_t  SYNCONF;                      /**< 008C: Synchronization Configuration                                */
   __IO uint32_t  INVCTRL;                      /**< 0090: FTM Inverting Control                                        */
   __IO uint32_t  SWOCTRL;                      /**< 0094: FTM Software Output Control                                  */
   __IO uint32_t  PWMLOAD;                      /**< 0098: FTM PWM Load                                                 */
} FTM1_Type;

/**
 * @} */ /* End group FTM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'FTM1' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup FTM_Register_Masks_GROUP FTM Register Masks
* @brief Register Masks for FTM
* @{
*/
/* ------- SC Bit Fields                            ------ */
/* ------- CNT Bit Fields                           ------ */
/* ------- MOD Bit Fields                           ------ */
/* ------- CnSC Bit Fields                          ------ */
/* ------- CnV Bit Fields                           ------ */
/* ------- CNTIN Bit Fields                         ------ */
/* ------- STATUS Bit Fields                        ------ */
/* ------- MODE Bit Fields                          ------ */
/* ------- SYNC Bit Fields                          ------ */
/* ------- OUTINIT Bit Fields                       ------ */
/* ------- OUTMASK Bit Fields                       ------ */
/* ------- COMBINE Bit Fields                       ------ */
/* ------- DEADTIME Bit Fields                      ------ */
/* ------- EXTTRIG Bit Fields                       ------ */
/* ------- POL Bit Fields                           ------ */
/* ------- FMS Bit Fields                           ------ */
/* ------- FILTER Bit Fields                        ------ */
/* ------- FLTCTRL Bit Fields                       ------ */
/* ------- QDCTRL Bit Fields                        ------ */
/* ------- CONF Bit Fields                          ------ */
/* ------- FLTPOL Bit Fields                        ------ */
/* ------- SYNCONF Bit Fields                       ------ */
/* ------- INVCTRL Bit Fields                       ------ */
/* ------- SWOCTRL Bit Fields                       ------ */
/* ------- PWMLOAD Bit Fields                       ------ */
/**
 * @} */ /* End group FTM_Register_Masks_GROUP 
 */

/* FTM1 - Peripheral instance base addresses */
#define FTM1_BasePtr                   0x40039000UL //!< Peripheral base address
#define FTM1                           ((FTM1_Type *) FTM1_BasePtr) //!< Freescale base pointer
#define FTM1_BASE_PTR                  (FTM1) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup FTM_Peripheral_access_layer_GROUP FTM Peripheral Access Layer
* @brief C Struct for FTM
* @{
*/

/* ================================================================================ */
/* ================           FTM3 (derived from FTM0)             ================ */
/* ================================================================================ */

/**
 * @brief FlexTimer Module (8 channels)
 */

/* FTM3 - Peripheral instance base addresses */
#define FTM3_BasePtr                   0x40026000UL //!< Peripheral base address
#define FTM3                           ((FTM_Type *) FTM3_BasePtr) //!< Freescale base pointer
#define FTM3_BASE_PTR                  (FTM3) //!< Freescale style base pointer
/**
 * @} */ /* End group FTM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIOA (file:GPIOA_0x400FF000)        ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */
/**
* @addtogroup GPIO_structs_GROUP GPIO struct
* @brief Struct for GPIO
* @{
*/
typedef struct {                                /*       GPIOA Structure                                              */
   __IO uint32_t  PDOR;                         /**< 0000: Port Data Output Register                                    */
   __O  uint32_t  PSOR;                         /**< 0004: Port Set Output Register                                     */
   __O  uint32_t  PCOR;                         /**< 0008: Port Clear Output Register                                   */
   __O  uint32_t  PTOR;                         /**< 000C: Port Toggle Output Register                                  */
   __I  uint32_t  PDIR;                         /**< 0010: Port Data Input Register                                     */
   __IO uint32_t  PDDR;                         /**< 0014: Port Data Direction Register                                 */
} GPIO_Type;

/**
 * @} */ /* End group GPIO_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'GPIOA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup GPIO_Register_Masks_GROUP GPIO Register Masks
* @brief Register Masks for GPIO
* @{
*/
/* ------- PDOR Bit Fields                          ------ */
/* ------- PSOR Bit Fields                          ------ */
/* ------- PCOR Bit Fields                          ------ */
/* ------- PTOR Bit Fields                          ------ */
/* ------- PDIR Bit Fields                          ------ */
/* ------- PDDR Bit Fields                          ------ */
/**
 * @} */ /* End group GPIO_Register_Masks_GROUP 
 */

/* GPIOA - Peripheral instance base addresses */
#define GPIOA_BasePtr                  0x400FF000UL //!< Peripheral base address
#define GPIOA                          ((GPIO_Type *) GPIOA_BasePtr) //!< Freescale base pointer
#define GPIOA_BASE_PTR                 (GPIOA) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIOB (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOB - Peripheral instance base addresses */
#define GPIOB_BasePtr                  0x400FF040UL //!< Peripheral base address
#define GPIOB                          ((GPIO_Type *) GPIOB_BasePtr) //!< Freescale base pointer
#define GPIOB_BASE_PTR                 (GPIOB) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIOC (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOC - Peripheral instance base addresses */
#define GPIOC_BasePtr                  0x400FF080UL //!< Peripheral base address
#define GPIOC                          ((GPIO_Type *) GPIOC_BasePtr) //!< Freescale base pointer
#define GPIOC_BASE_PTR                 (GPIOC) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIOD (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOD - Peripheral instance base addresses */
#define GPIOD_BasePtr                  0x400FF0C0UL //!< Peripheral base address
#define GPIOD                          ((GPIO_Type *) GPIOD_BasePtr) //!< Freescale base pointer
#define GPIOD_BASE_PTR                 (GPIOD) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup GPIO_Peripheral_access_layer_GROUP GPIO Peripheral Access Layer
* @brief C Struct for GPIO
* @{
*/

/* ================================================================================ */
/* ================           GPIOE (derived from GPIOA)           ================ */
/* ================================================================================ */

/**
 * @brief General Purpose Input/Output
 */

/* GPIOE - Peripheral instance base addresses */
#define GPIOE_BasePtr                  0x400FF100UL //!< Peripheral base address
#define GPIOE                          ((GPIO_Type *) GPIOE_BasePtr) //!< Freescale base pointer
#define GPIOE_BASE_PTR                 (GPIOE) //!< Freescale style base pointer
/**
 * @} */ /* End group GPIO_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup I2C_Peripheral_access_layer_GROUP I2C Peripheral Access Layer
* @brief C Struct for I2C
* @{
*/

/* ================================================================================ */
/* ================           I2C0 (file:I2C0_F12)                 ================ */
/* ================================================================================ */

/**
 * @brief Inter-Integrated Circuit
 */
/**
* @addtogroup I2C_structs_GROUP I2C struct
* @brief Struct for I2C
* @{
*/
typedef struct {                                /*       I2C0 Structure                                               */
   __IO uint8_t   A1;                           /**< 0000: Address Register 1                                           */
   __IO uint8_t   F;                            /**< 0001: Frequency Divider register                                   */
   __IO uint8_t   C1;                           /**< 0002: Control Register 1                                           */
   __IO uint8_t   S;                            /**< 0003: Status Register                                              */
   __IO uint8_t   D;                            /**< 0004: Data I/O register                                            */
   __IO uint8_t   C2;                           /**< 0005: Control Register 2                                           */
   __IO uint8_t   FLT;                          /**< 0006: Programmable Input Glitch Filter register                    */
   __IO uint8_t   RA;                           /**< 0007: Range Address register                                       */
   __IO uint8_t   SMB;                          /**< 0008: SMBus Control and Status register                            */
   __IO uint8_t   A2;                           /**< 0009: Address Register 2                                           */
   __IO uint8_t   SLTH;                         /**< 000A: SCL Low Timeout Register High                                */
   __IO uint8_t   SLTL;                         /**< 000B: SCL Low Timeout Register Low                                 */
} I2C_Type;

/**
 * @} */ /* End group I2C_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'I2C0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup I2C_Register_Masks_GROUP I2C Register Masks
* @brief Register Masks for I2C
* @{
*/
/* ------- A1 Bit Fields                            ------ */
#define I2C_A1_AD_MASK                           (0xFEU)                                             /*!< I2C0_A1.AD Mask                         */
#define I2C_A1_AD_SHIFT                          (1U)                                                /*!< I2C0_A1.AD Position                     */
#define I2C_A1_AD(x)                             (((uint8_t)(((uint8_t)(x))<<1U))&0xFEUL)            /*!< I2C0_A1.AD Field                        */
/* ------- F Bit Fields                             ------ */
#define I2C_F_ICR_MASK                           (0x3FU)                                             /*!< I2C0_F.ICR Mask                         */
#define I2C_F_ICR_SHIFT                          (0U)                                                /*!< I2C0_F.ICR Position                     */
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<0U))&0x3FUL)            /*!< I2C0_F.ICR Field                        */
#define I2C_F_MULT_MASK                          (0xC0U)                                             /*!< I2C0_F.MULT Mask                        */
#define I2C_F_MULT_SHIFT                         (6U)                                                /*!< I2C0_F.MULT Position                    */
#define I2C_F_MULT(x)                            (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< I2C0_F.MULT Field                       */
/* ------- C1 Bit Fields                            ------ */
#define I2C_C1_DMAEN_MASK                        (0x1U)                                              /*!< I2C0_C1.DMAEN Mask                      */
#define I2C_C1_DMAEN_SHIFT                       (0U)                                                /*!< I2C0_C1.DMAEN Position                  */
#define I2C_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< I2C0_C1.DMAEN Field                     */
#define I2C_C1_WUEN_MASK                         (0x2U)                                              /*!< I2C0_C1.WUEN Mask                       */
#define I2C_C1_WUEN_SHIFT                        (1U)                                                /*!< I2C0_C1.WUEN Position                   */
#define I2C_C1_WUEN(x)                           (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< I2C0_C1.WUEN Field                      */
#define I2C_C1_RSTA_MASK                         (0x4U)                                              /*!< I2C0_C1.RSTA Mask                       */
#define I2C_C1_RSTA_SHIFT                        (2U)                                                /*!< I2C0_C1.RSTA Position                   */
#define I2C_C1_RSTA(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< I2C0_C1.RSTA Field                      */
#define I2C_C1_TXAK_MASK                         (0x8U)                                              /*!< I2C0_C1.TXAK Mask                       */
#define I2C_C1_TXAK_SHIFT                        (3U)                                                /*!< I2C0_C1.TXAK Position                   */
#define I2C_C1_TXAK(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< I2C0_C1.TXAK Field                      */
#define I2C_C1_TX_MASK                           (0x10U)                                             /*!< I2C0_C1.TX Mask                         */
#define I2C_C1_TX_SHIFT                          (4U)                                                /*!< I2C0_C1.TX Position                     */
#define I2C_C1_TX(x)                             (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< I2C0_C1.TX Field                        */
#define I2C_C1_MST_MASK                          (0x20U)                                             /*!< I2C0_C1.MST Mask                        */
#define I2C_C1_MST_SHIFT                         (5U)                                                /*!< I2C0_C1.MST Position                    */
#define I2C_C1_MST(x)                            (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< I2C0_C1.MST Field                       */
#define I2C_C1_IICIE_MASK                        (0x40U)                                             /*!< I2C0_C1.IICIE Mask                      */
#define I2C_C1_IICIE_SHIFT                       (6U)                                                /*!< I2C0_C1.IICIE Position                  */
#define I2C_C1_IICIE(x)                          (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< I2C0_C1.IICIE Field                     */
#define I2C_C1_IICEN_MASK                        (0x80U)                                             /*!< I2C0_C1.IICEN Mask                      */
#define I2C_C1_IICEN_SHIFT                       (7U)                                                /*!< I2C0_C1.IICEN Position                  */
#define I2C_C1_IICEN(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< I2C0_C1.IICEN Field                     */
/* ------- S Bit Fields                             ------ */
#define I2C_S_RXAK_MASK                          (0x1U)                                              /*!< I2C0_S.RXAK Mask                        */
#define I2C_S_RXAK_SHIFT                         (0U)                                                /*!< I2C0_S.RXAK Position                    */
#define I2C_S_RXAK(x)                            (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< I2C0_S.RXAK Field                       */
#define I2C_S_IICIF_MASK                         (0x2U)                                              /*!< I2C0_S.IICIF Mask                       */
#define I2C_S_IICIF_SHIFT                        (1U)                                                /*!< I2C0_S.IICIF Position                   */
#define I2C_S_IICIF(x)                           (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< I2C0_S.IICIF Field                      */
#define I2C_S_SRW_MASK                           (0x4U)                                              /*!< I2C0_S.SRW Mask                         */
#define I2C_S_SRW_SHIFT                          (2U)                                                /*!< I2C0_S.SRW Position                     */
#define I2C_S_SRW(x)                             (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< I2C0_S.SRW Field                        */
#define I2C_S_RAM_MASK                           (0x8U)                                              /*!< I2C0_S.RAM Mask                         */
#define I2C_S_RAM_SHIFT                          (3U)                                                /*!< I2C0_S.RAM Position                     */
#define I2C_S_RAM(x)                             (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< I2C0_S.RAM Field                        */
#define I2C_S_ARBL_MASK                          (0x10U)                                             /*!< I2C0_S.ARBL Mask                        */
#define I2C_S_ARBL_SHIFT                         (4U)                                                /*!< I2C0_S.ARBL Position                    */
#define I2C_S_ARBL(x)                            (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< I2C0_S.ARBL Field                       */
#define I2C_S_BUSY_MASK                          (0x20U)                                             /*!< I2C0_S.BUSY Mask                        */
#define I2C_S_BUSY_SHIFT                         (5U)                                                /*!< I2C0_S.BUSY Position                    */
#define I2C_S_BUSY(x)                            (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< I2C0_S.BUSY Field                       */
#define I2C_S_IAAS_MASK                          (0x40U)                                             /*!< I2C0_S.IAAS Mask                        */
#define I2C_S_IAAS_SHIFT                         (6U)                                                /*!< I2C0_S.IAAS Position                    */
#define I2C_S_IAAS(x)                            (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< I2C0_S.IAAS Field                       */
#define I2C_S_TCF_MASK                           (0x80U)                                             /*!< I2C0_S.TCF Mask                         */
#define I2C_S_TCF_SHIFT                          (7U)                                                /*!< I2C0_S.TCF Position                     */
#define I2C_S_TCF(x)                             (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< I2C0_S.TCF Field                        */
/* ------- D Bit Fields                             ------ */
#define I2C_D_DATA_MASK                          (0xFFU)                                             /*!< I2C0_D.DATA Mask                        */
#define I2C_D_DATA_SHIFT                         (0U)                                                /*!< I2C0_D.DATA Position                    */
#define I2C_D_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< I2C0_D.DATA Field                       */
/* ------- C2 Bit Fields                            ------ */
#define I2C_C2_AD_MASK                           (0x7U)                                              /*!< I2C0_C2.AD Mask                         */
#define I2C_C2_AD_SHIFT                          (0U)                                                /*!< I2C0_C2.AD Position                     */
#define I2C_C2_AD(x)                             (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< I2C0_C2.AD Field                        */
#define I2C_C2_RMEN_MASK                         (0x8U)                                              /*!< I2C0_C2.RMEN Mask                       */
#define I2C_C2_RMEN_SHIFT                        (3U)                                                /*!< I2C0_C2.RMEN Position                   */
#define I2C_C2_RMEN(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< I2C0_C2.RMEN Field                      */
#define I2C_C2_SBRC_MASK                         (0x10U)                                             /*!< I2C0_C2.SBRC Mask                       */
#define I2C_C2_SBRC_SHIFT                        (4U)                                                /*!< I2C0_C2.SBRC Position                   */
#define I2C_C2_SBRC(x)                           (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< I2C0_C2.SBRC Field                      */
#define I2C_C2_HDRS_MASK                         (0x20U)                                             /*!< I2C0_C2.HDRS Mask                       */
#define I2C_C2_HDRS_SHIFT                        (5U)                                                /*!< I2C0_C2.HDRS Position                   */
#define I2C_C2_HDRS(x)                           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< I2C0_C2.HDRS Field                      */
#define I2C_C2_ADEXT_MASK                        (0x40U)                                             /*!< I2C0_C2.ADEXT Mask                      */
#define I2C_C2_ADEXT_SHIFT                       (6U)                                                /*!< I2C0_C2.ADEXT Position                  */
#define I2C_C2_ADEXT(x)                          (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< I2C0_C2.ADEXT Field                     */
#define I2C_C2_GCAEN_MASK                        (0x80U)                                             /*!< I2C0_C2.GCAEN Mask                      */
#define I2C_C2_GCAEN_SHIFT                       (7U)                                                /*!< I2C0_C2.GCAEN Position                  */
#define I2C_C2_GCAEN(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< I2C0_C2.GCAEN Field                     */
/* ------- FLT Bit Fields                           ------ */
#define I2C_FLT_FLT_MASK                         (0xFU)                                              /*!< I2C0_FLT.FLT Mask                       */
#define I2C_FLT_FLT_SHIFT                        (0U)                                                /*!< I2C0_FLT.FLT Position                   */
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< I2C0_FLT.FLT Field                      */
#define I2C_FLT_STARTF_MASK                      (0x10U)                                             /*!< I2C0_FLT.STARTF Mask                    */
#define I2C_FLT_STARTF_SHIFT                     (4U)                                                /*!< I2C0_FLT.STARTF Position                */
#define I2C_FLT_STARTF(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< I2C0_FLT.STARTF Field                   */
#define I2C_FLT_SSIE_MASK                        (0x20U)                                             /*!< I2C0_FLT.SSIE Mask                      */
#define I2C_FLT_SSIE_SHIFT                       (5U)                                                /*!< I2C0_FLT.SSIE Position                  */
#define I2C_FLT_SSIE(x)                          (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< I2C0_FLT.SSIE Field                     */
#define I2C_FLT_STOPF_MASK                       (0x40U)                                             /*!< I2C0_FLT.STOPF Mask                     */
#define I2C_FLT_STOPF_SHIFT                      (6U)                                                /*!< I2C0_FLT.STOPF Position                 */
#define I2C_FLT_STOPF(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< I2C0_FLT.STOPF Field                    */
#define I2C_FLT_SHEN_MASK                        (0x80U)                                             /*!< I2C0_FLT.SHEN Mask                      */
#define I2C_FLT_SHEN_SHIFT                       (7U)                                                /*!< I2C0_FLT.SHEN Position                  */
#define I2C_FLT_SHEN(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< I2C0_FLT.SHEN Field                     */
/* ------- RA Bit Fields                            ------ */
#define I2C_RA_RAD_MASK                          (0xFEU)                                             /*!< I2C0_RA.RAD Mask                        */
#define I2C_RA_RAD_SHIFT                         (1U)                                                /*!< I2C0_RA.RAD Position                    */
#define I2C_RA_RAD(x)                            (((uint8_t)(((uint8_t)(x))<<1U))&0xFEUL)            /*!< I2C0_RA.RAD Field                       */
/* ------- SMB Bit Fields                           ------ */
#define I2C_SMB_SHTF2IE_MASK                     (0x1U)                                              /*!< I2C0_SMB.SHTF2IE Mask                   */
#define I2C_SMB_SHTF2IE_SHIFT                    (0U)                                                /*!< I2C0_SMB.SHTF2IE Position               */
#define I2C_SMB_SHTF2IE(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< I2C0_SMB.SHTF2IE Field                  */
#define I2C_SMB_SHTF2_MASK                       (0x2U)                                              /*!< I2C0_SMB.SHTF2 Mask                     */
#define I2C_SMB_SHTF2_SHIFT                      (1U)                                                /*!< I2C0_SMB.SHTF2 Position                 */
#define I2C_SMB_SHTF2(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< I2C0_SMB.SHTF2 Field                    */
#define I2C_SMB_SHTF1_MASK                       (0x4U)                                              /*!< I2C0_SMB.SHTF1 Mask                     */
#define I2C_SMB_SHTF1_SHIFT                      (2U)                                                /*!< I2C0_SMB.SHTF1 Position                 */
#define I2C_SMB_SHTF1(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< I2C0_SMB.SHTF1 Field                    */
#define I2C_SMB_SLTF_MASK                        (0x8U)                                              /*!< I2C0_SMB.SLTF Mask                      */
#define I2C_SMB_SLTF_SHIFT                       (3U)                                                /*!< I2C0_SMB.SLTF Position                  */
#define I2C_SMB_SLTF(x)                          (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< I2C0_SMB.SLTF Field                     */
#define I2C_SMB_TCKSEL_MASK                      (0x10U)                                             /*!< I2C0_SMB.TCKSEL Mask                    */
#define I2C_SMB_TCKSEL_SHIFT                     (4U)                                                /*!< I2C0_SMB.TCKSEL Position                */
#define I2C_SMB_TCKSEL(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< I2C0_SMB.TCKSEL Field                   */
#define I2C_SMB_SIICAEN_MASK                     (0x20U)                                             /*!< I2C0_SMB.SIICAEN Mask                   */
#define I2C_SMB_SIICAEN_SHIFT                    (5U)                                                /*!< I2C0_SMB.SIICAEN Position               */
#define I2C_SMB_SIICAEN(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< I2C0_SMB.SIICAEN Field                  */
#define I2C_SMB_ALERTEN_MASK                     (0x40U)                                             /*!< I2C0_SMB.ALERTEN Mask                   */
#define I2C_SMB_ALERTEN_SHIFT                    (6U)                                                /*!< I2C0_SMB.ALERTEN Position               */
#define I2C_SMB_ALERTEN(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< I2C0_SMB.ALERTEN Field                  */
#define I2C_SMB_FACK_MASK                        (0x80U)                                             /*!< I2C0_SMB.FACK Mask                      */
#define I2C_SMB_FACK_SHIFT                       (7U)                                                /*!< I2C0_SMB.FACK Position                  */
#define I2C_SMB_FACK(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< I2C0_SMB.FACK Field                     */
/* ------- A2 Bit Fields                            ------ */
#define I2C_A2_SAD_MASK                          (0xFEU)                                             /*!< I2C0_A2.SAD Mask                        */
#define I2C_A2_SAD_SHIFT                         (1U)                                                /*!< I2C0_A2.SAD Position                    */
#define I2C_A2_SAD(x)                            (((uint8_t)(((uint8_t)(x))<<1U))&0xFEUL)            /*!< I2C0_A2.SAD Field                       */
/* ------- SLTH Bit Fields                          ------ */
#define I2C_SLTH_SSLT_MASK                       (0xFFU)                                             /*!< I2C0_SLTH.SSLT Mask                     */
#define I2C_SLTH_SSLT_SHIFT                      (0U)                                                /*!< I2C0_SLTH.SSLT Position                 */
#define I2C_SLTH_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< I2C0_SLTH.SSLT Field                    */
/* ------- SLTL Bit Fields                          ------ */
#define I2C_SLTL_SSLT_MASK                       (0xFFU)                                             /*!< I2C0_SLTL.SSLT Mask                     */
#define I2C_SLTL_SSLT_SHIFT                      (0U)                                                /*!< I2C0_SLTL.SSLT Position                 */
#define I2C_SLTL_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< I2C0_SLTL.SSLT Field                    */
/**
 * @} */ /* End group I2C_Register_Masks_GROUP 
 */

/* I2C0 - Peripheral instance base addresses */
#define I2C0_BasePtr                   0x40066000UL //!< Peripheral base address
#define I2C0                           ((I2C_Type *) I2C0_BasePtr) //!< Freescale base pointer
#define I2C0_BASE_PTR                  (I2C0) //!< Freescale style base pointer
/**
 * @} */ /* End group I2C_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LLWU_Peripheral_access_layer_GROUP LLWU Peripheral Access Layer
* @brief C Struct for LLWU
* @{
*/

/* ================================================================================ */
/* ================           LLWU (file:LLWU_PE8_FILT2)           ================ */
/* ================================================================================ */

/**
 * @brief Low leakage wakeup unit
 */
/**
* @addtogroup LLWU_structs_GROUP LLWU struct
* @brief Struct for LLWU
* @{
*/
typedef struct {                                /*       LLWU Structure                                               */
   union {                                      /**< 0000: (size=0008)                                                  */
      __IO uint8_t   PE[8];                     /**< 0000: Pin Enable  Register                                         */
      struct {                                  /**< 0000: (size=0008)                                                  */
         __IO uint8_t   PE1;                    /**< 0000: Pin Enable 1 Register                                        */
         __IO uint8_t   PE2;                    /**< 0001: Pin Enable 2 Register                                        */
         __IO uint8_t   PE3;                    /**< 0002: Pin Enable 3 Register                                        */
         __IO uint8_t   PE4;                    /**< 0003: Pin Enable 4 Register                                        */
         __IO uint8_t   PE5;                    /**< 0004: Pin Enable 5 Register                                        */
         __IO uint8_t   PE6;                    /**< 0005: Pin Enable 6 Register                                        */
         __IO uint8_t   PE7;                    /**< 0006: Pin Enable 7 Register                                        */
         __IO uint8_t   PE8;                    /**< 0007: Pin Enable 8 Register                                        */
      };
   };
   __IO uint8_t   ME;                           /**< 0008: Module Enable Register                                       */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint8_t   PF[4];                     /**< 0009: Pin Flag  Register                                           */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint8_t   PF1;                    /**< 0009: Pin Flag 1 Register                                          */
         __IO uint8_t   PF2;                    /**< 000A: Pin Flag 2 Register                                          */
         __IO uint8_t   PF3;                    /**< 000B: Pin Flag 3 Register                                          */
         __IO uint8_t   PF4;                    /**< 000C: Pin Flag 4 register                                          */
      };
   };
   __I  uint8_t   MF;                           /**< 000D: Module Flag Register                                         */
   union {                                      /**< 0000: (size=0002)                                                  */
      struct {                                  /**< 0000: (size=0002)                                                  */
      __IO uint8_t   FILT1;                     /**< 000E: Pin Filter 1 register                                        */
      __IO uint8_t   FILT2;                     /**< 000F: Pin Filter 2 register                                        */
      };
      __IO uint8_t   FILT[2];                   /**< 000E: Pin Filter  register                                         */
   };
} LLWU_Type;

/**
 * @} */ /* End group LLWU_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LLWU' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup LLWU_Register_Masks_GROUP LLWU Register Masks
* @brief Register Masks for LLWU
* @{
*/
/* ------- PE Bit Fields                            ------ */
#define LLWU_PE_WUPE0_MASK                       (0x3U)                                              /*!< LLWU_PE.WUPE0 Mask                      */
#define LLWU_PE_WUPE0_SHIFT                      (0U)                                                /*!< LLWU_PE.WUPE0 Position                  */
#define LLWU_PE_WUPE0(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE.WUPE0 Field                     */
#define LLWU_PE_WUPE1_MASK                       (0xCU)                                              /*!< LLWU_PE.WUPE1 Mask                      */
#define LLWU_PE_WUPE1_SHIFT                      (2U)                                                /*!< LLWU_PE.WUPE1 Position                  */
#define LLWU_PE_WUPE1(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE.WUPE1 Field                     */
#define LLWU_PE_WUPE2_MASK                       (0x30U)                                             /*!< LLWU_PE.WUPE2 Mask                      */
#define LLWU_PE_WUPE2_SHIFT                      (4U)                                                /*!< LLWU_PE.WUPE2 Position                  */
#define LLWU_PE_WUPE2(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE.WUPE2 Field                     */
#define LLWU_PE_WUPE3_MASK                       (0xC0U)                                             /*!< LLWU_PE.WUPE3 Mask                      */
#define LLWU_PE_WUPE3_SHIFT                      (6U)                                                /*!< LLWU_PE.WUPE3 Position                  */
#define LLWU_PE_WUPE3(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE.WUPE3 Field                     */
/* ------- PE1 Bit Fields                           ------ */
#define LLWU_PE1_WUPE0_MASK                      (0x3U)                                              /*!< LLWU_PE1.WUPE0 Mask                     */
#define LLWU_PE1_WUPE0_SHIFT                     (0U)                                                /*!< LLWU_PE1.WUPE0 Position                 */
#define LLWU_PE1_WUPE0(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE1.WUPE0 Field                    */
#define LLWU_PE1_WUPE1_MASK                      (0xCU)                                              /*!< LLWU_PE1.WUPE1 Mask                     */
#define LLWU_PE1_WUPE1_SHIFT                     (2U)                                                /*!< LLWU_PE1.WUPE1 Position                 */
#define LLWU_PE1_WUPE1(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE1.WUPE1 Field                    */
#define LLWU_PE1_WUPE2_MASK                      (0x30U)                                             /*!< LLWU_PE1.WUPE2 Mask                     */
#define LLWU_PE1_WUPE2_SHIFT                     (4U)                                                /*!< LLWU_PE1.WUPE2 Position                 */
#define LLWU_PE1_WUPE2(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE1.WUPE2 Field                    */
#define LLWU_PE1_WUPE3_MASK                      (0xC0U)                                             /*!< LLWU_PE1.WUPE3 Mask                     */
#define LLWU_PE1_WUPE3_SHIFT                     (6U)                                                /*!< LLWU_PE1.WUPE3 Position                 */
#define LLWU_PE1_WUPE3(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE1.WUPE3 Field                    */
/* ------- PE2 Bit Fields                           ------ */
#define LLWU_PE2_WUPE4_MASK                      (0x3U)                                              /*!< LLWU_PE2.WUPE4 Mask                     */
#define LLWU_PE2_WUPE4_SHIFT                     (0U)                                                /*!< LLWU_PE2.WUPE4 Position                 */
#define LLWU_PE2_WUPE4(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE2.WUPE4 Field                    */
#define LLWU_PE2_WUPE5_MASK                      (0xCU)                                              /*!< LLWU_PE2.WUPE5 Mask                     */
#define LLWU_PE2_WUPE5_SHIFT                     (2U)                                                /*!< LLWU_PE2.WUPE5 Position                 */
#define LLWU_PE2_WUPE5(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE2.WUPE5 Field                    */
#define LLWU_PE2_WUPE6_MASK                      (0x30U)                                             /*!< LLWU_PE2.WUPE6 Mask                     */
#define LLWU_PE2_WUPE6_SHIFT                     (4U)                                                /*!< LLWU_PE2.WUPE6 Position                 */
#define LLWU_PE2_WUPE6(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE2.WUPE6 Field                    */
#define LLWU_PE2_WUPE7_MASK                      (0xC0U)                                             /*!< LLWU_PE2.WUPE7 Mask                     */
#define LLWU_PE2_WUPE7_SHIFT                     (6U)                                                /*!< LLWU_PE2.WUPE7 Position                 */
#define LLWU_PE2_WUPE7(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE2.WUPE7 Field                    */
/* ------- PE3 Bit Fields                           ------ */
#define LLWU_PE3_WUPE8_MASK                      (0x3U)                                              /*!< LLWU_PE3.WUPE8 Mask                     */
#define LLWU_PE3_WUPE8_SHIFT                     (0U)                                                /*!< LLWU_PE3.WUPE8 Position                 */
#define LLWU_PE3_WUPE8(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE3.WUPE8 Field                    */
#define LLWU_PE3_WUPE9_MASK                      (0xCU)                                              /*!< LLWU_PE3.WUPE9 Mask                     */
#define LLWU_PE3_WUPE9_SHIFT                     (2U)                                                /*!< LLWU_PE3.WUPE9 Position                 */
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE3.WUPE9 Field                    */
#define LLWU_PE3_WUPE10_MASK                     (0x30U)                                             /*!< LLWU_PE3.WUPE10 Mask                    */
#define LLWU_PE3_WUPE10_SHIFT                    (4U)                                                /*!< LLWU_PE3.WUPE10 Position                */
#define LLWU_PE3_WUPE10(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE3.WUPE10 Field                   */
#define LLWU_PE3_WUPE11_MASK                     (0xC0U)                                             /*!< LLWU_PE3.WUPE11 Mask                    */
#define LLWU_PE3_WUPE11_SHIFT                    (6U)                                                /*!< LLWU_PE3.WUPE11 Position                */
#define LLWU_PE3_WUPE11(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE3.WUPE11 Field                   */
/* ------- PE4 Bit Fields                           ------ */
#define LLWU_PE4_WUPE12_MASK                     (0x3U)                                              /*!< LLWU_PE4.WUPE12 Mask                    */
#define LLWU_PE4_WUPE12_SHIFT                    (0U)                                                /*!< LLWU_PE4.WUPE12 Position                */
#define LLWU_PE4_WUPE12(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE4.WUPE12 Field                   */
#define LLWU_PE4_WUPE13_MASK                     (0xCU)                                              /*!< LLWU_PE4.WUPE13 Mask                    */
#define LLWU_PE4_WUPE13_SHIFT                    (2U)                                                /*!< LLWU_PE4.WUPE13 Position                */
#define LLWU_PE4_WUPE13(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE4.WUPE13 Field                   */
#define LLWU_PE4_WUPE14_MASK                     (0x30U)                                             /*!< LLWU_PE4.WUPE14 Mask                    */
#define LLWU_PE4_WUPE14_SHIFT                    (4U)                                                /*!< LLWU_PE4.WUPE14 Position                */
#define LLWU_PE4_WUPE14(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE4.WUPE14 Field                   */
#define LLWU_PE4_WUPE15_MASK                     (0xC0U)                                             /*!< LLWU_PE4.WUPE15 Mask                    */
#define LLWU_PE4_WUPE15_SHIFT                    (6U)                                                /*!< LLWU_PE4.WUPE15 Position                */
#define LLWU_PE4_WUPE15(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE4.WUPE15 Field                   */
/* ------- PE5 Bit Fields                           ------ */
#define LLWU_PE5_WUPE16_MASK                     (0x3U)                                              /*!< LLWU_PE5.WUPE16 Mask                    */
#define LLWU_PE5_WUPE16_SHIFT                    (0U)                                                /*!< LLWU_PE5.WUPE16 Position                */
#define LLWU_PE5_WUPE16(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE5.WUPE16 Field                   */
#define LLWU_PE5_WUPE17_MASK                     (0xCU)                                              /*!< LLWU_PE5.WUPE17 Mask                    */
#define LLWU_PE5_WUPE17_SHIFT                    (2U)                                                /*!< LLWU_PE5.WUPE17 Position                */
#define LLWU_PE5_WUPE17(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE5.WUPE17 Field                   */
#define LLWU_PE5_WUPE18_MASK                     (0x30U)                                             /*!< LLWU_PE5.WUPE18 Mask                    */
#define LLWU_PE5_WUPE18_SHIFT                    (4U)                                                /*!< LLWU_PE5.WUPE18 Position                */
#define LLWU_PE5_WUPE18(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE5.WUPE18 Field                   */
#define LLWU_PE5_WUPE19_MASK                     (0xC0U)                                             /*!< LLWU_PE5.WUPE19 Mask                    */
#define LLWU_PE5_WUPE19_SHIFT                    (6U)                                                /*!< LLWU_PE5.WUPE19 Position                */
#define LLWU_PE5_WUPE19(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE5.WUPE19 Field                   */
/* ------- PE6 Bit Fields                           ------ */
#define LLWU_PE6_WUPE20_MASK                     (0x3U)                                              /*!< LLWU_PE6.WUPE20 Mask                    */
#define LLWU_PE6_WUPE20_SHIFT                    (0U)                                                /*!< LLWU_PE6.WUPE20 Position                */
#define LLWU_PE6_WUPE20(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE6.WUPE20 Field                   */
#define LLWU_PE6_WUPE21_MASK                     (0xCU)                                              /*!< LLWU_PE6.WUPE21 Mask                    */
#define LLWU_PE6_WUPE21_SHIFT                    (2U)                                                /*!< LLWU_PE6.WUPE21 Position                */
#define LLWU_PE6_WUPE21(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE6.WUPE21 Field                   */
#define LLWU_PE6_WUPE22_MASK                     (0x30U)                                             /*!< LLWU_PE6.WUPE22 Mask                    */
#define LLWU_PE6_WUPE22_SHIFT                    (4U)                                                /*!< LLWU_PE6.WUPE22 Position                */
#define LLWU_PE6_WUPE22(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE6.WUPE22 Field                   */
#define LLWU_PE6_WUPE23_MASK                     (0xC0U)                                             /*!< LLWU_PE6.WUPE23 Mask                    */
#define LLWU_PE6_WUPE23_SHIFT                    (6U)                                                /*!< LLWU_PE6.WUPE23 Position                */
#define LLWU_PE6_WUPE23(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE6.WUPE23 Field                   */
/* ------- PE7 Bit Fields                           ------ */
#define LLWU_PE7_WUPE24_MASK                     (0x3U)                                              /*!< LLWU_PE7.WUPE24 Mask                    */
#define LLWU_PE7_WUPE24_SHIFT                    (0U)                                                /*!< LLWU_PE7.WUPE24 Position                */
#define LLWU_PE7_WUPE24(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE7.WUPE24 Field                   */
#define LLWU_PE7_WUPE25_MASK                     (0xCU)                                              /*!< LLWU_PE7.WUPE25 Mask                    */
#define LLWU_PE7_WUPE25_SHIFT                    (2U)                                                /*!< LLWU_PE7.WUPE25 Position                */
#define LLWU_PE7_WUPE25(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE7.WUPE25 Field                   */
#define LLWU_PE7_WUPE26_MASK                     (0x30U)                                             /*!< LLWU_PE7.WUPE26 Mask                    */
#define LLWU_PE7_WUPE26_SHIFT                    (4U)                                                /*!< LLWU_PE7.WUPE26 Position                */
#define LLWU_PE7_WUPE26(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE7.WUPE26 Field                   */
#define LLWU_PE7_WUPE27_MASK                     (0xC0U)                                             /*!< LLWU_PE7.WUPE27 Mask                    */
#define LLWU_PE7_WUPE27_SHIFT                    (6U)                                                /*!< LLWU_PE7.WUPE27 Position                */
#define LLWU_PE7_WUPE27(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE7.WUPE27 Field                   */
/* ------- PE8 Bit Fields                           ------ */
#define LLWU_PE8_WUPE28_MASK                     (0x3U)                                              /*!< LLWU_PE8.WUPE28 Mask                    */
#define LLWU_PE8_WUPE28_SHIFT                    (0U)                                                /*!< LLWU_PE8.WUPE28 Position                */
#define LLWU_PE8_WUPE28(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< LLWU_PE8.WUPE28 Field                   */
#define LLWU_PE8_WUPE29_MASK                     (0xCU)                                              /*!< LLWU_PE8.WUPE29 Mask                    */
#define LLWU_PE8_WUPE29_SHIFT                    (2U)                                                /*!< LLWU_PE8.WUPE29 Position                */
#define LLWU_PE8_WUPE29(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< LLWU_PE8.WUPE29 Field                   */
#define LLWU_PE8_WUPE30_MASK                     (0x30U)                                             /*!< LLWU_PE8.WUPE30 Mask                    */
#define LLWU_PE8_WUPE30_SHIFT                    (4U)                                                /*!< LLWU_PE8.WUPE30 Position                */
#define LLWU_PE8_WUPE30(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< LLWU_PE8.WUPE30 Field                   */
#define LLWU_PE8_WUPE31_MASK                     (0xC0U)                                             /*!< LLWU_PE8.WUPE31 Mask                    */
#define LLWU_PE8_WUPE31_SHIFT                    (6U)                                                /*!< LLWU_PE8.WUPE31 Position                */
#define LLWU_PE8_WUPE31(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< LLWU_PE8.WUPE31 Field                   */
/* ------- ME Bit Fields                            ------ */
#define LLWU_ME_WUME0_MASK                       (0x1U)                                              /*!< LLWU_ME.WUME0 Mask                      */
#define LLWU_ME_WUME0_SHIFT                      (0U)                                                /*!< LLWU_ME.WUME0 Position                  */
#define LLWU_ME_WUME0(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< LLWU_ME.WUME0 Field                     */
#define LLWU_ME_WUME1_MASK                       (0x2U)                                              /*!< LLWU_ME.WUME1 Mask                      */
#define LLWU_ME_WUME1_SHIFT                      (1U)                                                /*!< LLWU_ME.WUME1 Position                  */
#define LLWU_ME_WUME1(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< LLWU_ME.WUME1 Field                     */
#define LLWU_ME_WUME2_MASK                       (0x4U)                                              /*!< LLWU_ME.WUME2 Mask                      */
#define LLWU_ME_WUME2_SHIFT                      (2U)                                                /*!< LLWU_ME.WUME2 Position                  */
#define LLWU_ME_WUME2(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< LLWU_ME.WUME2 Field                     */
#define LLWU_ME_WUME3_MASK                       (0x8U)                                              /*!< LLWU_ME.WUME3 Mask                      */
#define LLWU_ME_WUME3_SHIFT                      (3U)                                                /*!< LLWU_ME.WUME3 Position                  */
#define LLWU_ME_WUME3(x)                         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< LLWU_ME.WUME3 Field                     */
#define LLWU_ME_WUME4_MASK                       (0x10U)                                             /*!< LLWU_ME.WUME4 Mask                      */
#define LLWU_ME_WUME4_SHIFT                      (4U)                                                /*!< LLWU_ME.WUME4 Position                  */
#define LLWU_ME_WUME4(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< LLWU_ME.WUME4 Field                     */
#define LLWU_ME_WUME5_MASK                       (0x20U)                                             /*!< LLWU_ME.WUME5 Mask                      */
#define LLWU_ME_WUME5_SHIFT                      (5U)                                                /*!< LLWU_ME.WUME5 Position                  */
#define LLWU_ME_WUME5(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< LLWU_ME.WUME5 Field                     */
#define LLWU_ME_WUME6_MASK                       (0x40U)                                             /*!< LLWU_ME.WUME6 Mask                      */
#define LLWU_ME_WUME6_SHIFT                      (6U)                                                /*!< LLWU_ME.WUME6 Position                  */
#define LLWU_ME_WUME6(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< LLWU_ME.WUME6 Field                     */
#define LLWU_ME_WUME7_MASK                       (0x80U)                                             /*!< LLWU_ME.WUME7 Mask                      */
#define LLWU_ME_WUME7_SHIFT                      (7U)                                                /*!< LLWU_ME.WUME7 Position                  */
#define LLWU_ME_WUME7(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_ME.WUME7 Field                     */
/* ------- PF Bit Fields                            ------ */
#define LLWU_PF_WUF0_MASK                        (0x1U)                                              /*!< LLWU_PF.WUF0 Mask                       */
#define LLWU_PF_WUF0_SHIFT                       (0U)                                                /*!< LLWU_PF.WUF0 Position                   */
#define LLWU_PF_WUF0(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< LLWU_PF.WUF0 Field                      */
#define LLWU_PF_WUF1_MASK                        (0x2U)                                              /*!< LLWU_PF.WUF1 Mask                       */
#define LLWU_PF_WUF1_SHIFT                       (1U)                                                /*!< LLWU_PF.WUF1 Position                   */
#define LLWU_PF_WUF1(x)                          (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< LLWU_PF.WUF1 Field                      */
#define LLWU_PF_WUF2_MASK                        (0x4U)                                              /*!< LLWU_PF.WUF2 Mask                       */
#define LLWU_PF_WUF2_SHIFT                       (2U)                                                /*!< LLWU_PF.WUF2 Position                   */
#define LLWU_PF_WUF2(x)                          (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< LLWU_PF.WUF2 Field                      */
#define LLWU_PF_WUF3_MASK                        (0x8U)                                              /*!< LLWU_PF.WUF3 Mask                       */
#define LLWU_PF_WUF3_SHIFT                       (3U)                                                /*!< LLWU_PF.WUF3 Position                   */
#define LLWU_PF_WUF3(x)                          (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< LLWU_PF.WUF3 Field                      */
#define LLWU_PF_WUF4_MASK                        (0x10U)                                             /*!< LLWU_PF.WUF4 Mask                       */
#define LLWU_PF_WUF4_SHIFT                       (4U)                                                /*!< LLWU_PF.WUF4 Position                   */
#define LLWU_PF_WUF4(x)                          (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< LLWU_PF.WUF4 Field                      */
#define LLWU_PF_WUF5_MASK                        (0x20U)                                             /*!< LLWU_PF.WUF5 Mask                       */
#define LLWU_PF_WUF5_SHIFT                       (5U)                                                /*!< LLWU_PF.WUF5 Position                   */
#define LLWU_PF_WUF5(x)                          (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< LLWU_PF.WUF5 Field                      */
#define LLWU_PF_WUF6_MASK                        (0x40U)                                             /*!< LLWU_PF.WUF6 Mask                       */
#define LLWU_PF_WUF6_SHIFT                       (6U)                                                /*!< LLWU_PF.WUF6 Position                   */
#define LLWU_PF_WUF6(x)                          (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< LLWU_PF.WUF6 Field                      */
#define LLWU_PF_WUF7_MASK                        (0x80U)                                             /*!< LLWU_PF.WUF7 Mask                       */
#define LLWU_PF_WUF7_SHIFT                       (7U)                                                /*!< LLWU_PF.WUF7 Position                   */
#define LLWU_PF_WUF7(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_PF.WUF7 Field                      */
/* ------- PF1 Bit Fields                           ------ */
#define LLWU_PF1_WUF0_MASK                       (0x1U)                                              /*!< LLWU_PF1.WUF0 Mask                      */
#define LLWU_PF1_WUF0_SHIFT                      (0U)                                                /*!< LLWU_PF1.WUF0 Position                  */
#define LLWU_PF1_WUF0(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< LLWU_PF1.WUF0 Field                     */
#define LLWU_PF1_WUF1_MASK                       (0x2U)                                              /*!< LLWU_PF1.WUF1 Mask                      */
#define LLWU_PF1_WUF1_SHIFT                      (1U)                                                /*!< LLWU_PF1.WUF1 Position                  */
#define LLWU_PF1_WUF1(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< LLWU_PF1.WUF1 Field                     */
#define LLWU_PF1_WUF2_MASK                       (0x4U)                                              /*!< LLWU_PF1.WUF2 Mask                      */
#define LLWU_PF1_WUF2_SHIFT                      (2U)                                                /*!< LLWU_PF1.WUF2 Position                  */
#define LLWU_PF1_WUF2(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< LLWU_PF1.WUF2 Field                     */
#define LLWU_PF1_WUF3_MASK                       (0x8U)                                              /*!< LLWU_PF1.WUF3 Mask                      */
#define LLWU_PF1_WUF3_SHIFT                      (3U)                                                /*!< LLWU_PF1.WUF3 Position                  */
#define LLWU_PF1_WUF3(x)                         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< LLWU_PF1.WUF3 Field                     */
#define LLWU_PF1_WUF4_MASK                       (0x10U)                                             /*!< LLWU_PF1.WUF4 Mask                      */
#define LLWU_PF1_WUF4_SHIFT                      (4U)                                                /*!< LLWU_PF1.WUF4 Position                  */
#define LLWU_PF1_WUF4(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< LLWU_PF1.WUF4 Field                     */
#define LLWU_PF1_WUF5_MASK                       (0x20U)                                             /*!< LLWU_PF1.WUF5 Mask                      */
#define LLWU_PF1_WUF5_SHIFT                      (5U)                                                /*!< LLWU_PF1.WUF5 Position                  */
#define LLWU_PF1_WUF5(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< LLWU_PF1.WUF5 Field                     */
#define LLWU_PF1_WUF6_MASK                       (0x40U)                                             /*!< LLWU_PF1.WUF6 Mask                      */
#define LLWU_PF1_WUF6_SHIFT                      (6U)                                                /*!< LLWU_PF1.WUF6 Position                  */
#define LLWU_PF1_WUF6(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< LLWU_PF1.WUF6 Field                     */
#define LLWU_PF1_WUF7_MASK                       (0x80U)                                             /*!< LLWU_PF1.WUF7 Mask                      */
#define LLWU_PF1_WUF7_SHIFT                      (7U)                                                /*!< LLWU_PF1.WUF7 Position                  */
#define LLWU_PF1_WUF7(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_PF1.WUF7 Field                     */
/* ------- PF2 Bit Fields                           ------ */
#define LLWU_PF2_WUF8_MASK                       (0x1U)                                              /*!< LLWU_PF2.WUF8 Mask                      */
#define LLWU_PF2_WUF8_SHIFT                      (0U)                                                /*!< LLWU_PF2.WUF8 Position                  */
#define LLWU_PF2_WUF8(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< LLWU_PF2.WUF8 Field                     */
#define LLWU_PF2_WUF9_MASK                       (0x2U)                                              /*!< LLWU_PF2.WUF9 Mask                      */
#define LLWU_PF2_WUF9_SHIFT                      (1U)                                                /*!< LLWU_PF2.WUF9 Position                  */
#define LLWU_PF2_WUF9(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< LLWU_PF2.WUF9 Field                     */
#define LLWU_PF2_WUF10_MASK                      (0x4U)                                              /*!< LLWU_PF2.WUF10 Mask                     */
#define LLWU_PF2_WUF10_SHIFT                     (2U)                                                /*!< LLWU_PF2.WUF10 Position                 */
#define LLWU_PF2_WUF10(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< LLWU_PF2.WUF10 Field                    */
#define LLWU_PF2_WUF11_MASK                      (0x8U)                                              /*!< LLWU_PF2.WUF11 Mask                     */
#define LLWU_PF2_WUF11_SHIFT                     (3U)                                                /*!< LLWU_PF2.WUF11 Position                 */
#define LLWU_PF2_WUF11(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< LLWU_PF2.WUF11 Field                    */
#define LLWU_PF2_WUF12_MASK                      (0x10U)                                             /*!< LLWU_PF2.WUF12 Mask                     */
#define LLWU_PF2_WUF12_SHIFT                     (4U)                                                /*!< LLWU_PF2.WUF12 Position                 */
#define LLWU_PF2_WUF12(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< LLWU_PF2.WUF12 Field                    */
#define LLWU_PF2_WUF13_MASK                      (0x20U)                                             /*!< LLWU_PF2.WUF13 Mask                     */
#define LLWU_PF2_WUF13_SHIFT                     (5U)                                                /*!< LLWU_PF2.WUF13 Position                 */
#define LLWU_PF2_WUF13(x)                        (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< LLWU_PF2.WUF13 Field                    */
#define LLWU_PF2_WUF14_MASK                      (0x40U)                                             /*!< LLWU_PF2.WUF14 Mask                     */
#define LLWU_PF2_WUF14_SHIFT                     (6U)                                                /*!< LLWU_PF2.WUF14 Position                 */
#define LLWU_PF2_WUF14(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< LLWU_PF2.WUF14 Field                    */
#define LLWU_PF2_WUF15_MASK                      (0x80U)                                             /*!< LLWU_PF2.WUF15 Mask                     */
#define LLWU_PF2_WUF15_SHIFT                     (7U)                                                /*!< LLWU_PF2.WUF15 Position                 */
#define LLWU_PF2_WUF15(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_PF2.WUF15 Field                    */
/* ------- PF3 Bit Fields                           ------ */
#define LLWU_PF3_WUF16_MASK                      (0x1U)                                              /*!< LLWU_PF3.WUF16 Mask                     */
#define LLWU_PF3_WUF16_SHIFT                     (0U)                                                /*!< LLWU_PF3.WUF16 Position                 */
#define LLWU_PF3_WUF16(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< LLWU_PF3.WUF16 Field                    */
#define LLWU_PF3_WUF17_MASK                      (0x2U)                                              /*!< LLWU_PF3.WUF17 Mask                     */
#define LLWU_PF3_WUF17_SHIFT                     (1U)                                                /*!< LLWU_PF3.WUF17 Position                 */
#define LLWU_PF3_WUF17(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< LLWU_PF3.WUF17 Field                    */
#define LLWU_PF3_WUF18_MASK                      (0x4U)                                              /*!< LLWU_PF3.WUF18 Mask                     */
#define LLWU_PF3_WUF18_SHIFT                     (2U)                                                /*!< LLWU_PF3.WUF18 Position                 */
#define LLWU_PF3_WUF18(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< LLWU_PF3.WUF18 Field                    */
#define LLWU_PF3_WUF19_MASK                      (0x8U)                                              /*!< LLWU_PF3.WUF19 Mask                     */
#define LLWU_PF3_WUF19_SHIFT                     (3U)                                                /*!< LLWU_PF3.WUF19 Position                 */
#define LLWU_PF3_WUF19(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< LLWU_PF3.WUF19 Field                    */
#define LLWU_PF3_WUF20_MASK                      (0x10U)                                             /*!< LLWU_PF3.WUF20 Mask                     */
#define LLWU_PF3_WUF20_SHIFT                     (4U)                                                /*!< LLWU_PF3.WUF20 Position                 */
#define LLWU_PF3_WUF20(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< LLWU_PF3.WUF20 Field                    */
#define LLWU_PF3_WUF21_MASK                      (0x20U)                                             /*!< LLWU_PF3.WUF21 Mask                     */
#define LLWU_PF3_WUF21_SHIFT                     (5U)                                                /*!< LLWU_PF3.WUF21 Position                 */
#define LLWU_PF3_WUF21(x)                        (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< LLWU_PF3.WUF21 Field                    */
#define LLWU_PF3_WUF22_MASK                      (0x40U)                                             /*!< LLWU_PF3.WUF22 Mask                     */
#define LLWU_PF3_WUF22_SHIFT                     (6U)                                                /*!< LLWU_PF3.WUF22 Position                 */
#define LLWU_PF3_WUF22(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< LLWU_PF3.WUF22 Field                    */
#define LLWU_PF3_WUF23_MASK                      (0x80U)                                             /*!< LLWU_PF3.WUF23 Mask                     */
#define LLWU_PF3_WUF23_SHIFT                     (7U)                                                /*!< LLWU_PF3.WUF23 Position                 */
#define LLWU_PF3_WUF23(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_PF3.WUF23 Field                    */
/* ------- PF4 Bit Fields                           ------ */
#define LLWU_PF4_WUF24_MASK                      (0x1U)                                              /*!< LLWU_PF4.WUF24 Mask                     */
#define LLWU_PF4_WUF24_SHIFT                     (0U)                                                /*!< LLWU_PF4.WUF24 Position                 */
#define LLWU_PF4_WUF24(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< LLWU_PF4.WUF24 Field                    */
#define LLWU_PF4_WUF25_MASK                      (0x2U)                                              /*!< LLWU_PF4.WUF25 Mask                     */
#define LLWU_PF4_WUF25_SHIFT                     (1U)                                                /*!< LLWU_PF4.WUF25 Position                 */
#define LLWU_PF4_WUF25(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< LLWU_PF4.WUF25 Field                    */
#define LLWU_PF4_WUF26_MASK                      (0x4U)                                              /*!< LLWU_PF4.WUF26 Mask                     */
#define LLWU_PF4_WUF26_SHIFT                     (2U)                                                /*!< LLWU_PF4.WUF26 Position                 */
#define LLWU_PF4_WUF26(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< LLWU_PF4.WUF26 Field                    */
#define LLWU_PF4_WUF27_MASK                      (0x8U)                                              /*!< LLWU_PF4.WUF27 Mask                     */
#define LLWU_PF4_WUF27_SHIFT                     (3U)                                                /*!< LLWU_PF4.WUF27 Position                 */
#define LLWU_PF4_WUF27(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< LLWU_PF4.WUF27 Field                    */
#define LLWU_PF4_WUF28_MASK                      (0x10U)                                             /*!< LLWU_PF4.WUF28 Mask                     */
#define LLWU_PF4_WUF28_SHIFT                     (4U)                                                /*!< LLWU_PF4.WUF28 Position                 */
#define LLWU_PF4_WUF28(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< LLWU_PF4.WUF28 Field                    */
#define LLWU_PF4_WUF29_MASK                      (0x20U)                                             /*!< LLWU_PF4.WUF29 Mask                     */
#define LLWU_PF4_WUF29_SHIFT                     (5U)                                                /*!< LLWU_PF4.WUF29 Position                 */
#define LLWU_PF4_WUF29(x)                        (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< LLWU_PF4.WUF29 Field                    */
#define LLWU_PF4_WUF30_MASK                      (0x40U)                                             /*!< LLWU_PF4.WUF30 Mask                     */
#define LLWU_PF4_WUF30_SHIFT                     (6U)                                                /*!< LLWU_PF4.WUF30 Position                 */
#define LLWU_PF4_WUF30(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< LLWU_PF4.WUF30 Field                    */
#define LLWU_PF4_WUF31_MASK                      (0x80U)                                             /*!< LLWU_PF4.WUF31 Mask                     */
#define LLWU_PF4_WUF31_SHIFT                     (7U)                                                /*!< LLWU_PF4.WUF31 Position                 */
#define LLWU_PF4_WUF31(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_PF4.WUF31 Field                    */
/* ------- MF Bit Fields                            ------ */
#define LLWU_MF_MWUF0_MASK                       (0x1U)                                              /*!< LLWU_MF.MWUF0 Mask                      */
#define LLWU_MF_MWUF0_SHIFT                      (0U)                                                /*!< LLWU_MF.MWUF0 Position                  */
#define LLWU_MF_MWUF0(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< LLWU_MF.MWUF0 Field                     */
#define LLWU_MF_MWUF1_MASK                       (0x2U)                                              /*!< LLWU_MF.MWUF1 Mask                      */
#define LLWU_MF_MWUF1_SHIFT                      (1U)                                                /*!< LLWU_MF.MWUF1 Position                  */
#define LLWU_MF_MWUF1(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< LLWU_MF.MWUF1 Field                     */
#define LLWU_MF_MWUF2_MASK                       (0x4U)                                              /*!< LLWU_MF.MWUF2 Mask                      */
#define LLWU_MF_MWUF2_SHIFT                      (2U)                                                /*!< LLWU_MF.MWUF2 Position                  */
#define LLWU_MF_MWUF2(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< LLWU_MF.MWUF2 Field                     */
#define LLWU_MF_MWUF3_MASK                       (0x8U)                                              /*!< LLWU_MF.MWUF3 Mask                      */
#define LLWU_MF_MWUF3_SHIFT                      (3U)                                                /*!< LLWU_MF.MWUF3 Position                  */
#define LLWU_MF_MWUF3(x)                         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< LLWU_MF.MWUF3 Field                     */
#define LLWU_MF_MWUF4_MASK                       (0x10U)                                             /*!< LLWU_MF.MWUF4 Mask                      */
#define LLWU_MF_MWUF4_SHIFT                      (4U)                                                /*!< LLWU_MF.MWUF4 Position                  */
#define LLWU_MF_MWUF4(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< LLWU_MF.MWUF4 Field                     */
#define LLWU_MF_MWUF5_MASK                       (0x20U)                                             /*!< LLWU_MF.MWUF5 Mask                      */
#define LLWU_MF_MWUF5_SHIFT                      (5U)                                                /*!< LLWU_MF.MWUF5 Position                  */
#define LLWU_MF_MWUF5(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< LLWU_MF.MWUF5 Field                     */
#define LLWU_MF_MWUF6_MASK                       (0x40U)                                             /*!< LLWU_MF.MWUF6 Mask                      */
#define LLWU_MF_MWUF6_SHIFT                      (6U)                                                /*!< LLWU_MF.MWUF6 Position                  */
#define LLWU_MF_MWUF6(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< LLWU_MF.MWUF6 Field                     */
#define LLWU_MF_MWUF7_MASK                       (0x80U)                                             /*!< LLWU_MF.MWUF7 Mask                      */
#define LLWU_MF_MWUF7_SHIFT                      (7U)                                                /*!< LLWU_MF.MWUF7 Position                  */
#define LLWU_MF_MWUF7(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_MF.MWUF7 Field                     */
/* ------- FILT Bit Fields                          ------ */
#define LLWU_FILT_FILTSEL_MASK                   (0x1FU)                                             /*!< LLWU_FILT.FILTSEL Mask                  */
#define LLWU_FILT_FILTSEL_SHIFT                  (0U)                                                /*!< LLWU_FILT.FILTSEL Position              */
#define LLWU_FILT_FILTSEL(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0x1FUL)            /*!< LLWU_FILT.FILTSEL Field                 */
#define LLWU_FILT_FILTE_MASK                     (0x60U)                                             /*!< LLWU_FILT.FILTE Mask                    */
#define LLWU_FILT_FILTE_SHIFT                    (5U)                                                /*!< LLWU_FILT.FILTE Position                */
#define LLWU_FILT_FILTE(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x60UL)            /*!< LLWU_FILT.FILTE Field                   */
#define LLWU_FILT_FILTF_MASK                     (0x80U)                                             /*!< LLWU_FILT.FILTF Mask                    */
#define LLWU_FILT_FILTF_SHIFT                    (7U)                                                /*!< LLWU_FILT.FILTF Position                */
#define LLWU_FILT_FILTF(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< LLWU_FILT.FILTF Field                   */
/**
 * @} */ /* End group LLWU_Register_Masks_GROUP 
 */

/* LLWU - Peripheral instance base addresses */
#define LLWU_BasePtr                   0x4007C000UL //!< Peripheral base address
#define LLWU                           ((LLWU_Type *) LLWU_BasePtr) //!< Freescale base pointer
#define LLWU_BASE_PTR                  (LLWU) //!< Freescale style base pointer
/**
 * @} */ /* End group LLWU_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup LPTMR_Peripheral_access_layer_GROUP LPTMR Peripheral Access Layer
* @brief C Struct for LPTMR
* @{
*/

/* ================================================================================ */
/* ================           LPTMR0 (file:LPTMR0_0)               ================ */
/* ================================================================================ */

/**
 * @brief Low Power Timer
 */
/**
* @addtogroup LPTMR_structs_GROUP LPTMR struct
* @brief Struct for LPTMR
* @{
*/
typedef struct {                                /*       LPTMR0 Structure                                             */
   __IO uint32_t  CSR;                          /**< 0000: Control Status Register                                      */
   __IO uint32_t  PSR;                          /**< 0004: Prescale Register                                            */
   __IO uint32_t  CMR;                          /**< 0008: Compare Register                                             */
   __I  uint32_t  CNR;                          /**< 000C: Counter Register                                             */
} LPTMR_Type;

/**
 * @} */ /* End group LPTMR_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'LPTMR0' Position & Mask macros                      ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup LPTMR_Register_Masks_GROUP LPTMR Register Masks
* @brief Register Masks for LPTMR
* @{
*/
/* ------- CSR Bit Fields                           ------ */
#define LPTMR_CSR_TEN_MASK                       (0x1U)                                              /*!< LPTMR0_CSR.TEN Mask                     */
#define LPTMR_CSR_TEN_SHIFT                      (0U)                                                /*!< LPTMR0_CSR.TEN Position                 */
#define LPTMR_CSR_TEN(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< LPTMR0_CSR.TEN Field                    */
#define LPTMR_CSR_TMS_MASK                       (0x2U)                                              /*!< LPTMR0_CSR.TMS Mask                     */
#define LPTMR_CSR_TMS_SHIFT                      (1U)                                                /*!< LPTMR0_CSR.TMS Position                 */
#define LPTMR_CSR_TMS(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< LPTMR0_CSR.TMS Field                    */
#define LPTMR_CSR_TFC_MASK                       (0x4U)                                              /*!< LPTMR0_CSR.TFC Mask                     */
#define LPTMR_CSR_TFC_SHIFT                      (2U)                                                /*!< LPTMR0_CSR.TFC Position                 */
#define LPTMR_CSR_TFC(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPTMR0_CSR.TFC Field                    */
#define LPTMR_CSR_TPP_MASK                       (0x8U)                                              /*!< LPTMR0_CSR.TPP Mask                     */
#define LPTMR_CSR_TPP_SHIFT                      (3U)                                                /*!< LPTMR0_CSR.TPP Position                 */
#define LPTMR_CSR_TPP(x)                         (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< LPTMR0_CSR.TPP Field                    */
#define LPTMR_CSR_TPS_MASK                       (0x30U)                                             /*!< LPTMR0_CSR.TPS Mask                     */
#define LPTMR_CSR_TPS_SHIFT                      (4U)                                                /*!< LPTMR0_CSR.TPS Position                 */
#define LPTMR_CSR_TPS(x)                         (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< LPTMR0_CSR.TPS Field                    */
#define LPTMR_CSR_TIE_MASK                       (0x40U)                                             /*!< LPTMR0_CSR.TIE Mask                     */
#define LPTMR_CSR_TIE_SHIFT                      (6U)                                                /*!< LPTMR0_CSR.TIE Position                 */
#define LPTMR_CSR_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< LPTMR0_CSR.TIE Field                    */
#define LPTMR_CSR_TCF_MASK                       (0x80U)                                             /*!< LPTMR0_CSR.TCF Mask                     */
#define LPTMR_CSR_TCF_SHIFT                      (7U)                                                /*!< LPTMR0_CSR.TCF Position                 */
#define LPTMR_CSR_TCF(x)                         (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< LPTMR0_CSR.TCF Field                    */
/* ------- PSR Bit Fields                           ------ */
#define LPTMR_PSR_PCS_MASK                       (0x3U)                                              /*!< LPTMR0_PSR.PCS Mask                     */
#define LPTMR_PSR_PCS_SHIFT                      (0U)                                                /*!< LPTMR0_PSR.PCS Position                 */
#define LPTMR_PSR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< LPTMR0_PSR.PCS Field                    */
#define LPTMR_PSR_PBYP_MASK                      (0x4U)                                              /*!< LPTMR0_PSR.PBYP Mask                    */
#define LPTMR_PSR_PBYP_SHIFT                     (2U)                                                /*!< LPTMR0_PSR.PBYP Position                */
#define LPTMR_PSR_PBYP(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< LPTMR0_PSR.PBYP Field                   */
#define LPTMR_PSR_PRESCALE_MASK                  (0x78U)                                             /*!< LPTMR0_PSR.PRESCALE Mask                */
#define LPTMR_PSR_PRESCALE_SHIFT                 (3U)                                                /*!< LPTMR0_PSR.PRESCALE Position            */
#define LPTMR_PSR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x78UL)          /*!< LPTMR0_PSR.PRESCALE Field               */
/* ------- CMR Bit Fields                           ------ */
#define LPTMR_CMR_COMPARE_MASK                   (0xFFFFU)                                           /*!< LPTMR0_CMR.COMPARE Mask                 */
#define LPTMR_CMR_COMPARE_SHIFT                  (0U)                                                /*!< LPTMR0_CMR.COMPARE Position             */
#define LPTMR_CMR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< LPTMR0_CMR.COMPARE Field                */
/* ------- CNR Bit Fields                           ------ */
#define LPTMR_CNR_COUNTER_MASK                   (0xFFFFU)                                           /*!< LPTMR0_CNR.COUNTER Mask                 */
#define LPTMR_CNR_COUNTER_SHIFT                  (0U)                                                /*!< LPTMR0_CNR.COUNTER Position             */
#define LPTMR_CNR_COUNTER(x)                     (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< LPTMR0_CNR.COUNTER Field                */
/**
 * @} */ /* End group LPTMR_Register_Masks_GROUP 
 */

/* LPTMR0 - Peripheral instance base addresses */
#define LPTMR0_BasePtr                 0x40040000UL //!< Peripheral base address
#define LPTMR0                         ((LPTMR_Type *) LPTMR0_BasePtr) //!< Freescale base pointer
#define LPTMR0_BASE_PTR                (LPTMR0) //!< Freescale style base pointer
/**
 * @} */ /* End group LPTMR_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MCG_Peripheral_access_layer_GROUP MCG Peripheral Access Layer
* @brief C Struct for MCG
* @{
*/

/* ================================================================================ */
/* ================           MCG (file:MCG_MKV40F15)              ================ */
/* ================================================================================ */

/**
 * @brief Multipurpose Clock Generator module
 */
/**
* @addtogroup MCG_structs_GROUP MCG struct
* @brief Struct for MCG
* @{
*/
typedef struct {                                /*       MCG Structure                                                */
   __IO uint8_t   C1;                           /**< 0000: Control 1 Register                                           */
   __IO uint8_t   C2;                           /**< 0001: Control 2 Register                                           */
   __IO uint8_t   C3;                           /**< 0002: Control 3 Register                                           */
   __IO uint8_t   C4;                           /**< 0003: Control 4 Register                                           */
   __IO uint8_t   C5;                           /**< 0004: Control 5 Register                                           */
   __IO uint8_t   C6;                           /**< 0005: Control 6 Register                                           */
   __IO uint8_t   S;                            /**< 0006: Status Register                                              */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   SC;                           /**< 0008: Status and Control Register                                  */
        uint8_t   RESERVED_1;                  
   __IO uint8_t   ATCVH;                        /**< 000A: ATM Compare Value High                                       */
   __IO uint8_t   ATCVL;                        /**< 000B: ATM Compare Value Low                                        */
        uint8_t   RESERVED_2;                  
   __IO uint8_t   C8;                           /**< 000D: Control 8 Register                                           */
} MCG_Type;

/**
 * @} */ /* End group MCG_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MCG' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MCG_Register_Masks_GROUP MCG Register Masks
* @brief Register Masks for MCG
* @{
*/
/* ------- C1 Bit Fields                            ------ */
#define MCG_C1_IREFSTEN_MASK                     (0x1U)                                              /*!< MCG_C1.IREFSTEN Mask                    */
#define MCG_C1_IREFSTEN_SHIFT                    (0U)                                                /*!< MCG_C1.IREFSTEN Position                */
#define MCG_C1_IREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< MCG_C1.IREFSTEN Field                   */
#define MCG_C1_IRCLKEN_MASK                      (0x2U)                                              /*!< MCG_C1.IRCLKEN Mask                     */
#define MCG_C1_IRCLKEN_SHIFT                     (1U)                                                /*!< MCG_C1.IRCLKEN Position                 */
#define MCG_C1_IRCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< MCG_C1.IRCLKEN Field                    */
#define MCG_C1_IREFS_MASK                        (0x4U)                                              /*!< MCG_C1.IREFS Mask                       */
#define MCG_C1_IREFS_SHIFT                       (2U)                                                /*!< MCG_C1.IREFS Position                   */
#define MCG_C1_IREFS(x)                          (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< MCG_C1.IREFS Field                      */
#define MCG_C1_FRDIV_MASK                        (0x38U)                                             /*!< MCG_C1.FRDIV Mask                       */
#define MCG_C1_FRDIV_SHIFT                       (3U)                                                /*!< MCG_C1.FRDIV Position                   */
#define MCG_C1_FRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<3U))&0x38UL)            /*!< MCG_C1.FRDIV Field                      */
#define MCG_C1_CLKS_MASK                         (0xC0U)                                             /*!< MCG_C1.CLKS Mask                        */
#define MCG_C1_CLKS_SHIFT                        (6U)                                                /*!< MCG_C1.CLKS Position                    */
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< MCG_C1.CLKS Field                       */
/* ------- C2 Bit Fields                            ------ */
#define MCG_C2_IRCS_MASK                         (0x1U)                                              /*!< MCG_C2.IRCS Mask                        */
#define MCG_C2_IRCS_SHIFT                        (0U)                                                /*!< MCG_C2.IRCS Position                    */
#define MCG_C2_IRCS(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< MCG_C2.IRCS Field                       */
#define MCG_C2_LP_MASK                           (0x2U)                                              /*!< MCG_C2.LP Mask                          */
#define MCG_C2_LP_SHIFT                          (1U)                                                /*!< MCG_C2.LP Position                      */
#define MCG_C2_LP(x)                             (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< MCG_C2.LP Field                         */
#define MCG_C2_EREFS0_MASK                       (0x4U)                                              /*!< MCG_C2.EREFS0 Mask                      */
#define MCG_C2_EREFS0_SHIFT                      (2U)                                                /*!< MCG_C2.EREFS0 Position                  */
#define MCG_C2_EREFS0(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< MCG_C2.EREFS0 Field                     */
#define MCG_C2_HGO0_MASK                         (0x8U)                                              /*!< MCG_C2.HGO0 Mask                        */
#define MCG_C2_HGO0_SHIFT                        (3U)                                                /*!< MCG_C2.HGO0 Position                    */
#define MCG_C2_HGO0(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< MCG_C2.HGO0 Field                       */
#define MCG_C2_RANGE0_MASK                       (0x30U)                                             /*!< MCG_C2.RANGE0 Mask                      */
#define MCG_C2_RANGE0_SHIFT                      (4U)                                                /*!< MCG_C2.RANGE0 Position                  */
#define MCG_C2_RANGE0(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< MCG_C2.RANGE0 Field                     */
#define MCG_C2_FCFTRIM_MASK                      (0x40U)                                             /*!< MCG_C2.FCFTRIM Mask                     */
#define MCG_C2_FCFTRIM_SHIFT                     (6U)                                                /*!< MCG_C2.FCFTRIM Position                 */
#define MCG_C2_FCFTRIM(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< MCG_C2.FCFTRIM Field                    */
#define MCG_C2_LOCRE0_MASK                       (0x80U)                                             /*!< MCG_C2.LOCRE0 Mask                      */
#define MCG_C2_LOCRE0_SHIFT                      (7U)                                                /*!< MCG_C2.LOCRE0 Position                  */
#define MCG_C2_LOCRE0(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< MCG_C2.LOCRE0 Field                     */
/* ------- C3 Bit Fields                            ------ */
#define MCG_C3_SCTRIM_MASK                       (0xFFU)                                             /*!< MCG_C3.SCTRIM Mask                      */
#define MCG_C3_SCTRIM_SHIFT                      (0U)                                                /*!< MCG_C3.SCTRIM Position                  */
#define MCG_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< MCG_C3.SCTRIM Field                     */
/* ------- C4 Bit Fields                            ------ */
#define MCG_C4_SCFTRIM_MASK                      (0x1U)                                              /*!< MCG_C4.SCFTRIM Mask                     */
#define MCG_C4_SCFTRIM_SHIFT                     (0U)                                                /*!< MCG_C4.SCFTRIM Position                 */
#define MCG_C4_SCFTRIM(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< MCG_C4.SCFTRIM Field                    */
#define MCG_C4_FCTRIM_MASK                       (0x1EU)                                             /*!< MCG_C4.FCTRIM Mask                      */
#define MCG_C4_FCTRIM_SHIFT                      (1U)                                                /*!< MCG_C4.FCTRIM Position                  */
#define MCG_C4_FCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x1EUL)            /*!< MCG_C4.FCTRIM Field                     */
#define MCG_C4_DRST_DRS_MASK                     (0x60U)                                             /*!< MCG_C4.DRST_DRS Mask                    */
#define MCG_C4_DRST_DRS_SHIFT                    (5U)                                                /*!< MCG_C4.DRST_DRS Position                */
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x60UL)            /*!< MCG_C4.DRST_DRS Field                   */
#define MCG_C4_DMX32_MASK                        (0x80U)                                             /*!< MCG_C4.DMX32 Mask                       */
#define MCG_C4_DMX32_SHIFT                       (7U)                                                /*!< MCG_C4.DMX32 Position                   */
#define MCG_C4_DMX32(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< MCG_C4.DMX32 Field                      */
/* ------- C5 Bit Fields                            ------ */
#define MCG_C5_PRDIV0_MASK                       (0x7U)                                              /*!< MCG_C5.PRDIV0 Mask                      */
#define MCG_C5_PRDIV0_SHIFT                      (0U)                                                /*!< MCG_C5.PRDIV0 Position                  */
#define MCG_C5_PRDIV0(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< MCG_C5.PRDIV0 Field                     */
#define MCG_C5_PLLSTEN0_MASK                     (0x20U)                                             /*!< MCG_C5.PLLSTEN0 Mask                    */
#define MCG_C5_PLLSTEN0_SHIFT                    (5U)                                                /*!< MCG_C5.PLLSTEN0 Position                */
#define MCG_C5_PLLSTEN0(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< MCG_C5.PLLSTEN0 Field                   */
#define MCG_C5_PLLCLKEN0_MASK                    (0x40U)                                             /*!< MCG_C5.PLLCLKEN0 Mask                   */
#define MCG_C5_PLLCLKEN0_SHIFT                   (6U)                                                /*!< MCG_C5.PLLCLKEN0 Position               */
#define MCG_C5_PLLCLKEN0(x)                      (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< MCG_C5.PLLCLKEN0 Field                  */
/* ------- C6 Bit Fields                            ------ */
#define MCG_C6_VDIV0_MASK                        (0x1FU)                                             /*!< MCG_C6.VDIV0 Mask                       */
#define MCG_C6_VDIV0_SHIFT                       (0U)                                                /*!< MCG_C6.VDIV0 Position                   */
#define MCG_C6_VDIV0(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1FUL)            /*!< MCG_C6.VDIV0 Field                      */
#define MCG_C6_CME0_MASK                         (0x20U)                                             /*!< MCG_C6.CME0 Mask                        */
#define MCG_C6_CME0_SHIFT                        (5U)                                                /*!< MCG_C6.CME0 Position                    */
#define MCG_C6_CME0(x)                           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< MCG_C6.CME0 Field                       */
#define MCG_C6_PLLS_MASK                         (0x40U)                                             /*!< MCG_C6.PLLS Mask                        */
#define MCG_C6_PLLS_SHIFT                        (6U)                                                /*!< MCG_C6.PLLS Position                    */
#define MCG_C6_PLLS(x)                           (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< MCG_C6.PLLS Field                       */
#define MCG_C6_LOLIE0_MASK                       (0x80U)                                             /*!< MCG_C6.LOLIE0 Mask                      */
#define MCG_C6_LOLIE0_SHIFT                      (7U)                                                /*!< MCG_C6.LOLIE0 Position                  */
#define MCG_C6_LOLIE0(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< MCG_C6.LOLIE0 Field                     */
/* ------- S Bit Fields                             ------ */
#define MCG_S_IRCST_MASK                         (0x1U)                                              /*!< MCG_S.IRCST Mask                        */
#define MCG_S_IRCST_SHIFT                        (0U)                                                /*!< MCG_S.IRCST Position                    */
#define MCG_S_IRCST(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< MCG_S.IRCST Field                       */
#define MCG_S_OSCINIT0_MASK                      (0x2U)                                              /*!< MCG_S.OSCINIT0 Mask                     */
#define MCG_S_OSCINIT0_SHIFT                     (1U)                                                /*!< MCG_S.OSCINIT0 Position                 */
#define MCG_S_OSCINIT0(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< MCG_S.OSCINIT0 Field                    */
#define MCG_S_CLKST_MASK                         (0xCU)                                              /*!< MCG_S.CLKST Mask                        */
#define MCG_S_CLKST_SHIFT                        (2U)                                                /*!< MCG_S.CLKST Position                    */
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< MCG_S.CLKST Field                       */
#define MCG_S_IREFST_MASK                        (0x10U)                                             /*!< MCG_S.IREFST Mask                       */
#define MCG_S_IREFST_SHIFT                       (4U)                                                /*!< MCG_S.IREFST Position                   */
#define MCG_S_IREFST(x)                          (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< MCG_S.IREFST Field                      */
#define MCG_S_PLLST_MASK                         (0x20U)                                             /*!< MCG_S.PLLST Mask                        */
#define MCG_S_PLLST_SHIFT                        (5U)                                                /*!< MCG_S.PLLST Position                    */
#define MCG_S_PLLST(x)                           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< MCG_S.PLLST Field                       */
#define MCG_S_LOCK0_MASK                         (0x40U)                                             /*!< MCG_S.LOCK0 Mask                        */
#define MCG_S_LOCK0_SHIFT                        (6U)                                                /*!< MCG_S.LOCK0 Position                    */
#define MCG_S_LOCK0(x)                           (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< MCG_S.LOCK0 Field                       */
#define MCG_S_LOLS0_MASK                         (0x80U)                                             /*!< MCG_S.LOLS0 Mask                        */
#define MCG_S_LOLS0_SHIFT                        (7U)                                                /*!< MCG_S.LOLS0 Position                    */
#define MCG_S_LOLS0(x)                           (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< MCG_S.LOLS0 Field                       */
/* ------- SC Bit Fields                            ------ */
#define MCG_SC_LOCS0_MASK                        (0x1U)                                              /*!< MCG_SC.LOCS0 Mask                       */
#define MCG_SC_LOCS0_SHIFT                       (0U)                                                /*!< MCG_SC.LOCS0 Position                   */
#define MCG_SC_LOCS0(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< MCG_SC.LOCS0 Field                      */
#define MCG_SC_FCRDIV_MASK                       (0xEU)                                              /*!< MCG_SC.FCRDIV Mask                      */
#define MCG_SC_FCRDIV_SHIFT                      (1U)                                                /*!< MCG_SC.FCRDIV Position                  */
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0xEUL)             /*!< MCG_SC.FCRDIV Field                     */
#define MCG_SC_FLTPRSRV_MASK                     (0x10U)                                             /*!< MCG_SC.FLTPRSRV Mask                    */
#define MCG_SC_FLTPRSRV_SHIFT                    (4U)                                                /*!< MCG_SC.FLTPRSRV Position                */
#define MCG_SC_FLTPRSRV(x)                       (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< MCG_SC.FLTPRSRV Field                   */
#define MCG_SC_ATMF_MASK                         (0x20U)                                             /*!< MCG_SC.ATMF Mask                        */
#define MCG_SC_ATMF_SHIFT                        (5U)                                                /*!< MCG_SC.ATMF Position                    */
#define MCG_SC_ATMF(x)                           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< MCG_SC.ATMF Field                       */
#define MCG_SC_ATMS_MASK                         (0x40U)                                             /*!< MCG_SC.ATMS Mask                        */
#define MCG_SC_ATMS_SHIFT                        (6U)                                                /*!< MCG_SC.ATMS Position                    */
#define MCG_SC_ATMS(x)                           (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< MCG_SC.ATMS Field                       */
#define MCG_SC_ATME_MASK                         (0x80U)                                             /*!< MCG_SC.ATME Mask                        */
#define MCG_SC_ATME_SHIFT                        (7U)                                                /*!< MCG_SC.ATME Position                    */
#define MCG_SC_ATME(x)                           (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< MCG_SC.ATME Field                       */
/* ------- ATCVH Bit Fields                         ------ */
#define MCG_ATCVH_ATCVH_MASK                     (0xFFU)                                             /*!< MCG_ATCVH.ATCVH Mask                    */
#define MCG_ATCVH_ATCVH_SHIFT                    (0U)                                                /*!< MCG_ATCVH.ATCVH Position                */
#define MCG_ATCVH_ATCVH(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< MCG_ATCVH.ATCVH Field                   */
/* ------- ATCVL Bit Fields                         ------ */
#define MCG_ATCVL_ATCVL_MASK                     (0xFFU)                                             /*!< MCG_ATCVL.ATCVL Mask                    */
#define MCG_ATCVL_ATCVL_SHIFT                    (0U)                                                /*!< MCG_ATCVL.ATCVL Position                */
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< MCG_ATCVL.ATCVL Field                   */
/* ------- C8 Bit Fields                            ------ */
#define MCG_C8_LOLRE_MASK                        (0x40U)                                             /*!< MCG_C8.LOLRE Mask                       */
#define MCG_C8_LOLRE_SHIFT                       (6U)                                                /*!< MCG_C8.LOLRE Position                   */
#define MCG_C8_LOLRE(x)                          (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< MCG_C8.LOLRE Field                      */
/**
 * @} */ /* End group MCG_Register_Masks_GROUP 
 */

/* MCG - Peripheral instance base addresses */
#define MCG_BasePtr                    0x40064000UL //!< Peripheral base address
#define MCG                            ((MCG_Type *) MCG_BasePtr) //!< Freescale base pointer
#define MCG_BASE_PTR                   (MCG) //!< Freescale style base pointer
/**
 * @} */ /* End group MCG_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup MCM_Peripheral_access_layer_GROUP MCM Peripheral Access Layer
* @brief C Struct for MCM
* @{
*/

/* ================================================================================ */
/* ================           MCM (file:MCM_MKV40F15)              ================ */
/* ================================================================================ */

/**
 * @brief Core Platform Miscellaneous Control Module
 */
/**
* @addtogroup MCM_structs_GROUP MCM struct
* @brief Struct for MCM
* @{
*/
typedef struct {                                /*       MCM Structure                                                */
        uint8_t   RESERVED_0[8];               
   __I  uint16_t  PLASC;                        /**< 0008: Crossbar Switch (AXBS) Slave Configuration                   */
   __I  uint16_t  PLAMC;                        /**< 000A: Crossbar Switch (AXBS) Master Configuration                  */
   __IO uint32_t  CR;                           /**< 000C: Control Register                                             */
   __IO uint32_t  ISR;                          /**< 0010: Interrupt Status Register                                    */
        uint8_t   RESERVED_1[44];              
   __IO uint32_t  CPO;                          /**< 0040: Compute Operation Control Register                           */
} MCM_Type;

/**
 * @} */ /* End group MCM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'MCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup MCM_Register_Masks_GROUP MCM Register Masks
* @brief Register Masks for MCM
* @{
*/
/* ------- PLASC Bit Fields                         ------ */
#define MCM_PLASC_ASC_MASK                       (0xFFU)                                             /*!< MCM_PLASC.ASC Mask                      */
#define MCM_PLASC_ASC_SHIFT                      (0U)                                                /*!< MCM_PLASC.ASC Position                  */
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0xFFUL)          /*!< MCM_PLASC.ASC Field                     */
/* ------- PLAMC Bit Fields                         ------ */
#define MCM_PLAMC_AMC_MASK                       (0xFFU)                                             /*!< MCM_PLAMC.AMC Mask                      */
#define MCM_PLAMC_AMC_SHIFT                      (0U)                                                /*!< MCM_PLAMC.AMC Position                  */
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x))<<0U))&0xFFUL)          /*!< MCM_PLAMC.AMC Field                     */
/* ------- CR Bit Fields                            ------ */
#define MCM_CR_SRAMUAP_MASK                      (0x3000000U)                                        /*!< MCM_CR.SRAMUAP Mask                     */
#define MCM_CR_SRAMUAP_SHIFT                     (24U)                                               /*!< MCM_CR.SRAMUAP Position                 */
#define MCM_CR_SRAMUAP(x)                        (((uint32_t)(((uint32_t)(x))<<24U))&0x3000000UL)    /*!< MCM_CR.SRAMUAP Field                    */
#define MCM_CR_SRAMUWP_MASK                      (0x4000000U)                                        /*!< MCM_CR.SRAMUWP Mask                     */
#define MCM_CR_SRAMUWP_SHIFT                     (26U)                                               /*!< MCM_CR.SRAMUWP Position                 */
#define MCM_CR_SRAMUWP(x)                        (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< MCM_CR.SRAMUWP Field                    */
#define MCM_CR_SRAMLAP_MASK                      (0x30000000U)                                       /*!< MCM_CR.SRAMLAP Mask                     */
#define MCM_CR_SRAMLAP_SHIFT                     (28U)                                               /*!< MCM_CR.SRAMLAP Position                 */
#define MCM_CR_SRAMLAP(x)                        (((uint32_t)(((uint32_t)(x))<<28U))&0x30000000UL)   /*!< MCM_CR.SRAMLAP Field                    */
#define MCM_CR_SRAMLWP_MASK                      (0x40000000U)                                       /*!< MCM_CR.SRAMLWP Mask                     */
#define MCM_CR_SRAMLWP_SHIFT                     (30U)                                               /*!< MCM_CR.SRAMLWP Position                 */
#define MCM_CR_SRAMLWP(x)                        (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< MCM_CR.SRAMLWP Field                    */
/* ------- ISR Bit Fields                           ------ */
#define MCM_ISR_FIOC_MASK                        (0x100U)                                            /*!< MCM_ISR.FIOC Mask                       */
#define MCM_ISR_FIOC_SHIFT                       (8U)                                                /*!< MCM_ISR.FIOC Position                   */
#define MCM_ISR_FIOC(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< MCM_ISR.FIOC Field                      */
#define MCM_ISR_FDZC_MASK                        (0x200U)                                            /*!< MCM_ISR.FDZC Mask                       */
#define MCM_ISR_FDZC_SHIFT                       (9U)                                                /*!< MCM_ISR.FDZC Position                   */
#define MCM_ISR_FDZC(x)                          (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< MCM_ISR.FDZC Field                      */
#define MCM_ISR_FOFC_MASK                        (0x400U)                                            /*!< MCM_ISR.FOFC Mask                       */
#define MCM_ISR_FOFC_SHIFT                       (10U)                                               /*!< MCM_ISR.FOFC Position                   */
#define MCM_ISR_FOFC(x)                          (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< MCM_ISR.FOFC Field                      */
#define MCM_ISR_FUFC_MASK                        (0x800U)                                            /*!< MCM_ISR.FUFC Mask                       */
#define MCM_ISR_FUFC_SHIFT                       (11U)                                               /*!< MCM_ISR.FUFC Position                   */
#define MCM_ISR_FUFC(x)                          (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< MCM_ISR.FUFC Field                      */
#define MCM_ISR_FIXC_MASK                        (0x1000U)                                           /*!< MCM_ISR.FIXC Mask                       */
#define MCM_ISR_FIXC_SHIFT                       (12U)                                               /*!< MCM_ISR.FIXC Position                   */
#define MCM_ISR_FIXC(x)                          (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< MCM_ISR.FIXC Field                      */
#define MCM_ISR_FIDC_MASK                        (0x8000U)                                           /*!< MCM_ISR.FIDC Mask                       */
#define MCM_ISR_FIDC_SHIFT                       (15U)                                               /*!< MCM_ISR.FIDC Position                   */
#define MCM_ISR_FIDC(x)                          (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< MCM_ISR.FIDC Field                      */
#define MCM_ISR_FIOCE_MASK                       (0x1000000U)                                        /*!< MCM_ISR.FIOCE Mask                      */
#define MCM_ISR_FIOCE_SHIFT                      (24U)                                               /*!< MCM_ISR.FIOCE Position                  */
#define MCM_ISR_FIOCE(x)                         (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< MCM_ISR.FIOCE Field                     */
#define MCM_ISR_FDZCE_MASK                       (0x2000000U)                                        /*!< MCM_ISR.FDZCE Mask                      */
#define MCM_ISR_FDZCE_SHIFT                      (25U)                                               /*!< MCM_ISR.FDZCE Position                  */
#define MCM_ISR_FDZCE(x)                         (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< MCM_ISR.FDZCE Field                     */
#define MCM_ISR_FOFCE_MASK                       (0x4000000U)                                        /*!< MCM_ISR.FOFCE Mask                      */
#define MCM_ISR_FOFCE_SHIFT                      (26U)                                               /*!< MCM_ISR.FOFCE Position                  */
#define MCM_ISR_FOFCE(x)                         (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< MCM_ISR.FOFCE Field                     */
#define MCM_ISR_FUFCE_MASK                       (0x8000000U)                                        /*!< MCM_ISR.FUFCE Mask                      */
#define MCM_ISR_FUFCE_SHIFT                      (27U)                                               /*!< MCM_ISR.FUFCE Position                  */
#define MCM_ISR_FUFCE(x)                         (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< MCM_ISR.FUFCE Field                     */
#define MCM_ISR_FIXCE_MASK                       (0x10000000U)                                       /*!< MCM_ISR.FIXCE Mask                      */
#define MCM_ISR_FIXCE_SHIFT                      (28U)                                               /*!< MCM_ISR.FIXCE Position                  */
#define MCM_ISR_FIXCE(x)                         (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< MCM_ISR.FIXCE Field                     */
#define MCM_ISR_FIDCE_MASK                       (0x80000000U)                                       /*!< MCM_ISR.FIDCE Mask                      */
#define MCM_ISR_FIDCE_SHIFT                      (31U)                                               /*!< MCM_ISR.FIDCE Position                  */
#define MCM_ISR_FIDCE(x)                         (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< MCM_ISR.FIDCE Field                     */
/* ------- CPO Bit Fields                           ------ */
#define MCM_CPO_CPOREQ_MASK                      (0x1U)                                              /*!< MCM_CPO.CPOREQ Mask                     */
#define MCM_CPO_CPOREQ_SHIFT                     (0U)                                                /*!< MCM_CPO.CPOREQ Position                 */
#define MCM_CPO_CPOREQ(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< MCM_CPO.CPOREQ Field                    */
#define MCM_CPO_CPOACK_MASK                      (0x2U)                                              /*!< MCM_CPO.CPOACK Mask                     */
#define MCM_CPO_CPOACK_SHIFT                     (1U)                                                /*!< MCM_CPO.CPOACK Position                 */
#define MCM_CPO_CPOACK(x)                        (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< MCM_CPO.CPOACK Field                    */
#define MCM_CPO_CPOWOI_MASK                      (0x4U)                                              /*!< MCM_CPO.CPOWOI Mask                     */
#define MCM_CPO_CPOWOI_SHIFT                     (2U)                                                /*!< MCM_CPO.CPOWOI Position                 */
#define MCM_CPO_CPOWOI(x)                        (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< MCM_CPO.CPOWOI Field                    */
/**
 * @} */ /* End group MCM_Register_Masks_GROUP 
 */

/* MCM - Peripheral instance base addresses */
#define MCM_BasePtr                    0xE0080000UL //!< Peripheral base address
#define MCM                            ((MCM_Type *) MCM_BasePtr) //!< Freescale base pointer
#define MCM_BASE_PTR                   (MCM) //!< Freescale style base pointer
/**
 * @} */ /* End group MCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup NV_Peripheral_access_layer_GROUP NV Peripheral Access Layer
* @brief C Struct for NV
* @{
*/

/* ================================================================================ */
/* ================           NV (file:NV_MKV40)                   ================ */
/* ================================================================================ */

/**
 * @brief Flash configuration field
 */
/**
* @addtogroup NV_structs_GROUP NV struct
* @brief Struct for NV
* @{
*/
typedef struct {                                /*       NV Structure                                                 */
   __I  uint8_t   BACKKEY3;                     /**< 0000: Backdoor Comparison Key 3                                    */
   __I  uint8_t   BACKKEY2;                     /**< 0001: Backdoor Comparison Key 2                                    */
   __I  uint8_t   BACKKEY1;                     /**< 0002: Backdoor Comparison Key 1                                    */
   __I  uint8_t   BACKKEY0;                     /**< 0003: Backdoor Comparison Key 0                                    */
   __I  uint8_t   BACKKEY7;                     /**< 0004: Backdoor Comparison Key 7                                    */
   __I  uint8_t   BACKKEY6;                     /**< 0005: Backdoor Comparison Key 6                                    */
   __I  uint8_t   BACKKEY5;                     /**< 0006: Backdoor Comparison Key 5                                    */
   __I  uint8_t   BACKKEY4;                     /**< 0007: Backdoor Comparison Key 4                                    */
   __I  uint8_t   FPROT3;                       /**< 0008: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT2;                       /**< 0009: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT1;                       /**< 000A: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FPROT0;                       /**< 000B: Non-volatile P-Flash Protection Register                     */
   __I  uint8_t   FSEC;                         /**< 000C: Non-volatile Flash Security Register                         */
   __I  uint8_t   FOPT;                         /**< 000D: Non-volatile Flash Option Register                           */
   __I  uint8_t   FEPROT;                       /**< 000E: Non-volatile EERAM Protection Register                       */
   __I  uint8_t   FDPROT;                       /**< 000F: Non-volatile D-Flash Protection Register                     */
} NV_Type;

/**
 * @} */ /* End group NV_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'NV' Position & Mask macros                          ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup NV_Register_Masks_GROUP NV Register Masks
* @brief Register Masks for NV
* @{
*/
/* ------- BACKKEY Bit Fields                       ------ */
#define NV_BACKKEY_KEY_MASK                      (0xFFU)                                             /*!< NV_BACKKEY.KEY Mask                     */
#define NV_BACKKEY_KEY_SHIFT                     (0U)                                                /*!< NV_BACKKEY.KEY Position                 */
#define NV_BACKKEY_KEY(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< NV_BACKKEY.KEY Field                    */
/* ------- FPROT Bit Fields                         ------ */
#define NV_FPROT_PROT_MASK                       (0xFFU)                                             /*!< NV_FPROT.PROT Mask                      */
#define NV_FPROT_PROT_SHIFT                      (0U)                                                /*!< NV_FPROT.PROT Position                  */
#define NV_FPROT_PROT(x)                         (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< NV_FPROT.PROT Field                     */
/* ------- FSEC Bit Fields                          ------ */
#define NV_FSEC_SEC_MASK                         (0x3U)                                              /*!< NV_FSEC.SEC Mask                        */
#define NV_FSEC_SEC_SHIFT                        (0U)                                                /*!< NV_FSEC.SEC Position                    */
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< NV_FSEC.SEC Field                       */
#define NV_FSEC_FSLACC_MASK                      (0xCU)                                              /*!< NV_FSEC.FSLACC Mask                     */
#define NV_FSEC_FSLACC_SHIFT                     (2U)                                                /*!< NV_FSEC.FSLACC Position                 */
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0xCUL)             /*!< NV_FSEC.FSLACC Field                    */
#define NV_FSEC_MEEN_MASK                        (0x30U)                                             /*!< NV_FSEC.MEEN Mask                       */
#define NV_FSEC_MEEN_SHIFT                       (4U)                                                /*!< NV_FSEC.MEEN Position                   */
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x))<<4U))&0x30UL)            /*!< NV_FSEC.MEEN Field                      */
#define NV_FSEC_KEYEN_MASK                       (0xC0U)                                             /*!< NV_FSEC.KEYEN Mask                      */
#define NV_FSEC_KEYEN_SHIFT                      (6U)                                                /*!< NV_FSEC.KEYEN Position                  */
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< NV_FSEC.KEYEN Field                     */
/* ------- FOPT Bit Fields                          ------ */
#define NV_FOPT_LPBOOT_MASK                      (0x1U)                                              /*!< NV_FOPT.LPBOOT Mask                     */
#define NV_FOPT_LPBOOT_SHIFT                     (0U)                                                /*!< NV_FOPT.LPBOOT Position                 */
#define NV_FOPT_LPBOOT(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< NV_FOPT.LPBOOT Field                    */
#define NV_FOPT_NMI_DIS_MASK                     (0x4U)                                              /*!< NV_FOPT.NMI_DIS Mask                    */
#define NV_FOPT_NMI_DIS_SHIFT                    (2U)                                                /*!< NV_FOPT.NMI_DIS Position                */
#define NV_FOPT_NMI_DIS(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< NV_FOPT.NMI_DIS Field                   */
#define NV_FOPT_FAST_INIT_MASK                   (0x20U)                                             /*!< NV_FOPT.FAST_INIT Mask                  */
#define NV_FOPT_FAST_INIT_SHIFT                  (5U)                                                /*!< NV_FOPT.FAST_INIT Position              */
#define NV_FOPT_FAST_INIT(x)                     (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< NV_FOPT.FAST_INIT Field                 */
/* ------- FEPROT Bit Fields                        ------ */
#define NV_FEPROT_EPROT_MASK                     (0xFFU)                                             /*!< NV_FEPROT.EPROT Mask                    */
#define NV_FEPROT_EPROT_SHIFT                    (0U)                                                /*!< NV_FEPROT.EPROT Position                */
#define NV_FEPROT_EPROT(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< NV_FEPROT.EPROT Field                   */
/* ------- FDPROT Bit Fields                        ------ */
#define NV_FDPROT_DPROT_MASK                     (0xFFU)                                             /*!< NV_FDPROT.DPROT Mask                    */
#define NV_FDPROT_DPROT_SHIFT                    (0U)                                                /*!< NV_FDPROT.DPROT Position                */
#define NV_FDPROT_DPROT(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< NV_FDPROT.DPROT Field                   */
/**
 * @} */ /* End group NV_Register_Masks_GROUP 
 */

/* NV - Peripheral instance base addresses */
#define NV_BasePtr                     0x00000400UL //!< Peripheral base address
#define NV                             ((NV_Type *) NV_BasePtr) //!< Freescale base pointer
#define NV_BASE_PTR                    (NV) //!< Freescale style base pointer
/**
 * @} */ /* End group NV_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup OSC_Peripheral_access_layer_GROUP OSC Peripheral Access Layer
* @brief C Struct for OSC
* @{
*/

/* ================================================================================ */
/* ================           OSC0 (file:OSC0_DIV)                 ================ */
/* ================================================================================ */

/**
 * @brief System Oscillator
 */
/**
* @addtogroup OSC_structs_GROUP OSC struct
* @brief Struct for OSC
* @{
*/
typedef struct {                                /*       OSC0 Structure                                               */
   __IO uint8_t   CR;                           /**< 0000: Control Register                                             */
        uint8_t   RESERVED_0;                  
   __IO uint8_t   DIV;                          /**< 0002: Clock Divider Register                                       */
} OSC_Type;

/**
 * @} */ /* End group OSC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'OSC0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup OSC_Register_Masks_GROUP OSC Register Masks
* @brief Register Masks for OSC
* @{
*/
/* ------- CR Bit Fields                            ------ */
#define OSC_CR_SCP_MASK                          (0xFU)                                              /*!< OSC0_CR.SCP Mask                        */
#define OSC_CR_SCP_SHIFT                         (0U)                                                /*!< OSC0_CR.SCP Position                    */
#define OSC_CR_SCP(x)                            (((uint8_t)(((uint8_t)(x))<<0U))&0xFUL)             /*!< OSC0_CR.SCP Field                       */
#define OSC_CR_SC16P_MASK                        (0x1U)                                              /*!< OSC0_CR.SC16P Mask                      */
#define OSC_CR_SC16P_SHIFT                       (0U)                                                /*!< OSC0_CR.SC16P Position                  */
#define OSC_CR_SC16P(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< OSC0_CR.SC16P Field                     */
#define OSC_CR_SC8P_MASK                         (0x2U)                                              /*!< OSC0_CR.SC8P Mask                       */
#define OSC_CR_SC8P_SHIFT                        (1U)                                                /*!< OSC0_CR.SC8P Position                   */
#define OSC_CR_SC8P(x)                           (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< OSC0_CR.SC8P Field                      */
#define OSC_CR_SC4P_MASK                         (0x4U)                                              /*!< OSC0_CR.SC4P Mask                       */
#define OSC_CR_SC4P_SHIFT                        (2U)                                                /*!< OSC0_CR.SC4P Position                   */
#define OSC_CR_SC4P(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< OSC0_CR.SC4P Field                      */
#define OSC_CR_SC2P_MASK                         (0x8U)                                              /*!< OSC0_CR.SC2P Mask                       */
#define OSC_CR_SC2P_SHIFT                        (3U)                                                /*!< OSC0_CR.SC2P Position                   */
#define OSC_CR_SC2P(x)                           (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< OSC0_CR.SC2P Field                      */
#define OSC_CR_EREFSTEN_MASK                     (0x20U)                                             /*!< OSC0_CR.EREFSTEN Mask                   */
#define OSC_CR_EREFSTEN_SHIFT                    (5U)                                                /*!< OSC0_CR.EREFSTEN Position               */
#define OSC_CR_EREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< OSC0_CR.EREFSTEN Field                  */
#define OSC_CR_ERCLKEN_MASK                      (0x80U)                                             /*!< OSC0_CR.ERCLKEN Mask                    */
#define OSC_CR_ERCLKEN_SHIFT                     (7U)                                                /*!< OSC0_CR.ERCLKEN Position                */
#define OSC_CR_ERCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< OSC0_CR.ERCLKEN Field                   */
/* ------- DIV Bit Fields                           ------ */
#define OSC_DIV_ERPS_MASK                        (0xC0U)                                             /*!< OSC0_DIV.ERPS Mask                      */
#define OSC_DIV_ERPS_SHIFT                       (6U)                                                /*!< OSC0_DIV.ERPS Position                  */
#define OSC_DIV_ERPS(x)                          (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< OSC0_DIV.ERPS Field                     */
/**
 * @} */ /* End group OSC_Register_Masks_GROUP 
 */

/* OSC0 - Peripheral instance base addresses */
#define OSC0_BasePtr                   0x40065000UL //!< Peripheral base address
#define OSC0                           ((OSC_Type *) OSC0_BasePtr) //!< Freescale base pointer
#define OSC0_BASE_PTR                  (OSC0) //!< Freescale style base pointer
/**
 * @} */ /* End group OSC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PDB_Peripheral_access_layer_GROUP PDB Peripheral Access Layer
* @brief C Struct for PDB
* @{
*/

/* ================================================================================ */
/* ================           PDB0 (file:PDB0_1CH_4TRIG_1DAC_4PO)       ================ */
/* ================================================================================ */

/**
 * @brief Programmable Delay Block (1 channels, 4 triggers, 1 DAC, 4 pulse outputs)
 */
/**
* @addtogroup PDB_structs_GROUP PDB struct
* @brief Struct for PDB
* @{
*/
typedef struct {                                /*       PDB0 Structure                                               */
   __IO uint32_t  SC;                           /**< 0000: Status and Control Register                                  */
   __IO uint32_t  MOD;                          /**< 0004: Modulus Register                                             */
   __I  uint32_t  CNT;                          /**< 0008: Counter Register                                             */
   __IO uint32_t  IDLY;                         /**< 000C: Interrupt Delay Register                                     */
   struct {
      __IO uint32_t  C1;                        /**< 0010: Channel  Control Register 1                                  */
      __IO uint32_t  S;                         /**< 0014: Channel  Status Register                                     */
      __IO uint32_t  DLY[4];                    /**< 0018: Channel Delay  Register                                      */
           uint8_t   RESERVED_0[16];           
   } CH[2];                                     /**< 0010: (cluster: size=0x0050, 80)                                   */
        uint8_t   RESERVED_1[240];             
   struct {
      __IO uint32_t  INTC;                      /**< 0150: DAC Interval Trigger n Control Register                      */
      __IO uint32_t  INT;                       /**< 0154: DAC Interval n Register                                      */
   } DAC[2];                                    /**< 0150: (cluster: size=0x0010, 16)                                   */
        uint8_t   RESERVED_3[48];              
   __IO uint32_t  POEN;                         /**< 0190: Pulse-Out Enable Register                                    */
   __IO uint32_t  PODLY[4];                     /**< 0194: Pulse-Out  Delay Register                                    */
} PDB_Type;

/**
 * @} */ /* End group PDB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PDB0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PDB_Register_Masks_GROUP PDB Register Masks
* @brief Register Masks for PDB
* @{
*/
/* ------- SC Bit Fields                            ------ */
#define PDB_SC_LDOK_MASK                         (0x1U)                                              /*!< PDB0_SC.LDOK Mask                       */
#define PDB_SC_LDOK_SHIFT                        (0U)                                                /*!< PDB0_SC.LDOK Position                   */
#define PDB_SC_LDOK(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PDB0_SC.LDOK Field                      */
#define PDB_SC_CONT_MASK                         (0x2U)                                              /*!< PDB0_SC.CONT Mask                       */
#define PDB_SC_CONT_SHIFT                        (1U)                                                /*!< PDB0_SC.CONT Position                   */
#define PDB_SC_CONT(x)                           (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< PDB0_SC.CONT Field                      */
#define PDB_SC_MULT_MASK                         (0xCU)                                              /*!< PDB0_SC.MULT Mask                       */
#define PDB_SC_MULT_SHIFT                        (2U)                                                /*!< PDB0_SC.MULT Position                   */
#define PDB_SC_MULT(x)                           (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< PDB0_SC.MULT Field                      */
#define PDB_SC_PDBIE_MASK                        (0x20U)                                             /*!< PDB0_SC.PDBIE Mask                      */
#define PDB_SC_PDBIE_SHIFT                       (5U)                                                /*!< PDB0_SC.PDBIE Position                  */
#define PDB_SC_PDBIE(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< PDB0_SC.PDBIE Field                     */
#define PDB_SC_PDBIF_MASK                        (0x40U)                                             /*!< PDB0_SC.PDBIF Mask                      */
#define PDB_SC_PDBIF_SHIFT                       (6U)                                                /*!< PDB0_SC.PDBIF Position                  */
#define PDB_SC_PDBIF(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< PDB0_SC.PDBIF Field                     */
#define PDB_SC_PDBEN_MASK                        (0x80U)                                             /*!< PDB0_SC.PDBEN Mask                      */
#define PDB_SC_PDBEN_SHIFT                       (7U)                                                /*!< PDB0_SC.PDBEN Position                  */
#define PDB_SC_PDBEN(x)                          (((uint32_t)(((uint32_t)(x))<<7U))&0x80UL)          /*!< PDB0_SC.PDBEN Field                     */
#define PDB_SC_TRGSEL_MASK                       (0xF00U)                                            /*!< PDB0_SC.TRGSEL Mask                     */
#define PDB_SC_TRGSEL_SHIFT                      (8U)                                                /*!< PDB0_SC.TRGSEL Position                 */
#define PDB_SC_TRGSEL(x)                         (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< PDB0_SC.TRGSEL Field                    */
#define PDB_SC_PRESCALER_MASK                    (0x7000U)                                           /*!< PDB0_SC.PRESCALER Mask                  */
#define PDB_SC_PRESCALER_SHIFT                   (12U)                                               /*!< PDB0_SC.PRESCALER Position              */
#define PDB_SC_PRESCALER(x)                      (((uint32_t)(((uint32_t)(x))<<12U))&0x7000UL)       /*!< PDB0_SC.PRESCALER Field                 */
#define PDB_SC_DMAEN_MASK                        (0x8000U)                                           /*!< PDB0_SC.DMAEN Mask                      */
#define PDB_SC_DMAEN_SHIFT                       (15U)                                               /*!< PDB0_SC.DMAEN Position                  */
#define PDB_SC_DMAEN(x)                          (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< PDB0_SC.DMAEN Field                     */
#define PDB_SC_SWTRIG_MASK                       (0x10000U)                                          /*!< PDB0_SC.SWTRIG Mask                     */
#define PDB_SC_SWTRIG_SHIFT                      (16U)                                               /*!< PDB0_SC.SWTRIG Position                 */
#define PDB_SC_SWTRIG(x)                         (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< PDB0_SC.SWTRIG Field                    */
#define PDB_SC_PDBEIE_MASK                       (0x20000U)                                          /*!< PDB0_SC.PDBEIE Mask                     */
#define PDB_SC_PDBEIE_SHIFT                      (17U)                                               /*!< PDB0_SC.PDBEIE Position                 */
#define PDB_SC_PDBEIE(x)                         (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< PDB0_SC.PDBEIE Field                    */
#define PDB_SC_LDMOD_MASK                        (0xC0000U)                                          /*!< PDB0_SC.LDMOD Mask                      */
#define PDB_SC_LDMOD_SHIFT                       (18U)                                               /*!< PDB0_SC.LDMOD Position                  */
#define PDB_SC_LDMOD(x)                          (((uint32_t)(((uint32_t)(x))<<18U))&0xC0000UL)      /*!< PDB0_SC.LDMOD Field                     */
/* ------- MOD Bit Fields                           ------ */
#define PDB_MOD_MOD_MASK                         (0xFFFFU)                                           /*!< PDB0_MOD.MOD Mask                       */
#define PDB_MOD_MOD_SHIFT                        (0U)                                                /*!< PDB0_MOD.MOD Position                   */
#define PDB_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< PDB0_MOD.MOD Field                      */
/* ------- CNT Bit Fields                           ------ */
#define PDB_CNT_CNT_MASK                         (0xFFFFU)                                           /*!< PDB0_CNT.CNT Mask                       */
#define PDB_CNT_CNT_SHIFT                        (0U)                                                /*!< PDB0_CNT.CNT Position                   */
#define PDB_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< PDB0_CNT.CNT Field                      */
/* ------- IDLY Bit Fields                          ------ */
#define PDB_IDLY_IDLY_MASK                       (0xFFFFU)                                           /*!< PDB0_IDLY.IDLY Mask                     */
#define PDB_IDLY_IDLY_SHIFT                      (0U)                                                /*!< PDB0_IDLY.IDLY Position                 */
#define PDB_IDLY_IDLY(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< PDB0_IDLY.IDLY Field                    */
/* ------- C1 Bit Fields                            ------ */
#define PDB_C1_EN_MASK                           (0xFFU)                                             /*!< PDB0_C1.EN Mask                         */
#define PDB_C1_EN_SHIFT                          (0U)                                                /*!< PDB0_C1.EN Position                     */
#define PDB_C1_EN(x)                             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< PDB0_C1.EN Field                        */
#define PDB_C1_TOS_MASK                          (0xFF00U)                                           /*!< PDB0_C1.TOS Mask                        */
#define PDB_C1_TOS_SHIFT                         (8U)                                                /*!< PDB0_C1.TOS Position                    */
#define PDB_C1_TOS(x)                            (((uint32_t)(((uint32_t)(x))<<8U))&0xFF00UL)        /*!< PDB0_C1.TOS Field                       */
#define PDB_C1_BB_MASK                           (0xFF0000U)                                         /*!< PDB0_C1.BB Mask                         */
#define PDB_C1_BB_SHIFT                          (16U)                                               /*!< PDB0_C1.BB Position                     */
#define PDB_C1_BB(x)                             (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< PDB0_C1.BB Field                        */
/* ------- S Bit Fields                             ------ */
#define PDB_S_ERR_MASK                           (0xFFU)                                             /*!< PDB0_S.ERR Mask                         */
#define PDB_S_ERR_SHIFT                          (0U)                                                /*!< PDB0_S.ERR Position                     */
#define PDB_S_ERR(x)                             (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< PDB0_S.ERR Field                        */
#define PDB_S_CF_MASK                            (0xFF0000U)                                         /*!< PDB0_S.CF Mask                          */
#define PDB_S_CF_SHIFT                           (16U)                                               /*!< PDB0_S.CF Position                      */
#define PDB_S_CF(x)                              (((uint32_t)(((uint32_t)(x))<<16U))&0xFF0000UL)     /*!< PDB0_S.CF Field                         */
/* ------- DLY Bit Fields                           ------ */
#define PDB_DLY_DLY_MASK                         (0xFFFFU)                                           /*!< PDB0_DLY.DLY Mask                       */
#define PDB_DLY_DLY_SHIFT                        (0U)                                                /*!< PDB0_DLY.DLY Position                   */
#define PDB_DLY_DLY(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< PDB0_DLY.DLY Field                      */
/* ------- INTC Bit Fields                          ------ */
#define PDB_INTC_TOE_MASK                        (0x1U)                                              /*!< PDB0_INTC.TOE Mask                      */
#define PDB_INTC_TOE_SHIFT                       (0U)                                                /*!< PDB0_INTC.TOE Position                  */
#define PDB_INTC_TOE(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PDB0_INTC.TOE Field                     */
#define PDB_INTC_EXT_MASK                        (0x2U)                                              /*!< PDB0_INTC.EXT Mask                      */
#define PDB_INTC_EXT_SHIFT                       (1U)                                                /*!< PDB0_INTC.EXT Position                  */
#define PDB_INTC_EXT(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< PDB0_INTC.EXT Field                     */
/* ------- INT Bit Fields                           ------ */
#define PDB_INT_INT_MASK                         (0xFFFFU)                                           /*!< PDB0_INT.INT Mask                       */
#define PDB_INT_INT_SHIFT                        (0U)                                                /*!< PDB0_INT.INT Position                   */
#define PDB_INT_INT(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< PDB0_INT.INT Field                      */
/* ------- POEN Bit Fields                          ------ */
#define PDB_POEN_POEN_MASK                       (0xFFU)                                             /*!< PDB0_POEN.POEN Mask                     */
#define PDB_POEN_POEN_SHIFT                      (0U)                                                /*!< PDB0_POEN.POEN Position                 */
#define PDB_POEN_POEN(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFUL)          /*!< PDB0_POEN.POEN Field                    */
/* ------- PODLY Bit Fields                         ------ */
#define PDB_PODLY_DLY2_MASK                      (0xFFFFU)                                           /*!< PDB0_PODLY.DLY2 Mask                    */
#define PDB_PODLY_DLY2_SHIFT                     (0U)                                                /*!< PDB0_PODLY.DLY2 Position                */
#define PDB_PODLY_DLY2(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< PDB0_PODLY.DLY2 Field                   */
#define PDB_PODLY_DLY1_MASK                      (0xFFFF0000U)                                       /*!< PDB0_PODLY.DLY1 Mask                    */
#define PDB_PODLY_DLY1_SHIFT                     (16U)                                               /*!< PDB0_PODLY.DLY1 Position                */
#define PDB_PODLY_DLY1(x)                        (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< PDB0_PODLY.DLY1 Field                   */
/**
 * @} */ /* End group PDB_Register_Masks_GROUP 
 */

/* PDB0 - Peripheral instance base addresses */
#define PDB0_BasePtr                   0x40036000UL //!< Peripheral base address
#define PDB0                           ((PDB_Type *) PDB0_BasePtr) //!< Freescale base pointer
#define PDB0_BASE_PTR                  (PDB0) //!< Freescale style base pointer
/**
 * @} */ /* End group PDB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PDB_Peripheral_access_layer_GROUP PDB Peripheral Access Layer
* @brief C Struct for PDB
* @{
*/

/* ================================================================================ */
/* ================           PDB1 (derived from PDB0)             ================ */
/* ================================================================================ */

/**
 * @brief Programmable Delay Block (1 channels, 4 triggers, 1 DAC, 4 pulse outputs)
 */

/* PDB1 - Peripheral instance base addresses */
#define PDB1_BasePtr                   0x40031000UL //!< Peripheral base address
#define PDB1                           ((PDB_Type *) PDB1_BasePtr) //!< Freescale base pointer
#define PDB1_BASE_PTR                  (PDB1) //!< Freescale style base pointer
/**
 * @} */ /* End group PDB_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PIT_Peripheral_access_layer_GROUP PIT Peripheral Access Layer
* @brief C Struct for PIT
* @{
*/

/* ================================================================================ */
/* ================           PIT (file:PIT_4CH_CHAIN)             ================ */
/* ================================================================================ */

/**
 * @brief Periodic Interrupt Timer (4 channels)
 */
/**
* @addtogroup PIT_structs_GROUP PIT struct
* @brief Struct for PIT
* @{
*/
typedef struct {                                /*       PIT Structure                                                */
   __IO uint32_t  MCR;                          /**< 0000: Module Control Register                                      */
        uint8_t   RESERVED_0[252];             
   struct {
      __IO uint32_t  LDVAL;                     /**< 0100: Timer Load Value Register                                    */
      __I  uint32_t  CVAL;                      /**< 0104: Current Timer Value Register                                 */
      __IO uint32_t  TCTRL;                     /**< 0108: Timer Control Register                                       */
      __IO uint32_t  TFLG;                      /**< 010C: Timer Flag Register                                          */
   } CHANNEL[4];                                /**< 0100: (cluster: size=0x0040, 64)                                   */
} PIT_Type;

/**
 * @} */ /* End group PIT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PIT' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PIT_Register_Masks_GROUP PIT Register Masks
* @brief Register Masks for PIT
* @{
*/
/* ------- MCR Bit Fields                           ------ */
#define PIT_MCR_FRZ_MASK                         (0x1U)                                              /*!< PIT_MCR.FRZ Mask                        */
#define PIT_MCR_FRZ_SHIFT                        (0U)                                                /*!< PIT_MCR.FRZ Position                    */
#define PIT_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PIT_MCR.FRZ Field                       */
#define PIT_MCR_MDIS_MASK                        (0x2U)                                              /*!< PIT_MCR.MDIS Mask                       */
#define PIT_MCR_MDIS_SHIFT                       (1U)                                                /*!< PIT_MCR.MDIS Position                   */
#define PIT_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< PIT_MCR.MDIS Field                      */
/* ------- LDVAL Bit Fields                         ------ */
#define PIT_LDVAL_TSV_MASK                       (0xFFFFFFFFU)                                       /*!< PIT_LDVAL.TSV Mask                      */
#define PIT_LDVAL_TSV_SHIFT                      (0U)                                                /*!< PIT_LDVAL.TSV Position                  */
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< PIT_LDVAL.TSV Field                     */
/* ------- CVAL Bit Fields                          ------ */
#define PIT_CVAL_TVL_MASK                        (0xFFFFFFFFU)                                       /*!< PIT_CVAL.TVL Mask                       */
#define PIT_CVAL_TVL_SHIFT                       (0U)                                                /*!< PIT_CVAL.TVL Position                   */
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< PIT_CVAL.TVL Field                      */
/* ------- TCTRL Bit Fields                         ------ */
#define PIT_TCTRL_TEN_MASK                       (0x1U)                                              /*!< PIT_TCTRL.TEN Mask                      */
#define PIT_TCTRL_TEN_SHIFT                      (0U)                                                /*!< PIT_TCTRL.TEN Position                  */
#define PIT_TCTRL_TEN(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PIT_TCTRL.TEN Field                     */
#define PIT_TCTRL_TIE_MASK                       (0x2U)                                              /*!< PIT_TCTRL.TIE Mask                      */
#define PIT_TCTRL_TIE_SHIFT                      (1U)                                                /*!< PIT_TCTRL.TIE Position                  */
#define PIT_TCTRL_TIE(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< PIT_TCTRL.TIE Field                     */
#define PIT_TCTRL_CHN_MASK                       (0x4U)                                              /*!< PIT_TCTRL.CHN Mask                      */
#define PIT_TCTRL_CHN_SHIFT                      (2U)                                                /*!< PIT_TCTRL.CHN Position                  */
#define PIT_TCTRL_CHN(x)                         (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< PIT_TCTRL.CHN Field                     */
/* ------- TFLG Bit Fields                          ------ */
#define PIT_TFLG_TIF_MASK                        (0x1U)                                              /*!< PIT_TFLG.TIF Mask                       */
#define PIT_TFLG_TIF_SHIFT                       (0U)                                                /*!< PIT_TFLG.TIF Position                   */
#define PIT_TFLG_TIF(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PIT_TFLG.TIF Field                      */
/**
 * @} */ /* End group PIT_Register_Masks_GROUP 
 */

/* PIT - Peripheral instance base addresses */
#define PIT_BasePtr                    0x40037000UL //!< Peripheral base address
#define PIT                            ((PIT_Type *) PIT_BasePtr) //!< Freescale base pointer
#define PIT_BASE_PTR                   (PIT) //!< Freescale style base pointer
/**
 * @} */ /* End group PIT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PMC_Peripheral_access_layer_GROUP PMC Peripheral Access Layer
* @brief C Struct for PMC
* @{
*/

/* ================================================================================ */
/* ================           PMC (file:PMC_MKM)                   ================ */
/* ================================================================================ */

/**
 * @brief Power Management Controller
 */
/**
* @addtogroup PMC_structs_GROUP PMC struct
* @brief Struct for PMC
* @{
*/
typedef struct {                                /*       PMC Structure                                                */
   __IO uint8_t   LVDSC1;                       /**< 0000: Low Voltage Detect Status and Control 1 Register             */
   __IO uint8_t   LVDSC2;                       /**< 0001: Low Voltage Detect Status and Control 2 Register             */
   __IO uint8_t   REGSC;                        /**< 0002: Regulator Status and Control Register                        */
} PMC_Type;

/**
 * @} */ /* End group PMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PMC_Register_Masks_GROUP PMC Register Masks
* @brief Register Masks for PMC
* @{
*/
/* ------- LVDSC1 Bit Fields                        ------ */
#define PMC_LVDSC1_LVDV_MASK                     (0x3U)                                              /*!< PMC_LVDSC1.LVDV Mask                    */
#define PMC_LVDSC1_LVDV_SHIFT                    (0U)                                                /*!< PMC_LVDSC1.LVDV Position                */
#define PMC_LVDSC1_LVDV(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< PMC_LVDSC1.LVDV Field                   */
#define PMC_LVDSC1_LVDRE_MASK                    (0x10U)                                             /*!< PMC_LVDSC1.LVDRE Mask                   */
#define PMC_LVDSC1_LVDRE_SHIFT                   (4U)                                                /*!< PMC_LVDSC1.LVDRE Position               */
#define PMC_LVDSC1_LVDRE(x)                      (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< PMC_LVDSC1.LVDRE Field                  */
#define PMC_LVDSC1_LVDIE_MASK                    (0x20U)                                             /*!< PMC_LVDSC1.LVDIE Mask                   */
#define PMC_LVDSC1_LVDIE_SHIFT                   (5U)                                                /*!< PMC_LVDSC1.LVDIE Position               */
#define PMC_LVDSC1_LVDIE(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< PMC_LVDSC1.LVDIE Field                  */
#define PMC_LVDSC1_LVDACK_MASK                   (0x40U)                                             /*!< PMC_LVDSC1.LVDACK Mask                  */
#define PMC_LVDSC1_LVDACK_SHIFT                  (6U)                                                /*!< PMC_LVDSC1.LVDACK Position              */
#define PMC_LVDSC1_LVDACK(x)                     (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< PMC_LVDSC1.LVDACK Field                 */
#define PMC_LVDSC1_LVDF_MASK                     (0x80U)                                             /*!< PMC_LVDSC1.LVDF Mask                    */
#define PMC_LVDSC1_LVDF_SHIFT                    (7U)                                                /*!< PMC_LVDSC1.LVDF Position                */
#define PMC_LVDSC1_LVDF(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< PMC_LVDSC1.LVDF Field                   */
/* ------- LVDSC2 Bit Fields                        ------ */
#define PMC_LVDSC2_LVWV_MASK                     (0x3U)                                              /*!< PMC_LVDSC2.LVWV Mask                    */
#define PMC_LVDSC2_LVWV_SHIFT                    (0U)                                                /*!< PMC_LVDSC2.LVWV Position                */
#define PMC_LVDSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< PMC_LVDSC2.LVWV Field                   */
#define PMC_LVDSC2_LVWIE_MASK                    (0x20U)                                             /*!< PMC_LVDSC2.LVWIE Mask                   */
#define PMC_LVDSC2_LVWIE_SHIFT                   (5U)                                                /*!< PMC_LVDSC2.LVWIE Position               */
#define PMC_LVDSC2_LVWIE(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< PMC_LVDSC2.LVWIE Field                  */
#define PMC_LVDSC2_LVWACK_MASK                   (0x40U)                                             /*!< PMC_LVDSC2.LVWACK Mask                  */
#define PMC_LVDSC2_LVWACK_SHIFT                  (6U)                                                /*!< PMC_LVDSC2.LVWACK Position              */
#define PMC_LVDSC2_LVWACK(x)                     (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< PMC_LVDSC2.LVWACK Field                 */
#define PMC_LVDSC2_LVWF_MASK                     (0x80U)                                             /*!< PMC_LVDSC2.LVWF Mask                    */
#define PMC_LVDSC2_LVWF_SHIFT                    (7U)                                                /*!< PMC_LVDSC2.LVWF Position                */
#define PMC_LVDSC2_LVWF(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< PMC_LVDSC2.LVWF Field                   */
/* ------- REGSC Bit Fields                         ------ */
#define PMC_REGSC_BGBE_MASK                      (0x1U)                                              /*!< PMC_REGSC.BGBE Mask                     */
#define PMC_REGSC_BGBE_SHIFT                     (0U)                                                /*!< PMC_REGSC.BGBE Position                 */
#define PMC_REGSC_BGBE(x)                        (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< PMC_REGSC.BGBE Field                    */
#define PMC_REGSC_BGBDS_MASK                     (0x2U)                                              /*!< PMC_REGSC.BGBDS Mask                    */
#define PMC_REGSC_BGBDS_SHIFT                    (1U)                                                /*!< PMC_REGSC.BGBDS Position                */
#define PMC_REGSC_BGBDS(x)                       (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< PMC_REGSC.BGBDS Field                   */
#define PMC_REGSC_REGONS_MASK                    (0x4U)                                              /*!< PMC_REGSC.REGONS Mask                   */
#define PMC_REGSC_REGONS_SHIFT                   (2U)                                                /*!< PMC_REGSC.REGONS Position               */
#define PMC_REGSC_REGONS(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< PMC_REGSC.REGONS Field                  */
#define PMC_REGSC_ACKISO_MASK                    (0x8U)                                              /*!< PMC_REGSC.ACKISO Mask                   */
#define PMC_REGSC_ACKISO_SHIFT                   (3U)                                                /*!< PMC_REGSC.ACKISO Position               */
#define PMC_REGSC_ACKISO(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< PMC_REGSC.ACKISO Field                  */
#define PMC_REGSC_BGEN_MASK                      (0x10U)                                             /*!< PMC_REGSC.BGEN Mask                     */
#define PMC_REGSC_BGEN_SHIFT                     (4U)                                                /*!< PMC_REGSC.BGEN Position                 */
#define PMC_REGSC_BGEN(x)                        (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< PMC_REGSC.BGEN Field                    */
/**
 * @} */ /* End group PMC_Register_Masks_GROUP 
 */

/* PMC - Peripheral instance base addresses */
#define PMC_BasePtr                    0x4007D000UL //!< Peripheral base address
#define PMC                            ((PMC_Type *) PMC_BasePtr) //!< Freescale base pointer
#define PMC_BASE_PTR                   (PMC) //!< Freescale style base pointer
/**
 * @} */ /* End group PMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTA (file:PORTA)                   ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
/**
* @addtogroup PORT_structs_GROUP PORT struct
* @brief Struct for PORT
* @{
*/
typedef struct {                                /*       PORTA Structure                                              */
   __IO uint32_t  PCR[32];                      /**< 0000: Pin Control Register                                         */
   __O  uint32_t  GPCLR;                        /**< 0080: Global Pin Control Low Register                              */
   __O  uint32_t  GPCHR;                        /**< 0084: Global Pin Control High Register                             */
        uint8_t   RESERVED_0[24];              
   __IO uint32_t  ISFR;                         /**< 00A0: Interrupt Status Flag Register                               */
} PORT_Type;

/**
 * @} */ /* End group PORT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PORTA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PORT_Register_Masks_GROUP PORT Register Masks
* @brief Register Masks for PORT
* @{
*/
/* ------- PCR Bit Fields                           ------ */
#define PORT_PCR_PD_MASK                         (0x3U)                                              /*!< PORTA_PCR.PD Mask                       */
#define PORT_PCR_PD_SHIFT                        (0U)                                                /*!< PORTA_PCR.PD Position                   */
#define PORT_PCR_PD(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< PORTA_PCR.PD Field                      */
#define PORT_PCR_PS_MASK                         (0x1U)                                              /*!< PORTA_PCR.PS Mask                       */
#define PORT_PCR_PS_SHIFT                        (0U)                                                /*!< PORTA_PCR.PS Position                   */
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PORTA_PCR.PS Field                      */
#define PORT_PCR_PE_MASK                         (0x2U)                                              /*!< PORTA_PCR.PE Mask                       */
#define PORT_PCR_PE_SHIFT                        (1U)                                                /*!< PORTA_PCR.PE Position                   */
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< PORTA_PCR.PE Field                      */
#define PORT_PCR_SRE_MASK                        (0x4U)                                              /*!< PORTA_PCR.SRE Mask                      */
#define PORT_PCR_SRE_SHIFT                       (2U)                                                /*!< PORTA_PCR.SRE Position                  */
#define PORT_PCR_SRE(x)                          (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< PORTA_PCR.SRE Field                     */
#define PORT_PCR_PFE_MASK                        (0x10U)                                             /*!< PORTA_PCR.PFE Mask                      */
#define PORT_PCR_PFE_SHIFT                       (4U)                                                /*!< PORTA_PCR.PFE Position                  */
#define PORT_PCR_PFE(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< PORTA_PCR.PFE Field                     */
#define PORT_PCR_ODE_MASK                        (0x20U)                                             /*!< PORTA_PCR.ODE Mask                      */
#define PORT_PCR_ODE_SHIFT                       (5U)                                                /*!< PORTA_PCR.ODE Position                  */
#define PORT_PCR_ODE(x)                          (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< PORTA_PCR.ODE Field                     */
#define PORT_PCR_DSE_MASK                        (0x40U)                                             /*!< PORTA_PCR.DSE Mask                      */
#define PORT_PCR_DSE_SHIFT                       (6U)                                                /*!< PORTA_PCR.DSE Position                  */
#define PORT_PCR_DSE(x)                          (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< PORTA_PCR.DSE Field                     */
#define PORT_PCR_MUX_MASK                        (0x700U)                                            /*!< PORTA_PCR.MUX Mask                      */
#define PORT_PCR_MUX_SHIFT                       (8U)                                                /*!< PORTA_PCR.MUX Position                  */
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0x700UL)         /*!< PORTA_PCR.MUX Field                     */
#define PORT_PCR_LK_MASK                         (0x8000U)                                           /*!< PORTA_PCR.LK Mask                       */
#define PORT_PCR_LK_SHIFT                        (15U)                                               /*!< PORTA_PCR.LK Position                   */
#define PORT_PCR_LK(x)                           (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< PORTA_PCR.LK Field                      */
#define PORT_PCR_IRQC_MASK                       (0xF0000U)                                          /*!< PORTA_PCR.IRQC Mask                     */
#define PORT_PCR_IRQC_SHIFT                      (16U)                                               /*!< PORTA_PCR.IRQC Position                 */
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x))<<16U))&0xF0000UL)      /*!< PORTA_PCR.IRQC Field                    */
#define PORT_PCR_ISF_MASK                        (0x1000000U)                                        /*!< PORTA_PCR.ISF Mask                      */
#define PORT_PCR_ISF_SHIFT                       (24U)                                               /*!< PORTA_PCR.ISF Position                  */
#define PORT_PCR_ISF(x)                          (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< PORTA_PCR.ISF Field                     */
/* ------- GPCLR Bit Fields                         ------ */
#define PORT_GPCLR_GPWD_MASK                     (0xFFFFU)                                           /*!< PORTA_GPCLR.GPWD Mask                   */
#define PORT_GPCLR_GPWD_SHIFT                    (0U)                                                /*!< PORTA_GPCLR.GPWD Position               */
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< PORTA_GPCLR.GPWD Field                  */
#define PORT_GPCLR_GPWE_MASK                     (0xFFFF0000U)                                       /*!< PORTA_GPCLR.GPWE Mask                   */
#define PORT_GPCLR_GPWE_SHIFT                    (16U)                                               /*!< PORTA_GPCLR.GPWE Position               */
#define PORT_GPCLR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< PORTA_GPCLR.GPWE Field                  */
/* ------- GPCHR Bit Fields                         ------ */
#define PORT_GPCHR_GPWD_MASK                     (0xFFFFU)                                           /*!< PORTA_GPCHR.GPWD Mask                   */
#define PORT_GPCHR_GPWD_SHIFT                    (0U)                                                /*!< PORTA_GPCHR.GPWD Position               */
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< PORTA_GPCHR.GPWD Field                  */
#define PORT_GPCHR_GPWE_MASK                     (0xFFFF0000U)                                       /*!< PORTA_GPCHR.GPWE Mask                   */
#define PORT_GPCHR_GPWE_SHIFT                    (16U)                                               /*!< PORTA_GPCHR.GPWE Position               */
#define PORT_GPCHR_GPWE(x)                       (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< PORTA_GPCHR.GPWE Field                  */
/* ------- ISFR Bit Fields                          ------ */
/**
 * @} */ /* End group PORT_Register_Masks_GROUP 
 */

/* PORTA - Peripheral instance base addresses */
#define PORTA_BasePtr                  0x40049000UL //!< Peripheral base address
#define PORTA                          ((PORT_Type *) PORTA_BasePtr) //!< Freescale base pointer
#define PORTA_BASE_PTR                 (PORTA) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTB (derived from PORTA)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTB - Peripheral instance base addresses */
#define PORTB_BasePtr                  0x4004A000UL //!< Peripheral base address
#define PORTB                          ((PORT_Type *) PORTB_BasePtr) //!< Freescale base pointer
#define PORTB_BASE_PTR                 (PORTB) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTC (derived from PORTB)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTC - Peripheral instance base addresses */
#define PORTC_BasePtr                  0x4004B000UL //!< Peripheral base address
#define PORTC                          ((PORT_Type *) PORTC_BasePtr) //!< Freescale base pointer
#define PORTC_BASE_PTR                 (PORTC) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTD (file:PORTD_DFER)              ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */
/**
* @addtogroup PORT_structs_GROUP PORT struct
* @brief Struct for PORT
* @{
*/
typedef struct {                                /*       PORTD Structure                                              */
   __IO uint32_t  PCR[32];                      /**< 0000: Pin Control Register                                         */
   __O  uint32_t  GPCLR;                        /**< 0080: Global Pin Control Low Register                              */
   __O  uint32_t  GPCHR;                        /**< 0084: Global Pin Control High Register                             */
        uint8_t   RESERVED_0[24];              
   __IO uint32_t  ISFR;                         /**< 00A0: Interrupt Status Flag Register                               */
        uint8_t   RESERVED_1[28];              
   __IO uint32_t  DFER;                         /**< 00C0: Digital Filter Enable Register                               */
   __IO uint32_t  DFCR;                         /**< 00C4: Digital Filter Clock Register                                */
   __IO uint32_t  DFWR;                         /**< 00C8: Digital Filter Width Register                                */
} PORTD_Type;

/**
 * @} */ /* End group PORT_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'PORTD' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup PORT_Register_Masks_GROUP PORT Register Masks
* @brief Register Masks for PORT
* @{
*/
/* ------- PCR Bit Fields                           ------ */
/* ------- GPCLR Bit Fields                         ------ */
/* ------- GPCHR Bit Fields                         ------ */
/* ------- ISFR Bit Fields                          ------ */
/* ------- DFER Bit Fields                          ------ */
/* ------- DFCR Bit Fields                          ------ */
#define PORT_DFCR_CS_MASK                        (0x1U)                                              /*!< PORTD_DFCR.CS Mask                      */
#define PORT_DFCR_CS_SHIFT                       (0U)                                                /*!< PORTD_DFCR.CS Position                  */
#define PORT_DFCR_CS(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< PORTD_DFCR.CS Field                     */
/* ------- DFWR Bit Fields                          ------ */
#define PORT_DFWR_FILT_MASK                      (0x1FU)                                             /*!< PORTD_DFWR.FILT Mask                    */
#define PORT_DFWR_FILT_SHIFT                     (0U)                                                /*!< PORTD_DFWR.FILT Position                */
#define PORT_DFWR_FILT(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x1FUL)          /*!< PORTD_DFWR.FILT Field                   */
/**
 * @} */ /* End group PORT_Register_Masks_GROUP 
 */

/* PORTD - Peripheral instance base addresses */
#define PORTD_BasePtr                  0x4004C000UL //!< Peripheral base address
#define PORTD                          ((PORTD_Type *) PORTD_BasePtr) //!< Freescale base pointer
#define PORTD_BASE_PTR                 (PORTD) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup PORT_Peripheral_access_layer_GROUP PORT Peripheral Access Layer
* @brief C Struct for PORT
* @{
*/

/* ================================================================================ */
/* ================           PORTE (derived from PORTB)           ================ */
/* ================================================================================ */

/**
 * @brief Pin Control and Interrupts
 */

/* PORTE - Peripheral instance base addresses */
#define PORTE_BasePtr                  0x4004D000UL //!< Peripheral base address
#define PORTE                          ((PORT_Type *) PORTE_BasePtr) //!< Freescale base pointer
#define PORTE_BASE_PTR                 (PORTE) //!< Freescale style base pointer
/**
 * @} */ /* End group PORT_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup RCM_Peripheral_access_layer_GROUP RCM Peripheral Access Layer
* @brief C Struct for RCM
* @{
*/

/* ================================================================================ */
/* ================           RCM (file:RCM_MKV40F15)              ================ */
/* ================================================================================ */

/**
 * @brief Reset Control Module
 */
/**
* @addtogroup RCM_structs_GROUP RCM struct
* @brief Struct for RCM
* @{
*/
typedef struct {                                /*       RCM Structure                                                */
   __I  uint8_t   SRS0;                         /**< 0000: System Reset Status Register 0                               */
   __I  uint8_t   SRS1;                         /**< 0001: System Reset Status Register 1                               */
        uint8_t   RESERVED_0[2];               
   __IO uint8_t   RPFC;                         /**< 0004: Reset Pin Filter Control Register                            */
   __IO uint8_t   RPFW;                         /**< 0005: Reset Pin Filter Width Register                              */
        uint8_t   RESERVED_1[2];               
   __IO uint8_t   SSRS0;                        /**< 0008: Sticky System Reset Status Register 0                        */
   __IO uint8_t   SSRS1;                        /**< 0009: Sticky System Reset Status Register 1                        */
} RCM_Type;

/**
 * @} */ /* End group RCM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'RCM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup RCM_Register_Masks_GROUP RCM Register Masks
* @brief Register Masks for RCM
* @{
*/
/* ------- SRS0 Bit Fields                          ------ */
#define RCM_SRS0_WAKEUP_MASK                     (0x1U)                                              /*!< RCM_SRS0.WAKEUP Mask                    */
#define RCM_SRS0_WAKEUP_SHIFT                    (0U)                                                /*!< RCM_SRS0.WAKEUP Position                */
#define RCM_SRS0_WAKEUP(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< RCM_SRS0.WAKEUP Field                   */
#define RCM_SRS0_LVD_MASK                        (0x2U)                                              /*!< RCM_SRS0.LVD Mask                       */
#define RCM_SRS0_LVD_SHIFT                       (1U)                                                /*!< RCM_SRS0.LVD Position                   */
#define RCM_SRS0_LVD(x)                          (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< RCM_SRS0.LVD Field                      */
#define RCM_SRS0_LOC_MASK                        (0x4U)                                              /*!< RCM_SRS0.LOC Mask                       */
#define RCM_SRS0_LOC_SHIFT                       (2U)                                                /*!< RCM_SRS0.LOC Position                   */
#define RCM_SRS0_LOC(x)                          (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< RCM_SRS0.LOC Field                      */
#define RCM_SRS0_LOL_MASK                        (0x8U)                                              /*!< RCM_SRS0.LOL Mask                       */
#define RCM_SRS0_LOL_SHIFT                       (3U)                                                /*!< RCM_SRS0.LOL Position                   */
#define RCM_SRS0_LOL(x)                          (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< RCM_SRS0.LOL Field                      */
#define RCM_SRS0_WDOG_MASK                       (0x20U)                                             /*!< RCM_SRS0.WDOG Mask                      */
#define RCM_SRS0_WDOG_SHIFT                      (5U)                                                /*!< RCM_SRS0.WDOG Position                  */
#define RCM_SRS0_WDOG(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< RCM_SRS0.WDOG Field                     */
#define RCM_SRS0_PIN_MASK                        (0x40U)                                             /*!< RCM_SRS0.PIN Mask                       */
#define RCM_SRS0_PIN_SHIFT                       (6U)                                                /*!< RCM_SRS0.PIN Position                   */
#define RCM_SRS0_PIN(x)                          (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< RCM_SRS0.PIN Field                      */
#define RCM_SRS0_POR_MASK                        (0x80U)                                             /*!< RCM_SRS0.POR Mask                       */
#define RCM_SRS0_POR_SHIFT                       (7U)                                                /*!< RCM_SRS0.POR Position                   */
#define RCM_SRS0_POR(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< RCM_SRS0.POR Field                      */
/* ------- SRS1 Bit Fields                          ------ */
#define RCM_SRS1_LOCKUP_MASK                     (0x2U)                                              /*!< RCM_SRS1.LOCKUP Mask                    */
#define RCM_SRS1_LOCKUP_SHIFT                    (1U)                                                /*!< RCM_SRS1.LOCKUP Position                */
#define RCM_SRS1_LOCKUP(x)                       (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< RCM_SRS1.LOCKUP Field                   */
#define RCM_SRS1_SW_MASK                         (0x4U)                                              /*!< RCM_SRS1.SW Mask                        */
#define RCM_SRS1_SW_SHIFT                        (2U)                                                /*!< RCM_SRS1.SW Position                    */
#define RCM_SRS1_SW(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< RCM_SRS1.SW Field                       */
#define RCM_SRS1_MDM_AP_MASK                     (0x8U)                                              /*!< RCM_SRS1.MDM_AP Mask                    */
#define RCM_SRS1_MDM_AP_SHIFT                    (3U)                                                /*!< RCM_SRS1.MDM_AP Position                */
#define RCM_SRS1_MDM_AP(x)                       (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< RCM_SRS1.MDM_AP Field                   */
#define RCM_SRS1_SACKERR_MASK                    (0x20U)                                             /*!< RCM_SRS1.SACKERR Mask                   */
#define RCM_SRS1_SACKERR_SHIFT                   (5U)                                                /*!< RCM_SRS1.SACKERR Position               */
#define RCM_SRS1_SACKERR(x)                      (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< RCM_SRS1.SACKERR Field                  */
/* ------- RPFC Bit Fields                          ------ */
#define RCM_RPFC_RSTFLTSRW_MASK                  (0x3U)                                              /*!< RCM_RPFC.RSTFLTSRW Mask                 */
#define RCM_RPFC_RSTFLTSRW_SHIFT                 (0U)                                                /*!< RCM_RPFC.RSTFLTSRW Position             */
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x3UL)             /*!< RCM_RPFC.RSTFLTSRW Field                */
#define RCM_RPFC_RSTFLTSS_MASK                   (0x4U)                                              /*!< RCM_RPFC.RSTFLTSS Mask                  */
#define RCM_RPFC_RSTFLTSS_SHIFT                  (2U)                                                /*!< RCM_RPFC.RSTFLTSS Position              */
#define RCM_RPFC_RSTFLTSS(x)                     (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< RCM_RPFC.RSTFLTSS Field                 */
/* ------- RPFW Bit Fields                          ------ */
#define RCM_RPFW_RSTFLTSEL_MASK                  (0x1FU)                                             /*!< RCM_RPFW.RSTFLTSEL Mask                 */
#define RCM_RPFW_RSTFLTSEL_SHIFT                 (0U)                                                /*!< RCM_RPFW.RSTFLTSEL Position             */
#define RCM_RPFW_RSTFLTSEL(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x1FUL)            /*!< RCM_RPFW.RSTFLTSEL Field                */
/* ------- SSRS0 Bit Fields                         ------ */
#define RCM_SSRS0_SWAKEUP_MASK                   (0x1U)                                              /*!< RCM_SSRS0.SWAKEUP Mask                  */
#define RCM_SSRS0_SWAKEUP_SHIFT                  (0U)                                                /*!< RCM_SSRS0.SWAKEUP Position              */
#define RCM_SSRS0_SWAKEUP(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< RCM_SSRS0.SWAKEUP Field                 */
#define RCM_SSRS0_SLVD_MASK                      (0x2U)                                              /*!< RCM_SSRS0.SLVD Mask                     */
#define RCM_SSRS0_SLVD_SHIFT                     (1U)                                                /*!< RCM_SSRS0.SLVD Position                 */
#define RCM_SSRS0_SLVD(x)                        (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< RCM_SSRS0.SLVD Field                    */
#define RCM_SSRS0_SLOC_MASK                      (0x4U)                                              /*!< RCM_SSRS0.SLOC Mask                     */
#define RCM_SSRS0_SLOC_SHIFT                     (2U)                                                /*!< RCM_SSRS0.SLOC Position                 */
#define RCM_SSRS0_SLOC(x)                        (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< RCM_SSRS0.SLOC Field                    */
#define RCM_SSRS0_SLOL_MASK                      (0x8U)                                              /*!< RCM_SSRS0.SLOL Mask                     */
#define RCM_SSRS0_SLOL_SHIFT                     (3U)                                                /*!< RCM_SSRS0.SLOL Position                 */
#define RCM_SSRS0_SLOL(x)                        (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< RCM_SSRS0.SLOL Field                    */
#define RCM_SSRS0_SWDOG_MASK                     (0x20U)                                             /*!< RCM_SSRS0.SWDOG Mask                    */
#define RCM_SSRS0_SWDOG_SHIFT                    (5U)                                                /*!< RCM_SSRS0.SWDOG Position                */
#define RCM_SSRS0_SWDOG(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< RCM_SSRS0.SWDOG Field                   */
#define RCM_SSRS0_SPIN_MASK                      (0x40U)                                             /*!< RCM_SSRS0.SPIN Mask                     */
#define RCM_SSRS0_SPIN_SHIFT                     (6U)                                                /*!< RCM_SSRS0.SPIN Position                 */
#define RCM_SSRS0_SPIN(x)                        (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< RCM_SSRS0.SPIN Field                    */
#define RCM_SSRS0_SPOR_MASK                      (0x80U)                                             /*!< RCM_SSRS0.SPOR Mask                     */
#define RCM_SSRS0_SPOR_SHIFT                     (7U)                                                /*!< RCM_SSRS0.SPOR Position                 */
#define RCM_SSRS0_SPOR(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< RCM_SSRS0.SPOR Field                    */
/* ------- SSRS1 Bit Fields                         ------ */
#define RCM_SSRS1_SLOCKUP_MASK                   (0x2U)                                              /*!< RCM_SSRS1.SLOCKUP Mask                  */
#define RCM_SSRS1_SLOCKUP_SHIFT                  (1U)                                                /*!< RCM_SSRS1.SLOCKUP Position              */
#define RCM_SSRS1_SLOCKUP(x)                     (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< RCM_SSRS1.SLOCKUP Field                 */
#define RCM_SSRS1_SSW_MASK                       (0x4U)                                              /*!< RCM_SSRS1.SSW Mask                      */
#define RCM_SSRS1_SSW_SHIFT                      (2U)                                                /*!< RCM_SSRS1.SSW Position                  */
#define RCM_SSRS1_SSW(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< RCM_SSRS1.SSW Field                     */
#define RCM_SSRS1_SMDM_AP_MASK                   (0x8U)                                              /*!< RCM_SSRS1.SMDM_AP Mask                  */
#define RCM_SSRS1_SMDM_AP_SHIFT                  (3U)                                                /*!< RCM_SSRS1.SMDM_AP Position              */
#define RCM_SSRS1_SMDM_AP(x)                     (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< RCM_SSRS1.SMDM_AP Field                 */
#define RCM_SSRS1_SSACKERR_MASK                  (0x20U)                                             /*!< RCM_SSRS1.SSACKERR Mask                 */
#define RCM_SSRS1_SSACKERR_SHIFT                 (5U)                                                /*!< RCM_SSRS1.SSACKERR Position             */
#define RCM_SSRS1_SSACKERR(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< RCM_SSRS1.SSACKERR Field                */
/**
 * @} */ /* End group RCM_Register_Masks_GROUP 
 */

/* RCM - Peripheral instance base addresses */
#define RCM_BasePtr                    0x4007F000UL //!< Peripheral base address
#define RCM                            ((RCM_Type *) RCM_BasePtr) //!< Freescale base pointer
#define RCM_BASE_PTR                   (RCM) //!< Freescale style base pointer
/**
 * @} */ /* End group RCM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SIM_Peripheral_access_layer_GROUP SIM Peripheral Access Layer
* @brief C Struct for SIM
* @{
*/

/* ================================================================================ */
/* ================           SIM (file:SIM_MKV40F15)              ================ */
/* ================================================================================ */

/**
 * @brief System Integration Module
 */
/**
* @addtogroup SIM_structs_GROUP SIM struct
* @brief Struct for SIM
* @{
*/
typedef struct {                                /*       SIM Structure                                                */
   __IO uint32_t  SOPT1;                        /**< 0000: System Options Register 1                                    */
        uint8_t   RESERVED_0[4096];            
   __IO uint32_t  SOPT2;                        /**< 1004: System Options Register 2                                    */
        uint8_t   RESERVED_1[4];               
   __IO uint32_t  SOPT4;                        /**< 100C: System Options Register 4                                    */
   __IO uint32_t  SOPT5;                        /**< 1010: System Options Register 5                                    */
        uint8_t   RESERVED_2[4];               
   __IO uint32_t  SOPT7;                        /**< 1018: System Options Register 7                                    */
   __IO uint32_t  SOPT8;                        /**< 101C: System Options Register 8                                    */
   __IO uint32_t  SOPT9;                        /**< 1020: System Options Register 9                                    */
   __I  uint32_t  SDID;                         /**< 1024: System Device Identification Register                        */
        uint8_t   RESERVED_3[12];              
   __IO uint32_t  SCGC4;                        /**< 1034: System Clock Gating Control Register 4                       */
   __IO uint32_t  SCGC5;                        /**< 1038: System Clock Gating Control Register 5                       */
   __IO uint32_t  SCGC6;                        /**< 103C: System Clock Gating Control Register 6                       */
   __IO uint32_t  SCGC7;                        /**< 1040: System Clock Gating Control Register 7                       */
   __IO uint32_t  CLKDIV1;                      /**< 1044: System Clock Divider Register 1                              */
        uint8_t   RESERVED_4[4];               
   __IO uint32_t  FCFG1;                        /**< 104C: Flash Configuration Register 1                               */
   __I  uint32_t  FCFG2;                        /**< 1050: Flash Configuration Register 2                               */
   __I  uint32_t  UIDH;                         /**< 1054: Unique Identification Register High                          */
   __I  uint32_t  UIDMH;                        /**< 1058: Unique Identification Register Mid-High                      */
   __I  uint32_t  UIDML;                        /**< 105C: Unique Identification Register Mid Low                       */
   __I  uint32_t  UIDL;                         /**< 1060: Unique Identification Register Low                           */
        uint8_t   RESERVED_5[4];               
   __IO uint32_t  CLKDIV4;                      /**< 1068: System Clock Divider Register 4                              */
   __IO uint32_t  MISCTRL;                      /**< 106C: Miscellaneous Control Register                               */
   __IO uint32_t  MISCTRL2;                     /**< 1070: Miscellaneous Control Register 2                             */
        uint8_t   RESERVED_6[140];             
   __IO uint32_t  WDOGC;                        /**< 1100: WDOG Control Register                                        */
   __IO uint32_t  PWRC;                         /**< 1104: Power Control Register                                       */
   __IO uint32_t  ADCOPT;                       /**< 1108: ADC Channel 6/7 Mux Control Register                         */
} SIM_Type;

/**
 * @} */ /* End group SIM_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SIM' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SIM_Register_Masks_GROUP SIM Register Masks
* @brief Register Masks for SIM
* @{
*/
/* ------- SOPT1 Bit Fields                         ------ */
#define SIM_SOPT1_RAMSIZE_MASK                   (0xF000U)                                           /*!< SIM_SOPT1.RAMSIZE Mask                  */
#define SIM_SOPT1_RAMSIZE_SHIFT                  (12U)                                               /*!< SIM_SOPT1.RAMSIZE Position              */
#define SIM_SOPT1_RAMSIZE(x)                     (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< SIM_SOPT1.RAMSIZE Field                 */
#define SIM_SOPT1_OSC32KSEL_MASK                 (0xC0000U)                                          /*!< SIM_SOPT1.OSC32KSEL Mask                */
#define SIM_SOPT1_OSC32KSEL_SHIFT                (18U)                                               /*!< SIM_SOPT1.OSC32KSEL Position            */
#define SIM_SOPT1_OSC32KSEL(x)                   (((uint32_t)(((uint32_t)(x))<<18U))&0xC0000UL)      /*!< SIM_SOPT1.OSC32KSEL Field               */
/* ------- SOPT2 Bit Fields                         ------ */
#define SIM_SOPT2_CLKOUTSEL_MASK                 (0xE0U)                                             /*!< SIM_SOPT2.CLKOUTSEL Mask                */
#define SIM_SOPT2_CLKOUTSEL_SHIFT                (5U)                                                /*!< SIM_SOPT2.CLKOUTSEL Position            */
#define SIM_SOPT2_CLKOUTSEL(x)                   (((uint32_t)(((uint32_t)(x))<<5U))&0xE0UL)          /*!< SIM_SOPT2.CLKOUTSEL Field               */
#define SIM_SOPT2_TRACECLKSEL_MASK               (0x1000U)                                           /*!< SIM_SOPT2.TRACECLKSEL Mask              */
#define SIM_SOPT2_TRACECLKSEL_SHIFT              (12U)                                               /*!< SIM_SOPT2.TRACECLKSEL Position          */
#define SIM_SOPT2_TRACECLKSEL(x)                 (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SIM_SOPT2.TRACECLKSEL Field             */
#define SIM_SOPT2_NANOEDGECLK2XSEL_MASK          (0x80000000U)                                       /*!< SIM_SOPT2.NANOEDGECLK2XSEL Mask         */
#define SIM_SOPT2_NANOEDGECLK2XSEL_SHIFT         (31U)                                               /*!< SIM_SOPT2.NANOEDGECLK2XSEL Position     */
#define SIM_SOPT2_NANOEDGECLK2XSEL(x)            (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SIM_SOPT2.NANOEDGECLK2XSEL Field        */
/* ------- SOPT4 Bit Fields                         ------ */
#define SIM_SOPT4_FTM0FLT0_MASK                  (0x1U)                                              /*!< SIM_SOPT4.FTM0FLT0 Mask                 */
#define SIM_SOPT4_FTM0FLT0_SHIFT                 (0U)                                                /*!< SIM_SOPT4.FTM0FLT0 Position             */
#define SIM_SOPT4_FTM0FLT0(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SIM_SOPT4.FTM0FLT0 Field                */
#define SIM_SOPT4_FTM0FLT1_MASK                  (0x2U)                                              /*!< SIM_SOPT4.FTM0FLT1 Mask                 */
#define SIM_SOPT4_FTM0FLT1_SHIFT                 (1U)                                                /*!< SIM_SOPT4.FTM0FLT1 Position             */
#define SIM_SOPT4_FTM0FLT1(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SIM_SOPT4.FTM0FLT1 Field                */
#define SIM_SOPT4_FTM0FLT2_MASK                  (0x4U)                                              /*!< SIM_SOPT4.FTM0FLT2 Mask                 */
#define SIM_SOPT4_FTM0FLT2_SHIFT                 (2U)                                                /*!< SIM_SOPT4.FTM0FLT2 Position             */
#define SIM_SOPT4_FTM0FLT2(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SIM_SOPT4.FTM0FLT2 Field                */
#define SIM_SOPT4_FTM0FLT3_MASK                  (0x8U)                                              /*!< SIM_SOPT4.FTM0FLT3 Mask                 */
#define SIM_SOPT4_FTM0FLT3_SHIFT                 (3U)                                                /*!< SIM_SOPT4.FTM0FLT3 Position             */
#define SIM_SOPT4_FTM0FLT3(x)                    (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SIM_SOPT4.FTM0FLT3 Field                */
#define SIM_SOPT4_FTM1FLT0_MASK                  (0x10U)                                             /*!< SIM_SOPT4.FTM1FLT0 Mask                 */
#define SIM_SOPT4_FTM1FLT0_SHIFT                 (4U)                                                /*!< SIM_SOPT4.FTM1FLT0 Position             */
#define SIM_SOPT4_FTM1FLT0(x)                    (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SIM_SOPT4.FTM1FLT0 Field                */
#define SIM_SOPT4_FTM3FLT0_MASK                  (0x1000U)                                           /*!< SIM_SOPT4.FTM3FLT0 Mask                 */
#define SIM_SOPT4_FTM3FLT0_SHIFT                 (12U)                                               /*!< SIM_SOPT4.FTM3FLT0 Position             */
#define SIM_SOPT4_FTM3FLT0(x)                    (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SIM_SOPT4.FTM3FLT0 Field                */
#define SIM_SOPT4_FTM0TRG0SRC_MASK               (0x10000U)                                          /*!< SIM_SOPT4.FTM0TRG0SRC Mask              */
#define SIM_SOPT4_FTM0TRG0SRC_SHIFT              (16U)                                               /*!< SIM_SOPT4.FTM0TRG0SRC Position          */
#define SIM_SOPT4_FTM0TRG0SRC(x)                 (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< SIM_SOPT4.FTM0TRG0SRC Field             */
#define SIM_SOPT4_FTM0TRG1SRC_MASK               (0x20000U)                                          /*!< SIM_SOPT4.FTM0TRG1SRC Mask              */
#define SIM_SOPT4_FTM0TRG1SRC_SHIFT              (17U)                                               /*!< SIM_SOPT4.FTM0TRG1SRC Position          */
#define SIM_SOPT4_FTM0TRG1SRC(x)                 (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< SIM_SOPT4.FTM0TRG1SRC Field             */
#define SIM_SOPT4_FTM0TRG2SRC_MASK               (0x40000U)                                          /*!< SIM_SOPT4.FTM0TRG2SRC Mask              */
#define SIM_SOPT4_FTM0TRG2SRC_SHIFT              (18U)                                               /*!< SIM_SOPT4.FTM0TRG2SRC Position          */
#define SIM_SOPT4_FTM0TRG2SRC(x)                 (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< SIM_SOPT4.FTM0TRG2SRC Field             */
#define SIM_SOPT4_FTM1TRG0SRC_MASK               (0x100000U)                                         /*!< SIM_SOPT4.FTM1TRG0SRC Mask              */
#define SIM_SOPT4_FTM1TRG0SRC_SHIFT              (20U)                                               /*!< SIM_SOPT4.FTM1TRG0SRC Position          */
#define SIM_SOPT4_FTM1TRG0SRC(x)                 (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< SIM_SOPT4.FTM1TRG0SRC Field             */
#define SIM_SOPT4_FTM1TRG2SRC_MASK               (0x400000U)                                         /*!< SIM_SOPT4.FTM1TRG2SRC Mask              */
#define SIM_SOPT4_FTM1TRG2SRC_SHIFT              (22U)                                               /*!< SIM_SOPT4.FTM1TRG2SRC Position          */
#define SIM_SOPT4_FTM1TRG2SRC(x)                 (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< SIM_SOPT4.FTM1TRG2SRC Field             */
#define SIM_SOPT4_FTM3TRG0SRC_MASK               (0x10000000U)                                       /*!< SIM_SOPT4.FTM3TRG0SRC Mask              */
#define SIM_SOPT4_FTM3TRG0SRC_SHIFT              (28U)                                               /*!< SIM_SOPT4.FTM3TRG0SRC Position          */
#define SIM_SOPT4_FTM3TRG0SRC(x)                 (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< SIM_SOPT4.FTM3TRG0SRC Field             */
#define SIM_SOPT4_FTM3TRG1SRC_MASK               (0x20000000U)                                       /*!< SIM_SOPT4.FTM3TRG1SRC Mask              */
#define SIM_SOPT4_FTM3TRG1SRC_SHIFT              (29U)                                               /*!< SIM_SOPT4.FTM3TRG1SRC Position          */
#define SIM_SOPT4_FTM3TRG1SRC(x)                 (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< SIM_SOPT4.FTM3TRG1SRC Field             */
#define SIM_SOPT4_FTM3TRG2SRC_MASK               (0x40000000U)                                       /*!< SIM_SOPT4.FTM3TRG2SRC Mask              */
#define SIM_SOPT4_FTM3TRG2SRC_SHIFT              (30U)                                               /*!< SIM_SOPT4.FTM3TRG2SRC Position          */
#define SIM_SOPT4_FTM3TRG2SRC(x)                 (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< SIM_SOPT4.FTM3TRG2SRC Field             */
/* ------- SOPT5 Bit Fields                         ------ */
#define SIM_SOPT5_UART0TXSRC_MASK                (0x1U)                                              /*!< SIM_SOPT5.UART0TXSRC Mask               */
#define SIM_SOPT5_UART0TXSRC_SHIFT               (0U)                                                /*!< SIM_SOPT5.UART0TXSRC Position           */
#define SIM_SOPT5_UART0TXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SIM_SOPT5.UART0TXSRC Field              */
#define SIM_SOPT5_UART0RXSRC_MASK                (0xCU)                                              /*!< SIM_SOPT5.UART0RXSRC Mask               */
#define SIM_SOPT5_UART0RXSRC_SHIFT               (2U)                                                /*!< SIM_SOPT5.UART0RXSRC Position           */
#define SIM_SOPT5_UART0RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< SIM_SOPT5.UART0RXSRC Field              */
#define SIM_SOPT5_UART1TXSRC_MASK                (0x10U)                                             /*!< SIM_SOPT5.UART1TXSRC Mask               */
#define SIM_SOPT5_UART1TXSRC_SHIFT               (4U)                                                /*!< SIM_SOPT5.UART1TXSRC Position           */
#define SIM_SOPT5_UART1TXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SIM_SOPT5.UART1TXSRC Field              */
#define SIM_SOPT5_UART1RXSRC_MASK                (0xC0U)                                             /*!< SIM_SOPT5.UART1RXSRC Mask               */
#define SIM_SOPT5_UART1RXSRC_SHIFT               (6U)                                                /*!< SIM_SOPT5.UART1RXSRC Position           */
#define SIM_SOPT5_UART1RXSRC(x)                  (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< SIM_SOPT5.UART1RXSRC Field              */
/* ------- SOPT7 Bit Fields                         ------ */
#define SIM_SOPT7_ADCATRGSEL_MASK                (0xFU)                                              /*!< SIM_SOPT7.ADCATRGSEL Mask               */
#define SIM_SOPT7_ADCATRGSEL_SHIFT               (0U)                                                /*!< SIM_SOPT7.ADCATRGSEL Position           */
#define SIM_SOPT7_ADCATRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< SIM_SOPT7.ADCATRGSEL Field              */
#define SIM_SOPT7_ADCAALTTRGEN_MASK              (0xC0U)                                             /*!< SIM_SOPT7.ADCAALTTRGEN Mask             */
#define SIM_SOPT7_ADCAALTTRGEN_SHIFT             (6U)                                                /*!< SIM_SOPT7.ADCAALTTRGEN Position         */
#define SIM_SOPT7_ADCAALTTRGEN(x)                (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< SIM_SOPT7.ADCAALTTRGEN Field            */
#define SIM_SOPT7_ADCBTRGSEL_MASK                (0xF00U)                                            /*!< SIM_SOPT7.ADCBTRGSEL Mask               */
#define SIM_SOPT7_ADCBTRGSEL_SHIFT               (8U)                                                /*!< SIM_SOPT7.ADCBTRGSEL Position           */
#define SIM_SOPT7_ADCBTRGSEL(x)                  (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< SIM_SOPT7.ADCBTRGSEL Field              */
#define SIM_SOPT7_ADCBALTTRGEN_MASK              (0xC000U)                                           /*!< SIM_SOPT7.ADCBALTTRGEN Mask             */
#define SIM_SOPT7_ADCBALTTRGEN_SHIFT             (14U)                                               /*!< SIM_SOPT7.ADCBALTTRGEN Position         */
#define SIM_SOPT7_ADCBALTTRGEN(x)                (((uint32_t)(((uint32_t)(x))<<14U))&0xC000UL)       /*!< SIM_SOPT7.ADCBALTTRGEN Field            */
/* ------- SOPT8 Bit Fields                         ------ */
#define SIM_SOPT8_FTM0SYNCBIT_MASK               (0x1U)                                              /*!< SIM_SOPT8.FTM0SYNCBIT Mask              */
#define SIM_SOPT8_FTM0SYNCBIT_SHIFT              (0U)                                                /*!< SIM_SOPT8.FTM0SYNCBIT Position          */
#define SIM_SOPT8_FTM0SYNCBIT(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SIM_SOPT8.FTM0SYNCBIT Field             */
#define SIM_SOPT8_FTM1SYNCBIT_MASK               (0x2U)                                              /*!< SIM_SOPT8.FTM1SYNCBIT Mask              */
#define SIM_SOPT8_FTM1SYNCBIT_SHIFT              (1U)                                                /*!< SIM_SOPT8.FTM1SYNCBIT Position          */
#define SIM_SOPT8_FTM1SYNCBIT(x)                 (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SIM_SOPT8.FTM1SYNCBIT Field             */
#define SIM_SOPT8_FTM3SYNCBIT_MASK               (0x8U)                                              /*!< SIM_SOPT8.FTM3SYNCBIT Mask              */
#define SIM_SOPT8_FTM3SYNCBIT_SHIFT              (3U)                                                /*!< SIM_SOPT8.FTM3SYNCBIT Position          */
#define SIM_SOPT8_FTM3SYNCBIT(x)                 (((uint32_t)(((uint32_t)(x))<<3U))&0x8UL)           /*!< SIM_SOPT8.FTM3SYNCBIT Field             */
#define SIM_SOPT8_FTM0CFSEL_MASK                 (0x100U)                                            /*!< SIM_SOPT8.FTM0CFSEL Mask                */
#define SIM_SOPT8_FTM0CFSEL_SHIFT                (8U)                                                /*!< SIM_SOPT8.FTM0CFSEL Position            */
#define SIM_SOPT8_FTM0CFSEL(x)                   (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< SIM_SOPT8.FTM0CFSEL Field               */
#define SIM_SOPT8_FTM3CFSEL_MASK                 (0x200U)                                            /*!< SIM_SOPT8.FTM3CFSEL Mask                */
#define SIM_SOPT8_FTM3CFSEL_SHIFT                (9U)                                                /*!< SIM_SOPT8.FTM3CFSEL Position            */
#define SIM_SOPT8_FTM3CFSEL(x)                   (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SIM_SOPT8.FTM3CFSEL Field               */
#define SIM_SOPT8_FTM0OCH0SRC_MASK               (0x10000U)                                          /*!< SIM_SOPT8.FTM0OCH0SRC Mask              */
#define SIM_SOPT8_FTM0OCH0SRC_SHIFT              (16U)                                               /*!< SIM_SOPT8.FTM0OCH0SRC Position          */
#define SIM_SOPT8_FTM0OCH0SRC(x)                 (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< SIM_SOPT8.FTM0OCH0SRC Field             */
#define SIM_SOPT8_FTM0OCH1SRC_MASK               (0x20000U)                                          /*!< SIM_SOPT8.FTM0OCH1SRC Mask              */
#define SIM_SOPT8_FTM0OCH1SRC_SHIFT              (17U)                                               /*!< SIM_SOPT8.FTM0OCH1SRC Position          */
#define SIM_SOPT8_FTM0OCH1SRC(x)                 (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< SIM_SOPT8.FTM0OCH1SRC Field             */
#define SIM_SOPT8_FTM0OCH2SRC_MASK               (0x40000U)                                          /*!< SIM_SOPT8.FTM0OCH2SRC Mask              */
#define SIM_SOPT8_FTM0OCH2SRC_SHIFT              (18U)                                               /*!< SIM_SOPT8.FTM0OCH2SRC Position          */
#define SIM_SOPT8_FTM0OCH2SRC(x)                 (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< SIM_SOPT8.FTM0OCH2SRC Field             */
#define SIM_SOPT8_FTM0OCH3SRC_MASK               (0x80000U)                                          /*!< SIM_SOPT8.FTM0OCH3SRC Mask              */
#define SIM_SOPT8_FTM0OCH3SRC_SHIFT              (19U)                                               /*!< SIM_SOPT8.FTM0OCH3SRC Position          */
#define SIM_SOPT8_FTM0OCH3SRC(x)                 (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< SIM_SOPT8.FTM0OCH3SRC Field             */
#define SIM_SOPT8_FTM0OCH4SRC_MASK               (0x100000U)                                         /*!< SIM_SOPT8.FTM0OCH4SRC Mask              */
#define SIM_SOPT8_FTM0OCH4SRC_SHIFT              (20U)                                               /*!< SIM_SOPT8.FTM0OCH4SRC Position          */
#define SIM_SOPT8_FTM0OCH4SRC(x)                 (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< SIM_SOPT8.FTM0OCH4SRC Field             */
#define SIM_SOPT8_FTM0OCH5SRC_MASK               (0x200000U)                                         /*!< SIM_SOPT8.FTM0OCH5SRC Mask              */
#define SIM_SOPT8_FTM0OCH5SRC_SHIFT              (21U)                                               /*!< SIM_SOPT8.FTM0OCH5SRC Position          */
#define SIM_SOPT8_FTM0OCH5SRC(x)                 (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< SIM_SOPT8.FTM0OCH5SRC Field             */
#define SIM_SOPT8_FTM0OCH6SRC_MASK               (0x400000U)                                         /*!< SIM_SOPT8.FTM0OCH6SRC Mask              */
#define SIM_SOPT8_FTM0OCH6SRC_SHIFT              (22U)                                               /*!< SIM_SOPT8.FTM0OCH6SRC Position          */
#define SIM_SOPT8_FTM0OCH6SRC(x)                 (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< SIM_SOPT8.FTM0OCH6SRC Field             */
#define SIM_SOPT8_FTM0OCH7SRC_MASK               (0x800000U)                                         /*!< SIM_SOPT8.FTM0OCH7SRC Mask              */
#define SIM_SOPT8_FTM0OCH7SRC_SHIFT              (23U)                                               /*!< SIM_SOPT8.FTM0OCH7SRC Position          */
#define SIM_SOPT8_FTM0OCH7SRC(x)                 (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< SIM_SOPT8.FTM0OCH7SRC Field             */
#define SIM_SOPT8_FTM3OCH0SRC_MASK               (0x1000000U)                                        /*!< SIM_SOPT8.FTM3OCH0SRC Mask              */
#define SIM_SOPT8_FTM3OCH0SRC_SHIFT              (24U)                                               /*!< SIM_SOPT8.FTM3OCH0SRC Position          */
#define SIM_SOPT8_FTM3OCH0SRC(x)                 (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< SIM_SOPT8.FTM3OCH0SRC Field             */
#define SIM_SOPT8_FTM3OCH1SRC_MASK               (0x2000000U)                                        /*!< SIM_SOPT8.FTM3OCH1SRC Mask              */
#define SIM_SOPT8_FTM3OCH1SRC_SHIFT              (25U)                                               /*!< SIM_SOPT8.FTM3OCH1SRC Position          */
#define SIM_SOPT8_FTM3OCH1SRC(x)                 (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SIM_SOPT8.FTM3OCH1SRC Field             */
#define SIM_SOPT8_FTM3OCH2SRC_MASK               (0x4000000U)                                        /*!< SIM_SOPT8.FTM3OCH2SRC Mask              */
#define SIM_SOPT8_FTM3OCH2SRC_SHIFT              (26U)                                               /*!< SIM_SOPT8.FTM3OCH2SRC Position          */
#define SIM_SOPT8_FTM3OCH2SRC(x)                 (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< SIM_SOPT8.FTM3OCH2SRC Field             */
#define SIM_SOPT8_FTM3OCH3SRC_MASK               (0x8000000U)                                        /*!< SIM_SOPT8.FTM3OCH3SRC Mask              */
#define SIM_SOPT8_FTM3OCH3SRC_SHIFT              (27U)                                               /*!< SIM_SOPT8.FTM3OCH3SRC Position          */
#define SIM_SOPT8_FTM3OCH3SRC(x)                 (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< SIM_SOPT8.FTM3OCH3SRC Field             */
#define SIM_SOPT8_FTM3OCH4SRC_MASK               (0x10000000U)                                       /*!< SIM_SOPT8.FTM3OCH4SRC Mask              */
#define SIM_SOPT8_FTM3OCH4SRC_SHIFT              (28U)                                               /*!< SIM_SOPT8.FTM3OCH4SRC Position          */
#define SIM_SOPT8_FTM3OCH4SRC(x)                 (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< SIM_SOPT8.FTM3OCH4SRC Field             */
#define SIM_SOPT8_FTM3OCH5SRC_MASK               (0x20000000U)                                       /*!< SIM_SOPT8.FTM3OCH5SRC Mask              */
#define SIM_SOPT8_FTM3OCH5SRC_SHIFT              (29U)                                               /*!< SIM_SOPT8.FTM3OCH5SRC Position          */
#define SIM_SOPT8_FTM3OCH5SRC(x)                 (((uint32_t)(((uint32_t)(x))<<29U))&0x20000000UL)   /*!< SIM_SOPT8.FTM3OCH5SRC Field             */
#define SIM_SOPT8_FTM3OCH6SRC_MASK               (0x40000000U)                                       /*!< SIM_SOPT8.FTM3OCH6SRC Mask              */
#define SIM_SOPT8_FTM3OCH6SRC_SHIFT              (30U)                                               /*!< SIM_SOPT8.FTM3OCH6SRC Position          */
#define SIM_SOPT8_FTM3OCH6SRC(x)                 (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< SIM_SOPT8.FTM3OCH6SRC Field             */
#define SIM_SOPT8_FTM3OCH7SRC_MASK               (0x80000000U)                                       /*!< SIM_SOPT8.FTM3OCH7SRC Mask              */
#define SIM_SOPT8_FTM3OCH7SRC_SHIFT              (31U)                                               /*!< SIM_SOPT8.FTM3OCH7SRC Position          */
#define SIM_SOPT8_FTM3OCH7SRC(x)                 (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SIM_SOPT8.FTM3OCH7SRC Field             */
/* ------- SOPT9 Bit Fields                         ------ */
#define SIM_SOPT9_FTM1ICH0SRC_MASK               (0x30U)                                             /*!< SIM_SOPT9.FTM1ICH0SRC Mask              */
#define SIM_SOPT9_FTM1ICH0SRC_SHIFT              (4U)                                                /*!< SIM_SOPT9.FTM1ICH0SRC Position          */
#define SIM_SOPT9_FTM1ICH0SRC(x)                 (((uint32_t)(((uint32_t)(x))<<4U))&0x30UL)          /*!< SIM_SOPT9.FTM1ICH0SRC Field             */
#define SIM_SOPT9_FTM1ICH1SRC_MASK               (0x40U)                                             /*!< SIM_SOPT9.FTM1ICH1SRC Mask              */
#define SIM_SOPT9_FTM1ICH1SRC_SHIFT              (6U)                                                /*!< SIM_SOPT9.FTM1ICH1SRC Position          */
#define SIM_SOPT9_FTM1ICH1SRC(x)                 (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SIM_SOPT9.FTM1ICH1SRC Field             */
#define SIM_SOPT9_FTM0CLKSEL_MASK                (0x3000000U)                                        /*!< SIM_SOPT9.FTM0CLKSEL Mask               */
#define SIM_SOPT9_FTM0CLKSEL_SHIFT               (24U)                                               /*!< SIM_SOPT9.FTM0CLKSEL Position           */
#define SIM_SOPT9_FTM0CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<24U))&0x3000000UL)    /*!< SIM_SOPT9.FTM0CLKSEL Field              */
#define SIM_SOPT9_FTM1CLKSEL_MASK                (0xC000000U)                                        /*!< SIM_SOPT9.FTM1CLKSEL Mask               */
#define SIM_SOPT9_FTM1CLKSEL_SHIFT               (26U)                                               /*!< SIM_SOPT9.FTM1CLKSEL Position           */
#define SIM_SOPT9_FTM1CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<26U))&0xC000000UL)    /*!< SIM_SOPT9.FTM1CLKSEL Field              */
#define SIM_SOPT9_FTM3CLKSEL_MASK                (0xC0000000U)                                       /*!< SIM_SOPT9.FTM3CLKSEL Mask               */
#define SIM_SOPT9_FTM3CLKSEL_SHIFT               (30U)                                               /*!< SIM_SOPT9.FTM3CLKSEL Position           */
#define SIM_SOPT9_FTM3CLKSEL(x)                  (((uint32_t)(((uint32_t)(x))<<30U))&0xC0000000UL)   /*!< SIM_SOPT9.FTM3CLKSEL Field              */
/* ------- SDID Bit Fields                          ------ */
#define SIM_SDID_PINID_MASK                      (0xFU)                                              /*!< SIM_SDID.PINID Mask                     */
#define SIM_SDID_PINID_SHIFT                     (0U)                                                /*!< SIM_SDID.PINID Position                 */
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< SIM_SDID.PINID Field                    */
#define SIM_SDID_DIEID_MASK                      (0xF80U)                                            /*!< SIM_SDID.DIEID Mask                     */
#define SIM_SDID_DIEID_SHIFT                     (7U)                                                /*!< SIM_SDID.DIEID Position                 */
#define SIM_SDID_DIEID(x)                        (((uint32_t)(((uint32_t)(x))<<7U))&0xF80UL)         /*!< SIM_SDID.DIEID Field                    */
#define SIM_SDID_REVID_MASK                      (0xF000U)                                           /*!< SIM_SDID.REVID Mask                     */
#define SIM_SDID_REVID_SHIFT                     (12U)                                               /*!< SIM_SDID.REVID Position                 */
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< SIM_SDID.REVID Field                    */
#define SIM_SDID_SERIESID_MASK                   (0xF00000U)                                         /*!< SIM_SDID.SERIESID Mask                  */
#define SIM_SDID_SERIESID_SHIFT                  (20U)                                               /*!< SIM_SDID.SERIESID Position              */
#define SIM_SDID_SERIESID(x)                     (((uint32_t)(((uint32_t)(x))<<20U))&0xF00000UL)     /*!< SIM_SDID.SERIESID Field                 */
#define SIM_SDID_SUBFAMID_MASK                   (0xF000000U)                                        /*!< SIM_SDID.SUBFAMID Mask                  */
#define SIM_SDID_SUBFAMID_SHIFT                  (24U)                                               /*!< SIM_SDID.SUBFAMID Position              */
#define SIM_SDID_SUBFAMID(x)                     (((uint32_t)(((uint32_t)(x))<<24U))&0xF000000UL)    /*!< SIM_SDID.SUBFAMID Field                 */
#define SIM_SDID_FAMILYID_MASK                   (0xF0000000U)                                       /*!< SIM_SDID.FAMILYID Mask                  */
#define SIM_SDID_FAMILYID_SHIFT                  (28U)                                               /*!< SIM_SDID.FAMILYID Position              */
#define SIM_SDID_FAMILYID(x)                     (((uint32_t)(((uint32_t)(x))<<28U))&0xF0000000UL)   /*!< SIM_SDID.FAMILYID Field                 */
/* ------- SCGC4 Bit Fields                         ------ */
#define SIM_SCGC4_EWM_MASK                       (0x2U)                                              /*!< SIM_SCGC4.EWM Mask                      */
#define SIM_SCGC4_EWM_SHIFT                      (1U)                                                /*!< SIM_SCGC4.EWM Position                  */
#define SIM_SCGC4_EWM(x)                         (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SIM_SCGC4.EWM Field                     */
#define SIM_SCGC4_I2C0_MASK                      (0x40U)                                             /*!< SIM_SCGC4.I2C0 Mask                     */
#define SIM_SCGC4_I2C0_SHIFT                     (6U)                                                /*!< SIM_SCGC4.I2C0 Position                 */
#define SIM_SCGC4_I2C0(x)                        (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SIM_SCGC4.I2C0 Field                    */
#define SIM_SCGC4_UART0_MASK                     (0x400U)                                            /*!< SIM_SCGC4.UART0 Mask                    */
#define SIM_SCGC4_UART0_SHIFT                    (10U)                                               /*!< SIM_SCGC4.UART0 Position                */
#define SIM_SCGC4_UART0(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SIM_SCGC4.UART0 Field                   */
#define SIM_SCGC4_UART1_MASK                     (0x800U)                                            /*!< SIM_SCGC4.UART1 Mask                    */
#define SIM_SCGC4_UART1_SHIFT                    (11U)                                               /*!< SIM_SCGC4.UART1 Position                */
#define SIM_SCGC4_UART1(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SIM_SCGC4.UART1 Field                   */
#define SIM_SCGC4_CMP_MASK                       (0x80000U)                                          /*!< SIM_SCGC4.CMP Mask                      */
#define SIM_SCGC4_CMP_SHIFT                      (19U)                                               /*!< SIM_SCGC4.CMP Position                  */
#define SIM_SCGC4_CMP(x)                         (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< SIM_SCGC4.CMP Field                     */
#define SIM_SCGC4_eFlexPWM0_MASK                 (0x1000000U)                                        /*!< SIM_SCGC4.eFlexPWM0 Mask                */
#define SIM_SCGC4_eFlexPWM0_SHIFT                (24U)                                               /*!< SIM_SCGC4.eFlexPWM0 Position            */
#define SIM_SCGC4_eFlexPWM0(x)                   (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< SIM_SCGC4.eFlexPWM0 Field               */
#define SIM_SCGC4_eFlexPWM1_MASK                 (0x2000000U)                                        /*!< SIM_SCGC4.eFlexPWM1 Mask                */
#define SIM_SCGC4_eFlexPWM1_SHIFT                (25U)                                               /*!< SIM_SCGC4.eFlexPWM1 Position            */
#define SIM_SCGC4_eFlexPWM1(x)                   (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SIM_SCGC4.eFlexPWM1 Field               */
#define SIM_SCGC4_eFlexPWM2_MASK                 (0x4000000U)                                        /*!< SIM_SCGC4.eFlexPWM2 Mask                */
#define SIM_SCGC4_eFlexPWM2_SHIFT                (26U)                                               /*!< SIM_SCGC4.eFlexPWM2 Position            */
#define SIM_SCGC4_eFlexPWM2(x)                   (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< SIM_SCGC4.eFlexPWM2 Field               */
#define SIM_SCGC4_eFlexPWM3_MASK                 (0x8000000U)                                        /*!< SIM_SCGC4.eFlexPWM3 Mask                */
#define SIM_SCGC4_eFlexPWM3_SHIFT                (27U)                                               /*!< SIM_SCGC4.eFlexPWM3 Position            */
#define SIM_SCGC4_eFlexPWM3(x)                   (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< SIM_SCGC4.eFlexPWM3 Field               */
/* ------- SCGC5 Bit Fields                         ------ */
#define SIM_SCGC5_LPTMR_MASK                     (0x1U)                                              /*!< SIM_SCGC5.LPTMR Mask                    */
#define SIM_SCGC5_LPTMR_SHIFT                    (0U)                                                /*!< SIM_SCGC5.LPTMR Position                */
#define SIM_SCGC5_LPTMR(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SIM_SCGC5.LPTMR Field                   */
#define SIM_SCGC5_PORTA_MASK                     (0x200U)                                            /*!< SIM_SCGC5.PORTA Mask                    */
#define SIM_SCGC5_PORTA_SHIFT                    (9U)                                                /*!< SIM_SCGC5.PORTA Position                */
#define SIM_SCGC5_PORTA(x)                       (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SIM_SCGC5.PORTA Field                   */
#define SIM_SCGC5_PORTB_MASK                     (0x400U)                                            /*!< SIM_SCGC5.PORTB Mask                    */
#define SIM_SCGC5_PORTB_SHIFT                    (10U)                                               /*!< SIM_SCGC5.PORTB Position                */
#define SIM_SCGC5_PORTB(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SIM_SCGC5.PORTB Field                   */
#define SIM_SCGC5_PORTC_MASK                     (0x800U)                                            /*!< SIM_SCGC5.PORTC Mask                    */
#define SIM_SCGC5_PORTC_SHIFT                    (11U)                                               /*!< SIM_SCGC5.PORTC Position                */
#define SIM_SCGC5_PORTC(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SIM_SCGC5.PORTC Field                   */
#define SIM_SCGC5_PORTD_MASK                     (0x1000U)                                           /*!< SIM_SCGC5.PORTD Mask                    */
#define SIM_SCGC5_PORTD_SHIFT                    (12U)                                               /*!< SIM_SCGC5.PORTD Position                */
#define SIM_SCGC5_PORTD(x)                       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SIM_SCGC5.PORTD Field                   */
#define SIM_SCGC5_PORTE_MASK                     (0x2000U)                                           /*!< SIM_SCGC5.PORTE Mask                    */
#define SIM_SCGC5_PORTE_SHIFT                    (13U)                                               /*!< SIM_SCGC5.PORTE Position                */
#define SIM_SCGC5_PORTE(x)                       (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< SIM_SCGC5.PORTE Field                   */
#define SIM_SCGC5_ENC_MASK                       (0x200000U)                                         /*!< SIM_SCGC5.ENC Mask                      */
#define SIM_SCGC5_ENC_SHIFT                      (21U)                                               /*!< SIM_SCGC5.ENC Position                  */
#define SIM_SCGC5_ENC(x)                         (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< SIM_SCGC5.ENC Field                     */
#define SIM_SCGC5_XBARA_MASK                     (0x2000000U)                                        /*!< SIM_SCGC5.XBARA Mask                    */
#define SIM_SCGC5_XBARA_SHIFT                    (25U)                                               /*!< SIM_SCGC5.XBARA Position                */
#define SIM_SCGC5_XBARA(x)                       (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SIM_SCGC5.XBARA Field                   */
#define SIM_SCGC5_XBARB_MASK                     (0x4000000U)                                        /*!< SIM_SCGC5.XBARB Mask                    */
#define SIM_SCGC5_XBARB_SHIFT                    (26U)                                               /*!< SIM_SCGC5.XBARB Position                */
#define SIM_SCGC5_XBARB(x)                       (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< SIM_SCGC5.XBARB Field                   */
#define SIM_SCGC5_AOI_MASK                       (0x8000000U)                                        /*!< SIM_SCGC5.AOI Mask                      */
#define SIM_SCGC5_AOI_SHIFT                      (27U)                                               /*!< SIM_SCGC5.AOI Position                  */
#define SIM_SCGC5_AOI(x)                         (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< SIM_SCGC5.AOI Field                     */
#define SIM_SCGC5_ADC_MASK                       (0x10000000U)                                       /*!< SIM_SCGC5.ADC Mask                      */
#define SIM_SCGC5_ADC_SHIFT                      (28U)                                               /*!< SIM_SCGC5.ADC Position                  */
#define SIM_SCGC5_ADC(x)                         (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< SIM_SCGC5.ADC Field                     */
/* ------- SCGC6 Bit Fields                         ------ */
#define SIM_SCGC6_FTF_MASK                       (0x1U)                                              /*!< SIM_SCGC6.FTF Mask                      */
#define SIM_SCGC6_FTF_SHIFT                      (0U)                                                /*!< SIM_SCGC6.FTF Position                  */
#define SIM_SCGC6_FTF(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SIM_SCGC6.FTF Field                     */
#define SIM_SCGC6_DMAMUX0_MASK                   (0x2U)                                              /*!< SIM_SCGC6.DMAMUX0 Mask                  */
#define SIM_SCGC6_DMAMUX0_SHIFT                  (1U)                                                /*!< SIM_SCGC6.DMAMUX0 Position              */
#define SIM_SCGC6_DMAMUX0(x)                     (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SIM_SCGC6.DMAMUX0 Field                 */
#define SIM_SCGC6_FLEXCAN0_MASK                  (0x10U)                                             /*!< SIM_SCGC6.FLEXCAN0 Mask                 */
#define SIM_SCGC6_FLEXCAN0_SHIFT                 (4U)                                                /*!< SIM_SCGC6.FLEXCAN0 Position             */
#define SIM_SCGC6_FLEXCAN0(x)                    (((uint32_t)(((uint32_t)(x))<<4U))&0x10UL)          /*!< SIM_SCGC6.FLEXCAN0 Field                */
#define SIM_SCGC6_FLEXCAN1_MASK                  (0x20U)                                             /*!< SIM_SCGC6.FLEXCAN1 Mask                 */
#define SIM_SCGC6_FLEXCAN1_SHIFT                 (5U)                                                /*!< SIM_SCGC6.FLEXCAN1 Position             */
#define SIM_SCGC6_FLEXCAN1(x)                    (((uint32_t)(((uint32_t)(x))<<5U))&0x20UL)          /*!< SIM_SCGC6.FLEXCAN1 Field                */
#define SIM_SCGC6_FTM3_MASK                      (0x40U)                                             /*!< SIM_SCGC6.FTM3 Mask                     */
#define SIM_SCGC6_FTM3_SHIFT                     (6U)                                                /*!< SIM_SCGC6.FTM3 Position                 */
#define SIM_SCGC6_FTM3(x)                        (((uint32_t)(((uint32_t)(x))<<6U))&0x40UL)          /*!< SIM_SCGC6.FTM3 Field                    */
#define SIM_SCGC6_SPI0_MASK                      (0x1000U)                                           /*!< SIM_SCGC6.SPI0 Mask                     */
#define SIM_SCGC6_SPI0_SHIFT                     (12U)                                               /*!< SIM_SCGC6.SPI0 Position                 */
#define SIM_SCGC6_SPI0(x)                        (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SIM_SCGC6.SPI0 Field                    */
#define SIM_SCGC6_PDB1_MASK                      (0x20000U)                                          /*!< SIM_SCGC6.PDB1 Mask                     */
#define SIM_SCGC6_PDB1_SHIFT                     (17U)                                               /*!< SIM_SCGC6.PDB1 Position                 */
#define SIM_SCGC6_PDB1(x)                        (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< SIM_SCGC6.PDB1 Field                    */
#define SIM_SCGC6_CRC_MASK                       (0x40000U)                                          /*!< SIM_SCGC6.CRC Mask                      */
#define SIM_SCGC6_CRC_SHIFT                      (18U)                                               /*!< SIM_SCGC6.CRC Position                  */
#define SIM_SCGC6_CRC(x)                         (((uint32_t)(((uint32_t)(x))<<18U))&0x40000UL)      /*!< SIM_SCGC6.CRC Field                     */
#define SIM_SCGC6_PDB0_MASK                      (0x400000U)                                         /*!< SIM_SCGC6.PDB0 Mask                     */
#define SIM_SCGC6_PDB0_SHIFT                     (22U)                                               /*!< SIM_SCGC6.PDB0 Position                 */
#define SIM_SCGC6_PDB0(x)                        (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< SIM_SCGC6.PDB0 Field                    */
#define SIM_SCGC6_PIT_MASK                       (0x800000U)                                         /*!< SIM_SCGC6.PIT Mask                      */
#define SIM_SCGC6_PIT_SHIFT                      (23U)                                               /*!< SIM_SCGC6.PIT Position                  */
#define SIM_SCGC6_PIT(x)                         (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< SIM_SCGC6.PIT Field                     */
#define SIM_SCGC6_FTM0_MASK                      (0x1000000U)                                        /*!< SIM_SCGC6.FTM0 Mask                     */
#define SIM_SCGC6_FTM0_SHIFT                     (24U)                                               /*!< SIM_SCGC6.FTM0 Position                 */
#define SIM_SCGC6_FTM0(x)                        (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< SIM_SCGC6.FTM0 Field                    */
#define SIM_SCGC6_FTM1_MASK                      (0x2000000U)                                        /*!< SIM_SCGC6.FTM1 Mask                     */
#define SIM_SCGC6_FTM1_SHIFT                     (25U)                                               /*!< SIM_SCGC6.FTM1 Position                 */
#define SIM_SCGC6_FTM1(x)                        (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SIM_SCGC6.FTM1 Field                    */
#define SIM_SCGC6_DAC0_MASK                      (0x80000000U)                                       /*!< SIM_SCGC6.DAC0 Mask                     */
#define SIM_SCGC6_DAC0_SHIFT                     (31U)                                               /*!< SIM_SCGC6.DAC0 Position                 */
#define SIM_SCGC6_DAC0(x)                        (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SIM_SCGC6.DAC0 Field                    */
/* ------- SCGC7 Bit Fields                         ------ */
#define SIM_SCGC7_DMA_MASK                       (0x100U)                                            /*!< SIM_SCGC7.DMA Mask                      */
#define SIM_SCGC7_DMA_SHIFT                      (8U)                                                /*!< SIM_SCGC7.DMA Position                  */
#define SIM_SCGC7_DMA(x)                         (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< SIM_SCGC7.DMA Field                     */
/* ------- CLKDIV1 Bit Fields                       ------ */
#define SIM_CLKDIV1_OUTDIV4_MASK                 (0xF0000U)                                          /*!< SIM_CLKDIV1.OUTDIV4 Mask                */
#define SIM_CLKDIV1_OUTDIV4_SHIFT                (16U)                                               /*!< SIM_CLKDIV1.OUTDIV4 Position            */
#define SIM_CLKDIV1_OUTDIV4(x)                   (((uint32_t)(((uint32_t)(x))<<16U))&0xF0000UL)      /*!< SIM_CLKDIV1.OUTDIV4 Field               */
#define SIM_CLKDIV1_OUTDIV2_MASK                 (0xF000000U)                                        /*!< SIM_CLKDIV1.OUTDIV2 Mask                */
#define SIM_CLKDIV1_OUTDIV2_SHIFT                (24U)                                               /*!< SIM_CLKDIV1.OUTDIV2 Position            */
#define SIM_CLKDIV1_OUTDIV2(x)                   (((uint32_t)(((uint32_t)(x))<<24U))&0xF000000UL)    /*!< SIM_CLKDIV1.OUTDIV2 Field               */
#define SIM_CLKDIV1_OUTDIV1_MASK                 (0xF0000000U)                                       /*!< SIM_CLKDIV1.OUTDIV1 Mask                */
#define SIM_CLKDIV1_OUTDIV1_SHIFT                (28U)                                               /*!< SIM_CLKDIV1.OUTDIV1 Position            */
#define SIM_CLKDIV1_OUTDIV1(x)                   (((uint32_t)(((uint32_t)(x))<<28U))&0xF0000000UL)   /*!< SIM_CLKDIV1.OUTDIV1 Field               */
/* ------- FCFG1 Bit Fields                         ------ */
#define SIM_FCFG1_FLASHDIS_MASK                  (0x1U)                                              /*!< SIM_FCFG1.FLASHDIS Mask                 */
#define SIM_FCFG1_FLASHDIS_SHIFT                 (0U)                                                /*!< SIM_FCFG1.FLASHDIS Position             */
#define SIM_FCFG1_FLASHDIS(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SIM_FCFG1.FLASHDIS Field                */
#define SIM_FCFG1_FLASHDOZE_MASK                 (0x2U)                                              /*!< SIM_FCFG1.FLASHDOZE Mask                */
#define SIM_FCFG1_FLASHDOZE_SHIFT                (1U)                                                /*!< SIM_FCFG1.FLASHDOZE Position            */
#define SIM_FCFG1_FLASHDOZE(x)                   (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SIM_FCFG1.FLASHDOZE Field               */
#define SIM_FCFG1_PFSIZE_MASK                    (0xF000000U)                                        /*!< SIM_FCFG1.PFSIZE Mask                   */
#define SIM_FCFG1_PFSIZE_SHIFT                   (24U)                                               /*!< SIM_FCFG1.PFSIZE Position               */
#define SIM_FCFG1_PFSIZE(x)                      (((uint32_t)(((uint32_t)(x))<<24U))&0xF000000UL)    /*!< SIM_FCFG1.PFSIZE Field                  */
/* ------- FCFG2 Bit Fields                         ------ */
#define SIM_FCFG2_MAXADDR0_MASK                  (0x7F000000U)                                       /*!< SIM_FCFG2.MAXADDR0 Mask                 */
#define SIM_FCFG2_MAXADDR0_SHIFT                 (24U)                                               /*!< SIM_FCFG2.MAXADDR0 Position             */
#define SIM_FCFG2_MAXADDR0(x)                    (((uint32_t)(((uint32_t)(x))<<24U))&0x7F000000UL)   /*!< SIM_FCFG2.MAXADDR0 Field                */
/* ------- UIDH Bit Fields                          ------ */
#define SIM_UIDH_UID_MASK                        (0xFFFFFFFFU)                                       /*!< SIM_UIDH.UID Mask                       */
#define SIM_UIDH_UID_SHIFT                       (0U)                                                /*!< SIM_UIDH.UID Position                   */
#define SIM_UIDH_UID(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< SIM_UIDH.UID Field                      */
/* ------- UIDMH Bit Fields                         ------ */
#define SIM_UIDMH_UID_MASK                       (0xFFFFFFFFU)                                       /*!< SIM_UIDMH.UID Mask                      */
#define SIM_UIDMH_UID_SHIFT                      (0U)                                                /*!< SIM_UIDMH.UID Position                  */
#define SIM_UIDMH_UID(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< SIM_UIDMH.UID Field                     */
/* ------- UIDML Bit Fields                         ------ */
#define SIM_UIDML_UID_MASK                       (0xFFFFFFFFU)                                       /*!< SIM_UIDML.UID Mask                      */
#define SIM_UIDML_UID_SHIFT                      (0U)                                                /*!< SIM_UIDML.UID Position                  */
#define SIM_UIDML_UID(x)                         (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< SIM_UIDML.UID Field                     */
/* ------- UIDL Bit Fields                          ------ */
#define SIM_UIDL_UID_MASK                        (0xFFFFFFFFU)                                       /*!< SIM_UIDL.UID Mask                       */
#define SIM_UIDL_UID_SHIFT                       (0U)                                                /*!< SIM_UIDL.UID Position                   */
#define SIM_UIDL_UID(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< SIM_UIDL.UID Field                      */
/* ------- CLKDIV4 Bit Fields                       ------ */
#define SIM_CLKDIV4_TRACEFRAC_MASK               (0x1U)                                              /*!< SIM_CLKDIV4.TRACEFRAC Mask              */
#define SIM_CLKDIV4_TRACEFRAC_SHIFT              (0U)                                                /*!< SIM_CLKDIV4.TRACEFRAC Position          */
#define SIM_CLKDIV4_TRACEFRAC(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SIM_CLKDIV4.TRACEFRAC Field             */
#define SIM_CLKDIV4_TRACEDIV_MASK                (0xEU)                                              /*!< SIM_CLKDIV4.TRACEDIV Mask               */
#define SIM_CLKDIV4_TRACEDIV_SHIFT               (1U)                                                /*!< SIM_CLKDIV4.TRACEDIV Position           */
#define SIM_CLKDIV4_TRACEDIV(x)                  (((uint32_t)(((uint32_t)(x))<<1U))&0xEUL)           /*!< SIM_CLKDIV4.TRACEDIV Field              */
#define SIM_CLKDIV4_TRACEDIVEN_MASK              (0x10000000U)                                       /*!< SIM_CLKDIV4.TRACEDIVEN Mask             */
#define SIM_CLKDIV4_TRACEDIVEN_SHIFT             (28U)                                               /*!< SIM_CLKDIV4.TRACEDIVEN Position         */
#define SIM_CLKDIV4_TRACEDIVEN(x)                (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< SIM_CLKDIV4.TRACEDIVEN Field            */
/* ------- MISCTRL Bit Fields                       ------ */
#define SIM_MISCTRL_CMPWIN0SRC_MASK              (0x300U)                                            /*!< SIM_MISCTRL.CMPWIN0SRC Mask             */
#define SIM_MISCTRL_CMPWIN0SRC_SHIFT             (8U)                                                /*!< SIM_MISCTRL.CMPWIN0SRC Position         */
#define SIM_MISCTRL_CMPWIN0SRC(x)                (((uint32_t)(((uint32_t)(x))<<8U))&0x300UL)         /*!< SIM_MISCTRL.CMPWIN0SRC Field            */
#define SIM_MISCTRL_CMPWIN1SRC_MASK              (0xC00U)                                            /*!< SIM_MISCTRL.CMPWIN1SRC Mask             */
#define SIM_MISCTRL_CMPWIN1SRC_SHIFT             (10U)                                               /*!< SIM_MISCTRL.CMPWIN1SRC Position         */
#define SIM_MISCTRL_CMPWIN1SRC(x)                (((uint32_t)(((uint32_t)(x))<<10U))&0xC00UL)        /*!< SIM_MISCTRL.CMPWIN1SRC Field            */
#define SIM_MISCTRL_CMPWIN2SRC_MASK              (0x3000U)                                           /*!< SIM_MISCTRL.CMPWIN2SRC Mask             */
#define SIM_MISCTRL_CMPWIN2SRC_SHIFT             (12U)                                               /*!< SIM_MISCTRL.CMPWIN2SRC Position         */
#define SIM_MISCTRL_CMPWIN2SRC(x)                (((uint32_t)(((uint32_t)(x))<<12U))&0x3000UL)       /*!< SIM_MISCTRL.CMPWIN2SRC Field            */
#define SIM_MISCTRL_CMPWIN3SRC_MASK              (0xC000U)                                           /*!< SIM_MISCTRL.CMPWIN3SRC Mask             */
#define SIM_MISCTRL_CMPWIN3SRC_SHIFT             (14U)                                               /*!< SIM_MISCTRL.CMPWIN3SRC Position         */
#define SIM_MISCTRL_CMPWIN3SRC(x)                (((uint32_t)(((uint32_t)(x))<<14U))&0xC000UL)       /*!< SIM_MISCTRL.CMPWIN3SRC Field            */
#define SIM_MISCTRL_EWMINSRC_MASK                (0x10000U)                                          /*!< SIM_MISCTRL.EWMINSRC Mask               */
#define SIM_MISCTRL_EWMINSRC_SHIFT               (16U)                                               /*!< SIM_MISCTRL.EWMINSRC Position           */
#define SIM_MISCTRL_EWMINSRC(x)                  (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< SIM_MISCTRL.EWMINSRC Field              */
#define SIM_MISCTRL_DACTRIGSRC_MASK              (0xC0000U)                                          /*!< SIM_MISCTRL.DACTRIGSRC Mask             */
#define SIM_MISCTRL_DACTRIGSRC_SHIFT             (18U)                                               /*!< SIM_MISCTRL.DACTRIGSRC Position         */
#define SIM_MISCTRL_DACTRIGSRC(x)                (((uint32_t)(((uint32_t)(x))<<18U))&0xC0000UL)      /*!< SIM_MISCTRL.DACTRIGSRC Field            */
/* ------- MISCTRL2 Bit Fields                      ------ */
#define SIM_MISCTRL2_SYNCXBARAPITTRIG0_MASK      (0x100U)                                            /*!< SIM_MISCTRL2.SYNCXBARAPITTRIG0 Mask     */
#define SIM_MISCTRL2_SYNCXBARAPITTRIG0_SHIFT     (8U)                                                /*!< SIM_MISCTRL2.SYNCXBARAPITTRIG0 Position */
#define SIM_MISCTRL2_SYNCXBARAPITTRIG0(x)        (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< SIM_MISCTRL2.SYNCXBARAPITTRIG0 Field    */
#define SIM_MISCTRL2_SYNCXBARAPITTRIG1_MASK      (0x200U)                                            /*!< SIM_MISCTRL2.SYNCXBARAPITTRIG1 Mask     */
#define SIM_MISCTRL2_SYNCXBARAPITTRIG1_SHIFT     (9U)                                                /*!< SIM_MISCTRL2.SYNCXBARAPITTRIG1 Position */
#define SIM_MISCTRL2_SYNCXBARAPITTRIG1(x)        (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SIM_MISCTRL2.SYNCXBARAPITTRIG1 Field    */
#define SIM_MISCTRL2_SYNCXBARAPITTRIG2_MASK      (0x400U)                                            /*!< SIM_MISCTRL2.SYNCXBARAPITTRIG2 Mask     */
#define SIM_MISCTRL2_SYNCXBARAPITTRIG2_SHIFT     (10U)                                               /*!< SIM_MISCTRL2.SYNCXBARAPITTRIG2 Position */
#define SIM_MISCTRL2_SYNCXBARAPITTRIG2(x)        (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SIM_MISCTRL2.SYNCXBARAPITTRIG2 Field    */
#define SIM_MISCTRL2_SYNCXBARAPITTRIG3_MASK      (0x800U)                                            /*!< SIM_MISCTRL2.SYNCXBARAPITTRIG3 Mask     */
#define SIM_MISCTRL2_SYNCXBARAPITTRIG3_SHIFT     (11U)                                               /*!< SIM_MISCTRL2.SYNCXBARAPITTRIG3 Position */
#define SIM_MISCTRL2_SYNCXBARAPITTRIG3(x)        (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SIM_MISCTRL2.SYNCXBARAPITTRIG3 Field    */
#define SIM_MISCTRL2_SYNCXBARBPITTRIG0_MASK      (0x1000U)                                           /*!< SIM_MISCTRL2.SYNCXBARBPITTRIG0 Mask     */
#define SIM_MISCTRL2_SYNCXBARBPITTRIG0_SHIFT     (12U)                                               /*!< SIM_MISCTRL2.SYNCXBARBPITTRIG0 Position */
#define SIM_MISCTRL2_SYNCXBARBPITTRIG0(x)        (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SIM_MISCTRL2.SYNCXBARBPITTRIG0 Field    */
#define SIM_MISCTRL2_SYNCXBARBPITTRIG1_MASK      (0x2000U)                                           /*!< SIM_MISCTRL2.SYNCXBARBPITTRIG1 Mask     */
#define SIM_MISCTRL2_SYNCXBARBPITTRIG1_SHIFT     (13U)                                               /*!< SIM_MISCTRL2.SYNCXBARBPITTRIG1 Position */
#define SIM_MISCTRL2_SYNCXBARBPITTRIG1(x)        (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< SIM_MISCTRL2.SYNCXBARBPITTRIG1 Field    */
#define SIM_MISCTRL2_SYNCDACHWTRIG_MASK          (0x10000U)                                          /*!< SIM_MISCTRL2.SYNCDACHWTRIG Mask         */
#define SIM_MISCTRL2_SYNCDACHWTRIG_SHIFT         (16U)                                               /*!< SIM_MISCTRL2.SYNCDACHWTRIG Position     */
#define SIM_MISCTRL2_SYNCDACHWTRIG(x)            (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< SIM_MISCTRL2.SYNCDACHWTRIG Field        */
#define SIM_MISCTRL2_SYNCEWMIN_MASK              (0x20000U)                                          /*!< SIM_MISCTRL2.SYNCEWMIN Mask             */
#define SIM_MISCTRL2_SYNCEWMIN_SHIFT             (17U)                                               /*!< SIM_MISCTRL2.SYNCEWMIN Position         */
#define SIM_MISCTRL2_SYNCEWMIN(x)                (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< SIM_MISCTRL2.SYNCEWMIN Field            */
#define SIM_MISCTRL2_SYNCCMP0SAMPLEWIN_MASK      (0x100000U)                                         /*!< SIM_MISCTRL2.SYNCCMP0SAMPLEWIN Mask     */
#define SIM_MISCTRL2_SYNCCMP0SAMPLEWIN_SHIFT     (20U)                                               /*!< SIM_MISCTRL2.SYNCCMP0SAMPLEWIN Position */
#define SIM_MISCTRL2_SYNCCMP0SAMPLEWIN(x)        (((uint32_t)(((uint32_t)(x))<<20U))&0x100000UL)     /*!< SIM_MISCTRL2.SYNCCMP0SAMPLEWIN Field    */
#define SIM_MISCTRL2_SYNCCMP1SAMPLEWIN_MASK      (0x200000U)                                         /*!< SIM_MISCTRL2.SYNCCMP1SAMPLEWIN Mask     */
#define SIM_MISCTRL2_SYNCCMP1SAMPLEWIN_SHIFT     (21U)                                               /*!< SIM_MISCTRL2.SYNCCMP1SAMPLEWIN Position */
#define SIM_MISCTRL2_SYNCCMP1SAMPLEWIN(x)        (((uint32_t)(((uint32_t)(x))<<21U))&0x200000UL)     /*!< SIM_MISCTRL2.SYNCCMP1SAMPLEWIN Field    */
#define SIM_MISCTRL2_SYNCCMP2SAMPLEWIN_MASK      (0x400000U)                                         /*!< SIM_MISCTRL2.SYNCCMP2SAMPLEWIN Mask     */
#define SIM_MISCTRL2_SYNCCMP2SAMPLEWIN_SHIFT     (22U)                                               /*!< SIM_MISCTRL2.SYNCCMP2SAMPLEWIN Position */
#define SIM_MISCTRL2_SYNCCMP2SAMPLEWIN(x)        (((uint32_t)(((uint32_t)(x))<<22U))&0x400000UL)     /*!< SIM_MISCTRL2.SYNCCMP2SAMPLEWIN Field    */
#define SIM_MISCTRL2_SYNCCMP3SAMPLEWIN_MASK      (0x800000U)                                         /*!< SIM_MISCTRL2.SYNCCMP3SAMPLEWIN Mask     */
#define SIM_MISCTRL2_SYNCCMP3SAMPLEWIN_SHIFT     (23U)                                               /*!< SIM_MISCTRL2.SYNCCMP3SAMPLEWIN Position */
#define SIM_MISCTRL2_SYNCCMP3SAMPLEWIN(x)        (((uint32_t)(((uint32_t)(x))<<23U))&0x800000UL)     /*!< SIM_MISCTRL2.SYNCCMP3SAMPLEWIN Field    */
/* ------- WDOGC Bit Fields                         ------ */
#define SIM_WDOGC_WDOGCLKS_MASK                  (0x2U)                                              /*!< SIM_WDOGC.WDOGCLKS Mask                 */
#define SIM_WDOGC_WDOGCLKS_SHIFT                 (1U)                                                /*!< SIM_WDOGC.WDOGCLKS Position             */
#define SIM_WDOGC_WDOGCLKS(x)                    (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SIM_WDOGC.WDOGCLKS Field                */
/* ------- PWRC Bit Fields                          ------ */
#define SIM_PWRC_SRPDN_MASK                      (0x3U)                                              /*!< SIM_PWRC.SRPDN Mask                     */
#define SIM_PWRC_SRPDN_SHIFT                     (0U)                                                /*!< SIM_PWRC.SRPDN Position                 */
#define SIM_PWRC_SRPDN(x)                        (((uint32_t)(((uint32_t)(x))<<0U))&0x3UL)           /*!< SIM_PWRC.SRPDN Field                    */
#define SIM_PWRC_SR27STDBY_MASK                  (0xCU)                                              /*!< SIM_PWRC.SR27STDBY Mask                 */
#define SIM_PWRC_SR27STDBY_SHIFT                 (2U)                                                /*!< SIM_PWRC.SR27STDBY Position             */
#define SIM_PWRC_SR27STDBY(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0xCUL)           /*!< SIM_PWRC.SR27STDBY Field                */
#define SIM_PWRC_SR12STDBY_MASK                  (0xC0U)                                             /*!< SIM_PWRC.SR12STDBY Mask                 */
#define SIM_PWRC_SR12STDBY_SHIFT                 (6U)                                                /*!< SIM_PWRC.SR12STDBY Position             */
#define SIM_PWRC_SR12STDBY(x)                    (((uint32_t)(((uint32_t)(x))<<6U))&0xC0UL)          /*!< SIM_PWRC.SR12STDBY Field                */
#define SIM_PWRC_SRPWRDETEN_MASK                 (0x100U)                                            /*!< SIM_PWRC.SRPWRDETEN Mask                */
#define SIM_PWRC_SRPWRDETEN_SHIFT                (8U)                                                /*!< SIM_PWRC.SRPWRDETEN Position            */
#define SIM_PWRC_SRPWRDETEN(x)                   (((uint32_t)(((uint32_t)(x))<<8U))&0x100UL)         /*!< SIM_PWRC.SRPWRDETEN Field               */
#define SIM_PWRC_SRPWRRDY_MASK                   (0x200U)                                            /*!< SIM_PWRC.SRPWRRDY Mask                  */
#define SIM_PWRC_SRPWRRDY_SHIFT                  (9U)                                                /*!< SIM_PWRC.SRPWRRDY Position              */
#define SIM_PWRC_SRPWRRDY(x)                     (((uint32_t)(((uint32_t)(x))<<9U))&0x200UL)         /*!< SIM_PWRC.SRPWRRDY Field                 */
#define SIM_PWRC_SRPWROK_MASK                    (0x10000U)                                          /*!< SIM_PWRC.SRPWROK Mask                   */
#define SIM_PWRC_SRPWROK_SHIFT                   (16U)                                               /*!< SIM_PWRC.SRPWROK Position               */
#define SIM_PWRC_SRPWROK(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< SIM_PWRC.SRPWROK Field                  */
/* ------- ADCOPT Bit Fields                        ------ */
#define SIM_ADCOPT_ADCACH6SEL_MASK               (0x7U)                                              /*!< SIM_ADCOPT.ADCACH6SEL Mask              */
#define SIM_ADCOPT_ADCACH6SEL_SHIFT              (0U)                                                /*!< SIM_ADCOPT.ADCACH6SEL Position          */
#define SIM_ADCOPT_ADCACH6SEL(x)                 (((uint32_t)(((uint32_t)(x))<<0U))&0x7UL)           /*!< SIM_ADCOPT.ADCACH6SEL Field             */
#define SIM_ADCOPT_ADCACH7SEL_MASK               (0x70U)                                             /*!< SIM_ADCOPT.ADCACH7SEL Mask              */
#define SIM_ADCOPT_ADCACH7SEL_SHIFT              (4U)                                                /*!< SIM_ADCOPT.ADCACH7SEL Position          */
#define SIM_ADCOPT_ADCACH7SEL(x)                 (((uint32_t)(((uint32_t)(x))<<4U))&0x70UL)          /*!< SIM_ADCOPT.ADCACH7SEL Field             */
#define SIM_ADCOPT_ADCBCH6SEL_MASK               (0x700U)                                            /*!< SIM_ADCOPT.ADCBCH6SEL Mask              */
#define SIM_ADCOPT_ADCBCH6SEL_SHIFT              (8U)                                                /*!< SIM_ADCOPT.ADCBCH6SEL Position          */
#define SIM_ADCOPT_ADCBCH6SEL(x)                 (((uint32_t)(((uint32_t)(x))<<8U))&0x700UL)         /*!< SIM_ADCOPT.ADCBCH6SEL Field             */
#define SIM_ADCOPT_ADCBCH7SEL_MASK               (0x7000U)                                           /*!< SIM_ADCOPT.ADCBCH7SEL Mask              */
#define SIM_ADCOPT_ADCBCH7SEL_SHIFT              (12U)                                               /*!< SIM_ADCOPT.ADCBCH7SEL Position          */
#define SIM_ADCOPT_ADCBCH7SEL(x)                 (((uint32_t)(((uint32_t)(x))<<12U))&0x7000UL)       /*!< SIM_ADCOPT.ADCBCH7SEL Field             */
#define SIM_ADCOPT_ROSB_MASK                     (0x1000000U)                                        /*!< SIM_ADCOPT.ROSB Mask                    */
#define SIM_ADCOPT_ROSB_SHIFT                    (24U)                                               /*!< SIM_ADCOPT.ROSB Position                */
#define SIM_ADCOPT_ROSB(x)                       (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< SIM_ADCOPT.ROSB Field                   */
#define SIM_ADCOPT_ADCIRCLK_MASK                 (0x2000000U)                                        /*!< SIM_ADCOPT.ADCIRCLK Mask                */
#define SIM_ADCOPT_ADCIRCLK_SHIFT                (25U)                                               /*!< SIM_ADCOPT.ADCIRCLK Position            */
#define SIM_ADCOPT_ADCIRCLK(x)                   (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SIM_ADCOPT.ADCIRCLK Field               */
/**
 * @} */ /* End group SIM_Register_Masks_GROUP 
 */

/* SIM - Peripheral instance base addresses */
#define SIM_BasePtr                    0x40047000UL //!< Peripheral base address
#define SIM                            ((SIM_Type *) SIM_BasePtr) //!< Freescale base pointer
#define SIM_BASE_PTR                   (SIM) //!< Freescale style base pointer
/**
 * @} */ /* End group SIM_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SMC_Peripheral_access_layer_GROUP SMC Peripheral Access Layer
* @brief C Struct for SMC
* @{
*/

/* ================================================================================ */
/* ================           SMC (file:SMC_MKV40F15)              ================ */
/* ================================================================================ */

/**
 * @brief System Mode Controller
 */
/**
* @addtogroup SMC_structs_GROUP SMC struct
* @brief Struct for SMC
* @{
*/
typedef struct {                                /*       SMC Structure                                                */
   __IO uint8_t   PMPROT;                       /**< 0000: Power Mode Protection register                               */
   __IO uint8_t   PMCTRL;                       /**< 0001: Power Mode Control register                                  */
   __IO uint8_t   STOPCTRL;                     /**< 0002: Stop Control Register                                        */
   __I  uint8_t   PMSTAT;                       /**< 0003: Power Mode Status register                                   */
} SMC_Type;

/**
 * @} */ /* End group SMC_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SMC' Position & Mask macros                         ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SMC_Register_Masks_GROUP SMC Register Masks
* @brief Register Masks for SMC
* @{
*/
/* ------- PMPROT Bit Fields                        ------ */
#define SMC_PMPROT_AVLLS_MASK                    (0x2U)                                              /*!< SMC_PMPROT.AVLLS Mask                   */
#define SMC_PMPROT_AVLLS_SHIFT                   (1U)                                                /*!< SMC_PMPROT.AVLLS Position               */
#define SMC_PMPROT_AVLLS(x)                      (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< SMC_PMPROT.AVLLS Field                  */
#define SMC_PMPROT_AVLP_MASK                     (0x20U)                                             /*!< SMC_PMPROT.AVLP Mask                    */
#define SMC_PMPROT_AVLP_SHIFT                    (5U)                                                /*!< SMC_PMPROT.AVLP Position                */
#define SMC_PMPROT_AVLP(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< SMC_PMPROT.AVLP Field                   */
#define SMC_PMPROT_AHSRUN_MASK                   (0x80U)                                             /*!< SMC_PMPROT.AHSRUN Mask                  */
#define SMC_PMPROT_AHSRUN_SHIFT                  (7U)                                                /*!< SMC_PMPROT.AHSRUN Position              */
#define SMC_PMPROT_AHSRUN(x)                     (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< SMC_PMPROT.AHSRUN Field                 */
/* ------- PMCTRL Bit Fields                        ------ */
#define SMC_PMCTRL_STOPM_MASK                    (0x7U)                                              /*!< SMC_PMCTRL.STOPM Mask                   */
#define SMC_PMCTRL_STOPM_SHIFT                   (0U)                                                /*!< SMC_PMCTRL.STOPM Position               */
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< SMC_PMCTRL.STOPM Field                  */
#define SMC_PMCTRL_STOPA_MASK                    (0x8U)                                              /*!< SMC_PMCTRL.STOPA Mask                   */
#define SMC_PMCTRL_STOPA_SHIFT                   (3U)                                                /*!< SMC_PMCTRL.STOPA Position               */
#define SMC_PMCTRL_STOPA(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< SMC_PMCTRL.STOPA Field                  */
#define SMC_PMCTRL_RUNM_MASK                     (0x60U)                                             /*!< SMC_PMCTRL.RUNM Mask                    */
#define SMC_PMCTRL_RUNM_SHIFT                    (5U)                                                /*!< SMC_PMCTRL.RUNM Position                */
#define SMC_PMCTRL_RUNM(x)                       (((uint8_t)(((uint8_t)(x))<<5U))&0x60UL)            /*!< SMC_PMCTRL.RUNM Field                   */
/* ------- STOPCTRL Bit Fields                      ------ */
#define SMC_STOPCTRL_VLLSM_MASK                  (0x7U)                                              /*!< SMC_STOPCTRL.VLLSM Mask                 */
#define SMC_STOPCTRL_VLLSM_SHIFT                 (0U)                                                /*!< SMC_STOPCTRL.VLLSM Position             */
#define SMC_STOPCTRL_VLLSM(x)                    (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< SMC_STOPCTRL.VLLSM Field                */
#define SMC_STOPCTRL_LPOPO_MASK                  (0x8U)                                              /*!< SMC_STOPCTRL.LPOPO Mask                 */
#define SMC_STOPCTRL_LPOPO_SHIFT                 (3U)                                                /*!< SMC_STOPCTRL.LPOPO Position             */
#define SMC_STOPCTRL_LPOPO(x)                    (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< SMC_STOPCTRL.LPOPO Field                */
#define SMC_STOPCTRL_RAM2PO_MASK                 (0x10U)                                             /*!< SMC_STOPCTRL.RAM2PO Mask                */
#define SMC_STOPCTRL_RAM2PO_SHIFT                (4U)                                                /*!< SMC_STOPCTRL.RAM2PO Position            */
#define SMC_STOPCTRL_RAM2PO(x)                   (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< SMC_STOPCTRL.RAM2PO Field               */
#define SMC_STOPCTRL_PORPO_MASK                  (0x20U)                                             /*!< SMC_STOPCTRL.PORPO Mask                 */
#define SMC_STOPCTRL_PORPO_SHIFT                 (5U)                                                /*!< SMC_STOPCTRL.PORPO Position             */
#define SMC_STOPCTRL_PORPO(x)                    (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< SMC_STOPCTRL.PORPO Field                */
#define SMC_STOPCTRL_PSTOPO_MASK                 (0xC0U)                                             /*!< SMC_STOPCTRL.PSTOPO Mask                */
#define SMC_STOPCTRL_PSTOPO_SHIFT                (6U)                                                /*!< SMC_STOPCTRL.PSTOPO Position            */
#define SMC_STOPCTRL_PSTOPO(x)                   (((uint8_t)(((uint8_t)(x))<<6U))&0xC0UL)            /*!< SMC_STOPCTRL.PSTOPO Field               */
/* ------- PMSTAT Bit Fields                        ------ */
#define SMC_PMSTAT_PMSTAT_MASK                   (0xFFU)                                             /*!< SMC_PMSTAT.PMSTAT Mask                  */
#define SMC_PMSTAT_PMSTAT_SHIFT                  (0U)                                                /*!< SMC_PMSTAT.PMSTAT Position              */
#define SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< SMC_PMSTAT.PMSTAT Field                 */
/**
 * @} */ /* End group SMC_Register_Masks_GROUP 
 */

/* SMC - Peripheral instance base addresses */
#define SMC_BasePtr                    0x4007E000UL //!< Peripheral base address
#define SMC                            ((SMC_Type *) SMC_BasePtr) //!< Freescale base pointer
#define SMC_BASE_PTR                   (SMC) //!< Freescale style base pointer
/**
 * @} */ /* End group SMC_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SPI_Peripheral_access_layer_GROUP SPI Peripheral Access Layer
* @brief C Struct for SPI
* @{
*/

/* ================================================================================ */
/* ================           SPI0 (file:SPI0_MKV_PCSIS6_PCSSE)       ================ */
/* ================================================================================ */

/**
 * @brief Serial Peripheral Interface
 */
/**
* @addtogroup SPI_structs_GROUP SPI struct
* @brief Struct for SPI
* @{
*/
typedef struct {                                /*       SPI0 Structure                                               */
   __IO uint32_t  MCR;                          /**< 0000: Module Configuration Register                                */
        uint8_t   RESERVED_0[4];               
   __IO uint32_t  TCR;                          /**< 0008: Transfer Count Register                                      */
   union {                                      /**< 0000: (size=0008)                                                  */
      __IO uint32_t  CTAR[2];                   /**< 000C: Clock and Transfer Attributes Register (In Master Mode)      */
      __IO uint32_t  CTAR_SLAVE;                /**< 000C: Clock and Transfer Attributes Register (In Slave Mode)       */
   };
        uint8_t   RESERVED_1[24];              
   __IO uint32_t  SR;                           /**< 002C: Status register                                              */
   __IO uint32_t  RSER;                         /**< 0030: DMA/Interrupt Request Select and Enable Register             */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  PUSHR;                     /**< 0034: PUSH TX FIFO Register In Master Mode                         */
      __IO uint32_t  PUSHR_SLAVE;               /**< 0034: PUSH TX FIFO Register In Slave Mode                          */
   };
   __I  uint32_t  POPR;                         /**< 0038: POP RX FIFO Register                                         */
   __I  uint32_t  TXFR[4];                      /**< 003C: Transmit FIFO                                                */
        uint8_t   RESERVED_2[48];              
   __I  uint32_t  RXFR[4];                      /**< 007C: Receive FIFO                                                 */
        uint8_t   RESERVED_3[176];             
   __IO uint32_t  SREX;                         /**< 013C: Status register Extended                                     */
} SPI_Type;

/**
 * @} */ /* End group SPI_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SPI0' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SPI_Register_Masks_GROUP SPI Register Masks
* @brief Register Masks for SPI
* @{
*/
/* ------- MCR Bit Fields                           ------ */
#define SPI_MCR_HALT_MASK                        (0x1U)                                              /*!< SPI0_MCR.HALT Mask                      */
#define SPI_MCR_HALT_SHIFT                       (0U)                                                /*!< SPI0_MCR.HALT Position                  */
#define SPI_MCR_HALT(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SPI0_MCR.HALT Field                     */
#define SPI_MCR_SMPL_PT_MASK                     (0x300U)                                            /*!< SPI0_MCR.SMPL_PT Mask                   */
#define SPI_MCR_SMPL_PT_SHIFT                    (8U)                                                /*!< SPI0_MCR.SMPL_PT Position               */
#define SPI_MCR_SMPL_PT(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0x300UL)         /*!< SPI0_MCR.SMPL_PT Field                  */
#define SPI_MCR_CLR_RXF_MASK                     (0x400U)                                            /*!< SPI0_MCR.CLR_RXF Mask                   */
#define SPI_MCR_CLR_RXF_SHIFT                    (10U)                                               /*!< SPI0_MCR.CLR_RXF Position               */
#define SPI_MCR_CLR_RXF(x)                       (((uint32_t)(((uint32_t)(x))<<10U))&0x400UL)        /*!< SPI0_MCR.CLR_RXF Field                  */
#define SPI_MCR_CLR_TXF_MASK                     (0x800U)                                            /*!< SPI0_MCR.CLR_TXF Mask                   */
#define SPI_MCR_CLR_TXF_SHIFT                    (11U)                                               /*!< SPI0_MCR.CLR_TXF Position               */
#define SPI_MCR_CLR_TXF(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SPI0_MCR.CLR_TXF Field                  */
#define SPI_MCR_DIS_RXF_MASK                     (0x1000U)                                           /*!< SPI0_MCR.DIS_RXF Mask                   */
#define SPI_MCR_DIS_RXF_SHIFT                    (12U)                                               /*!< SPI0_MCR.DIS_RXF Position               */
#define SPI_MCR_DIS_RXF(x)                       (((uint32_t)(((uint32_t)(x))<<12U))&0x1000UL)       /*!< SPI0_MCR.DIS_RXF Field                  */
#define SPI_MCR_DIS_TXF_MASK                     (0x2000U)                                           /*!< SPI0_MCR.DIS_TXF Mask                   */
#define SPI_MCR_DIS_TXF_SHIFT                    (13U)                                               /*!< SPI0_MCR.DIS_TXF Position               */
#define SPI_MCR_DIS_TXF(x)                       (((uint32_t)(((uint32_t)(x))<<13U))&0x2000UL)       /*!< SPI0_MCR.DIS_TXF Field                  */
#define SPI_MCR_MDIS_MASK                        (0x4000U)                                           /*!< SPI0_MCR.MDIS Mask                      */
#define SPI_MCR_MDIS_SHIFT                       (14U)                                               /*!< SPI0_MCR.MDIS Position                  */
#define SPI_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< SPI0_MCR.MDIS Field                     */
#define SPI_MCR_DOZE_MASK                        (0x8000U)                                           /*!< SPI0_MCR.DOZE Mask                      */
#define SPI_MCR_DOZE_SHIFT                       (15U)                                               /*!< SPI0_MCR.DOZE Position                  */
#define SPI_MCR_DOZE(x)                          (((uint32_t)(((uint32_t)(x))<<15U))&0x8000UL)       /*!< SPI0_MCR.DOZE Field                     */
#define SPI_MCR_PCSIS_MASK                       (0x3F0000U)                                         /*!< SPI0_MCR.PCSIS Mask                     */
#define SPI_MCR_PCSIS_SHIFT                      (16U)                                               /*!< SPI0_MCR.PCSIS Position                 */
#define SPI_MCR_PCSIS(x)                         (((uint32_t)(((uint32_t)(x))<<16U))&0x3F0000UL)     /*!< SPI0_MCR.PCSIS Field                    */
#define SPI_MCR_ROOE_MASK                        (0x1000000U)                                        /*!< SPI0_MCR.ROOE Mask                      */
#define SPI_MCR_ROOE_SHIFT                       (24U)                                               /*!< SPI0_MCR.ROOE Position                  */
#define SPI_MCR_ROOE(x)                          (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< SPI0_MCR.ROOE Field                     */
#define SPI_MCR_PCSSE_MASK                       (0x2000000U)                                        /*!< SPI0_MCR.PCSSE Mask                     */
#define SPI_MCR_PCSSE_SHIFT                      (25U)                                               /*!< SPI0_MCR.PCSSE Position                 */
#define SPI_MCR_PCSSE(x)                         (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SPI0_MCR.PCSSE Field                    */
#define SPI_MCR_MTFE_MASK                        (0x4000000U)                                        /*!< SPI0_MCR.MTFE Mask                      */
#define SPI_MCR_MTFE_SHIFT                       (26U)                                               /*!< SPI0_MCR.MTFE Position                  */
#define SPI_MCR_MTFE(x)                          (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< SPI0_MCR.MTFE Field                     */
#define SPI_MCR_FRZ_MASK                         (0x8000000U)                                        /*!< SPI0_MCR.FRZ Mask                       */
#define SPI_MCR_FRZ_SHIFT                        (27U)                                               /*!< SPI0_MCR.FRZ Position                   */
#define SPI_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< SPI0_MCR.FRZ Field                      */
#define SPI_MCR_DCONF_MASK                       (0x30000000U)                                       /*!< SPI0_MCR.DCONF Mask                     */
#define SPI_MCR_DCONF_SHIFT                      (28U)                                               /*!< SPI0_MCR.DCONF Position                 */
#define SPI_MCR_DCONF(x)                         (((uint32_t)(((uint32_t)(x))<<28U))&0x30000000UL)   /*!< SPI0_MCR.DCONF Field                    */
#define SPI_MCR_CONT_SCKE_MASK                   (0x40000000U)                                       /*!< SPI0_MCR.CONT_SCKE Mask                 */
#define SPI_MCR_CONT_SCKE_SHIFT                  (30U)                                               /*!< SPI0_MCR.CONT_SCKE Position             */
#define SPI_MCR_CONT_SCKE(x)                     (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< SPI0_MCR.CONT_SCKE Field                */
#define SPI_MCR_MSTR_MASK                        (0x80000000U)                                       /*!< SPI0_MCR.MSTR Mask                      */
#define SPI_MCR_MSTR_SHIFT                       (31U)                                               /*!< SPI0_MCR.MSTR Position                  */
#define SPI_MCR_MSTR(x)                          (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SPI0_MCR.MSTR Field                     */
/* ------- TCR Bit Fields                           ------ */
#define SPI_TCR_SPI_TCNT_MASK                    (0xFFFF0000U)                                       /*!< SPI0_TCR.SPI_TCNT Mask                  */
#define SPI_TCR_SPI_TCNT_SHIFT                   (16U)                                               /*!< SPI0_TCR.SPI_TCNT Position              */
#define SPI_TCR_SPI_TCNT(x)                      (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< SPI0_TCR.SPI_TCNT Field                 */
/* ------- CTAR Bit Fields                          ------ */
#define SPI_CTAR_BR_MASK                         (0xFU)                                              /*!< SPI0_CTAR.BR Mask                       */
#define SPI_CTAR_BR_SHIFT                        (0U)                                                /*!< SPI0_CTAR.BR Position                   */
#define SPI_CTAR_BR(x)                           (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< SPI0_CTAR.BR Field                      */
#define SPI_CTAR_DT_MASK                         (0xF0U)                                             /*!< SPI0_CTAR.DT Mask                       */
#define SPI_CTAR_DT_SHIFT                        (4U)                                                /*!< SPI0_CTAR.DT Position                   */
#define SPI_CTAR_DT(x)                           (((uint32_t)(((uint32_t)(x))<<4U))&0xF0UL)          /*!< SPI0_CTAR.DT Field                      */
#define SPI_CTAR_ASC_MASK                        (0xF00U)                                            /*!< SPI0_CTAR.ASC Mask                      */
#define SPI_CTAR_ASC_SHIFT                       (8U)                                                /*!< SPI0_CTAR.ASC Position                  */
#define SPI_CTAR_ASC(x)                          (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< SPI0_CTAR.ASC Field                     */
#define SPI_CTAR_CSSCK_MASK                      (0xF000U)                                           /*!< SPI0_CTAR.CSSCK Mask                    */
#define SPI_CTAR_CSSCK_SHIFT                     (12U)                                               /*!< SPI0_CTAR.CSSCK Position                */
#define SPI_CTAR_CSSCK(x)                        (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< SPI0_CTAR.CSSCK Field                   */
#define SPI_CTAR_PBR_MASK                        (0x30000U)                                          /*!< SPI0_CTAR.PBR Mask                      */
#define SPI_CTAR_PBR_SHIFT                       (16U)                                               /*!< SPI0_CTAR.PBR Position                  */
#define SPI_CTAR_PBR(x)                          (((uint32_t)(((uint32_t)(x))<<16U))&0x30000UL)      /*!< SPI0_CTAR.PBR Field                     */
#define SPI_CTAR_PDT_MASK                        (0xC0000U)                                          /*!< SPI0_CTAR.PDT Mask                      */
#define SPI_CTAR_PDT_SHIFT                       (18U)                                               /*!< SPI0_CTAR.PDT Position                  */
#define SPI_CTAR_PDT(x)                          (((uint32_t)(((uint32_t)(x))<<18U))&0xC0000UL)      /*!< SPI0_CTAR.PDT Field                     */
#define SPI_CTAR_PASC_MASK                       (0x300000U)                                         /*!< SPI0_CTAR.PASC Mask                     */
#define SPI_CTAR_PASC_SHIFT                      (20U)                                               /*!< SPI0_CTAR.PASC Position                 */
#define SPI_CTAR_PASC(x)                         (((uint32_t)(((uint32_t)(x))<<20U))&0x300000UL)     /*!< SPI0_CTAR.PASC Field                    */
#define SPI_CTAR_PCSSCK_MASK                     (0xC00000U)                                         /*!< SPI0_CTAR.PCSSCK Mask                   */
#define SPI_CTAR_PCSSCK_SHIFT                    (22U)                                               /*!< SPI0_CTAR.PCSSCK Position               */
#define SPI_CTAR_PCSSCK(x)                       (((uint32_t)(((uint32_t)(x))<<22U))&0xC00000UL)     /*!< SPI0_CTAR.PCSSCK Field                  */
#define SPI_CTAR_LSBFE_MASK                      (0x1000000U)                                        /*!< SPI0_CTAR.LSBFE Mask                    */
#define SPI_CTAR_LSBFE_SHIFT                     (24U)                                               /*!< SPI0_CTAR.LSBFE Position                */
#define SPI_CTAR_LSBFE(x)                        (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< SPI0_CTAR.LSBFE Field                   */
#define SPI_CTAR_MODE_MASK                       (0x6000000U)                                        /*!< SPI0_CTAR.MODE Mask                     */
#define SPI_CTAR_MODE_SHIFT                      (25U)                                               /*!< SPI0_CTAR.MODE Position                 */
#define SPI_CTAR_MODE(x)                         (((uint32_t)(((uint32_t)(x))<<25U))&0x6000000UL)    /*!< SPI0_CTAR.MODE Field                    */
#define SPI_CTAR_CPHA_MASK                       (0x2000000U)                                        /*!< SPI0_CTAR.CPHA Mask                     */
#define SPI_CTAR_CPHA_SHIFT                      (25U)                                               /*!< SPI0_CTAR.CPHA Position                 */
#define SPI_CTAR_CPHA(x)                         (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SPI0_CTAR.CPHA Field                    */
#define SPI_CTAR_CPOL_MASK                       (0x4000000U)                                        /*!< SPI0_CTAR.CPOL Mask                     */
#define SPI_CTAR_CPOL_SHIFT                      (26U)                                               /*!< SPI0_CTAR.CPOL Position                 */
#define SPI_CTAR_CPOL(x)                         (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< SPI0_CTAR.CPOL Field                    */
#define SPI_CTAR_FMSZ_MASK                       (0x78000000U)                                       /*!< SPI0_CTAR.FMSZ Mask                     */
#define SPI_CTAR_FMSZ_SHIFT                      (27U)                                               /*!< SPI0_CTAR.FMSZ Position                 */
#define SPI_CTAR_FMSZ(x)                         (((uint32_t)(((uint32_t)(x))<<27U))&0x78000000UL)   /*!< SPI0_CTAR.FMSZ Field                    */
#define SPI_CTAR_DBR_MASK                        (0x80000000U)                                       /*!< SPI0_CTAR.DBR Mask                      */
#define SPI_CTAR_DBR_SHIFT                       (31U)                                               /*!< SPI0_CTAR.DBR Position                  */
#define SPI_CTAR_DBR(x)                          (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SPI0_CTAR.DBR Field                     */
/* ------- CTAR_SLAVE Bit Fields                    ------ */
#define SPI_CTAR_SLAVE_MODE_MASK                 (0x6000000U)                                        /*!< SPI0_CTAR_SLAVE.MODE Mask               */
#define SPI_CTAR_SLAVE_MODE_SHIFT                (25U)                                               /*!< SPI0_CTAR_SLAVE.MODE Position           */
#define SPI_CTAR_SLAVE_MODE(x)                   (((uint32_t)(((uint32_t)(x))<<25U))&0x6000000UL)    /*!< SPI0_CTAR_SLAVE.MODE Field              */
#define SPI_CTAR_SLAVE_CPHA_MASK                 (0x2000000U)                                        /*!< SPI0_CTAR_SLAVE.CPHA Mask               */
#define SPI_CTAR_SLAVE_CPHA_SHIFT                (25U)                                               /*!< SPI0_CTAR_SLAVE.CPHA Position           */
#define SPI_CTAR_SLAVE_CPHA(x)                   (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SPI0_CTAR_SLAVE.CPHA Field              */
#define SPI_CTAR_SLAVE_CPOL_MASK                 (0x4000000U)                                        /*!< SPI0_CTAR_SLAVE.CPOL Mask               */
#define SPI_CTAR_SLAVE_CPOL_SHIFT                (26U)                                               /*!< SPI0_CTAR_SLAVE.CPOL Position           */
#define SPI_CTAR_SLAVE_CPOL(x)                   (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< SPI0_CTAR_SLAVE.CPOL Field              */
#define SPI_CTAR_SLAVE_FMSZ_MASK                 (0xF8000000U)                                       /*!< SPI0_CTAR_SLAVE.FMSZ Mask               */
#define SPI_CTAR_SLAVE_FMSZ_SHIFT                (27U)                                               /*!< SPI0_CTAR_SLAVE.FMSZ Position           */
#define SPI_CTAR_SLAVE_FMSZ(x)                   (((uint32_t)(((uint32_t)(x))<<27U))&0xF8000000UL)   /*!< SPI0_CTAR_SLAVE.FMSZ Field              */
/* ------- SR Bit Fields                            ------ */
#define SPI_SR_POPNXTPTR_MASK                    (0xFU)                                              /*!< SPI0_SR.POPNXTPTR Mask                  */
#define SPI_SR_POPNXTPTR_SHIFT                   (0U)                                                /*!< SPI0_SR.POPNXTPTR Position              */
#define SPI_SR_POPNXTPTR(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< SPI0_SR.POPNXTPTR Field                 */
#define SPI_SR_RXCTR_MASK                        (0xF0U)                                             /*!< SPI0_SR.RXCTR Mask                      */
#define SPI_SR_RXCTR_SHIFT                       (4U)                                                /*!< SPI0_SR.RXCTR Position                  */
#define SPI_SR_RXCTR(x)                          (((uint32_t)(((uint32_t)(x))<<4U))&0xF0UL)          /*!< SPI0_SR.RXCTR Field                     */
#define SPI_SR_TXNXTPTR_MASK                     (0xF00U)                                            /*!< SPI0_SR.TXNXTPTR Mask                   */
#define SPI_SR_TXNXTPTR_SHIFT                    (8U)                                                /*!< SPI0_SR.TXNXTPTR Position               */
#define SPI_SR_TXNXTPTR(x)                       (((uint32_t)(((uint32_t)(x))<<8U))&0xF00UL)         /*!< SPI0_SR.TXNXTPTR Field                  */
#define SPI_SR_TXCTR_MASK                        (0xF000U)                                           /*!< SPI0_SR.TXCTR Mask                      */
#define SPI_SR_TXCTR_SHIFT                       (12U)                                               /*!< SPI0_SR.TXCTR Position                  */
#define SPI_SR_TXCTR(x)                          (((uint32_t)(((uint32_t)(x))<<12U))&0xF000UL)       /*!< SPI0_SR.TXCTR Field                     */
#define SPI_SR_RFDF_MASK                         (0x20000U)                                          /*!< SPI0_SR.RFDF Mask                       */
#define SPI_SR_RFDF_SHIFT                        (17U)                                               /*!< SPI0_SR.RFDF Position                   */
#define SPI_SR_RFDF(x)                           (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< SPI0_SR.RFDF Field                      */
#define SPI_SR_RFOF_MASK                         (0x80000U)                                          /*!< SPI0_SR.RFOF Mask                       */
#define SPI_SR_RFOF_SHIFT                        (19U)                                               /*!< SPI0_SR.RFOF Position                   */
#define SPI_SR_RFOF(x)                           (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< SPI0_SR.RFOF Field                      */
#define SPI_SR_TFFF_MASK                         (0x2000000U)                                        /*!< SPI0_SR.TFFF Mask                       */
#define SPI_SR_TFFF_SHIFT                        (25U)                                               /*!< SPI0_SR.TFFF Position                   */
#define SPI_SR_TFFF(x)                           (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SPI0_SR.TFFF Field                      */
#define SPI_SR_TFUF_MASK                         (0x8000000U)                                        /*!< SPI0_SR.TFUF Mask                       */
#define SPI_SR_TFUF_SHIFT                        (27U)                                               /*!< SPI0_SR.TFUF Position                   */
#define SPI_SR_TFUF(x)                           (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< SPI0_SR.TFUF Field                      */
#define SPI_SR_EOQF_MASK                         (0x10000000U)                                       /*!< SPI0_SR.EOQF Mask                       */
#define SPI_SR_EOQF_SHIFT                        (28U)                                               /*!< SPI0_SR.EOQF Position                   */
#define SPI_SR_EOQF(x)                           (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< SPI0_SR.EOQF Field                      */
#define SPI_SR_TXRXS_MASK                        (0x40000000U)                                       /*!< SPI0_SR.TXRXS Mask                      */
#define SPI_SR_TXRXS_SHIFT                       (30U)                                               /*!< SPI0_SR.TXRXS Position                  */
#define SPI_SR_TXRXS(x)                          (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< SPI0_SR.TXRXS Field                     */
#define SPI_SR_TCF_MASK                          (0x80000000U)                                       /*!< SPI0_SR.TCF Mask                        */
#define SPI_SR_TCF_SHIFT                         (31U)                                               /*!< SPI0_SR.TCF Position                    */
#define SPI_SR_TCF(x)                            (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SPI0_SR.TCF Field                       */
/* ------- RSER Bit Fields                          ------ */
#define SPI_RSER_RFDF_DIRS_MASK                  (0x10000U)                                          /*!< SPI0_RSER.RFDF_DIRS Mask                */
#define SPI_RSER_RFDF_DIRS_SHIFT                 (16U)                                               /*!< SPI0_RSER.RFDF_DIRS Position            */
#define SPI_RSER_RFDF_DIRS(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< SPI0_RSER.RFDF_DIRS Field               */
#define SPI_RSER_RFDF_RE_MASK                    (0x20000U)                                          /*!< SPI0_RSER.RFDF_RE Mask                  */
#define SPI_RSER_RFDF_RE_SHIFT                   (17U)                                               /*!< SPI0_RSER.RFDF_RE Position              */
#define SPI_RSER_RFDF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<17U))&0x20000UL)      /*!< SPI0_RSER.RFDF_RE Field                 */
#define SPI_RSER_RFOF_RE_MASK                    (0x80000U)                                          /*!< SPI0_RSER.RFOF_RE Mask                  */
#define SPI_RSER_RFOF_RE_SHIFT                   (19U)                                               /*!< SPI0_RSER.RFOF_RE Position              */
#define SPI_RSER_RFOF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<19U))&0x80000UL)      /*!< SPI0_RSER.RFOF_RE Field                 */
#define SPI_RSER_TFFF_DIRS_MASK                  (0x1000000U)                                        /*!< SPI0_RSER.TFFF_DIRS Mask                */
#define SPI_RSER_TFFF_DIRS_SHIFT                 (24U)                                               /*!< SPI0_RSER.TFFF_DIRS Position            */
#define SPI_RSER_TFFF_DIRS(x)                    (((uint32_t)(((uint32_t)(x))<<24U))&0x1000000UL)    /*!< SPI0_RSER.TFFF_DIRS Field               */
#define SPI_RSER_TFFF_RE_MASK                    (0x2000000U)                                        /*!< SPI0_RSER.TFFF_RE Mask                  */
#define SPI_RSER_TFFF_RE_SHIFT                   (25U)                                               /*!< SPI0_RSER.TFFF_RE Position              */
#define SPI_RSER_TFFF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<25U))&0x2000000UL)    /*!< SPI0_RSER.TFFF_RE Field                 */
#define SPI_RSER_TFUF_RE_MASK                    (0x8000000U)                                        /*!< SPI0_RSER.TFUF_RE Mask                  */
#define SPI_RSER_TFUF_RE_SHIFT                   (27U)                                               /*!< SPI0_RSER.TFUF_RE Position              */
#define SPI_RSER_TFUF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< SPI0_RSER.TFUF_RE Field                 */
#define SPI_RSER_EOQF_RE_MASK                    (0x10000000U)                                       /*!< SPI0_RSER.EOQF_RE Mask                  */
#define SPI_RSER_EOQF_RE_SHIFT                   (28U)                                               /*!< SPI0_RSER.EOQF_RE Position              */
#define SPI_RSER_EOQF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<28U))&0x10000000UL)   /*!< SPI0_RSER.EOQF_RE Field                 */
#define SPI_RSER_TCF_RE_MASK                     (0x80000000U)                                       /*!< SPI0_RSER.TCF_RE Mask                   */
#define SPI_RSER_TCF_RE_SHIFT                    (31U)                                               /*!< SPI0_RSER.TCF_RE Position               */
#define SPI_RSER_TCF_RE(x)                       (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SPI0_RSER.TCF_RE Field                  */
/* ------- PUSHR Bit Fields                         ------ */
#define SPI_PUSHR_TXDATA_MASK                    (0xFFFFU)                                           /*!< SPI0_PUSHR.TXDATA Mask                  */
#define SPI_PUSHR_TXDATA_SHIFT                   (0U)                                                /*!< SPI0_PUSHR.TXDATA Position              */
#define SPI_PUSHR_TXDATA(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< SPI0_PUSHR.TXDATA Field                 */
#define SPI_PUSHR_PCS_MASK                       (0x3F0000U)                                         /*!< SPI0_PUSHR.PCS Mask                     */
#define SPI_PUSHR_PCS_SHIFT                      (16U)                                               /*!< SPI0_PUSHR.PCS Position                 */
#define SPI_PUSHR_PCS(x)                         (((uint32_t)(((uint32_t)(x))<<16U))&0x3F0000UL)     /*!< SPI0_PUSHR.PCS Field                    */
#define SPI_PUSHR_CTCNT_MASK                     (0x4000000U)                                        /*!< SPI0_PUSHR.CTCNT Mask                   */
#define SPI_PUSHR_CTCNT_SHIFT                    (26U)                                               /*!< SPI0_PUSHR.CTCNT Position               */
#define SPI_PUSHR_CTCNT(x)                       (((uint32_t)(((uint32_t)(x))<<26U))&0x4000000UL)    /*!< SPI0_PUSHR.CTCNT Field                  */
#define SPI_PUSHR_EOQ_MASK                       (0x8000000U)                                        /*!< SPI0_PUSHR.EOQ Mask                     */
#define SPI_PUSHR_EOQ_SHIFT                      (27U)                                               /*!< SPI0_PUSHR.EOQ Position                 */
#define SPI_PUSHR_EOQ(x)                         (((uint32_t)(((uint32_t)(x))<<27U))&0x8000000UL)    /*!< SPI0_PUSHR.EOQ Field                    */
#define SPI_PUSHR_CTAS_MASK                      (0x70000000U)                                       /*!< SPI0_PUSHR.CTAS Mask                    */
#define SPI_PUSHR_CTAS_SHIFT                     (28U)                                               /*!< SPI0_PUSHR.CTAS Position                */
#define SPI_PUSHR_CTAS(x)                        (((uint32_t)(((uint32_t)(x))<<28U))&0x70000000UL)   /*!< SPI0_PUSHR.CTAS Field                   */
#define SPI_PUSHR_CONT_MASK                      (0x80000000U)                                       /*!< SPI0_PUSHR.CONT Mask                    */
#define SPI_PUSHR_CONT_SHIFT                     (31U)                                               /*!< SPI0_PUSHR.CONT Position                */
#define SPI_PUSHR_CONT(x)                        (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SPI0_PUSHR.CONT Field                   */
/* ------- PUSHR_SLAVE Bit Fields                   ------ */
#define SPI_PUSHR_SLAVE_TXDATA_MASK              (0xFFFFU)                                           /*!< SPI0_PUSHR_SLAVE.TXDATA Mask            */
#define SPI_PUSHR_SLAVE_TXDATA_SHIFT             (0U)                                                /*!< SPI0_PUSHR_SLAVE.TXDATA Position        */
#define SPI_PUSHR_SLAVE_TXDATA(x)                (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< SPI0_PUSHR_SLAVE.TXDATA Field           */
/* ------- POPR Bit Fields                          ------ */
#define SPI_POPR_RXDATA_MASK                     (0xFFFFFFFFU)                                       /*!< SPI0_POPR.RXDATA Mask                   */
#define SPI_POPR_RXDATA_SHIFT                    (0U)                                                /*!< SPI0_POPR.RXDATA Position               */
#define SPI_POPR_RXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< SPI0_POPR.RXDATA Field                  */
/* ------- TXFR Bit Fields                          ------ */
#define SPI_TXFR_TXDATA_MASK                     (0xFFFFU)                                           /*!< SPI0_TXFR.TXDATA Mask                   */
#define SPI_TXFR_TXDATA_SHIFT                    (0U)                                                /*!< SPI0_TXFR.TXDATA Position               */
#define SPI_TXFR_TXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFUL)        /*!< SPI0_TXFR.TXDATA Field                  */
#define SPI_TXFR_TXCMD_TXDATA_MASK               (0xFFFF0000U)                                       /*!< SPI0_TXFR.TXCMD_TXDATA Mask             */
#define SPI_TXFR_TXCMD_TXDATA_SHIFT              (16U)                                               /*!< SPI0_TXFR.TXCMD_TXDATA Position         */
#define SPI_TXFR_TXCMD_TXDATA(x)                 (((uint32_t)(((uint32_t)(x))<<16U))&0xFFFF0000UL)   /*!< SPI0_TXFR.TXCMD_TXDATA Field            */
/* ------- RXFR Bit Fields                          ------ */
#define SPI_RXFR_RXDATA_MASK                     (0xFFFFFFFFU)                                       /*!< SPI0_RXFR.RXDATA Mask                   */
#define SPI_RXFR_RXDATA_SHIFT                    (0U)                                                /*!< SPI0_RXFR.RXDATA Position               */
#define SPI_RXFR_RXDATA(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< SPI0_RXFR.RXDATA Field                  */
/* ------- SREX Bit Fields                          ------ */
#define SPI_SREX_CMDNXTPTR_MASK                  (0xFU)                                              /*!< SPI0_SREX.CMDNXTPTR Mask                */
#define SPI_SREX_CMDNXTPTR_SHIFT                 (0U)                                                /*!< SPI0_SREX.CMDNXTPTR Position            */
#define SPI_SREX_CMDNXTPTR(x)                    (((uint32_t)(((uint32_t)(x))<<0U))&0xFUL)           /*!< SPI0_SREX.CMDNXTPTR Field               */
#define SPI_SREX_CMDCTR_MASK                     (0x1F0U)                                            /*!< SPI0_SREX.CMDCTR Mask                   */
#define SPI_SREX_CMDCTR_SHIFT                    (4U)                                                /*!< SPI0_SREX.CMDCTR Position               */
#define SPI_SREX_CMDCTR(x)                       (((uint32_t)(((uint32_t)(x))<<4U))&0x1F0UL)         /*!< SPI0_SREX.CMDCTR Field                  */
#define SPI_SREX_TXCTR4_MASK                     (0x800U)                                            /*!< SPI0_SREX.TXCTR4 Mask                   */
#define SPI_SREX_TXCTR4_SHIFT                    (11U)                                               /*!< SPI0_SREX.TXCTR4 Position               */
#define SPI_SREX_TXCTR4(x)                       (((uint32_t)(((uint32_t)(x))<<11U))&0x800UL)        /*!< SPI0_SREX.TXCTR4 Field                  */
#define SPI_SREX_RXCTR4_MASK                     (0x4000U)                                           /*!< SPI0_SREX.RXCTR4 Mask                   */
#define SPI_SREX_RXCTR4_SHIFT                    (14U)                                               /*!< SPI0_SREX.RXCTR4 Position               */
#define SPI_SREX_RXCTR4(x)                       (((uint32_t)(((uint32_t)(x))<<14U))&0x4000UL)       /*!< SPI0_SREX.RXCTR4 Field                  */
/**
 * @} */ /* End group SPI_Register_Masks_GROUP 
 */

/* SPI0 - Peripheral instance base addresses */
#define SPI0_BasePtr                   0x4002C000UL //!< Peripheral base address
#define SPI0                           ((SPI_Type *) SPI0_BasePtr) //!< Freescale base pointer
#define SPI0_BASE_PTR                  (SPI0) //!< Freescale style base pointer
/**
 * @} */ /* End group SPI_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup SYST_Peripheral_access_layer_GROUP SYST Peripheral Access Layer
* @brief C Struct for SYST
* @{
*/

/* ================================================================================ */
/* ================           SYST (file:SYST)                     ================ */
/* ================================================================================ */

/**
 * @brief System timer
 */
/**
* @addtogroup SYST_structs_GROUP SYST struct
* @brief Struct for SYST
* @{
*/
typedef struct {                                /*       SYST Structure                                               */
   __IO uint32_t  CSR;                          /**< 0000: Control and Status Register                                  */
   __IO uint32_t  RVR;                          /**< 0004: Reload Value Register                                        */
   __IO uint32_t  CVR;                          /**< 0008: Current Value Register                                       */
   __I  uint32_t  CALIB;                        /**< 000C: Calibration Value Register                                   */
} SYST_Type;

/**
 * @} */ /* End group SYST_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'SYST' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup SYST_Register_Masks_GROUP SYST Register Masks
* @brief Register Masks for SYST
* @{
*/
/* ------- CSR Bit Fields                           ------ */
#define SYST_CSR_ENABLE_MASK                     (0x1U)                                              /*!< SYST_CSR.ENABLE Mask                    */
#define SYST_CSR_ENABLE_SHIFT                    (0U)                                                /*!< SYST_CSR.ENABLE Position                */
#define SYST_CSR_ENABLE(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0x1UL)           /*!< SYST_CSR.ENABLE Field                   */
#define SYST_CSR_TICKINT_MASK                    (0x2U)                                              /*!< SYST_CSR.TICKINT Mask                   */
#define SYST_CSR_TICKINT_SHIFT                   (1U)                                                /*!< SYST_CSR.TICKINT Position               */
#define SYST_CSR_TICKINT(x)                      (((uint32_t)(((uint32_t)(x))<<1U))&0x2UL)           /*!< SYST_CSR.TICKINT Field                  */
#define SYST_CSR_CLKSOURCE_MASK                  (0x4U)                                              /*!< SYST_CSR.CLKSOURCE Mask                 */
#define SYST_CSR_CLKSOURCE_SHIFT                 (2U)                                                /*!< SYST_CSR.CLKSOURCE Position             */
#define SYST_CSR_CLKSOURCE(x)                    (((uint32_t)(((uint32_t)(x))<<2U))&0x4UL)           /*!< SYST_CSR.CLKSOURCE Field                */
#define SYST_CSR_COUNTFLAG_MASK                  (0x10000U)                                          /*!< SYST_CSR.COUNTFLAG Mask                 */
#define SYST_CSR_COUNTFLAG_SHIFT                 (16U)                                               /*!< SYST_CSR.COUNTFLAG Position             */
#define SYST_CSR_COUNTFLAG(x)                    (((uint32_t)(((uint32_t)(x))<<16U))&0x10000UL)      /*!< SYST_CSR.COUNTFLAG Field                */
/* ------- RVR Bit Fields                           ------ */
#define SYST_RVR_RELOAD_MASK                     (0xFFFFFFU)                                         /*!< SYST_RVR.RELOAD Mask                    */
#define SYST_RVR_RELOAD_SHIFT                    (0U)                                                /*!< SYST_RVR.RELOAD Position                */
#define SYST_RVR_RELOAD(x)                       (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< SYST_RVR.RELOAD Field                   */
/* ------- CVR Bit Fields                           ------ */
#define SYST_CVR_CURRENT_MASK                    (0xFFFFFFU)                                         /*!< SYST_CVR.CURRENT Mask                   */
#define SYST_CVR_CURRENT_SHIFT                   (0U)                                                /*!< SYST_CVR.CURRENT Position               */
#define SYST_CVR_CURRENT(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< SYST_CVR.CURRENT Field                  */
/* ------- CALIB Bit Fields                         ------ */
#define SYST_CALIB_TENMS_MASK                    (0xFFFFFFU)                                         /*!< SYST_CALIB.TENMS Mask                   */
#define SYST_CALIB_TENMS_SHIFT                   (0U)                                                /*!< SYST_CALIB.TENMS Position               */
#define SYST_CALIB_TENMS(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFUL)      /*!< SYST_CALIB.TENMS Field                  */
#define SYST_CALIB_SKEW_MASK                     (0x40000000U)                                       /*!< SYST_CALIB.SKEW Mask                    */
#define SYST_CALIB_SKEW_SHIFT                    (30U)                                               /*!< SYST_CALIB.SKEW Position                */
#define SYST_CALIB_SKEW(x)                       (((uint32_t)(((uint32_t)(x))<<30U))&0x40000000UL)   /*!< SYST_CALIB.SKEW Field                   */
#define SYST_CALIB_NOREF_MASK                    (0x80000000U)                                       /*!< SYST_CALIB.NOREF Mask                   */
#define SYST_CALIB_NOREF_SHIFT                   (31U)                                               /*!< SYST_CALIB.NOREF Position               */
#define SYST_CALIB_NOREF(x)                      (((uint32_t)(((uint32_t)(x))<<31U))&0x80000000UL)   /*!< SYST_CALIB.NOREF Field                  */
/**
 * @} */ /* End group SYST_Register_Masks_GROUP 
 */

/* SYST - Peripheral instance base addresses */
#define SYST_BasePtr                   0xE000E010UL //!< Peripheral base address
#define SYST                           ((SYST_Type *) SYST_BasePtr) //!< Freescale base pointer
#define SYST_BASE_PTR                  (SYST) //!< Freescale style base pointer
/**
 * @} */ /* End group SYST_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART0 (file:UART0_MKV40)             ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */
/**
* @addtogroup UART_structs_GROUP UART struct
* @brief Struct for UART
* @{
*/
typedef struct {                                /*       UART0 Structure                                              */
   __IO uint8_t   BDH;                          /**< 0000: Baud Rate Register: High                                     */
   __IO uint8_t   BDL;                          /**< 0001: Baud Rate Register: Low                                      */
   __IO uint8_t   C1;                           /**< 0002: Control Register 1                                           */
   __IO uint8_t   C2;                           /**< 0003: Control Register 2                                           */
   __I  uint8_t   S1;                           /**< 0004: Status Register 1                                            */
   __IO uint8_t   S2;                           /**< 0005: Status Register 2                                            */
   __IO uint8_t   C3;                           /**< 0006: Control Register 3                                           */
   __IO uint8_t   D;                            /**< 0007: Data Register                                                */
   __IO uint8_t   MA1;                          /**< 0008: Match Address Registers 1                                    */
   __IO uint8_t   MA2;                          /**< 0009: Match Address Registers 2                                    */
   __IO uint8_t   C4;                           /**< 000A: Control Register 4                                           */
   __IO uint8_t   C5;                           /**< 000B: Control Register 5                                           */
   __I  uint8_t   ED;                           /**< 000C: Extended Data Register                                       */
   __IO uint8_t   MODEM;                        /**< 000D: Modem Register                                               */
        uint8_t   RESERVED_0[2];               
   __IO uint8_t   PFIFO;                        /**< 0010: FIFO Parameters                                              */
   __IO uint8_t   CFIFO;                        /**< 0011: FIFO Control Register                                        */
   __IO uint8_t   SFIFO;                        /**< 0012: FIFO Status Register                                         */
   __IO uint8_t   TWFIFO;                       /**< 0013: FIFO Transmit Watermark                                      */
   __I  uint8_t   TCFIFO;                       /**< 0014: FIFO Transmit Count                                          */
   __IO uint8_t   RWFIFO;                       /**< 0015: FIFO Receive Watermark                                       */
   __I  uint8_t   RCFIFO;                       /**< 0016: FIFO Receive Count                                           */
} UART_Type;

/**
 * @} */ /* End group UART_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'UART0' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup UART_Register_Masks_GROUP UART Register Masks
* @brief Register Masks for UART
* @{
*/
/* ------- BDH Bit Fields                           ------ */
#define UART_BDH_SBR_MASK                        (0x1FU)                                             /*!< UART0_BDH.SBR Mask                      */
#define UART_BDH_SBR_SHIFT                       (0U)                                                /*!< UART0_BDH.SBR Position                  */
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1FUL)            /*!< UART0_BDH.SBR Field                     */
#define UART_BDH_SBNS_MASK                       (0x20U)                                             /*!< UART0_BDH.SBNS Mask                     */
#define UART_BDH_SBNS_SHIFT                      (5U)                                                /*!< UART0_BDH.SBNS Position                 */
#define UART_BDH_SBNS(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< UART0_BDH.SBNS Field                    */
#define UART_BDH_RXEDGIE_MASK                    (0x40U)                                             /*!< UART0_BDH.RXEDGIE Mask                  */
#define UART_BDH_RXEDGIE_SHIFT                   (6U)                                                /*!< UART0_BDH.RXEDGIE Position              */
#define UART_BDH_RXEDGIE(x)                      (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< UART0_BDH.RXEDGIE Field                 */
#define UART_BDH_LBKDIE_MASK                     (0x80U)                                             /*!< UART0_BDH.LBKDIE Mask                   */
#define UART_BDH_LBKDIE_SHIFT                    (7U)                                                /*!< UART0_BDH.LBKDIE Position               */
#define UART_BDH_LBKDIE(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_BDH.LBKDIE Field                  */
/* ------- BDL Bit Fields                           ------ */
#define UART_BDL_SBR_MASK                        (0xFFU)                                             /*!< UART0_BDL.SBR Mask                      */
#define UART_BDL_SBR_SHIFT                       (0U)                                                /*!< UART0_BDL.SBR Position                  */
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< UART0_BDL.SBR Field                     */
/* ------- C1 Bit Fields                            ------ */
#define UART_C1_PT_MASK                          (0x1U)                                              /*!< UART0_C1.PT Mask                        */
#define UART_C1_PT_SHIFT                         (0U)                                                /*!< UART0_C1.PT Position                    */
#define UART_C1_PT(x)                            (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_C1.PT Field                       */
#define UART_C1_PE_MASK                          (0x2U)                                              /*!< UART0_C1.PE Mask                        */
#define UART_C1_PE_SHIFT                         (1U)                                                /*!< UART0_C1.PE Position                    */
#define UART_C1_PE(x)                            (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< UART0_C1.PE Field                       */
#define UART_C1_ILT_MASK                         (0x4U)                                              /*!< UART0_C1.ILT Mask                       */
#define UART_C1_ILT_SHIFT                        (2U)                                                /*!< UART0_C1.ILT Position                   */
#define UART_C1_ILT(x)                           (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< UART0_C1.ILT Field                      */
#define UART_C1_WAKE_MASK                        (0x8U)                                              /*!< UART0_C1.WAKE Mask                      */
#define UART_C1_WAKE_SHIFT                       (3U)                                                /*!< UART0_C1.WAKE Position                  */
#define UART_C1_WAKE(x)                          (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< UART0_C1.WAKE Field                     */
#define UART_C1_M_MASK                           (0x10U)                                             /*!< UART0_C1.M Mask                         */
#define UART_C1_M_SHIFT                          (4U)                                                /*!< UART0_C1.M Position                     */
#define UART_C1_M(x)                             (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< UART0_C1.M Field                        */
#define UART_C1_RSRC_MASK                        (0x20U)                                             /*!< UART0_C1.RSRC Mask                      */
#define UART_C1_RSRC_SHIFT                       (5U)                                                /*!< UART0_C1.RSRC Position                  */
#define UART_C1_RSRC(x)                          (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< UART0_C1.RSRC Field                     */
#define UART_C1_UARTSWAI_MASK                    (0x40U)                                             /*!< UART0_C1.UARTSWAI Mask                  */
#define UART_C1_UARTSWAI_SHIFT                   (6U)                                                /*!< UART0_C1.UARTSWAI Position              */
#define UART_C1_UARTSWAI(x)                      (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< UART0_C1.UARTSWAI Field                 */
#define UART_C1_LOOPS_MASK                       (0x80U)                                             /*!< UART0_C1.LOOPS Mask                     */
#define UART_C1_LOOPS_SHIFT                      (7U)                                                /*!< UART0_C1.LOOPS Position                 */
#define UART_C1_LOOPS(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_C1.LOOPS Field                    */
/* ------- C2 Bit Fields                            ------ */
#define UART_C2_SBK_MASK                         (0x1U)                                              /*!< UART0_C2.SBK Mask                       */
#define UART_C2_SBK_SHIFT                        (0U)                                                /*!< UART0_C2.SBK Position                   */
#define UART_C2_SBK(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_C2.SBK Field                      */
#define UART_C2_RWU_MASK                         (0x2U)                                              /*!< UART0_C2.RWU Mask                       */
#define UART_C2_RWU_SHIFT                        (1U)                                                /*!< UART0_C2.RWU Position                   */
#define UART_C2_RWU(x)                           (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< UART0_C2.RWU Field                      */
#define UART_C2_RE_MASK                          (0x4U)                                              /*!< UART0_C2.RE Mask                        */
#define UART_C2_RE_SHIFT                         (2U)                                                /*!< UART0_C2.RE Position                    */
#define UART_C2_RE(x)                            (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< UART0_C2.RE Field                       */
#define UART_C2_TE_MASK                          (0x8U)                                              /*!< UART0_C2.TE Mask                        */
#define UART_C2_TE_SHIFT                         (3U)                                                /*!< UART0_C2.TE Position                    */
#define UART_C2_TE(x)                            (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< UART0_C2.TE Field                       */
#define UART_C2_ILIE_MASK                        (0x10U)                                             /*!< UART0_C2.ILIE Mask                      */
#define UART_C2_ILIE_SHIFT                       (4U)                                                /*!< UART0_C2.ILIE Position                  */
#define UART_C2_ILIE(x)                          (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< UART0_C2.ILIE Field                     */
#define UART_C2_RIE_MASK                         (0x20U)                                             /*!< UART0_C2.RIE Mask                       */
#define UART_C2_RIE_SHIFT                        (5U)                                                /*!< UART0_C2.RIE Position                   */
#define UART_C2_RIE(x)                           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< UART0_C2.RIE Field                      */
#define UART_C2_TCIE_MASK                        (0x40U)                                             /*!< UART0_C2.TCIE Mask                      */
#define UART_C2_TCIE_SHIFT                       (6U)                                                /*!< UART0_C2.TCIE Position                  */
#define UART_C2_TCIE(x)                          (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< UART0_C2.TCIE Field                     */
#define UART_C2_TIE_MASK                         (0x80U)                                             /*!< UART0_C2.TIE Mask                       */
#define UART_C2_TIE_SHIFT                        (7U)                                                /*!< UART0_C2.TIE Position                   */
#define UART_C2_TIE(x)                           (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_C2.TIE Field                      */
/* ------- S1 Bit Fields                            ------ */
#define UART_S1_PF_MASK                          (0x1U)                                              /*!< UART0_S1.PF Mask                        */
#define UART_S1_PF_SHIFT                         (0U)                                                /*!< UART0_S1.PF Position                    */
#define UART_S1_PF(x)                            (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_S1.PF Field                       */
#define UART_S1_FE_MASK                          (0x2U)                                              /*!< UART0_S1.FE Mask                        */
#define UART_S1_FE_SHIFT                         (1U)                                                /*!< UART0_S1.FE Position                    */
#define UART_S1_FE(x)                            (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< UART0_S1.FE Field                       */
#define UART_S1_NF_MASK                          (0x4U)                                              /*!< UART0_S1.NF Mask                        */
#define UART_S1_NF_SHIFT                         (2U)                                                /*!< UART0_S1.NF Position                    */
#define UART_S1_NF(x)                            (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< UART0_S1.NF Field                       */
#define UART_S1_OR_MASK                          (0x8U)                                              /*!< UART0_S1.OR Mask                        */
#define UART_S1_OR_SHIFT                         (3U)                                                /*!< UART0_S1.OR Position                    */
#define UART_S1_OR(x)                            (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< UART0_S1.OR Field                       */
#define UART_S1_IDLE_MASK                        (0x10U)                                             /*!< UART0_S1.IDLE Mask                      */
#define UART_S1_IDLE_SHIFT                       (4U)                                                /*!< UART0_S1.IDLE Position                  */
#define UART_S1_IDLE(x)                          (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< UART0_S1.IDLE Field                     */
#define UART_S1_RDRF_MASK                        (0x20U)                                             /*!< UART0_S1.RDRF Mask                      */
#define UART_S1_RDRF_SHIFT                       (5U)                                                /*!< UART0_S1.RDRF Position                  */
#define UART_S1_RDRF(x)                          (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< UART0_S1.RDRF Field                     */
#define UART_S1_TC_MASK                          (0x40U)                                             /*!< UART0_S1.TC Mask                        */
#define UART_S1_TC_SHIFT                         (6U)                                                /*!< UART0_S1.TC Position                    */
#define UART_S1_TC(x)                            (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< UART0_S1.TC Field                       */
#define UART_S1_TDRE_MASK                        (0x80U)                                             /*!< UART0_S1.TDRE Mask                      */
#define UART_S1_TDRE_SHIFT                       (7U)                                                /*!< UART0_S1.TDRE Position                  */
#define UART_S1_TDRE(x)                          (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_S1.TDRE Field                     */
/* ------- S2 Bit Fields                            ------ */
#define UART_S2_RAF_MASK                         (0x1U)                                              /*!< UART0_S2.RAF Mask                       */
#define UART_S2_RAF_SHIFT                        (0U)                                                /*!< UART0_S2.RAF Position                   */
#define UART_S2_RAF(x)                           (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_S2.RAF Field                      */
#define UART_S2_LBKDE_MASK                       (0x2U)                                              /*!< UART0_S2.LBKDE Mask                     */
#define UART_S2_LBKDE_SHIFT                      (1U)                                                /*!< UART0_S2.LBKDE Position                 */
#define UART_S2_LBKDE(x)                         (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< UART0_S2.LBKDE Field                    */
#define UART_S2_BRK13_MASK                       (0x4U)                                              /*!< UART0_S2.BRK13 Mask                     */
#define UART_S2_BRK13_SHIFT                      (2U)                                                /*!< UART0_S2.BRK13 Position                 */
#define UART_S2_BRK13(x)                         (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< UART0_S2.BRK13 Field                    */
#define UART_S2_RWUID_MASK                       (0x8U)                                              /*!< UART0_S2.RWUID Mask                     */
#define UART_S2_RWUID_SHIFT                      (3U)                                                /*!< UART0_S2.RWUID Position                 */
#define UART_S2_RWUID(x)                         (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< UART0_S2.RWUID Field                    */
#define UART_S2_RXINV_MASK                       (0x10U)                                             /*!< UART0_S2.RXINV Mask                     */
#define UART_S2_RXINV_SHIFT                      (4U)                                                /*!< UART0_S2.RXINV Position                 */
#define UART_S2_RXINV(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< UART0_S2.RXINV Field                    */
#define UART_S2_MSBF_MASK                        (0x20U)                                             /*!< UART0_S2.MSBF Mask                      */
#define UART_S2_MSBF_SHIFT                       (5U)                                                /*!< UART0_S2.MSBF Position                  */
#define UART_S2_MSBF(x)                          (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< UART0_S2.MSBF Field                     */
#define UART_S2_RXEDGIF_MASK                     (0x40U)                                             /*!< UART0_S2.RXEDGIF Mask                   */
#define UART_S2_RXEDGIF_SHIFT                    (6U)                                                /*!< UART0_S2.RXEDGIF Position               */
#define UART_S2_RXEDGIF(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< UART0_S2.RXEDGIF Field                  */
#define UART_S2_LBKDIF_MASK                      (0x80U)                                             /*!< UART0_S2.LBKDIF Mask                    */
#define UART_S2_LBKDIF_SHIFT                     (7U)                                                /*!< UART0_S2.LBKDIF Position                */
#define UART_S2_LBKDIF(x)                        (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_S2.LBKDIF Field                   */
/* ------- C3 Bit Fields                            ------ */
#define UART_C3_PEIE_MASK                        (0x1U)                                              /*!< UART0_C3.PEIE Mask                      */
#define UART_C3_PEIE_SHIFT                       (0U)                                                /*!< UART0_C3.PEIE Position                  */
#define UART_C3_PEIE(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_C3.PEIE Field                     */
#define UART_C3_FEIE_MASK                        (0x2U)                                              /*!< UART0_C3.FEIE Mask                      */
#define UART_C3_FEIE_SHIFT                       (1U)                                                /*!< UART0_C3.FEIE Position                  */
#define UART_C3_FEIE(x)                          (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< UART0_C3.FEIE Field                     */
#define UART_C3_NEIE_MASK                        (0x4U)                                              /*!< UART0_C3.NEIE Mask                      */
#define UART_C3_NEIE_SHIFT                       (2U)                                                /*!< UART0_C3.NEIE Position                  */
#define UART_C3_NEIE(x)                          (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< UART0_C3.NEIE Field                     */
#define UART_C3_ORIE_MASK                        (0x8U)                                              /*!< UART0_C3.ORIE Mask                      */
#define UART_C3_ORIE_SHIFT                       (3U)                                                /*!< UART0_C3.ORIE Position                  */
#define UART_C3_ORIE(x)                          (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< UART0_C3.ORIE Field                     */
#define UART_C3_TXINV_MASK                       (0x10U)                                             /*!< UART0_C3.TXINV Mask                     */
#define UART_C3_TXINV_SHIFT                      (4U)                                                /*!< UART0_C3.TXINV Position                 */
#define UART_C3_TXINV(x)                         (((uint8_t)(((uint8_t)(x))<<4U))&0x10UL)            /*!< UART0_C3.TXINV Field                    */
#define UART_C3_TXDIR_MASK                       (0x20U)                                             /*!< UART0_C3.TXDIR Mask                     */
#define UART_C3_TXDIR_SHIFT                      (5U)                                                /*!< UART0_C3.TXDIR Position                 */
#define UART_C3_TXDIR(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< UART0_C3.TXDIR Field                    */
#define UART_C3_T8_MASK                          (0x40U)                                             /*!< UART0_C3.T8 Mask                        */
#define UART_C3_T8_SHIFT                         (6U)                                                /*!< UART0_C3.T8 Position                    */
#define UART_C3_T8(x)                            (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< UART0_C3.T8 Field                       */
#define UART_C3_R8_MASK                          (0x80U)                                             /*!< UART0_C3.R8 Mask                        */
#define UART_C3_R8_SHIFT                         (7U)                                                /*!< UART0_C3.R8 Position                    */
#define UART_C3_R8(x)                            (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_C3.R8 Field                       */
/* ------- D Bit Fields                             ------ */
#define UART_D_RT_MASK                           (0xFFU)                                             /*!< UART0_D.RT Mask                         */
#define UART_D_RT_SHIFT                          (0U)                                                /*!< UART0_D.RT Position                     */
#define UART_D_RT(x)                             (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< UART0_D.RT Field                        */
/* ------- MA Bit Fields                            ------ */
#define UART_MA_MA_MASK                          (0xFFU)                                             /*!< UART0_MA.MA Mask                        */
#define UART_MA_MA_SHIFT                         (0U)                                                /*!< UART0_MA.MA Position                    */
#define UART_MA_MA(x)                            (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< UART0_MA.MA Field                       */
/* ------- C4 Bit Fields                            ------ */
#define UART_C4_BRFA_MASK                        (0x1FU)                                             /*!< UART0_C4.BRFA Mask                      */
#define UART_C4_BRFA_SHIFT                       (0U)                                                /*!< UART0_C4.BRFA Position                  */
#define UART_C4_BRFA(x)                          (((uint8_t)(((uint8_t)(x))<<0U))&0x1FUL)            /*!< UART0_C4.BRFA Field                     */
#define UART_C4_M10_MASK                         (0x20U)                                             /*!< UART0_C4.M10 Mask                       */
#define UART_C4_M10_SHIFT                        (5U)                                                /*!< UART0_C4.M10 Position                   */
#define UART_C4_M10(x)                           (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< UART0_C4.M10 Field                      */
#define UART_C4_MAEN2_MASK                       (0x40U)                                             /*!< UART0_C4.MAEN2 Mask                     */
#define UART_C4_MAEN2_SHIFT                      (6U)                                                /*!< UART0_C4.MAEN2 Position                 */
#define UART_C4_MAEN2(x)                         (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< UART0_C4.MAEN2 Field                    */
#define UART_C4_MAEN1_MASK                       (0x80U)                                             /*!< UART0_C4.MAEN1 Mask                     */
#define UART_C4_MAEN1_SHIFT                      (7U)                                                /*!< UART0_C4.MAEN1 Position                 */
#define UART_C4_MAEN1(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_C4.MAEN1 Field                    */
/* ------- C5 Bit Fields                            ------ */
#define UART_C5_LBKDDMAS_MASK                    (0x8U)                                              /*!< UART0_C5.LBKDDMAS Mask                  */
#define UART_C5_LBKDDMAS_SHIFT                   (3U)                                                /*!< UART0_C5.LBKDDMAS Position              */
#define UART_C5_LBKDDMAS(x)                      (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< UART0_C5.LBKDDMAS Field                 */
#define UART_C5_RDMAS_MASK                       (0x20U)                                             /*!< UART0_C5.RDMAS Mask                     */
#define UART_C5_RDMAS_SHIFT                      (5U)                                                /*!< UART0_C5.RDMAS Position                 */
#define UART_C5_RDMAS(x)                         (((uint8_t)(((uint8_t)(x))<<5U))&0x20UL)            /*!< UART0_C5.RDMAS Field                    */
#define UART_C5_TDMAS_MASK                       (0x80U)                                             /*!< UART0_C5.TDMAS Mask                     */
#define UART_C5_TDMAS_SHIFT                      (7U)                                                /*!< UART0_C5.TDMAS Position                 */
#define UART_C5_TDMAS(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_C5.TDMAS Field                    */
/* ------- ED Bit Fields                            ------ */
#define UART_ED_PARITYE_MASK                     (0x40U)                                             /*!< UART0_ED.PARITYE Mask                   */
#define UART_ED_PARITYE_SHIFT                    (6U)                                                /*!< UART0_ED.PARITYE Position               */
#define UART_ED_PARITYE(x)                       (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< UART0_ED.PARITYE Field                  */
#define UART_ED_NOISY_MASK                       (0x80U)                                             /*!< UART0_ED.NOISY Mask                     */
#define UART_ED_NOISY_SHIFT                      (7U)                                                /*!< UART0_ED.NOISY Position                 */
#define UART_ED_NOISY(x)                         (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_ED.NOISY Field                    */
/* ------- MODEM Bit Fields                         ------ */
#define UART_MODEM_TXCTSE_MASK                   (0x1U)                                              /*!< UART0_MODEM.TXCTSE Mask                 */
#define UART_MODEM_TXCTSE_SHIFT                  (0U)                                                /*!< UART0_MODEM.TXCTSE Position             */
#define UART_MODEM_TXCTSE(x)                     (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_MODEM.TXCTSE Field                */
#define UART_MODEM_TXRTSE_MASK                   (0x2U)                                              /*!< UART0_MODEM.TXRTSE Mask                 */
#define UART_MODEM_TXRTSE_SHIFT                  (1U)                                                /*!< UART0_MODEM.TXRTSE Position             */
#define UART_MODEM_TXRTSE(x)                     (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< UART0_MODEM.TXRTSE Field                */
#define UART_MODEM_TXRTSPOL_MASK                 (0x4U)                                              /*!< UART0_MODEM.TXRTSPOL Mask               */
#define UART_MODEM_TXRTSPOL_SHIFT                (2U)                                                /*!< UART0_MODEM.TXRTSPOL Position           */
#define UART_MODEM_TXRTSPOL(x)                   (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< UART0_MODEM.TXRTSPOL Field              */
#define UART_MODEM_RXRTSE_MASK                   (0x8U)                                              /*!< UART0_MODEM.RXRTSE Mask                 */
#define UART_MODEM_RXRTSE_SHIFT                  (3U)                                                /*!< UART0_MODEM.RXRTSE Position             */
#define UART_MODEM_RXRTSE(x)                     (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< UART0_MODEM.RXRTSE Field                */
/* ------- PFIFO Bit Fields                         ------ */
#define UART_PFIFO_RXFIFOSIZE_MASK               (0x7U)                                              /*!< UART0_PFIFO.RXFIFOSIZE Mask             */
#define UART_PFIFO_RXFIFOSIZE_SHIFT              (0U)                                                /*!< UART0_PFIFO.RXFIFOSIZE Position         */
#define UART_PFIFO_RXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<0U))&0x7UL)             /*!< UART0_PFIFO.RXFIFOSIZE Field            */
#define UART_PFIFO_RXFE_MASK                     (0x8U)                                              /*!< UART0_PFIFO.RXFE Mask                   */
#define UART_PFIFO_RXFE_SHIFT                    (3U)                                                /*!< UART0_PFIFO.RXFE Position               */
#define UART_PFIFO_RXFE(x)                       (((uint8_t)(((uint8_t)(x))<<3U))&0x8UL)             /*!< UART0_PFIFO.RXFE Field                  */
#define UART_PFIFO_TXFIFOSIZE_MASK               (0x70U)                                             /*!< UART0_PFIFO.TXFIFOSIZE Mask             */
#define UART_PFIFO_TXFIFOSIZE_SHIFT              (4U)                                                /*!< UART0_PFIFO.TXFIFOSIZE Position         */
#define UART_PFIFO_TXFIFOSIZE(x)                 (((uint8_t)(((uint8_t)(x))<<4U))&0x70UL)            /*!< UART0_PFIFO.TXFIFOSIZE Field            */
#define UART_PFIFO_TXFE_MASK                     (0x80U)                                             /*!< UART0_PFIFO.TXFE Mask                   */
#define UART_PFIFO_TXFE_SHIFT                    (7U)                                                /*!< UART0_PFIFO.TXFE Position               */
#define UART_PFIFO_TXFE(x)                       (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_PFIFO.TXFE Field                  */
/* ------- CFIFO Bit Fields                         ------ */
#define UART_CFIFO_RXUFE_MASK                    (0x1U)                                              /*!< UART0_CFIFO.RXUFE Mask                  */
#define UART_CFIFO_RXUFE_SHIFT                   (0U)                                                /*!< UART0_CFIFO.RXUFE Position              */
#define UART_CFIFO_RXUFE(x)                      (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_CFIFO.RXUFE Field                 */
#define UART_CFIFO_TXOFE_MASK                    (0x2U)                                              /*!< UART0_CFIFO.TXOFE Mask                  */
#define UART_CFIFO_TXOFE_SHIFT                   (1U)                                                /*!< UART0_CFIFO.TXOFE Position              */
#define UART_CFIFO_TXOFE(x)                      (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< UART0_CFIFO.TXOFE Field                 */
#define UART_CFIFO_RXOFE_MASK                    (0x4U)                                              /*!< UART0_CFIFO.RXOFE Mask                  */
#define UART_CFIFO_RXOFE_SHIFT                   (2U)                                                /*!< UART0_CFIFO.RXOFE Position              */
#define UART_CFIFO_RXOFE(x)                      (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< UART0_CFIFO.RXOFE Field                 */
#define UART_CFIFO_RXFLUSH_MASK                  (0x40U)                                             /*!< UART0_CFIFO.RXFLUSH Mask                */
#define UART_CFIFO_RXFLUSH_SHIFT                 (6U)                                                /*!< UART0_CFIFO.RXFLUSH Position            */
#define UART_CFIFO_RXFLUSH(x)                    (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< UART0_CFIFO.RXFLUSH Field               */
#define UART_CFIFO_TXFLUSH_MASK                  (0x80U)                                             /*!< UART0_CFIFO.TXFLUSH Mask                */
#define UART_CFIFO_TXFLUSH_SHIFT                 (7U)                                                /*!< UART0_CFIFO.TXFLUSH Position            */
#define UART_CFIFO_TXFLUSH(x)                    (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_CFIFO.TXFLUSH Field               */
/* ------- SFIFO Bit Fields                         ------ */
#define UART_SFIFO_RXUF_MASK                     (0x1U)                                              /*!< UART0_SFIFO.RXUF Mask                   */
#define UART_SFIFO_RXUF_SHIFT                    (0U)                                                /*!< UART0_SFIFO.RXUF Position               */
#define UART_SFIFO_RXUF(x)                       (((uint8_t)(((uint8_t)(x))<<0U))&0x1UL)             /*!< UART0_SFIFO.RXUF Field                  */
#define UART_SFIFO_TXOF_MASK                     (0x2U)                                              /*!< UART0_SFIFO.TXOF Mask                   */
#define UART_SFIFO_TXOF_SHIFT                    (1U)                                                /*!< UART0_SFIFO.TXOF Position               */
#define UART_SFIFO_TXOF(x)                       (((uint8_t)(((uint8_t)(x))<<1U))&0x2UL)             /*!< UART0_SFIFO.TXOF Field                  */
#define UART_SFIFO_RXOF_MASK                     (0x4U)                                              /*!< UART0_SFIFO.RXOF Mask                   */
#define UART_SFIFO_RXOF_SHIFT                    (2U)                                                /*!< UART0_SFIFO.RXOF Position               */
#define UART_SFIFO_RXOF(x)                       (((uint8_t)(((uint8_t)(x))<<2U))&0x4UL)             /*!< UART0_SFIFO.RXOF Field                  */
#define UART_SFIFO_RXEMPT_MASK                   (0x40U)                                             /*!< UART0_SFIFO.RXEMPT Mask                 */
#define UART_SFIFO_RXEMPT_SHIFT                  (6U)                                                /*!< UART0_SFIFO.RXEMPT Position             */
#define UART_SFIFO_RXEMPT(x)                     (((uint8_t)(((uint8_t)(x))<<6U))&0x40UL)            /*!< UART0_SFIFO.RXEMPT Field                */
#define UART_SFIFO_TXEMPT_MASK                   (0x80U)                                             /*!< UART0_SFIFO.TXEMPT Mask                 */
#define UART_SFIFO_TXEMPT_SHIFT                  (7U)                                                /*!< UART0_SFIFO.TXEMPT Position             */
#define UART_SFIFO_TXEMPT(x)                     (((uint8_t)(((uint8_t)(x))<<7U))&0x80UL)            /*!< UART0_SFIFO.TXEMPT Field                */
/* ------- TWFIFO Bit Fields                        ------ */
#define UART_TWFIFO_TXWATER_MASK                 (0xFFU)                                             /*!< UART0_TWFIFO.TXWATER Mask               */
#define UART_TWFIFO_TXWATER_SHIFT                (0U)                                                /*!< UART0_TWFIFO.TXWATER Position           */
#define UART_TWFIFO_TXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< UART0_TWFIFO.TXWATER Field              */
/* ------- TCFIFO Bit Fields                        ------ */
#define UART_TCFIFO_TXCOUNT_MASK                 (0xFFU)                                             /*!< UART0_TCFIFO.TXCOUNT Mask               */
#define UART_TCFIFO_TXCOUNT_SHIFT                (0U)                                                /*!< UART0_TCFIFO.TXCOUNT Position           */
#define UART_TCFIFO_TXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< UART0_TCFIFO.TXCOUNT Field              */
/* ------- RWFIFO Bit Fields                        ------ */
#define UART_RWFIFO_RXWATER_MASK                 (0xFFU)                                             /*!< UART0_RWFIFO.RXWATER Mask               */
#define UART_RWFIFO_RXWATER_SHIFT                (0U)                                                /*!< UART0_RWFIFO.RXWATER Position           */
#define UART_RWFIFO_RXWATER(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< UART0_RWFIFO.RXWATER Field              */
/* ------- RCFIFO Bit Fields                        ------ */
#define UART_RCFIFO_RXCOUNT_MASK                 (0xFFU)                                             /*!< UART0_RCFIFO.RXCOUNT Mask               */
#define UART_RCFIFO_RXCOUNT_SHIFT                (0U)                                                /*!< UART0_RCFIFO.RXCOUNT Position           */
#define UART_RCFIFO_RXCOUNT(x)                   (((uint8_t)(((uint8_t)(x))<<0U))&0xFFUL)            /*!< UART0_RCFIFO.RXCOUNT Field              */
/**
 * @} */ /* End group UART_Register_Masks_GROUP 
 */

/* UART0 - Peripheral instance base addresses */
#define UART0_BasePtr                  0x4006A000UL //!< Peripheral base address
#define UART0                          ((UART_Type *) UART0_BasePtr) //!< Freescale base pointer
#define UART0_BASE_PTR                 (UART0) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup UART_Peripheral_access_layer_GROUP UART Peripheral Access Layer
* @brief C Struct for UART
* @{
*/

/* ================================================================================ */
/* ================           UART1 (derived from UART0)           ================ */
/* ================================================================================ */

/**
 * @brief Universal Asynchronous Receiver/Transmitter
 */

/* UART1 - Peripheral instance base addresses */
#define UART1_BasePtr                  0x4006B000UL //!< Peripheral base address
#define UART1                          ((UART_Type *) UART1_BasePtr) //!< Freescale base pointer
#define UART1_BASE_PTR                 (UART1) //!< Freescale style base pointer
/**
 * @} */ /* End group UART_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup WDOG_Peripheral_access_layer_GROUP WDOG Peripheral Access Layer
* @brief C Struct for WDOG
* @{
*/

/* ================================================================================ */
/* ================           WDOG (file:WDOG_MK)                  ================ */
/* ================================================================================ */

/**
 * @brief Watchdog Timer
 */
/**
* @addtogroup WDOG_structs_GROUP WDOG struct
* @brief Struct for WDOG
* @{
*/
typedef struct {                                /*       WDOG Structure                                               */
   __IO uint16_t  STCTRLH;                      /**< 0000: Status and Control Register High                             */
   __IO uint16_t  STCTRLL;                      /**< 0002: Status and Control Register Low                              */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  TOVAL;                     /**< 0004: Time-out Value Register High TOVALL:TOVALH                   */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint16_t  TOVALH;                 /**< 0004: Time-out Value Register High                                 */
         __IO uint16_t  TOVALL;                 /**< 0006: Time-out Value Register Low                                  */
      };
   };
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  WIN;                       /**< 0008: Window Register (WINL:WINH)                                  */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint16_t  WINH;                   /**< 0008: Window Register High                                         */
         __IO uint16_t  WINL;                   /**< 000A: Window Register Low                                          */
      };
   };
   __IO uint16_t  REFRESH;                      /**< 000C: Refresh Register                                             */
   __IO uint16_t  UNLOCK;                       /**< 000E: Unlock Register                                              */
   union {                                      /**< 0000: (size=0004)                                                  */
      __IO uint32_t  TMROUT;                    /**< 0010: Timer Output Register (TMROUTL:TMROUTH)                      */
      struct {                                  /**< 0000: (size=0004)                                                  */
         __IO uint16_t  TMROUTH;                /**< 0010: Timer Output Register High                                   */
         __IO uint16_t  TMROUTL;                /**< 0012: Timer Output Register Low                                    */
      };
   };
   __IO uint16_t  RSTCNT;                       /**< 0014: Reset Count Register                                         */
   __IO uint16_t  PRESC;                        /**< 0016: Prescaler Register                                           */
} WDOG_Type;

/**
 * @} */ /* End group WDOG_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'WDOG' Position & Mask macros                        ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup WDOG_Register_Masks_GROUP WDOG Register Masks
* @brief Register Masks for WDOG
* @{
*/
/* ------- STCTRLH Bit Fields                       ------ */
#define WDOG_STCTRLH_WDOGEN_MASK                 (0x1U)                                              /*!< WDOG_STCTRLH.WDOGEN Mask                */
#define WDOG_STCTRLH_WDOGEN_SHIFT                (0U)                                                /*!< WDOG_STCTRLH.WDOGEN Position            */
#define WDOG_STCTRLH_WDOGEN(x)                   (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< WDOG_STCTRLH.WDOGEN Field               */
#define WDOG_STCTRLH_CLKSRC_MASK                 (0x2U)                                              /*!< WDOG_STCTRLH.CLKSRC Mask                */
#define WDOG_STCTRLH_CLKSRC_SHIFT                (1U)                                                /*!< WDOG_STCTRLH.CLKSRC Position            */
#define WDOG_STCTRLH_CLKSRC(x)                   (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< WDOG_STCTRLH.CLKSRC Field               */
#define WDOG_STCTRLH_IRQRSTEN_MASK               (0x4U)                                              /*!< WDOG_STCTRLH.IRQRSTEN Mask              */
#define WDOG_STCTRLH_IRQRSTEN_SHIFT              (2U)                                                /*!< WDOG_STCTRLH.IRQRSTEN Position          */
#define WDOG_STCTRLH_IRQRSTEN(x)                 (((uint16_t)(((uint16_t)(x))<<2U))&0x4UL)           /*!< WDOG_STCTRLH.IRQRSTEN Field             */
#define WDOG_STCTRLH_WINEN_MASK                  (0x8U)                                              /*!< WDOG_STCTRLH.WINEN Mask                 */
#define WDOG_STCTRLH_WINEN_SHIFT                 (3U)                                                /*!< WDOG_STCTRLH.WINEN Position             */
#define WDOG_STCTRLH_WINEN(x)                    (((uint16_t)(((uint16_t)(x))<<3U))&0x8UL)           /*!< WDOG_STCTRLH.WINEN Field                */
#define WDOG_STCTRLH_ALLOWUPDATE_MASK            (0x10U)                                             /*!< WDOG_STCTRLH.ALLOWUPDATE Mask           */
#define WDOG_STCTRLH_ALLOWUPDATE_SHIFT           (4U)                                                /*!< WDOG_STCTRLH.ALLOWUPDATE Position       */
#define WDOG_STCTRLH_ALLOWUPDATE(x)              (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< WDOG_STCTRLH.ALLOWUPDATE Field          */
#define WDOG_STCTRLH_DBGEN_MASK                  (0x20U)                                             /*!< WDOG_STCTRLH.DBGEN Mask                 */
#define WDOG_STCTRLH_DBGEN_SHIFT                 (5U)                                                /*!< WDOG_STCTRLH.DBGEN Position             */
#define WDOG_STCTRLH_DBGEN(x)                    (((uint16_t)(((uint16_t)(x))<<5U))&0x20UL)          /*!< WDOG_STCTRLH.DBGEN Field                */
#define WDOG_STCTRLH_STOPEN_MASK                 (0x40U)                                             /*!< WDOG_STCTRLH.STOPEN Mask                */
#define WDOG_STCTRLH_STOPEN_SHIFT                (6U)                                                /*!< WDOG_STCTRLH.STOPEN Position            */
#define WDOG_STCTRLH_STOPEN(x)                   (((uint16_t)(((uint16_t)(x))<<6U))&0x40UL)          /*!< WDOG_STCTRLH.STOPEN Field               */
#define WDOG_STCTRLH_WAITEN_MASK                 (0x80U)                                             /*!< WDOG_STCTRLH.WAITEN Mask                */
#define WDOG_STCTRLH_WAITEN_SHIFT                (7U)                                                /*!< WDOG_STCTRLH.WAITEN Position            */
#define WDOG_STCTRLH_WAITEN(x)                   (((uint16_t)(((uint16_t)(x))<<7U))&0x80UL)          /*!< WDOG_STCTRLH.WAITEN Field               */
#define WDOG_STCTRLH_TESTWDOG_MASK               (0x400U)                                            /*!< WDOG_STCTRLH.TESTWDOG Mask              */
#define WDOG_STCTRLH_TESTWDOG_SHIFT              (10U)                                               /*!< WDOG_STCTRLH.TESTWDOG Position          */
#define WDOG_STCTRLH_TESTWDOG(x)                 (((uint16_t)(((uint16_t)(x))<<10U))&0x400UL)        /*!< WDOG_STCTRLH.TESTWDOG Field             */
#define WDOG_STCTRLH_TESTSEL_MASK                (0x800U)                                            /*!< WDOG_STCTRLH.TESTSEL Mask               */
#define WDOG_STCTRLH_TESTSEL_SHIFT               (11U)                                               /*!< WDOG_STCTRLH.TESTSEL Position           */
#define WDOG_STCTRLH_TESTSEL(x)                  (((uint16_t)(((uint16_t)(x))<<11U))&0x800UL)        /*!< WDOG_STCTRLH.TESTSEL Field              */
#define WDOG_STCTRLH_BYTESEL_MASK                (0x3000U)                                           /*!< WDOG_STCTRLH.BYTESEL Mask               */
#define WDOG_STCTRLH_BYTESEL_SHIFT               (12U)                                               /*!< WDOG_STCTRLH.BYTESEL Position           */
#define WDOG_STCTRLH_BYTESEL(x)                  (((uint16_t)(((uint16_t)(x))<<12U))&0x3000UL)       /*!< WDOG_STCTRLH.BYTESEL Field              */
#define WDOG_STCTRLH_DISTESTWDOG_MASK            (0x4000U)                                           /*!< WDOG_STCTRLH.DISTESTWDOG Mask           */
#define WDOG_STCTRLH_DISTESTWDOG_SHIFT           (14U)                                               /*!< WDOG_STCTRLH.DISTESTWDOG Position       */
#define WDOG_STCTRLH_DISTESTWDOG(x)              (((uint16_t)(((uint16_t)(x))<<14U))&0x4000UL)       /*!< WDOG_STCTRLH.DISTESTWDOG Field          */
/* ------- STCTRLL Bit Fields                       ------ */
#define WDOG_STCTRLL_INTFLG_MASK                 (0x8000U)                                           /*!< WDOG_STCTRLL.INTFLG Mask                */
#define WDOG_STCTRLL_INTFLG_SHIFT                (15U)                                               /*!< WDOG_STCTRLL.INTFLG Position            */
#define WDOG_STCTRLL_INTFLG(x)                   (((uint16_t)(((uint16_t)(x))<<15U))&0x8000UL)       /*!< WDOG_STCTRLL.INTFLG Field               */
/* ------- TOVAL Bit Fields                         ------ */
#define WDOG_TOVAL_TOVAL_MASK                    (0xFFFFFFFFU)                                       /*!< WDOG_TOVAL.TOVAL Mask                   */
#define WDOG_TOVAL_TOVAL_SHIFT                   (0U)                                                /*!< WDOG_TOVAL.TOVAL Position               */
#define WDOG_TOVAL_TOVAL(x)                      (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< WDOG_TOVAL.TOVAL Field                  */
/* ------- TOVALH Bit Fields                        ------ */
#define WDOG_TOVALH_TOVALHIGH_MASK               (0xFFFFU)                                           /*!< WDOG_TOVALH.TOVALHIGH Mask              */
#define WDOG_TOVALH_TOVALHIGH_SHIFT              (0U)                                                /*!< WDOG_TOVALH.TOVALHIGH Position          */
#define WDOG_TOVALH_TOVALHIGH(x)                 (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_TOVALH.TOVALHIGH Field             */
/* ------- TOVALL Bit Fields                        ------ */
#define WDOG_TOVALL_TOVALLOW_MASK                (0xFFFFU)                                           /*!< WDOG_TOVALL.TOVALLOW Mask               */
#define WDOG_TOVALL_TOVALLOW_SHIFT               (0U)                                                /*!< WDOG_TOVALL.TOVALLOW Position           */
#define WDOG_TOVALL_TOVALLOW(x)                  (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_TOVALL.TOVALLOW Field              */
/* ------- WIN Bit Fields                           ------ */
#define WDOG_WIN_WIN_MASK                        (0xFFFFFFFFU)                                       /*!< WDOG_WIN.WIN Mask                       */
#define WDOG_WIN_WIN_SHIFT                       (0U)                                                /*!< WDOG_WIN.WIN Position                   */
#define WDOG_WIN_WIN(x)                          (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< WDOG_WIN.WIN Field                      */
/* ------- WINH Bit Fields                          ------ */
#define WDOG_WINH_WINHIGH_MASK                   (0xFFFFU)                                           /*!< WDOG_WINH.WINHIGH Mask                  */
#define WDOG_WINH_WINHIGH_SHIFT                  (0U)                                                /*!< WDOG_WINH.WINHIGH Position              */
#define WDOG_WINH_WINHIGH(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_WINH.WINHIGH Field                 */
/* ------- WINL Bit Fields                          ------ */
#define WDOG_WINL_WINLOW_MASK                    (0xFFFFU)                                           /*!< WDOG_WINL.WINLOW Mask                   */
#define WDOG_WINL_WINLOW_SHIFT                   (0U)                                                /*!< WDOG_WINL.WINLOW Position               */
#define WDOG_WINL_WINLOW(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_WINL.WINLOW Field                  */
/* ------- REFRESH Bit Fields                       ------ */
#define WDOG_REFRESH_WDOGREFRESH_MASK            (0xFFFFU)                                           /*!< WDOG_REFRESH.WDOGREFRESH Mask           */
#define WDOG_REFRESH_WDOGREFRESH_SHIFT           (0U)                                                /*!< WDOG_REFRESH.WDOGREFRESH Position       */
#define WDOG_REFRESH_WDOGREFRESH(x)              (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_REFRESH.WDOGREFRESH Field          */
/* ------- UNLOCK Bit Fields                        ------ */
#define WDOG_UNLOCK_WDOGUNLOCK_MASK              (0xFFFFU)                                           /*!< WDOG_UNLOCK.WDOGUNLOCK Mask             */
#define WDOG_UNLOCK_WDOGUNLOCK_SHIFT             (0U)                                                /*!< WDOG_UNLOCK.WDOGUNLOCK Position         */
#define WDOG_UNLOCK_WDOGUNLOCK(x)                (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_UNLOCK.WDOGUNLOCK Field            */
/* ------- TMROUT Bit Fields                        ------ */
#define WDOG_TMROUT_TIMEROUTHIGH_MASK            (0xFFFFFFFFU)                                       /*!< WDOG_TMROUT.TIMEROUTHIGH Mask           */
#define WDOG_TMROUT_TIMEROUTHIGH_SHIFT           (0U)                                                /*!< WDOG_TMROUT.TIMEROUTHIGH Position       */
#define WDOG_TMROUT_TIMEROUTHIGH(x)              (((uint32_t)(((uint32_t)(x))<<0U))&0xFFFFFFFFUL)    /*!< WDOG_TMROUT.TIMEROUTHIGH Field          */
/* ------- TMROUTH Bit Fields                       ------ */
#define WDOG_TMROUTH_TIMEROUTHIGH_MASK           (0xFFFFU)                                           /*!< WDOG_TMROUTH.TIMEROUTHIGH Mask          */
#define WDOG_TMROUTH_TIMEROUTHIGH_SHIFT          (0U)                                                /*!< WDOG_TMROUTH.TIMEROUTHIGH Position      */
#define WDOG_TMROUTH_TIMEROUTHIGH(x)             (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_TMROUTH.TIMEROUTHIGH Field         */
/* ------- TMROUTL Bit Fields                       ------ */
#define WDOG_TMROUTL_TIMEROUTLOW_MASK            (0xFFFFU)                                           /*!< WDOG_TMROUTL.TIMEROUTLOW Mask           */
#define WDOG_TMROUTL_TIMEROUTLOW_SHIFT           (0U)                                                /*!< WDOG_TMROUTL.TIMEROUTLOW Position       */
#define WDOG_TMROUTL_TIMEROUTLOW(x)              (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_TMROUTL.TIMEROUTLOW Field          */
/* ------- RSTCNT Bit Fields                        ------ */
#define WDOG_RSTCNT_RSTCNT_MASK                  (0xFFFFU)                                           /*!< WDOG_RSTCNT.RSTCNT Mask                 */
#define WDOG_RSTCNT_RSTCNT_SHIFT                 (0U)                                                /*!< WDOG_RSTCNT.RSTCNT Position             */
#define WDOG_RSTCNT_RSTCNT(x)                    (((uint16_t)(((uint16_t)(x))<<0U))&0xFFFFUL)        /*!< WDOG_RSTCNT.RSTCNT Field                */
/* ------- PRESC Bit Fields                         ------ */
#define WDOG_PRESC_PRESCVAL_MASK                 (0x700U)                                            /*!< WDOG_PRESC.PRESCVAL Mask                */
#define WDOG_PRESC_PRESCVAL_SHIFT                (8U)                                                /*!< WDOG_PRESC.PRESCVAL Position            */
#define WDOG_PRESC_PRESCVAL(x)                   (((uint16_t)(((uint16_t)(x))<<8U))&0x700UL)         /*!< WDOG_PRESC.PRESCVAL Field               */
/**
 * @} */ /* End group WDOG_Register_Masks_GROUP 
 */

/* WDOG - Peripheral instance base addresses */
#define WDOG_BasePtr                   0x40052000UL //!< Peripheral base address
#define WDOG                           ((WDOG_Type *) WDOG_BasePtr) //!< Freescale base pointer
#define WDOG_BASE_PTR                  (WDOG) //!< Freescale style base pointer
/**
 * @} */ /* End group WDOG_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup XBARA_Peripheral_access_layer_GROUP XBARA Peripheral Access Layer
* @brief C Struct for XBARA
* @{
*/

/* ================================================================================ */
/* ================           XBARA (file:XBARA_MKV30)             ================ */
/* ================================================================================ */

/**
 * @brief Crossbar Switch
 */
/**
* @addtogroup XBARA_structs_GROUP XBARA struct
* @brief Struct for XBARA
* @{
*/
typedef struct {                                /*       XBARA Structure                                              */
   __IO uint16_t  SEL0;                         /**< 0000: Crossbar A Select Register 0                                 */
   __IO uint16_t  SEL1;                         /**< 0002: Crossbar A Select Register 1                                 */
   __IO uint16_t  SEL2;                         /**< 0004: Crossbar A Select Register 2                                 */
   __IO uint16_t  SEL3;                         /**< 0006: Crossbar A Select Register 3                                 */
   __IO uint16_t  SEL4;                         /**< 0008: Crossbar A Select Register 4                                 */
   __IO uint16_t  SEL5;                         /**< 000A: Crossbar A Select Register 5                                 */
   __IO uint16_t  SEL6;                         /**< 000C: Crossbar A Select Register 6                                 */
   __IO uint16_t  SEL7;                         /**< 000E: Crossbar A Select Register 7                                 */
   __IO uint16_t  SEL8;                         /**< 0010: Crossbar A Select Register 8                                 */
   __IO uint16_t  SEL9;                         /**< 0012: Crossbar A Select Register 9                                 */
   __IO uint16_t  SEL10;                        /**< 0014: Crossbar A Select Register 10                                */
   __IO uint16_t  SEL11;                        /**< 0016: Crossbar A Select Register 11                                */
   __IO uint16_t  SEL12;                        /**< 0018: Crossbar A Select Register 12                                */
   __IO uint16_t  SEL13;                        /**< 001A: Crossbar A Select Register 13                                */
   __IO uint16_t  SEL14;                        /**< 001C: Crossbar A Select Register 14                                */
   __IO uint16_t  SEL15;                        /**< 001E: Crossbar A Select Register 15                                */
   __IO uint16_t  SEL16;                        /**< 0020: Crossbar A Select Register 16                                */
   __IO uint16_t  SEL17;                        /**< 0022: Crossbar A Select Register 17                                */
   __IO uint16_t  SEL18;                        /**< 0024: Crossbar A Select Register 18                                */
   __IO uint16_t  SEL19;                        /**< 0026: Crossbar A Select Register 19                                */
   __IO uint16_t  SEL20;                        /**< 0028: Crossbar A Select Register 20                                */
   __IO uint16_t  SEL21;                        /**< 002A: Crossbar A Select Register 21                                */
   __IO uint16_t  SEL22;                        /**< 002C: Crossbar A Select Register 22                                */
   __IO uint16_t  SEL23;                        /**< 002E: Crossbar A Select Register 23                                */
   __IO uint16_t  SEL24;                        /**< 0030: Crossbar A Select Register 24                                */
   __IO uint16_t  SEL25;                        /**< 0032: Crossbar A Select Register 25                                */
   __IO uint16_t  SEL26;                        /**< 0034: Crossbar A Select Register 26                                */
   __IO uint16_t  SEL27;                        /**< 0036: Crossbar A Select Register 27                                */
   __IO uint16_t  SEL28;                        /**< 0038: Crossbar A Select Register 28                                */
   __IO uint16_t  SEL29;                        /**< 003A: Crossbar A Select Register 29                                */
   __IO uint16_t  CTRL0;                        /**< 003C: Crossbar A Control Register 0                                */
   __IO uint16_t  CTRL1;                        /**< 003E: Crossbar A Control Register 1                                */
} XBARA_Type;

/**
 * @} */ /* End group XBARA_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'XBARA' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup XBARA_Register_Masks_GROUP XBARA Register Masks
* @brief Register Masks for XBARA
* @{
*/
/* ------- SEL0 Bit Fields                          ------ */
#define XBARA_SEL0_SEL0_MASK                     (0x3FU)                                             /*!< XBARA_SEL0.SEL0 Mask                    */
#define XBARA_SEL0_SEL0_SHIFT                    (0U)                                                /*!< XBARA_SEL0.SEL0 Position                */
#define XBARA_SEL0_SEL0(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL0.SEL0 Field                   */
#define XBARA_SEL0_SEL1_MASK                     (0x3F00U)                                           /*!< XBARA_SEL0.SEL1 Mask                    */
#define XBARA_SEL0_SEL1_SHIFT                    (8U)                                                /*!< XBARA_SEL0.SEL1 Position                */
#define XBARA_SEL0_SEL1(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL0.SEL1 Field                   */
/* ------- SEL1 Bit Fields                          ------ */
#define XBARA_SEL1_SEL2_MASK                     (0x3FU)                                             /*!< XBARA_SEL1.SEL2 Mask                    */
#define XBARA_SEL1_SEL2_SHIFT                    (0U)                                                /*!< XBARA_SEL1.SEL2 Position                */
#define XBARA_SEL1_SEL2(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL1.SEL2 Field                   */
#define XBARA_SEL1_SEL3_MASK                     (0x3F00U)                                           /*!< XBARA_SEL1.SEL3 Mask                    */
#define XBARA_SEL1_SEL3_SHIFT                    (8U)                                                /*!< XBARA_SEL1.SEL3 Position                */
#define XBARA_SEL1_SEL3(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL1.SEL3 Field                   */
/* ------- SEL2 Bit Fields                          ------ */
#define XBARA_SEL2_SEL4_MASK                     (0x3FU)                                             /*!< XBARA_SEL2.SEL4 Mask                    */
#define XBARA_SEL2_SEL4_SHIFT                    (0U)                                                /*!< XBARA_SEL2.SEL4 Position                */
#define XBARA_SEL2_SEL4(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL2.SEL4 Field                   */
#define XBARA_SEL2_SEL5_MASK                     (0x3F00U)                                           /*!< XBARA_SEL2.SEL5 Mask                    */
#define XBARA_SEL2_SEL5_SHIFT                    (8U)                                                /*!< XBARA_SEL2.SEL5 Position                */
#define XBARA_SEL2_SEL5(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL2.SEL5 Field                   */
/* ------- SEL3 Bit Fields                          ------ */
#define XBARA_SEL3_SEL6_MASK                     (0x3FU)                                             /*!< XBARA_SEL3.SEL6 Mask                    */
#define XBARA_SEL3_SEL6_SHIFT                    (0U)                                                /*!< XBARA_SEL3.SEL6 Position                */
#define XBARA_SEL3_SEL6(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL3.SEL6 Field                   */
#define XBARA_SEL3_SEL7_MASK                     (0x3F00U)                                           /*!< XBARA_SEL3.SEL7 Mask                    */
#define XBARA_SEL3_SEL7_SHIFT                    (8U)                                                /*!< XBARA_SEL3.SEL7 Position                */
#define XBARA_SEL3_SEL7(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL3.SEL7 Field                   */
/* ------- SEL4 Bit Fields                          ------ */
#define XBARA_SEL4_SEL8_MASK                     (0x3FU)                                             /*!< XBARA_SEL4.SEL8 Mask                    */
#define XBARA_SEL4_SEL8_SHIFT                    (0U)                                                /*!< XBARA_SEL4.SEL8 Position                */
#define XBARA_SEL4_SEL8(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL4.SEL8 Field                   */
#define XBARA_SEL4_SEL9_MASK                     (0x3F00U)                                           /*!< XBARA_SEL4.SEL9 Mask                    */
#define XBARA_SEL4_SEL9_SHIFT                    (8U)                                                /*!< XBARA_SEL4.SEL9 Position                */
#define XBARA_SEL4_SEL9(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL4.SEL9 Field                   */
/* ------- SEL5 Bit Fields                          ------ */
#define XBARA_SEL5_SEL10_MASK                    (0x3FU)                                             /*!< XBARA_SEL5.SEL10 Mask                   */
#define XBARA_SEL5_SEL10_SHIFT                   (0U)                                                /*!< XBARA_SEL5.SEL10 Position               */
#define XBARA_SEL5_SEL10(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL5.SEL10 Field                  */
#define XBARA_SEL5_SEL11_MASK                    (0x3F00U)                                           /*!< XBARA_SEL5.SEL11 Mask                   */
#define XBARA_SEL5_SEL11_SHIFT                   (8U)                                                /*!< XBARA_SEL5.SEL11 Position               */
#define XBARA_SEL5_SEL11(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL5.SEL11 Field                  */
/* ------- SEL6 Bit Fields                          ------ */
#define XBARA_SEL6_SEL12_MASK                    (0x3FU)                                             /*!< XBARA_SEL6.SEL12 Mask                   */
#define XBARA_SEL6_SEL12_SHIFT                   (0U)                                                /*!< XBARA_SEL6.SEL12 Position               */
#define XBARA_SEL6_SEL12(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL6.SEL12 Field                  */
#define XBARA_SEL6_SEL13_MASK                    (0x3F00U)                                           /*!< XBARA_SEL6.SEL13 Mask                   */
#define XBARA_SEL6_SEL13_SHIFT                   (8U)                                                /*!< XBARA_SEL6.SEL13 Position               */
#define XBARA_SEL6_SEL13(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL6.SEL13 Field                  */
/* ------- SEL7 Bit Fields                          ------ */
#define XBARA_SEL7_SEL14_MASK                    (0x3FU)                                             /*!< XBARA_SEL7.SEL14 Mask                   */
#define XBARA_SEL7_SEL14_SHIFT                   (0U)                                                /*!< XBARA_SEL7.SEL14 Position               */
#define XBARA_SEL7_SEL14(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL7.SEL14 Field                  */
#define XBARA_SEL7_SEL15_MASK                    (0x3F00U)                                           /*!< XBARA_SEL7.SEL15 Mask                   */
#define XBARA_SEL7_SEL15_SHIFT                   (8U)                                                /*!< XBARA_SEL7.SEL15 Position               */
#define XBARA_SEL7_SEL15(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL7.SEL15 Field                  */
/* ------- SEL8 Bit Fields                          ------ */
#define XBARA_SEL8_SEL16_MASK                    (0x3FU)                                             /*!< XBARA_SEL8.SEL16 Mask                   */
#define XBARA_SEL8_SEL16_SHIFT                   (0U)                                                /*!< XBARA_SEL8.SEL16 Position               */
#define XBARA_SEL8_SEL16(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL8.SEL16 Field                  */
#define XBARA_SEL8_SEL17_MASK                    (0x3F00U)                                           /*!< XBARA_SEL8.SEL17 Mask                   */
#define XBARA_SEL8_SEL17_SHIFT                   (8U)                                                /*!< XBARA_SEL8.SEL17 Position               */
#define XBARA_SEL8_SEL17(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL8.SEL17 Field                  */
/* ------- SEL9 Bit Fields                          ------ */
#define XBARA_SEL9_SEL18_MASK                    (0x3FU)                                             /*!< XBARA_SEL9.SEL18 Mask                   */
#define XBARA_SEL9_SEL18_SHIFT                   (0U)                                                /*!< XBARA_SEL9.SEL18 Position               */
#define XBARA_SEL9_SEL18(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL9.SEL18 Field                  */
#define XBARA_SEL9_SEL19_MASK                    (0x3F00U)                                           /*!< XBARA_SEL9.SEL19 Mask                   */
#define XBARA_SEL9_SEL19_SHIFT                   (8U)                                                /*!< XBARA_SEL9.SEL19 Position               */
#define XBARA_SEL9_SEL19(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL9.SEL19 Field                  */
/* ------- SEL10 Bit Fields                         ------ */
#define XBARA_SEL10_SEL20_MASK                   (0x3FU)                                             /*!< XBARA_SEL10.SEL20 Mask                  */
#define XBARA_SEL10_SEL20_SHIFT                  (0U)                                                /*!< XBARA_SEL10.SEL20 Position              */
#define XBARA_SEL10_SEL20(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL10.SEL20 Field                 */
#define XBARA_SEL10_SEL21_MASK                   (0x3F00U)                                           /*!< XBARA_SEL10.SEL21 Mask                  */
#define XBARA_SEL10_SEL21_SHIFT                  (8U)                                                /*!< XBARA_SEL10.SEL21 Position              */
#define XBARA_SEL10_SEL21(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL10.SEL21 Field                 */
/* ------- SEL11 Bit Fields                         ------ */
#define XBARA_SEL11_SEL22_MASK                   (0x3FU)                                             /*!< XBARA_SEL11.SEL22 Mask                  */
#define XBARA_SEL11_SEL22_SHIFT                  (0U)                                                /*!< XBARA_SEL11.SEL22 Position              */
#define XBARA_SEL11_SEL22(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL11.SEL22 Field                 */
#define XBARA_SEL11_SEL23_MASK                   (0x3F00U)                                           /*!< XBARA_SEL11.SEL23 Mask                  */
#define XBARA_SEL11_SEL23_SHIFT                  (8U)                                                /*!< XBARA_SEL11.SEL23 Position              */
#define XBARA_SEL11_SEL23(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL11.SEL23 Field                 */
/* ------- SEL12 Bit Fields                         ------ */
#define XBARA_SEL12_SEL24_MASK                   (0x3FU)                                             /*!< XBARA_SEL12.SEL24 Mask                  */
#define XBARA_SEL12_SEL24_SHIFT                  (0U)                                                /*!< XBARA_SEL12.SEL24 Position              */
#define XBARA_SEL12_SEL24(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL12.SEL24 Field                 */
#define XBARA_SEL12_SEL25_MASK                   (0x3F00U)                                           /*!< XBARA_SEL12.SEL25 Mask                  */
#define XBARA_SEL12_SEL25_SHIFT                  (8U)                                                /*!< XBARA_SEL12.SEL25 Position              */
#define XBARA_SEL12_SEL25(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL12.SEL25 Field                 */
/* ------- SEL13 Bit Fields                         ------ */
#define XBARA_SEL13_SEL26_MASK                   (0x3FU)                                             /*!< XBARA_SEL13.SEL26 Mask                  */
#define XBARA_SEL13_SEL26_SHIFT                  (0U)                                                /*!< XBARA_SEL13.SEL26 Position              */
#define XBARA_SEL13_SEL26(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL13.SEL26 Field                 */
#define XBARA_SEL13_SEL27_MASK                   (0x3F00U)                                           /*!< XBARA_SEL13.SEL27 Mask                  */
#define XBARA_SEL13_SEL27_SHIFT                  (8U)                                                /*!< XBARA_SEL13.SEL27 Position              */
#define XBARA_SEL13_SEL27(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL13.SEL27 Field                 */
/* ------- SEL14 Bit Fields                         ------ */
#define XBARA_SEL14_SEL28_MASK                   (0x3FU)                                             /*!< XBARA_SEL14.SEL28 Mask                  */
#define XBARA_SEL14_SEL28_SHIFT                  (0U)                                                /*!< XBARA_SEL14.SEL28 Position              */
#define XBARA_SEL14_SEL28(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL14.SEL28 Field                 */
#define XBARA_SEL14_SEL29_MASK                   (0x3F00U)                                           /*!< XBARA_SEL14.SEL29 Mask                  */
#define XBARA_SEL14_SEL29_SHIFT                  (8U)                                                /*!< XBARA_SEL14.SEL29 Position              */
#define XBARA_SEL14_SEL29(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL14.SEL29 Field                 */
/* ------- SEL15 Bit Fields                         ------ */
#define XBARA_SEL15_SEL30_MASK                   (0x3FU)                                             /*!< XBARA_SEL15.SEL30 Mask                  */
#define XBARA_SEL15_SEL30_SHIFT                  (0U)                                                /*!< XBARA_SEL15.SEL30 Position              */
#define XBARA_SEL15_SEL30(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL15.SEL30 Field                 */
#define XBARA_SEL15_SEL31_MASK                   (0x3F00U)                                           /*!< XBARA_SEL15.SEL31 Mask                  */
#define XBARA_SEL15_SEL31_SHIFT                  (8U)                                                /*!< XBARA_SEL15.SEL31 Position              */
#define XBARA_SEL15_SEL31(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL15.SEL31 Field                 */
/* ------- SEL16 Bit Fields                         ------ */
#define XBARA_SEL16_SEL32_MASK                   (0x3FU)                                             /*!< XBARA_SEL16.SEL32 Mask                  */
#define XBARA_SEL16_SEL32_SHIFT                  (0U)                                                /*!< XBARA_SEL16.SEL32 Position              */
#define XBARA_SEL16_SEL32(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL16.SEL32 Field                 */
#define XBARA_SEL16_SEL33_MASK                   (0x3F00U)                                           /*!< XBARA_SEL16.SEL33 Mask                  */
#define XBARA_SEL16_SEL33_SHIFT                  (8U)                                                /*!< XBARA_SEL16.SEL33 Position              */
#define XBARA_SEL16_SEL33(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL16.SEL33 Field                 */
/* ------- SEL17 Bit Fields                         ------ */
#define XBARA_SEL17_SEL34_MASK                   (0x3FU)                                             /*!< XBARA_SEL17.SEL34 Mask                  */
#define XBARA_SEL17_SEL34_SHIFT                  (0U)                                                /*!< XBARA_SEL17.SEL34 Position              */
#define XBARA_SEL17_SEL34(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL17.SEL34 Field                 */
#define XBARA_SEL17_SEL35_MASK                   (0x3F00U)                                           /*!< XBARA_SEL17.SEL35 Mask                  */
#define XBARA_SEL17_SEL35_SHIFT                  (8U)                                                /*!< XBARA_SEL17.SEL35 Position              */
#define XBARA_SEL17_SEL35(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL17.SEL35 Field                 */
/* ------- SEL18 Bit Fields                         ------ */
#define XBARA_SEL18_SEL36_MASK                   (0x3FU)                                             /*!< XBARA_SEL18.SEL36 Mask                  */
#define XBARA_SEL18_SEL36_SHIFT                  (0U)                                                /*!< XBARA_SEL18.SEL36 Position              */
#define XBARA_SEL18_SEL36(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL18.SEL36 Field                 */
#define XBARA_SEL18_SEL37_MASK                   (0x3F00U)                                           /*!< XBARA_SEL18.SEL37 Mask                  */
#define XBARA_SEL18_SEL37_SHIFT                  (8U)                                                /*!< XBARA_SEL18.SEL37 Position              */
#define XBARA_SEL18_SEL37(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL18.SEL37 Field                 */
/* ------- SEL19 Bit Fields                         ------ */
#define XBARA_SEL19_SEL38_MASK                   (0x3FU)                                             /*!< XBARA_SEL19.SEL38 Mask                  */
#define XBARA_SEL19_SEL38_SHIFT                  (0U)                                                /*!< XBARA_SEL19.SEL38 Position              */
#define XBARA_SEL19_SEL38(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL19.SEL38 Field                 */
#define XBARA_SEL19_SEL39_MASK                   (0x3F00U)                                           /*!< XBARA_SEL19.SEL39 Mask                  */
#define XBARA_SEL19_SEL39_SHIFT                  (8U)                                                /*!< XBARA_SEL19.SEL39 Position              */
#define XBARA_SEL19_SEL39(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL19.SEL39 Field                 */
/* ------- SEL20 Bit Fields                         ------ */
#define XBARA_SEL20_SEL40_MASK                   (0x3FU)                                             /*!< XBARA_SEL20.SEL40 Mask                  */
#define XBARA_SEL20_SEL40_SHIFT                  (0U)                                                /*!< XBARA_SEL20.SEL40 Position              */
#define XBARA_SEL20_SEL40(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL20.SEL40 Field                 */
#define XBARA_SEL20_SEL41_MASK                   (0x3F00U)                                           /*!< XBARA_SEL20.SEL41 Mask                  */
#define XBARA_SEL20_SEL41_SHIFT                  (8U)                                                /*!< XBARA_SEL20.SEL41 Position              */
#define XBARA_SEL20_SEL41(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL20.SEL41 Field                 */
/* ------- SEL21 Bit Fields                         ------ */
#define XBARA_SEL21_SEL42_MASK                   (0x3FU)                                             /*!< XBARA_SEL21.SEL42 Mask                  */
#define XBARA_SEL21_SEL42_SHIFT                  (0U)                                                /*!< XBARA_SEL21.SEL42 Position              */
#define XBARA_SEL21_SEL42(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL21.SEL42 Field                 */
#define XBARA_SEL21_SEL43_MASK                   (0x3F00U)                                           /*!< XBARA_SEL21.SEL43 Mask                  */
#define XBARA_SEL21_SEL43_SHIFT                  (8U)                                                /*!< XBARA_SEL21.SEL43 Position              */
#define XBARA_SEL21_SEL43(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL21.SEL43 Field                 */
/* ------- SEL22 Bit Fields                         ------ */
#define XBARA_SEL22_SEL44_MASK                   (0x3FU)                                             /*!< XBARA_SEL22.SEL44 Mask                  */
#define XBARA_SEL22_SEL44_SHIFT                  (0U)                                                /*!< XBARA_SEL22.SEL44 Position              */
#define XBARA_SEL22_SEL44(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL22.SEL44 Field                 */
#define XBARA_SEL22_SEL45_MASK                   (0x3F00U)                                           /*!< XBARA_SEL22.SEL45 Mask                  */
#define XBARA_SEL22_SEL45_SHIFT                  (8U)                                                /*!< XBARA_SEL22.SEL45 Position              */
#define XBARA_SEL22_SEL45(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL22.SEL45 Field                 */
/* ------- SEL23 Bit Fields                         ------ */
#define XBARA_SEL23_SEL46_MASK                   (0x3FU)                                             /*!< XBARA_SEL23.SEL46 Mask                  */
#define XBARA_SEL23_SEL46_SHIFT                  (0U)                                                /*!< XBARA_SEL23.SEL46 Position              */
#define XBARA_SEL23_SEL46(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL23.SEL46 Field                 */
#define XBARA_SEL23_SEL47_MASK                   (0x3F00U)                                           /*!< XBARA_SEL23.SEL47 Mask                  */
#define XBARA_SEL23_SEL47_SHIFT                  (8U)                                                /*!< XBARA_SEL23.SEL47 Position              */
#define XBARA_SEL23_SEL47(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL23.SEL47 Field                 */
/* ------- SEL24 Bit Fields                         ------ */
#define XBARA_SEL24_SEL48_MASK                   (0x3FU)                                             /*!< XBARA_SEL24.SEL48 Mask                  */
#define XBARA_SEL24_SEL48_SHIFT                  (0U)                                                /*!< XBARA_SEL24.SEL48 Position              */
#define XBARA_SEL24_SEL48(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL24.SEL48 Field                 */
#define XBARA_SEL24_SEL49_MASK                   (0x3F00U)                                           /*!< XBARA_SEL24.SEL49 Mask                  */
#define XBARA_SEL24_SEL49_SHIFT                  (8U)                                                /*!< XBARA_SEL24.SEL49 Position              */
#define XBARA_SEL24_SEL49(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL24.SEL49 Field                 */
/* ------- SEL25 Bit Fields                         ------ */
#define XBARA_SEL25_SEL50_MASK                   (0x3FU)                                             /*!< XBARA_SEL25.SEL50 Mask                  */
#define XBARA_SEL25_SEL50_SHIFT                  (0U)                                                /*!< XBARA_SEL25.SEL50 Position              */
#define XBARA_SEL25_SEL50(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL25.SEL50 Field                 */
#define XBARA_SEL25_SEL51_MASK                   (0x3F00U)                                           /*!< XBARA_SEL25.SEL51 Mask                  */
#define XBARA_SEL25_SEL51_SHIFT                  (8U)                                                /*!< XBARA_SEL25.SEL51 Position              */
#define XBARA_SEL25_SEL51(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL25.SEL51 Field                 */
/* ------- SEL26 Bit Fields                         ------ */
#define XBARA_SEL26_SEL52_MASK                   (0x3FU)                                             /*!< XBARA_SEL26.SEL52 Mask                  */
#define XBARA_SEL26_SEL52_SHIFT                  (0U)                                                /*!< XBARA_SEL26.SEL52 Position              */
#define XBARA_SEL26_SEL52(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL26.SEL52 Field                 */
#define XBARA_SEL26_SEL53_MASK                   (0x3F00U)                                           /*!< XBARA_SEL26.SEL53 Mask                  */
#define XBARA_SEL26_SEL53_SHIFT                  (8U)                                                /*!< XBARA_SEL26.SEL53 Position              */
#define XBARA_SEL26_SEL53(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL26.SEL53 Field                 */
/* ------- SEL27 Bit Fields                         ------ */
#define XBARA_SEL27_SEL54_MASK                   (0x3FU)                                             /*!< XBARA_SEL27.SEL54 Mask                  */
#define XBARA_SEL27_SEL54_SHIFT                  (0U)                                                /*!< XBARA_SEL27.SEL54 Position              */
#define XBARA_SEL27_SEL54(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL27.SEL54 Field                 */
#define XBARA_SEL27_SEL55_MASK                   (0x3F00U)                                           /*!< XBARA_SEL27.SEL55 Mask                  */
#define XBARA_SEL27_SEL55_SHIFT                  (8U)                                                /*!< XBARA_SEL27.SEL55 Position              */
#define XBARA_SEL27_SEL55(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL27.SEL55 Field                 */
/* ------- SEL28 Bit Fields                         ------ */
#define XBARA_SEL28_SEL56_MASK                   (0x3FU)                                             /*!< XBARA_SEL28.SEL56 Mask                  */
#define XBARA_SEL28_SEL56_SHIFT                  (0U)                                                /*!< XBARA_SEL28.SEL56 Position              */
#define XBARA_SEL28_SEL56(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL28.SEL56 Field                 */
#define XBARA_SEL28_SEL57_MASK                   (0x3F00U)                                           /*!< XBARA_SEL28.SEL57 Mask                  */
#define XBARA_SEL28_SEL57_SHIFT                  (8U)                                                /*!< XBARA_SEL28.SEL57 Position              */
#define XBARA_SEL28_SEL57(x)                     (((uint16_t)(((uint16_t)(x))<<8U))&0x3F00UL)        /*!< XBARA_SEL28.SEL57 Field                 */
/* ------- SEL29 Bit Fields                         ------ */
#define XBARA_SEL29_SEL58_MASK                   (0x3FU)                                             /*!< XBARA_SEL29.SEL58 Mask                  */
#define XBARA_SEL29_SEL58_SHIFT                  (0U)                                                /*!< XBARA_SEL29.SEL58 Position              */
#define XBARA_SEL29_SEL58(x)                     (((uint16_t)(((uint16_t)(x))<<0U))&0x3FUL)          /*!< XBARA_SEL29.SEL58 Field                 */
/* ------- CTRL0 Bit Fields                         ------ */
#define XBARA_CTRL0_DEN0_MASK                    (0x1U)                                              /*!< XBARA_CTRL0.DEN0 Mask                   */
#define XBARA_CTRL0_DEN0_SHIFT                   (0U)                                                /*!< XBARA_CTRL0.DEN0 Position               */
#define XBARA_CTRL0_DEN0(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< XBARA_CTRL0.DEN0 Field                  */
#define XBARA_CTRL0_IEN0_MASK                    (0x2U)                                              /*!< XBARA_CTRL0.IEN0 Mask                   */
#define XBARA_CTRL0_IEN0_SHIFT                   (1U)                                                /*!< XBARA_CTRL0.IEN0 Position               */
#define XBARA_CTRL0_IEN0(x)                      (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< XBARA_CTRL0.IEN0 Field                  */
#define XBARA_CTRL0_EDGE0_MASK                   (0xCU)                                              /*!< XBARA_CTRL0.EDGE0 Mask                  */
#define XBARA_CTRL0_EDGE0_SHIFT                  (2U)                                                /*!< XBARA_CTRL0.EDGE0 Position              */
#define XBARA_CTRL0_EDGE0(x)                     (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< XBARA_CTRL0.EDGE0 Field                 */
#define XBARA_CTRL0_STS0_MASK                    (0x10U)                                             /*!< XBARA_CTRL0.STS0 Mask                   */
#define XBARA_CTRL0_STS0_SHIFT                   (4U)                                                /*!< XBARA_CTRL0.STS0 Position               */
#define XBARA_CTRL0_STS0(x)                      (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< XBARA_CTRL0.STS0 Field                  */
#define XBARA_CTRL0_DEN1_MASK                    (0x100U)                                            /*!< XBARA_CTRL0.DEN1 Mask                   */
#define XBARA_CTRL0_DEN1_SHIFT                   (8U)                                                /*!< XBARA_CTRL0.DEN1 Position               */
#define XBARA_CTRL0_DEN1(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x100UL)         /*!< XBARA_CTRL0.DEN1 Field                  */
#define XBARA_CTRL0_IEN1_MASK                    (0x200U)                                            /*!< XBARA_CTRL0.IEN1 Mask                   */
#define XBARA_CTRL0_IEN1_SHIFT                   (9U)                                                /*!< XBARA_CTRL0.IEN1 Position               */
#define XBARA_CTRL0_IEN1(x)                      (((uint16_t)(((uint16_t)(x))<<9U))&0x200UL)         /*!< XBARA_CTRL0.IEN1 Field                  */
#define XBARA_CTRL0_EDGE1_MASK                   (0xC00U)                                            /*!< XBARA_CTRL0.EDGE1 Mask                  */
#define XBARA_CTRL0_EDGE1_SHIFT                  (10U)                                               /*!< XBARA_CTRL0.EDGE1 Position              */
#define XBARA_CTRL0_EDGE1(x)                     (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< XBARA_CTRL0.EDGE1 Field                 */
#define XBARA_CTRL0_STS1_MASK                    (0x1000U)                                           /*!< XBARA_CTRL0.STS1 Mask                   */
#define XBARA_CTRL0_STS1_SHIFT                   (12U)                                               /*!< XBARA_CTRL0.STS1 Position               */
#define XBARA_CTRL0_STS1(x)                      (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< XBARA_CTRL0.STS1 Field                  */
/* ------- CTRL1 Bit Fields                         ------ */
#define XBARA_CTRL1_DEN2_MASK                    (0x1U)                                              /*!< XBARA_CTRL1.DEN2 Mask                   */
#define XBARA_CTRL1_DEN2_SHIFT                   (0U)                                                /*!< XBARA_CTRL1.DEN2 Position               */
#define XBARA_CTRL1_DEN2(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0x1UL)           /*!< XBARA_CTRL1.DEN2 Field                  */
#define XBARA_CTRL1_IEN2_MASK                    (0x2U)                                              /*!< XBARA_CTRL1.IEN2 Mask                   */
#define XBARA_CTRL1_IEN2_SHIFT                   (1U)                                                /*!< XBARA_CTRL1.IEN2 Position               */
#define XBARA_CTRL1_IEN2(x)                      (((uint16_t)(((uint16_t)(x))<<1U))&0x2UL)           /*!< XBARA_CTRL1.IEN2 Field                  */
#define XBARA_CTRL1_EDGE2_MASK                   (0xCU)                                              /*!< XBARA_CTRL1.EDGE2 Mask                  */
#define XBARA_CTRL1_EDGE2_SHIFT                  (2U)                                                /*!< XBARA_CTRL1.EDGE2 Position              */
#define XBARA_CTRL1_EDGE2(x)                     (((uint16_t)(((uint16_t)(x))<<2U))&0xCUL)           /*!< XBARA_CTRL1.EDGE2 Field                 */
#define XBARA_CTRL1_STS2_MASK                    (0x10U)                                             /*!< XBARA_CTRL1.STS2 Mask                   */
#define XBARA_CTRL1_STS2_SHIFT                   (4U)                                                /*!< XBARA_CTRL1.STS2 Position               */
#define XBARA_CTRL1_STS2(x)                      (((uint16_t)(((uint16_t)(x))<<4U))&0x10UL)          /*!< XBARA_CTRL1.STS2 Field                  */
#define XBARA_CTRL1_DEN3_MASK                    (0x100U)                                            /*!< XBARA_CTRL1.DEN3 Mask                   */
#define XBARA_CTRL1_DEN3_SHIFT                   (8U)                                                /*!< XBARA_CTRL1.DEN3 Position               */
#define XBARA_CTRL1_DEN3(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x100UL)         /*!< XBARA_CTRL1.DEN3 Field                  */
#define XBARA_CTRL1_IEN3_MASK                    (0x200U)                                            /*!< XBARA_CTRL1.IEN3 Mask                   */
#define XBARA_CTRL1_IEN3_SHIFT                   (9U)                                                /*!< XBARA_CTRL1.IEN3 Position               */
#define XBARA_CTRL1_IEN3(x)                      (((uint16_t)(((uint16_t)(x))<<9U))&0x200UL)         /*!< XBARA_CTRL1.IEN3 Field                  */
#define XBARA_CTRL1_EDGE3_MASK                   (0xC00U)                                            /*!< XBARA_CTRL1.EDGE3 Mask                  */
#define XBARA_CTRL1_EDGE3_SHIFT                  (10U)                                               /*!< XBARA_CTRL1.EDGE3 Position              */
#define XBARA_CTRL1_EDGE3(x)                     (((uint16_t)(((uint16_t)(x))<<10U))&0xC00UL)        /*!< XBARA_CTRL1.EDGE3 Field                 */
#define XBARA_CTRL1_STS3_MASK                    (0x1000U)                                           /*!< XBARA_CTRL1.STS3 Mask                   */
#define XBARA_CTRL1_STS3_SHIFT                   (12U)                                               /*!< XBARA_CTRL1.STS3 Position               */
#define XBARA_CTRL1_STS3(x)                      (((uint16_t)(((uint16_t)(x))<<12U))&0x1000UL)       /*!< XBARA_CTRL1.STS3 Field                  */
/**
 * @} */ /* End group XBARA_Register_Masks_GROUP 
 */

/* XBARA - Peripheral instance base addresses */
#define XBARA_BasePtr                  0x40059000UL //!< Peripheral base address
#define XBARA                          ((XBARA_Type *) XBARA_BasePtr) //!< Freescale base pointer
#define XBARA_BASE_PTR                 (XBARA) //!< Freescale style base pointer
/**
 * @} */ /* End group XBARA_Peripheral_access_layer_GROUP 
 */
/**
* @addtogroup XBARB_Peripheral_access_layer_GROUP XBARB Peripheral Access Layer
* @brief C Struct for XBARB
* @{
*/

/* ================================================================================ */
/* ================           XBARB (file:XBARB_MKV40)             ================ */
/* ================================================================================ */

/**
 * @brief Crossbar Switch
 */
/**
* @addtogroup XBARB_structs_GROUP XBARB struct
* @brief Struct for XBARB
* @{
*/
typedef struct {                                /*       XBARB Structure                                              */
   __IO uint16_t  SEL0;                         /**< 0000: Crossbar B Select Register 0                                 */
   __IO uint16_t  SEL1;                         /**< 0002: Crossbar B Select Register 1                                 */
   __IO uint16_t  SEL2;                         /**< 0004: Crossbar B Select Register 2                                 */
   __IO uint16_t  SEL3;                         /**< 0006: Crossbar B Select Register 3                                 */
   __IO uint16_t  SEL4;                         /**< 0008: Crossbar B Select Register 4                                 */
   __IO uint16_t  SEL5;                         /**< 000A: Crossbar B Select Register 5                                 */
   __IO uint16_t  SEL6;                         /**< 000C: Crossbar B Select Register 6                                 */
   __IO uint16_t  SEL7;                         /**< 000E: Crossbar B Select Register 7                                 */
} XBARB_Type;

/**
 * @} */ /* End group XBARB_structs_GROUP 
 */

/* -------------------------------------------------------------------------------- */
/* -----------     'XBARB' Position & Mask macros                       ----------- */
/* -------------------------------------------------------------------------------- */

/**
* @addtogroup XBARB_Register_Masks_GROUP XBARB Register Masks
* @brief Register Masks for XBARB
* @{
*/
/* ------- SEL0 Bit Fields                          ------ */
#define XBARB_SEL0_SEL0_MASK                     (0x1FU)                                             /*!< XBARB_SEL0.SEL0 Mask                    */
#define XBARB_SEL0_SEL0_SHIFT                    (0U)                                                /*!< XBARB_SEL0.SEL0 Position                */
#define XBARB_SEL0_SEL0(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x1FUL)          /*!< XBARB_SEL0.SEL0 Field                   */
#define XBARB_SEL0_SEL1_MASK                     (0x1F00U)                                           /*!< XBARB_SEL0.SEL1 Mask                    */
#define XBARB_SEL0_SEL1_SHIFT                    (8U)                                                /*!< XBARB_SEL0.SEL1 Position                */
#define XBARB_SEL0_SEL1(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x1F00UL)        /*!< XBARB_SEL0.SEL1 Field                   */
/* ------- SEL1 Bit Fields                          ------ */
#define XBARB_SEL1_SEL2_MASK                     (0x1FU)                                             /*!< XBARB_SEL1.SEL2 Mask                    */
#define XBARB_SEL1_SEL2_SHIFT                    (0U)                                                /*!< XBARB_SEL1.SEL2 Position                */
#define XBARB_SEL1_SEL2(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x1FUL)          /*!< XBARB_SEL1.SEL2 Field                   */
#define XBARB_SEL1_SEL3_MASK                     (0x1F00U)                                           /*!< XBARB_SEL1.SEL3 Mask                    */
#define XBARB_SEL1_SEL3_SHIFT                    (8U)                                                /*!< XBARB_SEL1.SEL3 Position                */
#define XBARB_SEL1_SEL3(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x1F00UL)        /*!< XBARB_SEL1.SEL3 Field                   */
/* ------- SEL2 Bit Fields                          ------ */
#define XBARB_SEL2_SEL4_MASK                     (0x1FU)                                             /*!< XBARB_SEL2.SEL4 Mask                    */
#define XBARB_SEL2_SEL4_SHIFT                    (0U)                                                /*!< XBARB_SEL2.SEL4 Position                */
#define XBARB_SEL2_SEL4(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x1FUL)          /*!< XBARB_SEL2.SEL4 Field                   */
#define XBARB_SEL2_SEL5_MASK                     (0x1F00U)                                           /*!< XBARB_SEL2.SEL5 Mask                    */
#define XBARB_SEL2_SEL5_SHIFT                    (8U)                                                /*!< XBARB_SEL2.SEL5 Position                */
#define XBARB_SEL2_SEL5(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x1F00UL)        /*!< XBARB_SEL2.SEL5 Field                   */
/* ------- SEL3 Bit Fields                          ------ */
#define XBARB_SEL3_SEL6_MASK                     (0x1FU)                                             /*!< XBARB_SEL3.SEL6 Mask                    */
#define XBARB_SEL3_SEL6_SHIFT                    (0U)                                                /*!< XBARB_SEL3.SEL6 Position                */
#define XBARB_SEL3_SEL6(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x1FUL)          /*!< XBARB_SEL3.SEL6 Field                   */
#define XBARB_SEL3_SEL7_MASK                     (0x1F00U)                                           /*!< XBARB_SEL3.SEL7 Mask                    */
#define XBARB_SEL3_SEL7_SHIFT                    (8U)                                                /*!< XBARB_SEL3.SEL7 Position                */
#define XBARB_SEL3_SEL7(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x1F00UL)        /*!< XBARB_SEL3.SEL7 Field                   */
/* ------- SEL4 Bit Fields                          ------ */
#define XBARB_SEL4_SEL8_MASK                     (0x1FU)                                             /*!< XBARB_SEL4.SEL8 Mask                    */
#define XBARB_SEL4_SEL8_SHIFT                    (0U)                                                /*!< XBARB_SEL4.SEL8 Position                */
#define XBARB_SEL4_SEL8(x)                       (((uint16_t)(((uint16_t)(x))<<0U))&0x1FUL)          /*!< XBARB_SEL4.SEL8 Field                   */
#define XBARB_SEL4_SEL9_MASK                     (0x1F00U)                                           /*!< XBARB_SEL4.SEL9 Mask                    */
#define XBARB_SEL4_SEL9_SHIFT                    (8U)                                                /*!< XBARB_SEL4.SEL9 Position                */
#define XBARB_SEL4_SEL9(x)                       (((uint16_t)(((uint16_t)(x))<<8U))&0x1F00UL)        /*!< XBARB_SEL4.SEL9 Field                   */
/* ------- SEL5 Bit Fields                          ------ */
#define XBARB_SEL5_SEL10_MASK                    (0x1FU)                                             /*!< XBARB_SEL5.SEL10 Mask                   */
#define XBARB_SEL5_SEL10_SHIFT                   (0U)                                                /*!< XBARB_SEL5.SEL10 Position               */
#define XBARB_SEL5_SEL10(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0x1FUL)          /*!< XBARB_SEL5.SEL10 Field                  */
#define XBARB_SEL5_SEL11_MASK                    (0x1F00U)                                           /*!< XBARB_SEL5.SEL11 Mask                   */
#define XBARB_SEL5_SEL11_SHIFT                   (8U)                                                /*!< XBARB_SEL5.SEL11 Position               */
#define XBARB_SEL5_SEL11(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x1F00UL)        /*!< XBARB_SEL5.SEL11 Field                  */
/* ------- SEL6 Bit Fields                          ------ */
#define XBARB_SEL6_SEL12_MASK                    (0x1FU)                                             /*!< XBARB_SEL6.SEL12 Mask                   */
#define XBARB_SEL6_SEL12_SHIFT                   (0U)                                                /*!< XBARB_SEL6.SEL12 Position               */
#define XBARB_SEL6_SEL12(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0x1FUL)          /*!< XBARB_SEL6.SEL12 Field                  */
#define XBARB_SEL6_SEL13_MASK                    (0x1F00U)                                           /*!< XBARB_SEL6.SEL13 Mask                   */
#define XBARB_SEL6_SEL13_SHIFT                   (8U)                                                /*!< XBARB_SEL6.SEL13 Position               */
#define XBARB_SEL6_SEL13(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x1F00UL)        /*!< XBARB_SEL6.SEL13 Field                  */
/* ------- SEL7 Bit Fields                          ------ */
#define XBARB_SEL7_SEL14_MASK                    (0x1FU)                                             /*!< XBARB_SEL7.SEL14 Mask                   */
#define XBARB_SEL7_SEL14_SHIFT                   (0U)                                                /*!< XBARB_SEL7.SEL14 Position               */
#define XBARB_SEL7_SEL14(x)                      (((uint16_t)(((uint16_t)(x))<<0U))&0x1FUL)          /*!< XBARB_SEL7.SEL14 Field                  */
#define XBARB_SEL7_SEL15_MASK                    (0x1F00U)                                           /*!< XBARB_SEL7.SEL15 Mask                   */
#define XBARB_SEL7_SEL15_SHIFT                   (8U)                                                /*!< XBARB_SEL7.SEL15 Position               */
#define XBARB_SEL7_SEL15(x)                      (((uint16_t)(((uint16_t)(x))<<8U))&0x1F00UL)        /*!< XBARB_SEL7.SEL15 Field                  */
/**
 * @} */ /* End group XBARB_Register_Masks_GROUP 
 */

/* XBARB - Peripheral instance base addresses */
#define XBARB_BasePtr                  0x4005A000UL //!< Peripheral base address
#define XBARB                          ((XBARB_Type *) XBARB_BasePtr) //!< Freescale base pointer
#define XBARB_BASE_PTR                 (XBARB) //!< Freescale style base pointer
/**
 * @} */ /* End group XBARB_Peripheral_access_layer_GROUP 
 */
/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif
/**
 * @} */ /* End group Peripheral_access_layer_GROUP 
 */

#ifdef __cplusplus
}
#endif


#endif  /* MCU_MKV40F16 */

