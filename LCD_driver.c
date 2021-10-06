/*
 * Author: Karen Bassem Thabet
 * File Name: LCD_drive.c
 * Description: Source file for LCD driver
 * Module: LCD
 */

/* TESTED */
#include "LCD_driver.h"

void LCD_sendCommand(uint8 command){
	GPIO_writePin(LCD_CONTROL_PORT, RS_PIN, LOGIC_LOW);
	GPIO_writePin(LCD_CONTROL_PORT, RW_PIN, LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(LCD_CONTROL_PORT, E_PIN, LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePort(LCD_DATA_PORT, command);  /* htala3 el command 3al port bta3y */
	_delay_ms(1);
	GPIO_writePin(LCD_CONTROL_PORT, E_PIN, LOGIC_LOW);
	_delay_ms(1);
}

void LCD_init(void){
	GPIO_setupPinDirection(LCD_CONTROL_PORT, RS_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_CONTROL_PORT, RW_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_CONTROL_PORT, E_PIN, PIN_OUTPUT);
	GPIO_setupPortDirection(LCD_DATA_PORT,  PORT_OUTPUT);
	LCD_sendCommand(LCD_TWO_LINES_8_BITS);  /* 2 line, 8_bits mode */
	LCD_sendCommand(LCD_CURSOR_OFF);
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}

void LCD_displayCharacter(uint8 element){
	GPIO_writePin(LCD_CONTROL_PORT, RS_PIN, LOGIC_HIGH);
	GPIO_writePin(LCD_CONTROL_PORT, RW_PIN, LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(LCD_CONTROL_PORT, E_PIN, LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePort(LCD_DATA_PORT, element);
	_delay_ms(1);
	GPIO_writePin(LCD_CONTROL_PORT, E_PIN, LOGIC_LOW);
	_delay_ms(1);
}

void LCD_displayString(const uint8 * str){
	while(*str!='\0'){
		LCD_displayCharacter(*str);
		str++;
	}
}
