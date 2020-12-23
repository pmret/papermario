#ifndef _WORLD_PARTNER_GOOMBARIO_H_
#define _WORLD_PARTNER_GOOMBARIO_H_

#include "common.h"
#include "script_api/map.h"

void world_goombario_init(Npc* partner);
s32 world_goombario_can_pause(Npc* partner);
ApiStatus func_802BDB84(ScriptInstance* script, s32 isInitialCall);
void world_goombario_pre_battle(s32 arg0);

extern Script world_goombario_take_out;

#endif
