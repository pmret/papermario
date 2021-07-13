#ifndef BATTLE_ITEM_VOLT_SHROOM
#define BATTLE_ITEM_VOLT_SHROOM

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_volt_shroom

ApiStatus N(func_802A123C_71AA2C)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);
Script N(EatItem);

#endif
