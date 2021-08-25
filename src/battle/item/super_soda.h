#ifndef BATTLE_ITEM_SUPER_SODA
#define BATTLE_ITEM_SUPER_SODA

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_super_soda

ApiStatus SetVirtualEntityFlags(Evt* script, s32 isInitialCall);
ApiStatus GetVirtualEntityPosition(Evt* script, s32 isInitialCall);
ApiStatus func_802D75D8(Evt* script, s32 isInitialCall);
ApiStatus func_802D7520(Evt* script, s32 isInitialCall);

ApiStatus N(func_802A123C_724F1C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A12EC_724FCC)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A1418_7250F8)(Evt* script, s32 isInitialCall);
ApiStatus N(AddFP)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802A1378_725058)(Evt* script, s32 isInitialCall);

EvtSource N(UseItemWithEffect);
EvtSource N(PlayerGoHome);
EvtSource N(UseItem);

#endif
