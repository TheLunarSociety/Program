


#include "../../4.Driver/Include/WROS_Register.h"

#include "../../5.Hardware/Include/bootloader.h"

const UINT8 LoadSignalConfirm[32] = {
0xAA, 0x20, 0x44, 0x4F, 0x4C, 0x4F, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xDD, 0x55};

/* 
	0x44 'D', 
	0x4F 'O', 
	0x4C 'L', 
	0x4F 'O'
*/
__no_init UINT8 gucMagic0 @ 0x20007f00;
__no_init UINT8 gucMagic1 @ 0x20007f01;
__no_init UINT8 gucMagic2 @ 0x20007f02;
__no_init UINT8 gucMagic3 @ 0x20007f03;

void DownloaderCheck(UINT8* PaucRecvBuffer)
{
	UINT8 ucBufCntCheck = 0;
	struct AIRCR_Register AIRCR_Registers;

	while(PaucRecvBuffer[ucBufCntCheck] == LoadSignalConfirm[ucBufCntCheck])
	{
		ucBufCntCheck++;
		
		if(ucBufCntCheck == SIZE_OF_ARRAY(LoadSignalConfirm))
		{
			API_SetStackPointer(*(int*)0x0000);
			API_SetBootLoaderMode(USER_DOLO_MODE);
			*(int*)0xE000ED08 = 0x0000;
			
			__DSB(15);
			AIRCR_Registers.VECTKEY		= 0x05FA;
			AIRCR_Registers.PRIGROUP	= WROS_CORE_M->NVIC_register.AIRCR_register.PRIGROUP;
			AIRCR_Registers.SYSRESETREQ	= SET;
			
			WROS_CORE_M->NVIC_register.AIRCR_register = AIRCR_Registers;
			while(1);
		}
	}
}

void API_SetStackPointer(UINT32 ulTopOfStack)
{
	__asm("msr msp, r0");
	__asm("bx lr");
}

void API_SetBootLoaderMode(UINT16 ucmode)
{
 	if(ucmode == USER_DOLO_MODE)
	{
		gucMagic3 = 'D';
		gucMagic2 = 'O';
		gucMagic1 = 'L';
		gucMagic0 = 'O';
	}
	else
	{
		gucMagic3 = 0;
		gucMagic2 = 0;
		gucMagic1 = 0;
		gucMagic0 = 0;		
	}
}
