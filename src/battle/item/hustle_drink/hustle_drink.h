#ifndef BATTLE_ITEM_HUSTLE_DRINK
#define BATTLE_ITEM_HUSTLE_DRINK

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_hustle_drink

ApiStatus func_802D7520(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A12C4_726224)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A123C_72619C)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);
Script N(DrinkItem);

#endif
