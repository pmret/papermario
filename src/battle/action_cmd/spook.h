#ifndef _SPOOK_H_
#define _SPOOK_H_

#include "common_structs.h"

ApiStatus action_command_spook_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_spook_start(Evt* script, s32 isInitialCall);
void action_command_spook_update(void);
void action_command_spook_draw(void);
void action_command_spook_free(void);

#endif
