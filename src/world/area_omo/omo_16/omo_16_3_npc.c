#include "omo_16.h"

#include "world/common/npc/TrainToad.inc.c"

NpcData N(NpcData_TrainToad) = {
    .id = NPC_Conductor,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_400000,
    .settings = &N(NpcSettings_TrainToad),
    .drops = NO_DROPS,
    .animations = TRAIN_CONDUCTOR_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TrainToad)),
    {}
};
