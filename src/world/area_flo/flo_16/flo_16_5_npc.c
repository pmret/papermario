#include "flo_16.h"
#include "entity.h"

#include "world/common/enemy/complete/TuffPuff.inc.c"

StaticNpc N(NpcData_TuffPuff_01) = {
    .id = NPC_TuffPuff_01,
    .settings = &N(NpcSettings_TuffPuff),
    .pos = { 440.0f, 145.0f, 15.0f },
    .yaw = 90,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .drops = TUFF_PUFF_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 440, 145, 15 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 485, 145, 55 },
            .detectSize = { 225, 95 },
        }
    },
    .animations = TUFF_PUFF_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_TuffPuff_02) = {
    .id = NPC_TuffPuff_02,
    .settings = &N(NpcSettings_TuffPuff),
    .pos = { 600.0f, 145.0f, 15.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .drops = TUFF_PUFF_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 600, 145, 15 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 485, 145, 55 },
            .detectSize = { 225, 95 },
        }
    },
    .animations = TUFF_PUFF_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TuffPuff_01), BTL_FLO_FORMATION_24, BTL_FLO_STAGE_05),
    NPC_GROUP(N(NpcData_TuffPuff_02), BTL_FLO_FORMATION_20, BTL_FLO_STAGE_05),
    {}
};
