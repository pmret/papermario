#ifndef _FLEE_H_
#define _FLEE_H_

#include "common_structs.h"

ApiStatus action_command_flee_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_flee_start(Evt* script, s32 isInitialCall);
void action_command_flee_update(void);
void action_command_flee_draw(void);
void action_command_flee_free(void);

#endif
