#ifndef _FLEE_H_
#define _FLEE_H_

#include "common_structs.h"

// args: unknown value from actor var
API_CALLABLE(action_command_flee_init);

// args: prep time, duration, difficulty
API_CALLABLE(action_command_flee_start);

void action_command_flee_update(void);
void action_command_flee_draw(void);
void action_command_flee_free(void);

#endif
