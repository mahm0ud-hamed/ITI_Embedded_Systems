/*
 * GIE_register.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_GIE_GIE_REGISTER_H_
#define MACL_GIE_GIE_REGISTER_H_


#define SREG        (*(volatile u8*)(0x5F))/*status register address */

#define SREG_GEI    7 /*general interrupt pin on status register */
#endif /* MACL_GIE_GIE_REGISTER_H_ */
