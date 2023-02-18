#include "flo_16.h"
#include "entity.h"

#include "world/common/enemy/TuffPuff.inc.c"

NpcData N(NpcData_TuffPuff_01) = {
    .id = NPC_TuffPuff_01,
    .pos = { 440.0f, 145.0f, 15.0f },
    .yaw = 90,
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
    .settings = &N(NpcSettings_TuffPuff),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
    .drops = TUFF_PUFF_DROPS,
    .animations = TUFF_PUFF_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_TuffPuff_02) = {
    .id = NPC_TuffPuff_02,
    .pos = { 600.0f, 145.0f, 15.0f },
    .yaw = 270,
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
    .settings = &N(NpcSettings_TuffPuff),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
    .drops = TUFF_PUFF_DROPS,
    .animations = TUFF_PUFF_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_TuffPuff_01), 0x1A24, BTL_FLO_STAGE_05),
    NPC_GROUP(N(NpcData_TuffPuff_02), 0x1A20, BTL_FLO_STAGE_05),
    {}
};
