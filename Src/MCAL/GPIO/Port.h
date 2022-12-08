#ifndef PORT_H
#define PORT_H


//Library inclusions
#include "types.h"

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