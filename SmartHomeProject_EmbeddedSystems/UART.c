/*

 * uart.c
 *
 *  Created on: Mar 12, 2018
 *      Author: ahmedRaafat
 */

/*include the required headers*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "uart.h"
#include "GIE.h"

/*define the needed registers needed by the uart*/
#define UBRRH *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)
#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRC *((volatile u8*)0x40)
#define UDR   *((volatile u8*)0x2C)


/****** bits of UCSRB ******/
#define UCSZ2 2
#define RXCIE 7
#define RXEN 4
#define TXEN 3

/***** bits of UCRSA ****/
#define UDRE 5
#define RXC 7
#define TXC 6

/*** bits of UCSRC ***/
#define URSEL	7
#define UMSEL	6
#define UPM1	5
#define UPM0	4
#define USBS	3
#define UCSZ1	2
#define UCSZ0	1
#define UCPOL	0
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

extern void uart_init(void)
{

	  UBRRL = BAUD_PRESCALE;// Load lower 8-bits into the low byte of the UBRR register
	  UBRRH = (BAUD_PRESCALE >> 8);
		 /* Load upper 8-bits into the high byte of the UBRR register
	    Default frame format is 8 data bits, no parity, 1 stop bit
	  to change use UCSRC, see AVR datasheet*/

	  // Enable receiver and transmitter and receive complete interrupt
	  UCSRB = ((1<<TXEN)|(1<<RXEN) | (1<<RXCIE));
}

void write_uart(unsigned char data)
{
	while(!(UCSRA&(1<<UDRE)));
	UDR=data;
	while(!(UCSRA&(1<<TXC)));
}

/*receive a character through UART*/
unsigned char read_uart()
{
	unsigned char data;
	while(!(UCSRA&(1<<RXC)));
	data=UDR;
	return data;
}
