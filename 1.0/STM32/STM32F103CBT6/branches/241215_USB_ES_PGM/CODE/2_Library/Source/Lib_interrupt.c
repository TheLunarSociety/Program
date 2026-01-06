
#include "../../1_Application/Include/sys.h"
#include "../Include/Lib_usart.h"



//USB中断处理函数
void USB_LP_CAN1_RX0_IRQHandler(void)
{
	USB_Istr();
}

//USB唤醒中断服务函数
void USBWakeUp_IRQHandler(void)
{
	EXTI_ClearITPendingBit(EXTI_Line18);//清除USB唤醒中断挂起位
}


void USART1_IRQHandler(void)                	//串口1中断服务程序
{
	u8 Res;
	
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
		Res = USART_ReceiveData(USART1);	//读取接收到的数据

		if((USART_RX_STA & 0x8000) == 0)//接收未完成
		{
			if(USART_RX_STA & 0x4000)//接收到了0x0d
			{
				if(Res != 0x0a)
				{
					USART_RX_STA = 0;//接收错误,重新开始
				}
				else
				{
					USART_RX_STA  |= 0x8000;	//接收完成了
				}
			}
			else //还没收到0X0D
			{
				if(Res == 0x0d)
				{
					USART_RX_STA |= 0x4000;
				}
				else
				{
					USART_RX_BUF[USART_RX_STA & 0X3FFF] = Res ;
					USART_RX_STA++;
					
					if(USART_RX_STA > (USART_REC_LEN - 1))
					{	
						USART_RX_STA = 0;//接收数据错误,重新开始接收
					}
					else
					{	;
					}
				}
			}
		}
	}
}
