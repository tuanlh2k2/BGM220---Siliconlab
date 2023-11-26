################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_3.2.3/platform/service/system/src/subdir.mk
-include gecko_sdk_3.2.3/platform/service/iostream/src/subdir.mk
-include gecko_sdk_3.2.3/platform/service/device_init/src/subdir.mk
-include gecko_sdk_3.2.3/platform/emlib/src/subdir.mk
-include gecko_sdk_3.2.3/platform/emdrv/gpiointerrupt/src/subdir.mk
-include gecko_sdk_3.2.3/platform/driver/leddrv/src/subdir.mk
-include gecko_sdk_3.2.3/platform/driver/button/src/subdir.mk
-include gecko_sdk_3.2.3/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_3.2.3/platform/Device/SiliconLabs/BGM22/Source/GCC/subdir.mk
-include gecko_sdk_3.2.3/platform/Device/SiliconLabs/BGM22/Source/subdir.mk
-include gecko_sdk_3.2.3/hardware/board/src/subdir.mk
-include gecko_sdk_3.2.3/app/common/util/app_log/subdir.mk
-include autogen/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := empty
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: empty.axf

# Tool invocations
empty.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -T "C:\Users\Wind\OneDrive\Desktop\test\empty\autogen\linkerfile.ld" -Xlinker --gc-sections -Xlinker -Map="empty.map" -mfpu=fpv5-sp-d16 -mfloat-abi=hard --specs=nano.specs -o empty.axf -Wl,--start-group "./app.o" "./main.o" "./autogen/sl_board_default_init.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./autogen/sl_iostream_handles.o" "./autogen/sl_iostream_init_usart_instances.o" "./autogen/sl_simple_button_instances.o" "./autogen/sl_simple_led_instances.o" "./gecko_sdk_3.2.3/app/common/util/app_log/app_log.o" "./gecko_sdk_3.2.3/hardware/board/src/sl_board_control_gpio.o" "./gecko_sdk_3.2.3/hardware/board/src/sl_board_init.o" "./gecko_sdk_3.2.3/platform/Device/SiliconLabs/BGM22/Source/GCC/startup_bgm22.o" "./gecko_sdk_3.2.3/platform/Device/SiliconLabs/BGM22/Source/system_bgm22.o" "./gecko_sdk_3.2.3/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_3.2.3/platform/driver/button/src/sl_button.o" "./gecko_sdk_3.2.3/platform/driver/button/src/sl_simple_button.o" "./gecko_sdk_3.2.3/platform/driver/leddrv/src/sl_led.o" "./gecko_sdk_3.2.3/platform/driver/leddrv/src/sl_simple_led.o" "./gecko_sdk_3.2.3/platform/emdrv/gpiointerrupt/src/gpiointerrupt.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_assert.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_cmu.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_core.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_emu.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_gpio.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_system.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_usart.o" "./gecko_sdk_3.2.3/platform/service/device_init/src/sl_device_init_dcdc_s2.o" "./gecko_sdk_3.2.3/platform/service/device_init/src/sl_device_init_emu_s2.o" "./gecko_sdk_3.2.3/platform/service/device_init/src/sl_device_init_hfxo_s2.o" "./gecko_sdk_3.2.3/platform/service/device_init/src/sl_device_init_lfxo_s2.o" "./gecko_sdk_3.2.3/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_3.2.3/platform/service/iostream/src/sl_iostream.o" "./gecko_sdk_3.2.3/platform/service/iostream/src/sl_iostream_retarget_stdio.o" "./gecko_sdk_3.2.3/platform/service/iostream/src/sl_iostream_stdlib_config.o" "./gecko_sdk_3.2.3/platform/service/iostream/src/sl_iostream_uart.o" "./gecko_sdk_3.2.3/platform/service/iostream/src/sl_iostream_usart.o" "./gecko_sdk_3.2.3/platform/service/system/src/sl_system_init.o" "./gecko_sdk_3.2.3/platform/service/system/src/sl_system_process_action.o" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: empty.out'
	arm-none-eabi-objcopy "empty.axf" "empty.out"
	@echo ' '

	@echo 'Building hex file: empty.hex'
	arm-none-eabi-objcopy -O ihex "empty.axf" "empty.hex"
	@echo ' '

	@echo 'Building bin file: empty.bin'
	arm-none-eabi-objcopy -O binary "empty.axf" "empty.bin"
	@echo ' '

	@echo 'Building s37 file: empty.s37'
	arm-none-eabi-objcopy -O srec "empty.axf" "empty.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "empty.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) empty.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
