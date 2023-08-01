/*
 * DIO_register.h
 *
 *  Created on: Mar 23, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MCAL_DIO_DIO_REGISTER_H_
#define MCAL_DIO_DIO_REGISTER_H_


#define PINA     *((volatile u8*)0x39)
#define DDRA     *((volatile u8*)0x3A)
#define PORTA    *((volatile u8*)0x3B)

#define PINB     *((volatile u8*)0x36)
#define DDRB     *((volatile u8*)0x37)
#define PORTB    *((volatile u8*)0x38)

#define PIND     *((volatile u8*)0x30)
#define DDRD     *((volatile u8*)0x31)
#define PORTD    *((volatile u8*)0x32)

#define DDRC     *((volatile u8*)0x34)
#define PINC     *((volatile u8*)0x33)
#define PORTC    *((volatile u8*)0x35)


#endif /* MCAL_DIO_DIO_REGISTER_H_ */
