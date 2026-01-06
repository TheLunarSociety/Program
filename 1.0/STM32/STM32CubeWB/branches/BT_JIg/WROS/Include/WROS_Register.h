


#include "stm32wbxx_hal.h"
#include "../../WROS/Include/general.h"

#ifndef WROS_REGISTER_H
#define WROS_REGISTER_H


typedef enum IRQn
{
	/******  Cortex-M4 Processor Exceptions Numbers ***************************************************************/
	Cortex_M4_NonMaskableInt_IRQn   = -14,       /*!< 2 Non Maskable Interrupt                                    */
	Cortex_M4_HardFault_IRQn        = -13,       /*!< 3 Cortex-M4 Hard Fault Interrupt                            */
	
	Cortex_M4_MemoryManagement_IRQn = -12,       /*!< 4 Cortex-M4 Memory Management Interrupt                     */
	Cortex_M4_BusFault_IRQn         = -11,       /*!< 5 Cortex-M4 Bus Fault Interrupt                             */
	Cortex_M4_UsageFault_IRQn       = -10,       /*!< 6 Cortex-M4 Usage Fault Interrupt                           */
	NULL_9_IRQn 					= -9,
	
	NULL_8_IRQn 					= -8,
	NULL_7_IRQn 					= -7,
	NULL_6_IRQn 					= -6,
	Cortex_M4_SVCall_IRQn           = -5,        /*!< 11 Cortex-M4 SV Call Interrupt                              */
	
	Cortex_M4_DebugMonitor_IRQn     = -4,        /*!< 12 Cortex-M4 Debug Monitor Interrupt                        */
	NULL_3_IRQn						= -3,
	Cortex_M4_PendSV_IRQn           = -2,        /*!< 14 Cortex-M4 Pend SV Interrupt                              */
	Cortex_M4_SysTick_IRQn          = -1,        /*!< 15 Cortex-M4 System Tick Interrupt                          */

	/******  TMPM470 Specific Interrupt Numbers *******************************************************************/
	ExternalInterrupts_IRQn_0			= 0,
	ExternalInterrupts_IRQn_1			= 1,
	ExternalInterrupts_IRQn_2			= 2,
	ExternalInterrupts_IRQn_3			= 3,
	ExternalInterrupts_IRQn_4			= 4,
	ExternalInterrupts_IRQn_5			= 5,
	ExternalInterrupts_IRQn_6			= 6,
	ExternalInterrupts_IRQn_7			= 7,
	ExternalInterrupts_IRQn_8			= 8,
	ExternalInterrupts_IRQn_9			= 9,
	ExternalInterrupts_IRQn_10			= 10,
	ExternalInterrupts_IRQn_11			= 11,
	ExternalInterrupts_IRQn_12			= 12,
	ExternalInterrupts_IRQn_13			= 13,
	ExternalInterrupts_IRQn_14			= 14,
	ExternalInterrupts_IRQn_15			= 15,
	ExternalInterrupts_IRQn_16			= 16,
	ExternalInterrupts_IRQn_17			= 17,
	ExternalInterrupts_IRQn_18			= 18,
	ExternalInterrupts_IRQn_19			= 19,
	ExternalInterrupts_IRQn_20			= 20,
	ExternalInterrupts_IRQn_21			= 21,
	ExternalInterrupts_IRQn_22			= 22,
	ExternalInterrupts_IRQn_23			= 23,
	ExternalInterrupts_IRQn_24			= 24,
	ExternalInterrupts_IRQn_25			= 25,
	ExternalInterrupts_IRQn_26			= 26,
	ExternalInterrupts_IRQn_27			= 27,
	ExternalInterrupts_IRQn_28			= 28,
	ExternalInterrupts_IRQn_29			= 29,
	ExternalInterrupts_IRQn_30			= 30,
	ExternalInterrupts_IRQn_31			= 31,
	ExternalInterrupts_IRQn_32			= 32,
	ExternalInterrupts_IRQn_33			= 33,
	ExternalInterrupts_IRQn_34			= 34,
	ExternalInterrupts_IRQn_35			= 35,
	ExternalInterrupts_IRQn_36			= 36,
	ExternalInterrupts_IRQn_37			= 37,
	ExternalInterrupts_IRQn_38			= 38,
	ExternalInterrupts_IRQn_39			= 39,
	ExternalInterrupts_IRQn_40			= 40,
	ExternalInterrupts_IRQn_41			= 41,
	ExternalInterrupts_IRQn_42			= 42,
	ExternalInterrupts_IRQn_43			= 43,
	ExternalInterrupts_IRQn_44			= 44,
	ExternalInterrupts_IRQn_45			= 45,
	ExternalInterrupts_IRQn_46			= 46,
	ExternalInterrupts_IRQn_47			= 47,
	ExternalInterrupts_IRQn_48			= 48,
	ExternalInterrupts_IRQn_49			= 49,
	ExternalInterrupts_IRQn_50			= 50,
	ExternalInterrupts_IRQn_51			= 51,
	ExternalInterrupts_IRQn_52			= 52,
	ExternalInterrupts_IRQn_53			= 53,
	ExternalInterrupts_IRQn_54			= 54,
	ExternalInterrupts_IRQn_55			= 55,
	ExternalInterrupts_IRQn_56			= 56,
	ExternalInterrupts_IRQn_57			= 57,
	ExternalInterrupts_IRQn_58			= 58,
	ExternalInterrupts_IRQn_59			= 59,
	ExternalInterrupts_IRQn_60			= 60,
	ExternalInterrupts_IRQn_61			= 61,
	ExternalInterrupts_IRQn_62			= 62,
	ExternalInterrupts_IRQn_63			= 63,
	ExternalInterrupts_IRQn_64			= 64,
	ExternalInterrupts_IRQn_65			= 65,
	ExternalInterrupts_IRQn_66			= 66,
	ExternalInterrupts_IRQn_67			= 67,
	ExternalInterrupts_IRQn_68			= 68,
	ExternalInterrupts_IRQn_69			= 69,
	ExternalInterrupts_IRQn_70			= 70,
	ExternalInterrupts_IRQn_71			= 71,
	ExternalInterrupts_IRQn_72			= 72,
	ExternalInterrupts_IRQn_73			= 73,
	ExternalInterrupts_IRQn_74			= 74,
	ExternalInterrupts_IRQn_75			= 75,
	ExternalInterrupts_IRQn_76			= 76,
	ExternalInterrupts_IRQn_77			= 77,
	ExternalInterrupts_IRQn_78			= 78,
	ExternalInterrupts_IRQn_79			= 79,
	ExternalInterrupts_IRQn_80			= 80,
	ExternalInterrupts_IRQn_81			= 81,
	ExternalInterrupts_IRQn_82			= 82,
	ExternalInterrupts_IRQn_83			= 83,
	ExternalInterrupts_IRQn_84			= 84,
	ExternalInterrupts_IRQn_85			= 85,
	ExternalInterrupts_IRQn_86			= 86,
	ExternalInterrupts_IRQn_87			= 87,
	ExternalInterrupts_IRQn_88			= 88,
	ExternalInterrupts_IRQn_89			= 89,
	ExternalInterrupts_IRQn_90			= 90,
} WROS_IRQn_Type;


typedef struct {
	uint32_t RESERVED;					// 0xE000E000
	uint32_t ICTR;						// 0xE000E004: (R/ ) Interrupt Controller Type Register, ICTR

	union {
		volatile uint32_t ACTLR;			// 0xE000E008: (R/W) Auxiliary Control Register, ACTLR on page 4-5
		struct ACTLR_Register {
			uint32_t DISMCYCINT	: 1;		
			uint32_t DISDEFWBUF	: 1;		
			uint32_t DISFOLD		: 1;	// Disables folding of IT instructions.
			uint32_t RESERVED0	: 5;
			uint32_t DISOOFP		: 1;	// Disables floating point instructions completing out of order with respect to integer instructions.
			uint32_t DISFPCA		: 1;	// Disables lazy stacking of floating point context. See Exceptions on page 7-8 for more information.
		} ACTLR_register;
	};
	
	struct SYSTICK_Register
	{
		uint32_t RESERVED0;				// 0xE000E00C:
		union
		{
			uint32_t STCSR; 				// 0xE000E010: (R/W) SysTick Control and Status Register
			struct STCSR_Register
			{
				uint32_t ENABLE		: 1;		// Request CORTEX_M reset
				uint32_t TICKINT	: 1;		// Clear all abnormal Info
				uint32_t CLKSOURCE	: 1;		// Request MCU reset
				uint32_t RESERVED_0	: 13;
				uint32_t COUNTFLAG	: 1;		// Priority grouping
				uint32_t RESERVED_1	: 15;
			} STCSR_register;
		};

		union
		{
			uint32_t STRVR; 				// 0xE000E014: (R/W) SysTick Reload Value Register
			struct STRVR_Register
			{
				uint32_t RELOAD		: 24;	
				uint32_t RESERVED_0	: 8;
			} STRVR_register;
		};
		
		union
		{
			uint32_t STCVR; 				// 0xE000E018: (R/W) SysTick Current Value Register 	
			struct STCVR_Register
			{
				uint32_t CURRENT	: 24;	
				uint32_t RESERVED_0	: 8;
			} STCVR_register;
		};
		
		union
		{
			uint32_t STCR;	//	STCALIB 	// 0xE000E01C: (R/ ) SysTick Calibration Value Register 	
			struct STCR_Register
			{
				uint32_t TENMS		: 24;
				uint32_t RESERVED_0	: 6;
				uint32_t SKEW		: 1;
				uint32_t NOREF		: 1;
			} STCR_register;
		};
		uint32_t RESERVED1[56];			// 0xE000E020: ( / ) SysTick Current Value Register
	}SYSTICK_register;
	
	struct NVIC_Register {

		uint32_t ISER[8];					// 0xE000E100: (R/W) Interrupt Set Enable Register
		uint32_t RESERVED2[24];							
		uint32_t ICER[8];					// 0xE000E180: (R/W) Interrupt Clear Enable Register
		uint32_t RESERVED3[24]; 							
		uint32_t ISPR[8];					// 0xE000E200: (R/W) Interrupt Set Pending Register
		uint32_t RESERVED4[24];							
		uint32_t ICPR[8];					// 0xE000E280: (R/W) Interrupt Clear Pending Register
		uint32_t RESERVED5[24];							
		uint32_t IABR[8];					// 0xE000E300: (R/W) Interrupt Active bit Register
		uint32_t RESERVED6[56];
		uint8_t IPR[240];					// 0xE000E400: (R/W) Interrupt Active bit Register
		uint32_t RESERVED7[516];			// 0xE000E4F0
		
		union {
			volatile uint32_t CPUID;		// 0xE000ED00: (R/ ) CPU ID Base Register	// Reset 0x410FC240	
			struct CPUID_Register {
				uint32_t REVISION		: 4;		// Indicates patch release: 0x0 = Patch 0.
				uint32_t PARTNO			: 12;		// Indicates part number: 0xC24 = Cortex-M4, 0xC23 = Cortex-M3
				uint32_t Constant		: 4;		// Reads as 0xF
				uint32_t VARIANT		: 4;		// Indicates processor revision: 0x0 = Revision 0
				uint32_t IMPLEMENTER	: 8;		// Indicates implementor: 0x41 = ARM
			} CPUID_register;
		};
		
		uint32_t ICSR;					// 0xE000ED04: (R/W)  Interrupt Control State Register
		uint32_t VTOR;					// 0xE000ED08: (R/W)  Vector Table Offset Register


		union {
			uint32_t AIRCR;					// 0xE000ED0C: (R/W)  Application Interrupt / Reset Control Register
			struct AIRCR_Register {
				uint32_t VECTRESET		: 1;		// Request CORTEX_M reset
				uint32_t VECTCLRACTIVE	: 1;		// Clear all abnormal Info
				uint32_t SYSRESETREQ	: 1;		// Request MCU reset
				uint32_t RESERVED0		: 5;
				uint32_t PRIGROUP		: 3;		// Priority grouping
				uint32_t RESERVED1		: 4;
				uint32_t ENDIANESS		: 1;		// READ ONLY		1 = MSB, 0 = LSB
				uint32_t VECTKEY		: 16;		// OPER Key			WRITE: 0x05FA, READ: 0xFA05
			} AIRCR_register;
		};
		
		uint32_t SCR;						// 0xE000ED10: (R/W)  System Control Register
		uint32_t CCR;						// 0xE000ED14: (R/W)  Configuration Control Register 
		uint8_t SHP[12];					// 0xE000ED18: (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) 
		uint32_t SHCSR;					// 0xE000ED24: (R/W)  System Handler Control and State Register			 
		uint32_t CFSR;					// 0xE000ED28: (R/W)  Configurable Fault Status Register 				   
		uint32_t HFSR;					// 0xE000ED2C: (R/W)  Hard Fault Status Register 						   
		uint32_t DFSR;					// 0xE000ED30: (R/W)  Debug Fault Status Register						   
		uint32_t MMFAR;					// 0xE000ED34: (R/W)  Mem Manage Address Register						   
		uint32_t BFAR;					// 0xE000ED38: (R/W)  Bus Fault Address Register 						   
		uint32_t AFSR;					// 0xE000ED3C: (R/W)  Auxiliary Fault Status Register					   
		uint32_t PFR[2];					// 0xE000ED40: (R/ )  Processor Feature Register 						   
		uint32_t DFR;						// 0xE000ED48: (R/ )  Debug Feature Register 							   
		uint32_t ADR;						// 0xE000ED4C: (R/ )  Auxiliary Feature Register 						   
		uint32_t MMFR[4];					// 0xE000ED50: (R/ )  Memory Model Feature Register						
		uint32_t ISAR[5];					// 0xE000ED60: (R/ )  ISA Feature Register								   
		uint32_t RESERVED8[5];
		uint32_t CPACR;					// 0xE000ED88: (R/W)  Coprocessor access register鍗忓鐞嗗櫒璁块棶瀵勫瓨鍣紙M4 FPU鐩稿叧锛孧3鏃狅級
		uint32_t RESERVED9;				// 0xE000ED8C
		uint32_t MPU_TYPE;				// 0xE000ED90: (R/ )  MPU Type Register
		uint32_t MPU_CTRL;				// 0xE000ED94: (R/W)  MPU Control Register
		uint32_t MPU_RNR;					// 0xE000ED98: (R/W)  MPU Region Number Register
		uint32_t MPU_RBAR;				// 0xE000ED9C: (R/W)  MPU Region Number Register
		uint32_t MPU_RASR;				// 0xE000EDA0: (R/W)  MPU Region Number Register
		uint32_t MPU_RBAR_A1;				// 0xE000EDA4: (R/W)  MPU alias registers
		uint32_t MPU_RASR_A1;				// 0xE000EDA8: (R/W)  
		uint32_t MPU_RBAR_A2;				// 0xE000EDAC: (R/W)  
		uint32_t MPU_RASR_A2;				// 0xE000EDB0: (R/W)  
		uint32_t MPU_RBAR_A3;				// 0xE000EDB4: (R/W)  
		uint32_t MPU_RASR_A3;				// 0xE000EDB8: (R/W)  
		uint32_t RESERVED10[81];			// 0xE000EDBC
		
		uint32_t STIR;					// 0xE000EF00: ( /W)  Software Triggered Interrupt Register
	}NVIC_register;
} WROS_CORTEX_M_Typedef;


/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/




// 				FLASH



typedef struct {
    // Flash 璁块棶鎺у埗瀵勫瓨鍣? (FLASH_ACR)
    union {
        __IO uint32_t ACR;                /*!< Flash memory access control register        */
        struct ACR_Register {
            uint32_t LATENCY       : 3;    /*!< Latency (Number of wait states)             */
            uint32_t RESERVED0     : 5;    /*!< Reserved bits                                */
            uint32_t PRFTEN        : 1;    /*!< Prefetch enable                             */
            uint32_t ICEN          : 1;    /*!< Instruction cache enable                    */
            uint32_t DCEN          : 1;    /*!< Data cache enable                           */
            uint32_t ICRST         : 1;    /*!< Instruction cache reset                     */
            uint32_t DCRST         : 1;    /*!< Data cache reset                            */
            uint32_t RESERVED1     : 2;    /*!< Reserved bits                                */
            uint32_t PES           : 1;    /*!< CPU1 program/erase suspend request          */
            uint32_t EMPTY         : 1;    /*!< Flash memory User area empty                */
            uint32_t RESERVED2     : 15;   /*!< Reserved bits                                */
        } ACR_register;
    };

    uint32_t RESERVED4;                /*!< Reserved space (0x004 - 0x007)              */

    // Flash 瀵嗛挜瀵勫瓨鍣? (FLASH_KEYR)
    __IO uint32_t KEYR;                  /*!< Flash memory key register                    */

    // Flash 閫夐」瀵嗛挜瀵勫瓨鍣? (FLASH_OPTKEYR)
    __IO uint32_t OPTKEYR;               /*!< Flash memory option key register            */

    // Flash 鐘舵?佸瘎瀛樺櫒 (FLASH_SR)
    union {
        __IO uint32_t SR;                 /*!< Flash memory status register                 */
        struct SR_Register {
            uint32_t EOP           : 1;    /*!< End of operation                            */
            uint32_t OPERR         : 1;    /*!< Operation error                             */
            uint32_t RESERVED5     : 1;    /*!< Reserved bit                                */
            uint32_t PROGERR       : 1;    /*!< Programming error                           */
            uint32_t WRPERR        : 1;    /*!< Write protection error                      */
            uint32_t PGAERR        : 1;    /*!< Programming alignment error                 */
            uint32_t SIZERR        : 1;    /*!< Size error                                  */
            uint32_t PGSERR        : 1;    /*!< Programming sequence error                  */
            uint32_t MISERR        : 1;    /*!< Fast programming data miss error            */
            uint32_t FASTERR       : 1;    /*!< Fast programming error                      */
            uint32_t RESERVED6     : 3;    /*!< Reserved bits                               */
            uint32_t OPTNV         : 1;    /*!< User Option OPTVAL indication               */
            uint32_t RDERR     		 : 1;    /*!< Reserved bits                               */
            uint32_t OPTVERR       : 1;    /*!< Option and Engineering bits loading validity error */
            uint32_t BSY           : 1;    /*!< Busy                                        */
            uint32_t RESERVED8     : 1;    /*!< Reserved bit                                */
            uint32_t CFGBSY        : 1;    /*!< Programming or erase configuration busy     */
            uint32_t PESD          : 1;    /*!< Programming / erase operation suspended     */
            uint32_t RESERVED9     : 12;   /*!< Reserved bits                               */
        } SR_register;
    };

    // Flash 鎺у埗瀵勫瓨鍣? (FLASH_CR)
    union {
        __IO uint32_t FLASH_CR;                 /*!< Flash memory control register                */
        struct FLASH_CR_Register {
            uint32_t PG            : 1;    /*!< Programming                                 */
            uint32_t PER           : 1;    /*!< Page erase                                  */
            uint32_t MER           : 1;    /*!< Mass erase                                  */
            uint32_t PNB           : 8;    /*!< Page number selection                       */
            uint32_t RESERVED11    : 5;    /*!< Reserved bits                               */
            uint32_t STRT          : 1;    /*!< Start                                       */
            uint32_t OPTSTRT       : 1;    /*!< Options modification start                  */
            uint32_t FSTPG         : 1;    /*!< Fast programming                            */
            uint32_t RESERVED12    : 5;    /*!< Reserved bits                               */
            uint32_t EOPIE         : 1;    /*!< End of operation interrupt enable           */
            uint32_t ERRIE         : 1;    /*!< Error interrupt enable                      */
            uint32_t RDERRIE       : 1;    /*!< PCROP read error interrupt enable           */
            uint32_t OBL_LAUNCH    : 1;    /*!< Forces the option byte loading              */
            uint32_t RESERVED13    : 2;    /*!< Reserved bits                                */
            uint32_t OPTLOCK       : 1;    /*!< Options Lock                                */
            uint32_t LOCK          : 1;    /*!< FLASH_CR Lock                               */
        } FLASH_CR_register;
    };

    // Flash ECC 瀵勫瓨鍣? (FLASH_ECCR)
    union {
        __IO uint32_t ECCR;               /*!< Flash memory ECC register                   */
        struct ECCR_Register {
            uint32_t ADDR_ECC      : 17;   /*!< ECC fail double-word address                */
            uint32_t RESERVED14    : 3;    /*!< Reserved bits                               */
            uint32_t SYSF_ECC      : 1;    /*!< System Flash memory ECC fail                */
            uint32_t RESERVED15    : 3;    /*!< Reserved bits                               */
            uint32_t ECCIE         : 1;    /*!< ECC correction interrupt enable             */
            uint32_t RESERVED16    : 1;    /*!< Reserved bit                                */
            uint32_t CPUID         : 3;    /*!< CPU identification                          */
            uint32_t RESERVED17    : 1;    /*!< Reserved bit                                */
            uint32_t ECCC          : 1;    /*!< ECC correction                              */
            uint32_t ECCD          : 1;    /*!< ECC detection                               */
        } ECCR_register;
    };

    uint32_t RESERVED18;                /*!< Reserved space (0x01C - 0x01F)              */

    // Flash 閫夐」瀵勫瓨鍣? (FLASH_OPTR)
    union {
        __IO uint32_t OPTR;               /*!< Flash memory option register                */
        struct OPTR_Register {
            uint32_t RDP           : 8;    /*!< Read protection level                       */
            uint32_t ESE           : 1;    /*!< ESE                                         */
            uint32_t BOR_LEV       : 3;    /*!< BOR level                                   */
            uint32_t nRST_STOP     : 1;    /*!< nRST_STOP                                   */
            uint32_t nRST_STDBY    : 1;    /*!< nRST_STDBY                                  */
            uint32_t nRST_SHDW     : 1;    /*!< nRST_SHDW                                   */
            uint32_t RESERVED21    : 1;    /*!< Reserved bit                                */
            uint32_t IWDG_SW       : 1;    /*!< Independent watchdog selection              */
            uint32_t IWDG_STOP     : 1;    /*!< Independent watchdog counter freeze in stop mode */
            uint32_t IWDG_STDBY    : 1;    /*!< Independent watchdog counter freeze in Standby mode */
            uint32_t WWDG_SW       : 1;    /*!< Window watchdog selection                   */
            uint32_t RESERVED20    : 3;    /*!< Reserved bits                               */
            uint32_t nBOOT1        : 1;    /*!< Boot configuration                          */
            uint32_t SRAM2_PE      : 1;    /*!< SRAM2 parity check enable                   */
            uint32_t SRAM2_RST     : 1;    /*!< SRAM2 and PKA RAM Erase when system reset   */
            uint32_t nSWBOOT0      : 1;    /*!< Software BOOT0 selection                    */
            uint32_t nBOOT0        : 1;    /*!< nBOOT0 option bit                           */
            uint32_t RESERVED19    : 1;    /*!< Reserved bit                                */
            uint32_t AGC_TRIM      : 3;    /*!< Radio automatic gain control trimming       */
        } OPTR_register;
    };

    // Flash PCROP 鍖哄煙 A 璧峰鍦板潃瀵勫瓨鍣? (FLASH_PCROP1ASR)
    union {
        __IO uint32_t PCROP1A_SR;          /*!< Flash memory PCROP zone A Start address register */
        struct PCROP1A_SR_Register {
            uint32_t PCROP1A_STRT  : 9;    /*!< PCROP1A area start offset                   */
            uint32_t RESERVED23    : 23;   /*!< Reserved bits                                */
        } PCROP1A_SR_register;
    };

    // Flash PCROP 鍖哄煙 A 缁撴潫鍦板潃瀵勫瓨鍣? (FLASH_PCROP1AER)
    union {
        __IO uint32_t PCROP1A_ER;          /*!< Flash memory PCROP zone A End address register */
        struct PCROP1A_ER_Register {
            uint32_t PCROP1A_END   : 9;    /*!< PCROP1A area end offset                     */
            uint32_t RESERVED24    : 22;   /*!< Reserved bits                                */
						uint32_t PCROP_RDP	   : 1;    /*!< PCROP area preserved when RDP level decreased */
        } PCROP1A_ER_register;
    };

    // Flash WRP 鍖哄煙 A 鍦板潃瀵勫瓨鍣? (FLASH_WRP1AR)
    union {
        __IO uint32_t WRP1A_R;             /*!< Flash memory WRP area A address register    */
        struct WRP1AR_Register {
            uint32_t WRP1A_STRT    : 8;    /*!< WRP first area "A" start offset             */
            uint32_t RESERVED25    : 8;    /*!< Reserved bits                                */
            uint32_t WRP1A_END     : 8;    /*!< WRP first area "A" end offset               */
						uint32_t RESERVED26    : 8;    /*!< Reserved bits								 */
        } WRP1A_R_register;
    };

    // Flash WRP 鍖哄煙 B 鍦板潃瀵勫瓨鍣? (FLASH_WRP1BR)
    union {
        __IO uint32_t WRP1B_R;             /*!< Flash memory WRP area B address register    */
        struct WRP1B_R_Register {
            uint32_t WRP1B_STRT    : 8;    /*!< WRP second area "B" start offset            */
            uint32_t RESERVED27    : 8;    /*!< Reserved bits                                */
            uint32_t WRP1B_END     : 8;    /*!< WRP second area "B" end offset              */
						uint32_t RESERVED28    : 8;    /*!< Reserved bits								 */
        } WRP1B_R_register;
    };

    // Flash PCROP 鍖哄煙 B 璧峰鍦板潃瀵勫瓨鍣? (FLASH_PCROP1BSR)
    union {
        __IO uint32_t PCROP1B_SR;          /*!< Flash memory PCROP zone B Start address register */
        struct PCROP1B_SR_Register {
            uint32_t PCROP1B_STRT  : 9;    /*!< PCROP1B area start offset                   */
            uint32_t RESERVED30    : 23;   /*!< Reserved bits                                */
        } PCROP1B_SR_register;
    };

    // Flash PCROP 鍖哄煙 B 缁撴潫鍦板潃瀵勫瓨鍣? (FLASH_PCROP1BER)
    union {
        __IO uint32_t PCROP1B_ER;          /*!< Flash memory PCROP zone B End address register */
        struct PCROP1B_ER_Register {
            uint32_t PCROP1B_END   : 9;    /*!< PCROP1B area end offset                     */
            uint32_t RESERVED31    : 23;   /*!< Reserved bits                                */
        } PCROP1B_ER_register;
    };

    // Flash IPCC 閭鏁版嵁缂撳啿鍖哄湴鍧?瀵勫瓨鍣? (FLASH_IPCCBR)
    union {
        __IO uint32_t IPCCBR;             /*!< Flash memory IPCC mailbox data buffer address register */
        struct IPCCBR_Register {
            uint32_t IPCCBA        : 14;   /*!< IPCC mailbox data buffer base address offset */
            uint32_t RESERVED32    : 18;   /*!< Reserved bits                                */
        } IPCCBR_register;
    };

    uint32_t RESERVED33[7];              /*!< Reserved space (0x040 - 0x07F)              */

    // Flash CPU2 璁块棶鎺у埗瀵勫瓨鍣? (FLASH_C2ACR)
    union {
        __IO uint32_t C2ACR;              /*!< Flash memory CPU2 access control register   */
        struct C2ACR_Register {
            uint32_t RESERVED38    : 8;    /*!< Reserved bits                                */
            uint32_t PRFTEN        : 1;    /*!< CPU2 Prefetch enable                        */
            uint32_t ICEN          : 1;    /*!< CPU2 Instruction cache enable               */
            uint32_t RESERVED39    : 1;    /*!< Reserved bit                                */
            uint32_t ICRST         : 1;    /*!< CPU2 Instruction cache reset                */
            uint32_t RESERVED40    : 3;   /*!< Reserved bits                                */
            uint32_t PES           : 1;    /*!< CPU2 program/erase suspend request          */
						uint32_t RESERVED41    : 16;   /*!< Reserved bits								 */
        } C2ACR_register;
    };

    // Flash CPU2 鐘舵?佸瘎瀛樺櫒 (FLASH_C2SR)
    union {
        __IO uint32_t C2SR;               /*!< Flash memory CPU2 status register            */
        struct C2SR_Register {
            uint32_t EOP           : 1;    /*!< End of operation (0: No, 1: Yes)            */
            uint32_t OPERR         : 1;    /*!< Operation error (0: No, 1: Yes)             */
            uint32_t RESERVED41    : 1;    /*!< Reserved bit                                */
            uint32_t PROGERR       : 1;    /*!< Programming error (0: No, 1: Yes)           */
            uint32_t WRPERR        : 1;    /*!< Write protection error (0: No, 1: Yes)      */
            uint32_t PGAERR        : 1;    /*!< Programming alignment error (0: No, 1: Yes) */
            uint32_t SIZERR        : 1;    /*!< Size error (0: No, 1: Yes)                  */
            uint32_t PGSERR        : 1;    /*!< Programming sequence error (0: No, 1: Yes)  */
            uint32_t MISSERR       : 1;    /*!< Fast programming data miss error            */
            uint32_t FASTERR       : 1;    /*!< Fast programming error                      */
            uint32_t RESERVED42    : 4;    /*!< Reserved bits                               */
            uint32_t RDERR         : 1;    /*!< User Option OPTVAL indication               */
            uint32_t RESERVED43    : 1;    /*!< Reserved bits                               */
            uint32_t BSY           : 1;    /*!< Busy flag (0: Ready, 1: Busy)               */
            uint32_t RESERVED44    : 1;    /*!< Reserved bit                                */
            uint32_t CFGBSY        : 1;    /*!< Configuration busy (0: Ready, 1: Busy)      */
            uint32_t PESD          : 1;    /*!< Program/erase suspended (0: No, 1: Yes)     */
            uint32_t RESERVED45    : 12;   /*!< Reserved bits                               */
        } C2SR_register;
    };

    // Flash CPU2 鎺у埗瀵勫瓨鍣? (FLASH_C2CR)
    union {
        __IO uint32_t FLASH_C2CR;               /*!< Flash memory CPU2 control register           */
        struct FLASH_C2CR_Register {
            uint32_t PG            : 1;    /*!< Programming enable (0: Disable, 1: Enable)  */
            uint32_t PER           : 1;    /*!< Page erase enable (0: Disable, 1: Enable)   */
            uint32_t MER           : 1;    /*!< Mass erase enable (0: Disable, 1: Enable)   */
            uint32_t PNB           : 8;    /*!< Page number selection (0~255)               */
            uint32_t RESERVED46    : 5;    /*!< Reserved bits                               */
            uint32_t STRT          : 1;    /*!< Start operation (0: No, 1: Trigger)         */
            uint32_t RESERVED47    : 1;    /*!< Reserved bits                               */
            uint32_t FSTPG         : 1;    /*!< Fast programming enable                     */
            uint32_t RESERVED48    : 5;    /*!< Reserved bits                               */
            uint32_t EOPIE         : 1;    /*!< End of operation interrupt enable           */
            uint32_t ERRIE         : 1;    /*!< Error interrupt enable                      */
            uint32_t RDERRIE       : 1;    /*!< PCROP read error interrupt enable           */
            uint32_t RESERVED49    : 5;    /*!< Reserved bits                               */
        } FLASH_C2CR_register;
    };
		
    uint32_t RESERVED34[6];              /*!< Reserved space (0x040 - 0x07F)              */
    // 瀹夊叏 Flash 璧峰鍦板潃瀵勫瓨鍣? (FLASH_SFR)
    union {
        __IO uint32_t SFR;                /*!< Secure Flash memory start address register  */
        struct SFR_Register {
            uint32_t SPSA          : 8;    /*!< SPSA                                        */
            uint32_t FSD           : 1;    /*!< FSD                                         */
            uint32_t RESERVED34    : 3;    /*!< Reserved bits                                */
            uint32_t DDS           : 1;    /*!< Disable CPU2 Debug access                   */
            uint32_t RESERVED36    : 19;   /*!< Reserved bits                                */
        } SFR_register;
    };

    // Flash 瀹夊叏 SRAM2 璧峰鍦板潃鍜? CPU2 澶嶄綅鍚戦噺瀵勫瓨鍣? (FLASH_SRRVR)
    union {
        __IO uint32_t SRRVR;              /*!< Flash memory secure SRAM2 start address and CPU2 reset vector register */
        struct SRRVR_Register {
            uint32_t SBRV          : 18;   /*!< CPU2 boot reset vector                      */
            uint32_t SBRSA         : 5;    /*!< Secure non-backup SRAM2b start address      */
            uint32_t BRSD          : 1;    /*!< backup SRAM2a security disable              */
            uint32_t RESERVED37    : 1;    /*!< Reserved bit                                */
            uint32_t SNBRSA        : 5;    /*!< Secure backup SRAM2a start address          */
            uint32_t NBRSD         : 1;    /*!< non-backup SRAM2b security disable          */
            uint32_t C2OPT         : 1;    /*!< CPU2 boot reset vector memory selection     */
        } SRRVR_register;
    };

} WROS_FLASH_TypeDef;







/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/





// 				RCC





typedef struct {
    // RCC 鏃堕挓鎺у埗瀵勫瓨鍣? (RCC_CR)   					
	  // 0x5800 0000
    union {
        __IO uint32_t RCC_CR;                /*!< RCC clock control register                  */
        struct RCC_CR_Register {
			uint32_t MSION         : 1;    /*!< HSI oscillator enable                       */
			uint32_t MSIRDY        : 1;    /*!< HSI oscillator ready flag                   */
			uint32_t MSIPLLEN      : 1;    /*!< MSI PLL enable                              */
			uint32_t Reserved_0    : 1;    /*!< Reserved bit                                */
			uint32_t MSIRANGE      : 4;    /*!< MSI clock range                             */
			uint32_t HSION         : 1;    /*!< MSI oscillator enable                       */
			uint32_t HSIKERON      : 1;    /*!< HSI oscillator enable                       */
			uint32_t HSIRDY        : 1;    /*!< HSI oscillator ready flag                   */
			uint32_t HSIASFS       : 1;    /*!< HSI16 automatic start from Stop                       */
			uint32_t HSIKERDY      : 1;    /*!< HSI16 kernel clock ready flag for peripherals requests */
			uint32_t Reserved_1    : 3;    /*!< Reserved bit                                */
			uint32_t HSEON         : 1;    /*!< HSE oscillator enable                       */
			uint32_t HSERDY        : 1;    /*!< HSE oscillator ready flag                   */
			uint32_t HSEBYP        : 1;    /*!< HSE oscillator bypass                       */
			uint32_t CSSON         : 1;    /*!< Clock security system enable                */
			uint32_t HSEPRE        : 1;    /*!< HSE sysclk and PLL M divider prescaler      */
			uint32_t Reserved_2    : 3;    /*!< Reserved bit                                */
			uint32_t PLLON         : 1;    /*!< Main PLL enable                             */
			uint32_t PLLRDY        : 1;    /*!< Main PLL clock ready flag                   */
			uint32_t PLLSAI1ON     : 1;    /*!< PLLSAI enable                               */
			uint32_t PLLSAI1RDY    : 1;    /*!< PLLSAI clock ready flag                     */
			uint32_t Reserved_3    : 4;    /*!< Reserved bit								*/
        } RCC_CR_register;
    };

    // RCC 鍐呴儴鏃堕挓婧愭牎鍑嗗瘎瀛樺櫒 (RCC_ICSCR)			
		// 0x5800 0004
    union {
        __IO uint32_t ICSCR;             /*!< RCC internal clock sources calibration register */
        struct ICSCR_Register {
            uint32_t HSITRIM       : 7;    /*!< HSI16 clock trimming                        */
            uint32_t HSICAL        : 8;    /*!< HSI16 clock calibration                     */
            uint32_t RESERVED3     : 1;    /*!< Reserved bit                                */
            uint32_t MSITRIM       : 8;    /*!< MSI clock trimming                          */
            uint32_t MSICAL        : 8;    /*!< MSI clock calibration                       */
        } ICSCR_register;
    };

    // RCC 鏃堕挓閰嶇疆瀵勫瓨鍣? (RCC_CFGR)						
		// 0x5800 0008
    union {
        __IO uint32_t CFGR;              /*!< RCC clock configuration register            */
        struct CFGR_Register {
            uint32_t SW            : 2;    /*!< System clock switch                         */
            uint32_t SWS           : 2;    /*!< System clock switch status                  */
            uint32_t HPRE          : 4;    /*!< AHB prescaler                               */
            uint32_t RESERVED4     : 1;    /*!< Reserved bit                                */
            uint32_t PPRE1         : 3;    /*!< APB low-speed prescaler (APB1)              */
            uint32_t PPRE2         : 3;    /*!< APB high-speed prescaler (APB2)             */
            uint32_t RTCPRE        : 5;    /*!< RTC prescaler                               */
            uint32_t MCO1          : 2;    /*!< Microcontroller clock output 1              */
            uint32_t MCO1PRE       : 3;    /*!< Microcontroller clock output 1 prescaler    */
            uint32_t MCO2PRE       : 3;    /*!< Microcontroller clock output 2 prescaler    */
            uint32_t MCO2          : 2;    /*!< Microcontroller clock output 2              */
            uint32_t RESERVED5     : 2;    /*!< Reserved bits                               */
        } CFGR_register;
    };

    // RCC PLL 閰嶇疆瀵勫瓨鍣? (RCC_PLLCFGR)				
		// 0x5800 000C
    union {
        __IO uint32_t PLLCFGR;           /*!< RCC PLL configuration register              */
        struct PLLCFGR_Register {
            uint32_t PLLM          : 6;    /*!< PLLM division factor                        */
            uint32_t PLLN          : 9;    /*!< PLLN multiplication factor                  */
            uint32_t PLLP          : 2;    /*!< PLLP division factor                        */
            uint32_t RESERVED6     : 1;    /*!< Reserved bit                                */
            uint32_t PLLSRC        : 2;    /*!< PLL entry clock source                      */
            uint32_t PLLQ          : 4;    /*!< PLLQ division factor                        */
            uint32_t RESERVED7     : 2;    /*!< Reserved bits                               */
            uint32_t PLLR          : 2;    /*!< PLLR division factor                        */
            uint32_t RESERVED8     : 3;    /*!< Reserved bits                               */
        } PLLCFGR_register;
    };

    // RCC PLLSAI1 閰嶇疆瀵勫瓨鍣? (RCC_PLLSAI1CFGR)				
		// 0x5800 0010
    union {
        __IO uint32_t PLLSAI1CFGR;       /*!< RCC PLLSAI1 configuration register          */
        struct PLLSAI1CFGR_Register {
            uint32_t PLLSAI1M      : 6;    /*!< PLLSAI1M division factor                    */
            uint32_t PLLSAI1N      : 9;    /*!< PLLSAI1N multiplication factor              */
            uint32_t PLLSAI1P      : 2;    /*!< PLLSAI1P division factor                    */
            uint32_t RESERVED9     : 1;    /*!< Reserved bit                                */
            uint32_t PLLSAI1SRC    : 2;    /*!< PLLSAI1 entry clock source                  */
            uint32_t PLLSAI1Q      : 4;    /*!< PLLSAI1Q division factor                    */
            uint32_t RESERVED10    : 2;    /*!< Reserved bits                               */
            uint32_t PLLSAI1R      : 2;    /*!< PLLSAI1R division factor                    */
            uint32_t RESERVED11    : 3;    /*!< Reserved bits                               */
        } PLLSAI1CFGR_register;
    };
		
    uint32_t RESERVED_0;
    // RCC 鏃堕挓涓柇浣胯兘瀵勫瓨鍣? (RCC_CIER)						
		// 0x5800 0018
    union {
        __IO uint32_t CIER;              /*!< RCC clock interrupt enable register         */
        struct CIER_Register {
            uint32_t LSIRDYIE      : 1;    /*!< LSIRDY interrupt enable                     */
            uint32_t LSERDYIE      : 1;    /*!< LSERDY interrupt enable                     */
            uint32_t HSIRDYIE      : 1;    /*!< HSIRDY interrupt enable                     */
            uint32_t HSERDYIE      : 1;    /*!< HSERDY interrupt enable                     */
            uint32_t PLLRDYIE      : 1;    /*!< PLLRDY interrupt enable                     */
            uint32_t PLLSAI1RDYIE  : 1;    /*!< PLLSAI1RDY interrupt enable                 */
            uint32_t HSI48RDYIE    : 1;    /*!< HSI48RDY interrupt enable                   */
            uint32_t MSIRDYIE      : 1;    /*!< MSIRDY interrupt enable                     */
            uint32_t LSECSSIE      : 1;    /*!< LSECSS interrupt enable                     */
            uint32_t CSSCIE        : 1;    /*!< CSSC interrupt enable                       */
            uint32_t RESERVED12    : 22;   /*!< Reserved bits                               */
        } CIER_register;
    };

    // RCC 鏃堕挓涓柇鏍囧織瀵勫瓨鍣? (RCC_CIFR)			
		// 0x5800 001C
    union {
        __IO uint32_t CIFR;              /*!< RCC clock interrupt flag register           */
        struct CIFR_Register {
            uint32_t LSIRDYF       : 1;    /*!< LSIRDY flag                                 */
            uint32_t LSERDYF       : 1;    /*!< LSERDY flag                                 */
            uint32_t HSIRDYF       : 1;    /*!< HSIRDY flag                                 */
            uint32_t HSERDYF       : 1;    /*!< HSERDY flag                                 */
            uint32_t PLLRDYF       : 1;    /*!< PLLRDY flag                                 */
            uint32_t PLLSAI1RDYF   : 1;    /*!< PLLSAI1RDY flag                             */
            uint32_t HSI48RDYF     : 1;    /*!< HSI48RDY flag                               */
            uint32_t MSIRDYF       : 1;    /*!< MSIRDY flag                                 */
            uint32_t LSECSSF       : 1;    /*!< LSECSS flag                                 */
            uint32_t CSSCF         : 1;    /*!< CSSC flag                                   */
            uint32_t RESERVED13    : 22;   /*!< Reserved bits                               */
        } CIFR_register;
    };

    // RCC 鏃堕挓涓柇娓呴浂瀵勫瓨鍣? (RCC_CICR)			
		// 0x5800 0020
    union {
        __IO uint32_t CICR;              /*!< RCC clock interrupt clear register          */
        struct CICR_Register {
            uint32_t LSIRDYCF      : 1;    /*!< LSIRDY clear flag                           */
            uint32_t LSERDYCF      : 1;    /*!< LSERDY clear flag                           */
            uint32_t HSIRDYCF      : 1;    /*!< HSIRDY clear flag                           */
            uint32_t HSERDYCF      : 1;    /*!< HSERDY clear flag                           */
            uint32_t PLLRDYCF      : 1;    /*!< PLLRDY clear flag                           */
            uint32_t PLLSAI1RDYCF  : 1;    /*!< PLLSAI1RDY clear flag                       */
            uint32_t HSI48RDYCF    : 1;    /*!< HSI48RDY clear flag                         */
            uint32_t MSIRDYCF      : 1;    /*!< MSIRDY clear flag                           */
            uint32_t LSECSSCF      : 1;    /*!< LSECSS clear flag                           */
            uint32_t CSSCCF        : 1;    /*!< CSSC clear flag                             */
            uint32_t RESERVED14    : 22;   /*!< Reserved bits                               */
        } CICR_register;
    };

    // RCC SMPS 闄嶅帇杞崲鍣ㄦ帶鍒跺瘎瀛樺櫒 (RCC_SMPSCR)			
		// 0x5800 0024
    union {
        __IO uint32_t SMPSCR;            /*!< RCC SMPS step-down converter control register */
        struct SMPSCR_Register {
            uint32_t SMPSSEL       : 2;    /*!< SMPS clock selection                        */
            uint32_t SMPSDIV       : 2;    /*!< SMPS clock prescaler                        */
            uint32_t RESERVED15    : 4;    /*!< Reserved bits                               */
            uint32_t SMPSEN        : 1;    /*!< SMPS enable                                 */
            uint32_t SMPSRUNSTDBY  : 1;    /*!< SMPS run in standby                         */
            uint32_t SMPSLEVEL     : 3;    /*!< SMPS voltage level                          */
            uint32_t RESERVED16    : 19;   /*!< Reserved bits                               */
        } SMPSCR_register;
    };

    // RCC AHB1 澶栬澶嶄綅瀵勫瓨鍣? (RCC_AHB1RSTR)			
		// 0x5800 0028
    union {
        __IO uint32_t AHB1RSTR;          /*!< RCC AHB1 peripheral reset register          */
        struct AHB1RSTR_Register {
            uint32_t DMA1RST       : 1;    /*!< DMA1 reset                                  */
            uint32_t DMA2RST       : 1;    /*!< DMA2 reset                                  */
            uint32_t DMAMUX1RST    : 1;    /*!< DMAMUX reset                                  */
            uint32_t Reserved_0    : 9;
						uint32_t CRCRST        : 1;    /*!< CRC reset                                 */
            uint32_t Reserved_1    : 3;    
            uint32_t TSCRST			   : 1;    /*!< Touch Sensing Controller reset           */
            uint32_t Reserved_2    : 15;   /*!< Reserved bits                               */
        } AHB1RSTR_register;
    };

    // RCC AHB2 澶栬澶嶄綅瀵勫瓨鍣? (RCC_AHB2RSTR)			
		// 0x5800 002C
    union {
        __IO uint32_t AHB2RSTR;          /*!< RCC AHB2 peripheral reset register          */
        struct AHB2RSTR_Register {
            uint32_t GPIOARST      : 1;    /*!< GPIOA reset                                 */
            uint32_t GPIOBRST      : 1;    /*!< GPIOB reset                                 */
            uint32_t GPIOCRST      : 1;    /*!< GPIOC reset                                 */
            uint32_t GPIODRST      : 1;    /*!< GPIOD reset                                 */
            uint32_t GPIOERST      : 1;    /*!< GPIOE reset                                 */
            uint32_t Reserved_0    : 2;    /*!< Reserved bit                                */
            uint32_t GPIOHRST      : 1;    /*!< GPIOH reset                                 */
            uint32_t Reserved_1    : 5;    /*!< ADC1 and ADC2 reset                         */
            uint32_t ADCRST        : 1;    /*!< ADC3 reset                                  */
            uint32_t Reserved_3    : 18;   /*!< Reserved bits                               */
        } AHB2RSTR_register;
    };

    // RCC AHB3 鍜? AHB4 澶栬澶嶄綅瀵勫瓨鍣? (RCC_AHB3RSTR)			
		// 0x5800 0030
    union {
        __IO uint32_t AHB3RSTR;          /*!< RCC AHB3 and AHB4 peripheral reset register */
        struct AHB3RSTR_Register {
            uint32_t Reserved_0    : 8;   /*!< Reserved bits                               */
            uint32_t QUADSPIRST    : 1;    /*!< QUADSPI reset                               */
            uint32_t Reserved_1    : 7;   /*!< Reserved bits                               */
            uint32_t PKARST        : 1;    /*!< PKA reset                                   */
            uint32_t AES2RST       : 1;    /*!< AES2 reset                                  */
            uint32_t RNGRST        : 1;    /*!< RNG reset                                   */
            uint32_t HSEMRST       : 1;    /*!< HSEM reset                                  */
            uint32_t IPCCRST       : 1;    /*!< IPCC interface reset                        */
            uint32_t Reserved_2    : 4;   /*!< Reserved bits                               */
            uint32_t FLASHRST      : 1;    /*!< Flash interface reset                       */
            uint32_t Reserved_3    : 6;    /*!< Reserved bits                               */

			
        } AHB3RSTR_register;
    };

    uint32_t RESERVED_1;
    // RCC APB1 澶栬澶嶄綅瀵勫瓨鍣? 1 (RCC_APB1RSTR1)			
		// 0x5800 0038
    union {
        __IO uint32_t APB1RSTR1;         /*!< RCC APB1 peripheral reset register 1        */
        struct APB1RSTR1_Register {
            uint32_t TIM2RST       : 1;    /*!< TIM2 reset                                  */
            uint32_t Reserved_0    : 8;   /*!< Reserved bits                               */
            uint32_t LCDRST        : 1;    /*!< LCD reset                                   */
            uint32_t Reserved_1    : 4;   /*!< Reserved bits                               */
            uint32_t SPI2RST       : 1;    /*!< SPI2 reset                                  */
            uint32_t Reserved_2    : 6;   /*!< Reserved bits                               */
            uint32_t I2C1RST       : 1;    /*!< I2C1 reset                                  */
            uint32_t Reserved_3    : 1;   /*!< Reserved bits                               */
            uint32_t I2C3RST       : 1;    /*!< I2C3 reset                                  */
            uint32_t CRSRST        : 1;    /*!< CRS reset                                   */
            uint32_t Reserved_4    : 1;   /*!< Reserved bits                               */
            uint32_t USBFSRST      : 1;    /*!< USBFS reset                                 */
            uint32_t Reserved_5    : 4;   /*!< Reserved bits                               */
            uint32_t LPTIM1RST     : 1;    /*!< LPTIM1 reset                                */
        } APB1RSTR1_register;
    };

    // RCC APB1 澶栬澶嶄綅瀵勫瓨鍣? 2 (RCC_APB1RSTR2)			
		// 0x5800 003C
    union {
        __IO uint32_t APB1RSTR2;         /*!< RCC APB1 peripheral reset register 2        */
        struct APB1RSTR2_Register {
            uint32_t LPUART1RST    : 1;    /*!< LPUART1 reset                               */
            uint32_t Reserved_0    : 4;    /*!< Reserved bits                               */
            uint32_t LPTIM2RST     : 1;    /*!< LPTIM2 reset                                */
            uint32_t Reserved_1    : 26;   /*!< Reserved bits                               */
        } APB1RSTR2_register;
    };

    // RCC APB2 澶栬澶嶄綅瀵勫瓨鍣? (RCC_APB2RSTR)			
		// 0x5800 0040
    union {
        __IO uint32_t APB2RSTR;          /*!< RCC APB2 peripheral reset register          */
        struct APB2RSTR_Register {
            uint32_t Reserved_0    : 11;    /*!< Reserved bits                               */
            uint32_t TIM1RST       : 1;    /*!< TIM1 reset                                  */
            uint32_t SPI1RST       : 1;    /*!< SPI1 reset                                  */
            uint32_t Reserved_1    : 1;    /*!< Reserved bits                               */
            uint32_t USART1RST     : 1;    /*!< USART1 reset                                */
            uint32_t Reserved_2    : 2;    /*!< Reserved bits                               */
            uint32_t TIM16RST      : 1;    /*!< TIM16 reset                                 */
            uint32_t TIM17RST      : 1;    /*!< TIM17 reset                                 */
            uint32_t Reserved_3    : 2;    /*!< Reserved bits                               */
            uint32_t SAI1RST       : 1;    /*!< SAI1 reset                                  */
            uint32_t RESERVED31    : 10;   /*!< Reserved bits                               */
        } APB2RSTR_register;
    };

    // RCC APB3 澶栬澶嶄綅瀵勫瓨鍣? (RCC_APB3RSTR)			
		// 0x5800 0044
    union {
        __IO uint32_t APB3RSTR;          /*!< RCC APB3 peripheral reset register          */
        struct APB3RSTR_Register {
            uint32_t RFRST         : 1;    /*!< Radio system reset                          */
            uint32_t Reserved_0    : 31;   /*!< Reserved bits                               */
        } APB3RSTR_register;
    };

    // RCC AHB1 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_AHB1ENR)			
		// 0x5800 0048
    union {
        __IO uint32_t AHB1ENR;           /*!< RCC AHB1 peripheral clock enable register   */
        struct AHB1ENR_Register {
            uint32_t DMA1EN        : 1;    /*!< DMA1 clock enable                           */
            uint32_t DMA2EN        : 1;    /*!< DMA2 clock enable                           */
            uint32_t DMAMUX1EN     : 1;    /*!< DMAMUX clock enable                          */
            uint32_t Reserved_0    : 9;   /*!< Reserved bits                               */
            uint32_t CRCEN         : 1;    /*!< CRC clock enable                            */
            uint32_t Reserved_1    : 3;   /*!< Reserved bits                               */
            uint32_t TSCEN         : 1;    /*!< TSC clock enable                            */
            uint32_t Reserved_2    : 15;   /*!< Reserved bits                               */
        } AHB1ENR_register;
    };

    // RCC AHB2 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_AHB2ENR)			
		// 0x5800 004C
    union {
        __IO uint32_t AHB2ENR;           /*!< RCC AHB2 peripheral clock enable register   */
        struct AHB2ENR_Register {
            uint32_t GPIOAEN       : 1;    /*!< GPIOA clock enable                          */
            uint32_t GPIOBEN       : 1;    /*!< GPIOB clock enable                          */
            uint32_t GPIOCEN       : 1;    /*!< GPIOC clock enable                          */
            uint32_t GPIODEN       : 1;    /*!< GPIOD clock enable                          */
            uint32_t GPIOEEN       : 1;    /*!< GPIOE clock enable                          */
            uint32_t Reserved_0    : 2;   /*!< Reserved bits                               */
            uint32_t GPIOHEN       : 1;    /*!< GPIOH clock enable                          */
            uint32_t Reserved_1    : 5;   /*!< Reserved bits                               */
            uint32_t ADCEN		   : 1;    /*!< ADC clock enable                  */
            uint32_t Reserved_2    : 2;    /*!< Reserved bits                               */
            uint32_t AES1EN        : 1;    /*!< AES1 clock enable                           */
            uint32_t Reserved_3    : 15;   /*!< Reserved bits                               */
        } AHB2ENR_register;
    };

    // RCC AHB3 鍜? AHB4 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_AHB3ENR)			
		// 0x5800 0050
    union {
        __IO uint32_t AHB3ENR;           /*!< RCC AHB3 and AHB4 peripheral clock enable register */
        struct AHB3ENR_Register {
            uint32_t Reserved_0    : 8;   /*!< Reserved bits                               */
            uint32_t QUADSPIEN     : 1;    /*!< QUADSPI clock enable                        */
            uint32_t Reserved_1    : 7;   /*!< Reserved bits                               */
            uint32_t PKAEN         : 1;    /*!< PKA clock enable                            */
            uint32_t AES2EN        : 1;    /*!< AES2 clock enable                           */
            uint32_t RNGEN         : 1;    /*!< RNG clock enable                            */
            uint32_t HSEMEN        : 1;    /*!< HSEM clock enable                           */
            uint32_t IPCCEN        : 1;    /*!< IPCC interface clock enable                 */
            uint32_t Reserved_2    : 4;   /*!< Reserved bits                               */
            uint32_t FLASHEN       : 1;    /*!< Flash interface clock enable                */
            uint32_t Reserved_3    : 6;   /*!< Reserved bits                               */
        } AHB3ENR_register;
    };

    uint32_t RESERVED_2;
    // RCC APB1 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? 1 (RCC_APB1ENR1)			
		// 0x5800 0058
    union {
        __IO uint32_t APB1ENR1;          /*!< RCC APB1 peripheral clock enable register 1 */
        struct APB1ENR1_Register {
            uint32_t TIM2EN        : 1;    /*!< TIM2 clock enable                           */
            uint32_t Reserved_0    : 8;   /*!< Reserved bits                               */
            uint32_t LCDEN         : 1;    /*!< LCD clock enable                            */
            uint32_t RTCAPBEN      : 1;    /*!< RTC APB clock enable                        */
            uint32_t WWDGEN        : 1;    /*!< CPU1 Window watchdog clock enable          */
            uint32_t Reserved_1    : 2;   /*!< Reserved bits                               */
            uint32_t SPI2EN        : 1;    /*!< SPI2 clock enable                           */
            uint32_t Reserved_2    : 6;   /*!< Reserved bits                               */
            uint32_t I2C1EN        : 1;    /*!< I2C1 clock enable                           */
            uint32_t Reserved_3    : 1;   /*!< Reserved bits                               */
            uint32_t I2C3EN        : 1;    /*!< I2C3 clock enable                           */
            uint32_t CRSEN         : 1;    /*!< CRS clock enable                            */
            uint32_t Reserved_4    : 1;   /*!< Reserved bits                               */
            uint32_t USBFSEN       : 1;    /*!< USBFS clock enable                          */
            uint32_t Reserved_5    : 4;   /*!< Reserved bits                               */
            uint32_t LPTIM1EN      : 1;    /*!< LPTIM1 clock enable                         */
        } APB1ENR1_register;
    };

    // RCC APB1 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? 2 (RCC_APB1ENR2)			
		// 0x5800 005C
    union {
        __IO uint32_t APB1ENR2;          /*!< RCC APB1 peripheral clock enable register 2 */
        struct APB1ENR2_Register {
            uint32_t LPUART1EN     : 1;    /*!< LPUART1 clock enable                        */
            uint32_t Reserved_0    : 4;    /*!< Reserved bits                               */
            uint32_t LPTIM2EN      : 1;    /*!< LPTIM2 clock enable                         */
            uint32_t Reserved_1    : 26;   /*!< Reserved bits                               */
        } APB1ENR2_register;
    };

    // RCC APB2 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_APB2ENR)			
		// 0x5800 0060
    union {
        __IO uint32_t APB2ENR;           /*!< RCC APB2 peripheral clock enable register   */
        struct APB2ENR_Register {
            uint32_t Reserved_0    : 11;    /*!< Reserved bits                               */
            uint32_t TIM1EN        : 1;    /*!< TIM1 clock enable                           */
            uint32_t SPI1EN        : 1;    /*!< SPI1 clock enable                           */
            uint32_t Reserved_1    : 1;    /*!< Reserved bits                               */
            uint32_t USART1EN      : 1;    /*!< USART1 clock enable                         */
            uint32_t Reserved_2    : 2;    /*!< Reserved bits                               */
            uint32_t TIM16EN       : 1;    /*!< TIM16 clock enable                          */
            uint32_t TIM17EN       : 1;    /*!< TIM17 clock enable                          */
            uint32_t Reserved_3    : 2;    /*!< Reserved bits                               */
            uint32_t SAI1EN        : 1;    /*!< SAI1 clock enable                           */
            uint32_t Reserved_4    : 10;   /*!< Reserved bits                               */
        } APB2ENR_register;
    };

    uint32_t RESERVED_3;
    // 鐫＄湢妯″紡涓嬬殑 RCC AHB1 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_AHB1SMENR)			
		// 0x5800 0068
    union {
        __IO uint32_t AHB1SMENR;         /*!< RCC AHB1 peripheral clocks enable in Sleep modes register */
        struct AHB1SMENR_Register {
            uint32_t DMA1SMEN     : 1;    /*!< DMA1 clock enable in Sleep mode              */
            uint32_t DMA2SMEN     : 1;    /*!< DMA2 clock enable in Sleep mode              */
            uint32_t DMAMUX1SMEN  : 1;    /*!< DMAMUX1 clock enable in Sleep mode             */
            uint32_t Reserved_0   : 6;    /*!< Reserved bits                               */
            uint32_t SRAM1SMEN    : 1;    /*!< SRAM1 clock enable in Sleep mode             */
            uint32_t Reserved_1   : 2;    /*!< Reserved bits                               */
            uint32_t CRCSMEN      : 1;    /*!< CRC clock enable in Sleep mode               */
            uint32_t Reserved_3   : 3;    /*!< Reserved bits                               */
            uint32_t TSCSMEN      : 1;    /*!< TSC clock enable in Sleep mode               */
            uint32_t Reserved_4   : 15;   /*!< Reserved bits                                */
        } AHB1SMENR_register;
    };

    // 鐫＄湢妯″紡涓嬬殑 RCC AHB2 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_AHB2SMENR)
		// 0x5800 006C
    union {
        __IO uint32_t AHB2SMENR;         /*!< RCC AHB2 peripheral clocks enable in Sleep modes register */
        struct AHB2SMENR_Register {
            uint32_t GPIOASMEN    : 1;    /*!< GPIOA clock enable in Sleep mode             */
            uint32_t GPIOBSMEN    : 1;    /*!< GPIOB clock enable in Sleep mode             */
            uint32_t GPIOCSMEN    : 1;    /*!< GPIOC clock enable in Sleep mode             */
            uint32_t GPIODSMEN    : 1;    /*!< GPIOD clock enable in Sleep mode             */
            uint32_t GPIOESMEN    : 1;    /*!< GPIOE clock enable in Sleep mode             */
            uint32_t Reserved_0   : 2;    /*!< Reserved bits                               */
            uint32_t GPIOHSMEN    : 1;    /*!< GPIOH clock enable in Sleep mode             */
            uint32_t Reserved_1   : 5;    /*!< Reserved bits                               */
            uint32_t ADCSMEN      : 1;    /*!< ADC3 clock enable in Sleep mode              */
            uint32_t Reserved_2   : 2;    /*!< Reserved bits                               */
            uint32_t AES1SMEN     : 1;    /*!< AES1 clock enable in Sleep mode              */
            uint32_t Reserved_3   : 15;   /*!< Reserved bits                                */
        } AHB2SMENR_register;
    };

    // 鐫＄湢鍜屽仠姝㈡ā寮忎笅鐨? RCC AHB3 鍜? AHB4 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_AHB3SMENR)
		//		0x5800 0070
    union {
        __IO uint32_t AHB3SMENR;         /*!< RCC AHB3 and AHB4 peripheral clocks enable in Sleep and Stop modes register */
        struct AHB3SMENR_Register {
            uint32_t Reserved_0   : 8;    /*!< Reserved bits                               */
            uint32_t QUADSPISMEN  : 1;    /*!< QUADSPI clock enable in Sleep mode           */
            uint32_t Reserved_1   : 7;    /*!< Reserved bits                               */
            uint32_t PKASMEN      : 1;    /*!< PKA clock enable in Sleep mode               */
            uint32_t AES2SMEN     : 1;    /*!< AES2 clock enable in Sleep mode              */
            uint32_t RNGSMEN      : 1;    /*!< RNG clock enable in Sleep mode               */
            uint32_t Reserved_2   : 5;    /*!< Reserved bits                               */
            uint32_t SRAM2SMEN    : 1;    /*!< SRAM2a and SRAM2b memory interface clock enable during CPU1 CSleep mode  */
            uint32_t FLASHSMEN    : 1;    /*!< Flash interface clock enable in Sleep mode   */
            uint32_t Reserved_3   : 6;   /*!< Reserved bits                                */
        } AHB3SMENR_register;
    };

    uint32_t RESERVED_4;
    // 鐫＄湢妯″紡涓嬬殑 RCC APB1 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? 1 (RCC_APB1SMENR1)
		//		0x5800 0078
	union {
		__IO uint32_t APB1SMENR1;		  /*!< RCC APB1 peripheral clocks enable in Sleep mode register 1 */
		struct APB1SMENR1_Register {
			uint32_t TIM2SMEN	  : 1;	  /*!< 浣?0: TIM2 clock enable in Sleep/Stop mode				*/
			uint32_t Reserved_0   : 8;	  /*!< 浣?1~8: 淇濈暀浣?										   */
			uint32_t LSESMEN	  : 1;	  /*!< 浣?9: LSE clock enable in Sleep mode (娉細鍥剧墖涓綅9鏄疞SESMEN) */
			uint32_t RTCAPBSMEN   : 1;	  /*!< 浣?10: RTC APB clock enable in Sleep mode				*/
			uint32_t WWDGSMEN	  : 1;	  /*!< 浣?11: WWDG clock enable in Sleep/Stop mode				*/
			uint32_t Reserved_1   : 2;	  /*!< 淇濈暀浣? 								   */
			uint32_t SPI2SMEN	  : 1;	  /*!< 浣?14: SPI2 clock enable in Sleep/Stop mode				*/
			uint32_t Reserved_2   : 6;   /*!< 淇濈暀浣?										  */
			uint32_t I2C1SMEN	  : 1;	  /*!< 浣?28: I2C1 clock enable in Sleep/Stop mode				*/
			uint32_t Reserved_3   : 1;   /*!< 淇濈暀浣?										  */
			uint32_t I2C3SMEN	  : 1;	  /*!< 浣?29: I2C3 clock enable in Sleep/Stop mode				*/
			uint32_t CRSSMEN	  : 1;	  /*!< 浣?30: CRS clock enable in Sleep mode					*/
			uint32_t Reserved_4   : 1;   /*!< 淇濈暀浣?										  */
			uint32_t USBSMEN	  : 1;	  /*!< 浣?26: USB FS clock enable in Sleep/Stop mode			*/
			uint32_t Reserved_5   : 4;   /*!< 淇濈暀浣?										  */
			uint32_t LPTIM1SMEN   : 1;	  /*!< 浣?31: LPTIM1 clock enable in Sleep/Stop mode			*/
		} APB1SMENR1_register;
	};


    // 鐫＄湢妯″紡涓嬬殑 RCC APB1 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? 2 (RCC_APB1SMENR2)
		//		0x5800 007C
		union {
        __IO uint32_t APB1SMENR2;        /*!< RCC APB1 peripheral clocks enable in Sleep mode register 2 */
        struct APB1SMENR2_Register {
            uint32_t LPUART1SMEN   : 1;    /*!< LPUART1 clock enable in Sleep mode           */
            uint32_t Reserved_0    : 4;    /*!< Reserved bits                                */
            uint32_t LPTIM2SMEN    : 1;    /*!< LPTIM2 clock enable in Sleep mode            */
            uint32_t Reserved_1    : 26;   /*!< Reserved bits                                */
        } APB1SMENR2_register;
    };

    // 鐫＄湢妯″紡涓嬬殑 RCC APB2 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_APB2SMENR)
		//		0x5800 0080
		union {
		__IO uint32_t APB2SMENR;		  /*!< RCC APB2 peripheral clocks enable in Sleep mode register */
		struct APB2SMENR_Register {
			uint32_t Reserved_0   : 11;   /*!< 浣?0~15: 淇濈暀浣嶏紙鍏朵腑浣?10銆?12銆?13銆?14涓烘湁鏁堜綅锛屽叾浣欎负淇濈暀锛? */
			uint32_t TIM1SMEN	  : 1;	  /*!< 浣?10: TIM1 clock enable in Sleep/Stop mode */
			uint32_t SPI1SMEN	  : 1;	  /*!< 浣?12: SPI1 clock enable in Sleep/Stop mode */
			uint32_t Reserved_1   : 1;	  /*!< 浣?17銆?19~20: 淇濈暀浣? */
			uint32_t USART1SMEN   : 1;	  /*!< 浣?14: USART1 clock enable in Sleep/Stop mode */
			uint32_t Reserved_2   : 2;   /*!< 浣?22~31: 淇濈暀浣? */
			uint32_t TIM16SMEN	  : 1;	  /*!< 浣?16: TIM16 clock enable in Sleep/Stop mode */
			uint32_t TIM17SMEN	  : 1;	  /*!< 浣?18: TIM17 clock enable in Sleep/Stop mode */
			uint32_t Reserved_3   : 2;   /*!< 浣?22~31: 淇濈暀浣? */
			uint32_t SAI1SMEN	  : 1;	  /*!< 浣?21: SAI1 clock enable in Sleep/Stop mode */
			uint32_t Reserved_4   : 10;   /*!< 浣?22~31: 淇濈暀浣? */
		} APB2SMENR_register;
	};


    uint32_t RESERVED_5;
    // RCC 澶栬鐙珛鏃堕挓閰嶇疆瀵勫瓨鍣? (RCC_CCIPR)
		//		0x5800 0088
		union {
		__IO uint32_t CCIPR;			  /*!< RCC peripherals independent clock configuration register */
		struct CCIPR_Register {
			uint32_t USART1SEL		: 2;  /*!< 浣?0~1: USART1 clock source selection */
			uint32_t Reserved_0 	: 8; /*!< 浣?2~11: 淇濈暀浣? */
			uint32_t LPUART1SEL 	: 2;  /*!< 浣?12~13: LPUART1 clock source selection */
			uint32_t I2C2SEL		: 2;  /*!< 浣?14~15: I2C2 clock source selection */
			uint32_t Reserved_1 	: 2;  /*!< 浣?24~25: 淇濈暀浣? */
			uint32_t I2C3SEL		: 2;  /*!< 浣?16~17: I2C3 clock source selection */
			uint32_t LPTIM1SEL		: 2;  /*!< 浣?18~19: LPTIM1 clock source selection */
			uint32_t LPTIM2SEL		: 2;  /*!< 浣?20~21: LPTIM2 clock source selection */
			uint32_t SAI1SEL		: 2;  /*!< 浣?22~23: SAI1 clock source selection */
			uint32_t Reserved_2 	: 2;  /*!< 浣?24~25: 淇濈暀浣? */
			uint32_t CLK48SEL		: 2;  /*!< 浣?26~27: 48 MHz clock source selection */
			uint32_t ADCSEL 		: 2;  /*!< 浣?28~29: ADC clock source selection */
			uint32_t RNGSEL 		: 2;  /*!< 浣?30~31: RNG clock source selection */
		} CCIPR_register;
	};


    uint32_t RESERVED_6;
    // RCC 澶囦唤鍩熸帶鍒跺瘎瀛樺櫒 (RCC_BDCR)
		//		0x5800 0090
    union {
        __IO uint32_t BDCR;              /*!< RCC backup domain control register           */
        struct BDCR_Register {
            uint32_t LSEON        : 1;    /*!< LSE oscillator enable                        */
            uint32_t LSERDY       : 1;    /*!< LSE oscillator ready flag                    */
            uint32_t LSEBYP       : 1;    /*!< LSE oscillator bypass                        */
            uint32_t LSEDRV       : 2;		// LSE 鎸崱鍣ㄩ┍鍔ㄨ兘鍔?
            uint32_t LSECSSON     : 1;    /*!< LSE CSS enable                               */
            uint32_t LSECSSD      : 1;    // LSE 涓婄殑 CSS 鏁呴殰妫?娴?
            uint32_t Reserved_0   : 1;    /*!< Reserved bit                                 */
            uint32_t RTCSEL       : 2;    /*!< RTC clock source selection                   */
            uint32_t Reserved_1   : 5;    /*!< Reserved bits                                */
            uint32_t RTCEN        : 1;    /*!< RTC clock enable                             */
            uint32_t BDRST        : 1;    /*!< Backup domain software reset                 */
            uint32_t Reserved_2   : 7;   /*!< Reserved bits                                */
            uint32_t LSCOEN       : 1;    /*!< Low speed clock output enable                */
            uint32_t LSCOSEL      : 1;    /*!< Low speed clock output selection             */
            uint32_t Reserved_3   : 6;   /*!< Reserved bits                                */
        } BDCR_register;
    };

    // RCC 鎺у埗/鐘舵?佸瘎瀛樺櫒 (RCC_CSR)
		//		0x5800 0094
	union {
		__IO uint32_t CSR;				  /*!< RCC control/status register					 */
		struct CSR_Register {
			uint32_t LSI1ON 	   : 1;    /*!< 浣?0: LSI1 oscillator enable					*/
			uint32_t LSI1RDY	   : 1;    /*!< 浣?1: LSI1 oscillator ready flag				*/
			uint32_t LSI2ON 	   : 1;    /*!< 浣?2: LSI2 oscillator enable					*/
			uint32_t LSI2RDY	   : 1;    /*!< 浣?3: LSI2 oscillator ready flag				*/
			uint32_t Reserved_0    : 4;    /*!< 浣?4~7: Reserved bits							*/
			uint32_t LSI2TRIM	   : 4;    /*!< 浣?8~11: LSI2 oscillator trimming				*/
			uint32_t Reserved_1    : 2;    /*!< 浣?12~13: Reserved bits 						*/
			uint32_t RFWKPSEL	   : 2;    /*!< 浣?14~15: RF wakeup clock source selection		*/
			uint32_t RFRSTSF	   : 1;    /*!< 浣?16: RF reset status flag (read-only) 		*/
			uint32_t Reserved_2    : 6;    /*!< 浣?17~23: Reserved bits 						*/
			uint32_t RMVF		   : 1;    /*!< 浣?24: Reset flags clear						*/
			uint32_t Reserved_3    : 1;    /*!< 浣?25: Reserved bit 							*/
			uint32_t OBLRSTF	   : 1;    /*!< 浣?26: Option byte load reset flag (read-only)	*/
			uint32_t PINRSTF	   : 1;    /*!< 浣?27: Pin reset flag (read-only)				*/
			uint32_t BORRSTF	   : 1;    /*!< 浣?28: Brownout reset flag (read-only)			*/
			uint32_t SFTRSTF	   : 1;    /*!< 浣?29: Software reset flag (read-only)			*/
			uint32_t IWWGRSTF	   : 1;    /*!< 浣?30: Independent watchdog reset flag (read-only) */
			uint32_t WWDGRSTF	   : 1;    /*!< 浣?31: Window watchdog reset flag (read-only)	*/
			uint32_t LPWRRSTF	   : 1;    /*!< 浣?31: Low-power reset flag (read-only) 		*/
		} CSR_register;
	};


    // RCC 鏃堕挓鎭㈠ RC 瀵勫瓨鍣? (RCC_CRRCR)
		//		0x5800 0098
    union {
        __IO uint32_t CRRCR;             /*!< RCC Clock recovery RC register              */
        struct CRRCR_Register {
            uint32_t HSI48ON     : 1;    /*!< HSI48 clock enable                          */
            uint32_t HSI48RDY    : 1;    /*!< HSI48 clock ready flag                      */
            uint32_t Reserved_0  : 5;    /*!< Reserved bits                               */
            uint32_t HSI48CAL    : 9;    /*!< HSI48 clock calibration                     */
            uint32_t Reserved_1  : 16;   /*!< Reserved bits                               */
        } CRRCR_register;
    };

    // RCC 鏃堕挓 HSE 瀵勫瓨鍣? (RCC_HSECR)
		//		0x5800 009C
	union {
		__IO uint32_t HSECR;			  /*!< RCC clock HSE register */
		struct HSECR_Register {
			uint32_t UNLOCKED	  : 1;	  /*!< 浣?0: Unlocked status */
			uint32_t Reserved_0   : 2;	  /*!< 浣?1~2: Reserved bits */
			uint32_t HSES		  : 1;	  /*!< 浣?3: HSE enable status */
			uint32_t HSEGMC 	  : 3;	  /*!< 浣?4~6: HSE gain margin control */
			uint32_t Reserved_1   : 1;	  /*!< 浣?7: Reserved bit */
			uint32_t HSETUNE	  : 6;	  /*!< 浣?8~13: HSE tuning */
			uint32_t Reserved_2   : 2;	  /*!< 浣?14~15: Reserved bits */
			uint32_t Reserved_3   : 16;   /*!< 浣?16~31: Reserved bits */
		} HSECR_register;
	};


    uint32_t RESERVED_7[26];
    // RCC 鎵╁睍鏃堕挓鎭㈠瀵勫瓨鍣? (RCC_EXTCFGR)
		//		0x5800 0108
	union {
		__IO uint32_t EXTCCFGR; 		  /*!< RCC extended clock recovery register */
		struct EXTCCFGR_Register {
			uint32_t SHDHPRE	  : 4;	  /*!< SHDH prescaler */
			uint32_t C2HPRE 	  : 4;	  /*!< C2H prescaler */
			uint32_t Reserved_0   : 8;	  /*!< Reserved bits */
			uint32_t SHDHPREF	  : 1;	  /*!< SHDH prescaler flag */
			uint32_t C2HPREF	  : 1;	  /*!< C2H prescaler flag */
			uint32_t Reserved_1   : 2;	  /*!< Reserved bits */
			uint32_t RFCSS		  : 1;	  /*!< RFCSS flag */
			uint32_t Reserved_2   : 11;   /*!< Reserved bits */
		} EXTCCFGR_register;
	};


    uint32_t RESERVED_8[15];
    // RCC CPU2 AHB1 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_C2AHB1ENR)
		//		0x5800 0148
	union {
		__IO uint32_t C2AHB1ENR;		  /*!< RCC CPU2 AHB1 peripheral clock enable register */
		struct C2AHB1ENR_Register {
			uint32_t DMA1EN 	  : 1;	  /*!< DMA1 clock enable */
			uint32_t DMA2EN 	  : 1;	  /*!< DMA2 clock enable */
			uint32_t DMAMUX1EN	  : 1;	  /*!< DMAMUX1 clock enable */
			uint32_t Reserved_0   : 6;	  /*!< Reserved bits */
			uint32_t SRAM1EN	  : 1;	  /*!< SRAM1 clock enable */
			uint32_t Reserved_1   : 2;	  /*!< Reserved bits */
			uint32_t CRCEN		  : 1;	  /*!< CRC clock enable */
			uint32_t Reserved_2   : 3;	  /*!< Reserved bits */
			uint32_t TSCEN		  : 1;	  /*!< TSC clock enable */
			uint32_t Reserved_3   : 15;   /*!< Reserved bits */
		} C2AHB1ENR_register;
	};


    // RCC CPU2 AHB2 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_C2AHB2ENR)
		//		0x5800 014C
	union {
		__IO uint32_t C2AHB2ENR;		  /*!< RCC CPU2 AHB2 peripheral clock enable register */
		struct C2AHB2ENR_Register {
			uint32_t GPIOAEN	  : 1;	  /*!< GPIOA clock enable */
			uint32_t GPIOBEN	  : 1;	  /*!< GPIOB clock enable */
			uint32_t GPIOCEN	  : 1;	  /*!< GPIOC clock enable */
			uint32_t GPIODEN	  : 1;	  /*!< GPIOD clock enable */
			uint32_t GPIOEEN	  : 1;	  /*!< GPIOE clock enable */
			uint32_t Reserved_0   : 2;	  /*!< Reserved bits */
			uint32_t GPIOHEN	  : 1;	  /*!< GPIOH clock enable */
			uint32_t Reserved_1   : 5;	  /*!< Reserved bits */
			uint32_t ADCEN		  : 1;	  /*!< ADC clock enable */
			uint32_t Reserved_2   : 2;	  /*!< Reserved bits */
			uint32_t AES1EN 	  : 1;	  /*!< AES1 clock enable */
			uint32_t Reserved_3   : 15;   /*!< Reserved bits */
		} C2AHB2ENR_register;
	};


    // RCC CPU2 AHB3 鍜? AHB4 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_C2AHB3ENR)
		//		0x5800 0150
	union {
		__IO uint32_t C2AHB3ENR;		  /*!< RCC CPU2 AHB3 and AHB4 peripheral clock enable register */
		struct C2AHB3ENR_Register {
			uint32_t Reserved_0   : 16;   /*!< Reserved bits */
			uint32_t PKAEN		  : 1;	  /*!< PKA clock enable */
			uint32_t AES2EN 	  : 1;	  /*!< AES2 clock enable */
			uint32_t RNGEN		  : 1;	  /*!< RNG clock enable */
			uint32_t HSEMEN 	  : 1;	  /*!< HSEM clock enable */
			uint32_t IPCCEN 	  : 1;	  /*!< IPCC clock enable */
			uint32_t Reserved_1   : 4;	  /*!< Reserved bits */
			uint32_t FLASHEN	  : 1;	  /*!< FLASH clock enable */
			uint32_t Reserved_2   : 6;	  /*!< Reserved bits */
		} C2AHB3ENR_register;
	};


    uint32_t RESERVED_9;
    // RCC CPU2 APB1 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? 1 (RCC_C2APB1ENR1)
		//		0x5800 0158
		union {
			__IO uint32_t C2APB1ENR1;		  /*!< RCC CPU2 APB1 peripheral clock enable register 1 */
			struct C2APB1ENR1_Register {
				uint32_t TIM2EN 	  : 1;	  /*!< TIM2 clock enable */
				uint32_t Reserved_0   : 8;	  /*!< Reserved bits */
				uint32_t LCDEN		  : 1;	  /*!< LCD clock enable */
				uint32_t RTCAPBEN	  : 1;	  /*!< RTC APB clock enable */
				uint32_t Reserved_1   : 3;	  /*!< Reserved bits */
				uint32_t SPI2EN 	  : 1;	  /*!< SPI2 clock enable */
				uint32_t Reserved_2   : 6;	  /*!< Reserved bits */
				uint32_t I2C1EN 	  : 1;	  /*!< I2C1 clock enable */
				uint32_t Reserved_3   : 1;	  /*!< Reserved bit */
				uint32_t I2C3EN 	  : 1;	  /*!< I2C3 clock enable */
				uint32_t CRSEN		  : 1;	  /*!< CRS clock enable */
				uint32_t Reserved_4   : 1;	  /*!< Reserved bits */
				uint32_t USBEN		  : 1;	  /*!< USB clock enable */
				uint32_t Reserved_5   : 4;	  /*!< Reserved bits */
				uint32_t LPTIM1EN	  : 1;	  /*!< LPTIM1 clock enable */
			} C2APB1ENR1_register;
		};


    // RCC CPU2 APB1 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? 2 (RCC_C2APB1ENR2)
    //		0x5800 015C
		union {
			__IO uint32_t C2APB1ENR2;		  /*!< RCC CPU2 APB1 peripheral clock enable register 2 */
			struct C2APB1ENR2_Register {
				uint32_t LPUART1EN	  : 1;	  /*!< LPUART1 clock enable */
				uint32_t Reserved_0   : 4;	  /*!< Reserved bits */
				uint32_t LPTIM2EN	  : 1;	  /*!< LPTIM2 clock enable */
				uint32_t Reserved_1   : 26;   /*!< Reserved bits */
			} C2APB1ENR2_register;
		};


    // RCC CPU2 APB2 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_C2APB2ENR)
		//		0x5800 0160
		union {
			__IO uint32_t C2APB2ENR;		  /*!< RCC CPU2 APB2 peripheral clock enable register */
			struct C2APB2ENR_Register {
				uint32_t Reserved_0   : 11;	  /*!< Reserved bit */
				uint32_t TIM1EN 	  : 1;	  /*!< TIM1 clock enable */
				uint32_t SPI1EN 	  : 1;	  /*!< SPI1 clock enable */
				uint32_t Reserved_1   : 1;   /*!< Reserved bits */
				uint32_t USART1EN	  : 1;	  /*!< USART1 clock enable */
				uint32_t Reserved_2   : 2;   /*!< Reserved bits */
				uint32_t TIM16EN	  : 1;	  /*!< TIM16 clock enable */
				uint32_t TIM17EN	  : 1;	  /*!< TIM17 clock enable */
				uint32_t Reserved_3   : 2;	  /*!< Reserved bits */
				uint32_t SAI1EN 	  : 1;	  /*!< SAI1 clock enable */
				uint32_t Reserved_4   : 10;   /*!< Reserved bits */
			} C2APB2ENR_register;
		};

    // RCC CPU2 APB3 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_C2APB3ENR)
		//		0x5800 0164
		union {
        __IO uint32_t C2APB3ENR;         /*!< RCC CPU2 APB3 peripheral clock enable register */
        struct C2APB3ENR_Register {
            uint32_t BLEEN       : 1;    /*!< BLE interface clock enable for CPU2           */
            uint32_t _802EN		 : 1;    /*!< IEEE 802.15.4 interface clock enable for CPU2 */
            uint32_t Reserved_0  : 30;   /*!< Reserved bits                                 */
        } C2APB3ENR_register;
    };

    // 鐫＄湢妯″紡涓嬬殑 RCC CPU2 AHB1 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_C2AHB1SMENR)
		//		0x5800 0168
		union {
			__IO uint32_t C2AHB1SMENR;		  /*!< RCC CPU2 AHB1 peripheral clocks enable in Sleep mode register */
			struct C2AHB1SMENR_Register {
				uint32_t DMA1SMEN	  : 1;	  /*!< DMA1 clock enable in Sleep mode */
				uint32_t DMA2SMEN	  : 1;	  /*!< DMA2 clock enable in Sleep mode */
				uint32_t DMAMUX1SMEN  : 1;	  /*!< DMAMUX1 clock enable in Sleep mode */
				uint32_t Reserved_0   : 6;	  /*!< Reserved bits */
				uint32_t SRAM1SMEN	  : 1;	  /*!< SRAM1 clock enable in Sleep mode */
				uint32_t Reserved_1   : 2;	  /*!< Reserved bits */
				uint32_t CRCSMEN	  : 1;	  /*!< CRC clock enable in Sleep mode */
				uint32_t Reserved_2   : 3;	  /*!< Reserved bits */
				uint32_t TSCSMEN	  : 1;	  /*!< TSC clock enable in Sleep mode */
				uint32_t Reserved_3   : 15;   /*!< Reserved bits */
			} C2AHB1SMENR_register;
		};


    // 鐫＄湢妯″紡涓嬬殑 RCC CPU2 AHB2 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_C2AHB2SMENR)
		//		0x5800 016C
		union {
			__IO uint32_t C2AHB2SMENR;		  /*!< RCC CPU2 AHB2 peripheral clocks enable in Sleep mode register */
			struct C2AHB2SMENR_Register {
				uint32_t GPIOASMEN	  : 1;	  /*!< GPIOA clock enable in Sleep mode */
				uint32_t GPIOBSMEN	  : 1;	  /*!< GPIOB clock enable in Sleep mode */
				uint32_t GPIOCSMEN	  : 1;	  /*!< GPIOC clock enable in Sleep mode */
				uint32_t GPIODSMEN	  : 1;	  /*!< GPIOD clock enable in Sleep mode */
				uint32_t GPIOESMEN	  : 1;	  /*!< GPIOE clock enable in Sleep mode */
				uint32_t Reserved_0   : 2;	  /*!< Reserved bits */
				uint32_t GPIOHSMEN	  : 1;	  /*!< GPIOH clock enable in Sleep mode */
				uint32_t Reserved_1   : 5;	  /*!< Reserved bits */
				uint32_t ADCSMEN	  : 1;	  /*!< ADC clock enable in Sleep mode */
				uint32_t Reserved_2   : 2;	  /*!< Reserved bits */
				uint32_t AES1SMEN	  : 1;	  /*!< AES1 clock enable in Sleep mode */
				uint32_t Reserved_3   : 15;   /*!< Reserved bits */
			} C2AHB2SMENR_register;
		};


    // 鐫＄湢妯″紡涓嬬殑 RCC CPU2 AHB3 鍜? AHB4 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_C2AHB3SMENR)
		//		0x5800 0170
		union {
			__IO uint32_t C2AHB3SMENR;		  /*!< RCC CPU2 AHB3 and AHB4 peripheral clocks enable in Sleep mode register */
			struct C2AHB3SMENR_Register {
				uint32_t Reserved_0   : 16;   /*!< Reserved bits */
				uint32_t PKASMEN	  : 1;	  /*!< PKA clock enable in Sleep mode */
				uint32_t AES2SMEN	  : 1;	  /*!< AES2 clock enable in Sleep mode */
				uint32_t RNGSMEN	  : 1;	  /*!< RNG clock enable in Sleep mode */
				uint32_t Reserved_1   : 5;	  /*!< Reserved bits */
				uint32_t SRAM2SMEN	  : 1;	  /*!< SRAM2 clock enable in Sleep mode */
				uint32_t FLASHSMEN	  : 1;	  /*!< FLASH clock enable in Sleep mode */
				uint32_t Reserved_2   : 6;	  /*!< Reserved bits */
			} C2AHB3SMENR_register;
		};


    uint32_t RESERVED_10;
    // 鐫＄湢妯″紡涓嬬殑 RCC CPU2 APB1 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? 1 (RCC_C2APB1SMENR1)
		//		0x5800 0178
		union {
			__IO uint32_t C2APB1SMENR1; 	  /*!< RCC CPU2 APB1 peripheral clocks enable in Sleep mode register 1 */
			struct C2APB1SMENR1_Register {
				uint32_t TIM2SMEN	  : 1;	  /*!< TIM2 clock enable in Sleep mode */
				uint32_t Reserved_0   : 8;	  /*!< Reserved bits */
				uint32_t LCDSMEN	  : 1;	  /*!< LCD clock enable in Sleep mode */
				uint32_t RTCAPBSMEN   : 1;	  /*!< RTC APB clock enable in Sleep mode */
				uint32_t Reserved_1   : 3;	  /*!< Reserved bits */
				uint32_t SPI2SMEN	  : 1;	  /*!< SPI2 clock enable in Sleep mode */
				uint32_t Reserved_2   : 6;	  /*!< Reserved bits */
				uint32_t I2C1SMEN	  : 1;	  /*!< I2C1 clock enable in Sleep mode */
				uint32_t Reserved_3   : 1;	  /*!< Reserved bits */
				uint32_t I2C3SMEN	  : 1;	  /*!< I2C3 clock enable in Sleep mode */
				uint32_t CRSSMEN	  : 1;	  /*!< CRS clock enable in Sleep mode */
				uint32_t Reserved_4   : 1;	  /*!< Reserved bits */
				uint32_t USBSMEN	  : 1;	  /*!< USB clock enable in Sleep mode */
				uint32_t Reserved_5   : 4;	  /*!< Reserved bits */
				uint32_t LPTIM1SMEN   : 1;	  /*!< LPTIM1 clock enable in Sleep mode */
			} C2APB1SMENR1_register;
		};


    // 鐫＄湢妯″紡涓嬬殑 RCC CPU2 APB1 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? 2 (RCC_C2APB1SMENR2)
		//		0x5800 017C
		union {
			__IO uint32_t C2APB1SMENR2; 	  /*!< RCC CPU2 APB1 peripheral clocks enable in Sleep mode register 2 */
			struct C2APB1SMENR2_Register {
				uint32_t LPUART1SMEN  : 1;	  /*!< LPUART1 clock enable in Sleep mode */
				uint32_t Reserved_0   : 4;	  /*!< Reserved bits */
				uint32_t LPTIM2SMEN   : 1;	  /*!< LPTIM2 clock enable in Sleep mode */
				uint32_t Reserved_1   : 26;   /*!< Reserved bits */
			} C2APB1SMENR2_register;
		};


    // 鐫＄湢妯″紡涓嬬殑 RCC CPU2 APB2 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_C2APB2SMENR)
		//		0x5800 0180
		union {
			__IO uint32_t C2APB2SMENR;		  /*!< RCC CPU2 APB2 peripheral clocks enable in Sleep mode register */
			struct C2APB2SMENR_Register {
				uint32_t Reserved_0   : 11;	  /*!< Reserved bit */
				uint32_t TIM1SMEN	  : 1;	  /*!< TIM1 clock enable in Sleep mode */
				uint32_t SPI1SMEN	  : 1;	  /*!< SPI1 clock enable in Sleep mode */
				uint32_t Reserved_1   : 1;	  /*!< Reserved bit */
				uint32_t USART1SMEN   : 1;	  /*!< USART1 clock enable in Sleep mode */
				uint32_t Reserved_2   : 2;   /*!< Reserved bits */
				uint32_t TIM16SMEN	  : 1;	  /*!< TIM16 clock enable in Sleep mode */
				uint32_t TIM17SMEN	  : 1;	  /*!< TIM17 clock enable in Sleep mode */
				uint32_t Reserved_3   : 2;	  /*!< Reserved bits */
				uint32_t SAI1SMEN	  : 1;	  /*!< SAI1 clock enable in Sleep mode */
				uint32_t Reserved_4   : 10;   /*!< Reserved bits */
			} C2APB2SMENR_register;
		};


    // 鐫＄湢妯″紡涓嬬殑 RCC CPU2 APB3 澶栬鏃堕挓浣胯兘瀵勫瓨鍣? (RCC_C2APB3SMENR)
		//		0x5800 0184
		union {
			__IO uint32_t C2APB3SMENR;		  /*!< RCC CPU2 APB3 peripheral clock enable in Sleep mode register */
			struct C2APB3SMENR_Register {
				uint32_t BLESMEN	  : 1;	  /*!< BLE clock enable in Sleep mode */
				uint32_t _802S1SMEN	  : 1;	  /*!< 802.15.4 interface bus clock enable in Sleep mode */
				uint32_t Reserved_0   : 30;   /*!< Reserved bits */
			} C2APB3SMENR_register;
		};

} WROS_RCC_TypeDef;








/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/




// 				SYSCFG




typedef struct {
    // SYSCFG 瀛樺偍鍣ㄩ噸鏄犲皠瀵勫瓨鍣? (SYSCFG_MEMRMP)锛屽亸绉诲湴鍧?锛?0x00
    union {
        __IO uint32_t MEMRMP;
        struct MEMRMP_Register {
            uint32_t MEM_MODE : 3; /*!< 瀛樺偍鍣ㄦ槧灏勯?夋嫨 */
            uint32_t RESERVED0 : 29; /*!< 淇濈暀浣? */
        } MEMRMP_register;
    };

    // SYSCFG 閰嶇疆瀵勫瓨鍣? 1 (SYSCFG_CFGFR1)锛屽亸绉诲湴鍧?锛?0x04
    union {
        __IO uint32_t CFGR1;
        struct CFGR1_Register {
            uint32_t FPU_IE0 : 1; /*!< FPU 鏃犳搷浣滀腑鏂娇鑳? */
            uint32_t FPU_IE1 : 1; /*!< FPU 涓嬫孩涓柇浣胯兘 */
            uint32_t FPU_IE2 : 1; /*!< FPU 涓婃孩涓柇浣胯兘 */
            uint32_t FPU_IE3 : 1; /*!< FPU 杈撳叆闈炲父瑙勪腑鏂娇鑳? */
            uint32_t FPU_IE4 : 1; /*!< FPU 涓嶇簿纭殑涓柇浣胯兘 */
            uint32_t FPU_IE5 : 1; /*!< FPU 杈撳叆寮傚父涓柇浣胯兘 */
            uint32_t RESERVED1 : 1; /*!< 淇濈暀浣? */
            uint32_t BOOST_EN : 1; /*!< BOOST 浣胯兘 */
            uint32_t I2C_PB7_FMP : 1; /*!< I2C_PB7 涓婄殑瓒呭揩閫熸ā寮忛┍鍔ㄥ姛鑳芥縺娲? */
            uint32_t I2C_PB8_FMP : 1; /*!< I2C_PB8 涓婄殑瓒呭揩閫熸ā寮忛┍鍔ㄥ姛鑳芥縺娲? */
            uint32_t I2C_PB9_FMP : 1; /*!< I2C_PB9 涓婄殑瓒呭揩閫熸ā寮忛┍鍔ㄥ姛鑳芥縺娲? */
            uint32_t I2C1_FMP : 1; /*!< I2C1 瓒呭揩閫熸ā寮忛┍鍔ㄥ姛鑳芥縺娲? */
            uint32_t I2C3_FMP : 1; /*!< I2C3 瓒呭揩閫熸ā寮忛┍鍔ㄥ姛鑳芥縺娲? */
            uint32_t RESERVED2 : 19; /*!< 淇濈暀浣? */
        } CFGR1_register;
    };

    // SYSCFG 澶栭儴涓柇閰嶇疆瀵勫瓨鍣? 1 (SYSCFG_EXTICR1)锛屽亸绉诲湴鍧?锛?0x08
    union {
        __IO uint32_t EXTICR1;
        struct EXTICR1_Register {
            uint32_t EXTI0 : 3; /*!< EXTI0 閰嶇疆浣? */
            uint32_t RESERVED3 : 1; /*!< 淇濈暀浣? */
            uint32_t EXTI1 : 3; /*!< EXTI1 閰嶇疆浣? */
            uint32_t RESERVED4 : 1; /*!< 淇濈暀浣? */
            uint32_t EXTI2 : 3; /*!< EXTI2 閰嶇疆浣? */
            uint32_t RESERVED5 : 1; /*!< 淇濈暀浣? */
            uint32_t EXTI3 : 3; /*!< EXTI3 閰嶇疆浣? */
            uint32_t RESERVED6 : 17; /*!< 淇濈暀浣? */
        } EXTICR1_register;
    };

    // SYSCFG 澶栭儴涓柇閰嶇疆瀵勫瓨鍣? 2 (SYSCFG_EXTICR2)锛屽亸绉诲湴鍧?锛?0x0C
    union {
        __IO uint32_t EXTICR2;
        struct EXTICR2_Register {
            uint32_t EXTI4 : 3; /*!< EXTI4 閰嶇疆浣? */
            uint32_t RESERVED7 : 1; /*!< 淇濈暀浣? */
            uint32_t EXTI5 : 3; /*!< EXTI5 閰嶇疆浣? */
            uint32_t RESERVED8 : 1; /*!< 淇濈暀浣? */
            uint32_t EXTI6 : 3; /*!< EXTI6 閰嶇疆浣? */
            uint32_t RESERVED9 : 1; /*!< 淇濈暀浣? */
            uint32_t EXTI7 : 3; /*!< EXTI7 閰嶇疆浣? */
            uint32_t RESERVED10 : 17; /*!< 淇濈暀浣? */
        } EXTICR2_register;
    };

    // SYSCFG 澶栭儴涓柇閰嶇疆瀵勫瓨鍣? 3 (SYSCFG_EXTICR3)锛屽亸绉诲湴鍧?锛?0x10
    union {
        __IO uint32_t EXTICR3;
        struct EXTICR3_Register {
            uint32_t EXTI8 : 3; /*!< EXTI8 閰嶇疆浣? */
            uint32_t RESERVED11 : 1; /*!< 淇濈暀浣? */
            uint32_t EXTI9 : 3; /*!< EXTI9 閰嶇疆浣? */
            uint32_t RESERVED12 : 1; /*!< 淇濈暀浣? */
            uint32_t EXTI10 : 3; /*!< EXTI10 閰嶇疆浣? */
            uint32_t RESERVED13 : 1; /*!< 淇濈暀浣? */
            uint32_t EXTI11 : 3; /*!< EXTI11 閰嶇疆浣? */
            uint32_t RESERVED14 : 17; /*!< 淇濈暀浣? */
        } EXTICR3_register;
    };

    // SYSCFG 澶栭儴涓柇閰嶇疆瀵勫瓨鍣? 4 (SYSCFG_EXTICR4)锛屽亸绉诲湴鍧?锛?0x14
    union {
        __IO uint32_t EXTICR4;
        struct EXTICR4_Register {
            uint32_t EXTI12 : 3; /*!< EXTI12 閰嶇疆浣? */
            uint32_t RESERVED15 : 1; /*!< 淇濈暀浣? */
            uint32_t EXTI13 : 3; /*!< EXTI13 閰嶇疆浣? */
            uint32_t RESERVED16 : 1; /*!< 淇濈暀浣? */
            uint32_t EXTI14 : 3; /*!< EXTI14 閰嶇疆浣? */
            uint32_t RESERVED17 : 1; /*!< 淇濈暀浣? */
            uint32_t EXTI15 : 3; /*!< EXTI15 閰嶇疆浣? */
            uint32_t RESERVED18 : 17; /*!< 淇濈暀浣? */
        } EXTICR4_register;
    };

    // SYSCFG SRAM2 鎺у埗鍜岀姸鎬佸瘎瀛樺櫒 (SYSCFG_SCSR)锛屽亸绉诲湴鍧?锛?0x18
    union {
        __IO uint32_t SCSR;
        struct SCSR_Register {
            uint32_t SRAM2ER : 1; /*!< SRAM2 鍜? PKA RAM 鎿﹂櫎 */
            uint32_t SRAM2BSY : 1; /*!< SRAM2 鍜? PKA RAM 蹇欎簬鎿﹂櫎鎿嶄綔 */
            uint32_t RESERVED19 : 28; /*!< 淇濈暀浣? */
            uint32_t CFRFD : 1; /*!< CPU2 SRAM 鍙栨寚锛堟墽琛岋級绂佹 */
            uint32_t RESERVED20 : 1; /*!< 淇濈暀浣? */
        } SCSR_register;
    };

    // SYSCFG 閰嶇疆瀵勫瓨鍣? 2 (SYSCFG_CFGFR2)锛屽亸绉诲湴鍧?锛?0x1C
    union {
        __IO uint32_t CFGR2;
        struct CFGR2_Register {
            uint32_t CLL : 1; /*!< CLL */
            uint32_t SPL : 1; /*!< SRAM2 濂囧伓鏍￠獙閿佸畾浣? */
            uint32_t PVDL : 1; /*!< PVD 閿佸畾浣胯兘浣? */
            uint32_t ECCL : 1; /*!< ECC 閿佸畾 */
            uint32_t RESERVED21 : 4; /*!< 淇濈暀浣? */
            uint32_t SPF : 1; /*!< SRAM2 濂囧伓鏍￠獙閿欒鏍囧織 */
            uint32_t RESERVED22 : 24; /*!< 淇濈暀浣? */
        } CFGR2_register;
    };

    // SYSCFG SRAM2 鍐欎繚鎶ゅ瘎瀛樺櫒 (SYSCFG_SWPR1)锛屽亸绉诲湴鍧?锛?0x20
    union {
        __IO uint32_t SWPR1;
        struct SWPR1_Register {
            uint32_t P0WP : 1; /*!< SRAM2 1KB 椤? 0 鍐欎繚鎶? */
            uint32_t P1WP : 1; /*!< SRAM2 1KB 椤? 1 鍐欎繚鎶? */
            uint32_t P2WP : 1; /*!< SRAM2 1KB 椤? 2 鍐欎繚鎶? */
            uint32_t P3WP : 1; /*!< SRAM2 1KB 椤? 3 鍐欎繚鎶? */
            uint32_t P4WP : 1; /*!< SRAM2 1KB 椤? 4 鍐欎繚鎶? */
            uint32_t P5WP : 1; /*!< SRAM2 1KB 椤? 5 鍐欎繚鎶? */
            uint32_t P6WP : 1; /*!< SRAM2 1KB 椤? 6 鍐欎繚鎶? */
            uint32_t P7WP : 1; /*!< SRAM2 1KB 椤? 7 鍐欎繚鎶? */
            uint32_t P8WP : 1; /*!< SRAM2 1KB 椤? 8 鍐欎繚鎶? */
            uint32_t P9WP : 1; /*!< SRAM2 1KB 椤? 9 鍐欎繚鎶? */
            uint32_t P10WP : 1; /*!< SRAM2 1KB 椤? 10 鍐欎繚鎶? */
            uint32_t P11WP : 1; /*!< SRAM2 1KB 椤? 11 鍐欎繚鎶? */
            uint32_t P12WP : 1; /*!< SRAM2 1KB 椤? 12 鍐欎繚鎶? */
            uint32_t P13WP : 1; /*!< SRAM2 1KB 椤? 13 鍐欎繚鎶? */
            uint32_t P14WP : 1; /*!< SRAM2 1KB 椤? 14 鍐欎繚鎶? */
            uint32_t P15WP : 1; /*!< SRAM2 1KB 椤? 15 鍐欎繚鎶? */
            uint32_t P16WP : 1; /*!< SRAM2 1KB 椤? 16 鍐欎繚鎶? */
            uint32_t P17WP : 1; /*!< SRAM2 1KB 椤? 17 鍐欎繚鎶? */
            uint32_t P18WP : 1; /*!< SRAM2 1KB 椤? 18 鍐欎繚鎶? */
            uint32_t P19WP : 1; /*!< SRAM2 1KB 椤? 19 鍐欎繚鎶? */
            uint32_t P20WP : 1; /*!< SRAM2 1KB 椤? 20 鍐欎繚鎶? */
            uint32_t P21WP : 1; /*!< SRAM2 1KB 椤? 21 鍐欎繚鎶? */
            uint32_t P22WP : 1; /*!< SRAM2 1KB 椤? 22 鍐欎繚鎶? */
            uint32_t P23WP : 1; /*!< SRAM2 1KB 椤? 23 鍐欎繚鎶? */
            uint32_t P24WP : 1; /*!< SRAM2 1KB 椤? 24 鍐欎繚鎶? */
            uint32_t P25WP : 1; /*!< SRAM2 1KB 椤? 25 鍐欎繚鎶? */
            uint32_t P26WP : 1; /*!< SRAM2 1KB 椤? 26 鍐欎繚鎶? */
            uint32_t P27WP : 1; /*!< SRAM2 1KB 椤? 27 鍐欎繚鎶? */
            uint32_t P28WP : 1; /*!< SRAM2 1KB 椤? 28 鍐欎繚鎶? */
            uint32_t P29WP : 1; /*!< SRAM2 1KB 椤? 29 鍐欎繚鎶? */
            uint32_t P30WP : 1; /*!< SRAM2 1KB 椤? 30 鍐欎繚鎶? */
            uint32_t P31WP : 1; /*!< SRAM2 1KB 椤? 31 鍐欎繚鎶? */
        } SWPR1_register;
    };

    // SYSCFG SRAM2 瀵嗛挜瀵勫瓨鍣? (SYSCFG_SKR)锛屽亸绉诲湴鍧?锛?0x24
    union {
        __IO uint32_t SKR;
        struct SKR_Register {
            uint32_t KEY : 8; /*!< 杞欢鎿﹂櫎鐨? SRAM2 鍐欎繚鎶ゅ瘑閽? */
            uint32_t RESERVED23 : 24; /*!< 淇濈暀浣? */
        } SKR_register;
    };

    // SYSCFG SRAM2 鍐欎繚鎶ゅ瘎瀛樺櫒 2 (SYSCFG_SWPR2)锛屽亸绉诲湴鍧?锛?0x28
    union {
        __IO uint32_t SWPR2;
        struct SWPR2_Register {
            uint32_t P32WP : 1; /*!< SRAM2 1KB 椤? 32 鍐欎繚鎶? */
            uint32_t P33WP : 1; /*!< SRAM2 1KB 椤? 33 鍐欎繚鎶? */
            uint32_t P34WP : 1; /*!< SRAM2 1KB 椤? 34 鍐欎繚鎶? */
            uint32_t P35WP : 1; /*!< SRAM2 1KB 椤? 35 鍐欎繚鎶? */
            uint32_t P36WP : 1; /*!< SRAM2 1KB 椤? 36 鍐欎繚鎶? */
            uint32_t P37WP : 1; /*!< SRAM2 1KB 椤? 37 鍐欎繚鎶? */
            uint32_t P38WP : 1; /*!< SRAM2 1KB 椤? 38 鍐欎繚鎶? */
            uint32_t P39WP : 1; /*!< SRAM2 1KB 椤? 39 鍐欎繚鎶? */
            uint32_t P40WP : 1; /*!< SRAM2 1KB 椤? 40 鍐欎繚鎶? */
            uint32_t P41WP : 1; /*!< SRAM2 1KB 椤? 41 鍐欎繚鎶? */
            uint32_t P42WP : 1; /*!< SRAM2 1KB 椤? 42 鍐欎繚鎶? */
            uint32_t P43WP : 1; /*!< SRAM2 1KB 椤? 43 鍐欎繚鎶? */
            uint32_t P44WP : 1; /*!< SRAM2 1KB 椤? 44 鍐欎繚鎶? */
            uint32_t P45WP : 1; /*!< SRAM2 1KB 椤? 45 鍐欎繚鎶? */
            uint32_t P46WP : 1; /*!< SRAM2 1KB 椤? 46 鍐欎繚鎶? */
            uint32_t P47WP : 1; /*!< SRAM2 1KB 椤? 47 鍐欎繚鎶? */
            uint32_t P48WP : 1; /*!< SRAM2 1KB 椤? 48 鍐欎繚鎶? */
            uint32_t P49WP : 1; /*!< SRAM2 1KB 椤? 49 鍐欎繚鎶? */
            uint32_t P50WP : 1; /*!< SRAM2 1KB 椤? 50 鍐欎繚鎶? */
            uint32_t P51WP : 1; /*!< SRAM2 1KB 椤? 51 鍐欎繚鎶? */
            uint32_t P52WP : 1; /*!< SRAM2 1KB 椤? 52 鍐欎繚鎶? */
            uint32_t P53WP : 1; /*!< SRAM2 1KB 椤? 53 鍐欎繚鎶? */
            uint32_t P54WP : 1; /*!< SRAM2 1KB 椤? 54 鍐欎繚鎶? */
            uint32_t P55WP : 1; /*!< SRAM2 1KB 椤? 55 鍐欎繚鎶? */
            uint32_t P56WP : 1; /*!< SRAM2 1KB 椤? 56 鍐欎繚鎶? */
            uint32_t P57WP : 1; /*!< SRAM2 1KB 椤? 57 鍐欎繚鎶? */
            uint32_t P58WP : 1; /*!< SRAM2 1KB 椤? 58 鍐欎繚鎶? */
            uint32_t P59WP : 1; /*!< SRAM2 1KB 椤? 59 鍐欎繚鎶? */
            uint32_t P60WP : 1; /*!< SRAM2 1KB 椤? 60 鍐欎繚鎶? */
            uint32_t P61WP : 1; /*!< SRAM2 1KB 椤? 61 鍐欎繚鎶? */
            uint32_t P62WP : 1; /*!< SRAM2 1KB 椤? 62 鍐欎繚鎶? */
            uint32_t P63WP : 1; /*!< SRAM2 1KB 椤? 63 鍐欎繚鎶? */
        } SWPR2_register;
    };

    // 淇濈暀鍖哄煙 (0x2C - 0x0FF)锛岀敤浜庡湴鍧?鍋忕Щ
    __IO uint32_t RESERVED24[53]; /*!< 53涓?32浣嶅瘎瀛樺櫒锛屽亸绉?0x2C鍒?0x0FF */

    // SYSCFG 涓柇灞忚斀瀵勫瓨鍣? 1 (SYSCFG_IMR1)锛屽亸绉诲湴鍧?锛?0x100
    union {
        __IO uint32_t IMR1;
        struct IMR1_Register {
            uint32_t IMR0 : 1; /*!< 涓柇绾?0灞忚斀浣? */
            uint32_t IMR1 : 1; /*!< 涓柇绾?1灞忚斀浣? */
            uint32_t IMR2 : 1; /*!< 涓柇绾?2灞忚斀浣? */
            uint32_t IMR3 : 1; /*!< 涓柇绾?3灞忚斀浣? */
            uint32_t IMR4 : 1; /*!< 涓柇绾?4灞忚斀浣? */
            uint32_t IMR5 : 1; /*!< 涓柇绾?5灞忚斀浣? */
            uint32_t IMR6 : 1; /*!< 涓柇绾?6灞忚斀浣? */
            uint32_t IMR7 : 1; /*!< 涓柇绾?7灞忚斀浣? */
            uint32_t IMR8 : 1; /*!< 涓柇绾?8灞忚斀浣? */
            uint32_t IMR9 : 1; /*!< 涓柇绾?9灞忚斀浣? */
            uint32_t IMR10 : 1; /*!< 涓柇绾?10灞忚斀浣? */
            uint32_t IMR11 : 1; /*!< 涓柇绾?11灞忚斀浣? */
            uint32_t IMR12 : 1; /*!< 涓柇绾?12灞忚斀浣? */
            uint32_t IMR13 : 1; /*!< 涓柇绾?13灞忚斀浣? */
            uint32_t IMR14 : 1; /*!< 涓柇绾?14灞忚斀浣? */
            uint32_t IMR15 : 1; /*!< 涓柇绾?15灞忚斀浣? */
            uint32_t RESERVED25 : 16; /*!< 淇濈暀浣? */
        } IMR1_register;
    };

    // SYSCFG 涓柇灞忚斀瀵勫瓨鍣? 2 (SYSCFG_IMR2)锛屽亸绉诲湴鍧?锛?0x104
    union {
        __IO uint32_t IMR2;
        struct IMR2_Register {
            uint32_t IMR16 : 1; /*!< 涓柇绾?16灞忚斀浣? */
            uint32_t IMR17 : 1; /*!< 涓柇绾?17灞忚斀浣? */
            uint32_t IMR18 : 1; /*!< 涓柇绾?18灞忚斀浣? */
            uint32_t IMR19 : 1; /*!< 涓柇绾?19灞忚斀浣? */
            uint32_t IMR20 : 1; /*!< 涓柇绾?20灞忚斀浣? */
            uint32_t IMR21 : 1; /*!< 涓柇绾?21灞忚斀浣? */
            uint32_t IMR22 : 1; /*!< 涓柇绾?22灞忚斀浣? */
            uint32_t IMR23 : 1; /*!< 涓柇绾?23灞忚斀浣? */
            uint32_t IMR24 : 1; /*!< 涓柇绾?24灞忚斀浣? */
            uint32_t IMR25 : 1; /*!< 涓柇绾?25灞忚斀浣? */
            uint32_t IMR26 : 1; /*!< 涓柇绾?26灞忚斀浣? */
            uint32_t IMR27 : 1; /*!< 涓柇绾?27灞忚斀浣? */
            uint32_t IMR28 : 1; /*!< 涓柇绾?28灞忚斀浣? */
            uint32_t IMR29 : 1; /*!< 涓柇绾?29灞忚斀浣? */
            uint32_t IMR30 : 1; /*!< 涓柇绾?30灞忚斀浣? */
            uint32_t IMR31 : 1; /*!< 涓柇绾?31灞忚斀浣? */
            uint32_t RESERVED26 : 16; /*!< 淇濈暀浣? */
        } IMR2_register;
    };

    // SYSCFG CPU2 涓柇灞忚斀瀵勫瓨鍣? 1 (SYSCFG_C2IMR1)锛屽亸绉诲湴鍧?锛?0x108
    union {
        __IO uint32_t C2IMR1;
        struct C2IMR1_Register {
            uint32_t C2IMR0 : 1; /*!< CPU2 涓柇绾?0灞忚斀浣? */
            uint32_t C2IMR1 : 1; /*!< CPU2 涓柇绾?1灞忚斀浣? */
            uint32_t C2IMR2 : 1; /*!< CPU2 涓柇绾?2灞忚斀浣? */
            uint32_t C2IMR3 : 1; /*!< CPU2 涓柇绾?3灞忚斀浣? */
            uint32_t C2IMR4 : 1; /*!< CPU2 涓柇绾?4灞忚斀浣? */
            uint32_t C2IMR5 : 1; /*!< CPU2 涓柇绾?5灞忚斀浣? */
            uint32_t C2IMR6 : 1; /*!< CPU2 涓柇绾?6灞忚斀浣? */
            uint32_t C2IMR7 : 1; /*!< CPU2 涓柇绾?7灞忚斀浣? */
            uint32_t C2IMR8 : 1; /*!< CPU2 涓柇绾?8灞忚斀浣? */
            uint32_t C2IMR9 : 1; /*!< CPU2 涓柇绾?9灞忚斀浣? */
            uint32_t C2IMR10 : 1; /*!< CPU2 涓柇绾?10灞忚斀浣? */
            uint32_t C2IMR11 : 1; /*!< CPU2 涓柇绾?11灞忚斀浣? */
            uint32_t C2IMR12 : 1; /*!< CPU2 涓柇绾?12灞忚斀浣? */
            uint32_t C2IMR13 : 1; /*!< CPU2 涓柇绾?13灞忚斀浣? */
            uint32_t C2IMR14 : 1; /*!< CPU2 涓柇绾?14灞忚斀浣? */
            uint32_t C2IMR15 : 1; /*!< CPU2 涓柇绾?15灞忚斀浣? */
            uint32_t RESERVED27 : 16; /*!< 淇濈暀浣? */
        } C2IMR1_register;
    };

    // SYSCFG CPU2 涓柇灞忚斀瀵勫瓨鍣? 2 (SYSCFG_C2IMR2)锛屽亸绉诲湴鍧?锛?0x10C
    union {
        __IO uint32_t C2IMR2;
        struct C2IMR2_Register {
            uint32_t C2IMR16 : 1; /*!< CPU2 涓柇绾?16灞忚斀浣? */
            uint32_t C2IMR17 : 1; /*!< CPU2 涓柇绾?17灞忚斀浣? */
            uint32_t C2IMR18 : 1; /*!< CPU2 涓柇绾?18灞忚斀浣? */
            uint32_t C2IMR19 : 1; /*!< CPU2 涓柇绾?19灞忚斀浣? */
            uint32_t C2IMR20 : 1; /*!< CPU2 涓柇绾?20灞忚斀浣? */
            uint32_t C2IMR21 : 1; /*!< CPU2 涓柇绾?21灞忚斀浣? */
            uint32_t C2IMR22 : 1; /*!< CPU2 涓柇绾?22灞忚斀浣? */
            uint32_t C2IMR23 : 1; /*!< CPU2 涓柇绾?23灞忚斀浣? */
            uint32_t C2IMR24 : 1; /*!< CPU2 涓柇绾?24灞忚斀浣? */
            uint32_t C2IMR25 : 1; /*!< CPU2 涓柇绾?25灞忚斀浣? */
            uint32_t C2IMR26 : 1; /*!< CPU2 涓柇绾?26灞忚斀浣? */
            uint32_t C2IMR27 : 1; /*!< CPU2 涓柇绾?27灞忚斀浣? */
            uint32_t C2IMR28 : 1; /*!< CPU2 涓柇绾?28灞忚斀浣? */
            uint32_t C2IMR29 : 1; /*!< CPU2 涓柇绾?29灞忚斀浣? */
            uint32_t C2IMR30 : 1; /*!< CPU2 涓柇绾?30灞忚斀浣? */
            uint32_t C2IMR31 : 1; /*!< CPU2 涓柇绾?31灞忚斀浣? */
            uint32_t RESERVED28 : 16; /*!< 淇濈暀浣? */
        } C2IMR2_register;
    };

    // SYSCFG 瀹夊叏鍏ヤ镜閰嶇疆瀵勫瓨鍣? (SYSCFG_SIPCR)锛屽亸绉诲湴鍧?锛?0x110
    union {
        __IO uint32_t SIPCR;
        struct SIPCR_Register {
            uint32_t SIPL : 2; /*!< 瀹夊叏鍏ヤ镜寮曡剼鐢靛钩 */
            uint32_t SIPOL : 1; /*!< 瀹夊叏鍏ヤ镜寮曡剼鏋佹?? */
            uint32_t SIEN : 1; /*!< 瀹夊叏鍏ヤ镜妫?娴嬩娇鑳? */
            uint32_t SRST : 1; /*!< 瀹夊叏鍏ヤ镜澶嶄綅 */
            uint32_t RESERVED29 : 27; /*!< 淇濈暀浣? */
        } SIPCR_register;
    };
} WROS_SYSCFG_TypeDef;
    



/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/
/***************************************************************************************************************/



// 				PWR

typedef struct {
    /* -------------------------- 0x000: PWR_CR1 瀵勫瓨鍣? ------------------------- */
    union {
        __IO uint32_t PWR_CR1;                 /*!< PWR Control Register 1 */
        struct PWR_CR1_Register {
            uint32_t LPMS      : 2;    /*!< Bit 0-1: LPMS[1:0] - Low-power mode selection */
            uint32_t RESERVED0 : 1;    /*!< Bit 2: Reserved */
            uint32_t FPDR      : 1;    /*!< Bit 3: FPDR - Flash power-down in Stop mode */
            uint32_t FDDS      : 1;    /*!< Bit 4: FDDS - Flash deep power-down in Stop mode */
            uint32_t RESERVED1 : 3;    /*!< Bit 5-7: Reserved */
            uint32_t DBP       : 1;    /*!< Bit 8: DBP - Disable backup domain write protection */
            uint32_t RESERVED2 : 1;    /*!< Bit 9: Reserved */
            uint32_t VOS       : 2;    /*!< Bit 10-11: VOS[1:0] - Voltage scaling selection */
            uint32_t RESERVED3 : 2;    /*!< Bit 12-13: Reserved */
            uint32_t LPR       : 1;    /*!< Bit 14: LPR - Low-power run */
            uint32_t RESERVED4 : 17;   /*!< Bit 15-31: Reserved */
        } PWR_CR1_register;
    };

    /* -------------------------- 0x004: PWR_CR2 瀵勫瓨鍣? ------------------------- */
    union {
        __IO uint32_t PWR_CR2;                 /*!< PWR Control Register 2 */
        struct PWR_CR2_Register {
            uint32_t PLS       : 3;    /*!< Bit 0-2: PLS[2:0] - Power lock status */
            uint32_t RESERVED5 : 1;    /*!< Bit 3: Reserved */
            uint32_t PME       : 1;    /*!< Bit 4: PME - Power management event */
            uint32_t RESERVED6 : 3;    /*!< Bit 5-7: Reserved */
            uint32_t USV       : 1;    /*!< Bit 8: USV - Under-voltage supervision */
            uint32_t RESERVED7 : 23;   /*!< Bit 9-31: Reserved */
        } PWR_CR2_register;
    };

    /* -------------------------- 0x008: PWR_CR3 瀵勫瓨鍣? ------------------------- */
    union {
        __IO uint32_t PWR_CR3;                 /*!< PWR Control Register 3 */
        struct PWR_CR3_Register {
            uint32_t EWP1      : 1;    /*!< Bit 0: EWP1 - Enable wakeup pin 1 */
            uint32_t EWP2      : 1;    /*!< Bit 1: EWP2 - Enable wakeup pin 2 */
            uint32_t EWP3      : 1;    /*!< Bit 2: EWP3 - Enable wakeup pin 3 */
            uint32_t EWP4      : 1;    /*!< Bit 3: EWP4 - Enable wakeup pin 4 */
            uint32_t EWP5      : 1;    /*!< Bit 4: EWP5 - Enable wakeup pin 5 */
            uint32_t RESERVED8 : 3;    /*!< Bit 5-7: Reserved */
            uint32_t ERRS      : 1;    /*!< Bit 8: ERRS - Enable retention register supply */
            uint32_t RESERVED9 : 3;    /*!< Bit 9-11: Reserved */
            uint32_t APC       : 1;    /*!< Bit 12: APC - Apply pull-up and pull-down configuration */
            uint32_t EBLEA     : 1;    /*!< Bit 13: EBLEA - Enable backup domain low-power */
            uint32_t RESERVED10: 2;    /*!< Bit 14-15: Reserved */
            uint32_t E2SE      : 1;    /*!< Bit 16: E2SE - Enable 2nd security level */
            uint32_t RESERVED11: 3;    /*!< Bit 17-19: Reserved */
            uint32_t EEMUL     : 1;    /*!< Bit 20: EEMUL - Enable internal voltage regulator in deep sleep */
            uint32_t RESERVED12: 11;   /*!< Bit 21-31: Reserved */
        } PWR_CR3_register;
    };

    /* -------------------------- 0x00C: PWR_CR4 瀵勫瓨鍣? ------------------------- */
    union {
        __IO uint32_t PWR_CR4;                 /*!< PWR Control Register 4 */
        struct PWR_CR4_Register {
            uint32_t WP1       : 1;    /*!< Bit 0: WP1 - Wakeup pin 1 */
            uint32_t WP2       : 1;    /*!< Bit 1: WP2 - Wakeup pin 2 */
            uint32_t WP3       : 1;    /*!< Bit 2: WP3 - Wakeup pin 3 */
            uint32_t RESERVED13: 5;    /*!< Bit 3-7: Reserved */
            uint32_t VRES      : 1;    /*!< Bit 8: VRES - Voltage regulator reset */
            uint32_t RESERVED14: 11;   /*!< Bit 9-19: Reserved */
            uint32_t C2BOOT    : 1;    /*!< Bit 20: C2BOOT - CPU2 boot */
            uint32_t RESERVED15: 11;   /*!< Bit 21-31: Reserved */
        } PWR_CR4_register;
    };

    /* -------------------------- 0x010: PWR_SR1 瀵勫瓨鍣? ------------------------- */
    union {
        __IO uint32_t PWR_SR1;                 /*!< PWR Status Register 1 */
        struct PWR_SR1_Register {
            uint32_t WUF1      : 1;    /*!< Bit 0: WUF1 - Wakeup flag 1 */
            uint32_t WUF2      : 1;    /*!< Bit 1: WUF2 - Wakeup flag 2 */
            uint32_t WUF3      : 1;    /*!< Bit 2: WUF3 - Wakeup flag 3 */
            uint32_t WUF4      : 1;    /*!< Bit 3: WUF4 - Wakeup flag 4 */
            uint32_t WUF5      : 1;    /*!< Bit 4: WUF5 - Wakeup flag 5 */
            uint32_t RESERVED16: 3;    /*!< Bit 5-7: Reserved */
            uint32_t SMSF      : 1;    /*!< Bit 8: SMSF - Standby flag */
            uint32_t RESERVED17: 3;    /*!< Bit 9-11: Reserved */
            uint32_t BORF      : 1;    /*!< Bit 12: BORF - Brownout reset flag */
            uint32_t CWUF      : 1;    /*!< Bit 13: CWUF - Clear wakeup flag */
            uint32_t RESERVED18: 2;    /*!< Bit 14-15: Reserved */
            uint32_t REGLPF    : 1;    /*!< Bit 16: REGLPF - Regulator low-power flag */
            uint32_t RESERVED19: 3;    /*!< Bit 17-19: Reserved */
            uint32_t SBF       : 1;    /*!< Bit 20: SBF - Standby flag */
            uint32_t B2SAF     : 1;    /*!< Bit 21: B2SAF - Backup domain 2nd security flag */
            uint32_t C85AEF    : 1;    /*!< Bit 22: C85AEF - 85掳C alarm flag */
            uint32_t WUF       : 1;    /*!< Bit 23: WUF - Wakeup flag */
            uint32_t RESERVED20: 8;    /*!< Bit 24-31: Reserved */
        } PWR_SR1_register;
    };

    /* -------------------------- 0x014: PWR_SR2 瀵勫瓨鍣? ------------------------- */
    union {
        __IO uint32_t PWR_SR2;                 /*!< PWR Status Register 2 */
        struct PWR_SR2_Register {
            uint32_t PDU0      : 1;    /*!< Bit 0: PDU0 - Pull-down for I/O pin 0 */
            uint32_t PDU1      : 1;    /*!< Bit 1: PDU1 - Pull-down for I/O pin 1 */
            uint32_t PDU2      : 1;    /*!< Bit 2: PDU2 - Pull-down for I/O pin 2 */
            uint32_t PDU3      : 1;    /*!< Bit 3: PDU3 - Pull-down for I/O pin 3 */
            uint32_t PDU4      : 1;    /*!< Bit 4: PDU4 - Pull-down for I/O pin 4 */
            uint32_t PDU5      : 1;    /*!< Bit 5: PDU5 - Pull-down for I/O pin 5 */
            uint32_t PDU6      : 1;    /*!< Bit 6: PDU6 - Pull-down for I/O pin 6 */
            uint32_t PDU7      : 1;    /*!< Bit 7: PDU7 - Pull-down for I/O pin 7 */
            uint32_t PDU8      : 1;    /*!< Bit 8: PDU8 - Pull-down for I/O pin 8 */
            uint32_t PDU9      : 1;    /*!< Bit 9: PDU9 - Pull-down for I/O pin 9 */
            uint32_t PDU10     : 1;    /*!< Bit 10: PDU10 - Pull-down for I/O pin 10 */
            uint32_t PDU11     : 1;    /*!< Bit 11: PDU11 - Pull-down for I/O pin 11 */
            uint32_t PDU12     : 1;    /*!< Bit 12: PDU12 - Pull-down for I/O pin 12 */
            uint32_t PDU13     : 1;    /*!< Bit 13: PDU13 - Pull-down for I/O pin 13 */
            uint32_t PDU14     : 1;    /*!< Bit 14: PDU14 - Pull-down for I/O pin 14 */
            uint32_t PDU15     : 1;    /*!< Bit 15: PDU15 - Pull-down for I/O pin 15 */
            uint32_t PU0       : 1;    /*!< Bit 16: PU0 - Pull-up for I/O pin 0 */
            uint32_t PU1       : 1;    /*!< Bit 17: PU1 - Pull-up for I/O pin 1 */
            uint32_t PU2       : 1;    /*!< Bit 18: PU2 - Pull-up for I/O pin 2 */
            uint32_t PU3       : 1;    /*!< Bit 19: PU3 - Pull-up for I/O pin 3 */
            uint32_t PU4       : 1;    /*!< Bit 20: PU4 - Pull-up for I/O pin 4 */
            uint32_t PU5       : 1;    /*!< Bit 21: PU5 - Pull-up for I/O pin 5 */
            uint32_t PU6       : 1;    /*!< Bit 22: PU6 - Pull-up for I/O pin 6 */
            uint32_t PU7       : 1;    /*!< Bit 23: PU7 - Pull-up for I/O pin 7 */
            uint32_t PU8       : 1;    /*!< Bit 24: PU8 - Pull-up for I/O pin 8 */
            uint32_t PU9       : 1;    /*!< Bit 25: PU9 - Pull-up for I/O pin 9 */
            uint32_t PU10      : 1;    /*!< Bit 26: PU10 - Pull-up for I/O pin 10 */
            uint32_t PU11      : 1;    /*!< Bit 27: PU11 - Pull-up for I/O pin 11 */
            uint32_t PU12      : 1;    /*!< Bit 28: PU12 - Pull-up for I/O pin 12 */
            uint32_t PU13      : 1;    /*!< Bit 29: PU13 - Pull-up for I/O pin 13 */
            uint32_t PU14      : 1;    /*!< Bit 30: PU14 - Pull-up for I/O pin 14 */
            uint32_t PU15      : 1;    /*!< Bit 31: PU15 - Pull-up for I/O pin 15 */
        } PWR_SR2_register;
    };

    /* -------------------------- 0x018: PWR_SCR 瀵勫瓨鍣? ------------------------- */
    union {
        __IO uint32_t PWR_SCR;                 /*!< PWR Status Clear Register */
        struct PWR_SCR_Register {
            uint32_t CWUF1     : 1;    /*!< Bit 0: CWUF1 - Clear wakeup flag 1 */
            uint32_t CWUF2     : 1;    /*!< Bit 1: CWUF2 - Clear wakeup flag 2 */
            uint32_t CWUF3     : 1;    /*!< Bit 2: CWUF3 - Clear wakeup flag 3 */
            uint32_t CWUF4     : 1;    /*!< Bit 3: CWUF4 - Clear wakeup flag 4 */
            uint32_t CWUF5     : 1;    /*!< Bit 4: CWUF5 - Clear wakeup flag 5 */
            uint32_t RESERVED21: 3;    /*!< Bit 5-7: Reserved */
            uint32_t CSMF      : 1;    /*!< Bit 8: CSMF - Clear standby flag */
            uint32_t RESERVED22: 3;    /*!< Bit 9-11: Reserved */
            uint32_t CBORF     : 1;    /*!< Bit 12: CBORF - Clear brownout reset flag */
            uint32_t CWUF      : 1;    /*!< Bit 13: CWUF - Clear wakeup flag */
            uint32_t RESERVED23: 2;    /*!< Bit 14-15: Reserved */
            uint32_t CREGLPF   : 1;    /*!< Bit 16: CREGLPF - Clear regulator low-power flag */
            uint32_t RESERVED24: 3;    /*!< Bit 17-19: Reserved */
            uint32_t CSBF      : 1;    /*!< Bit 20: CSBF - Clear standby flag */
            uint32_t CB2SAF    : 1;    /*!< Bit 21: CB2SAF - Clear backup domain 2nd security flag */
            uint32_t CC85AEF   : 1;    /*!< Bit 22: CC85AEF - Clear 85掳C alarm flag */
            uint32_t CWUF_GLOBAL:1;    /*!< Bit 23: CWUF_GLOBAL - Clear global wakeup flag */
            uint32_t RESERVED25: 8;    /*!< Bit 24-31: Reserved */
        } PWR_SCR_register;
    };

    /* -------------------------- 0x01C: PWR_CR5 瀵勫瓨鍣? ------------------------- */
    union {
        __IO uint32_t PWR_CR5;                 /*!< PWR Control Register 5 */
        struct PWR_CR5_Register {
            uint32_t VOS3      : 2;    /*!< Bit 0-1: VOS3[1:0] - Voltage scaling 3 selection */
            uint32_t SMPS      : 3;    /*!< Bit 2-4: SMPS[2:0] - SMPS configuration */
            uint32_t RESERVED26: 3;    /*!< Bit 5-7: Reserved */
            uint32_t BORHC     : 1;    /*!< Bit 8: BORHC - Brownout reset high threshold */
            uint32_t RESERVED27: 11;   /*!< Bit 9-19: Reserved */
            uint32_t SNSEN     : 1;    /*!< Bit 20: SNSEN - Sensor enable */
            uint32_t RESERVED28: 11;   /*!< Bit 21-31: Reserved */
        } PWR_CR5_register;
    };

    /* -------------------------- 0x020: PWR_PUCRA 瀵勫瓨鍣? ----------------------- */
    union {
        __IO uint32_t PUCRA;               /*!< PWR Pull-up Control Register A */
        struct PUCRA_Register {
            uint32_t PU0       : 1;    /*!< Bit 0: PU0 - Pull-up for PA0 */
            uint32_t PU1       : 1;    /*!< Bit 1: PU1 - Pull-up for PA1 */
            uint32_t PU2       : 1;    /*!< Bit 2: PU2 - Pull-up for PA2 */
            uint32_t PU3       : 1;    /*!< Bit 3: PU3 - Pull-up for PA3 */
            uint32_t PU4       : 1;    /*!< Bit 4: PU4 - Pull-up for PA4 */
            uint32_t PU5       : 1;    /*!< Bit 5: PU5 - Pull-up for PA5 */
            uint32_t PU6       : 1;    /*!< Bit 6: PU6 - Pull-up for PA6 */
            uint32_t PU7       : 1;    /*!< Bit 7: PU7 - Pull-up for PA7 */
            uint32_t PU8       : 1;    /*!< Bit 8: PU8 - Pull-up for PA8 */
            uint32_t PU9       : 1;    /*!< Bit 9: PU9 - Pull-up for PA9 */
            uint32_t PU10      : 1;    /*!< Bit 10: PU10 - Pull-up for PA10 */
            uint32_t PU11      : 1;    /*!< Bit 11: PU11 - Pull-up for PA11 */
            uint32_t PU12      : 1;    /*!< Bit 12: PU12 - Pull-up for PA12 */
            uint32_t PU13      : 1;    /*!< Bit 13: PU13 - Pull-up for PA13 */
            uint32_t PU14      : 1;    /*!< Bit 14: PU14 - Pull-up for PA14 */
            uint32_t PU15      : 1;    /*!< Bit 15: PU15 - Pull-up for PA15 */
            uint32_t RESERVED29: 16;   /*!< Bit 16-31: Reserved */
        } PUCRA_register;
    };

    /* -------------------------- 0x024: PWR_PDCRA 瀵勫瓨鍣? ----------------------- */
    union {
        __IO uint32_t PDCRA;               /*!< PWR Pull-down Control Register A */
        struct PDCRA_Register {
            uint32_t PD0       : 1;    /*!< Bit 0: PD0 - Pull-down for PA0 */
            uint32_t PD1       : 1;    /*!< Bit 1: PD1 - Pull-down for PA1 */
            uint32_t PD2       : 1;    /*!< Bit 2: PD2 - Pull-down for PA2 */
            uint32_t PD3       : 1;    /*!< Bit 3: PD3 - Pull-down for PA3 */
            uint32_t PD4       : 1;    /*!< Bit 4: PD4 - Pull-down for PA4 */
            uint32_t PD5       : 1;    /*!< Bit 5: PD5 - Pull-down for PA5 */
            uint32_t PD6       : 1;    /*!< Bit 6: PD6 - Pull-down for PA6 */
            uint32_t PD7       : 1;    /*!< Bit 7: PD7 - Pull-down for PA7 */
            uint32_t PD8       : 1;    /*!< Bit 8: PD8 - Pull-down for PA8 */
            uint32_t PD9       : 1;    /*!< Bit 9: PD9 - Pull-down for PA9 */
            uint32_t PD10      : 1;    /*!< Bit 10: PD10 - Pull-down for PA10 */
            uint32_t PD11      : 1;    /*!< Bit 11: PD11 - Pull-down for PA11 */
            uint32_t PD12      : 1;    /*!< Bit 12: PD12 - Pull-down for PA12 */
            uint32_t PD13      : 1;    /*!< Bit 13: PD13 - Pull-down for PA13 */
            uint32_t PD14      : 1;    /*!< Bit 14: PD14 - Pull-down for PA14 */
            uint32_t PD15      : 1;    /*!< Bit 15: PD15 - Pull-down for PA15 */
            uint32_t RESERVED30: 16;   /*!< Bit 16-31: Reserved */
        } PDCRA_register;
    };

    /* -------------------------- 0x028: PWR_PUCRB 瀵勫瓨鍣? ----------------------- */
    union {
        __IO uint32_t PUCRB;               /*!< PWR Pull-up Control Register B */
        struct PUCRB_Register {
            uint32_t PU0       : 1;    /*!< Bit 0: PU0 - Pull-up for PB0 */
            uint32_t PU1       : 1;    /*!< Bit 1: PU1 - Pull-up for PB1 */
            uint32_t PU2       : 1;    /*!< Bit 2: PU2 - Pull-up for PB2 */
            uint32_t PU3       : 1;    /*!< Bit 3: PU3 - Pull-up for PB3 */
            uint32_t PU4       : 1;    /*!< Bit 4: PU4 - Pull-up for PB4 */
            uint32_t PU5       : 1;    /*!< Bit 5: PU5 - Pull-up for PB5 */
            uint32_t PU6       : 1;    /*!< Bit 6: PU6 - Pull-up for PB6 */
            uint32_t PU7       : 1;    /*!< Bit 7: PU7 - Pull-up for PB7 */
            uint32_t PU8       : 1;    /*!< Bit 8: PU8 - Pull-up for PB8 */
            uint32_t PU9       : 1;    /*!< Bit 9: PU9 - Pull-up for PB9 */
            uint32_t PU10      : 1;    /*!< Bit 10: PU10 - Pull-up for PB10 */
            uint32_t PU11      : 1;    /*!< Bit 11: PU11 - Pull-up for PB11 */
            uint32_t PU12      : 1;    /*!< Bit 12: PU12 - Pull-up for PB12 */
            uint32_t PU13      : 1;    /*!< Bit 13: PU13 - Pull-up for PB13 */
            uint32_t PU14      : 1;    /*!< Bit 14: PU14 - Pull-up for PB14 */
            uint32_t PU15      : 1;    /*!< Bit 15: PU15 - Pull-up for PB15 */
            uint32_t RESERVED31: 16;   /*!< Bit 16-31: Reserved */
        } PUCRB_register;
    };

    /* -------------------------- 0x02C: PWR_PDCRB 瀵勫瓨鍣? ----------------------- */
    union {
        __IO uint32_t PDCRB;               /*!< PWR Pull-down Control Register B */
        struct PDCRB_Register {
            uint32_t PD0       : 1;    /*!< Bit 0: PD0 - Pull-down for PB0 */
            uint32_t PD1       : 1;    /*!< Bit 1: PD1 - Pull-down for PB1 */
            uint32_t PD2       : 1;    /*!< Bit 2: PD2 - Pull-down for PB2 */
            uint32_t PD3       : 1;    /*!< Bit 3: PD3 - Pull-down for PB3 */
            uint32_t PD4       : 1;    /*!< Bit 4: PD4 - Pull-down for PB4 */
            uint32_t PD5       : 1;    /*!< Bit 5: PD5 - Pull-down for PB5 */
            uint32_t PD6       : 1;    /*!< Bit 6: PD6 - Pull-down for PB6 */
            uint32_t PD7       : 1;    /*!< Bit 7: PD7 - Pull-down for PB7 */
            uint32_t PD8       : 1;    /*!< Bit 8: PD8 - Pull-down for PB8 */
            uint32_t PD9       : 1;    /*!< Bit 9: PD9 - Pull-down for PB9 */
            uint32_t PD10      : 1;    /*!< Bit 10: PD10 - Pull-down for PB10 */
            uint32_t PD11      : 1;    /*!< Bit 11: PD11 - Pull-down for PB11 */
            uint32_t PD12      : 1;    /*!< Bit 12: PD12 - Pull-down for PB12 */
            uint32_t PD13      : 1;    /*!< Bit 13: PD13 - Pull-down for PB13 */
            uint32_t PD14      : 1;    /*!< Bit 14: PD14 - Pull-down for PB14 */
            uint32_t PD15      : 1;    /*!< Bit 15: PD15 - Pull-down for PB15 */
            uint32_t RESERVED32: 16;   /*!< Bit 16-31: Reserved */
        } PDCRB_register;
    };

    /* -------------------------- 0x030: PWR_PUCRC 瀵勫瓨鍣? ----------------------- */
    union {
        __IO uint32_t PUCRC;               /*!< PWR Pull-up Control Register C */
        struct PUCRC_Register {
            uint32_t PU0       : 1;    /*!< Bit 0: PU0 - Pull-up for PC0 */
            uint32_t PU1       : 1;    /*!< Bit 1: PU1 - Pull-up for PC1 */
            uint32_t PU2       : 1;    /*!< Bit 2: PU2 - Pull-up for PC2 */
            uint32_t PU3       : 1;    /*!< Bit 3: PU3 - Pull-up for PC3 */
            uint32_t PU4       : 1;    /*!< Bit 4: PU4 - Pull-up for PC4 */
            uint32_t PU5       : 1;    /*!< Bit 5: PU5 - Pull-up for PC5 */
            uint32_t PU6       : 1;    /*!< Bit 6: PU6 - Pull-up for PC6 */
            uint32_t PU7       : 1;    /*!< Bit 7: PU7 - Pull-up for PC7 */
            uint32_t PU8       : 1;    /*!< Bit 8: PU8 - Pull-up for PC8 */
            uint32_t PU9       : 1;    /*!< Bit 9: PU9 - Pull-up for PC9 */
            uint32_t PU10      : 1;    /*!< Bit 10: PU10 - Pull-up for PC10 */
            uint32_t PU11      : 1;    /*!< Bit 11: PU11 - Pull-up for PC11 */
            uint32_t PU12      : 1;    /*!< Bit 12: PU12 - Pull-up for PC12 */
            uint32_t PU13      : 1;    /*!< Bit 13: PU13 - Pull-up for PC13 */
            uint32_t PU14      : 1;    /*!< Bit 14: PU14 - Pull-up for PC14 */
            uint32_t PU15      : 1;    /*!< Bit 15: PU15 - Pull-up for PC15 */
            uint32_t RESERVED33: 16;   /*!< Bit 16-31: Reserved */
        } PUCRC_register;
    };

    /* -------------------------- 0x034: PWR_PDCRC 瀵勫瓨鍣? ----------------------- */
    union {
        __IO uint32_t PDCRC;               /*!< PWR Pull-down Control Register C */
        struct PDCRC_Register {
            uint32_t PD0       : 1;    /*!< Bit 0: PD0 - Pull-down for PC0 */
            uint32_t PD1       : 1;    /*!< Bit 1: PD1 - Pull-down for PC1 */
            uint32_t PD2       : 1;    /*!< Bit 2: PD2 - Pull-down for PC2 */
            uint32_t PD3       : 1;    /*!< Bit 3: PD3 - Pull-down for PC3 */
            uint32_t PD4       : 1;    /*!< Bit 4: PD4 - Pull-down for PC4 */
            uint32_t PD5       : 1;    /*!< Bit 5: PD5 - Pull-down for PC5 */
            uint32_t PD6       : 1;    /*!< Bit 6: PD6 - Pull-down for PC6 */
            uint32_t PD7       : 1;    /*!< Bit 7: PD7 - Pull-down for PC7 */
            uint32_t PD8       : 1;    /*!< Bit 8: PD8 - Pull-down for PC8 */
            uint32_t PD9       : 1;    /*!< Bit 9: PD9 - Pull-down for PC9 */
            uint32_t PD10      : 1;    /*!< Bit 10: PD10 - Pull-down for PC10 */
            uint32_t PD11      : 1;    /*!< Bit 11: PD11 - Pull-down for PC11 */
            uint32_t PD12      : 1;    /*!< Bit 12: PD12 - Pull-down for PC12 */
            uint32_t PD13      : 1;    /*!< Bit 13: PD13 - Pull-down for PC13 */
            uint32_t PD14      : 1;    /*!< Bit 14: PD14 - Pull-down for PC14 */
            uint32_t PD15      : 1;    /*!< Bit 15: PD15 - Pull-down for PC15 */
            uint32_t RESERVED34: 16;   /*!< Bit 16-31: Reserved */
        } PDCRC_register;
    };

 /* -------------------------- 0x038: PWR_PUCRD 瀵勫瓨鍣? ----------------------- */
    union {
        __IO uint32_t PUCRD;               /*!< PWR Pull-up Control Register D */
        struct PUCRD_Register {
            uint32_t PU0       : 1;    /*!< Bit 0: PU0 - Pull-up for PD0 */
            uint32_t PU1       : 1;    /*!< Bit 1: PU1 - Pull-up for PD1 */
            uint32_t PU2       : 1;    /*!< Bit 2: PU2 - Pull-up for PD2 */
            uint32_t PU3       : 1;    /*!< Bit 3: PU3 - Pull-up for PD3 */
            uint32_t PU4       : 1;    /*!< Bit 4: PU4 - Pull-up for PD4 */
            uint32_t PU5       : 1;    /*!< Bit 5: PU5 - Pull-up for PD5 */
            uint32_t PU6       : 1;    /*!< Bit 6: PU6 - Pull-up for PD6 */
            uint32_t PU7       : 1;    /*!< Bit 7: PU7 - Pull-up for PD7 */
            uint32_t PU8       : 1;    /*!< Bit 8: PU8 - Pull-up for PD8 */
            uint32_t PU9       : 1;    /*!< Bit 9: PU9 - Pull-up for PD9 */
            uint32_t PU10      : 1;    /*!< Bit 10: PU10 - Pull-up for PD10 */
            uint32_t PU11      : 1;    /*!< Bit 11: PU11 - Pull-up for PD11 */
            uint32_t PU12      : 1;    /*!< Bit 12: PU12 - Pull-up for PD12 */
            uint32_t PU13      : 1;    /*!< Bit 13: PU13 - Pull-up for PD13 */
            uint32_t PU14      : 1;    /*!< Bit 14: PU14 - Pull-up for PD14 */
            uint32_t PU15      : 1;    /*!< Bit 15: PU15 - Pull-up for PD15 */
            uint32_t RESERVED35: 16;   /*!< Bit 16-31: Reserved */
        } PUCRD_register;
    };

    /* -------------------------- 0x03C: PWR_PDCRD 瀵勫瓨鍣? ----------------------- */
    union {
        __IO uint32_t PDCRD;               /*!< PWR Pull-down Control Register D */
        struct PDCRD_Register {
            uint32_t PD0       : 1;    /*!< Bit 0: PD0 - Pull-down for PD0 */
            uint32_t PD1       : 1;    /*!< Bit 1: PD1 - Pull-down for PD1 */
            uint32_t PD2       : 1;    /*!< Bit 2: PD2 - Pull-down for PD2 */
            uint32_t PD3       : 1;    /*!< Bit 3: PD3 - Pull-down for PD3 */
            uint32_t PD4       : 1;    /*!< Bit 4: PD4 - Pull-down for PD4 */
            uint32_t PD5       : 1;    /*!< Bit 5: PD5 - Pull-down for PD5 */
            uint32_t PD6       : 1;    /*!< Bit 6: PD6 - Pull-down for PD6 */
            uint32_t PD7       : 1;    /*!< Bit 7: PD7 - Pull-down for PD7 */
            uint32_t PD8       : 1;    /*!< Bit 8: PD8 - Pull-down for PD8 */
            uint32_t PD9       : 1;    /*!< Bit 9: PD9 - Pull-down for PD9 */
            uint32_t PD10      : 1;    /*!< Bit 10: PD10 - Pull-down for PD10 */
            uint32_t PD11      : 1;    /*!< Bit 11: PD11 - Pull-down for PD11 */
            uint32_t PD12      : 1;    /*!< Bit 12: PD12 - Pull-down for PD12 */
            uint32_t PD13      : 1;    /*!< Bit 13: PD13 - Pull-down for PD13 */
            uint32_t PD14      : 1;    /*!< Bit 14: PD14 - Pull-down for PD14 */
            uint32_t PD15      : 1;    /*!< Bit 15: PD15 - Pull-down for PD15 */
            uint32_t RESERVED36: 16;   /*!< Bit 16-31: Reserved */
        } PDCRD_register;
    };

    /* -------------------------- 0x040: PWR_PUCRE 瀵勫瓨鍣? ----------------------- */
    union {
        __IO uint32_t PUCRE;               /*!< PWR Pull-up Control Register E */
        struct PUCRE_Register {
            uint32_t PU0       : 1;    /*!< Bit 0: PU0 - Pull-up for PE0 */
            uint32_t PU1       : 1;    /*!< Bit 1: PU1 - Pull-up for PE1 */
            uint32_t PU2       : 1;    /*!< Bit 2: PU2 - Pull-up for PE2 */
            uint32_t PU3       : 1;    /*!< Bit 3: PU3 - Pull-up for PE3 */
            uint32_t PU4       : 1;    /*!< Bit 4: PU4 - Pull-up for PE4 */
            uint32_t RESERVED37: 27;   /*!< Bit 5-31: Reserved */
        } PUCRE_register;
    };

    /* -------------------------- 0x044: PWR_PDCRE 瀵勫瓨鍣? ----------------------- */
    union {
        __IO uint32_t PDCRE;               /*!< PWR Pull-dow
