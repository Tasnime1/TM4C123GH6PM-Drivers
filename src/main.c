#include "BIT_MATH.h"
#include "GPIO.h"
#include "GPIO_cfg.h"

void TEST_GPIO();
extern const GPIO_ConfigType PortsConfig [PINS_NUM];
int main()
{
	Port_Init(PortsConfig);
	//TEST_GPIO();
	while(1)
	{
		
		 
	}
}

void TEST_GPIO()
{
	RCGCGPIO |= (1<<2);
	int i=0;
	for(i=0; i<100; i++);
	
	GPIOLOCK(2) = UNLOCK_VALUE;
	GPIOCR(2) |= (15<<0);
	
	GPIODEN(2) |= (1<<1);

	GPIODEN(2) |= (1<<2);
	GPIODEN(2) |= (1<<3);	
	
	GPIOAFSEL(2) = 0x0;
	GPIOAMSEL(2) = 0X0;
	
	
	GPIODIR(2) |= (1<<1);
	GPIODIR(2) |= (1<<2);
	GPIODIR(2) |= (1<<3);
	
	SET_BIT(GPIODATA(2, 1), 1);
	SET_BIT(GPIODATA(2, 2), 2);
	SET_BIT(GPIODATA(2, 3), 3);
		
	for(i=0; i<100; i++);
		
		
	CLR_BIT(GPIODATA(2, 1), 1);
	CLR_BIT(GPIODATA(2, 2), 2);
	CLR_BIT(GPIODATA(2, 3), 3);
}