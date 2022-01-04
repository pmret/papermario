#ifndef BATTLE_ITEM_FOOD
#define BATTLE_ITEM_FOOD

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_food

ApiStatus N(func_802A123C_73330C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A12EC_7333BC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A15A0_733670)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A1378_733448)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A1438_733508)(Evt* script, s32 isInitialCall);
ApiStatus N(AddHP)(Evt* script, s32 isInitialCall);
ApiStatus N(AddFP)(Evt* script, s32 isInitialCall);

extern EvtSource N(UseItemWithEffect);
extern EvtSource N(PlayerGoHome);
extern EvtSource N(UseItem);
extern EvtSource N(EatItem);
extern EvtSource N(DrinkItem);

#endif
