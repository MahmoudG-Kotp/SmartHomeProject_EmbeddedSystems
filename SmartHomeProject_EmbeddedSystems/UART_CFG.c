/*
 * uart_cfg.c
 *
 *  Created on: Mar 12, 2018
 *      Author: ahmedRaafat
 */

#include "STD_TYPES.h"
#include "uart_cfg.h"

/*define array that represents the array that holds the real configuration of the driver*/
const uart_cfg_t uart_cfg[]=
{
		{(u32)9600,NO_PARITY,EIGHT_BITS,ONE_STOP}
};

