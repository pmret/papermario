#ifndef _SQUIRT_H_
#define _SQUIRT_H_

#include "common_structs.h"

// args: none
API_CALLABLE(action_command_squirt_init);

// args: prep time, duration, difficulty
API_CALLABLE(action_command_squirt_start);

void action_command_squirt_update(void);
void action_command_squirt_draw(void);
void action_command_squirt_free(void);

#endif
