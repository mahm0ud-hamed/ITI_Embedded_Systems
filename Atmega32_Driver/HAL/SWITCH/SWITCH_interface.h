/*
 * SWITCH_interface.h
 *
 *  Created on: Mar 25, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef HAL_SWITCH_SWITCH_INTERFACE_H_
#define HAL_SWITCH_SWITCH_INTERFACE_H_
#include "SWITCH_private.h"
/*function that read the state of switch and return it */
SwitchEErrState_t SWITCH_SwitchErrorStateGetState(Switch_info_t * Switch, SwitchState_t *Result );

#endif /* HAL_SWITCH_SWITCH_INTERFACE_H_ */
