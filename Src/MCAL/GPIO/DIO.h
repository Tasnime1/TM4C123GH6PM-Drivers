#ifndef DIO_H
#define DIO_H


//Library inclusions
#include "types.h"


//API-TYPES
typedef enum EN_DIO_ChannelType_t
{
	A0, A1, A2, A3, A4, A5, A6, A7
}EN_DIO_ChannelType_t;

typedef enum EN_Dio_PortType_t
{
	PORTA, PORTB, PORTC, PORTD, PORTE, PORTF
}EN_Dio_PortType_t;

typedef enum EN_Dio_ChannelLevelType_t
{
	HIGH, LOW
}EN_Dio_ChannelLevelType_t;

typedef uint8_t Dio_PortLevelType_t; 

//API-FUNCTIONS
EN_Dio_ChannelLevelType_t DIO_ReadChannel (EN_DIO_ChannelType_t ChannelId);

void DIO_WriteChannel (EN_DIO_ChannelType_t ChannelId, EN_Dio_ChannelLevelType_t Level);

Dio_PortLevelType_t Dio_ReadPort (EN_Dio_PortType_t PortId);

void Dio_WritePort (EN_Dio_PortType_t PortId, Dio_PortLevelType_t Level);

//we should add EN_Dio_PortType_t as input parameter too I guess
EN_Dio_ChannelLevelType_t Dio_FlipChannel (EN_DIO_ChannelType_t ChannelId);


#endif /* DIO.H */