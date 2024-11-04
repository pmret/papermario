#ifndef _AIR_RAID_H_
#define _AIR_RAID_H_

#include "common_structs.h"

// args: none
API_CALLABLE(action_command_air_raid_init);

// args: prep time, duration, difficulty
API_CALLABLE(action_command_air_raid_start);

void action_command_air_raid_update(void);
void action_command_air_raid_draw(void);
void action_command_air_raid_free(void);

#endif
