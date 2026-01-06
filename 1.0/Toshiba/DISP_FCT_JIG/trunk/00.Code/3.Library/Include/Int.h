#include "../../4.Driver/Include/WROS_Register.h"
#ifndef __INC_INT_LIB__
#define __INC_INT_LIB__

#ifdef	ROOT
#define	EXTR
#else
#define	EXTR	extern
#endif

#define	CHECKSUM_KEY	((WROS_____PE->DATA >> 4) & BIN4(1100))
#define	CHOOSE_KEY		((WROS_____PE->DATA >> 4) & BIN4(0011))

#define STANDBY_SIGNAL				GPIO_DATA(A, 7)	//PA_DATA_PA7 

#define Door_SIG_SIGNAL				GPIO_DATA(E, 2)	//PE_DATA_PE2		//	Main -> Display
#define Door_SEN_SIGNAL				GPIO_DATA(E, 3)	//PE_DATA_PE3		//	Display -> Main

/*****************************************************************************
	DD Type(BLDCM) Washing Machine Program
	Model				: Panacea-PJT
	Version				: Ver 1.0
	CPU					: MN103SFE4K
	File type				: C header file
	File name				: int.h
	Included Funtion		: 

	Description			: timer interrupt control function & variable
	be coded by KIM KYUNG HOON
********************************************************************************/


EXTR	UINT8	gunKey_New;


//EXTR	UINT8		Door_SEN_SIGNAL_Flag;
//EXTR	UINT8		Door_SIG_SIGNAL_Flag;





#define 	LED_SCAN_LINE_MAX		3

#define 	LED_SCAN_LINE_0_3       WROS_____PC->DATA
#define	SCAN_LINE_0			GPIO_DATA(C, 3)//PC_DATA_PC3
#define	SCAN_LINE_1			GPIO_DATA(C, 2)//PC_DATA_PC2
#define	SCAN_LINE_2			GPIO_DATA(C, 1)//PC_DATA_PC1
#define	SCAN_LINE_3			GPIO_DATA(C, 0)//PC_DATA_PC0


#define 	LED_DATA_LINE_A_G       WROS_____PA->DATA
#define	LED_DATA_LINE_A		GPIO_DATA(A, 0)//PA_DATA_PA0
#define	LED_DATA_LINE_B		GPIO_DATA(A, 1)//PA_DATA_PA1
#define	LED_DATA_LINE_C		GPIO_DATA(A, 2)//PA_DATA_PA2
#define	LED_DATA_LINE_D		GPIO_DATA(A, 3)//PA_DATA_PA3
#define	LED_DATA_LINE_E		GPIO_DATA(A, 4)//PA_DATA_PA4
#define	LED_DATA_LINE_F		GPIO_DATA(A, 5)//PA_DATA_PA5
#define	LED_DATA_LINE_G		GPIO_DATA(A, 6)//PA_DATA_PA6

//#define	HW_UP_KEY			PE_DATA_PE4
//#define	HW_DOWN_KEY			PE_DATA_PE5
#define	HW_SELECT_KEY		GPIO_DATA(E, 6)//PE_DATA_PE6
#define	HW_RESULT_KEY		GPIO_DATA(E, 7)//PE_DATA_PE7
/**********************************************************************
		<Function>
**********************************************************************/
void	MWI_INT_Timer0(void);
UINT32	timer_1s_calc(void);
void	Timer_TimeInc(void);		
UINT8	Timer_MsecCheckPassTime(T_Time*, UINT32);	
void	Timer_GetTime(T_Time*);

static	T_Time mstTimeCheckBaseTimer;

#undef	EXTR
#endif




// END OF File
