#ifndef _WORLD_PARTNER_GOOMBARIO_H_
#define _WORLD_PARTNER_GOOMBARIO_H_

#include "common.h"
#include "script_api/map.h"

void world_goombario_init(Npc* partner);
s32 world_goombario_can_pause(Npc* partner);
ApiStatus WorldGoombarioPutAway(Evt* script, s32 isInitialCall);
void world_goombario_pre_battle(Npc* partner);
s32 world_goombario_get_trigger_tattle(s32 arg0);

extern EvtScript EVS_GoombarioTakeOut;
extern EvtScript EVS_GoombarioUpdate;
extern EvtScript EVS_GoombarioUseAbility;
extern EvtScript EVS_GoombarioPutAway;

#endif
