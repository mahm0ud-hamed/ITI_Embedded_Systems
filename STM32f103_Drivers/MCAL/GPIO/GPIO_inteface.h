/*
 * GPIO_inteface.h
 *
 *  Created on: May 24, 2023
 *      Author: hp
 */

#ifndef GPIO_GPIO_INTEFACE_H_
#define GPIO_GPIO_INTEFACE_H_

/**************** includes **********************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/utility.h"


/**************** defines ***********************/


#define SET 0
#define RESET 1
#define PIN_VAL_LOW  0
#define PIN_VAL_HIGH   1

/*pin output speed */
enum PinOutSpeed{
	pinOutSpeed_10MHz,
	pinOutSpeed_2MHz,
	pinOutSpeed_50MHz
};

/*pin output configuration */
enum PinOutConfg{
	PinOutConfgGP_PushPull ,
	PinOutConfgGP_OpenDrain,
	PinOutConfgALT_PushPull,
	PinOutConfgALT_OpenDrain
};

/*pin input configuration  */
enum PinInpConfg{
	PinInpConfg_Analog ,
	PinInpConfg_Floating,
	PinInpConfg_InPllDwn ,
	PinInpConfg_InPllUp=2
};

/*port numbers */
enum POTR_x{
	PORT_A ,
	PORT_B ,
	PORT_C ,
};

/*pin numbers */
enum PIN_x{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15
};

/**************** data types ********************/




/******** interface function prototype **********/

Err_st GPIO_SetPinOutPut(u32 PORT_x , u32 PIN_x , u32 PinOutSpeed , u32 PinOutConfg );

Err_st GPIO_SetPinInput(u32 PORT_x , u32 PIN_x , u32 PinInpConfg );

Err_st GPIO_SetPinValue(u32 PORT_x , u32 PIN_X , u32 PIN_VAL) ;

Err_st GPIO_GetPinValue(u32 PORT_x , u32 PIN_x , u32 * PIN_RET_VAL );

Err_st GPIO_SetPortValue(u32 PORT_x , u32 PORT_VALUE) ;

Err_st GPIO_GetPortValue(u32 PORT_x , u32 *PORT_RET_VALUE );

Err_st GPIO_Set_Reset_PinValue(u32 PORT_x  , u32 PIN_x , u32 SET_REST);


Err_st GPIO_ResetPinValue(u32 PORT_x , u32 PIN_x );




/*************************************************/
#endif /* GPIO_GPIO_INTEFACE_H_ */
