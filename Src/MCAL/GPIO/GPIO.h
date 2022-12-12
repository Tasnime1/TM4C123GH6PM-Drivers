#ifndef GPIO_H
#define GPIO_H


/**************************/
/*********INCLUDES*********/
/**************************/
#include "types.h"
#include <stdio.h>
#include "BIT_MATH.h"
#include "GPIO_Lcfg.h"


/******************************/
/********GPIO REGISTERS********/
/******************************/
#define SystemControl              	0x400FE000

#define GPIO_APB
//#define GPIO_AHB

#if defined(GPIO_APB)
#define GPIOx(x)               	(x<4?((0x40004000)+((x)*0x1000)):((0x40024000)+((x-4)*1000)))
//#define GPIO_GPIOA_APB_OFFSET                     0x40004000
//#define GPIO_GPIOB_APB_OFFSET 										0x40005000
//#define GPIO_GPIOC_APB_OFFSET 										0x40006000
//#define GPIO_GPIOD_APB_OFFSET 										0x40007000
//#define GPIO_GPIOE_APB_OFFSET 										0x40024000
//#define GPIO_GPIOF_APB_OFFSET											0x40025000


#elif defined(GPIO_AHB)
#define GPIOx(x)                     (0x40058000)+((x)*0x1000)
//#define GPIO_GPIOA_AHB_OFFSET 									 	0x40058000
//#define GPIO_GPIOB_AHB_OFFSET 										0x40059000
//#define GPIO_GPIOC_AHB_OFFSET 										0x4005A000
//#define GPIO_GPIOD_AHB_OFFSET 										0x4005B000
//#define GPIO_GPIOE_AHB_OFFSET 										0x4005C000
//#define GPIO_GPIOF_AHB_OFFSET 										0x4005D000

#else
#error "Please choose a bus for GPIOs"
#define GPIO_OFFSET 0x40004000
#endif


#define RCGCGPIO				                      *((volatile uint32_t*)(SystemControl + (0x608)))    
#define GPIODATA(x)			                      *((volatile uint32_t*)(GPIOx(x) + (0x000)))   //RW and is masked 0-255 addresses (bits 2-9) add them to address to apply mask
#define GPIODIR(x)														*((volatile uint32_t*)(GPIOx(x) + (0x400)))   //direction; 0 input and 1 output
#define GPIOIS(x)                             *((volatile uint32_t*)(GPIOx(x) + (0x404)))   //interrupt sense
#define GPIOIBE(x)														*((volatile uint32_t*)(GPIOx(x) + (0x408)))   //interrupt sense
#define GPIOIEV(x)														*((volatile uint32_t*)(GPIOx(x) + (0x40C)))   //interrupt event ....
#define GPIOIM(x)															*((volatile uint32_t*)(GPIOx(x) + (0x410)))   //interrupt sense
#define GPIORIS(x)														*((volatile uint32_t*)(GPIOx(x) + (0x414)))   //interrupt sense
#define GPIOMIS(x)														*((volatile uint32_t*)(GPIOx(x) + (0x418)))   //interrup mask
#define GPIOICR(x)                            *((volatile uint32_t*)(GPIOx(x) + (0x41C)))   //
#define GPIOAFSEL(x)                          *((volatile uint32_t*)(GPIOx(x) + (0x420)))   //Alternate Function
#define GPIODR2R(x)                           *((volatile uint32_t*)(GPIOx(x) + (0x500)))   //2mA
#define GPIODR4R(x)                           *((volatile uint32_t*)(GPIOx(x) + (0x504)))   //4mA
#define GPIODR8R(x)                           *((volatile uint32_t*)(GPIOx(x) + (0x508)))   //8mA
#define GPIOODR(x)														*((volatile uint32_t*)(GPIOx(x) + (0x50C)))   //open-drain
#define GPIOPUR(x)														*((volatile uint32_t*)(GPIOx(x) + (0x510)))   //pullup
#define GPIOPDR(x)														*((volatile uint32_t*)(GPIOx(x) + (0x514)))   //pulldown
#define GPIOSLR(x)														*((volatile uint32_t*)(GPIOx(x) + (0x518)))   //slew rate control
#define GPIODEN(x)														*((volatile uint32_t*)(GPIOx(x) + (0x51C)))   //
#define GPIOLOCK(x)														*((volatile uint32_t*)(GPIOx(x) + (0x520)))   //
#define GPIOCR(x)															*((volatile uint32_t*)(GPIOx(x) + (0x524)))   //commit
#define GPIOAMSEL(x)													*((volatile uint32_t*)(GPIOx(x) + (0x528)))   //
#define GPIOPCTL(x)														*((volatile uint32_t*)(GPIOx(x) + (0x52C)))   //
#define GPIOADCCTL(x)													*((volatile uint32_t*)(GPIOx(x) + (0x530)))   //
#define GPIODMACTL(x)													*((volatile uint32_t*)(GPIOx(x) + (0x534)))   //


/***********************/
/*******API-TYPES*******/
/***********************/
typedef enum
{
	GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7
}EN_GPIO_ChannelNum_t;


typedef enum 
{
	GPIO_PIN_LOW=0, GPIO_PIN_HIGH
}EN_GPIO_ChannelLevelType_t;

typedef enum 
{
	GPIO_PORT_A=0, GPIO_PORT_B, GPIO_PORT_C, GPIO_PORT_D, GPIO_PORT_E, GPIO_PORT_F
}EN_GPIO_PortNum_t;

typedef uint8_t GPIO_GPIOLevelType_t; 

typedef enum 
{
	GPIO_PIN_INPUT=0, GPIO_PIN_OUTPUT
}EN_GPIO_PinDirectionType_t;

typedef enum 
{
	//TO-DO: State all types here
	GPIO_DEN, GPIO_UART, GPIO_SPI, GPIO_I2C
}EN_GPIO_PinModeType_t;

typedef enum 
{
	GPIO_PULL_UP, GPIO_PULL_DOWN, GPIO_OPEN_DRAIN
}EN_GPIO_PinInternalAttachType_t;

typedef enum 
{
	GPIO_2mA, GPIO_4mA, GPIO_8mA 
}EN_GPIO_PinOutputCurrentType_t;


typedef struct
{
	EN_GPIO_PinModeType_t PinMode;
	EN_GPIO_ChannelLevelType_t PinLevelValue;
	EN_GPIO_PinDirectionType_t PinDirection;
	EN_GPIO_PinInternalAttachType_t PinInternalAttach;
	EN_GPIO_PinOutputCurrentType_t PinOutputCurrent;
	EN_GPIO_PortNum_t PortNum;
	EN_GPIO_ChannelNum_t PinNum;
}GPIO_ConfigType;



/***********************/
/*****API-FUNCTIONS*****/
/***********************/
void GPIO_Init (const GPIO_ConfigType* ConfigPtr);

EN_GPIO_ChannelLevelType_t GPIO_ReadChannel (EN_GPIO_PortNum_t GPIOId, EN_GPIO_ChannelNum_t ChannelId);
void GPIO_WriteChannel (EN_GPIO_PortNum_t GPIOId, EN_GPIO_ChannelNum_t ChannelId, EN_GPIO_ChannelLevelType_t Level);
EN_GPIO_ChannelLevelType_t GPIO_FlipChannel (EN_GPIO_PortNum_t GPIOId, EN_GPIO_ChannelNum_t ChannelId);
GPIO_GPIOLevelType_t GPIO_ReadGPIO (EN_GPIO_PortNum_t GPIOId);
void GPIO_WriteGPIO (EN_GPIO_PortNum_t GPIOId, GPIO_GPIOLevelType_t Level);

#endif /* GPIO.H */