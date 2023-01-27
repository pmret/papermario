#include "pra_04.h"

#include "world/common/enemy/complete/Swooper.inc.c"

StaticNpc N(NpcData_Swoopula) = {
    .id = NPC_Swoopula,
    .settings = &N(NpcSettings_Swoopula),
    .pos = { 50.0f, 130.0f, 75.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_200000,
    .drops = SWOOPULA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 50, 130, 75 },
            .wanderSize = { 0 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 50, 130, 75 },
            .detectSize = { 200 },
        }
    },
    .animations = SWOOPULA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Swoopula), BTL_PRA3_FORMATION_00, BTL_PRA3_STAGE_00),
    {}
};
