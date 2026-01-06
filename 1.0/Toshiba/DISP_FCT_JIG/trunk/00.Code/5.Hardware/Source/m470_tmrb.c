/*******************************************************************************
*
* @file:    m470_tmrb.c
* @purpose: 16-bit Timer/Event Counters Source File
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


#define DEFINE_APP_TMRB
#include "../Include/m470_tmrb.h"
#undef DEFINE_APP_TMRB

struct EN___Register	EN___Registers;
struct RUN__Register	RUN__Registers;
struct TBCR_Register	TBCR_Registers;
struct MOD__Register	MOD__Registers;
struct FFCR_Register	FFCR_Registers;
struct ST___Register	ST___Registers;
struct IM___Register	IM___Registers;
struct UC___Register	UC___Registers;
struct RG0__Register	RG0__Registers;
struct RG1__Register	RG1__Registers;
struct CP0__Register	CP0__Registers;
struct CP1__Register	CP1__Registers;


static void Init_TMRB_0()
{
}

static void Init_TMRB_1()
{
}

static void Init_TMRB_2()
{
}

static void Init_TMRB_3()
{
}

static void Init_TMRB_4()
{
}

static void Init_TMRB_5()
{
	// EN
	EN___Registers.TB_HALT = CLEAR;
	EN___Registers.TB___EN = SET;										/* TMB51 interrupt enable */

	
	// RUN
	RUN__Registers.TB__RUN = SET;
	RUN__Registers.TB_PRUN = SET;

	// CP0
	CP0__Registers.TB__CP0 = CLEAR;
	
	// CP1
	CP1__Registers.TB__CP1 = CLEAR;
	
	// RG0
	RG0__Registers.TB__RG0 = CLEAR;
	
	// RG1
	RG1__Registers.TB__RG1 = 3750;
	
	// IM
	IM___Registers.TB__IM0 = SET;
	IM___Registers.TB__IM1 = CLEAR;
	IM___Registers.TB_IMOF = SET;
	
	// FFCR
	FFCR_Registers.TB_FF0C = 3;
	FFCR_Registers.TB_E0T1 = CLEAR;
	FFCR_Registers.TB_E1T1 = CLEAR;
	FFCR_Registers.TB_C0T1 = CLEAR;
	FFCR_Registers.TB_C1T1 = CLEAR;
	
	// MOD
	MOD__Registers.TB__CLK = 2;
	MOD__Registers.TB__CLE = SET;
	MOD__Registers.TB__CPM = CLEAR;
	MOD__Registers.TB___CP = SET;
	MOD__Registers.TB_RSWR = CLEAR;

	// CR
	TBCR_Registers.C__SSEL = CLEAR;
	TBCR_Registers.TRG_SEL = CLEAR;
	TBCR_Registers.I__2_TB = CLEAR;
	TBCR_Registers.TB_SYNC = CLEAR;
	TBCR_Registers.TB__WBF = CLEAR;

	WROS_TIER_5->EN___register = EN___Registers;
	WROS_TIER_5->RUN__register = RUN__Registers;
	WROS_TIER_5->TBCR_register = TBCR_Registers;
	WROS_TIER_5->MOD__register = MOD__Registers;
	WROS_TIER_5->FFCR_register = FFCR_Registers;
	WROS_TIER_5->ST___register = ST___Registers;
	WROS_TIER_5->IM___register = IM___Registers;
	WROS_TIER_5->UC___register = UC___Registers;
	WROS_TIER_5->RG0__register = RG0__Registers;
	WROS_TIER_5->RG1__register = RG1__Registers;
	WROS_TIER_5->CP0__register = CP0__Registers;
	WROS_TIER_5->CP1__register = CP1__Registers;

	
	// dummy read
	{
		volatile uint8_t st = WROS_TIER_5->ST;
	}
	
}

static void Init_TMRB_6()
{
}

static void Init_TMRB_7()
{
}

static void Init_TMRB_8()
{
}

static void Init_TMRB_9()
{	;
}

void WROS_TMRB_Init()
{
	Init_TMRB_0(); 												/* TimerB0 initialize */
	Init_TMRB_1(); 												/* TimerB1 initialize */
	Init_TMRB_2();												/* TimerB2 initialize */
	Init_TMRB_3();												/* TimerB3 initialize */
	Init_TMRB_4(); 												/* TimerB4 initialize */
	Init_TMRB_5(); 												/* TimerB5 initialize */
	Init_TMRB_6(); 												/* TimerB6 initialize */
	Init_TMRB_7(); 												/* TimerB7 initialize */
	Init_TMRB_8(); 												/* TimerB8 initialize */
	Init_TMRB_9(); 												/* TimerB9 initialize */
}

/*********************************** END OF FILE ******************************/
