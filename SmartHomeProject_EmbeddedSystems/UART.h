/*
 * uart.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ahmedRaafat
 */

#ifndef UART_H
#define UART_H

/*include the configuration file*/
#include "uart_cfg.h"

/*define the required interfaces for different functions*/

/*initialize function that set the baud rate frame format(parit,stop,data bits)*/
extern void uart_init(void);

unsigned char read_uart(void);

void write_uart(unsigned char data);

#endif

