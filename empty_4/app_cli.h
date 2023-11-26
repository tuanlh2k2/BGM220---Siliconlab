/*
 * app_cli.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Wind
 */

#ifndef APP_CLI_H_
#define APP_CLI_H_

#include "sl_cli.h"
#include "sl_cli_handles.h"

/******************************************************************************
 * CLI - run: Handler of the `custom run` command
 *****************************************************************************/
void cmd_set_timer_handler(sl_cli_command_arg_t *arguments);

void cli_custom_cmd_init();


#endif /* APP_CLI_H_ */
