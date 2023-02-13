#include "kpa_50.h"

#include "world/common/enemy/HammerBros_Wander.inc.c"
#include "world/common/enemy/Koopatrol_Wander.inc.c"

StaticNpc N(NpcData_Koopatrol_01) = {
    .id = NPC_Koopatrol_01,
    .settings = &N(NpcSettings_Koopatrol_Wander),
    .pos = { -251.0f, 0.0f, -30.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = KOOPATROL_DROPS,
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
    .animations = KOOPATROL_ANIMS,
};

StaticNpc N(NpcData_Koopatrol_02) = {
    .id = NPC_Koopatrol_02,
    .settings = &N(NpcSettings_Koopatrol_Wander),
    .pos = { 100.0f, 0.0f, -30.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = KOOPATROL_DROPS,
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
    .animations = KOOPATROL_ANIMS,
};

StaticNpc N(NpcData_HammerBros_01)[] = {
    {
        .id = NPC_HammerBros,
        .settings = &N(NpcSettings_HammerBros_Wander),
        .pos = { 450.0f, 0.0f, -30.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
        .drops = HAMMER_BROS_DROPS,
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
