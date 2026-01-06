

#ifndef __FLASH_H
#define __FLASH_H


typedef struct
{
				uint32_t RESERVED0[4];
	volatile 	uint32_t SECBIT;            /*!< Security Bit Register                        */
				uint32_t RESERVED1[3];
	volatile  	uint32_t PSR0;              /*!< Protect Status Register 0                    */
				uint32_t RESERVED2[55];
	volatile  	uint32_t SR;                /*!< Status Register                              */
	volatile  	uint32_t SWPSR;             /*!< Swap Status Register                         */
				uint32_t RESERVED3[14];
	volatile 	uint32_t AREASEL;           /*!< Area Selection Register                      */
				uint32_t RESERVED4;
	volatile 	uint32_t CR;                /*!< Control Register                             */
	volatile 	uint32_t STSCLR;            /*!< Status Clear Register                        */
	volatile 	uint32_t WCLKCR;            /*!< WCLK Configuration Register                  */
	volatile 	uint32_t PROGCR;            /*!< Program Counter Configuration Register       */
	volatile 	uint32_t ERASECR;           /*!< Erase Counter Configuration Register         */
} FC_TypeDef;

#define FC_BASE                (0x40000000UL  + 0x1DFF0000UL)
#define FC                     ((FC_TypeDef *) FC_BASE)


void SetCMDBuffer(UINT32*);
void HWI_FlashEraseSector(UINT32);


typedef enum
{
	CMD_ERASE_STEP,
	CMD_WRITE_STEP,
	CMD_FINISH_STEP,
}T_CMD_STEP;

typedef enum
{	/**********HEADER*********/
	SIZE_OF_STX = 1,
	SIZE_OF_LENGTH = 2,

	/**********BODY*********/
	SIZE_OF_FRAME_ID = 1,
	SIZE_OF_DOWNLOAD_ID = 1,

	/**********FOOTER*********/
	SIZE_OF_CRC = 1,
	SIZE_OF_ETX = 1,

}T_PKT_LENGTH;

#define		DATA_LEN				256L
#define		PROGRAM_UNIT		4L	

#define FLASH_SEQ_BASE		0x5E000000
#define FLASH_0_SEQ_54XX	*((volatile UINT32*)(FLASH_SEQ_BASE + 0x005400))
#define FLASH_0_SEQ_AAXX	*((volatile UINT32*)(FLASH_SEQ_BASE + 0x00AA00))


/* Flash 目膏靛 鉴辑 内靛	*/
#define		FLASH_CMD_AA		0xAA
#define		FLASH_CMD_40		0x40
#define		FLASH_CMD_55		0x55
#define		FLASH_CMD_10		0x10
#define		FLASH_CMD_30		0x30
#define		FLASH_CMD_80		0x80
#define		FLASH_CMD_A0		0xA0

#define		NVIC_ISPR0			*((volatile UINT32*)	(0xE000E200))	/* Set-Pending Reg Irq00?31	*/
#define		NVIC_ICPR0			*((volatile UINT32*)	(0xE000E280))	/* Clear-Pending Reg Irq00?31	*/

#define		INTRX0_BIT			0x0040					/* INTRX0 壶厘		*/
#define		INTTX0_BIT			0x0080					/* INTTX0 壶厘		*/

T_CMD_STEP CMDErase(void);
T_CMD_STEP CMDWrite(void);

void HWI_FlashWrite(UINT32, UINT32*);
void HW_CheckBusy(void);

typedef T_CMD_STEP (*T_CMD_Step_Func)(void);

static const T_CMD_Step_Func mapfnFlashStepFunc[] =
{
	CMDErase,
	CMDWrite,
};

#endif


