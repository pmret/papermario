#include "tik_07.h"

#include "world/common/enemy/Paragloomba_Wander.inc.c"

NpcData N(NpcData_Paragloomba_01) = {
    .id = NPC_Paragoomba_01,
    .pos = { 230.0f, 50.0f, 50.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 230, 50, 50 },
            .wanderSize = { 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 230, 50, 50 },
            .detectSize = { 150 },
        }
    },
    .settings = &N(NpcSettings_Paragloomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = PARAGLOOMBA_DROPS,
    .animations = PARAGLOOMBA_ANIMS,
};

NpcData N(NpcData_Paragloomba_02) = {
    .id = NPC_Paragoomba_02,
    .pos = { 535.0f, 50.0f, 20.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 535, 50, 20 },
            .wanderSize = { 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 535, 50, 20 },
            .detectSize = { 150 },
        }
    },
    .settings = &N(NpcSettings_Paragloomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = PARAGLOOMBA_DROPS,
    .animations = PARAGLOOMBA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Paragloomba_01), BTL_TIK_FORMATION_0C, BTL_TIK_STAGE_01),
    NPC_GROUP(N(NpcData_Paragloomba_02), BTL_TIK_FORMATION_0D, BTL_TIK_STAGE_01),
    {}
};
