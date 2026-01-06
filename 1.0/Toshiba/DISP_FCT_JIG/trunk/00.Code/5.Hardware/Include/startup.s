;/**
; *******************************************************************************
; * @file    startup_TMPM470.s
; * @brief   CMSIS Cortex-M4 Core Device Startup File for the
; *          TOSHIBA 'TMPM470' Device Series
; * @version V2.0.2.3 (Tentative)
; * @date    2015/01/12
; * 
; * DO NOT USE THIS SOFTWARE WITHOUT THE SOFTWARE LISENCE AGREEMENT.
; * 
; * (C)Copyright TOSHIBA CORPORATION 2015 All rights reserved
; *******************************************************************************
; */
;
; The modules in this file are included in the libraries, and may be replaced
; by any user-defined modules that define the PUBLIC symbol _program_start or
; a user defined start symbol.
; To override the cstartup defined in the library, simply add your modified
; version to the workbench project.
;
; Cortex-M version
;

                MODULE  ?cstartup

                ;; Forward declaration of sections.
                SECTION CSTACK:DATA:NOROOT(3)

                SECTION .intvec:CODE:NOROOT(2)

                EXTERN  __iar_program_start
                EXTERN  WROS_Init
                EXTERN  vTaskSwitchContext
                EXTERN  pxCurrentTCB
                EXTERN  TEST_COUNT
                PUBLIC  __vector_table

                DATA
__vector_table  DCD     sfe(CSTACK)
                DCD     Reset_Handler

                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     MemManage_Handler         ; MPU Fault Handler
                DCD     BusFault_Handler          ; Bus Fault Handler
                DCD     UsageFault_Handler        ; Usage Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                DCD     ExternalInterrupts_0	    ; 0:
                DCD     ExternalInterrupts_1	    ; 1:
                DCD     ExternalInterrupts_2	    ; 2:
                DCD     ExternalInterrupts_3	    ; 3:
                DCD     ExternalInterrupts_4	    ; 4:
                DCD     ExternalInterrupts_5	    ; 5:
                DCD     ExternalInterrupts_6	    ; 6:	(TM380)(TM470)	Uart_0 RX
                DCD     ExternalInterrupts_7	    ; 7:	(TM380)(TM470)	Uart_0 TX
                DCD     ExternalInterrupts_8	    ; 8:	(TM380)(TM470)	Uart_1 RX
                DCD     ExternalInterrupts_9	    ; 9:	(TM380)(TM470)	Uart_1 TX
                DCD     ExternalInterrupts_10	    ; 10:
                DCD     ExternalInterrupts_11	    ; 11:
                DCD     ExternalInterrupts_12	    ; 12:
                DCD     ExternalInterrupts_13	    ; 13:
                DCD     ExternalInterrupts_14	    ; 14:
                DCD     ExternalInterrupts_15	    ; 15: ********************************* (ABOV)	TIMER_0	
                DCD     ExternalInterrupts_16	    ; 16:									(ABOV)	TIMER_1
                DCD     ExternalInterrupts_17	    ; 17:									(ABOV)	TIMER_2
                DCD     ExternalInterrupts_18	    ; 18:									(ABOV)	TIMER_3
                DCD     ExternalInterrupts_19	    ; 19:									(ABOV)	TIMER_4
                DCD     ExternalInterrupts_20	    ; 20:	(TM380)(TM470)	TMRB_00			(ABOV)	TIMER_5
                DCD     ExternalInterrupts_21	    ; 21:	(TM380)(TM470)	TMRB_01			(ABOV)	TIMER_6
                DCD     ExternalInterrupts_22	    ; 22:	(TM380)(TM470)	TMRB_10			(ABOV)	TIMER_7
                DCD     ExternalInterrupts_23	    ; 23:	(TM380)(TM470)	TMRB_11			(ABOV)	TIMER_8
                DCD     ExternalInterrupts_24	    ; 24: **(TM380)(TM470)	TMRB_40 ******* (ABOV)	TIMER_9
                DCD     ExternalInterrupts_25	    ; 25:	(TM380)(TM470)	TMRB_41
                DCD     ExternalInterrupts_26	    ; 26:	(TM380)(TM470)	TMRB_50
                DCD     ExternalInterrupts_27	    ; 27:	(TM380)(TM470)	TMRB_51
                DCD     ExternalInterrupts_28	    ; 28:
                DCD     ExternalInterrupts_29	    ; 29:
                DCD     ExternalInterrupts_30	    ; 30:
                DCD     ExternalInterrupts_31	    ; 31:
                DCD     ExternalInterrupts_32	    ; 32:
                DCD     ExternalInterrupts_33	    ; 33:
                DCD     ExternalInterrupts_34	    ; 34:
                DCD     ExternalInterrupts_35	    ; 35:
                DCD     ExternalInterrupts_36	    ; 36:
                DCD     ExternalInterrupts_37	    ; 37:
                DCD     ExternalInterrupts_38	    ; 38:
                DCD     ExternalInterrupts_39	    ; 39:
                DCD     ExternalInterrupts_40	    ; 40:	(TM380)(TM470)	Uart_2 RX
                DCD     ExternalInterrupts_41	    ; 41:	(TM380)(TM470)	Uart_2 TX
                DCD     ExternalInterrupts_42	    ; 42:
                DCD     ExternalInterrupts_43	    ; 43:
                DCD     ExternalInterrupts_44	    ; 44:
                DCD     ExternalInterrupts_45	    ; 45:
                DCD     ExternalInterrupts_46	    ; 46:	(TM380)(TM470)	TMRB_20
                DCD     ExternalInterrupts_47	    ; 47:	(TM380)(TM470)	TMRB_21
                DCD     ExternalInterrupts_48	    ; 48:	(TM380)(TM470)	TMRB_30
                DCD     ExternalInterrupts_49	    ; 49:	(TM380)(TM470)	TMRB_31
                DCD     ExternalInterrupts_50	    ; 50:
                DCD     ExternalInterrupts_51	    ; 51:
                DCD     ExternalInterrupts_52	    ; 52:
                DCD     ExternalInterrupts_53	    ; 53:
                DCD     ExternalInterrupts_54	    ; 54:
                DCD     ExternalInterrupts_55	    ; 55:
                DCD     ExternalInterrupts_56	    ; 56:
                DCD     ExternalInterrupts_57	    ; 57:
                DCD     ExternalInterrupts_58	    ; 58:
                DCD     ExternalInterrupts_59	    ; 59:
                DCD     ExternalInterrupts_60	    ; 60:
                DCD     ExternalInterrupts_61	    ; 61:
                DCD     ExternalInterrupts_62	    ; 62:
                DCD     ExternalInterrupts_63	    ; 63: *********************************	(ABOV)	UART_0	
                DCD     ExternalInterrupts_64	    ; 64: 									(ABOV)	UART_1	
                DCD     ExternalInterrupts_65	    ; 65: 									(ABOV)	UART_2	
                DCD     ExternalInterrupts_66	    ; 66: 	(TM380)(TM470)	TMRB_60			(ABOV)	UART_3	
                DCD     ExternalInterrupts_67	    ; 67: 	(TM380)(TM470)	TMRB_61			(ABOV)	UART_4	
                DCD     ExternalInterrupts_68	    ; 68: **(TM380)(TM470)	TMRB_70	******* (ABOV)	UART_5	
                DCD     ExternalInterrupts_69	    ; 69:	(TM380)(TM470)	TMRB_71
                DCD     ExternalInterrupts_70	    ; 70:
                DCD     ExternalInterrupts_71	    ; 71:
                DCD     ExternalInterrupts_72	    ; 72:
                DCD     ExternalInterrupts_73	    ; 73:
                DCD     ExternalInterrupts_74	    ; 74:
                DCD     ExternalInterrupts_75	    ; 75:
                DCD     ExternalInterrupts_76	    ; 76:
                DCD     ExternalInterrupts_77	    ; 77:
                DCD     ExternalInterrupts_78	    ; 78:
                DCD     ExternalInterrupts_79	    ; 79:
                DCD     ExternalInterrupts_80	    ; 80:
                DCD     ExternalInterrupts_81	    ; 81:
                DCD     ExternalInterrupts_82	    ; 82:
                DCD     ExternalInterrupts_83	    ; 83:
                DCD     ExternalInterrupts_84	    ; 84:	(TM380)(TM470)	TMRB_80
                DCD     ExternalInterrupts_85	    ; 85:	(TM380)(TM470)	TMRB_81
                DCD     ExternalInterrupts_86	    ; 86:	(TM380)(TM470)	TMRB_90
                DCD     ExternalInterrupts_87	    ; 87:	(TM380)(TM470)	TMRB_91
                DCD     ExternalInterrupts_88	    ; 88:
                DCD     ExternalInterrupts_89	    ; 89:
                DCD     ExternalInterrupts_90	    ; 90:
                THUMB
; Dummy Exception Handlers (infinite loops which can be modified)

                PUBWEAK Reset_Handler
                SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler
                ;LDR     R0, =SystemInit
                LDR     R0, =WROS_Init
                BLX     R0
                LDR     R0, =__iar_program_start
                BX      R0

                PUBWEAK NMI_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
                B       NMI_Handler

                PUBWEAK HardFault_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
                B       HardFault_Handler

                PUBWEAK MemManage_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
MemManage_Handler
                B       MemManage_Handler

                PUBWEAK BusFault_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
BusFault_Handler
                B       BusFault_Handler

                PUBWEAK UsageFault_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
UsageFault_Handler
                B       UsageFault_Handler

                PUBWEAK SVC_Handler
                SECTION .text:CODE:REORDER:NOROOT(2)

SVC_Handler
				PRESERVE8 

				MRS r0, CONTROL
				ORR r0, r0, #1  ; CONTROL[0] = 1：强制使用 PSP 作为任务栈
				MSR CONTROL, r0
				ISB

				ldr	r3, =pxCurrentTCB
				ldr r1, [r3]
				ldr r0, [r1]
				ldmia r0!, {r4-r11}
				msr psp, r0
				isb

				mov r0, #0
				msr	basepri, r0
				
				mov lr, #0xFFFFFFFD	;orr r14, #0xd  

				mov r2, #5
				ldr r3, =TEST_COUNT
				str r2, [r3]

				bx r14

                PUBWEAK DebugMon_Handler
                SECTION .text:CODE:REORDER:NOROOT(1)
DebugMon_Handler
                B       DebugMon_Handler

                PUBWEAK PendSV_Handler
                SECTION .text:CODE:REORDER:NOROOT(2)
PendSV_Handler
				PRESERVE8
				; -------------------------- 第一步：保存当前任务的上下文（PSP 栈） --------------------------
				mrs r0, psp               ; 1. 读取进程栈指针（PSP）到 r0，PSP 指向当前任务的栈顶
				isb                       ; 2. 指令同步屏障，确保 MRS 指令执行完成后再执行后续操作（防止指令乱序）

				ldr r3, =pxCurrentTCB     ; 3. r3 = &pxCurrentTCB（全局变量 pxCurrentTCB 的地址，指向当前任务的 TCB）
				ldr r2, [r3]              ; 4. r2 = *pxCurrentTCB（取当前任务 TCB 的首地址）

				stmdb r0!, {r4-r11}       ; 5. 递减 PSP（r0）并压入 r4-r11 寄存器（这些是 Cortex-M 需手动保存的寄存器）
						                          ;    ! 表示 r0 自动更新为压栈后的新栈顶（STMDB = 递减后存储，满递减栈）
				str r0, [r2]              ; 6. 将新的 PSP 栈顶（r0）写入当前 TCB 的第一个成员（TCB->pxTopOfStack）
						                          ;    FreeRTOS TCB 首成员始终是任务栈顶指针

				; -------------------------- 第二步：保护中断上下文 + 屏蔽低优先级中断 --------------------------
				stmdb sp!, {r3, r14}      ; 7. 递减主栈指针（MSP），压入 r3（TCB 地址）和 r14(LR)（中断返回值）
						                          ;    保护这两个寄存器，避免后续操作覆盖

				mov r0, #0x60             ; 8. r0 = 0x30（对应 FreeRTOS 的 configMAX_SYSCALL_INTERRUPT_PRIORITY）
						                          ;    Cortex-M4 BASEPRI 寄存器：仅屏蔽优先级 ≥ 0x30 的中断（高4位有效）
				msr basepri, r0           ; 9. 将 r0 写入 BASEPRI，屏蔽低优先级中断（防止任务切换时被打断）
				dsb                       ; 10. 数据同步屏障，确保 BASEPRI 生效
				isb                       ; 11. 指令同步屏障，确保中断屏蔽生效后再执行任务切换

				; -------------------------- 第三步：执行 FreeRTOS 任务切换逻辑 --------------------------
				bl vTaskSwitchContext     ; 12. 调用 FreeRTOS 任务切换函数，修改 pxCurrentTCB 指向新任务的 TCB
						                          ;    BL = 带链接跳转，自动保存返回地址到 LR

				; -------------------------- 第四步：解除中断屏蔽 + 恢复保护的上下文 --------------------------
				mov r0, #0                ; 13. r0 = 0，解除所有中断屏蔽
				msr basepri, r0           ; 14. 写入 BASEPRI，恢复所有中断响应

				ldmia sp!, {r3, r14}      ; 15. 递增 MSP 并弹出 r3 和 r14(LR)（恢复第二步压栈的寄存器）
						                          ;    LDMIA = 递增后加载，与 STMDB 配对

				; -------------------------- 第五步：恢复新任务的上下文（PSP 栈） --------------------------
				ldr r1, [r3]              ; 16. r1 = *pxCurrentTCB（新任务的 TCB 首地址，已被 vTaskSwitchContext 更新）
				ldr r0, [r1]              ; 17. r0 = TCB->pxTopOfStack（新任务的栈顶指针）
				ldmia r0!, {r4-r11}       ; 18. 递增 r0 并弹出 r4-r11 到新任务的寄存器（恢复新任务上下文）
						                          ;    ! 表示 r0 自动更新为弹栈后的新栈顶
				msr psp, r0               ; 19. 将新栈顶写入 PSP，PSP 现在指向新任务的栈
				isb                       ; 20. 指令同步屏障，确保 PSP 更新生效

				mov r2, #6
				ldr r3, =TEST_COUNT
				str r2, [r3]


				; -------------------------- 第六步：中断返回，跳转到新任务执行 --------------------------
				bx r14                    ; 21. 中断返回：r14(LR) 存储 EXC_RETURN 特殊值，跳转到新任务的指令地址
						                          ;    EXC_RETURN 决定返回后使用 PSP（线程模式），执行新任务代码
				nop                       ; 22. 空指令，防止汇编器指令对齐问题
                
                PUBWEAK SysTick_Handler
                SECTION .text:CODE:REORDER:NOROOT(2)
SysTick_Handler
                B       SysTick_Handler

; ------------------------------ 外部中断 ------------------------------

                PUBWEAK ExternalInterrupts_0
                SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_0
                B       ExternalInterrupts_0

                PUBWEAK ExternalInterrupts_1
                SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_1

                B       ExternalInterrupts_1

                PUBWEAK ExternalInterrupts_2
                SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_2

                B       ExternalInterrupts_2

                PUBWEAK ExternalInterrupts_3
                SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_3

                B       ExternalInterrupts_3

                PUBWEAK ExternalInterrupts_4
                SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_4

                B       ExternalInterrupts_4

                PUBWEAK ExternalInterrupts_5
                SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_5

                B       ExternalInterrupts_5

                PUBWEAK ExternalInterrupts_6
                SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_6

                B       ExternalInterrupts_6

                PUBWEAK ExternalInterrupts_7
                SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_7

                B       ExternalInterrupts_7

                PUBWEAK ExternalInterrupts_8
                SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_8

                B       ExternalInterrupts_8

                PUBWEAK ExternalInterrupts_9
                SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_9

                B       ExternalInterrupts_9

                PUBWEAK ExternalInterrupts_10
                SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_10

                B       ExternalInterrupts_10

                PUBWEAK ExternalInterrupts_11
                SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_11

                B       ExternalInterrupts_11

				PUBWEAK ExternalInterrupts_12
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_12

				B		ExternalInterrupts_12

				PUBWEAK ExternalInterrupts_13
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_13

				B		ExternalInterrupts_13

				PUBWEAK ExternalInterrupts_14
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_14

				B		ExternalInterrupts_14

				PUBWEAK ExternalInterrupts_15
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_15

				B		ExternalInterrupts_15

				PUBWEAK ExternalInterrupts_16
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_16

				B		ExternalInterrupts_16

				PUBWEAK ExternalInterrupts_17
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_17

				B		ExternalInterrupts_17

				PUBWEAK ExternalInterrupts_18
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_18

				B		ExternalInterrupts_18

				PUBWEAK ExternalInterrupts_19
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_19

				B		ExternalInterrupts_19

				PUBWEAK ExternalInterrupts_20
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_20

				B		ExternalInterrupts_20

				PUBWEAK ExternalInterrupts_21
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_21

				B		ExternalInterrupts_21

				PUBWEAK ExternalInterrupts_22
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_22

				B		ExternalInterrupts_22

				PUBWEAK ExternalInterrupts_23
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_23

				B		ExternalInterrupts_23

				PUBWEAK ExternalInterrupts_24
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_24

				B		ExternalInterrupts_24

				PUBWEAK ExternalInterrupts_25
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_25

				B		ExternalInterrupts_25

				PUBWEAK ExternalInterrupts_26
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_26

				B		ExternalInterrupts_26

				PUBWEAK ExternalInterrupts_27
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_27

				B		ExternalInterrupts_27

				PUBWEAK ExternalInterrupts_28
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_28

				B		ExternalInterrupts_28

				PUBWEAK ExternalInterrupts_29
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_29

				B		ExternalInterrupts_29

				PUBWEAK ExternalInterrupts_30
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_30

				B		ExternalInterrupts_30

				PUBWEAK ExternalInterrupts_31
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_31

				B		ExternalInterrupts_31

				PUBWEAK ExternalInterrupts_32
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_32

				B		ExternalInterrupts_32

				PUBWEAK ExternalInterrupts_33
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_33

				B		ExternalInterrupts_33

				PUBWEAK ExternalInterrupts_34
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_34

				B		ExternalInterrupts_34

				PUBWEAK ExternalInterrupts_35
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_35

				B		ExternalInterrupts_35

				PUBWEAK ExternalInterrupts_36
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_36

				B		ExternalInterrupts_36

				PUBWEAK ExternalInterrupts_37
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_37

				B		ExternalInterrupts_37

				PUBWEAK ExternalInterrupts_38
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_38

				B		ExternalInterrupts_38

				PUBWEAK ExternalInterrupts_39
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_39

				B		ExternalInterrupts_39

				PUBWEAK ExternalInterrupts_40
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_40

				B		ExternalInterrupts_40

				PUBWEAK ExternalInterrupts_41
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_41

				B		ExternalInterrupts_41

				PUBWEAK ExternalInterrupts_42
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_42

				B		ExternalInterrupts_42

				PUBWEAK ExternalInterrupts_43
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_43

				B		ExternalInterrupts_43

				PUBWEAK ExternalInterrupts_44
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_44

				B		ExternalInterrupts_44

				PUBWEAK ExternalInterrupts_45
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_45

				B		ExternalInterrupts_45

				PUBWEAK ExternalInterrupts_46
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_46

				B		ExternalInterrupts_46

				PUBWEAK ExternalInterrupts_47
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_47

				B		ExternalInterrupts_47

				PUBWEAK ExternalInterrupts_48
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_48

				B		ExternalInterrupts_48

				PUBWEAK ExternalInterrupts_49
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_49

				B		ExternalInterrupts_49

				PUBWEAK ExternalInterrupts_50
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_50

				B		ExternalInterrupts_50

				PUBWEAK ExternalInterrupts_51
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_51

				B		ExternalInterrupts_51

				PUBWEAK ExternalInterrupts_52
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_52

				B		ExternalInterrupts_52

				PUBWEAK ExternalInterrupts_53
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_53

				B		ExternalInterrupts_53

				PUBWEAK ExternalInterrupts_54
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_54

				B		ExternalInterrupts_54

				PUBWEAK ExternalInterrupts_55
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_55

				B		ExternalInterrupts_55

				PUBWEAK ExternalInterrupts_56
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_56

				B		ExternalInterrupts_56

				PUBWEAK ExternalInterrupts_57
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_57

				B		ExternalInterrupts_57

				PUBWEAK ExternalInterrupts_58
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_58

				B		ExternalInterrupts_58

				PUBWEAK ExternalInterrupts_59
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_59

				B		ExternalInterrupts_59

				PUBWEAK ExternalInterrupts_60
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_60

				B		ExternalInterrupts_60

				PUBWEAK ExternalInterrupts_61
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_61

				B		ExternalInterrupts_61

				PUBWEAK ExternalInterrupts_62
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_62

				B		ExternalInterrupts_62

				PUBWEAK ExternalInterrupts_63
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_63

				B		ExternalInterrupts_63

				PUBWEAK ExternalInterrupts_64
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_64

				B		ExternalInterrupts_64

				PUBWEAK ExternalInterrupts_65
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_65

				B		ExternalInterrupts_65

				PUBWEAK ExternalInterrupts_66
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_66

				B		ExternalInterrupts_66

				PUBWEAK ExternalInterrupts_67
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_67

				B		ExternalInterrupts_67

				PUBWEAK ExternalInterrupts_68
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_68

				B		ExternalInterrupts_68

				PUBWEAK ExternalInterrupts_69
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_69

				B		ExternalInterrupts_69

				PUBWEAK ExternalInterrupts_70
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_70

				B		ExternalInterrupts_70

				PUBWEAK ExternalInterrupts_71
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_71

				B		ExternalInterrupts_71

				PUBWEAK ExternalInterrupts_72
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_72

				B		ExternalInterrupts_72

				PUBWEAK ExternalInterrupts_73
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_73

				B		ExternalInterrupts_73

				PUBWEAK ExternalInterrupts_74
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_74

				B		ExternalInterrupts_74

				PUBWEAK ExternalInterrupts_75
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_75

				B		ExternalInterrupts_75

				PUBWEAK ExternalInterrupts_76
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_76

				B		ExternalInterrupts_76

				PUBWEAK ExternalInterrupts_77
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_77

				B		ExternalInterrupts_77

				PUBWEAK ExternalInterrupts_78
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_78

				B		ExternalInterrupts_78

				PUBWEAK ExternalInterrupts_79
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_79

				B		ExternalInterrupts_79

				PUBWEAK ExternalInterrupts_80
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_80

				B		ExternalInterrupts_80

				PUBWEAK ExternalInterrupts_81
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_81

				B		ExternalInterrupts_81

				PUBWEAK ExternalInterrupts_82
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_82

				B		ExternalInterrupts_82

				PUBWEAK ExternalInterrupts_83
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_83

				B		ExternalInterrupts_83

				PUBWEAK ExternalInterrupts_84
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_84

				B		ExternalInterrupts_84

				PUBWEAK ExternalInterrupts_85
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_85

				B		ExternalInterrupts_85

				PUBWEAK ExternalInterrupts_86
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_86

				B		ExternalInterrupts_86

				PUBWEAK ExternalInterrupts_87
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_87

				B		ExternalInterrupts_87

				PUBWEAK ExternalInterrupts_88
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_88

				B		ExternalInterrupts_88

				PUBWEAK ExternalInterrupts_89
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_89

				B		ExternalInterrupts_89

				PUBWEAK ExternalInterrupts_90
				SECTION .text:CODE:REORDER:NOROOT(1)
ExternalInterrupts_90

				B		ExternalInterrupts_90




                END
