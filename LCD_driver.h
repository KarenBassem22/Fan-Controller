/*
 * Author: Karen Bassem Thabet
 * File Name: LCD_drive.h
 * Description: Header file for LCD driver
 * Module: LCD
 */

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#include "common_macros.h"
#include "gpio.h"
#include "std_types.h"
#include "util\delay.h"

/* define control pins numbers */
#define RS_PIN 4//0
#define RW_PIN 5//1
#define E_PIN 6//2

/* define LCD ports */
#define LCD_CONTROL_PORT PORTD_ID
#define LCD_DATA_PORT PORTC_ID

/* control commands */
#define LCD_TWO_LINES_8_BITS 0x38
#define LCD_CLEAR_COMMAND 0x01
#define LCD_CURSOR_OFF 0x0C

/* function prototypes */
void LCD_sendCommand(uint8 command);
void LCD_init(void);
void LCD_displayCharacter(uint8 element);
void LCD_displayString(const uint8 * str);

#endif /* LCD_DRIVER_H_ */
