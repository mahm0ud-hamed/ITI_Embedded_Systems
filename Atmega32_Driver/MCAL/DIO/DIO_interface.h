/*
 * DIO_interface.h
 *
 *  Created on: Mar 23, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
#include "DIO_register.h"
#include "DIO_private.h"
#include "../../LIB/STD_TYPES.h"
#define NULL (void*)0
#define DIO_u8REG_MAX  255

 typedef enum
 {
	 DIO_pin0,
	 DIO_pin1,
	 DIO_pin2,
	 DIO_pin3,
	 DIO_pin4,
	 DIO_pin5,
	 DIO_pin6,
	 DIO_pin7
 }DIO_PIN_t;

 typedef enum
 {
	 DIO_u8_PORTA,
	 DIO_u8_PORTB,
	 DIO_u8_PORTC,
	 DIO_u8_PORTD
 }DIO_PORT_t;


 typedef enum
 {
	 DIO_U8_INPUT,
	 DIO_U8_OUTPUT
 }DIO_DIR_t;

 typedef enum
 {
	 DIO_U8_LOW,
	 DIO_U8_HIGH


 }DIO_VALUE_t;




Err_STATE_t DIO_ErrStateSetPinDirec(DIO_PORT_t copy_u8PortNum , DIO_PIN_t copy_u8PinNum,DIO_DIR_t copy_u8dierction);
Err_STATE_t DIO_ErrStateSetPinValue(DIO_PORT_t copy_u8PortNum , DIO_PIN_t copy_u8PinNum , DIO_DIR_t copy_u8Value);
Err_STATE_t DIO_ErrStateReadPinValue(DIO_PORT_t copy_u8PortNum, DIO_PIN_t copy_u8pinNum  , u8* Read);

Err_STATE_t DIO_ErrStateTogglePin(DIO_PORT_t copy_u8PortNum, DIO_PIN_t copy_u8pinNum);

Err_STATE_t DIO_ErrStateSetPortDirec( DIO_PORT_t copy_u8PortNum , u8 copy_u8dierction);
Err_STATE_t DIO_ErrStateSetPortValue( DIO_PORT_t copy_u8PortNum , u8 copy_u8Value);



#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
