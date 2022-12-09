#include "blink.h"
#include "Port_Lcfg.h"


extern const Port_ConfigType PortsConfig [];

int main()
{
	Port_Init(PortsConfig);
	while (1)
	{
		
	}
}