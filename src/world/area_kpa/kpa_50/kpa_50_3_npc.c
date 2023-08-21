#include "kpa_50.h"

#include "world/common/enemy/HammerBros_Wander.inc.c"
#include "world/common/enemy/Koopatrol_Wander.inc.c"

NpcData N(NpcData_Koopatrol_01) = {
    .id = NPC_Koopatrol_01,
    .pos = { -251.0f, 0.0f, -30.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -251, 0, -30 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -251, 0, -30 },
            .detectSize = { 300 },
        }
    },
    .settings = &N(NpcSettings_Koopatrol_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = KOOPATROL_DROPS,
    .animations = KOOPATROL_ANIMS,
};

NpcData N(NpcData_Koopatrol_02) = {
    .id = NPC_Koopatrol_02,
    .pos = { 100.0f, 0.0f, -30.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 100, 0, -30 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 100, 0, -30 },
            .detectSize = { 300 },
        }
    },
    .settings = &N(NpcSettings_Koopatrol_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = KOOPATROL_DROPS,
    .animations = KOOPATROL_ANIMS,
};

NpcData N(NpcData_HammerBros_01)[] = {
    {
        .id = NPC_HammerBros,
        .pos = { 450.0f, 0.0f, -30.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 450, 0, -30 },
                .wanderSize = { 50 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 450, 0, -30 },
                .detectSize = { 300 },
            }
        },
        .settings = &N(NpcSettings_HammerBros_Wander),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = HAMMER_BROS_DROPS,
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
    NPC_GROUP(N(NpcData_Koopatrol_01), BTL_KPA_FORMATION_18, BTL_KPA_STAGE_00),
    NPC_GROUP(N(NpcData_Koopatrol_02), BTL_KPA_FORMATION_1A, BTL_KPA_STAGE_00),
    NPC_GROUP(N(NpcData_HammerBros_01), BTL_KPA_FORMATION_0F, BTL_KPA_STAGE_00),
    {}
};
