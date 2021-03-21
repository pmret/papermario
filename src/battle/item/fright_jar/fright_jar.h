#ifndef BATTLE_ITEM_FRIGHT_JAR
#define BATTLE_ITEM_FRIGHT_JAR

#include "common.h"
#include "script_api/battle.h"

#undef NAMESPACE
#define NAMESPACE battle_item_fright_jar

ApiStatus func_80269EAC(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(FadeBackgroundToBlack)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802A12D4_72BBE4)(ScriptInstance* script, s32 isInitialCall);

Script N(UseItemWithEffect);
Script N(PlayerGoHome);

#endif
