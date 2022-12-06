#include "isk_04.h"

#include "world/common/enemy/complete/SpikeTop.inc.c"

StaticNpc N(NpcData_BuzzyBeetle_01) = {
    .id = NPC_BuzzyBeetle_01,
    .settings = &N(NpcSettings_BuzzyBeetle),
    .pos = { 561.0f, 25.0f, 47.0f },
    .yaw = 355,
    .flags = ENEMY_FLAGS_400,
    .drops = ISK_BUZZY_BEETLE_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 561, 25, 47 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 606, 25, 94 },
            .detectSize = { 80 },
        }
    },
    .animations = BUZZY_BEETLE_ANIMS,
};

StaticNpc N(NpcData_BuzzyBeetle_02) = {
    .id = NPC_BuzzyBeetle_02,
    .settings = &N(NpcSettings_BuzzyBeetle),
    .pos = { 608.0f, -260.0f, -158.0f },
    .yaw = 175,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .drops = ISK_BUZZY_BEETLE_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 608, -260, -158 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 596, -260, -203 },
            .detectSize = { 80 },
        }
    },
    .animations = BUZZY_BEETLE_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BuzzyBeetle_01), BTL_ISK_PART_1_FORMATION_09, BTL_ISK_PART_1_STAGE_03),
    NPC_GROUP(N(NpcData_BuzzyBeetle_02), BTL_ISK_PART_1_FORMATION_09, BTL_ISK_PART_1_STAGE_03),
    {}
};
