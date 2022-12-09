#ifndef PORT_H
#define PORT_H


/**************************/
/*********INCLUDES*********/
/**************************/
#include "types.h"
#include "DIO.h"
#include <stdio.h>

/******************************/
/********GPIO REGISTERS********/
/******************************/
#define SystemControl              	0x400FE000

#define GPIO_APB
//#define GPIO_AHB

#if defined(GPIO_APB)
#define GPIOx(x)               	(x<4?((0x40004000)+((x)*0x1000)):((0x40024000)+((x-4)*1000)))
//#define GPIO_PortA_APB_OFFSET                     0x40004000
//#define GPIO_PortB_APB_OFFSET 										0x40005000
//#define GPIO_PortC_APB_OFFSET 										0x40006000
//#define GPIO_PortD_APB_OFFSET 										0x40007000
//#define GPIO_PortE_APB_OFFSET 										0x40024000
//#define GPIO_PortF_APB_OFFSET											0x40025000


#elif defined(GPIO_AHB)
#define GPIOx(x)                     (0x40058000)+((x)*0x1000)
//#define GPIO_PortA_AHB_OFFSET 									 	0x40058000
//#define GPIO_PortB_AHB_OFFSET 										0x40059000
//#define GPIO_PortC_AHB_OFFSET 										0x4005A000
//#define GPIO_PortD_AHB_OFFSET 										0x4005B000
//#define GPIO_PortE_AHB_OFFSET 										0x4005C000
//#define GPIO_PortF_AHB_OFFSET 										0x4005D000

#else
#error "Please choose a bus for GPIOs"
#define GPIO_OFFSET 0x40004000
#endif


#define RCGCGPIO				                      *((volatile uint32*)(SystemControl + (0x608)))    
#define GPIODATA(x)			                      *((volatile uint32*)(GPIOx(x) + (0x000)))   //RW and is masked 0-255 addresses (bits 2-9) add them to address to apply mask
#define GPIODIR(x)														*((volatile uint32*)(GPIOx(x) + (0x400)))   //direction; 0 input and 1 output
#define GPIOIS(x)                             *((volatile uint32*)(GPIOx(x) + (0x404)))   //interrupt sense
#define GPIOIBE(x)														*((volatile uint32*)(GPIOx(x) + (0x408)))   //interrupt sense
#define GPIOIEV(x)														*((volatile uint32*)(GPIOx(x) + (0x40C)))   //interrupt event ....
#define GPIOIM(x)															*((volatile uint32*)(GPIOx(x) + (0x410)))   //interrupt sense
#define GPIORIS(x)														*((volatile uint32*)(GPIOx(x) + (0x414)))   //interrupt sense
#define GPIOMIS(x)														*((volatile uint32*)(GPIOx(x) + (0x418)))   //interrup mask
#define GPIOICR(x)                            *((volatile uint32*)(GPIOx(x) + (0x41C)))   //
#define GPIOAFSEL(x)                          *((volatile uint32*)(GPIOx(x) + (0x420)))   //Alternate Function
#define GPIODR2R(x)                           *((volatile uint32*)(GPIOx(x) + (0x500)))   //2mA
#define GPIODR4R(x)                           *((volatile uint32*)(GPIOx(x) + (0x504)))   //4mA
#define GPIODR8R(x)                           *((volatile uint32*)(GPIOx(x) + (0x508)))   //8mA
#define GPIOODR(x)														*((volatile uint32*)(GPIOx(x) + (0x50C)))   //open-drain
#define GPIOPUR(x)														*((volatile uint32*)(GPIOx(x) + (0x510)))   //pullup
#define GPIOPDR(x)														*((volatile uint32*)(GPIOx(x) + (0x514)))   //pulldown
#define GPIOSLR(x)														*((volatile uint32*)(GPIOx(x) + (0x518)))   //slew rate control
#define GPIODEN(x)														*((volatile uint32*)(GPIOx(x) + (0x51C)))   //
#define GPIOLOCK(x)														*((volatile uint32*)(GPIOx(x) + (0x520)))   //
#define GPIOCR(x)															*((volatile uint32*)(GPIOx(x) + (0x524)))   //commit
#define GPIOAMSEL(x)													*((volatile uint32*)(GPIOx(x) + (0x528)))   //
#define GPIOPCTL(x)														*((volatile uint32*)(GPIOx(x) + (0x52C)))   //
#define GPIOADCCTL(x)													*((volatile uint32*)(GPIOx(x) + (0x530)))   //
#define GPIODMACTL(x)													*((volatile uint32*)(GPIOx(x) + (0x534)))   //



/***********************/
/*******API-TYPES*******/
/***********************/
typedef enum 
{
	PORT_PIN_0, PORT_PIN_1, PORT_PIN_2, PORT_PIN_3, PORT_PIN_4, PORT_PIN_5, PORT_PIN_6, PORT_PIN_7
}EN_Port_PinNum_t;


typedef enum 
{
	PORT_PIN_OUTPUT, PORT_PIN_INPUT
}EN_Port_PinDirectionType_t;

typedef enum 
{
	//TO-DO: State all types here
	PORT_DEN, PORT_UART, PORT_SPI, PORT_I2C
}EN_Port_PinModeType_t;

typedef enum 
{
	PORT_PULL_UP, PORT_PULL_DOWN, PORT_OPEN_DRAIN
}EN_Port_PinInternalAttachType_t;

typedef enum 
{
	PORT_2mA, PORT_4mA, PORT_8mA 
}EN_Port_PinOutputCurrentType_t;

typedef EN_Dio_PortNum_t Port_Num_t;
typedef EN_Dio_ChannelNum_t Port_PinNum_t;
typedef EN_Dio_ChannelLevelType_t Port_PinLevelType_t;


typedef struct
{
	EN_Port_PinModeType_t PortPinMode;
	Port_PinLevelType_t PortPinLevelValue;
	EN_Port_PinDirectionType_t PortPinDirection;
	EN_Port_PinInternalAttachType_t PortPinInternalAttach;
	EN_Port_PinOutputCurrentType_t PortPinOutputCurrent;
	Port_Num_t PortNum;
	Port_PinNum_t PortPinNum;
}Port_ConfigType;


/***********************/
/*****API-FUNCTIONS*****/
/***********************/
void Port_Init (const Port_ConfigType* ConfigPtr);


#endif /* PORT.H */