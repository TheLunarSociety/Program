


#ifndef __M470_SIO_H
#define __M470_SIO_H


void		WROS_UART_Init(void);
void		API_UART_Setting(WROS_UART__TypeDef*, UINT8);
void		API_SIO_SndDataSet(WROS_UART__TypeDef*, UINT8);
UINT8		API_SIO_RcvDataRead(WROS_UART__TypeDef*);

#endif /* __M470_SIO_H */

