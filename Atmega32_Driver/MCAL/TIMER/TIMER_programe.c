/*

 * TIMER0_programe.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Mahmoud Hamed
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "TIMER_interface.h"

static void (*TIMER_PvCallBack[8])(void)= {NULL};

void TIMER_voidInit(TIMER_NUM copy_timer , TIMER_MODE_t copy_Mode , TIMER_PRESCALER_t copy_prescaler , TIMER_Compare_Mode copy_OutCompMode)
{
	u8 Local_u8Timer1ModeTEMP=0;
	switch(copy_timer)
	{
	case Timer0:
	{
		/** select wave generation mode**/
		TCCR0&=0b10110111;
		TCCR0|=copy_Mode;  /*bit masking for */

		/**SELECT PRESCALER**/
		TCCR0&=0b11111000;
		TCCR0|=copy_prescaler;

		/**SELECT OUTCOMPARE MODE **/
		/*shit mode number by 4 bits to set the 4th bit and 5th bit to selct compare mode */
		TCCR0&=0b11001111;
		TCCR0|=copy_OutCompMode<<4;
		/*disable interrupts */
		CLR_BIT(TIMSK,TIMSK_TOIE0);
		CLR_BIT(TIMSK,TIMSK_OCIE0);
		/*clear flag */
		SET_BIT(TIFR,TIFR_TOV0);
		SET_BIT(TIFR,TIFR_OCF0);
		/*clear timer zero counter register */
		TCNT0= 0 ;
		break ;
	}
	case Timer1A:
	{
		/*to select mode in two different registers with one value
		 * we split the value always consist of 4 bits so we take the first two bit for one
		 * register and the second two bits for the other register */
		Local_u8Timer1ModeTEMP = (copy_Mode & 0b00000011)  ;
		/** select wave generation mode**/
		TCCR1A&=0b11111100;
		TCCR1A|=Local_u8Timer1ModeTEMP;  /*bit masking for */
		Local_u8Timer1ModeTEMP = (copy_Mode & 0b00001100)  ;
		TCCR1B&=0b11100111;
		TCCR1B|=(Local_u8Timer1ModeTEMP<<1);  /*bit masking for */


		/**SELECT PRESCALER**/
		TCCR1B&=0b11111000;
		TCCR1B|=copy_prescaler;

		/**SELECT OUTCOMPARE MODE **/
		/*shit mode number by 4 bits to set the 4th bit and 5th bit to select compare mode */
		TCCR1A&=0b00111111;
		TCCR1A|=copy_OutCompMode<<6;
		/*disable interrupts */
		CLR_BIT(TIMSK,TIMSK_TOIE1);
		CLR_BIT(TIMSK,TIMSK_OCIE1A);
		/*clear flags*/
		SET_BIT(TIFR,TIFR_TOV1);
		SET_BIT(TIFR,TIFR_OCF1A);
		/*clear timer zero counter register */
		TCNT1= 0 ;
		break ;
	}
	case Timer1B:
	{
		/*to select mode in two different registers with one value
		 * we split the value always consist of 4 bits so we take the first two bit for one
		 * register and the second two bits for the other register */
		Local_u8Timer1ModeTEMP = (copy_Mode & 0b00000011)  ;
		/** select wave generation mode**/
		TCCR1A&=0b11111100;
		TCCR1A|=Local_u8Timer1ModeTEMP;  /*bit masking for */
		Local_u8Timer1ModeTEMP = (copy_Mode & 0b00001100)  ;
		TCCR1B&=0b11100111;
		TCCR1B|=(Local_u8Timer1ModeTEMP<<1);  /*bit masking for */


		/**SELECT PRESCALER**/
		TCCR1B&=0b11111000;
		TCCR1B|=copy_prescaler;

		/**SELECT OUTCOMPARE MODE **/
		/*shit mode number by 4 bits to set the 4th bit and 5th bit to selct compare mode */
		TCCR1A&=0b11001111;
		TCCR1A|=copy_OutCompMode<<4;
		/*disable interrupts */
		CLR_BIT(TIMSK,TIMSK_TOIE1);
		CLR_BIT(TIMSK,TIMSK_OCIE1B);
		/*clear flags*/
		SET_BIT(TIFR,TIFR_TOV1);
		SET_BIT(TIFR,TIFR_OCF1B);
		/*clear timer zero counter register */
		TCNT1= 0 ;
		break ;
	}
	case Timer2:
	{
		/** select wave generation mode**/
		TCCR2&=0b10110111;
		TCCR2|=copy_Mode;  /*bit masking for */

		/**SELECT PRESCALER**/
		TCCR2&=0b11111000;
		TCCR2|=copy_prescaler;

		/**SELECT OUTCOMPARE MODE **/
		/*shit mode number by 4 bits to set the 4th bit and 5th bit to selct compare mode */
		TCCR2&=0b11001111;
		TCCR2|=copy_OutCompMode<<4;
		/*disable interrupts */
		CLR_BIT(TIMSK,TIMSK_TOIE2);
		CLR_BIT(TIMSK,TIMSK_OCIE2);
		/*clear timer two counter register */
		TCNT2= 0 ;
		break ;
	}
	case Timer1_ICU:
	{
		/*to select mode in two different registers with one value
		 * we split the value always consist of 4 bits so we take the first two bit for one
		 * register and the second two bits for the other register */
		Local_u8Timer1ModeTEMP = (copy_Mode & 0b00000011)  ;
		/** select wave generation mode**/
		TCCR1A&=0b11111100;
		TCCR1A|=Local_u8Timer1ModeTEMP;  /*bit masking for */
		Local_u8Timer1ModeTEMP = (copy_Mode & 0b00001100)  ;
		TCCR1B&=0b11111100;
		TCCR1B|=(Local_u8Timer1ModeTEMP<<1);  /*bit masking for */


		/**SELECT PRESCALER**/
		TCCR1B&=0b11111000;
		TCCR1B|=copy_prescaler;

		/**SELECT OUTCOMPARE MODE **/
		/*shit mode number by 4 bits to set the 4th bit and 5th bit to selct compare mode */
		TCCR1A&=0b00111111;
		TCCR1A|=copy_OutCompMode<<6;
		/*disable interrupts */
		CLR_BIT(TIMSK,TIMSK_TICIE1);
		/*clear flags*/
		SET_BIT(TIFR,TIFR_ICF1);

		/*initialize the input capture unit */
#if INPUT_CAPTUR_NOISE == ACTIVE
		SET_BIT(TCCR1B,TCCR1B_ICNC1);
#elif INPUT_CAPTUR_NOISE == NOT ACTIVE
		CLR_BIT(TCCR1B,TCCR1B_ICNC1);
#endif
		/*select trigger edge */
#if INPUT_CAPTURE_EDGE == INPUT_CAPTURE_FALLING_EDGE
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
#elif INPUT_CAPTURE_EDGE == INPUT_CAPTURE_RISING_EDGE
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
#endif
		break ;
	}
	default:// do nothing
		break;

	}
}
void TIMER_voidSetTimerPreLoadValue(TIMER_NUM copy_timer, u16 copy_u16TCNTValue)
{
	switch (copy_timer)
	{
	case Timer0  : TCNT0 = copy_u16TCNTValue; break;
	case Timer1A : TCNT1 = copy_u16TCNTValue; break;
	case Timer1B : TCNT1 = copy_u16TCNTValue; break;
	case Timer2  : TCNT2 = copy_u16TCNTValue; break;
	default :// do nothing
		break ;
	}
}
void TIMER_voidSetTimerCompareValue(TIMER_NUM copy_timer, u16 copy_u16OCRValue)
{
	switch (copy_timer)
	{
	case Timer0  : OCR0 = copy_u16OCRValue;  break;
	case Timer1A : OCR1A = copy_u16OCRValue; break;
	case Timer1B : OCR1B = copy_u16OCRValue; break;
	case Timer2  : OCR2 = copy_u16OCRValue;  break;
	default :// do nothing
		break ;
	}
}

void TIMER_voidSetICUCompValue(u16 copy_u16ICR1Value)
{
	ICR1=copy_u16ICR1Value;
}

u8 TIMER_u8SetCallBack(TimerInterrupt Interrupt,void(*Copy_pvPtr_Func)(void))
{
	u8 Local_u8ErrorState =0 ;
	if(Copy_pvPtr_Func!= NULL)
	{
		if(Interrupt<8)
		{
			TIMER_PvCallBack[Interrupt] = Copy_pvPtr_Func ;
		}
		else
		{
			Local_u8ErrorState=1;
		}
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState ;
}

void TIMER_voidInterruptEnable( TimerInterrupt Interrupt)
{
	SET_BIT(TIMSK,Interrupt);
}
void TIMER_voidInterruptDisable( TimerInterrupt Interrupt)
{
	CLR_BIT(TIMSK,Interrupt);
}

/*timer zero overflow interrupt service routine */
void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	if(TIMER_PvCallBack[0]!= NULL)
	{
		TIMER_PvCallBack[0]();
	}
}

/*timer zero compare match interrupt service routine */
void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	if(TIMER_PvCallBack[1]!= NULL)
	{
	TIMER_PvCallBack[1]();
	}
}
/*timer one overflow interrupt service routine */
void __vector_9(void)__attribute__((signal));
void __vector_9(void)
{
	if(TIMER_PvCallBack[2]!= NULL)
	{
	TIMER_PvCallBack[2]();
	}
}
/*timer one channel B compare match interrupt service routine */
void __vector_8(void)__attribute__((signal));
void __vector_8(void)
{
	if(TIMER_PvCallBack[3]!= NULL)
	{
	TIMER_PvCallBack[3]();
	}
}
/*timer one channel A  compare match interrupt service routine */
void __vector_7(void)__attribute__((signal));
void __vector_7(void)
{
	if(TIMER_PvCallBack[4]!= NULL)
	{
	TIMER_PvCallBack[4]();
	}
}


/*timer one capture event  interrupt service routine */
void __vector_6(void)__attribute__((signal));
void __vector_6(void)
{
	if(TIMER_PvCallBack[5]!= NULL)
	{
	TIMER_PvCallBack[5]();
	}
}
/*timer two overflow   interrupt service routine */
void __vector_5(void)__attribute__((signal));
void __vector_5(void)
{
	if(TIMER_PvCallBack[6]!= NULL)
	{
	TIMER_PvCallBack[6]();
	}
}
/*timer two   compare match interrupt service routine */

void __vector_4(void)__attribute__((signal));
void __vector_4(void)
{
	if(TIMER_PvCallBack[7]!= NULL)
	{
	TIMER_PvCallBack[7]();
	}
}

