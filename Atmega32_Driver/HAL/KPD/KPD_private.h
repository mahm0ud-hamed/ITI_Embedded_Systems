/*
 * KPD_private.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef HAL_KPD_KPD_PRIVATE_H_
#define HAL_KPD_KPD_PRIVATE_H_


//typedef struct
//{
//	/*ports of KPD */
//	DIO_PORT_t KPD_ROW_PORT;
//	DIO_PORT_t KPD_COL_PORT;
//
//	/*pins of rows*/
//	DIO_PIN_t  KPD_ROW_Pin0;
//	DIO_PIN_t  KPD_ROW_Pin1;
//	DIO_PIN_t  KPD_ROW_Pin2;
//	DIO_PIN_t  KPD_ROW_Pin3;
//
//	/*pins of columns*/
//	DIO_PIN_t  KPD_COL_Pin0;
//	DIO_PIN_t  KPD_COL_Pin1;
//	DIO_PIN_t  KPD_COL_Pin2;
//	DIO_PIN_t  KPD_COL_Pin3;
//
//}KPD_info_t;




typedef enum {

	KPD_NoError ,
	KPD_RowPortError ,
	KPD_ColPortError,
	KPD_GetValueAdressError
}KPD_ErrState_t;



#endif /* HAL_KPD_KPD_PRIVATE_H_ */
