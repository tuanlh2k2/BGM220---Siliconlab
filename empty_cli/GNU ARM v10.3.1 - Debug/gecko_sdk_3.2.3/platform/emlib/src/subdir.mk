################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_assert.c \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_cmu.c \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_core.c \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_emu.c \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_gpio.c \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_system.c \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_usart.c 

OBJS += \
./gecko_sdk_3.2.3/platform/emlib/src/em_assert.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_cmu.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_core.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_emu.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_gpio.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_system.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_usart.o 

C_DEPS += \
./gecko_sdk_3.2.3/platform/emlib/src/em_assert.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_cmu.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_core.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_emu.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_gpio.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_system.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_usart.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_3.2.3/platform/emlib/src/em_assert.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_assert.c gecko_sdk_3.2.3/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//app/common/util/app_log" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/cli/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/iostream/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_assert.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_cmu.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_cmu.c gecko_sdk_3.2.3/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//app/common/util/app_log" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/cli/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/iostream/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_cmu.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_core.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_core.c gecko_sdk_3.2.3/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//app/common/util/app_log" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/cli/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/iostream/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_core.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_emu.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_emu.c gecko_sdk_3.2.3/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//app/common/util/app_log" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/cli/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/iostream/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_emu.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_gpio.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_gpio.c gecko_sdk_3.2.3/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//app/common/util/app_log" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/cli/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/iostream/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_gpio.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_system.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_system.c gecko_sdk_3.2.3/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//app/common/util/app_log" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/cli/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/iostream/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_system.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_usart.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_usart.c gecko_sdk_3.2.3/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//app/common/util/app_log" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/cli/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/iostream/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_usart.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


