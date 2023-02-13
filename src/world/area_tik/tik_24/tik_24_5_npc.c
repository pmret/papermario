#include "tik_24.h"

#include "world/common/enemy/DarkTroopa_Wander.inc.c"

StaticNpc N(NpcData_DarkTroopa_01) = {
    .id = NPC_DarkTroopa_01,
    .settings = &N(NpcSettings_DarkTroopa_Wander),
    .pos = { -75.0f, -10.0f, 50.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = DARK_TROOPA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -75, -10, 50 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -75, -10, 50 },
            .detectSize = { 250 },
        }
    },
    .animations = DARK_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_DarkTroopa_02) = {
    .id = NPC_DarkTroopa_02,
    .settings = &N(NpcSettings_DarkTroopa_Wander),
    .pos = { 175.0f, -10.0f, -50.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = DARK_TROOPA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 175, -10, -50 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 175, -10, -50 },
            .detectSize = { 250 },
        }
    },
    .animations = DARK_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_DarkTroopa_01), BTL_TIK_FORMATION_06, BTL_TIK_STAGE_00),
    NPC_GROUP(N(NpcData_DarkTroopa_02), BTL_TIK_FORMATION_07, BTL_TIK_STAGE_00),
    {}
};
