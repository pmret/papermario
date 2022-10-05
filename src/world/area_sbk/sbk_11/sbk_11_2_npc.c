#include "sbk_11.h"

#include "world/common/enemy/complete/Bandit.inc.c"
#include "world/common/enemy/complete/Pokey.inc.c"

StaticNpc N(NpcData_Pokey) = {
    .id = NPC_Pokey,
    .settings = &N(NpcSettings_Pokey),
    .pos = { -120.0f, 0.0f, 90.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 15,
        .itemDrops = {
            { ITEM_DRIED_FRUIT, 9, 0 },
            { ITEM_TASTY_TONIC, 1, 0 },
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
            .centerPos  = { -120, 0, 90 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 1000 },
        }
    },
    .animations = {
        .idle   = ANIM_Pokey_Anim04,
        .walk   = ANIM_Pokey_Anim08,
        .run    = ANIM_Pokey_Anim08,
        .chase  = ANIM_Pokey_Anim08,
        .anim_4 = ANIM_Pokey_Anim04,
        .anim_5 = ANIM_Pokey_Anim04,
        .death  = ANIM_Pokey_Anim0C,
        .hit    = ANIM_Pokey_Anim0C,
        .anim_8 = ANIM_Pokey_Anim08,
        .anim_9 = ANIM_Pokey_Anim08,
        .anim_A = ANIM_Pokey_Anim08,
        .anim_B = ANIM_Pokey_Anim08,
        .anim_C = ANIM_Pokey_Anim08,
        .anim_D = ANIM_Pokey_Anim08,
        .anim_E = ANIM_Pokey_Anim08,
        .anim_F = ANIM_Pokey_Anim08,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Bandit) = {
    .id = NPC_Bandit,
    .settings = &N(NpcSettings_Bandit),
    .pos = { -200.0f, 0.0f, 230.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_HONEY_SYRUP, 10, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 3,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -200, 0, 230 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 0, 0, 0 },
            .detectSize = { 1000 },
        }
    },
    .animations = {
        .idle   = ANIM_Bandit_Anim01,
        .walk   = ANIM_Bandit_Anim05,
        .run    = ANIM_Bandit_Anim07,
        .chase  = ANIM_Bandit_Anim07,
        .anim_4 = ANIM_Bandit_Anim01,
        .anim_5 = ANIM_Bandit_Anim01,
        .death  = ANIM_Bandit_Anim09,
        .hit    = ANIM_Bandit_Anim09,
        .anim_8 = ANIM_Bandit_Anim00,
        .anim_9 = ANIM_Bandit_Anim00,
        .anim_A = ANIM_Bandit_Anim00,
        .anim_B = ANIM_Bandit_Anim00,
        .anim_C = ANIM_Bandit_Anim00,
        .anim_D = ANIM_Bandit_Anim00,
        .anim_E = ANIM_Bandit_Anim00,
        .anim_F = ANIM_Bandit_Anim00,
    },
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Pokey), BTL_SBK_FORMATION_04, BTL_SBK_STAGE_00),
    NPC_GROUP(N(NpcData_Bandit), BTL_SBK_FORMATION_0D, BTL_SBK_STAGE_00),
    {}
};
