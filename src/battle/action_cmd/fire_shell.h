#ifndef _FIRE_SHELL_H_
#define _FIRE_SHELL_H_

#include "common_structs.h"

API_CALLABLE(action_command_fire_shell_init);
API_CALLABLE(action_command_fire_shell_start);
void action_command_fire_shell_update(void);
void action_command_fire_shell_draw(void);
void action_command_fire_shell_free(void);

#endif
