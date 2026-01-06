
#include <stdlib.h>


#include "../../6.VariableSource/Include/Vable_ModelInformation.h"


const T_BufferDef mpstBufferInfo[CommStateMax] = 
{	
	//	0.Send State					1.	Recv state				2.	Stx			3.	Etx	
	// NormalComm
	{gaucSendBuffer,				gaucRecvBuffer,				STX_NORMAL,		ETX_NORMAL},
	// LoadOpComm
	{OP_gaucSendBuffer, 			OP_gaucRecvBuffer,			STX_OPTION, 	ETX_OPTION},
	// Jig2PCComm
	{PC_gaucSendBuffer, 			PC_gaucRecvBuffer,			STX_PC, 		ETX_PC},
};

const UINT8 gaucBeeperInfo[PlaformMax][BeeperInformMax] = 
{
	//	0.Beep_Power_ON		1.Beep_Power_OFF		2.Beep_KEY_IN		3.Beep_DUMMY		4.Beep_Error		5.Beep_HeadOnOff	6.Beep_Counter( 6:1100,0000;  5:0110 0000 )
	//	0
	{NULL,					NULL,					NULL,				NULL,				NULL,				NULL,				NULL},
	//	1.Vivace
	{VVC_Power_ON,			VVC_Power_OFF,			VVC_KEY_IN,			VVC_DUMMY,			VVC_Error,			BIN8(0000,0000),	BIN8(1100,0000)},
	//	2.Topgun_WW
	{Topgun_WW_Power_ON,	Topgun_WW_Power_OFF,	Topgun_WW_KEY_IN,	Topgun_WW_DUMMY,	Topgun_WW_Error,	BIN8(1000,0000),	BIN8(0110,0000)},
	//	3.Mini
	{Mini_Power_ON,			Mini_Power_OFF,			Mini_KEY_IN,		Mini_Power_DUMMY,	Mini_Error,			BIN8(0010,0000),	BIN8(1100,0000)},
	//	4.Topgun_Amr
	{Topgun_Amr_Power_ON,	Topgun_Amr_Power_OFF,	Topgun_Amr_KEY_IN,	Topgun_Amr_DUMMY,	Topgun_Amr_Error,	BIN8(0000,0000),	BIN8(0110,0000)},
	//	5.Mega_Titan
	{Mega_Titan_Power_ON,	Mega_Titan_Power_OFF,	Mega_Titan_KEY_IN,	Mega_Titan_DUMMY,	Mega_Titan_Error,	BIN8(0000,0000),	BIN8(1100,0000)},
	//	6.NT
	{New_Topgun_Power_ON,	New_Topgun_Power_OFF,	New_Topgun_KEY_IN,	New_Topgun_DUMMY,	New_Topgun_Error,	BIN8(1000,0000),	BIN8(1100,0000)},
	//	7.LCD_VX_NT
	{LCD_VX_NT_Power_ON,	LCD_VX_NT_Power_OFF,	LCD_VX_NT_KEY_IN,	LCD_VX_NT_DUMMY,	LCD_VX_NT_Error,	BIN8(0000,0000),	BIN8(1100,0000)},
	//	8.LCD_VXD_Dryer
	{LCD_VXD_Dryer_Power_ON,LCD_VXD_Dryer_Power_OFF,LCD_VXD_Dryer_KEY_IN,LCD_VXD_Dryer_DUMMY,LCD_VXD_Dryer_Error,BIN8(0000,0000),	BIN8(1100,0000)},
	//	9.GVX_CVX
	{GVX_Power_ON,			GVX_Power_OFF,			GVX_KEY_IN,			GVX_DUMMY,			GVX_Error,			BIN8(0000,0000),	BIN8(1100,0000)},
	//	10.GVX_CVX_Dryer
	{GVX_Dryer_Power_ON,	GVX_Dryer_Power_OFF,	GVX_Dryer_KEY_IN,	GVX_Dryer_DUMMY,	GVX_Dryer_Error,	BIN8(0000,0000),	BIN8(1100,0000)},
	//	11.New_Mini
	{New_Mini_Power_ON,		New_Mini_Power_OFF,		New_Mini_KEY_IN,	New_Mini_DUMMY,		New_Mini_Error,		BIN8(0000,0000),	BIN8(1100,0000)},
};

const UINT8 gauCommInfo[PlaformMax][CommInformMax] = 
{
	//0.SEND_SIZE								1.RECV_SIZE									2.PacketGaptime
	//	0.JigUpdate
	{8,		32,		60},	
	//	1.Vivace	
	{48,	22,		70},	
	//	2.Topgun_WW
	{60,	18,		60},	
	//	3.Mini
	{79,	14,		60},	
	//	4.Topgun_Amr
	{60,	19,		60},	
	//	5.Mega_Titan
	{29,	17,		70},	
	//	6.New_Topgun
	{60,	18,		60},	
	//	7.LCD_VX_NT
	{121,	51,		60},	
	//	8.LCD_VXD_Dryer
	{253,	54,		60},	
	//	9.GVX_CVX
	{83,	27,		60},	
	//	10.GVX_CVX_Dryer
	{60,	40,		80},	
	//	11.New_Mini
	{71,	25,		60},	
};

const UINT8 gauProductModeInfo[PlaformMax][Mode_MAX] = 
{
	// PLQC_Mode		CS_Mode		Other_Mode
	// 0.JigUpdate
	{NA,			NA,			NA},	//	1-> 2-> 3-> 4-> 5-> 6
	// 1.Vivace
	{1,				NA,			1},		//	1->  ->  -> 4-> 5-> 6
	// 2.Topgun_WW
	{10,			18,			10},	//	 -> 2-> 3-> 4-> 5->  
	// 3.Mini
	{6,				NA,			6},	//	1->  -> 3-> 4->  ->  
	// 4.Topgun_Amr
	{3,				NA,			3},	//	1->  -> 3-> 4-> 5->  
	// 5.Mega_Titan
	{1,				NA,			1},	//	1->  ->  -> 4->  ->  
	// 6.New_Topgun	
	{10,			18,			10},	//	 -> 2-> 3-> 4-> 5->  
	// 7.LCD_VX_NT	
	{9,				NA,			9},	//	1->  ->  ->  -> 5->  
	// 8.LCD_VXD_Dryer
	{6,				NA,			255},	//	1->  ->  ->  -> 5->  
	// 9.GVX_CVX
	{1,				NA,			1},		//	1->  ->  -> 4-> 5-> 6
	// 10.GVX_CVX_Dryer
	{6,				NA,			6},		//	1->  ->  -> 4-> 5-> 6
	// 11.New_Mini
	{6,				NA,			6},	//	1->  -> 3-> 4->  ->  
};

const UINT8 gauLqcStepInfo[PlaformMax][STEP_MAX] = 
{
	//0.Version	1.CheckSum	2.1888		3.LED 		4.WIFI 		5.FinalStep
	// 0.JigUpdate
	{NA,		NA,			NA,			NA,			NA,			NA},	//	1-> 2-> 3-> 4-> 5-> 6
	// 1.Vivace
	{0,			NA,			NA,			11,			13,			0},		//	1->  ->  -> 4-> 5-> 6
	// 2.Topgun_WW
	{NA,		1,			2,			3,			18,			NA},	//	 -> 2-> 3-> 4-> 5->  
	// 3.Mini
	{31,		NA,			21,			31,			NA,			NA},	//	1->  -> 3-> 4->  ->  
	// 4.Topgun_Amr
	{0,			NA,			2,			3,			4,			NA},	//	1->  -> 3-> 4-> 5->  
	// 5.Mega_Titan
	{0,			NA,			NA,			1,			NA,			NA},	//	1->  ->  -> 4->  ->  
	// 6.New_Topgun	
	{NA,		1,			2,			3,			18,			NA},	//	 -> 2-> 3-> 4-> 5->  
	// 7.LCD_VX_NT	
	{0,			NA,			NA,			11,			NA,			NA},	//	1->  ->  ->  -> 5->  
	// 8.LCD_VXD_Dryer
	{0,			NA,			NA,			1,			NA,			NA},	//	1->  ->  ->  -> 5->  
	// 9.GVX_CVX
	{0,			NA,			NA,			11,			13,			0},		//	1->  ->  -> 4-> 5-> 6
	// 10.GVX_CVX_Dryer
	{0,			NA,			NA,			NA,			6,			NA},	//	1->  ->  -> 4-> 5-> 6
	// 11.New_Mini
	{31,		NA,			21,			31,			NA,			NA},	//	1->  -> 3-> 4->  ->  
};

