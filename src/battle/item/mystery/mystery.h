#ifndef BATTLE_ITEM_MYSTERY
#define BATTLE_ITEM_MYSTERY

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_mystery

struct N(tempStc) {
    s32 iconId;
    s32 unk_04;
} N(tempStc);

s32 N(D_802A227C_72D82C)[8];
s32 N(D_802A229C_72D84C)[8];

ApiStatus N(func_802A13E4_72C994)(ScriptInstance *script, s32 isInitialCall);
ApiStatus N(func_802A188C_72CE3C)(ScriptInstance *script, s32 isInitialCall);

#endif
