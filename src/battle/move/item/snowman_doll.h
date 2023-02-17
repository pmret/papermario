#ifndef BATTLE_ITEM_SNOWMAN_DOLL
#define BATTLE_ITEM_SNOWMAN_DOLL

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_snowman_doll

API_CALLABLE(N(FadeBackgroundToBlack));
API_CALLABLE(N(func_802A123C_71C06C));
API_CALLABLE(N(func_802A13B8_71C1E8));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);

#endif


