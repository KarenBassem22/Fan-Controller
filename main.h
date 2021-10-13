/*
 * Author: Karen Bassem Thabet
 * File Name: third_mini_project.h
 * Description: fan controller system header file
 * Date: 5/10/2021
 */

#ifndef THIRD_MINI_PROJECT_H_
#define THIRD_MINI_PROJECT_H_

#include <stdio.h>
#include "common_macros.h"
#include "std_types.h"
#include "avr\io.h"
#include "gpio.h"
#include <util\delay.h>
#include "ADC_driver.h"
#include "PWM.h"
#include "DC_motor.h"
#include "LCD_driver.h"
#include "LM35_sensor.h"

/* to use to display fan state */
enum FAN_state{
	OFF,ON
};

#endif /* THIRD_MINI_PROJECT_H_ */
