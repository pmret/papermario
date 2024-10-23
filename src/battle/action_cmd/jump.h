#ifndef _JUMP_H_
#define _JUMP_H_

#include "common_structs.h"

// args: none
API_CALLABLE(action_command_jump_init);

// args: duration, difficulty
// duration should be two frames fewer than actual motion toward the target
API_CALLABLE(action_command_jump_start);

void action_command_jump_update(void);
void action_command_jump_draw(void);
void action_command_jump_free(void);

#endif
