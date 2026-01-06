#include <stdlib.h>
#include <string.h>

#define __WORKINGNORMAL
#include "../../1.Application/Include/APP_WorkingNormalState.h"
#undef __WORKINGNORMAL

#include "../../2.Component/Include/Cmp_KeyScan.h"
#include "../../2.Component/Include/Cmp_Display_Service.h"
#include "../../2.Component/Include/Cmp_LQC_Process.h"
#include "../../2.Component/Include/Cmp_SetError.h"
#include "../../2.Component/Include/Cmp_Onboarding.h"

#include "../../3.Library/Include/Int.h"
#include "../../3.Library/Include/Lib_UartComm.h"
#include "../../3.Library/Include/Lib_CommSubMicom.h"
#include "../../3.Library/Include/Lib_EEPROM.h"
#include "../../3.Library/Include/Lib_Flash.h"

#include "../../4.Driver/Include/DDI_BootingDriver.h"


#include "../../6.VariableSource/Include/Vable_ModelInformation.h"


void ConCurrentFuction(T_DispInfo*);
void App_CheckData(T_DispInfo*);
void App_Uart_Control(T_DispInfo*);
void App_RequestData(T_DispInfo*);
void AutoBPS(T_DispInfo*);

UINT32* ReadingFlash(UINT32,UINT8);
void WriteingFlash(UINT8);
void WriteingEEPROM(UINT8);
UINT16 CalcChecksum(UINT32, UINT32);

extern const UINT8 gauCommInfo[PlaformMax][CommInformMax];
extern const T_BufferDef mpstBufferInfo[CommStateMax];

UINT8 EEPROM_MemoryInfo[8] = {0,};
UINT32 MemorySpace[8];
T_Time	gstDataCheckGapTime;
/**
* @fn void Run(UINT16 ucCheckSum)
* @return       NA 
* @see          gstDisplayInfo
*/
void WROS_FUNC_Run(T_DispInfo* psDisplayInfo)
{
	while(1)
	{
		API_WDT_Set_Wdt_Nmi_Clr();												//	Clear watch dog
		ConCurrentFuction(psDisplayInfo);
		
		#ifdef OPTION_ONBOARDING	
		Cmp_OnboardingCheck(psDisplayInfo);										//	not use onboarding
		#endif
		
		#ifndef EEPROM_MEMORY	
		WriteingFlash(psDisplayInfo->DispType);									//	Save to Flash
		#else					
		WriteingEEPROM(psDisplayInfo->DispType);								//	Save to EEPROM
		#endif
	}
}

void App_Init_State(T_DispInfo* psDisplayInfo)
{
	gunKey_New										= NO_KEY;
	PRE_ERROR										= NO_ERROR;
	ERROR_State										= NO_ERROR;
	
	psDisplayInfo->DispType							= JigUpdate;
	psDisplayInfo->MainStatus						= OFF;
	psDisplayInfo->mucLogLqcStep					= VERSION_STEP;
	psDisplayInfo->BeepStatus						= CLEAR;
	psDisplayInfo->UartInfo.UartRx_Index 			= CLEAR;
	psDisplayInfo->UartInfo.UartRx_Finish			= CLEAR;
	psDisplayInfo->UartInfo.UartRx_PktSize			= CLEAR;
	psDisplayInfo->UartInfo.UartTx_Index 			= CLEAR;
	psDisplayInfo->UartInfo.UartTx_Finish			= CLEAR;
	psDisplayInfo->UartInfo.UartTx_PktSize			= CLEAR;
	
	psDisplayInfo->UartInfo.CommMode[NormalComm]	= SET;
	psDisplayInfo->UartInfo.CommMode[LoadOpComm]	= CLEAR;
	psDisplayInfo->UartInfo.CommMode[Jig2PCComm]	= CLEAR;
	psDisplayInfo->UartInfo.CommMode[CommStateMax]	= CLEAR;
	
	psDisplayInfo->UartInfo.CurCommMode				= NormalComm;
	
	psDisplayInfo->DispAnsChk						= CLEAR;
	psDisplayInfo->PlatCheckStep					= PlatChk_Request;

	Onboarding_ModelFlag							= CLEAR;
	Memory_Flag										= CLEAR;
	gunOpWriteFlag									= CLEAR;
	EEPROM_Flag										= CLEAR;
	ErrorCheckFlag									= CLEAR;
	STANDBY_SIGNAL_Flag								= CLEAR;
	Door_SEN_SIGNAL_Flag							= CLEAR;
	Door_SIG_SIGNAL_Flag							= CLEAR;

#ifdef OPTION_ONBOARDING	
	psDisplayInfo->UartInfo.CommMode[NormalComm]	= CLEAR;
	psDisplayInfo->UartInfo.CommMode[LoadOpComm]	= SET;
	Onboarding_ModelFlag							= SET;
#endif

/*
#ifndef EEPROM_MEMORY	
	ReadingFlash(0x60000,8);
	Onboarding_ModelFlag = MemorySpace[4];
#else
	EEP_LoadBufferFromEEPROM(1,EEPROM_MemoryInfo,8);							//	Load from EEPROM
	Onboarding_ModelFlag = EEPROM_MemoryInfo[1];
#endif
*/
}

void ConCurrentFuction(T_DispInfo* psDisplayInfo)
{	
	Cmp_JIG_KeyScan(psDisplayInfo);												//	JIG Key
	
	Cmp_JIG_Display(psDisplayInfo);											//	JIG Led

	Cmp_Error_Check(psDisplayInfo); 												//	Error Check

	Cmp_Set_Platform(psDisplayInfo);  											//	Set Platform and UART Comm

	Cmp_LQC_ModeProcess(psDisplayInfo);										//	Display check start
}

void WROS_FUNC_Set_Platform(T_DispInfo* psDisplayInfo)
{
	while(1)
	{
		MAKE_TEST_POINT(SET_PLAT_FLAG);
		Cmp_Set_Platform(psDisplayInfo);
	}
}

void Cmp_Set_Platform(T_DispInfo* psDisplayInfo)
{
	switch(psDisplayInfo->PlatCheckStep)
	{
		default:
		case PlatChk_Request:
			App_RequestData(psDisplayInfo);
			break;
			
		case PlatChk_Working:
			App_CheckData(psDisplayInfo);
			break;
		
		case PlatChk_Finish:
			App_Uart_Control(psDisplayInfo);
			break;
	}	
}

void App_RequestData(T_DispInfo* psDisplayInfo)
{
	if(psDisplayInfo->PlatCheckStep == PlatChk_Request)
	{
		psDisplayInfo->PlatCheckStep = PlatChk_Working;
		
		psDisplayInfo->UartInfo.UartTx_PktSize = gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];
		psDisplayInfo->UartInfo.UartTxBuff = (TxBufMon_T*)mpstBufferInfo[NormalComm].pstSendBuffer;
		psDisplayInfo->UartInfo.UartRxBuff = (RxBufMon_T*)mpstBufferInfo[NormalComm].pstRecvBuffer;
		
		memset(mpstBufferInfo[NormalComm].pstSendBuffer, 0, 255);
		switch(psDisplayInfo->DispType)
		{
			case Mega_Titan:
				mpstBufferInfo[NormalComm].pstSendBuffer[0] = psDisplayInfo->UartInfo.UartTx_PktSize;
				mpstBufferInfo[NormalComm].pstSendBuffer[1] = STX_NORMAL;
				break;
				
			case Vivace:
				mpstBufferInfo[NormalComm].pstSendBuffer[0] = STX_NORMAL;
				mpstBufferInfo[NormalComm].pstSendBuffer[1] = psDisplayInfo->UartInfo.UartTx_PktSize;
				mpstBufferInfo[NormalComm].pstSendBuffer[2] = psDisplayInfo->DispType;
				mpstBufferInfo[NormalComm].pstSendBuffer[29]= SET << 6;
				break;
				
			case LCD_VXD_Dryer:
				mpstBufferInfo[NormalComm].pstSendBuffer[0] = STX_NORMAL;
				mpstBufferInfo[NormalComm].pstSendBuffer[1] = 0;
				mpstBufferInfo[NormalComm].pstSendBuffer[2] = psDisplayInfo->UartInfo.UartTx_PktSize;
				mpstBufferInfo[NormalComm].pstSendBuffer[4] = ACK;
				mpstBufferInfo[NormalComm].pstSendBuffer[7] = SET;
				break;

			default:
				mpstBufferInfo[NormalComm].pstSendBuffer[0] = STX_NORMAL;
				mpstBufferInfo[NormalComm].pstSendBuffer[1] = psDisplayInfo->UartInfo.UartTx_PktSize;
				mpstBufferInfo[NormalComm].pstSendBuffer[2] = psDisplayInfo->DispType;
				break;
		}

		Uart_CrcPacketEncode(mpstBufferInfo[NormalComm].pstSendBuffer, psDisplayInfo->UartInfo.UartTx_PktSize, ETX_NORMAL);
		
		psDisplayInfo->UartInfo.UartTx_Index = 0;
		func_uart_disp_tx_packet(psDisplayInfo, mpstBufferInfo[NormalComm].pstSendBuffer);
		Timer_GetTime(&gstDataCheckGapTime);
	}
	else
	{	;
	}
}

void App_CheckData(T_DispInfo* psDisplayInfo)
{	
	UINT8 ucCheckTimes = 0;
	ucCheckTimes = DataReadWriteDataMemory(mucDispCheckTimes, READ, NA);
	
	psDisplayInfo->UartInfo.UartRx_PktSize = gauCommInfo[psDisplayInfo->DispType][RECV_DATA_SIZE];
	// Already Read Data finish 
	if(psDisplayInfo->UartInfo.UartRx_Finish == SET)
	{
		psDisplayInfo->UartInfo.UartRx_Finish = CLEAR;
		
		// Check Platform
		if(Uart_CrcPacketCheck(psDisplayInfo, mpstBufferInfo[NormalComm].pstRecvBuffer) == RETURN_OK)
		{
			if(psDisplayInfo->DispType == New_Topgun || psDisplayInfo->DispType == Topgun_WW) 
			{	psDisplayInfo->DispType = (mpstBufferInfo[NormalComm].pstRecvBuffer[9] == SET ? New_Topgun : Topgun_WW);
			}
			else
			{	;
			}
	
			psDisplayInfo->UartInfo.UartRx_Index	= CLEAR;
			psDisplayInfo->UartInfo.UartRx_Finish	= CLEAR;
			psDisplayInfo->UartInfo.UartTx_Finish	= CLEAR;
			psDisplayInfo->UartInfo.UartRx_PktSize	= gauCommInfo[psDisplayInfo->DispType][RECV_DATA_SIZE];
			psDisplayInfo->UartInfo.UartTx_PktSize	= gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];
			Comm_DispRecvPacket_Normal(psDisplayInfo->DispType, mpstBufferInfo[NormalComm].pstRecvBuffer);
			DataReadWriteDataMemory(mucDispEnable, WRITE, SET);

			psDisplayInfo->PlatCheckStep = PlatChk_Finish;
			return;
		}
		else
		{	
			if(ucCheckTimes == CLEAR)
			{
				AutoBPS(psDisplayInfo);
			}
			else
			{
				DataReadWriteDataMemory(mucDispCheckTimes, WRITE, (ucCheckTimes - 1));
				psDisplayInfo->PlatCheckStep = PlatChk_Request;
			}
		}
	}
	else if(Timer_MsecCheckPassTime(&gstDataCheckGapTime, 60) == SET)
	{
		if(ucCheckTimes == CLEAR)
		{
			psDisplayInfo->UartInfo.UartRx_Index = CLEAR;
			psDisplayInfo->UartInfo.UartRx_Finish = CLEAR;
			AutoBPS(psDisplayInfo);
			DataReadWriteDataMemory(mucDispEnable, WRITE, CLEAR);
		}
		else
		{	
			DataReadWriteDataMemory(mucDispCheckTimes, WRITE, (ucCheckTimes - 1));
			psDisplayInfo->PlatCheckStep = PlatChk_Request;
		}
	}
	else
	{	;
	}
}

void AutoBPS(T_DispInfo* psDisplayInfo)
{
	CounterAddLimit(psDisplayInfo->DispType, JigUpdate, PlaformMax - 1);
	DataReadWriteDataMemory(mucDispCheckTimes, WRITE, psDisplayInfo->DispType == LCD_VX_NT ? 1 : 0);	// Only "LCD_VX_NT" need check twice

	switch(psDisplayInfo->DispType)
	{
		case JigUpdate:
		case Mega_Titan:
			API_UART_Setting(WROS_UART_0, BPS_9600);
			break;
			
		case LCD_VX_NT:
		case LCD_VXD_Dryer:
			API_UART_Setting(WROS_UART_0, BPS_115200);
			break;
			
		default:
			API_UART_Setting(WROS_UART_0, BPS_19200);
			break;
	}

	psDisplayInfo->PlatCheckStep = PlatChk_Request;
}

void App_Uart_Control(T_DispInfo* psDisplayInfo)
{
	Lib_Uart_Control(psDisplayInfo);
	
	if(psDisplayInfo->DispAnsChk <= 3)
	{	;
	}
	else
	{
		psDisplayInfo->DispAnsChk = 0;
		psDisplayInfo->PlatCheckStep = PlatChk_Request;
	}
}

UINT32* ReadingFlash(UINT32 ulAddress, UINT8 SIZE)
{
	UINT8 i;
	
	for(i = 0; i < SIZE; i++)
	{
		MemorySpace[i] = *(UINT16*)(ulAddress + i);
	}
			
	return MemorySpace;
}

void WriteingFlash(UINT8 ucDispType)
{
	T_CMD_STEP CMD_Step = CMD_ERASE_STEP;

	MemorySpace[0] = ucDispType;
	MemorySpace[1] = Onboarding_ModelFlag;

	SetCMDBuffer(MemorySpace);
	
	if(Memory_Flag == SET)
	{
		Memory_Flag = CLEAR;

		__disable_interrupt();
		
		while(CMD_Step != CMD_FINISH_STEP)
		{
			CMD_Step = mapfnFlashStepFunc[CMD_Step]();
		}
		__enable_interrupt();
	}
	else
	{	;
	}
}

void WriteingEEPROM(UINT8 ucDispType)
{
	if(EEPROM_Flag == SET)
	{	
		EEPROM_Flag = CLEAR;
		EEPROM_MemoryInfo[0] = ucDispType;
		EEPROM_MemoryInfo[1] = Onboarding_ModelFlag;
		EEP_SaveBufferToEEPROM(1,EEPROM_MemoryInfo,8);								//	Save to EEPROM
	}
	else
	{	;
	}
}

UINT16 CalcChecksum(UINT32 ulAddress, UINT32 ulLength)
{

	UINT16 unCheckSum = 0;
	UINT8* pucRomData = (UINT8*)ulAddress;

	while(ulLength)
	{
		unCheckSum += *pucRomData;
		pucRomData++;
		ulLength--;
	}

	return unCheckSum;
}

