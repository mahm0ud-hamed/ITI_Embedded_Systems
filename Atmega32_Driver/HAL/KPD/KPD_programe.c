/*
 * KPD_programe.c
 *
 *  Created on: Mar 28, 2023
 *      Author: Mahmoud Hamed
 */

#include "../../LIB/STD_TYPES.h"

#include "../../MACL/DIO/DIO_interface.h"
#include "KPD_interface.h"
#include "../LCD/LCD_interface.h"

/*extern the LCD info variable from main file */
extern LCD_info_t LCD ;

void KPD_ErrStateInit(void)
{
	/*set all columns as internal pulled up resistor
	 * 1- set input
	 * 2- write one to activate pull up */
/******************1- set input *******************************/
	DIO_ErrStateSetPinDirec(KPD_COL_PORT,KPD_COL1,DIO_U8_INPUT);
	DIO_ErrStateSetPinDirec(KPD_COL_PORT,KPD_COL2,DIO_U8_INPUT);
	DIO_ErrStateSetPinDirec(KPD_COL_PORT,KPD_COL3,DIO_U8_INPUT);
	DIO_ErrStateSetPinDirec(KPD_COL_PORT,KPD_COL4,DIO_U8_INPUT);

/******************2- write one to activate pull up ***********/
	DIO_ErrStateSetPinValue(KPD_COL_PORT,KPD_COL1,DIO_U8_HIGH);
	DIO_ErrStateSetPinValue(KPD_COL_PORT,KPD_COL2,DIO_U8_HIGH);
	DIO_ErrStateSetPinValue(KPD_COL_PORT,KPD_COL3,DIO_U8_HIGH);
	DIO_ErrStateSetPinValue(KPD_COL_PORT,KPD_COL4,DIO_U8_HIGH);

	/*set all row pins as output high
	 * 1- set direction as output
	 * 2- write one to set as high */
/***************** 1- set as OUTPUT *****************************/
	DIO_ErrStateSetPinDirec(KPD_ROW_PORT,KPD_ROW1,DIO_U8_OUTPUT);
	DIO_ErrStateSetPinDirec(KPD_ROW_PORT,KPD_ROW2,DIO_U8_OUTPUT);
	DIO_ErrStateSetPinDirec(KPD_ROW_PORT,KPD_ROW3,DIO_U8_OUTPUT);
	DIO_ErrStateSetPinDirec(KPD_ROW_PORT,KPD_ROW4,DIO_U8_OUTPUT);

/**************** 2- write one to set as high *******************/

	DIO_ErrStateSetPinValue(KPD_ROW_PORT,KPD_ROW1,DIO_U8_HIGH);
	DIO_ErrStateSetPinValue(KPD_ROW_PORT,KPD_ROW2,DIO_U8_HIGH);
	DIO_ErrStateSetPinValue(KPD_ROW_PORT,KPD_ROW3,DIO_U8_HIGH);
	DIO_ErrStateSetPinValue(KPD_ROW_PORT,KPD_ROW4,DIO_U8_HIGH);



	//return KPD_NoError;
}


KPD_ErrState_t KPD_ErrStateGetPressedKey( u8 *copy_u8GetValue)
{
	/*flag to check if the right column have pressed button */
	u8 flag =0;
	/*variables to iterate on rows  */
	u8 Local_u8ROWCounter;
	/*variables to iterate on columns   */
	u8 Local_u8COLCounter;
	/*variable for reading the pressed button */
	u8 Local_u8PressedKey =KPD_NOTPRESSED ;
	/*looping for all ROW pins and set it one by one LOW and read columns on this time */
	for (Local_u8ROWCounter =0 ; Local_u8ROWCounter< ROW_SIZE; Local_u8ROWCounter++  )
	{
		/*set the current row pin as low */
		DIO_ErrStateSetPinValue(KPD_ROW_PORT,KPD_ROWS[Local_u8ROWCounter],DIO_U8_LOW);
		/*looping for the columns pin and check which one is pressed */
		for (Local_u8COLCounter = 0 ;  Local_u8COLCounter < COL_SIZE; Local_u8COLCounter++)
		{
			/*read the current columns state */
			DIO_ErrStateReadPinValue(KPD_COL_PORT,KPD_COLS[Local_u8COLCounter],&Local_u8PressedKey);

			if(Local_u8PressedKey == DIO_U8_LOW )
			{

				flag = 1;
				while(Local_u8PressedKey == DIO_U8_LOW)
				{
					DIO_ErrStateReadPinValue(KPD_COL_PORT,KPD_COLS[Local_u8COLCounter],&Local_u8PressedKey);
				}

			}
			if(flag == 1 )
			{
				*copy_u8GetValue =  KPD_BUTTONS[Local_u8ROWCounter][Local_u8COLCounter];
				return KPD_NoError ;
			}
		}
		/*if the current key columns have no pressed then return the row pin to its initial state */
		DIO_ErrStateSetPinValue(KPD_ROW_PORT,KPD_ROWS[Local_u8ROWCounter],DIO_U8_HIGH);

	}

	return KPD_NoError;
}


KPD_ErrState_t KPD_ErrStateGetPressedValue( u16 * copy_u8GetValue)
{
	/*variable to carry the actual value of all digits gits from keypad*/
	u16 Local_u16Sum =0 ;
	/*variable used to get one digi from keypad*/
	u8  Local_u8PressedKey = KPD_NOTPRESSED ;
	/*loop until the pressed key equal '='*/
	do
	{

		/*loop to get one digit from keypad*/
		do
		{
			KPD_ErrStateGetPressedKey(&Local_u8PressedKey);

		}while(Local_u8PressedKey == KPD_NOTPRESSED);

		/*check if pressed key equal '='*/
		if(Local_u8PressedKey == '=')
		{
			LCD_voidClearDispla(&LCD);
			* copy_u8GetValue = Local_u16Sum ;
			return KPD_NoError;
		}
		else
		{

			/*multiply sum by 10 and add the new digit to it */
			Local_u16Sum= (Local_u16Sum*10+(Local_u8PressedKey-'0'));
			LCD_voidClearDispla(&LCD);

		}
		/*return pressed key to it initial value not pressed */
		Local_u8PressedKey = KPD_NOTPRESSED;
		/*send current number to LCD*/
		LCD_LcdErrStateSendNumber(&LCD,Local_u16Sum);

	}while (Local_u8PressedKey != '=' );

}

