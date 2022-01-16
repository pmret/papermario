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

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);
extern EvtScript N(EatItem);
extern EvtScript N(script7);
extern EvtScript N(script8);
extern EvtScript N(script9);

#endif


