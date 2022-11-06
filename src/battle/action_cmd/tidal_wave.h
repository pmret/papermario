#ifndef _TIDAL_WAVE_H_
#define _TIDAL_WAVE_H_

#include "common_structs.h"

ApiStatus action_command_tidal_wave_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_tidal_wave_start(Evt* script, s32 isInitialCall);
void action_command_tidal_wave_update(void);
void action_command_tidal_wave_draw(void);
void action_command_tidal_wave_free(void);

#endif
