#ifndef BATTLE_ITEM_HUSTLE_DRINK
#define BATTLE_ITEM_HUSTLE_DRINK

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_hustle_drink

API_CALLABLE(N(func_802A12C4_726224));
API_CALLABLE(N(func_802A123C_72619C));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);
extern EvtScript N(DrinkItem);

#endif
