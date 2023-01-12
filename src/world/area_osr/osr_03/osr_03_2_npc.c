#include "osr_03.h"

NpcSettings N(NpcSettings_Kammy) = {
    .height = 40,
    .radius = 30,
    .level = 26,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

s32 N(ExtraAnims_Kammy)[] = {
    ANIM_WorldKammy_Anim09,
    ANIM_WorldKammy_Anim0A,
    ANIM_WorldKammy_Anim0B,
    ANIM_WorldKammy_Anim0C,
    ANIM_WorldKammy_Anim0D,
    ANIM_WorldKammy_Anim0E,
    ANIM_WorldKammy_Anim0F,
    ANIM_WorldKammy_Anim10,
    ANIM_WorldKammy_Anim11,
    ANIM_WorldKammy_Anim12,
    ANIM_WorldKammy_Anim13,
    ANIM_WorldKammy_Anim14,
    ANIM_WorldKammy_Anim15,
    ANIM_WorldKammy_Anim16,
    ANIM_WorldKammy_Anim1A,
    -1
};

StaticNpc N(NpcData_Kammy) = {
    .id = NPC_Kammy,
    .settings = &N(NpcSettings_Kammy),
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 90,
    .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_WorldKammy_Anim01,
        .walk   = ANIM_WorldKammy_Anim02,
        .run    = ANIM_WorldKammy_Anim03,
        .chase  = ANIM_WorldKammy_Anim03,
        .anim_4 = ANIM_WorldKammy_Anim01,
        .anim_5 = ANIM_WorldKammy_Anim01,
        .death  = ANIM_WorldKammy_Anim00,
        .hit    = ANIM_WorldKammy_Anim00,
        .anim_8 = ANIM_WorldKammy_Anim03,
        .anim_9 = ANIM_WorldKammy_Anim03,
        .anim_A = ANIM_WorldKammy_Anim03,
        .anim_B = ANIM_WorldKammy_Anim03,
        .anim_C = ANIM_WorldKammy_Anim03,
        .anim_D = ANIM_WorldKammy_Anim03,
        .anim_E = ANIM_WorldKammy_Anim03,
        .anim_F = ANIM_WorldKammy_Anim03,
    },
    .extraAnimations = N(ExtraAnims_Kammy),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Kammy)),
    {}
};
