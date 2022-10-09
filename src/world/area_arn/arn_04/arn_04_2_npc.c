#include "arn_04.h"

#include "world/common/enemy/complete/HyperGoomba_Patrol.inc.c"
#include "world/common/enemy/complete/HyperParagoomba.inc.c"
#include "world/common/enemy/complete/HyperCleft.inc.c"

StaticNpc N(NpcData_HyperParagoomba) = {
    .id = NPC_HyperParagoomba,
    .settings = &N(NpcSettings_HyperParagoomba),
    .pos = { -350.0f, 180.0f, 150.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS,
    .drops = HYPER_PARAGOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -350, 180, 150 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -350, 180, 150 },
            .detectSize = { 150 },
        }
    },
    .animations = HYPER_PARAGOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_HyperGoomba) = {
    .id = NPC_HyperGoomba,
    .settings = &N(NpcSettings_HyperGoomba_Patrol),
    .pos = { 360.0f, 208.0f, 100.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS,
    .drops = HYPER_GOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 360, 208, 100 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 360, 208, 100 },
            .detectSize = { 150 },
        }
    },
    .animations = HYPER_GOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_HyperCleft_01) = {
    .id = NPC_HyperCleft_01,
    .settings = &N(NpcSettings_HyperCleft),
    .pos = { 150.0f, 177.0f, 160.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS,
    .drops = HYPER_CLEFT_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 150, 177, 160 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 150, 177, 160 },
            .detectSize = { 150 },
        }
    },
    .animations = HYPER_CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_HyperCleft_02) = {
    .id = NPC_HyperCleft_02,
    .settings = &N(NpcSettings_HyperCleft),
    .pos = { 550.0f, 230.0f, 125.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS,
    .drops = HYPER_CLEFT_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 550, 230, 125 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 550, 230, 125 },
            .detectSize = { 150 },
        }
    },
    .animations = HYPER_CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_HyperParagoomba), BTL_ARN_FORMATION_09, BTL_ARN_STAGE_00),
    NPC_GROUP(N(NpcData_HyperGoomba), BTL_ARN_FORMATION_03, BTL_ARN_STAGE_00),
    NPC_GROUP(N(NpcData_HyperCleft_01), BTL_ARN_FORMATION_0C, BTL_ARN_STAGE_00),
    NPC_GROUP(N(NpcData_HyperCleft_02), BTL_ARN_FORMATION_0E, BTL_ARN_STAGE_00),
    {}
};
