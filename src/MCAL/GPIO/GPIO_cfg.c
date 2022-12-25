/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: GPIO_CFG.C
*       Module: GPIO_CFG
*		
*	 Description: Source file for all GPIO configurations
*
*
***************************************************************************************/


/*- INCLUDES
***************************************************************************************/

#include "GPIO_cfg.h"



/*- CONSTANT COFIGURATION ARRAY
***************************************************************************************/

const GPIO_ConfigType PortsConfigPtr [PINS_NUM] =
{
	{GPIO_DEN, GPIO_PIN_HIGH, GPIO_PIN_OUTPUT, GPIO_PULL_DOWN, GPIO_8mA, GPIO_PORT_F, GPIO_PIN_1},
	{GPIO_TIMER, GPIO_PIN_HIGH, GPIO_PIN_INPUT, GPIO_PULL_UP, GPIO_8mA, GPIO_PORT_F, GPIO_PIN_0},
	{GPIO_TIMER, GPIO_PIN_HIGH, GPIO_PIN_INPUT, GPIO_PULL_UP, GPIO_8mA, GPIO_PORT_F, GPIO_PIN_4}
};
