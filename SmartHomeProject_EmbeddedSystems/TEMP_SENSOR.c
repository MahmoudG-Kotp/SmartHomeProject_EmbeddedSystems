/*
 * Temp_Sensor.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#include "DIO.h"
#include "ADC.h"
#include <stdlib.h>
#include "TEMP_SENSOR.h"

void TEMP_Initialize()
{
	DIO_voidSetDDR(LM35, LOW); //Set LM35 Input
	ADC_Init();
}

u8 TEMP_READ()
{
	return (((ADC_GetResult(0))*4.88f)/10);
}


void TEMP_STR_READ(char *strPtr)
{
	itoa(TEMP_READ(), strPtr, 10);
}

