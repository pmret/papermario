#include "tik_24.h"

#include "world/common/enemy/DarkTroopa_Wander.inc.c"

NpcData N(NpcData_DarkTroopa_01) = {
    .id = NPC_DarkTroopa_01,
    .pos = { -75.0f, -10.0f, 50.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -75, -10, 50 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -75, -10, 50 },
            .detectSize = { 250 },
        }
    },
    .settings = &N(NpcSettings_DarkTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = DARK_TROOPA_DROPS,
    .animations = DARK_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_DarkTroopa_02) = {
    .id = NPC_DarkTroopa_02,
    .pos = { 175.0f, -10.0f, -50.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 175, -10, -50 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 175, -10, -50 },
            .detectSize = { 250 },
        }
    },
    .settings = &N(NpcSettings_DarkTroopa_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = DARK_TROOPA_DROPS,
    .animations = DARK_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_DarkTroopa_01), BTL_TIK_FORMATION_06, BTL_TIK_STAGE_00),
    NPC_GROUP(N(NpcData_DarkTroopa_02), BTL_TIK_FORMATION_07, BTL_TIK_STAGE_00),
    {}
};
