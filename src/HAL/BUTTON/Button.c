#include "BUTTON.h"

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


/*- CALLBACK FUNCTION-related
***************************************************************************************/

cb_type Callback_ptr  = NULL;

void Buttons_cb(cb_type ptr)
{
	if(ptr != NULL)
	{
		Callback_ptr = ptr;
	}
}

void GPIOF_Handler(void)
{
	if(Callback_ptr != NULL)
	{
		Callback_ptr();
	}
}


/*- APIs DECLARATIONS
***************************************************************************************/

EN_GPIO_ChannelLevelType_t BUTTON_Read (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t BUTTONId)
{
	return GPIO_ReadChannel(PortId, BUTTONId);
}
