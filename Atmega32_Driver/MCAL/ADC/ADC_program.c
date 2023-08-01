/*
 * ADC_program.c
 *
 *  Created on: Apr 3, 2023
 *      Author: Mahmoud Hamed
 */

#include "../../LIB/BIT_MATH.h"
#include  "../../LIB/STD_TYPES.h"
#include "ADC_interface.h"

u8 ADC_BusyFlag =IDLE ;
static u16*ADC_Pu16Reading = NULL ;
static void(*ADC_pvNotificationFunc)(void)=NULL ;

void (*ADC_PTR_FUNC)(void)=NULL;
void ADC_voidInit(void)
{
	/*select reference volt */
#if VOLT_REF_SELEC == AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif VOLT_REF_SELEC == AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif VOLT_REF_SELEC == NTERANAL_2.56V
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#endif
	/*select right or left adjustment */
	/*with 10 bit resolution */
#if ADC_ADJUSTMENT == RIGHT_ADJST
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	/*with 8 bit resolution */
#elif ADC_ADJUSTMENT == LEFT_ADJST_ADJST
	SET_BIT(ADMUX,ADMUX_ADLAR);
#endif

	/* select prescaler by bit masking first set the three bit that resopnsible for prescaler by zero
	 * and then assign the value of prescaler to this three bits which will affect only in the first three bits */
	ADCSRA&=0b11111000 ;
	ADCSRA|=ADC_PRESCALER;
	/*enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}
/*for the left adjustment read only the low register */
#if ADC_ADJUSTMENT == LEFT_ADJST
u8 ADC_u8Conversion(ADC_CHANEL Chanel)
{
	/*choose chanel*/
	ADMUX &= 0b11111000;
	ADMUX|= Chanel;
	/*ADC start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*wait until the conversion ended */
	while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);
	/*return value that store on ADCH 8 bit only  */
	return ADCH;
}
#endif

#if ADC_ADJUSTMENT== RIGHT_ADJST
u16  ADC_u16Conversion(ADC_CHANEL Chanel)
{
	/*choose chanel*/
	ADMUX&=0b11111000;
	ADMUX|=Chanel;
	/*ADC start conversion */
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*wait until conversion ended */
	while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);
	/*return value of  ADC 10 bits */
	return ADC ;
}
#endif

u16 ADC_voidCalculateAnalog(u16 copy_u16DigitalValue)
{
	u16 Local_u16AnalogValue =0 ;
#if ADC_ADJUSTMENT == LEFT_ADJST
	/*8 bit mode
	 * resolution  8 bit so 2^res = 256
	 * vref = 5000 mili volt  */
	Local_u16AnalogValue = ((f32)copy_u16DigitalValue*5000UL)/256UL ;

#elif ADC_ADJUSTMENT == RIGHT_ADJST
	Local_u16AnalogValue = ((f32)copy_u16DigitalValue*5000UL)/1024UL;
#endif
	return Local_u16AnalogValue ;
}


ADC_ERR ADC_ADCERRConversionSynchrounous(ADC_CHANEL chanel , u16 * copy_Pu16Result)
{
	u16 TimeOut_Counter=0 ;
	if(copy_Pu16Result != NULL)
	{
		if(ADC_BusyFlag == IDLE)
		{
			ADC_BusyFlag =BUSY ;
			/*active channel */
			ADMUX&=0b11100000;
			ADMUX|=chanel ;
			/*start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/*busy waiting until the conversion  complete flag  or the time out is finished */
			while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0 && TimeOut_Counter != TIME_OUT_LIMIT)
			{
				TimeOut_Counter++; /*increase counter by one */
			}
			/*check the reason of terminate the while loop
			 * by time out or by flag */
			if (TimeOut_Counter == TIME_OUT_LIMIT)
			{
				return TimeOutError ;
			}// end of check timeout if condition

			else
			{
				#if ADC_ADJUSTMENT == LEFT_ADJST
				*copy_Pu16Result= ADCH ;
				#elif ADC_ADJUSTMENT ==RIGHT_ADJST
				*copy_Pu16Result= ADC ;
				#endif
			}// end of check timeout else  condition

		}// end of check channel busy of condition
		else
		{
			return ADC_BusyError ;

		}// end of check of channel else condition

	}// end of check address of result if condition
	else
	{
		return ADC_AdressError ;
	}// end of check address of result else  condition
	return NoADC_Error;

}

ADC_ERR ADC_ADCERRConversionASynchrounous(ADC_CHANEL chanel , u16 *copy_pu16Result , void (*copy_PvNotificationfunction)(void ))
{
	if(copy_pu16Result==NULL || copy_PvNotificationfunction == NULL )
	{
		return ADC_AdressError ;
	}// end of address check if condition
	else
	{
		/*assign copy_pu16Result to global pointer that well work on ISR and reflect on the address of copy_pu16Result */
		ADC_Pu16Reading = copy_pu16Result ;
		/*assign copy_pvNotificationFunction  to global pointer to function that well invoked on ISR function*/
		ADC_pvNotificationFunc= copy_PvNotificationfunction;
		/*active channel */
		ADMUX&=0b11100000;
		ADMUX|=chanel;
		/*start conversion */
		SET_BIT(ADCSRA,ADCSRA_ADSC);
		/*active ADC interrupt */
		SET_BIT(ADCSRA,ADCSRA_ADIE);
	}
	return NoADC_Error ;
}


/*ADC complete conversion ISR*/
void __vector_16(void)__attribute__((signal));
void __vector_16(void)
{
	/*Read ADC*/
#if ADC_ADJUSTMENT==LEFT_ADJST
	*ADC_Pu16Reading =ADCH ;
#elif  ADC_ADJUSTMENT==RIGHT_ADJST
	*ADC_Pu16Reading =ADC;
#endif
	/*INVOKE the notification function */
	ADC_pvNotificationFunc();
}
