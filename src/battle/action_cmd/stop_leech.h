#ifndef _STOP_LEECH_H_
#define _STOP_LEECH_H_

#include "common_structs.h"

API_CALLABLE(action_command_stop_leech_init);
API_CALLABLE(action_command_stop_leech_start);
void action_command_stop_leech_update(void);
void action_command_stop_leech_draw(void);
void action_command_stop_leech_free(void);

#endif
