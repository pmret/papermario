#include "kmr_06.h"

#include "world/common/enemy/ai/FlyingAI.inc.c"

MobileAISettings N(D_80242040_8D3550) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 130.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 2.5f,
    .chaseTurnRate = 180,
    .chaseUpdateInterval = 3,
    .chaseRadius = 150.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_SpikedGoomba) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(D_80242040_8D3550)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_SpikedGoomba) = {
    .height = 23,
    .radius = 23,
    .level = 6,
    .ai = &N(EVS_NpcAI_SpikedGoomba),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

f32 N(FlyingAI_JumpVels)[] = {
    4.5, 3.5, 2.6, 2.0, 1.5, 20.0, 
};

MobileAISettings N(AISettings_Paragoomba) = {
    .moveSpeed = 1.6f,
    .moveTime = 60,
    .waitTime = 30,
    .alertRadius = 80.0f,
    .playerSearchInterval = 5,
    .chaseSpeed = 2.2f,
    .chaseTurnRate = 60,
    .chaseUpdateInterval = 15,
    .chaseRadius = 100.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Paragoomba) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -500)
    EVT_CALL(SetSelfVar, 6, 21)
    EVT_CALL(SetSelfVar, 1, 580)
    EVT_CALL(N(FlyingAI_Main), EVT_PTR(N(AISettings_Paragoomba)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Paragoomba) = {
    .height = 20,
    .radius = 21,
    .level = 6,
    .ai = &N(EVS_NpcAI_Paragoomba),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_02,
};

StaticNpc N(NpcData_SpikedGoomba) = {
    .id = NPC_SpikedGoomba,
    .settings = &N(NpcSettings_SpikedGoomba),
    .pos = { 160.0f, 0.0f, 30.0f },
    .yaw = 270,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING | NPC_FLAG_NO_PROJECT_SHADOW,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_MUSHROOM, 10, 0 },
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
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 160, 0, 30 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 160, 0, 30 },
            .detectSize = { 300 },
        }
    },
    .animations = {
        .idle   = ANIM_SpikedGoomba_Idle,
        .walk   = ANIM_SpikedGoomba_Walk,
        .run    = ANIM_SpikedGoomba_Run,
        .chase  = ANIM_SpikedGoomba_Run,
        .anim_4 = ANIM_SpikedGoomba_Idle,
        .anim_5 = ANIM_SpikedGoomba_Idle,
        .death  = ANIM_SpikedGoomba_HurtStill,
        .hit    = ANIM_SpikedGoomba_HurtStill,
        .anim_8 = ANIM_SpikedGoomba_Run,
        .anim_9 = ANIM_SpikedGoomba_Run,
        .anim_A = ANIM_SpikedGoomba_Run,
        .anim_B = ANIM_SpikedGoomba_Run,
        .anim_C = ANIM_SpikedGoomba_Run,
        .anim_D = ANIM_SpikedGoomba_Run,
        .anim_E = ANIM_SpikedGoomba_Run,
        .anim_F = ANIM_SpikedGoomba_Run,
    },
};

StaticNpc N(NpcData_Paragoomba) = {
    .id = NPC_Paragoomba,
    .settings = &N(NpcSettings_Paragoomba),
    .pos = { 525.0f, 60.0f, 15.0f },
    .yaw = 270,
    .flags = NPC_FLAG_100 | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = {
            { ITEM_MUSHROOM, 10, 0 },
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
            .centerPos  = { 525, 60, 15 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 525, 60, 15 },
            .detectSize = { 300 },
        }
    },
    .animations = {
        .idle   = ANIM_Paragoomba_Idle,
        .walk   = ANIM_Paragoomba_Walk,
        .run    = ANIM_Paragoomba_Run,
        .chase  = ANIM_Paragoomba_Run,
        .anim_4 = ANIM_Paragoomba_Idle,
        .anim_5 = ANIM_Paragoomba_Idle,
        .death  = ANIM_Paragoomba_Hurt,
        .hit    = ANIM_Paragoomba_Hurt,
        .anim_8 = ANIM_Paragoomba_Run,
        .anim_9 = ANIM_Paragoomba_Run,
        .anim_A = ANIM_Paragoomba_Run,
        .anim_B = ANIM_Paragoomba_Run,
        .anim_C = ANIM_Paragoomba_Run,
        .anim_D = ANIM_Paragoomba_Run,
        .anim_E = ANIM_Paragoomba_Run,
        .anim_F = ANIM_Paragoomba_Run,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_SpikedGoomba), BTL_KMR_PART_1_FORMATION_0B, BTL_KMR_PART_1_STAGE_02),
    NPC_GROUP(N(NpcData_Paragoomba), BTL_KMR_PART_1_FORMATION_09, BTL_KMR_PART_1_STAGE_02),
    {}
};
