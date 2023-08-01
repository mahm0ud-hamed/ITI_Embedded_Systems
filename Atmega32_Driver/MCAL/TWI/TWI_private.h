/*
 * TWI_private.h
 *
 *  Created on: Apr 22, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_TWI_TWI_PRIVATE_H_
#define MACL_TWI_TWI_PRIVATE_H_


typedef enum
{
	StartAck = 0x08,          	    /*start has been sent*/
	RepStartAck=0x10,         		/*repeated start has been sent*/
	SlaveAddWithWrite=0x18,         /*master transmit (slave address + write request) ACK */
	SlaveAddWithRead= 0x40,         /*master transmit  (salve address + read request ) ACK */
	MsterWriteByte = 0x28 ,         /*master transmit data ACK*/
	MasterReadByteWithAck = 0x50 ,  /*master received data with ACK */
	MasterReadByteWithNack = 0x58,  /*master received data with Not ACK */
	SlaveAddRecvWithRead = 0xA8,    /*Slave Address is received with read request */
	SlaveAddRecvWithWire = 0x60 , 	/*Slave Address is received with Write request */
	SalveDataRecv = 0x80 , 			/*Byte Is Received*/
	SalveByteTransmitted = 0xB8     /*the Salve Written byte is transmitted */

}TWI_statusCode;

#define READ_BIT   0
#define WRITE_BIT  0
#endif /* MACL_TWI_TWI_PRIVATE_H_ */
