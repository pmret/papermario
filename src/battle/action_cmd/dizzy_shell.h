#ifndef _DIZZY_SHELL_H_
#define _DIZZY_SHELL_H_

#include "common_structs.h"

API_CALLABLE(action_command_dizzy_shell_init);
API_CALLABLE(action_command_dizzy_shell_start);
void action_command_dizzy_shell_update(void);
void action_command_dizzy_shell_draw(void);
void action_command_dizzy_shell_free(void);

#endif
