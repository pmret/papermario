#ifndef BATTLE_ITEM_STOP_WATCH
#define BATTLE_ITEM_STOP_WATCH

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_stop_watch

API_CALLABLE(ItemAfflictEnemy);

API_CALLABLE(N(FadeBackgroundToBlack));
API_CALLABLE(N(func_802A12D4_7270A4));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);

#endif


