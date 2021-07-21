#ifndef BATTLE_ITEM_UNKNOWN_ITEM
#define BATTLE_ITEM_UNKNOWN_ITEM

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_unknown_item

ApiStatus func_802D7520(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D75D8(ScriptInstance* script, s32 isInitialCall);

ApiStatus N(func_802A123C_72447C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A12FC_72453C)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);
Script N(EatItem);

#endif
