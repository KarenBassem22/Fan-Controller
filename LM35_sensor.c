/******************************************************************************
 * Module: Temperature LM35 Sensor
 * File Name: lm35_sensor.c
 * Description: source file for the LM35 Temperature Sensor driver
 * Author: Karen Bassem
 *******************************************************************************/

#include "LM35_sensor.h"
#include "LCD_driver.h"
#include "ADC_driver.h"

/* Function to calculate the temperature from the ADC digital value */
uint8 LM35_getTemperature(void)
{
	uint16 adc_value = 0;
	adc_value = ADC_readChannel(ADC_CHANNEL_USED); /* read the channel where the sensor is connected */
	return (uint8)(((uint32)adc_value*SENSOR_MAX_TEMP*VREF)/(ADC_MAX_VALUE*SENSOR_MAX_VOLT)); /* Calculate the temperature using equation*/
}
