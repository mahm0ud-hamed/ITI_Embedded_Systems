/*
 * LCD_programe.c
 *
 *  Created on: Mar 27, 2023
 *      Author: Mahmoud Hamed
 */

#include "../../MACL/DIO/DIO_interface.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "LCD_interface.h"
#include <util/delay.h>

LcdErrState_t  LCD_LcdErrStateSendChar(LCD_info_t* LCD , u8 copy_u8Data)
{
		/*to send DATA RS pin must be HIGH */
		DIO_ErrStateSetPinValue(LCD->RS_Port,LCD->RS_Pin,DIO_U8_HIGH);
		/*to write on lCD R/W pin must be low */
		DIO_ErrStateSetPinValue(LCD->RW_Port,LCD->RW_Pin,DIO_U8_LOW);
		/*assign the value of command to the Data port */
		DIO_ErrStateSetPortValue(LCD->Data_port,copy_u8Data) ;
		/*send pulse top the uC of LCD TO by wetting enable high and delay and set it low */
		DIO_ErrStateSetPinValue(LCD->E_Port,LCD->E_Pin,DIO_U8_HIGH);
		/*wait using delay */
		_delay_ms(1);
		DIO_ErrStateSetPinValue(LCD->E_Port,LCD->E_Pin,DIO_U8_LOW);
		_delay_ms(1);
		return NoLCDError;
}

LcdErrState_t  LCD_LcdErrStateSendCommand(LCD_info_t* LCD , u8 copy_u8Data)
{
	/*to send command RS pin must be LOW */
	DIO_ErrStateSetPinValue(LCD->RS_Port,LCD->RS_Pin,DIO_U8_LOW);
	/*to write on lCD R/W pin must be low */
	DIO_ErrStateSetPinValue(LCD->RW_Port,LCD->RW_Pin,DIO_U8_LOW);
	/*assign the value of command to the Data port */
	DIO_ErrStateSetPortValue(LCD->Data_port,copy_u8Data) ;
	/*send pulse top the uC of LCD TO by wetting enable high and delay and set it low */
	DIO_ErrStateSetPinValue(LCD->E_Port,LCD->E_Pin,DIO_U8_HIGH);
	/*wait using delay */
	_delay_ms(1);
	DIO_ErrStateSetPinValue(LCD->E_Port,LCD->E_Pin,DIO_U8_LOW);
	_delay_ms(1);
	return NoLCDError;
}
void LCD_init(LCD_info_t * LCD)
{
	/*initialize all ports and pin that LCD connected with */
	/*set RS pin as OUTPUT*/
	DIO_ErrStateSetPinDirec(LCD->RS_Port,LCD->RS_Pin,DIO_U8_OUTPUT);
	/*set RW pin as OURTPUT*/
	DIO_ErrStateSetPinDirec(LCD->RW_Port,LCD->RW_Pin,DIO_U8_OUTPUT);
	/*set enable pin as OUTPUT*/
	DIO_ErrStateSetPinDirec(LCD->E_Port,LCD->E_Pin,DIO_U8_OUTPUT);
	/*set direction of DATA port as OUTPUT*/
	DIO_ErrStateSetPortDirec(LCD->Data_port,DIO_u8REG_MAX);/*reg_max 255*/
	/********state initialization ********/
	/*delay is must recommended by data sheet*/
	_delay_ms(40);
	/*set number of lines and font size  */
	LCD_LcdErrStateSendCommand(LCD , LCD_8BIT2Line);
	_delay_ms(1);
	LCD_LcdErrStateSendCommand(LCD , LCD_ON_crs_blink);
	/*clear display */
	LCD_LcdErrStateSendCommand(LCD,LCD_CLR_Display);
   _delay_ms(2);

}
LcdErrState_t  LCD_LcdErrStateSendString(LCD_info_t* LCD , u8* copy_u8string)
{
	/*counter for loop*/
	 u8 Local_u8Counter = 0 ;

	while(copy_u8string[Local_u8Counter]!='\0')
	{
		LCD_LcdErrStateSendChar(LCD,copy_u8string[Local_u8Counter]);
		Local_u8Counter++;
	}
	return NoLCDError;
}

void LCD_voidClearDispla(LCD_info_t* LCD)
{
	LCD_LcdErrStateSendCommand(LCD,LCD_CLR_Display);
}

LcdErrState_t  LCD_LcdErrStateSendNumber(LCD_info_t* LCD , 	s32 Copy_u32Num)
{
	u32 Revers_num = 0;
	u8 displayed_num = 0;
	u32 multiplier = 1, i = 0;
	if(Copy_u32Num == 0)
	{
		LCD_LcdErrStateSendChar(LCD,'0');
	}
	else if(Copy_u32Num < 0)
	{
		LCD_LcdErrStateSendChar(LCD,'-');
		Copy_u32Num *= -1;
	}

	while (Copy_u32Num != 0)
	{
		Revers_num = (Revers_num * 10) + Copy_u32Num % 10;
		if (Revers_num == 0)
			multiplier *= 10;
		Copy_u32Num /= 10;
	}
	while (Revers_num != i)
	{
		displayed_num = Revers_num % 10;
		LCD_LcdErrStateSendChar(LCD,displayed_num + 48 );   //48 -> '0'
		Revers_num/=10;
		if (Revers_num == 0 && multiplier >= 10)
		{
			i = 1;
			Revers_num = multiplier;
		}
	}
	return NoLCDError;
}

 void LCD_voidGoToX_Y(LCD_info_t* LCD,LCD_ROW RWO ,LCD_COL COL)
{
	u8 DDRAM_u8Adrress ;
	if(RWO==RWO1)
	{
		DDRAM_u8Adrress= COL ;
	}
	else if (RWO == RWO2)
	{
		DDRAM_u8Adrress=DDRAM_SECOND_ROW_Address+COL;
	}
	LCD_LcdErrStateSendCommand(LCD, DDRAM_ADDRES+DDRAM_u8Adrress);
}

 void LCD_voidStoreSpecialCahracter(LCD_info_t* LCD, BLOCK_NUM_t BLOCK_NUM , u8 * PTR_u8SpCharacter)
 {
	 u8 Local_u8counter=0;
	 /*every block is consist of 8 byte */
	 u8 CGRam_u8Address = (BLOCK_NUM*BLOCK_SIZE_BYTE);
	 /*set bit NUM 6 by one as recommended on data sheet*/
	 SET_BIT(CGRam_u8Address,6);
	 /*go to CGram address*/
	 LCD_LcdErrStateSendCommand(LCD,CGRam_u8Address);
	 /*store special character on CGram*/
	 for (Local_u8counter=0 ; Local_u8counter < 8 ; Local_u8counter++)
	 {
		 LCD_LcdErrStateSendChar(LCD,PTR_u8SpCharacter[Local_u8counter]);
	 }
	 /*back to DDRAM*/
	 LCD_LcdErrStateSendCommand(LCD,DDRAM_ADDRES);/*0x80 DDRAM address*/
	 /*print the special character */

 }
 void LCD_voidSndSpecialCahracter(LCD_info_t* LCD, BLOCK_NUM_t BLOCK_NUM )
 {
	 /*print the special character */
	 LCD_LcdErrStateSendChar(LCD,BLOCK_NUM);
 }

