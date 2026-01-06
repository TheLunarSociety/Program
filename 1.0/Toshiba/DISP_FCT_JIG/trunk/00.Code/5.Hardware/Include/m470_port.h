/*******************************************************************************
*
* @file:    m470_port.h
* @purpose: Input/Output Ports Header File
*           for the TOSHIBA 'TMPM470' Device Series
* @version: V1.0.0.0
* @date:    2017/03/07
*
*-------------------------------------------------------------------------------
* --Notice--
*  The information contained herein has been carefully checked
* and is believed to be reliable. However, no responsibility can be
* assumed for inaccuracies that may not have been detected. The
* information contained herein is subject to change without notice.
*  The information contained herein is presented only as a guide
* for the application of our products. No responsibility is assumed
* by TOSHIBA for any infringements of patents or other rights of
* the third parties which may result from its use. No license is
* granted by implication or otherwise under any patent or patent
* rights of TOSHIBA or others.
*-------------------------------------------------------------------------------
*  Copyright(C) TOSHIBA CORPORATION 2017 All rights reserved
********************************************************************************/


#ifndef __M470_PORT_H
#define __M470_PORT_H

#ifdef DEFINE_APP_PORT
#define EXTERN_PORT
#else
#define EXTERN_PORT  extern
#endif

///////////////////////////////////////////////////////////////////////////////////////////////
// BLDC Model /////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
/* PORT initial data */
#define IOB8(y)  ( ((0x##y##L & 0x00000001L) >>  0) \
                 | ((0x##y##L & 0x00000010L) >>  3) \
                 | ((0x##y##L & 0x00000100L) >>  6) \
                 | ((0x##y##L & 0x00001000L) >>  9) \
                 | ((0x##y##L & 0x00010000L) >> 12) \
                 | ((0x##y##L & 0x00100000L) >> 15) \
                 | ((0x##y##L & 0x01000000L) >> 18) \
                 | ((0x##y##L & 0x10000000L) >> 21) )
                 
/*-------------------------------------------------------------------------------
PORT A 			Dataline PA0-6 Output		Standby PA7 Iutput
-------------------------------------------------------------------------------*/
#define		PORT_A_DT	((uint32_t)IOB8(00000000))
#define  	PORT_A_CR 	((uint32_t)IOB8(01111111))
#define  	PORT_A_FR1 	((uint32_t)IOB8(00000000))
#define		PORT_A_FR2	((uint32_t)IOB8(00000000))
#define		PORT_A_OD	((uint32_t)IOB8(00000000))
#define		PORT_A_PUP	((uint32_t)IOB8(00000000))
#define		PORT_A_PDN	((uint32_t)IOB8(00000000))
#define		PORT_A_IE	((uint32_t)IOB8(10000000))
							/* 0		|||||||+--- (63) bit0:		GND 																*/
							/* 1		||||||+---- (64) bit1:		GND 																*/
							/* 2		|||||+----- (65) bit2:		GND 																*/
							/* 3		||||+------ (66) bit3:-	I/O TMS 																	*/
							/* 4		|||+------- (67) bit4:-	I	TCK 																	*/
							/* 5		||+-------- (68) bit5:- O	TD0 																	*/
							/* 6		|+--------- (69) bit6:- I	TDI 																	*/
							/* 7		+---------- (70) bit7:- I	TDAS																		*/

/*-------------------------------------------------------------------------------
PORT B			GND	PB0-2					Debug PB3-7 
-------------------------------------------------------------------------------*/
#define		PORT_B_DT	((uint32_t)IOB8(00000000))
#define		PORT_B_CR	((uint32_t)IOB8(00101000)) 
#define		PORT_B_FR1	((uint32_t)IOB8(11111000))  
#define		PORT_B_PUP	((uint32_t)IOB8(11001000)) 	
#define		PORT_B_PDN	((uint32_t)IOB8(00010111))  
#define		PORT_B_IE	((uint32_t)IOB8(11011000)) 
							/* 0        |||||||+--- (63) bit0: 		GND																	*/
							/* 1        ||||||+---- (64) bit1: 		GND																	*/
							/* 2        |||||+----- (65) bit2: 		GND																	*/
							/* 3        ||||+------ (66) bit3:-	I/O	TMS																		*/
							/* 4        |||+------- (67) bit4:-	I 	TCK																		*/
							/* 5        ||+-------- (68) bit5:-	O	TD0																		*/
							/* 6        |+--------- (69) bit6:-	I 	TDI																		*/
							/* 7        +---------- (70) bit7:-	I 	TDAS																		*/


/*-------------------------------------------------------------------------------
PORT C 			Scanline PC0-3 Output		 GND PC5-7
-------------------------------------------------------------------------------*/
#define		PORT_C_DT	((uint32_t)IOB8(00000000))
#define		PORT_C_CR	((uint32_t)IOB8(00001111))
#define		PORT_C_FR1	((uint32_t)IOB8(00000000))
#define		PORT_C_OD	((uint32_t)IOB8(00000000))
#define		PORT_C_PUP	((uint32_t)IOB8(00000000))
#define		PORT_C_PDN	((uint32_t)IOB8(11110000))
#define		PORT_C_IE	((uint32_t)IOB8(00000000))
							/* 0		|||||||+--- (63) bit0:- I	SCAN1 																*/
							/* 1		||||||+---- (64) bit1:- I	SCAN2 																*/
							/* 2		|||||+----- (65) bit2:- I	SCAN3 																*/
							/* 3		||||+------ (66) bit3:- I	SCAN4																	*/
							/* 4		|||+------- (67) bit4: 		GND 																	*/
							/* 5		||+-------- (68) bit5: 		GND 																	*/
							/* 6		|+--------- (69) bit6: 		GND 																	*/
							/* 7		+---------- (70) bit7: 		GND																		*/
													
/*-------------------------------------------------------------------------------
PORT D 			GND PD0-6 					PD7 No have
-------------------------------------------------------------------------------*/

#ifdef	OPTION_ONBOARDING
#ifdef	EEPROM_MEMORY
//	yes Onboarding and yes EEPROM
#define		PORT_D_DT	((uint32_t)IOB8(00000000))
#define		PORT_D_CR	((uint32_t)IOB8(00111100))
#define		PORT_D_FR1	((uint32_t)IOB8(01100000))
#define		PORT_D_FR2	((uint32_t)IOB8(00000000))
#define		PORT_D_OD	((uint32_t)IOB8(00000000))
#define		PORT_D_PUP	((uint32_t)IOB8(00000000))
#define		PORT_D_PDN	((uint32_t)IOB8(00000001))
#define		PORT_D_IE	((uint32_t)IOB8(01000010))														
							/* 0		|||||||+--- (63) bit0:		GND																	*/
							/* 1		||||||+---- (64) bit1:- I	EEPROM Read															*/
							/* 2		|||||+----- (65) bit2:- O	EEPROM Write														*/
							/* 3		||||+------ (66) bit3:- O	EEPROM Chip Select													*/
							/* 4		|||+------- (67) bit4:- O	EEPROM Clock 														*/
							/* 5		||+-------- (68) bit5:- O	SC2TXD 																*/
							/* 6		|+--------- (69) bit6:- I	SC2RXD 																*/
							/* 7		+---------- (70) bit7:		No have 															*/
#else
//	yes Onboarding and no EEPROM
#define		PORT_D_DT	((uint32_t)IOB8(00000000))
#define		PORT_D_CR	((uint32_t)IOB8(00100000))
#define		PORT_D_FR1	((uint32_t)IOB8(01100000))
#define		PORT_D_FR2	((uint32_t)IOB8(00000000))
#define		PORT_D_OD	((uint32_t)IOB8(00000000))
#define		PORT_D_PUP	((uint32_t)IOB8(00000000))
#define		PORT_D_PDN	((uint32_t)IOB8(00000001))
#define		PORT_D_IE	((uint32_t)IOB8(01000000))														
							/* 0		|||||||+--- (63) bit0:		GND																	*/
							/* 1		||||||+---- (64) bit1:- I	EEPROM Read															*/
							/* 2		|||||+----- (65) bit2:- O	EEPROM Write														*/
							/* 3		||||+------ (66) bit3:- O	EEPROM Chip Select													*/
							/* 4		|||+------- (67) bit4:- O	EEPROM Clock 														*/
							/* 5		||+-------- (68) bit5:- O	SC2TXD 																*/
							/* 6		|+--------- (69) bit6:- I	SC2RXD 																*/
							/* 7		+---------- (70) bit7:		No have 															*/
#endif
#else
#ifdef	EEPROM_MEMORY
//	no Onboarding and yes EEPROM
#define		PORT_D_DT	((uint32_t)IOB8(00000000))
#define		PORT_D_CR	((uint32_t)IOB8(00011100))
#define		PORT_D_FR1	((uint32_t)IOB8(00000000))
#define		PORT_D_FR2	((uint32_t)IOB8(00000000))
#define		PORT_D_OD	((uint32_t)IOB8(00000000))
#define		PORT_D_PUP	((uint32_t)IOB8(00000000))
#define		PORT_D_PDN	((uint32_t)IOB8(00000001))
#define		PORT_D_IE	((uint32_t)IOB8(00000010))														
							/* 0		|||||||+--- (63) bit0:		GND																	*/
							/* 1		||||||+---- (64) bit1:- I	EEPROM Read															*/
							/* 2		|||||+----- (65) bit2:- O	EEPROM Write														*/
							/* 3		||||+------ (66) bit3:- O	EEPROM Chip Select													*/
							/* 4		|||+------- (67) bit4:- O	EEPROM Clock 														*/
							/* 5		||+-------- (68) bit5:- O	SC2TXD 																*/
							/* 6		|+--------- (69) bit6:- I	SC2RXD 																*/
							/* 7		+---------- (70) bit7:		No have 															*/
#else
//	no Onboarding and no EEPROM
#define		PORT_D_DT	((uint32_t)IOB8(00000000))
#define		PORT_D_CR	((uint32_t)IOB8(00000000))
#define		PORT_D_FR1	((uint32_t)IOB8(00000000))
#define		PORT_D_FR2	((uint32_t)IOB8(00000000))
#define		PORT_D_OD	((uint32_t)IOB8(00000000))
#define		PORT_D_PUP	((uint32_t)IOB8(00000000))
#define		PORT_D_PDN	((uint32_t)IOB8(00000001))
#define		PORT_D_IE	((uint32_t)IOB8(00000000))														
							/* 0		|||||||+--- (63) bit0:		GND																	*/
							/* 1		||||||+---- (64) bit1:- I	EEPROM Read															*/
							/* 2		|||||+----- (65) bit2:- O	EEPROM Write														*/
							/* 3		||||+------ (66) bit3:- O	EEPROM Chip Select													*/
							/* 4		|||+------- (67) bit4:- O	EEPROM Clock 														*/
							/* 5		||+-------- (68) bit5:- O	SC2TXD 																*/
							/* 6		|+--------- (69) bit6:- I	SC2RXD 																*/
							/* 7		+---------- (70) bit7:		No have 															*/
#endif
#endif
/*-------------------------------------------------------------------------------
PORT E 		 PE0 Ouput  PE1 Input  	 	 PE2-3 Sensing Input			PE4-7 key input
-------------------------------------------------------------------------------*/
#define		PORT_E_DT	((uint32_t)IOB8(00000000))
#define		PORT_E_CR	((uint32_t)IOB8(00000101))
#define		PORT_E_FR1	((uint32_t)IOB8(00000011))
#define		PORT_E_FR2	((uint32_t)IOB8(00000000))
#define		PORT_E_OD	((uint32_t)IOB8(00000000))
#define		PORT_E_PUP	((uint32_t)IOB8(00000011))
#define		PORT_E_PDN	((uint32_t)IOB8(00000000))
#define		PORT_E_IE	((uint32_t)IOB8(11111010))
							/* 0		|||||||+--- (12) bit0:- O	UartO (TX0)															*/
							/* 1		||||||+---- (13) bit1:- I	UartO (RX0)															*/
							/* 2		|||||+----- (14) bit2:- O 	Door_SIG															*/
							/* 3		||||+------ (15) bit3:- I 	Door_SENS				 											*/
							/* 4		|||+------- (17) bit4:- I 	Up_Key																*/
							/* 5		||+-------- (18) bit5:- I 	Down_Key															*/
							/* 6		|+--------- (19) bit6:- I   OK_Key																*/
							/* 7		+---------- (20) bit7:- i   Cancel_Key															*/


/*-------------------------------------------------------------------------------
PORT F PF1 flowmeter out put
-------------------------------------------------------------------------------*/

#define		PORT_F_DT	((uint32_t)IOB8(00000000))
#define  	PORT_F_CR 	((uint32_t)IOB8(00000001))
#define  	PORT_F_FR1 	((uint32_t)IOB8(00000000))
#define		PORT_F_FR2	((uint32_t)IOB8(00000000))
#define		PORT_F_FR3	((uint32_t)IOB8(00000000))
#define		PORT_F_OD	((uint32_t)IOB8(00000000))
#define		PORT_F_PUP	((uint32_t)IOB8(00000000))
#define		PORT_F_PDN	((uint32_t)IOB8(00011110))
#define  	PORT_F_IE 	((uint32_t)IOB8(00000000))
							/* 0		   ||||+--- (52) bit0:- O  	Chip Selection														*/
							/* 1		   |||+---- (53) bit1:		GND																	*/
							/* 2		   ||+----- (54) bit2:		GND																	*/
							/* 3		   |+------ (55) bit3:		GND																	*/
							/* 4		   +------- (56) bit4:		GND 																*/



/*-------------------------------------------------------------------------------
PORT G PG1-2 AC pump input PG3-4 door SW signal
-------------------------------------------------------------------------------*/
#define		PORT_G_DT	((uint32_t)IOB8(00000000))
#define  	PORT_G_CR 	((uint32_t)IOB8(00000000))
#define		PORT_G_FR1	((uint32_t)IOB8(00000000))
#define		PORT_G_OD	((uint32_t)IOB8(00000000))
#define		PORT_G_PUP	((uint32_t)IOB8(00000000))
#define		PORT_G_PDN	((uint32_t)IOB8(11111111))
#define		PORT_G_IE	((uint32_t)IOB8(00000000))								
							/* 0		|||||||+--- (63) bit0:		GND 															*/
							/* 1		||||||+---- (64) bit1:		GND 															*/
							/* 2		|||||+----- (65) bit2:		GND 															*/
							/* 3		||||+------ (66) bit3:		GND 																*/
							/* 4		|||+------- (67) bit4:		GND 																	*/
							/* 5		||+-------- (68) bit5:		GND 																	*/
							/* 6		|+--------- (69) bit6:		GND 																	*/
							/* 7		+---------- (70) bit7:		GND 																	*/


/*-------------------------------------------------------------------------------
PORT H 				PC3	DC(AINA3)
-------------------------------------------------------------------------------*/
#define		PORT_H_DT	((uint32_t)IOB8(00000000))
#define		PORT_H_CR	((uint32_t)IOB8(00000000))
#define		PORT_H_OD	((uint32_t)IOB8(00000000))
#define		PORT_H_PUP	((uint32_t)IOB8(00000000))
#define		PORT_H_PDN	((uint32_t)IOB8(11110111))
#define		PORT_H_IE	((uint32_t)IOB8(00000000))										
							/* 0		|||||||+--- (63) bit0:		GND 															*/
							/* 1		||||||+---- (64) bit1:		GND 															*/
							/* 2		|||||+----- (65) bit2:		GND 															*/
							/* 3		||||+------ (66) bit3:		DC(AINA3) 																*/
							/* 4		|||+------- (67) bit4:		GND 																	*/
							/* 5		||+-------- (68) bit5:		GND 																	*/
							/* 6		|+--------- (69) bit6:		GND 																	*/
							/* 7		+---------- (70) bit7:		GND 																	*/


/*-------------------------------------------------------------------------------
PORT P no use
-------------------------------------------------------------------------------*/
#define		PORT_P_DT	((uint32_t)IOB8(00000000))
#define		PORT_P_CR	((uint32_t)IOB8(00000000))
#define		PORT_P_OD	((uint32_t)IOB8(00000000))
#define		PORT_P_PUP	((uint32_t)IOB8(00000000))
#define		PORT_P_PDN	((uint32_t)IOB8(00001111))
#define		PORT_P_IE	((uint32_t)IOB8(00000000))
							/* 0			|||+--- (63) bit0:		GND 															*/
							/* 1			||+---- (64) bit1:		GND 															*/
							/* 2			|+----- (65) bit2:		GND 															*/
							/* 3			+------ (66) bit3:		GND 																*/
											
/*-------------------------------------------------------------------------------
PORT J no use
-------------------------------------------------------------------------------*/
#define		PORT_J_DT	((uint32_t)IOB8(00000000))
#define		PORT_J_CR	((uint32_t)IOB8(00000000)) 
#define		PORT_J_OD	((uint32_t)IOB8(00000000))
#define		PORT_J_PUP	((uint32_t)IOB8(00000000))
#define		PORT_J_PDN	((uint32_t)IOB8(11111111))
#define		PORT_J_IE	((uint32_t)IOB8(00000000))
							/* 0		|||||||+--- (63) bit0:		GND 															*/
							/* 1		||||||+---- (64) bit1:		GND 															*/
							/* 2		|||||+----- (65) bit2:		GND 															*/
							/* 3		||||+------ (66) bit3:		GND 																*/
							/* 4		|||+------- (67) bit4:		GND 																	*/
							/* 5		||+-------- (68) bit5:		GND 																	*/
							/* 6		|+--------- (69) bit6:		GND 																	*/
							/* 7		+---------- (70) bit7:		GND 																	*/

/*-------------------------------------------------------------------------------
PORT K no sue
-------------------------------------------------------------------------------*/
#define		PORT_K_DT	((uint32_t)IOB8(00000000))
#define		PORT_K_CR	((uint32_t)IOB8(00000000))
#define		PORT_K_FR1	((uint32_t)IOB8(00000000))
#define		PORT_K_OD	((uint32_t)IOB8(00000000))
#define		PORT_K_PUP	((uint32_t)IOB8(00000000))
#define		PORT_K_PDN	((uint32_t)IOB8(00000011))
#define		PORT_K_IE	((uint32_t)IOB8(00000000))																
								/* 0		  |+--- bit0:-  GND */
								/* 1		  +---- bit1:-  GND */


/*-------------------------------------------------------------------------------
PORT L no use
-------------------------------------------------------------------------------*/
#define		PORT_L_DT	((uint32_t)IOB8(00000000))
#define		PORT_L_CR	((uint32_t)IOB8(00000000))
#define		PORT_L_OD	((uint32_t)IOB8(00000000))
#define		PORT_L_PUP	((uint32_t)IOB8(00000000))
#define		PORT_L_PDN	((uint32_t)IOB8(00000011))
#define		PORT_L_IE	((uint32_t)IOB8(00000000))
								/* 0		  |+--- bit0:-  GND	*/
								/* 1		  +---- bit1:-  GND	*/

/*-------------------------------------------------------------------------------
PORT N
-------------------------------------------------------------------------------*/


#define		PORT_N_DT	((uint32_t)IOB8(00000000))
#define		PORT_N_CR	((uint32_t)IOB8(00000000))
#define		PORT_N_FR1	((uint32_t)IOB8(00000000))
#define		PORT_N_FR2	((uint32_t)IOB8(00000000))
#define		PORT_N_OD	((uint32_t)IOB8(00000000))
#define		PORT_N_PUP	((uint32_t)IOB8(00000000))
#define		PORT_N_PDN	((uint32_t)IOB8(00000111))
#define		PORT_N_IE	((uint32_t)IOB8(00000000))
								/* 0		 ||+--- bit0:-	GND */
								/* 1		 |+---- bit1:-	GND */
								/* 2		 +----- bit1:-	GND */


/********************/
/*** Port Channel ***/
/********************/
typedef enum { PORT_A = 0,
			   PORT_B = 1,
			   PORT_C = 2,
			   PORT_D = 3,
			   PORT_E = 4,
			   PORT_F = 5,
			   PORT_G = 6,
			   PORT_H = 7,
			   PORT_P = 8,
			   PORT_J = 9,
			   PORT_K = 10,
			   PORT_L = 11,
			   PORT_N = 12
			 } IpPORT_ChSel;							/* PORT CH data */

/******************/
/*** Bit Select ***/
/******************/
typedef enum { PORT_A0 = PORT_A*10, PORT_A1, PORT_A2, PORT_A3, PORT_A4, PORT_A5, PORT_A6, PORT_A7,
			   PORT_B0 = PORT_B*10, PORT_B1, PORT_B2, PORT_B3, PORT_B4, PORT_B5, PORT_B6, PORT_B7,
			   PORT_C0 = PORT_C*10, PORT_C1, PORT_C2, PORT_C3, PORT_C4, PORT_C5, PORT_C6, PORT_C7,
			   PORT_D0 = PORT_D*10, PORT_D1, PORT_D2, PORT_D3, PORT_D4, PORT_D5, PORT_D6, PORT_D7,
			   PORT_E0 = PORT_E*10, PORT_E1, PORT_E2, PORT_E3, PORT_E4, PORT_E5, PORT_E6, PORT_E7,
			   PORT_F0 = PORT_F*10, PORT_F1, PORT_F2, PORT_F3, PORT_F4, PORT_F5, PORT_F6, PORT_F7,
			   PORT_G0 = PORT_G*10, PORT_G1, PORT_G2, PORT_G3, PORT_G4, PORT_G5, PORT_G6, PORT_G7,
			   PORT_H0 = PORT_H*10, PORT_H1, PORT_H2, PORT_H3, PORT_H4, PORT_H5, PORT_H6, PORT_H7,
			   PORT_P0 = PORT_P*10, PORT_P1, PORT_P2, PORT_P3, PORT_P4, PORT_P5, PORT_P6, PORT_P7,
			   PORT_J0 = PORT_J*10, PORT_J1, PORT_J2, PORT_J3, PORT_J4, PORT_J5, PORT_J6, PORT_J7,
			   PORT_K0 = PORT_K*10, PORT_K1, PORT_K2, PORT_K3, PORT_K4, PORT_K5, PORT_K6, PORT_K7,
			   PORT_L0 = PORT_L*10, PORT_L1, PORT_L2, PORT_L3, PORT_L4, PORT_L5, PORT_L6, PORT_L7,
			   PORT_N0 = PORT_N*10, PORT_N1, PORT_N2, PORT_N3, PORT_N4, PORT_N5, PORT_N6, PORT_N7
			 } IpPORT_BitSel;							/* PORT BIT data */


EXTERN_PORT void		WROS_PORT_Init(void);
EXTERN_PORT void		API_PORT_Out(IpPORT_ChSel portChSel, UINT8 px);
EXTERN_PORT UINT8		API_PORT_Read(IpPORT_ChSel portChSel);
EXTERN_PORT UINT8		API_PORT_ReadBit(IpPORT_BitSel portBitSel);
EXTERN_PORT UINT8		API_PORT_Load_ReadBit_Status(IpPORT_BitSel portBitSel,UINT8 bit);
EXTERN_PORT void		API_PORT_BitSet(IpPORT_BitSel portBitSel, UINT8 px);

/**************************************************************/
#undef EXTERN_PORT
#endif /* __M470_PORT_H */

