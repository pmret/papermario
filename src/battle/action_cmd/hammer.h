#ifndef _HAMMER_H_
#define _HAMMER_H_

#include "common_structs.h"

API_CALLABLE(action_command_hammer_init);
API_CALLABLE(action_command_hammer_start);
void action_command_hammer_update(void);
void action_command_hammer_draw(void);
void action_command_hammer_free(void);

#endif
