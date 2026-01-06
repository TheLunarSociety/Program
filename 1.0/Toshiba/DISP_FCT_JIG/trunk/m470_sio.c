/*******************************************************************************
*
* @file:    m470_sio.c
* @purpose: serial I/O Source File
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

#define DEFINE_APP_SIO
#include "../Include/m470_sio.h"
#undef DEFINE_APP_SIO

/*******************************************************************************
* Function Name  : API_SIO_Init
* Description	 : SIO Initialize
* Input 		 : SIO Channel
* Output		 : none
*******************************************************************************/
struct EN_Register		EN_registers;
struct BUF_Register		BUF_registers;
struct CR_Register		CR_registers;
struct MOD0_Register	MOD0_registers;
struct BRCR_Register	BRCR_registers;
struct BRADD_Register	BRADD_registers;
struct MOD1_Register	MOD1_registers;
struct MOD2_Register	MOD2_registers;
struct RFC_Register		RFC_registers;
struct TFC_Register		TFC_registers;
struct FCNF_Register	FCNF_registers;

const UINT8 PRESCALE_N[BPS_MAX] = {12,	6,		1};
const UINT8 PRESCALE_K[BPS_MAX] = {12,	14,		15};

static void Init_UART_0(UINT8 ucBPS)
{
	EN_registers.SIOE			= CLEAR;
	WROS_UART_0->EN_register	= EN_registers;
	
	BUF_registers.DATA_Buffer	= CLEAR;
		
	CR_registers.IOC			= CLEAR;
	CR_registers.SCLKS			= CLEAR;
	CR_registers.PEN			= CLEAR;
	CR_registers.EVEN			= CLEAR;
	CR_registers.TIDLE			= 0;
	CR_registers.TXDEMP			= 0;
	CR_registers.EHOLD			= 0;

	MOD0_registers.SC			= 0x01;
	MOD0_registers.SM			= 0x02;
	MOD0_registers.WU			= CLEAR;
	MOD0_registers.RXE			= SET;
	MOD0_registers.CTSE			= CLEAR;
	MOD0_registers.TBit8		= CLEAR;
	
	FCNF_registers.CNFG			= SET;
	FCNF_registers.RXTXCNT		= CLEAR;
	FCNF_registers.RFIE			= CLEAR;
	FCNF_registers.TFIE			= CLEAR;
	FCNF_registers.RFST			= CLEAR;

	RFC_registers.RIL			= 0x00;
	RFC_registers.RFIS			= CLEAR;
	RFC_registers.RFCS			= SET;

	TFC_registers.TIL			= 0x00;
	TFC_registers.TFIS			= CLEAR;
	TFC_registers.TFCS			= CLEAR;
	TFC_registers.TBCLR			= CLEAR;

	
	EN_registers.SIOE			= SET;
	EN_registers.BRCKSEL		= 0x00;
	
	MOD1_registers.EMPTY		= CLEAR;
	MOD1_registers.SINT			= 0x00;
	MOD1_registers.TXE			= SET;
	MOD1_registers.FDPX			= 0x00;		// think
	MOD1_registers.I2SC			= CLEAR;

	MOD2_registers.TBEMP		= SET;
	MOD2_registers.SWRST		= 0x00;
	MOD2_registers.WBUF			= SET;
	MOD2_registers.DRCHG		= CLEAR;
	MOD2_registers.SBLEN		= CLEAR;

	BRCR_registers.BRS			= PRESCALE_N[ucBPS];	// change	N
	BRCR_registers.BRCK			= 0x02;				// change	predevice
	BRCR_registers.BRADDE		= SET;
	
	BRADD_registers.BRK			= PRESCALE_K[ucBPS];		// change	K
	
	WROS_UART_0->BUF_register	= BUF_registers;
	WROS_UART_0->EN_register	= EN_registers;
	WROS_UART_0->CR_register	= CR_registers;
	WROS_UART_0->MOD0_register	= MOD0_registers;
	WROS_UART_0->BRCR_register	= BRCR_registers;
	WROS_UART_0->BRADD_register	= BRADD_registers;
	WROS_UART_0->MOD1_register	= MOD1_registers;
	WROS_UART_0->MOD2_register	= MOD2_registers;
	WROS_UART_0->RFC_register	= RFC_registers;
	WROS_UART_0->TFC_register	= TFC_registers;
	WROS_UART_0->FCNF_register	= FCNF_registers;
        
	while(1) 
	{
		API_SIO_RcvDataRead(WROS_UART_0);
                if(WROS_UART_0->MOD2_register.RBFLL == CLEAR)break;
	}
}

static void Init_UART_1(UINT8 ucBPS)
{

}

static void Init_UART_2(UINT8 ucBPS)
{
	EN_registers.SIOE			= CLEAR;
	WROS_UART_2->EN_register	= EN_registers;
	
	BUF_registers.DATA_Buffer	= CLEAR;
		
	CR_registers.IOC			= CLEAR;
	CR_registers.SCLKS			= CLEAR;
	CR_registers.PEN			= CLEAR;
	CR_registers.EVEN			= CLEAR;
	CR_registers.TIDLE			= 0;
	CR_registers.TXDEMP			= 0;
	CR_registers.EHOLD			= 0;

	MOD0_registers.SC			= 0x01;
	MOD0_registers.SM			= 0x02;
	MOD0_registers.WU			= CLEAR;
	MOD0_registers.RXE			= SET;
	MOD0_registers.CTSE			= CLEAR;
	MOD0_registers.TBit8		= CLEAR;
	
	FCNF_registers.CNFG			= SET;
	FCNF_registers.RXTXCNT		= CLEAR;
	FCNF_registers.RFIE			= CLEAR;
	FCNF_registers.TFIE			= CLEAR;
	FCNF_registers.RFST			= CLEAR;

	RFC_registers.RIL			= 0x00;
	RFC_registers.RFIS			= CLEAR;
	RFC_registers.RFCS			= SET;

	TFC_registers.TIL			= 0x00;
	TFC_registers.TFIS			= CLEAR;
	TFC_registers.TFCS			= CLEAR;
	TFC_registers.TBCLR			= CLEAR;

	
	EN_registers.SIOE			= SET;
	EN_registers.BRCKSEL		= 0x00;
	
	MOD1_registers.EMPTY		= CLEAR;
	MOD1_registers.SINT			= 0x00;
	MOD1_registers.TXE			= SET;
	MOD1_registers.FDPX			= 0x00;		// think
	MOD1_registers.I2SC			= CLEAR;

	MOD2_registers.SWRST		= 0x00;
	MOD2_registers.WBUF			= SET;
	MOD2_registers.DRCHG		= CLEAR;
	MOD2_registers.SBLEN		= CLEAR;

	BRCR_registers.BRS			= PRESCALE_N[ucBPS];	// change	N
	BRCR_registers.BRCK			= 0x02;				// change	predevice
	BRCR_registers.BRADDE		= SET;
	
	BRADD_registers.BRK			= PRESCALE_K[ucBPS];		// change	K
	
	WROS_UART_2->BUF_register	= BUF_registers;
	WROS_UART_2->EN_register	= EN_registers;
	WROS_UART_2->CR_register	= CR_registers;
	WROS_UART_2->MOD0_register	= MOD0_registers;
	WROS_UART_2->BRCR_register	= BRCR_registers;
	WROS_UART_2->BRADD_register	= BRADD_registers;
	WROS_UART_2->MOD1_register	= MOD1_registers;
	WROS_UART_2->MOD2_register	= MOD2_registers;
	WROS_UART_2->RFC_register	= RFC_registers;
	WROS_UART_2->TFC_register	= TFC_registers;
	WROS_UART_2->FCNF_register	= FCNF_registers;
	
	while(1) 
	{
		API_SIO_RcvDataRead(WROS_UART_2);
                if(WROS_UART_2->MOD2_register.RBFLL == CLEAR)break;
	}
}

static void Init_UART_3(UINT8 ucBPS)
{

}

typedef struct {
	UINT32 UartChannel;	 // 存储 WROS_UART_0 这类结构体指针
	void(*init_func)(UINT8); 		 // 存储 Init_UART_0 这类函数指针
} UART_Func_Table_TypeDef;

UART_Func_Table_TypeDef P_Func_Table[] =
{
	{WROS_UART0_BASE, Init_UART_0},
	{WROS_UART1_BASE, Init_UART_1},
	{WROS_UART2_BASE, Init_UART_2},
	{WROS_UART3_BASE, Init_UART_3},
};

void API_UART_Setting(WROS_UART__TypeDef* UART_IDX, UINT8 BaudRate)
{
	UINT8 ucUartChann = 0;
	while(UART_IDX != (WROS_UART__TypeDef*)P_Func_Table[ucUartChann].UartChannel)
	{
		ucUartChann++;
	}
	
	P_Func_Table[ucUartChann].init_func(BaudRate);
}

void WROS_UART_Init()
{	
	API_UART_Setting(WROS_UART_0, BPS_9600);
	API_UART_Setting(WROS_UART_2, BPS_19200);
}


/*******************************************************************************
* Function Name  : API_SIO_SndDataSet
* Description	 : SIO Set Send data
* Input 		 : SIO Channel, SCxBUF
* Output		 : none
*******************************************************************************/
void API_SIO_SndDataSet(WROS_UART__TypeDef* UART_Channel, uint8_t scbuf)
{
	UART_Channel->BUF = (uint32_t)(scbuf);
}

/*******************************************************************************
* Function Name  : API_SIO_RcvDataRead
* Description	 : SIO Get Receive data
* Input 		 : SIO Channel
* Output		 : SCxBUF
*******************************************************************************/
UINT8 API_SIO_RcvDataRead(WROS_UART__TypeDef* UART_Channel)
{
	return ((UINT8)(UART_Channel->BUF));
}
/*********************************** END OF FILE ******************************/
