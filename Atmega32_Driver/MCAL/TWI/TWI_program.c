/*
 * TWI_program.c
 *
 *  Created on: Apr 22, 2023
 *      Author: Mahmoud Hamed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TWI_register.h"
#include "TWI_private.h"
#include "TWI_confing.h"
#include "TWI_interface.h"

/*pass zero in the salve address argument if master will not be addressed  */
void TWI_MasterInit(u8 copy_SlaveAddress)
{
	/*1- check if the address are reserved
	 *2- check if the user need the master will be slve or not  */

	/*Set Clock frequency as 400 KBIT/S  */
	TWDR = 2;
	/*Clear TWo Bits Of Prescaler */
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);
	if(copy_SlaveAddress !=0 )
	{
		TWAR =(copy_SlaveAddress<<1);
	}
	/*Enable TWI */
	SET_BIT(TWCR,TWCR_TWEN);

}

/**/
void TWI_voidSlaveInit(u8 copy_SlaveAddress)
{
	/*initialize the slave Address*/
	TWAR =(copy_SlaveAddress<<1);
	/*Enable TWI */
	SET_BIT(TWCR,TWCR_TWEN);
}

TWI_ErrStatus TWI_SendStartCondition(void)
{
	/*SEND Start condition on the Buss*/
	SET_BIT(TWCR,TWCR_TWSTA);
	/*(flag initially is raised )clear flag to let the previous operation done
	 *  because  while flag is set the clock State  low
	 * and it continue as low until the flag is cleared
	 * while flag is cleared the clock will run and make previous operation done */
	SET_BIT(TWCR,TWCR_TWINT);
	/*waiting until the interrupt flag is raised again and the previous operation is done*/
	while(GET_BIT(TWCR,TWCR_TWINT)== 0 );
	/*check that start condition is sent correct */

	if((TWSR & 0xf8) != StartAck )
	{
		return SartCondErr ;
	}
	else
	{
		/*do noting */
	}

	return TWI_NoErr ;
}

TWI_ErrStatus TWI_SendRepeatStart(void)
{
	/*SEND Start condition on the Buss*/
	SET_BIT(TWCR,TWCR_TWSTA);
	/*(flag initially is raised )clear flag to let the previous operation done
	 *  because  while flag is set the clock State  low
	 * and it continue as low until the flag is cleared
	 * while flag is cleared the clock will run and make previous operation done */
	SET_BIT(TWCR,TWCR_TWINT);
	/*waiting until the interrupt flag is raised again and the previous operation is done*/
	while(GET_BIT(TWCR,TWCR_TWINT)== 0 );
	/*check that start condition is sent correct */

	if((TWSR & 0xf8) != RepStartAck )
	{
		return RepSartCondErr ;
	}
	else
	{
		/*do noting */
	}

	return TWI_NoErr ;
}

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 copy_SlaveAddress )
{
	/*clear the start condition bit
	 * due to  data sheet must clear start condition after finish send start condition */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*set the slave address in the 7 MOS Bits in data register */
	TWDR=(copy_SlaveAddress<<1) ;
	/*for write request Clear bit 0 */
	CLR_BIT(TWDR,WRITE_BIT);

	/*Clear interrupt flag to let the previous operation done*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*waiting until the flag is raised again */
	while(GET_BIT(TWCR,TWCR_TWINT)== 0 );

	/*check if send slave address with write send correct*/
	if((TWSR & 0xf8) != SlaveAddWithWrite )
	{
		return SlaveAddWithWriteErr ;
	}
	else
	{
		/*do noting */
	}

	return TWI_NoErr ;
}

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 copy_SlaveAddress )
{
	/*clear the start condition bit
	 * due to  data sheet must clear start condition after finish send start condition */
	CLR_BIT(TWCR,TWCR_TWSTA);
	/*set the slave address in the 7 MOS Bits in data register */
	TWDR=(copy_SlaveAddress<<1) ;
	/*for read request set bit 0 */
	SET_BIT(TWDR,READ_BIT);
	/*Clear interrupt flag to let the previous operation done*/
	SET_BIT(TWCR,TWCR_TWINT);
	/*waiting until the flag is raised again */
	while(GET_BIT(TWCR,TWCR_TWINT)== 0 );
	/*check if send slave address with read send correct*/
	if((TWSR & 0xf8) != SlaveAddWithRead )
	{
		return SlaveAddWithReadErr ;
	}
	else
	{
		/*do noting */
	}

	return TWI_NoErr ;
}

TWI_ErrStatus TWI_MasterWriteDataByte(u8 copy_pu8DataByte)
{
	/*write data byte on data register */
	TWDR = copy_pu8DataByte ;

	/*clear interrupt flag to make operation done */
	SET_BIT(TWCR,TWCR_TWINT);

	/*waiting until the interrupt  flag is raised again */
	while(GET_BIT(TWCR,TWCR_TWINT)== 0 );

	if((TWSR & 0xf8) != MsterWriteByte )
	{
		return MasterWriteByteErr ;
	}
	else
	{
		/*do noting */
	}


	return TWI_NoErr ;
}

TWI_ErrStatus TWI_MasterReadDataByte(u8* copy_pu8DataByte)
{
	/*enable master generation ACK bit after receiving data*/
	SET_BIT(TWCR,TWCR_TWEA);
	/*clear interrupt flag to Start slave sending data  */
	SET_BIT(TWCR,TWCR_TWINT);
	/*waiting until the interrupt  flag is raised again */
	while(GET_BIT(TWCR,TWCR_TWINT)== 0 );

	if((TWSR & 0xf8) != MasterReadByteWithAck )
	{
		return MasterReadByteErr ;
	}
	else
	{
		/*read received data */
		*copy_pu8DataByte = TWDR ;

	}


	return TWI_NoErr ;
}

void TWI_SendStopCondition(void)
{
	/*SET The Stop Condition Bit */
	SET_BIT(TWCR,TWCR_TWSTO);
	/*Clear interrupt flag to let the previous operation done*/
	SET_BIT(TWCR,TWCR_TWINT);
}

void __vector_19(void)__attribute__((signal));
void __vector_19(void)
{
	/*continue later */
}
