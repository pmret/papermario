#include "isk_08.h"

#include "world/common/enemy/SpikeTop.inc.c"

NpcData N(NpcData_BuzzyBeetle) = {
    .id = NPC_BuzzyBeetle,
    .pos = { -415.0f, -520.0f, 355.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -432, -520, 390 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -450, -520, 386 },
            .detectSize = { 60 },
        }
    },
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .settings = &N(NpcSettings_BuzzyBeetle),
    .drops = ISK_BUZZY_BEETLE_DROPS,
    .animations = BUZZY_BEETLE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BuzzyBeetle), BTL_ISK_PART_1_FORMATION_0A, BTL_ISK_PART_1_STAGE_03),
    {}
};
