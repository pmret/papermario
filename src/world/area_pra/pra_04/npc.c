#include "pra_04.h"

#include "world/common/enemy/Swooper.inc.c"

NpcData N(NpcData_Swoopula) = {
    .id = NPC_Swoopula,
    .pos = { 50.0f, 130.0f, 75.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 50, 130, 75 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 50, 130, 75 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_Swoopula),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .drops = SWOOPULA_DROPS,
    .animations = SWOOPULA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Swoopula), BTL_PRA3_FORMATION_00, BTL_PRA3_STAGE_00),
    {}
};
