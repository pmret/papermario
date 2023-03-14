#ifndef _WORLD_PARTNER_PARAKARRY_H_
#define _WORLD_PARTNER_PARAKARRY_H_

#include "common.h"
#include "script_api/map.h"

void world_parakarry_init(Npc*);
void world_parakarry_pre_battle(Npc*);
void world_parakarry_post_battle(Npc*);

extern EvtScript EVS_WorldParakarry_TakeOut;
extern EvtScript EVS_WorldParakarry_Update;
extern EvtScript EVS_WorldParakarry_UseAbility;
extern EvtScript EVS_WorldParakarry_PutAway;

#endif
