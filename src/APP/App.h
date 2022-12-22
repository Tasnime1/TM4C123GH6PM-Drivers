#ifndef APP_H
#define APP_H

/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: APP.H
*       Module: APP
*		
*	 Description: header file for all APP-related functionalities
*
*
***************************************************************************************/


/*- INCLUDES
***************************************************************************************/
#include "BIT_MATH.h"
#include "GPIO.h"
#include "GPIO_cfg.h"
#include "GPT.h"
#include "GPT_cfg.h"
#include "IntCtrl.h"
#include "IntCtrl_Config.h"
#include "LED.h"
#include "Button.h"


/*- FUNCTIONS' PROTOTYPES
***************************************************************************************/
void App_BlinkLED();
void OnoFFTime_Handler();

#endif /* APP.H */