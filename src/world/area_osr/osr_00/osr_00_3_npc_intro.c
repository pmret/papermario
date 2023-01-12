#include "osr_00.h"

#include "world/common/npc/Luigi.inc.c"

StaticNpc N(NpcData_Luigi) = {
    .id = NPC_Luigi,
    .settings = &N(NpcSettings_Luigi),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = LUIGI_DROPS,
    .animations = LUIGI_ANIMS,
};

NpcGroupList N(IntroNPCs) = {
    NPC_GROUP(N(NpcData_Luigi)),
    {}
};
