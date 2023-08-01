/*
 * WD_TIMER_program.c

 *
 *  Created on: Apr 13, 2023
 *      Author: Mahmoud Hamed
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "WD_TIMER_private.h"
#include "WD_TIMER_interface.h"

void WDT_voidWatchDogSleep(WDT_PRESCALER prescaler)
{
	/*select prescale */
	WDTCR &=0b00010000;   /*set all bit for prescaler as zeros*/
	WDTCR |=prescaler ; /*BIT masking the presacler Bits to selected presacler */

	/*watch dog enable */
	SET_BIT(WDTCR,WDTCR_WDE);
}

void WDT_voidDisable(void)
{
	/*on the same operation  write logic one to WDTOE ND WDE*/
	WDTCR |= 0b00011000;
	/*assign all register to zero */
	WDTCR = 0x00 ;
}
