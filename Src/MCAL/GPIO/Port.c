#include "Port.h"

void Port_Init (const Port_ConfigType* ConfigPtr)
{
	//check if null ptr or not; if yes warning message and return for example
	if(ConfigPtr == NULL)
	{
		#warning "You passed an empty pointer for configuration"  
		return;
	}
	
	//Step0: Initiate Clock-> RCGCGPIO -> 6 pins for Ports A->F
	
	
	//Step1: Set Direction of pin-> GPIODIR
	
	
	//TO-DO: macro for set/clr bit for non reentrant functions/initializations
	
	//Step2: Start accesing ptr fields and registers to apply configurations
}