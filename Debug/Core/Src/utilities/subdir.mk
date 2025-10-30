################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/utilities/UtilityEeprom.c \
../Core/Src/utilities/UtilityGPIO.c \
../Core/Src/utilities/UtilityLCD.c \
../Core/Src/utilities/UtilityTeclado.c \
../Core/Src/utilities/UtilityUART.c 

OBJS += \
./Core/Src/utilities/UtilityEeprom.o \
./Core/Src/utilities/UtilityGPIO.o \
./Core/Src/utilities/UtilityLCD.o \
./Core/Src/utilities/UtilityTeclado.o \
./Core/Src/utilities/UtilityUART.o 

C_DEPS += \
./Core/Src/utilities/UtilityEeprom.d \
./Core/Src/utilities/UtilityGPIO.d \
./Core/Src/utilities/UtilityLCD.d \
./Core/Src/utilities/UtilityTeclado.d \
./Core/Src/utilities/UtilityUART.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/utilities/%.o Core/Src/utilities/%.su Core/Src/utilities/%.cyclo: ../Core/Src/utilities/%.c Core/Src/utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-utilities

clean-Core-2f-Src-2f-utilities:
	-$(RM) ./Core/Src/utilities/UtilityEeprom.cyclo ./Core/Src/utilities/UtilityEeprom.d ./Core/Src/utilities/UtilityEeprom.o ./Core/Src/utilities/UtilityEeprom.su ./Core/Src/utilities/UtilityGPIO.cyclo ./Core/Src/utilities/UtilityGPIO.d ./Core/Src/utilities/UtilityGPIO.o ./Core/Src/utilities/UtilityGPIO.su ./Core/Src/utilities/UtilityLCD.cyclo ./Core/Src/utilities/UtilityLCD.d ./Core/Src/utilities/UtilityLCD.o ./Core/Src/utilities/UtilityLCD.su ./Core/Src/utilities/UtilityTeclado.cyclo ./Core/Src/utilities/UtilityTeclado.d ./Core/Src/utilities/UtilityTeclado.o ./Core/Src/utilities/UtilityTeclado.su ./Core/Src/utilities/UtilityUART.cyclo ./Core/Src/utilities/UtilityUART.d ./Core/Src/utilities/UtilityUART.o ./Core/Src/utilities/UtilityUART.su

.PHONY: clean-Core-2f-Src-2f-utilities

