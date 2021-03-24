#ifndef BATTLE_ITEM_SLEEPY_SHEEP
#define BATTLE_ITEM_SLEEPY_SHEEP

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_sleepy_sheep

ApiStatus func_80273444(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D3998(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D3A60(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_80252B3C(ScriptInstance* script, s32 isInitialCall);

ApiStatus N(func_802A123C_71E88C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A1740_71ED90)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A1848_71EE98)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);

#endif
 
 
