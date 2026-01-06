/*******************************************************************************
*
* @file:    m470_int.c
* @purpose: Interrupt Setting Source File
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


#define DEFINE_APP_INT
#include "../../5.Hardware/Include/m470_int.h"
#undef DEFINE_APP_INT

/*******************************************************************************
* Function Name  : API_INT_Init
* Description	 : Interrupt Initialize
* Input 		 : none
* Output		 : none
*******************************************************************************/
void API_INT_Init(void)
{
/*----- MCU(M470) INTERRUPT INITIALIZE -----*/
	API_INT_Clear_Init();		//	CG->RSTFLG = 0x00;
	API_CG_Active_Reset();

/*----- Cortex-M4 NVIC INITIALIZE -----*/
	UINT8 i;
	for (i=0; i<240; i++){
		WROS_CORE_M->NVIC_register.IPR[i] = 0x00;
	}

	WROS_CORE_M->NVIC_register.ICSR = 0x00000000; 		/* Interruption control register */	
	WROS_CORE_M->NVIC_register.VTOR = 0x4000;
	WROS_CORE_M->NVIC_register.SHP[0] = 0x00; 			/* System handler priority register */
	WROS_CORE_M->NVIC_register.SHP[1] = 0x00;
	WROS_CORE_M->NVIC_register.SHP[2] = 0x00;
	WROS_CORE_M->NVIC_register.SHP[3] = 0x00;
	WROS_CORE_M->NVIC_register.SHP[4] = 0x00;
	WROS_CORE_M->NVIC_register.SHP[5] = 0x00;
	WROS_CORE_M->NVIC_register.SHP[6] = 0x00;
	WROS_CORE_M->NVIC_register.SHP[7] = 0x00;
	WROS_CORE_M->NVIC_register.SHP[8] = 0x00;
	WROS_CORE_M->NVIC_register.SHP[9] = 0x00;
	WROS_CORE_M->NVIC_register.SHP[10] = 0x00;
	WROS_CORE_M->NVIC_register.SHP[11] = 0x00;
	WROS_CORE_M->NVIC_register.SHCSR = 0x00000000;		/* System handler control register */
	WROS_CORE_M->SYSTICK_register.STCSR = 0x00000000;		/* SysTick register */
        
}

/*******************************************************************************
* Function Name  : API_INT_Clear_Init
* Description	 : CG Interrupt Request All Clear
* Input 		 : none
* Output		 : none
*******************************************************************************/
void API_INT_Clear_Init(void)
{
	WROS_CLK_GE->ICRCG = 0x00;
	WROS_CLK_GE->ICRCG = 0x01;
	WROS_CLK_GE->ICRCG = 0x02;
	WROS_CLK_GE->ICRCG = 0x03;
	WROS_CLK_GE->ICRCG = 0x04;
	WROS_CLK_GE->ICRCG = 0x05;
	WROS_CLK_GE->ICRCG = 0x06;
	WROS_CLK_GE->ICRCG = 0x07;
	WROS_CLK_GE->ICRCG = 0x08;
	WROS_CLK_GE->ICRCG = 0x09;
	WROS_CLK_GE->ICRCG = 0x0A;
	WROS_CLK_GE->ICRCG = 0x0B;
	WROS_CLK_GE->ICRCG = 0x0C;
	WROS_CLK_GE->ICRCG = 0x0D;
	WROS_CLK_GE->ICRCG = 0x0E;
	WROS_CLK_GE->ICRCG = 0x0F;
}

/*******************************************************************************
* Function Name  : API_CG_Active_Reset
* Description	 : Initialize INTx clear input & Active state setting
* Input 		 : none
* Output		 : none
*******************************************************************************/
struct IMCGA_Register IMCGA_registers;
struct IMCGB_Register IMCGB_registers;
struct IMCGC_Register IMCGC_registers;
struct IMCGD_Register IMCGD_registers;

void API_CG_Active_Reset(void)
{
	IMCGA_registers.INT00EN	= CLEAR;
	IMCGA_registers.EMCG00	= CLEAR;
	IMCGA_registers.INT01EN	= CLEAR;
	IMCGA_registers.EMCG01	= CLEAR;
	IMCGA_registers.INT02EN	= CLEAR;
	IMCGA_registers.EMCG02	= CLEAR;
	IMCGA_registers.INT03EN	= CLEAR;
	IMCGA_registers.EMCG03	= CLEAR;
	
	IMCGB_registers.INT04EN	= CLEAR;
	IMCGB_registers.EMCG04	= CLEAR;
	IMCGB_registers.INT05EN	= CLEAR;
	IMCGB_registers.EMCG05	= CLEAR;
	IMCGB_registers.INT06EN	= CLEAR;
	IMCGB_registers.EMCG06	= CLEAR;
	IMCGB_registers.INT07EN	= CLEAR;
	IMCGB_registers.EMCG07	= CLEAR;
	
	IMCGC_registers.INT08EN	= CLEAR;
	IMCGC_registers.EMCG08	= CLEAR;
	IMCGC_registers.INT09EN	= CLEAR;
	IMCGC_registers.EMCG09	= CLEAR;
	IMCGC_registers.INT0AEN	= CLEAR;
	IMCGC_registers.EMCG0A	= CLEAR;
	IMCGC_registers.INT0BEN	= CLEAR;
	IMCGC_registers.EMCG0B	= CLEAR;

	IMCGD_registers.INT0CEN	= CLEAR;
	IMCGD_registers.EMCG0C	= CLEAR;
	IMCGD_registers.INT0DEN	= CLEAR;
	IMCGD_registers.EMCG0D	= CLEAR;
	IMCGD_registers.INT0EEN	= CLEAR;
	IMCGD_registers.EMCG0E	= CLEAR;
	IMCGD_registers.INT0FEN	= CLEAR;
	IMCGD_registers.EMCG0F	= CLEAR;

	WROS_CLK_GE->IMCGA_register = IMCGA_registers;
	WROS_CLK_GE->IMCGB_register = IMCGB_registers;
	WROS_CLK_GE->IMCGC_register = IMCGC_registers;
	WROS_CLK_GE->IMCGD_register = IMCGD_registers;
}

/*******************************************************************************
* Function Name  : API_INT_PR_Reset
* Description	 : Initialize interrupt level
* Input 		 : none
* Output		 : none
*******************************************************************************/
void API_INT_PR_Reset(void)
{
	UINT8 i;
	for (i=0; i<240; i++){
		WROS_CORE_M->NVIC_register.IPR[i] = 0x00;
	}
}

/*******************************************************************************
* Function Name  : TOTAL_PENDING_CLEAR
* Description	 : 
* Input 		 : none
* Output		 : none
*******************************************************************************/
void TOTAL_PENDING_CLEAR(void)
{
	WROS_CORE_M->NVIC_register.ICPR[0] = 0xFFFFFFFF;
	WROS_CORE_M->NVIC_register.ICPR[1] = 0xFFFFFFFF;
	WROS_CORE_M->NVIC_register.ICPR[2] = 0xFFFFFFFF;
	WROS_CORE_M->NVIC_register.ICPR[3] = 0xFFFFFFFF;
	WROS_CORE_M->NVIC_register.ICPR[4] = 0xFFFFFFFF;
	WROS_CORE_M->NVIC_register.ICPR[5] = 0xFFFFFFFF;
	WROS_CORE_M->NVIC_register.ICPR[6] = 0xFFFFFFFF;
	WROS_CORE_M->NVIC_register.ICPR[7] = 0xFFFFFFFF;
}


/*********************************** END OF FILE ******************************/
