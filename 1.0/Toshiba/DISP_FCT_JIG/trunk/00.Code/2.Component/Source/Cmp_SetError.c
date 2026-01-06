

#include <stdlib.h>
#include <string.h>

#include "../../1.Application/Include/APP_WorkingNormalState.h"

#define __SETERROR_H__
#include "../../2.Component/Include/Cmp_SetError.h"
#undef __SETERROR_H__

#include "../../2.Component/Include/Cmp_LQC_Process.h"
#include "../../2.Component/Include/Cmp_KeyScan.h"
#include "../../3.Library/Include/Int.h"
#include "../../3.Library/Include/Lib_UartComm.h"
#include "../../3.Library/Include/Lib_CommSubMicom.h"
#include "../../3.Library/Include/Lib_EEPROM.h"

#include "../../6.VariableSource/Include/Vable_ModelInformation.h"


T_Time	SetErrorGapTime;
extern const UINT8 gaucBeeperInfo[PlaformMax][BeeperInformMax];

void Cmp_ErrorSet(T_DispInfo*);

void WROS_FUNC_Error_Check(T_DispInfo* psDisplayInfo)
{	
	while(1)
	{
		MAKE_TEST_POINT(ERROR_CHECK_FLAG);
		Cmp_Error_Check(psDisplayInfo);
	}
}

void Cmp_Error_Check(T_DispInfo* psDisplayInfo)
{	
	for(
#ifdef	No_ErrorMode
		T_ERROR_STEP ErrChk_STEP = ERROR_MAX;
#else				 
		T_ERROR_STEP ErrChk_STEP = SE_ERROR_STEP;
#endif
		ErrChk_STEP < ERROR_MAX; ErrChk_STEP++)									//Power off, keeping check
	{
		if(ErrorCheck[ErrChk_STEP](psDisplayInfo->DispType))
		{
			break;
		}
		else
		{	;
		}
	}
	
	Cmp_ErrorSet(psDisplayInfo);
}

UINT8 StandByErrorCheck(UINT8 ucDispType)
{
	if(ucDispType != JigUpdate)
	{
		if(STANDBY_SIGNAL_Flag == SET)
		{
			PRE_ERROR = NO_ERROR;
		}
		else
		{
			PRE_ERROR = SE_ERROR;
			return ERROR;
		}		
	}
	else
	{	;
	}
	
	return NO_ERROR;
}

UINT8 DE4ErrorCheck(UINT8 ucDispType)
{
	switch(ucDispType)
	{
		case Vivace:
			if(DataReadWriteDataMemory(mucPanelType, READ, NA) != VBF_PanelType)
			{
				if(DataReadWriteDataMemory(mucDoorState, READ, NA) == DOOR_CLOSE)
				{
					PRE_ERROR = NO_ERROR;
				}
				else
				{
					PRE_ERROR = VVC_DE4_ERROR;
					return ERROR;
				}
			}
			else
			{
				if(Door_SEN_SIGNAL_Flag == 1)
				{
					PRE_ERROR = NO_ERROR;
				}
				else
				{
					PRE_ERROR = VVC_DE4_ERROR;
					return ERROR;
				}
			}
			break;
		
		case Topgun_WW:
		case Topgun_Amr:
			if(Door_SEN_SIGNAL_Flag == 1)
			{
				PRE_ERROR = NO_ERROR;
			}
			else
			{
				PRE_ERROR = Topgun_DE4_ERROR;
				return ERROR;
			}
			break;

		case New_Topgun:
			if(DataReadWriteDataMemory(mucDoorState, READ, NA) == NT_DOOR_CLOSE)
			{
				PRE_ERROR = NO_ERROR;
			}
			else
			{
				PRE_ERROR = Topgun_DE4_ERROR;
				return ERROR;
			}
			break;
			
		case LCD_VX_NT:
		case LCD_VXD_Dryer:

			break;

		default:
			break;
	}
	
	return NO_ERROR;
}

void Cmp_ErrorSet(T_DispInfo* psDisplayInfo)
{
	if(ErrorCheckFlag == SET)
	{
		if(Timer_MsecCheckPassTime(&SetErrorGapTime, 100) == SET)
		{
			ErrorCheckFlag = CLEAR;
			
			if(PRE_ERROR == NO_ERROR)
			{
				;
			}
			else
			{
				psDisplayInfo->MainStatus = CLEAR;
				ERROR_State = PRE_ERROR;

				GetBeeperCounter(psDisplayInfo, DataReadWriteDataMemory(mucWifiState, READ, NA));
				psDisplayInfo->BeepStatus = ((gaucBeeperInfo[psDisplayInfo->DispType][Beep_HeadOnOff]\
											|(gaucBeeperInfo[psDisplayInfo->DispType][Beep_Counter] & DataReadWriteDataMemory(mucBeeperCounter, READ, NA))\
											|(gaucBeeperInfo[psDisplayInfo->DispType][Beep_DUMMY])));
				
			}
		}
		else
		{
			Timer_GetTime(&SetErrorGapTime);
		}
	}
	else
	{	;
	}
}



