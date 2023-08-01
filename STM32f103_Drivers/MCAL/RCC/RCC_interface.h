/*
 * RCC_interface.h
 *
 *  Created on: May 21, 2023
 *      Author: hp
 */
#ifndef RCC_RCC_INTERFACE_H_
#define RCC_RCC_INTERFACE_H_


// includes

#include "../../LIB/utility.h"


// defines

#define CLK_HSI  BIT0_MASK
#define CLK_HSE  BIT16_MASK
#define CLK_PLL	 BIT24_MASK

#define PLL_SRC_HSI        0
#define PLL_SRC_HSE        1

#define Divider_1          0
#define Divider_2          1

#define Buss_AHB           0
#define Buss_ABP1          1
#define Buss_ABP2          2

#define AHB_PreSC_1        0
#define AHB_PreSC_2        8
#define AHB_PreSC_4        9
#define AHB_PreSC_8        10
#define AHB_PreSC_16       11
#define AHB_PreSC_64       12
#define AHB_PreSC_128      13
#define AHB_PreSC_256      14
#define AHB_PreSC_512      15

#define APBx_preSC_1        0
#define APBx_preSC_2        4
#define APBx_preSC_4        5
#define APBx_preSC_8        6
#define APBx_preSC_16       7

#define USB_preSC_1         0
#define USB_preSC_1_5       1




#define ABP2_PREPH_UART1   BIT14_MASK
#define ABP2_PREPH_SPI1    BIT12_MASK
#define ABP2_PREPH_TIM1    BIT11_MASK
#define ABP2_PREPH_ADC2    BIT10_MASK
#define ABP2_PREPH_ADC1    BIT9_MASK
#define ABP2_PREPH_IOPA    BIT2_MASK
#define ABP2_PREPH_IOPB    BIT3_MASK
#define ABP2_PREPH_IOPC    BIT4_MASK
#define ABP2_PREPH_AFIO    BIT0_MASK



#define ABP1_PREPH_TIM2   BIT0_MASK
#define ABP1_PREPH_TIM3   BIT1_MASK
#define ABP1_PREPH_TIM4   BIT2_MASK
#define ABP1_PREPH_UART2  BIT17_MASK
#define ABP1_PREPH_UART3  BIT18_MASK
#define ABP1_PREPH_SPI2   BIT14_MASK
#define ABP1_PREPH_I2C1   BIT21_MASK
#define ABP1_PREPH_I2C2   BIT22_MASK










enum prepheral{
	GPIO ,
	UART

};



// data types



/************ interface function prototype ****************/

Err_st RCC_EnableClock(u32 CLK);
Err_st RCC_SelecSystemClock(u32 CLK);
Err_st Rcc_DisableClock(u32 CLK) ;
Err_st RCC_ConfigPllClock(u32 PLL_SRC , u32 Divider , u32 Multiplier);
Err_st RCC_configBusAHBClock(u32 AHB_PreSC) ;
Err_st RCC_ConfingBusAPBClock(u32 Buss_APPx , u32 APBx_presc );
Err_st RCC_ConfigUSBClock(u32 USB_presc);
Err_st Rcc_EnableABP_1PrepheralClock(u32 ABP1_Preph);
Err_st Rcc_EnableABP_2PrepheralClock(u32 ABP2_Preph);
Err_st Rcc_DisableABP_1PrepheralClock(u32 ABP1_Preph);
Err_st Rcc_DisableABP_2PrepheralClock(u32 ABP2_Preph);

/************************************************************/


#endif /* RCC_RCC_INTERFACE_H_ */
