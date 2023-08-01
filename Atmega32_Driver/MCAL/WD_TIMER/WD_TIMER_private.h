/*
 * WD_TIMER_private.h
 *
 *  Created on: Apr 13, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_WD_TIMER_WD_TIMER_PRIVATE_H_
#define MACL_WD_TIMER_WD_TIMER_PRIVATE_H_

#define MCUCSR        (*(volatile u8*)(0x54))

#define MCUCSR_PORF   0   /*POWER ON reset flag */
#define MCUCSR_EXTRF  1   /*EXTERNAL reset flag */
#define MCUCSR_BORF   2   /*BROWN-OUT reset flag*/
#define MCUCSR_WDRF   3	  /*WATCH DOG reset flag*/
#define MCUCSR_JTRF   4   /*JTAG reset flag     */


#define WDTCR         (*(volatile u8*)(0x41))

#define WDTCR_WDTOE    4
#define WDTCR_WDE      3
#define WDTCR_WDP2     2
#define WDTCR_WDP1     1
#define WDTCR_WDP0     0





#endif /* MACL_WD_TIMER_WD_TIMER_PRIVATE_H_ */
