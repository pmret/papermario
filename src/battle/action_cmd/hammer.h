#ifndef _HAMMER_H_
#define _HAMMER_H_

#include "common_structs.h"

ApiStatus action_command_hammer_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_hammer_start(Evt* script, s32 isInitialCall);
void action_command_hammer_update(void);
void action_command_hammer_draw(void);
void action_command_hammer_free(void);

#endif
