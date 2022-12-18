#include "BIT_MATH.h"
#include "GPIO.h"
#include "GPIO_cfg.h"

void TEST_GPIO();
extern const GPIO_ConfigType PortsConfig [PINS_NUM];
int main()
{
	TEST_GPIO();
	while(1)
	{
		
		 
	}
}

void TEST_GPIO()
{
	RCGCGPIO |= (1<<5);
	int i=0;
	for(i=0; i<100; i++);
	
	GPIODEN(5) |= (1<<1);

	GPIODEN(5) |= (1<<2);
	GPIODEN(5) |= (1<<3);	
	
	GPIOAFSEL(5) = 0x0;
	GPIOAMSEL(5) = 0X0;
	
	
	GPIODIR(5) |= (1<<1);
	GPIODIR(5) |= (1<<2);
	GPIODIR(5) |= (1<<3);
	
	SET_BIT(GPIODATA(5, 1), 1);
	SET_BIT(GPIODATA(5, 2), 2);
	SET_BIT(GPIODATA(5, 3), 3);
		
	for(i=0; i<100; i++);
		
		
	CLR_BIT(GPIODATA(5, 1), 1);
	CLR_BIT(GPIODATA(5, 2), 2);
	CLR_BIT(GPIODATA(5, 3), 3);
}