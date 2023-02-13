#include "isk_18.h"

#include "world/common/enemy/SpikeTop.inc.c"

StaticNpc N(NpcData_BuzzyBeetle_01) = {
    .id = NPC_BuzzyBeetle_01,
    .settings = &N(NpcSettings_BuzzyBeetle_Ceiling),
    .pos = { -372.0f, -700.0f, 439.0f },
    .yaw = 0,
    .flags = ENEMY_FLAG_400,
    .initVarCount = 1,
    .initVar = { .value = BTL_ISK_PART_1_FORMATION_0E },
    .drops = ISK_BUZZY_BEETLE_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -372, -700, 439 },
            .wanderSize = { 40 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -372, -700, 439 },
            .detectSize = { 200 },
        }
    },
    .animations = BUZZY_BEETLE_ANIMS,
};

StaticNpc N(NpcData_BuzzyBeetle_02) = {
    .id = NPC_BuzzyBeetle_02,
    .settings = &N(NpcSettings_BuzzyBeetle_Ceiling),
    .pos = { -58.0f, -700.0f, 591.0f },
    .yaw = 0,
    .flags = ENEMY_FLAG_400,
    .initVarCount = 1,
    .initVar = { .value = BTL_ISK_PART_1_FORMATION_0B },
    .drops = ISK_BUZZY_BEETLE_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -58, -700, 591 },
            .wanderSize = { 40 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -58, -700, 591 },
            .detectSize = { 200 },
        }
    },
    .animations = BUZZY_BEETLE_ANIMS,
};

StaticNpc N(NpcData_BuzzyBeetle_03) = {
    .id = NPC_BuzzyBeetle_03,
    .settings = &N(NpcSettings_BuzzyBeetle),
    .pos = { 292.0f, -780.0f, 488.0f },
    .yaw = 0,
    .flags = ENEMY_FLAG_400,
    .drops = ISK_BUZZY_BEETLE_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 292, -780, 488 },
            .wanderSize = { 40 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 292, -780, 488 },
            .detectSize = { 200 },
        }
    },
    .animations = BUZZY_BEETLE_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BuzzyBeetle_01), BTL_ISK_PART_1_FORMATION_0F, BTL_ISK_PART_1_STAGE_08),
    NPC_GROUP(N(NpcData_BuzzyBeetle_02), BTL_ISK_PART_1_FORMATION_13, BTL_ISK_PART_1_STAGE_08),
    NPC_GROUP(N(NpcData_BuzzyBeetle_03), BTL_ISK_PART_1_FORMATION_0C, BTL_ISK_PART_1_STAGE_08),
    {}
};
