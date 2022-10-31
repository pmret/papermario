#include "kmr_06.h"

#include "world/common/enemy/complete/SpikedGoomba_Wander.inc.c"
#include "world/common/enemy/complete/Paragoomba_Wander.inc.c"

StaticNpc N(NpcData_SpikedGoomba) = {
    .id = NPC_SpikedGoomba,
    .settings = &N(NpcSettings_SpikedGoomba_Wander),
    .pos = { 160.0f, 0.0f, 30.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
    .drops = SPIKED_GOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 160, 0, 30 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 160, 0, 30 },
            .detectSize = { 300 },
        }
    },
    .animations = SPIKED_GOOMBA_ANIMS,
};

StaticNpc N(NpcData_Paragoomba) = {
    .id = NPC_Paragoomba,
    .settings = &N(NpcSettings_Paragoomba_Wander),
    .pos = { 525.0f, 60.0f, 15.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .drops = PARAGOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 525, 60, 15 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 525, 60, 15 },
            .detectSize = { 300 },
        }
    },
    .animations = PARAGOOMBA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_SpikedGoomba), BTL_KMR_PART_1_FORMATION_0B, BTL_KMR_PART_1_STAGE_02),
    NPC_GROUP(N(NpcData_Paragoomba), BTL_KMR_PART_1_FORMATION_09, BTL_KMR_PART_1_STAGE_02),
    {}
};
