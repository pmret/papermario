#ifndef _STOP_LEECH_H_
#define _STOP_LEECH_H_

#include "common_structs.h"

ApiStatus action_command_stop_leech_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_stop_leech_start(Evt* script, s32 isInitialCall);
void action_command_stop_leech_update(void);
void action_command_stop_leech_draw(void);
void action_command_stop_leech_free(void);

#endif
