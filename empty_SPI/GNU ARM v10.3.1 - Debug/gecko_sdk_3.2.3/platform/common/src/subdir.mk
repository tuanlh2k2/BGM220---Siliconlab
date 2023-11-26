################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/common/src/sl_slist.c 

OBJS += \
./gecko_sdk_3.2.3/platform/common/src/sl_slist.o 

C_DEPS += \
./gecko_sdk_3.2.3/platform/common/src/sl_slist.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_3.2.3/platform/common/src/sl_slist.o: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2/platform/common/src/sl_slist.c gecko_sdk_3.2.3/platform/common/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DBGM220PC22HNA=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI\config" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI\autogen" -I"C:\Users\Wind\OneDrive\Desktop\test\empty_SPI" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/BGM22/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//hardware/board/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/button/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/gpiointerrupt/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2//platform/emdrv/spidrv/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/common/src/sl_slist.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


