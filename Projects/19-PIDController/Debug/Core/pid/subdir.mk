################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/engin/Documents/GitHub/esclib/src/control/pid.c 

OBJS += \
./Core/pid/pid.o 

C_DEPS += \
./Core/pid/pid.d 


# Each subdirectory must supply rules for building sources it contributes
Core/pid/pid.o: C:/Users/engin/Documents/GitHub/esclib/src/control/pid.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../USB_HOST/App -I"C:/Users/engin/Documents/GitHub/esclib/inc/control" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../USB_HOST/Target -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/pid/pid.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

