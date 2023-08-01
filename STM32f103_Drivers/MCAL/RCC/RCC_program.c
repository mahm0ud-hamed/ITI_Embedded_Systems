/*
 * RCC_program.c
 *
 *  Created on: May 21, 2023
 *      Author: hp
 */



// includes
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/utility.h"
#include "../../MCAL/RCC/RCC_interface.h"


// defines

#define   RCC_BASEADD    0x40021000


// types

typedef struct{
	volatile u32 RCC_CR ;
	volatile u32 RCC_CFGR ;
	volatile u32 RCC_CIR;
	volatile u32 RCC_APB2RSTR;
	volatile u32 RCC_APB1RSTR;
	volatile u32 RCC_AHBENR;
	volatile u32 RCC_APB2ENR;
	volatile u32 RCC_APB1ENR;
	volatile u32 RCC_BDCR;
	volatile u32 RCC_RCC_CSR;
}RCC_t;




// variables

static volatile RCC_t * const RCC_ptr = (volatile RCC_t * const ) RCC_BASEADD ;


// static function prototype






// interface  function implementation


Err_st RCC_EnableClock(u32 CLK){

	if(CLK > CLK_HSI && CLK<CLK_PLL){
		/*Enable Selected clock bit */
		RCC_ptr->RCC_CR |= CLK ;
	}
	else{
		return Err_Args ;
	}

	return Err_ok;
}

Err_st RCC_SelecSystemClock(u32 CLK){

	//__if(CLK > CLK_HSI && CLK <CLK_PLL){

		switch(CLK){
		case  CLK_HSI :
			RCC_ptr->RCC_CFGR &= (~BIT0_MASK) & (~BIT1_MASK);
			break ;
		case CLK_HSE :
			RCC_ptr->RCC_CFGR &= 0xfffffffc ;
			RCC_ptr->RCC_CFGR |= BIT0_MASK ;
			break ;
		case CLK_PLL :
			RCC_ptr->RCC_CFGR &= 0xfffffffc ;
			RCC_ptr->RCC_CFGR |= BIT1_MASK ;
			break ;
		}
//	}
//	else {
//		return Err_Args ;
//	}
	return Err_ok ;
}

Err_st Rcc_DisableClock(u32 CLK) {

	RCC_ptr ->RCC_CR &=~(CLK);
	return Err_ok ;
}


Err_st RCC_ConfigPllClock(u32 PLL_SRC , u32 Divider , u32 Multiplier){
	Multiplier-=2 ;
	RCC_ptr->RCC_CFGR&=~((u32)15<<18);
	RCC_ptr->RCC_CFGR|=((u32)Multiplier<<18);
	switch(PLL_SRC){
	case PLL_SRC_HSE:
		if(Divider == Divider_2){
			RCC_ptr->RCC_CFGR |= BIT17_MASK ;
		}
		else if (Divider == Divider_1){
			RCC_ptr->RCC_CFGR &= ~BIT17_MASK ;
		}
		RCC_ptr->RCC_CFGR|= BIT16_MASK ;
		break ;
	case PLL_SRC_HSI:
		RCC_ptr->RCC_CFGR&= ~BIT16_MASK ;
		break ;
	}
	return Err_ok ;
}


Err_st RCC_configBusAHBClock(u32 AHB_PreSC) {
	RCC_ptr ->RCC_CFGR&=~(15<<4);
	RCC_ptr ->RCC_CFGR|=(AHB_PreSC<<4);
	return Err_ok ;
}


Err_st RCC_ConfingBusAPBClock(u32 Buss_APPx , u32 APBx_presc ){
	switch(Buss_APPx){
	case Buss_ABP1:
		RCC_ptr ->RCC_CFGR&=~(7<<8);
		RCC_ptr ->RCC_CFGR|=(APBx_presc<<8);
		break ;
	case Buss_ABP2:
		RCC_ptr ->RCC_CFGR&=~(7<<11);
		RCC_ptr ->RCC_CFGR|=(APBx_presc<<11);
		break ;
	}
	return Err_ok;

}

Err_st RCC_ConfigUSBClock(u32 USB_presc){
	RCC_ptr ->RCC_CFGR|=(USB_presc<<22);
	return Err_ok ;
}


Err_st Rcc_EnableABP_1PrepheralClock(u32 ABP1_Preph){
	RCC_ptr ->RCC_APB1ENR |= ABP1_Preph ;
	return Err_ok ;
}

Err_st Rcc_EnableABP_2PrepheralClock(u32 ABP2_Preph){
	RCC_ptr ->RCC_APB2ENR |= ABP2_Preph ;
	return Err_ok ;
}


Err_st Rcc_DisableABP_1PrepheralClock(u32 ABP1_Preph){
	RCC_ptr ->RCC_APB1ENR &= ~(ABP1_Preph) ;
	return Err_ok;
}

Err_st Rcc_DisableABP_2PrepheralClock(u32 ABP2_Preph){
	RCC_ptr ->RCC_APB2ENR &= ~ABP2_Preph ;
	return Err_ok ;
}
// static function implementation






