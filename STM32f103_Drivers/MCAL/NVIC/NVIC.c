/*
 * NVIC.c
 *
 *  Created on: May 31, 2023
 *      Author: Mahmoud Hamed
 */
/**************** Includes ****************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/utility.h"

#include "NVIC.h"

/****************Defines ******************/

#define NVIC_BASEADDRESS          0xE000E100
#define SYSCRLBLOCK_BASEADDRESS   0xE000ED00
#define SCB_AIRCR_PASS            (0x0FA05)
#define AIRCR_PASS_LEN              16
#define GROP_PRI_MASK               0x07
#define GROP_PRI_LEN                 8
#define PASS_MASK                  0xffff0000
/****************Types *********************/

typedef struct {
	u32 NVIC_ISER[2] ;
	u32 RESREVED0[30];
	u32 NVIC_ICER[2] ;
	u32 RESERVED1[30];
	u32 NVIC_ISPR[2] ;
	u32 RESERVED2[30];
	u32 NVIC_ICPR[2] ;
	u32 RESERVED3[30];
	u32 NVIC_IABR[2] ;
	u32 RESERVED4[62];
	u8  NVIC_IPR[81] ;
	u32 RESERVED5[696];
	u32 NVIC_STIR ;
}NVIC_t;


typedef struct {
	u32 SCB_CPUID ;
	u32 SCB_ICSR  ;
	u32 SCB_VTOR  ;
	u32 SCB_AIRCR ;
	u32 SCB_SCR   ;
	u32 SCB_CCR   ;
	u32 SCB_SHPR1 ;
	u32 SCB_SHPR2 ;
	u32 SCB_SHPR3 ;
	u32 SCB_SHCRS ;
	u32 SCB_CFSR  ;
	u32 SCB_HFSR  ;
	u32 SCB_MMAR  ;
	u32 SCB_BFAR  ;
}SCB_t;
/**************** Variables  **************************/

 volatile NVIC_t* const NVIC_ptr = ((volatile NVIC_t*)NVIC_BASEADDRESS);

volatile SCB_t  * const  SCB_ptr = ((volatile SCB_t *)SYSCRLBLOCK_BASEADDRESS) ;

/*********** Static functions Prototypes ************/


/********** Interface Function Implementation  *********/



/******************************************************************************************************************************************************************/
/* 1- Function Description                                                                                                                                        */
/*               @brief    : SET the preemption  Bits and the subgroups Bits    											   									  */
/* 2- Function Input                                                                                                                                              */
/*               @param : Group_priority        /****nees to edit 					                                                                              */
/*                                                                                           																      */
/* 3- Function Return                                                                                                                                             */
/*               @return Error status of the function                                                                                                             */
/*                              (Err_oK)      : The function done successfully                                                                                    */
/*                              (Err_Args )   : The user enter wrong bit mask                                                              					      */
/*       																												                                          */
/******************************************************************************************************************************************************************/
Err_st NVIC_SetPeriorityGrouping(u32 Group_priority){

	if((Group_priority >= GROP_PRI_4G_0SUB)  &&   (Group_priority <= GROP_PRI_0G_0SUB) ){
		u32 Temp = SCB_ptr ->SCB_AIRCR;
		Temp &= ~(PASS_MASK << AIRCR_PASS_LEN)     ;
		Temp |= (SCB_AIRCR_PASS << AIRCR_PASS_LEN) ;
		Temp &= ~(GROP_PRI_MASK << GROP_PRI_LEN )  ;
		Temp |= (Group_priority << GROP_PRI_LEN )  ;
		SCB_ptr ->SCB_AIRCR = Temp                 ;
	}
	else {
		return Err_Args;
	}
	return Err_ok ;
}


Err_st NVIC_EnableIRQ(u32 IRQn){

	if(IRQn >= WWDG && IRQn <= DMA2_Channel4_5 ){
		NVIC_ptr->NVIC_ISER[IRQn / 32] |= (1U << IRQn % 32);
	}
	else {
		return Err_Args ;
	}
	return Err_ok ;
}


Err_st NVIC_DisableIRQ(u32 IRQn) {

	if(IRQn >= WWDG && IRQn <= DMA2_Channel4_5 ){
		NVIC_ptr->NVIC_ICER[IRQn / 32] |= (1U << IRQn % 32);
	}
	else {
		return Err_Args ;
	}
	return Err_ok ;
}


Err_st NVIC_GetPendingIRQ(u32 IRQn , u32* RET_PEND){
	Err_st Er_st = Err_ok  ;
	if(IRQn >= WWDG && IRQn <= DMA2_Channel4_5 ){
		if(RET_PEND != NULL ){
			*RET_PEND = (NVIC_ptr->NVIC_ISPR[IRQn / 32] >>(IRQn % 32)) & 1;
		}
		else {
			Er_st=  Err_NULL ;
		}
	}
	else {
		Er_st =  Err_Args ;
	}
	return Er_st ;

}

Err_st NVIC_SetPendingIRQ(u32 IRQn){
	if(IRQn >= WWDG && IRQn <= DMA2_Channel4_5 ){
		NVIC_ptr->NVIC_ISPR[IRQn / 32] |=(1U << IRQn % 32) ;
	}
	else {
		return Err_Args  ;
	}
	return Err_ok ;
}

Err_st NVIC_CLRPendingIRQ(u32 IRQn){
	if(IRQn >= WWDG && IRQn <= DMA2_Channel4_5 ){
		NVIC_ptr->NVIC_ICPR[IRQn / 32] |=(1U << IRQn % 32) ;
	}
	else {
		return Err_Args  ;
	}
	return Err_ok ;
}


Err_st NVIC_GetActive(u32 IRQn , u32* RET_ACTIVE){
	Err_st Er_st = Err_ok  ;
	if(IRQn >= WWDG && IRQn <= DMA2_Channel4_5 ){
		if(RET_ACTIVE != NULL){
			*RET_ACTIVE = (NVIC_ptr->NVIC_IABR[IRQn / 32] >>(IRQn % 32)) & 1;
		}
		else{
			Er_st = Err_NULL ;
		}

	}
	else {
		Er_st = Err_Args ;
	}
	return Er_st ;
}


Err_st NVIC_SetPeriority(u8 IRQn , u8 Periority ){
	if(IRQn >= WWDG && IRQn <= DMA2_Channel4_5 ){
		NVIC_ptr->NVIC_IPR[IRQn] = (Periority << 4);
	}
	else {
		return Err_Args ;
	}
	return Err_ok ;
}

Err_st NVIC_GetPeriority(u32 IRQn , u32* RET_PER){
	Err_st Er_st = Err_ok  ;
	if(IRQn >= WWDG && IRQn <= DMA2_Channel4_5 ){
		if(RET_PER!=NULL){
			* RET_PER = NVIC_ptr->NVIC_IPR[IRQn] ;
		}
		else {
			Er_st = Err_NULL ;
		}
	}
	else {
		Er_st = Err_Args ;
	}
	return Er_st ;
}


Err_st NVIC_TrigerSwIRQn(u32 IRQn ) {
	if(IRQn >= WWDG && IRQn <= DMA2_Channel4_5 ){
		u32 Temp = NVIC_ptr->NVIC_STIR ;
		Temp &=(u8)(0) ;
		Temp|= IRQn ;
		NVIC_ptr->NVIC_STIR =Temp;
	}
	else {
		return Err_Args ;
	}
	return Err_ok ;
}


/*********** Static functions Implementation  ************/
