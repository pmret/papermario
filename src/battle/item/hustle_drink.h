#ifndef BATTLE_ITEM_HUSTLE_DRINK
#define BATTLE_ITEM_HUSTLE_DRINK

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_hustle_drink

ApiStatus N(func_802A12C4_726224)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A123C_72619C)(Evt* script, s32 isInitialCall);

extern EvtSource N(UseItemWithEffect);
extern EvtSource N(PlayerGoHome);
extern EvtSource N(DrinkItem);

#endif
