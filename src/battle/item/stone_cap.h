#ifndef BATTLE_ITEM_STONE_CAP
#define BATTLE_ITEM_STONE_CAP

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_stone_cap

ApiStatus N(func_802A123C_7217DC)(Evt* script, s32 isInitialCall);

EvtSource N(UseItemWithEffect);
EvtSource N(PlayerGoHome);

#endif


