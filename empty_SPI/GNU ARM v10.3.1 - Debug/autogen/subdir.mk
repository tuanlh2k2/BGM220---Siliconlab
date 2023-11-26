################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../autogen/sl_board_default_init.c \
../autogen/sl_device_init_clocks.c \
../autogen/sl_event_handler.c \
../autogen/sl_simple_button_instances.c \
../autogen/sl_spidrv_init.c 

OBJS += \
./autogen/sl_board_default_init.o \
./autogen/sl_device_init_clocks.o \
./autogen/sl_event_handler.o \
./autogen/sl_simple_button_instances.o \
./autogen/sl_spidrv_init.o 

C_DEPS += \
./autogen/sl_board_default_init.d \
./autogen/sl_device_init_clocks.d \
./autogen/sl_event_handler.d \
./autogen/sl_simple_button_instances.d \
./autogen/sl_spidrv_init.d 


# Each subdirectory must supply rules for building sources it contributes
autogen/sl_board_default_init.o: ../autogen/sl_board_default_init.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/button/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/gpiointerrupt/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/spidrv/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_board_default_init.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_device_init_clocks.o: ../autogen/sl_device_init_clocks.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/button/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/gpiointerrupt/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/spidrv/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_device_init_clocks.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_event_handler.o: ../autogen/sl_event_handler.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/button/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/gpiointerrupt/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/spidrv/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_event_handler.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_simple_button_instances.o: ../autogen/sl_simple_button_instances.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/button/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/gpiointerrupt/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/spidrv/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_simple_button_instances.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_spidrv_init.o: ../autogen/sl_spidrv_init.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/button/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/gpiointerrupt/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/spidrv/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_spidrv_init.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


