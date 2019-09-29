/*
 * Fan.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */
#include "DIO.h"
#include "Fan.h"

void Fan_Initialize()
{
	DIO_voidSetDDR(DC_MOTOR, HIGH); //Set DDR Output
}

void Fan_ON()
{

	DIO_voidSetPin(DC_MOTOR, HIGH);
}

void Fan_OFF()
{
	DIO_voidSetPin(DC_MOTOR, LOW);
}
