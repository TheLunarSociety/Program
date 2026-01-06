


#include "../../1.Application/Include/APP_WorkingNormalState.h"

#define __LQCPROCESS__
#include "../../2.Component/Include/Cmp_LQC_Process.h"
#undef __LQCPROCESS__

#include "../../2.Component/Include/Cmp_KeyScan.h"
#include "../../2.Component/Include/Cmp_SetError.h"
#include "../../2.Component/Include/Cmp_Onboarding.h"

#include "../../3.Library/Include/Int.h"
#include "../../3.Library/Include/Lib_UartComm.h"
#include "../../3.Library/Include/Lib_CommSubMicom.h"
#include "../../3.Library/Include/Lib_EEPROM.h"

#include "../../6.VariableSource/Include/Vable_ModelInformation.h"

extern const UINT8 gaucBeeperInfo[PlaformMax][BeeperInformMax];
extern const UINT8 gauCommInfo[PlaformMax][CommInformMax];
extern const UINT8 gauProductModeInfo[PlaformMax][Mode_MAX];
extern const UINT8 gauLqcStepInfo[PlaformMax][STEP_MAX];

#define	DelayTime	2

static UINT8 sucLQC_Index = 0;
static UINT8 sucLQC_SkipF = 0;

T_Time	InitGapTime;

// Skip Function i set "if" function		// Power on is "Version check" Step, not set in mapfnNormalLqcStepTbl

static void (* const mapfnNormalLqcStepTbl[])(T_DispInfo*) =
{
	LQC_CHECKSUM_CheckStep,		// 0
	LQC_1888_CheckStep,			// 1
	LQC_LED_CheckStep,			// 2
	LQC_WIFI_CheckStep,			// 3
	LQC_Normal_FinalStep,		// 4
};

void WROS_FUNC_LQC_ModeProcess(T_DispInfo* psDisplayInfo)
{
	while(1)
	{
		MAKE_TEST_POINT(LQC_PROCESS_FLAG);
		Cmp_LQC_ModeProcess(psDisplayInfo);
	}
}

void Cmp_LQC_ModeProcess(T_DispInfo* psDisplayInfo)
{
	Init_LQCTestModeProcess(psDisplayInfo);											//After power off,delay 2s reset beeper
	
	if(sucLQC_SkipF)
	{
	  	sucLQC_SkipF = CLEAR;
		TestControlStep_LQC_Normal(sucLQC_Index,psDisplayInfo);
	}
	else
	{
		switch(Comm_GetKeyValue())
		{	
			case DISP_NO_KEY:
				ClearKeyValue();
				break;		
			
			case DISP_POWER_KEY:
				ClearKeyValue();
				if(ERROR_State == NO_ERROR)
				{
					LQC_Display_POWER_ON_OFF(psDisplayInfo);
				}
				else
				{	;
				}
				break;
				
			case DISP_START_KEY:
				ClearKeyValue();
				if(psDisplayInfo->MainStatus != CLEAR && ERROR_State == NO_ERROR)
				{
					TestControlStep_LQC_Normal(sucLQC_Index,psDisplayInfo);
				}
				else
				{
					;
				}
				break;
			
			default:
				ClearKeyValue();
				if(psDisplayInfo->MainStatus != CLEAR && ERROR_State == NO_ERROR)						//except power & start, other key will make beeper
				{
					OptionKeyInBeep(psDisplayInfo);
				}
				else
				{	;
				}
				break;

		}	
	}
}

void Init_LQCTestModeProcess(T_DispInfo* psDisplayInfo)
{	
	if(psDisplayInfo->MainStatus == OFF)// && Comm_GetKeyCount() == CLEAR)
	{
		psDisplayInfo->mucLogLqcStep	=	CLEAR;
		DataReadWriteDataMemory(mucBeeperCounter, WRITE, CLEAR);
		
		if(Timer_MsecCheckPassTime(&InitGapTime, (DelayTime * 1000)) == SET)
		{
			psDisplayInfo->BeepStatus = gaucBeeperInfo[psDisplayInfo->DispType][Beep_DUMMY];
		}
		else
		{	;
		}
	}
	else
	{	Timer_GetTime(&InitGapTime);
	}
}

void TestControlStep_LQC_Normal(UINT8 ucLQCIndex,T_DispInfo* psDisplayInfo)
{
	if( 0 < (sizeof(mapfnNormalLqcStepTbl) / sizeof(void *)) )//&& Get_JigPlatform() != Mini)
	{	
		mapfnNormalLqcStepTbl[ucLQCIndex](psDisplayInfo);
	}
	else
	{	;
	}
}

void OptionKeyInBeep(T_DispInfo* psDisplayInfo)
{
	if(psDisplayInfo->MainStatus != OFF)
	{
		GetBeeperCounter(psDisplayInfo, DataReadWriteDataMemory(mucBeeperCounter, READ, NA));

		psDisplayInfo->BeepStatus = ((gaucBeeperInfo[psDisplayInfo->DispType][Beep_HeadOnOff])\
									|(gaucBeeperInfo[psDisplayInfo->DispType][Beep_Counter] & DataReadWriteDataMemory(mucBeeperCounter, READ, NA))\
									|(gaucBeeperInfo[psDisplayInfo->DispType][Beep_KEY_IN]));
	}
	else
	{	;
	}
}

void LQC_Display_POWER_ON_OFF(T_DispInfo* psDisplayInfo)
{
	if(psDisplayInfo->MainStatus == OFF)	//	Power On
	{
		ErrorCheckFlag = SET;
		if(gauLqcStepInfo[psDisplayInfo->DispType][VERSION_STEP] == NA)
		{
			LQC_CHECKSUM_CheckStep(psDisplayInfo);											//skip version check
		}
		else
		{
			psDisplayInfo->MainStatus = gauProductModeInfo[psDisplayInfo->DispType][PLQC_Mode];
			
			GetBeeperCounter(psDisplayInfo,DataReadWriteDataMemory(mucBeeperCounter, READ, NA));
			psDisplayInfo->mucLogLqcStep = gauLqcStepInfo[psDisplayInfo->DispType][(Onboarding_ModelFlag == SET ? KEY_CHK_STEP : VERSION_STEP)];
			psDisplayInfo->BeepStatus = ((gaucBeeperInfo[psDisplayInfo->DispType][Beep_HeadOnOff])\
										|(gaucBeeperInfo[psDisplayInfo->DispType][Beep_Counter] & DataReadWriteDataMemory(mucBeeperCounter, READ, NA))\
										|(gaucBeeperInfo[psDisplayInfo->DispType][Beep_Power_ON]));
		}
	}
	else					//	Power OFF
	{
		psDisplayInfo->MainStatus = CLEAR;
		
		GetBeeperCounter(psDisplayInfo, DataReadWriteDataMemory(mucBeeperCounter, READ, NA));
		psDisplayInfo->mucLogLqcStep = CLEAR;
		psDisplayInfo->BeepStatus = ((gaucBeeperInfo[psDisplayInfo->DispType][Beep_HeadOnOff])\
									|(gaucBeeperInfo[psDisplayInfo->DispType][Beep_Counter] & DataReadWriteDataMemory(mucBeeperCounter, READ, NA))\
									|(gaucBeeperInfo[psDisplayInfo->DispType][Beep_Power_OFF]));
					
		/*
		while(STANDBY_SIGNAL)
		{	;
		}
		*/
		sucLQC_Index = CLEAR;
		STANDBY_SIGNAL_Flag = CLEAR;
		gunOpWriteFlag = CLEAR;
		DataReadWriteDataMemory(mucKeyChkFlag, WRITE, CLEAR);
		SET_STX(CLEAR);
	}
}

void LQC_CHECKSUM_CheckStep(T_DispInfo* psDisplayInfo)
{
	if(gauLqcStepInfo[psDisplayInfo->DispType][CHECKSUM_STEP]== NA)
	{
		sucLQC_SkipF = SET;
	}
	else
	{
		psDisplayInfo->MainStatus = gauProductModeInfo[psDisplayInfo->DispType][CS_Mode];
	}
	
	sucLQC_Index++;
}

void LQC_1888_CheckStep(T_DispInfo* psDisplayInfo)
{
	if(gauLqcStepInfo[psDisplayInfo->DispType][LED_1888_STEP]== NA)
	{
		sucLQC_SkipF = SET;
	}
	else
	{
		psDisplayInfo->MainStatus = gauProductModeInfo[psDisplayInfo->DispType][PLQC_Mode];
		psDisplayInfo->mucLogLqcStep = gauLqcStepInfo[psDisplayInfo->DispType][LED_1888_STEP];

		GetBeeperCounter(psDisplayInfo, DataReadWriteDataMemory(mucBeeperCounter, READ, NA));
		psDisplayInfo->BeepStatus = ((gaucBeeperInfo[psDisplayInfo->DispType][Beep_HeadOnOff])\
									|(gaucBeeperInfo[psDisplayInfo->DispType][Beep_Counter] & DataReadWriteDataMemory(mucBeeperCounter, READ, NA))\
									|(gaucBeeperInfo[psDisplayInfo->DispType][Beep_KEY_IN]));
	}
	
	sucLQC_Index++;
}

void LQC_LED_CheckStep(T_DispInfo* psDisplayInfo)
{
	if(gauLqcStepInfo[psDisplayInfo->DispType][KEY_CHK_STEP]== NA)
	{
		sucLQC_SkipF = SET;
	}
	else
	{
		
		psDisplayInfo->MainStatus = gauProductModeInfo[psDisplayInfo->DispType][PLQC_Mode];
		psDisplayInfo->mucLogLqcStep = gauLqcStepInfo[psDisplayInfo->DispType][(Onboarding_ModelFlag == SET ? VERSION_STEP : KEY_CHK_STEP)];

		GetBeeperCounter(psDisplayInfo, DataReadWriteDataMemory(mucBeeperCounter, READ, NA));
		psDisplayInfo->BeepStatus = ((gaucBeeperInfo[psDisplayInfo->DispType][Beep_HeadOnOff])\
									|(gaucBeeperInfo[psDisplayInfo->DispType][Beep_Counter] & DataReadWriteDataMemory(mucBeeperCounter, READ, NA))\
									|(gaucBeeperInfo[psDisplayInfo->DispType][Beep_KEY_IN]));
	}
	
	
	DataReadWriteDataMemory(mucKeyChkFlag, WRITE, SET)	;		//	Only LCD model use this
	sucLQC_Index++;
}

void LQC_WIFI_CheckStep(T_DispInfo* psDisplayInfo)
{	
	if(gauLqcStepInfo[psDisplayInfo->DispType][WIFI_STEP] == NA)
	{
		sucLQC_SkipF = SET;
	}
	else
	{
		psDisplayInfo->MainStatus = gauProductModeInfo[psDisplayInfo->DispType][Other_Mode];	//	Dryer WIFI Check
		psDisplayInfo->mucLogLqcStep = gauLqcStepInfo[psDisplayInfo->DispType][WIFI_STEP];

		GetBeeperCounter(psDisplayInfo, DataReadWriteDataMemory(mucBeeperCounter, READ, NA));
		psDisplayInfo->BeepStatus = ((gaucBeeperInfo[psDisplayInfo->DispType][Beep_HeadOnOff])\
									|(gaucBeeperInfo[psDisplayInfo->DispType][Beep_Counter] & DataReadWriteDataMemory(mucBeeperCounter, READ, NA))\
									|(gaucBeeperInfo[psDisplayInfo->DispType][Beep_KEY_IN]));
	}

	sucLQC_Index++;
}	

void LQC_Normal_FinalStep(T_DispInfo* psDisplayInfo)
{
	if(gauLqcStepInfo[psDisplayInfo->DispType][Final_STEP] != NA)
	{
		if((DataReadWriteDataMemory(mucWifiState, READ, NA) & SET) == SET)
		{
			LQC_Display_POWER_ON_OFF(psDisplayInfo);
		}
		else
		{	;
		}
	}
	else
	{
		LQC_Display_POWER_ON_OFF(psDisplayInfo);
	}
}

void GetBeeperCounter(T_DispInfo* psDisplayInfo, UINT8 ucBeeperCounter)
{
	UINT8 ucNewBeeperCount;
		
	switch(gaucBeeperInfo[psDisplayInfo->DispType][Beep_Counter])
	{
		default:
		case 0xC0:
			ucNewBeeperCount = ucBeeperCounter + 0x40;

			if(ucNewBeeperCount > 0xC0)
			{	DataReadWriteDataMemory(mucBeeperCounter, WRITE, 0);
			}
			else
			{	DataReadWriteDataMemory(mucBeeperCounter, WRITE, ucNewBeeperCount);
			}
			break;
			 
		case 0x60:
			ucNewBeeperCount =	ucBeeperCounter + 0x20;

			if(ucNewBeeperCount > 0x60)
			{	DataReadWriteDataMemory(mucBeeperCounter, WRITE, 0);
			}
			else
			{	DataReadWriteDataMemory(mucBeeperCounter, WRITE, ucNewBeeperCount);
			}
			break;
	}

}

