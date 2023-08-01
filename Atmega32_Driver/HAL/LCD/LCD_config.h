/*
 * LCD_config.h
 *
 *  Created on: Mar 27, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

typedef struct
{
	DIO_PORT_t RS_Port ;
	DIO_PORT_t RW_Port ;
	DIO_PORT_t E_Port ;
	DIO_PIN_t RS_Pin;
	DIO_PIN_t RW_Pin;
	DIO_PIN_t E_Pin;

	DIO_PORT_t Data_port;

}LCD_info_t;

typedef enum {

	NoLCDError,
	RS_portError,
	RW_portError,
	E_portError,
	RS_pinError,
	RW_pinError,
	E_pintError,

}LcdErrState_t;

typedef enum
{
	RWO1,
	RWO2,

}LCD_ROW;

typedef enum
{
	COL1,
	COL2,
	COL3,
	COL4,
	COL5,
	COL6,
	COL7,
	COL8,
	COL9,
	COL10,
	COL11,
	COL12,
	COL13,
	COL14,
	COL15,
	COL16
}LCD_COL;

typedef enum {

	Block1=1,
	Block2=2,
	Block3=3,
	Block4=4,
	Block5=5,
	Block6=6,
	Block7=7,
	Block8=8,
}BLOCK_NUM_t;

#endif /* HAL_LCD_LCD_CONFIG_H_ */
