#ifndef BATTLE_ITEM_THUNDER_BOLT
#define BATTLE_ITEM_THUNDER_BOLT

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_thunder_bolt

ApiStatus N(FadeBackgroundToBlack)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A123C_722D7C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A1420_722F60)(Evt* script, s32 isInitialCall);

EvtSource N(UseItemWithEffect);
EvtSource N(PlayerGoHome);

#endif
