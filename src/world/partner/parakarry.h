#ifndef _WORLD_PARTNER_PARAKARRY_H_
#define _WORLD_PARTNER_PARAKARRY_H_

#include "common.h"
#include "script_api/map.h"

void world_parakarry_init(Npc*);
void world_parakarry_pre_battle(Npc*);
void world_parakarry_post_battle(Npc*);

extern EvtSource world_parakarry_take_out;
extern EvtSource world_parakarry_update;
extern EvtSource world_parakarry_use_ability;
extern EvtSource world_parakarry_put_away;

#endif
