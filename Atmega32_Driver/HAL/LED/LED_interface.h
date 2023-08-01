/*
 * LED_interface.h
 *
 *  Created on: Mar 24, 2023
 *      Author: Mahmoud Hamed
 */
/**********************************************************/
/*        NAME    : MAHMOUD MOHAMED HAMED                 */
/*        Data    : 23 - mars - 2023                      */
/*        Layer   :     HAL                     	      */
/*        MODULE  :  	LEDs                              */
/**********************************************************/
#ifndef HAL_LEDS_LED_INTERFACE_H_
#define HAL_LEDS_LED_INTERFACE_H_
#include "LED_private.h"

LED_ErrState_t LED_ErrStatLedOn(LED_Info_t * Ptr_u8ledinfo);
LED_ErrState_t LED_ErrStatLedInit(LED_Info_t * Ptr_u8ledinfo);
LED_ErrState_t LED_ErrStatLedOFF(LED_Info_t * Ptr_u8ledinfo);

#endif /* HAL_LEDS_LED_INTERFACE_H_ */
