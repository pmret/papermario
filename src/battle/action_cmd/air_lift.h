#ifndef _AIR_LIFT_H_
#define _AIR_LIFT_H_

#include "common_structs.h"

ApiStatus action_command_air_lift_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_air_lift_start(Evt* script, s32 isInitialCall);
void action_command_air_lift_update(void);
void action_command_air_lift_draw(void);
void action_command_air_lift_free(void);

#endif
