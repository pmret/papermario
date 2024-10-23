#ifndef _SPINY_SURGE_H_
#define _SPINY_SURGE_H_

#include "common_structs.h"

// args: none
API_CALLABLE(action_command_spiny_surge_init);

// args: prep time, duration, difficulty
API_CALLABLE(action_command_spiny_surge_start);

void action_command_spiny_surge_update(void);
void action_command_spiny_surge_draw(void);
void action_command_spiny_surge_free(void);

enum {
    SPINY_SURGE_RESET   = -1,
    SPINY_SURGE_NONE    = 0,
    SPINY_SURGE_HOLD    = 1,
    SPINY_SURGE_THROW   = 2,
    SPINY_SURGE_IGNORE  = 3,
};

#endif
