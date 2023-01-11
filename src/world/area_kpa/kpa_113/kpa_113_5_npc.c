#include "kpa_113.h"

#include "world/common/enemy/complete/SpikeTop.inc.c"

StaticNpc N(NpcData_BonyBeetle) = {
    .id = NPC_BonyBeetle,
    .settings = &N(NpcSettings_BonyBeetle),
    .pos = { 100.0f, 0.0f, 83.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = BONY_BEETLE_DROPS,
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
    .animations = BONY_BEETLE_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_BonyBeetle), BTL_KPA_FORMATION_06, BTL_KPA_STAGE_0C),
    {}
};
