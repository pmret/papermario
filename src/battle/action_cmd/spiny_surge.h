#ifndef _SPINY_SURGE_H_
#define _SPINY_SURGE_H_

#include "common_structs.h"

API_CALLABLE(action_command_spiny_surge_init);
API_CALLABLE(action_command_spiny_surge_start);
void action_command_spiny_surge_update(void);
void action_command_spiny_surge_draw(void);
void action_command_spiny_surge_free(void);

#endif
