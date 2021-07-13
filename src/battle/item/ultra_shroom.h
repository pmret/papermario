#ifndef BATTLE_ITEM_ULTRA_SHROOM
#define BATTLE_ITEM_ULTRA_SHROOM

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_ultra_shroom

ApiStatus func_802D7520(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D75D8(ScriptInstance* script, s32 isInitialCall);

ApiStatus N(func_802A123C_7239BC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A12FC_723A7C)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);
Script N(EatItem);

#endif
