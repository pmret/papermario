#ifndef BATTLE_ITEM_FOOD
#define BATTLE_ITEM_FOOD

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_food

ApiStatus func_802D3F74(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D378C(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D7520(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D75D8(ScriptInstance* script, s32 isInitialCall);

ApiStatus N(func_802A123C_73330C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A12EC_7333BC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A15A0_733670)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A1378_733448)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A1438_733508)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(AddHP)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(AddFP)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);
Script N(UseItem);
Script N(EatItem);
Script N(DrinkItem);

#endif
