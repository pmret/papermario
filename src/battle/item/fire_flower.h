#ifndef BATTLE_ITEM_FIRE_FLOWER
#define BATTLE_ITEM_FIRE_FLOWER

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_fire_flower

ApiStatus N(FadeBackgroundToBlack)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A123C_716E9C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A1378_716FD8)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);

#endif
