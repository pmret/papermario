#ifndef _WORLD_PARTNER_WATT_H_
#define _WORLD_PARTNER_WATT_H_

#include "common.h"
#include "script_api/map.h"

void world_watt_init(Npc*);
void world_watt_pre_battle(Npc*);
void world_watt_post_battle(Npc*);

extern EvtScript world_watt_take_out;
extern EvtScript world_watt_update;
extern EvtScript world_watt_use_ability;
extern EvtScript world_watt_put_away;
extern EvtScript world_watt_while_riding;

#endif
