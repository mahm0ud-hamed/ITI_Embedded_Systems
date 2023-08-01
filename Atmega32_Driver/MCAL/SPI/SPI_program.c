/*
 * SPI_program.c
 *
 *  Created on: Apr 8, 2023
 *      Author: Mahmoud Hamed
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../DIO/DIO_interface.h"
#include "SPI_pirvate.h"
#include "SPI_inteface.h"
/*glopal pounter to reciver the address of value need to store SPI received value on it */
static u8 * SPI_u8Tranceive = NULL;
/*global pointer to function to store SPI notification function  on it to run on ISR */
static void(*SPI_PvNotificationFunc)(void)= NULL ;


/*function to enable SPI interrupt */
void SPI_voidInterruptEnable(void)
{
	SET_BIT(SPCR,SPCR_SPIE);
}
/*function to enable SPI interrupt */
void SPI_voidInterruptDisable(void)
{
	CLR_BIT(SPCR,SPCR_SPIE);
}

/*function to initialize as Master*/
void SPI_voidMasterInit(SPI_Presacle Prescale ,  CLOCK_POLR_PHASE Polarity  , CLOCK_POLR_PHASE Phase  )
{
	/*********************************SPI MASTER  PIN CONFIG  *************************************/
	/*set pins related to SPI for master initialization */
	/*1- set MOSI as PORTB PIN 5 output
	 *2- set MISO as PORTB PIN 6  input
	 *3- set SCK PORTB PIN 7 as output*/

	/*1- set MOSI as PORTB PIN 5 output*/
	DIO_ErrStateSetPinDirec(DIO_u8_PORTB,DIO_pin5,DIO_U8_OUTPUT);
	/*2- set MISO as PORTB PIN 6 output*/
	DIO_ErrStateSetPinDirec(DIO_u8_PORTB,DIO_pin6,DIO_U8_INPUT);
	/*3- set SCK PORTB PIN 7 as output*/
	DIO_ErrStateSetPinDirec(DIO_u8_PORTB,DIO_pin7,DIO_U8_OUTPUT);
	/* 4- set SS PORTB PIN 4 as OUTPUT for master protection  */
	DIO_ErrStateSetPinDirec(DIO_u8_PORTB,DIO_pin4,DIO_U8_OUTPUT);
	/*
	DIO_ErrStateSetPinDirec(DIO_u8_PORTB,DIO_pin4,DIO_U8_INPUT);
	DIO_ErrStateSetPinValue(DIO_u8_PORTB,DIO_pin4,DIO_U8_HIGH);*/

	/*set as master */
	SET_BIT(SPCR,SPCR_MSTR);
	/***************************CLOCK polarity and clock phase CONFIG and data order  ***************************/

	/*set data order LSB transmitted  first */
	SET_BIT(SPCR,SPCR_DORD);

	/*select clock polarity initial high or low */
	if (Polarity == CLOCK_ploarity_LOW)
	{
		CLR_BIT(SPCR,SPCR_CPOL);
	}
	else if (Polarity == CLOCK_ploarity_High)
	{
		SET_BIT(SPCR,SPCR_CPOL);
	}
	else {/*Do Nothing*/}

	/*Select  clock phase */
	if(Phase == CLOCK_Phase_SAMPL_Frist)
	{
		CLR_BIT(SPCR,SPCR_CPHA);
	}
	else if (Phase == CLOCK_Phase_Setup_Frist)
	{
		SET_BIT(SPCR,SPCR_CPHA);
	}
	else {/*Do Nothing*/}

	/***********************************PRESACLE CONFIG *******************************************/

	if(Prescale <= Prescale_1xSpeed_128)
	{
		SPCR&=  0b11111100;
		SPCR|=  Prescale;
	}
	else
	{
		switch (Prescale)
		{
		case Prescale_2xSpeed_2 :
			CLR_BIT(SPCR,SPCR_SPR0);
			CLR_BIT(SPCR,SPCR_SPR1);
			SET_BIT(SPSR,SPSR_SPI2X);
			break ;
		case Prescale_2xSpeed_8:
			SET_BIT(SPCR,SPCR_SPR0);
			CLR_BIT(SPCR,SPCR_SPR1);
			SET_BIT(SPSR,SPSR_SPI2X);
			break ;

		case Prescale_2xSpeed_32:
			CLR_BIT(SPCR,SPCR_SPR0);
			SET_BIT(SPCR,SPCR_SPR1);
			SET_BIT(SPSR,SPSR_SPI2X);
			break ;
		case Prescale_2xSpeed_64:
			SET_BIT(SPCR,SPCR_SPR0);
			SET_BIT(SPCR,SPCR_SPR1);
			SET_BIT(SPSR,SPSR_SPI2X);
			break ;
		default : /*do nothing */
		break ;
		}
	}

	/*********************************SPI Enable*************************************/
	SET_BIT(SPCR,SPCR_SPE);

}/*end of SPI master INIT FUNC*/



/*function to initialize as Slave*/
void SPI_voidSlaveInit( CLOCK_POLR_PHASE Polarity  , CLOCK_POLR_PHASE Phase  )
{
	/*********************************SPI SLAVE  PIN CONFIG  *************************************/
	/*set pins related to SPI for master initialization */
	/*1- set MOSI as PORTB PIN 5 INPUT
	 *2- set MISO as PORTB PIN 6 OUTPUT
	 *3- set SCK PORTB PIN 7 as INPUT
	 *4-  set slave Select as input */

	/*1- set MOSI as PORTB PIN 5 INPUT*/
	DIO_ErrStateSetPinDirec(DIO_u8_PORTB,DIO_pin5,DIO_U8_INPUT);
	/*2- set MISO as PORTB PIN 6 OUTPUT*/
	DIO_ErrStateSetPinDirec(DIO_u8_PORTB,DIO_pin6,DIO_U8_OUTPUT);
	/*3- set SCK PORTB PIN 7 as INPUT*/
	DIO_ErrStateSetPinDirec(DIO_u8_PORTB,DIO_pin7,DIO_U8_INPUT);
	/* 4- set SS PORTB PIN 4 as INPUT */
	DIO_ErrStateSetPinDirec(DIO_u8_PORTB,DIO_pin4,DIO_U8_INPUT);
	/*set as SLAVE */
	CLR_BIT(SPCR,SPCR_MSTR);

	/***************************CLOCK polarity and clock phase CONFIG and data order  ***************************/

	/*set data order LSB transmitted  first */
	SET_BIT(SPCR,SPCR_DORD);

	/*select clock polarity initial high or low */
	if (Polarity == CLOCK_ploarity_LOW)
	{
		CLR_BIT(SPCR,SPCR_CPOL);
	}
	else if (Polarity == CLOCK_ploarity_High)
	{
		SET_BIT(SPCR,SPCR_CPOL);
	}
	else {/*Do Nothing*/}

	/*Select  clock phase */
	if(Phase == CLOCK_Phase_SAMPL_Frist)
	{
		CLR_BIT(SPCR,SPCR_CPHA);
	}
	else if (Phase == CLOCK_Phase_Setup_Frist)
	{
		SET_BIT(SPCR,SPCR_CPHA);
	}
	else {/*Do Nothing*/}

	/*********************************SPI Enable*************************************/
	SET_BIT(SPCR,SPCR_SPE);
}/*end of spi slave initialization */

SPI_ErrState  SPI_u8TrancieveSynch(u8 *copy_u8RecvData , u8 copy_u8SendData )
{
	/*counter used for time out concept */
	u16 Local_u16TimeOutCounter =0 ;

	/*write data on SPI register to start transmission  */
	 SPDR= copy_u8SendData ;

	/*with concept of Time out concept */
	/*wait until trancieve complete or time out */
	while(GET_BIT(SPSR,SPSR_SPIF)==0 && Local_u16TimeOutCounter < SPI_Time_OUT)
	{
		Local_u16TimeOutCounter++ ;
	}
	/*check why polling while loop is terminated */
	if (Local_u16TimeOutCounter == SPI_Time_OUT)
	{
		/*if terminated by time out return time out error */
		return SPI_Time_OutErr;
	}
	else
	{
		/*if terminated by receive complete flag */
		/*return received in register */
		*copy_u8RecvData = SPDR ;
	}

	return SPI_No_Err;
}



SPI_ErrState   SPI_u8TrancieveAsynch(u8 *copy_u8RecvData , u8 copy_u8SendData , void(*Copy_PvNotifiactionFunc)(void))
{
	/*check for the two addresses that not equal null */
	if(copy_u8RecvData != NULL && Copy_PvNotifiactionFunc != NULL )
	{
		/*write data on register */
		 SPDR= copy_u8SendData ;
		 SPI_u8Tranceive = copy_u8RecvData ;
		 SPI_PvNotificationFunc = Copy_PvNotifiactionFunc ;
		  /*enable SPI interrupt */
		 SPI_voidInterruptEnable();
	}
	else
	{
		return SPI_Address_Error;
	}
	return SPI_No_Err ;
}

/*ISR of SPI serial Transfer complete */
void __vector_12(void)__attribute__((signal));
void __vector_12(void)
{
	/*get SPI data register on global pointer which point
	 * to the address of varable that nedd to store data Transfered to it */
	*SPI_u8Tranceive =SPDR ;
	/*excute notification function that will announce that transfer is complete */
	 SPI_PvNotificationFunc();

}
