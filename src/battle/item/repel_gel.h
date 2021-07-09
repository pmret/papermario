#ifndef BATTLE_ITEM_REPEL_GEL
#define BATTLE_ITEM_REPEL_GEL

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_repel_gel

ApiStatus N(func_802A123C_72DDAC)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);

#endif
