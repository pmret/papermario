#ifndef BATTLE_ITEM_SUPER_SODA
#define BATTLE_ITEM_SUPER_SODA

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_super_soda

API_CALLABLE(N(func_802A123C_724F1C));
API_CALLABLE(N(func_802A12EC_724FCC));
API_CALLABLE(N(func_802A1418_7250F8));
API_CALLABLE(N(AddFP));
API_CALLABLE(N(func_802A1378_725058));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);
extern EvtScript N(UseItem);

#endif
