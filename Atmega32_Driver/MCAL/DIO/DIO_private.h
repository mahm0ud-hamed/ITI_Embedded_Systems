/*
 * DIO_private.h
 *
 *  Created on: Mar 23, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_


 typedef enum
 {
	 NOError ,
	 PinNumberError,
	 PortNumberError,
	 pinDirectionError, /*if Direction */
	 PinValueError,     /*if value > 1 and < low*/
	 PortDirectionError,
	 PortValueError,
	 AddressError

 }Err_STATE_t;


#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
