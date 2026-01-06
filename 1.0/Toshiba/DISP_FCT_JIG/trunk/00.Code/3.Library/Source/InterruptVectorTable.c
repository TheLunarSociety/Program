/*****************************************************************************
	DD Type(BLDCM) Washing Machine Program
	Model					: Panacea-PJT
	Version					: Ver 1.0
	CPU						: MN103SFA5K
	File type				: C source file
	File name				: InterruptVectorTable.c
	Included Funtion		:
	Contents				: define interrupt vector table

	be coded by KIM KYUNG HOON
********************************************************************************/

#include "../../3.Library/Include/Int.h"

#include "../../5.Hardware/Include/system.h"
#include "../../5.Hardware/Include/m470_wdt.h"

#include "../../6.VariableSource/Include/Vable_ModelInformation.h"


extern void MWI_UART_DispStartUartInterrupt(T_DispInfo*,char);		//UART0
extern void MWI_UART_PCStartUartInterrupt(T_DispInfo*,char);		//UART2

extern T_DispInfo gstDisplayInfo;

UINT8 gucWdt_Nmi_Count = 0;

typedef void( *T_intfunc )( void );
typedef union { T_intfunc __fun; void * __ptr; } T_intvec_elem;


void NMI_Handler(void)					/* NMI Handler																	*/
{
	gucWdt_Nmi_Count++;
	if (gucWdt_Nmi_Count >= 5)
	{
		API_WDT_RESET_Init();
	}
	else
	{
		API_WDT_Set_WdtClr();
	}
}

void UART_R_0_Handler(void)			/* 6:  Serial reception (channel.0)                    							*/
{
	MWI_UART_DispStartUartInterrupt(&gstDisplayInfo, 0x01);			// Main-Display E?Interrupt
}

void UART_T_0_Handler(void)			/* 7:  Serial transmission (channel.0)                 							*/
{
	MWI_UART_DispStartUartInterrupt(&gstDisplayInfo,0x02);			// Main-Display E?Interrupt
}


void UART_RT_0_Handler(void)			/* 7:  Serial transmission (channel.0)                 							*/
{
	MWI_UART_DispStartUartInterrupt(&gstDisplayInfo,0x02);			// Main-Display E?Interrupt
}

void INTTB51_IRQHandler(void)			/* 27: 16bit TMRB5 compare match detection 1           							*/
{
	MWI_INT_Timer0();
}

void UART_R_2_Handler(void)			/* 40: Serial reception (channel.2)                    							*/
{
	MWI_UART_PCStartUartInterrupt(&gstDisplayInfo, 0x01);
}
void UART_T_2_Handler(void)			/* 41: Serial transmission (channel.2)                 							*/
{
	MWI_UART_PCStartUartInterrupt(&gstDisplayInfo, 0x02);
}
