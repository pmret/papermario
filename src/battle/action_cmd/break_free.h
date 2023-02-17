#ifndef _BREAK_FREE_H_
#define _BREAK_FREE_H_

#include "common_structs.h"

API_CALLABLE(action_command_break_free_init);
API_CALLABLE(action_command_break_free_start);
void action_command_break_free_update(void);
void action_command_break_free_draw(void);
void action_command_break_free_free(void);

#endif
