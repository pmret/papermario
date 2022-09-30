#include "kzn_11.h"

f32 N(FlyingAI_JumpVels)[] = {
    4.5, 3.5, 2.6, 2.0, 1.5, 20.0,
};

#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/enemy/FlyingNoAttackAI.inc.c"

#include "world/common/enemy/FireBarAI.inc.c"

MobileAISettings N(AISettings_Bubble) = {
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

EvtScript N(EVS_NpcAI_Bubble) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, 0)
    EVT_CALL(SetSelfVar, 6, 0)
    EVT_CALL(SetSelfVar, 1, 150)
    EVT_CALL(N(FlyingNoAttackAI_Main), EVT_PTR(N(AISettings_Bubble)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Bubble) = {
    .height = 20,
    .radius = 22,
    .level = 17,
    .ai = &N(EVS_NpcAI_Bubble),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

s32 N(FireBar_Sounds)[] = {
    SOUND_FireBar0, SOUND_FireBar1, SOUND_FireBar2, SOUND_FireBar3,
    SOUND_FireBar4, SOUND_FireBar5, SOUND_FireBar6, SOUND_FireBar7,
    SOUND_FireBar8, SOUND_FireBar9, SOUND_FireBar9,
};

EvtScript N(EVS_FireBar_Defeated) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_LOOP(15)
        EVT_LOOP(LVar1)
            EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_2, TRUE)
            EVT_ADD(LVar0, 1)
        EVT_END_LOOP
        EVT_WAIT(1)
        EVT_SET(LVar0, LVarA)
        EVT_SET(LVar1, LVarB)
        EVT_LOOP(LVar1)
            EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_2, FALSE)
            EVT_ADD(LVar0, 1)
        EVT_END_LOOP
        EVT_WAIT(1)
        EVT_SET(LVar0, LVarA)
        EVT_SET(LVar1, LVarB)
    EVT_END_LOOP
    EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(PlaySoundAt, SOUND_B000000A, 0, LVar1, LVar2, LVar3)
    EVT_LOOP(10)
        EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_CALL(RandInt, 50, LVar4)
        EVT_SUB(LVar4, 25)
        EVT_CALL(RandInt, 30, LVar5)
        EVT_ADD(LVar1, LVar4)
        EVT_ADD(LVar2, LVar5)
        EVT_CALL(PlayEffect, EFFECT_00, LVar1, LVar2, LVar3, 1, 20, 3, 2, 0, 0, 0, 0, 0, 0)
    EVT_END_LOOP
    EVT_IF_EQ(LVarA, NPC_FireBar_1A)
        EVT_IF_EQ(AF_KZN11_FireBar1_Coins, FALSE)
            EVT_SET(AF_KZN11_FireBar1_Coins, TRUE)
            EVT_LOOP(10)
                EVT_CALL(MakeItemEntity, ITEM_COIN, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVarA, NPC_FireBar_2A)
        EVT_IF_EQ(AF_KZN11_FireBar2_Coins, FALSE)
            EVT_SET(AF_KZN11_FireBar2_Coins, TRUE)
            EVT_LOOP(10)
                EVT_CALL(MakeItemEntity, ITEM_COIN, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVarA, NPC_FireBar_3A)
        EVT_IF_EQ(AF_KZN11_FireBar3_Coins, FALSE)
            EVT_SET(AF_KZN11_FireBar3_Coins, TRUE)
            EVT_LOOP(10)
                EVT_CALL(MakeItemEntity, ITEM_COIN, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RemoveEncounter, LVarA)
    EVT_RETURN
    EVT_END
};

FireBarAISettings N(AISettings_FireBar_01) = {
    .centerPos = { -300, 20, 15 },
    .rotationRate = 8,
    .firstNpc = NPC_FireBar_1A,
    .npcCount = 4,
    .callback = N(FireBarAI_Callback),
};

FireBarAISettings N(AISettings_FireBar_02) = {
    .centerPos = { 0, 20, 15 },
    .rotationRate = -8,
    .firstNpc = NPC_FireBar_2A,
    .npcCount = 4,
    .callback = N(FireBarAI_Callback),
};

FireBarAISettings N(AISettings_FireBar_03) = {
    .centerPos = { 325, 20, 15 },
    .rotationRate = -8,
    .firstNpc = NPC_FireBar_3A,
    .npcCount = 4,
    .callback = N(FireBarAI_Callback),
};

EvtScript N(EVS_NpcAI_FireBar_01) = {
    EVT_CALL(N(FireBarAI_Main), EVT_PTR(N(AISettings_FireBar_01)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_FireBar_02) = {
    EVT_CALL(N(FireBarAI_Main), EVT_PTR(N(AISettings_FireBar_02)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_FireBar_03) = {
    EVT_CALL(N(FireBarAI_Main), EVT_PTR(N(AISettings_FireBar_03)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_FireBar_01) = {
    .defaultAnim = ANIM_Fire_Brighest_Burn,
    .height = 12,
    .radius = 20,
    .ai = &N(EVS_NpcAI_FireBar_01),
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
};

NpcSettings N(NpcSettings_FireBar_02) = {
    .defaultAnim = ANIM_Fire_Brighest_Burn,
    .height = 12,
    .radius = 20,
    .ai = &N(EVS_NpcAI_FireBar_02),
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
};

NpcSettings N(NpcSettings_FireBar_03) = {
    .defaultAnim = ANIM_Fire_Brighest_Burn,
    .height = 12,
    .radius = 20,
    .ai = &N(EVS_NpcAI_FireBar_03),
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
};

NpcSettings N(NpcSettings_FireBar_Extra) = {
    .defaultAnim = ANIM_Fire_Brighest_Burn,
    .height = 12,
    .radius = 20,
    .flags = ENEMY_FLAGS_100 | ENEMY_FLAGS_200 | ENEMY_FLAGS_400 | ENEMY_FLAGS_800,
};

StaticNpc N(NpcData_FireBar_01)[] = {
    {
        .id = NPC_FireBar_1A,
        .settings = &N(NpcSettings_FireBar_01),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE,
        .init = (void*) 0x00004003,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_1B,
        .settings = &N(NpcSettings_FireBar_Extra),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE,
        .init = (void*) 0x00004003,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_1C,
        .settings = &N(NpcSettings_FireBar_Extra),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE,
        .init = (void*) 0x00004003,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_1D,
        .settings = &N(NpcSettings_FireBar_Extra),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE,
        .init = (void*) 0x00004003,
        .animations = {
        },
    },
};

StaticNpc N(NpcData_FireBar_02)[] = {
    {
        .id = NPC_FireBar_2A,
        .settings = &N(NpcSettings_FireBar_02),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE,
        .init = (void*) 0x00004003,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_2B,
        .settings = &N(NpcSettings_FireBar_Extra),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE,
        .init = (void*) 0x00004003,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_2C,
        .settings = &N(NpcSettings_FireBar_Extra),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE,
        .init = (void*) 0x00004003,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_2D,
        .settings = &N(NpcSettings_FireBar_Extra),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE,
        .init = (void*) 0x00004003,
        .animations = {
        },
    },
};

StaticNpc N(NpcData_FireBar_03)[] = {
    {
        .id = NPC_FireBar_3A,
        .settings = &N(NpcSettings_FireBar_03),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE,
        .init = (void*) 0x00004003,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_3B,
        .settings = &N(NpcSettings_FireBar_Extra),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE,
        .init = (void*) 0x00004003,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_3C,
        .settings = &N(NpcSettings_FireBar_Extra),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE,
        .init = (void*) 0x00004003,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_3D,
        .settings = &N(NpcSettings_FireBar_Extra),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE,
        .init = (void*) 0x00004003,
        .animations = {
        },
    },
};

StaticNpc N(NpcData_Bubble_01) = {
    .id = NPC_Bubble_01,
    .settings = &N(NpcSettings_Bubble),
    .pos = { -150.0f, 50.0f, 10.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
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
            .centerPos  = { -150, 50, 10 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -150, 50, 10 },
            .detectSize = { 150 },
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
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Bubble_02) = {
    .id = NPC_Bubble_02,
    .settings = &N(NpcSettings_Bubble),
    .pos = { 150.0f, 50.0f, 10.0f },
    .yaw = 270,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
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
            .centerPos  = { 150, 50, 10 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 150, 50, 10 },
            .detectSize = { 150 },
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
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_FireBar_01)),
    NPC_GROUP(N(NpcData_FireBar_02)),
    NPC_GROUP(N(NpcData_FireBar_03)),
    NPC_GROUP(N(NpcData_Bubble_01), BTL_KZN_FORMATION_00, BTL_KZN_STAGE_02),
    NPC_GROUP(N(NpcData_Bubble_02), BTL_KZN_FORMATION_07, BTL_KZN_STAGE_02),
    {}
};
