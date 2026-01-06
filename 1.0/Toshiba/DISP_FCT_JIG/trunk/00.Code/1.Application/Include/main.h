

#ifndef _MAIN_H
#define _MAIN_H


#include "../../1.Application/Include/APP_WorkingNormalState.h"
#include "../../2.Component/Include/Cmp_KeyScan.h"
#include "../../2.Component/Include/Cmp_Display_Service.h"
#include "../../2.Component/Include/Cmp_LQC_Process.h"
#include "../../2.Component/Include/Cmp_SetError.h"

#define FUNC__DO_CONCAT(x, y)		x ## y
#define FUNC_CONCAT(x, y)			FUNC__DO_CONCAT(x, y)
#define FUNC_NAME_GET(name)			(FUNC_CONCAT(WROS_FUNC_, name))


DEVICE_DEFINE(TimerTask,	FUNC_NAME_GET(Timer_Task),		INIT_APPLICATION,	SMALL_TASK_SIZE,	No_Error, NULL)
DEVICE_DEFINE(ERRORCHECK,	FUNC_NAME_GET(Error_Check),		INIT_APPLICATION,	SMALL_TASK_SIZE,	No_Error, NULL)
DEVICE_DEFINE(JIGKEYSCAN,	FUNC_NAME_GET(JIG_KeyScan),		INIT_APPLICATION,	SMALL_TASK_SIZE,	No_Error, NULL)
DEVICE_DEFINE(DISPLAY,		FUNC_NAME_GET(JIG_Display),		INIT_APPLICATION,	NORMAL_TASK_SIZE,	No_Error, NULL)
DEVICE_DEFINE(PLATFORMCOMM, 	FUNC_NAME_GET(Set_Platform),		INIT_APPLICATION,	MAX_TASK_SIZE,		No_Error, NULL)
DEVICE_DEFINE(LQCPROCESS,	FUNC_NAME_GET(LQC_ModeProcess),		INIT_APPLICATION,	BIG_TASK_SIZE,		No_Error, NULL)
DEVICE_DEFINE(TaskIDLE, 	FUNC_NAME_GET(Run),			INIT_PREV_KERNEL,	SMALL_TASK_SIZE,	No_Error, NULL)


#endif


