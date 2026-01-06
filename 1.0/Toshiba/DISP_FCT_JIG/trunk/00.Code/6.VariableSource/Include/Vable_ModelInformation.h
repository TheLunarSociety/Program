
#ifndef _VableModelInfo_
#define _VableModelInfo_

#define FCT_JIGVersion  14

#define CHECKSUM_VALUE  0x9A2F

//#define ROTARY_KEY
//#define OPTION_ONBOARDING
//#define No_ErrorMode
//#define EEPROM_MEMORY
#define RTOS_WROS



/******************************
	Model List 
******************************/
enum
{
	JigUpdate,		//	0
	Vivace,			//	1
	Topgun_WW,		//	2
	Mini,			//	3
	Topgun_Amr,		//	4
	Mega_Titan,		//	5
	New_Topgun,		//	6
	LCD_VX_NT,		//	7
	LCD_VXD_Dryer,	//	8	total platform
	GVX_CVX,		//	9	total platform
	GVX_CVX_Dryer,	//	10	total platform
	New_Mini,		//	11	total platform
	PlaformMax		//		(platform 0 is Downlaod PGM platform)
};
/******************************
	Information List 
******************************/

enum
{
	NO_KEY			= 0,	JIG_AUGMENT_KEY	= 1,	JIG_SUBTRACT_KEY= 2,	JIG_CONF_KEY	= 3,	JIG_L_CONF_KEY	= 4,	JIG_ONBOARD_KEY	= 5,	JIG_L_ONBOARD_KEY	= 6,	JIG_OTHER_KEY = 0x3F,

	DISP_NO_KEY		= 0,	DISP_POWER_KEY	= 1,	DISP_START_KEY	= 2,	DISP_OTHER_KEY	= 3,
					
	Beep_Power_ON	= 0,	Beep_Power_OFF	= 1,	Beep_KEY_IN 	= 2,	Beep_DUMMY		= 3,	Beep_Error = 4,		Beep_HeadOnOff	= 5,	Beep_Counter	= 6,	BeeperInformMax = 7,
	
	NO_ERROR		= 0,	ERROR			= 1,							SE_ERROR 		= 3,												VVC_DE4_ERROR = 18,		Topgun_DE4_ERROR = 19,

	NormalComm		= 0,	LoadOpComm		= 1,	Jig2PCComm		= 2, 	CommStateMax	= 3,
	
	SEND_DATA_SIZE	= 0,	RECV_DATA_SIZE	= 1,	PacketGaptime	= 2,	CommInformMax	= 3, 	
	
	VVC_PanelType	= 0,	RFH_PanelType	= 1,	VBF_PanelType	= 2,	

	PLQC_Mode		= 0,	CS_Mode			= 1,	Other_Mode		= 2,	Mode_MAX		= 3,			
	
	VERSION_STEP	= 0,	CHECKSUM_STEP	= 1,	LED_1888_STEP	= 2,	KEY_CHK_STEP	= 3,	WIFI_STEP	= 4,	Final_STEP		= 5,	STEP_MAX		= 6,			
	
	Real_Option		= 0,	FCT_Recv_OP		= 1,	FCT_Send_OP		= 2,	PC_Recv_OP		= 3,	PC_Send_OP	= 4,	OptionInfo_MAX	= 5,

	PlatChk_Request	= 0,	PlatChk_Working	= 1,	PlatChk_Finish	= 2,
	
	BPS_9600		= 0,	BPS_19200		= 1,	BPS_115200		= 2,	BPS_MAX 		= 3,
	
	SUB_STE_STANDBY	= 0,	SUB_STE_INITIAL	= 1,	STATE_LQCTEST	= 2,
	
	NT_DOOR_Sensing	= 0,	NT_DOOR_OPEN	= 1,	NT_DOOR_CLOSE	= 2,
	
	NA				= 255
};

typedef enum
{
	STX_NORMAL		= 2,	ETX_NORMAL		= 3,
		
	STX_NT_CRITICAL	= 0x55, ETX_NT_CRITICAL	= 0xAA,

	STX_OPTION		= 0xAA,	ETX_OPTION		= 0x55,

	STX_PC			= 0xAA,	ETX_PC			= 0x55,
	
	ACK				= 6,	NAK				= 21,
	
}T_STXVar;


/**********************************************************************/	//Uart Data Size

static UINT8	gaucSendBuffer[255],	gaucRecvBuffer[70];

static UINT8	OP_gaucSendBuffer[255],	OP_gaucRecvBuffer[70];

static UINT8	PC_gaucSendBuffer[255],	PC_gaucRecvBuffer[70];

/**********************************************************************/	//Beeper Power on

#define VVC_Power_ON			0x00	//00000000
#define Topgun_WW_Power_ON		0x01	//00000001
#define Mini_Power_ON			0x02	//00000010
#define Topgun_Amr_Power_ON		0x00	//00000000
#define Mega_Titan_Power_ON		0x00
#define New_Topgun_Power_ON		0x01	//00000001
#define LCD_VX_NT_Power_ON		0x01	//00000001
#define LCD_VXD_Dryer_Power_ON	0x03	//00000001	0x43	01000011	0xC3	11000011
#define GVX_Power_ON			0x00	//00000000
#define GVX_Dryer_Power_ON		0x03	//00000000
#define New_Mini_Power_ON		0x02	//00000000

/**********************************************************************/	//Beeper Power off

#define VVC_Power_OFF			0x03	//00000011
#define Topgun_WW_Power_OFF		0x04	//00000100
#define Mini_Power_OFF			0x09	//00001001
#define Topgun_Amr_Power_OFF	0x03	//00000011
#define Mega_Titan_Power_OFF	0x03
#define New_Topgun_Power_OFF	0x04	//00000100
#define LCD_VX_NT_Power_OFF		0x04	//00000001
#define LCD_VXD_Dryer_Power_OFF	0x04	//00000001	0x04	00000100	0x84	10000100
#define GVX_Power_OFF			0x03	//00000011
#define GVX_Dryer_Power_OFF		0x04	//00000011
#define New_Mini_Power_OFF		0x09	//00000011

/**********************************************************************/	//Beeper Key in

#define VVC_KEY_IN				0x01	//00000001
#define Topgun_WW_KEY_IN		0x02	//00000010
#define Mini_KEY_IN				0x0D	//00001101
#define Topgun_Amr_KEY_IN		0x01	//00000001
#define Mega_Titan_KEY_IN		0x01
#define New_Topgun_KEY_IN		0x02	//00000010
#define LCD_VX_NT_KEY_IN		0x02	//00000001
#define LCD_VXD_Dryer_KEY_IN	0x02	//00000001
#define GVX_KEY_IN				0x01	//00000001
#define GVX_Dryer_KEY_IN		0x00	//00000001  buzzer key in 0x02 no use
#define New_Mini_KEY_IN			0x0D	//00000001

/**********************************************************************/	//Beeper Deny

#define VVC_DUMMY				0x0F	//00001111
#define Topgun_WW_DUMMY			0x00	//00000000
#define Mini_Power_DUMMY		0x00	//00000000
#define Topgun_Amr_DUMMY		0x0D	//00001101
#define Mega_Titan_DUMMY		0x0F		
#define New_Topgun_DUMMY		0x00	//00000000
#define LCD_VX_NT_DUMMY			0x00	//00000001
#define LCD_VXD_Dryer_DUMMY		0x00	//00000001
#define GVX_DUMMY				0x0F	//00001111
#define GVX_Dryer_DUMMY			0x00	//00001111
#define New_Mini_DUMMY			0x00	//00001111

/**********************************************************************/	//Beeper Error

#define VVC_Error				0x11	//00010001
#define Topgun_WW_Error			0x0F	//00001111
#define Mini_Error				0x11	//00010001
#define Topgun_Amr_Error		0x10	//00010000
#define Mega_Titan_Error		0x11	//00010001
#define New_Topgun_Error		0x0F	//00001111
#define LCD_VX_NT_Error			0x05	//00000001
#define LCD_VXD_Dryer_Error		0x05	//00000001
#define GVX_Error				0x11	//00010001
#define GVX_Dryer_Error			0x05	//00010001
#define New_Mini_Error			0x11	//00010001


#endif
/* THE END */

