#ifndef BATTLE_ITEM_INSECTICIDE_HERB
#define BATTLE_ITEM_INSECTICIDE_HERB

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_insecticide_herb

EvtSource N(UseItemWithEffect);
EvtSource N(PlayerGoHome);
ApiStatus N(func_802A12E0_72AA30)(Evt *script, s32 isInitialCall);
ApiStatus N(func_802A123C_72A98C)(Evt *script, s32 isInitialCall);
ApiStatus N(func_802A1280_72A9D0)(Evt *script, s32 isInitialCall);

#endif
