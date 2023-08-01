/*
 * GPIO_.c
 *
 *  Created on: May 24, 2023
 *      Author: hp
 */


/*********** includes **********/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/utility.h"
#include "../../MCAL/GPIO/GPIO_inteface.h"
/**************************************/

/************ defines **********/
#define GPIO_PORTA_BASEADD  (0x40010800)
#define GPIO_PORTB_BASEADD  (0x40010C00)
#define GPIO_PORTC_BASEADD  (0x40011000)

#define MODE_MASK   0x03
#define CONFG_MASK  0x03
#define MODE_SHIFT  4
#define RESET_SHIFT 16
#define CRH_OFFSET  8
/**************************************/

/************  types  **********/
/*GPIO priepheral  memory */
typedef struct{
	u32 GPIO_CRL;
	u32 GPIO_CRH;
	u32 GPIO_IDR;
	u32 GPIO_ODR;
	u32 GPIO_BSRR;
	u32 GPIO_BRR;
	u32 GPIO_LCKR;
}GPIOx_t;
/***************************************/

/*************** variables *************/
/*pointers to the base address of the GPIOS prephieral */
volatile GPIOx_t * const GPIOA_ptr = (volatile GPIOx_t *)(0x40010800) ;
volatile GPIOx_t * const GPIOB_ptr = (volatile GPIOx_t *)(0x40010C00) ;
volatile GPIOx_t * const GPIOC_ptr = (volatile GPIOx_t *)(0x40011000) ;

/****** static function prototype****/


/****** interface function implementation *******/

Err_st GPIO_SetPinOutPut(u32 PORT_x , u32 PIN_x , u32 PinOutSpeed , u32 PinOutConfg ){
	u32 Temp =0 ;
	if(PIN_x < PIN_8){
		switch(PORT_x){
		case PORT_A :
			Temp=GPIOA_ptr->GPIO_CRL;
			Temp &=(~(MODE_MASK<<(PIN_x * MODE_SHIFT))) & (~(CONFG_MASK<<(PIN_x * MODE_SHIFT + 2 ))) ;
			Temp |= (PinOutSpeed<<(PIN_x * MODE_SHIFT)) | (PinOutConfg<<(PIN_x * MODE_SHIFT + 2)) ;
			GPIOA_ptr->GPIO_CRL = Temp ;
			break;
		case PORT_B :
			Temp=GPIOB_ptr->GPIO_CRL;
			Temp &=(~(MODE_MASK<<(PIN_x * MODE_SHIFT))) & (~(CONFG_MASK<<(PIN_x * MODE_SHIFT + 2 ))) ;
			Temp |= (PinOutSpeed<<(PIN_x * MODE_SHIFT)) | (PinOutConfg<<(PIN_x * MODE_SHIFT + 2)) ;
			GPIOB_ptr->GPIO_CRL = Temp ;
			break;
		case PORT_C :
			Temp=GPIOC_ptr->GPIO_CRL;
			Temp &=(~(MODE_MASK<<(PIN_x * MODE_SHIFT))) & (~(CONFG_MASK<<(PIN_x * MODE_SHIFT + 2 ))) ;
			Temp |= (PinOutSpeed<<(PIN_x * MODE_SHIFT)) | (PinOutConfg<<(PIN_x * MODE_SHIFT + 2)) ;
			GPIOC_ptr->GPIO_CRL = Temp ;
			break;
		}// end of switch
	}else if (PIN_x >= PIN_8){
		switch(PORT_x){
		case PORT_A :
			Temp=GPIOA_ptr->GPIO_CRH;
			Temp &=(~(MODE_MASK<<((PIN_x-CRH_OFFSET) * MODE_SHIFT))) & (~(CONFG_MASK<<((PIN_x-CRH_OFFSET) * MODE_SHIFT + 2 ))) ;
			Temp |= (PinOutSpeed<<((PIN_x-CRH_OFFSET) * MODE_SHIFT)) | (PinOutConfg<<((PIN_x-CRH_OFFSET) * MODE_SHIFT + 2)) ;
			GPIOA_ptr->GPIO_CRH = Temp ;
			break;
		case PORT_B :
			Temp=GPIOB_ptr->GPIO_CRH;
			Temp &=(~(MODE_MASK<<((PIN_x-CRH_OFFSET) * MODE_SHIFT))) & (~(CONFG_MASK<<((PIN_x-8) * MODE_SHIFT + 2 ))) ;
			Temp |= (PinOutSpeed<<((PIN_x-CRH_OFFSET) * 4)) | (PinOutConfg<<((PIN_x-CRH_OFFSET) * MODE_SHIFT + 2)) ;
			GPIOB_ptr->GPIO_CRH = Temp ;
			break;
		case PORT_C :
			Temp=GPIOC_ptr->GPIO_CRH;
			Temp &=(~(MODE_MASK<<((PIN_x-CRH_OFFSET) * MODE_SHIFT))) & (~(CONFG_MASK<<((PIN_x-CRH_OFFSET) * MODE_SHIFT + 2 ))) ;
			Temp |= (PinOutSpeed<<((PIN_x-CRH_OFFSET) * 4)) | (PinOutConfg<<((PIN_x-CRH_OFFSET) * MODE_SHIFT + 2)) ;
			GPIOC_ptr->GPIO_CRH = Temp ;
			break;
		}// end of switch
	}
	return Err_ok ;
}

Err_st GPIO_SetPinInput(u32 PORT_x , u32 PIN_x , u32 PinInpConfg ){
	u32 Temp = 0 ;
	if(PIN_x < PIN_8){
		switch (PORT_x){
		case PORT_A :
			Temp = GPIOA_ptr-> GPIO_CRL ;
			Temp &=(~(MODE_MASK<<(PIN_x * MODE_SHIFT))) & (~(CONFG_MASK<<(PIN_x * MODE_SHIFT + 2 ))) ;
			Temp |= (PinInpConfg<<PIN_x*MODE_SHIFT+2);
			GPIOA_ptr-> GPIO_CRL = Temp;
			break ;
		case PORT_B :
			Temp = GPIOB_ptr-> GPIO_CRL ;
			Temp &=(~(MODE_MASK<<(PIN_x * MODE_SHIFT))) & (~(CONFG_MASK<<(PIN_x * MODE_SHIFT + 2 ))) ;
			Temp |= (PinInpConfg<<PIN_x*MODE_SHIFT+2);
			GPIOB_ptr-> GPIO_CRL = Temp;
			break ;
		case PORT_C :
			Temp = GPIOC_ptr-> GPIO_CRL ;
			Temp &=(~(MODE_MASK<<(PIN_x * MODE_SHIFT))) & (~(CONFG_MASK<<(PIN_x * MODE_SHIFT + 2 ))) ;
			Temp |= (PinInpConfg<<PIN_x*MODE_SHIFT+2);
			GPIOC_ptr-> GPIO_CRL = Temp;
			break ;
		}// end of switch
	}
	else if(PIN_x >= PIN_8){
		switch (PORT_x){
		case PORT_A :
			Temp = GPIOA_ptr-> GPIO_CRL ;
			Temp &=(~(MODE_MASK<<((PIN_x-CRH_OFFSET) * MODE_SHIFT))) & (~(CONFG_MASK<<((PIN_x-CRH_OFFSET) * MODE_SHIFT + 2 ))) ;
			Temp |= (PinInpConfg<<(PIN_x-CRH_OFFSET)*MODE_SHIFT+2);
			GPIOA_ptr-> GPIO_CRL = Temp;
			break ;
		case PORT_B :
			Temp = GPIOB_ptr-> GPIO_CRL ;
			Temp &=(~(MODE_MASK<<((PIN_x-CRH_OFFSET) * MODE_SHIFT))) & (~(CONFG_MASK<<((PIN_x-CRH_OFFSET) * MODE_SHIFT + 2 ))) ;
			Temp |= (PinInpConfg<<(PIN_x-CRH_OFFSET)*MODE_SHIFT+2);
			GPIOB_ptr-> GPIO_CRL = Temp;
			break ;
		case PORT_C :
			Temp = GPIOC_ptr-> GPIO_CRL ;
			Temp &=(~(MODE_MASK<<((PIN_x-CRH_OFFSET) * MODE_SHIFT))) & (~(CONFG_MASK<<((PIN_x-CRH_OFFSET) * MODE_SHIFT + 2 ))) ;
			Temp |= (PinInpConfg<<(PIN_x-CRH_OFFSET)*MODE_SHIFT+2);
			GPIOC_ptr-> GPIO_CRL = Temp;
			break ;
		}// end of switch
	}
	return Err_ok;
}

Err_st GPIO_GetPinValue(u32 PORT_x , u32 PIN_x , u32 * PIN_RET_VAL ){
	switch (PORT_x){
	case PORT_A :
		*PIN_RET_VAL = (GPIOA_ptr->GPIO_ODR >> PIN_x)&(0x01);
		break;
	case PORT_B :
		*PIN_RET_VAL = (GPIOB_ptr->GPIO_IDR >> PIN_x)&(0x01);
		break ;
	case PORT_C :
		*PIN_RET_VAL = (GPIOB_ptr->GPIO_IDR >> PIN_x)&(0x01);
		break;
	}
	return Err_ok ;
}


Err_st GPIO_SetPortValue(u32 PORT_x , u32 PORT_VALUE){
	switch (PORT_x){
	case PORT_A :
		GPIOA_ptr->GPIO_ODR = PORT_VALUE ;
		break;
	case PORT_B :
		GPIOB_ptr->GPIO_ODR = PORT_VALUE ;
		break ;
	case PORT_C :
		GPIOC_ptr->GPIO_ODR = PORT_VALUE ;
		break;
	}
	return Err_ok ;
}


Err_st GPIO_GetPortValue(u32 PORT_x , u32 *PORT_RET_VALUE ){
	switch (PORT_x){
	case PORT_A :
		*PORT_RET_VALUE = GPIOA_ptr->GPIO_ODR ;
		break ;
	case PORT_B :
		*PORT_RET_VALUE = GPIOB_ptr->GPIO_ODR ;
		break ;
	case PORT_C :
		*PORT_RET_VALUE = GPIOC_ptr->GPIO_ODR ;
		break ;
	default :
		return Err_Args ;
		break ;
	}
	return  Err_ok ;
}


Err_st GPIO_ResetPinValue(u32 PORT_x , u32 PIN_x ){
	switch(PORT_x){
	case PORT_A :
		GPIOA_ptr->GPIO_BRR |=(1<<PIN_x); break ;
	case PORT_B :
		GPIOB_ptr->GPIO_BRR |=(1<<PIN_x); break ;
	case PORT_C :
		GPIOC_ptr->GPIO_BRR |=(1<<PIN_x); break ;
	default :
		return Err_Args ;
		break;
	}
	return Err_ok ;
}


Err_st GPIO_SetPinValue(u32 PORT_x , u32 PIN_X , u32 PIN_VAL){
	if(PIN_VAL == PIN_VAL_HIGH){
		switch (PORT_x){
		case PORT_A :
			GPIOA_ptr->GPIO_ODR |=(1<<PIN_X); break;
		case PORT_B :
			GPIOB_ptr->GPIO_ODR |=(1<<PIN_X); break;
		case PORT_C :
			GPIOC_ptr->GPIO_ODR |=(1<<PIN_X); break;
		default :
			return Err_Args ;
		}// end of switch case
	}
	else if(PIN_VAL == PIN_VAL_LOW){
		switch (PORT_x){
		case PORT_A :
			GPIOA_ptr->GPIO_ODR &=~(1<<PIN_X); break;
		case PORT_B :
			GPIOB_ptr->GPIO_ODR &=~(1<<PIN_X); break;
		case PORT_C :
			GPIOC_ptr->GPIO_ODR &=~(1<<PIN_X); break;
		default :
			return Err_Args ;
		}// end of switch case
	}
	return Err_ok;
}




/****** static function implementation  *********/

