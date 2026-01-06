




#include "../../4_Library/Include/general.h"


#ifdef __WORKINGNORMAL
#define EXTR
#else
#define EXTR extern
#endif



void Run(UINT16);


EXTR UINT32 MemorySpace[8];



EXTR T_UByteBit BITFlag;

#define Onboarding_ModelFlag		BITFlag.BIT.B0
#define BPS_Choose_Flag				BITFlag.BIT.B1
#define Memory_Flag					BITFlag.BIT.B2
#define EEPROM_Flag					BITFlag.BIT.B3



#undef EXTR




