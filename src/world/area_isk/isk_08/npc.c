#include "isk_08.h"

#include "world/common/enemy/SpikeTop.inc.c"

NpcData N(NpcData_BuzzyBeetle) = {
    .id = NPC_BuzzyBeetle,
    .pos = { -415.0f, -520.0f, 355.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -432, -520, 390 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -450, -520, 386 },
            .detectSize = { 60 },
        }
    },
    .settings = &N(NpcSettings_BuzzyBeetle),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = ISK_BUZZY_BEETLE_DROPS,
    .animations = BUZZY_BEETLE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BuzzyBeetle), BTL_ISK_1_FORMATION_0A, BTL_ISK_1_STAGE_03),
    {}
};
