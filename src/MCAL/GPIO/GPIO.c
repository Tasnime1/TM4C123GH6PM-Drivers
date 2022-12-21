/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: GPIO.H
*       Module: GPIO
*		
*	 Description: header file for all GPIO related registers and APIs
*
*
***************************************************************************************/

/*- INCLUDES
***************************************************************************************/

#include "GPIO.h"

/*- FUNCTIONS' DECLARATION
***************************************************************************************/

void Port_Init (const GPIO_ConfigType* ConfigPtr)
{
	//check if null ptr or not; if yes warning message and return for example
	if(ConfigPtr == NULL)
	{
		#warning "You passed an empty pointer for configuration"  
		return;
	}
	uint8_t PinCounter = 0;
	
	//All steps inside for loop
	for(PinCounter =0; PinCounter<PINS_NUM; PinCounter++)
	{
		
		EN_GPIO_ChannelNum_t PinNum = ConfigPtr[PinCounter].PinNum;
		EN_GPIO_PortNum_t PortNum = ConfigPtr[PinCounter].PortNum;
			
		//Step0: Initiate Clock-> RCGCGPIO -> 6 pins for GPIOs A->F
		SET_BIT(RCGCGPIO, PortNum);
		
		//change to timer delay!
		int i;
		for(i=0; i<100; i++);
		
		GPIOLOCK(GPIO_PORT_F) = UNLOCK_VALUE;
		GPIOCR(GPIO_PORT_F) = 0XFF;
		GPIOLOCK(GPIO_PORT_F) = 0;
		
		//Step1: Set pin mode, DEN, UART...etc
		//----------------------------------------------ONLY DEN IS SUPPORTED------------------------------------------------
		if(ConfigPtr[PinCounter].PinMode == GPIO_DEN)
		{
			//Disable alternate function
			CLR_BIT(GPIOAFSEL(PortNum), PinNum);

			//Enable DEN
			SET_BIT(GPIODEN(PortNum), PinNum);

			//Disable Analog function
			CLR_BIT(GPIOAMSEL(PortNum), PinNum);
		}
		else
		{
			#warning "Other pin modes aren't supported yet"
		}
		//Step2: Set pin direction-> GPIODIR
		if(ConfigPtr[PinCounter].PinDirection == GPIO_PIN_INPUT)
		{
			CLR_BIT(GPIODIR(PortNum), PinNum);
		}
		else if(ConfigPtr[PinCounter].PinDirection == GPIO_PIN_OUTPUT)
		{
			SET_BIT(GPIODIR(PortNum), PinNum);
			//Step3: Write pin Level
			
			if(ConfigPtr[PinCounter].PinLevelValue == GPIO_PIN_LOW)
			{
				CLR_BIT(GPIODATA(PortNum, PinNum), PinNum);
			}
			else if(ConfigPtr[PinCounter].PinLevelValue == GPIO_PIN_HIGH)
			{
				SET_BIT(GPIODATA(PortNum, PinNum), PinNum);
			}
			else
			{
				#warning "You've entered wrong pin level in configuration"
			}
			
			//Step4: Set output current
			if(ConfigPtr[PinCounter].PinOutputCurrent == GPIO_2mA)
			{
				SET_BIT(GPIODR2R(PortNum), PinNum);
			}
			else if(ConfigPtr[PinCounter].PinOutputCurrent == GPIO_4mA)
			{
				SET_BIT(GPIODR4R(PortNum), PinNum);
			}
			else if(ConfigPtr[PinCounter].PinOutputCurrent == GPIO_8mA)
			{
				SET_BIT(GPIODR8R(PortNum), PinNum);
			}
			else
			{
				#warning "You've entered wrong output current"
			}
		}
		else
		{
			#warning "You've entered wrong direction"
		}
		//Step4: Set internal pull; up, down or open-drain
		if(ConfigPtr[PinCounter].PinInternalAttach == GPIO_PULL_UP)
		{
			SET_BIT(GPIOPUR(PortNum), PinNum);
		}
		else if(ConfigPtr[PinCounter].PinInternalAttach == GPIO_PULL_DOWN)
		{
			SET_BIT(GPIOPDR(PortNum), PinNum);
		}
		else if(ConfigPtr[PinCounter].PinInternalAttach == GPIO_OPEN_DRAIN)
		{
			SET_BIT(GPIOODR(PortNum), PinNum);
		}
		else
		{
			#warning "You've entered wrong internal atttach"
		}
		
	}
}