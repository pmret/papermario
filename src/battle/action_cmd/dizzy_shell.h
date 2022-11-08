#ifndef _DIZZY_SHELL_H_
#define _DIZZY_SHELL_H_

#include "common_structs.h"

ApiStatus action_command_dizzy_shell_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_dizzy_shell_start(Evt* script, s32 isInitialCall);
void action_command_dizzy_shell_update(void);
void action_command_dizzy_shell_draw(void);
void action_command_dizzy_shell_free(void);

#endif
