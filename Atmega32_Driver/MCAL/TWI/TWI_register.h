/*
 * TWI_register.h
 *
 *  Created on: Apr 22, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_TWI_TWI_REGISTER_H_
#define MACL_TWI_TWI_REGISTER_H_

/*TWI Bit RAte Register */
#define TWBR   (*(volatile u8*)(0x20))


/*TWI Control  Register */
#define TWCR        (*(volatile u8*)(0x56))

#define TWCR_TWIE   0  /*TWI Interrupt Enable */
#define TWCR_TWEN   2  /*TWI Enable Bit*/
#define TWCR_TWWC   3  /*TWI Write Collision Flag*/
#define TWCR_TWSTO  4  /*TWI Stop Condition Bit */
#define TWCR_TWSTA  5  /*TWi Start condition bit */
#define TWCR_TWEA   6  /*TWI Enable Acknowledge BIt */
#define TWCR_TWINT  7  /*TWI Interrupt flag*/


/*TWI Status Register */
#define TWSR        (*(volatile u8*)(0x21))

/*TWI Prescaler Bits */
#define TWSR_TWPS0  0
#define TWSR_TWPS1  1

/*TWI Status Bits*/
#define TWSR_TWS3   3
#define TWSR_TWS4   4
#define TWSR_TWS5   5
#define TWSR_TWS6   6
#define TWSR_TWS7   7

/*TWI DATA Register */
#define TWDR        (*(volatile u8*)(0x23))


/*TWI Slave Address(my Address while I Act Like A Slave)*/
#define TWAR        (*(volatile u8*)(0x22))

#define TWAR_TWGCE  0  /*TWI General Call Enable Bit */

#endif /* MACL_TWI_TWI_REGISTER_H_ */
