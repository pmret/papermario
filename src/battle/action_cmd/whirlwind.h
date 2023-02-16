#ifndef _WHIRLWIND_H_
#define _WHIRLWIND_H_

#include "common_structs.h"

API_CALLABLE(action_command_whirlwind_init);
API_CALLABLE(action_command_whirlwind_start);
void action_command_whirlwind_update(void);
void action_command_whirlwind_draw(void);
void action_command_whirlwind_free(void);

#endif
