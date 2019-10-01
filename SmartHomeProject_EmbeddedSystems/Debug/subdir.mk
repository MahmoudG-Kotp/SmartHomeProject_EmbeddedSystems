################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../BUZZER.c \
../DIO.c \
../Door.c \
../Fan.c \
../LCD.c \
../LED.c \
../TEMP_SENSOR.c \
../TIM.c \
../UART.c \
../UART_CFG.c \
../main.c 

OBJS += \
./ADC.o \
./BUZZER.o \
./DIO.o \
./Door.o \
./Fan.o \
./LCD.o \
./LED.o \
./TEMP_SENSOR.o \
./TIM.o \
./UART.o \
./UART_CFG.o \
./main.o 

C_DEPS += \
./ADC.d \
./BUZZER.d \
./DIO.d \
./Door.d \
./Fan.d \
./LCD.d \
./LED.d \
./TEMP_SENSOR.d \
./TIM.d \
./UART.d \
./UART_CFG.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


