#include "tik_20.h"

#include "world/common/enemy/DarkTroopa_Wander.inc.c"

NpcData N(NpcData_DarkTroopa_01) = {
    .id = NPC_DarkTroopa_01,
    .pos = { -50.0f, -20.0f, 100.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -50, -20, 100 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -50, -20, 100 },
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
    .pos = { 250.0f, -20.0f, 100.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 250, -20, 100 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 250, -20, 100 },
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
    NPC_GROUP(N(NpcData_DarkTroopa_01), BTL_TIK_FORMATION_04, BTL_TIK_STAGE_03),
    NPC_GROUP(N(NpcData_DarkTroopa_02), BTL_TIK_FORMATION_05, BTL_TIK_STAGE_03),
    {}
};
