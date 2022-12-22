#ifndef BUTTON_H
#define BUTTON_H

/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: BUTTON.H
*       Module: BUTTON
*		
*	 Description: header file for all BUTTON related functionalities
*
*
***************************************************************************************/


/*- INCLUDES
***************************************************************************************/
#include "GPIO.h"

/*- CALLBACK FUNCTION AND TYPEDEF
***************************************************************************************/

typedef void(*cb_type)(void);
void Buttons_cb(cb_type ptr);

/*- APIs
***************************************************************************************/
EN_GPIO_ChannelLevelType_t BUTTON_Read (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t BUTTONId);

#endif /* BUTTON.H */