#include "tik_05.h"

MobileAISettings N(D_80241C90_876A50) = {
    .moveSpeed = 2.2f,
    .alertRadius = 70.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 3.2f,
    .chaseTurnRate = 15,
    .chaseUpdateInterval = 1,
    .chaseRadius = 90.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_SpikedGoomba_01) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(D_80241C90_876A50)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_SpikedGoomba_01) = {
    .height = 23,
    .radius = 23,
    .level = 12,
    .ai = &N(EVS_NpcAI_SpikedGoomba_01),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

StaticNpc N(NpcData_SpikedGoomba_01) = {
    .id = NPC_SpikedGoomba_01,
    .settings = &N(NpcSettings_SpikedGoomba_01),
    .pos = { 220.0f, -10.0f, -80.0f },
    .yaw = 270,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 20,
        .itemDrops = {
            { ITEM_DIZZY_DIAL, 5, 0 },
            { ITEM_SLEEPY_SHEEP, 5, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 2,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 220, -10, -80 },
            .wanderSize = { 20 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 160, 0, -20 },
            .detectSize = { 180, 100 },
        }
    },
    .animations = {
        .idle   = ANIM_SpikedGoomba_Dark_Idle,
        .walk   = ANIM_SpikedGoomba_Dark_Run,
        .run    = ANIM_SpikedGoomba_Dark_Run,
        .chase  = ANIM_SpikedGoomba_Dark_Run,
        .anim_4 = ANIM_SpikedGoomba_Dark_Run,
        .anim_5 = ANIM_SpikedGoomba_Dark_Idle,
        .death  = ANIM_SpikedGoomba_Dark_HurtStill,
        .hit    = ANIM_SpikedGoomba_Dark_HurtStill,
        .anim_8 = ANIM_SpikedGoomba_Dark_Still,
        .anim_9 = ANIM_SpikedGoomba_Dark_Still,
        .anim_A = ANIM_SpikedGoomba_Dark_Still,
        .anim_B = ANIM_SpikedGoomba_Dark_Still,
        .anim_C = ANIM_SpikedGoomba_Dark_Still,
        .anim_D = ANIM_SpikedGoomba_Dark_Still,
        .anim_E = ANIM_SpikedGoomba_Dark_Still,
        .anim_F = ANIM_SpikedGoomba_Dark_Still,
    },
};

StaticNpc N(NpcData_SpikedGoomba_02) = {
    .id = NPC_SpikedGoomba_02,
    .settings = &N(NpcSettings_SpikedGoomba_01),
    .pos = { 130.0f, -10.0f, 45.0f },
    .yaw = 90,
    .flags = ENEMY_FLAGS_400 | ENEMY_FLAGS_800 | ENEMY_FLAGS_2000,
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 20,
        .itemDrops = {
            { ITEM_DIZZY_DIAL, 5, 0 },
            { ITEM_SLEEPY_SHEEP, 5, 0 },
        },
        .heartDrops  = STANDARD_HEART_DROPS(2),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 2,
    },
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 130, -10, 45 },
            .wanderSize = { 20 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 160, 0, -20 },
            .detectSize = { 180, 100 },
        }
    },
    .animations = {
        .idle   = ANIM_SpikedGoomba_Dark_Idle,
        .walk   = ANIM_SpikedGoomba_Dark_Run,
        .run    = ANIM_SpikedGoomba_Dark_Run,
        .chase  = ANIM_SpikedGoomba_Dark_Run,
        .anim_4 = ANIM_SpikedGoomba_Dark_Run,
        .anim_5 = ANIM_SpikedGoomba_Dark_Idle,
        .death  = ANIM_SpikedGoomba_Dark_HurtStill,
        .hit    = ANIM_SpikedGoomba_Dark_HurtStill,
        .anim_8 = ANIM_SpikedGoomba_Dark_Still,
        .anim_9 = ANIM_SpikedGoomba_Dark_Still,
        .anim_A = ANIM_SpikedGoomba_Dark_Still,
        .anim_B = ANIM_SpikedGoomba_Dark_Still,
        .anim_C = ANIM_SpikedGoomba_Dark_Still,
        .anim_D = ANIM_SpikedGoomba_Dark_Still,
        .anim_E = ANIM_SpikedGoomba_Dark_Still,
        .anim_F = ANIM_SpikedGoomba_Dark_Still,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_SpikedGoomba_01), BTL_TIK_FORMATION_10, BTL_TIK_STAGE_00),
    NPC_GROUP(N(NpcData_SpikedGoomba_02), BTL_TIK_FORMATION_12, BTL_TIK_STAGE_00),
    {}
};
