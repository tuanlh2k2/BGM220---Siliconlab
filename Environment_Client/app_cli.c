/*
 * app_cli.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Wind
 */

#include "app_cli.h"

// Xét thời gian indicate.
static const sl_cli_command_info_t cmd_set_timer = \
SL_CLI_COMMAND(cmd_set_timer_handler,
		"Set timer command",
		"Argument1 - set device" SL_CLI_UNIT_SEPARATOR
		"Argument2 - set timer (ms)",
		{ SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

// Xét bật/ tắt thiết bị.
static const sl_cli_command_info_t cmd_set_connect_device = \
		SL_CLI_COMMAND(cmd_set_connect_device_handler,
				"Set connect device",
				"Argument1 - set device" SL_CLI_UNIT_SEPARATOR
				"Argument2 - set state (1. connect, 0. disconnect)",
				{ SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

// Xét khoảng ảo để test tín hiệu vượt ngưỡng.
static const sl_cli_command_info_t cmd_set_virtual_threshold = \
		SL_CLI_COMMAND(cmd_set_virtual_threshold_handler,
				"Set virtual_threshold for device",
				"Argument1 - set device" SL_CLI_UNIT_SEPARATOR
				"Argument2 - set variable type (0 - temp, 1 - humi, 2 - light)" SL_CLI_UNIT_SEPARATOR
				"Argument3 - virtual threshold (< 100)",
				{ SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

// Xét ngưỡng cho các tín hiệu.
static const sl_cli_command_info_t cmd_set_threshold_for_device = \
		SL_CLI_COMMAND(cmd_set_threshold_for_device_handler,
				"Set threshold for device",
				"Argument1 - set device" SL_CLI_UNIT_SEPARATOR
				"Argument2 - set variable type (0 - temp, 1 - humi, 2 - light)" SL_CLI_UNIT_SEPARATOR
				"Argument3 - threshold min (< 100)" SL_CLI_UNIT_SEPARATOR
				"Argument4 - threshold max (> 10)",
				{ SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static sl_cli_command_entry_t custom_cmd_table[] = {
		{ "set_timer", &cmd_set_timer, false },
		{ "set_connect_device", &cmd_set_connect_device, false },
		{ "set_virtual_threshold", &cmd_set_virtual_threshold, false },
		{ "set_threshold_for_device", &cmd_set_threshold_for_device, false},
		{ NULL, NULL, NULL, NULL, false },
};

static sl_cli_command_group_t custom_cmd_group = {
		{NULL},
		false,
		custom_cmd_table
};

void cli_custom_cmd_init()
{
	sl_cli_command_add_command_group(sl_cli_example_handle, &custom_cmd_group);
}

