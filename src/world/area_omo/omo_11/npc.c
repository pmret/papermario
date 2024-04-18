#include "omo_11.h"

#include "world/common/enemy/PyroGuy.inc.c"

NpcData N(NpcData_PyroGuy_01) = {
    .id = NPC_PyroGuy_01,
    .pos = { -180.0f, 0.0f, 70.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { -180, 0, 70 },
            .wanderSize = { 30, 10 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -180, 0, 70 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_PyroGuy),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = PYRO_GUY_DROPS,
    .animations = PYRO_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_PyroGuy_02) = {
    .id = NPC_PyroGuy_02,
    .pos = { 330.0f, 0.0f, 83.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 330, 0, 83 },
            .wanderSize = { 30, 10 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 330, 0, 83 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_PyroGuy),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = PYRO_GUY_DROPS,
    .animations = PYRO_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_PyroGuy_01), BTL_OMO_FORMATION_22, BTL_OMO_STAGE_07),
    NPC_GROUP(N(NpcData_PyroGuy_02), BTL_OMO_FORMATION_24, BTL_OMO_STAGE_07),
    {}
};
