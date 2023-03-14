#ifndef _WORLD_PARTNER_KOOPER_H_
#define _WORLD_PARTNER_KOOPER_H_

#include "common.h"
#include "script_api/map.h"

void world_kooper_init(Npc*);
s32 world_kooper_test_first_strike(Npc*, Npc*);
void world_kooper_pre_battle(Npc*);
void world_kooper_post_battle(Npc*);

extern EvtScript EVS_WorldKooper_TakeOut;
extern EvtScript EVS_WorldKooper_Update;
extern EvtScript EVS_WorldKooper_UseAbility;
extern EvtScript EVS_WorldKooper_PutAway;

#endif
