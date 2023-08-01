/*
 * SWITCH_programe.c
 *
 *  Created on: Mar 25, 2023
 *      Author: Mahmoud Hamed
 */

#include "../../MACL/DIO/DIO_interface.h"
#include "../../LIB/STD_TYPES.h"
#include "SWITCH_interface.h"


SwitchEErrState_t SWITCH_SwitchErrorStateGetState(Switch_info_t* Switch, SwitchState_t *Result )
{
	u8 Local_u8STATE ;
	if(Switch->Switch_port <= DIO_u8_PORTD && Switch->Switch_port >= DIO_u8_PORTA )
	{
		if(Switch->Switch_pin <= DIO_pin7 && Switch->Switch_pin >= DIO_pin0 )
		{
			DIO_ErrStateSetPinDirec(Switch->Switch_port , Switch->Switch_pin ,DIO_U8_INPUT);
			switch(Switch->connect_type)
			{
			case internalPullUp :
				DIO_ErrStateSetPinValue(Switch->Switch_port , Switch->Switch_pin ,DIO_U8_HIGH);
				DIO_ErrStateReadPinValue(Switch->Switch_port, Switch->Switch_pin ,&Local_u8STATE);
				if(Local_u8STATE == 0 )
				{
					*Result = PressedPullUp ;

				}
				else if(Local_u8STATE == 1)
				{
					*Result = NOTPressedPullUp;
				}
				break;

			case ExternalPullUp:

				DIO_ErrStateReadPinValue(Switch->Switch_port, Switch->Switch_pin ,&Local_u8STATE);
				if(Local_u8STATE == 0 )
				{
					*Result = PressedPullUp ;
				}
				else if(Local_u8STATE == 1)
				{
					*Result = NOTPressedPullUp;
				}

				break;

			case ExternalPullDown:
				DIO_ErrStateReadPinValue(Switch->Switch_port, Switch->Switch_pin ,&Local_u8STATE);
				if(Local_u8STATE == 0 )
				{
					*Result = NOTPressedPullDown ;
				}
				else if(Local_u8STATE == 1)
				{
					*Result = PressedPullDown;

				}
				break;
			    default: // do nothing
				break ;


			}

		}
		else
		{
			return PinSwitchError ;
		}
	}
	else
	{
		return PortSwitchError;
	}
	return NoSwitchError ;

}
