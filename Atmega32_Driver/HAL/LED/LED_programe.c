/*
 * LED_programe.c
 *
 *  Created on: Mar 24, 2023
 *      Author: Mahmoud Hamed
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MACL/DIO/DIO_interface.h"
#include "LED_interface.h"

LED_ErrState_t LED_ErrStatLedInit(LED_Info_t * Ptr_u8ledinfo)
{
	if(Ptr_u8ledinfo->LED_PIN >= DIO_pin0 && Ptr_u8ledinfo->LED_PIN <= DIO_pin7)
	{

			DIO_ErrStateSetPinDirec(Ptr_u8ledinfo->LED_PORT , Ptr_u8ledinfo->LED_PIN , DIO_U8_OUTPUT);
	}

	return NoError ;
}
LED_ErrState_t LED_ErrStatLedOn(LED_Info_t * Ptr_u8ledinfo)
{
	if(Ptr_u8ledinfo->LED_PIN >= DIO_pin0 && Ptr_u8ledinfo->LED_PIN <= DIO_pin7)
	{
		if(Ptr_u8ledinfo->connection_type == sourceconnection)
		{
			DIO_ErrStateSetPinDirec(Ptr_u8ledinfo->LED_PORT , Ptr_u8ledinfo->LED_PIN , DIO_U8_OUTPUT);
			DIO_ErrStateSetPinValue(Ptr_u8ledinfo->LED_PORT , Ptr_u8ledinfo->LED_PIN , DIO_U8_HIGH);
		}
		else if (Ptr_u8ledinfo->connection_type == Sinkconnection)
		{
			 DIO_ErrStateSetPinDirec(Ptr_u8ledinfo->LED_PORT , Ptr_u8ledinfo->LED_PIN , DIO_U8_OUTPUT);
		     DIO_ErrStateSetPinValue(Ptr_u8ledinfo->LED_PORT , Ptr_u8ledinfo->LED_PIN , DIO_U8_LOW);
		}
		else
		{
			return LedConnectionError ;
		}
	}

		return NoError ;
}
LED_ErrState_t LED_ErrStatLedOFF(LED_Info_t * Ptr_u8ledinfo)
{
	if(Ptr_u8ledinfo->LED_PIN >= DIO_pin0 && Ptr_u8ledinfo->LED_PIN <= DIO_pin7)
	{
		if(Ptr_u8ledinfo->connection_type == sourceconnection)
		{

			DIO_ErrStateSetPinValue(Ptr_u8ledinfo->LED_PORT , Ptr_u8ledinfo->LED_PIN , DIO_U8_LOW);
		}
		else if (Ptr_u8ledinfo->connection_type == Sinkconnection)
		{

		     DIO_ErrStateSetPinValue(Ptr_u8ledinfo->LED_PORT , Ptr_u8ledinfo->LED_PIN , DIO_U8_HIGH);
		}
		else
		{
			return LedConnectionError ;
		}
	}

		return NoError ;
}
