/*
 * ADC_private.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_ADC_ADC_PRIVATE_H_
#define MACL_ADC_ADC_PRIVATE_H_
/*ADC chanel busy or not */
#define IDLE  0
#define BUSY  1

/*the time out concept*/
#define TIME_OUT_LIMIT 50000
/*voltage reference selection */
#define AREF              0 /*ARFE the internal voltage vref is turned off */
#define AVCC              1 /*AVCC with external capcitor on AREF*/
#define INTERANAL_2.56V   3 /*internal 2.56 volatage with external cpacitor on AREF*/


/* left or right adjustment */
#define LEFT_ADJST    1
#define RIGHT_ADJST   0


/** ADC channels*/
typedef enum
{
	chanel0,
	chanel1,
	chanel2,
	chanel3,
	chanel4,
	chanel5,
	chanel6,
	chanel7
}ADC_CHANEL ;

typedef enum {
	NoADC_Error ,
	ADC_AdressError,
	ADC_BusyError,
	TimeOutError

}ADC_ERR ;
/*ADC prescaler selection (division factor)*/
#define ADC_PRESCALE_2     1  /*division by 2*/
#define ADC_PRESCALE_4     2  /*division by 4*/
#define ADC_PRESCALE_8     3  /*division by 8*/
#define ADC_PRESCALE_16    4  /*division by 16*/
#define ADC_PRESCALE_32    5  /*division by 32*/
#define ADC_PRESCALE_64    6  /*division by 64*/
#define ADC_PRESCALE_128   7  /*division by 128*/

/*auto triger source*/
#define FREE_RUNNING       0
#define ANALOG_COMPARATOR  1
#define EXT_INT0           2
#define TIMER0_COMPMATCH   3
#define TIMER0_OVF         4
#define TIMER1_COMPMATCH   5
#define TIMER1_OVF         6
#define TIMER1_ICU_EVENT   7

#endif /* MACL_ADC_ADC_PRIVATE_H_ */
