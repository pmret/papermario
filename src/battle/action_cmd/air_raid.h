#ifndef _AIR_RAID_H_
#define _AIR_RAID_H_

#include "common_structs.h"

ApiStatus action_command_air_raid_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_air_raid_start(Evt* script, s32 isInitialCall);
void action_command_air_raid_update(void);
void action_command_air_raid_draw(void);
void action_command_air_raid_free(void);

#endif
