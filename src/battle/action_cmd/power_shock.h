#ifndef _POWER_SHOCK_H_
#define _POWER_SHOCK_H_

#include "common_structs.h"

ApiStatus action_command_power_shock_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_power_shock_start(Evt* script, s32 isInitialCall);
void action_command_power_shock_update(void);
void action_command_power_shock_draw(void);
void action_command_power_shock_free(void);

#endif
