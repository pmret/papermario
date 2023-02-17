#ifndef BATTLE_ITEM_THUNDER_BOLT
#define BATTLE_ITEM_THUNDER_BOLT

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_thunder_bolt

API_CALLABLE(N(FadeBackgroundToBlack));
API_CALLABLE(N(func_802A123C_722D7C));
API_CALLABLE(N(func_802A1420_722F60));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);

#endif
