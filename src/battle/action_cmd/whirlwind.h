#ifndef _WHIRLWIND_H_
#define _WHIRLWIND_H_

#include "common_structs.h"

ApiStatus action_command_whirlwind_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_whirlwind_start(Evt* script, s32 isInitialCall);
void action_command_whirlwind_update(void);
void action_command_whirlwind_draw(void);
void action_command_whirlwind_free(void);

#endif
