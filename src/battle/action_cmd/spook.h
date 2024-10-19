#ifndef _SPOOK_H_
#define _SPOOK_H_

#include "common_structs.h"

// args: none
API_CALLABLE(action_command_spook_init);

// args: prep time, duration, difficulty, chance
API_CALLABLE(action_command_spook_start);

void action_command_spook_update(void);
void action_command_spook_draw(void);
void action_command_spook_free(void);

#endif
