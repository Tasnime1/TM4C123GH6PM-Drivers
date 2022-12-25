
/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: SYSTICK.C
*       Module: SYSTICK
*		
*	 Description: Source file for all SYSTICK related registers and APIs
*
*
***************************************************************************************/


/*- INCLUDES
***************************************************************************************/
#include "SysTick.h"


/*- CALLBACK DECLARATION
***************************************************************************************/

SysTick_cb_type SysTick_Callback_ptr  = NULL;

void SysTick_cb(SysTick_cb_type ptr)
{
	if(ptr != NULL)
	{
		SysTick_Callback_ptr = ptr;
	}
}

void SysTick_Handler(void)
{
	if(SysTick_Callback_ptr != NULL)
	{
		SysTick_Callback_ptr();
	}
}

/*- APIs DECLARATIONS
***************************************************************************************/

void SysTick_Init()
{
	SET_BIT(STCTRL, SYSTICK_ENABLE_PIN);  //Enabling SysTick Timer
	SET_BIT(STCTRL, SYSTICK_INTEN_PIN);   //Enabling SysTick ISR
	SET_BIT(STCTRL, SYSTICK_CLK_SRC_PIN); //Enabling Internal Clock Source and not PIOSC Oscillator
	STRELOAD = 15999999;
	STCURRENT = 0X0;
}