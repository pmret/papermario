#ifndef BATTLE_ITEM_STOP_WATCH
#define BATTLE_ITEM_STOP_WATCH

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_stop_watch

ApiStatus ItemAfflictEnemy(Evt* script, s32 isInitialCall);

ApiStatus N(FadeBackgroundToBlack)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A12D4_7270A4)(Evt* script, s32 isInitialCall);

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);

#endif


