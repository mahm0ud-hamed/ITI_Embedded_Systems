/*
 * ADC_interface.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef MACL_ADC_ADC_INTERFACE_H_
#define MACL_ADC_ADC_INTERFACE_H_
#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_config.h"


/*function initialize analog to digital converter */
void ADC_voidInit(void);
/*start conversion of chanel on 8 bit mode*/
u8 ADC_u8Conversion(ADC_CHANEL Chanel);
/*start convert on chanel for 10 bit mode */
u16  ADC_u16Conversion(ADC_CHANEL Chanel);
/*function to enable analog to digital converter */
void ADC_voidEnable(void);
/*function to disable analog to digital converter */
void ADC_voidDisable(void);

/*calculate analog value that help to understand the value  of sensor refer to */
u16 ADC_voidCalculateAnalog(u16 copy_u16DigitalValue);

ADC_ERR ADC_ADCERRConversionSynchrounous(ADC_CHANEL chanel , u16 * copy_Pu16Result);
ADC_ERR ADC_ADCERRConversionASynchrounous(ADC_CHANEL chanel , u16 *copy_pu16Result , void (*copy_PvNotificationfunction)(void ));
#endif /* MACL_ADC_ADC_INTERFACE_H_ */
