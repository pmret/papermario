#include "kmr_06.h"

#include "world/common/enemy/SpikedGoomba_Wander.inc.c"
#include "world/common/enemy/Paragoomba_Wander.inc.c"

NpcData N(NpcData_SpikedGoomba) = {
    .id = NPC_SpikedGoomba,
    .pos = { 160.0f, 0.0f, 30.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 160, 0, 30 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 160, 0, 30 },
            .detectSize = { 300 },
        }
    },
    .settings = &N(NpcSettings_SpikedGoomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = SPIKED_GOOMBA_DROPS,
    .animations = SPIKED_GOOMBA_ANIMS,
};

NpcData N(NpcData_Paragoomba) = {
    .id = NPC_Paragoomba,
    .pos = { 525.0f, 60.0f, 15.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 525, 60, 15 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 525, 60, 15 },
            .detectSize = { 300 },
        }
    },
    .settings = &N(NpcSettings_Paragoomba_Wander),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = PARAGOOMBA_DROPS,
    .animations = PARAGOOMBA_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_SpikedGoomba), BTL_KMR_1_FORMATION_0B, BTL_KMR_1_STAGE_02),
    NPC_GROUP(N(NpcData_Paragoomba), BTL_KMR_1_FORMATION_09, BTL_KMR_1_STAGE_02),
    {}
};
