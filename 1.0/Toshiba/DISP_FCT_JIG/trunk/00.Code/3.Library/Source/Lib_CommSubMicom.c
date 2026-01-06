
#include "stdlib.h"
#include "string.h"

#include "../../4.Driver/Include/WROS_Register.h"

#include "../../1.Application/Include/APP_WorkingNormalState.h"

#include "../../2.Component/Include/Cmp_KeyScan.h"
#include "../../2.Component/Include/Cmp_LQC_Process.h"
#include "../../2.Component/Include/Cmp_SetError.h"
#include "../../2.Component/Include/Cmp_Onboarding.h"


#include "../../3.Library/Include/Int.h"
#include "../../3.Library/Include/Lib_UartComm.h"
#define __COMMSUBMICOM__
#include "../../3.Library/Include/Lib_CommSubMicom.h"
#undef __COMMSUBMICOM__
#include "../../3.Library/Include/Lib_EEPROM.h"

#include "../../4.Driver/Include/DDI_BootingDriver.h"

#include "../../5.Hardware/Include/m470_sio.h"
#include "../../5.Hardware/Include/bootloader.h"

#include "../../6.VariableSource/Include/Vable_ModelInformation.h"



extern const T_BufferDef mpstBufferInfo[CommStateMax];
extern const UINT8 gaucBeeperInfoDefine[PlaformMax][BeeperInformMax];
extern const UINT8 gauCommInfo[PlaformMax][CommInformMax];

UINT8 gastLQC_NormalStepList[19] =
{
//  	Num.		STEP				
/*0*/	LQC_FUNC_INIT,		
/*1*/	LQC_FUNC_WAIT,
/*2*/	LQC_FUNC_TUMBLE_CW,	
/*3*/	LQC_FUNC_LOW_RPM,	 
/*4*/	LQC_FUNC_FINAL_MODEM_CHK,//LQC_FUNC_HIGH_RPM,	
/*5*/	LQC_FUNC_PRE_VALVE,	
/*6*/	LQC_FUNC_COLD_VALVE,
/*7*/	LQC_FUNC_HOT_VALVE,	
/*8*/	LQC_FUNC_BLEACH_VALVE,
/*9*/	LQC_FUNC_DRY_VALVE,	
/*10*/	LQC_FUNC_STEAM_VALVE,
/*11*/	LQC_FUNC_TUMBLE_CCW,
/*12*/	LQC_FUNC_WASH_HEATER,
/*13*/	LQC_FUNC_CIR_PUMP,	
/*14*/	LQC_FUNC_DRAIN_PUMP,
/*15*/	LQC_FUNC_STEAM_SENSE,
/*16*/	LQC_FUNC_STEAM_HEATER,
/*17*/	LQC_FUNC_DRY,		
/*--*/	LQC_FUNC_END,		
};

UINT8 gast_OSP_CommState_List[18] =
{
	WI_STATE_POWEROFF,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL,
	WI_STATE_INITIAL
};


UINT8 gast_OSP_RecvKeyShift[255] =
{
	DISP_NO_KEY,
	DISP_NO_KEY,
	DISP_POWER_KEY,
	DISP_START_KEY,
};

typedef void(*const T_TYPE_FUNC_P)(UINT8*);

T_Time PstSendGapTime;

UINT8	ucRetKeyVal		= 0;
UINT8	ucKeydisable	= 0;
UINT8	mucReceiveSTX	= 0;
UINT8	mucKeyValue		= 0;
UINT8	mucKeyCount		= 0;
UINT8	mucProduceInfo	= 0;
UINT16	mucRecvDispCUM	= 0;

UINT8	mucRecvPackCNT	= 0;
UINT8	mucSendPackCNT	= 0;




UINT8	ShiftTopgunAmrStep	= 0;

UINT16	punOption[OptionInfo_MAX] = {0x00, 0x00, 0x00, 0x00, 0x00};



static UINT8 STX	  		= 0;
static UINT8 sucPC2JIG_ACK	= 0;

//************************************************************************************

#define DispPacket
void Comm_DispSetPacket_Normal(UINT8* pucSendBuffer, T_DispInfo* psDisplayInfo, UINT8 ucCommOper)
{
	if(psDisplayInfo->DispType == Vivace
		|| psDisplayInfo->DispType == Topgun_WW 
		|| psDisplayInfo->DispType == New_Topgun)
	{	
		if(API_SIO_RcvDataRead(WROS_UART_0) != 0)											//	Vivace and Titan need reset, //sense connecter wether insert,reset operation(STX 0 -> 2)
		{
			STX = mpstBufferInfo[ucCommOper].ucStx;
		}
		else
		{	;
		}
	}
	else
	{
		STX = mpstBufferInfo[ucCommOper].ucStx;
	}

	memset(pucSendBuffer, 0, SIZE_OF_ARRAY(pucSendBuffer));
	
	switch(psDisplayInfo->DispType)
	{	
		case Vivace:
			pucSendBuffer[0] = STX;
			pucSendBuffer[1] = gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];				//	Data size
			pucSendBuffer[12] = ACK;											//	NAK ACK
			pucSendBuffer[13] = (UINT8)(DOOR_CLOSE << 7|VVC_PanelType << 6|(psDisplayInfo->MainStatus == SET ? STATE_LQCTEST : SUB_STE_STANDBY)),//				//LQC mode
			pucSendBuffer[14] = ERROR_State;									//	De4	Errror
			pucSendBuffer[15] = psDisplayInfo->MainStatus;						//	Mainstate =1
			pucSendBuffer[17] = psDisplayInfo->BeepStatus;						//	Beeper
			pucSendBuffer[26] = psDisplayInfo->mucLogLqcStep;					//	LQC index 
			pucSendBuffer[29] = (SET << 6);										//	Send WD Model flag
			break;		

		case Topgun_WW:
			pucSendBuffer[0] = STX;
			pucSendBuffer[1] = gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];			//	Data size
			pucSendBuffer[3] = psDisplayInfo->MainStatus == 0 ? COMM_MODE_NORMAL : COMM_MODE_LQC_TEST;								//PacketMode											//LQC communication State
			pucSendBuffer[5] = ERROR_State;										//	De4	Errror
			pucSendBuffer[11] = psDisplayInfo->BeepStatus;						//	Beeper
			pucSendBuffer[29] = psDisplayInfo->MainStatus;						//	Main State
			pucSendBuffer[39] = 0x01; 											//	Variable Data Packet ID #define	PACKET_ID_TESTMIDE 1
			pucSendBuffer[40] = psDisplayInfo->mucLogLqcStep;					//	LQC index
			break;		

		case Mini:
			pucSendBuffer[0] = STX;
			pucSendBuffer[1] = gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];				//	Data size
			pucSendBuffer[5] = psDisplayInfo->MainStatus; 						//	Main State
			pucSendBuffer[29] = psDisplayInfo->mucLogLqcStep; 					//	LQC index
			pucSendBuffer[30] = psDisplayInfo->BeepStatus;						//	Beeper
			break;		

		case Topgun_Amr:
			pucSendBuffer[0] = STX;
			pucSendBuffer[1] = gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];			//	Data size
			pucSendBuffer[5] = ERROR_State;										//	De4	Errror
			pucSendBuffer[11] = psDisplayInfo->BeepStatus;						//	Beeper
			pucSendBuffer[29] = psDisplayInfo->MainStatus;						//	Main State
			pucSendBuffer[39] = 0x01; 											//	Variable Data Packet ID #define	PACKET_ID_TESTMIDE 1
			pucSendBuffer[40] = psDisplayInfo->mucLogLqcStep;					//	LQC index			
			pucSendBuffer[54] = gastLQC_NormalStepList[psDisplayInfo->mucLogLqcStep];
			break;		

		case Mega_Titan:
			pucSendBuffer[0] = gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];			//	Data size
			pucSendBuffer[1] = STX;
			pucSendBuffer[2] = ACK;												//	NAK ACK
			pucSendBuffer[3] = (UINT8)((psDisplayInfo->MainStatus * 0x40) | ERROR_State);		//LQC mode ERROR INFO
			pucSendBuffer[4] = psDisplayInfo->MainStatus;						//	Main State
			pucSendBuffer[7] = psDisplayInfo->BeepStatus;						//	Beeper
			pucSendBuffer[13] = 0xFF;											//	Motor RPM 255 display for LED check
			pucSendBuffer[16] = psDisplayInfo->mucLogLqcStep;					//	LQC index
			break;
			
		case New_Topgun:
			pucSendBuffer[0] = STX;
			pucSendBuffer[1] = gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];			//	Data size
			pucSendBuffer[5] = ERROR_State;										//	De4	Errror
			pucSendBuffer[10] = (4 << 4);										//	Beeper Volume //extra high
			pucSendBuffer[11] = psDisplayInfo->BeepStatus;						//	Beeper
			pucSendBuffer[29] = psDisplayInfo->MainStatus;						//	Main State
			pucSendBuffer[39] = 0x01; 											//	Variable Data Packet ID #define	PACKET_ID_TESTMIDE 1
			pucSendBuffer[40] = psDisplayInfo->mucLogLqcStep;					//	LQC index
			break;
			
		case LCD_VX_NT:
			pucSendBuffer[0] = STX;
			pucSendBuffer[1] = gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];			//	Data size
			pucSendBuffer[3] = DataReadWriteDataMemory(mucACK,READ,NULL);												//	NAK ACK
			pucSendBuffer[4] = gast_OSP_CommState_List[psDisplayInfo->MainStatus];	//	OSP Comm State
			pucSendBuffer[5] = psDisplayInfo->MainStatus;								//	Main State
			pucSendBuffer[6] = ERROR_State;										//	Error Info
			pucSendBuffer[21] = psDisplayInfo->BeepStatus;						//	BeepInfo
			pucSendBuffer[32] = DRAWING_CLOSE;
			pucSendBuffer[35] = SET;											//	KEY Receive Flag
			pucSendBuffer[59] = DataReadWriteDataMemory(mucKeyChkFlag,READ,NULL)|SET << 7;							//	Key|Draw Check
			pucSendBuffer[60] = psDisplayInfo->mucLogLqcStep;					//	LQC index
			break;
			
		case LCD_VXD_Dryer:
			pucSendBuffer[0] = STX;
			pucSendBuffer[1] = GET_HIGH_1BYTE(gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE]);	//	Data size
			pucSendBuffer[2] = GET_LOW_1BYTE(gauCommInfo[LCD_VXD_Dryer][SEND_DATA_SIZE]);	//	Data size
			pucSendBuffer[3] = CounterAddLimit(mucSendPackCNT, 0, 255);
			pucSendBuffer[4] = DataReadWriteDataMemory(mucACK,READ,NULL);
			pucSendBuffer[5] = psDisplayInfo->MainStatus;
			pucSendBuffer[7] = SET;												//	Delay End State
			pucSendBuffer[16] = psDisplayInfo->BeepStatus;						//	BeepInfo
			break;
			
		case GVX_CVX:
			pucSendBuffer[0] = STX;
			pucSendBuffer[1] = gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];			//	Data size
			pucSendBuffer[12] = ACK;											//	NAK ACK
			pucSendBuffer[13] = (UINT8)(DOOR_CLOSE << 7|VVC_PanelType << 6|(psDisplayInfo->MainStatus == SET ? STATE_LQCTEST : SUB_STE_STANDBY)),//				//LQC mode
			pucSendBuffer[14] = ERROR_State;									//	De4	Errror
			pucSendBuffer[15] = psDisplayInfo->MainStatus;						//	Mainstate =1
			pucSendBuffer[17] = psDisplayInfo->BeepStatus;						//	Beeper
			pucSendBuffer[26] = psDisplayInfo->mucLogLqcStep;					//	LQC index 
			pucSendBuffer[29] = (SET << 6);										//	Send WD Model flag
			pucSendBuffer[39] = ((psDisplayInfo->MainStatus != 0) << 2);		//	Drum Light on as long as power on
			pucSendBuffer[51] = 0x04;											//	set Buzzer Volume high
			break;		
						
		case GVX_CVX_Dryer:
			pucSendBuffer[0] = STX;
			pucSendBuffer[1] = gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];		//	Data size
			pucSendBuffer[5] = 0;												//	PACKET_MODE, 0: normal packet
			pucSendBuffer[6] = psDisplayInfo->MainStatus;						//	Mainstate =1
			pucSendBuffer[21] = psDisplayInfo->BeepStatus;						//	Beeper name
			pucSendBuffer[22] = 2;												//	Beeper Level	1: Low	2: Mid	3: High
			pucSendBuffer[24] = (psDisplayInfo->MainStatus == CLEAR ? 0 : 0x10);//	Door Locked
			pucSendBuffer[36] = 1;												//	0: Sub 1,		1: Sub 2,	2: Sub 3,		Sub 2 for test index
			pucSendBuffer[37] = 0;												//	0: Normal LQC
			pucSendBuffer[38] = psDisplayInfo->mucLogLqcStep;					//	LQC index 
			break;	

		case New_Mini:
			pucSendBuffer[0] = STX;
			pucSendBuffer[1] = gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];					//	Data size
			pucSendBuffer[5] = psDisplayInfo->MainStatus; 							//	Main State
			pucSendBuffer[11] = (4 << 4);
			pucSendBuffer[27] = psDisplayInfo->mucLogLqcStep; 						//	LQC index
			pucSendBuffer[28] = psDisplayInfo->BeepStatus;							//	Beeper
			break;		
			
		case JigUpdate:
		default:
			pucSendBuffer[0] = STX;
			pucSendBuffer[1] = gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];	//	Data size
			pucSendBuffer[2] = JigUpdate;
			pucSendBuffer[3] = 0xAA;
			pucSendBuffer[4] = 0x55;
			break;
	}
}

void Comm_DispRecvPacket_Normal(UINT8 ucDispType, UINT8* PaucRecvBuffer)
{	
	switch(ucDispType)
	{
		case Vivace:
			mucReceiveSTX = PaucRecvBuffer[0];
			mucKeyValue = PaucRecvBuffer[3];
			mucKeyCount = PaucRecvBuffer[4];
			DataReadWriteDataMemory(mucPanelType,WRITE,PaucRecvBuffer[6] >> 5);
			DataReadWriteDataMemory(mucDoorState,WRITE,PaucRecvBuffer[14]);
			DataReadWriteDataMemory(mucWifiState,WRITE,PaucRecvBuffer[15]);
			
			punOption[Real_Option] = ((UINT16)PaucRecvBuffer[8] << 8\
											| PaucRecvBuffer[9]);
			Comm_SetKeyValue_1(mucKeyValue,mucKeyCount);
			break;		

		case Topgun_WW:
		case New_Topgun:
			mucReceiveSTX = PaucRecvBuffer[0];
			mucKeyValue = PaucRecvBuffer[2];
			mucKeyCount = PaucRecvBuffer[3];
			DataReadWriteDataMemory(mucDoorState,WRITE,((PaucRecvBuffer[5] >> 1) & 0x03));					//	only for New topgun
			
			Comm_SetKeyValue_3(mucKeyValue,mucKeyCount);
			break;
			
		case Topgun_Amr:
			mucReceiveSTX = PaucRecvBuffer[0];
			mucKeyValue = PaucRecvBuffer[2];
			mucKeyCount = PaucRecvBuffer[3];

			Comm_SetKeyValue_1(mucKeyValue,mucKeyCount);
			break;

		case Mini:
			mucReceiveSTX = PaucRecvBuffer[0];
			mucKeyValue = PaucRecvBuffer[2];
			mucKeyCount = PaucRecvBuffer[3];
			
			Comm_SetKeyValue_2(mucKeyValue,mucKeyCount);
			break;		

		case Mega_Titan:
			mucReceiveSTX = PaucRecvBuffer[0];
			mucKeyValue = PaucRecvBuffer[3];
			mucKeyCount = PaucRecvBuffer[4];
			
			Comm_SetKeyValue_1(mucKeyValue,mucKeyCount);
			break;
			
		case LCD_VX_NT:
			mucReceiveSTX = PaucRecvBuffer[0];
			mucKeyValue = PaucRecvBuffer[4];
			mucKeyCount = PaucRecvBuffer[5];
			DataReadWriteDataMemory(mucDoorState,WRITE,(PaucRecvBuffer[10] >> 4));
			DataReadWriteDataMemory(mucWifiState,WRITE,PaucRecvBuffer[25]);
			
			Comm_SetKeyValue_1(gast_OSP_RecvKeyShift[mucKeyValue],mucKeyCount);
			break;
			
		case LCD_VXD_Dryer:
			mucReceiveSTX = PaucRecvBuffer[0];
			mucKeyValue = PaucRecvBuffer[6];
			mucKeyCount = PaucRecvBuffer[7];
			DataReadWriteDataMemory(mucWifiState,WRITE,PaucRecvBuffer[25]);
			
			Comm_SetKeyValue_2(mucKeyValue,mucKeyCount);
			break;
			
		case GVX_CVX:
			mucReceiveSTX = PaucRecvBuffer[0];
			mucKeyValue = PaucRecvBuffer[3];
			mucKeyCount = PaucRecvBuffer[4];
			DataReadWriteDataMemory(mucPanelType,WRITE,PaucRecvBuffer[6] >> 5);
			DataReadWriteDataMemory(mucDoorState,WRITE,PaucRecvBuffer[14]);
			DataReadWriteDataMemory(mucWifiState,WRITE,PaucRecvBuffer[15]);
			
			punOption[Real_Option] = ((UINT16)PaucRecvBuffer[8] << 8\
											| PaucRecvBuffer[9]);
			Comm_SetKeyValue_1(mucKeyValue,mucKeyCount);
			break;	
			
		case GVX_CVX_Dryer:
			mucReceiveSTX = PaucRecvBuffer[0];
			mucKeyValue = PaucRecvBuffer[6];
			mucKeyCount = PaucRecvBuffer[7];
			DataReadWriteDataMemory(mucPanelType,WRITE,PaucRecvBuffer[6] >> 5);
			DataReadWriteDataMemory(mucDoorState,WRITE,PaucRecvBuffer[14]);
			DataReadWriteDataMemory(mucWifiState,WRITE,PaucRecvBuffer[15]);
			
			punOption[Real_Option] = ((UINT16)PaucRecvBuffer[8] << 8\
											| PaucRecvBuffer[9]);
			Comm_SetKeyValue_1(mucKeyValue,mucKeyCount);
			break;		

		case New_Mini:
			mucReceiveSTX = PaucRecvBuffer[0];
			mucKeyCount = PaucRecvBuffer[2];
			mucKeyValue = PaucRecvBuffer[4];
			
			Comm_SetKeyValue_2(mucKeyValue,mucKeyCount);
			break;		

		default:
			DownloaderCheck(PaucRecvBuffer);
			break;
	}
	//memset(PaucRecvBuffer, 0, SIZE_OF_ARRAY(PaucRecvBuffer));
}

#define OPPacket
void Comm_OptionSetPacket_Normal(UINT8* pucSendBuffer, T_DispInfo*	 psDisplayInfo, UINT8 ucCommOper)
{
	pucSendBuffer[0] = mpstBufferInfo[ucCommOper].ucStx;
	pucSendBuffer[1] = gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];			//	Data size
	pucSendBuffer[3] = 'F';
	pucSendBuffer[4] = 'C';
	pucSendBuffer[5] = 'T';
	pucSendBuffer[6] = gunOpWriteFlag;
	pucSendBuffer[7] = (UINT8)(punOption[FCT_Send_OP] >> 8);
	pucSendBuffer[8] = (UINT8)(punOption[FCT_Send_OP] & 0xFF);
	pucSendBuffer[20] = 0x06;

}

void Comm_OptionRecvPacket_Normal(UINT8 ucDispType, UINT8* PaucRecvBuffer)
{
//	mucReceiveSTX = PaucRecvBuffer[0];
//	mucReceiveSize = PaucRecvBuffer[1];
	punOption[FCT_Recv_OP] = ((UINT16)PaucRecvBuffer[7] << 8\
									| PaucRecvBuffer[8]);
	
	mucRecvDispCUM = ((UINT16)PaucRecvBuffer[13] << 8\
									| PaucRecvBuffer[14]);
}

#define PCPacket

void Comm_PCSetPacket_Normal(UINT8* pucSendBuffer, T_DispInfo* psDisplayInfo, UINT8 ucCommOper)
{
	pucSendBuffer[0] = mpstBufferInfo[ucCommOper].ucStx;
	pucSendBuffer[1] = gauCommInfo[psDisplayInfo->DispType][SEND_DATA_SIZE];
	pucSendBuffer[2] = CounterAddLimit(mucSendPackCNT, 0, 255);
	pucSendBuffer[3] = 'F';
	pucSendBuffer[4] = 'C';
	pucSendBuffer[5] = 'T';
	
	pucSendBuffer[6] = mucProduceInfo;														//	PC send Update	0x00: No PC send	0x01: Lot No.1		0x10: A Lot
	pucSendBuffer[7] = (mucProduceInfo == 0x01 ? 0x00 : ++mucProduceInfo);					//	Lot PCB Counter	0~255
	pucSendBuffer[8] = (punOption[Real_Option] == punOption[PC_Recv_OP] ? 0x01 : 0x00);	//	Judgment		0x00: In judgment	0x01: judgment OK	0x02: CHK NG	0x03: ROM no have OP Info
	pucSendBuffer[9] = (Door_SEN_SIGNAL == SET ? SET : CLEAR);																	// 	JIG ready

	pucSendBuffer[20] = (sucPC2JIG_ACK == SET ? 0x06 : 0x15);								//	JIG2PC_ACK	if PC send, reply ACK 0x06, if not reply 0x15 
	(pucSendBuffer[20] == 0x06 ? sucPC2JIG_ACK = CLEAR : CLEAR);								//	Clear ACK, wait for next PC send
	
	pucSendBuffer[21] = (UINT8)(punOption[Real_Option] >> 8);
	pucSendBuffer[22] = (UINT8)(punOption[Real_Option] & 0xFF);

	pucSendBuffer[45] = (UINT8)(mucRecvDispCUM >> 8);
	pucSendBuffer[46] = (UINT8)(mucRecvDispCUM & 0xFF);
	pucSendBuffer[47] = mpstBufferInfo[ucCommOper].ucEtx;

}
void Comm_PCRecvPacket_Normal(UINT8 ucDispType, UINT8* PaucRecvBuffer)
{
//	mucReceiveSTX = PaucRecvBuffer[0];
//	mucReceiveSize = PaucRecvBuffer[1];
	mucRecvPackCNT =  PaucRecvBuffer[2];
	mucProduceInfo =  PaucRecvBuffer[6];
	punOption[PC_Recv_OP] = ((UINT16)PaucRecvBuffer[8] << 8 | PaucRecvBuffer[9]);
	Comm_SetPCOption(mucRecvPackCNT);
}

UINT16 Uart_CRCMaker(UINT8* pucBuffer, UINT8 ucLength)
{	UINT8 uci = 0;
	UINT16 unCrc = 0;
	UINT16 unTemp = 0;
	UINT16 unQuick = 0;

	for(uci = 0 ; uci < ucLength ; uci++)
	{	unTemp = (unCrc >> 8) ^ *pucBuffer++;
		unCrc <<= 8;
		unQuick = unTemp ^ (unTemp >> 4);
		unCrc ^= unQuick;
		unQuick <<= 5;
		unCrc ^= unQuick;
		unQuick <<= 7;
		unCrc ^= unQuick;
	}

	return (unCrc);
}

void Uart_CrcPacketEncode(UINT8* pucPacket, UINT8 ucPktSize, UINT8 ucEtx)
{
	UINT16 unCrcValue = 0;
		
	unCrcValue = Uart_CRCMaker(pucPacket, (UINT8)(ucPktSize - 3));
	pucPacket[ucPktSize - 3] = (UINT8)((unCrcValue & 0xFF00) >> 8);
	pucPacket[ucPktSize - 2] = (UINT8)(unCrcValue & 0x00FF);
	pucPacket[ucPktSize - 1] = ucEtx;
}

UINT8 Uart_CrcPacketCheck(T_DispInfo* psDisplayInfo, UINT8* pucPacket)
{	
	UINT8 ucCrcCheckResult = RETURN_NG;
	
	psDisplayInfo->UartInfo.UartDateCRC = (pucPacket[psDisplayInfo->UartInfo.UartRx_PktSize - 2] << 8 | pucPacket[psDisplayInfo->UartInfo.UartRx_PktSize - 3] & 0xFF);
	psDisplayInfo->UartInfo.UartRealCRC = Uart_CRCMaker(pucPacket, (UINT8)(psDisplayInfo->UartInfo.UartRx_PktSize - 3));

	if(psDisplayInfo->UartInfo.UartDateCRC == psDisplayInfo->UartInfo.UartRealCRC)
	{
		ucCrcCheckResult = RETURN_OK;
		psDisplayInfo->PlatCheckStep = PlatChk_Finish;
	}
	else
	{
		psDisplayInfo->UartInfo.UartDateCRC = (pucPacket[psDisplayInfo->UartInfo.UartRx_PktSize - 3] << 8 | pucPacket[psDisplayInfo->UartInfo.UartRx_PktSize - 2] & 0xFF);
		psDisplayInfo->UartInfo.UartRealCRC = Uart_CRCMaker(pucPacket, (UINT8)(psDisplayInfo->UartInfo.UartRx_PktSize - 3));

		if(psDisplayInfo->UartInfo.UartDateCRC == psDisplayInfo->UartInfo.UartRealCRC)
		{
			ucCrcCheckResult = RETURN_OK;
			psDisplayInfo->PlatCheckStep = PlatChk_Finish;
		}
		else
		{
			ucCrcCheckResult = RETURN_NG;
			psDisplayInfo->PlatCheckStep = PlatChk_Request;
		}
	}

	return ucCrcCheckResult;
}

void Comm_SetKeyValue_1(UINT8 ucKeyValue,UINT8 ucKeyCount)
{		
	static UINT8	KeyCountBefore = 0;
	
	if(ucKeydisable == CLEAR)
	{
		ucKeydisable = SET;
		
		if(ucKeyCount != KeyCountBefore)
		{
			if(ucKeyValue == 0x65)
			{
				ucKeydisable = CLEAR;
				return;
			}
			else
			{;
			}
			KeyCountBefore = ucKeyCount;
			ucRetKeyVal = ucKeyValue;
		}
		else
		{	;
		}
	}	
	else
	{	;
	}
}

void Comm_SetKeyValue_2(UINT8 ucKeyValue, UINT8 ucKeyCount)
{	
	static UINT8	KeyCountBefore = 0;
	
	if(ucKeydisable == CLEAR)
	{
		if((ucKeyValue == DISP_POWER_KEY || ucKeyValue == DISP_START_KEY) && ucKeyCount != KeyCountBefore)
		{
			ucKeydisable = SET;
			KeyCountBefore = ucKeyCount;
			ucRetKeyVal = ucKeyValue;
		}
		else
		{
			ucRetKeyVal = NO_KEY;
		}
	}
	else
	{	;
	}
}

void Comm_SetKeyValue_3(UINT8 ucKeyValue,UINT8 ucKeyCount)
{	
	static UINT8	KeyCountBefore = 0;
	
	if(ucKeyCount == 0)															//in the begining, beforekey set 0
	{	
		KeyCountBefore = CLEAR;
	}
	else if(ucKeyCount != 0 && KeyCountBefore == 0)								//beforekey can't be clear to 0, in check keeping
	{
		KeyCountBefore = ucKeyCount - 1;
	}
	else if((ucKeyCount - KeyCountBefore) > 1 || KeyCountBefore > ucKeyCount)	//beforekey can't lower than receive key more 2,and beforekey can't be set to bigger than receive key
	{
		KeyCountBefore = ucKeyCount - 1;
	}
	else
	{	;
	}
	
	if(ucKeydisable == CLEAR)
	{
		if((ucKeyCount == KeyCountBefore + 1) && ucKeyValue != NO_KEY)
		{
			ucKeydisable = SET;
			KeyCountBefore++;
			ucRetKeyVal = ucKeyValue;
		}
		else
		{
			ucRetKeyVal = NO_KEY;
		}
	}	
	else
	{	;
	}
}

void SET_STX(UINT8 ucSTX)
{
	STX = ucSTX;
}

void Comm_SetPCOption(UINT8 ucRecvPackCNT)
{	
	static UINT8	PCRecvPackCNTBefore = 0;
	
	if(ucRecvPackCNT != PCRecvPackCNTBefore)
	{
		PCRecvPackCNTBefore = ucRecvPackCNT;
		sucPC2JIG_ACK = SET;
		gunOpWriteFlag = SET;
	}
	else
	{	;
	}
}

UINT16* Get_OPTION()
{
	return punOption;
}

UINT8 Comm_GetKeyValue()
{
	if(ucRetKeyVal != NO_KEY)
	{
		if(Timer_MsecCheckPassTime(&PstSendGapTime, 100) == SET)
		{
			return ucRetKeyVal;
		}
		else
		{	;
		}
	}
	else
	{	;
	}
	
    return NO_KEY;
}

UINT8 Comm_GetKeyCount()
{	
    return mucKeyCount;
}


void ClearKeyValue(void)
{
	ucRetKeyVal = CLEAR;
	ucKeydisable = CLEAR;
}

UINT8 DataReadWriteDataMemory(UINT8 ucIdx, UINT8 ucReadWrite, UINT8 ucDataReq)
{
	static UINT16 sucDataMemory[mucDataMemoryMax] = {0,};

	if(ucIdx >= mucDataMemoryMax)
	{
		return RETURN_NG;
	}
	else if(ucReadWrite == WRITE)
	{
		sucDataMemory[ucIdx] = ((UINT16)(ucDataReq << 8) | ucDataReq);
		return RETURN_OK;
	}
	else if(ucReadWrite == READ)
	{
		if((UINT8)(sucDataMemory[ucIdx] >> 8) == (UINT8)(sucDataMemory[ucIdx] & 0xFF))
		{
			return (UINT8)(sucDataMemory[ucIdx] & 0xFF);
		}
		else
		{
			return RETURN_NG;
		}
	}
	else
	{
		return RETURN_NG;	
	}
}

