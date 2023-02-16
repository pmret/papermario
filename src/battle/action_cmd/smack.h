#ifndef _SMACK_H_
#define _SMACK_H_

#include "common_structs.h"

API_CALLABLE(action_command_smack_init);
API_CALLABLE(action_command_smack_start);
void action_command_smack_update(void);
void action_command_smack_draw(void);
void action_command_smack_free(void);

#endif
