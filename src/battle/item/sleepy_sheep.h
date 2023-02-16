#ifndef BATTLE_ITEM_SLEEPY_SHEEP
#define BATTLE_ITEM_SLEEPY_SHEEP

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_sleepy_sheep

API_CALLABLE(SetVirtualEntityMoveSpeed);
API_CALLABLE(VirtualEntityMoveTo);
API_CALLABLE(ItemAfflictEnemy);

API_CALLABLE(N(func_802A123C_71E88C));
API_CALLABLE(N(func_802A1740_71ED90));
API_CALLABLE(N(func_802A1848_71EE98));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);

#endif


