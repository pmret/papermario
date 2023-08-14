#include "pra_10.h"

#include "world/common/enemy/Swooper.inc.c"

EvtScript N(EVS_NpcInit_Swoopula) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_REFLECT_FLOOR, TRUE)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_Swoopula_01) = {
    .id = NPC_Swoopula_01,
    .pos = { 166.0f, 130.0f, 90.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 166, 130, 90 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 166, 130, 90 },
            .detectSize = { 250 },
        }
    },
    .init = &N(EVS_NpcInit_Swoopula),
    .settings = &N(NpcSettings_Swoopula),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = SWOOPULA_DROPS,
    .animations = SWOOPULA_ANIMS,
};

NpcData N(NpcData_Swoopula_02) = {
    .id = NPC_Swoopula_02,
    .pos = { 358.0f, 130.0f, 75.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 358, 130, 75 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 358, 130, 75 },
            .detectSize = { 250 },
        }
    },
    .init = &N(EVS_NpcInit_Swoopula),
    .settings = &N(NpcSettings_Swoopula),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = SWOOPULA_DROPS,
    .animations = SWOOPULA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Swoopula_01), BTL_PRA_FORMATION_01, BTL_PRA_STAGE_00),
    NPC_GROUP(N(NpcData_Swoopula_02), BTL_PRA_FORMATION_03, BTL_PRA_STAGE_00),
    {}
};
