/*
 * LED.h
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#ifndef LED_H
#define LED_H

typedef enum {
	LED_CHANNEL_0 = 0,
	LED_CHANNEL_1,
	LED_CHANNEL_2
}LED_Channels;

/*LEDs Controlling*/
void LED_Initialize();
void LED_ON(u8 LED_Channel);
void LED_OFF(u8 LED_Channel);
void LED_Toggle(u8 LED_Channel);

#endif // LED_H
