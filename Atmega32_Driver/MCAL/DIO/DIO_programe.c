/*
 * DIO_programe.c
 *
 *  Created on: Mar 23, 2023
 *      Author: Mahmoud Hamed
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_register.h"
#include "DIO_interface.h"



Err_STATE_t DIO_ErrStateSetPinDirec(DIO_PORT_t copy_u8PortNum,DIO_PIN_t copy_u8PinNum,DIO_DIR_t copy_u8dierction)
{
	if(copy_u8PinNum <= DIO_pin7 && copy_u8PinNum>= DIO_pin0)
	{
		if(copy_u8dierction == DIO_U8_OUTPUT)
		{
			switch (copy_u8PortNum)
			{
			case DIO_u8_PORTA :SET_BIT(DDRA,copy_u8PinNum); break;
			case DIO_u8_PORTB :SET_BIT(DDRB,copy_u8PinNum); break;
			case DIO_u8_PORTC :SET_BIT(DDRC,copy_u8PinNum); break;
			case DIO_u8_PORTD :SET_BIT(DDRD,copy_u8PinNum); break;
			default :
				return PortNumberError ;
			}
		}
		else if(copy_u8dierction == DIO_U8_INPUT)
		{
			switch (copy_u8PortNum)
			{
			case DIO_u8_PORTA :CLR_BIT(DDRA,copy_u8PinNum); break;
			case DIO_u8_PORTB :CLR_BIT(DDRB,copy_u8PinNum); break;
			case DIO_u8_PORTC :CLR_BIT(DDRC,copy_u8PinNum); break;
			case DIO_u8_PORTD :CLR_BIT(DDRD,copy_u8PinNum); break;
			default :
				return PortNumberError ;
			}

		}
		else
		{
			return pinDirectionError ;
		}

	}
	else
	{
		return PinNumberError ;
	}

	return NOError ;
}


Err_STATE_t DIO_ErrStateSetPinValue(DIO_PORT_t copy_u8PortNum,DIO_PIN_t copy_u8PinNum , DIO_DIR_t copy_u8Value)
{
	if(copy_u8PinNum <= DIO_pin7 && copy_u8PinNum >= DIO_pin0)
	{
		if(copy_u8Value == DIO_U8_HIGH)
		{
			switch (copy_u8PortNum)
			{
			case DIO_u8_PORTA :SET_BIT(PORTA,copy_u8PinNum); break;
			case DIO_u8_PORTB :SET_BIT(PORTB,copy_u8PinNum); break;
			case DIO_u8_PORTC :SET_BIT(PORTC,copy_u8PinNum); break;
			case DIO_u8_PORTD :SET_BIT(PORTD,copy_u8PinNum); break;
			default :
				return PortNumberError ;
			}
		}
		else if(copy_u8Value == DIO_U8_LOW)
		{
			switch (copy_u8PortNum)
			{
			case DIO_u8_PORTA :CLR_BIT(PORTA,copy_u8PinNum); break;
			case DIO_u8_PORTB :CLR_BIT(PORTB,copy_u8PinNum); break;
			case DIO_u8_PORTC :CLR_BIT(PORTC,copy_u8PinNum); break;
			case DIO_u8_PORTD :CLR_BIT(PORTD,copy_u8PinNum); break;
			default :
				return PortNumberError ;
			}

		}
		else
		{
			return PinValueError ;
		}

	}
	else
	{
		return PinNumberError ;
	}

	return NOError ;
}
Err_STATE_t DIO_ErrStateReadPinValue(DIO_PORT_t copy_u8PortNum , DIO_PIN_t copy_u8pinNum , u8* Read)
{
	if(Read != NULL )
	{

		if((copy_u8pinNum <= DIO_pin7) && (copy_u8pinNum  >= DIO_pin0))
		{
			switch (copy_u8PortNum)
			{
			case DIO_u8_PORTA :*Read=GET_BIT(PINA,copy_u8pinNum); break;
			case DIO_u8_PORTB :*Read=GET_BIT(PINB,copy_u8pinNum); break;
			case DIO_u8_PORTC :*Read=GET_BIT(PINC,copy_u8pinNum); break;
			case DIO_u8_PORTD :*Read=GET_BIT(PIND,copy_u8pinNum); break;
			default :
				return PortNumberError ;
			}
		}
		else
		{
			return PinNumberError ;
		}
	}
	else
	{
		return AddressError ;
	}

	return NOError ;
}

Err_STATE_t DIO_ErrStateSetPortDirec(DIO_PORT_t copy_u8PortNum, u8 copy_u8dierction)
{
	if(copy_u8dierction <= DIO_u8REG_MAX)
	{
		switch(copy_u8PortNum)
		{
		case DIO_u8_PORTA : DDRA = copy_u8dierction ; break;
		case DIO_u8_PORTB : DDRB = copy_u8dierction ; break;
		case DIO_u8_PORTC : DDRC = copy_u8dierction ; break;
		case DIO_u8_PORTD : DDRD = copy_u8dierction ; break;
		default :
			return PortNumberError ;
		}
	}
	else
	{
		return PortDirectionError ;
	}
	return NOError ;
}
Err_STATE_t DIO_ErrStateSetPortValue(DIO_PORT_t copy_u8PortNum,u8 copy_u8Value)
{
	if(copy_u8Value <= DIO_u8REG_MAX)
	{
		switch(copy_u8PortNum)
		{
		case DIO_u8_PORTA : PORTA = copy_u8Value ; break;
		case DIO_u8_PORTB : PORTB = copy_u8Value ; break;
		case DIO_u8_PORTC : PORTC = copy_u8Value ; break;
		case DIO_u8_PORTD : PORTD = copy_u8Value ; break;
		default :
			return PortNumberError ;
		}
	}
	else
	{
		return PortValueError ;
	}
	return NOError ;
}

Err_STATE_t DIO_ErrStateTogglePin(DIO_PORT_t copy_u8PortNum, DIO_PIN_t copy_u8pinNum)
{
	if(copy_u8pinNum<=7 && copy_u8pinNum >= 0)
	{
		switch (copy_u8PortNum)
		{
		case DIO_u8_PORTA : TOG_BIT(PORTA,copy_u8pinNum); break;
		case DIO_u8_PORTB : TOG_BIT(PORTB,copy_u8pinNum); break;
		case DIO_u8_PORTC : TOG_BIT(PORTC,copy_u8pinNum); break;
		case DIO_u8_PORTD : TOG_BIT(PORTD,copy_u8pinNum); break;
		default :
			return PortNumberError ;
		}
	}
	else
	{
		return PinNumberError;
	}
	return NOError ;
}
