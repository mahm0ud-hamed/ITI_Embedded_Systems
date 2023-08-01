/*
 * UART_interface.h
 *
 *  Created on: Apr 16, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_UART_UART_INTERFACE_H_
#define MACL_UART_UART_INTERFACE_H_


typedef enum
{
	NoParity ,
	EvenParity=2 ,
	Oddparity
}UART_ParityMode;


typedef enum
{
	OneSTB ,
	TwoSTB ,
	Asynchronous =0 ,
	synchronous
}STB_Syn_ASync_Mode;


typedef enum
{
	_5bits,
	_6bits,
	_7bits,
	_8bits,
	_9bits=7
}Character_size;

typedef enum
{
	BUAD_2400 = 207,
	BUAD_4800 = 103,
	BUAD_9600 = 51

}UART_8MHZ_BUAD;

typedef struct
{
	UART_ParityMode    parity  ;
	STB_Syn_ASync_Mode NUM_STB ;
	STB_Syn_ASync_Mode SYNC_ASYNC ;
	Character_size     Char_size ;
	UART_8MHZ_BUAD     BAUD_RATE;
}UART_info ;


typedef enum {
	UartNoErr,
	TimeOutErr,
	UArtAddressError
}UART_ErrState;
/****************************UART_INIT*********************************************/

/*function to initiate UART*/
void UART_voidInit(UART_info * UART);

/**************************UART SYNCHRONOUS ***************************************/

/*function to send character (one byte ) synchronously */
UART_ErrState UART_SendCharSynch(u8 Copy_u8Data );

/*function to receive character (one byte ) synchronously */
UART_ErrState UART_RecevCharSynch(u8 * Copy_u8Data );

/************************UART ASYNCHRONOUS****************************************/

/*function to send character (one byte ) Asynchronously */
UART_ErrState UART_SendCharASynch(u8 Copy_u8Data , void(*Pv_copyNotificationFunc)(void));

/*function to receive character (one byte ) Asynchronously */
UART_ErrState UART_RecevCharASynch(u8 * Copy_u8Data,  void(*Pv_copyNotificationFunc)(void));

/*function to SEND string Asynchronously */
UART_ErrState UART_SendStringASynch(char * Copy_u8String , void(*Pv_copyNotificationFunc)(void));



#endif /* MACL_UART_UART_INTERFACE_H_ */
