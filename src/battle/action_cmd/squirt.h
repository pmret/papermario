#ifndef _SQUIRT_H_
#define _SQUIRT_H_

#include "common_structs.h"

ApiStatus action_command_squirt_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_squirt_start(Evt* script, s32 isInitialCall);
void action_command_squirt_update(void);
void action_command_squirt_draw(void);
void action_command_squirt_free(void);

#endif
