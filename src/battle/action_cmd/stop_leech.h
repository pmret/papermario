#ifndef _STOP_LEECH_H_
#define _STOP_LEECH_H_

#include "common_structs.h"

// args: none
API_CALLABLE(action_command_stop_leech_init);

// args: prep time, duration, difficulty
API_CALLABLE(action_command_stop_leech_start);

void action_command_stop_leech_update(void);
void action_command_stop_leech_draw(void);
void action_command_stop_leech_free(void);

// timeout duration for leech -- if the player can survive for this many frames (> 18.2 mintues) the command will end
#define AC_LEECH_MAX_TIME 32767

#endif
