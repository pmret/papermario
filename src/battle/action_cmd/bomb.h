#ifndef _BOMB_H_
#define _BOMB_H_

#include "common_structs.h"

ApiStatus action_command_bomb_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_bomb_start(Evt* script, s32 isInitialCall);
void action_command_bomb_update(void);
void action_command_bomb_draw(void);
void action_command_bomb_free(void);

#endif
