#include "common.h"
#include "map.h"

#define NAMESPACE dgb_15

ApiStatus N(GetEntityPosition)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(SetEntityFlags100000)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc1)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_8024061C_C4FB2C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241464_C50974)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(UnkFunc7)(ScriptInstance* script, s32 isInitialCall);

NpcGroupList N(npcGroupList_80242AB0);
Script N(80242AD0);
Script N(main);
Script N(makeEntities);
Script N(npcAI_8024274C);
Script N(unk_80241F8C);
