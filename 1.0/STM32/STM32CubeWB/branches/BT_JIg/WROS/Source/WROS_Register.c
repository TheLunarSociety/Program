



#include "../../WROS/Include/WROS_Register.h"





WROS_CORTEX_M_Typedef*	WROS_CORE_M 	=	((WROS_CORTEX_M_Typedef*)WROS_CORTEX_M);



WROS_FLASH_TypeDef*		WROS_ST_FLASH	= 	((WROS_FLASH_TypeDef*)WROS_FLASH_REG_BASE);

WROS_PWR_TypeDef*		WROS_ST_PWR		= 	((WROS_PWR_TypeDef*)WROS_PWR_REG_BASE);

WROS_GPIO_TypeDef*		WROS_ST_GPIO_A	= 	((WROS_GPIO_TypeDef*)WROS_GPIO_A_REG_BASE);
WROS_GPIO_TypeDef*		WROS_ST_GPIO_B	= 	((WROS_GPIO_TypeDef*)WROS_GPIO_B_REG_BASE);
WROS_GPIO_TypeDef*		WROS_ST_GPIO_C	= 	((WROS_GPIO_TypeDef*)WROS_GPIO_C_REG_BASE);
WROS_GPIO_TypeDef*		WROS_ST_GPIO_D	= 	((WROS_GPIO_TypeDef*)WROS_GPIO_D_REG_BASE);
WROS_GPIO_TypeDef*		WROS_ST_GPIO_E	= 	((WROS_GPIO_TypeDef*)WROS_GPIO_E_REG_BASE);

WROS_RCC_TypeDef*		WROS_ST_RCC		= 	((WROS_RCC_TypeDef*)WROS_RCC_REG_BASE);

WROS_IPCC_TypeDef*		WROS_ST_IPCC	= 	((WROS_IPCC_TypeDef*)WROS_IPCC_REG_BASE);



/************************************************************************
************************************************************************
                                Device_Func
************************************************************************
************************************************************************/
//        timer
static UINT32 Base_Timer_100us = 0;
static UINT32 Base_Timer_1s = 0;
/*
void timer_0_1ms(void);		//        100us
void timer_1ms(void);		//        1000us
void timer_10ms(void);		//        10000us
*/
/*

static inline void __enable_irq(void)
{
  __asm ("cpsie i");
}

static inline void __disable_irq(void)
{
  __asm ("cpsid i");
}
*/

void __enable_interrupt(void)
{
	__enable_irq();
}

void __disable_interrupt(void)
{
	__disable_irq();
}

/*
// 手动声明屏障函数（ARM 架构专用）
static inline void __dsb(unsigned int unused) { 
    (void)unused; 
    __asm("dsb"); 
}

static inline void __isb(unsigned int unused) { 
    (void)unused; 
    __asm("isb"); 
}

void __DSB(unsigned int unused)
{
	__dsb(unused);
}

void __ISB(unsigned int unused)
{
	__isb(unused);
}

*/





static void timer_0_1ms()
{

}

static void timer_1ms()
{

}
static void timer_10ms()
{
	if(Base_Timer_100us % 100 == 0)
	{	;
	}
}

static void (* const FuncBaseTimer[]) (void) =
{
	timer_0_1ms,
	timer_1ms,
	timer_10ms,
};

// TIMER
void WROS_Base_Timer()
{
	Base_Timer_100us++;
	if(Base_Timer_100us % 10000 == 0)
	{
		Base_Timer_100us = 0;
		Base_Timer_1s++;					// Max130years
	}

	UINT8 TimerIndex = 0;
	while(TimerIndex < SIZE_OF_ARRAY(FuncBaseTimer)){FuncBaseTimer[TimerIndex++]();}
}

// TICK
void WROS_Tick_Init(void)
{
	UINT32 MCU_SystemCoreClock = 1200000000;
	
	struct STCSR_Register	STCSR_Registers;
	struct STRVR_Register	STRVR_Registers;
	struct STCVR_Register	STCVR_Registers;
	struct STCR_Register	STCR_Registers;
	
	STCSR_Registers.ENABLE		= 1;		//	0: Disable								1: Enable
	STCSR_Registers.TICKINT		= 0;		//	0: Do not pend SysTick					1: Pend SysTick
	STCSR_Registers.CLKSOURCE	= 1;		//	0: External reference clock (fosc/32)	1: CPU clock (fsys)
	STCSR_Registers.COUNTFLAG	= 0;		//	0: Timer not counted to 0				1: Timer counted to 0

	STRVR_Registers.RELOAD		= MCU_SystemCoreClock / 1000;						// 0.5 ms

	STCVR_Registers.CURRENT		= 0;

	STCR_Registers.TENMS		= 0;
	STCR_Registers.SKEW			= 0;
	STCR_Registers.NOREF		= 0;
	
	WROS_CORE_M->SYSTICK_register.STCSR_register	= STCSR_Registers;
	WROS_CORE_M->SYSTICK_register.STRVR_register	= STRVR_Registers;
	WROS_CORE_M->SYSTICK_register.STCVR_register	= STCVR_Registers;
	WROS_CORE_M->SYSTICK_register.STCR_register	= STCR_Registers;
}

void WROS_TimerTask(T_DispInfo* P_DispInfo)
{
	while(1)
	{

	}
}

const INT8 Interrupt[][2] = 
{
	{SysTick_IRQn,		0},
	{IPCC_C1_RX_IRQn,	0},
	{IPCC_C1_TX_IRQn,	0},
	{HSEM_IRQn,			0},
	{RTC_WKUP_IRQn,		0},
};


// NVIC
void WROS_NVIC_Init(void)
{
	for(int NVIC_Interrupt = 0; NVIC_Interrupt <= SIZE_OF_ARRAY(Interrupt) - 1; NVIC_Interrupt++)
	{
		if(Interrupt[NVIC_Interrupt][0] < 0)
		{	WROS_CORE_M->NVIC_register.SHP[(Interrupt[NVIC_Interrupt][0] + 12)]	= ((Interrupt[NVIC_Interrupt][1] << NVIC_FREE_BITS) & 0xFF);
		}
		else
		{	WROS_CORE_M->NVIC_register.IPR[Interrupt[NVIC_Interrupt][0]]		= ((Interrupt[NVIC_Interrupt][1] << NVIC_FREE_BITS) & 0xFF);
			WROS_CORE_M->NVIC_register.ISER[Interrupt[NVIC_Interrupt][0] >> 5]	|= (1 << ((Interrupt[NVIC_Interrupt][0]) & 0x1F));
		}
	}
}

void WROS_NVIC_Setting(UINT8 InterReqIdx, UINT8 SetAble, UINT8 PriorityLv)
{
	WROS_CORE_M->NVIC_register.IPR[InterReqIdx]			= ((PriorityLv << NVIC_FREE_BITS) & 0xFF);
	
	if(SetAble == SET)
	{
		WROS_CORE_M->NVIC_register.ISER[InterReqIdx >> 5]	|= (1 << ((InterReqIdx) & 0x1F));
	}
	else
	{
		WROS_CORE_M->NVIC_register.ICER[InterReqIdx >> 5]	|= (1 << ((InterReqIdx) & 0x1F));
	}
}



































