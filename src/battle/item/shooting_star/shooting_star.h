#ifndef BATTLE_ITEM_SHOOTING_STAR
#define BATTLE_ITEM_SHOOTING_STAR

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_shooting_star

ApiStatus N(func_802A1444_71DBB4)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A123C_71D9AC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A1388_71DAF8)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A14D4_71DC44)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);

#endif
