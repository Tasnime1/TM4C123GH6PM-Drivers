#include "blink.h"
#include "GPIO_Lcfg.h"


extern const GPIO_ConfigType PortsConfig [];

int main()
{
	Port_Init(PortsConfig);
	while (1)
	{
		
	}
}