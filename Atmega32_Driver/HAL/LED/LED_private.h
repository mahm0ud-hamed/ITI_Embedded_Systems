/*
 * LED_private.h
 *
 *  Created on: Mar 24, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef HAL_LEDS_LED_PRIVATE_H_
#define HAL_LEDS_LED_PRIVATE_H_

/*data type for determining the type of connection between led and microcontroller */
typedef enum
{
	Sinkconnection,
	sourceconnection
}LED_connectionType_t;

/*data type that will carry the port and pin and type of connection of led */
typedef struct
{
	DIO_DIR_t  LED_PORT;
	DIO_PIN_t  LED_PIN ;
	LED_connectionType_t connection_type;

}LED_Info_t;

/*data type for determining the error that return from calling led functions  */
typedef enum
{
	NoError,
	LedPortError,
	LedConnectionError
}LED_ErrState_t;

#endif /* HAL_LEDS_LED_PRIVATE_H_ */
