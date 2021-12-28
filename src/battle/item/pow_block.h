#ifndef BATTLE_ITEM_POW_BLOCK
#define BATTLE_ITEM_POW_BLOCK

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_pow_block

ApiStatus func_80269EAC(Evt* script, s32 isInitialCall);

ApiStatus N(func_802A1318_718B68)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A123C_718A8C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A12E4_718B34)(Evt* script, s32 isInitialCall);

EvtSource N(UseItemWithEffect);
EvtSource N(PlayerGoHome);

#endif
