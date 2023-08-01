/*
 * TIMER0_private.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_TIMER_TIMER_PRIVATE_H_
#define MACL_TIMER_TIMER_PRIVATE_H_

/*******************************************( REGISTERS TIMER 0 )*******************************************/
#define TIMSK      (*(volatile u8 * )(0x59))  // Timer/Counter Interrupt Mask Register
#define OCR0       (*(volatile u8 * )(0x5C))  // Output Compare Register
#define TCCR0      (*(volatile u8 * )(0x53))  // Timer0/Counter0 Control Register
#define TCNT0      (*(volatile u8 * )(0x52))  // Timer/Counter Register   the compare match on the following timer clock
#define TIFR       (*(volatile u8 * )(0x58))  // Timer/Counter Interrupt Flag Register
/**********************************************************************************************************/

/*******************************************( REGISTERS TIMER 1 )*******************************************/
#define OCR1A      (*(volatile u16* )(0x4A))  // Output Compare Register A
#define OCR1B      (*(volatile u16* )(0x48))  // Output Compare Register B
#define TCCR1A     (*(volatile u8 * )(0x4F))  // Timer/Counter1 Control Register A
#define TCCR1B     (*(volatile u8 * )(0x4E))  // Timer/Counter1 Control Register B
#define TCNT1      (*(volatile u16* )(0x4C))  // Timer/Counter1
#define ICR1       (*(volatile u16* )(0x46))  // Input Capture Register
/**********************************************************************************************************/

/*******************************************( REGISTERS TIMER 2 )*******************************************/
#define OCR2       (*(volatile u8 * )(0x43))  // Output Compare Register Timer2/Counter2
#define TCCR2      (*(volatile u8 * )(0x45))  // Timer2/Counter2 Control Register
#define TCNT2      (*(volatile u8 * )(0x44))  // Timer2/Counter2 Register   the compare match on the following timer clock
/**********************************************************************************************************/




#define ACTIVE                      1
#define NOT_ACTIVE                  0
#define INPUT_CAPTURE_FALLING_EDGE  0
#define INPUT_CAPTURE_RISING_EDGE	1

typedef enum
{
	TIMER0_OVF_INT,
	TIMER0_COMP_INT,
	TIMER1_OVF_INT,
	TIMER1B_COMPB_INT,
	TIMER1A_COMPA_INT,
	TIMER1_CAPT_INT,
	TIMER2_OVF_INT,
	TIMER2_COMP_INT

}TimerInterrupt;
typedef enum
{
	TIMER0_2_NORMAL_MODE=0,
	TIMER0_2_PHASE_PWM_MODE=8,
	TIMER0_2_CTC_MODE=64,
	TIMER0_2_FAST_PWM_MODE=72 ,

	TIMER1_NORMAL_MODE=0,
	TIMER1_PWM_PHASE_CORRECT_8_BIT_MODE,
	TIMER1_PWM_PHASE_CORRECT_9_BIT_MODE,
	TIMER1_PWM_PHASE_CORRECT_10_BIT_MODE,
	TIMER1_CTC_MODE,
	TIMER1_FAST_PWM_8_BIT_MODE,
	TIMER1_FAST_PWM_9_BIT_MODE,
	TIMER1_FAST_PWM_10_BIT_MODE,
	TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICR1_MODE,
	TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OCR1A_MODE,
	TIMER1_PWM_PHASE_CORRECT_ICR1_MODE,
	TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE,
	TIMER1_CTC_ICR1_MODE,
	TIMER1_FAST_PWM_ICR1_MODE=14,
	TIMER1_FAST_PWM_OCR1A_MODE,
}TIMER_MODE_t;

typedef enum
{
	TIMER_NOCLOC ,
	TIMER_PRESCALER_1 ,
	TIMER_PRESCALER_8,
	TIMER_PRESCALER_64,
	TIMER_PRESCALER_256,
	TIMER_PRESCALER_1024,
	TIMER_External_CLK_FALING,
	TIMER_External_CLK_RISING
}TIMER_PRESCALER_t;


typedef enum
{
 TIMER_NO_ACTION,
 TIMER_TOGGLE,
 TIMER_CLEAR	,		     /* set on top clear on compare */
 TIMER_SET,		            /* set on top clear on compare */
 TIMER_NON_INVERTED=2,      /* CLEAR on Compare SET on top */
 TIMER_INVERTED             /* SET on Compare CLEAR on top */
}TIMER_Compare_Mode;

typedef enum
{
	Timer0 ,
	Timer1A ,
	Timer1B ,
	Timer2,
	Timer1_ICU
}TIMER_NUM;

#define TIMER0_INVERTED        1
#define TIMER0_NON_INVERTED    2

/* TCCR0 Register pins   */
#define TCCR0_FOC0            7 // Force Output Compare
#define TCCR0_WGM00           6 // Waveform Generation Mode
#define TCCR0_COM01           5 // Compare Output Mode, non-PWM Mode
#define TCCR0_COM00           4 // Compare Output Mode, non-PWM Mode
#define TCCR0_WGM01           3 // Waveform Generation Mode
#define TCCR0_CS02            2 // Clock Select
#define TCCR0_CS01            1 // Clock Select
#define TCCR0_CS00            0 // Clock Select

/* TIMSK Register pins   */
#define TIMSK_OCIE2           7 // Timer2/Counter2 Output Compare Match Interrupt Enable
#define TIMSK_TOIE2           6 // Timer2/Counter2 Overflow Interrupt Enable
#define TIMSK_TICIE1          5 // Input Capture Interrupt Enable
#define TIMSK_OCIE1A          4 // Output Compare A Match Interrupt Enable
#define TIMSK_OCIE1B          3 // Output Compare B Match Interrupt Enable
#define TIMSK_TOIE1           2 // Overflow Interrupt Enable
#define TIMSK_OCIE0           1 // Timer/Counter0 Output Compare Match Interrupt Enable
#define TIMSK_TOIE0           0 // Timer/Counter0 Overflow Interrupt Enable

/* TIFR Register pins   */
#define TIFR_OCF2             7 // Output Compare Flag2
#define TIFR_TOV2             6 // Timer2/Counter2 Overflow Flag
#define TIFR_ICF1             5 // Input Capture Flag
#define TIFR_OCF1A            4 // Output Compare A Match Flag
#define TIFR_OCF1B            6 // Output Compare B Match Flag
#define TIFR_TOV1             2 // Overflow Flag
#define TIFR_OCF0             1 // Output Compare Flag 0
#define TIFR_TOV0             0 // Timer/Counter0 Overflow Flag


/* TCCR2 Register pins   */
#define TCCR2_FOC2            7 // Force Output Compare
#define TCCR2_WGM20           6 // Waveform Generation Mode
#define TCCR2_COM21           5 // Compare Output Mode, non-PWM Mode
#define TCCR2_COM20           4 // Compare Output Mode, non-PWM Mode
#define TCCR2_WGM21           3 // Waveform Generation Mode
#define TCCR2_CS22            2 // Clock Select
#define TCCR2_CS21            1 // Clock Select
#define TCCR2_CS20            0 // Clock Select


/* TCCR1A Register pins   */
#define TCCR1A_COM1A1          7 // Compare Output Mode for Compare unit A
#define TCCR1A_COM1A0          6 // Compare Output Mode for Compare unit A
#define TCCR1A_COM1B1          5 // Compare Output Mode for Compare unit B
#define TCCR1A_COM1B0          4 // Compare Output Mode for Compare unit B
#define TCCR1A_FOC1A           3 // Force Output Compare for Compare unit A
#define TCCR1A_FOC1B           2 // Force Output Compare for Compare unit B
#define TCCR1A_WGM11           1 // Waveform Generation Mode
#define TCCR1A_WGM10           0 // Waveform Generation Mode

/* TCCR1B Register pins   */
#define TCCR1B_ICNC1          7 // Input Capture Noise Canceler
#define TCCR1B_ICES1          6 // Input Capture Edge Select
#define TCCR1B_WGM13          4 // Waveform Generation Mode
#define TCCR1B_WGM12          3 // Waveform Generation Mode
#define TCCR1B_CS12           2 // Clock Select
#define TCCR1B_CS11           1 // Clock Select
#define TCCR1B_CS10           0 // Clock Select




#endif /* MACL_TIMER_TIMER_PRIVATE_H_ */
