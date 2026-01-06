


#include "../../4.Driver/Include/DDI_BootingDriver.h"
#include "../../4.Driver/Include/WROS_Register.h"

#include "../../6.VariableSource/Include/Vable_ModelInformation.h"



void Micom_Reset(void);


void __iar_program_start(void);

/*********************************************************************
 <Description> :
 <Note> :
 *********************************************************************/
void DDI_WROS_BootMicom(void)
{	
  	MAKE_TEST_POINT(BOOT_START_FLAG);
	__disable_interrupt();	
	
	API_INT_Init();

	WROS_WDT_Init();
	WROS_PORT_Init();
	
	WROS_TMRB_Init();
	WROS_UART_Init();
//	WROS_DMA_Init();
	
	
	WROS_Tick_Init();
	WROS_NVIC_Init();	

	TOTAL_PENDING_CLEAR();
	
	__enable_interrupt();
	MAKE_TEST_POINT(BOOT_FINISH_FLAG);			 
}

void Micom_Reset(void)
{
	API_WDT_Disable();
	__iar_program_start();
}  

//End of File

