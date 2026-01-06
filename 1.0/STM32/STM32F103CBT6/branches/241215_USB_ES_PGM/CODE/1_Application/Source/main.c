#include "../../1_Application/Include/sys.h"
//#include "delay.h"
#include "../../2_Library/Include/Lib_usart.h"
//#include "led.h"
//#include "lcd.h"
#include "../../3_Driver/Include/usb_lib.h"
#include "../../3_Driver/Include/hw_config.h"
#include "../../3_Driver/Include/usb_pwr.h"

/************************************************
 ALIENTEK精英STM32开发板实验43
 USB虚拟串口 实验
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司
 作者：正点原子 @ALIENTEK
************************************************/


 int main(void)
 {
// 	u16 t;
//	u16 len;
	u8 usbstatus=0;
	SystemInit();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级


	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	//使能USART1，GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC, ENABLE);  //使能PB,PE端口时钟
	RCC_USBCLKConfig(RCC_USBCLKSource_PLLCLK_1Div5);//USBclk=PLLclk/1.5=48Mhz
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USB, ENABLE);	 //USB时钟使能


	uart_init(115200);	 	//串口初始化为115200
	
	USB->CTLR &= 0xFFFD;		// USB先断开  再次连接

 	USB_Interrupts_Init();
 	USB_Init();

	while(1)
	{
		if(usbstatus!=bDeviceState)//USB连接状态发生了改变.
		{	usbstatus=bDeviceState;//记录新的状态
			PCout(13) = usbstatus==CONFIGURED ? 0 : 1;	//  亮和灭
		}
	}




/*
	while(1)
	{
		if(usbstatus!=bDeviceState)//USB连接状态发生了改变.
		{
			usbstatus=bDeviceState;//记录新的状态
			if(usbstatus==CONFIGURED)
			{
				PCout(13)=0;//DS1亮
			}else
			{
				PCout(13)=1;//DS1灭
			}
		}
		if(USB_USART_RX_STA&0x8000)
		{
			len=USB_USART_RX_STA&0x3FFF;//得到此次接收到的数据长度
			//usb_printf("\r\n您发送的消息为:%d\r\n\r\n",len);
			for(t=0;t<len;t++)
			{
				USB_USART_SendData(USB_USART_RX_BUF[t]);//以字节方式,发送给USB
			}
			//usb_printf("\r\n\r\n");//插入换行
			USB_USART_RX_STA=0;
		}else
		{
			times++;
			if(times%5000==0)
			{
				usb_printf("\r\n精英STM32开发板USB虚拟串口实验\r\n");
				usb_printf("正点原子@ALIENTEK\r\n\r\n");
			}
			if(times%200==0)usb_printf("请输入数据,以回车键结束\r\n");
			if(times%30==0)LED0=!LED0;//闪烁LED,提示系统正在运行.
			delay_ms(10);
		}
	}
*/
}
