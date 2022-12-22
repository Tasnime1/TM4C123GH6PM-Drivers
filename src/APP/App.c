/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: APP.C
*       Module: APP
*		
*	 Description: Source file for all APP related functionalities
*
*
***************************************************************************************/

/*- INCLUDES
***************************************************************************************/

#include "APP.h"

/*- GLOBAL AND EXTERN VARIABLES
***************************************************************************************/

extern const ST_IntCtrl_ConfigType_t IntCtrlConfigPtr[INTS_NUM];
extern const GPIO_ConfigType PortsConfigPtr [PINS_NUM];
extern const GPT_ConfigType Gpt_TimersConfigPtr[TIMERS_NUM];


extern uint8_t onTime;
extern uint8_t offTime;

static uint8_t switch_pin0_pressed = 0;
static uint8_t switch_pin4_pressed = 0;

static uint8_t counter =0;


/*- FUNCTIONS' DECLARATION
***************************************************************************************/

int main()
{
	GPIO_Init(PortsConfigPtr);
	IntCtrl_Init(IntCtrlConfigPtr);
	Gpt_Init(Gpt_TimersConfigPtr);
	Buttons_cb(OnoFFTime_Handler);
	while(1)
	{
		App_BlinkLED();
	}
}

void OnoFFTime_Handler(void)
{	
  if (GPIOMIS(GPIO_PORT_F) & (1<<GPIO_PIN_0)) 
    {
      GPIOICR(GPIO_PORT_F) |= (1<<GPIO_PIN_0); /* clear the interrupt flag */
			if(switch_pin4_pressed)
			{
				switch_pin0_pressed = 0;
				switch_pin4_pressed = 0;
				offTime = counter;
				counter = 0;
			}
			else
			{
				counter ++;
				switch_pin0_pressed = 1;
			}
     } 
		
	if (GPIOMIS(GPIO_PORT_F) & (1<<GPIO_PIN_4)) /* check if interrupt causes by PF4/SW1*/
  { 
		GPIOICR(GPIO_PORT_F) |= (1<<GPIO_PIN_4); /* clear the interrupt flag */
		if(switch_pin0_pressed)
			{
				switch_pin0_pressed = 0;
				switch_pin4_pressed = 0;
				onTime = counter;
				counter = 0;
			}
			else
			{
				counter ++;
				switch_pin4_pressed = 1;
			}
  } 

}

void App_BlinkLED()
{
	LED_On(GPIO_PORT_F, GPIO_PIN_1);
	Gpt_StartTimer(TIMER_CHANNEL_0 , onTime);
		
	LED_Off(GPIO_PORT_F, GPIO_PIN_1);
	Gpt_StartTimer(TIMER_CHANNEL_1, offTime);
}
