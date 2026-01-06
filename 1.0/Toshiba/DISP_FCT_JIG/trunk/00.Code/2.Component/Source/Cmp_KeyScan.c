#include <stdlib.h>
#include <string.h>


#include "../../1.Application/Include/APP_WorkingNormalState.h"

#include "../../2.Component/Include/Cmp_KeyScan.h"
#include "../../2.Component/Include/Cmp_SetError.h"

#include "../../3.Library/Include/Int.h"


#include "../../6.VariableSource/Include/Vable_ModelInformation.h"


UINT8 gunKey_Set = JIG_CONF_KEY;


typedef struct T_KEY_StructList
{
	UINT8 stSelectedKey;
	void (*KeyFunction)(T_DispInfo*);
}T_KEY_Struct;


#ifdef ROTARY_KEY

static const T_KEY_Struct mastKeyTable[] =
{
	{BIN8(0000,0000),	No_Key							},
	{BIN8(0000,0001),	JigInputProc_SubtractKey		},
	{BIN8(0000,0010),	JigInputProc_AugmentKey			},
	{BIN8(0000,0100),	JigInputProc_OnBoardingKey		},
	{BIN8(0000,1000),	JigInputProc_ConfirmKey			},
	{BIN8(0100,0000),	JigInputProc_LongOnBoardingKey	},
	{BIN8(1000,0000),	JigInputProc_LongConfirmKey		},
};

#else

static const T_KEY_Struct mastKeyTable[] =
{
	{BIN8(0000,0000),	No_Key							},
	{BIN8(0000,0001),	JigInputProc_ConfirmKey			},
	{BIN8(0000,0010),	JigInputProc_ConfirmKey			},
	{BIN8(0000,0100),	JigInputProc_ConfirmKey			},
	{BIN8(0000,1000),	JigInputProc_ConfirmKey			},
	{BIN8(1000,0000),	No_Key							},
	{BIN8(0010,0000),	No_Key							},
};

#endif


void WROS_FUNC_JIG_KeyScan(T_DispInfo* psDisplayInfo)
{
	while(1)
	{
		MAKE_TEST_POINT(KEY_FLAG);
		Cmp_JIG_KeyScan(psDisplayInfo);
	}
}

void Cmp_JIG_KeyScan(T_DispInfo* psDisplayInfo)
{	
	UINT8 i = 0;
	for(i = 0;	i <= (sizeof(mastKeyTable) / sizeof(T_KEY_Struct) - 1);	i++)
	{
		if(gunKey_New == mastKeyTable[i].stSelectedKey ) 
		{
			gunKey_New = NO_KEY;
			mastKeyTable[i].KeyFunction(psDisplayInfo);
		}
		else
		{	;
		}
	}

}

void No_Key(T_DispInfo* psDisplayInfo)
{
	;
}

void JigInputProc_AugmentKey(T_DispInfo* psDisplayInfo)
{
	if(gunKey_Set != JIG_CONF_KEY)
	{
		gunKey_Set = JIG_SUBTRACT_KEY;
	}
	else
	{	;
	}
}

void JigInputProc_SubtractKey(T_DispInfo* psDisplayInfo)
{	
	if(gunKey_Set != JIG_CONF_KEY)
	{
		gunKey_Set = JIG_SUBTRACT_KEY;
	}
	else
	{	;
	}
}
void JigInputProc_ConfirmKey(T_DispInfo* psDisplayInfo)
{
	gunKey_Set = JIG_CONF_KEY;												//The pupose what i set ulKey_New is to lock key

	ErrorCheckFlag = CLEAR;
	PRE_ERROR = CLEAR;
	ERROR_State = CLEAR;
}
void JigInputProc_LongConfirmKey(T_DispInfo* psDisplayInfo)
{
	gunKey_Set = JIG_L_CONF_KEY;											//The pupose what i set ulKey_New is to lock key

	Onboarding_ModelFlag = CLEAR;
}
void JigInputProc_OnBoardingKey(T_DispInfo* psDisplayInfo)
{
	;
}
void JigInputProc_LongOnBoardingKey(T_DispInfo* psDisplayInfo)
{	
	#ifdef OPTION_ONBOARDING
	if(psDisplayInfo->DispType == Vivace)
	{
		ErrorCheckFlag = CLEAR;
		Onboarding_ModelFlag = ~Onboarding_ModelFlag;
	}
	else
	{	;
	}
	#endif
}

UINT8 Get_JigKey(void)
{
	return gunKey_Set;
}

