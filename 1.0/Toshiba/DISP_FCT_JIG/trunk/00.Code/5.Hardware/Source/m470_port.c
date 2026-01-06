/*******************************************************************************
*
* @file:    m470_port.c
* @purpose: Input/Output Ports Source File
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
#include "../../6.VariableSource/Include/Vable_ModelInformation.h"

#define DEFINE_APP_PORT
#include "../../5.Hardware/Include/m470_port.h"
#undef DEFINE_APP_PORT


struct DATA_Register DATA_Registers;
struct CR___Register CR___Registers;
struct FR1__Register FR1__Registers;
struct FR2__Register FR2__Registers;
struct FR3__Register FR3__Registers;
struct OD___Register OD___Registers;
struct PUP__Register PUP__Registers;
struct PDN__Register PDN__Registers;
struct IE___Register IE___Registers;




static void Init_PORT_A(void)
{
	
	//	PA0
	DATA_Registers.DATA_0 = CLEAR;
	CR___Registers.CR___0 = SET;
	FR1__Registers.FR1__0 = CLEAR;
	FR2__Registers.FR2__0 = CLEAR;
	FR3__Registers.FR3__0 = CLEAR;
	OD___Registers.OD___0 = CLEAR;
	PUP__Registers.PUP__0 = CLEAR;
	PDN__Registers.PDN__0 = CLEAR;
	IE___Registers.IE___0 = CLEAR;
	
	//	PA1
	DATA_Registers.DATA_1 = CLEAR;
	CR___Registers.CR___1 = SET;
	FR1__Registers.FR1__1 = CLEAR;
	FR2__Registers.FR2__1 = CLEAR;
	FR3__Registers.FR3__1 = CLEAR;
	OD___Registers.OD___1 = CLEAR;
	PUP__Registers.PUP__1 = CLEAR;
	PDN__Registers.PDN__1 = CLEAR;
	IE___Registers.IE___1 = CLEAR;

	//	PA2
	DATA_Registers.DATA_2 = CLEAR;
	CR___Registers.CR___2 = SET;
	FR1__Registers.FR1__2 = CLEAR;
	FR2__Registers.FR2__2 = CLEAR;
	FR3__Registers.FR3__2 = CLEAR;
	OD___Registers.OD___2 = CLEAR;
	PUP__Registers.PUP__2 = CLEAR;
	PDN__Registers.PDN__2 = CLEAR;
	IE___Registers.IE___2 = CLEAR;

	//	PA3
	DATA_Registers.DATA_3 = CLEAR;
	CR___Registers.CR___3 = SET;
	FR1__Registers.FR1__3 = CLEAR;
	FR2__Registers.FR2__3 = CLEAR;
	FR3__Registers.FR3__3 = CLEAR;
	OD___Registers.OD___3 = CLEAR;
	PUP__Registers.PUP__3 = CLEAR;
	PDN__Registers.PDN__3 = CLEAR;
	IE___Registers.IE___3 = CLEAR;

	//	PA4
	DATA_Registers.DATA_4 = CLEAR;
	CR___Registers.CR___4 = SET;
	FR1__Registers.FR1__4 = CLEAR;
	FR2__Registers.FR2__4 = CLEAR;
	FR3__Registers.FR3__4 = CLEAR;
	OD___Registers.OD___4 = CLEAR;
	PUP__Registers.PUP__4 = CLEAR;
	PDN__Registers.PDN__4 = CLEAR;
	IE___Registers.IE___4 = CLEAR;

	//	PA5
	DATA_Registers.DATA_5 = CLEAR;
	CR___Registers.CR___5 = SET;
	FR1__Registers.FR1__5 = CLEAR;
	FR2__Registers.FR2__5 = CLEAR;
	FR3__Registers.FR3__5 = CLEAR;
	OD___Registers.OD___5 = CLEAR;
	PUP__Registers.PUP__5 = CLEAR;
	PDN__Registers.PDN__5 = CLEAR;
	IE___Registers.IE___5 = CLEAR;
	
	//	PA6
	DATA_Registers.DATA_6 = CLEAR;
	CR___Registers.CR___6 = SET;
	FR1__Registers.FR1__6 = CLEAR;
	FR2__Registers.FR2__6 = CLEAR;
	FR3__Registers.FR3__6 = CLEAR;
	OD___Registers.OD___6 = CLEAR;
	PUP__Registers.PUP__6 = CLEAR;
	PDN__Registers.PDN__6 = CLEAR;
	IE___Registers.IE___6 = CLEAR;

	//	PA7
	DATA_Registers.DATA_7 = CLEAR;
	CR___Registers.CR___7 = CLEAR;
	FR1__Registers.FR1__7 = CLEAR;
	FR2__Registers.FR2__7 = CLEAR;
	FR3__Registers.FR3__7 = CLEAR;
	OD___Registers.OD___7 = CLEAR;
	PUP__Registers.PUP__7 = CLEAR;
	PDN__Registers.PDN__7 = CLEAR;
	IE___Registers.IE___7 = SET;

	WROS_____PA->DATA_register = DATA_Registers;
	WROS_____PA->CR___register = CR___Registers;
	WROS_____PA->FR1__register = FR1__Registers;
	WROS_____PA->FR2__register = FR2__Registers;
	WROS_____PA->FR3__register = FR3__Registers;
	WROS_____PA->OD___register = OD___Registers;
	WROS_____PA->PUP__register = PUP__Registers;
	WROS_____PA->PDN__register = PDN__Registers;
	WROS_____PA->IE___register = IE___Registers;
	
}

static void Init_PORT_B()
{
	//	PB0
	DATA_Registers.DATA_0 = CLEAR;
	CR___Registers.CR___0 = CLEAR;
	FR1__Registers.FR1__0 = CLEAR;
	FR2__Registers.FR2__0 = CLEAR;
	FR3__Registers.FR3__0 = CLEAR;
	OD___Registers.OD___0 = CLEAR;
	PUP__Registers.PUP__0 = CLEAR;
	PDN__Registers.PDN__0 = CLEAR;
	IE___Registers.IE___0 = CLEAR;
	
	//	PB1
	DATA_Registers.DATA_1 = CLEAR;
	CR___Registers.CR___1 = CLEAR;
	FR1__Registers.FR1__1 = CLEAR;
	FR2__Registers.FR2__1 = CLEAR;
	FR3__Registers.FR3__1 = CLEAR;
	OD___Registers.OD___1 = CLEAR;
	PUP__Registers.PUP__1 = CLEAR;
	PDN__Registers.PDN__1 = CLEAR;
	IE___Registers.IE___1 = CLEAR;

	//	PB2
	DATA_Registers.DATA_2 = CLEAR;
	CR___Registers.CR___2 = CLEAR;
	FR1__Registers.FR1__2 = CLEAR;
	FR2__Registers.FR2__2 = CLEAR;
	FR3__Registers.FR3__2 = CLEAR;
	OD___Registers.OD___2 = CLEAR;
	PUP__Registers.PUP__2 = CLEAR;
	PDN__Registers.PDN__2 = CLEAR;
	IE___Registers.IE___2 = CLEAR;

	//	PB3
	DATA_Registers.DATA_3 = CLEAR;
	CR___Registers.CR___3 = SET;
	FR1__Registers.FR1__3 = SET;
	FR2__Registers.FR2__3 = CLEAR;
	FR3__Registers.FR3__3 = CLEAR;
	OD___Registers.OD___3 = CLEAR;
	PUP__Registers.PUP__3 = SET;
	PDN__Registers.PDN__3 = CLEAR;
	IE___Registers.IE___3 = SET;

	//	PB4
	DATA_Registers.DATA_4 = CLEAR;
	CR___Registers.CR___4 = CLEAR;
	FR1__Registers.FR1__4 = SET;
	FR2__Registers.FR2__4 = CLEAR;
	FR3__Registers.FR3__4 = CLEAR;
	OD___Registers.OD___4 = CLEAR;
	PUP__Registers.PUP__4 = CLEAR;
	PDN__Registers.PDN__4 = SET;
	IE___Registers.IE___4 = SET;

	//	PB5
	DATA_Registers.DATA_5 = CLEAR;
	CR___Registers.CR___5 = CLEAR;
	FR1__Registers.FR1__5 = CLEAR;
	FR2__Registers.FR2__5 = CLEAR;
	FR3__Registers.FR3__5 = CLEAR;
	OD___Registers.OD___5 = CLEAR;
	PUP__Registers.PUP__5 = CLEAR;
	PDN__Registers.PDN__5 = CLEAR;
	IE___Registers.IE___5 = CLEAR;
	
	//	PB6
	DATA_Registers.DATA_6 = CLEAR;
	CR___Registers.CR___6 = CLEAR;
	FR1__Registers.FR1__6 = CLEAR;
	FR2__Registers.FR2__6 = CLEAR;
	FR3__Registers.FR3__6 = CLEAR;
	OD___Registers.OD___6 = CLEAR;
	PUP__Registers.PUP__6 = CLEAR;
	PDN__Registers.PDN__6 = CLEAR;
	IE___Registers.IE___6 = CLEAR;

	//	PB7
	DATA_Registers.DATA_7 = CLEAR;
	CR___Registers.CR___7 = CLEAR;
	FR1__Registers.FR1__7 = CLEAR;
	FR2__Registers.FR2__7 = CLEAR;
	FR3__Registers.FR3__7 = CLEAR;
	OD___Registers.OD___7 = CLEAR;
	PUP__Registers.PUP__7 = CLEAR;
	PDN__Registers.PDN__7 = CLEAR;
	IE___Registers.IE___7 = CLEAR;


	WROS_____PB->DATA_register = DATA_Registers;
	WROS_____PB->CR___register = CR___Registers;
	WROS_____PB->FR1__register = FR1__Registers;
	WROS_____PB->FR2__register = FR2__Registers;
	WROS_____PB->FR3__register = FR3__Registers;
	WROS_____PB->OD___register = OD___Registers;
	WROS_____PB->PUP__register = PUP__Registers;
	WROS_____PB->PDN__register = PDN__Registers;
	WROS_____PB->IE___register = IE___Registers;
}

static void Init_PORT_C()
{
	//	PC0
	DATA_Registers.DATA_0 = CLEAR;
	CR___Registers.CR___0 = SET;
	FR1__Registers.FR1__0 = CLEAR;
	FR2__Registers.FR2__0 = CLEAR;
	FR3__Registers.FR3__0 = CLEAR;
	OD___Registers.OD___0 = CLEAR;
	PUP__Registers.PUP__0 = CLEAR;
	PDN__Registers.PDN__0 = CLEAR;
	IE___Registers.IE___0 = CLEAR;
	
	//	PC1
	DATA_Registers.DATA_1 = CLEAR;
	CR___Registers.CR___1 = SET;
	FR1__Registers.FR1__1 = CLEAR;
	FR2__Registers.FR2__1 = CLEAR;
	FR3__Registers.FR3__1 = CLEAR;
	OD___Registers.OD___1 = CLEAR;
	PUP__Registers.PUP__1 = CLEAR;
	PDN__Registers.PDN__1 = CLEAR;
	IE___Registers.IE___1 = CLEAR;

	//	PC2
	DATA_Registers.DATA_2 = CLEAR;
	CR___Registers.CR___2 = SET;
	FR1__Registers.FR1__2 = CLEAR;
	FR2__Registers.FR2__2 = CLEAR;
	FR3__Registers.FR3__2 = CLEAR;
	OD___Registers.OD___2 = CLEAR;
	PUP__Registers.PUP__2 = CLEAR;
	PDN__Registers.PDN__2 = CLEAR;
	IE___Registers.IE___2 = CLEAR;

	//	PC3
	DATA_Registers.DATA_3 = CLEAR;
	CR___Registers.CR___3 = SET;
	FR1__Registers.FR1__3 = CLEAR;
	FR2__Registers.FR2__3 = CLEAR;
	FR3__Registers.FR3__3 = CLEAR;
	OD___Registers.OD___3 = CLEAR;
	PUP__Registers.PUP__3 = CLEAR;
	PDN__Registers.PDN__3 = CLEAR;
	IE___Registers.IE___3 = CLEAR;

	//	PC4
	DATA_Registers.DATA_4 = CLEAR;
	CR___Registers.CR___4 = CLEAR;
	FR1__Registers.FR1__4 = CLEAR;
	FR2__Registers.FR2__4 = CLEAR;
	FR3__Registers.FR3__4 = CLEAR;
	OD___Registers.OD___4 = CLEAR;
	PUP__Registers.PUP__4 = CLEAR;
	PDN__Registers.PDN__4 = CLEAR;
	IE___Registers.IE___4 = CLEAR;

	//	PC5
	DATA_Registers.DATA_5 = CLEAR;
	CR___Registers.CR___5 = CLEAR;
	FR1__Registers.FR1__5 = CLEAR;
	FR2__Registers.FR2__5 = CLEAR;
	FR3__Registers.FR3__5 = CLEAR;
	OD___Registers.OD___5 = CLEAR;
	PUP__Registers.PUP__5 = CLEAR;
	PDN__Registers.PDN__5 = CLEAR;
	IE___Registers.IE___5 = CLEAR;
	
	//	PC6
	DATA_Registers.DATA_6 = CLEAR;
	CR___Registers.CR___6 = CLEAR;
	FR1__Registers.FR1__6 = CLEAR;
	FR2__Registers.FR2__6 = CLEAR;
	FR3__Registers.FR3__6 = CLEAR;
	OD___Registers.OD___6 = CLEAR;
	PUP__Registers.PUP__6 = CLEAR;
	PDN__Registers.PDN__6 = CLEAR;
	IE___Registers.IE___6 = CLEAR;

	//	PC7
	DATA_Registers.DATA_7 = CLEAR;
	CR___Registers.CR___7 = CLEAR;
	FR1__Registers.FR1__7 = CLEAR;
	FR2__Registers.FR2__7 = CLEAR;
	FR3__Registers.FR3__7 = CLEAR;
	OD___Registers.OD___7 = CLEAR;
	PUP__Registers.PUP__7 = CLEAR;
	PDN__Registers.PDN__7 = CLEAR;
	IE___Registers.IE___7 = CLEAR;


	WROS_____PC->DATA_register = DATA_Registers;
	WROS_____PC->CR___register = CR___Registers;
	WROS_____PC->FR1__register = FR1__Registers;
	WROS_____PC->FR2__register = FR2__Registers;
	WROS_____PC->FR3__register = FR3__Registers;
	WROS_____PC->OD___register = OD___Registers;
	WROS_____PC->PUP__register = PUP__Registers;
	WROS_____PC->PDN__register = PDN__Registers;
	WROS_____PC->IE___register = IE___Registers;
}

static void Init_PORT_D()
{
	//	PD0
	DATA_Registers.DATA_0 = CLEAR;
	CR___Registers.CR___0 = CLEAR;
	FR1__Registers.FR1__0 = CLEAR;
	FR2__Registers.FR2__0 = CLEAR;
	FR3__Registers.FR3__0 = CLEAR;
	OD___Registers.OD___0 = CLEAR;
	PUP__Registers.PUP__0 = CLEAR;
	PDN__Registers.PDN__0 = CLEAR;
	IE___Registers.IE___0 = CLEAR;
	
	//	PD1
	DATA_Registers.DATA_1 = CLEAR;
	CR___Registers.CR___1 = CLEAR;
	FR1__Registers.FR1__1 = CLEAR;
	FR2__Registers.FR2__1 = CLEAR;
	FR3__Registers.FR3__1 = CLEAR;
	OD___Registers.OD___1 = CLEAR;
	PUP__Registers.PUP__1 = CLEAR;
	PDN__Registers.PDN__1 = CLEAR;
	IE___Registers.IE___1 = CLEAR;

	//	PD2
	DATA_Registers.DATA_2 = CLEAR;
	CR___Registers.CR___2 = CLEAR;
	FR1__Registers.FR1__2 = CLEAR;
	FR2__Registers.FR2__2 = CLEAR;
	FR3__Registers.FR3__2 = CLEAR;
	OD___Registers.OD___2 = CLEAR;
	PUP__Registers.PUP__2 = CLEAR;
	PDN__Registers.PDN__2 = CLEAR;
	IE___Registers.IE___2 = CLEAR;

	//	PD3
	DATA_Registers.DATA_3 = CLEAR;
	CR___Registers.CR___3 = CLEAR;
	FR1__Registers.FR1__3 = CLEAR;
	FR2__Registers.FR2__3 = CLEAR;
	FR3__Registers.FR3__3 = CLEAR;
	OD___Registers.OD___3 = CLEAR;
	PUP__Registers.PUP__3 = CLEAR;
	PDN__Registers.PDN__3 = CLEAR;
	IE___Registers.IE___3 = CLEAR;

	//	PD4
	DATA_Registers.DATA_4 = CLEAR;
	CR___Registers.CR___4 = CLEAR;
	FR1__Registers.FR1__4 = CLEAR;
	FR2__Registers.FR2__4 = CLEAR;
	FR3__Registers.FR3__4 = CLEAR;
	OD___Registers.OD___4 = CLEAR;
	PUP__Registers.PUP__4 = CLEAR;
	PDN__Registers.PDN__4 = CLEAR;
	IE___Registers.IE___4 = CLEAR;

	//	PD5
	DATA_Registers.DATA_5 = CLEAR;
	CR___Registers.CR___5 = SET;
	FR1__Registers.FR1__5 = SET;
	FR2__Registers.FR2__5 = CLEAR;
	FR3__Registers.FR3__5 = CLEAR;
	OD___Registers.OD___5 = CLEAR;
	PUP__Registers.PUP__5 = CLEAR;
	PDN__Registers.PDN__5 = CLEAR;
	IE___Registers.IE___5 = CLEAR;
	
	//	PD6
	DATA_Registers.DATA_6 = CLEAR;
	CR___Registers.CR___6 = CLEAR;
	FR1__Registers.FR1__6 = SET;
	FR2__Registers.FR2__6 = CLEAR;
	FR3__Registers.FR3__6 = CLEAR;
	OD___Registers.OD___6 = CLEAR;
	PUP__Registers.PUP__6 = CLEAR;
	PDN__Registers.PDN__6 = CLEAR;
	IE___Registers.IE___6 = SET;

	//	PD7
	DATA_Registers.DATA_7 = CLEAR;
	CR___Registers.CR___7 = CLEAR;
	FR1__Registers.FR1__7 = CLEAR;
	FR2__Registers.FR2__7 = CLEAR;
	FR3__Registers.FR3__7 = CLEAR;
	OD___Registers.OD___7 = CLEAR;
	PUP__Registers.PUP__7 = CLEAR;
	PDN__Registers.PDN__7 = CLEAR;
	IE___Registers.IE___7 = CLEAR;
	
	
	WROS_____PD->DATA_register = DATA_Registers;
	WROS_____PD->CR___register = CR___Registers;
	WROS_____PD->FR1__register = FR1__Registers;
	WROS_____PD->FR2__register = FR2__Registers;
	WROS_____PD->FR3__register = FR3__Registers;
	WROS_____PD->OD___register = OD___Registers;
	WROS_____PD->PUP__register = PUP__Registers;
	WROS_____PD->PDN__register = PDN__Registers;
	WROS_____PD->IE___register = IE___Registers;
}

static void Init_PORT_E()
{
	//	PE0
	DATA_Registers.DATA_0 = CLEAR;
	CR___Registers.CR___0 = SET;
	FR1__Registers.FR1__0 = SET;
	FR2__Registers.FR2__0 = CLEAR;
	FR3__Registers.FR3__0 = CLEAR;
	OD___Registers.OD___0 = CLEAR;
	PUP__Registers.PUP__0 = SET;
	PDN__Registers.PDN__0 = CLEAR;
	IE___Registers.IE___0 = CLEAR;
	
	//	PE1
	DATA_Registers.DATA_1 = CLEAR;
	CR___Registers.CR___1 = CLEAR;
	FR1__Registers.FR1__1 = SET;
	FR2__Registers.FR2__1 = CLEAR;
	FR3__Registers.FR3__1 = CLEAR;
	OD___Registers.OD___1 = CLEAR;
	PUP__Registers.PUP__1 = SET;
	PDN__Registers.PDN__1 = CLEAR;
	IE___Registers.IE___1 = SET;

	//	PE2
	DATA_Registers.DATA_2 = CLEAR;
	CR___Registers.CR___2 = SET;
	FR1__Registers.FR1__2 = CLEAR;
	FR2__Registers.FR2__2 = CLEAR;
	FR3__Registers.FR3__2 = CLEAR;
	OD___Registers.OD___2 = CLEAR;
	PUP__Registers.PUP__2 = CLEAR;
	PDN__Registers.PDN__2 = CLEAR;
	IE___Registers.IE___2 = CLEAR;

	//	PE3
	DATA_Registers.DATA_3 = CLEAR;
	CR___Registers.CR___3 = CLEAR;
	FR1__Registers.FR1__3 = CLEAR;
	FR2__Registers.FR2__3 = CLEAR;
	FR3__Registers.FR3__3 = CLEAR;
	OD___Registers.OD___3 = CLEAR;
	PUP__Registers.PUP__3 = CLEAR;
	PDN__Registers.PDN__3 = CLEAR;
	IE___Registers.IE___3 = SET;

	//	PE4
	DATA_Registers.DATA_4 = CLEAR;
	CR___Registers.CR___4 = CLEAR;
	FR1__Registers.FR1__4 = CLEAR;
	FR2__Registers.FR2__4 = CLEAR;
	FR3__Registers.FR3__4 = CLEAR;
	OD___Registers.OD___4 = CLEAR;
	PUP__Registers.PUP__4 = CLEAR;
	PDN__Registers.PDN__4 = CLEAR;
	IE___Registers.IE___4 = SET;

	//	PE5
	DATA_Registers.DATA_5 = CLEAR;
	CR___Registers.CR___5 = CLEAR;
	FR1__Registers.FR1__5 = CLEAR;
	FR2__Registers.FR2__5 = CLEAR;
	FR3__Registers.FR3__5 = CLEAR;
	OD___Registers.OD___5 = CLEAR;
	PUP__Registers.PUP__5 = CLEAR;
	PDN__Registers.PDN__5 = CLEAR;
	IE___Registers.IE___5 = SET;
	
	//	PE6
	DATA_Registers.DATA_6 = CLEAR;
	CR___Registers.CR___6 = CLEAR;
	FR1__Registers.FR1__6 = CLEAR;
	FR2__Registers.FR2__6 = CLEAR;
	FR3__Registers.FR3__6 = CLEAR;
	OD___Registers.OD___6 = CLEAR;
	PUP__Registers.PUP__6 = CLEAR;
	PDN__Registers.PDN__6 = CLEAR;
	IE___Registers.IE___6 = SET;

	//	PE7
	DATA_Registers.DATA_7 = CLEAR;
	CR___Registers.CR___7 = CLEAR;
	FR1__Registers.FR1__7 = CLEAR;
	FR2__Registers.FR2__7 = CLEAR;
	FR3__Registers.FR3__7 = CLEAR;
	OD___Registers.OD___7 = CLEAR;
	PUP__Registers.PUP__7 = CLEAR;
	PDN__Registers.PDN__7 = CLEAR;
	IE___Registers.IE___7 = SET;
	
	
	WROS_____PE->DATA_register = DATA_Registers;
	WROS_____PE->CR___register = CR___Registers;
	WROS_____PE->FR1__register = FR1__Registers;
	WROS_____PE->FR2__register = FR2__Registers;
	WROS_____PE->FR3__register = FR3__Registers;
	WROS_____PE->OD___register = OD___Registers;
	WROS_____PE->PUP__register = PUP__Registers;
	WROS_____PE->PDN__register = PDN__Registers;
	WROS_____PE->IE___register = IE___Registers;
}

static void Init_PORT_F()
{
	//	PF0
	DATA_Registers.DATA_0 = CLEAR;
	CR___Registers.CR___0 = CLEAR;
	FR1__Registers.FR1__0 = CLEAR;
	FR2__Registers.FR2__0 = CLEAR;
	FR3__Registers.FR3__0 = CLEAR;
	OD___Registers.OD___0 = CLEAR;
	PUP__Registers.PUP__0 = CLEAR;
	PDN__Registers.PDN__0 = CLEAR;
	IE___Registers.IE___0 = CLEAR;
	
	//	PF1
	DATA_Registers.DATA_1 = CLEAR;
	CR___Registers.CR___1 = CLEAR;
	FR1__Registers.FR1__1 = CLEAR;
	FR2__Registers.FR2__1 = CLEAR;
	FR3__Registers.FR3__1 = CLEAR;
	OD___Registers.OD___1 = CLEAR;
	PUP__Registers.PUP__1 = CLEAR;
	PDN__Registers.PDN__1 = CLEAR;
	IE___Registers.IE___1 = CLEAR;

	//	PF2
	DATA_Registers.DATA_2 = CLEAR;
	CR___Registers.CR___2 = CLEAR;
	FR1__Registers.FR1__2 = CLEAR;
	FR2__Registers.FR2__2 = CLEAR;
	FR3__Registers.FR3__2 = CLEAR;
	OD___Registers.OD___2 = CLEAR;
	PUP__Registers.PUP__2 = CLEAR;
	PDN__Registers.PDN__2 = CLEAR;
	IE___Registers.IE___2 = CLEAR;

	//	PF3
	DATA_Registers.DATA_3 = CLEAR;
	CR___Registers.CR___3 = CLEAR;
	FR1__Registers.FR1__3 = CLEAR;
	FR2__Registers.FR2__3 = CLEAR;
	FR3__Registers.FR3__3 = CLEAR;
	OD___Registers.OD___3 = CLEAR;
	PUP__Registers.PUP__3 = CLEAR;
	PDN__Registers.PDN__3 = CLEAR;
	IE___Registers.IE___3 = CLEAR;

	//	PF4
	DATA_Registers.DATA_4 = CLEAR;
	CR___Registers.CR___4 = CLEAR;
	FR1__Registers.FR1__4 = CLEAR;
	FR2__Registers.FR2__4 = CLEAR;
	FR3__Registers.FR3__4 = CLEAR;
	OD___Registers.OD___4 = CLEAR;
	PUP__Registers.PUP__4 = CLEAR;
	PDN__Registers.PDN__4 = CLEAR;
	IE___Registers.IE___4 = CLEAR;

	//	PF5
	DATA_Registers.DATA_5 = CLEAR;
	CR___Registers.CR___5 = CLEAR;
	FR1__Registers.FR1__5 = CLEAR;
	FR2__Registers.FR2__5 = CLEAR;
	FR3__Registers.FR3__5 = CLEAR;
	OD___Registers.OD___5 = CLEAR;
	PUP__Registers.PUP__5 = CLEAR;
	PDN__Registers.PDN__5 = CLEAR;
	IE___Registers.IE___5 = CLEAR;
	
	//	PF6
	DATA_Registers.DATA_6 = CLEAR;
	CR___Registers.CR___6 = CLEAR;
	FR1__Registers.FR1__6 = CLEAR;
	FR2__Registers.FR2__6 = CLEAR;
	FR3__Registers.FR3__6 = CLEAR;
	OD___Registers.OD___6 = CLEAR;
	PUP__Registers.PUP__6 = CLEAR;
	PDN__Registers.PDN__6 = CLEAR;
	IE___Registers.IE___6 = CLEAR;

	//	PF7
	DATA_Registers.DATA_7 = CLEAR;
	CR___Registers.CR___7 = CLEAR;
	FR1__Registers.FR1__7 = CLEAR;
	FR2__Registers.FR2__7 = CLEAR;
	FR3__Registers.FR3__7 = CLEAR;
	OD___Registers.OD___7 = CLEAR;
	PUP__Registers.PUP__7 = CLEAR;
	PDN__Registers.PDN__7 = CLEAR;
	IE___Registers.IE___7 = CLEAR;


	WROS_____PF->DATA_register = DATA_Registers;
	WROS_____PF->CR___register = CR___Registers;
	WROS_____PF->FR1__register = FR1__Registers;
	WROS_____PF->FR2__register = FR2__Registers;
	WROS_____PF->FR3__register = FR3__Registers;
	WROS_____PF->OD___register = OD___Registers;
	WROS_____PF->PUP__register = PUP__Registers;
	WROS_____PF->PDN__register = PDN__Registers;
	WROS_____PF->IE___register = IE___Registers;
}

static void Init_PORT_G()
{
	//	PG0
	DATA_Registers.DATA_0 = CLEAR;
	CR___Registers.CR___0 = CLEAR;
	FR1__Registers.FR1__0 = CLEAR;
	FR2__Registers.FR2__0 = CLEAR;
	FR3__Registers.FR3__0 = CLEAR;
	OD___Registers.OD___0 = CLEAR;
	PUP__Registers.PUP__0 = CLEAR;
	PDN__Registers.PDN__0 = CLEAR;
	IE___Registers.IE___0 = CLEAR;
	
	//	PG1
	DATA_Registers.DATA_1 = CLEAR;
	CR___Registers.CR___1 = CLEAR;
	FR1__Registers.FR1__1 = CLEAR;
	FR2__Registers.FR2__1 = CLEAR;
	FR3__Registers.FR3__1 = CLEAR;
	OD___Registers.OD___1 = CLEAR;
	PUP__Registers.PUP__1 = CLEAR;
	PDN__Registers.PDN__1 = CLEAR;
	IE___Registers.IE___1 = CLEAR;

	//	PG2
	DATA_Registers.DATA_2 = CLEAR;
	CR___Registers.CR___2 = CLEAR;
	FR1__Registers.FR1__2 = CLEAR;
	FR2__Registers.FR2__2 = CLEAR;
	FR3__Registers.FR3__2 = CLEAR;
	OD___Registers.OD___2 = CLEAR;
	PUP__Registers.PUP__2 = CLEAR;
	PDN__Registers.PDN__2 = CLEAR;
	IE___Registers.IE___2 = CLEAR;

	//	PG3
	DATA_Registers.DATA_3 = CLEAR;
	CR___Registers.CR___3 = CLEAR;
	FR1__Registers.FR1__3 = CLEAR;
	FR2__Registers.FR2__3 = CLEAR;
	FR3__Registers.FR3__3 = CLEAR;
	OD___Registers.OD___3 = CLEAR;
	PUP__Registers.PUP__3 = CLEAR;
	PDN__Registers.PDN__3 = CLEAR;
	IE___Registers.IE___3 = CLEAR;

	//	PG4
	DATA_Registers.DATA_4 = CLEAR;
	CR___Registers.CR___4 = CLEAR;
	FR1__Registers.FR1__4 = CLEAR;
	FR2__Registers.FR2__4 = CLEAR;
	FR3__Registers.FR3__4 = CLEAR;
	OD___Registers.OD___4 = CLEAR;
	PUP__Registers.PUP__4 = CLEAR;
	PDN__Registers.PDN__4 = CLEAR;
	IE___Registers.IE___4 = CLEAR;

	//	PG5
	DATA_Registers.DATA_5 = CLEAR;
	CR___Registers.CR___5 = CLEAR;
	FR1__Registers.FR1__5 = CLEAR;
	FR2__Registers.FR2__5 = CLEAR;
	FR3__Registers.FR3__5 = CLEAR;
	OD___Registers.OD___5 = CLEAR;
	PUP__Registers.PUP__5 = CLEAR;
	PDN__Registers.PDN__5 = CLEAR;
	IE___Registers.IE___5 = CLEAR;
	
	//	PG6
	DATA_Registers.DATA_6 = CLEAR;
	CR___Registers.CR___6 = CLEAR;
	FR1__Registers.FR1__6 = CLEAR;
	FR2__Registers.FR2__6 = CLEAR;
	FR3__Registers.FR3__6 = CLEAR;
	OD___Registers.OD___6 = CLEAR;
	PUP__Registers.PUP__6 = CLEAR;
	PDN__Registers.PDN__6 = CLEAR;
	IE___Registers.IE___6 = CLEAR;

	//	PG7
	DATA_Registers.DATA_7 = CLEAR;
	CR___Registers.CR___7 = CLEAR;
	FR1__Registers.FR1__7 = CLEAR;
	FR2__Registers.FR2__7 = CLEAR;
	FR3__Registers.FR3__7 = CLEAR;
	OD___Registers.OD___7 = CLEAR;
	PUP__Registers.PUP__7 = CLEAR;
	PDN__Registers.PDN__7 = CLEAR;
	IE___Registers.IE___7 = CLEAR;


	WROS_____PG->DATA_register = DATA_Registers;
	WROS_____PG->CR___register = CR___Registers;
	WROS_____PG->FR1__register = FR1__Registers;
	WROS_____PG->FR2__register = FR2__Registers;
	WROS_____PG->FR3__register = FR3__Registers;
	WROS_____PG->OD___register = OD___Registers;
	WROS_____PG->PUP__register = PUP__Registers;
	WROS_____PG->PDN__register = PDN__Registers;
	WROS_____PG->IE___register = IE___Registers;
}

static void Init_PORT_H()
{
	//	PH0
	DATA_Registers.DATA_0 = CLEAR;
	CR___Registers.CR___0 = CLEAR;
	FR1__Registers.FR1__0 = CLEAR;
	FR2__Registers.FR2__0 = CLEAR;
	FR3__Registers.FR3__0 = CLEAR;
	OD___Registers.OD___0 = CLEAR;
	PUP__Registers.PUP__0 = CLEAR;
	PDN__Registers.PDN__0 = CLEAR;
	IE___Registers.IE___0 = CLEAR;
	
	//	PH1
	DATA_Registers.DATA_1 = CLEAR;
	CR___Registers.CR___1 = CLEAR;
	FR1__Registers.FR1__1 = CLEAR;
	FR2__Registers.FR2__1 = CLEAR;
	FR3__Registers.FR3__1 = CLEAR;
	OD___Registers.OD___1 = CLEAR;
	PUP__Registers.PUP__1 = CLEAR;
	PDN__Registers.PDN__1 = CLEAR;
	IE___Registers.IE___1 = CLEAR;

	//	PH2
	DATA_Registers.DATA_2 = CLEAR;
	CR___Registers.CR___2 = CLEAR;
	FR1__Registers.FR1__2 = CLEAR;
	FR2__Registers.FR2__2 = CLEAR;
	FR3__Registers.FR3__2 = CLEAR;
	OD___Registers.OD___2 = CLEAR;
	PUP__Registers.PUP__2 = CLEAR;
	PDN__Registers.PDN__2 = CLEAR;
	IE___Registers.IE___2 = CLEAR;

	//	PH3
	DATA_Registers.DATA_3 = CLEAR;
	CR___Registers.CR___3 = CLEAR;
	FR1__Registers.FR1__3 = CLEAR;
	FR2__Registers.FR2__3 = CLEAR;
	FR3__Registers.FR3__3 = CLEAR;
	OD___Registers.OD___3 = CLEAR;
	PUP__Registers.PUP__3 = CLEAR;
	PDN__Registers.PDN__3 = CLEAR;
	IE___Registers.IE___3 = CLEAR;

	//	PH4
	DATA_Registers.DATA_4 = CLEAR;
	CR___Registers.CR___4 = CLEAR;
	FR1__Registers.FR1__4 = CLEAR;
	FR2__Registers.FR2__4 = CLEAR;
	FR3__Registers.FR3__4 = CLEAR;
	OD___Registers.OD___4 = CLEAR;
	PUP__Registers.PUP__4 = CLEAR;
	PDN__Registers.PDN__4 = CLEAR;
	IE___Registers.IE___4 = CLEAR;

	//	PH5
	DATA_Registers.DATA_5 = CLEAR;
	CR___Registers.CR___5 = CLEAR;
	FR1__Registers.FR1__5 = CLEAR;
	FR2__Registers.FR2__5 = CLEAR;
	FR3__Registers.FR3__5 = CLEAR;
	OD___Registers.OD___5 = CLEAR;
	PUP__Registers.PUP__5 = CLEAR;
	PDN__Registers.PDN__5 = CLEAR;
	IE___Registers.IE___5 = CLEAR;
	
	//	PH6
	DATA_Registers.DATA_6 = CLEAR;
	CR___Registers.CR___6 = CLEAR;
	FR1__Registers.FR1__6 = CLEAR;
	FR2__Registers.FR2__6 = CLEAR;
	FR3__Registers.FR3__6 = CLEAR;
	OD___Registers.OD___6 = CLEAR;
	PUP__Registers.PUP__6 = CLEAR;
	PDN__Registers.PDN__6 = CLEAR;
	IE___Registers.IE___6 = CLEAR;

	//	PH7
	DATA_Registers.DATA_7 = CLEAR;
	CR___Registers.CR___7 = CLEAR;
	FR1__Registers.FR1__7 = CLEAR;
	FR2__Registers.FR2__7 = CLEAR;
	FR3__Registers.FR3__7 = CLEAR;
	OD___Registers.OD___7 = CLEAR;
	PUP__Registers.PUP__7 = CLEAR;
	PDN__Registers.PDN__7 = CLEAR;
	IE___Registers.IE___7 = CLEAR;
	
	
	WROS_____PH->DATA_register = DATA_Registers;
	WROS_____PH->CR___register = CR___Registers;
	WROS_____PH->FR1__register = FR1__Registers;
	WROS_____PH->FR2__register = FR2__Registers;
	WROS_____PH->FR3__register = FR3__Registers;
	WROS_____PH->OD___register = OD___Registers;
	WROS_____PH->PUP__register = PUP__Registers;
	WROS_____PH->PDN__register = PDN__Registers;
	WROS_____PH->IE___register = IE___Registers;
}

static void Init_PORT_J()
{
	//	PJ0
	DATA_Registers.DATA_0 = CLEAR;
	CR___Registers.CR___0 = CLEAR;
	FR1__Registers.FR1__0 = CLEAR;
	FR2__Registers.FR2__0 = CLEAR;
	FR3__Registers.FR3__0 = CLEAR;
	OD___Registers.OD___0 = CLEAR;
	PUP__Registers.PUP__0 = CLEAR;
	PDN__Registers.PDN__0 = CLEAR;
	IE___Registers.IE___0 = CLEAR;
	
	//	PJ1
	DATA_Registers.DATA_1 = CLEAR;
	CR___Registers.CR___1 = CLEAR;
	FR1__Registers.FR1__1 = CLEAR;
	FR2__Registers.FR2__1 = CLEAR;
	FR3__Registers.FR3__1 = CLEAR;
	OD___Registers.OD___1 = CLEAR;
	PUP__Registers.PUP__1 = CLEAR;
	PDN__Registers.PDN__1 = CLEAR;
	IE___Registers.IE___1 = CLEAR;

	//	PJ2
	DATA_Registers.DATA_2 = CLEAR;
	CR___Registers.CR___2 = CLEAR;
	FR1__Registers.FR1__2 = CLEAR;
	FR2__Registers.FR2__2 = CLEAR;
	FR3__Registers.FR3__2 = CLEAR;
	OD___Registers.OD___2 = CLEAR;
	PUP__Registers.PUP__2 = CLEAR;
	PDN__Registers.PDN__2 = CLEAR;
	IE___Registers.IE___2 = CLEAR;

	//	PJ3
	DATA_Registers.DATA_3 = CLEAR;
	CR___Registers.CR___3 = CLEAR;
	FR1__Registers.FR1__3 = CLEAR;
	FR2__Registers.FR2__3 = CLEAR;
	FR3__Registers.FR3__3 = CLEAR;
	OD___Registers.OD___3 = CLEAR;
	PUP__Registers.PUP__3 = CLEAR;
	PDN__Registers.PDN__3 = CLEAR;
	IE___Registers.IE___3 = CLEAR;

	//	PJ4
	DATA_Registers.DATA_4 = CLEAR;
	CR___Registers.CR___4 = CLEAR;
	FR1__Registers.FR1__4 = CLEAR;
	FR2__Registers.FR2__4 = CLEAR;
	FR3__Registers.FR3__4 = CLEAR;
	OD___Registers.OD___4 = CLEAR;
	PUP__Registers.PUP__4 = CLEAR;
	PDN__Registers.PDN__4 = CLEAR;
	IE___Registers.IE___4 = CLEAR;

	//	PJ5
	DATA_Registers.DATA_5 = CLEAR;
	CR___Registers.CR___5 = CLEAR;
	FR1__Registers.FR1__5 = CLEAR;
	FR2__Registers.FR2__5 = CLEAR;
	FR3__Registers.FR3__5 = CLEAR;
	OD___Registers.OD___5 = CLEAR;
	PUP__Registers.PUP__5 = CLEAR;
	PDN__Registers.PDN__5 = CLEAR;
	IE___Registers.IE___5 = CLEAR;
	
	//	PJ6
	DATA_Registers.DATA_6 = CLEAR;
	CR___Registers.CR___6 = CLEAR;
	FR1__Registers.FR1__6 = CLEAR;
	FR2__Registers.FR2__6 = CLEAR;
	FR3__Registers.FR3__6 = CLEAR;
	OD___Registers.OD___6 = CLEAR;
	PUP__Registers.PUP__6 = CLEAR;
	PDN__Registers.PDN__6 = CLEAR;
	IE___Registers.IE___6 = CLEAR;

	//	PJ7
	DATA_Registers.DATA_7 = CLEAR;
	CR___Registers.CR___7 = CLEAR;
	FR1__Registers.FR1__7 = CLEAR;
	FR2__Registers.FR2__7 = CLEAR;
	FR3__Registers.FR3__7 = CLEAR;
	OD___Registers.OD___7 = CLEAR;
	PUP__Registers.PUP__7 = CLEAR;
	PDN__Registers.PDN__7 = CLEAR;
	IE___Registers.IE___7 = CLEAR;
	
	
	WROS_____PJ->DATA_register = DATA_Registers;
	WROS_____PJ->CR___register = CR___Registers;
	WROS_____PJ->FR1__register = FR1__Registers;
	WROS_____PJ->FR2__register = FR2__Registers;
	WROS_____PJ->FR3__register = FR3__Registers;
	WROS_____PJ->OD___register = OD___Registers;
	WROS_____PJ->PUP__register = PUP__Registers;
	WROS_____PJ->PDN__register = PDN__Registers;
	WROS_____PJ->IE___register = IE___Registers;
}

static void Init_PORT_K()
{
	//	PK0
	DATA_Registers.DATA_0 = CLEAR;
	CR___Registers.CR___0 = CLEAR;
	FR1__Registers.FR1__0 = CLEAR;
	FR2__Registers.FR2__0 = CLEAR;
	FR3__Registers.FR3__0 = CLEAR;
	OD___Registers.OD___0 = CLEAR;
	PUP__Registers.PUP__0 = CLEAR;
	PDN__Registers.PDN__0 = CLEAR;
	IE___Registers.IE___0 = CLEAR;
	
	//	PK1
	DATA_Registers.DATA_1 = CLEAR;
	CR___Registers.CR___1 = CLEAR;
	FR1__Registers.FR1__1 = CLEAR;
	FR2__Registers.FR2__1 = CLEAR;
	FR3__Registers.FR3__1 = CLEAR;
	OD___Registers.OD___1 = CLEAR;
	PUP__Registers.PUP__1 = CLEAR;
	PDN__Registers.PDN__1 = CLEAR;
	IE___Registers.IE___1 = CLEAR;

	//	PK2
	DATA_Registers.DATA_2 = CLEAR;
	CR___Registers.CR___2 = CLEAR;
	FR1__Registers.FR1__2 = CLEAR;
	FR2__Registers.FR2__2 = CLEAR;
	FR3__Registers.FR3__2 = CLEAR;
	OD___Registers.OD___2 = CLEAR;
	PUP__Registers.PUP__2 = CLEAR;
	PDN__Registers.PDN__2 = CLEAR;
	IE___Registers.IE___2 = CLEAR;

	//	PK3
	DATA_Registers.DATA_3 = CLEAR;
	CR___Registers.CR___3 = CLEAR;
	FR1__Registers.FR1__3 = CLEAR;
	FR2__Registers.FR2__3 = CLEAR;
	FR3__Registers.FR3__3 = CLEAR;
	OD___Registers.OD___3 = CLEAR;
	PUP__Registers.PUP__3 = CLEAR;
	PDN__Registers.PDN__3 = CLEAR;
	IE___Registers.IE___3 = CLEAR;

	//	PK4
	DATA_Registers.DATA_4 = CLEAR;
	CR___Registers.CR___4 = CLEAR;
	FR1__Registers.FR1__4 = CLEAR;
	FR2__Registers.FR2__4 = CLEAR;
	FR3__Registers.FR3__4 = CLEAR;
	OD___Registers.OD___4 = CLEAR;
	PUP__Registers.PUP__4 = CLEAR;
	PDN__Registers.PDN__4 = CLEAR;
	IE___Registers.IE___4 = CLEAR;

	//	PK5
	DATA_Registers.DATA_5 = CLEAR;
	CR___Registers.CR___5 = CLEAR;
	FR1__Registers.FR1__5 = CLEAR;
	FR2__Registers.FR2__5 = CLEAR;
	FR3__Registers.FR3__5 = CLEAR;
	OD___Registers.OD___5 = CLEAR;
	PUP__Registers.PUP__5 = CLEAR;
	PDN__Registers.PDN__5 = CLEAR;
	IE___Registers.IE___5 = CLEAR;
	
	//	PK6
	DATA_Registers.DATA_6 = CLEAR;
	CR___Registers.CR___6 = CLEAR;
	FR1__Registers.FR1__6 = CLEAR;
	FR2__Registers.FR2__6 = CLEAR;
	FR3__Registers.FR3__6 = CLEAR;
	OD___Registers.OD___6 = CLEAR;
	PUP__Registers.PUP__6 = CLEAR;
	PDN__Registers.PDN__6 = CLEAR;
	IE___Registers.IE___6 = CLEAR;

	//	PK7
	DATA_Registers.DATA_7 = CLEAR;
	CR___Registers.CR___7 = CLEAR;
	FR1__Registers.FR1__7 = CLEAR;
	FR2__Registers.FR2__7 = CLEAR;
	FR3__Registers.FR3__7 = CLEAR;
	OD___Registers.OD___7 = CLEAR;
	PUP__Registers.PUP__7 = CLEAR;
	PDN__Registers.PDN__7 = CLEAR;
	IE___Registers.IE___7 = CLEAR;
	
	WROS_____PK->DATA_register = DATA_Registers;
	WROS_____PK->CR___register = CR___Registers;
	WROS_____PK->FR1__register = FR1__Registers;
	WROS_____PK->FR2__register = FR2__Registers;
	WROS_____PK->FR3__register = FR3__Registers;
	WROS_____PK->OD___register = OD___Registers;
	WROS_____PK->PUP__register = PUP__Registers;
	WROS_____PK->PDN__register = PDN__Registers;
	WROS_____PK->IE___register = IE___Registers;
}

static void Init_PORT_L()
{
	//	PL0
	DATA_Registers.DATA_0 = CLEAR;
	CR___Registers.CR___0 = CLEAR;
	FR1__Registers.FR1__0 = CLEAR;
	FR2__Registers.FR2__0 = CLEAR;
	FR3__Registers.FR3__0 = CLEAR;
	OD___Registers.OD___0 = CLEAR;
	PUP__Registers.PUP__0 = CLEAR;
	PDN__Registers.PDN__0 = CLEAR;
	IE___Registers.IE___0 = CLEAR;
	
	//	PL1
	DATA_Registers.DATA_1 = CLEAR;
	CR___Registers.CR___1 = CLEAR;
	FR1__Registers.FR1__1 = CLEAR;
	FR2__Registers.FR2__1 = CLEAR;
	FR3__Registers.FR3__1 = CLEAR;
	OD___Registers.OD___1 = CLEAR;
	PUP__Registers.PUP__1 = CLEAR;
	PDN__Registers.PDN__1 = CLEAR;
	IE___Registers.IE___1 = CLEAR;

	//	PL2
	DATA_Registers.DATA_2 = CLEAR;
	CR___Registers.CR___2 = CLEAR;
	FR1__Registers.FR1__2 = CLEAR;
	FR2__Registers.FR2__2 = CLEAR;
	FR3__Registers.FR3__2 = CLEAR;
	OD___Registers.OD___2 = CLEAR;
	PUP__Registers.PUP__2 = CLEAR;
	PDN__Registers.PDN__2 = CLEAR;
	IE___Registers.IE___2 = CLEAR;

	//	PL3
	DATA_Registers.DATA_3 = CLEAR;
	CR___Registers.CR___3 = CLEAR;
	FR1__Registers.FR1__3 = CLEAR;
	FR2__Registers.FR2__3 = CLEAR;
	FR3__Registers.FR3__3 = CLEAR;
	OD___Registers.OD___3 = CLEAR;
	PUP__Registers.PUP__3 = CLEAR;
	PDN__Registers.PDN__3 = CLEAR;
	IE___Registers.IE___3 = CLEAR;

	//	PL4
	DATA_Registers.DATA_4 = CLEAR;
	CR___Registers.CR___4 = CLEAR;
	FR1__Registers.FR1__4 = CLEAR;
	FR2__Registers.FR2__4 = CLEAR;
	FR3__Registers.FR3__4 = CLEAR;
	OD___Registers.OD___4 = CLEAR;
	PUP__Registers.PUP__4 = CLEAR;
	PDN__Registers.PDN__4 = CLEAR;
	IE___Registers.IE___4 = CLEAR;

	//	PL5
	DATA_Registers.DATA_5 = CLEAR;
	CR___Registers.CR___5 = CLEAR;
	FR1__Registers.FR1__5 = CLEAR;
	FR2__Registers.FR2__5 = CLEAR;
	FR3__Registers.FR3__5 = CLEAR;
	OD___Registers.OD___5 = CLEAR;
	PUP__Registers.PUP__5 = CLEAR;
	PDN__Registers.PDN__5 = CLEAR;
	IE___Registers.IE___5 = CLEAR;
	
	//	PL6
	DATA_Registers.DATA_6 = CLEAR;
	CR___Registers.CR___6 = CLEAR;
	FR1__Registers.FR1__6 = CLEAR;
	FR2__Registers.FR2__6 = CLEAR;
	FR3__Registers.FR3__6 = CLEAR;
	OD___Registers.OD___6 = CLEAR;
	PUP__Registers.PUP__6 = CLEAR;
	PDN__Registers.PDN__6 = CLEAR;
	IE___Registers.IE___6 = CLEAR;

	//	PL7
	DATA_Registers.DATA_7 = CLEAR;
	CR___Registers.CR___7 = CLEAR;
	FR1__Registers.FR1__7 = CLEAR;
	FR2__Registers.FR2__7 = CLEAR;
	FR3__Registers.FR3__7 = CLEAR;
	OD___Registers.OD___7 = CLEAR;
	PUP__Registers.PUP__7 = CLEAR;
	PDN__Registers.PDN__7 = CLEAR;
	IE___Registers.IE___7 = CLEAR;
	
	WROS_____PL->DATA_register = DATA_Registers;
	WROS_____PL->CR___register = CR___Registers;
	WROS_____PL->FR1__register = FR1__Registers;
	WROS_____PL->FR2__register = FR2__Registers;
	WROS_____PL->FR3__register = FR3__Registers;
	WROS_____PL->OD___register = OD___Registers;
	WROS_____PL->PUP__register = PUP__Registers;
	WROS_____PL->PDN__register = PDN__Registers;
	WROS_____PL->IE___register = IE___Registers;
}

static void Init_PORT_N()
{
	//	PN0
	DATA_Registers.DATA_0 = CLEAR;
	CR___Registers.CR___0 = CLEAR;
	FR1__Registers.FR1__0 = CLEAR;
	FR2__Registers.FR2__0 = CLEAR;
	FR3__Registers.FR3__0 = CLEAR;
	OD___Registers.OD___0 = CLEAR;
	PUP__Registers.PUP__0 = CLEAR;
	PDN__Registers.PDN__0 = CLEAR;
	IE___Registers.IE___0 = CLEAR;
	
	//	PN1
	DATA_Registers.DATA_1 = CLEAR;
	CR___Registers.CR___1 = CLEAR;
	FR1__Registers.FR1__1 = CLEAR;
	FR2__Registers.FR2__1 = CLEAR;
	FR3__Registers.FR3__1 = CLEAR;
	OD___Registers.OD___1 = CLEAR;
	PUP__Registers.PUP__1 = CLEAR;
	PDN__Registers.PDN__1 = CLEAR;
	IE___Registers.IE___1 = CLEAR;

	//	PN2
	DATA_Registers.DATA_2 = CLEAR;
	CR___Registers.CR___2 = CLEAR;
	FR1__Registers.FR1__2 = CLEAR;
	FR2__Registers.FR2__2 = CLEAR;
	FR3__Registers.FR3__2 = CLEAR;
	OD___Registers.OD___2 = CLEAR;
	PUP__Registers.PUP__2 = CLEAR;
	PDN__Registers.PDN__2 = CLEAR;
	IE___Registers.IE___2 = CLEAR;

	//	PN3
	DATA_Registers.DATA_3 = CLEAR;
	CR___Registers.CR___3 = CLEAR;
	FR1__Registers.FR1__3 = CLEAR;
	FR2__Registers.FR2__3 = CLEAR;
	FR3__Registers.FR3__3 = CLEAR;
	OD___Registers.OD___3 = CLEAR;
	PUP__Registers.PUP__3 = CLEAR;
	PDN__Registers.PDN__3 = CLEAR;
	IE___Registers.IE___3 = CLEAR;

	//	PN4
	DATA_Registers.DATA_4 = CLEAR;
	CR___Registers.CR___4 = CLEAR;
	FR1__Registers.FR1__4 = CLEAR;
	FR2__Registers.FR2__4 = CLEAR;
	FR3__Registers.FR3__4 = CLEAR;
	OD___Registers.OD___4 = CLEAR;
	PUP__Registers.PUP__4 = CLEAR;
	PDN__Registers.PDN__4 = CLEAR;
	IE___Registers.IE___4 = CLEAR;

	//	PN5
	DATA_Registers.DATA_5 = CLEAR;
	CR___Registers.CR___5 = CLEAR;
	FR1__Registers.FR1__5 = CLEAR;
	FR2__Registers.FR2__5 = CLEAR;
	FR3__Registers.FR3__5 = CLEAR;
	OD___Registers.OD___5 = CLEAR;
	PUP__Registers.PUP__5 = CLEAR;
	PDN__Registers.PDN__5 = CLEAR;
	IE___Registers.IE___5 = CLEAR;
	
	//	PN6
	DATA_Registers.DATA_6 = CLEAR;
	CR___Registers.CR___6 = CLEAR;
	FR1__Registers.FR1__6 = CLEAR;
	FR2__Registers.FR2__6 = CLEAR;
	FR3__Registers.FR3__6 = CLEAR;
	OD___Registers.OD___6 = CLEAR;
	PUP__Registers.PUP__6 = CLEAR;
	PDN__Registers.PDN__6 = CLEAR;
	IE___Registers.IE___6 = CLEAR;

	//	PN7
	DATA_Registers.DATA_7 = CLEAR;
	CR___Registers.CR___7 = CLEAR;
	FR1__Registers.FR1__7 = CLEAR;
	FR2__Registers.FR2__7 = CLEAR;
	FR3__Registers.FR3__7 = CLEAR;
	OD___Registers.OD___7 = CLEAR;
	PUP__Registers.PUP__7 = CLEAR;
	PDN__Registers.PDN__7 = CLEAR;
	IE___Registers.IE___7 = CLEAR;
	
	WROS_____PN->DATA_register = DATA_Registers;
	WROS_____PN->CR___register = CR___Registers;
	WROS_____PN->FR1__register = FR1__Registers;
	WROS_____PN->FR2__register = FR2__Registers;
	WROS_____PN->FR3__register = FR3__Registers;
	WROS_____PN->OD___register = OD___Registers;
	WROS_____PN->PUP__register = PUP__Registers;
	WROS_____PN->PDN__register = PDN__Registers;
	WROS_____PN->IE___register = IE___Registers;
}

static void Init_PORT_P()
{
	//	PP0
	DATA_Registers.DATA_0 = CLEAR;
	CR___Registers.CR___0 = CLEAR;
	FR1__Registers.FR1__0 = CLEAR;
	FR2__Registers.FR2__0 = CLEAR;
	FR3__Registers.FR3__0 = CLEAR;
	OD___Registers.OD___0 = CLEAR;
	PUP__Registers.PUP__0 = CLEAR;
	PDN__Registers.PDN__0 = CLEAR;
	IE___Registers.IE___0 = CLEAR;
	
	//	PP1
	DATA_Registers.DATA_1 = CLEAR;
	CR___Registers.CR___1 = CLEAR;
	FR1__Registers.FR1__1 = CLEAR;
	FR2__Registers.FR2__1 = CLEAR;
	FR3__Registers.FR3__1 = CLEAR;
	OD___Registers.OD___1 = CLEAR;
	PUP__Registers.PUP__1 = CLEAR;
	PDN__Registers.PDN__1 = CLEAR;
	IE___Registers.IE___1 = CLEAR;

	//	PP2
	DATA_Registers.DATA_2 = CLEAR;
	CR___Registers.CR___2 = CLEAR;
	FR1__Registers.FR1__2 = CLEAR;
	FR2__Registers.FR2__2 = CLEAR;
	FR3__Registers.FR3__2 = CLEAR;
	OD___Registers.OD___2 = CLEAR;
	PUP__Registers.PUP__2 = CLEAR;
	PDN__Registers.PDN__2 = CLEAR;
	IE___Registers.IE___2 = CLEAR;

	//	PP3
	DATA_Registers.DATA_3 = CLEAR;
	CR___Registers.CR___3 = CLEAR;
	FR1__Registers.FR1__3 = CLEAR;
	FR2__Registers.FR2__3 = CLEAR;
	FR3__Registers.FR3__3 = CLEAR;
	OD___Registers.OD___3 = CLEAR;
	PUP__Registers.PUP__3 = CLEAR;
	PDN__Registers.PDN__3 = CLEAR;
	IE___Registers.IE___3 = CLEAR;

	//	PP4
	DATA_Registers.DATA_4 = CLEAR;
	CR___Registers.CR___4 = CLEAR;
	FR1__Registers.FR1__4 = CLEAR;
	FR2__Registers.FR2__4 = CLEAR;
	FR3__Registers.FR3__4 = CLEAR;
	OD___Registers.OD___4 = CLEAR;
	PUP__Registers.PUP__4 = CLEAR;
	PDN__Registers.PDN__4 = CLEAR;
	IE___Registers.IE___4 = CLEAR;

	//	PP5
	DATA_Registers.DATA_5 = CLEAR;
	CR___Registers.CR___5 = CLEAR;
	FR1__Registers.FR1__5 = CLEAR;
	FR2__Registers.FR2__5 = CLEAR;
	FR3__Registers.FR3__5 = CLEAR;
	OD___Registers.OD___5 = CLEAR;
	PUP__Registers.PUP__5 = CLEAR;
	PDN__Registers.PDN__5 = CLEAR;
	IE___Registers.IE___5 = CLEAR;
	
	//	PP6
	DATA_Registers.DATA_6 = CLEAR;
	CR___Registers.CR___6 = CLEAR;
	FR1__Registers.FR1__6 = CLEAR;
	FR2__Registers.FR2__6 = CLEAR;
	FR3__Registers.FR3__6 = CLEAR;
	OD___Registers.OD___6 = CLEAR;
	PUP__Registers.PUP__6 = CLEAR;
	PDN__Registers.PDN__6 = CLEAR;
	IE___Registers.IE___6 = CLEAR;

	//	PP7
	DATA_Registers.DATA_7 = CLEAR;
	CR___Registers.CR___7 = CLEAR;
	FR1__Registers.FR1__7 = CLEAR;
	FR2__Registers.FR2__7 = CLEAR;
	FR3__Registers.FR3__7 = CLEAR;
	OD___Registers.OD___7 = CLEAR;
	PUP__Registers.PUP__7 = CLEAR;
	PDN__Registers.PDN__7 = CLEAR;
	IE___Registers.IE___7 = CLEAR;	

	WROS_____PP->DATA_register = DATA_Registers;
	WROS_____PP->CR___register = CR___Registers;
	WROS_____PP->FR1__register = FR1__Registers;
	WROS_____PP->FR2__register = FR2__Registers;
	WROS_____PP->FR3__register = FR3__Registers;
	WROS_____PP->OD___register = OD___Registers;
	WROS_____PP->PUP__register = PUP__Registers;
	WROS_____PP->PDN__register = PDN__Registers;
	WROS_____PP->IE___register = IE___Registers;
}

void WROS_PORT_Init(void)
{
	Init_PORT_A();
	Init_PORT_B();
	Init_PORT_C();
	Init_PORT_D();
	Init_PORT_E();
	Init_PORT_F();
	Init_PORT_G();
	Init_PORT_H();
//	Init_PORT_J();
//	Init_PORT_K();
//	Init_PORT_L();
//	Init_PORT_N();
//	Init_PORT_P();
}

/*************************** END OF FILE **************************************/
