#ifndef BATTLE_ITEM_TASTY_TONIC
#define BATTLE_ITEM_TASTY_TONIC

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_tasty_tonic

ApiStatus func_802D7520(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D75D8(ScriptInstance* script, s32 isInitialCall);

ApiStatus N(func_802A123C_72223C)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);
Script N(DrinkItem);

#endif
