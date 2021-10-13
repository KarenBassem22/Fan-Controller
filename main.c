/*
 * Author: Karen Bassem Thabet
 * File Name: third_mini_project.c
 * Description: fan controller system
 * Date: 5/10/2021
 */

#include "third_mini_project.h"

int main(void){
	LCD_init();                               /* initialise LCD */

	ADC_ConfigType configPtr={INTERNAL,PRESCALER_8};
	ADC_init(&configPtr);                     /* pass pointer to structure to ADC_init function after setting its values */


	DcMotor_Init();                           /* initialise the motor */

	DcMotor_State fan_state;
	uint8 fan_temp=0;
	LCD_displayStringRowColumn(0,3,"FAN IS ");
	LCD_displayStringRowColumn(1,3,"TEMP=     C");

	while(1){

		fan_temp=LM35_getTemperature();       /* assign the digital value calculated to the temperature value */
		LCD_moveCursor(1,9);
		LCD_integerToString(fan_temp);

		if(fan_temp<30){
			fan_state=OFF;
			DcMotor_Rotate(STOP,DUTY_CYCLE_0);/* SPEED=0 */
		}
		else if((fan_temp>=30)&&(fan_temp<60)){
			fan_state=ON;
			DcMotor_Rotate(CW,DUTY_CYCLE_25); /* SPEED=25% of max speed */
		}
		else if((fan_temp>=60)&&(fan_temp<90)){
			fan_state=ON;
			DcMotor_Rotate(CW,DUTY_CYCLE_50); /* SPEED=50% of max speed */
		}
		else if ((fan_temp>=90)&&(fan_temp<120)){
			fan_state=ON;
			DcMotor_Rotate(CW,DUTY_CYCLE_75); /* SPEED=75% of max speed */
		}
		else if ((fan_temp>=120)&&(fan_temp<=150)){
			fan_state=ON;
			DcMotor_Rotate(CW,DUTY_CYCLE_100);/* SPEED=100% of max speed */
		}
		else{
			fan_state=OFF;
			DcMotor_Rotate(STOP,DUTY_CYCLE_0);/* if temp > 150 close the fan... it will burn */
		}

		/* display fan state on LCD */
		if(fan_state==OFF){
			LCD_displayStringRowColumn(0,10,"OFF");
		}
		else
			LCD_displayStringRowColumn(0,10,"ON ");
	}
}


