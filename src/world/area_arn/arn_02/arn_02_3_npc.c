#include "arn_02.h"

#include "world/common/enemy/complete/HyperGoomba_Wander.inc.c"
#include "world/common/enemy/complete/HyperCleft.inc.c"

StaticNpc N(NpcData_Cleft_01) = {
    .id = NPC_Cleft_01,
    .settings = &N(NpcSettings_Cleft),
    .pos = { -196.0f, 130.0f, 104.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS,
    .drops = HYPER_CLEFT_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { -196, 130, 104 },
            .wanderSize = { 50, 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -196, 130, 104 },
            .detectSize = { 120 },
        }
    },
    .animations = HYPER_CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Cleft_02) = {
    .id = NPC_Cleft_02,
    .settings = &N(NpcSettings_Cleft),
    .pos = { 641.0f, 268.0f, 202.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS,
    .drops = HYPER_CLEFT_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 641, 268, 202 },
            .wanderSize = { 50, 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 641, 268, 202 },
            .detectSize = { 120 },
        }
    },
    .animations = HYPER_CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Goomba) = {
    .id = NPC_Goomba,
    .settings = &N(NpcSettings_Goomba),
    .pos = { 333.0f, 215.0f, 85.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS,
    .drops = HYPER_GOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 333, 215, 85 },
            .wanderSize = { 40, 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 360, 215, 150 },
            .detectSize = { 120, 137 },
        }
    },
    .animations = HYPER_GOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Cleft_01), BTL_ARN_FORMATION_0A, BTL_ARN_STAGE_00),
    NPC_GROUP(N(NpcData_Cleft_02), BTL_ARN_FORMATION_0D, BTL_ARN_STAGE_00),
    NPC_GROUP(N(NpcData_Goomba), BTL_ARN_FORMATION_03, BTL_ARN_STAGE_00),
    {}
};
