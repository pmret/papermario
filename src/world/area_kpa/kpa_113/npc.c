#include "kpa_113.h"

#include "world/common/enemy/SpikeTop.inc.c"

NpcData N(NpcData_BonyBeetle) = {
    .id = NPC_BonyBeetle,
    .pos = { 100.0f, 0.0f, 83.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 100, 0, 83 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 65, 0, 100 },
            .detectSize = { 260, 100 },
        }
    },
    .settings = &N(NpcSettings_BonyBeetle),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = BONY_BEETLE_DROPS,
    .animations = BONY_BEETLE_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BonyBeetle), BTL_KPA_FORMATION_06, BTL_KPA_STAGE_0C),
    {}
};
