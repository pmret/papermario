#ifndef BATTLE_ITEM_FOOD
#define BATTLE_ITEM_FOOD

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_food

API_CALLABLE(N(func_802A123C_73330C));
API_CALLABLE(N(func_802A12EC_7333BC));
API_CALLABLE(N(func_802A15A0_733670));
API_CALLABLE(N(func_802A1378_733448));
API_CALLABLE(N(func_802A1438_733508));
API_CALLABLE(N(AddHP));
API_CALLABLE(N(AddFP));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);
extern EvtScript N(UseItem);
extern EvtScript N(EatItem);
extern EvtScript N(DrinkItem);

#endif
