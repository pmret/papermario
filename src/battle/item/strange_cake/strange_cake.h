#ifndef BATTLE_ITEM_STRANGE_CAKE
#define BATTLE_ITEM_STRANGE_CAKE

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE 
#define NAMESPACE battle_item_strange_cake

ApiStatus func_802D75D8(ScriptInstance *script, s32 isInitialCall);
ApiStatus func_802D7520(ScriptInstance *script, s32 isInitialCall);

ApiStatus N(func_802A1A8C_731D8C)(ScriptInstance *script, s32 isInitialCall);
ApiStatus N(func_802A18D8_731BD8)(ScriptInstance *script, s32 isInitialCall);
ApiStatus N(AddFP)(ScriptInstance *script, s32 isInitialCall);
ApiStatus N(func_802A13E4_7316E4)(ScriptInstance *script, s32 isInitialCall);
ApiStatus N(func_802A1AD8_731DD8)(ScriptInstance *script, s32 isInitialCall);
ApiStatus N(func_802A1B14_731E14)(ScriptInstance *script, s32 isInitialCall);
ApiStatus N(func_802A1B68_731E68)(ScriptInstance *script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);
Script N(EatItem);
Script N(script7);
Script N(script8);
Script N(script9);

#endif
 
 
