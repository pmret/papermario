#ifndef BATTLE_ITEM_FRIGHT_JAR
#define BATTLE_ITEM_FRIGHT_JAR

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_fright_jar

API_CALLABLE(N(FadeBackgroundToBlack));
API_CALLABLE(N(func_802A12D4_72BBE4));

extern EvtScript N(UseItemWithEffect);
extern EvtScript N(PlayerGoHome);

#endif
