
#include "kpa_52.h"

#include "world/common/enemy/HammerBros_Wander.inc.c"

NpcData N(NpcData_HammerBros_01)[] = {
    {
        .id = NPC_HammerBros_01,
        .pos = { 190.0f, 0.0f, -27.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = false,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 190, 0, -27 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 190, 0, -27 },
                .detectSize = { 300 },
            }
        },
        .settings = &N(NpcSettings_HammerBros_Wander),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = HAMMER_BROS_DROPS,
        .animations = HAMMER_BROS_ANIMS,
    },
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros_01 + 1),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros_01 + 2),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros_01 + 3),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros_01 + 4),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros_01 + 5),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros_01 + 6),
};

NpcData N(NpcData_HammerBros_02)[] = {
    {
        .id = NPC_HammerBros_02,
        .pos = { 190.0f, 120.0f, -145.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = false,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 190, 120, -145 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 190, 120, -130 },
                .detectSize = { 140, 40 },
            }
        },
        .settings = &N(NpcSettings_HammerBros_Wander),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = HAMMER_BROS_DROPS,
        .animations = HAMMER_BROS_ANIMS,
    },
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros_02 + 1),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros_02 + 2),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros_02 + 3),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros_02 + 4),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros_02 + 5),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros_02 + 6),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_HammerBros_01), BTL_KPA_FORMATION_15, BTL_KPA_STAGE_00),
    NPC_GROUP(N(NpcData_HammerBros_02), BTL_KPA_FORMATION_13, BTL_KPA_STAGE_00),
    {}
};
