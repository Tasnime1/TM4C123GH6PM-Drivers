#include "BIT_MATH.h"
#include "GPIO.h"
#include "GPIO_cfg.h"
#include "GPT.h"
#include "GPT_cfg.h"
#include "IntCtrl.h"
#include "IntCtrl_Config.h"

void TEST_GPIO();
void TEST_Timer(uint32_t timee);
void Timer_init();
void Blink_test();
void TEST_interrupt();

extern const ST_IntCtrl_ConfigType_t IntCtrlConfigPtr[INTS_NUM];
extern const GPIO_ConfigType PortsConfig [PINS_NUM];
extern const GPT_ConfigType Gpt_TimersConfig[TIMERS_NUM];


static uint8_t onTime=3;
static uint8_t offTime=3;

static uint8_t switch_pin0_pressed = 0;
static uint8_t switch_pin4_pressed = 0;

static uint8_t counter =0;

int main()
{
	GPIO_Init(PortsConfig);
	IntCtrl_Init(IntCtrlConfigPtr);
	
	while(1)
	{
		SET_BIT(GPIODATA(GPIO_PORT_F, GPIO_PIN_1), GPIO_PIN_1);
		TEST_Timer(onTime);
		CLR_BIT(GPIODATA(GPIO_PORT_F, GPIO_PIN_1), GPIO_PIN_1);
		TEST_Timer(offTime);
	}
}

void GPIOF_Handler(void)
{	
  if (GPIOMIS(GPIO_PORT_F) & (1<<GPIO_PIN_0)) /* check if interrupt causes by PF4/SW1*/
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

void TEST_GPIO()
{
	SET_BIT(RCGCGPIO, GPIO_PORT_F);
	SET_BIT(GPIODIR(GPIO_PORT_F), GPIO_PIN_1);
	SET_BIT(GPIODEN(GPIO_PORT_F), GPIO_PIN_1);
	while(1)
	{
		TOGGLE_BIT(GPIODATA(GPIO_PORT_F, GPIO_PIN_1), GPIO_PIN_1);
		int i=0;
		for(i=0; i<100; i++);
	}
}

//Timers work up to channel 3; channels 4 and 5 don't blink the LED!!
//1 second delay test
void TEST_Timer(uint32_t timee)
{
	//Timer Initialization
	SET_BIT(RCGCTIMER, TIMER_CHANNEL_0);
	
	CLR_BIT(GPTMCTL(TIMER_CHANNEL_0), TAEN);
	
	GPTMTAMR(TIMER_CHANNEL_0) = (PERIODIC_TIMER_MODE<<TAMR_START_BIT);
	GPTMCFG(TIMER_CHANNEL_0) |= (GPT_NORMAL_32_VALUE<<GPTMCFG_START_BIT);
	GPTMTAPR(TIMER_CHANNEL_0) = 250-1;
	GPTMTAILR(TIMER_CHANNEL_0) = 64000-1;
	SET_BIT(GPTMICR(TIMER_CHANNEL_0), TATOCINT);
	SET_BIT(GPTMIMR(TIMER_CHANNEL_0) ,TATOIM);	
	SET_BIT(GPTMCTL(TIMER_CHANNEL_0), TAEN);
	
		int i=0;
		for( i=0; i<timee; i++)
		{
		while((GPTMMIS(TIMER_CHANNEL_0) & (1<<TATOMIS))==0);
		SET_BIT(GPTMICR(TIMER_CHANNEL_0), TATOCINT);
		}
}

void Timer_init()
{
	//Timer Initialization
	SET_BIT(RCGCTIMER, TIMER_CHANNEL_0);
	
	CLR_BIT(GPTMCTL(TIMER_CHANNEL_0), TAEN);
	
	GPTMCFG(TIMER_CHANNEL_0) |= (GPT_NORMAL_16_VALUE<<GPTMCFG_START_BIT);
	GPTMTAMR(TIMER_CHANNEL_0) = PERIODIC_TIMER_MODE;
	GPTMTAPR(TIMER_CHANNEL_0) = 250-1;
	GPTMTAILR(TIMER_CHANNEL_0) = 64000-1;
	SET_BIT(GPTMICR(TIMER_CHANNEL_0), TATOCINT);
	SET_BIT(GPTMIMR(TIMER_CHANNEL_0) ,TATOIM);	
	
	SET_BIT(GPTMCTL(TIMER_CHANNEL_0), TAEN);

}

void Blink_test()
{
	//TEST_GPIO();
	Timer_init();
	while(1)
	{
		SET_BIT(GPIODATA(GPIO_PORT_F, GPIO_PIN_1), GPIO_PIN_1);
		TEST_Timer(3);
		CLR_BIT(GPIODATA(GPIO_PORT_F, GPIO_PIN_1), GPIO_PIN_1);
		TEST_Timer(5);
	}
}

void TEST_interrupt()
{
	SET_BIT(RCGCGPIO, GPIO_PORT_F);
	
	GPIOLOCK(GPIO_PORT_F) = UNLOCK_VALUE;
	GPIOCR(GPIO_PORT_F) = 0XFF;
	GPIOLOCK(GPIO_PORT_F) = 0;
	
	CLR_BIT(GPIODIR(GPIO_PORT_F), GPIO_PIN_0); //switch 0 as input
	SET_BIT(GPIOPUR(GPIO_PORT_F), GPIO_PIN_0);
	CLR_BIT(GPIODIR(GPIO_PORT_F), GPIO_PIN_4); //switch 4 as input
	SET_BIT(GPIOPUR(GPIO_PORT_F), GPIO_PIN_4);
	
	SET_BIT(GPIODIR(GPIO_PORT_F), GPIO_PIN_1); //led 1 as output
	SET_BIT(GPIODEN(GPIO_PORT_F), GPIO_PIN_1);
	SET_BIT(GPIODIR(GPIO_PORT_F), GPIO_PIN_2); //led 2 as output
	SET_BIT(GPIODEN(GPIO_PORT_F), GPIO_PIN_2);
	
	//congig interrupt
	IntCtrl_Init(IntCtrlConfigPtr);

}