/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: INT_CTRL_CFG.C
*       Module: INT_CTRL_CFG
*		
*	 Description: Source file for all INT_CTRL Configurations
*
*
***************************************************************************************/


/*- INCLUDES
***************************************************************************************/
#include "IntCtrl_cfg.h"



/*- CONSTANT COFIGURATION ARRAY
***************************************************************************************/
const ST_IntCtrl_ConfigType_t IntCtrlConfigPtr[INTS_NUM] =
{
	{ INTCTRL_PORTF_INT_NUM, 3, USE_0_GROUPS_8_SUBGROUPS, INTCTRL_EDGE_TRIGGERED, INTCTRL_RISING, GPIO_PORT_F, GPIO_PIN_0},
	{ INTCTRL_PORTF_INT_NUM, 3, USE_0_GROUPS_8_SUBGROUPS, INTCTRL_EDGE_TRIGGERED, INTCTRL_RISING, GPIO_PORT_F, GPIO_PIN_4}
};