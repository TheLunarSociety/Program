/**********************************************************************
<Inform> : WWR DISP FCT Plat
<Date> : 2023.04.18
<Programmer> : WWR
<Description> : TMPM470FZFG
Copyright (c) 2023 LG Electronics Inc. - All rights reserved.
**********************************************************************/



#include "../../1.Application/Include/APP_WorkingNormalState.h"


#include "../../2.Component/Include/Cmp_Display_Service.h"
#include "../../2.Component/Include/Cmp_KeyScan.h"
#include "../../2.Component/Include/Cmp_SetError.h"
#include "../../2.Component/Include/Cmp_LQC_Process.h"


#include "../../4.Driver/Include/DDI_BootingDriver.h"

#include "../../5.Hardware/Include/bootloader.h"




#pragma location = "VDE_checksum_section"
const UINT16 gunVDECheckSumData[2] = {(UINT16)~CHECKSUM_VALUE, (UINT16)CHECKSUM_VALUE};  //Checksum balance

/*********************************************************************
@fn: main()
@param	void
@return	void
*********************************************************************/
T_DispInfo gstDisplayInfo;

void main(void)
{	
	API_SetBootLoaderMode(gunVDECheckSumData[1]);	// Set Checksum
	API_SetStackPointer(*(int*)0x4000); 			// 0x0000 ~ 0x3FFF is "DOLO" program
	
	DDI_WROS_BootMicom();
	DDI_WROS_Init(&gstDisplayInfo);					// Initial OS Task
	DDI_WROS_Start(&gstDisplayInfo);
}

