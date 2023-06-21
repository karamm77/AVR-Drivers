################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BB_program.c \
../DIO_program.c \
../EXTI_program.c \
../GIE_program.c \
../SSegmant_program.c \
../main.c 

OBJS += \
./BB_program.o \
./DIO_program.o \
./EXTI_program.o \
./GIE_program.o \
./SSegmant_program.o \
./main.o 

C_DEPS += \
./BB_program.d \
./DIO_program.d \
./EXTI_program.d \
./GIE_program.d \
./SSegmant_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


