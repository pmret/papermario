#include "kpa_115.h"

#include "world/common/enemy/HammerBros_Wander.inc.c"

StaticNpc N(NpcData_HammerBros)[] = {
    {
        .id = NPC_HammerBros,
        .settings = &N(NpcSettings_HammerBros_Wander),
        .pos = { 100.0f, 0.0f, 120.0f },
        .yaw = 90,
        .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .drops = HAMMER_BROS_DROPS,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 100, 0, 120 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 100, 0, 120 },
                .detectSize = { 200 },
            }
        },
        .animations = HAMMER_BROS_ANIMS,
    },
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros + 1),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros + 2),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros + 3),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros + 4),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros + 5),
    HAMMER_BROS_HAMMER_HITBOX(NPC_HammerBros + 6),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_HammerBros), BTL_KPA_FORMATION_14, BTL_KPA_STAGE_0C),
    {}
};
