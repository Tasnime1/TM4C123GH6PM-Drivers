/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: BUTTON.C
*       Module: BUTTON
*		
*	 Description: Source file for all Button related functionalities
*
*
***************************************************************************************/

/*- INCLUDES
***************************************************************************************/

#include "Button.h"


/*- APIs DECLARATIONS
***************************************************************************************/

EN_GPIO_ChannelLevelType_t BUTTON_Read (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t BUTTONId)
{
	return GPIO_ReadChannel(PortId, BUTTONId);
}
