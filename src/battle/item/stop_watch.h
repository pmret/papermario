#ifndef BATTLE_ITEM_STOP_WATCH
#define BATTLE_ITEM_STOP_WATCH

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_stop_watch

ApiStatus func_80252B3C(ScriptInstance* script, s32 isInitialCall);

ApiStatus N(FadeBackgroundToBlack)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A12D4_7270A4)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);

#endif
 
 
