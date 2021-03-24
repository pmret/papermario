#ifndef BATTLE_ITEM_POW_BLOCK
#define BATTLE_ITEM_POW_BLOCK

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_pow_block

ApiStatus func_80273444(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_80269EAC(ScriptInstance* script, s32 isInitialCall);

ApiStatus N(func_802A1318_718B68)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A123C_718A8C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A12E4_718B34)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);

#endif
