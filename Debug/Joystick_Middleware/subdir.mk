################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Joystick_Middleware/Joystick_Middleware.c 

OBJS += \
./Joystick_Middleware/Joystick_Middleware.o 

C_DEPS += \
./Joystick_Middleware/Joystick_Middleware.d 


# Each subdirectory must supply rules for building sources it contributes
Joystick_Middleware/%.o Joystick_Middleware/%.su Joystick_Middleware/%.cyclo: ../Joystick_Middleware/%.c Joystick_Middleware/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/GPIO" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/DMA" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/USART" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/Console" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/ADC" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/Joystick_HAL" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/Joystick_Device_Driver" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/Joystick_Middleware" -I"B:/STM32F407V_Firmware_C_Lang/Joystick_Driver/Temp/Temp_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Joystick_Middleware

clean-Joystick_Middleware:
	-$(RM) ./Joystick_Middleware/Joystick_Middleware.cyclo ./Joystick_Middleware/Joystick_Middleware.d ./Joystick_Middleware/Joystick_Middleware.o ./Joystick_Middleware/Joystick_Middleware.su

.PHONY: clean-Joystick_Middleware

