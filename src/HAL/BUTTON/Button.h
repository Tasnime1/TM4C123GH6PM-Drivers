/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: BUTTON.H
*       Module: BUTTON
*		
*	 Description: Header file for all BUTTON related functionalities
*
***************************************************************************************/

#ifndef BUTTON_H
#define BUTTON_H



/*- INCLUDES
***************************************************************************************/
#include "GPIO.h"


/*- APIs
***************************************************************************************/
EN_GPIO_ChannelLevelType_t BUTTON_Read (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t BUTTONId);

#endif /* BUTTON.H */