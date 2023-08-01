/*
 * SPI_pirvate.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_SPI_SPI_PIRVATE_H_
#define MACL_SPI_SPI_PIRVATE_H_
 /*time out counter */
#define SPI_Time_OUT   5000
/*SPI Control Register  */
#define SPCR  (*(volatile u8*)(0x2D))

#define SPCR_SPR0   0  /*SPR0 & SPR1 select prescale*/
#define SPCR_SPR1   1
#define SPCR_CPHA   2  /*SPI Clock Phase */
#define SPCR_CPOL   3  /*SPI Clock Polarity */
#define SPCR_MSTR   4  /*Master or Slave Select */
#define SPCR_DORD   5  /*DATA order  */
#define SPCR_SPE    6  /*SPI  enable */
#define SPCR_SPIE   7  /*SPI interrupt enable */

#define SPSR  (*(volatile u8*)(0x2E))
#define SPSR_SPI2X  0  /*SPI Double Speed */
#define SPSR_WCOL   6  /*SPI Write Collision Flag  */
#define SPSR_SPIF   7  /*SPI interrupt Flag */

/*SPI Data Register */
#define SPDR  (*(volatile u8*)(0x2F))


#endif /* MACL_SPI_SPI_PIRVATE_H_ */
