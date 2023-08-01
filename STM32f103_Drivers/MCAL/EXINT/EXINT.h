/*
 * EXINT.h
 *
 *  Created on: Jun 3, 2023
 *      Author: mahmoud hamed
 */

#ifndef EXINT_EXINT_H_
#define EXINT_EXINT_H_

/***************includes****************************/
#include "../LIB/utility.h"
#include "../LIB/STD_TYPES.h"
/***************defines*****************************/

#define EXTI0_MASK     BIT0_MASK
#define EXTI1_MASK     BIT1_MASK
#define EXTI2_MASK     BIT2_MASK
#define EXTI3_MASK     BIT3_MASK
#define EXTI4_MASK     BIT4_MASK
#define EXTI5_MASK     BIT5_MASK
#define EXTI6_MASK     BIT6_MASK
#define EXTI7_MASK     BIT7_MASK
#define EXTI8_MASK     BIT8_MASK
#define EXTI9_MASK     BIT9_MASK
#define EXTI10_MASK    BIT10_MASK
#define EXTI11_MASK    BIT11_MASK
#define EXTI12_MASK    BIT12_MASK
#define EXTI13_MASK    BIT13_MASK
#define EXTI14_MASK    BIT14_MASK
#define EXTI15_MASK    BIT15_MASK

#define ENABLE        1
#define DISABLE       0


#define EXINT_PORTA   0
#define EXINT_PORTB   1
#define EXINT_PORTC   2

enum EXINT_NUM{
	EXTINT0 ,
	EXTINT1 ,
	EXTINT2 ,
	EXTINT3 ,
	EXTINT4 ,
	EXTINT5 ,
	EXTINT6 ,
	EXTINT7 ,
	EXTINT8 ,
	EXTINT9 ,
	EXTINT10,
	EXTINT11,
	EXTINT12 ,
	EXTINT13 ,
	EXTINT14 ,
	EXTINT15 ,
};

/***************  Data Types   **********************/


/*************** Interface function Prototypes **********************/

Err_st EXTI_PinMask( u32 EXINT_NUM , u32 EXINT_PORTx , u32 EXTIx_MASK) ;

Err_st EXTI_EventMask(u32 EXTIx_MASK , u8 EN_DIS) ;

Err_st EXTI_RisingEdgeTrigr(u32 EXTIx_MASK , u8 EN_DIS ) ;

Err_st EXTI_FallingEdgeTrigr(u32 EXTIx_MASK , u8 EN_DIS) ;

Err_st EXTI_OnChangTrigr(u32 EXTIx_MASK , u8 EN_DIS) ;

Err_st  EXTI_SoftWarTrigr(u32 EXTIx_MASK ) ;

Err_st EXTI_CLRPend(u32 EXTIx_MASK) ;

void EXINTx_SetCallBack( u8 EXINT_x , void(*ptr)(void)) ;

#endif /* EXINT_EXINT_H_ */
