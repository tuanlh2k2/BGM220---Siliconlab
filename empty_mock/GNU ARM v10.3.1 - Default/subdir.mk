################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/app.c \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/bh1750.c \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/dht11.c \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/main.c \
C:/Users/Wind/OneDrive/Desktop/test/empty_mock/sl_gatt_service_device_information.c 

OBJS += \
./app.o \
./bh1750.o \
./dht11.o \
./main.o \
./sl_gatt_service_device_information.o 

C_DEPS += \
./app.d \
./bh1750.d \
./dht11.d \
./main.d \
./sl_gatt_service_device_information.d 


# Each subdirectory must supply rules for building sources it contributes
app.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/app.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"app.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

bh1750.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/bh1750.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"bh1750.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

dht11.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/dht11.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"dht11.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/main.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"main.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

sl_gatt_service_device_information.o: C:/Users/Wind/OneDrive/Desktop/test/empty_mock/sl_gatt_service_device_information.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 -I"C:\Users\Wind\OneDrive\Desktop\test\empty_mock\autogen" -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"sl_gatt_service_device_information.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


