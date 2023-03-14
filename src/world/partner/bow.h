#ifndef _WORLD_PARTNER_BOW_H_
#define _WORLD_PARTNER_BOW_H_

#include "common.h"
#include "script_api/map.h"

void world_bow_init(Npc*);
void world_bow_pre_battle(Npc*);

extern EvtScript EVS_WorldBow_TakeOut;
extern EvtScript EVS_WorldBow_Update;
extern EvtScript EVS_WorldBow_UseAbility;
extern EvtScript EVS_WorldBow_PutAway;

#endif
