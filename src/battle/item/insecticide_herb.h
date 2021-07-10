#ifndef BATTLE_ITEM_INSECTICIDE_HERB
#define BATTLE_ITEM_INSECTICIDE_HERB

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_insecticide_herb

Script N(UseItemWithEffect);
Script N(PlayerGoHome);
ApiStatus N(func_802A12E0_72AA30)(ScriptInstance *script, s32 isInitialCall);
ApiStatus N(func_802A123C_72A98C)(ScriptInstance *script, s32 isInitialCall);
ApiStatus N(func_802A1280_72A9D0)(ScriptInstance *script, s32 isInitialCall);

#endif
