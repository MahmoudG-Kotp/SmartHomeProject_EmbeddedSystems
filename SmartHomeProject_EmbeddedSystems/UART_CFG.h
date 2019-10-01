/*
 * uart_cfg.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ahmedRaafat
 */

#ifndef UART_CFG_H
#define UART_CFG_H

/* define system frequency */
#define SYSTEM_FREQUENCY	(u32)8000000UL

/****** defines for configuration ****/

/* Parity */
#define NO_PARITY 	0
#define EVEN_PARITY 2
#define ODD_PARITY	3

/* data length */
#define FIVE_BITS	0
#define SIX_BITS	1
#define SEVEN_BITS	2
#define EIGHT_BITS	3
#define NINE_BITS	4

/* stop bits length */
#define ONE_STOP	0
#define TWO_STOPS	1

/*define the receive buffer length*/
#define RECIEVE_BUFFER_LENGTH 10

/*define struct that holds the parameters of the uart*/
typedef struct
{
	u32 baudRate;
	u8 parity;
	u8 dataLen;
	u8 stopLen;

}uart_cfg_t;


const extern uart_cfg_t uart_cfg[];

#endif


