#include "trd_02.h"

#include "world/common/enemy/complete/Bobomb_Wander.inc.c"
#include "world/common/enemy/complete/KoopaTroopa_Wander.inc.c"
#include "world/common/enemy/complete/KoopaTroopa_Patrol.inc.c"

StaticNpc N(NpcData_Bobomb_01) = {
    .id = NPC_Bobomb_01,
    .settings = &N(NpcSettings_Bobomb_Wander),
    .pos = { -70.0f, 0.0f, 80.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_HONEY_SYRUP, 5, 0 },
            { ITEM_FIRE_FLOWER, 5, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 0,
        .maxCoinBonus = 1,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -70, 0, 80 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 0, 0, 35 },
            .detectSize = { 250, 175 },
        }
    },
    .animations = {
        .idle   = ANIM_Bobomb_Anim02,
        .walk   = ANIM_Bobomb_Anim04,
        .run    = ANIM_Bobomb_Anim06,
        .chase  = ANIM_Bobomb_Anim06,
        .anim_4 = ANIM_Bobomb_Anim02,
        .anim_5 = ANIM_Bobomb_Anim02,
        .death  = ANIM_Bobomb_Anim0E,
        .hit    = ANIM_Bobomb_Anim0E,
        .anim_8 = ANIM_Bobomb_Anim06,
        .anim_9 = ANIM_Bobomb_Anim06,
        .anim_A = ANIM_Bobomb_Anim06,
        .anim_B = ANIM_Bobomb_Anim06,
        .anim_C = ANIM_Bobomb_Anim06,
        .anim_D = ANIM_Bobomb_Anim06,
        .anim_E = ANIM_Bobomb_Anim06,
        .anim_F = ANIM_Bobomb_Anim06,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Bobomb_02) = {
    .id = NPC_Bobomb_02,
    .settings = &N(NpcSettings_Bobomb_Wander),
    .pos = { 140.0f, 0.0f, 80.0f },
    .yaw = 270,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_HONEY_SYRUP, 5, 0 },
            { ITEM_FIRE_FLOWER, 5, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 0,
        .maxCoinBonus = 1,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 140, 0, 80 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 0, 0, 35 },
            .detectSize = { 250, 175 },
        }
    },
    .animations = {
        .idle   = ANIM_Bobomb_Anim02,
        .walk   = ANIM_Bobomb_Anim04,
        .run    = ANIM_Bobomb_Anim06,
        .chase  = ANIM_Bobomb_Anim06,
        .anim_4 = ANIM_Bobomb_Anim02,
        .anim_5 = ANIM_Bobomb_Anim02,
        .death  = ANIM_Bobomb_Anim0E,
        .hit    = ANIM_Bobomb_Anim0E,
        .anim_8 = ANIM_Bobomb_Anim06,
        .anim_9 = ANIM_Bobomb_Anim06,
        .anim_A = ANIM_Bobomb_Anim06,
        .anim_B = ANIM_Bobomb_Anim06,
        .anim_C = ANIM_Bobomb_Anim06,
        .anim_D = ANIM_Bobomb_Anim06,
        .anim_E = ANIM_Bobomb_Anim06,
        .anim_F = ANIM_Bobomb_Anim06,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_KoopaTroopa) = {
    .id = NPC_KoopaTroopa,
    .settings = &N(NpcSettings_KoopaTroopa_Patrol),
    .pos = { 50.0f, 187.0f, 183.0f },
    .yaw = 0,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_MUSHROOM, 5, 0 },
            { ITEM_P_O_W_BLOCK, 5, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 1,
    },
    .territory = {
        .patrol = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .numPoints  = 2,
            .points  = {
                { 70, 187, 183 },
                { -20, 187, 183 },
            },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 20, 187, 207 },
            .detectSize = { 150, 80 },
        }
    },
    .animations = {
        .idle   = ANIM_KoopaTroopa_Anim01,
        .walk   = ANIM_KoopaTroopa_Anim03,
        .run    = ANIM_KoopaTroopa_Anim04,
        .chase  = ANIM_KoopaTroopa_Anim04,
        .anim_4 = ANIM_KoopaTroopa_Anim01,
        .anim_5 = ANIM_KoopaTroopa_Anim01,
        .death  = ANIM_KoopaTroopa_Anim0B,
        .hit    = ANIM_KoopaTroopa_Anim0B,
        .anim_8 = ANIM_KoopaTroopa_Anim07,
        .anim_9 = ANIM_KoopaTroopa_Anim06,
        .anim_A = ANIM_KoopaTroopa_Anim08,
        .anim_B = ANIM_KoopaTroopa_Anim04,
        .anim_C = ANIM_KoopaTroopa_Anim04,
        .anim_D = ANIM_KoopaTroopa_Anim04,
        .anim_E = ANIM_KoopaTroopa_Anim04,
        .anim_F = ANIM_KoopaTroopa_Anim04,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Bobomb_01), BTL_TRD_PART_1_FORMATION_10, BTL_TRD_PART_1_STAGE_09),
    NPC_GROUP(N(NpcData_Bobomb_02), BTL_TRD_PART_1_FORMATION_10, BTL_TRD_PART_1_STAGE_09),
    NPC_GROUP(N(NpcData_KoopaTroopa), BTL_TRD_PART_1_FORMATION_07, BTL_TRD_PART_1_STAGE_0C),
    {}
};
