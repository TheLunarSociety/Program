/*******************************************************************************
*
* @file:    m470_wdt.c
* @purpose: Watchdog Timer Source File
*           for the TOSHIBA 'TMPM470' Device Series 
* @version: V1.0.0.0
* @date:    2017/03/07
*
*-------------------------------------------------------------------------------
* --Notice--
*  The information contained herein has been carefully checked
* and is believed to be reliable. However, no responsibility can be
* assumed for inaccuracies that may not have been detected. The
* information contained herein is subject to change without notice.
*  The information contained herein is presented only as a guide
* for the application of our products. No responsibility is assumed
* by TOSHIBA for any infringements of patents or other rights of
* the third parties which may result from its use. No license is
* granted by implication or otherwise under any patent or patent
* rights of TOSHIBA or others.
*-------------------------------------------------------------------------------
*  Copyright(C) TOSHIBA CORPORATION 2017 All rights reserved
********************************************************************************/


#include "../../4.Driver/Include/WROS_Register.h"


#define DEFINE_APP_WDT
#include "../../5.Hardware/Include/m470_wdt.h"
#undef DEFINE_APP_WDT

extern UINT8 gucWdt_Nmi_Count;

/*******************************************************************************
* Description	 : WDT Initialize
* Input 		 : none
* Output		 : none
*******************************************************************************/


struct WDT_MOD_Register	WDT_MOD_registers;
struct WDT_CR_Register	WDT_CR_registers;


void WROS_WDT_Init(void)
{
	WDT_CR_registers.TMCR = WDT_CLEARCODE;

	WDT_MOD_registers.RESCR = CLEAR;
	WDT_MOD_registers.I2WDT = CLEAR;
	WDT_MOD_registers.WDTP = 0x05;
	WDT_MOD_registers.WDTE = SET;


	WROS_WDT__0->WDT_CR_register	= WDT_CR_registers;
	WROS_WDT__0->WDT_MOD_register	= WDT_MOD_registers;
	__DSB(15);
}

/*******************************************************************************
* Function Name  : API_WDT_RESET_Init
* Description	 : WDT RESET Initialize
* Input 		 : none
* Output		 : none
*******************************************************************************/
void API_WDT_RESET_Init(void)
{
	WDT_MOD_registers.RESCR = SET;
	WDT_MOD_registers.I2WDT = CLEAR;
	WDT_MOD_registers.WDTP = 0x05;
	WDT_MOD_registers.WDTE = SET;
	
	WROS_WDT__0->WDT_MOD_register	= WDT_MOD_registers;
	__DSB(15);
}

/*******************************************************************************
* Function Name  : API_WDT_Set_Wdt_Nmi_Clr
* Description	 : Set WDT Clear
* Input 		 : none
* Output		 : none
*******************************************************************************/
void API_WDT_Set_Wdt_Nmi_Clr(void)
{
	WDT_CR_registers.TMCR = WDT_CLEARCODE;
	WROS_WDT__0->WDT_CR_register	= WDT_CR_registers;
	__DSB(15);
	gucWdt_Nmi_Count = CLEAR;	
}

/*******************************************************************************
* Function Name  : API_WDT_Set_WdtClr
* Description	 : Set WDT Clear
* Input 		 : none
* Output		 : none
*******************************************************************************/
void API_WDT_Set_WdtClr(void)
{
	WDT_CR_registers.TMCR = WDT_CLEARCODE;
	WROS_WDT__0->WDT_CR_register	= WDT_CR_registers;
	__DSB(15);
}

/*******************************************************************************
* Function Name  : API_WDT_Disable
* Description	 : WDT Disable
* Input 		 : none
* Output		 : none
*******************************************************************************/
void API_WDT_Disable(void)
{
	WDT_MOD_registers.RESCR = CLEAR;
	WDT_MOD_registers.I2WDT = CLEAR;
	WDT_MOD_registers.WDTP = 0x05;
	WDT_MOD_registers.WDTE = CLEAR;
	
	WROS_WDT__0->WDT_MOD_register	= WDT_MOD_registers;

	WDT_CR_registers.TMCR = WDT_DISABLECODE;
	WROS_WDT__0->WDT_CR_register	= WDT_CR_registers;
	__DSB(15);
}

/*************************** END OF FILE **************************************/
