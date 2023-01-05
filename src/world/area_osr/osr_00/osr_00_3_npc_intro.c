#include "osr_00.h"

#include "world/common/npc/Luigi.inc.c"

StaticNpc N(NpcData_Luigi) = {
    .id = NPC_Luigi,
    .settings = &N(NpcSettings_Luigi),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = ENEMY_FLAGS_1 | ENEMY_FLAGS_4 | ENEMY_FLAGS_8 | ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .drops = LUIGI_DROPS,
    .animations = LUIGI_ANIMS,
};

NpcGroupList N(IntroNPCs) = {
    NPC_GROUP(N(NpcData_Luigi)),
    {}
};
