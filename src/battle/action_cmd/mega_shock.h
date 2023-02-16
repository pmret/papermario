#ifndef _MEGA_SHOCK_H_
#define _MEGA_SHOCK_H_

#include "common_structs.h"

API_CALLABLE(action_command_mega_shock_init);
API_CALLABLE(action_command_mega_shock_start);
void action_command_mega_shock_update(void);
void action_command_mega_shock_draw(void);
void action_command_mega_shock_free(void);

#endif
