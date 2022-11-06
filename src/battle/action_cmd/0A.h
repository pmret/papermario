#ifndef _0A_H_
#define _0A_H_

#include "common_structs.h"

ApiStatus action_command_0A_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_0A_start(Evt* script, s32 isInitialCall);
void action_command_0A_update(void);
void action_command_0A_draw(void);
void action_command_0A_free(void);

#endif
