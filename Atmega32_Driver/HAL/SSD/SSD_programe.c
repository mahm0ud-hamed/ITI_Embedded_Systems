/*
 * SSD_programe.c
 *
 *  Created on: Mar 26, 2023
 *      Author: Mahmoud Hamed
 */

#include"../../LIB/STD_TYPES.h"
#include "../../MACL/DIO/DIO_interface.h"
#include <util/delay.h>
#include "SSD_interface.h"


/*function to display particular number */
SevSegErrState_t SevSeg_SevSegErrStateDisplayNum(SevSeg_info_t *SSD ,u8 copy_u8Num)
{
	if(SSD->SSD_port <= DIO_u8_PORTD && SSD->SSD_port >= DIO_u8_PORTA)
	{
		if(SSD->SSD_Eport <= DIO_u8_PORTD && SSD->SSD_Eport >= DIO_u8_PORTA)
		{
			if(SSD->SSD_Epin <= DIO_pin7 && SSD->SSD_Epin >= DIO_pin0)
			{
				switch(SSD->Type)
				{
				case CommCathode :
					DIO_ErrStateSetPortDirec(SSD->SSD_port,0xff);
					DIO_ErrStateSetPinDirec(SSD->SSD_Eport,SSD->SSD_Epin,DIO_U8_OUTPUT);
					DIO_ErrStateSetPortValue(SSD->SSD_port,SsdArr[copy_u8Num]);
					DIO_ErrStateSetPinValue(SSD->SSD_Eport,SSD->SSD_Epin,DIO_U8_LOW);
					break;
				case CommAnode :
					DIO_ErrStateSetPortDirec(SSD->SSD_port,0xff);
					DIO_ErrStateSetPinDirec(SSD->SSD_Eport,SSD->SSD_Epin,DIO_U8_OUTPUT);
					DIO_ErrStateSetPortValue(SSD->SSD_port,~(SsdArr[copy_u8Num]));
					DIO_ErrStateSetPinValue(SSD->SSD_Eport,SSD->SSD_Epin,DIO_U8_HIGH);
					break ;
				default :
					return TypeSsdError ;

				}
			}
			else
			{
				return EpinSsdError ;
			}
		}
		else
		{
			return EportSsdError ;
		}
	}
	else
	{
		return PortSsdError ;
	}
	return NoSsdError ;
}

/*function to display range of number between start and end */
SevSegErrState_t SevSeg_SevSegErrStateDisplayRange(SevSeg_info_t *SSD ,u8 copy_u8Start,u8 copy_u8End)
{
	u8 Local_u8counter =0 ;
	for (Local_u8counter= copy_u8Start ; Local_u8counter<= copy_u8End ;Local_u8counter++)
	{
		SevSeg_SevSegErrStateDisplayNum(SSD ,Local_u8counter);
		_delay_ms(500);
	}
	return NoSsdError ;
}

/*function to display numbers between zero and max */
SevSegErrState_t SevSeg_SevSegErrStateDisplayMax(SevSeg_info_t *SSD ,u8 copy_u8Max)
{
	u8 Local_u8counter =0 ;
	for (Local_u8counter= 0 ; Local_u8counter<= copy_u8Max ;Local_u8counter++)
	{
		SevSeg_SevSegErrStateDisplayNum(SSD ,Local_u8counter);
		_delay_ms(500);
	}
	return NoSsdError ;
}

