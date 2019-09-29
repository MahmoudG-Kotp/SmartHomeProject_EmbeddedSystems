#ifndef TIM_REG_H_
#define TIM_REG_H_

#define TCCR0 *((u8*)0x53) //Timer/Counter Control Register >> control OC behavior and Prescaler
#define TCNT0 *((u8*)0x52) //Timer/Counter Location of Counts >> you can read from to know which u count u r in
#define TIMSK *((u8*)0x59) //Timer Interrupt Mask Register >> control interrupts of Timer if Overflow or Compare match occurred
#define TIFR  *((u8*)0x58)  //Enables TIMSK Register (CAUSE IT'S INTERRUPT)
#define OCR0  *((u8*)0x5C)  //Output Compare Register >> Location of OC value >> save OC value in this register

#endif /* TIM_REG_H_ */
