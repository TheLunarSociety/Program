

#include "../../4.Driver/Include/WROS_Register.h"

#include "../../5.Hardware/Include/system.h"


/***********************z************************************************
************************************************************************
                                WROS_Reister
************************************************************************
************************************************************************/

//        SCU
WROS_CORTEX_M_Typedef*	WROS_CORE_M =	((WROS_CORTEX_M_Typedef*)WROS_CORTEX_M);


WROS_DMA___Typedef*	WROS____DMA	=	((WROS_DMA___Typedef*)WROS_DMA____BASE);

//        Clock Generator
WROS_CLKGE_TypeDef* WROS_CLK_GE = 	((WROS_CLKGE_TypeDef*)WROS_CLOCK__BASE);

//        GPIO
WROS_PORT__TypeDef*	WROS_____PA	=	((WROS_PORT__TypeDef*)WROS_PA_____BASE);
WROS_PORT__TypeDef*	WROS_____PB	=	((WROS_PORT__TypeDef*)WROS_PB_____BASE);
WROS_PORT__TypeDef*	WROS_____PC	= 	((WROS_PORT__TypeDef*)WROS_PC_____BASE);
WROS_PORT__TypeDef*	WROS_____PD	= 	((WROS_PORT__TypeDef*)WROS_PD_____BASE);
WROS_PORT__TypeDef*	WROS_____PE	= 	((WROS_PORT__TypeDef*)WROS_PE_____BASE);
WROS_PORT__TypeDef*	WROS_____PF	=	((WROS_PORT__TypeDef*)WROS_PF_____BASE);
WROS_PORT__TypeDef*	WROS_____PG	=	((WROS_PORT__TypeDef*)WROS_PG_____BASE);
WROS_PORT__TypeDef*	WROS_____PH	=	((WROS_PORT__TypeDef*)WROS_PH_____BASE);
WROS_PORT__TypeDef*	WROS_____PJ	=	((WROS_PORT__TypeDef*)WROS_PJ_____BASE);
WROS_PORT__TypeDef*	WROS_____PK	=	((WROS_PORT__TypeDef*)WROS_PK_____BASE);
WROS_PORT__TypeDef*	WROS_____PL	=	((WROS_PORT__TypeDef*)WROS_PL_____BASE);
WROS_PORT__TypeDef*	WROS_____PN	=	((WROS_PORT__TypeDef*)WROS_PN_____BASE);
WROS_PORT__TypeDef*	WROS_____PP	=	((WROS_PORT__TypeDef*)WROS_PP_____BASE);

//        TIER
WROS_TIMER_TypeDef*	WROS_TIER_0	=	((WROS_TIMER_TypeDef*)WROS_TIMER0_BASE);
WROS_TIMER_TypeDef*	WROS_TIER_1	=	((WROS_TIMER_TypeDef*)WROS_TIMER1_BASE);
WROS_TIMER_TypeDef*	WROS_TIER_2	=	((WROS_TIMER_TypeDef*)WROS_TIMER2_BASE);
WROS_TIMER_TypeDef*	WROS_TIER_3	=	((WROS_TIMER_TypeDef*)WROS_TIMER3_BASE);
WROS_TIMER_TypeDef*	WROS_TIER_4	=	((WROS_TIMER_TypeDef*)WROS_TIMER4_BASE);
WROS_TIMER_TypeDef*	WROS_TIER_5	=	((WROS_TIMER_TypeDef*)WROS_TIMER5_BASE);
WROS_TIMER_TypeDef*	WROS_TIER_6	=	((WROS_TIMER_TypeDef*)WROS_TIMER6_BASE);
WROS_TIMER_TypeDef*	WROS_TIER_7	=	((WROS_TIMER_TypeDef*)WROS_TIMER7_BASE);
WROS_TIMER_TypeDef*	WROS_TIER_8	=	((WROS_TIMER_TypeDef*)WROS_TIMER8_BASE);
WROS_TIMER_TypeDef*	WROS_TIER_9	=	((WROS_TIMER_TypeDef*)WROS_TIMER9_BASE);

//        UART
WROS_UART__TypeDef*	WROS_UART_0	=	((WROS_UART__TypeDef*)WROS_UART0_BASE);
WROS_UART__TypeDef*	WROS_UART_1	=	((WROS_UART__TypeDef*)WROS_UART1_BASE);
WROS_UART__TypeDef*	WROS_UART_2	=	((WROS_UART__TypeDef*)WROS_UART2_BASE);
WROS_UART__TypeDef*	WROS_UART_3	=	((WROS_UART__TypeDef*)WROS_UART3_BASE);


//        WDT
WROS_WDT___TypeDef*	WROS_WDT__0	=	((WROS_WDT___TypeDef*)WROS_WDT___BASE);

/************************************************************************
************************************************************************
                                Device_Func
************************************************************************
************************************************************************/
//        timer
static UINT32 Base_Timer_100us = 0;
static UINT32 Base_Timer_1s = 0;
void timer_0_1ms(void);		//        100us
void timer_1ms(void);		//        1000us
void timer_10ms(void);		//        10000us

void WROS_Serial_Interface_Control(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_Start(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_Stop(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_ChangetoTx(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_ChangetoRx(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_WriteAddress(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_WriteOneByteAddress(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_WriteData(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_WriteOneByteData(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_ReadAddress(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_ReadOneByteAddress(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_ReadData(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_ReadOneByte(T_Serial_Interface_drive* pstSerial_CommInfo);
T_Echo_Step WROS_Write_ACK(volatile UINT32* Clock_Pin, volatile UINT32* DataW_Pin, volatile UINT32* DataR_Pin, volatile UINT32* DataW_Pin_State, volatile UINT32* DataR_Pin_State);
T_Echo_Step WROS_Read_ACK(volatile UINT32* Clock_Pin, volatile UINT32* DataW_Pin, volatile UINT32* DataR_Pin, volatile UINT32* DataW_Pin_State, volatile UINT32* DataR_Pin_State);
void Loop_Delay(UINT8);


T_Serial_Interface_drive        LCD_Device;
T_Serial_Interface_drive        Flash_Device;
T_Serial_Interface_drive        Mpu6050_Device;
//        USB
//T_USB_drive USB_Device;

/************************************************************************
************************************************************************/

UINT8 MCU_TYPE 					= 0;
static UINT8 NVIC_FREE_BITS 	= 0;

void WROS_Init()
{
	WROS_CORE_M =	((WROS_CORTEX_M_Typedef*)WROS_CORTEX_M);
	
	while(WROS_CORE_M->NVIC_register.IPR[0] == CLEAR)
	{
		WROS_CORE_M->NVIC_register.IPR[0] = 0xFF;
	}
	NVIC_FREE_BITS = WROS_CORE_M->NVIC_register.IPR[0];
	UINT8 ucLoop = 0;
	while(!((NVIC_FREE_BITS >> ucLoop) & SET))
	{
		ucLoop++;
	}
	NVIC_FREE_BITS = ucLoop;

	if(NVIC_FREE_BITS == 5)
	{
		if(WROS_CORE_M->NVIC_register.CPUID_register.PARTNO == 0xC24)
		{
			MCU_TYPE = TMPM470;
		}
		else
		{
			MCU_TYPE = TMPM380;
		}
	}
	else
	{
		MCU_TYPE = A34M418;
	}

	WROS_CLK_GE = 	((WROS_CLKGE_TypeDef*)WROS_CLOCK__BASE);


	WROS_____PA	=	((WROS_PORT__TypeDef*)WROS_PA_____BASE);
	WROS_____PB	=	((WROS_PORT__TypeDef*)WROS_PB_____BASE);
	WROS_____PC	= 	((WROS_PORT__TypeDef*)WROS_PC_____BASE);
	WROS_____PD	= 	((WROS_PORT__TypeDef*)WROS_PD_____BASE);
	WROS_____PE	= 	((WROS_PORT__TypeDef*)WROS_PE_____BASE);
	WROS_____PF	=	((WROS_PORT__TypeDef*)WROS_PF_____BASE);
	WROS_____PG	=	((WROS_PORT__TypeDef*)WROS_PG_____BASE);
	WROS_____PH	=	((WROS_PORT__TypeDef*)WROS_PH_____BASE);
	WROS_____PJ	=	((WROS_PORT__TypeDef*)WROS_PJ_____BASE);
	WROS_____PK	=	((WROS_PORT__TypeDef*)WROS_PK_____BASE);
	WROS_____PL	=	((WROS_PORT__TypeDef*)WROS_PL_____BASE);
	WROS_____PN	=	((WROS_PORT__TypeDef*)WROS_PN_____BASE);
	WROS_____PP	=	((WROS_PORT__TypeDef*)WROS_PP_____BASE);


	WROS_TIER_0	=	((WROS_TIMER_TypeDef*)WROS_TIMER0_BASE);
	WROS_TIER_1	=	((WROS_TIMER_TypeDef*)WROS_TIMER1_BASE);
	WROS_TIER_2	=	((WROS_TIMER_TypeDef*)WROS_TIMER2_BASE);
	WROS_TIER_3	=	((WROS_TIMER_TypeDef*)WROS_TIMER3_BASE);
	WROS_TIER_4	=	((WROS_TIMER_TypeDef*)WROS_TIMER4_BASE);
	WROS_TIER_5	=	((WROS_TIMER_TypeDef*)WROS_TIMER5_BASE);
	WROS_TIER_6	=	((WROS_TIMER_TypeDef*)WROS_TIMER6_BASE);
	WROS_TIER_7	=	((WROS_TIMER_TypeDef*)WROS_TIMER7_BASE);
	WROS_TIER_8	=	((WROS_TIMER_TypeDef*)WROS_TIMER8_BASE);
	WROS_TIER_9	=	((WROS_TIMER_TypeDef*)WROS_TIMER9_BASE);


	WROS_UART_0	=	((WROS_UART__TypeDef*)WROS_UART0_BASE);
	WROS_UART_1	=	((WROS_UART__TypeDef*)WROS_UART1_BASE);
	WROS_UART_2	=	((WROS_UART__TypeDef*)WROS_UART2_BASE);
	WROS_UART_3	=	((WROS_UART__TypeDef*)WROS_UART3_BASE);



	WROS_WDT__0	=	((WROS_WDT___TypeDef*)WROS_WDT___BASE);

	SystemInit();
}


static inline void __enable_irq(void)
{
  __asm ("cpsie i");
}

static inline void __disable_irq(void)
{
  __asm ("cpsid i");
}
	
void __enable_interrupt(void)
{
	__enable_irq();
}

void __disable_interrupt(void)
{
	__disable_irq();
}


// 手动声明屏障函数（ARM 架构专用）
static inline void __dsb(unsigned int unused) { 
    (void)unused; 
    __asm("dsb"); 
}

static inline void __isb(unsigned int unused) { 
    (void)unused; 
    __asm("isb"); 
}

void __DSB(unsigned int unused)
{
	__dsb(unused);
}

void __ISB(unsigned int unused)
{
	__isb(unused);
}







static void timer_0_1ms()
{
	if(LCD_Device.Comm_Request != Serial_Sleep)
	{
		WROS_Serial_Interface_Control(&LCD_Device);
	}
	else
	{	;
	}
}

static void timer_1ms()
{
	if(Mpu6050_Device.Comm_Request != Serial_Sleep)
	{
		WROS_Serial_Interface_Control(&Mpu6050_Device);
	}
	else
	{		 ;
	}
}
static void timer_10ms()
{
	if(Base_Timer_100us % 100 == 0)
	{	;
	}
}

static void (* const FuncBaseTimer[]) (void) =
{
	timer_0_1ms,
	timer_1ms,
	timer_10ms,
};

// TIMER
void WROS_Base_Timer()
{
	Base_Timer_100us++;
	if(Base_Timer_100us % 10000 == 0)
	{
		Base_Timer_100us = 0;
		Base_Timer_1s++;					// Max130years
	}

	UINT8 TimerIndex = 0;
	while(TimerIndex < SIZE_OF_ARRAY(FuncBaseTimer)){FuncBaseTimer[TimerIndex++]();}
}

// TICK
void WROS_Tick_Init(void)
{
	UINT32 MCU_SystemCoreClock = 1200000000;
	
	struct STCSR_Register	STCSR_Registers;
	struct STRVR_Register	STRVR_Registers;
	struct STCVR_Register	STCVR_Registers;
	struct STCR_Register	STCR_Registers;
	
	STCSR_Registers.ENABLE		= 1;		//	0: Disable								1: Enable
	STCSR_Registers.TICKINT		= 0;		//	0: Do not pend SysTick					1: Pend SysTick
	STCSR_Registers.CLKSOURCE	= 1;		//	0: External reference clock (fosc/32)	1: CPU clock (fsys)
	STCSR_Registers.COUNTFLAG	= 0;		//	0: Timer not counted to 0				1: Timer counted to 0

	STRVR_Registers.RELOAD		= MCU_SystemCoreClock / 1000;						// 0.5 ms

	STCVR_Registers.CURRENT		= 0;

	STCR_Registers.TENMS		= 0;
	STCR_Registers.SKEW			= 0;
	STCR_Registers.NOREF		= 0;
	
	WROS_CORE_M->SYSTICK_register.STCSR_register	= STCSR_Registers;
	WROS_CORE_M->SYSTICK_register.STRVR_register	= STRVR_Registers;
	WROS_CORE_M->SYSTICK_register.STCVR_register	= STCVR_Registers;
	WROS_CORE_M->SYSTICK_register.STCR_register	= STCR_Registers;
}

void WROS_TimerTask(T_DispInfo* P_DispInfo)
{
	while(1)
	{

	}
}



// NVIC
void WROS_NVIC_Init(void)
{
	for(int NVIC_Interrupt = 0; NVIC_Interrupt <= SIZE_OF_ARRAY(Interrupt) - 1; NVIC_Interrupt++)
	{
		if(Interrupt[NVIC_Interrupt][0] < 0)
		{	WROS_CORE_M->NVIC_register.SHP[(Interrupt[NVIC_Interrupt][0] + 12)]	= ((Interrupt[NVIC_Interrupt][1] << NVIC_FREE_BITS) & 0xFF);
		}
		else
		{	WROS_CORE_M->NVIC_register.IPR[Interrupt[NVIC_Interrupt][0]]		= ((Interrupt[NVIC_Interrupt][1] << NVIC_FREE_BITS) & 0xFF);
			WROS_CORE_M->NVIC_register.ISER[Interrupt[NVIC_Interrupt][0] >> 5]	= (1 << ((Interrupt[NVIC_Interrupt][0]) & 0x1F));
		}
	}
}

void WROS_NVIC_Setting(UINT8 InterReqIdx, UINT8 SetAble, UINT8 PriorityLv)
{
	WROS_CORE_M->NVIC_register.IPR[InterReqIdx]			= ((PriorityLv << NVIC_FREE_BITS) & 0xFF);
	
	if(SetAble == SET)
	{
		WROS_CORE_M->NVIC_register.ISER[InterReqIdx >> 5]	= (1 << ((InterReqIdx) & 0x1F));
	}
	else
	{
		WROS_CORE_M->NVIC_register.ICER[InterReqIdx >> 5]	= (1 << ((InterReqIdx) & 0x1F));
	}
}


#define  IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME	20
void WROS_Serial_Interface_Control(T_Serial_Interface_drive* pstSerial_CommInfo)
{
        switch(pstSerial_CommInfo->Comm_Step)
        {
                case Serial_Start:
                        WROS_Serial_Start(pstSerial_CommInfo);
                        pstSerial_CommInfo->Device_NextStep();
                        break;

                case Serial_Write_mode:
                        WROS_Serial_ChangetoTx(pstSerial_CommInfo);
                        pstSerial_CommInfo->Device_NextStep();
                        break;

                case Serial_Read_mode:
                        WROS_Serial_ChangetoRx(pstSerial_CommInfo);
                        pstSerial_CommInfo->Device_NextStep();
                        break;

                case Serial_TX_Adr:
                        WROS_Serial_WriteAddress(pstSerial_CommInfo);
                        pstSerial_CommInfo->Device_NextStep();
                        break;

                case Serial_RX_Adr:
                        WROS_Serial_ReadAddress(pstSerial_CommInfo);
                        pstSerial_CommInfo->Device_NextStep();
                        break;

                case Serial_TX_DATA:
                        WROS_Serial_WriteData(pstSerial_CommInfo);
                        pstSerial_CommInfo->Device_NextStep();
                        break;

                case Serial_RX_DATA:
                        WROS_Serial_ReadData(pstSerial_CommInfo);
                        pstSerial_CommInfo->Device_NextStep();
                        break;

                case Serial_Stop:
                        WROS_Serial_Stop(pstSerial_CommInfo);
                        pstSerial_CommInfo->Device_NextStep();
                        break;

                default:
                        break;
        }


        if(pstSerial_CommInfo->EchoReq == NONE)
        {        ;
        }
        else
        {
                pstSerial_CommInfo->Device_Event = (pstSerial_CommInfo->EchoReq == Write_ACK ? WROS_Write_ACK : WROS_Read_ACK);
                pstSerial_CommInfo->Device_Event(pstSerial_CommInfo->Clock_Pin, pstSerial_CommInfo->DataW_Pin, pstSerial_CommInfo->DataR_Pin, pstSerial_CommInfo->Write_Pin_state, pstSerial_CommInfo->Read_Pin_state);
                pstSerial_CommInfo->EchoReq = NONE;
        }
}

void WROS_Serial_Start(T_Serial_Interface_drive* pstSerial_CommInfo)
{
        if(pstSerial_CommInfo->Device_Type == IIC)
        {
                Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);
        }

        *pstSerial_CommInfo->DataW_Pin = (pstSerial_CommInfo->Device_Type == IIC ? SET : CLEAR);
        *pstSerial_CommInfo->DataR_Pin = (pstSerial_CommInfo->Device_Type == IIC ? SET : CLEAR);
        *pstSerial_CommInfo->Clock_Pin = (pstSerial_CommInfo->Device_Type == IIC ? SET : CLEAR);

        if(pstSerial_CommInfo->Device_Type == IIC)
        {
                Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);
        }

        *pstSerial_CommInfo->DataW_Pin = CLEAR;
        *pstSerial_CommInfo->DataR_Pin = CLEAR;

        if(pstSerial_CommInfo->Device_Type == IIC)
        {
                Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);
        }

        *pstSerial_CommInfo->Clock_Pin = CLEAR;
}

void WROS_Serial_Stop(T_Serial_Interface_drive* pstSerial_CommInfo)
{
        if(pstSerial_CommInfo->Device_Type == IIC)
        {
                Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);
        }

        *pstSerial_CommInfo->Clock_Pin = CLEAR;
        *pstSerial_CommInfo->DataW_Pin = CLEAR;
        *pstSerial_CommInfo->DataR_Pin = CLEAR;

        if(pstSerial_CommInfo->Device_Type == IIC)
        {
                Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);
        }

        *pstSerial_CommInfo->Clock_Pin = (pstSerial_CommInfo->Device_Type == IIC ? SET : CLEAR);

        if(pstSerial_CommInfo->Device_Type == IIC)
        {
                Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);
        }

        *pstSerial_CommInfo->DataW_Pin = (pstSerial_CommInfo->Device_Type == IIC ? SET : CLEAR);
        *pstSerial_CommInfo->DataR_Pin = (pstSerial_CommInfo->Device_Type == IIC ? SET : CLEAR);
}

void WROS_Serial_ChangetoTx(T_Serial_Interface_drive* pstSerial_CommInfo)
{
        if(*pstSerial_CommInfo->Write_Pin_state == ((Pin_Out >> 1) & 0x01))
        {        ;
        }
        else
        {
                *pstSerial_CommInfo->Write_Pin_state = ((Pin_Out >> 1) & 0x01);
        }
}

void WROS_Serial_ChangetoRx(T_Serial_Interface_drive* pstSerial_CommInfo)
{
        if(*pstSerial_CommInfo->Read_Pin_state == ((Pin__In >> 1) & 0x01))
        {        ;
        }
        else
        {
                *pstSerial_CommInfo->Read_Pin_state = ((Pin__In >> 1) & 0x01);
        }
}

void WROS_Serial_WriteAddress(T_Serial_Interface_drive* pstSerial_CommInfo)
{
        if(pstSerial_CommInfo->T_Serial_Packet.Adr_Size != 0)
        {
                pstSerial_CommInfo->T_Serial_Packet.Adr_Size--;
                WROS_Serial_WriteOneByteAddress(pstSerial_CommInfo);
                pstSerial_CommInfo->T_Serial_Packet.Adr_Index++;
        }
}

void WROS_Serial_WriteOneByteAddress(T_Serial_Interface_drive* pstSerial_CommInfo)
{
        UINT8 Data = pstSerial_CommInfo->T_Serial_Packet.Adr[pstSerial_CommInfo->T_Serial_Packet.Adr_Index];

        for(UINT8 i = 8; i > 0; i--)
        {
                if(Data & 0x80)
                {
                        *pstSerial_CommInfo->DataW_Pin = SET;
                }
                else
                {
                        *pstSerial_CommInfo->DataW_Pin        = CLEAR;
                }

                if(pstSerial_CommInfo->Device_Type == IIC)
                {
                        Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);
                }

                *pstSerial_CommInfo->Clock_Pin = CLEAR;
                *pstSerial_CommInfo->Clock_Pin = SET;

                if(pstSerial_CommInfo->Device_Type == IIC)
                {
                        Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);
                        *pstSerial_CommInfo->Clock_Pin = CLEAR;
                }
                else
                {        ;
                }

                Data <<= 1;
        }

}

void WROS_Serial_WriteData(T_Serial_Interface_drive* pstSerial_CommInfo)
{
        if(pstSerial_CommInfo->T_Serial_Packet.Data_Size != 0)
        {
                pstSerial_CommInfo->T_Serial_Packet.Data_Size--;
                WROS_Serial_WriteOneByteData(pstSerial_CommInfo);
                pstSerial_CommInfo->T_Serial_Packet.Data_Index++;
        }
}

void WROS_Serial_WriteOneByteData(T_Serial_Interface_drive* pstSerial_CommInfo)
{
        UINT8 Data = pstSerial_CommInfo->T_Serial_Packet.Data[pstSerial_CommInfo->T_Serial_Packet.Data_Index];

        for(UINT8 i = 8; i > 0; i--)
        {
                if(Data & 0x80)
                {
                        *pstSerial_CommInfo->DataW_Pin = SET;
                }
                else
                {
                        *pstSerial_CommInfo->DataW_Pin        = CLEAR;
                }

                if(pstSerial_CommInfo->Device_Type == IIC)
                {
                        Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);
                }
                else
                {        ;
                }

                *pstSerial_CommInfo->Clock_Pin = CLEAR;
                *pstSerial_CommInfo->Clock_Pin = SET;

                if(pstSerial_CommInfo->Device_Type == IIC)
                {
                        Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);
                        *pstSerial_CommInfo->Clock_Pin = CLEAR;
                }
                else
                {        ;
                }

                Data <<= 1;
        }

        *pstSerial_CommInfo->DataW_Pin = (pstSerial_CommInfo->Device_Type == SPI ? CLEAR : SET);
}

void WROS_Serial_ReadAddress(T_Serial_Interface_drive* pstSerial_CommInfo)
{
        if(pstSerial_CommInfo->T_Serial_Packet.Adr_Size != 0)
        {
                pstSerial_CommInfo->T_Serial_Packet.Adr_Size--;
                WROS_Serial_ReadOneByteAddress(pstSerial_CommInfo);
                pstSerial_CommInfo->T_Serial_Packet.Adr_Index++;
        }
}

void WROS_Serial_ReadOneByteAddress(T_Serial_Interface_drive* pstSerial_CommInfo)
{
        UINT8 Data = pstSerial_CommInfo->T_Serial_Packet.Adr[pstSerial_CommInfo->T_Serial_Packet.Adr_Index];

        for(UINT8 i = 8; i > 0; i--)
        {
                if(Data & 0x80)
                {
                        *pstSerial_CommInfo->DataW_Pin = SET;
                }
                else
                {
                        *pstSerial_CommInfo->DataW_Pin        = CLEAR;
                }

                if(pstSerial_CommInfo->Device_Type == IIC)
                {
                        Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);
                }

                *pstSerial_CommInfo->Clock_Pin = CLEAR;
                *pstSerial_CommInfo->Clock_Pin = SET;

                if(pstSerial_CommInfo->Device_Type == IIC)
                {
                        Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);
                        *pstSerial_CommInfo->Clock_Pin = CLEAR;
                }
                else
                {        ;
                }

                Data <<= 1;
        }

}

void WROS_Serial_ReadData(T_Serial_Interface_drive* pstSerial_CommInfo)
{
        pstSerial_CommInfo->T_Serial_Packet.Data_Size--;
        WROS_Serial_ReadOneByte(pstSerial_CommInfo);
        pstSerial_CommInfo->T_Serial_Packet.Data_Index++;
}



void WROS_Serial_ReadOneByte(T_Serial_Interface_drive* pstSerial_CommInfo)
{
	UINT8 Data = 0;

	for(UINT8 i = 8; i > 0; i--)
	{
		Data <<= 1;

		*pstSerial_CommInfo->Clock_Pin = CLEAR;

		if(pstSerial_CommInfo->Device_Type == IIC)
		{
			Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);
		}

		*pstSerial_CommInfo->Clock_Pin = SET;

		if(pstSerial_CommInfo->Device_Type == IIC)
		{
			Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);
		}

		if(*pstSerial_CommInfo->DataR_Pin == SET)
		{
			Data |= 0x01;
		}
		else
		{
			Data &= 0xFE;
		}
	}
	pstSerial_CommInfo->T_Serial_Packet.Data[pstSerial_CommInfo->T_Serial_Packet.Data_Index] = Data;
// *pstSerial_CommInfo->DataW_Pin = (pstSerial_CommInfo->Comm_Type == SPI ? CLEAR : SET);
}

T_Echo_Step WROS_Write_ACK(volatile UINT32* Clock_Pin, volatile UINT32* DataW_Pin, volatile UINT32* DataR_Pin, volatile UINT32* DataW_Pin_State, volatile UINT32* DataR_Pin_State)
{
	UINT8 Pin_State;
	Pin_State = *(DataR_Pin_State);
	*DataR_Pin_State = Pin__In;

	*Clock_Pin = CLEAR;

	Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);

	*DataW_Pin = CLEAR;                                                // write Low Signal ACK

	Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);


	*Clock_Pin = SET;

	Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);


	*Clock_Pin = CLEAR;

	*DataR_Pin_State = Pin_State;

	return Echo_ACK;
}

T_Echo_Step WROS_Read_ACK(volatile UINT32* Clock_Pin, volatile UINT32* DataW_Pin, volatile UINT32* DataR_Pin, volatile UINT32* DataW_Pin_State, volatile UINT32* DataR_Pin_State)
{
	UINT8 Pin_State;
	Pin_State = *(DataR_Pin_State);
	*DataR_Pin_State = ((Pin__In >> 1) & 0x01);

	T_Echo_Step ucTemp;
	*Clock_Pin = CLEAR;

	Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);

	*Clock_Pin = SET;

	Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);

	ucTemp = (*DataR_Pin == CLEAR ? Echo_ACK : Echo_NCK);        // read Low Signal ACK
	*Clock_Pin = CLEAR;

	Loop_Delay(IIC_SPI_INTERFACE_DEFAULT_DELAY_TIME);


	*Clock_Pin = CLEAR;

	*DataR_Pin_State = Pin_State;

	return ucTemp;
}

void Loop_Delay(UINT8 ucLoop_Number)
{
	while(ucLoop_Number > 0)
	{	ucLoop_Number--;
	}
}

