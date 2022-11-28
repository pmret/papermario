#include "tik_05.h"

#include "world/common/enemy/complete/SpikedGloomba_Wander.inc.c"

StaticNpc N(NpcData_SpikedGloomba_01) = {
    .id = NPC_SpikedGoomba_01,
    .settings = &N(NpcSettings_SpikedGloomba_Wander),
    .pos = { 220.0f, -10.0f, -80.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
    .drops = SPIKED_GLOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 220, -10, -80 },
            .wanderSize = { 20 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 160, 0, -20 },
            .detectSize = { 180, 100 },
        }
    },
    .animations = SPIKED_GLOOMBA_ANIMS,
};

StaticNpc N(NpcData_SpikedGloomba_02) = {
    .id = NPC_SpikedGoomba_02,
    .settings = &N(NpcSettings_SpikedGloomba_Wander),
    .pos = { 130.0f, -10.0f, 45.0f },
    .yaw = 90,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
    .drops = SPIKED_GLOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 130, -10, 45 },
            .wanderSize = { 20 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 160, 0, -20 },
            .detectSize = { 180, 100 },
        }
    },
    .animations = SPIKED_GLOOMBA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_SpikedGloomba_01), BTL_TIK_FORMATION_10, BTL_TIK_STAGE_00),
    NPC_GROUP(N(NpcData_SpikedGloomba_02), BTL_TIK_FORMATION_12, BTL_TIK_STAGE_00),
    {}
};
