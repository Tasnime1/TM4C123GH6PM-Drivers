#ifndef APP_H
#define APP_H

/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: APP.H
*       Module: APP
*		
*	 Description: Header file for all APP-related functions' prototypes and inclusions
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
#include "IntCtrl_cfg.h"
#include "LED.h"
#include "Button.h"
#include "SysTick.h"


/*- FUNCTIONS' PROTOTYPES
***************************************************************************************/
void App_BlinkLED();
void Button_Handler();
void SysTickDriver_Handler(void);

#endif /* APP.H */