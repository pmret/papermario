#ifndef BATTLE_ITEM_SLEEPY_SHEEP
#define BATTLE_ITEM_SLEEPY_SHEEP

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_sleepy_sheep

ApiStatus func_80273444(Evt* script, s32 isInitialCall);
ApiStatus SetVirtualEntityMoveSpeed(Evt* script, s32 isInitialCall);
ApiStatus VirtualEntityMoveTo(Evt* script, s32 isInitialCall);
ApiStatus func_80252B3C(Evt* script, s32 isInitialCall);

ApiStatus N(func_802A123C_71E88C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A1740_71ED90)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A1848_71EE98)(Evt* script, s32 isInitialCall);

EvtSource N(UseItemWithEffect);
EvtSource N(PlayerGoHome);

#endif


