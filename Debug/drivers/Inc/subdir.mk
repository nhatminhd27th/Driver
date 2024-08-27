################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Inc/stm32_gpio.c 

OBJS += \
./drivers/Inc/stm32_gpio.o 

C_DEPS += \
./drivers/Inc/stm32_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Inc/%.o drivers/Inc/%.su drivers/Inc/%.cyclo: ../drivers/Inc/%.c drivers/Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411VETx -DSTM32 -DSTM32F4 -c -I../Inc -I"C:/Users/OS/OneDrive/Documentos/STM32/Workspace/STM32F411_driver/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drivers-2f-Inc

clean-drivers-2f-Inc:
	-$(RM) ./drivers/Inc/stm32_gpio.cyclo ./drivers/Inc/stm32_gpio.d ./drivers/Inc/stm32_gpio.o ./drivers/Inc/stm32_gpio.su

.PHONY: clean-drivers-2f-Inc

