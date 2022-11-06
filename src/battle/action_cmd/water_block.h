#ifndef _WATER_BLOCK_H_
#define _WATER_BLOCK_H_

#include "common_structs.h"

ApiStatus action_command_water_block_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_water_block_start(Evt* script, s32 isInitialCall);
void action_command_water_block_update(void);
void action_command_water_block_draw(void);
void action_command_water_block_free(void);

#endif
