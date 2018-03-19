################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/String.c \
../Src/UART_Handler.c \
../Src/main.c \
../Src/stm32l4xx_hal_msp.c \
../Src/stm32l4xx_it.c \
../Src/system_stm32l4xx.c 

OBJS += \
./Src/String.o \
./Src/UART_Handler.o \
./Src/main.o \
./Src/stm32l4xx_hal_msp.o \
./Src/stm32l4xx_it.o \
./Src/system_stm32l4xx.o 

C_DEPS += \
./Src/String.d \
./Src/UART_Handler.d \
./Src/main.d \
./Src/stm32l4xx_hal_msp.d \
./Src/stm32l4xx_it.d \
./Src/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L476xx -I"C:/Users/phiwersports/Desktop/Projects/kod från emir/STM_CUBE_GENERATIONS/Side Project 1/SideProject1/Inc" -I"C:/Users/phiwersports/Desktop/Projects/kod från emir/STM_CUBE_GENERATIONS/Side Project 1/SideProject1/Drivers/STM32L4xx_HAL_Driver/Inc" -I"C:/Users/phiwersports/Desktop/Projects/kod från emir/STM_CUBE_GENERATIONS/Side Project 1/SideProject1/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/phiwersports/Desktop/Projects/kod från emir/STM_CUBE_GENERATIONS/Side Project 1/SideProject1/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"C:/Users/phiwersports/Desktop/Projects/kod från emir/STM_CUBE_GENERATIONS/Side Project 1/SideProject1/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


