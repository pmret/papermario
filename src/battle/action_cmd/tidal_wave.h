#ifndef _TIDAL_WAVE_H_
#define _TIDAL_WAVE_H_

#include "common_structs.h"

// args: none
API_CALLABLE(action_command_tidal_wave_init);

// args: prep time, duration, difficulty
API_CALLABLE(action_command_tidal_wave_start);

void action_command_tidal_wave_update(void);
void action_command_tidal_wave_draw(void);
void action_command_tidal_wave_free(void);

#endif
