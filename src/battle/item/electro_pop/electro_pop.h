#ifndef BATTLE_ITEM_ELECTRO_POP
#define BATTLE_ITEM_ELECTRO_POP

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_electro_pop

ApiStatus func_802D7520(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D75D8(ScriptInstance* script, s32 isInitialCall);

ApiStatus N(func_802A123C_7307DC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A14F0_730A90)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A133C_7308DC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(AddFP)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);
Script N(EatItem);

#endif
