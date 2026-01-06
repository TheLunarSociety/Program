
#include "../../1.Application/Include/APP_WorkingNormalState.h"

#include "../../2.Component/Include/Cmp_KeyScan.h"
#include "../../2.Component/Include/Cmp_Onboarding.h"


#include "../../3.Library/Include/Int.h"
#include "../../3.Library/Include/Lib_UartComm.h"
#include "../../3.Library/Include/Lib_CommSubMicom.h"
#include "../../3.Library/Include/Lib_EEPROM.h"

#include "../../4.Driver/Include/DDI_BootingDriver.h"

#include "../../6.VariableSource/Include/Vable_ModelInformation.h"

extern const T_BufferDef mpstBufferInfo[CommStateMax];
extern const UINT8 gaucBeeperInfo[PlaformMax][BeeperInformMax];
extern const UINT8 gauCommInfo[PlaformMax][CommInformMax];


UINT8	PCSendIndex = 0;
UINT8	PCRecvIndex = 0;
UINT8	PCUartRece_Ok_F = 0;
T_Time	gstDispSendGapTime;
T_Time	gstDispReceGapTime;

void Lib_Uart_Control(T_DispInfo* psDisplayInfo)
{
	for(UINT8 unCommOper = NormalComm; unCommOper < CommStateMax; unCommOper++)
	{
		if(psDisplayInfo->UartInfo.CommMode[unCommOper] == SET)
		{
			psDisplayInfo->UartInfo.CurCommMode = unCommOper;
			psDisplayInfo->UartInfo.UartTxBuff = (TxBufMon_T*)mpstBufferInfo[unCommOper].pstSendBuffer;
			psDisplayInfo->UartInfo.UartRxBuff = (RxBufMon_T*)mpstBufferInfo[unCommOper].pstRecvBuffer;
			
			Uart_Display(psDisplayInfo, unCommOper);
		}
		else
		{	;
		}
	}
}

void Uart_Display(T_DispInfo* psDisplayInfo,UINT8 ucCommOper)	// *** PC Comm not apply, please note this ***
{
	if(Timer_MsecCheckPassTime(&gstDispSendGapTime, gauCommInfo[psDisplayInfo->DispType][PacketGaptime]) == SET)
	{	
		UART_Control[ucCommOper].pSendFunc(psDisplayInfo, ucCommOper);
	}
	else
	{	;
	}
	
	switch(ucCommOper)
	{
		case Jig2PCComm:
			if(PCUartRece_Ok_F == SET)
			{
				PCUartRece_Ok_F = CLEAR;
				UART_Control[ucCommOper].pRecvFunc(psDisplayInfo,ucCommOper);
			}
			else
			{	;
			}
			break;

		case NormalComm:
		case LoadOpComm:
		default:
			if(psDisplayInfo->UartInfo.UartRx_Finish == SET)
			{	
				UART_Control[ucCommOper].pRecvFunc(psDisplayInfo, ucCommOper);
				psDisplayInfo->UartInfo.UartRx_Finish = CLEAR;
				psDisplayInfo->DispAnsChk = 0;
				Timer_GetTime(&gstDispReceGapTime);
			}
			else
			{	
				/**********************************************************************
				Function:		WakeUp Interrupter INTRX0_IRQn 
				Description:	Sometime Topgun_Amr Model Uart Receive Stop,and INTRX0_IRQHandler Stop,
							So This Function is 20ms call RX to keep Uart Receive Stable;
				**********************************************************************/
				if(Timer_MsecCheckPassTime(&gstDispReceGapTime, 300) == SET)
				{	
					psDisplayInfo->DispAnsChk++;	
					/*
					WROS_NVIC_Setting(ExternalInterrupts_6, ENABLE, 4);
					WROS_UART_0->EN_register.SIOE = SET;;
					while(WROS_UART_0->MOD2_register.TBEMP) 
					{
						WROS_UART_0->BUF = 0;
					}
					*/
				}
				else
				{	;
				}
			}
			break;
	}
}

#define DP_UART
void Uart_DisplayPacketSendControl(T_DispInfo* psDisplayInfo, UINT8 ucCommOper)
{		
	psDisplayInfo->UartInfo.UartTx_Index = 0;
	psDisplayInfo->UartInfo.UartRx_Index = 0;

	Comm_DispSetPacket_Normal(mpstBufferInfo[ucCommOper].pstSendBuffer, psDisplayInfo, ucCommOper);
	Uart_CrcPacketEncode(mpstBufferInfo[ucCommOper].pstSendBuffer,\
						gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE],\
						mpstBufferInfo[ucCommOper].ucEtx);
	func_uart_disp_tx_packet(psDisplayInfo, mpstBufferInfo[ucCommOper].pstSendBuffer);
}

void Uart_DisplayPacketReceiveControl(T_DispInfo* psDisplayInfo, UINT8 ucCommOper)
{	
	Comm_DispRecvPacket_Normal(psDisplayInfo->DispType, mpstBufferInfo[ucCommOper].pstRecvBuffer);
	Uart_CrcPacketCheck(psDisplayInfo, mpstBufferInfo[NormalComm].pstRecvBuffer);
}

#define OP_UART

void Uart_OptionPacketSendControl(T_DispInfo* psDisplayInfo, UINT8 ucCommOper)
{		
	psDisplayInfo->UartInfo.UartTx_Index = 0;
	psDisplayInfo->UartInfo.UartRx_Index = 0;
	
	Comm_OptionSetPacket_Normal(mpstBufferInfo[ucCommOper].pstSendBuffer,psDisplayInfo,ucCommOper);
	Uart_CrcPacketEncode(mpstBufferInfo[ucCommOper].pstSendBuffer,\
						gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE],\
						mpstBufferInfo[ucCommOper].ucEtx);
	func_uart_disp_tx_packet(psDisplayInfo, mpstBufferInfo[ucCommOper].pstSendBuffer);
}

void Uart_OptionPacketReceiveControl(T_DispInfo* psDisplayInfo, UINT8 ucCommOper)
{	
	Comm_OptionRecvPacket_Normal(psDisplayInfo->DispType, mpstBufferInfo[ucCommOper].pstRecvBuffer);
}

#define PC_UART

void Uart_PCPacketSendControl(T_DispInfo* psDisplayInfo, UINT8 ucCommOper)
{
	PCSendIndex = 0;
	PCRecvIndex = 0;
	
	Comm_PCSetPacket_Normal(mpstBufferInfo[ucCommOper].pstSendBuffer,\
							psDisplayInfo,ucCommOper);
	func_uart_pc_tx_packet(psDisplayInfo, mpstBufferInfo[ucCommOper].pstSendBuffer);
}

void Uart_PCPacketReceiveControl(T_DispInfo* psDisplayInfo, UINT8 ucCommOper)
{
	Comm_PCRecvPacket_Normal(psDisplayInfo->DispType, mpstBufferInfo[ucCommOper].pstRecvBuffer);
}
#define MWI_UART

/*********************************************************************
<Description> :
	- interrupt rx, tx
<Note> :
	- argument
		u8InterruptMode : rx or tx flag
	- return
	- call by int_group14()
	- operation
*********************************************************************/
void MWI_UART_DispStartUartInterrupt(T_DispInfo* psDisplayInfo, UINT8 ucInterruptMode)
{
	if(ucInterruptMode == 1)
	{	
		func_uart_disp_rx_packet(psDisplayInfo, mpstBufferInfo[psDisplayInfo->UartInfo.CurCommMode].pstRecvBuffer);		//Rx data
	}
	else if(ucInterruptMode == 2)
	{	
		func_uart_disp_tx_packet(psDisplayInfo, mpstBufferInfo[psDisplayInfo->UartInfo.CurCommMode].pstSendBuffer);		//Tx data
	}
	else
	{	;
	}
}

/*********************************************************************
<Description> :
	- transfer tx packet
<Note> :
	- argument
	- return
	- operation
*********************************************************************/

void func_uart_disp_tx_packet(T_DispInfo* psDisplayInfo, UINT8* pucPacket)
{	
	if(psDisplayInfo->UartInfo.UartTx_Index < psDisplayInfo->UartInfo.UartTx_PktSize)
	{	
		API_SIO_SndDataSet(WROS_UART_0, pucPacket[psDisplayInfo->UartInfo.UartTx_Index++]);
	}
	else
	{	psDisplayInfo->UartInfo.UartTx_Index = 0;
	}
}

/*********************************************************************
<Description> :
	- receive rx packet
<Note> :
	- argument
	- return
	- operation
*********************************************************************/
void func_uart_disp_rx_packet(T_DispInfo* psDisplayInfo, UINT8* pucPacket)
{
	if(psDisplayInfo->UartInfo.UartRx_Index < psDisplayInfo->UartInfo.UartRx_PktSize && psDisplayInfo->UartInfo.UartRx_Finish == CLEAR)
	{	
		pucPacket[psDisplayInfo->UartInfo.UartRx_Index] = API_SIO_RcvDataRead(WROS_UART_0);
		
		if(pucPacket[0] == STX_NORMAL 
		|| (psDisplayInfo->DispType == New_Topgun	&& pucPacket[0] == STX_NT_CRITICAL)
		|| (psDisplayInfo->DispType == JigUpdate	&& pucPacket[0] == STX_OPTION)
		|| (psDisplayInfo->DispType == Vivace		&& pucPacket[0] == STX_OPTION)
		|| (psDisplayInfo->DispType == Mega_Titan	&& pucPacket[0] == psDisplayInfo->UartInfo.UartRx_PktSize))
		{
			psDisplayInfo->UartInfo.UartRx_Index++;
			if(psDisplayInfo->UartInfo.UartRx_Index >= psDisplayInfo->UartInfo.UartRx_PktSize)
			{	
				psDisplayInfo->UartInfo.UartRx_Finish = SET;
				psDisplayInfo->UartInfo.UartRx_Index = CLEAR;
				DataReadWriteDataMemory(mucACK,WRITE,ACK);
			}
			else
			{
				DataReadWriteDataMemory(mucACK,WRITE,NAK);
			}
		}
		else
		{	;
		}
		
	}
	else
	{	;
	}
}

void MWI_UART_PCStartUartInterrupt(T_DispInfo* psDisplayInfo, UINT8 ucInterruptMode)
{
	if(ucInterruptMode == 1)
	{	
		func_uart_pc_rx_packet(psDisplayInfo, mpstBufferInfo[psDisplayInfo->UartInfo.CurCommMode].pstRecvBuffer);	//Rx data
	}
	else if(ucInterruptMode == 2)
	{	
		func_uart_pc_tx_packet(psDisplayInfo, mpstBufferInfo[psDisplayInfo->UartInfo.CurCommMode].pstSendBuffer);		//Tx data
	}
	else
	{
		;
	}
}

/*********************************************************************
<Description> :
	- transfer tx packet
<Note> :
	- argument
	- return
	- operation
*********************************************************************/

void func_uart_pc_tx_packet(T_DispInfo* psDisplayInfo, UINT8* pucPacket)
{
	if(PCSendIndex < gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE])
	{	
		API_SIO_SndDataSet(WROS_UART_2, pucPacket[PCSendIndex++]);
	}
	else
	{	PCSendIndex = 0;
	}
}

/*********************************************************************
<Description> :
	- receive rx packet
<Note> :
	- argument
	- return
	- operation
*********************************************************************/
void func_uart_pc_rx_packet(T_DispInfo* psDisplayInfo, UINT8* pucPacket)
{
	pucPacket[1] = gauCommInfo[psDisplayInfo->DispType][RECV_DATA_SIZE];
			
	if(PCRecvIndex < pucPacket[1])
	{
		pucPacket[PCRecvIndex++] = API_SIO_RcvDataRead(WROS_UART_2);
		if(PCRecvIndex >= pucPacket[1])
		{	PCUartRece_Ok_F = SET;
		}
		else
		{	;
		}
	}
	else
	{	;
	}
}

//End of File

