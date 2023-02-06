#include "kpa_134.h"

#include "world/common/npc/Toad_Stationary.inc.c"

EvtScript N(EVS_NpcInit_Toad) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_HAS_SHADOW, FALSE)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Dummy) = {
    .id = NPC_Dummy,
    .settings = &N(NpcSettings_Toad_Stationary),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_4000 | ENEMY_FLAG_200000,
    .init = &N(EVS_NpcInit_Toad),
    .drops = TOAD_DROPS,
    .animations = TOAD_RED_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Dummy)),
    {}
};
