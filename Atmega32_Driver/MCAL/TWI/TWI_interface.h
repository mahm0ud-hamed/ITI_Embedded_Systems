/*
 * TWI_interface.h
 *
 *  Created on: Apr 22, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_TWI_TWI_INTERFACE_H_
#define MACL_TWI_TWI_INTERFACE_H_

typedef enum
{
TWI_NoErr ,
SartCondErr ,
RepSartCondErr,
SlaveAddWithWriteErr ,
SlaveAddWithReadErr,
MasterWriteByteErr ,
MasterReadByteErr

}TWI_ErrStatus ;
/*pass zero in the salve address argument if master will not be addressed  */
void TWI_MasterInit(u8 copy_SlaveAddress);

/**/
void TWI_voidSlaveInit(u8 copy_SlaveAddress);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatStart(void);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 copy_SlaveAddress );

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 copy_SlaveAddress );

TWI_ErrStatus TWI_MasterWriteDataByte(u8 copy_pu8DataByte);

TWI_ErrStatus TWI_MasterReadDataByte(u8* copy_pu8DataByte);

void TWI_SendStopCondition(void);
#endif /* MACL_TWI_TWI_INTERFACE_H_ */
