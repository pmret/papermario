#ifndef _WORLD_PARTNER_LAKILESTER_H_
#define _WORLD_PARTNER_LAKILESTER_H_

#include "common.h"
#include "script_api/map.h"

void world_lakilester_init(Npc*);
void world_lakilester_pre_battle(Npc*);
void world_lakilester_post_battle(Npc*);

extern EvtScript EVS_WorldLakilester_TakeOut;
extern EvtScript EVS_WorldLakilester_Update;
extern EvtScript EVS_WorldLakilester_UseAbility;
extern EvtScript EVS_WorldLakilester_PutAway;
extern EvtScript evs_worldlakilester_riding;

#endif
