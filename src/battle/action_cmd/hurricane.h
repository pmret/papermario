#ifndef _HURRICANE_H_
#define _HURRICANE_H_

#include "common_structs.h"

ApiStatus action_command_hurricane_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_hurricane_start(Evt* script, s32 isInitialCall);
void action_command_hurricane_update(void);
void action_command_hurricane_draw(void);
void action_command_hurricane_free(void);

#endif
