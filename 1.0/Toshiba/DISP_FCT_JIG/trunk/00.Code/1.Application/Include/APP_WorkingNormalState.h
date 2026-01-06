

#ifdef	__WORKINGNORMAL
#define	EXTR
#else
#define	EXTR	extern
#endif


void WROS_FUNC_Run(T_DispInfo*);
void App_Init_State(T_DispInfo*);
void WROS_FUNC_Set_Platform(T_DispInfo*);
void Cmp_Set_Platform(T_DispInfo*);

EXTR T_UByteBit BITFlag;
#define	Onboarding_ModelFlag	BITFlag.BIT.B0
#define	gunOpWriteFlag			BITFlag.BIT.B1
#define	Memory_Flag				BITFlag.BIT.B2
#define	EEPROM_Flag				BITFlag.BIT.B3
#define	ErrorCheckFlag			BITFlag.BIT.B4
#define	Door_SEN_SIGNAL_Flag	BITFlag.BIT.B5
#define	Door_SIG_SIGNAL_Flag	BITFlag.BIT.B6
#define	STANDBY_SIGNAL_Flag		BITFlag.BIT.B7



#undef EXTR
