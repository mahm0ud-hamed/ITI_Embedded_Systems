/*
 * UART_register.h
 *
 *  Created on: Apr 16, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_UART_UART_REGISTER_H_
#define MACL_UART_UART_REGISTER_H_


/*   normal mode 1x speed
 *   UBBR = (Fosc/16BUAD)-1 */


/*UART FRAME
 * start(1) BIT  DATA(5->9)BITS  STOP(1/2)BITS
 * */

/*UART Data Register */
#define UDR   (*(volatile u8*)(0x2C))



/*UART control and status Register A */

#define UCSRA      (*(volatile u8*)(0x2B))

#define UCSRA_RXC   7  /*UART receive complete  flag             */
#define UCSRA_TXC   6  /*UART Transmit complete flag             */
#define UCSRA_UDRE  5  /*DATA register is empty flag             */
#define UCSRA_FE    4  /*Frame error flag                        */
#define UCSRA_DOR   3  /*DATA over RUN flag                      */
#define UCSRA_PE    2  /*Parity Error flag                       */
#define UCSRA_U2X   1  /*Double the UART transmission speed      */
#define UCSRA_MPCM  0  /*Multi processor communication  mode     */

/*UART control and status Register B */
#define UCSRB      (*(volatile u8*)(0x2A))

#define UCSRB_RXCIE  7  /*UART receive complete interrupt enable  */
#define UCSRB_TXCIE  6  /*UART Transmit complete interrupt enable */
#define UCSRB_UDRIE  5  /*DATA register is empty interrupt enable */
#define UCSRB_RXEN   4  /*Receiver enable                         */
#define UCSRB_TXEN   3  /*Transmitter enable      				  */
#define UCSRB_UCSZ2  2  /*Character size          				  */
#define UCSRB_RXB8   1  /*Receive data 8 bit */
#define UCSRB_TXB8   0  /*Transmit data 8 bit*/


/*UART control and status Register C */
#define UCSRC      (*(volatile u8*)(0x40))
/*selection between UBBRH And UCSRC and must be one when writing on UCSRC*/
#define UCSRC_URSEL  7

#define UCSRC_UMSEL  6  /*UART MODE Select  					  */
#define UCSRC_UPM1   5  /*PARITY MODE  							  */
#define UCSRC_UPM0   4  /*PARITY MODE                      	      */
#define UCSRC_USBS   3  /*STOP BIT Setting      				  */
#define UCSRC_UCSZ1  2  /*Character size          				  */
#define UCSRC_UCSZ0  1  /*Character size   */
#define UCSRC_UCPOL  0  /*CLOCK Polarity with synchronous mode only*/
/*BUAD Rate register */
#define UBBRH     (*(volatile u16*)(0x40))
#define UBBRL     (*(volatile u16*)(0x29))


#endif /* MACL_UART_UART_REGISTER_H_ */
