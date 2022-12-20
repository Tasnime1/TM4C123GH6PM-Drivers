#ifndef GPIO_H
#define GPIO_H

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
#include "types.h"
#include "BIT_MATH.h"
#include "GPIO_cfg.h"
#include "stdio.h"

/*- GPIO PORTS' ADDRESSES
***************************************************************************************/

#define GPIO_APB
//#define GPIO_AHB

#if defined(GPIO_APB)
#define GPIOx(x)               	    (x<4?((0x40004000)+((x)*0x1000)):((0x40024000)+((x-4)*0x1000)))
#define GPIOA_ADDRESS                      0x40004000
#define GPIOB_ADDRESS 										 0x40005000
#define GPIOC_ADDRESS 										 0x40006000
#define GPIOD_ADDRESS 										 0x40007000
#define GPIOE_ADDRESS 										 0x40024000
#define GPIOF_ADDRESS										 	 0x40025000


#elif defined(GPIO_AHB)
#define GPIOx(x)                     (0x40058000)+((x)*0x1000)
//#define GPIOA_ADDRESS 									 	0x40058000
//#define GPIOB_ADDRESS 										0x40059000
//#define GPIOC_ADDRESS 										0x4005A000
//#define GPIOD_ADDRESS 										0x4005B000
//#define GPIOE_ADDRESS 										0x4005C000
//#define GPIOF_ADDRESS 										0x4005D000

#else
#error "Please choose a bus for GPIOs"
#endif




/*- GPIO REGISTERS
***************************************************************************************/

#define DATA_OFFSET(y) ( 1 << (y+2) )

#define SystemControl              						0x400FE000
#define RCGCGPIO				                      (*((volatile uint32_t*)(SystemControl + (0x608))))    
#define GPIODATA(x, y)			                  (*((volatile uint32_t*)(GPIOx(x) + (0x000)+ (DATA_OFFSET(y)) )))   //RW and is masked 0-255 addresses (bits 2-9) add them to address to apply mask
#define GPIODIR(x)														(*((volatile uint32_t*)(GPIOx(x) + (0x400))))   //direction; 0 input and 1 output
#define GPIOIS(x)                             (*((volatile uint32_t*)(GPIOx(x) + (0x404))))   //interrupt sense
#define GPIOIBE(x)														(*((volatile uint32_t*)(GPIOx(x) + (0x408))))   //interrupt both edges
#define GPIOIEV(x)														(*((volatile uint32_t*)(GPIOx(x) + (0x40C))))   //interrupt event ....
#define GPIOIM(x)															(*((volatile uint32_t*)(GPIOx(x) + (0x410))))   //interrupt mask
#define GPIORIS(x)														(*((volatile uint32_t*)(GPIOx(x) + (0x414))))   //interrupt ...
#define GPIOMIS(x)														(*((volatile uint32_t*)(GPIOx(x) + (0x418))))   //interrup ..
#define GPIOICR(x)                            (*((volatile uint32_t*)(GPIOx(x) + (0x41C))))   //
#define GPIOAFSEL(x)                          (*((volatile uint32_t*)(GPIOx(x) + (0x420))))   //Alternate Function
#define GPIODR2R(x)                           (*((volatile uint32_t*)(GPIOx(x) + (0x500))))   //2mA
#define GPIODR4R(x)                           (*((volatile uint32_t*)(GPIOx(x) + (0x504))))   //4mA
#define GPIODR8R(x)                           (*((volatile uint32_t*)(GPIOx(x) + (0x508))))   //8mA
#define GPIOODR(x)														(*((volatile uint32_t*)(GPIOx(x) + (0x50C))))   //open-drain
#define GPIOPUR(x)														(*((volatile uint32_t*)(GPIOx(x) + (0x510))))   //pullup
#define GPIOPDR(x)														(*((volatile uint32_t*)(GPIOx(x) + (0x514))))   //pulldown
#define GPIOSLR(x)														(*((volatile uint32_t*)(GPIOx(x) + (0x518))))   //slew rate control
#define GPIODEN(x)														(*((volatile uint32_t*)(GPIOx(x) + (0x51C))))   //
#define GPIOLOCK(x)														(*((volatile uint32_t*)(GPIOx(x) + (0x520))))   //
#define GPIOCR(x)															(*((volatile uint32_t*)(GPIOx(x) + (0x524))))   //commit
#define GPIOAMSEL(x)													(*((volatile uint32_t*)(GPIOx(x) + (0x528))))   //
#define GPIOPCTL(x)														(*((volatile uint32_t*)(GPIOx(x) + (0x52C))))   //
#define GPIOADCCTL(x)													(*((volatile uint32_t*)(GPIOx(x) + (0x530))))  //
#define GPIODMACTL(x)													(*((volatile uint32_t*)(GPIOx(x) + (0x534))))   //


#define UNLOCK_VALUE 0x4C4F434B
#define BITMASK_SHIFT 2





/*- API TYPES
***************************************************************************************/
typedef enum
{
	GPIO_PIN_0=0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7
}EN_GPIO_ChannelNum_t;


typedef enum 
{
	GPIO_PIN_LOW=0, GPIO_PIN_HIGH
}EN_GPIO_ChannelLevelType_t;

typedef enum 
{
	GPIO_PORT_A=0, GPIO_PORT_B=1, GPIO_PORT_C=2, GPIO_PORT_D=3, GPIO_PORT_E=4, GPIO_PORT_F=5
}EN_GPIO_PortNum_t;

typedef uint8_t GPIO_LevelType_t; 

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



/*- APIs
***************************************************************************************/
void GPIO_Init (const GPIO_ConfigType* ConfigPtr);

EN_GPIO_ChannelLevelType_t GPIO_ReadChannel (EN_GPIO_PortNum_t GPIOId, EN_GPIO_ChannelNum_t ChannelId);
void GPIO_WriteChannel (EN_GPIO_PortNum_t GPIOId, EN_GPIO_ChannelNum_t ChannelId, EN_GPIO_ChannelLevelType_t Level);
EN_GPIO_ChannelLevelType_t GPIO_FlipChannel (EN_GPIO_PortNum_t GPIOId, EN_GPIO_ChannelNum_t ChannelId);
GPIO_LevelType_t GPIO_ReadPort (EN_GPIO_PortNum_t GPIOId);
void GPIO_WritePort (EN_GPIO_PortNum_t GPIOId, GPIO_LevelType_t Level);


#endif /* GPIO.H */