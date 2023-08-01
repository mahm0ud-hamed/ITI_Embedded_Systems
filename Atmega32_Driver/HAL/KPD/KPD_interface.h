/*
 * KPD_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_
#include "KPD_private.h"
#include "KPD_config.h"

/*function to initiate KPD pins*/
void KPD_ErrStateInit(void);

/*function to read the value of the pressed key on KPD*/
KPD_ErrState_t KPD_ErrStateGetPressedKey( u8 * copy_u8GetValue);

KPD_ErrState_t KPD_ErrStateGetPressedValue( u16 * copy_u8GetValue);

#endif /* HAL_KPD_KPD_INTERFACE_H_ */
