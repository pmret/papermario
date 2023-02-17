#ifndef _BOMB_H_
#define _BOMB_H_

#include "common_structs.h"

API_CALLABLE(action_command_bomb_init);
API_CALLABLE(action_command_bomb_start);
void action_command_bomb_update(void);
void action_command_bomb_draw(void);
void action_command_bomb_free(void);

#endif
