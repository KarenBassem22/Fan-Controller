/*
 * Author: Karen Bassem Thabet
 * File Name: third_mini_project.c
 * Description: fan controller system
 * Date: 5/10/2021
 */

#include "third_mini_project.h"

int main(void){

	ADC_ConfigType* configPtr;           /* structure of type ADC_ConfigType */
	configPtr->prescaler = PRESCALER_8;  /* choose prescaler 8 as needed */
	configPtr->ref_volt = INTERNAL;      /* choose with internal 2.56 volt */
	ADC_init(configPtr);                 /* pass pointer to structure to ADC_init function after setting its values */

	LCD_init();                          /* LCD initialization */
  LCD_displayCharacter('k');         /* test LCD */
  LCD_displayString("Temp = ");
	//LCD_intToString(LM35_GetTemperature());
	while(1){

	}
}
