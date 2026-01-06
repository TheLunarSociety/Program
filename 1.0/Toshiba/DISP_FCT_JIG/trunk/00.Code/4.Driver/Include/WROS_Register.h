

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
				uint32_t VECTRESET	: 1;		// Request CORTEX_M reset
				uint32_t VECTCLRACTIVE: 1;		// Clear all abnormal Info
				uint32_t SYSRESETREQ	: 1;		// Request MCU reset
				uint32_t RESERVED0	: 5;
				uint32_t PRIGROUP		: 3;		// Priority grouping
				uint32_t RESERVED1	: 4;
				uint32_t ENDIANESS	: 1;		// READ ONLY		1 = MSB, 0 = LSB
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
		uint32_t CPACR;					// 0xE000ED88: (R/W)  Coprocessor access register协处理器访问寄存器（M4 FPU相关，M3无）
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


//************************** Direct Memory Access ******************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//


// DMAxStatus 寄存器结构体
typedef struct
{
    union
	{
        volatile uint32_t DMA_Status;  // DMA_Status (0x0000)
        struct DMA_Status_Register 
		{
            uint32_t MASTER_ENABLE  : 1;  // Bit 0: DMA operation enable (Read Only)
            uint32_t RESERVED_0     : 31;
        } DMA_Status_register;
    };

    union
	{
        volatile uint32_t DMA_Cfg;      // DMA_Cfg (0x0004)
        struct DMA_Cfg_Register
		{
            uint32_t MASTER_ENABLE  : 1;  // Bit 0: DMA operation enable
            uint32_t RESERVED_0     : 31;
        } DMA_Cfg_register;
    };

    union
	{
        volatile uint32_t DMA_CtrlBasePtr; // DMA_CtrlBasePtr (0x0008)
        struct DMA_CtrlBasePtr_Register
		{
            uint32_t RESERVED_0     : 10;
            uint32_t CTRL_BASE_PTR  : 22;  // Bits 31-8: Primary data base pointer
        } DMA_CtrlBasePtr_register;
    };

    union
	{
        volatile uint32_t DMA_AltCtrlBasePtr; // DMA_AltCtrlBasePtr (0x000C)
        struct DMA_AltCtrlBasePtr_Register
		{
            uint32_t ALT_CTRL_BASE_PTR : 32; // Bits 31-0: Alternative data base pointer	(Read only)
        } DMA_AltCtrlBasePtr_register;
    };
    
    uint32_t RESERVED_0;

    union
	{
        volatile uint32_t DMA_ChnlSwRequest; // DMA_ChnlSwRequest (0x0014)
        struct DMA_ChnlSwRequest_Register
		{
            uint32_t CHNL_SW_REQUEST_0	: 1;
            uint32_t CHNL_SW_REQUEST_1	: 1;
            uint32_t CHNL_SW_REQUEST_2	: 1;
            uint32_t CHNL_SW_REQUEST_3	: 1;
            uint32_t CHNL_SW_REQUEST_4	: 1;
            uint32_t CHNL_SW_REQUEST_5	: 1;
            uint32_t CHNL_SW_REQUEST_6	: 1;
            uint32_t CHNL_SW_REQUEST_7	: 1;
            uint32_t CHNL_SW_REQUEST_8	: 1;
            uint32_t CHNL_SW_REQUEST_9	: 1;
            uint32_t CHNL_SW_REQUEST_10	: 1;
            uint32_t CHNL_SW_REQUEST_11	: 1;
            uint32_t CHNL_SW_REQUEST_12	: 1;
            uint32_t CHNL_SW_REQUEST_13	: 1;
            uint32_t CHNL_SW_REQUEST_14	: 1;
            uint32_t CHNL_SW_REQUEST_15	: 1;
            uint32_t CHNL_SW_REQUEST_16	: 1;
            uint32_t CHNL_SW_REQUEST_17	: 1;
            uint32_t CHNL_SW_REQUEST_18	: 1;
            uint32_t CHNL_SW_REQUEST_19	: 1;
            uint32_t CHNL_SW_REQUEST_20	: 1;
            uint32_t CHNL_SW_REQUEST_21	: 1;
            uint32_t CHNL_SW_REQUEST_22	: 1;
            uint32_t CHNL_SW_REQUEST_23	: 1;
            uint32_t CHNL_SW_REQUEST_24	: 1;
            uint32_t CHNL_SW_REQUEST_25	: 1;
            uint32_t CHNL_SW_REQUEST_26	: 1;
            uint32_t CHNL_SW_REQUEST_27	: 1;
            uint32_t CHNL_SW_REQUEST_28	: 1;
            uint32_t CHNL_SW_REQUEST_29	: 1;
            uint32_t CHNL_SW_REQUEST_30	: 1;
            uint32_t CHNL_SW_REQUEST_31	: 1;
        } DMA_ChnlSwRequest_register;
    };

    union
	{
        volatile uint32_t DMA_ChnlUseburstSet; // DMA_ChnlUseburstSet (0x0018)
        struct DMA_ChnlUseburstSet_Register
		{
            uint32_t CHNL_USEBURST_SET_0	: 1;
            uint32_t CHNL_USEBURST_SET_1	: 1;
            uint32_t CHNL_USEBURST_SET_2	: 1;
            uint32_t CHNL_USEBURST_SET_3	: 1;
            uint32_t CHNL_USEBURST_SET_4	: 1;
            uint32_t CHNL_USEBURST_SET_5	: 1;
            uint32_t CHNL_USEBURST_SET_6	: 1;
            uint32_t CHNL_USEBURST_SET_7	: 1;
            uint32_t CHNL_USEBURST_SET_8	: 1;
            uint32_t CHNL_USEBURST_SET_9	: 1;
            uint32_t CHNL_USEBURST_SET_10	: 1;
            uint32_t CHNL_USEBURST_SET_11	: 1;
            uint32_t CHNL_USEBURST_SET_12	: 1;
            uint32_t CHNL_USEBURST_SET_13	: 1;
            uint32_t CHNL_USEBURST_SET_14	: 1;
            uint32_t CHNL_USEBURST_SET_15	: 1;
            uint32_t CHNL_USEBURST_SET_16	: 1;
            uint32_t CHNL_USEBURST_SET_17	: 1;
            uint32_t CHNL_USEBURST_SET_18	: 1;
            uint32_t CHNL_USEBURST_SET_19	: 1;
            uint32_t CHNL_USEBURST_SET_20	: 1;
            uint32_t CHNL_USEBURST_SET_21	: 1;
            uint32_t CHNL_USEBURST_SET_22	: 1;
            uint32_t CHNL_USEBURST_SET_23	: 1;
            uint32_t CHNL_USEBURST_SET_24	: 1;
            uint32_t CHNL_USEBURST_SET_25	: 1;
            uint32_t CHNL_USEBURST_SET_26	: 1;
            uint32_t CHNL_USEBURST_SET_27	: 1;
            uint32_t CHNL_USEBURST_SET_28	: 1;
            uint32_t CHNL_USEBURST_SET_29	: 1;
            uint32_t CHNL_USEBURST_SET_30	: 1;
            uint32_t CHNL_USEBURST_SET_31	: 1;
        } DMA_ChnlUseburstSet_register;
    };

    union
	{
        volatile uint32_t DMA_ChnlUseburstClr; // DMA_ChnlUseburstClr (0x001C)
        struct DMA_ChnlUseburstClr_Register
		{
            uint32_t CHNL_USEBURST_CLR_0	: 1;
            uint32_t CHNL_USEBURST_CLR_1	: 1;
            uint32_t CHNL_USEBURST_CLR_2	: 1;
            uint32_t CHNL_USEBURST_CLR_3	: 1;
            uint32_t CHNL_USEBURST_CLR_4	: 1;
            uint32_t CHNL_USEBURST_CLR_5	: 1;
            uint32_t CHNL_USEBURST_CLR_6	: 1;
            uint32_t CHNL_USEBURST_CLR_7	: 1;
            uint32_t CHNL_USEBURST_CLR_8	: 1;
            uint32_t CHNL_USEBURST_CLR_9	: 1;
            uint32_t CHNL_USEBURST_CLR_10	: 1;
            uint32_t CHNL_USEBURST_CLR_11	: 1;
            uint32_t CHNL_USEBURST_CLR_12	: 1;
            uint32_t CHNL_USEBURST_CLR_13	: 1;
            uint32_t CHNL_USEBURST_CLR_14	: 1;
            uint32_t CHNL_USEBURST_CLR_15	: 1;
            uint32_t CHNL_USEBURST_CLR_16	: 1;
            uint32_t CHNL_USEBURST_CLR_17	: 1;
            uint32_t CHNL_USEBURST_CLR_18	: 1;
            uint32_t CHNL_USEBURST_CLR_19	: 1;
            uint32_t CHNL_USEBURST_CLR_20	: 1;
            uint32_t CHNL_USEBURST_CLR_21	: 1;
            uint32_t CHNL_USEBURST_CLR_22	: 1;
            uint32_t CHNL_USEBURST_CLR_23	: 1;
            uint32_t CHNL_USEBURST_CLR_24	: 1;
            uint32_t CHNL_USEBURST_CLR_25	: 1;
            uint32_t CHNL_USEBURST_CLR_26	: 1;
            uint32_t CHNL_USEBURST_CLR_27	: 1;
            uint32_t CHNL_USEBURST_CLR_28	: 1;
            uint32_t CHNL_USEBURST_CLR_29	: 1;
            uint32_t CHNL_USEBURST_CLR_30	: 1;
            uint32_t CHNL_USEBURST_CLR_31	: 1;
        } DMA_ChnlUseburstClr_register;
    };

    union
	{
        volatile uint32_t DMA_ChnlReqMaskSet; // DMA_ChnlReqMaskSet (0x0020)
        struct DMA_ChnlReqMaskSet_Register
		{
            uint32_t CHNL_REQ_MASK_SET_0	: 1;
            uint32_t CHNL_REQ_MASK_SET_1	: 1;
            uint32_t CHNL_REQ_MASK_SET_2	: 1;
            uint32_t CHNL_REQ_MASK_SET_3	: 1;
            uint32_t CHNL_REQ_MASK_SET_4	: 1;
            uint32_t CHNL_REQ_MASK_SET_5	: 1;
            uint32_t CHNL_REQ_MASK_SET_6	: 1;
            uint32_t CHNL_REQ_MASK_SET_7	: 1;
            uint32_t CHNL_REQ_MASK_SET_8	: 1;
            uint32_t CHNL_REQ_MASK_SET_9	: 1;
            uint32_t CHNL_REQ_MASK_SET_10	: 1;
            uint32_t CHNL_REQ_MASK_SET_11	: 1;
            uint32_t CHNL_REQ_MASK_SET_12	: 1;
            uint32_t CHNL_REQ_MASK_SET_13	: 1;
            uint32_t CHNL_REQ_MASK_SET_14	: 1;
            uint32_t CHNL_REQ_MASK_SET_15	: 1;
            uint32_t CHNL_REQ_MASK_SET_16	: 1;
            uint32_t CHNL_REQ_MASK_SET_17	: 1;
            uint32_t CHNL_REQ_MASK_SET_18	: 1;
            uint32_t CHNL_REQ_MASK_SET_19	: 1;
            uint32_t CHNL_REQ_MASK_SET_20	: 1;
            uint32_t CHNL_REQ_MASK_SET_21	: 1;
            uint32_t CHNL_REQ_MASK_SET_22	: 1;
            uint32_t CHNL_REQ_MASK_SET_23	: 1;
            uint32_t CHNL_REQ_MASK_SET_24	: 1;
            uint32_t CHNL_REQ_MASK_SET_25	: 1;
            uint32_t CHNL_REQ_MASK_SET_26	: 1;
            uint32_t CHNL_REQ_MASK_SET_27	: 1;
            uint32_t CHNL_REQ_MASK_SET_28	: 1;
            uint32_t CHNL_REQ_MASK_SET_29	: 1;
            uint32_t CHNL_REQ_MASK_SET_30	: 1;
            uint32_t CHNL_REQ_MASK_SET_31	: 1;
        } DMA_ChnlReqMaskSet_register;
    };

    union
	{
        volatile uint32_t DMA_ChnlReqMaskClr; // DMA_ChnlReqMaskClr (0x0024)
        struct DMA_ChnlReqMaskClr_Register
		{
            uint32_t CHNL_REQ_MASK_CLR_0	: 1;
            uint32_t CHNL_REQ_MASK_CLR_1	: 1;
            uint32_t CHNL_REQ_MASK_CLR_2	: 1;
            uint32_t CHNL_REQ_MASK_CLR_3	: 1;
            uint32_t CHNL_REQ_MASK_CLR_4	: 1;
            uint32_t CHNL_REQ_MASK_CLR_5	: 1;
            uint32_t CHNL_REQ_MASK_CLR_6	: 1;
            uint32_t CHNL_REQ_MASK_CLR_7	: 1;
            uint32_t CHNL_REQ_MASK_CLR_8	: 1;
            uint32_t CHNL_REQ_MASK_CLR_9	: 1;
            uint32_t CHNL_REQ_MASK_CLR_10	: 1;
            uint32_t CHNL_REQ_MASK_CLR_11	: 1;
            uint32_t CHNL_REQ_MASK_CLR_12	: 1;
            uint32_t CHNL_REQ_MASK_CLR_13	: 1;
            uint32_t CHNL_REQ_MASK_CLR_14	: 1;
            uint32_t CHNL_REQ_MASK_CLR_15	: 1;
            uint32_t CHNL_REQ_MASK_CLR_16	: 1;
            uint32_t CHNL_REQ_MASK_CLR_17	: 1;
            uint32_t CHNL_REQ_MASK_CLR_18	: 1;
            uint32_t CHNL_REQ_MASK_CLR_19	: 1;
            uint32_t CHNL_REQ_MASK_CLR_20	: 1;
            uint32_t CHNL_REQ_MASK_CLR_21	: 1;
            uint32_t CHNL_REQ_MASK_CLR_22	: 1;
            uint32_t CHNL_REQ_MASK_CLR_23	: 1;
            uint32_t CHNL_REQ_MASK_CLR_24	: 1;
            uint32_t CHNL_REQ_MASK_CLR_25	: 1;
            uint32_t CHNL_REQ_MASK_CLR_26	: 1;
            uint32_t CHNL_REQ_MASK_CLR_27	: 1;
            uint32_t CHNL_REQ_MASK_CLR_28	: 1;
            uint32_t CHNL_REQ_MASK_CLR_29	: 1;
            uint32_t CHNL_REQ_MASK_CLR_30	: 1;
            uint32_t CHNL_REQ_MASK_CLR_31	: 1;
        } DMA_ChnlReqMaskClr_register;
    };
	union
	{
		volatile uint32_t DMAxChnlEnableSet; // DMAxChnlEnableSet (0x0028)
		struct DMAxChnlEnableSet_Register{
			uint32_t CHNL_ENABLE_SET_0	: 1;
			uint32_t CHNL_ENABLE_SET_1	: 1;
			uint32_t CHNL_ENABLE_SET_2	: 1;
			uint32_t CHNL_ENABLE_SET_3	: 1;
			uint32_t CHNL_ENABLE_SET_4	: 1;
			uint32_t CHNL_ENABLE_SET_5	: 1;
			uint32_t CHNL_ENABLE_SET_6	: 1;
			uint32_t CHNL_ENABLE_SET_7	: 1;
			uint32_t CHNL_ENABLE_SET_8	: 1;
			uint32_t CHNL_ENABLE_SET_9	: 1;
			uint32_t CHNL_ENABLE_SET_10	: 1;
			uint32_t CHNL_ENABLE_SET_11	: 1;
			uint32_t CHNL_ENABLE_SET_12	: 1;
			uint32_t CHNL_ENABLE_SET_13	: 1;
			uint32_t CHNL_ENABLE_SET_14	: 1;
			uint32_t CHNL_ENABLE_SET_15	: 1;
			uint32_t CHNL_ENABLE_SET_16	: 1;
			uint32_t CHNL_ENABLE_SET_17	: 1;
			uint32_t CHNL_ENABLE_SET_18	: 1;
			uint32_t CHNL_ENABLE_SET_19	: 1;
			uint32_t CHNL_ENABLE_SET_20	: 1;
			uint32_t CHNL_ENABLE_SET_21	: 1;
			uint32_t CHNL_ENABLE_SET_22	: 1;
			uint32_t CHNL_ENABLE_SET_23	: 1;
			uint32_t CHNL_ENABLE_SET_24	: 1;
			uint32_t CHNL_ENABLE_SET_25	: 1;
			uint32_t CHNL_ENABLE_SET_26	: 1;
			uint32_t CHNL_ENABLE_SET_27	: 1;
			uint32_t CHNL_ENABLE_SET_28	: 1;
			uint32_t CHNL_ENABLE_SET_29	: 1;
			uint32_t CHNL_ENABLE_SET_30	: 1;
			uint32_t CHNL_ENABLE_SET_31	: 1;
		} DMAxChnlEnableSet_register;
	};

	union
	{
		volatile uint32_t DMAxChnlEnableClr; // DMAxChnlEnableClr (0x002C)
		struct DMAxChnlEnableClr_Register
		{
			uint32_t CHNL_ENABLE_CLR_0	: 1;
			uint32_t CHNL_ENABLE_CLR_1	: 1;
			uint32_t CHNL_ENABLE_CLR_2	: 1;
			uint32_t CHNL_ENABLE_CLR_3	: 1;
			uint32_t CHNL_ENABLE_CLR_4	: 1;
			uint32_t CHNL_ENABLE_CLR_5	: 1;
			uint32_t CHNL_ENABLE_CLR_6	: 1;
			uint32_t CHNL_ENABLE_CLR_7	: 1;
			uint32_t CHNL_ENABLE_CLR_8	: 1;
			uint32_t CHNL_ENABLE_CLR_9	: 1;
			uint32_t CHNL_ENABLE_CLR_10	: 1;
			uint32_t CHNL_ENABLE_CLR_11	: 1;
			uint32_t CHNL_ENABLE_CLR_12	: 1;
			uint32_t CHNL_ENABLE_CLR_13	: 1;
			uint32_t CHNL_ENABLE_CLR_14	: 1;
			uint32_t CHNL_ENABLE_CLR_15	: 1;
			uint32_t CHNL_ENABLE_CLR_16	: 1;
			uint32_t CHNL_ENABLE_CLR_17	: 1;
			uint32_t CHNL_ENABLE_CLR_18	: 1;
			uint32_t CHNL_ENABLE_CLR_19	: 1;
			uint32_t CHNL_ENABLE_CLR_20	: 1;
			uint32_t CHNL_ENABLE_CLR_21	: 1;
			uint32_t CHNL_ENABLE_CLR_22	: 1;
			uint32_t CHNL_ENABLE_CLR_23	: 1;
			uint32_t CHNL_ENABLE_CLR_24	: 1;
			uint32_t CHNL_ENABLE_CLR_25	: 1;
			uint32_t CHNL_ENABLE_CLR_26	: 1;
			uint32_t CHNL_ENABLE_CLR_27	: 1;
			uint32_t CHNL_ENABLE_CLR_28	: 1;
			uint32_t CHNL_ENABLE_CLR_29	: 1;
			uint32_t CHNL_ENABLE_CLR_30	: 1;
			uint32_t CHNL_ENABLE_CLR_31	: 1;
		} DMAxChnlEnableClr_register;
	};

    union
	{
        volatile uint32_t DMAxChnlPriAltSet; // DMAxChnlPriAltSet (0x0030)
        struct DMAxChnlPriAltSet_Register
		{
            uint32_t CHNL_PRI_ALT_SET_0	: 1;
            uint32_t CHNL_PRI_ALT_SET_1	: 1;
            uint32_t CHNL_PRI_ALT_SET_2	: 1;
            uint32_t CHNL_PRI_ALT_SET_3	: 1;
            uint32_t CHNL_PRI_ALT_SET_4	: 1;
            uint32_t CHNL_PRI_ALT_SET_5	: 1;
            uint32_t CHNL_PRI_ALT_SET_6	: 1;
            uint32_t CHNL_PRI_ALT_SET_7	: 1;
            uint32_t CHNL_PRI_ALT_SET_8	: 1;
            uint32_t CHNL_PRI_ALT_SET_9	: 1;
            uint32_t CHNL_PRI_ALT_SET_10	: 1;
            uint32_t CHNL_PRI_ALT_SET_11	: 1;
            uint32_t CHNL_PRI_ALT_SET_12	: 1;
            uint32_t CHNL_PRI_ALT_SET_13	: 1;
            uint32_t CHNL_PRI_ALT_SET_14	: 1;
            uint32_t CHNL_PRI_ALT_SET_15	: 1;
            uint32_t CHNL_PRI_ALT_SET_16	: 1;
            uint32_t CHNL_PRI_ALT_SET_17	: 1;
            uint32_t CHNL_PRI_ALT_SET_18	: 1;
            uint32_t CHNL_PRI_ALT_SET_19	: 1;
            uint32_t CHNL_PRI_ALT_SET_20	: 1;
            uint32_t CHNL_PRI_ALT_SET_21	: 1;
            uint32_t CHNL_PRI_ALT_SET_22	: 1;
            uint32_t CHNL_PRI_ALT_SET_23	: 1;
            uint32_t CHNL_PRI_ALT_SET_24	: 1;
            uint32_t CHNL_PRI_ALT_SET_25	: 1;
            uint32_t CHNL_PRI_ALT_SET_26	: 1;
            uint32_t CHNL_PRI_ALT_SET_27	: 1;
            uint32_t CHNL_PRI_ALT_SET_28	: 1;
            uint32_t CHNL_PRI_ALT_SET_29	: 1;
            uint32_t CHNL_PRI_ALT_SET_30	: 1;
            uint32_t CHNL_PRI_ALT_SET_31	: 1;
        } DMAxChnlPriAltSet_register;
    };

    union
	{
        volatile uint32_t DMAxChnlPriAltClr; // DMAxChnlPriAltClr (0x0034)
        struct DMAxChnlPriAltClr_Register
		{
            uint32_t CHNL_PRI_ALT_CLR_0		: 1;
            uint32_t CHNL_PRI_ALT_CLR_1		: 1;
            uint32_t CHNL_PRI_ALT_CLR_2		: 1;
            uint32_t CHNL_PRI_ALT_CLR_3		: 1;
            uint32_t CHNL_PRI_ALT_CLR_4		: 1;
            uint32_t CHNL_PRI_ALT_CLR_5		: 1;
            uint32_t CHNL_PRI_ALT_CLR_6		: 1;
            uint32_t CHNL_PRI_ALT_CLR_7		: 1;
            uint32_t CHNL_PRI_ALT_CLR_8		: 1;
            uint32_t CHNL_PRI_ALT_CLR_9		: 1;
            uint32_t CHNL_PRI_ALT_CLR_10	: 1;
            uint32_t CHNL_PRI_ALT_CLR_11	: 1;
            uint32_t CHNL_PRI_ALT_CLR_12	: 1;
            uint32_t CHNL_PRI_ALT_CLR_13	: 1;
            uint32_t CHNL_PRI_ALT_CLR_14	: 1;
            uint32_t CHNL_PRI_ALT_CLR_15	: 1;
            uint32_t CHNL_PRI_ALT_CLR_16	: 1;
            uint32_t CHNL_PRI_ALT_CLR_17	: 1;
            uint32_t CHNL_PRI_ALT_CLR_18	: 1;
            uint32_t CHNL_PRI_ALT_CLR_19	: 1;
            uint32_t CHNL_PRI_ALT_CLR_20	: 1;
            uint32_t CHNL_PRI_ALT_CLR_21	: 1;
            uint32_t CHNL_PRI_ALT_CLR_22	: 1;
            uint32_t CHNL_PRI_ALT_CLR_23	: 1;
            uint32_t CHNL_PRI_ALT_CLR_24	: 1;
            uint32_t CHNL_PRI_ALT_CLR_25	: 1;
            uint32_t CHNL_PRI_ALT_CLR_26	: 1;
            uint32_t CHNL_PRI_ALT_CLR_27	: 1;
            uint32_t CHNL_PRI_ALT_CLR_28	: 1;
            uint32_t CHNL_PRI_ALT_CLR_29	: 1;
            uint32_t CHNL_PRI_ALT_CLR_30	: 1;
            uint32_t CHNL_PRI_ALT_CLR_31	: 1;
        } DMAxChnlPriAltClr_register;
    };

    union
	{
        volatile uint32_t DMAxChnlPrioritySet; // DMAxChnlPrioritySet (0x0038)
        struct DMAxChnlPrioritySet_Register
		{
            uint32_t CHNL_PRIORITY_SET_0	: 1;
            uint32_t CHNL_PRIORITY_SET_1	: 1;
            uint32_t CHNL_PRIORITY_SET_2	: 1;
            uint32_t CHNL_PRIORITY_SET_3	: 1;
            uint32_t CHNL_PRIORITY_SET_4	: 1;
            uint32_t CHNL_PRIORITY_SET_5	: 1;
            uint32_t CHNL_PRIORITY_SET_6	: 1;
            uint32_t CHNL_PRIORITY_SET_7	: 1;
            uint32_t CHNL_PRIORITY_SET_8	: 1;
            uint32_t CHNL_PRIORITY_SET_9	: 1;
            uint32_t CHNL_PRIORITY_SET_10	: 1;
            uint32_t CHNL_PRIORITY_SET_11	: 1;
            uint32_t CHNL_PRIORITY_SET_12	: 1;
            uint32_t CHNL_PRIORITY_SET_13	: 1;
            uint32_t CHNL_PRIORITY_SET_14	: 1;
            uint32_t CHNL_PRIORITY_SET_15	: 1;
            uint32_t CHNL_PRIORITY_SET_16	: 1;
            uint32_t CHNL_PRIORITY_SET_17	: 1;
            uint32_t CHNL_PRIORITY_SET_18	: 1;
            uint32_t CHNL_PRIORITY_SET_19	: 1;
            uint32_t CHNL_PRIORITY_SET_20	: 1;
            uint32_t CHNL_PRIORITY_SET_21	: 1;
            uint32_t CHNL_PRIORITY_SET_22	: 1;
            uint32_t CHNL_PRIORITY_SET_23	: 1;
            uint32_t CHNL_PRIORITY_SET_24	: 1;
            uint32_t CHNL_PRIORITY_SET_25	: 1;
            uint32_t CHNL_PRIORITY_SET_26	: 1;
            uint32_t CHNL_PRIORITY_SET_27	: 1;
            uint32_t CHNL_PRIORITY_SET_28	: 1;
            uint32_t CHNL_PRIORITY_SET_29	: 1;
            uint32_t CHNL_PRIORITY_SET_30	: 1;
            uint32_t CHNL_PRIORITY_SET_31	: 1;
        } DMAxChnlPrioritySet_register;
    };

    union
	{
        volatile uint32_t DMAxChnlPriorityClr; // DMAxChnlPriorityClr (0x003C)
        struct DMAxChnlPriorityClr_Register
		{
            uint32_t CHNL_PRIORITY_CLR_0	: 1;
            uint32_t CHNL_PRIORITY_CLR_1	: 1;
            uint32_t CHNL_PRIORITY_CLR_2	: 1;
            uint32_t CHNL_PRIORITY_CLR_3	: 1;
            uint32_t CHNL_PRIORITY_CLR_4	: 1;
            uint32_t CHNL_PRIORITY_CLR_5	: 1;
            uint32_t CHNL_PRIORITY_CLR_6	: 1;
            uint32_t CHNL_PRIORITY_CLR_7	: 1;
            uint32_t CHNL_PRIORITY_CLR_8	: 1;
            uint32_t CHNL_PRIORITY_CLR_9	: 1;
            uint32_t CHNL_PRIORITY_CLR_10	: 1;
            uint32_t CHNL_PRIORITY_CLR_11	: 1;
            uint32_t CHNL_PRIORITY_CLR_12	: 1;
            uint32_t CHNL_PRIORITY_CLR_13	: 1;
            uint32_t CHNL_PRIORITY_CLR_14	: 1;
            uint32_t CHNL_PRIORITY_CLR_15	: 1;
            uint32_t CHNL_PRIORITY_CLR_16	: 1;
            uint32_t CHNL_PRIORITY_CLR_17	: 1;
            uint32_t CHNL_PRIORITY_CLR_18	: 1;
            uint32_t CHNL_PRIORITY_CLR_19	: 1;
            uint32_t CHNL_PRIORITY_CLR_20	: 1;
            uint32_t CHNL_PRIORITY_CLR_21	: 1;
            uint32_t CHNL_PRIORITY_CLR_22	: 1;
            uint32_t CHNL_PRIORITY_CLR_23	: 1;
            uint32_t CHNL_PRIORITY_CLR_24	: 1;
            uint32_t CHNL_PRIORITY_CLR_25	: 1;
            uint32_t CHNL_PRIORITY_CLR_26	: 1;
            uint32_t CHNL_PRIORITY_CLR_27	: 1;
            uint32_t CHNL_PRIORITY_CLR_28	: 1;
            uint32_t CHNL_PRIORITY_CLR_29	: 1;
            uint32_t CHNL_PRIORITY_CLR_30	: 1;
            uint32_t CHNL_PRIORITY_CLR_31	: 1;
		} DMAxChnlPriorityClr_register;
	};
    
	uint32_t RESERVED1[3];

	union
	{
		volatile uint32_t DMAxErrClr;  // DMAxErrClr
		struct DMAxErrClr_Register 
		{
			uint32_t ERR_CLR		: 1;  // Bit 0:		Writing "1" clears a bus error. Writing "0" has no meaning.
			uint32_t RESERVED_0 	: 31;
		} DMAxErrClr_register;
	};

	uint32_t RESERVED2[0x4BEC];
	union
	{
		volatile uint32_t DMA_FLG;  // DMAxErrClr
		struct DMA_FLG_Register 
		{
            uint32_t FLG_0	: 1;
            uint32_t FLG_1	: 1;
            uint32_t FLG_2	: 1;
            uint32_t FLG_3	: 1;
            uint32_t FLG_4	: 1;
            uint32_t FLG_5	: 1;
            uint32_t FLG_6	: 1;
            uint32_t FLG_7	: 1;
            uint32_t FLG_8	: 1;
            uint32_t FLG_9	: 1;
            uint32_t FLG_10	: 1;
            uint32_t FLG_11	: 1;
            uint32_t FLG_12	: 1;
            uint32_t FLG_13	: 1;
            uint32_t FLG_14	: 1;
            uint32_t FLG_15	: 1;
            uint32_t FLG_16	: 1;
            uint32_t FLG_17	: 1;
            uint32_t FLG_18	: 1;
            uint32_t FLG_19	: 1;
            uint32_t FLG_20	: 1;
            uint32_t FLG_21	: 1;
            uint32_t FLG_22	: 1;
            uint32_t FLG_23	: 1;
            uint32_t FLG_24	: 1;
            uint32_t FLG_25	: 1;
            uint32_t FLG_26	: 1;
            uint32_t FLG_27	: 1;
            uint32_t FLG_28	: 1;
            uint32_t FLG_29	: 1;
            uint32_t FLG_30	: 1;
            uint32_t FLG_31	: 1;
		} DMA_FLG_register;
	};
}WROS_DMA___Typedef;


//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//************************** Direct Memory Access ******************************//



//******************************* Clock generator ******************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
typedef struct
{
	union {
		volatile	uint32_t SYSCR;         // System Control Register
		struct SYSCR_Register 
		{
            uint32_t GEAR 			: 3;        // 时钟齿轮分频比：000=fc, 100=fc/2 等
            uint32_t Reserved_0		: 5;   		// 位3-5，只读0
            uint32_t PRCK 			: 3;        // 预分频时钟(φT0)分频比：000=fc, 001=fc/2 等
            uint32_t Reserved_1		: 1;   		// 位3-5，只读0
            uint32_t FPSSEL 		: 1;      	// 外设时钟(fperiph)源选择：0=fgear, 1=fc
            uint32_t Reserved_2		: 3;   		// 位3-5，只读0
            uint32_t Reserved_3		: 16;  		// 位13-31，只读0（位17-16需写01)
		} SYSCR_register;
	};

	union {
		volatile	uint32_t OSCCR;         // Oscillation Control Register
		struct OSCCR_Register 
		{
            uint32_t WUEON			: 1;      	// 预热定时器控制：1=启动（写0无意义）
            uint32_t WUEF			: 1;       	// 预热定时器状态：0=完成, 1=运行
            uint32_t PLLON			: 1;      	// PLL操作控制：0=停止, 1=振荡
            uint32_t WUPSEL1		: 1;    	// 预热定时器时钟源，必须写0
            uint32_t Reserved_1		: 4;   		// 位4-6，只读0
            uint32_t XEN1			: 1;       	// 外部高速振荡器(EOSC)使能：0=禁用, 1=使能
            uint32_t Reserved_2		: 7;   		// 位9-15，写0或只读0
            uint32_t XEN2			: 1;       	// 内部高速振荡器(IOSC)使能：0=禁用, 1=使能
            uint32_t OSCSEL			: 1;     	// 高速振荡器源选择：0=内部(fiosc), 1=外部(fosc)
            uint32_t HOSCON			: 1;   		// Port M or X1/X2		0: Port M	1: X1/X2 (fEHOSC)
            uint32_t WUPSEL2		: 1;    	// 预热定时器时钟源选择：0=内部(fiosc), 1=外部(fosc)
            uint32_t WUODR			: 12;   	// 高速振荡器预热定时器比较值（12位）
		} OSCCR_register;
	};


	union {
		volatile	uint32_t STBYCR;            // Standby Control Register
		struct STBYCR_Register
		{
            uint32_t STBY			: 3;       	// 低功耗模式选择：001=STOP, 011=IDLE 等
            uint32_t Reserved_0		: 5; 		// 位3-7，只读0
            uint32_t RXEN			: 1;       	// STOP模式退出后高速振荡器使能，写1
            uint32_t Reserved_1		: 7;   		// 位9-15，写0或只读0
            uint32_t Reserved_2		: 16;  		// 位16-31，只读0或写0
		} STBYCR_register;
	};

	union {
		volatile	uint32_t PLLSEL;            // PLL Selection Register
		struct PLLSEL_Register 
		{
            uint32_t PLLSEL			: 1;     	// 高速时钟(fc)源选择：0=fosc, 1=fpu
            uint32_t PLLSET			: 15;   	// PLL倍增值（如0x591E对应10MHz输入→80MHz输出等）
            uint32_t Reserved_0		: 16;  		// 位16-31，只读0
		} PLLSEL_register;
	};

	union {
		volatile	uint32_t CKSEL;			 				// System Clock Selection Register
		struct CKSEL_Register 
		{
            uint32_t SYSCKFLG		: 1;     	// System clock status	0: high-speed	1: low-speed	(Read Only)
            uint32_t SYSCK			: 1;   		// Selects system clock	0: high-speed	1: low-speed
            uint32_t Reserved_0		: 30;
		} CKSEL_register;
	};

	union {
		volatile	uint32_t ICRCG;             // CG Interrupt Request Clear Register
		struct ICRCG_Register {
			uint32_t ICRCG			: 5;		
            uint32_t Reserved_0		: 3;
            uint32_t Reserved_1		: 24;  		// 位16-31，只读0
		} ICRCG_register;
	};

	union {
		volatile	uint32_t NMIFLG;             // NMI Flag Register
		struct NMIFLG_Register {
			uint32_t NMIFLG0		: 1;		//	cleared to "0" when they are read.	(Read Only)
            uint32_t Reserved_0		: 31;
		} NMIFLG_register;
	};

	union {
		volatile	uint32_t RSTFLG;            // Reset Flag Register
		struct RSTFLG_Register {
            uint32_t PONRSTF		: 1;    	// 上电复位标志：bit0，读1表示上电复位，写0清除
            uint32_t PINRSTF		: 1;    	// 复位引脚标志：bit1，读1表示复位引脚触发，写0清除
            uint32_t WDTRSTF		: 1;    	// 看门狗复位标志：bit2，读1表示WDT触发，写0清除
            uint32_t VLTDRSTF		: 1;   		// 电压检测复位标志：bit3，读1表示VLTD触发，写0清除
            uint32_t DBGRSTF		: 1;   		// 调试复位标志：bit4，读1表示SYSRESETREQ触发，写0清除
            uint32_t OFDRSTF		: 1;   		// OFD复位标志：bit5，读1表示OFD触发，写0清除
            uint32_t Reserved_0	: 2; 		// bit6-7，只读0
            uint32_t Reserved_1	: 24;		// bit8-31，只读0
		} RSTFLG_register;
	};

	union {
		volatile	uint32_t IMCGA;             // CG Interrupt Mode Control Register A
		struct IMCGA_Register {
            uint32_t INT00EN		: 1;    	// INT00使能：bit0，0=禁用，1=使能
            uint32_t Reserved_0 	: 1; 		// bit1，undefined
            uint32_t EMST00		: 2;     	// INT00边沿控制：bit3-2
            uint32_t EMCG00		: 3;     	// INT00模式控制：bit7-6
            uint32_t Reserved_1 	: 1; 		// bit1，undefined
			
            uint32_t INT01EN		: 1;    	// INT01使能：bit8，0=禁用，1=使能
            uint32_t Reserved_2 	: 1; 		// bit9，undefined
            uint32_t EMST01		: 2;     	// INT01边沿控制：bit11-10
            uint32_t EMCG01		: 3;     	// INT01模式控制：bit15-14
            uint32_t Reserved_3 	: 1; 		// bit9，undefined
			
            uint32_t INT02EN		: 1;    	// INT02使能：bit16，0=禁用，1=使能
            uint32_t Reserved_4 	: 1; 		// bit17，undefined
            uint32_t EMST02		: 2;     	// INT02边沿控制：bit19-18
            uint32_t EMCG02		: 3;     	// INT02模式控制：bit23-22
            uint32_t Reserved_5 	: 1; 		// bit9，undefined
			
            uint32_t INT03EN		: 1;   		// INT03使能：bit24，0=禁用，1=使能
            uint32_t Reserved_6 	: 1; 		// bit25，undefined
            uint32_t EMST03		: 2;     	// INT03边沿控制：bit27-26
            uint32_t EMCG03		: 3;     	// INT03模式控制：bit31-30
            uint32_t Reserved_7 	: 1; 		// bit9，undefined
		} IMCGA_register;
	};
	
	union {
		volatile	uint32_t IMCGB;             // CG Interrupt Mode Control Register B
		struct IMCGB_Register {
            uint32_t INT04EN		: 1;    	// INT00使能：bit0，0=禁用，1=使能
            uint32_t Reserved_0 	: 1; 		// bit1，undefined
            uint32_t EMST04		: 2;     	// INT00边沿控制：bit3-2
            uint32_t EMCG04		: 3;     	// INT00模式控制：bit7-6
            uint32_t Reserved_1 	: 1; 		// bit1，undefined
			
            uint32_t INT05EN		: 1;    	// INT01使能：bit8，0=禁用，1=使能
            uint32_t Reserved_2 	: 1; 		// bit9，undefined
            uint32_t EMST05		: 2;     	// INT01边沿控制：bit11-10
            uint32_t EMCG05		: 3;     	// INT01模式控制：bit15-14
            uint32_t Reserved_3 	: 1; 		// bit9，undefined
			
            uint32_t INT06EN		: 1;    	// INT02使能：bit16，0=禁用，1=使能
            uint32_t Reserved_4 	: 1; 		// bit17，undefined
            uint32_t EMST06		: 2;     	// INT02边沿控制：bit19-18
            uint32_t EMCG06		: 3;     	// INT02模式控制：bit23-22
            uint32_t Reserved_5 	: 1; 		// bit9，undefined
			
            uint32_t INT07EN		: 1;   		// INT03使能：bit24，0=禁用，1=使能
            uint32_t Reserved_6 	: 1; 		// bit25，undefined
            uint32_t EMST07		: 2;     	// INT03边沿控制：bit27-26
            uint32_t EMCG07		: 3;     	// INT03模式控制：bit31-30
            uint32_t Reserved_7 	: 1; 		// bit9，undefined
		} IMCGB_register;
	};
	
	union {
		volatile	uint32_t IMCGC;             // CG Interrupt Mode Control Register C
		struct IMCGC_Register {
            uint32_t INT08EN		: 1;    	// INT00使能：bit0，0=禁用，1=使能
            uint32_t Reserved_0 	: 1; 		// bit1，undefined
            uint32_t EMST08		: 2;     	// INT00边沿控制：bit3-2
            uint32_t EMCG08		: 3;     	// INT00模式控制：bit7-6
            uint32_t Reserved_1 	: 1; 		// bit1，undefined
			
            uint32_t INT09EN		: 1;    	// INT01使能：bit8，0=禁用，1=使能
            uint32_t Reserved_2 	: 1; 		// bit9，undefined
            uint32_t EMST09		: 2;     	// INT01边沿控制：bit11-10
            uint32_t EMCG09		: 3;     	// INT01模式控制：bit15-14
            uint32_t Reserved_3 	: 1; 		// bit9，undefined
			
            uint32_t INT0AEN		: 1;    	// INT02使能：bit16，0=禁用，1=使能
            uint32_t Reserved_4 	: 1; 		// bit17，undefined
            uint32_t EMST0A		: 2;     	// INT02边沿控制：bit19-18
            uint32_t EMCG0A		: 3;     	// INT02模式控制：bit23-22
            uint32_t Reserved_5 	: 1; 		// bit9，undefined
			
            uint32_t INT0BEN		: 1;   		// INT03使能：bit24，0=禁用，1=使能
            uint32_t Reserved_6 	: 1; 		// bit25，undefined
            uint32_t EMST0B		: 2;     	// INT03边沿控制：bit27-26
            uint32_t EMCG0B		: 3;     	// INT03模式控制：bit31-30
            uint32_t Reserved_7 	: 1; 		// bit9，undefined
		} IMCGC_register;
	};
	
	union {
		volatile	uint32_t IMCGD;             // CG Interrupt Mode Control Register D
		struct IMCGD_Register {
            uint32_t INT0CEN		: 1;    	// INT00使能：bit0，0=禁用，1=使能
            uint32_t Reserved_0 	: 1; 		// bit1，undefined
            uint32_t EMST0C		: 2;     	// INT00边沿控制：bit3-2
            uint32_t EMCG0C		: 3;     	// INT00模式控制：bit7-6
            uint32_t Reserved_1 	: 1; 		// bit1，undefined
			
            uint32_t INT0DEN		: 1;    	// INT01使能：bit8，0=禁用，1=使能
            uint32_t Reserved_2 	: 1; 		// bit9，undefined
            uint32_t EMST0D		: 2;     	// INT01边沿控制：bit11-10
            uint32_t EMCG0D		: 3;     	// INT01模式控制：bit15-14
            uint32_t Reserved_3 	: 1; 		// bit9，undefined
			
            uint32_t INT0EEN		: 1;    	// INT02使能：bit16，0=禁用，1=使能
            uint32_t Reserved_4 	: 1; 		// bit17，undefined
            uint32_t EMST0E		: 2;     	// INT02边沿控制：bit19-18
            uint32_t EMCG0E		: 3;     	// INT02模式控制：bit23-22
            uint32_t Reserved_5 	: 1; 		// bit9，undefined
			
            uint32_t INT0FEN		: 1;   		// INT03使能：bit24，0=禁用，1=使能
            uint32_t Reserved_6 	: 1; 		// bit25，undefined
            uint32_t EMST0F		: 2;     	// INT03边沿控制：bit27-26
            uint32_t EMCG0F		: 3;     	// INT03模式控制：bit31-30
            uint32_t Reserved_7 	: 1; 		// bit9，undefined
		} IMCGD_register;
	};

} WROS_CLKGE_TypeDef;

//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//******************************* Clock generator ******************************//



//*********************** General Purpose Input/Output *************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//

typedef struct
{
	// MOD (WD Mode Register)
    union {
        volatile uint32_t WDT_MOD;                // WD Mode Register
        struct WDT_MOD_Register {
            uint32_t RESERVED_0	: 1;		// Write 0
            uint32_t RESCR		: 1;
            uint32_t I2WDT		: 1; 
            uint32_t RESERVED_1	: 1; 
            uint32_t WDTP		: 3; 
            uint32_t WDTE		: 1; 
            uint32_t RESERVED_2	: 24; 
        } WDT_MOD_register;
    };
	
	// CR (WD Control Register)
    union {
        volatile uint32_t WDT_CR;                // WD Control Register
        struct WDT_CR_Register {
            uint32_t TMCR		: 8;
            uint32_t RESERVED_0	: 24; 
        } WDT_CR_register;
    };
} WROS_WDT___TypeDef;

typedef struct {
    // 数据寄存器：16个引脚单独控制
	union {
		volatile uint32_t DATA;              /*!< Port Data Register                           */
		struct DATA_Register {
			uint32_t DATA_0      : 1;    /*!< Pin 0 Data (0: Low, 1: High)                 */
			uint32_t DATA_1      : 1;    /*!< Pin 1 Data (0: Low, 1: High)                 */
			uint32_t DATA_2      : 1;    /*!< Pin 2 Data (0: Low, 1: High)                 */
			uint32_t DATA_3      : 1;    /*!< Pin 3 Data (0: Low, 1: High)                 */
			uint32_t DATA_4      : 1;    /*!< Pin 4 Data (0: Low, 1: High)                 */
			uint32_t DATA_5      : 1;    /*!< Pin 5 Data (0: Low, 1: High)                 */
			uint32_t DATA_6      : 1;    /*!< Pin 6 Data (0: Low, 1: High)                 */
			uint32_t DATA_7      : 1;    /*!< Pin 7 Data (0: Low, 1: High)                 */
			uint32_t DATA_8      : 1;    /*!< Pin 8 Data (0: Low, 1: High)                 */
			uint32_t DATA_9      : 1;    /*!< Pin 9 Data (0: Low, 1: High)                 */
			uint32_t DATA_10     : 1;    /*!< Pin 10 Data (0: Low, 1: High)                */
			uint32_t DATA_11     : 1;    /*!< Pin 11 Data (0: Low, 1: High)                */
			uint32_t DATA_12     : 1;    /*!< Pin 12 Data (0: Low, 1: High)                */
			uint32_t DATA_13     : 1;    /*!< Pin 13 Data (0: Low, 1: High)                */
			uint32_t DATA_14     : 1;    /*!< Pin 14 Data (0: Low, 1: High)                */
			uint32_t DATA_15     : 1;    /*!< Pin 15 Data (0: Low, 1: High)                */
			uint32_t RESERVED    : 16;   /*!< Reserved Bits                                */
		} DATA_register;
	};

    // 输出控制寄存器：16个引脚单独使能
    union {
        volatile uint32_t CR;                /*!< Port Output Control Register                 */
        struct CR___Register {
            uint32_t CR___0        : 1;    /*!< Pin 0 Output Enable (0: Disable, 1: Enable)  */
            uint32_t CR___1        : 1;    /*!< Pin 1 Output Enable (0: Disable, 1: Enable)  */
            uint32_t CR___2        : 1;    /*!< Pin 2 Output Enable (0: Disable, 1: Enable)  */
            uint32_t CR___3        : 1;    /*!< Pin 3 Output Enable (0: Disable, 1: Enable)  */
            uint32_t CR___4        : 1;    /*!< Pin 4 Output Enable (0: Disable, 1: Enable)  */
            uint32_t CR___5        : 1;    /*!< Pin 5 Output Enable (0: Disable, 1: Enable)  */
            uint32_t CR___6        : 1;    /*!< Pin 6 Output Enable (0: Disable, 1: Enable)  */
            uint32_t CR___7        : 1;    /*!< Pin 7 Output Enable (0: Disable, 1: Enable)  */
            uint32_t CR___8        : 1;    /*!< Pin 8 Output Enable (0: Disable, 1: Enable)  */
            uint32_t CR___9        : 1;    /*!< Pin 9 Output Enable (0: Disable, 1: Enable)  */
            uint32_t CR___10       : 1;    /*!< Pin 10 Output Enable (0: Disable, 1: Enable) */
            uint32_t CR___11       : 1;    /*!< Pin 11 Output Enable (0: Disable, 1: Enable) */
            uint32_t CR___12       : 1;    /*!< Pin 12 Output Enable (0: Disable, 1: Enable) */
            uint32_t CR___13       : 1;    /*!< Pin 13 Output Enable (0: Disable, 1: Enable) */
            uint32_t CR___14       : 1;    /*!< Pin 14 Output Enable (0: Disable, 1: Enable) */
            uint32_t CR___15       : 1;    /*!< Pin 15 Output Enable (0: Disable, 1: Enable) */
            uint32_t RESERVED      : 16;   /*!< Reserved Bits                                */
        } CR___register;
    };

    // 功能寄存器1：低8引脚复用选择（每引脚3位）
    union {
        volatile uint32_t FR1;               /*!< Port Function Register 1                     */
        struct FR1__Register {            
			uint32_t FR1__0        : 1;    /*!< Pin 0 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR1__1        : 1;    /*!< Pin 1 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR1__2        : 1;    /*!< Pin 2 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR1__3        : 1;    /*!< Pin 3 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR1__4        : 1;    /*!< Pin 4 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR1__5        : 1;    /*!< Pin 5 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR1__6        : 1;    /*!< Pin 6 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR1__7        : 1;    /*!< Pin 7 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR1__8        : 1;    /*!< Pin 8 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR1__9        : 1;    /*!< Pin 9 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR1__10       : 1;    /*!< Pin 10 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR1__11       : 1;    /*!< Pin 11 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR1__12       : 1;    /*!< Pin 12 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR1__13       : 1;    /*!< Pin 13 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR1__14       : 1;    /*!< Pin 14 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR1__15       : 1;    /*!< Pin 15 Function Enable (0: Disable, 1: Enable) */
            uint32_t RESERVED      : 16;   /*!< Reserved Bits                                */
        } FR1__register;
    };

    // 功能寄存器2：高8引脚复用选择（每引脚3位）
    union {
        volatile uint32_t FR2;               /*!< Port Function Register 2                     */
        struct FR2__Register {
			uint32_t FR2__0        : 1;    /*!< Pin 0 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR2__1        : 1;    /*!< Pin 1 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR2__2        : 1;    /*!< Pin 2 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR2__3        : 1;    /*!< Pin 3 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR2__4        : 1;    /*!< Pin 4 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR2__5        : 1;    /*!< Pin 5 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR2__6        : 1;    /*!< Pin 6 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR2__7        : 1;    /*!< Pin 7 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR2__8        : 1;    /*!< Pin 8 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR2__9        : 1;    /*!< Pin 9 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR2__10       : 1;    /*!< Pin 10 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR2__11       : 1;    /*!< Pin 11 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR2__12       : 1;    /*!< Pin 12 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR2__13       : 1;    /*!< Pin 13 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR2__14       : 1;    /*!< Pin 14 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR2__15       : 1;    /*!< Pin 15 Function Enable (0: Disable, 1: Enable) */
            uint32_t RESERVED      : 16;   /*!< Reserved Bits                                */
        } FR2__register;
    };

    // 功能寄存器3：扩展功能配置（每引脚3位）
    union {
        volatile uint32_t FR3;               /*!< Port Function Register 3                     */
        struct FR3__Register {
			uint32_t FR3__0        : 1;    /*!< Pin 0 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR3__1        : 1;    /*!< Pin 1 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR3__2        : 1;    /*!< Pin 2 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR3__3        : 1;    /*!< Pin 3 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR3__4        : 1;    /*!< Pin 4 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR3__5        : 1;    /*!< Pin 5 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR3__6        : 1;    /*!< Pin 6 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR3__7        : 1;    /*!< Pin 7 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR3__8        : 1;    /*!< Pin 8 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR3__9        : 1;    /*!< Pin 9 Function Enable (0: Disable, 1: Enable)  */
            uint32_t FR3__10       : 1;    /*!< Pin 10 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR3__11       : 1;    /*!< Pin 11 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR3__12       : 1;    /*!< Pin 12 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR3__13       : 1;    /*!< Pin 13 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR3__14       : 1;    /*!< Pin 14 Function Enable (0: Disable, 1: Enable) */
            uint32_t FR3__15       : 1;    /*!< Pin 15 Function Enable (0: Disable, 1: Enable) */
            uint32_t RESERVED      : 16;   /*!< Reserved Bits                                */

        } FR3__register;
    };

    uint32_t RESERVED0[5];              /*!< Reserved Registers (5 * 32-bit)              */

    // 开漏控制寄存器：16个引脚单独配置
    union {
        volatile uint32_t OD;                /*!< Port Open Drain Control Register             */
        struct OD___Register {
            uint32_t OD___0        : 1;    /*!< Pin 0 Open Drain (0: CMOS, 1: Open Drain)    */
            uint32_t OD___1        : 1;    /*!< Pin 1 Open Drain (0: CMOS, 1: Open Drain)    */
            uint32_t OD___2        : 1;    /*!< Pin 2 Open Drain (0: CMOS, 1: Open Drain)    */
            uint32_t OD___3        : 1;    /*!< Pin 3 Open Drain (0: CMOS, 1: Open Drain)    */
            uint32_t OD___4        : 1;    /*!< Pin 4 Open Drain (0: CMOS, 1: Open Drain)    */
            uint32_t OD___5        : 1;    /*!< Pin 5 Open Drain (0: CMOS, 1: Open Drain)    */
            uint32_t OD___6        : 1;    /*!< Pin 6 Open Drain (0: CMOS, 1: Open Drain)    */
            uint32_t OD___7        : 1;    /*!< Pin 7 Open Drain (0: CMOS, 1: Open Drain)    */
            uint32_t OD___8        : 1;    /*!< Pin 8 Open Drain (0: CMOS, 1: Open Drain)    */
            uint32_t OD___9        : 1;    /*!< Pin 9 Open Drain (0: CMOS, 1: Open Drain)    */
            uint32_t OD___10       : 1;    /*!< Pin 10 Open Drain (0: CMOS, 1: Open Drain)   */
            uint32_t OD___11       : 1;    /*!< Pin 11 Open Drain (0: CMOS, 1: Open Drain)   */
            uint32_t OD___12       : 1;    /*!< Pin 12 Open Drain (0: CMOS, 1: Open Drain)   */
            uint32_t OD___13       : 1;    /*!< Pin 13 Open Drain (0: CMOS, 1: Open Drain)   */
            uint32_t OD___14       : 1;    /*!< Pin 14 Open Drain (0: CMOS, 1: Open Drain)   */
            uint32_t OD___15       : 1;    /*!< Pin 15 Open Drain (0: CMOS, 1: Open Drain)   */
            uint32_t RESERVED      : 16;   /*!< Reserved Bits                                */
        } OD___register;
    };

    // 上拉控制寄存器：16个引脚单独配置
    union {
        volatile uint32_t PUP;               /*!< Port Pull-up Control Register                */
        struct PUP__Register {
            uint32_t PUP__0       : 1;    /*!< Pin 0 Pull-up (0: Disable, 1: Enable)        */
            uint32_t PUP__1       : 1;    /*!< Pin 1 Pull-up (0: Disable, 1: Enable)        */
            uint32_t PUP__2       : 1;    /*!< Pin 2 Pull-up (0: Disable, 1: Enable)        */
            uint32_t PUP__3       : 1;    /*!< Pin 3 Pull-up (0: Disable, 1: Enable)        */
            uint32_t PUP__4       : 1;    /*!< Pin 4 Pull-up (0: Disable, 1: Enable)        */
            uint32_t PUP__5       : 1;    /*!< Pin 5 Pull-up (0: Disable, 1: Enable)        */
            uint32_t PUP__6       : 1;    /*!< Pin 6 Pull-up (0: Disable, 1: Enable)        */
            uint32_t PUP__7       : 1;    /*!< Pin 7 Pull-up (0: Disable, 1: Enable)        */
            uint32_t PUP__8       : 1;    /*!< Pin 8 Pull-up (0: Disable, 1: Enable)        */
            uint32_t PUP__9       : 1;    /*!< Pin 9 Pull-up (0: Disable, 1: Enable)        */
            uint32_t PUP__10      : 1;    /*!< Pin 10 Pull-up (0: Disable, 1: Enable)       */
            uint32_t PUP__11      : 1;    /*!< Pin 11 Pull-up (0: Disable, 1: Enable)       */
            uint32_t PUP__12      : 1;    /*!< Pin 12 Pull-up (0: Disable, 1: Enable)       */
            uint32_t PUP__13      : 1;    /*!< Pin 13 Pull-up (0: Disable, 1: Enable)       */
            uint32_t PUP__14      : 1;    /*!< Pin 14 Pull-up (0: Disable, 1: Enable)       */
            uint32_t PUP__15      : 1;    /*!< Pin 15 Pull-up (0: Disable, 1: Enable)       */
            uint32_t RESERVED     : 16;   /*!< Reserved Bits                                */
        } PUP__register;
    };

    // 下拉控制寄存器：16个引脚单独配置
    union {
        volatile uint32_t PDN;               /*!< Port Pull-down Control Register              */
        struct PDN__Register {
            uint32_t PDN__0       : 1;    /*!< Pin 0 Pull-down (0: Disable, 1: Enable)      */
            uint32_t PDN__1       : 1;    /*!< Pin 1 Pull-down (0: Disable, 1: Enable)      */
            uint32_t PDN__2       : 1;    /*!< Pin 2 Pull-down (0: Disable, 1: Enable)      */
            uint32_t PDN__3       : 1;    /*!< Pin 3 Pull-down (0: Disable, 1: Enable)      */
            uint32_t PDN__4       : 1;    /*!< Pin 4 Pull-down (0: Disable, 1: Enable)      */
            uint32_t PDN__5       : 1;    /*!< Pin 5 Pull-down (0: Disable, 1: Enable)      */
            uint32_t PDN__6       : 1;    /*!< Pin 6 Pull-down (0: Disable, 1: Enable)      */
            uint32_t PDN__7       : 1;    /*!< Pin 7 Pull-down (0: Disable, 1: Enable)      */
            uint32_t PDN__8       : 1;    /*!< Pin 8 Pull-down (0: Disable, 1: Enable)      */
            uint32_t PDN__9       : 1;    /*!< Pin 9 Pull-down (0: Disable, 1: Enable)      */
            uint32_t PDN__10      : 1;    /*!< Pin 10 Pull-down (0: Disable, 1: Enable)     */
            uint32_t PDN__11      : 1;    /*!< Pin 11 Pull-down (0: Disable, 1: Enable)     */
            uint32_t PDN__12      : 1;    /*!< Pin 12 Pull-down (0: Disable, 1: Enable)     */
            uint32_t PDN__13      : 1;    /*!< Pin 13 Pull-down (0: Disable, 1: Enable)     */
            uint32_t PDN__14      : 1;    /*!< Pin 14 Pull-down (0: Disable, 1: Enable)     */
            uint32_t PDN__15      : 1;    /*!< Pin 15 Pull-down (0: Disable, 1: Enable)     */
            uint32_t RESERVED     : 16;   /*!< Reserved Bits                                */
        } PDN__register;
    };

    uint32_t RESERVED1;                 /*!< Reserved Register                            */

    // 输入控制寄存器：16个引脚单独配置
    union {
        volatile uint32_t IE;                /*!< Port Input Control Register                  */
        struct IE___Register {
            uint32_t IE___0        : 1;    /*!< Pin 0 Input Enable (0: Disable, 1: Enable)   */
            uint32_t IE___1        : 1;    /*!< Pin 1 Input Enable (0: Disable, 1: Enable)   */
            uint32_t IE___2        : 1;    /*!< Pin 2 Input Enable (0: Disable, 1: Enable)   */
            uint32_t IE___3        : 1;    /*!< Pin 3 Input Enable (0: Disable, 1: Enable)   */
            uint32_t IE___4        : 1;    /*!< Pin 4 Input Enable (0: Disable, 1: Enable)   */
            uint32_t IE___5        : 1;    /*!< Pin 5 Input Enable (0: Disable, 1: Enable)   */
            uint32_t IE___6        : 1;    /*!< Pin 6 Input Enable (0: Disable, 1: Enable)   */
            uint32_t IE___7        : 1;    /*!< Pin 7 Input Enable (0: Disable, 1: Enable)   */
            uint32_t IE___8        : 1;    /*!< Pin 8 Input Enable (0: Disable, 1: Enable)   */
            uint32_t IE___9        : 1;    /*!< Pin 9 Input Enable (0: Disable, 1: Enable)   */
            uint32_t IE___10       : 1;    /*!< Pin 10 Input Enable (0: Disable, 1: Enable)  */
            uint32_t IE___11       : 1;    /*!< Pin 11 Input Enable (0: Disable, 1: Enable)  */
            uint32_t IE___12       : 1;    /*!< Pin 12 Input Enable (0: Disable, 1: Enable)  */
            uint32_t IE___13       : 1;    /*!< Pin 13 Input Enable (0: Disable, 1: Enable)  */
            uint32_t IE___14       : 1;    /*!< Pin 14 Input Enable (0: Disable, 1: Enable)  */
            uint32_t IE___15       : 1;    /*!< Pin 15 Input Enable (0: Disable, 1: Enable)  */
            uint32_t RESERVED      : 16;   /*!< Reserved Bits                                */
        } IE___register;
    };
} WROS_PORT__TypeDef;
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//******************************************************************************//
//*********************** General Purpose Input/Output *************************//


typedef struct {
    // TBxEN (Enable register)
    union {
        volatile uint32_t EN;                /*!< TB Enable Register                           */
        struct EN___Register {
            uint32_t RESERVED1	: 6;   /*!< Reserved Bits (Read as 0)                    */
            uint32_t TB_HALT		: 1;    /*!< Clock operation during debug HALT (0: Run, 1: Stop) */
            uint32_t TB___EN		: 1;    /*!< TMRBx operation (0: Disable, 1: Enable)      */              
        } EN___register;
    };

    // TBxRUN (RUN register)
    union {
        volatile uint32_t RUN;               /*!< TB RUN Register                              */
        struct RUN__Register {
            uint32_t TB__RUN		: 1;    /*!< Count operation (0: Stop & clear, 1: Count)  */
            uint32_t RESERVED3	: 1;    /*!< Reserved Bit (Read as 0)                     */
            uint32_t TB_PRUN		: 1;    /*!< Prescaler operation (0: Stop & clear, 1: Count) */               
        } RUN__register;
    };

    // TBxCR (Control register)
    union {
        volatile uint32_t CR;                /*!< TB Control Register                          */
        struct TBCR_Register {
            uint32_t C__SSEL		: 1;    /*!< Counter Start select (0: Software start, 1: External trigger) */
            uint32_t TRG_SEL		: 1;    /*!< External Trigger select (0: Rising edge, 1: Falling edge) */
            uint32_t RESERVED5	: 1;    /*!< Write as 0                                   */
            uint32_t I__2_TB		: 1;    /*!< Operation at IDLE mode (0: Stop, 1: Operation) */
            uint32_t RESERVED6    : 1;    /*!< Read as 0                                    */
            uint32_t TB_SYNC		: 1;    /*!< Synchronous mode switch (0: individual, 1: synchronous) */
            uint32_t RESERVED7    : 1;    /*!< Write as 0                                   */
            uint32_t TB__WBF      : 1;    /*!< Double buffer (0: Disable, 1: Enable)        */
        } TBCR_register;
    };

    // TBxMOD (Mode register)
    union {
        volatile uint32_t MOD;               /*!< TB Mode Register                             */
        struct MOD__Register {
            uint32_t TB__CLK		: 3;    /*!< Selects the TMRBx source clock               */
            uint32_t TB__CLE		: 1;    /*!< Up-counter control (0: Disable clearing, 1: Enables clearing) */
            uint32_t TB__CPM		: 2;    /*!< Capture timing                               */
            uint32_t TB___CP		: 1;    /*!< Capture by softwareTB (0: Capture, 1: Don't care) */
            uint32_t TB_RSWR 		: 1;    /*!< Write to timer registers 0 and 1 (0: No, 1: Yes) */
        } MOD__register;
    };

    // TBxFFCR (Flip-flop control register)
    union {
        volatile uint32_t FFCR;              /*!< TB Flip-Flop Control Register                */
        struct FFCR_Register {
            uint32_t TB_FF0C       : 2;    /*!< TBxFFD control                               */
            uint32_t TB_E0T1       : 1;    /*!< TBxFFD reverse trigger (TBxRG0 match) (0: Disable, 1: Enable) */
            uint32_t TB_E1T1       : 1;    /*!< TBxFFD reverse trigger (TBxRG1 match) (0: Disable, 1: Enable) */
            uint32_t TB_C0T1       : 1;    /*!< TBxFFD reverse trigger (TBxCP1 capture) (0: Disable, 1: Enable) */
            uint32_t TB_C1T1       : 1;    /*!< TBxFFD reverse trigger (TBxCP0 capture) (0: Disable, 1: Enable) */
        } FFCR_register;
    };

    // TBxST (Status register)
    union {
        volatile  uint32_t ST;                /*!< TB Status Register                           */
        struct ST___Register {
            uint32_t INTTB0       : 1;    /*!< Match flag (TBxRG0) (0: No match, 1: Match)  */
            uint32_t INTTB1       : 1;    /*!< Match flag (TBxRG1) (0: No match, 1: Match)  */
            uint32_t INTTBOF      : 1;    /*!< Overflow flag (0: No overflow, 1: Overflow)  */
        } ST___register;
    };

    // TBxIM (Interrupt mask register)
    union {
        volatile uint32_t IM;                /*!< TB Interrupt Mask Register                   */
        struct IM___Register {
            uint32_t TB__IM0		: 1;    /*!< Match interrupt mask (TBxRG0) (0: Disable, 1: Enable) */
            uint32_t TB__IM1		: 1;    /*!< Match interrupt mask (TBxRG1) (0: Disable, 1: Enable) */
            uint32_t TB_IMOF		: 1;    /*!< Overflow interrupt mask (0: Disable, 1: Enable) */
        } IM___register;
    };

    // TBxUC (Up counter capture register)
    union {
        volatile  uint32_t UC;                /*!< TB Up-counter Capture Register               */
        struct UC___Register {
            uint32_t TBUC         : 16;   /*!< Captured up-counter value                    */
            uint32_t RESERVED18   : 16;   /*!< Reserved Bits (Read as 0)                    */
        } UC___register;
    };

    // TBxRG0 (Timer register 0)
    union {
        volatile uint32_t RG0;               /*!< TB RG0 Timer Register                        */
        struct RG0__Register {
            uint32_t TB__RG0        : 16;   /*!< Value compared to the up-counter             */
            uint32_t RESERVED20   : 16;   /*!< Reserved Bits (Read as 0)                    */
        } RG0__register;
    };

    // TBxRG1 (Timer register 1)
    union {
        volatile uint32_t RG1;               /*!< TB RG1 Timer Register                        */
        struct RG1__Register {
            uint32_t TB__RG1        : 16;   /*!< Value compared to the up-counter             */
            uint32_t RESERVED22   : 16;   /*!< Reserved Bits (Read as 0)                    */
        } RG1__register;
    };

    // TBxCP0 (Capture register 0)
    union {
        volatile  uint32_t CP0;               /*!< TB CP0 Capture Register                      */
        struct CP0__Register {
            uint32_t TB__CP0		: 16;   /*!< Captured up-counter value                    */
            uint32_t RESERVED24	: 16;   /*!< Reserved Bits (Read as 0)                    */
        } CP0__register;
    };

    // TBxCP1 (Capture register 1)
    union {
        volatile  uint32_t CP1;               /*!< TB CP1 Capture Register                      */
        struct CP1__Register {
            uint32_t TB__CP1		: 16;   /*!< Captured up-counter value                    */
            uint32_t RESERVED26	: 16;   /*!< Reserved Bits (Read as 0)                    */
        } CP1__register;
    };
} WROS_TIMER_TypeDef;

typedef struct
{
    // EN (Enable Register)
    union
    {
        uint32_t EN;
        struct EN_Register
        {
            uint32_t SIOE			: 1;  /* 串口通道操作：0=禁用，1=使能 */
            uint32_t BRCKSEL		: 1;  /* 预分频器输入时钟选择：0=φT0/2，1=φT0 */
            uint32_t Reserved_0	: 30; /* 位2-31，保留（只读为0） */
        } EN_register;
    };
	
    // BUF (Buffer Register)
    union
    {
        uint32_t BUF;
        struct BUF_Register
        {
            uint32_t DATA_Buffer	: 8;  /* 收发缓冲数据，写为发送缓冲，读为接收缓冲 */
            uint32_t Reserved_0	: 24; /* 保留位 */
        } BUF_register;
    };

    // CR (Control Register)
    union
    {
        uint32_t CR;
        struct CR_Register
        {
            uint32_t IOC			: 1;  /* 时钟输入/输出模式选择：0=输出，1=输入 */
            uint32_t SCLKS		: 1;  /* 时钟沿选择：0=RXD下降沿发、上升沿收；1=SCLK上升沿发、下降沿收 */
            uint32_t FERR			: 1;  /* 帧错误标志：0=正常，1=错误（读时清零） */
            uint32_t PERR			: 1;  /* 奇偶/欠载错误标志：0=正常，1=错误（读时清零） */
            uint32_t OERR			: 1;  /* 溢出错误标志：0=正常，1=错误（读时清零） */
            uint32_t PEN			: 1;  /* 奇偶校验使能：0=禁用，1=使能 */
            uint32_t EVEN			: 1;  /* 奇偶校验类型：0=奇，1=偶 */
            uint32_t RB8			: 1;  /* 接收数据位8（仅9位UART模式） */
            uint32_t TIDLE		: 2;  /* 最后一位输出后的TXD状态：00=低，01=高，10=保持最后一位 */
            uint32_t TXDEMP		: 1;  /* 欠载错误时的TXD状态：0=低，1=高 */
            uint32_t Reserved_0	: 1; /* 保留位 */
            uint32_t EHOLD		: 3;  /* 最后一位保持时间：000=2/fsys 至 110=128/fsys */
            uint32_t Reserved_1	: 1; /* 保留位 */
            uint32_t Reserved_2	: 16; /* 保留位 */
        } CR_register;
    };

    // MOD0 (Mode Control Register 0)
    union
    {
        uint32_t MOD0;
        struct MOD0_Register
        {
            uint32_t SC			: 2;  /* 串口传输时钟选择：00=TMRB输出，01=波特率发生器，10=系统时钟，11=外部时钟 */
            uint32_t SM			: 2;  /* 传输模式：00=I/O接口，01=7位UART，10=8位UART，11=9位UART */
            uint32_t WU			: 1;  /* 唤醒功能使能：0=禁用，1=使能（仅9位UART模式） */
            uint32_t RXE			: 1;  /* 接收使能：0=禁用，1=使能 */
            uint32_t CTSE			: 1;  /* CTS握手功能使能：0=禁用，1=使能 */
            uint32_t TBit8		: 1;  /* 传输数据位8（仅9位UART模式） */
            uint32_t Reserved_2	: 24; /* 保留位 */
        } MOD0_register;
    };

    // BRCR (Baud Rate Generator Control Register)
    union
    {
        uint32_t BRCR;
        struct BRCR_Register
        {
            uint32_t BRS			: 4;  /* 分频比N：0000=N=16 至 1111=N=15 */
            uint32_t BRCK			: 2;  /* 波特率发生器输入时钟选择：00=φTS0 等 */
            uint32_t BRADDE		: 1;  /* N + (16-K)/16 分频功能使能：0=禁用，1=使能 */
            uint32_t Reserved_5	: 1;  /* 保留位 */
            uint32_t Reserved_6	: 24; /* 保留位 */
        } BRCR_register;
    };

    // BRADD (Baud Rate Generator Control Register 2)
    union
    {
        uint32_t BRADD;
        struct BRADD_Register
        {
            uint32_t BRK			: 4;  /* K值：0001=K=1 至 1111=K=15（K=0禁止） */
            uint32_t Reserved_7	: 28; /* 保留位 */
        } BRADD_register;
    };

    // MOD1 (Mode Control Register 1)
    union
    {
        uint32_t MOD1;
        struct MOD1_Register
        {
            uint32_t EMPTY		: 1; /* 保留位 */
            uint32_t SINT			: 3;  /* 连续传输间隔时间：000=无 至 111=64×SCLK周期 */
            uint32_t TXE			: 1;  /* 传输使能：0=禁用，1=使能 */
            uint32_t FDPX			: 2;  /* 传输模式设置：00=禁止，01=半双工收，10=半双工发，11=全双工 */
            uint32_t I2SC			: 1;  /* IDLE模式操作：0=停止，1=运行 */
            uint32_t Reserved_3	: 24; /* 保留位 */
        } MOD1_register;
    };

    // MOD2 (Mode Control Register 2)
    union
    {
        uint32_t MOD2;
        struct MOD2_Register
        {
            uint32_t SWRST		: 2;  /* 软件复位：01→10 触发复位 */
            uint32_t WBUF			: 1;  /* 双缓冲使能：0=禁用，1=使能 */
            uint32_t DRCHG		: 1;  /* 传输方向：0=LSB优先，1=MSB优先 */
            uint32_t SBLEN		: 1;  /* 停止位长度：0=1位，1=2位 */
            uint32_t TXRUN		: 1;  /* 传输中标志：0=停止，1=运行 */
            uint32_t RBFLL		: 1;  /* 接收缓冲满标志：0=空，1=满 */
            uint32_t TBEMP		: 1;  /* 传输缓冲空标志：0=满，1=空 */
            uint32_t Reserved_4	: 24; /* 保留位 */
        } MOD2_register;
    };

    // RFC (Receive FIFO Configuration Register)
    union
    {
        uint32_t RFC;
        struct RFC_Register
        {
            uint32_t RIL			: 2;  /* 接收中断FIFO填充级别：00-11对应不同半双工/全双工配置 */
            uint32_t Reserved_11	: 4;  /* 位2-5，保留 */
            uint32_t RFIS			: 1;  /* 接收中断生成条件：0=等于RIL，1=大于等于RIL */
            uint32_t RFCS			: 1;  /* 接收FIFO清除：0=不关心，1=清除 */
            uint32_t Reserved_12	: 24; /* 位8-31，保留 */
        } RFC_register;
    };

    // TFC (Transmit FIFO Configuration Register)
    union
    {
        uint32_t TFC;
        struct TFC_Register
        {
            uint32_t TIL			: 2;  /* 发送中断FIFO填充级别：00-11对应不同半双工/全双工配置 */
            uint32_t Reserved_13	: 4;  /* 位2-5，保留 */
            uint32_t TFIS			: 1;  /* 发送中断生成条件：0=等于TIL，1=小于等于TIL */
            uint32_t TFCS			: 1;  /* 发送FIFO清除：0=不关心，1=清除 */
            uint32_t TBCLR		: 1;  /* 发送缓冲清除：0=不关心，1=清除 */
            uint32_t Reserved_14	: 23; /* 位9-31，保留 */
        } TFC_register;
    };

    // RST (Receive FIFO Status Register)
    union
    {
        uint32_t RST;
        struct RST_Register
        {
            uint32_t RLVL			: 3;  /* 接收FIFO填充状态：000=空 到 100=4字节 */
            uint32_t Reserved_15	: 4;  /* 位3-6，保留 */
            uint32_t ROR			: 1;  /* 接收FIFO溢出：0=未生成，1=生成 */
            uint32_t Reserved_16	: 24; /* 位8-31，保留 */
        } RST_register;
    };

    // TST (Transmit FIFO Status Register)
    union
    {
        uint32_t TST;
        struct TST_Register
        {
            uint32_t TLVL			: 3;  /* 发送FIFO级别状态：000=空 到 100=4字节 */
            uint32_t Reserved_17	: 4;  /* 位3-6，保留 */
            uint32_t TUR			: 1;  /* 发送FIFO欠载：0=未生成，1=生成 */
            uint32_t Reserved_18	: 24; /* 位8-31，保留 */
        } TST_register;
    };

    // FCNF (FIFO Configuration Register)
    union
    {
        uint32_t FCNF;
        struct FCNF_Register
        {
            uint32_t CNFG			: 1;  /* FIFO使能：0=禁用，1=使能 */
            uint32_t RXTXCNT		: 1;  /* 自动禁用RXE/TXE：0=无，1=自动禁用 */
            uint32_t RFIE			: 1;  /* 接收FIFO中断使能：0=禁用，1=使能 */
            uint32_t TFIE			: 1;  /* 发送FIFO中断使能：0=禁用，1=使能 */
            uint32_t RFST			: 1;  /* 接收FIFO使用字节数：0=最大，1=与接收FIFO填充级别相同 */
            uint32_t Reserved_9	: 3;  /* 位5-7，必须写000 */
            uint32_t Reserved_10	: 24; /* 位8-31，保留 */
        } FCNF_register;
    };

} WROS_UART__TypeDef;

/* =========================================================================================================================== */
/* ================                                           SPI0                                            ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                                           I2C0                                            ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                                            CAN                                            ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                                           MPWM0                                           ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  */


#define WROS_PERI_BASE			(0x40000000UL)
#define BITBAND_WROS_PERI_BASE	(0x42000000UL)

#define WROS_CORE_M_BASE		(0xE0000000UL)


#define WROS_CORTEX_M				(WROS_CORE_M_BASE	+ 0x000E000UL)

// 寄存器基地址
#define WROS_DMA____BASE			(WROS_PERI_BASE	+ 0x004C000UL)

#define WROS_CLOCK__BASE			(WROS_PERI_BASE	+ 0x00F3000UL)

#define WROS_PA_____BASE			(WROS_PERI_BASE	+ 0x00C0000UL)
#define WROS_PB_____BASE			(WROS_PERI_BASE	+ 0x00C0100UL)
#define WROS_PC_____BASE			(WROS_PERI_BASE	+ 0x00C0200UL)
#define WROS_PD_____BASE			(WROS_PERI_BASE	+ 0x00C0300UL)
#define WROS_PE_____BASE			(WROS_PERI_BASE	+ 0x00C0400UL)
#define WROS_PF_____BASE			(WROS_PERI_BASE	+ 0x00C0500UL)
#define WROS_PG_____BASE			(WROS_PERI_BASE	+ 0x00C0600UL)
#define WROS_PH_____BASE			(WROS_PERI_BASE	+ 0x00C0700UL)
#define WROS_PJ_____BASE			(WROS_PERI_BASE	+ 0x00C0800UL)
#define WROS_PK_____BASE			(WROS_PERI_BASE	+ 0x00C0900UL)
#define WROS_PL_____BASE			(WROS_PERI_BASE	+ 0x00C0A00UL)
#define WROS_PN_____BASE			(WROS_PERI_BASE	+ 0x00C0C00UL)
#define WROS_PP_____BASE			(WROS_PERI_BASE	+ 0x00C0D00UL)

#define WROS_TIMER0_BASE			(WROS_PERI_BASE  + 0x00C4000UL)
#define WROS_TIMER1_BASE			(WROS_PERI_BASE  + 0x00C4100UL)
#define WROS_TIMER2_BASE			(WROS_PERI_BASE  + 0x00C4200UL)
#define WROS_TIMER3_BASE			(WROS_PERI_BASE  + 0x00C4300UL)
#define WROS_TIMER4_BASE			(WROS_PERI_BASE  + 0x00C4400UL)
#define WROS_TIMER5_BASE			(WROS_PERI_BASE  + 0x00C4500UL)
#define WROS_TIMER6_BASE			(WROS_PERI_BASE  + 0x00C4600UL)
#define WROS_TIMER7_BASE			(WROS_PERI_BASE  + 0x00C4700UL)
#define WROS_TIMER8_BASE			(WROS_PERI_BASE  + 0x00C4800UL)
#define WROS_TIMER9_BASE			(WROS_PERI_BASE  + 0x00C4900UL)

#define WROS_UART0_BASE				(WROS_PERI_BASE  + 0x00E1000UL)
#define WROS_UART1_BASE				(WROS_PERI_BASE  + 0x00E1100UL)
#define WROS_UART2_BASE				(WROS_PERI_BASE  + 0x00E1200UL)
#define WROS_UART3_BASE				(WROS_PERI_BASE  + 0x00E1300UL)

#define WROS_WDT___BASE				(WROS_PERI_BASE  + 0x00F2000UL)

#define WROS_FLASH_BASE				(WROS_PERI_BASE  + 0x1DFF0000UL)

/** @} */ /* End of group Device_Peripheral_peripheralAddr */


/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_declaration
  * @{
  */



/** @} */ /* End of group Device_Peripheral_declaration */
extern		WROS_CORTEX_M_Typedef*	WROS_CORE_M;

extern		WROS_DMA___Typedef*		WROS____DMA;

extern		WROS_CLKGE_TypeDef*		WROS_CLK_GE;

extern		WROS_PORT__TypeDef*		WROS_____PA;
extern		WROS_PORT__TypeDef*		WROS_____PB;
extern		WROS_PORT__TypeDef*		WROS_____PC;
extern		WROS_PORT__TypeDef*		WROS_____PD;
extern		WROS_PORT__TypeDef*		WROS_____PE;
extern		WROS_PORT__TypeDef*		WROS_____PF;
extern 		WROS_PORT__TypeDef*		WROS_____PG;
extern 		WROS_PORT__TypeDef*		WROS_____PH;
extern 		WROS_PORT__TypeDef*		WROS_____PJ;
extern 		WROS_PORT__TypeDef*		WROS_____PK;
extern 		WROS_PORT__TypeDef*		WROS_____PL;
extern 		WROS_PORT__TypeDef*		WROS_____PN;
extern		WROS_PORT__TypeDef*		WROS_____PP;

extern		WROS_TIMER_TypeDef*		WROS_TIER_0;
extern		WROS_TIMER_TypeDef*		WROS_TIER_1;
extern		WROS_TIMER_TypeDef*		WROS_TIER_2;
extern		WROS_TIMER_TypeDef*		WROS_TIER_3;
extern		WROS_TIMER_TypeDef*		WROS_TIER_4;
extern		WROS_TIMER_TypeDef*		WROS_TIER_5;

extern		WROS_UART__TypeDef*		WROS_UART_0;
extern		WROS_UART__TypeDef*		WROS_UART_1;
extern		WROS_UART__TypeDef*		WROS_UART_2;
extern		WROS_UART__TypeDef*		WROS_UART_3;

extern		WROS_WDT___TypeDef*		WROS_WDT__0;

enum{ Pin__In,	Pin_Out };



#define WROS_BITBAND_PERI(addr, bitnum)	(BITBAND_WROS_PERI_BASE + (((uint32_t)(addr) & 0x00FFFFFF) << 5) + ((uint32_t)(bitnum) << 2))

#define GPIO_DATA(PinID, Num)			(*((volatile uint32_t *)WROS_BITBAND_PERI(&((WROS_____P ## PinID)->DATA),Num)))

void WROS_Init(void);

/************************************************************************
************************************************************************
                                ARM_CORTEX
************************************************************************
************************************************************************/
#define __ASM	__asm

void __enable_interrupt(void);
void __disable_interrupt(void);


void __DSB(unsigned int unused);
void __ISB(unsigned int unused);


/************************************************************************
************************************************************************
                                Driver_Struct
************************************************************************
************************************************************************/
//        TIMER
void WROS_Base_Timer(void);
void WROS_Tick_Init(void);
void WROS_NVIC_Init(void);
void WROS_NVIC_Setting(UINT8,UINT8,UINT8);

typedef enum{ SPI,				IIC																													}T_Device_Type;
typedef enum{ Initial_Dev_0,	Device_Index_1,		Device_Index_2,		Device_Index_3,	Device_Index_4,	Device_Index_5,	Device_Index_6				}T_Device_Step;
typedef enum{ Serial_Oneshot,	Serial_Keep,		Serial_Busy,		Serial_Sleep																}T_Comm_State;
typedef enum{ Serial_Start,		Serial_Write_mode,	Serial_Read_mode,	Serial_TX_Adr,	Serial_RX_Adr,	Serial_TX_DATA,	Serial_RX_DATA,	Serial_Stop	}T_Comm_Step;
typedef enum{ NONE,				Echo_ACK,			Echo_NCK,			Write_ACK,		Read_ACK														}T_Echo_Step;

typedef void(*Device_NextStep)();
typedef T_Echo_Step(*Device_Event)(volatile UINT32*, volatile UINT32*, volatile UINT32*);
typedef struct
{
	T_Device_Type Device_Type;
	T_Device_Step Device_Step;
	T_Comm_State Comm_Request;
	T_Comm_Step Comm_Step;

	struct
	{
		UINT8 Adr_Size;
		UINT8 Adr_Index;
		UINT8 Adr[4];

		UINT16 Data_Size;
		UINT16 Data_Index;
		UINT8 Data[320];
	}T_Serial_Packet;

	volatile UINT32* Eable_Pin;
	volatile UINT32* Clock_Pin;
	volatile UINT32* ChipS_Pin;
	volatile UINT32* DataW_Pin;
	volatile UINT32* Write_Pin_state;        //
	volatile UINT32* DataR_Pin;
	volatile UINT32* Read_Pin_state;

	void (*Device_NextStep)(void);

	T_Echo_Step EchoReq;
	T_Echo_Step (*Device_Event)(volatile UINT32*, volatile UINT32*, volatile UINT32*, volatile UINT32*, volatile UINT32*);
}T_Serial_Interface_drive;

extern T_Serial_Interface_drive        LCD_Device;
extern T_Serial_Interface_drive        Flash_Device;
extern T_Serial_Interface_drive        Mpu6050_Device;

#ifndef SET
#define SET		1
#endif

#ifndef CLEAR
#define CLEAR	0
#endif

#ifndef TRUE
#define TRUE	1
#endif

#ifndef FALSE
#define FALSE	0
#endif


#endif /* WROS_H */

