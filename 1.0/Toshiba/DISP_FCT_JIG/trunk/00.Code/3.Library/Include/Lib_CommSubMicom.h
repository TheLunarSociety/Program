
/*******************************************************************
* Main - Display Uart communication define
*******************************************************************/



enum	// LQC Functions
{
	LQC_FUNC_INIT,					//	0
	LQC_FUNC_MODEM_UART_CHK,		//	1
	LQC_FUNC_WAIT,					//	2
	LQC_FUNC_TUMBLE_CW,				//	3
	LQC_FUNC_TUMBLE_CCW,			//	4
	LQC_FUNC_WATER_FREQ,			//	5
	LQC_FUNC_STEAM_SENSE,			//	6
	LQC_FUNC_PRE_VALVE,				//	7
	LQC_FUNC_COLD_VALVE,			//	8
	LQC_FUNC_HOT_VALVE,				//	9
	LQC_FUNC_DRY_VALVE,				//	10
	LQC_FUNC_STEAM_VALVE,			//	11
	LQC_FUNC_BLEACH_VALVE,			//	12
	LQC_FUNC_CIR_PUMP,				//	13
	LQC_FUNC_DRAIN_PUMP,			//	14
	LQC_FUNC_WASH_HEATER,			//	15
	LQC_FUNC_STEAM_HEATER,			//	16
	LQC_FUNC_DRY_HEATER,			//	17
	LQC_FUNC_LOW_RPM,				//	18
	LQC_FUNC_HIGH_RPM,				//	19
	LQC_FUNC_HIGH_RPM_N_MODEM_CHK,	//	20
	LQC_FUNC_DRY_FAN,				//	21
	LQC_FUNC_DRY,					//	22
	LQC_FUNC_FINAL_MODEM_CHK,		//	23
	LQC_FUNC_AUTO_WAIT,				//	24
	LQC_FUNC_VER_HEATER_CIR,		//	25
	LQC_FUNC_PRE_COLD_DOUBLE_VAVLE,	//	26
	LQC_FUNC_HOT_DRY_DOUBLE_VALVE,	//	27
	LQC_FUNC_HOT_PRE_DOUBLE_VALVE,	//	28
	LQC_FUNC_HOT_STEAM_DOUBLE_VALVE,//	29
	LQC_FUNC_PRE_BLEACH_DOUBLE_VALVE,//	30
	LQC_FUNC_DRY_DRAIN,				//	31
	LQC_FUNC_HIGH_RPM_N_CHK_TIME,	//	32
	LQC_FUN_AUTO_LQC_TOUCH_UART_ERROR_CHK,
	LQC_FUNC_END,					//	34

	LQC_FUNC_NFC_INIT,
	LQC_FUNC_NFC_MOTOR,
	LQC_FUNC_NFC_PRE_VALVE,
	LQC_FUNC_NFC_HOT_VALVE,
	LQC_FUNC_NFC_DRAIN_PUMP,
	LQC_FUNC_NFC_END,

	FCT_FUNC_STEP_NUM
};

enum	// LQC Functions
{

	WI_STATE_POWEROFF,
	WI_STATE_INITIAL,
	WI_STATE_PAUSE,	
	WI_STATE_DETECTING
};



#define	COMM_MODE_NORMAL				0
#define	COMM_MODE_DATA_VIEW				1
#define	COMM_MODE_LQC_TEST				2


#define	DRAWING_CLOSE					0x04
#define	DRAWING_OPEN					0x00



void	Comm_DispSetPacket_Normal(UINT8*,T_DispInfo*,UINT8);
void	Comm_DispRecvPacket_Normal(UINT8,UINT8*);
void	Comm_OptionSetPacket_Normal(UINT8*,T_DispInfo*,UINT8);
void	Comm_OptionRecvPacket_Normal(UINT8,UINT8*);
void	Comm_PCSetPacket_Normal(UINT8*,T_DispInfo*,UINT8);
void 	Comm_PCRecvPacket_Normal(UINT8,UINT8*);

UINT16	Uart_CRCMaker(UINT8* , UINT8 );
void	Uart_CrcPacketEncode(UINT8*,UINT8,UINT8);
UINT8 Uart_CrcPacketCheck(T_DispInfo*, UINT8*);

void	Comm_SetKeyValue_1(UINT8,UINT8);
void	Comm_SetKeyValue_2(UINT8,UINT8);
void	Comm_SetKeyValue_3(UINT8,UINT8);
void	SET_STX(UINT8);
void	Comm_SetPCOption(UINT8);
UINT16*	Get_OPTION(void);

UINT8	Comm_GetKeyValue(void);
UINT8	Comm_GetKeyCount(void);
void	ClearKeyValue(void);

UINT8	Get_PanelType(void);
void	SetACK(UINT8);
void	SetKeyChkF(UINT8);

UINT8	DataReadWriteDataMemory(UINT8, UINT8, UINT8);


// End Of File

