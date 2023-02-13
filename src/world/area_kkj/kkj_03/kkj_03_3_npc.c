#include "kkj_03.h"

#include "world/common/npc/Peach.inc.c"

NpcData N(NpcData_Peach) = {
    .id = NPC_Peach,
    .pos = { 670.0f, 0.0f, -12.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_Peach),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_20000,
    .drops = NO_DROPS,
    .animations = PEACH_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Peach)),
    {}
};
