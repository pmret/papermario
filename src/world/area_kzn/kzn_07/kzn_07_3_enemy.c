#include "kzn_07.h"
#include "effects.h"
#include "sprite/npc/LavaBubble.h"

#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/enemy/FlyingNoAttackAI.inc.c"

f32 N(FlyingAI_JumpVels)[] = {
    4.5, 3.5, 2.6, 2.0, 1.5, 20.0, 
};

MobileAISettings N(D_80242BA8_C70ED8) = {
    .moveSpeed = 0.8f,
    .moveTime = 100,
    .alertRadius = 90.0f,
    .playerSearchInterval = 4,
    .chaseSpeed = 3.2f,
    .chaseTurnRate = 10,
    .chaseUpdateInterval = 1,
    .chaseRadius = 100.0f,
    .unk_AI_2C = 1,
};

EvtScript N(D_80242BD8_C70F08) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, 0)
    EVT_CALL(SetSelfVar, 6, 0)
    EVT_CALL(SetSelfVar, 1, 150)
    EVT_CALL(N(FlyingNoAttackAI_Main), EVT_PTR(N(D_80242BA8_C70ED8)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(D_80242C48_C70F78) = {
    .height = 20,
    .radius = 22,
    .level = 17,
    .ai = &N(D_80242BD8_C70F08),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

StaticNpc N(D_80242C74_C70FA4) = {
    .id = NPC_Bubble_01,
    .settings = &N(D_80242C48_C70F78),
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

StaticNpc N(D_80242E64_C71194) = {
    .id = NPC_Bubble_02,
    .settings = &N(D_80242C48_C70F78),
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
    NPC_GROUP(N(D_80242C74_C70FA4), BTL_KZN_FORMATION_05, BTL_KZN_STAGE_01),
    NPC_GROUP(N(D_80242E64_C71194), BTL_KZN_FORMATION_06, BTL_KZN_STAGE_01),
    {}
};
