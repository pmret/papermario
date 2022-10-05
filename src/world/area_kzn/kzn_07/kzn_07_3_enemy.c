#include "kzn_07.h"
#include "effects.h"

#include "world/common/enemy/complete/LavaBubble.inc.c"

StaticNpc N(NpcData_LavaBubble_01) = {
    .id = NPC_Bubble_01,
    .settings = &N(NpcSettings_LavaBubble),
    .pos = { -200.0f, 50.0f, 150.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_SUPER_SHROOM, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 0,
        .maxCoinBonus = 3,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -200, 50, 150 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -200, 50, 150 },
            .detectSize = { 300 },
        }
    },
    .animations = {
        .idle   = ANIM_LavaBubble_Anim01,
        .walk   = ANIM_LavaBubble_Anim02,
        .run    = ANIM_LavaBubble_Anim03,
        .chase  = ANIM_LavaBubble_Anim03,
        .anim_4 = ANIM_LavaBubble_Anim01,
        .anim_5 = ANIM_LavaBubble_Anim01,
        .death  = ANIM_LavaBubble_Anim07,
        .hit    = ANIM_LavaBubble_Anim07,
        .anim_8 = ANIM_LavaBubble_Anim04,
        .anim_9 = ANIM_LavaBubble_Anim01,
        .anim_A = ANIM_LavaBubble_Anim01,
        .anim_B = ANIM_LavaBubble_Anim01,
        .anim_C = ANIM_LavaBubble_Anim01,
        .anim_D = ANIM_LavaBubble_Anim01,
        .anim_E = ANIM_LavaBubble_Anim01,
        .anim_F = ANIM_LavaBubble_Anim01,
    },
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_LavaBubble_02) = {
    .id = NPC_Bubble_02,
    .settings = &N(NpcSettings_LavaBubble),
    .pos = { -250.0f, 80.0f, 50.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_SUPER_SHROOM, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 0,
        .maxCoinBonus = 3,
    },
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -250, 80, 50 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -250, 80, 50 },
            .detectSize = { 300 },
        }
    },
    .animations = {
        .idle   = ANIM_LavaBubble_Anim01,
        .walk   = ANIM_LavaBubble_Anim02,
        .run    = ANIM_LavaBubble_Anim03,
        .chase  = ANIM_LavaBubble_Anim03,
        .anim_4 = ANIM_LavaBubble_Anim01,
        .anim_5 = ANIM_LavaBubble_Anim01,
        .death  = ANIM_LavaBubble_Anim07,
        .hit    = ANIM_LavaBubble_Anim07,
        .anim_8 = ANIM_LavaBubble_Anim04,
        .anim_9 = ANIM_LavaBubble_Anim01,
        .anim_A = ANIM_LavaBubble_Anim01,
        .anim_B = ANIM_LavaBubble_Anim01,
        .anim_C = ANIM_LavaBubble_Anim01,
        .anim_D = ANIM_LavaBubble_Anim01,
        .anim_E = ANIM_LavaBubble_Anim01,
        .anim_F = ANIM_LavaBubble_Anim01,
    },
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_LavaBubble_01), BTL_KZN_FORMATION_05, BTL_KZN_STAGE_01),
    NPC_GROUP(N(NpcData_LavaBubble_02), BTL_KZN_FORMATION_06, BTL_KZN_STAGE_01),
    {}
};
