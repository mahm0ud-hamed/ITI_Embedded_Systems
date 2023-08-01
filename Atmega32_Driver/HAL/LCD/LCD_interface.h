/*
 * LCD_interface.h
 *
 *  Created on: Mar 27, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#include "LCD_config.h"
#include "LCD_register.h"
#include "LCD_private.h"

LcdErrState_t  LCD_LcdErrStateSendChar(LCD_info_t* LCD , u8 copy_u8Data);
LcdErrState_t  LCD_LcdErrStateSendCommand(LCD_info_t* LCD , u8 copy_u8Data);
LcdErrState_t  LCD_LcdErrStateSendString(LCD_info_t* LCD , u8* copy_u8string);
LcdErrState_t  LCD_LcdErrStateSendNumber(LCD_info_t* LCD , s32 Copy_u32Num);
void LCD_voidGoToX_Y(LCD_info_t* LCD,LCD_ROW RWO ,LCD_COL COL);


void LCD_voidStoreSpecialCahracter(LCD_info_t* LCD, BLOCK_NUM_t BLOCK_NUM , u8 * PTR_u8SpCharacter);
void LCD_voidSndSpecialCahracter(LCD_info_t* LCD, BLOCK_NUM_t BLOCK_NUM );

void LCD_voidClearDispla(LCD_info_t* LCD);
void LCD_init(LCD_info_t* LCD);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
