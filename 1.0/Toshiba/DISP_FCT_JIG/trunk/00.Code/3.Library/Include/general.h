/****************************************************************
 *	   TLCS-870X C Compiler I/O Type Definition File		    *
 *																*
 *			For : W/M Viking model S/W made in LG	   			*
 *																*
 * Copyright(C) 1996,97 LG W.M Control Gr. CORPORATION          *
 * 										  All rights reserved   *
 ****************************************************************/

#include <stddef.h>
/*=================== Data Type ======================*/
#ifndef _GENERAL_H_
#define _GENERAL_H_



typedef unsigned char 		U8;

typedef unsigned char 		UINT8;
typedef unsigned char 		uint8_t;

typedef signed char 		INT8;
typedef signed char 		int8_t;

typedef unsigned short	 	UINT16;
typedef unsigned short	 	uint16_t;


typedef signed short 		INT16;
typedef signed short 		int16_t;

typedef unsigned long 		UINT32;
typedef unsigned long 		uint32_t;

typedef signed long 		INT32;
typedef signed long 		int32_t;

typedef size_t 				SIZE_T;



/***For Toshiba Pin Setting***/
#define BIN4(a)  ( ((0x ## a ## L & 0x00000001L) >>  0)  \
                |  ((0x ## a ## L & 0x00000010L) >>  3)  \
                |  ((0x ## a ## L & 0x00000100L) >>  6)  \
                |  ((0x ## a ## L & 0x00001000L) >>  9) )

#define BIN8(a, b)  \
	( (uint8_t)(((0x0F & (BIN4(a))) << 4) | (0x0F & (BIN4(b)))) )

#define BIN16(a, b, c, d)  \
	( (uint16_t)(((0x00FF & (uint16_t)(BIN8(a, b))) << 8) | (0x00FF & (uint16_t)(BIN8(c, d)))) )

#define BIN32(a, b, c, d, e, f, g, h)  \
	( (uint32_t)(((0x0000FFFF & (uint32_t)(BIN16(a, b, c, d))) << 16) | (0x0000FFFF & (uint32_t)(BIN16(e, f, g, h)))) )

/*--------------------------------------------------------------------------
---------------------------------------------------------------------------*/


typedef union 
{
	unsigned char BYTE;					// Byte Access
	struct 
	{						// Bit Access		// "Caution" bit order.
		unsigned char B7:1;				// Bit 7
		unsigned char B6:1;				// Bit 6
		unsigned char B5:1;				// Bit 5
		unsigned char B4:1;				// Bit 4
		unsigned char B3:1;				// Bit 3
		unsigned char B2:1;				// Bit 2
		unsigned char B1:1;				// Bit 1
		unsigned char B0:1;				// Bit 0
	}BIT;
}T_UByteBit;

typedef struct
{
	UINT8 ucBufferMonitoring[255];
}TxBufMon_T;

typedef struct
{
	UINT8 ucBufferMonitoring[70];
}RxBufMon_T;

typedef struct
{
	UINT8 DispType;
	UINT8 MainStatus;
	UINT8 mucLogLqcStep;
	UINT8 BeepStatus;
	UINT8 PlatCheckStep;
	UINT8 DispAnsChk;
	
	struct T_UartInfo
	{
		UINT8 UartRx_Index;
		UINT8 UartRx_Finish;
		UINT8 UartRx_PktSize;
		UINT8 UartTx_Index;
		UINT8 UartTx_Finish;
		UINT8 UartTx_PktSize;
		UINT16 UartDateCRC;
		UINT16 UartRealCRC;
		UINT8 CommMode[4];
		UINT8 CurCommMode;
		TxBufMon_T* UartTxBuff;
		RxBufMon_T* UartRxBuff;
	}UartInfo;
	
}T_DispInfo;

typedef	struct
{
	UINT16	RealDspOption;
	UINT16	RecvDspOption;
	UINT16	RecvPCOption;
}T_OptionInfo;

typedef	struct
{
	UINT8*	pstSendBuffer;
	UINT8*	pstRecvBuffer;
	UINT8	ucStx;
	UINT8	ucEtx;
}T_BufferDef;

typedef void (*RPC_SEND_PACKET_TYPE)(T_DispInfo*,UINT8);
typedef void (*RPC_RECV_PACKET_TYPE)(T_DispInfo*,UINT8);

typedef	struct
{
	RPC_SEND_PACKET_TYPE	pSendFunc;
	RPC_RECV_PACKET_TYPE	pRecvFunc;
}T_UartCommDef;

typedef struct {
	unsigned char b7:1;
	unsigned char b6:1;
	unsigned char b5:1;
	unsigned char b4:1;
	unsigned char b3:1;
	unsigned char b2:1;
	unsigned char b1:1;
	unsigned char b0:1;
	unsigned char b15:1;
	unsigned char b14:1;
	unsigned char b13:1;
	unsigned char b12:1;
	unsigned char b11:1;
	unsigned char b10:1;
	unsigned char b9:1;
	unsigned char b8:1;
} WORD_FIELD;


typedef union {
	unsigned int		word;
	unsigned char		byte[2];
	WORD_FIELD 		bit;
} TYPE_WORD;


typedef struct
{
	UINT32 ulLow;
}T_Time;


typedef void	(*void_DispInfo_func)	(T_DispInfo*);
typedef void	(*void_Pointer_func)		( void * );


typedef void	(*void_void_func)		(void);
typedef void	(*void_UINT32_func)		(UINT32);
typedef UINT32	(*UINT32_void_func)		(void);
typedef UINT32	(*UINT32_UINT32_func)	(UINT32);




/**********************************************************************
		<4. External Variable>
**********************************************************************/
/**********************************************************************
		<5. External Function>
**********************************************************************/
/**********************************************************************
		<6. Local Constant Variable>
**********************************************************************/
/**********************************************************************
		<7. Global Variable>
**********************************************************************/
/**********************************************************************
		<8. Static Variable>
**********************************************************************/
/**********************************************************************
		<9. Local Function Prototype>
**********************************************************************/
/**********************************************************************
		<10. Local Funtion>
**********************************************************************/

enum
{
	CLEAR			= 0,	SET				= 1,
		
	OFF				= 0,	ON				= 1,
		
	DISABLE			= 0,	ENABLE			= 1,
	
	RETURN_NG		= 0,	RETURN_OK		= 1,
	
	WRITE			= 0,	READ			= 1,
	
	DOOR_OPEN		= 0,	DOOR_CLOSE		= 1,
};


typedef enum
{
	mucACK,				// 0
	mucKeyChkFlag,		// 1
	mucPanelType,		// 2
	mucDoorState,		// 3
	mucWifiState,		// 4
	mucBeeperCounter,	// 5
	mucDispEnable,		// 6
	mucDispCheckTimes,	// 7
	mucDataMemoryMax,	// 8
}DataMemory;


#endif

#define	MIN_Limite(X, MINlimit,MAXlimit)	((X)<(MINlimit) ? (X)=MAXlimit : (X) )
#define	MAX_Limite(X, MINlimit,MAXlimit)	((X)>(MAXlimit) ? (X)=MINlimit : (X) )
#define CounterAddLimit(X, MIN,	MAX)		(X < MAX ? ++X : (X = MIN))

#define	SIZE_OF_ARRAY(Variable)		( sizeof(Variable) / sizeof(Variable[0]))

#define	GET_HIGH_1BYTE(Data)			((UINT8)((Data) >> 8))
#define	GET_LOW_1BYTE(Data)				((UINT8)((Data) & 0xFF))


#define	TMPM470	0
#define	TMPM380	1
#define	A34M418	2

extern UINT8 MCU_TYPE;
/**********************************************************************/	//Normal KEY

/**********************************************************************/	//


