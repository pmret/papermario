#include "omo_16.h"

#include "world/common/npc/TrainConductorToad.inc.c"

StaticNpc N(NpcData_TrainStationToad) = {
    .id = NPC_Conductor,
    .settings = &N(NpcSettings_TrainConductorToad),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
    .drops = NPC_NO_DROPS,
    .animations = TRAIN_CONDUCTOR_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TrainStationToad)),
    {}
};
