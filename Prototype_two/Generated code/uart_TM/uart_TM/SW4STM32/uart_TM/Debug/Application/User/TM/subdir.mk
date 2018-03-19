################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/phiwersports/Documents/exjobb/TM_STM32_lib/tm_stm32_buffer.c \
C:/Users/phiwersports/Documents/exjobb/TM_STM32_lib/tm_stm32_gpio.c \
C:/Users/phiwersports/Documents/exjobb/TM_STM32_lib/tm_stm32_usart.c 

OBJS += \
./Application/User/TM/tm_stm32_buffer.o \
./Application/User/TM/tm_stm32_gpio.o \
./Application/User/TM/tm_stm32_usart.o 

C_DEPS += \
./Application/User/TM/tm_stm32_buffer.d \
./Application/User/TM/tm_stm32_gpio.d \
./Application/User/TM/tm_stm32_usart.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/TM/tm_stm32_buffer.o: C:/Users/phiwersports/Documents/exjobb/TM_STM32_lib/tm_stm32_buffer.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/phiwersports/Desktop/Projects/Generated code/uart_TM/uart_TM/Inc" -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/STM32L4xx_HAL_Driver/Inc -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/CMSIS/Device/ST/STM32L4xx/Include -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/CMSIS/Include -I"C:/Users/phiwersports/Documents/exjobb/TM_STM32_lib/h_files"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/TM/tm_stm32_buffer.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/TM/tm_stm32_gpio.o: C:/Users/phiwersports/Documents/exjobb/TM_STM32_lib/tm_stm32_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/phiwersports/Desktop/Projects/Generated code/uart_TM/uart_TM/Inc" -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/STM32L4xx_HAL_Driver/Inc -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/CMSIS/Device/ST/STM32L4xx/Include -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/CMSIS/Include -I"C:/Users/phiwersports/Documents/exjobb/TM_STM32_lib/h_files"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/TM/tm_stm32_gpio.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/TM/tm_stm32_usart.o: C:/Users/phiwersports/Documents/exjobb/TM_STM32_lib/tm_stm32_usart.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/phiwersports/Desktop/Projects/Generated code/uart_TM/uart_TM/Inc" -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/STM32L4xx_HAL_Driver/Inc -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/CMSIS/Device/ST/STM32L4xx/Include -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/CMSIS/Include -I"C:/Users/phiwersports/Documents/exjobb/TM_STM32_lib/h_files"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/TM/tm_stm32_usart.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


