#ifndef BATTLE_ITEM_SNOWMAN_DOLL
#define BATTLE_ITEM_SNOWMAN_DOLL

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_snowman_doll

ApiStatus N(FadeBackgroundToBlack)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A123C_71C06C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A13B8_71C1E8)(Evt* script, s32 isInitialCall);

EvtSource N(UseItemWithEffect);
EvtSource N(PlayerGoHome);

#endif


