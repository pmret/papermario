#ifndef BATTLE_ITEM_STRANGE_CAKE
#define BATTLE_ITEM_STRANGE_CAKE

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_strange_cake

ApiStatus func_802D75D8(Evt *script, s32 isInitialCall);
ApiStatus func_802D7520(Evt *script, s32 isInitialCall);

ApiStatus N(func_802A1A8C_731D8C)(Evt *script, s32 isInitialCall);
ApiStatus N(func_802A18D8_731BD8)(Evt *script, s32 isInitialCall);
ApiStatus N(AddFP)(Evt *script, s32 isInitialCall);
ApiStatus N(func_802A13E4_7316E4)(Evt *script, s32 isInitialCall);
ApiStatus N(func_802A1AD8_731DD8)(Evt *script, s32 isInitialCall);
ApiStatus N(func_802A1B14_731E14)(Evt *script, s32 isInitialCall);
ApiStatus N(func_802A1B68_731E68)(Evt *script, s32 isInitialCall);

EvtSource N(UseItemWithEffect);
EvtSource N(PlayerGoHome);
EvtSource N(EatItem);
EvtSource N(script7);
EvtSource N(script8);
EvtSource N(script9);

#endif


