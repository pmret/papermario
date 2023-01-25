#include "omo_11.h"

#include "world/common/enemy/complete/PyroGuy.inc.c"

StaticNpc N(NpcData_PyroGuy_01) = {
    .id = NPC_PyroGuy_01,
    .settings = &N(NpcSettings_PyroGuy),
    .pos = { -180.0f, 0.0f, 70.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = PYRO_GUY_DROPS,
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
    .animations = PYRO_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_PyroGuy_02) = {
    .id = NPC_PyroGuy_02,
    .settings = &N(NpcSettings_PyroGuy),
    .pos = { 330.0f, 0.0f, 83.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = PYRO_GUY_DROPS,
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
    .animations = PYRO_GUY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_PyroGuy_01), BTL_OMO_FORMATION_22, BTL_OMO_STAGE_07),
    NPC_GROUP(N(NpcData_PyroGuy_02), BTL_OMO_FORMATION_24, BTL_OMO_STAGE_07),
    {}
};
