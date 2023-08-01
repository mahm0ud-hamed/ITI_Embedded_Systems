/*
 * SPI_inteface.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_SPI_SPI_INTEFACE_H_
#define MACL_SPI_SPI_INTEFACE_H_

typedef enum
{
	Prescale_1xSpeed_4,
	Prescale_1xSpeed_16,
	Prescale_1xSpeed_64,
	Prescale_1xSpeed_128,

	Prescale_2xSpeed_2,
	Prescale_2xSpeed_8,
	Prescale_2xSpeed_32,
	Prescale_2xSpeed_64
}SPI_Presacle;

typedef enum
{

	CLOCK_ploarity_LOW,
	CLOCK_ploarity_High ,

	CLOCK_Phase_SAMPL_Frist=0,
	CLOCK_Phase_Setup_Frist

}CLOCK_POLR_PHASE;

typedef enum
{
	SPI_No_Err ,
	SPI_Time_OutErr,
	SPI_Address_Error

}SPI_ErrState;

/*function to enable SPI interrupt */
void SPI_voidInterruptEnable(void);

/*function to enable SPI interrupt */
void SPI_voidInterruptDisable(void);

/*function to initialize as Master*/
void SPI_voidMasterInit(SPI_Presacle Prescale ,  CLOCK_POLR_PHASE Polarity  , CLOCK_POLR_PHASE Phase  );


/*function to initialize as Slave*/
void SPI_voidSlaveInit( CLOCK_POLR_PHASE Polarity  , CLOCK_POLR_PHASE Phase  );

/*function to initialize as Slave*/
SPI_ErrState  SPI_u8TrancieveSynch(u8 *copy_u8RecvData , u8 copy_u8SendData );

SPI_ErrState   SPI_u8TrancieveAsynch(u8 *copy_u8RecvData , u8 copy_u8SendData , void(*Copy_PvNotifiactionFunc)(void));

#endif /* MACL_SPI_SPI_INTEFACE_H_ */
