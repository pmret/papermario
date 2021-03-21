#ifndef BATTLE_ITEM_LIFE_SHROOM
#define BATTLE_ITEM_LIFE_SHROOM

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_life_shroom

ApiStatus func_802D3F74(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D378C(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D7520(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D75D8(ScriptInstance* script, s32 isInitialCall);

ApiStatus N(func_802A123C_72E76C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A12EC_72E81C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A1484_72E9B4)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A1438_72E968)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A1378_72E8A8)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);
Script N(UseItem);
Script N(EatItem);

#endif
