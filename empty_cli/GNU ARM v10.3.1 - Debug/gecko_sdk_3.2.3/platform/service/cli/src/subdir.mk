################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/service/cli/src/sl_cli.c \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/service/cli/src/sl_cli_arguments.c \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/service/cli/src/sl_cli_command.c \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/service/cli/src/sl_cli_input.c \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/service/cli/src/sl_cli_io.c \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/service/cli/src/sl_cli_tokenize.c 

OBJS += \
./gecko_sdk_3.2.3/platform/service/cli/src/sl_cli.o \
./gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_arguments.o \
./gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_command.o \
./gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_input.o \
./gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_io.o \
./gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_tokenize.o 

C_DEPS += \
./gecko_sdk_3.2.3/platform/service/cli/src/sl_cli.d \
./gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_arguments.d \
./gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_command.d \
./gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_input.d \
./gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_io.d \
./gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_tokenize.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_3.2.3/platform/service/cli/src/sl_cli.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/service/cli/src/sl_cli.c gecko_sdk_3.2.3/platform/service/cli/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//app/common/util/app_log" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/cli/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/iostream/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/service/cli/src/sl_cli.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_arguments.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/service/cli/src/sl_cli_arguments.c gecko_sdk_3.2.3/platform/service/cli/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//app/common/util/app_log" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/cli/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/iostream/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_arguments.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_command.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/service/cli/src/sl_cli_command.c gecko_sdk_3.2.3/platform/service/cli/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//app/common/util/app_log" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/cli/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/iostream/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_command.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_input.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/service/cli/src/sl_cli_input.c gecko_sdk_3.2.3/platform/service/cli/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//app/common/util/app_log" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/cli/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/iostream/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_input.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_io.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/service/cli/src/sl_cli_io.c gecko_sdk_3.2.3/platform/service/cli/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//app/common/util/app_log" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/cli/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/iostream/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_io.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_tokenize.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/service/cli/src/sl_cli_tokenize.c gecko_sdk_3.2.3/platform/service/cli/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_cli" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//app/common/util/app_log" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/cli/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/iostream/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/service/cli/src/sl_cli_tokenize.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


