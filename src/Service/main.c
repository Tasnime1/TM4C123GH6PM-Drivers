#include "blink.h"
#include "GPIO_Lcfg.h"
#include "BIT_MATH.h"
#include "GPIO.h"

extern const GPIO_ConfigType PortsConfig [];

int main()
{
	// add 3FC to address for data register to work
	Port_Init(PortsConfig);
	//RCGCGPIO = 0x0020;
	//SET_BIT_PER_BB(GPIODEN(GPIO_PORT_F), GPIO_PIN_1);
	//SET_BIT_PER_BB(GPIODIR(GPIO_PORT_F), GPIO_PIN_1);
	//CLR_BIT_PER_BB(GPIOAMSEL(GPIO_PORT_F), GPIO_PIN_1);
	//CLR_BIT_PER_BB(GPIOAFSEL(GPIO_PORT_F), GPIO_PIN_1);
	/**while (1)
	{
		int i=0;
		SET_BIT_PER_BB(GPIODATA(GPIO_PORT_F), GPIO_PIN_1);
		for(i=0; i<1000000; i++);
		CLR_BIT_PER_BB(GPIODATA(GPIO_PORT_F), GPIO_PIN_1);
		for(i=0; i<1000000; i++);
		}**/
}