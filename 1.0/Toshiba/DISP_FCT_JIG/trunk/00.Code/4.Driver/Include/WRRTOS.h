

#ifndef _WROS_H
#define _WROS_H



	
#define INIT_PREV_KERNEL	0
#define INIT_POST_KERNEL	1
#define INIT_DRIV_INTERF	2
#define INIT_APPLICATION	3
#define INIT_END			4
#define INIT_MAX			5

#define MAX_PRIORITIES		7

#define SMALL_TASK_SIZE		64
#define NORMAL_TASK_SIZE	250
#define BIG_TASK_SIZE		400
#define MAX_TASK_SIZE		600


#define tskDYNAMICALLY_ALLOCATED_STACK_AND_TCB 		( ( UINT8 ) 0 )
#define tskSTATICALLY_ALLOCATED_STACK_ONLY 			( ( UINT8 ) 1 )
#define tskSTATICALLY_ALLOCATED_STACK_AND_TCB		( ( UINT8 ) 2 )

#define taskNOT_WAITING_NOTIFICATION				( ( UINT8 ) 0 )
#define taskWAITING_NOTIFICATION					( ( UINT8 ) 1 )
#define taskNOTIFICATION_RECEIVED					( ( UINT8 ) 2 )


/* FreeRTOS error definitions. */
#define errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY		( -1 )
#define errQUEUE_BLOCKED							( -4 )
#define errQUEUE_YIELD								( -5 )

enum{
	BOOT_START_FLAG,	// 0
	BOOT_FINISH_FLAG,	// 1
	TASK_CREATE_FLAG,	// 2
	SYSTICK_INT_FLAG,	// 3
	FUNC_RUN_FLAG,		// 4
	SVC_TRIGGER_FLAG,			// 5
	PendSV_TRIGGER_FLAG,		// 6
	SYSTICK_ENTER_FLAG,			// 7
	SYSTICK_FINISH_FLAG,		// 8
	KEY_FLAG,			// 9
	DISPLAY_FLAG,		// 10
	ERROR_CHECK_FLAG,	// 10
	SET_PLAT_FLAG,		// 11
	LQC_PROCESS_FLAG,	// 12
	TASK_EXIT_ERR_FLAG,	// 13
};

extern volatile UINT32 TEST_COUNT;
#define MAKE_TEST_POINT(x)		{TEST_COUNT = x;}


#define HEAP_SIZE				(SIZE_T)(3072)								// 12288 byte
#define BlockAllocatedBit		(SIZE_T)(0x8000)

#define BlockStructStandard		((sizeof(BlockLink_t) + (SIZE_T)0x0007) & ~((SIZE_T)0x0007 ))


#define AlignCheck(x)			if(x == CLEAR)						{ vPortRaiseBASEPRI(); for( ;; );}
#define AlignSet(RequestSize)	if((RequestSize & 0x0007) != CLEAR)	{ RequestSize += (8 - (RequestSize & 0x0007));}


#define STRINGIFY(s)							_STRINGIFY(s)
#define _DO_CONCAT(x, y)						x ## y
#define _CONCAT(x, y)							_DO_CONCAT(x, y)
#define DEVICE_NAME_GET(name)					(_CONCAT(WROS_DEV_, name))






#define LIST
struct xLIST_ITEM
{
	volatile UINT32 xItemValue;				// volatile may can unuse
	struct xLIST_ITEM * volatile pxNext;		
	struct xLIST_ITEM * volatile pxPrevious;	
	void * pvOwner;										
	void * volatile pvContainer;				
};
typedef struct xLIST_ITEM ListItem_t;					



struct xMINI_LIST_ITEM
{
	volatile UINT32 xItemValue;				// volatile may can unuse
	struct xLIST_ITEM * volatile pxNext;
	struct xLIST_ITEM * volatile pxPrevious;
};
typedef struct xMINI_LIST_ITEM MiniListItem_t;



typedef struct xLIST
{
	volatile UINT32 uxNumberOfItems;		// volatile may can unuse
	ListItem_t * volatile pxIndex;
	MiniListItem_t xListEnd;
} List_t;
#define LIST_END
/******************************************************************************/
/*********************************** LIST *************************************/



#define BLOCK
typedef struct tskTaskControlBlock
{
	volatile UINT32* pxTopOfStack;		// Points to the location of the last item placed on the tasks stack.  THIS MUST BE THE FIRST MEMBER OF THE TCB STRUCT.
	volatile UINT32* pxEndOfStack;		// Points to the highest valid address for the stack.
//	xMPU_SETTINGS	xMPUSettings;		// The MPU settings are defined as part of the port layer.  THIS MUST BE THE SECOND MEMBER OF THE TCB STRUCT.
	ListItem_t	xStateListItem;			// The list that the state list item of a task is reference from denotes the state of that task (Ready, Blocked, Suspended ).
	ListItem_t	xEventListItem;			// Used to reference a task from an event list.
	UINT32		uxPriority;				// The priority of the task.  0 is the lowest priority.
	UINT32*		pxStack;				// Points to the start of the stack.
	UINT32		uxBasePriority;			// The priority last assigned to the task - used by the priority inheritance mechanism.
	UINT8		pcTaskName[16];			// Descriptive name given to the task when created.  Facilitates debugging only. lint !e971 Unqualified char types are allowed for strings and single characters only.
	UINT32		uxCriticalNesting;		// Holds the critical section nesting depth for ports that do not maintain their own count in the port layer.
	UINT32		uxMutexesHeld;
	UINT32		ulRunTimeCounter;		// Stores the amount of time the task has spent in the Running state.
	volatile	UINT32 ulNotifiedValue;
	volatile	UINT8 ucNotifyState;
	UINT8		ucDelayAborted;
	UINT32		uxTCBNumber;			// Stores a number that increments each time a TCB is created.  It allows debuggers to determine when a task has been deleted and then recreated.
	UINT32		uxTaskNumber;			// Stores a number specifically for use by third party trace code. */
} tskTCB;

typedef tskTCB TCB_t;

typedef struct BLOCK_LINK
{
	struct BLOCK_LINK* pNextFreeBlock;		/*<< The next free block in the list. */
	UINT32 BlockSize;						/*<< The size of the free block. */
} BlockLink_t;
#define BLOCK_END
/******************************************************************************/
/*********************************** TASKBLOCK ********************************/


#define TimerControl
typedef void * QueueHandle_t;

typedef struct QueueDefinition
{
	int8_t *pcHead;					/*< Points to the beginning of the queue storage area. */
	int8_t *pcTail;					/*< Points to the byte at the end of the queue storage area.  Once more byte is allocated than necessary to store the queue items, this is used as a marker. */
	int8_t *pcWriteTo;				/*< Points to the free next place in the storage area. */

	union							/* Use of a union is an exception to the coding standard to ensure two mutually exclusive structure members don't appear simultaneously (wasting RAM). */
	{
		int8_t *pcReadFrom;			/*< Points to the last place that a queued item was read from when the structure is used as a queue. */
		UINT32 uxRecursiveCallCount;/*< Maintains a count of the number of times a recursive mutex has been recursively 'taken' when the structure is used as a mutex. */
	} u;

	List_t xTasksWaitingToSend;		/*< List of tasks that are blocked waiting to post onto this queue.  Stored in priority order. */
	List_t xTasksWaitingToReceive;	/*< List of tasks that are blocked waiting to read from this queue.  Stored in priority order. */

	volatile UINT32 uxMessagesWaiting;/*< The number of items currently in the queue. */
	UINT32 uxLength;			/*< The length of the queue defined as the number of items it will hold, not the number of bytes. */
	UINT32 uxItemSize;			/*< The size of each items that the queue will hold. */

	volatile int8_t cRxLock;		/*< Stores the number of items received from the queue (removed from the queue) while the queue was locked.  Set to queueUNLOCKED when the queue is not locked. */
	volatile int8_t cTxLock;		/*< Stores the number of items transmitted to the queue (added to the queue) while the queue was locked.  Set to queueUNLOCKED when the queue is not locked. */

	#if( ( configSUPPORT_STATIC_ALLOCATION == 1 ) && ( configSUPPORT_DYNAMIC_ALLOCATION == 1 ) )
		uint8_t ucStaticallyAllocated;	/*< Set to pdTRUE if the memory used by the queue was statically allocated to ensure no attempt is made to free the memory. */
	#endif

	#if ( configUSE_QUEUE_SETS == 1 )
		struct QueueDefinition *pxQueueSetContainer;
	#endif

	#if ( configUSE_TRACE_FACILITY == 1 )
		UINT32 uxQueueNumber;
		uint8_t ucQueueType;
	#endif

} xQUEUE;
typedef xQUEUE Queue_t;


typedef void * TimerHandle_t;
typedef void (*TimerCallbackFunction_t)( TimerHandle_t xTimer );

typedef struct tmrTimerControl
{
	const char				*pcTimerName;		
	ListItem_t				xTimerListItem;		
	UINT32					xTimerPeriodInTicks;
	UINT32					uxAutoReload;		
	void 					*pvTimerID;			
	TimerCallbackFunction_t	pxCallbackFunction;	
	UINT32					uxTimerNumber;
	uint8_t 				ucStaticallyAllocated;
} xTIMER;

typedef xTIMER Timer_t;


typedef struct tmrTimerParameters
{
	UINT32			xMessageValue;
	Timer_t *			pxTimer;
} TimerParameter_t;

typedef void (*PendedFunction_t)( void *, UINT32 );
typedef struct tmrCallbackParameters
{
	PendedFunction_t	pxCallbackFunction;	
	void *pvParameter1;						
	UINT32 ulParameter2;					
} CallbackParameters_t;

typedef struct TimerQueueMessage
{
	UINT32		MessageID;
	union
	{
		TimerParameter_t xTimerParameters;
		CallbackParameters_t xCallbackParameters;
	} u;
} DaemonTaskMessage_t;
#define TimerControl_END
/******************************************************************************/
/********************************* TimerControl *******************************/







struct device
{
	const		char* name;
	void 		(*driver_api)(T_DispInfo*);
	UINT32		driver_level;
	UINT32		driver_StackDepth;
	UINT32		driver_ErrorIndex;
	TCB_t*		driver_TaskHandle;
};


#define DEVICE_DEFINE(dev_name, api, level, StackDepth, ErrorIndex, TaskHandle) \
__root struct device DEVICE_NAME_GET(dev_name) @ "WROS_section" = { \
    .name = STRINGIFY(dev_name), \
    .driver_api = api, \
    .driver_level = level, \
    .driver_StackDepth = StackDepth, \
    .driver_ErrorIndex = ErrorIndex, \
    .driver_TaskHandle = TaskHandle, \
};

static BlockLink_t T_Block_Start, *P_Block_End = NULL;

enum { No_Error, A1_Error, A2_Error };

/*
#define FORCE_LINK_BEGIN(dev_name, level) 
#define FORCE_LINK_END(dev_name, level) \
	_Pragma(STRINGIFY(_CONCAT(location=, STRINGIFY(_CONCAT(_CONCAT(__devices_, level), m))))) \
	__root struct device *_CONCAT(__devices_pointer, dev_name) = &_CONCAT(__devices, dev_name);

#define DEVICE_DEFINE(dev_name, level, api, conf, data, init, deinit) \
FORCE_LINK_BEGIN(dev_name, level) \
struct device DEVICE_NAME_GET(dev_name) = \
{ \
	.name = STRINGIFY(dev_name), \
	.driver_api = api, \
	.driver_conf = conf, \
	.driver_data = data, \
	.driver_init = init, \
	.driver_deinit = deinit, \
}; \
FORCE_LINK_END(dev_name, level)
*/





void DDI_WROS_Init(T_DispInfo*);
void DDI_WROS_Start(T_DispInfo*);
void WROS_FUNC_Task_IDLE(T_DispInfo*);
void WROS_FUNC_Timer_Task(T_DispInfo*);
void vTaskSwitchContext(void);


#endif

