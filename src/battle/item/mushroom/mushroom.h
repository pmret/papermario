#ifndef BATTLE_ITEM_MUSHROOM
#define BATTLE_ITEM_MUSHROOM

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_mushroom

ApiStatus func_802D3F74(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D378C(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D7520(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D75D8(ScriptInstance* script, s32 isInitialCall);

ApiStatus N(func_802A123C_715A8C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A12EC_715B3C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A15A0_715DF0)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A1378_715BC8)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A1438_715C88)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(AddHP)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(AddFP)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);
Script N(UseItem);
Script N(EatItem);

#endif
