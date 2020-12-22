#ifndef _WORLD_PARTNER_GOOMBARIO_H_
#define _WORLD_PARTNER_GOOMBARIO_H_

#include "common.h"
#include "script_api/map.h"

s32 func_802BD100(s32 arg0);
void world_goombario_init(Npc* npc);
s32 func_802BD188();
s32 func_802BD1D0();
s32 func_802BD564();
s32 func_802BD5A8();
s32 func_802BD5D8();
s32 func_802BDB30();
ApiStatus func_802BDB84(ScriptInstance* script, s32 isInitialCall);
void world_goombario_pre_battle(s32 arg0);

extern Script world_goombario_take_out;

#endif
