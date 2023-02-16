#ifndef BATTLE_ITEM_POW_BLOCK
#define BATTLE_ITEM_POW_BLOCK

#include "common.h"
#include "script_api/battle.h"
#include "entity.h"

#undef NAMESPACE
#define NAMESPACE battle_item_pow_block

API_CALLABLE(N(func_802A1318_718B68));
API_CALLABLE(N(func_802A123C_718A8C));
API_CALLABLE(N(func_802A12E4_718B34));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);

#endif
