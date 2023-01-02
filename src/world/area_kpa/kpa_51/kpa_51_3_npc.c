
#include "kpa_51.h"

#include "world/common/enemy/complete/Magikoopa.inc.c"
#include "world/common/enemy/complete/Koopatrol_Wander.inc.c"

StaticNpc N(NpcData_Magikoopa_01)[] = {
    {
        .id = NPC_Magikoopa_01,
        .settings = &N(NpcSettings_Magikoopa),
        .pos = { -130.0f, 0.0f, -30.0f },
        .yaw = 90,
        .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_SUPER_SHROOM, 5, 0 },
                { ITEM_MAPLE_SYRUP, 5, 0 },
                { ITEM_THUNDER_RAGE, 5, 0 },
                { ITEM_STOP_WATCH, 5, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(5),
            .minCoinBonus = 1,
            .maxCoinBonus = 3,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { -130, 0, -30 },
                .wanderSize = { 100, 20 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -130, 0, -30 },
                .detectSize = { 200 },
            }
        },
        .animations = {
            .idle   = ANIM_Magikoopa_Anim01,
            .walk   = ANIM_Magikoopa_Anim01,
            .run    = ANIM_Magikoopa_Anim01,
            .chase  = ANIM_Magikoopa_Anim01,
            .anim_4 = ANIM_Magikoopa_Anim01,
            .anim_5 = ANIM_Magikoopa_Anim01,
            .death  = ANIM_Magikoopa_Anim04,
            .hit    = ANIM_Magikoopa_Anim04,
            .anim_8 = ANIM_Magikoopa_Anim02,
            .anim_9 = ANIM_Magikoopa_Anim03,
            .anim_A = ANIM_Magikoopa_Anim01,
            .anim_B = ANIM_Magikoopa_Anim01,
            .anim_C = ANIM_Magikoopa_Anim01,
            .anim_D = ANIM_Magikoopa_Anim01,
            .anim_E = ANIM_Magikoopa_Anim01,
            .anim_F = ANIM_Magikoopa_Anim01,
        },
        .extraAnimations = N(ExtraAnims_Magikoopa),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    MAGIKOOPA_SPELL_HITBOX(NPC_Magikoopa_01 + 1)
};

StaticNpc N(NpcData_Magikoopa_02)[] = {
    {
        .id = NPC_Magikoopa_02,
        .settings = &N(NpcSettings_Magikoopa),
        .pos = { 150.0f, 0.0f, -30.0f },
        .yaw = 270,
        .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_SUPER_SHROOM, 5, 0 },
                { ITEM_MAPLE_SYRUP, 5, 0 },
                { ITEM_THUNDER_RAGE, 5, 0 },
                { ITEM_STOP_WATCH, 5, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(5),
            .minCoinBonus = 1,
            .maxCoinBonus = 3,
        },
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 150, 0, -30 },
                .wanderSize = { 100, 20 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 150, 0, -30 },
                .detectSize = { 200 },
            }
        },
        .animations = {
            .idle   = ANIM_Magikoopa_Anim01,
            .walk   = ANIM_Magikoopa_Anim01,
            .run    = ANIM_Magikoopa_Anim01,
            .chase  = ANIM_Magikoopa_Anim01,
            .anim_4 = ANIM_Magikoopa_Anim01,
            .anim_5 = ANIM_Magikoopa_Anim01,
            .death  = ANIM_Magikoopa_Anim04,
            .hit    = ANIM_Magikoopa_Anim04,
            .anim_8 = ANIM_Magikoopa_Anim02,
            .anim_9 = ANIM_Magikoopa_Anim03,
            .anim_A = ANIM_Magikoopa_Anim01,
            .anim_B = ANIM_Magikoopa_Anim01,
            .anim_C = ANIM_Magikoopa_Anim01,
            .anim_D = ANIM_Magikoopa_Anim01,
            .anim_E = ANIM_Magikoopa_Anim01,
            .anim_F = ANIM_Magikoopa_Anim01,
        },
        .extraAnimations = N(ExtraAnims_Magikoopa),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    MAGIKOOPA_SPELL_HITBOX(NPC_Magikoopa_02 + 1)
};

StaticNpc N(NpcData_Koopatrol) = {
    .id = NPC_Koopatrol,
    .settings = &N(NpcSettings_Koopatrol_Wander),
    .pos = { 0.0f, 0.0f, -30.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_SUPER_SHROOM, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(5),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 0,
        .maxCoinBonus = 3,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 0, 0, -30 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, -30 },
            .detectSize = { 300 },
        }
    },
    .animations = {
        .idle   = ANIM_WorldKoopatrol_Anim01,
        .walk   = ANIM_WorldKoopatrol_Anim04,
        .run    = ANIM_WorldKoopatrol_Anim06,
        .chase  = ANIM_WorldKoopatrol_Anim06,
        .anim_4 = ANIM_WorldKoopatrol_Anim01,
        .anim_5 = ANIM_WorldKoopatrol_Anim01,
        .death  = ANIM_WorldKoopatrol_Anim10,
        .hit    = ANIM_WorldKoopatrol_Anim10,
        .anim_8 = ANIM_WorldKoopatrol_Anim0C,
        .anim_9 = ANIM_WorldKoopatrol_Anim0B,
        .anim_A = ANIM_WorldKoopatrol_Anim0D,
        .anim_B = ANIM_WorldKoopatrol_Anim01,
        .anim_C = ANIM_WorldKoopatrol_Anim01,
        .anim_D = ANIM_WorldKoopatrol_Anim01,
        .anim_E = ANIM_WorldKoopatrol_Anim01,
        .anim_F = ANIM_WorldKoopatrol_Anim01,
    },
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Magikoopa_01), BTL_KPA_FORMATION_2C, BTL_KPA_STAGE_00),
    NPC_GROUP(N(NpcData_Magikoopa_02), BTL_KPA_FORMATION_29, BTL_KPA_STAGE_00),
    NPC_GROUP(N(NpcData_Koopatrol), BTL_KPA_FORMATION_24, BTL_KPA_STAGE_00),
    {}
};
