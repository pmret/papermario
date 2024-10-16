#ifndef _WATER_BLOCK_H_
#define _WATER_BLOCK_H_

#include "common_structs.h"

API_CALLABLE(action_command_water_block_init);
API_CALLABLE(action_command_water_block_start);
void action_command_water_block_update(void);
void action_command_water_block_draw(void);
void action_command_water_block_free(void);

// variants for this action command
enum {
    TIMING_BUFF_WATER_BLOCK     = 0,
    TIMING_BUFF_TURBO_CHARGE    = 1,
    TIMING_BUFF_CLOUD_NINE      = 2,
};

#endif
