/*
 * SWITCH_private.h
 *
 *  Created on: Mar 25, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef HAL_SWITCH_SWITCH_PRIVATE_H_
#define HAL_SWITCH_SWITCH_PRIVATE_H_


typedef enum
{
	internalPullUp,
	ExternalPullUp,
	ExternalPullDown
}SwitchConnectionType_t ;

typedef struct
{
	DIO_PORT_t Switch_port ;
	DIO_PIN_t  Switch_pin ;
	SwitchConnectionType_t connect_type;
}Switch_info_t;

typedef enum
{
	NoSwitchError,
	PortSwitchError,
	PinSwitchError,
	AdressSwitchError
}SwitchEErrState_t;



typedef enum
{
	PressedPullUp,
	NOTPressedPullUp,
	NOTPressedPullDown=0,
	PressedPullDown,
}SwitchState_t ;

#endif /* HAL_SWITCH_SWITCH_PRIVATE_H_ */
