/*
 * main.c
 *
 *  Created on: Sep 29, 2019
 *      Author: MahmoudGamal
 */

#include "STD_TYPES.h"
#include "util/delay.h"
#include "LED.h"
#include "LCD.h"
#include "UART.h"
#include "SERVO.h"
#include "BUZZER.h"
#include "Keypad.h"
#include "DC_MOTOR.h"
#include "TEMP_SENSOR.h"
#include "EXTI.h"

#define HOME_PASSWORD 2411

void IntializeDrivers(void);
void WirelessControl(void);

int main()
{
	IntializeDrivers();
	while(1)
	{

	}//end of 1st while
}

void IntializeDrivers(void)
{
	LED_Initialize();
	LCD_Initialize();
	UART_Initialize();
	SERVO_Initialize();
	BUZZER_Initialize();
	Keypad_Intialize();
	DC_MOTOR_Initialize();
	TEMP_Initialize();
	EXTI_Initialize();
}

void WirelessControl(void)
{
	switch(UART_Read())
	{
		case 1: LED_ON(LED_CHANNEL_0);
				break;

		case 2: LED_OFF(LED_CHANNEL_0);
				break;

		case 3: LED_ON(LED_CHANNEL_1);
				break;

		case 4: LED_OFF(LED_CHANNEL_1);
				break;

		case 5: LED_ON(LED_CHANNEL_2);
				break;

		case 6: LED_OFF(LED_CHANNEL_2);
				break;

		case 7: BUZZER_ON();
				break;

		case 8: BUZZER_OFF();
				break;

		case 9: SERVO_ON(); //OPEN DOOR
				break;

		case 10: SERVO_OFF(); //CLOSE DOOR
				 break;

		case 11: DC_MOTOR_ON(); //TURN FAN ON
				 break;

		case 12: DC_MOTOR_OFF(); //TURN FAN OFF
				 break;

		case 13: LCD_WriteString((u8*) "Testing ESPI");
				 break;

		case 14: LCD_Clear();
	}
}
