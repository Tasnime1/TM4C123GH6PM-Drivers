/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: LED.H
*       Module: LED
*		
*	 Description: Header file for all LED related functionalities
*
*
***************************************************************************************/


#ifndef LED_H
#define LED_H



/*- INCLUDES
***************************************************************************************/
#include "stdio.h"
#include "GPIO.h"


/*- APIs
***************************************************************************************/
EN_GPIO_ChannelLevelType_t LED_ReadLED (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t LEDId);
void LED_On (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t LEDId);
void LED_Off (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t LEDId);
EN_GPIO_ChannelLevelType_t LED_Toggle (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t LEDId);


#endif /* LED.H */
