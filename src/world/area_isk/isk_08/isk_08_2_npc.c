#include "isk_08.h"

#include "world/common/enemy/complete/SpikeTop.inc.c"

StaticNpc N(NpcData_BuzzyBeetle) = {
    .id = NPC_BuzzyBeetle,
    .settings = &N(NpcSettings_BuzzyBeetle),
    .pos = { -415.0f, -520.0f, 355.0f },
    .yaw = 0,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .drops = ISK_BUZZY_BEETLE_DROPS,
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
    .animations = BUZZY_BEETLE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BuzzyBeetle), BTL_ISK_PART_1_FORMATION_0A, BTL_ISK_PART_1_STAGE_03),
    {}
};
