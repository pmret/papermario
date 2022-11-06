#ifndef _07_H_
#define _07_H_

#include "common_structs.h"

ApiStatus action_command_07_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_07_start(Evt* script, s32 isInitialCall);
void action_command_07_update(void);
void action_command_07_draw(void);
void action_command_07_free(void);

#endif
