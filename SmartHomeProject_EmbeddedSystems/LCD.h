#ifndef LCD_H
#define LCD_H
#include"STD_TYPES.h"

#define COLUMN_ZERO 0x80 // 0x80 first panel on LCD
#define ROW_ZERO 0x40

#define LCD_CLEAR_CMD 0x01
#define LCD_DISPLAY_CMD 0X0E

#define LCD_8_MODE_CMD 0x38 //MODE 8 PINS
#define LCD_4_MODE_CMD_SEQ1 0x23 //MODE 4 PINS
#define LCD_4_MODE_CMD_SEQ2 0x22 //MODE 4 PINS
#define LCD_4_MODE_CMD_SEQ3 0x28 //MODE 4 PINS
#define F_CPU 16000000UL

void LCD_Initialize(void);
void LCD_Shift(u8 row, u8 column);
void LCD_WriteString(u8 *str);
void LCD_Clear();

#endif // LCD_H