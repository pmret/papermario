#include "kzn_04.h"
#include "effects.h"

#include "sprite/npc/Fire.h"
#include "world/common/enemy/ai/FireBarAI.inc.c"

s32 N(FireBar_Sounds)[] = {
    SOUND_SEQ_FIRE_BAR_0, SOUND_SEQ_FIRE_BAR_1, SOUND_SEQ_FIRE_BAR_2, SOUND_SEQ_FIRE_BAR_3,
    SOUND_SEQ_FIRE_BAR_4, SOUND_SEQ_FIRE_BAR_5, SOUND_SEQ_FIRE_BAR_6, SOUND_SEQ_FIRE_BAR_7,
    SOUND_SEQ_FIRE_BAR_8, SOUND_SEQ_FIRE_BAR_9, SOUND_SEQ_FIRE_BAR_9,
};

EvtScript N(EVS_FireBar_Defeated) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_LOOP(15)
        EVT_LOOP(LVar1)
            EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_INVISIBLE, TRUE)
            EVT_ADD(LVar0, 1)
        EVT_END_LOOP
        EVT_WAIT(1)
        EVT_SET(LVar0, LVarA)
        EVT_SET(LVar1, LVarB)
        EVT_LOOP(LVar1)
            EVT_CALL(SetNpcFlagBits, LVar0, NPC_FLAG_INVISIBLE, FALSE)
            EVT_ADD(LVar0, 1)
        EVT_END_LOOP
        EVT_WAIT(1)
        EVT_SET(LVar0, LVarA)
        EVT_SET(LVar1, LVarB)
    EVT_END_LOOP
    EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(PlaySoundAt, SOUND_SEQ_FIRE_BAR_DEAD, SOUND_SPACE_DEFAULT, LVar1, LVar2, LVar3)
    EVT_LOOP(10)
        EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_CALL(RandInt, 50, LVar4)
        EVT_SUB(LVar4, 25)
        EVT_CALL(RandInt, 30, LVar5)
        EVT_ADD(LVar1, LVar4)
        EVT_ADD(LVar2, LVar5)
        EVT_PLAY_EFFECT(EFFECT_00, LVar1, LVar2, LVar3, 1, 20, 3, 2)
    EVT_END_LOOP
    EVT_IF_EQ(LVarA, NPC_FireBar_1A)
        EVT_IF_EQ(AF_KZN04_FireBar1_Coins, FALSE)
            EVT_SET(AF_KZN04_FireBar1_Coins, TRUE)
            EVT_LOOP(10)
                EVT_CALL(MakeItemEntity, ITEM_COIN, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVarA, NPC_FireBar_2A)
        EVT_IF_EQ(AF_KZN04_FireBar2_Coins, FALSE)
            EVT_SET(AF_KZN04_FireBar2_Coins, TRUE)
            EVT_LOOP(10)
                EVT_CALL(MakeItemEntity, ITEM_COIN, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVarA, NPC_FireBar_3A)
        EVT_IF_EQ(AF_KZN04_FireBar3_Coins, FALSE)
            EVT_SET(AF_KZN04_FireBar3_Coins, TRUE)
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
    .centerPos = { -280, 500, -30 },
    .rotRate = 8,
    .firstNpc = NPC_FireBar_1A,
    .npcCount = 4,
    .callback = N(FireBarAI_Callback),
};

FireBarAISettings N(AISettings_FireBar_02) = {
    .centerPos = { 0, 500, 40 },
    .rotRate = -8,
    .firstNpc = NPC_FireBar_2A,
    .npcCount = 4,
    .callback = N(FireBarAI_Callback),
};

FireBarAISettings N(AISettings_FireBar_03) = {
    .centerPos = { 280, 500, -30 },
    .rotRate = 8,
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
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
};

NpcSettings N(NpcSettings_FireBar_02) = {
    .defaultAnim = ANIM_Fire_Brighest_Burn,
    .height = 12,
    .radius = 20,
    .ai = &N(EVS_NpcAI_FireBar_02),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
};

NpcSettings N(NpcSettings_FireBar_03) = {
    .defaultAnim = ANIM_Fire_Brighest_Burn,
    .height = 12,
    .radius = 20,
    .ai = &N(EVS_NpcAI_FireBar_03),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
};

NpcSettings N(NpcSettings_FireBar_Extra) = {
    .defaultAnim = ANIM_Fire_Brighest_Burn,
    .height = 12,
    .radius = 25,
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
};

NpcData N(NpcData_FireBar_01)[] = {
    {
        .id = NPC_FireBar_1A,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = (void*) 0x00004003,
        .settings = &N(NpcSettings_FireBar_01),
        .flags = ENEMY_FLAG_PASSIVE,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_1B,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = (void*) 0x00004003,
        .settings = &N(NpcSettings_FireBar_Extra),
        .flags = ENEMY_FLAG_PASSIVE,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_1C,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = (void*) 0x00004003,
        .settings = &N(NpcSettings_FireBar_Extra),
        .flags = ENEMY_FLAG_PASSIVE,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_1D,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = (void*) 0x00004003,
        .settings = &N(NpcSettings_FireBar_Extra),
        .flags = ENEMY_FLAG_PASSIVE,
        .animations = {
        },
    },
};

NpcData N(NpcData_FireBar_02)[] = {
    {
        .id = NPC_FireBar_2A,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = (void*) 0x00004003,
        .settings = &N(NpcSettings_FireBar_02),
        .flags = ENEMY_FLAG_PASSIVE,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_2B,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = (void*) 0x00004003,
        .settings = &N(NpcSettings_FireBar_Extra),
        .flags = ENEMY_FLAG_PASSIVE,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_2C,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = (void*) 0x00004003,
        .settings = &N(NpcSettings_FireBar_Extra),
        .flags = ENEMY_FLAG_PASSIVE,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_2D,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = (void*) 0x00004003,
        .settings = &N(NpcSettings_FireBar_Extra),
        .flags = ENEMY_FLAG_PASSIVE,
        .animations = {
        },
    },
};

NpcData N(NpcData_FireBar_03)[] = {
    {
        .id = NPC_FireBar_3A,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = (void*) 0x00004003,
        .settings = &N(NpcSettings_FireBar_03),
        .flags = ENEMY_FLAG_PASSIVE,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_3B,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = (void*) 0x00004003,
        .settings = &N(NpcSettings_FireBar_Extra),
        .flags = ENEMY_FLAG_PASSIVE,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_3C,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = (void*) 0x00004003,
        .settings = &N(NpcSettings_FireBar_Extra),
        .flags = ENEMY_FLAG_PASSIVE,
        .animations = {
        },
    },
    {
        .id = NPC_FireBar_3D,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = (void*) 0x00004003,
        .settings = &N(NpcSettings_FireBar_Extra),
        .flags = ENEMY_FLAG_PASSIVE,
        .animations = {
        },
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_FireBar_01)),
    NPC_GROUP(N(NpcData_FireBar_02)),
    NPC_GROUP(N(NpcData_FireBar_03)),
    {}
};
