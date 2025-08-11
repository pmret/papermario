#include "flo_16.h"
#include "entity.h"

#include "world/common/enemy/RuffPuff.inc.c"

NpcData N(NpcData_RuffPuff_01) = {
    .id = NPC_RuffPuff_01,
    .pos = { 440.0f, 145.0f, 15.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 440, 145, 15 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 485, 145, 55 },
            .detectSize = { 225, 95 },
        }
    },
    .settings = &N(NpcSettings_RuffPuff),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = RUFF_PUFF_DROPS,
    .animations = RUFF_PUFF_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_RuffPuff_02) = {
    .id = NPC_RuffPuff_02,
    .pos = { 600.0f, 145.0f, 15.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 600, 145, 15 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 485, 145, 55 },
            .detectSize = { 225, 95 },
        }
    },
    .settings = &N(NpcSettings_RuffPuff),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = RUFF_PUFF_DROPS,
    .animations = RUFF_PUFF_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_RuffPuff_01), BTL_FLO_FORMATION_24, BTL_FLO_STAGE_05),
    NPC_GROUP(N(NpcData_RuffPuff_02), BTL_FLO_FORMATION_20, BTL_FLO_STAGE_05),
    {}
};
