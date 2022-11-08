#ifndef _SPINY_SURGE_H_
#define _SPINY_SURGE_H_

#include "common_structs.h"

ApiStatus action_command_spiny_surge_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_spiny_surge_start(Evt* script, s32 isInitialCall);
void action_command_spiny_surge_update(void);
void action_command_spiny_surge_draw(void);
void action_command_spiny_surge_free(void);

#endif
