/*******************************************************************************************************************************
 * Author: Karen Bassem
 * File Name: ADC_driver.c
 * Description: source file for ADC using polling technique
 * Module: ADC driver
 ******************************************************************************************************************************/

#include "ADC_driver.h"
void ADC_init(const ADC_ConfigType * Config_Ptr){

	ADMUX= (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6);   /* To choose the voltage reference at bit 6&7 as given*/
	ADCSRA=(1<<ADEN);                                    /* enable ADC */
	ADCSRA = (ADCSRA & 0xF8)|(Config_Ptr->prescaler);  /* select the prescaler value given */
}

uint16 ADC_readChannel(uint8 Ch_num){
	/* channel number must be 3 bits only
	 * put channel number in 5 LSB after clearing them */
	ADMUX = (ADMUX & 0xE0) | (Ch_num & 0x07);
	SET_BIT(ADCSRA,ADSC);                /* Start conversion */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)){};  /* Polling until ADIF is set */
	SET_BIT(ADCSRA,ADIF);                /* CLEAR flag by logical 1 */
	return ADC;
}
