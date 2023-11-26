################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/gatt_db.c \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_bluetooth.c \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_board_default_init.c \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_device_init_clocks.c \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_event_handler.c \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_i2cspm_init.c \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_iostream_handles.c \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_iostream_init_usart_instances.c \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_power_manager_handler.c \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_simple_led_instances.c 

OBJS += \
./autogen/gatt_db.o \
./autogen/sl_bluetooth.o \
./autogen/sl_board_default_init.o \
./autogen/sl_device_init_clocks.o \
./autogen/sl_event_handler.o \
./autogen/sl_i2cspm_init.o \
./autogen/sl_iostream_handles.o \
./autogen/sl_iostream_init_usart_instances.o \
./autogen/sl_power_manager_handler.o \
./autogen/sl_simple_led_instances.o 

C_DEPS += \
./autogen/gatt_db.d \
./autogen/sl_bluetooth.d \
./autogen/sl_board_default_init.d \
./autogen/sl_device_init_clocks.d \
./autogen/sl_event_handler.d \
./autogen/sl_i2cspm_init.d \
./autogen/sl_iostream_handles.d \
./autogen/sl_iostream_init_usart_instances.d \
./autogen/sl_power_manager_handler.d \
./autogen/sl_simple_led_instances.d 


# Each subdirectory must supply rules for building sources it contributes
autogen/gatt_db.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/gatt_db.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/gatt_db.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_bluetooth.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_bluetooth.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_bluetooth.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_board_default_init.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_board_default_init.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_board_default_init.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_device_init_clocks.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_device_init_clocks.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_device_init_clocks.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_event_handler.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_event_handler.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_event_handler.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_i2cspm_init.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_i2cspm_init.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_i2cspm_init.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_iostream_handles.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_iostream_handles.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_iostream_handles.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_iostream_init_usart_instances.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_iostream_init_usart_instances.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_iostream_init_usart_instances.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_power_manager_handler.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_power_manager_handler.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_power_manager_handler.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_simple_led_instances.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/autogen/sl_simple_led_instances.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_simple_led_instances.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


