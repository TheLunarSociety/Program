


#ifndef _LED_DIS_SERVICE_
#define _LED_DIS_SERVICE_

#ifdef	__LEDDISPLAY__
#define	EXTR
#else
#define	EXTR	extern
#endif

EXTR TYPE_WORD gu8LED_Data[4];		// LED OUTPUT DATA

void WROS_FUNC_JIG_Display(T_DispInfo*);
void Cmp_JIG_Display(T_DispInfo*);

#undef	EXTR
#endif
