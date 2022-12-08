#ifndef PORT_H
#define PORT_H


//Library inclusions
#include "types.h"

//REGISTERS' BASE ADDRESSES     
#define System_Control_Base_Address              	0x400FE000

/**********************/
/****GPIO REGISTERS****/
/**********************/
#define GPIO_APB

#if defined(GPIO_APB)
#define GPIOx(x)               	(x<4?((0x40004000)+((x)*0x1000)):((0x40024000)+((x-4)*1000)))
//#define GPIO_PortA_APB_OFFSET                     0x40004000
//#define GPIO_PortB_APB_OFFSET 										0x40005000
//#define GPIO_PortC_APB_OFFSET 										0x40006000
//#define GPIO_PortD_APB_OFFSET 										0x40007000
//#define GPIO_PortE_APB_OFFSET 										0x40024000
//#define GPIO_PortF_APB_OFFSET											0x40025000


#elif defined(GPIO_AHB)
#define GPIO_x(x)                     (0x40058000)+((x)*0x1000)
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


//Registers' addresses and offsets
#define RCGCGPIO_address                          *((volatile uint32*)(System_Control_Base_Address + (0x608)))    
#define GPIODATA_offset                           0x000   //RW and is masked 0-255 addresses (bits 2-9) add them to address to apply mask
#define GPIODIR_offset														0x400   //direction; 0 input and 1 output
#define GPIOIS_offset                             0x404   //interrupt sense
#define GPIOIEV_offset														0x40C   //interrupt event ....
#define GPIOIM_offset															0x410   //interrup mask
#define GPIOICR_offset                            0x41C   //
#define GPIOAFSEL_offset                          0x420   //Alternate Function
#define GPIODR2R_offset                           0x500   //2mA
#define GPIODR4R_offset                           0x504   //4mA
#define GPIODR8R_offset                           0x508   //8mA
#define GPIOODR_offset														0x50C   //open-drain
#define GPIOPUR_offset														0x510   //pullup
#define GPIOPDR_offset														0x514   //pullup

// TO-DO: page 682 for enabling and AFSEL functionalities


//API-TYPES
typedef enum EN_PORT_PinType_t
{
	A0, A1, A2, A3, A4, A5, A6, A7
}EN_PORT_PinType_t;

typedef enum EN_PORT_PinDirectionType_t
{
	OUTPUT, INPUT
}EN_PORT_PinDirectionType_t;

typedef enum EN_PORT_PinModeType_t
{
	//state all types here
	DIO, UART, SPI, I2C
}EN_PORT_PinModeType_t;

typedef enum EN_PORT_PinInternalAttachType_t
{
	PULL_UP, PULL_DOWN, OPEN_DRAIN
}EN_PORT_PinInternalAttachType_t;

typedef enum EN_PORT_PinOutputCurrentType_t
{
	_2mA, _4mA, _8mA 
}EN_PORT_PinOutputCurrentType_t;

typedef struct
{
	uint8_t PortPinMode;
	char PortPinLevelValue;
	char PortPinDirection;
	uint8_t PortPinInternalAttach;
	uint8_t PortPinOutputCurrent;
}Port_ConfigType;


//API-FUNCTIONS
void Port_Init (const Port_ConfigType ConfigPtr);

#endif /* PORT.H */