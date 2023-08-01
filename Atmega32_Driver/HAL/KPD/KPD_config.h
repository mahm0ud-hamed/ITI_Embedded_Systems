/*
 * KPD_config.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_

/*********************** selection of KPD ports ******************************/
#define KPD_ROW_PORT   DIO_u8_PORTA
#define KPD_COL_PORT   DIO_u8_PORTA

/*********************** selection of KPD pins *******************************/
#define KPD_ROW1  0
#define KPD_ROW2  1
#define KPD_ROW3  2
#define KPD_ROW4  3

#define KPD_COL1  4
#define KPD_COL2  5
#define KPD_COL3  6
#define KPD_COL4  7

#define ROW_SIZE  4
#define COL_SIZE  4

#define KPD_NOTPRESSED   0xff

/**************************array for carry the row and col values*********************************************/

/*array to carry KPD rows value*/
static u8 KPD_ROWS[ROW_SIZE]={KPD_ROW1,KPD_ROW2,KPD_ROW3,KPD_ROW4};
/*array to carry KPD columns s value */
static u8 KPD_COLS[ROW_SIZE]={KPD_COL1,KPD_COL2,KPD_COL3,KPD_COL4};

/********************************* 2D array to represent the 4*4 Key Pad **************************************/

static u8 KPD_BUTTONS[ROW_SIZE][COL_SIZE]= {{'7','8','9','/'},
											{'4','5','6','*'},
											{'1','2','3','-'},
											{'c','0','=','+'}};



/**************************************************************************************************************/


#endif /* HAL_KPD_KPD_CONFIG_H_ */
