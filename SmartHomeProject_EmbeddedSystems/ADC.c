/*
 * ADC.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#include "BIT_MATH.h"
#include "ADC_REG.h"
#include "ADC_CFG.h"
#include "ADC.h"

void ADC_Init(void)
{
	ADMUX = ADMUX_ENABLE_MSK;
	ADCSRA = ADCSRA_ENABLE_MSK;
}

u16 ADC_GetResult(u8 ADC_Channel) {

	ADC_Channel &= ADC_CHANNEL_CLEAR_MSK;

	ADMUX &= ADMUX_CLEAR_MSK;
	/* choose the correct channel by setting the channel number in MUX4:0 bits */
	ADMUX |= ADC_Channel;

	ADCSRA |= START_CONVERSION_MSK;

	/* wait for conversion to complete ADIF becomes '1' */
	while(GET_BIT(ADCSRA, 4) == LOW);

	ADCSRA |= ADIF_CLEAR_MSK;
	return ADC;/* return the data register */
}
