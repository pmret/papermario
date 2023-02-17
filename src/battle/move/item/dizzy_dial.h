#ifndef BATTLE_ITEM_DIZZY_DIAL
#define BATTLE_ITEM_DIZZY_DIAL

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_dizzy_dial

API_CALLABLE(ItemAfflictEnemy);
API_CALLABLE(N(func_802A1270_727B80));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);

#endif
