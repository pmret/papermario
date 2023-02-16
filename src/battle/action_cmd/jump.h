#ifndef _JUMP_H_
#define _JUMP_H_

#include "common_structs.h"

API_CALLABLE(action_command_jump_init);
API_CALLABLE(action_command_jump_start);
void action_command_jump_update(void);
void action_command_jump_draw(void);
void action_command_jump_free(void);

#endif
