#ifndef BATTLE_ITEM_MUSHROOM
#define BATTLE_ITEM_MUSHROOM

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_mushroom

ApiStatus N(func_802A123C_715A8C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A12EC_715B3C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A15A0_715DF0)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A1378_715BC8)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A1438_715C88)(Evt* script, s32 isInitialCall);
ApiStatus N(AddHP)(Evt* script, s32 isInitialCall);
ApiStatus N(AddFP)(Evt* script, s32 isInitialCall);

EvtSource N(UseItemWithEffect);
EvtSource N(PlayerGoHome);
EvtSource N(UseItem);
EvtSource N(EatItem);

#endif
