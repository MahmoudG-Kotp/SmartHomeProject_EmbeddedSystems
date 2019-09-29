/*
 * Interrupts_List.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef INTERRUPTS_LIST_H
#define INTERRUPTS_LIST_H

//vectors is memory locations contains jump instructions to interrupt functions like reset
//non-maskable mean can't be disabled like reset
#define EXTI_INT0				   	__vector_1
#define EXTI_INT1				   	__vector_2
#define EXTI_INT2				   	__vector_3
#define TIMER2_COMP					__vector_4
#define TIMER2_OVF					__vector_5
#define TIMER1_CAPT					__vector_6
#define TIMER1_COMPA				__vector_7
#define TIMER1_COMPB				__vector_8
#define TIMER1_OVF					__vector_9
#define TIMER0_COMP					__vector_10
#define TIMER0_OVF					__vector_11
#define SPI_STC						__vector_12
#define USART_RXC					__vector_13
#define USART_UDRE					__vector_14
#define USART_TXC					__vector_15
#define ADC							__vector_16


#endif /* INTERRUPTS_LIST_H_ */
