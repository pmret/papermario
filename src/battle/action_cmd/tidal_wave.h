#ifndef _TIDAL_WAVE_H_
#define _TIDAL_WAVE_H_

#include "common_structs.h"

ApiStatus action_command_tidal_wave_CreateHudElements(Evt* script, s32 isInitialCall);
ApiStatus func_802A9138_42C828(Evt* script, s32 isInitialCall);

void action_command_tidal_wave_update(void);

#endif
