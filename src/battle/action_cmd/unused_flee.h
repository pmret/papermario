#ifndef _UNUSED_FLEE_H_
#define _UNUSED_FLEE_H_

#include "common_structs.h"

API_CALLABLE(action_command_unused_flee_init);
API_CALLABLE(action_command_unused_flee_start);
void action_command_unused_flee_update(void);
void action_command_unused_flee_draw(void);
void action_command_unused_flee_free(void);

#endif
