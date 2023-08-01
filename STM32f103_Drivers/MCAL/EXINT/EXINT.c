/*
 * EXINT.c
 *
 *  Created on: Jun 3, 2023
 *      Author: Mahmoud Hamed
 */

/************* includes ******************/
#include "EXINT.h"
/****************Defines ******************/
#define EXINT_BASEADD       0x40010400
#define AFIO_EXTINTBASEADD  0x40010008
#define EXINT_LINE_MASK       15
/****************Types *********************/

 /*Registers of EXINT */
typedef struct {
	u32 EXTI_IMR ;
	u32 EXTI_EMR ;
	u32 EXTI_RTSR ;
	u32 EXTI_FTSR ;
	u32 EXTI_SWIER;
	u32 EXTI_PR ;
}EXINT_t ;

/*registers that determine line of EXINT of AFIO  */
typedef struct {
	u32 EXINT[4] ;
}AFIO_t;

/**************** Variables  **************************/

/*pointer to the base address of the interrupt registers on memory */
volatile EXINT_t * const EXINT_ptr = (volatile EXINT_t *)(EXINT_BASEADD);


/*pointer to the base address of line register on AFIO  */
volatile AFIO_t  * const AFIO_ptr  = (volatile AFIO_t  *)(AFIO_EXTINTBASEADD);

/*global array of pointers to function to set call back */
static void (*EXINTx_CallBacK[16])(void) = {NULL} ;


/*********** Static functions Prototypes ************/


/************+*** Interface function implementation **********/


/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : Select port which the INT line , enable pin as interrupt pin   																	  */
/* 2- Function Input                                                                                                                                              */
/*               @param : EXINT_NUM         number of EXINT   		   @ref EXINT_1                                                                               */
/*               @param : EXINT_PORTx       number of pin     		   @ref EXINT_PORTA                                                                           */
/*               @param : EXTIx_MASK        mask of interrupt pin      @ref EXTI0_MASK                                                                            */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (Err_oK)      : The function done successfully                                                                                    */
/*                              (Err_Args )   : The user enter number of PIN more than PORT PINs                                                                  */
/*                              (Err_NULL)    : The user enter number of PORT more than MC PORTs  or negative number                                             */
/*       																												                                          */
/******************************************************************************************************************************************************************/
Err_st EXTI_PinMask( u32 EXINT_NUM , u32 EXINT_PORTx , u32 EXTIx_MASK) {
	// select the line which pin ins connected   to
	u32 Index = EXINT_NUM / 4 ;
	u32 ST_BIT = EXINT_NUM % 4 ;

	u32 Temp  = AFIO_ptr->EXINT[Index] ;
	Temp&=~(EXINT_LINE_MASK<<ST_BIT*4) ;
	Temp|= (EXINT_PORTx << ST_BIT*4 );
	AFIO_ptr->EXINT[Index] = Temp ;
	 // enable pin interrupt
	EXINT_ptr->EXTI_IMR |= EXTIx_MASK ;
	return Err_ok ;
}


/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : Enable event  													   																	  */
/* 2- Function Input                                                                                                                                              */
/*               @param : EXTIx_MASK        mask of interrupt pin      @ref EXTI0_MASK                                                                            */
/*               @param : EN_DIS      	    Select enable or disable    @ref ENABLE                                                                               */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (Err_oK)      : The function done successfully                                                                                    */
/*                              (Err_Args )   : The user enter wrong bit mask                                                              					      */
/*       																												                                          */
/******************************************************************************************************************************************************************/
Err_st EXTI_EventMask(u32 EXTIx_MASK , u8 EN_DIS) {
	if(EN_DIS == ENABLE )
		EXINT_ptr-> EXTI_EMR |= EXTIx_MASK ;

	else if(EN_DIS == DISABLE )
		EXINT_ptr-> EXTI_EMR &= ~ EXTIx_MASK ;
	return Err_ok ;
}


/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : SET interrupt trigger on Rising edge   													   										  */
/* 2- Function Input                                                                                                                                              */
/*               @param : EXTIx_MASK        mask of interrupt pin       @ref EXTI0_MASK                                                                           */
/*               @param : EN_DIS      	    Select enable or disable    @ref ENABLE                                                                               */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (Err_oK)      : The function done successfully                                                                                    */
/*                              (Err_Args )   : The user enter wrong bit mask                                                              					      */
/*       																												                                          */
/******************************************************************************************************************************************************************/
Err_st EXTI_RisingEdgeTrigr(u32 EXTIx_MASK , u8 EN_DIS ) {
	if(EN_DIS == ENABLE ){
		EXINT_ptr-> EXTI_RTSR |= EXTIx_MASK ;
		EXINT_ptr-> EXTI_FTSR &= ~ EXTIx_MASK ;
	}

	else if(EN_DIS == DISABLE )
		EXINT_ptr-> EXTI_RTSR &= ~ EXTIx_MASK ;
	return Err_ok ;
}


/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : SET interrupt trigger on Falling edge   													   										  */
/* 2- Function Input                                                                                                                                              */
/*               @param : EXTIx_MASK        mask of interrupt pin       @ref EXTI0_MASK                                                                           */
/*               @param : EN_DIS      	    Select enable or disable    @ref ENABLE                                                                               */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (Err_oK)      : The function done successfully                                                                                    */
/*                              (Err_Args )   : The user enter wrong bit mask                                                              					      */
/*       																												                                          */
/******************************************************************************************************************************************************************/

Err_st EXTI_FallingEdgeTrigr(u32 EXTIx_MASK , u8 EN_DIS) {
	if(EN_DIS == ENABLE ){
		EXINT_ptr-> EXTI_FTSR |= EXTIx_MASK ;
		EXINT_ptr-> EXTI_RTSR &= ~ EXTIx_MASK ;
	}

	else if(EN_DIS == DISABLE )
		EXINT_ptr-> EXTI_FTSR &= ~ EXTIx_MASK ;
	return Err_ok ;
}


/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : SET interrupt trigger on change 		   													   										  */
/* 2- Function Input                                                                                                                                              */
/*               @param : EXTIx_MASK        mask of interrupt pin       @ref EXTI0_MASK                                                                           */
/*               @param : EN_DIS      	    Select enable or disable    @ref ENABLE                                                                               */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (Err_oK)      : The function done successfully                                                                                    */
/*                              (Err_Args )   : The user enter wrong bit mask                                                              					      */
/*       																												                                          */
/******************************************************************************************************************************************************************/

Err_st EXTI_OnChangTrigr(u32 EXTIx_MASK , u8 EN_DIS) {
	if(EN_DIS == ENABLE ){
		EXINT_ptr-> EXTI_FTSR |= EXTIx_MASK ;
		EXINT_ptr-> EXTI_RTSR |= EXTIx_MASK ;
	}
	else if(EN_DIS == DISABLE ){
			EXINT_ptr-> EXTI_FTSR &= ~ EXTIx_MASK ;
			EXINT_ptr-> EXTI_RTSR &= ~ EXTIx_MASK ;
	}
	return Err_ok ;
}


/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    :Trigger Interrupt by software    													   									      	      */
/* 2- Function Input                                                                                                                                              */
/*               @param : EXTIx_MASK        mask of interrupt pin       @ref EXTI0_MASK                                                                           */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (Err_oK)      : The function done successfully                                                                                    */
/*                              (Err_Args )   : The user enter wrong bit mask                                                              					      */
/*       																												                                          */
/******************************************************************************************************************************************************************/

Err_st  EXTI_SoftWarTrigr(u32 EXTIx_MASK ) {

	EXINT_ptr-> EXTI_SWIER |= EXTIx_MASK ;
	return Err_ok ;
}

/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : Clear pending to clear disable interrupt   													   									  */
/* 2- Function Input                                                                                                                                              */
/*               @param : EXTIx_MASK        mask of interrupt pin       @ref EXTI0_MASK                                                                           */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (Err_oK)      : The function done successfully                                                                                    */
/*                              (Err_Args )   : The user enter wrong bit mask                                                              					      */
/*       																												                                          */
/******************************************************************************************************************************************************************/
Err_st EXTI_CLRPend(u32 EXTIx_MASK) {

	EXINT_ptr-> EXTI_PR |= EXTIx_MASK ;
	return Err_ok ;
}


/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : Assign the address of APP  function to global pointer to function to invoke it when interrupt is triggerd   						  */
/* 2- Function Input                                                                                                                                              */
/*               @param : INT_x        		interrupt Number            @ref EXINT_1                                                                              */
/*               @param : void(*ptr)(void)  Address of Application function     @ref ENABLE                                                                       */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (Err_oK)      : The function done successfully                                                                                    */
/*                              (Err_Args )   : The user enter wrong bit mask                                                              					      */
/*       																												                                          */
/******************************************************************************************************************************************************************/
void EXINTx_SetCallBack( u8 INT_x , void(*ptr)(void)){

	EXINTx_CallBacK[INT_x]= ptr ;
	//return Err_ok ;
}



/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : the ISR function that is Invoked  by hardware when the External interrupt (0) is fired    		  									  */
/* 2- Function Input                                                                                              	                                              */
/*               @param : void        		                                                                       											      */
/*               @param : void                                                                                                                                    */
/* 3- Function Return                                                                                                                                             */
/*              void                                                                                                        								      */
/******************************************************************************************************************************************************************/
void EXTI0_IRQHandler(void){
	EXINTx_CallBacK[0]();
	// Disable interrupt by SW
	EXTI_CLRPend(EXTI0_MASK) ;


}

/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : the ISR function that is Invoked  by hardware when the External interrupt (1) is fired    		  									  */
/* 2- Function Input                                                                                              	                                              */
/*               @param : void        		                                                                       											      */
/*               @param : void                                                                                                                                    */
/* 3- Function Return                                                                                                                                             */
/*              void                                                                                                        								      */
/******************************************************************************************************************************************************************/
void EXTI1_IRQHandler(void){
	EXINTx_CallBacK[1]();
	EXTI_CLRPend(EXTI1_MASK) ;
}

/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : the ISR function that is Invoked  by hardware when the External interrupt (2) is fired    		  									  */
/* 2- Function Input                                                                                              	                                              */
/*               @param : void        		                                                                       											      */
/*               @param : void                                                                                                                                    */
/* 3- Function Return                                                                                                                                             */
/*              void                                                                                                        								      */
/******************************************************************************************************************************************************************/
void EXTI2_IRQHandler(void){
	EXINTx_CallBacK[2]();
	EXTI_CLRPend(EXTI2_MASK) ;
}

/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : the ISR function that is Invoked  by hardware when the External interrupt (3) is fired    		  									  */
/* 2- Function Input                                                                                              	                                              */
/*               @param : void        		                                                                       											      */
/*               @param : void                                                                                                                                    */
/* 3- Function Return                                                                                                                                             */
/*              void                                                                                                        								      */
/******************************************************************************************************************************************************************/
void EXTI3_IRQHandler(void){
	EXINTx_CallBacK[3]();
	EXTI_CLRPend(EXTI3_MASK) ;
}


/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : the ISR function that is Invoked  by hardware when the External interrupt (4) is fired    		  									  */
/* 2- Function Input                                                                                              	                                              */
/*               @param : void        		                                                                       											      */
/*               @param : void                                                                                                                                    */
/* 3- Function Return                                                                                                                                             */
/*              void                                                                                                        								      */
/******************************************************************************************************************************************************************/
void EXTI4_IRQHandler(void){
	EXINTx_CallBacK[4]();
	EXTI_CLRPend(EXTI4_MASK) ;
}



/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : the ISR function that is Invoked  by hardware when the External interrupts (5->9) is fired    		  								  */
/* 2- Function Input                                                                                              	                                              */
/*               @param : void        		                                                                       											      */
/*               @param : void                                                                                                                                    */
/* 3- Function Return                                                                                                                                             */
/*              void                                                                                                        								      */
/******************************************************************************************************************************************************************/
void EXTI9_5_IRQHandler(void){
	if(EXINT_ptr->EXTI_PR & (1<<EXTINT5)){
	EXINTx_CallBacK[5]();
	EXTI_CLRPend(EXTI5_MASK) ;
	}
	else if(EXINT_ptr->EXTI_PR & (1<<EXTINT6)){
	EXINTx_CallBacK[6]();
	EXTI_CLRPend(EXTI6_MASK) ;
	}
	else if(EXINT_ptr->EXTI_PR & (1<<EXTINT7)){
	EXINTx_CallBacK[7]();
	EXTI_CLRPend(EXTI7_MASK) ;
	}
	else if(EXINT_ptr->EXTI_PR & (1<<EXTINT8)){
	EXINTx_CallBacK[8]();
	EXTI_CLRPend(EXTI8_MASK) ;
	}
	else if(EXINT_ptr->EXTI_PR & (1<<EXTINT9)){
	EXINTx_CallBacK[9]();
	EXTI_CLRPend(EXTI9_MASK) ;
	}
}


/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : the ISR function that is Invoked  by hardware when the External interrupts (10->15) is fired    		  							  */
/* 2- Function Input                                                                                              	                                              */
/*               @param : void        		                                                                       											      */
/*               @param : void                                                                                                                                    */
/* 3- Function Return                                                                                                                                             */
/*              void                                                                                                        								      */
/******************************************************************************************************************************************************************/
void EXTI15_10_IRQHandler(void){
	if(EXINT_ptr->EXTI_PR & (1<<EXTINT10)){
	EXINTx_CallBacK[10]();
	EXTI_CLRPend(EXTI10_MASK) ;
	}
	else if(EXINT_ptr->EXTI_PR & (1<<EXTINT11)){
	EXINTx_CallBacK[11]();
	EXTI_CLRPend(EXTI11_MASK) ;
	}
	else if(EXINT_ptr->EXTI_PR & (1<<EXTINT12)){
	EXINTx_CallBacK[12]();
	EXTI_CLRPend(EXTI12_MASK) ;
	}
	else if(EXINT_ptr->EXTI_PR & (1<<EXTINT13)){
	EXINTx_CallBacK[13]();
	EXTI_CLRPend(EXTI13_MASK) ;
	}
	else if(EXINT_ptr->EXTI_PR & (1<<EXTINT14)){
	EXINTx_CallBacK[14]();
	EXTI_CLRPend(EXTI14_MASK) ;
	}
	else if(EXINT_ptr->EXTI_PR & (1<<EXTINT15)){
	EXINTx_CallBacK[15]();
	EXTI_CLRPend(EXTI15_MASK) ;
	}
}

/*********** Static functions Implementation  ************/



