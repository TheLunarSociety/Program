



void WROS_FUNC_LQC_ModeProcess(T_DispInfo*);
void Cmp_LQC_ModeProcess(T_DispInfo*);
void Init_LQCTestModeProcess(T_DispInfo*);


void LQC_Display_POWER_ON_OFF(T_DispInfo*);
void TestControlStep_LQC_Normal(UINT8,T_DispInfo*);
void OptionKeyInBeep(T_DispInfo*);

void LQC_CHECKSUM_CheckStep(T_DispInfo*);
void LQC_1888_CheckStep(T_DispInfo*);
void LQC_LED_CheckStep(T_DispInfo*);
void LQC_WIFI_CheckStep(T_DispInfo*);
void LQC_Normal_FinalStep(T_DispInfo*);

//void LQC_Normal_DispCheckStep(void);

UINT8 Comm_KeyValue(void);

void GetBeeperCounter(T_DispInfo*, UINT8);


