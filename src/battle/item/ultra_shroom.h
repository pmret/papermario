#ifndef BATTLE_ITEM_ULTRA_SHROOM
#define BATTLE_ITEM_ULTRA_SHROOM

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_ultra_shroom

API_CALLABLE(N(func_802A123C_7239BC));
API_CALLABLE(N(func_802A12FC_723A7C));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);
extern EvtScript N(EatItem);

#endif
