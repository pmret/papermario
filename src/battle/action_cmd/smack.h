#ifndef _SMACK_H_
#define _SMACK_H_

#include "common_structs.h"

ApiStatus action_command_smack_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_smack_start(Evt* script, s32 isInitialCall);
void action_command_smack_update(void);
void action_command_smack_draw(void);
void action_command_smack_free(void);

#endif
