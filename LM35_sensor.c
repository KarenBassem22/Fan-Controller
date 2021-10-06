/*
 * Author: Karen Bassem Thabet
 * File Name: LM35_sensor.c
 * Description: Source file for LM35 sensor
 * Module: LM35 sensor
 */

#include "LM35_sensor.h"

uint8 LM35_GetTemperature(){
	uint16 digital_value;
	digital_value= ADC_readChannel(ADC_CHANNEL_USED);  /* pass channel number used to be read */
	return ((uint8)(((uint32)(digital_value*SENSOR_MAX_TEMP*VREF))/(SENSOR_MAX_VOLT*ADC_MAX_VALUE)));
}
