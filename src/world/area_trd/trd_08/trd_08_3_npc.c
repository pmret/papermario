#include "trd_08.h"
#include "effects.h"

#include "world/common/enemy/ai/FireBarAI.inc.c"

s32 N(FireBar_Sounds)[] = {
    SOUND_FIRE_BAR_0, SOUND_FIRE_BAR_1, SOUND_FIRE_BAR_2, SOUND_FIRE_BAR_3,
    SOUND_FIRE_BAR_4, SOUND_FIRE_BAR_5, SOUND_FIRE_BAR_6, SOUND_FIRE_BAR_7,
    SOUND_FIRE_BAR_8, SOUND_FIRE_BAR_9, SOUND_FIRE_BAR_9,
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
    EVT_CALL(PlaySoundAt, SOUND_B000000A, SOUND_SPACE_MODE_0, LVar1, LVar2, LVar3)
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
        EVT_IF_EQ(AF_TRD08_FireBar1_Coins, FALSE)
            EVT_SET(AF_TRD08_FireBar1_Coins, TRUE)
            EVT_LOOP(10)
                EVT_CALL(MakeItemEntity, ITEM_COIN, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVarA, NPC_FireBar_2A)
        EVT_IF_EQ(AF_TRD08_FireBar2_Coins, FALSE)
            EVT_SET(AF_TRD08_FireBar2_Coins, TRUE)
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
    .centerPos = { -100, 0, 40 },
    .rotRate = 8,
    .firstNpc = NPC_FireBar_1A,
    .npcCount = 4,
    .callback = N(FireBarAI_Callback),
};

FireBarAISettings N(AISettings_FireBar_02) = {
    .centerPos = { 300, 0, -35 },
    .rotRate = -8,
    .firstNpc = NPC_FireBar_2A,
    .npcCount = 4,
    .callback = N(FireBarAI_Callback),
};

EvtScript N(EVS_NpcAuxAI_00) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, 0, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
    EVT_THREAD
        EVT_CALL(RandInt, 5, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_WAIT(LVar0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fire_Brighest_Still)
        EVT_WAIT(1)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fire_Brighest_Burn)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
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

NpcSettings N(NpcSettings_FireBar_01) = {
    .defaultAnim = ANIM_Fire_Brighest_Burn,
    .height = 12,
    .radius = 20,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .ai = &N(EVS_NpcAI_FireBar_01),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
};

NpcSettings N(NpcSettings_FireBar_02) = {
    .defaultAnim = ANIM_Fire_Brighest_Burn,
    .height = 12,
    .radius = 20,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .ai = &N(EVS_NpcAI_FireBar_02),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
};

NpcSettings N(NpcSettings_FireBar_Extra) = {
    .defaultAnim = ANIM_Fire_Brighest_Burn,
    .height = 12,
    .radius = 20,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800,
};

NpcData N(NpcData_00)[] = {
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

NpcData N(NpcData_05)[] = {
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

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_00), BTL_KMR_1_FORMATION_06),
    NPC_GROUP(N(NpcData_05), BTL_KMR_1_FORMATION_06),
    {}
};
