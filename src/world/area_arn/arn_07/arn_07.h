#include "common.h"
#include "map.h"
#include "../arn.h"

#define NAMESPACE arn_07

ApiStatus N(func_80240000_BECDF0)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_8024004C_BECE3C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802401AC_BECF9C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802405BC_BED3AC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_802405FC_BED3EC)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240708_BED4F8)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80240800_BED5F0)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(func_80241C5C_BEEA4C)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(SetEntityFlags100000)(ScriptInstance* script, s32 isInitialCall);
ApiStatus N(GetEntityPosition)(ScriptInstance* script, s32 isInitialCall);
ApiStatus PostChapter3StatUpdate(ScriptInstance* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_8024787C);
extern NpcGroupList N(npcGroupList_802478B8);
extern NpcGroupList N(npcGroupList_802478E8);
extern Script N(exitSingleDoor_802428D4);
extern Script N(80243790);
extern Script N(802437AC);
extern Script N(802439B0);
extern Script N(80242048);
extern Script N(80241F10);
extern Script N(main);
extern Script N(makeEntities);

enum {
    NPC_TUBBAS_HEART,
    NPC_WORLD_TUBBA,
    NPC_BOO0,
    NPC_BOO1,
    NPC_BOO2,
    NPC_BOO3,
    NPC_BOO4,
    NPC_BOO5,
    NPC_WORLD_BOW,
    NPC_BOOTLER,
    NPC_PARAGOOMBA0,
    NPC_PARAGOOMBA1,
    NPC_PARAGOOMBA2,
    NPC_WORLD_SKOLAR,
};
