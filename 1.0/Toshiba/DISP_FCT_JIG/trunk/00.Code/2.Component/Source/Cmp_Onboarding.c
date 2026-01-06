#include <stdlib.h>
#include <string.h>

#include "../../1.Application/Include/APP_WorkingNormalState.h"

#include "../../2.Component/Include/Cmp_KeyScan.h"

#include "../../2.Component/Include/Cmp_Onboarding.h"

#include "../../3.Library/Include/Int.h"
#include "../../3.Library/Include/Lib_CommSubMicom.h"

#include "../../6.VariableSource/Include/Vable_ModelInformation.h"




static UINT8 Cmp_OnBodOptionCheck(T_DispInfo* psDisplayInfo)
{
	if(psDisplayInfo->UartInfo.CommMode[NormalComm] == SET)
	{
		if(Get_OPTION()[Real_Option] == Get_OPTION()[PC_Recv_OP])
		{
			return RETURN_OK;
		}
	}
	else
	{
		if(Get_OPTION()[FCT_Recv_OP] == Get_OPTION()[PC_Recv_OP])
		{
			return RETURN_OK;
		}
	}
	
	return RETURN_NG;
}


static void Cmp_OnBodCommModeSet(T_DispInfo* psDisplayInfo)
{		
	if(Onboarding_ModelFlag == CLEAR)
	{
		psDisplayInfo->UartInfo.CommMode[NormalComm] = SET;
		psDisplayInfo->UartInfo.CommMode[LoadOpComm] = CLEAR;
	}
	else
	{
		if(Cmp_OnBodOptionCheck(psDisplayInfo))
		{
			psDisplayInfo->UartInfo.CommMode[NormalComm] = SET;
			psDisplayInfo->UartInfo.CommMode[LoadOpComm] = CLEAR;
			
			Get_OPTION()[FCT_Send_OP] = CLEAR;
		}
		else
		{
			psDisplayInfo->UartInfo.CommMode[NormalComm] = CLEAR;
			psDisplayInfo->UartInfo.CommMode[LoadOpComm] = SET;
			
			Get_OPTION()[FCT_Send_OP] = Get_OPTION()[PC_Recv_OP];
		}
	}
}



void Cmp_OnboardingCheck(T_DispInfo* psDisplayInfo)
{
	if(psDisplayInfo->DispType == Vivace)
	{
		Cmp_OnBodCommModeSet(psDisplayInfo);
	}
	else
	{
		psDisplayInfo->UartInfo.CommMode[NormalComm] = SET;
		psDisplayInfo->UartInfo.CommMode[LoadOpComm] = CLEAR;
	}
}

