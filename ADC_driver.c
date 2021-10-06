/*
 * File name: ADC_driver.c
 * Description: Source file for ADC driver using polling technique
 * Module: ADC
 * Author: Karen Bassem
 */
/* TESTED */

#include "ADC_driver.h"

void ADC_init(const ADC_ConfigType * Config_Ptr){
	ADMUX=((Config_Ptr->ref_volt)<<6);        /* To choose the voltage reference at bit 6&7 as given*/
	CLEAR_BIT(ADCSRA,ADIE);                   /* Disable ADC interrupt enable */
	ADCSRA=(1<<ADEN)|(Config_Ptr->prescaler); /* Enable ADC & select the prescaler value given */
}

uint16 ADC_readChannel(uint8 Ch_num){
	/* channel number must be 3 bits only
	 * put channel number in 5 LSB after clearing them */
	ADMUX&=(0b11100000)|(Ch_num&=0x07);
	SET_BIT(ADCSRA,ADSC);                /* Start conversion */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)){};  /* Polling until ADIF is set */
	SET_BIT(ADCSRA,ADIF);                /* CLEAR flag by logical 1 */
	return ADC;
}
