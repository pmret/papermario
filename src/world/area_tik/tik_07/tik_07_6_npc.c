#include "tik_07.h"

#include "world/common/enemy/Paragloomba_Wander.inc.c"

StaticNpc N(NpcData_Paragloomba_01) = {
    .id = NPC_Paragoomba_01,
    .settings = &N(NpcSettings_Paragloomba_Wander),
    .pos = { 230.0f, 50.0f, 50.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = PARAGLOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 230, 50, 50 },
            .wanderSize = { 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 230, 50, 50 },
            .detectSize = { 150 },
        }
    },
    .animations = PARAGLOOMBA_ANIMS,
};

StaticNpc N(NpcData_Paragloomba_02) = {
    .id = NPC_Paragoomba_02,
    .settings = &N(NpcSettings_Paragloomba_Wander),
    .pos = { 535.0f, 50.0f, 20.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = PARAGLOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 535, 50, 20 },
            .wanderSize = { 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 535, 50, 20 },
            .detectSize = { 150 },
        }
    },
    .animations = PARAGLOOMBA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Paragloomba_01), BTL_TIK_FORMATION_0C, BTL_TIK_STAGE_01),
    NPC_GROUP(N(NpcData_Paragloomba_02), BTL_TIK_FORMATION_0D, BTL_TIK_STAGE_01),
    {}
};
