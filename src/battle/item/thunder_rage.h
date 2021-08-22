#ifndef BATTLE_ITEM_THUNDER_RAGE
#define BATTLE_ITEM_THUNDER_RAGE

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_thunder_rage

ApiStatus N(FadeBackgroundToBlack)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A1354_71B4F4)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A12D4_71B474)(Evt* script, s32 isInitialCall);

EvtSource N(UseItemWithEffect);
EvtSource N(PlayerGoHome);

#endif
