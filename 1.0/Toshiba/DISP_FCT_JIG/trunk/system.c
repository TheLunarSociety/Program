/**
 *******************************************************************************
 * @file    system_TMPM470.c
 * @brief   CMSIS Cortex-M4 Device Peripheral Access Layer Source File for the
 *          TOSHIBA 'TMPM470' Device Series 
 * @version V2.0.2.1
 * @date    2014/12/26
 * 
 * DO NOT USE THIS SOFTWARE WITHOUT THE SOFTWARE LISENCE AGREEMENT.
 * 
 * (C)Copyright TOSHIBA CORPORATION 2014 All rights reserved
 *******************************************************************************
 */
 
#include "../../4.Driver/Include/WROS_Register.h"

#include "../../5.Hardware/Include/bootloader.h"



const INT32 Interrupt[8][2] = 
{
	// External Interrupt
	{ExternalInterrupts_IRQn_6,	4}, 			// Uart0 RX
	{ExternalInterrupts_IRQn_7,	4}, 			// Uart0 TX
	{ExternalInterrupts_IRQn_27, 5}, 			// Timer51
	{ExternalInterrupts_IRQn_40, 6}, 			// Uart2 RX
	{ExternalInterrupts_IRQn_41, 6}, 			// Uart2 TX
		
	// Cortex_M4 Interrupt
	{Cortex_M4_SVCall_IRQn, 2}, 			// SVCall
	{Cortex_M4_SysTick_IRQn,7}, 			// SysTick
	{Cortex_M4_PendSV_IRQn, 7}, 			// PendSV
};

	
#define CG_8M_MUL_4_FPLL        (0x0000591EUL)	// PLL 10 * 8 
#define CG_10M_MUL_4_FPLL       (0x00005926UL)	// PLL 10 * 10 
#define CG_12M_MUL_4_FPLL       (0x000059AEUL)	// PLL 10 * 12 

#define OSC_10M                (10000000UL)
#define HZ_1M                  (1000000UL)

#define WU_TIME_PLL_100        (100UL)           // warm-up time for PLL is 100us 
#define WU_TIME_PLL_200        (200UL)           // warm-up time for PLL is 200us 
#define WU_TIME_EXT            (5000UL)          // warm-up time for EXT is 5ms   

#define OSCCR_WUODR_PLL_100    ((WU_TIME_PLL_100	* OSC_10M / HZ_1M / 16UL))
#define OSCCR_WUODR_PLL_200    ((WU_TIME_PLL_200	* OSC_10M / HZ_1M / 16UL))
#define OSCCR_WUODR_EXT        ((WU_TIME_EXT		* OSC_10M / HZ_1M / 16UL))



#define CG_SYSCR_GEAR_MASK      (0xFFFFFFF8UL)
#define CG_SYSCR_GEAR_0         (0x00000000UL)
#define CG_SYSCR_GEAR_2         (0x00000004UL)
#define CG_SYSCR_GEAR_4         (0x00000005UL)
#define CG_SYSCR_GEAR_8         (0x00000006UL)
#define CG_SYSCR_GEAR_16        (0x00000007UL)
#define CG_SYSCR_GEAR_SET        CG_SYSCR_GEAR_0


#define STBYCR_Val              (0x00000103UL)
#define CG_SYSCR_GEAR_0         (0x00000000UL)
#define SYSCR_Val               (0x00010100UL)

struct OSCCR_Register	OSCCR_registers;
struct PLLSEL_Register	PLLSEL_registers;
struct SYSCR_Register	SYSCR_Registers;

void SystemInit(void)
{
	WROS_WDT__0->WDT_MOD = CLEAR;
	if (!(WROS_WDT__0->WDT_MOD_register.WDTE)) {     /* If watchdog is to be disabled */
	WROS_WDT__0->WDT_CR = 0x000000B1UL;
	} 
	else {
	}
	// TODO : OFD off code 甸绢啊具 窃!
	/* Switch over from the internal oscillator to the external oscillator. */

	OSCCR_registers = WROS_CLK_GE->OSCCR_register;
	OSCCR_registers.WUODR |= (WU_TIME_EXT * OSC_10M / HZ_1M / 16UL);		// warm-up =  time(us) * EXTALH(MHz) / 16 
	WROS_CLK_GE->OSCCR_register = OSCCR_registers;


	OSCCR_registers = WROS_CLK_GE->OSCCR_register;
	OSCCR_registers.XEN1	= SET;
	OSCCR_registers.WUPSEL2	= SET;
	OSCCR_registers.WUEON	= SET;
	WROS_CLK_GE->OSCCR_register = OSCCR_registers;



	while (WROS_CLK_GE->OSCCR_register.WUEF) {
	}                          

	OSCCR_registers = WROS_CLK_GE->OSCCR_register;
	OSCCR_registers.OSCSEL	= SET;
	WROS_CLK_GE->OSCCR_register = OSCCR_registers;

	while (WROS_CLK_GE->OSCCR_register.OSCSEL != 1U) {
	}                          
	OSCCR_registers = WROS_CLK_GE->OSCCR_register;
	OSCCR_registers.XEN2	= CLEAR;
	WROS_CLK_GE->OSCCR_register = OSCCR_registers;


	/* Set PLL and select PLL as fc source */

	OSCCR_registers = WROS_CLK_GE->OSCCR_register;
	OSCCR_registers.WUODR |= OSCCR_WUODR_PLL_100;		
	WROS_CLK_GE->OSCCR_register = OSCCR_registers;

	PLLSEL_registers = WROS_CLK_GE->PLLSEL_register;
	PLLSEL_registers.PLLSET = CG_12M_MUL_4_FPLL;		
	WROS_CLK_GE->PLLSEL_register = PLLSEL_registers;

	OSCCR_registers = WROS_CLK_GE->OSCCR_register;
	OSCCR_registers.WUEON	= SET;
	WROS_CLK_GE->OSCCR_register = OSCCR_registers;

	while (WROS_CLK_GE->OSCCR_register.WUEF) {
	} 

	OSCCR_registers = WROS_CLK_GE->OSCCR_register;
	OSCCR_registers.WUODR |= OSCCR_WUODR_PLL_200;		
	WROS_CLK_GE->OSCCR_register = OSCCR_registers;

	OSCCR_registers = WROS_CLK_GE->OSCCR_register;
	OSCCR_registers.PLLON	= SET;   
	WROS_CLK_GE->OSCCR_register = OSCCR_registers;

	OSCCR_registers = WROS_CLK_GE->OSCCR_register;
	OSCCR_registers.WUEON	= SET;
	WROS_CLK_GE->OSCCR_register = OSCCR_registers;

	while (WROS_CLK_GE->OSCCR_register.WUEF) {
	}                          

	PLLSEL_registers = WROS_CLK_GE->PLLSEL_register;
	PLLSEL_registers.PLLSEL	= SET;
	WROS_CLK_GE->PLLSEL_register = PLLSEL_registers;


	WROS_CLK_GE->SYSCR = SYSCR_Val;
	WROS_CLK_GE->SYSCR &= CG_SYSCR_GEAR_MASK;
	WROS_CLK_GE->SYSCR |= CG_SYSCR_GEAR_SET;

	WROS_CLK_GE->STBYCR = STBYCR_Val;
}

