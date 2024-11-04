#ifndef _SMACK_H_
#define _SMACK_H_

#include "common_structs.h"

// args: none
API_CALLABLE(action_command_smack_init);

// args: prep time, duration, difficulty, variation
API_CALLABLE(action_command_smack_start);

void action_command_smack_update(void);
void action_command_smack_draw(void);
void action_command_smack_free(void);

// variants for this action command
enum {
    ACV_SMACK_HAND      = 0,
    ACV_SMACK_FAN       = 1,
};

#endif
