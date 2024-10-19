#ifndef _BOMB_H_
#define _BOMB_H_

#include "common_structs.h"

// args: none
API_CALLABLE(action_command_bomb_init);

// args: prep time, duration, difficulty, variation
API_CALLABLE(action_command_bomb_start);

void action_command_bomb_update(void);
void action_command_bomb_draw(void);
void action_command_bomb_free(void);

// variants for this action command
enum {
    ACV_BOMB_BASIC      = 0,
    ACV_BOMB_SUPER      = 1,
    ACV_BOMB_ULTRA      = 2,
};

#endif
