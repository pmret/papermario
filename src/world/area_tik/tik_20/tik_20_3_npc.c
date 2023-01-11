#include "tik_20.h"

#include "world/common/enemy/complete/DarkTroopa_Wander.inc.c"

StaticNpc N(NpcData_DarkTroopa_01) = {
    .id = NPC_DarkTroopa_01,
    .settings = &N(NpcSettings_DarkTroopa_Wander),
    .pos = { -50.0f, -20.0f, 100.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = DARK_TROOPA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -50, -20, 100 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -50, -20, 100 },
            .detectSize = { 250 },
        }
    },
    .animations = DARK_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_DarkTroopa_02) = {
    .id = NPC_DarkTroopa_02,
    .settings = &N(NpcSettings_DarkTroopa_Wander),
    .pos = { 250.0f, -20.0f, 100.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = DARK_TROOPA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 250, -20, 100 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 250, -20, 100 },
            .detectSize = { 250 },
        }
    },
    .animations = DARK_TROOPA_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_DarkTroopa_01), BTL_TIK_FORMATION_04, BTL_TIK_STAGE_03),
    NPC_GROUP(N(NpcData_DarkTroopa_02), BTL_TIK_FORMATION_05, BTL_TIK_STAGE_03),
    {}
};
