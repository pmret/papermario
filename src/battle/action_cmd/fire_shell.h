#ifndef _FIRE_SHELL_H_
#define _FIRE_SHELL_H_

#include "common_structs.h"

// args: none
API_CALLABLE(action_command_fire_shell_init);

// args: prep time, duration, difficulty
API_CALLABLE(action_command_fire_shell_start);

void action_command_fire_shell_update(void);
void action_command_fire_shell_draw(void);
void action_command_fire_shell_free(void);

#endif
