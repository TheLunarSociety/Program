/*****************************************************************************
	DD Type(BLDCM) Washing Machine Program
	Model					: Panacea-PJT
	Version					: Ver 1.0
	CPU						: MN103SFA5K
	File type				: C source file
	File name				: int.c
	Included Funtion		:

	be coded by KIM KYUNG HOON
********************************************************************************/

#include "../../1.Application/Include/APP_WorkingNormalState.h"

#include "../../2.Component/Include/Cmp_Display_Service.h"



#define ROOT
#include "../../3.Library/Include/Int.h"
#undef  ROOT



static UINT8 mucDimmingScanline;
void SetLEDScanLine(UINT8);
void SetDataLine(UINT16);
void ControlDataLine(void);
void ControlScanLine(void);
void ReadKeyData(UINT8);
void MWI_LEDControlPortAllClear(void);
void PWMForDisplay(void);
void HWKeyScan(void);
void Encoder_Input_Control(void);
void DoorDE4Scan(void);
void StandbySignalScan(void);
void Timer_TimeInc();


#ifdef ROTARY_KEY
#define KEY_VALUE	((WROS_____PE->DATA >> 4) & BIN4(1100))
#else
#define KEY_VALUE	((WROS_____PE->DATA >> 4) & BIN4(1111))
#endif


/*********************************************************************
<Description> :
	- time flag setting
<Note> :
	- argument
	- return
	- call by int_group3()
	- operation
		500us timer interrupt
*********************************************************************/

static	UINT32	gunTime_HalfS_Cnt = 0;
static	UINT16	Base_Timer_500us = 0;

static void timer_500us()
{
	PWMForDisplay();
	HWKeyScan();
	StandbySignalScan(); 
	DoorDE4Scan(); 
}

static void timer_1ms()
{
	if(Base_Timer_500us % 2 == 0)	//	1ms
	{
		ControlScanLine();
		ControlDataLine();

	#ifdef ROTARY_KEY
		Encoder_Input_Control();
	#else
	#endif
	}
}

static void timer_10ms()
{	
	if(Base_Timer_500us % 20 == 0)	//	10ms
	{	Timer_TimeInc();	// timer control base timer count
	}
}

static void timer_500ms()
{
	if(Base_Timer_500us % 1000 == 0)	//	500ms
	{
		gunTime_HalfS_Cnt++;
		Base_Timer_500us = 0;
		MAX_Limite(gunTime_HalfS_Cnt,0,9);
	}
}

static void (* const FuncBaseTimer[]) (void) =
{
	timer_500us,
	timer_1ms,
	timer_10ms,
	timer_500ms,
};

void MWI_INT_Timer0(void)
{
	Base_Timer_500us++;
	UINT8 TimerIndex = 0;
	
	while(TimerIndex < SIZE_OF_ARRAY(FuncBaseTimer)){FuncBaseTimer[TimerIndex++]();}
}

void ControlScanLine()
{
	static UINT8 ucScan_Line = 0;
	
	MWI_LEDControlPortAllClear();
	CounterAddLimit(ucScan_Line,0,3);
	SetLEDScanLine(ucScan_Line);
	mucDimmingScanline = ucScan_Line;
}

void ControlDataLine(void)
{
	UINT16 unLEDDataLine = 0;	
	
	unLEDDataLine = gu8LED_Data[mucDimmingScanline].word; 
	SetDataLine(unLEDDataLine);
}

void SetLEDScanLine(UINT8 ucScan_Line)
{
	LED_SCAN_LINE_0_3 = (SET << (LED_SCAN_LINE_MAX - ucScan_Line));
	// Macro ES1 Scanline 2008-06-19

	__asm("NOP");							// Delay time 何咯
	__asm("NOP");
	__asm("NOP");
}

void SetDataLine(UINT16 unMasking)
{
	LED_DATA_LINE_A_G = (UINT8)(unMasking & 0x7F);

}

void MWI_LEDControlPortAllClear(void)
{
	UINT8 ucindex = CLEAR;
	
	// LED Data Clear
	LED_DATA_LINE_A = 0;
	LED_DATA_LINE_B = 0;
	LED_DATA_LINE_C = 0;
	LED_DATA_LINE_D = 0;
	LED_DATA_LINE_E = 0;
	LED_DATA_LINE_F = 0;
	LED_DATA_LINE_G = 0;


	// Delay time: 2us
	__asm("NOP");
	__asm("NOP");
	__asm("NOP");

	// Scan line clean
	SCAN_LINE_0 = 0;
	SCAN_LINE_1 = 0;
	SCAN_LINE_2 = 0;
	SCAN_LINE_3 = 0;


	// Delay time 20us
	for(ucindex = 0 ; ucindex < 15 ; ucindex++)
	{
		;
	}

}
void PWMForDisplay()
{
	static	UINT8 Step = 0;
	
	Step++;
	
	if(Step <= 10)		//5ms
	{
		Door_SIG_SIGNAL = Door_SIG_SIGNAL_Flag;
	}
	else
	{
		Door_SIG_SIGNAL = CLEAR;
	}
	
	if(Step == 40)		//20ms
	{
		Step = CLEAR;
	}
	else
	{	;
	}
}

void HWKeyScan(void)
{
	static UINT16 sucKeycounter = 0;

	if(KEY_VALUE != CLEAR)
	{
		if(sucKeycounter < 4000)
		{
			sucKeycounter++;
			if(sucKeycounter == 119)
			{	
				gunKey_New |= KEY_VALUE;
			}
			else if(sucKeycounter == 3999)
			{
				gunKey_New |= (KEY_VALUE << 4);
			}
			else
			{	;
			}
		}
		else
		{	;
		}
	}
	else
	{
		gunKey_New = CLEAR;
		sucKeycounter = 0;
	}

}

void Encoder_Input_Control(void)
{
	static UINT8 gu8Encoder_Timer = 0;
	static UINT8 gu8Encoder_InCounter = 0;
	static UINT8 gaucEncoderBuffer[5] = {0,};
	UINT8	Temp = 0;
	UINT8	b, c = 0;
	
	if(gu8Encoder_Timer != 0)
	{	gu8Encoder_Timer--;
		return;										
	}
	else
	{	
		Temp = (UINT8)(CHOOSE_KEY);						
		
		if(Temp != gaucEncoderBuffer[0])						
		{	
			for(b=4, c=3; b != 0; b--, c--)
			{	gaucEncoderBuffer[b] = gaucEncoderBuffer[c];		
			}
		
			gaucEncoderBuffer[0] = Temp;					
			gu8Encoder_InCounter++;
			if((gu8Encoder_InCounter >= 4)					
				&& (gaucEncoderBuffer[0] == 0x03))				
			{
				if((gaucEncoderBuffer[1] == 0x02) 
					&& (gaucEncoderBuffer[2] == 0x00) 
					&& (gaucEncoderBuffer[3] == 0x01) 
					&& (gaucEncoderBuffer[4] == 0x03))
				{	gu8Encoder_InCounter = 0;				
					gu8Encoder_Timer = 100;				
					gunKey_New |= (CHOOSE_KEY & BIN4(0001));

				}
				else if(	(gaucEncoderBuffer[1] == 0x01) 
					&& (gaucEncoderBuffer[2] == 0x00) 
					&& (gaucEncoderBuffer[3] == 0x02) 
					&& (gaucEncoderBuffer[4] == 0x03))
				{	gu8Encoder_InCounter = 0;				
					gu8Encoder_Timer = 100;				
					gunKey_New |= (CHOOSE_KEY & BIN4(0010));
				}
				else
				{	;
				}
			}
			else
			{	;
			}
		}
		else
		{	;
		}

	}	


}

void StandbySignalScan(void)
{
	if(STANDBY_SIGNAL == 1)
	{
		STANDBY_SIGNAL_Flag = SET;
	}
	else
	{
		;
	}
}

void DoorDE4Scan(void)
{
	if(Door_SEN_SIGNAL == 1)
	{
		Door_SEN_SIGNAL_Flag = SET;
		Door_SIG_SIGNAL_Flag = SET;
	}
	else
	{
		Door_SEN_SIGNAL_Flag = CLEAR;
		Door_SIG_SIGNAL_Flag = CLEAR;
	}
}

void Timer_TimeInc(void)			// to be simple						
{
	mstTimeCheckBaseTimer.ulLow += 10;		// ms timer 10ms
}

UINT8 Timer_MsecCheckPassTime(T_Time* pstTime, UINT32 ulTime)	
{
	T_Time stCurrentTime;
	UINT8 ucRetValue = 0;
		
	stCurrentTime.ulLow = mstTimeCheckBaseTimer.ulLow;


	if(stCurrentTime.ulLow >= pstTime->ulLow)
	{	
		if(stCurrentTime.ulLow - pstTime->ulLow >= ulTime)
		{	ucRetValue = 1;
		}
		else
		{	ucRetValue = 0;
		}
	}
	
	else if ((0xFFFFFFFF - pstTime->ulLow + stCurrentTime.ulLow) >= ulTime)
	{	ucRetValue = 1;
	}
	else
	{	ucRetValue = 0;
	}
	
	if(ucRetValue == SET)		// && (ucUpdateOption==SET))
	{
		pstTime->ulLow = stCurrentTime.ulLow;
	}
	else
	{	;
	}
	
	return ucRetValue;
}

void Timer_GetTime(T_Time* pstTime)
{
	pstTime->ulLow = mstTimeCheckBaseTimer.ulLow;
}

UINT32 timer_1s_calc(void)
{	return gunTime_HalfS_Cnt;
}

// End of file
