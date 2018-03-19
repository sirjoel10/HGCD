################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/phiwersports/Desktop/Projects/Generated\ code/uart_TM/uart_TM/Src/main.c \
C:/Users/phiwersports/Desktop/Projects/Generated\ code/uart_TM/uart_TM/Src/stm32l4xx_hal_msp.c \
C:/Users/phiwersports/Desktop/Projects/Generated\ code/uart_TM/uart_TM/Src/stm32l4xx_it.c 

OBJS += \
./Application/User/main.o \
./Application/User/stm32l4xx_hal_msp.o \
./Application/User/stm32l4xx_it.o 

C_DEPS += \
./Application/User/main.d \
./Application/User/stm32l4xx_hal_msp.d \
./Application/User/stm32l4xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/main.o: C:/Users/phiwersports/Desktop/Projects/Generated\ code/uart_TM/uart_TM/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/phiwersports/Desktop/Projects/Generated code/uart_TM/uart_TM/Inc" -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/STM32L4xx_HAL_Driver/Inc -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/CMSIS/Device/ST/STM32L4xx/Include -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/CMSIS/Include -I"C:/Users/phiwersports/Documents/exjobb/TM_STM32_lib/h_files"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/main.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32l4xx_hal_msp.o: C:/Users/phiwersports/Desktop/Projects/Generated\ code/uart_TM/uart_TM/Src/stm32l4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/phiwersports/Desktop/Projects/Generated code/uart_TM/uart_TM/Inc" -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/STM32L4xx_HAL_Driver/Inc -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/CMSIS/Device/ST/STM32L4xx/Include -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/CMSIS/Include -I"C:/Users/phiwersports/Documents/exjobb/TM_STM32_lib/h_files"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/stm32l4xx_hal_msp.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32l4xx_it.o: C:/Users/phiwersports/Desktop/Projects/Generated\ code/uart_TM/uart_TM/Src/stm32l4xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/phiwersports/Desktop/Projects/Generated code/uart_TM/uart_TM/Inc" -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/STM32L4xx_HAL_Driver/Inc -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/CMSIS/Device/ST/STM32L4xx/Include -IC:/Users/phiwersports/STM32Cube/Repository/STM32Cube_FW_L4_V1.11.0/Drivers/CMSIS/Include -I"C:/Users/phiwersports/Documents/exjobb/TM_STM32_lib/h_files"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/stm32l4xx_it.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


