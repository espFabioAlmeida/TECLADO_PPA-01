################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/subrotinas/SubrotinasConfiguracoes.c \
../Core/Src/subrotinas/SubrotinasLCD.c \
../Core/Src/subrotinas/SubrotinasTeclado.c 

OBJS += \
./Core/Src/subrotinas/SubrotinasConfiguracoes.o \
./Core/Src/subrotinas/SubrotinasLCD.o \
./Core/Src/subrotinas/SubrotinasTeclado.o 

C_DEPS += \
./Core/Src/subrotinas/SubrotinasConfiguracoes.d \
./Core/Src/subrotinas/SubrotinasLCD.d \
./Core/Src/subrotinas/SubrotinasTeclado.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/subrotinas/%.o Core/Src/subrotinas/%.su Core/Src/subrotinas/%.cyclo: ../Core/Src/subrotinas/%.c Core/Src/subrotinas/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-subrotinas

clean-Core-2f-Src-2f-subrotinas:
	-$(RM) ./Core/Src/subrotinas/SubrotinasConfiguracoes.cyclo ./Core/Src/subrotinas/SubrotinasConfiguracoes.d ./Core/Src/subrotinas/SubrotinasConfiguracoes.o ./Core/Src/subrotinas/SubrotinasConfiguracoes.su ./Core/Src/subrotinas/SubrotinasLCD.cyclo ./Core/Src/subrotinas/SubrotinasLCD.d ./Core/Src/subrotinas/SubrotinasLCD.o ./Core/Src/subrotinas/SubrotinasLCD.su ./Core/Src/subrotinas/SubrotinasTeclado.cyclo ./Core/Src/subrotinas/SubrotinasTeclado.d ./Core/Src/subrotinas/SubrotinasTeclado.o ./Core/Src/subrotinas/SubrotinasTeclado.su

.PHONY: clean-Core-2f-Src-2f-subrotinas

