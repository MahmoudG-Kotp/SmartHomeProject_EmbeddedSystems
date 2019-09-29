/*
 * LED.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */
#include "util/delay.h"
#include "STD_TYPES.h"
#include "DIO.h"
#include "LED.h"

void LED_Initialize(u8 LED_Channel)
{
	DIO_voidSetDDR(LED_Channel, HIGH);
}

void LED_ON(u8 LED_Channel)
{
	DIO_voidSetPin(LED_Channel, HIGH);
}

void LED_OFF(u8 LED_Channel)
{
	DIO_voidSetPin(LED_Channel, LOW);
}

void LED_Toggle(u8 LED_Channel)
{
	u8 LEDStatus = DIO_getPinVal(LED_Channel);
	DIO_voidSetPin(LED_Channel, (LEDStatus ^= 1));
}
