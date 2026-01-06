/*******************************************************************************
*
*  CPU:TMPM470
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
*  Copyright(C) TOSHIBA CORPORATION 2010 All rights reserved
********************************************************************************/

/****************************************************************************
 * Controls the order of bitfield members
 * Use this pragma directive to control the layout of bitfield members.

	Bitfield members are placed from the most significant bit to
	the least significant bit in the container type. Storage
	containers of bitfields with different base types will not
	overlap. 
*****************************************************************************/
#pragma bitfields=default//reversed_disjoint_types	
											
											


#include "../../3.Library/Include/general.h"

#include "../../4.Driver/Include/WRRTOS.h"
#include "../../4.Driver/Include/WROS_Register.h"

#include "../../6.VariableSource/Include/Vable_ModelInformation.h"


