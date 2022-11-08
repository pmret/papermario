#ifndef _JUMP_H_
#define _JUMP_H_

#include "common_structs.h"

ApiStatus action_command_jump_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_jump_start(Evt* script, s32 isInitialCall);
void action_command_jump_update(void);
void action_command_jump_draw(void);
void action_command_jump_free(void);

#endif
