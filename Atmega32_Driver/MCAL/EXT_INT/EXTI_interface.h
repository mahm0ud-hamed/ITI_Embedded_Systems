/*
 * EXTI_interface.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_EXT_INT_EXTI_INTERFACE_H_
#define MACL_EXT_INT_EXTI_INTERFACE_H_

#include "EXTI_register.h"
#include "EXTI_config.h"

/*function to ini*/
void EXT_INTvoidInit(EXT_INT_info* EXINT_info);

void EXT_INTvoidEnable(EXINT_NUM_t EXTI_NUM);

void EXT_INTvoidDiable(EXINT_NUM_t EXTI_NUM);

void EXT_INT0voidSetCallBackFunction(void(*func_Name)(void));

void EXT_INT1voidSetCallBackFunction(void(*func_Name)(void));

void EXT_INT2voidSetCallBackFunction(void(*func_Name)(void));
#endif /* MACL_EXT_INT_EXTI_INTERFACE_H_ */
