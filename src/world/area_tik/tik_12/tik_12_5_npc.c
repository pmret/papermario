#include "tik_12.h"

#include "world/common/enemy/SpikeTop.inc.c"

NpcData N(NpcData_BuzzyBeetle) = {
    .id = NPC_BuzzyBeetle,
    .pos = { -6.0f, -135.0f, 75.0f },
    .yaw = 90,
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
    .settings = &N(NpcSettings_BuzzyBeetle),
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = TIK_BUZZY_BEETLE_DROPS,
    .animations = BUZZY_BEETLE_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BuzzyBeetle), BTL_TIK_FORMATION_15, BTL_TIK_STAGE_01),
    {}
};
