#ifndef BATTLE_ITEM_ELECTRO_POP
#define BATTLE_ITEM_ELECTRO_POP

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_electro_pop

API_CALLABLE(N(func_802A123C_7307DC));
API_CALLABLE(N(func_802A14F0_730A90));
API_CALLABLE(N(func_802A133C_7308DC));
API_CALLABLE(N(AddFP));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);
extern EvtScript N(EatItem);

#endif
