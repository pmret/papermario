#ifndef BATTLE_ITEM_LIFE_SHROOM
#define BATTLE_ITEM_LIFE_SHROOM

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_life_shroom

API_CALLABLE(N(func_802A123C_72E76C));
API_CALLABLE(N(func_802A12EC_72E81C));
API_CALLABLE(N(func_802A1484_72E9B4));
API_CALLABLE(N(func_802A1438_72E968));
API_CALLABLE(N(func_802A1378_72E8A8));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);
extern EvtScript N(UseItem);
extern EvtScript N(EatItem);

#endif
