#include "LED.h"

/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: LED.C
*       Module: LED
*		
*	 Description: Source file for all LED related functionalities
*
*
***************************************************************************************/

/*- APIs DECLARATIONS
***************************************************************************************/

EN_GPIO_ChannelLevelType_t LED_ReadLED (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t LEDId)
{
	return GPIO_ReadChannel(PortId, LEDId);
}

void LED_On (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t LEDId)
{
	GPIO_WriteChannel(PortId, LEDId, GPIO_PIN_HIGH);
}

void LED_Off (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t LEDId)
{
	
	GPIO_WriteChannel(PortId, LEDId, GPIO_PIN_LOW);
}

EN_GPIO_ChannelLevelType_t LED_FlipLED (EN_GPIO_PortNum_t PortId, EN_GPIO_ChannelNum_t LEDId)
{
	return GPIO_FlipChannel(PortId, LEDId);
}
