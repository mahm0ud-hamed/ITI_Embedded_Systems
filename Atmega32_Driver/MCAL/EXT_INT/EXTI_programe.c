/*
 * EXTI_programe.c
 *
 *  Created on: Mar 30, 2023
 *      Author: Mahmoud Hamed
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_interface.h"


void (*PtrFunc[3])(void)={NULL};
void EXT_INTvoidInit(EXT_INT_info* EXINT_info)
{
	/*check NUM interrupt*/
	if(EXINT_info->INT_NUM == INT1)
	{
		/*check the sense of interrupt */
		switch(EXINT_info->INT_sense)
		{
		case LOWLevel :
			 	    CLR_BIT(MCUCR,MCUCR_ISC10); /*interrupt occur in low level */
				    CLR_BIT(MCUCR,MCUCR_ISC11);
		break ;
		case Anynchange :						/*interrupt occur on any change of pin state level */
					SET_BIT(MCUCR,MCUCR_ISC10);
					CLR_BIT(MCUCR,MCUCR_ISC11);
		break ;

		case FallingEdge :						/*interrupt occur on falling level */
					CLR_BIT(MCUCR,MCUCR_ISC10);
					SET_BIT(MCUCR,MCUCR_ISC11);
		break ;
		case RissingEdge :						/*interrupt occur on rising edge level */
					SET_BIT(MCUCR,MCUCR_ISC10);
					SET_BIT(MCUCR,MCUCR_ISC11);
		break ;
		default :
			// do nothing
		break ;



		}
	}// end of INT1 if condition

	if(EXINT_info->INT_NUM == INT0)
	{
		switch(EXINT_info->INT_sense)
		{
		case LOWLevel :							/*interrupt occur in low level */
			 	    CLR_BIT(MCUCR,MCUCR_ISC00);
				    CLR_BIT(MCUCR,MCUCR_ISC01);
		break ;
		case Anynchange :						/*interrupt occur on any change of pin state level */
					SET_BIT(MCUCR,MCUCR_ISC00);
					CLR_BIT(MCUCR,MCUCR_ISC01);
		break ;

		case FallingEdge :						/*interrupt occur on falling level */
					CLR_BIT(MCUCR,MCUCR_ISC00);
					SET_BIT(MCUCR,MCUCR_ISC01);
		break ;
		case RissingEdge :						/*interrupt occur on rising edge level */
					SET_BIT(MCUCR,MCUCR_ISC00);
					SET_BIT(MCUCR,MCUCR_ISC01);
		break ;
		default :
			// do nothing
		break ;

		}
	}// end of INT1 if condition

	if(EXINT_info->INT_NUM == INT2)
	{
		switch(EXINT_info->INT_sense)
		{
		case FallingEdge :						/*interrupt occur on falling level */
			 	    CLR_BIT(MCUCSR,MCUCSR_ISC2);

		break ;
		case RissingEdge :						/*interrupt occur on rising edge level */
					SET_BIT(MCUCSR,MCUCSR_ISC2);
		break ;

		default :
			// do nothing
		break ;

		}
	}// end of INT2
}

void EXT_INTvoidEnable(EXINT_NUM_t EXTI_NUM)
{
	/*check interrupt number  for enable */
	switch(EXTI_NUM)
	{
	case INT0:
		SET_BIT(GICR,GICR_INT0); /*enable INT0 */
		break ;
	case INT1:
		SET_BIT(GICR,GICR_INT1); /*enable INT1 */
		break ;
	case INT2:
		SET_BIT(GICR,GICR_INT2); /*enable INT2 */
		break ;
	default:
		// do nothing
		break ;
	}
}

void EXT_INTvoidDiable(EXINT_NUM_t EXTI_NUM)
{
	/*check interrupt number  for enable */
	switch(EXTI_NUM)
	{
	case INT0:
		CLR_BIT(GICR,GICR_INT0); /*disable INT0 */
		break ;
	case INT1:
		CLR_BIT(GICR,GICR_INT1); /*disable INT1 */
		break ;
	case INT2:
		CLR_BIT(GICR,GICR_INT2); /*disable INT1 */
		break ;
	default:
		// do nothing
		break ;
	}
}

/*function callback for interrupt0 */
void EXT_INT0voidSetCallBackFunction(void(*func_Name)(void))
{
	if(func_Name != NULL )
	{
		PtrFunc[0]=func_Name;
	}
}

/*function callback for interrupt1 */
void EXT_INT1voidSetCallBackFunction(void(*func_Name)(void))
{
	if(func_Name != NULL )
	{
		PtrFunc[1]=func_Name;
	}
}
/*function callback for interrupt1 */
void EXT_INT2voidSetCallBackFunction(void(*func_Name)(void))
{
	if(func_Name != NULL )
	{
		PtrFunc[2]=func_Name;
	}
}

/*ISR FOR INT0*/
void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	PtrFunc[0]();
}
/*ISR FOR INT1*/
void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
	PtrFunc[1]();
}

/*ISR FOR INT2*/
void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	PtrFunc[2]();
}
