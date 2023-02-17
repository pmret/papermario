#ifndef BATTLE_ITEM_THUNDER_RAGE
#define BATTLE_ITEM_THUNDER_RAGE

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_thunder_rage

API_CALLABLE(N(FadeBackgroundToBlack));
API_CALLABLE(N(func_802A1354_71B4F4));
API_CALLABLE(N(func_802A12D4_71B474));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);

#endif
