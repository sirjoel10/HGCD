################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/phiwersports/Desktop/Projects/Generated\ code/uart2/uart2/Src/system_stm32l4xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32l4xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32l4xx.o: C:/Users/phiwersports/Desktop/Projects/Generated\ code/uart2/uart2/Src/system_stm32l4xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/phiwersports/Desktop/Projects/Generated code/uart2/uart2/Inc" -I"C:/Users/phiwersports/Documents/exjobb/TM_STM32_lib" -I"C:/Users/phiwersports/Desktop/Projects/Generated code/uart2/uart2/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/phiwersports/Desktop/Projects/Generated code/uart2/uart2/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/phiwersports/Desktop/Projects/Generated code/uart2/uart2/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/phiwersports/Desktop/Projects/Generated code/uart2/uart2/Drivers/CMSIS/Include"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Drivers/CMSIS/system_stm32l4xx.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


