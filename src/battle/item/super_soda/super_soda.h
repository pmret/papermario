#ifndef BATTLE_ITEM_SUPER_SODA
#define BATTLE_ITEM_SUPER_SODA

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_super_soda

ApiStatus func_802D3F74(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D378C(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D75D8(ScriptInstance* script, s32 isInitialCall);
ApiStatus func_802D7520(ScriptInstance* script, s32 isInitialCall);

ApiStatus N(func_802A123C_724F1C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A12EC_724FCC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A1418_7250F8)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(AddFP)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A1378_725058)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);
Script N(UseItem);

#endif
