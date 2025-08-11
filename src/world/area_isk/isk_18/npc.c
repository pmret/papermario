#include "isk_18.h"

#include "world/common/enemy/SpikeTop.inc.c"

NpcData N(NpcData_BuzzyBeetle_01) = {
    .id = NPC_BuzzyBeetle_01,
    .pos = { -372.0f, -700.0f, 439.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -372, -700, 439 },
            .wanderSize = { 40 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -372, -700, 439 },
            .detectSize = { 200 },
        }
    },
    .initVarCount = 1,
    .initVar = { .value = BTL_ISK_1_FORMATION_0E },
    .settings = &N(NpcSettings_BuzzyBeetle_Ceiling),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = ISK_BUZZY_BEETLE_DROPS,
    .animations = BUZZY_BEETLE_ANIMS,
};

NpcData N(NpcData_BuzzyBeetle_02) = {
    .id = NPC_BuzzyBeetle_02,
    .pos = { -58.0f, -700.0f, 591.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -58, -700, 591 },
            .wanderSize = { 40 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -58, -700, 591 },
            .detectSize = { 200 },
        }
    },
    .initVarCount = 1,
    .initVar = { .value = BTL_ISK_1_FORMATION_0B },
    .settings = &N(NpcSettings_BuzzyBeetle_Ceiling),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = ISK_BUZZY_BEETLE_DROPS,
    .animations = BUZZY_BEETLE_ANIMS,
};

NpcData N(NpcData_BuzzyBeetle_03) = {
    .id = NPC_BuzzyBeetle_03,
    .pos = { 292.0f, -780.0f, 488.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 292, -780, 488 },
            .wanderSize = { 40 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 292, -780, 488 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_BuzzyBeetle),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = ISK_BUZZY_BEETLE_DROPS,
    .animations = BUZZY_BEETLE_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BuzzyBeetle_01), BTL_ISK_1_FORMATION_0F, BTL_ISK_1_STAGE_08),
    NPC_GROUP(N(NpcData_BuzzyBeetle_02), BTL_ISK_1_FORMATION_13, BTL_ISK_1_STAGE_08),
    NPC_GROUP(N(NpcData_BuzzyBeetle_03), BTL_ISK_1_FORMATION_0C, BTL_ISK_1_STAGE_08),
    {}
};
