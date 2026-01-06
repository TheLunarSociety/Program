

#ifndef __M470_INT_H
#define __M470_INT_H

#ifdef DEFINE_APP_INT
#define EXTERN_INT
#else
#define EXTERN_INT  extern
#endif

/******************************************/
/***	- PROTO TYPE DEFINITION -		***/
/******************************************/
EXTERN_INT		void		API_INT_Init(void);
EXTERN_INT		void		API_INT_Clear_Init(void);
EXTERN_INT		void		API_INT_PR_Reset(void);
EXTERN_INT		void		API_CG_Active_Reset(void);
EXTERN_INT		void		TOTAL_PENDING_CLEAR(void);

/**************************************************************/
#undef EXTERN_INT
#endif /* __M470_INT_H */

/*************************** END OF FILE **************************************/
