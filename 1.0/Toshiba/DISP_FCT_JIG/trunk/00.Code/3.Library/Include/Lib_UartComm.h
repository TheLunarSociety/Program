#pragma once

#ifndef __UARTCOMMUNACTION__
#define __UARTCOMMUNACTION__


/***********************************************************
	<Variable>
***********************************************************/



// Toshiba Uart function
void	Lib_Uart_Control(T_DispInfo*);
void	Uart_Display(T_DispInfo*, UINT8);
void	Uart_PC(T_DispInfo*, UINT8);



void	Uart_DisplayPacketSendControl(T_DispInfo*, UINT8);
void	Uart_DisplayPacketReceiveControl(T_DispInfo*,UINT8);

void	Uart_OptionPacketSendControl(T_DispInfo*, UINT8);
void	Uart_OptionPacketReceiveControl(T_DispInfo*,UINT8);

void	Uart_PCPacketSendControl(T_DispInfo*, UINT8);
void	Uart_PCPacketReceiveControl(T_DispInfo*,UINT8);

static const T_UartCommDef UART_Control[] = 
{
	{	Uart_DisplayPacketSendControl,	Uart_DisplayPacketReceiveControl
	},
	
	{	Uart_OptionPacketSendControl,	Uart_OptionPacketReceiveControl
	},
	
	{	Uart_PCPacketSendControl,		Uart_PCPacketReceiveControl
	},
};


/***********************************************************
	<Function>
***********************************************************/
void MWI_UART_DispStartUartInterrupt(T_DispInfo*, UINT8);		//tx rx interrupt
void MWI_UART_PCStartUartInterrupt(T_DispInfo*, UINT8);		//tx rx interrupt


void func_uart_disp_tx_packet(T_DispInfo*, UINT8*);
void func_uart_disp_rx_packet(T_DispInfo*, UINT8*);

void func_uart_pc_tx_packet(T_DispInfo*, UINT8*);
void func_uart_pc_rx_packet(T_DispInfo*, UINT8*);

#endif

/* End of File */

