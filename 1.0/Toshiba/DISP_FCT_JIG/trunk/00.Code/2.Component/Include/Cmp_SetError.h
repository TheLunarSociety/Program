
#ifdef	__SETERROR_H__
#define	EXTR
#else
#define	EXTR	extern
#endif

void WROS_FUNC_Error_Check(T_DispInfo*);

void Cmp_Error_Check(T_DispInfo*);
UINT8 StandByErrorCheck(UINT8);
UINT8 DE4ErrorCheck(UINT8);

typedef enum
{
	SE_ERROR_STEP,
	DE_ERROR_STEP,
	ERROR_MAX,
}T_ERROR_STEP;

static UINT8 (* const ErrorCheck[])(UINT8) = 
{
	StandByErrorCheck,
	DE4ErrorCheck,
};

EXTR UINT8 PRE_ERROR;
EXTR UINT8 ERROR_State;

#undef	EXTR


