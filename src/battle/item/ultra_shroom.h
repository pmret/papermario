#ifndef BATTLE_ITEM_ULTRA_SHROOM
#define BATTLE_ITEM_ULTRA_SHROOM

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_ultra_shroom

ApiStatus N(func_802A123C_7239BC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A12FC_723A7C)(Evt* script, s32 isInitialCall);

EvtSource N(UseItemWithEffect);
EvtSource N(PlayerGoHome);
EvtSource N(EatItem);

#endif
