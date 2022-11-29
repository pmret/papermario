#include "tik_12.h"

#include "world/common/enemy/complete/SpikeTop.inc.c"

StaticNpc N(NpcData_BuzzyBeetle) = {
    .id = NPC_BuzzyBeetle,
    .settings = &N(NpcSettings_BuzzyBeetle),
    .pos = { -6.0f, -135.0f, 75.0f },
    .yaw = 90,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
    .drops = BUZZY_BEETLE_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -6, -135, 75 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 60, -135, 5 },
            .detectSize = { 150 },
        }
    },
    .animations = BUZZY_BEETLE_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BuzzyBeetle), BTL_TIK_FORMATION_15, BTL_TIK_STAGE_01),
    {}
};
