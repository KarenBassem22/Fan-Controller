/*
 * Author: Karen Bassem Thabet
 * File Name: LM35_sensor.h
 * Description: Header file for LM35 sensor
 * Module: LM35 sensor
 */


#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"
#include "ADC_driver.h"

/* DEFINITIONS */
#define SENSOR_MAX_TEMP 150
#define SENSOR_MAX_VOLT 1.5

/* FUNCTION PROTOTYPE */
uint8 LM35_GetTemperature();

#endif /* LM35_SENSOR_H_ */
