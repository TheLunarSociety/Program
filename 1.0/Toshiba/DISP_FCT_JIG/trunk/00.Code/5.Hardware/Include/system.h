
#ifndef __SYSTEM_TMPM470_H
#define __SYSTEM_TMPM470_H


extern const INT32 Interrupt[8][2];

#define UART_R_0_Handler	ExternalInterrupts_6
#define UART_T_0_Handler	ExternalInterrupts_7
#define UART_R_2_Handler	ExternalInterrupts_40
#define UART_T_2_Handler	ExternalInterrupts_41
#define INTTB51_IRQHandler	ExternalInterrupts_27


extern uint32_t SystemCoreClock;     /*!< System Clock Frequency (Core Clock)  */
extern void SystemInit (void);
extern void SystemCoreClockUpdate (void);

#undef EXTR
#endif
