#ifndef _WORLD_PARTNER_LAKILESTER_H_
#define _WORLD_PARTNER_LAKILESTER_H_

#include "common.h"
#include "script_api/map.h"

void world_lakilester_init(Npc*);
void world_lakilester_pre_battle(Npc*);
void world_lakilester_post_battle(Npc*);

extern EvtSource world_lakilester_take_out;
extern EvtSource world_lakilester_update;
extern EvtSource world_lakilester_use_ability;
extern EvtSource world_lakilester_put_away;
extern EvtSource world_lakilester_while_riding;

#endif
