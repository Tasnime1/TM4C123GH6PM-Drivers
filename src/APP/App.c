/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: APP.C
*       Module: APP
*		
*	 Description: Source file for all APP logic
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

static uint8_t Currently_On = 1;
static uint8_t Currently_Off = 0;
static uint8_t Timer_Counter = 0;
	
static uint8_t switch_pin0_pressed = 0;
static uint8_t switch_pin4_pressed = 0;

static uint8_t Button_Counter =0;


/*- FUNCTIONS' DECLARATION
***************************************************************************************/

int main()
{
	GPIO_Init(PortsConfigPtr);
	IntCtrl_Init(IntCtrlConfigPtr);
	//Gpt_Init(Gpt_TimersConfigPtr);
	SysTick_Init();
	
	SysTick_cb(SysTickDriver_Handler);
	GPIOF_cb(Button_Handler);
	
	
	/**while(1)
	{
		App_BlinkLED();
	}**/
	while(1)
	{
		
	}
	
}

void Button_Handler(void)
{	
  if (GPIOMIS(GPIO_PORT_F) & (1<<GPIO_PIN_0)) 
    {
      GPIOICR(GPIO_PORT_F) |= (1<<GPIO_PIN_0); /* clear the interrupt flag */
			if(switch_pin4_pressed)
			{
				switch_pin0_pressed = 0;
				switch_pin4_pressed = 0;
				offTime = Button_Counter;
				Button_Counter = 0;
			}
			else
			{
				Button_Counter ++;
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
				onTime = Button_Counter;
				Button_Counter = 0;
			}
			else
			{
				Button_Counter ++;
				switch_pin4_pressed = 1;
			}
  } 

}

void SysTickDriver_Handler(void)
{	
	if(Currently_On)
	{
		Timer_Counter ++;
		if(Timer_Counter >= onTime)
		{
			Currently_On = 0;
			Currently_Off = 1;
			Timer_Counter = 0;
			LED_Toggle(GPIO_PORT_F, GPIO_PIN_1);
		}
	}
	else if(Currently_Off)
	{
		Timer_Counter ++;
		if(Timer_Counter >= offTime)
		{
			Currently_On = 1;
			Currently_Off = 0;
			Timer_Counter = 0;
			LED_Toggle(GPIO_PORT_F, GPIO_PIN_1);
		}
	}
}

void App_BlinkLED()
{
	LED_On(GPIO_PORT_F, GPIO_PIN_1);
	Gpt_StartTimer(TIMER_CHANNEL_0 , onTime);
		
	LED_Off(GPIO_PORT_F, GPIO_PIN_1);
	Gpt_StartTimer(TIMER_CHANNEL_0, offTime);
}
