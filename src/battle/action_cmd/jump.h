#ifndef _JUMP_H_
#define _JUMP_H_

#include "common_structs.h"

void action_command_jump_update(void);

ApiStatus action_command_jump_CreateHudElements(Evt* script, s32 isInitialCall);

#endif
