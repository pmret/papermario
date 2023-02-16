#ifndef BATTLE_ITEM_FIRE_FLOWER
#define BATTLE_ITEM_FIRE_FLOWER

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_fire_flower

API_CALLABLE(N(FadeBackgroundToBlack));
API_CALLABLE(N(func_802A123C_716E9C));
API_CALLABLE(N(func_802A1378_716FD8));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);

#endif
