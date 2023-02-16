#ifndef _HURRICANE_H_
#define _HURRICANE_H_

#include "common_structs.h"

API_CALLABLE(action_command_hurricane_init);
API_CALLABLE(action_command_hurricane_start);
void action_command_hurricane_update(void);
void action_command_hurricane_draw(void);
void action_command_hurricane_free(void);

#endif
