#ifndef BATTLE_ITEM_MUSHROOM
#define BATTLE_ITEM_MUSHROOM

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_mushroom

API_CALLABLE(N(func_802A123C_715A8C));
API_CALLABLE(N(func_802A12EC_715B3C));
API_CALLABLE(N(func_802A15A0_715DF0));
API_CALLABLE(N(func_802A1378_715BC8));
API_CALLABLE(N(func_802A1438_715C88));
API_CALLABLE(N(AddHP));
API_CALLABLE(N(AddFP));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);
extern EvtScript N(UseItem);
extern EvtScript N(EatItem);

#endif
