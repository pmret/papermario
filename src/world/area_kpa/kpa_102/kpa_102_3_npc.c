#include "kpa_102.h"

#include "world/common/enemy/complete/HammerBros.inc.c"
#include "world/common/enemy/complete/Koopatrol_Wander.inc.c"
#include "world/common/enemy/complete/FlyingMagikoopa.inc.c"

StaticNpc N(NpcData_Koopatrol) = {
    .id = NPC_Koopatrol,
    .settings = &N(NpcSettings_Koopatrol_Wander),
    .pos = { -200.0f, 0.0f, -225.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .drops = KOOPATROL_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -200, 0, -225 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -200, 0, -225 },
            .detectSize = { 200 },
        }
    },
    .animations = KOOPATROL_ANIMS,
};

StaticNpc N(NpcData_FlyingMagikoopa)[] = {
    {
        .id = NPC_FlyingMagikoopa,
        .settings = &N(NpcSettings_FlyingMagikoopa),
        .pos = { 125.0f, 50.0f, -225.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_800,
        .drops = FLYING_MAGIKOOPA_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 125, 50, -225 },
                .wanderSize = { 120, 25 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 125, 50, -225 },
                .detectSize = { 200 },
            }
        },
        .animations = FLYING_MAGIKOOPA_ANIMS,
        .extraAnimations = N(ExtraAnims_FlyingMagikoopa),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    FLYING_MAGIKOOPA_SPELL_HITBOX(NPC_FlyingMagikoopa + 1),
};

StaticNpc N(NpcData_HammerBros)[] = {
    {
        .id = NPC_HammerBros,
        .settings = &N(NpcSettings_HammerBros),
        .pos = { 450.0f, 0.0f, -225.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .drops = HAMMER_BROS_DROPS,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 450, 0, -225 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 450, 0, -225 },
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
    NPC_GROUP(N(NpcData_Koopatrol), BTL_KPA_FORMATION_24, BTL_KPA_STAGE_0A),
    NPC_GROUP(N(NpcData_FlyingMagikoopa), BTL_KPA_FORMATION_32, BTL_KPA_STAGE_0A),
    NPC_GROUP(N(NpcData_HammerBros), BTL_KPA_FORMATION_16, BTL_KPA_STAGE_0A),
    {}
};
