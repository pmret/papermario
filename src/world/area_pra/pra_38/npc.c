#include "pra_38.h"

#include "world/common/enemy/Swooper.inc.c"

EvtScript N(EVS_NpcInit_Swoopula) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, true)
    Return
    End
};

NpcData N(NpcData_Swoopula_01) = {
    .id = NPC_Swoopula_01,
    .pos = { 175.0f, 130.0f, 75.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 175, 130, 75 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 175, 130, 75 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_Swoopula),
    .settings = &N(NpcSettings_Swoopula),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = SWOOPULA_DROPS,
    .animations = SWOOPULA_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Swoopula_02) = {
    .id = NPC_Swoopula_02,
    .pos = { 325.0f, 130.0f, 75.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 325, 130, 75 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 325, 130, 75 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_Swoopula),
    .settings = &N(NpcSettings_Swoopula),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = SWOOPULA_DROPS,
    .animations = SWOOPULA_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Swoopula_01), BTL_PRA_FORMATION_01, BTL_PRA_STAGE_00),
    NPC_GROUP(N(NpcData_Swoopula_02), BTL_PRA_FORMATION_02, BTL_PRA_STAGE_00),
    {}
};
