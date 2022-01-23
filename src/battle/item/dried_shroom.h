#ifndef BATTLE_ITEM_DRIED_SHROOM
#define BATTLE_ITEM_DRIED_SHROOM

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_dried_shroom

ApiStatus N(func_802A123C_71CF1C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A12FC_71CFDC)(Evt* script, s32 isInitialCall);

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);
extern EvtScript N(EatItem);

#endif
