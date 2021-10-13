/****************************************************************************************************************************
 * Author: Karen Bassem Thabet
 * File Name: LCD_drive.c
 * Description: Source file for LCD driver
 * Module: LCD
 ***************************************************************************************************************************/

#include <util/delay.h> /* For the delay functions */
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "LCD_driver.h"
#include "gpio.h"


/* function to initialise the LCD */
void LCD_init(void)
{
	/* Configure the direction for RS, RW and E pins as output pins */
	GPIO_setupPinDirection(LCD_RS_PORT_ID,RS_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_RW_PORT_ID,RW_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_E_PORT_ID,E_PIN,PIN_OUTPUT);

	/* Configure the data port as output port */
	GPIO_setupPortDirection(LCD_DATA_PORT_ID,PORT_OUTPUT);  /* data port as output to receive the data to display */

	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);   /* 2 lines, 8_bits mode, 5*7 dot display Mode */

	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */

	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

/* function to send the command to be executed by LCD */
/* the function receive the command as an argument passed to it */
/* delays are calculated according to data sheet */
void LCD_sendCommand(uint8 command)
{
	GPIO_writePin(LCD_RS_PORT_ID,RS_PIN,LOGIC_LOW); /* RS=0 to use it with commands */
	GPIO_writePin(LCD_RW_PORT_ID,RW_PIN,LOGIC_LOW); /* RW=0 to write on LCD */
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID,E_PIN,LOGIC_HIGH); /* Enable LCD */
	_delay_ms(1);
	GPIO_writePort(LCD_DATA_PORT_ID,command); /* htala3 el command 3al port bta3y */
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID,E_PIN,LOGIC_LOW); /* Disable LCD */
	_delay_ms(1);
}

/* function to display a character on LCD */
/* the function takes a uint8 parameter which will be displayed */
void LCD_displayCharacter(uint8 data)
{
	GPIO_writePin(LCD_RS_PORT_ID,RS_PIN,LOGIC_HIGH); /* Data Mode RS=1 */
	GPIO_writePin(LCD_RW_PORT_ID,RW_PIN,LOGIC_LOW); /* RW=0 to write on LCD */
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID,E_PIN,LOGIC_HIGH); /* Enable LCD */
	_delay_ms(1);
	GPIO_writePort(LCD_DATA_PORT_ID,data); /* htala3 el command 3al port bta3y */
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID,E_PIN,LOGIC_LOW); /* Disable LCD */
	_delay_ms(1);
}


/* function to display a string on LCD */
/* the function recieves the string to be displayed as an argument */
void LCD_displayString(const char *Str)
{

	while(*Str != '\0')
	{
		LCD_displayCharacter(*Str);
		Str++;
	}

}

/* Move the cursor to a specified row and column index on the screen */
void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
	case 0:
		lcd_memory_address=col;
		break;
	case 1:
		lcd_memory_address=col+0x40;
		break;
	case 2:
		lcd_memory_address=col+0x10;
		break;
	case 3:
		lcd_memory_address=col+0x50;
		break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/* Display the required string in a specified row and column index on the screen */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

/* Display the required decimal value on the screen */
void LCD_integerToString(int data)
{
	char buff[16]; /* String to hold the ascii result */
	itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_displayString(buff); /* Display the string */
}

/* Send the clear screen command */
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}


