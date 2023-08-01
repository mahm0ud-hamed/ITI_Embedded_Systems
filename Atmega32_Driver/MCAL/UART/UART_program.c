/*
 * UART_program.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Mahmoud Hamed
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "UART_register.h"
#include "UART_config.h"
#include "UART_private.h"
#include "UART_interface.h"

static void(*UART_pvNotifactionFunc[2])(void)={NULL};

static u8 * UART_pu8RecCmplete = NULL ;

static char*  UART_pu8StringSend = NULL ;

/*select ISR for string sending or char sending   */
 u8 UART_SRC_CHAR= 0;
 u8 UART_SRC_STR = 1;
/*global variable to select ISR for string sending or char sending   */
static u8 UART_SOUREC ;

/*global variable for count sting character*/
static u8 UART_STR_COUNTER =0 ;




void UART_voidInit(UART_info * UART)
{
	u8 Local_u8UCSRC=0  ;

/*****set URSEL as one to select writing on UCSRC*****/
	SET_BIT(Local_u8UCSRC,UCSRC_URSEL);
/*****check for synchronous and asynchronous mode ****/
	if(UART->SYNC_ASYNC == Asynchronous)
	{
		CLR_BIT(Local_u8UCSRC,UCSRC_UMSEL);
	}
	else if(UART->SYNC_ASYNC == synchronous)
	{
		SET_BIT(Local_u8UCSRC,UCSRC_UMSEL);
	}
/******check for parity mode************/
	if(UART->parity == NoParity )
	{
		CLR_BIT(Local_u8UCSRC,UCSRC_UPM0);
		CLR_BIT(Local_u8UCSRC,UCSRC_UPM1);
	}
	else if(UART->parity == EvenParity)
	{
		CLR_BIT(Local_u8UCSRC,UCSRC_UPM0);
		SET_BIT(Local_u8UCSRC,UCSRC_UPM1);
	}
	else if(UART->parity == Oddparity)
	{
		SET_BIT(Local_u8UCSRC,UCSRC_UPM0);
		SET_BIT(Local_u8UCSRC,UCSRC_UPM1);
	}

/***************check for number of stop BITS ****/
	if(UART->NUM_STB == OneSTB)
	{
		CLR_BIT(Local_u8UCSRC,UCSRC_USBS);
	}
	else if(UART->NUM_STB == OneSTB)
	{
		SET_BIT(Local_u8UCSRC,UCSRC_USBS);
	}
/**************set character size **************/
	if(UART->Char_size <= _8bits)
	{
		UCSRC&=0b11111100 ;
		UCSRC|=UART->Char_size ;
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
	}
	else if(UART->Char_size == _9bits)
	{
		SET_BIT(Local_u8UCSRC,UCSRC_UCSZ1);
		SET_BIT(Local_u8UCSRC,UCSRC_UCSZ0);
		SET_BIT(UCSRB,UCSRB_UCSZ2);
	}
	/*assign ALL configuration to UCSRC*/
	UCSRB=Local_u8UCSRC;
/****************SET BUAD RATE*************/
	UBBRH=0x00 ;
	UBBRL =UART->BAUD_RATE ;

/****************ENABLE SEND AND RECEIVE ************************/
	SET_BIT(UCSRB,UCSRB_RXEN); // receive enable
	SET_BIT(UCSRB,UCSRB_TXEN); // transmit enable
}

UART_ErrState UART_SendCharSynch(u8 Copy_u8Data )
{
	/*counter for time out */
	u16 Local_u16TimeOut=0;
	/*wait until the transmitted register be empty */
	while(( GET_BIT(UCSRA,UCSRA_UDRE)==0 ) &&  (Local_u16TimeOut < UART_TIMEOUT))
	{
		Local_u16TimeOut ++ ;
	}
	/*check if polling on flag terminated by time out or by flag rising */
	if(Local_u16TimeOut == UART_TIMEOUT )
	{
		return TimeOutErr ;
	}
	else
	{
		/*assign data on the data transmit register */
		UDR= Copy_u8Data;
	}
	return UartNoErr;
}


UART_ErrState UART_RecevCharSynch(u8* Copy_u8Data )
{
	/*counter for time out */
	u16 Local_u16TimeOut=0;
	/*check that address not NULL*/
	if(Copy_u8Data == NULL)
	{
		return UArtAddressError ;
	}
	else
	{
		/*wait until receiving flag is raised */
		while(GET_BIT(UCSRA,UCSRA_RXC) == 0 && Local_u16TimeOut <UART_TIMEOUT)
		{
			Local_u16TimeOut++ ;
		}
		/*assign receiving register to variable*/
		*Copy_u8Data = UDR ;
	}
	return UartNoErr;
}

UART_ErrState UART_SendStringSynch(u8* Copy_u8Data )
{
	u8 Local_u8Counter =0 ;
	if(Copy_u8Data!= NULL)
	{
		while(Copy_u8Data[Local_u8Counter]!='\0')
		{
			UART_SendCharSynch(Copy_u8Data[Local_u8Counter]);
			Local_u8Counter++ ;
		}

	}
	else
	{
		return UArtAddressError;
	}

	return UartNoErr;
}

UART_ErrState UART_SendCharASynch(u8 Copy_u8Data ,void(*Pv_copyNotificationFunc)(void))
{
	/*check for NOtification FUNC address  not NULL*/
	if (Pv_copyNotificationFunc == NULL )
	{
		return UArtAddressError;
	}
	else
	{
		/*inform ISR that character send  */
		UART_SOUREC= UART_SRC_CHAR;
		/*assign address of notification function to the global pointer to execute on ISR */
		UART_pvNotifactionFunc[0]=Pv_copyNotificationFunc ;
		//UART_pu8StringSend=
		/*start sending */
		UDR = Copy_u8Data ;
		/*enable  interrupt*/
		SET_BIT(UCSRB,UCSRB_TXCIE);
	}
	return UartNoErr;
}


/*function to receive character (one byte ) Asynchronously */
UART_ErrState UART_RecevCharASynch(u8 * Copy_u8Data,  void(*Pv_copyNotificationFunc)(void))
{
	/*check for NOtification FUNC address  not NULL*/
	if (Pv_copyNotificationFunc == NULL )
	{
		return UArtAddressError;
	}
	else
	{
		/*assign address of notification function to the global pointer to execute on ISR */
		UART_pvNotifactionFunc[1]=Pv_copyNotificationFunc ;
		/*assign address of passing value to global pointer to grt UDR value when ISR is executed  */
		UART_pu8RecCmplete = Copy_u8Data ;
		/*enable  interrupt*/
		SET_BIT(UCSRB,UCSRB_RXCIE);
	}

	return UartNoErr ;
}

/*function to SEND string Asynchronously */
UART_ErrState UART_SendStringASynch(char * Copy_u8String , void(*Pv_copyNotificationFunc)(void))
{
	if(Copy_u8String != NULL && Pv_copyNotificationFunc != NULL )
	{
		/*inform ISR that string send  */
		UART_SOUREC= UART_SRC_STR;

		/*initialize parameters on  global variables */
		UART_pvNotifactionFunc[0]=Pv_copyNotificationFunc ;

		UART_pu8StringSend=Copy_u8String;
		//	/*variable to iterate on string array  */
		//	static u8 Local_u8Counter = 0;
		UART_STR_COUNTER =0 ;
		//	while(Copy_u8String[Local_u8Counter]!='\0')
		//	{
		//		UART_SendCharASynch(Copy_u8String[Local_u8Counter] , Pv_copyNotificationFunc);
		//		Local_u8Counter++ ;
		//	}
		/*enable transmit complete interrupt */
		SET_BIT(UCSRB,UCSRB_TXCIE);
	}
	else
	{
		return UArtAddressError;
	}
	return UartNoErr ;
}


/*
 * receive string with for polling */

/*ISR OF Transmit complete */
void __vector_15(void)__attribute__((signal));
void __vector_15(void)
{
	/*if global variable not equal NULL */
//	if(UART_pvNotifactionFunc[0] != NULL)
//	{
//		/*check source is character send interrupt */
		if(UART_SOUREC == UART_SRC_CHAR)
		{
			SET_BIT(DDRB,0);
			SET_BIT(PORTB,0);

			/*disable UART transmit complete interrupt */
			CLR_BIT(UCSRB,UCSRB_TXCIE);
			/*Invoke notification function */
			UART_pvNotifactionFunc[0]();
		}
		else if(UART_SOUREC==UART_SRC_STR)
		{
			SET_BIT(DDRB,1);
			SET_BIT(PORTB,1);
			if (UART_pu8StringSend[UART_STR_COUNTER]=='\0')
			{
				/*disable UART transmit complete interrupt */
				CLR_BIT(UCSRB,UCSRB_TXCIE);
				/*invoke notification function */
				UART_pvNotifactionFunc[0]();
			}

			/*assign current character to data transmit register */
			UDR= UART_pu8StringSend[UART_STR_COUNTER];

			/*increment string counter by one */
			UART_STR_COUNTER++;
		}




//	}
}


/*ISR OF Receive complete */
void __vector_13(void)__attribute__((signal));
void __vector_13(void)
{
	/*if global variable not equal NULL */
	if(UART_pvNotifactionFunc[1] != NULL)
	{
		/*get value of date receive register */
		*UART_pu8RecCmplete=UDR;
		/*execute notification function */
		UART_pvNotifactionFunc[1]();
	}
}










