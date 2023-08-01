/*
 * TIMER0_interface.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_TIMER_TIMER_INTERFACE_H_
#define MACL_TIMER_TIMER_INTERFACE_H_

#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_register.h"

/*function description
 * to set input capture unit compare match value */
void TIMER_voidSetICUCompValue(u16 copy_u16ICR1Value);

/*function description
 * to enable interrupt of timers  */
void TIMER_voidInterruptEnable( TimerInterrupt Interrupt);

/*function description
 * to set input capture unit compare match value */
void TIMER_voidInterruptDisable( TimerInterrupt Interrupt);

/*function description
 * to initialize timer  */
void TIMER_voidInit(TIMER_NUM copy_timer , TIMER_MODE_t copy_Mode , TIMER_PRESCALER_t copu_prescaler , TIMER_Compare_Mode copy_OutCompMode);

/*function description
 * to set input preloaded value of timer  */
void TIMER_voidSetTimerPreLoadValue(TIMER_NUM copy_timer, u16 copy_u16TCNTValue);
void TIMER_voidSetTimerCompareValue(TIMER_NUM copy_timer, u16 copy_u16OCRValue);
u8 TIMER_u8SetCallBack(TimerInterrupt Interrupt,void(*Copy_pvPtr_Func)(void));
#endif /* MACL_TIMER_TIMER_INTERFACE_H_ */
