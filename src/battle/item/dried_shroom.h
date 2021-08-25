#ifndef BATTLE_ITEM_DRIED_SHROOM
#define BATTLE_ITEM_DRIED_SHROOM

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_dried_shroom

ApiStatus func_802D7520(Evt* script, s32 isInitialCall);
ApiStatus func_802D75D8(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A123C_71CF1C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A12FC_71CFDC)(Evt* script, s32 isInitialCall);

EvtSource N(UseItemWithEffect);
EvtSource N(PlayerGoHome);
EvtSource N(EatItem);

#endif
