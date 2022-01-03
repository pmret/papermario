#ifndef BATTLE_ITEM_STRANGE_CAKE
#define BATTLE_ITEM_STRANGE_CAKE

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_strange_cake

ApiStatus N(func_802A1A8C_731D8C)(Evt *script, s32 isInitialCall);
ApiStatus N(func_802A18D8_731BD8)(Evt *script, s32 isInitialCall);
ApiStatus N(AddFP)(Evt *script, s32 isInitialCall);
ApiStatus N(func_802A13E4_7316E4)(Evt *script, s32 isInitialCall);
ApiStatus N(func_802A1AD8_731DD8)(Evt *script, s32 isInitialCall);
ApiStatus N(func_802A1B14_731E14)(Evt *script, s32 isInitialCall);
ApiStatus N(func_802A1B68_731E68)(Evt *script, s32 isInitialCall);

extern EvtSource N(UseItemWithEffect);
extern EvtSource N(PlayerGoHome);
extern EvtSource N(EatItem);
extern EvtSource N(script7);
extern EvtSource N(script8);
extern EvtSource N(script9);

#endif


