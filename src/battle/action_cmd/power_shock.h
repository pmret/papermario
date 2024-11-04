#ifndef _POWER_SHOCK_H_
#define _POWER_SHOCK_H_

#include "common_structs.h"

// args: none
API_CALLABLE(action_command_power_shock_init);

// args: prep time, duration, difficulty, chance
API_CALLABLE(action_command_power_shock_start);

void action_command_power_shock_update(void);
void action_command_power_shock_draw(void);
void action_command_power_shock_free(void);

#endif
