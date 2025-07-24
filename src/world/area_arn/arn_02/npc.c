#include "arn_02.h"

#include "world/common/enemy/HyperGoomba_Wander.inc.c"
#include "world/common/enemy/HyperCleft.inc.c"

NpcData N(NpcData_HyperCleft_01) = {
    .id = NPC_HyperCleft_01,
    .pos = { -196.0f, 130.0f, 104.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { -196, 130, 104 },
            .wanderSize = { 50, 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -196, 130, 104 },
            .detectSize = { 120 },
        }
    },
    .settings = &N(NpcSettings_HyperCleft),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = HYPER_CLEFT_DROPS,
    .animations = HYPER_CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_HyperCleft_02) = {
    .id = NPC_HyperCleft_02,
    .pos = { 641.0f, 268.0f, 202.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 641, 268, 202 },
            .wanderSize = { 50, 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 641, 268, 202 },
            .detectSize = { 120 },
        }
    },
    .settings = &N(NpcSettings_HyperCleft),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = HYPER_CLEFT_DROPS,
    .animations = HYPER_CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_HyperGoomba) = {
    .id = NPC_HyperGoomba,
    .pos = { 333.0f, 215.0f, 85.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = false,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 333, 215, 85 },
            .wanderSize = { 40, 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 360, 215, 150 },
            .detectSize = { 120, 137 },
        }
    },
    .settings = &N(NpcSettings_HyperGoomba),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = HYPER_GOOMBA_DROPS,
    .animations = HYPER_GOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_HyperCleft_01), BTL_ARN_FORMATION_0A, BTL_ARN_STAGE_00),
    NPC_GROUP(N(NpcData_HyperCleft_02), BTL_ARN_FORMATION_0D, BTL_ARN_STAGE_00),
    NPC_GROUP(N(NpcData_HyperGoomba), BTL_ARN_FORMATION_03, BTL_ARN_STAGE_00),
    {}
};
