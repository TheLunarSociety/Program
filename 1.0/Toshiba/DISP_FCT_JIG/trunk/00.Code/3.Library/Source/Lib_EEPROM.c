

#include "../../3.Library/Include/Int.h"
#include "../../3.Library/Include/Lib_UartComm.h"
#include "../../3.Library/Include/Lib_EEPROM.h"


/**
* @fn void EEP_SetFixDataToEEPROM(UINT16 unStartAddr, UINT16 unSize, UINT8 SetNum)
* 
* @param		
* @return		
* @see
*/
/*
UINT8 EEP_SetFixDataToEEPROM(UINT16 unStartAddr, UINT16 unSize, UINT8 SetNum)
{
	UINT16 i = 0;
	
	DDI_INIT_SetWatchDogClear();	// Watchdog Timer Clear(max 384ms)
	
	EEP_Erase_Write_Enable();
	for(i = 0 ; i < unSize ; i++)
	{
		if(EEP_ByteWrite((unStartAddr + i), SetNum) == RETURN_NG)
		{	return RETURN_NG;
		}
		else
		{	;
		}
	}
	EEP_Erase_Write_Disable();

	return RETURN_OK;
}
*/

#define EEPROM


UINT8 EEP_SaveBufferToEEPROM(UINT16 unStartAddr, UINT8* pucBuff, UINT8 ucBuffSize)
{
	UINT8	i = 0;
	
	EEP_Erase_Write_Enable();
	for(i = 0 ; i < ucBuffSize ; i++)
	{
		if(EEP_ByteWrite((unStartAddr + i), (UINT8)(*(pucBuff + i))) == RETURN_NG)
		{	return RETURN_NG;
		}
		else
		{	;
		}
	}
	EEP_Erase_Write_Disable();

	return RETURN_OK;
}

void EEP_LoadBufferFromEEPROM(UINT16 unStartAddr, UINT8* pucBuff, UINT8 ucBuffSize)
{
	UINT8	i = 0;
	
	for(i = 0 ; i < ucBuffSize ; i++)
	{
		*(pucBuff + i) = EEP_ByteRead(unStartAddr + i);
	}
}

#define ADD_HW_EEPROM
//****************************************************************
//
//		EEPROM HW Control function
//
//****************************************************************
UINT8 EEP_ByteRead(UINT16 unAddress_Data)
{
	UINT8	u8Read_Data = 0;
	
	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
	EEP_nBit_Write(0xC0, 3);		// op code (read-110)	// start bit = 1, op-code = 10
	EEP_AddressSet(unAddress_Data);
	u8Read_Data = EEP_nBit_Read();							// read 0		// read 1 byte(8 bit)
	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;					// CS = L

	return(u8Read_Data);
}

UINT8 EEP_ByteWrite(UINT16 unAddress_Data, UINT8 ucWrite_Data)
{
	UINT8	ucRetVal = 0;
	
	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
	EEP_nBit_Write(0xA0, 3);					//	101: Start 1,op code 01
	EEP_AddressSet(unAddress_Data);				//	A10,A9,	A8~A0
	
	//-------------------------------------------------- Data Write

	EEP_nBit_Write(ucWrite_Data, WRITE_BIT_LENGTH);

	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;			// CS = L
	EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);
	EEPROM_CHIP_SELECT_INPUT_P = SET;				// CS = H

	if(EEP_Busy_Delay() == RETURN_NG)
	{	 ucRetVal = RETURN_NG;
	}
	else
	{	ucRetVal = RETURN_OK;
	}

	return ucRetVal;
}

void EEP_AddressSet(UINT16 unAddress)
{
#if (EEPROM_TYPE == M93C86)

	EEP_nBit_Write(((UINT8)(unAddress >> 3) & 0xE0), 3);	// abc XXXX XXXX >> 3  ==> abcX XXXX & 1110 0000 ==> abc0 0000
	
#else

	EEP_nBit_Write(((UINT8)(unAddress >> 1) & 0x80), 1);	// a XXXX XXXX >> 1  ==> aXXX XXXX & 1000 0000 ==> a000 0000

#endif

	EEP_nBit_Write((UINT8)(unAddress & 0x00FF), 8);
}

UINT8 EEP_Busy_Delay(void)
{
	static T_Time	stEEPROMtimer;

	Timer_GetTime(&stEEPROMtimer);

	while(!EEPROM_SERIAL_READ_P)
	{
		if(Timer_MsecCheckPassTime(&stEEPROMtimer, (UINT32)(BUSY_DELAY_TIME)) == SET)
		{	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;		// CS = L
			EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);
			EEPROM_SERIAL_CLOCK_P = CLEAR;			// CLK = L
			return(RETURN_NG);
		}
		else
		{	;
		}
	}

	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;				// CS = L
	EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);
	EEPROM_SERIAL_CLOCK_P = CLEAR;					// CLK = L

	return(RETURN_OK);
}

void EEP_nBit_Write(UINT8 ucWriteData, UINT8 ucNumberOfBit)
{
	UINT8 ucTemp1 = 0;

	EEPROM_SERIAL_CLOCK_P = CLEAR;			// CLK = L
	EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);
	EEPROM_CHIP_SELECT_INPUT_P = SET;			// CS = H

	ucTemp1 = ucWriteData;
	while(1)
	{
		if(ucTemp1 & 0x80)
		{	EEPROM_SERIAL_WRITE_P = ON;		// data
		}
		else
		{	EEPROM_SERIAL_WRITE_P = OFF;		// data
		}
		
		EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);
		EEPROM_SERIAL_CLOCK_P = SET;			// CLK = H,
		ucNumberOfBit--;

		if(ucNumberOfBit != 0)
		{	ucTemp1 = (UINT8)((ucTemp1 << 1) & 0xFF);
			EEPROM_SERIAL_CLOCK_P = CLEAR;		// CLK = L
		}
		else
		{	EEPROM_SERIAL_CLOCK_P = CLEAR;		// CLK = L
			EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);
			EEPROM_SERIAL_WRITE_P = CLEAR;
			return;
		}
	}
}

UINT8 EEP_nBit_Read(void)
{
	UINT8 ucTemp1 = WRITE_BIT_LENGTH;
	UINT8 ucRead_Data = 0;

	while(1)
	{
		EEPROM_CHIP_SELECT_INPUT_P = SET;			// CS = H
		EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);
		
		EEPROM_SERIAL_CLOCK_P = SET;				// CLK = H
		EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);

		if(EEPROM_SERIAL_READ_P == SET)
		{	ucRead_Data |= 0x01;						//	set 0 bit;
		}
		else
		{	ucRead_Data &= 0xFE;						//	clr 0 bit;
		}
		
		EEPROM_SERIAL_CLOCK_P = CLEAR;			// CLK = L
		ucTemp1--;

		if(ucTemp1 != 0)
		{	ucRead_Data <<= 1;
		}
		else
		{	return(ucRead_Data);
		}
	}
}

void EEP_Erase_Write_Enable(void)
{	
	
	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
	EEP_nBit_Write(0x80, 3);		// 100: start bit = 1, op-code = 00

#if (EEPROM_TYPE == M93C86)

	EEP_nBit_Write(0xC0, 3);		// 110:	
	EEP_nBit_Write(0x00, 8);	//0000,0000:  don't care
#else
	EEP_nBit_Write(ENABLE_ORDER, 8);
#endif

	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
}

void EEP_Erase_Write_Disable(void)
{	
	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
	EEP_nBit_Write(0x80, 3);		//	100: start bit = 1, op-code = 00

#if (EEPROM_TYPE == M93C86)

	EEP_nBit_Write(0x00, 3);		//	00X (X = Don't Care bit)
	
#endif
	
	EEP_nBit_Write(0x00, 8);		// Address : 00XX XXXX (X = don't care.)
	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
}

void EEP_Loop_Delay(UINT8 ucLoop_Number)				// do not over 50.
{	
	while(ucLoop_Number > 0)
	{	ucLoop_Number--;
	}
}


