/*
 * File name: ADC_driver.h
 * Description: Header file for ADC driver
 * Module: ADC
 * Author: Karen Bassem
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "gpio.h"
#include "common_macros.h"
#include "std_types.h"
#include "avr\io.h"

/************************************************************************************************************/
                                          /* Type definitions */
/************************************************************************************************************/
typedef enum{
	AREF,AVCC,INTERNAL=3
}ADC_ReferenceVoltage;

typedef enum{
	PRESCALER_1,PRESCALER_2,PRESCALER_4,PRESCALER_8,PRESCALER_16,PRESCALER_32,PRESCALER_64,PRESCALER_128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/************************************************************************************************************/
                                            /* Definitions */
/************************************************************************************************************/
#define ADC_CHANNEL_USED 2
#define VREF 2.56          /* INTERNAL */
#define ADC_MAX_VALUE 1023 /* 2^10 */

/************************************************************************************************************/
                                       /* ADC function prototypes */
/************************************************************************************************************/
void ADC_init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_readChannel(uint8 Ch_num);


#endif /* ADC_DRIVER_H_ */
