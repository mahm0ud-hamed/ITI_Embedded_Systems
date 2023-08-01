/*
 * GIE_program.c
 *
 *  Created on: Mar 30, 2023
 *      Author: Mahmoud Hamed
 */

#include "GIE_register.h"
#include"GIE_interface.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

void GIE_voidGeneraLINTEnable(void)
{
	/*set general interrupt enable bit on status register*/
	SET_BIT(SREG,SREG_GEI);
}

void GIE_voidGeneralINTDisable(void)
{
	/*set general interrupt enable bit on status register*/
	CLR_BIT(SREG,SREG_GEI);
}
