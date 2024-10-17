#ifndef _THREE_CHANCES_H_
#define _THREE_CHANCES_H_

#include "common_structs.h"

API_CALLABLE(action_command_three_chances_init);
API_CALLABLE(action_command_three_chances_start);
void action_command_three_chances_update(void);
void action_command_three_chances_draw(void);
void action_command_three_chances_free(void);

// variants for this action command
enum {
    ACV_THREE_CHANCES_WATER_BLOCK   = 0,
    ACV_THREE_CHANCES_TURBO_CHARGE  = 1,
    ACV_THREE_CHANCES_CLOUD_NINE    = 2,
};

#endif
