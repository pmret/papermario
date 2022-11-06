#ifndef _FIRE_SHELL_H_
#define _FIRE_SHELL_H_

#include "common_structs.h"

ApiStatus action_command_fire_shell_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_fire_shell_start(Evt* script, s32 isInitialCall);
void action_command_fire_shell_update(void);
void action_command_fire_shell_draw(void);
void action_command_fire_shell_free(void);

#endif
