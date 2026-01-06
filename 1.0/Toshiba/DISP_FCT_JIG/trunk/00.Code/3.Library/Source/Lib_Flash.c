#include <stdlib.h>
#include <string.h>


#define _FLASH
#include "../../3.Library/Include/Lib_Flash.h"
#undef _FLASH

static  UINT32 maucWriteBuffer[64] = {0,};


void SetCMDBuffer(UINT32* pstMemoryInfo)
{
	memset(maucWriteBuffer,0xFF,(SIZE_OF_ARRAY(maucWriteBuffer) * 4));
	maucWriteBuffer[0] = pstMemoryInfo[0];
	maucWriteBuffer[1] = pstMemoryInfo[1];
}

T_CMD_STEP CMDErase(void)
{
	HWI_FlashEraseSector(0x60000);
	return CMD_WRITE_STEP;
}

T_CMD_STEP CMDWrite(void)
{
	HWI_FlashWrite(0x60000,maucWriteBuffer);

	return CMD_FINISH_STEP;
}

#pragma location = "RAMCODE"
void HWI_FlashEraseSector(UINT32 ulAdr)
{
    volatile UINT32 * ADR_54XX;
    volatile UINT32 * ADR_AAXX;
    volatile UINT8 * BA_ADR;
    
    ADR_54XX = &FLASH_0_SEQ_54XX;
    ADR_AAXX = &FLASH_0_SEQ_AAXX;

    FC->AREASEL = 0x07;
    while (FC->AREASEL != 0x07) {
      /* Do nothing */
    }
    
    ulAdr &= 0xffffC000;
    ulAdr |= 0x5E000000;
    BA_ADR = (volatile UINT8 *) ulAdr;
    
    *ADR_AAXX = 0xf0;													/* Reset FLASH */
    HW_CheckBusy();																/* Flash Busy 	*/
    
    *ADR_54XX = FLASH_CMD_AA;							
    *ADR_AAXX = FLASH_CMD_55;							
    *ADR_54XX = FLASH_CMD_80;								
    *ADR_54XX = FLASH_CMD_AA;								
    *ADR_AAXX = FLASH_CMD_55;								
    *BA_ADR = FLASH_CMD_30;									
    									
    HW_CheckBusy();																/* Flash Busy */

    FC->AREASEL = 0x00;
    while (FC->AREASEL != 0x00) {
      /* Do nothing */
    }
    //	*ADR_AAXX = 0xf0;	
}

#pragma location = "RAMCODE"
void HWI_FlashWrite(UINT32 ulAdr, UINT32* pulData)
{
	int nLoop;
	int tLoop;
	volatile UINT32 * ADR_54XX;
	volatile UINT32 * ADR_AAXX;
	volatile UINT32 * PA_ADR;
	
	ADR_54XX = &FLASH_0_SEQ_54XX;
	ADR_AAXX = &FLASH_0_SEQ_AAXX;
	
	//	adr &= 0xffffC000;
	ulAdr &= 0xffffFF00;
	ulAdr |= 0x5E000000;
	PA_ADR = (UINT32 *) ulAdr;
	
	for(tLoop=0;tLoop<(DATA_LEN/(PROGRAM_UNIT<<2));tLoop++)
	{
		FC->AREASEL = 0x07;
		while (FC->AREASEL != 0x07) {/* Do nothing */}
		
		*ADR_AAXX = 0xf0;												/* Reset FLASH */
		HW_CheckBusy();															/* Flash Busy */
		
		*ADR_54XX = FLASH_CMD_AA;						
		*ADR_AAXX = FLASH_CMD_55;						
		*ADR_54XX = FLASH_CMD_A0;						
		
		for(nLoop = 0; nLoop < PROGRAM_UNIT; nLoop++) {
			*PA_ADR = *pulData;											
			pulData++;
		}
		
		PA_ADR += PROGRAM_UNIT;
		HW_CheckBusy();															/* Flash Busy	*/
		*ADR_AAXX = 0xf0;												/* Reset FLASH */

		FC->AREASEL = 0x00;
		while (FC->AREASEL != 0x00) {/* Do nothing */}
	}
}

#pragma location = "RAMCODE"
void HW_CheckBusy(void)
{
	//unsigned short cnt;
	for(;(FC->PSR0&0x01)==0;){;;}
}

UINT8 UART_CrcMaker(UINT8* pucBuffer, UINT16 unLength)
{
	UINT16 unIndex = 0;
	UINT8 ucCrc = 0;

	for( ; unIndex < unLength; unIndex++)
	{
		ucCrc += *pucBuffer++;
	}
	return (ucCrc ^ 0x55);
}


