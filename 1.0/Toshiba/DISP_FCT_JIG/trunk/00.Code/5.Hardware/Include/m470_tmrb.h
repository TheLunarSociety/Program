/*******************************************************************************
*
* @file:    m470_tmrb.h
* @purpose: 16-bit Timer/Event Counters Header File
*           for the TOSHIBA 'TMPM470' Device Series 
* @version: V1.0.0.0
* @date:    2017/03/07
*
*-------------------------------------------------------------------------------
* --Notice--
*  The information contained herein has been carefully checked
* and is believed to be reliable. However, no responsibility can be
* assumed for inaccuracies that may not have been detected. The
* information contained herein is subject to change without notice.
*  The information contained herein is presented only as a guide
* for the application of our products. No responsibility is assumed
* by TOSHIBA for any infringements of patents or other rights of
* the third parties which may result from its use. No license is
* granted by implication or otherwise under any patent or patent
* rights of TOSHIBA or others.
*-------------------------------------------------------------------------------
*  Copyright(C) TOSHIBA CORPORATION 2017 All rights reserved
********************************************************************************/


#ifndef __M470_TMRB_H
#define __M470_TMRB_H

#ifdef DEFINE_APP_TMRB
#define EXTERN_TMRB
#else
#define EXTERN_TMRB  extern
#endif

/******************************************/
/***	- PROTO TYPE DEFINITION -		***/
/******************************************/
EXTERN_TMRB 	void		WROS_TMRB_Init(void);

/**************************************************************/
#undef EXTERN_TMRB
#endif /* __M470_TMRB_H */

/*************************** END OF FILE **************************************/
