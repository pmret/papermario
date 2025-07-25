#include "sbk_66.h"

#include "world/common/enemy/Bandit.inc.c"

NpcData N(NpcData_Bandit_01) = {
    .id = NPC_Bandit_01,
    .pos = { -120.0f, 0.0f, 45.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -120, 0, 45 },
            .wanderSize = { 80 },
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
    .pos = { -76.0f, 0.0f, -20.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -76, 0, -20 },
            .wanderSize = { 80 },
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

NpcData N(NpcData_Bandit_03) = {
    .id = NPC_Bandit_03,
    .pos = { -78.0f, 0.0f, 80.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -78, 0, 80 },
            .wanderSize = { 80 },
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

NpcData N(NpcData_Bandit_04) = {
    .id = NPC_Bandit_04,
    .pos = { -20.0f, 0.0f, 40.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -20, 0, 40 },
            .wanderSize = { 80 },
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

NpcData N(NpcData_Bandit_05) = {
    .id = NPC_Bandit_05,
    .pos = { 45.0f, 0.0f, -30.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 45, 0, -30 },
            .wanderSize = { 80 },
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

NpcData N(NpcData_Bandit_06) = {
    .id = NPC_Bandit_06,
    .pos = { 40.0f, 0.0f, 150.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 40, 0, 150 },
            .wanderSize = { 80 },
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
    NPC_GROUP(N(NpcData_Bandit_01), BTL_SBK_FORMATION_09, BTL_SBK_STAGE_00),
    NPC_GROUP(N(NpcData_Bandit_02), BTL_SBK_FORMATION_0B, BTL_SBK_STAGE_00),
    NPC_GROUP(N(NpcData_Bandit_03), BTL_SBK_FORMATION_0C, BTL_SBK_STAGE_00),
    NPC_GROUP(N(NpcData_Bandit_04), BTL_SBK_FORMATION_0A, BTL_SBK_STAGE_00),
    NPC_GROUP(N(NpcData_Bandit_05), BTL_SBK_FORMATION_0A, BTL_SBK_STAGE_00),
    NPC_GROUP(N(NpcData_Bandit_06), BTL_SBK_FORMATION_0A, BTL_SBK_STAGE_00),
    {}
};
