
#include <stdlib.h>
#include <string.h>


#include "../../1.Application/Include/APP_WorkingNormalState.h"

#define	__LEDDISPLAY__
#include "../../2.Component/Include/Cmp_Display_Service.h"
#undef	__LEDDISPLAY__

#include "../../2.Component/Include/Cmp_KeyScan.h"
#include "../../2.Component/Include/Cmp_SetError.h"

#include "../../3.Library/Include/Int.h"
#include "../../3.Library/Include/Lib_UartComm.h"
#include "../../3.Library/Include/Lib_CommSubMicom.h"
#include "../../3.Library/Include/Lib_EEPROM.h"

#include "../../4.Driver/Include/WROS_Register.h"


#include "../../6.VariableSource/Include/Vable_ModelInformation.h"

UINT8 gu8Temp_Data[4];	// Temp led output data

void Cmp_Dsp_Setting_Normal(UINT8,UINT16);
void Cmp_Dsp_Setting_Error();
void Cmp_Dsp_Displaying(void);
UINT8 Lamp1sBlink(UINT8,UINT8);
UINT8 NumbertoChar(UINT8);

#define	GET_CHAR_PICTURE(a,b)			( (a[b][0] << 0)	\
										| (a[b][1] << 5)	\
										| (a[b][2] << 1)	\
										| (a[b][3] << 6)	\
										| (a[b][4] << 4)	\
										| (a[b][5] << 2)	\
										| (a[b][6] << 3)	)


const UINT8 Test_Picture[7][7] =
{
	{
			1,
		0,		0,
			0,
		0,		0,
			0
	},
	{
			0,
		1,		0,
			0,
		0,		0,
			0
	},
	{
			0,
		0,		1,
			0,
		0,		0,
			0
	},
	{
			0,
		0,		0,
			1,
		0,		0,
			0
	},
	{
			0,
		0,		0,
			0,
		1,		0,
			0
	},
	{
			0,
		0,		0,
			0,
		0,		1,
			0
	},
	{
			0,
		0,		0,
			0,
		0,		0,
			1
	}
};

const UINT8 Number_Picture[16][7] =
{
	//******* 0
	{
			1,
		1,		1,
			0,
		1,		1,
			1
	},
	//******* 1
	{
			0,
		0,		1,
			0,
		0,		1,
			0
	},
	//******* 2
	{
			1,
		0,		1,
			1,
		1,		0,
			1
	},
	//******* 3
	{
			1,
		0,		1,
			1,
		0,		1,
			1
	},
	//******* 4
	{
			0,
		1,		1,
			1,
		0,		1,
			0
	},
	//******* 5
	{
			1,
		1,		0,
			1,
		0,		1,
			1
	},
	//******* 6
	{
			1,
		1,		0,
			1,
		1,		1,
			1
	},
	//******* 7
	{
			1,
		0,		1,
			0,
		0,		1,
			0
	},
	//******* 8
	{
			1,
		1,		1,
			1,
		1,		1,
			1
	},
	//******* 9
	{
			1,
		1,		1,
			1,
		0,		1,
			1
	},
	//******* A
	{
			1,
		1,		1,
			1,
		1,		1,
			0
	},
	//******* B
	{
			0,
		1,		0,
			1,
		1,		1,
			1
	},
	//******* C
	{
			1,
		1,		0,
			0,
		1,		0,
			1
	},
	//******* D
	{
			0,
		0,		1,
			1,
		1,		1,
			1
	},
	//******* E
	{
			1,
		1,		1,
			1,
		1,		0,
			1
	},
	//******* F
	{
			1,
		1,		0,
			1,
		1,		0,
			0
	},
};

const UINT8 Alphabet_pattern[26][7] = 
{	// 18:88 LED Numeric,Character Display
	// Big Alphabet			0x41
	//******* A
	{
			1,
		1,		1,
			1,
		1,		1,
			0
	},
	//******* B
	{
			0,
		1,		0,
			1,
		1,		1,
			1
	},
	//******* C
	{
			1,
		1,		0,
			0,
		1,		0,
			1
	},
	//******* D
	{
			0,
		0,		1,
			1,
		1,		1,
			1
	},
	//******* E
	{
			1,
		1,		0,
			1,
		1,		0,
			1
	},
	//******* F
	{
			1,
		1,		0,
			1,
		1,		0,
			0
	},
	//******* G
	{
			1,
		1,		0,
			1,
		0,		1,
			1
	},
	//******* H
	{
			0,
		1,		1,
			1,
		1,		1,
			0
	},
	//******* I
	{
			0,
		0,		1,
			0,
		0,		1,
			0
	},
	//******* J
	{
			1,
		0,		1,
			0,
		0,		1,
			1
	},
	//******* K
	{
			0,
		0,		0,
			0,
		0,		0,
			0
	},
	//******* L
	{
			0,
		1,		0,
			0,
		1,		0,
			1
	},
	//******* M
	{
			0,
		0,		0,
			0,
		0,		0,
			0
	},
	//******* N
	{
			0,
		0,		0,
			1,
		1,		1,
			0
	},
	//******* O
	{
			0,
		0,		0,
			1,
		1,		1,
			1
	},
	//******* P
	{
			1,
		1,		1,
			1,
		1,		0,
			0
	},
	//******* Q
	{
			1,
		1,		1,
			1,
		0,		1,
			0
	},
	//******* R
	{
			0,
		1,		0,
			1,
		1,		0,
			0
	},
	//******* S
	{
			1,
		1,		0,
			1,
		0,		1,
			1
	},
	//******* T
	{
			0,
		1,		0,
			1,
		1,		0,
			1
	},
	//******* U
	{
			0,
		1,		1,
			0,
		1,		1,
			1
	},
	//******* V
	{
			0,
		0,		0,
			0,
		1,		1,
			1
	},
	//******* W
	{
			0,
		0,		0,
			0,
		0,		0,
			0
	},
	//******* X
	{
			0,
		0,		0,
			0,
		0,		0,
			0
	},
	//******* Y
	{
			0,
		0,		0,
			0,
		0,		0,
			0
	},
	//******* Z
	{
			0,
		0,		0,
			0,
		0,		0,
			0
	},

};

void WROS_FUNC_JIG_Display(T_DispInfo* psDisplayInfo)
{
	while(1)
	{
		MAKE_TEST_POINT(DISPLAY_FLAG);
		Cmp_JIG_Display(psDisplayInfo);
	}
}

void Cmp_JIG_Display(T_DispInfo* psDisplayInfo)
{
	if(ERROR_State == NO_ERROR)
	{
		Cmp_Dsp_Setting_Normal(psDisplayInfo->DispType, (*(UINT32*)(0x0005FF02)));
	}
	else
	{
		Cmp_Dsp_Setting_Error();
	}

	if(DataReadWriteDataMemory(mucDispEnable, READ, NA))
	{
		Cmp_Dsp_Displaying();
	}
	else
	{
		gu8LED_Data[0].word = NumbertoChar(FCT_JIGVersion % 10);
		gu8LED_Data[1].word = NumbertoChar(FCT_JIGVersion / 10);
		gu8LED_Data[2].word = NumbertoChar('U');
		gu8LED_Data[3].word = CLEAR;
	}
}

void Cmp_Dsp_Setting_Normal(UINT8 ucDispType, UINT16 ucCheckSum)
{
	UINT8 TEMP;

	memset(gu8Temp_Data,NULL,SIZE_OF_ARRAY(gu8Temp_Data));
	
	gu8Temp_Data[0] = NumbertoChar(ucDispType % 10);							//	Show Platform
	gu8Temp_Data[1] = NumbertoChar(ucDispType / 10);							//	Show Platform
	
	if(CHECKSUM_KEY == BIN4(1100) && Get_JigKey() == JIG_CONF_KEY)
	{
		TEMP = (ucCheckSum / 1);
		gu8Temp_Data[0] = NumbertoChar(TEMP % 16);
		TEMP = (ucCheckSum / 16);
		gu8Temp_Data[1] = NumbertoChar(TEMP % 16);
		TEMP = (ucCheckSum / 256);
		gu8Temp_Data[2] = NumbertoChar(TEMP % 16);
		TEMP = (ucCheckSum / 4096);
		gu8Temp_Data[3] = NumbertoChar(TEMP % 16);
	}
	else
	{		
		if(ucDispType == JigUpdate && Get_JigKey() == JIG_CONF_KEY)	
		{
			gu8Temp_Data[0] = NumbertoChar(GET_LOW_1BYTE(FCT_JIGVersion));
			gu8Temp_Data[1] = NumbertoChar(GET_HIGH_1BYTE(FCT_JIGVersion));
			gu8Temp_Data[2] = NumbertoChar('U');
		}
		else if(ucDispType == Vivace && Onboarding_ModelFlag == SET)
		{
			gu8Temp_Data[2] = NumbertoChar('P');
		}
		else
		{	;
		}
	}
}

void Cmp_Dsp_Setting_Error()
{
	if(ERROR_State == SE_ERROR)
	{
		gu8Temp_Data[0] = NumbertoChar('E');
		gu8Temp_Data[1] = NumbertoChar('S');
		gu8Temp_Data[2] = NULL;
		gu8Temp_Data[3] = NULL;
	}	
	else
	{
		gu8Temp_Data[0] = NumbertoChar(4);
		gu8Temp_Data[1] = NumbertoChar('E');
		gu8Temp_Data[2] = NumbertoChar('D');
		gu8Temp_Data[3] = NULL;
	}
}

void Cmp_Dsp_Displaying()
{	
	if(Get_JigKey() == JIG_CONF_KEY && ERROR_State == NO_ERROR)
	{		
		if(CHECKSUM_KEY == BIN4(1100))
		{
			gu8LED_Data[0].word = Lamp1sBlink(gu8Temp_Data[0],gu8Temp_Data[2]);
			gu8LED_Data[1].word = Lamp1sBlink(gu8Temp_Data[1],gu8Temp_Data[3]);
			gu8LED_Data[2].word = Lamp1sBlink(NumbertoChar('L'),NumbertoChar('H'));
			gu8LED_Data[3].word = NULL;
		}
		else
		{
			gu8LED_Data[0].word = gu8Temp_Data[0];
			gu8LED_Data[1].word = gu8Temp_Data[1];
			gu8LED_Data[2].word = gu8Temp_Data[2];
			gu8LED_Data[3].word = gu8Temp_Data[3];
		}
	}	
	else
	{	
		gu8LED_Data[0].word = Lamp1sBlink(gu8Temp_Data[0],NULL);
		gu8LED_Data[1].word = Lamp1sBlink(gu8Temp_Data[1],NULL);
		gu8LED_Data[2].word = Lamp1sBlink(gu8Temp_Data[2],NULL);
		gu8LED_Data[3].word = Lamp1sBlink(gu8Temp_Data[3],NULL);
	}
}


UINT8 Lamp1sBlink(UINT8 ucblinkOn, UINT8 ucblinkOff)
{
	return (timer_1s_calc() % 2 == 1 ? ucblinkOn : ucblinkOff);
}

UINT8 NumbertoChar(UINT8 ucnumber)
{
	return (ucnumber < 16 ? GET_CHAR_PICTURE(Number_Picture,ucnumber) : GET_CHAR_PICTURE(Alphabet_pattern,(ucnumber - 65)));
}





/***********************************************************
 End File
************************************************************/
