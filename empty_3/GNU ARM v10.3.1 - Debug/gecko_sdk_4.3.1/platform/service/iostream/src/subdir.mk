################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream.c \
C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_retarget_stdio.c \
C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_stdlib_config.c \
C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_uart.c \
C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_usart.c 

OBJS += \
./gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream.o \
./gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_retarget_stdio.o \
./gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_stdlib_config.o \
./gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_uart.o \
./gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_usart.o 

C_DEPS += \
./gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream.d \
./gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_retarget_stdio.d \
./gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_stdlib_config.d \
./gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_uart.d \
./gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_usart.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream.o: C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream.c gecko_sdk_4.3.1/platform/service/iostream/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4314A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/BGM22/Include" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_retarget_stdio.o: C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_retarget_stdio.c gecko_sdk_4.3.1/platform/service/iostream/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4314A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/BGM22/Include" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_retarget_stdio.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_stdlib_config.o: C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_stdlib_config.c gecko_sdk_4.3.1/platform/service/iostream/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4314A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/BGM22/Include" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_stdlib_config.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_uart.o: C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_uart.c gecko_sdk_4.3.1/platform/service/iostream/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4314A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/BGM22/Include" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_uart.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_usart.o: C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk/platform/service/iostream/src/sl_iostream_usart.c gecko_sdk_4.3.1/platform/service/iostream/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4314A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_3" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/BGM22/Include" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_log" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/dmadrv/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/iostream/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Wind/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.3.1/platform/service/iostream/src/sl_iostream_usart.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


