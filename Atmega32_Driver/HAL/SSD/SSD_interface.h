/*
 * SSD_interface.h
 *
 *  Created on: Mar 26, 2023
 *      Author: Mahmoud Hamed
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_
#include "SSD_Config.h"
#include "SSD_private.h"


/*function to display particular number */
SevSegErrState_t SevSeg_SevSegErrStateDisplayNum(SevSeg_info_t *SSD ,u8 copy_u8Num);

/*function to display range of number between start and end */
SevSegErrState_t SevSeg_SevSegErrStateDisplayRange(SevSeg_info_t *SSD ,u8 copy_u8Start,u8 copy_u8End);

/*function to display numbers between zero and max */
SevSegErrState_t SevSeg_SevSegErrStateDisplayMax(SevSeg_info_t *SSD ,u8 copy_u8Max);

#endif /* HAL_SSD_SSD_INTERFACE_H_ */
