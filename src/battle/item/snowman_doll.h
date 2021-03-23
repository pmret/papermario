#ifndef BATTLE_ITEM_SNOWMAN_DOLL
#define BATTLE_ITEM_SNOWMAN_DOLL

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_snowman_doll

ApiStatus N(FadeBackgroundToBlack)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A123C_71C06C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A13B8_71C1E8)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);

#endif
 
 
