################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/phiwersports/Desktop/Projects/Generated\ code/uart_TM/uart_TM/Src/system_stm32l4xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32l4xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32l4xx.o: C:/Users/phiwersports/Desktop/Projects/Generated\ code/uart_TM/uart_TM/Src/system_stm32l4xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/phiwersports/Desktop/Projects/Generated code/uart_TM/uart_TM/Inc" -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/STM32L4xx_HAL_Driver/Inc -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/CMSIS/Device/ST/STM32L4xx/Include -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/CMSIS/Include -I"C:/Users/phiwersports/Documents/exjobb/TM_STM32_lib/h_files"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Drivers/CMSIS/system_stm32l4xx.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


