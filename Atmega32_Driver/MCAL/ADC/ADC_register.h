/*
 * ADC_register.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_ADC_ADC_REGISTER_H_
#define MACL_ADC_ADC_REGISTER_H_

/*ADC multiplexer selection register */
#define ADMUX         (*(volatile u8*)(0x27))
#define ADMUX_MUX0     0/*0-5 select channel */
#define ADMUX_MUX1     1
#define ADMUX_MUX2     2
#define ADMUX_MUX3     3
#define ADMUX_MUX4     4
#define ADMUX_ADLAR    5
#define ADMUX_REFS0    6 /*6-7 select reference voltage */
#define ADMUX_REFS1    7

/*ADC control and status register */
#define ADCSRA         (*(volatile u8*)(0x26))
#define ADCSRA_ADPS0    0/*0-2 ADC select prescaler*/
#define ADCSRA_ADPS1    1
#define ADCSRA_ADPS2    2
#define ADCSRA_ADIE     3/*ADC interrupt enalble*/
#define ADCSRA_ADIF     4/*ADC interrupt flag */
#define ADCSRA_ADATE    5/*ADC auto triggered enable*/
#define ADCSRA_ADSC     6/*ADC start conversion */
#define ADCSRA_ADEN     7/*ADC enable*/

/*ADC data register*/
#define ADCL           (*(volatile u8*)(0x24)) /*ADC data lower register*/
#define ADCH           (*(volatile u8*)(0x25)) /*ADC data higher register */
#define ADC            (*(volatile u16*)(0x24))/*treat two register as one 16 bit register */

/*special function IO register*/
#define SOIFR           (*(volatile u8*)(0x50))

#define SFIOR_ADTS0      5/*5-7 ADC auto trigger source */
#define SFIOR_ADST1      6
#define SFIOR_ADST2      7
#define SFIOR_PSR
#endif /* MACL_ADC_ADC_REGISTER_H_ */
