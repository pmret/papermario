#include "sbk_25.h"

#include "world/common/enemy/Bandit.inc.c"

NpcData N(NpcData_Bandit_01) = {
    .id = NPC_Bandit_01,
    .pos = { -80.0f, 0.0f, -20.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -80, 0, -20 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 1000 },
        }
    },
    .settings = &N(NpcSettings_Bandit),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = BANDIT_DROPS,
    .animations = BANDIT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Bandit_02) = {
    .id = NPC_Bandit_02,
    .pos = { 120.0f, 0.0f, 20.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 120, 0, 20 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 1000 },
        }
    },
    .settings = &N(NpcSettings_Bandit),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = BANDIT_DROPS,
    .animations = BANDIT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Bandit_01), BTL_SBK_FORMATION_0A, BTL_SBK_STAGE_00),
    NPC_GROUP(N(NpcData_Bandit_02), BTL_SBK_FORMATION_0A, BTL_SBK_STAGE_00),
    {}
};
