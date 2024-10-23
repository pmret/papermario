#ifndef _HAMMER_H_
#define _HAMMER_H_

#include "common_structs.h"

// args: none
API_CALLABLE(action_command_hammer_init);

// args: prep time, duration, difficulty
API_CALLABLE(action_command_hammer_start);

void action_command_hammer_update(void);
void action_command_hammer_draw(void);
void action_command_hammer_free(void);

#endif
