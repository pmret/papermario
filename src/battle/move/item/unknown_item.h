#ifndef BATTLE_ITEM_UNKNOWN_ITEM
#define BATTLE_ITEM_UNKNOWN_ITEM

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_unknown_item

API_CALLABLE(N(func_802A123C_72447C));
API_CALLABLE(N(func_802A12FC_72453C));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);
extern EvtScript N(EatItem);

#endif
