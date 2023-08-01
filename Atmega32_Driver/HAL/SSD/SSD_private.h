/*
 * SSD_private.h
 *
 *  Created on: Mar 26, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef HAL_SSD_SSD_PRIVATE_H_
#define HAL_SSD_SSD_PRIVATE_H_
#include "SSD_Config.h"


static u8 SsdArr[10]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


typedef enum
{
	CommAnode,
	CommCathode
}SevSeg_type_t;

typedef struct
{
	SevSeg_type_t Type;
	DIO_PORT_t SSD_port;
	DIO_PORT_t SSD_Eport;
	DIO_PIN_t  SSD_Epin;

}SevSeg_info_t;

typedef enum
{
	NoSsdError,
	PortSsdError,
	EpinSsdError,
	EportSsdError,
	TypeSsdError
}SevSegErrState_t ;





#endif /* HAL_SSD_SSD_PRIVATE_H_ */
