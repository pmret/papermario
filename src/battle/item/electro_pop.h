#ifndef BATTLE_ITEM_ELECTRO_POP
#define BATTLE_ITEM_ELECTRO_POP

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_electro_pop

ApiStatus N(func_802A123C_7307DC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A14F0_730A90)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A133C_7308DC)(Evt* script, s32 isInitialCall);
ApiStatus N(AddFP)(Evt* script, s32 isInitialCall);

EvtSource N(UseItemWithEffect);
EvtSource N(PlayerGoHome);
EvtSource N(EatItem);

#endif
