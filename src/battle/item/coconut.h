#ifndef BATTLE_ITEM_COCONUT
#define BATTLE_ITEM_COCONUT

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_coconut

EvtSource N(UseItemWithEffect);
EvtSource N(PlayerGoHome);

ApiStatus func_802A1000_72F720(Evt* script, s32 isInitialCall);
ApiStatus func_802A11D4_72F8F4(Evt* script, s32 isInitialCall);

#endif
