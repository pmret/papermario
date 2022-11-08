#ifndef _BREAK_FREE_H_
#define _BREAK_FREE_H_

#include "common_structs.h"

ApiStatus action_command_break_free_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_break_free_start(Evt* script, s32 isInitialCall);
void action_command_break_free_update(void);
void action_command_break_free_draw(void);
void action_command_break_free_free(void);

#endif
