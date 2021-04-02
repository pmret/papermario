#include "common.h"
#include "map.h"

#define NAMESPACE arn_07

void func_802D6420(void);
void func_802D6954(void);
void func_802CF56C(void);

s32 N(func_8024004C_BECE3C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape);
s32 N(func_802401AC_BECF9C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape);
s32 N(func_80240000_BECDF0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape);
s32 N(func_802405BC_BED3AC)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape);
s32 N(func_802405FC_BED3EC)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape);
s32 N(func_80240708_BED4F8)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape);
s32 N(func_80240800_BED5F0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape);
ApiStatus N(GetEntityPosition)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(SetEntityFlags100000)(ScriptInstance* script, s32 isInitialCall);
s32 N(func_80241C5C_BEEA4C)(ScriptInstance *script, NpcAISettings *aiSettings);
ApiStatus PostChapter3StatUpdate(ScriptInstance* script, s32 isInitialCall);

Script N(script_Main);
Script N(script_80241F10);
Script N(script_80243790);
Script N(script_802439B0);
NpcGroupList N(npcGroupList_802478B8);
NpcGroupList N(npcGroupList_8024787C);
NpcGroupList N(npcGroupList_802478E8);
NpcGroupList N(npcGroupList_802478B8);
Script N(script_MakeEntities);
Script N(script_80243790);
Script N(script_802437AC);
// Script N(script_ExitWalk_80242978);
// Script N(script_ExitWalk_802429D4);
Script N(script_ExitSingleDoor_802428D4);
// Script N(itemList_80242040);
Script N(script_80242048);
// Script N(script_80242498);
