/******************************************************************************
 * Module: Temperature LM35 Sensor
 * File Name: lm35_sensor.h
 * Description: header file for the LM35 Temperature Sensor driver
 * Author: Karen Bassem
 *******************************************************************************/
#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_MAX_VOLT     1.5
#define SENSOR_MAX_TEMP    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* Function to calculate the temperature from the ADC digital value */
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
