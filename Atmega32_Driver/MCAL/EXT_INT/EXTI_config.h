/*
 * EXTI_config.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_EXT_INT_EXTI_CONFIG_H_
#define MACL_EXT_INT_EXTI_CONFIG_H_


typedef enum
{
	INT0,
	INT1,
	INT2
}EXINT_NUM_t;

typedef enum
{

	RissingEdge,
	FallingEdge,
	LOWLevel,
	Anynchange
}EXINT_NUM_Sense;

typedef struct
{
	EXINT_NUM_t    INT_NUM ;
	EXINT_NUM_Sense INT_sense ;

}EXT_INT_info;

#endif /* MACL_EXT_INT_EXTI_CONFIG_H_ */
