/*
 * WD_TIMER_interface.h
 *
 *  Created on: Apr 13, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_WD_TIMER_WD_TIMER_INTERFACE_H_
#define MACL_WD_TIMER_WD_TIMER_INTERFACE_H_

typedef enum
{
	WDT_prescale_16,  /*waiting time 16.3 ms*/
	WDT_prescale_32,  /*waiting time 32.5 ms*/
	WDT_prescale_64,  /*waiting time  65 ms */
	WDT_prescale_128, /*waiting time .13 s  */
	WDT_prescale_256, /*waiting time .26 s  */
	WDT_prescale_512, /*waiting time .52 s  */
	WDT_prescale_1024,/*waiting time  1  s  */
	WDT_prescale_2048 /*waiting time 2.1 s  */
}WDT_PRESCALER;

/*function to enable watch dog timer */
void WDT_voidWatchDogSleep(WDT_PRESCALER prescaler);

/*function to disable watch dog timer*/
void WDT_voidDisable(void);
#endif /* MACL_WD_TIMER_WD_TIMER_INTERFACE_H_ */
