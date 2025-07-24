#include "tik_23.h"

#include "world/common/enemy/Spiny.inc.c"

NpcData N(NpcData_Spiny_01) = {
    .id = NPC_Spiny_01,
    .pos = { 25.0f, -20.0f, 0.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 25, -20, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 25, -20, 0 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_Spiny),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_02) = {
    .id = NPC_Spiny_02,
    .pos = { 275.0f, -20.0f, 120.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 275, -20, 120 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 275, -20, 120 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_Spiny),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Spiny_03) = {
    .id = NPC_Spiny_03,
    .pos = { -150.0f, -20.0f, 120.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -150, -20, 120 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -150, -20, 120 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_Spiny),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Spiny_01), BTL_TIK_FORMATION_16, BTL_TIK_STAGE_03),
    NPC_GROUP(N(NpcData_Spiny_02), BTL_TIK_FORMATION_17, BTL_TIK_STAGE_03),
    NPC_GROUP(N(NpcData_Spiny_03), BTL_TIK_FORMATION_16, BTL_TIK_STAGE_03),
    {}
};
