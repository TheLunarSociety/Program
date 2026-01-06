
#ifndef __M470_WDT_H
#define __M470_WDT_H

#ifdef DEFINE_APP_WDT
#define EXTERN_WDT
#else
#define EXTERN_WDT  extern
#endif

#define		WDT_DISABLECODE			(0xB1)
#define		WDT_CLEARCODE			(0x4E)

/******************************************/
/***	- PROTO TYPE DEFINITION -		***/
/******************************************/
EXTERN_WDT		void		WROS_WDT_Init(void);
EXTERN_WDT		void		API_WDT_Set_WdtClr(void);
EXTERN_WDT		void		API_WDT_Disable(void);
EXTERN_WDT		void		API_WDT_RESET_Init(void);
EXTERN_WDT		void		API_WDT_Set_Wdt_Nmi_Clr(void);

/**************************************************************/
#undef EXTERN_WDT
#endif /* __M470_WDT_H */

/*************************** END OF FILE **************************************/
