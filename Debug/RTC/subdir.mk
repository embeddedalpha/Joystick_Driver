################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTC/RTC.c 

OBJS += \
./RTC/RTC.o 

C_DEPS += \
./RTC/RTC.d 


# Each subdirectory must supply rules for building sources it contributes
RTC/%.o RTC/%.su RTC/%.cyclo: ../RTC/%.c RTC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/GPIO" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/DMA" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/USART" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/Console" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/ADC" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/Joystick_HAL" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/Joystick_Device_Driver" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/Joystick_Middleware" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-RTC

clean-RTC:
	-$(RM) ./RTC/RTC.cyclo ./RTC/RTC.d ./RTC/RTC.o ./RTC/RTC.su

.PHONY: clean-RTC

