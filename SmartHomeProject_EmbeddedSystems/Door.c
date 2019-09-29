/*
 * Door.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#include "BIT_MATH.h"
#include "util/delay.h"
#include "GIE.h"
#include "TIM.h"
#include "Door.h"

void Door_Initialize()
{
	TIM_voidInitialize();
}

void Door_OPEN()
{
	TIM_voidSetCompareValue(15);  //Open degree
}

void Door_CLOSE()
{
	TIM_voidSetCompareValue(200);  //Close degree
}

