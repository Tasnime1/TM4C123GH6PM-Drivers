#include "Port.h"

void Port_Init (const Port_ConfigType* ConfigPtr)
{
	//check if null ptr or not; if yes warning message and return for example
	if(ConfigPtr == NULL)
	{
		#warning "You passed an empty pointer for configuration"  
		return;
	}
	uint8_t PinCounter = 0;
	Port_PinNum_t PortPinNum = ConfigPtr->PortPinNum;
	Port_Num_t PortNum = ConfigPtr->PortNum;
	
	//All steps inside for loop
	for(PinCounter =0; PinCounter<PORT_PINS_NUM; PinCounter++)
	{
		
	
	//Step0: Initiate Clock-> RCGCGPIO -> 6 pins for Ports A->F
	SET_BIT(RCGCGPIO, PortNum);
	
	
	//Step1: Set Direction of pin-> GPIODIR
	if(ConfigPtr[PinCounter].PortPinDirection == PORT_PIN_INPUT)
	{
		CLR_BIT(GPIODIR(PortNum), PortPinNum);
	}
	else if(ConfigPtr[PinCounter].PortPinDirection == PORT_PIN_OUTPUT)
	{
		SET_BIT(GPIODIR(PortNum), PortPinNum);
		if(ConfigPtr[PinCounter].PortPinLevelValue == DIO_PIN_LOW)
		{
			CLR_BIT(GPIODATA(PortNum), PortPinNum);
		}
		else if(ConfigPtr[PinCounter].PortPinLevelValue == DIO_PIN_HIGH)
		{
			SET_BIT(GPIODATA(PortNum), PortPinNum);
		}
		else
		{
			#warning "you've entered wrong pin level in configuration"
		}
	}	
	//TO-DO: macro for set/clr bit for non reentrant functions/initializations
	
	//Step2: Start accesing ptr fields and registers to apply configurations
	}
}