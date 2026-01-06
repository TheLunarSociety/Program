

#include <string.h>

#include "../../1.Application/Include/main.h"
#include "../../4.Driver/Include/DDI_BootingDriver.h"

#include "../../4.Driver/Include/WRRTOS.h"
#include "../../4.Driver/Include/WROS_Register.h"


volatile UINT32 TEST_COUNT = 0;

#define PRIVILEGED_DATA		_Pragma("location=\"WROS_section\"")

static __no_init uint32_t  ucHeap[HEAP_SIZE] 				@ 0x20004000;

PRIVILEGED_DATA static volatile UINT32 uSchedulerSuspended					= CLEAR;
PRIVILEGED_DATA static volatile UINT32 uCurrentNumberOfTasks				= CLEAR;
PRIVILEGED_DATA static volatile UINT32 xYieldPending 						= CLEAR;
PRIVILEGED_DATA static volatile UINT32 uxPendedTicks 						= CLEAR;
PRIVILEGED_DATA static volatile UINT32 xSchedulerRunning 					= CLEAR;
PRIVILEGED_DATA static volatile UINT32 uxTopReadyPriority 					= CLEAR;
PRIVILEGED_DATA static volatile UINT32 xNextTaskUnblockTime					= CLEAR;
PRIVILEGED_DATA static volatile UINT32 uxSchedulerSuspended					= CLEAR;
PRIVILEGED_DATA static volatile UINT32 xTickCount 							= CLEAR;
PRIVILEGED_DATA static volatile UINT32 xNumOfOverflows 						= CLEAR;

PRIVILEGED_DATA static 			UINT32 uxTaskNumber 						= CLEAR;


PRIVILEGED_DATA static List_t pxReadyTasksLists[MAX_PRIORITIES]				= {0};
PRIVILEGED_DATA static List_t xDelayedTaskList1								= {0};
PRIVILEGED_DATA static List_t xDelayedTaskList2								= {0};
PRIVILEGED_DATA static List_t xActiveTimerList1 							= {0};
PRIVILEGED_DATA static List_t xActiveTimerList2 							= {0};
PRIVILEGED_DATA static List_t xPendingReadyList								= {0};
PRIVILEGED_DATA static List_t xSuspendedTaskList							= {0};
PRIVILEGED_DATA static List_t xTasksWaitingTermination						= {0};
PRIVILEGED_DATA static List_t * volatile pxDelayedTaskList					= NULL;
PRIVILEGED_DATA static List_t * volatile pxOverflowDelayedTaskList			= NULL;
//PRIVILEGED_DATA static List_t * pxCurrentTimerList 							= NULL;
//PRIVILEGED_DATA static List_t * pxOverflowTimerList 						= NULL;

PRIVILEGED_DATA static void* xTimerQueue									= NULL;

PRIVILEGED_DATA TCB_t * volatile pxCurrentTCB								= NULL;


static SIZE_T MinimumEverFreeBytesRemaining;
static SIZE_T FreeBytesRemaining;

static UINT32 uCriticalNesting = 0xAAAAAAAA;



//	Check it is ture
#define listGET_OWNER_OF_HEAD_ENTRY(pxList)		((&((pxList)->xListEnd))->pxNext->pvOwner)
#define listCURRENT_LIST_LENGTH(pxList)			((pxList)->uxNumberOfItems)
#define listGET_LIST_ITEM_VALUE(pxListItem)		((pxListItem)->xItemValue)
#define listLIST_ITEM_CONTAINER(pxListItem) 	((pxListItem)->pvContainer)
#define listLIST_IS_EMPTY(pxList)				((UINT32)((pxList)->uxNumberOfItems == 0))
#define portSETUP_TCB(pxTCB)					(void) pxTCB



#define listGET_OWNER_OF_NEXT_ENTRY(pxTCB, pxList)										\
{																							\
	List_t * const pxConstList = (pxList);												\
	(pxConstList)->pxIndex = (pxConstList)->pxIndex->pxNext;							\
	if((void *) (pxConstList)->pxIndex == (void *) &((pxConstList)->xListEnd))	\
	{																						\
		(pxConstList)->pxIndex = (pxConstList)->pxIndex->pxNext;						\
	}																						\
	(pxTCB) = (pxConstList)->pxIndex->pvOwner;											\
}

#define taskSELECT_HIGHEST_PRIORITY_TASK()															\
{																									\
	UINT32 uxTopPriority = uxTopReadyPriority; 														\
																									\
	while(listLIST_IS_EMPTY(&(pxReadyTasksLists[uxTopPriority])))									\
	{																								\
		AlignCheck(uxTopPriority);																	\
		--uxTopPriority;																			\
	}																								\
																									\
	listGET_OWNER_OF_NEXT_ENTRY(pxCurrentTCB, &(pxReadyTasksLists[ uxTopPriority ]));			\
	uxTopReadyPriority = uxTopPriority; 															\
}


#define CodePacketStart
#define CodePacketEnd

/*
void WROS_TaskIDLE(T_DispInfo* psDisplayInfo)	
{
	while(1){}
};
*/
/* Scheduler utilities. */
#define portYIELD()																\
{																				\
	(* ((volatile UINT32 *) 0xE000ED04)) = (1UL << 28UL);						\
																				\
	__DSB(15);																	\
	__ISB(15);																	\
}

static inline void vPortRaiseBASEPRI(void)
{

	// 直接在汇编中写入优先级数值（假设为3）
	// ulNewBASEPRI = (3 << 4)
	__asm("mov r0, #0x60");
	__asm("msr basepri, r0");
	__asm("dsb");
	__asm("isb");

}

static inline void vPortSetBASEPRI(void)
{
    __asm("mov r0, #0");
    __asm("msr basepri, r0");
}

static void TaskExitError(void)
{
	MAKE_TEST_POINT(TASK_EXIT_ERR_FLAG);
	AlignCheck(uCriticalNesting == ~0UL);
	vPortRaiseBASEPRI();
	for(;;);
}

static void ENTER_CRITICAL(void)	
{

	vPortRaiseBASEPRI();              // DISENABLE_INTERRUPTS
	uCriticalNesting++;

	if(uCriticalNesting == 1)
	{
		AlignCheck(((*((volatile UINT32 *)0xe000ed04)) & (0xFFUL)) == 0);
	}
	else
	{	;
	}
}

static void EXIT_CRITICAL(void)	
{

	AlignCheck(uCriticalNesting);
	uCriticalNesting--;
	if(uCriticalNesting == 0)
	{
		vPortSetBASEPRI();  // ENABLE_INTERRUPTS
	}
}

static void AddTaskToReadyList(TCB_t *pxNewTCB)
{
    ListItem_t * const pxIndex = (&pxReadyTasksLists[pxNewTCB->uxPriority])->pxIndex;

    // 核心：双向链表尾部插入（按FreeRTOS链表设计，插入到pxIndex之前）
    (&pxNewTCB->xStateListItem)->pxNext = pxIndex;
    (&pxNewTCB->xStateListItem)->pxPrevious = pxIndex->pxPrevious;
    pxIndex->pxPrevious->pxNext = (&pxNewTCB->xStateListItem);
    pxIndex->pxPrevious = (&pxNewTCB->xStateListItem);

    // 记录节点所属链表 + 更新链表节点计数
    (&pxNewTCB->xStateListItem)->pvContainer = &pxReadyTasksLists[pxNewTCB->uxPriority];
    (&pxReadyTasksLists[pxNewTCB->uxPriority])->uxNumberOfItems++;
}

static UINT32 uxListRemove(ListItem_t * const pxItemToRemove)	
{
	List_t * const pxList = (List_t *) pxItemToRemove->pvContainer;
	
	// pxItemToRemove->pxNext->pxPrevious = pxItemToRemove->pxPrevious;
	// pxItemToRemove->pxPrevious->pxNext = pxItemToRemove->pxNext;
	
	// 1. 先用中间变量暂存 volatile 指针的值（只访问一次 volatile）
	ListItem_t * const pxNext = pxItemToRemove->pxNext;    // 暂存 next 指针
	ListItem_t * const pxPrev = pxItemToRemove->pxPrevious;  // 暂存 previous 指针

	// 2. 通过中间变量操作，避免同一表达式中多次访问 volatile
	pxNext->pxPrevious = pxPrev;  // 原行146
	pxPrev->pxNext = pxNext;      // 原行147

	if(pxList->pxIndex == pxItemToRemove)
	{
		pxList->pxIndex = pxItemToRemove->pxPrevious;
	}
	else
	{	;
	}

	pxItemToRemove->pvContainer = NULL;
	(pxList->uxNumberOfItems)--;

	return pxList->uxNumberOfItems;
}

UINT32 xTaskIncrementTick(void)
{
	TCB_t * pxTCB;
	UINT32 xItemValue;
	UINT32 xSwitchRequired = CLEAR;

	if(uxSchedulerSuspended == (UINT32) CLEAR)
	{
		const UINT32 xConstTickCount = xTickCount + (UINT32) 1;

		xTickCount = xConstTickCount;

		if(xConstTickCount == (UINT32) 0U) /*lint !e774 'if' does not always evaluate to false as it is looking for an overflow. */
		{
			// taskSWITCH_DELAYED_LISTS();	
			List_t *pxTemp;																
																						
			/* The delayed tasks list should be empty when the lists are switched. */	
			AlignCheck(pxDelayedTaskList->uxNumberOfItems == CLEAR);					
																						
			pxTemp = pxDelayedTaskList;													
			pxDelayedTaskList = pxOverflowDelayedTaskList;								
			pxOverflowDelayedTaskList = pxTemp;											
			xNumOfOverflows++;	
			
			// prvResetNextTaskUnblockTime();	
			if(pxDelayedTaskList->uxNumberOfItems != CLEAR)
			{
				xNextTaskUnblockTime = 0xFFFFFFFF;
			}
			else
			{
				(pxTCB) = (TCB_t *) ((&(pxDelayedTaskList->xListEnd))->pxNext->pvOwner);
				xNextTaskUnblockTime = ((pxTCB)->xStateListItem).xItemValue;
			}
		}
		else
		{	;
		}

		if(xConstTickCount >= xNextTaskUnblockTime)
		{
			for(;;)
			{
				if(pxDelayedTaskList->uxNumberOfItems != CLEAR)
				{
					xNextTaskUnblockTime = 0xFFFFFFFF; /*lint !e961 MISRA exception as the casts are only redundant for some ports. */
					break;
				}
				else
				{
					pxTCB = (TCB_t *) ((&((pxDelayedTaskList)->xListEnd))->pxNext->pvOwner);
					xItemValue = (&(pxTCB->xStateListItem))->xItemValue;

					if(xConstTickCount < xItemValue)
					{
						xNextTaskUnblockTime = xItemValue;
						break;
					}
					else
					{	;
					}

					(void) uxListRemove(&(pxTCB->xStateListItem));

					if((&(pxTCB->xEventListItem))->pvContainer != NULL)
					{
						(void) uxListRemove(&(pxTCB->xEventListItem));
					}
					else
					{	;
					}

					AddTaskToReadyList(pxTCB);

					#if ( configUSE_PREEMPTION == 1)
					{
						if(pxTCB->uxPriority >= pxCurrentTCB->uxPriority)
						{
							xSwitchRequired = TRUE;
						}
						else
						{	;
						}
					}
					#endif /* configUSE_PREEMPTION */
				}
			}
		}

		#if ((configUSE_PREEMPTION == 1) && (configUSE_TIME_SLICING == 1))
		{
			if(listCURRENT_LIST_LENGTH(&(pxReadyTasksLists[pxCurrentTCB->uxPriority])) > (UINT32) 1)
			{
				xSwitchRequired = TRUE;
			}
			else
			{	;
			}
		}
		#endif /* ((configUSE_PREEMPTION == 1) && (configUSE_TIME_SLICING == 1)) */

		#if (configUSE_TICK_HOOK == 1)
		{
			if(uxPendedTicks == (UINT32) 0U)
			{
				vApplicationTickHook();
			}
			else
			{	;
			}
		}
		#endif /* configUSE_TICK_HOOK */
	}
	else
	{
		++uxPendedTicks;
	}

	#if (configUSE_PREEMPTION == 1)
	{
		if(xYieldPending != CLEAR)
		{
			xSwitchRequired = SET;
		}
		else
		{	;
		}
	}
	#endif /* configUSE_PREEMPTION */

	return xSwitchRequired;
}

static void TaskSuspendAll(void)	
{	++uSchedulerSuspended;
}

static UINT32 TaskResumeAll(void)
{
	TCB_t *pxTCB = NULL;
	UINT32 xAlreadyYielded = RETURN_NG;

	AlignCheck(uSchedulerSuspended);

	ENTER_CRITICAL();
	{
		--uSchedulerSuspended;

		if(uSchedulerSuspended == (UINT32) CLEAR)
		{
			if(uCurrentNumberOfTasks > (UINT32) 0U)
			{
				while(xPendingReadyList.uxNumberOfItems != CLEAR)
				{
					pxTCB = (TCB_t *) listGET_OWNER_OF_HEAD_ENTRY((&xPendingReadyList));
					(void) uxListRemove(&(pxTCB->xEventListItem));
					(void) uxListRemove(&(pxTCB->xStateListItem));

					
					AddTaskToReadyList(pxTCB);

					if(pxTCB->uxPriority >= pxCurrentTCB->uxPriority)
					{
						xYieldPending = RETURN_OK;
					}
					else
					{	;
					}
				}// xPendingReadyList.uxNumberOfItems != CLEAR

				if(pxTCB != NULL)
				{
					// prvResetNextTaskUnblockTime();
					TCB_t *pxTCB;

					if(pxDelayedTaskList->uxNumberOfItems != CLEAR)
					{
						xNextTaskUnblockTime = 0xFFFFFFFF;
					}
					else
					{
						(pxTCB) = (TCB_t *) ((&(pxDelayedTaskList->xListEnd))->pxNext->pvOwner);
						xNextTaskUnblockTime = ((pxTCB)->xStateListItem).xItemValue;
					}
				}// pxTCB != NULL
				else
				{	;
				}
				
				CodePacketStart
				{
					UINT32 uxPendedCounts = uxPendedTicks;

					if(uxPendedCounts > (UINT32) 0U)
					{
						do
						{
							if(xTaskIncrementTick() != RETURN_NG)
							{
								xYieldPending = RETURN_OK;
							}
							else
							{	;
							}
							--uxPendedCounts;
						} while(uxPendedCounts > (UINT32) 0U);

						uxPendedTicks = 0;
					}
					else
					{	;
					}
				}
				CodePacketEnd

				if(xYieldPending != RETURN_NG)
				{
					xAlreadyYielded = RETURN_OK;
					portYIELD();
				}
				else
				{	;
				}
			}// uCurrentNumberOfTasks > (UINT32) 0U
			else
			{	;
			}
		}// uSchedulerSuspended == (UINT32) CLEAR 
		else 
		{	;
		}
	}
	EXIT_CRITICAL();

	return xAlreadyYielded;
}


#define TaskBlockManager

void vListInitialise(List_t * const pxList)
{
	pxList->pxIndex				= (ListItem_t *) &(pxList->xListEnd);			/*lint !e826 !e740 The mini list structure is used as the list end to save RAM.  This is checked and valid. */

	pxList->xListEnd.xItemValue	= 0xFFFFFFFF;
	pxList->xListEnd.pxNext		= (ListItem_t *) &(pxList->xListEnd);	/*lint !e826 !e740 The mini list structure is used as the list end to save RAM.  This is checked and valid. */
	pxList->xListEnd.pxPrevious	= (ListItem_t *) &(pxList->xListEnd);/*lint !e826 !e740 The mini list structure is used as the list end to save RAM.  This is checked and valid. */

	pxList->uxNumberOfItems		= CLEAR;
}

static UINT32 * pInitialiseStack(UINT32 *pxTopOfStack, void_DispInfo_func pxCode, void * pvParameters)
{
	// Simulate the stack frame as it would be created by a context switch interrupt.
	// Offset added to account for the way the MCU uses the stack on entry/exit of interrupts.
	// xPSR
	pxTopOfStack--; 												
	*pxTopOfStack = (0x01000000);
	// PC
	pxTopOfStack--;
	*pxTopOfStack = ((UINT32) pxCode) & ((UINT32) 0xFFFFFFFE);	
	// LR
	pxTopOfStack--;
	*pxTopOfStack = (UINT32) TaskExitError;
	// R12
	pxTopOfStack --;									
	*pxTopOfStack = (0x00000000);



	
	// R3
	pxTopOfStack --;									
	*pxTopOfStack = (0x00000000);						
	// R2
	pxTopOfStack --;									
	*pxTopOfStack = (0x00000000);						
	// R1
	pxTopOfStack --;									
	*pxTopOfStack = (0x00000000);						
	// R0
	pxTopOfStack --;									
	*pxTopOfStack = (UINT32) pvParameters;



	
	// R11
	pxTopOfStack --;												
	*pxTopOfStack = (0x00000000);									
	// R10
	pxTopOfStack --;												
	*pxTopOfStack = (0x00000000);									
	// R9
	pxTopOfStack --;												
	*pxTopOfStack = (0x00000000);									
	// R8
	pxTopOfStack --;												
	*pxTopOfStack = (0x00000000);



	
	// R7
	pxTopOfStack --;												
	*pxTopOfStack = (0x00000000);									
	// R6
	pxTopOfStack --;												
	*pxTopOfStack = (0x00000000);									
	// R5
	pxTopOfStack --;												
	*pxTopOfStack = (0x00000000);									
	// R4
	pxTopOfStack --;												
	*pxTopOfStack = (0x00000000);									
	
	return pxTopOfStack;
}

static void AddNewTaskToReadyList(TCB_t *pxNewTCB)
{
	ENTER_CRITICAL();
	{
		uCurrentNumberOfTasks++;
		uxTaskNumber++;
		pxNewTCB->uxTCBNumber = uxTaskNumber;
		
		if(pxCurrentTCB == NULL)
		{
			pxCurrentTCB = pxNewTCB;
		}
		else
		{
			/* If the scheduler is not running, make the highest priority task to be current*/
			if(xSchedulerRunning == CLEAR)
			{
				if(pxNewTCB->uxPriority >= pxCurrentTCB->uxPriority)
				{
					pxCurrentTCB = pxNewTCB;
				}
				else
				{	;
				}
			}
			else
			{	;
			}
		}

		/* Add a counter into the TCB for tracing only. */
		if(pxNewTCB->uxPriority > uxTopReadyPriority)
		{
			uxTopReadyPriority = (pxNewTCB->uxPriority);
		}
		else
		{	;
		}
		
		//uxTopReadyPriority |= (1UL << (pxNewTCB->uxPriority));

		AddTaskToReadyList(pxNewTCB);

		portSETUP_TCB(pxNewTCB);
	}
	EXIT_CRITICAL();

	if(xSchedulerRunning != CLEAR)
	{
		if(pxNewTCB->uxPriority > pxCurrentTCB->uxPriority)
		{
			// taskYIELD_IF_USING_PREEMPTION();
			portYIELD();
		}
		else
		{	;
		}
	}
	else
	{	;
	}
}

static void InitialiseNewTask(struct device* P_DEVICE, T_DispInfo* psDisplayInfo, UINT32* pNewTaskStack, TCB_t* pNewTaskCtlBlk)
{
	//	_REENT_INIT_PTR((&(pxNewTCB->xNewLib_reent)));


	//vListInitialiseItem(&(pxNewTCB->xStateListItem));
	//vListInitialiseItem(&(pxNewTCB->xEventListItem));
	(&(pNewTaskCtlBlk->xStateListItem))->pvContainer	= NULL;
	(&(pNewTaskCtlBlk->xEventListItem))->pvContainer	= NULL;
	
	//listSET_LIST_ITEM_OWNER(&(pxNewTCB->xStateListItem), pxNewTCB);
	(&(pNewTaskCtlBlk->xStateListItem))->pvOwner		= pNewTaskCtlBlk;

	//listSET_LIST_ITEM_VALUE(&(pxNewTCB->xEventListItem), (TickType_t) configMAX_PRIORITIES - (TickType_t) uxPriority); /*lint !e961 MISRA exception as the casts are only redundant for some ports. */
	//listSET_LIST_ITEM_OWNER(&(pxNewTCB->xEventListItem), pxNewTCB);
	(&(pNewTaskCtlBlk->xEventListItem))->xItemValue		= (UINT32) MAX_PRIORITIES - (UINT32) P_DEVICE->driver_level; /*lint !e961 MISRA exception as the casts are only redundant for some ports. */
	(&(pNewTaskCtlBlk->xEventListItem))->pvOwner		= pNewTaskCtlBlk;

	// Set "pNewTaskCtlBlk->pxStack" default 0xAA
	pNewTaskCtlBlk->pxStack			= pNewTaskStack;
	memset(pNewTaskCtlBlk->pxStack, (int) 0xAA, (SIZE_T)P_DEVICE->driver_StackDepth * sizeof(UINT32));

	// Set "pNewTaskCtlBlk->pxEndOfStack"
	UINT32* pTopOfStack;
	pTopOfStack = pNewTaskCtlBlk->pxStack + (P_DEVICE->driver_StackDepth);
	pTopOfStack = (UINT32 *)(((UINT32) pTopOfStack) & (~((UINT32) 0x0007)));
	AlignCheck((((UINT32)pTopOfStack & (UINT32) 0x0007) == 0UL));
	pNewTaskCtlBlk->pxEndOfStack	= pTopOfStack;

	// Set "pNewTaskCtlBlk->pxTopOfStack"
	pNewTaskCtlBlk->pxTopOfStack	= pInitialiseStack(pTopOfStack, P_DEVICE->driver_api, psDisplayInfo);

	// Set "pNewTaskCtlBlk->uxPriority"
	// Set "pNewTaskCtlBlk->uxBasePriority"
	MAX_Limite(P_DEVICE->driver_level, MAX_PRIORITIES - 1, MAX_PRIORITIES - 1);
	pNewTaskCtlBlk->uxPriority			= P_DEVICE->driver_level;
	pNewTaskCtlBlk->uxBasePriority		= P_DEVICE->driver_level;


	// Set "pNewTaskCtlBlk->pcTaskName" total 16 char
	UINT8 x = 0;
	while(P_DEVICE->name[x] != '\0' && x <= 14)
	{
		pNewTaskCtlBlk->pcTaskName[x]	= P_DEVICE->name[x];
		x++;
	}
	pNewTaskCtlBlk->pcTaskName[15]		= '\0';
	
	// Set "pNewTaskCtlBlk->uxCriticalNesting"
	pNewTaskCtlBlk->uxCriticalNesting	= (UINT32) 0U;

	// Set "pNewTaskCtlBlk->uxMutexesHeld"
	pNewTaskCtlBlk->uxMutexesHeld		= 0UL;
	
	// Set "pNewTaskCtlBlk->ulRunTimeCounter"
	pNewTaskCtlBlk->ulRunTimeCounter	= 0UL;
	
	
	// Set "pNewTaskCtlBlk->ulNotifiedValue"
	// Set "pNewTaskCtlBlk->ucNotifyState"
	pNewTaskCtlBlk->ulNotifiedValue		= 0;
	pNewTaskCtlBlk->ucNotifyState		= taskNOT_WAITING_NOTIFICATION;
	
	// Set "pNewTaskCtlBlk->ucDelayAborted"
	pNewTaskCtlBlk->ucDelayAborted		= CLEAR;
	
	
	if((void*)(&(P_DEVICE->driver_TaskHandle)) != NULL)
	{
		P_DEVICE->driver_TaskHandle = (TCB_t*) pNewTaskCtlBlk;
	}
	else
	{	;
	}
}

static void BlockIntoFreeList(BlockLink_t *pIntoListBlock)
{
	BlockLink_t * pxIterator;
	UINT8 * puc;

	//	Search front free block link
	for(pxIterator = &T_Block_Start; pxIterator->pNextFreeBlock < pIntoListBlock; pxIterator = pxIterator->pNextFreeBlock)
	{
	}
	
	puc = (UINT8*) pxIterator;
	if((puc + pxIterator->BlockSize) == (UINT8*) pIntoListBlock)
	{
		pxIterator->BlockSize	+= pIntoListBlock->BlockSize;
		pIntoListBlock			= pxIterator;
	}
	else
	{	;
	}
	
	puc = (UINT8*) pIntoListBlock;
	if((puc + pIntoListBlock->BlockSize) == (UINT8*) pxIterator->pNextFreeBlock)
	{
		if(pxIterator->pNextFreeBlock != P_Block_End)
		{
			/* Form one big block from the two blocks. */
			pIntoListBlock->BlockSize += pxIterator->pNextFreeBlock->BlockSize;
			pIntoListBlock->pNextFreeBlock = pxIterator->pNextFreeBlock->pNextFreeBlock;
		}
		else
		{
			pIntoListBlock->pNextFreeBlock = P_Block_End;
		}
	}
	else
	{
		pIntoListBlock->pNextFreeBlock = pxIterator->pNextFreeBlock;
	}
	
	if(pxIterator != pIntoListBlock)
	{
		pxIterator->pNextFreeBlock = pIntoListBlock;
	}
	else
	{	;
	}
}

static void * AllocMalloc(SIZE_T RequestSize)
{
	BlockLink_t *p_TotalSection, *p_CurrentBlock, *p_FrontOneBlock, *p_NewBlockLink;
	void *pReturn = NULL;
	
	TaskSuspendAll();
	{
		//	HeapInit
		if(P_Block_End == NULL)
		{
			memset(ucHeap, 0, sizeof(ucHeap));
			
			T_Block_Start.pNextFreeBlock	= (void*)ucHeap;
			T_Block_Start.BlockSize			= (SIZE_T)0;

			P_Block_End 					= (void*)((ucHeap + HEAP_SIZE) - BlockStructStandard);
			P_Block_End->pNextFreeBlock		= (void*)NULL;
			P_Block_End->BlockSize			= (SIZE_T)0;

			p_TotalSection					= (void*)ucHeap;
			p_TotalSection->BlockSize		= (SIZE_T)P_Block_End - (SIZE_T)ucHeap;
			p_TotalSection->pNextFreeBlock	= P_Block_End;

			MinimumEverFreeBytesRemaining	= p_TotalSection->BlockSize;
			FreeBytesRemaining				= p_TotalSection->BlockSize;
		}
		else
		{	;
		}
		
		//	Not over Allocated Size
		if((RequestSize & BlockAllocatedBit) == 0 && (RequestSize <= FreeBytesRemaining))
		{
			RequestSize += sizeof(BlockLink_t);		// Include P_Block_End Size
			AlignSet(RequestSize);
			AlignCheck((RequestSize & 0x0007) == 0);

			p_FrontOneBlock	= &T_Block_Start;
			p_CurrentBlock	= T_Block_Start.pNextFreeBlock;
			while((p_CurrentBlock->BlockSize < RequestSize) && (p_CurrentBlock->pNextFreeBlock != NULL))
			{
				p_FrontOneBlock	= p_CurrentBlock;
				p_CurrentBlock	= p_CurrentBlock->pNextFreeBlock;
			}

			if(p_CurrentBlock != P_Block_End)
			{	
				pReturn = (void*)(((UINT8*) p_FrontOneBlock->pNextFreeBlock) + BlockStructStandard);
				
				// put rear block link with front block link, Current block link release
				p_FrontOneBlock->pNextFreeBlock = p_CurrentBlock->pNextFreeBlock;	
				
				if((p_CurrentBlock->BlockSize - RequestSize) > (BlockStructStandard << 1))
				{
					p_NewBlockLink				= (void*)(((UINT8*) p_CurrentBlock) + RequestSize);
					AlignCheck((((SIZE_T) p_NewBlockLink) & 0x0007) == 0);						// check align 8
					p_NewBlockLink->BlockSize	= p_CurrentBlock->BlockSize - RequestSize;
					p_CurrentBlock->BlockSize	= RequestSize;
					
					BlockIntoFreeList(p_NewBlockLink);
				}
				else
				{	;
				}

				FreeBytesRemaining -= p_CurrentBlock->BlockSize;

				if(FreeBytesRemaining < MinimumEverFreeBytesRemaining)
				{
					MinimumEverFreeBytesRemaining = FreeBytesRemaining;
				}
				else
				{	;
				}
				p_CurrentBlock->BlockSize |= BlockAllocatedBit;
				p_CurrentBlock->pNextFreeBlock = NULL;
			}
			else
			{	;
			}
		}
		else
		{	;
		}
	}
	TaskResumeAll();
	
	AlignCheck((((SIZE_T)pReturn) & 0x0007) == 0);
	return pReturn;
}

static void ReleaseMalloc(void * pRelease)
{
	BlockLink_t *pReleaseBlock = (BlockLink_t*)((UINT8*)pRelease - BlockStructStandard);

	AlignCheck((pReleaseBlock->BlockSize & BlockAllocatedBit) != 0);
	AlignCheck(pReleaseBlock->pNextFreeBlock == NULL);

	if((pReleaseBlock->BlockSize & BlockAllocatedBit) != 0)
	{
		if(pReleaseBlock->pNextFreeBlock == NULL)
		{
			pReleaseBlock->BlockSize &= ~BlockAllocatedBit;

			TaskSuspendAll();
			{
				FreeBytesRemaining += pReleaseBlock->BlockSize;
				BlockIntoFreeList((BlockLink_t *)pReleaseBlock);
			}
			TaskResumeAll();
		}
		else
		{	;
		}
	}
	else
	{	;
	}
}

static void WROS_State_Init()
{
	UINT8 PRIORITIES = 0;
	while(PRIORITIES < SIZE_OF_ARRAY(pxReadyTasksLists)){vListInitialise(&pxReadyTasksLists[PRIORITIES++]);};
	
	vListInitialise(&xDelayedTaskList1);
	vListInitialise(&xDelayedTaskList2);
	vListInitialise(&xActiveTimerList1);
	vListInitialise(&xActiveTimerList2);
	vListInitialise(&xPendingReadyList);
	vListInitialise(&xSuspendedTaskList);
	vListInitialise(&xTasksWaitingTermination);
	
	uSchedulerSuspended					= CLEAR;
	uCurrentNumberOfTasks				= CLEAR;
	xYieldPending 						= CLEAR;
	uxPendedTicks 						= CLEAR;
	xSchedulerRunning 					= CLEAR;
	uxTopReadyPriority 					= CLEAR;
	xNextTaskUnblockTime				= CLEAR;
	uxSchedulerSuspended				= CLEAR;
	xTickCount 							= CLEAR;
	xNumOfOverflows 					= CLEAR;
	uxTaskNumber 						= CLEAR;

//	pxCurrentTimerList					= &xActiveTimerList1;
//	pxOverflowTimerList					= &xActiveTimerList2;
	pxDelayedTaskList					= &xDelayedTaskList1;
	pxOverflowDelayedTaskList			= &xDelayedTaskList2;
	
	pxCurrentTCB 						= NULL;
	xTimerQueue 						= NULL;
}

static UINT32 WROS_TaskCreate(struct device* P_DEVICE, T_DispInfo* psDisplayInfo) 
{
	UINT32*	pNewTask_Stack	= NULL;;
	TCB_t*	pNewTask_CtlBlk	= NULL;

	pNewTask_Stack = (UINT32*)(AllocMalloc((P_DEVICE->driver_StackDepth) * sizeof(UINT32)));
	if(pNewTask_Stack != NULL)
	{
		pNewTask_CtlBlk = (TCB_t*)AllocMalloc(sizeof(TCB_t));
		if(pNewTask_CtlBlk != NULL)
		{			
			InitialiseNewTask(P_DEVICE, psDisplayInfo, pNewTask_Stack, pNewTask_CtlBlk);
			AddNewTaskToReadyList(pNewTask_CtlBlk);
			return RETURN_OK;
		}
		else
		{	
			ReleaseMalloc(pNewTask_Stack);
			P_DEVICE->driver_ErrorIndex = A2_Error;
		}
	}
	else
	{
		P_DEVICE->driver_ErrorIndex = A1_Error;
	}
	
	return RETURN_NG;
}

void WROS_FUNC_Task_IDLE(T_DispInfo* psDisplayInfo)	
{
	__asm("mov r0, #0");
	__asm("msr basepri, r0");
	
	__asm("dsb");
	__asm("isb");
};

void WROS_FUNC_Timer_Task(T_DispInfo* P_DispInfo)
{
	static UINT32 Timer_Task_Count = 0;
	while(1)
	{
		API_WDT_Set_Wdt_Nmi_Clr();												//	Clear watch dog
		CounterAddLimit(Timer_Task_Count, 0, 65535);
	}
}


void DDI_WROS_Init(T_DispInfo* psDisplayInfo)
{
	App_Init_State(psDisplayInfo);
	WROS_State_Init();
	WROS_TaskCreate(&WROS_DEV_PLATFORMCOMM,	psDisplayInfo);
	WROS_TaskCreate(&WROS_DEV_DISPLAY,		psDisplayInfo);
	WROS_TaskCreate(&WROS_DEV_JIGKEYSCAN,	psDisplayInfo);
	WROS_TaskCreate(&WROS_DEV_ERRORCHECK,	psDisplayInfo);
	WROS_TaskCreate(&WROS_DEV_LQCPROCESS,	psDisplayInfo);
	WROS_TaskCreate(&WROS_DEV_TaskIDLE,		psDisplayInfo);					// not use
	WROS_TaskCreate(&WROS_DEV_TimerTask,	psDisplayInfo);
	MAKE_TEST_POINT(TASK_CREATE_FLAG);	
}

#define TaskStart

//#pragma required=8
static void prvStartFirstTask(void)
{
	// PRESERVE8
	// __asm("ldr r0, =0xE000ED08");
	// __asm("ldr r0, =0xE000ED08");

	//__asm("movw r0, #0xED08"); 
	//__asm("movt r0, #0xE000"); 
	//__asm("ldr r0, [r0]");
	//__asm("ldr r0, [r0]");
	//__asm("msr msp, r0");
	
	vPortSetBASEPRI();

	__asm("cpsie i");
	__asm("cpsie f");
        
	__asm("dsb");
	__asm("isb");
	
	__asm("svc 0");
	__asm("nop");
	__asm("nop");
}

static void vListInsertEnd(List_t * const pxList, ListItem_t * const pxNewListItem)
{
	ListItem_t * const pxIndex = pxList->pxIndex;

	//listTEST_LIST_INTEGRITY(pxList);
	//listTEST_LIST_ITEM_INTEGRITY(pxNewListItem);

	pxNewListItem->pxNext = pxIndex;
	pxNewListItem->pxPrevious = pxIndex->pxPrevious;

	//mtCOVERAGE_TEST_DELAY();

	pxIndex->pxPrevious->pxNext = pxNewListItem;
	pxIndex->pxPrevious = pxNewListItem;

	pxNewListItem->pvContainer = (void *) pxList;

	(pxList->uxNumberOfItems)++;
}

static void prvResetNextTaskUnblockTime(void)
{
	TCB_t *pxTCB;

	if(listLIST_IS_EMPTY(pxDelayedTaskList) != FALSE)
	{
		xNextTaskUnblockTime = 0xFFFFFFFF;
	}
	else
	{
		(pxTCB) = (TCB_t *) listGET_OWNER_OF_HEAD_ENTRY(pxDelayedTaskList);
		xNextTaskUnblockTime = listGET_LIST_ITEM_VALUE(&((pxTCB)->xStateListItem));
	}
}

static UINT32 xTaskRemoveFromEventList(const List_t * const pxEventList)
{
	TCB_t *pxUnblockedTCB;
	UINT32 xReturn;


	pxUnblockedTCB = (TCB_t *) listGET_OWNER_OF_HEAD_ENTRY(pxEventList);
	AlignCheck(pxUnblockedTCB);
	(void) uxListRemove(&(pxUnblockedTCB->xEventListItem));

	if(uxSchedulerSuspended == (UINT32) FALSE)
	{
		(void) uxListRemove(&(pxUnblockedTCB->xStateListItem));
		AddTaskToReadyList(pxUnblockedTCB);
	}
	else
	{
		vListInsertEnd(&(xPendingReadyList), &(pxUnblockedTCB->xEventListItem));
	}

	if(pxUnblockedTCB->uxPriority > pxCurrentTCB->uxPriority)
	{
		xReturn = TRUE;

		xYieldPending = TRUE;
	}
	else
	{
		xReturn = FALSE;
	}

	prvResetNextTaskUnblockTime();

	return xReturn;
}

#define queueUNLOCKED					((int8_t) -1)
static UINT32 xQueueGenericReset(QueueHandle_t xQueue, UINT32 xNewQueue)
{
Queue_t * const pxQueue = (Queue_t *) xQueue;

	AlignCheck(pxQueue);

	ENTER_CRITICAL();
	{
		pxQueue->pcTail = pxQueue->pcHead + (pxQueue->uxLength * pxQueue->uxItemSize);
		pxQueue->uxMessagesWaiting = (UINT32) 0U;
		pxQueue->pcWriteTo = pxQueue->pcHead;
		pxQueue->u.pcReadFrom = pxQueue->pcHead + ((pxQueue->uxLength - (UINT32) 1U) * pxQueue->uxItemSize);
		pxQueue->cRxLock = queueUNLOCKED;
		pxQueue->cTxLock = queueUNLOCKED;

		if(xNewQueue == FALSE)
		{
			if(listLIST_IS_EMPTY(&(pxQueue->xTasksWaitingToSend)) == FALSE)
			{
				if(xTaskRemoveFromEventList(&(pxQueue->xTasksWaitingToSend)) != FALSE)
				{
					portYIELD();
				}
				else
				{	;
				}
			}
			else
			{	;
			}
		}
		else
		{
			vListInitialise(&(pxQueue->xTasksWaitingToSend));
			vListInitialise(&(pxQueue->xTasksWaitingToReceive));
		}
	}
	EXIT_CRITICAL();

	return RETURN_OK;
}

static void prvInitialiseNewQueue(const UINT32 uxQueueLength, const UINT32 uxItemSize, uint8_t *pucQueueStorage, const uint8_t ucQueueType, Queue_t *pxNewQueue)
{
	(void) ucQueueType;

	if(uxItemSize == (UINT32) 0)
	{
		pxNewQueue->pcHead = (int8_t *) pxNewQueue;
	}
	else
	{
		pxNewQueue->pcHead = (int8_t *) pucQueueStorage;
	}

	pxNewQueue->uxLength = uxQueueLength;
	pxNewQueue->uxItemSize = uxItemSize;
	(void) xQueueGenericReset(pxNewQueue, TRUE);

	#if (configUSE_TRACE_FACILITY == 1)
	{
		pxNewQueue->ucQueueType = ucQueueType;
	}
	#endif

	#if(configUSE_QUEUE_SETS == 1)
	{
		pxNewQueue->pxQueueSetContainer = NULL;
	}
	#endif
}

static QueueHandle_t xQueueGenericCreate(const UINT32 uxQueueLength, const UINT32 uxItemSize, const uint8_t ucQueueType)
{
	Queue_t		*pxNewQueue;
	SIZE_T		xQueueSizeInBytes;
	uint8_t 	*pucQueueStorage;

	AlignCheck(uxQueueLength > CLEAR);

	if(uxItemSize == (UINT32) 0)
	{
		xQueueSizeInBytes = (SIZE_T) 0;
	}
	else
	{
		xQueueSizeInBytes = (SIZE_T) (uxQueueLength * uxItemSize); /*lint !e961 MISRA exception as the casts are only redundant for some ports. */
	}

	pxNewQueue = (Queue_t *) AllocMalloc(sizeof(Queue_t) + xQueueSizeInBytes);

	if(pxNewQueue != NULL)
	{
		pucQueueStorage = ((uint8_t *) pxNewQueue) + sizeof(Queue_t);

		#if(configSUPPORT_STATIC_ALLOCATION == 1)
		{
			pxNewQueue->ucStaticallyAllocated = FALSE;
		}
		#endif

		prvInitialiseNewQueue(uxQueueLength, uxItemSize, pucQueueStorage, ucQueueType, pxNewQueue);
	}
	else
	{	;
	}

	return pxNewQueue;
}

#define TIMER_QUEUE_LENGTH			10
#define QUEUE_TYPE_BASE				0
static void prvCheckForValidListAndQueue(void)
{
	ENTER_CRITICAL();
	{
		if(xTimerQueue == NULL)
		{
			xTimerQueue = xQueueGenericCreate((UINT32)TIMER_QUEUE_LENGTH, sizeof(DaemonTaskMessage_t), QUEUE_TYPE_BASE);
		}
		else
		{	;
		}
	}
	EXIT_CRITICAL();
}


static UINT16 xPortStartScheduler(T_DispInfo* psDisplayInfo)
{
	#if(configASSERT_DEFINED == 1)
	{
		volatile uint32_t ulOriginalPriority;
		volatile uint8_t ucMaxPriorityValue;

		ulOriginalPriority = WROS_CORE_M->NVIC_register.IPR[0];

		WROS_CORE_M->NVIC_register.IPR[0] = 0xFF;
		ucMaxPriorityValue = WROS_CORE_M->NVIC_register.IPR[0];


		ucMaxSysCallPriority = configMAX_SYSCALL_INTERRUPT_PRIORITY & ucMaxPriorityValue;

		ulMaxPRIGROUPValue = portMAX_PRIGROUP_BITS;
		while((ucMaxPriorityValue & portTOP_BIT_OF_BYTE) == portTOP_BIT_OF_BYTE)
		{
			ulMaxPRIGROUPValue--;
			ucMaxPriorityValue <<= (uint8_t) 0x01;
		}

		#ifdef configPRIO_BITS
		{
			AlignCheck((portMAX_PRIGROUP_BITS - ulMaxPRIGROUPValue) == configPRIO_BITS);
		}
		#endif

		ulMaxPRIGROUPValue <<= portPRIGROUP_SHIFT;
		ulMaxPRIGROUPValue &= portPRIORITY_GROUP_MASK;

		*pucFirstUserPriorityRegister = ulOriginalPriority;
	}
	#endif

	
	uCriticalNesting = 0;
	return 0;
}

void DDI_WROS_Start(T_DispInfo* psDisplayInfo)
{
	prvCheckForValidListAndQueue();

	vPortRaiseBASEPRI();

	xNextTaskUnblockTime	= 0xFFFFFFFF;
	xSchedulerRunning		= SET;
	xTickCount				= CLEAR;
	
	xPortStartScheduler(psDisplayInfo);
	
#ifdef RTOS_WROS
	MAKE_TEST_POINT(SYSTICK_INT_FLAG);
	(*((volatile uint32_t *) 0xE000E010)) |= SET << 1;
	prvStartFirstTask();
	(void)WROS_DEV_TimerTask.driver_api(psDisplayInfo);
#endif
	MAKE_TEST_POINT(FUNC_RUN_FLAG);
	vPortSetBASEPRI();
	(void)WROS_DEV_TaskIDLE.driver_api(psDisplayInfo);
}

void vTaskSwitchContext(void)
{
	if(uxSchedulerSuspended != FALSE)
	{
		xYieldPending = TRUE;
	}
	else
	{
		xYieldPending = FALSE;
		taskSELECT_HIGHEST_PRIORITY_TASK();
	}
}

//  在icf中，声明堆栈8字节对齐
//#pragma required=8

void SysTick_Handler(void)				// SysTick Handler
{
	UINT8	xSwitchRequired = CLEAR;
	
	vPortRaiseBASEPRI();
	MAKE_TEST_POINT(SYSTICK_ENTER_FLAG);
	if(uxSchedulerSuspended == CLEAR)
	{
		const UINT32 xConstTickCount = xTickCount + 1;
		xTickCount = xConstTickCount;
		
		if(xConstTickCount == 0U)
		{
			//taskSWITCH_DELAYED_LISTS();
			List_t* pxTemp = pxDelayedTaskList;	
			pxDelayedTaskList = pxOverflowDelayedTaskList;
			pxOverflowDelayedTaskList = pxTemp;
			xNumOfOverflows++;

			if(listLIST_IS_EMPTY(pxDelayedTaskList) == SET)	// last Delayed Task have empty
			{
				xNextTaskUnblockTime = 0xFFFFFFFF;		// refresh Time
			}
			else
			{
				TCB_t* pxTCBTemp = (TCB_t*) listGET_OWNER_OF_HEAD_ENTRY(pxDelayedTaskList);
				xNextTaskUnblockTime = listGET_LIST_ITEM_VALUE(&((pxTCBTemp)->xStateListItem));
			}
		}
		else
		{	;
		}
		
		if(xConstTickCount >= xNextTaskUnblockTime)
		{
			for( ;; )
			{
				if(listLIST_IS_EMPTY(pxDelayedTaskList) != CLEAR)
				{
					xNextTaskUnblockTime = 0xFFFFFFFF;
					break;
				}
				else
				{
					TCB_t*	pxTCB = (TCB_t*)listGET_OWNER_OF_HEAD_ENTRY(pxDelayedTaskList);
					UINT32	xItemValue = listGET_LIST_ITEM_VALUE(&(pxTCB->xStateListItem));

					if(xConstTickCount < xItemValue)
					{
						xNextTaskUnblockTime = xItemValue;
						break;
					}
					else
					{	;
					}

					(void) uxListRemove(&(pxTCB->xStateListItem));

					if(listLIST_ITEM_CONTAINER(&(pxTCB->xEventListItem)) != NULL)
					{
						(void)uxListRemove(&(pxTCB->xEventListItem));
					}
					else
					{	;
					}

					AddTaskToReadyList(pxTCB);

					if( pxTCB->uxPriority >= pxCurrentTCB->uxPriority )
					{
						xSwitchRequired = SET;
					}
					else
					{	;
					}
				}
			}
		}

		if( listCURRENT_LIST_LENGTH(&(pxReadyTasksLists[pxCurrentTCB->uxPriority])) > 1)
		{
			xSwitchRequired = SET;
		}
		else
		{	;
		}
	}
	else
	{
		++uxPendedTicks;
	}

	xSwitchRequired = (xSwitchRequired == SET) || (xYieldPending == SET) ? SET : CLEAR;
	if(xSwitchRequired)
	{	portYIELD();
	}
	else
	{	;
	}
	
	vPortSetBASEPRI();
	
	MAKE_TEST_POINT(SYSTICK_FINISH_FLAG);
}

