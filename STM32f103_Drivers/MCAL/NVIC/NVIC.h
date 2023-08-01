/*
 * NVIC.h
 *
 *  Created on: May 31, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef NVIC_NVIC_H_
#define NVIC_NVIC_H_


/***************includes****************************/


/***************defines*****************************/

/*the premption and subgroups */
#define GROP_PRI_4G_0SUB  0x03
#define GROP_PRI_3G_1SUB  0x04
#define GROP_PRI_2G_2SUB  0x05
#define GROP_PRI_1G_3SUB  0x06
#define GROP_PRI_0G_0SUB  0x07

/*the interrupts numbers on the vector table */
enum IRQn_VECTABLE{
	WWDG , PVD , TAMPER , RTC , FLASH , RCC , EXTI0 , EXTI1 , EXTI2 , EXTI3,

	EXTI4 , DMA1_Channel1, DMA1_Channel2 , DMA1_Channel3 , DMA1_Channel4 ,DMA1_Channel5,

	DMA1_Channel6 , DMA1_Channel7 ,ADC1_2 , USB_HP_CAN_TX , USB_LP_CAN_RX0 ,

	CAN_RX1 , CAN_SCE , EXTI9_5 ,TIM1_BRK , TIM1_UP , TIM1_TRG_COM , TIM1_CC ,

	TIM2 , TIM3 , TIM4 , I2C1_EV , I2C1_ER , I2C2_EV , I2C2_ER , SPI1 , SPI2 ,

	USART1 , USART2 , USART3 , EXTI15_10 , RTCAlarm , USBWakeup , TIM8_BRK ,TIM8_UP ,

	TIM8_TRG_COM , TIM8_CC , ADC3 , FSMC , SDIO , TIM5, SPI3 , UART4 , UART5 , TIM6 ,

	TIM7 , DMA2_Channel1 , DMA2_Channel2 ,DMA2_Channel3 ,DMA2_Channel4_5
};
/***************  Data Types   **********************/




/*************** Interface function Prototypes **********************/

Err_st NVIC_SetPeriorityGrouping(u32 Group_priority) ;
Err_st NVIC_EnableIRQ(u32 IRQn) ;
Err_st NVIC_DisableIRQ(u32 IRQn) ;
Err_st NVIC_GetPendingIRQ(u32 IRQn , u32* RET_PEND);
Err_st NVIC_SetPendingIRQ(u32 IRQn);
Err_st NVIC_CLRPendingIRQ(u32 IRQn);
Err_st NVIC_GetActive(u32 IRQn , u32* RET_ACTIVE);
Err_st NVIC_SetPeriority(u8 IRQn , u8 Periority );
Err_st NVIC_GetPeriority(u32 IRQn , u32* RET_PER);
Err_st NVIC_TrigerSwIRQn(u32 IRQn ) ;
void   NVIC_SystemReset(void) ;



#endif /* NVIC_NVIC_H_ */
