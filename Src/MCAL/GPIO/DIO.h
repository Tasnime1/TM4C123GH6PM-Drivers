#ifndef DIO_H
#define DIO_H


//Library inclusions
#include "types.h"


//API-TYPES
typedef enum
{
	DIO_PIN_0, DIO_PIN_1, DIO_PIN_2, DIO_PIN_3, DIO_PIN_4, DIO_PIN_5, DIO_PIN_6, DIO_PIN_7
}EN_Dio_ChannelNum_t;


typedef enum 
{
	DIO_LEVEL_LOW=0, DIO_LEVEL_HIGH
}EN_Dio_ChannelLevelType_t;

typedef enum 
{
	DIO_PORT_A=0, DIO_PORT_B, DIO_PORT_C, DIO_PORT_D, DIO_PORT_E, DIO_PORT_F
}EN_Dio_PortNum_t;

typedef uint8_t Dio_PortLevelType_t; 


//API-FUNCTIONS
EN_Dio_ChannelLevelType_t Dio_ReadChannel (EN_Dio_PortNum_t PortId, EN_Dio_ChannelNum_t ChannelId);
void DIO_WriteChannel (EN_Dio_PortNum_t PortId, EN_Dio_ChannelNum_t ChannelId, EN_Dio_ChannelLevelType_t Level);
EN_Dio_ChannelLevelType_t Dio_FlipChannel (EN_Dio_PortNum_t PortId, EN_Dio_ChannelNum_t ChannelId);

Dio_PortLevelType_t Dio_ReadPort (EN_Dio_PortNum_t PortId);
void Dio_WritePort (EN_Dio_PortNum_t PortId, Dio_PortLevelType_t Level);


#endif /* DIO.H */