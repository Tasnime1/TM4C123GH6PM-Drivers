#ifndef LED_H
#define LED_H

/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: LED.H
*       Module: LED
*		
*	 Description: header file for all LED related functionalities
*
*
***************************************************************************************/


/*- INCLUDES
***************************************************************************************/
#include "stdio.h"
#include "GPIO.h"


/*- APIs
***************************************************************************************/
EN_GPIO_ChannelLevelType_t LED_ReadLED (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t LEDId);
void LED_On (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t LEDId);
void LED_Off (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t LEDId);
EN_GPIO_ChannelLevelType_t LED_FlipLED (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t LEDId);


#endif /* LED.H */