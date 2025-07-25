#include "trd_08.h"
#include "effects.h"

#include "world/common/enemy/ai/FireBarAI.inc.c"

s32 N(FireBar_Sounds)[] = {
    SOUND_SEQ_FIRE_BAR_0, SOUND_SEQ_FIRE_BAR_1, SOUND_SEQ_FIRE_BAR_2, SOUND_SEQ_FIRE_BAR_3,
    SOUND_SEQ_FIRE_BAR_4, SOUND_SEQ_FIRE_BAR_5, SOUND_SEQ_FIRE_BAR_6, SOUND_SEQ_FIRE_BAR_7,
    SOUND_SEQ_FIRE_BAR_8, SOUND_SEQ_FIRE_BAR_9, SOUND_SEQ_FIRE_BAR_9,
};

EvtScript N(EVS_FireBar_Defeated) = {
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Loop(15)
        Loop(LVar1)
            Call(SetNpcFlagBits, LVar0, NPC_FLAG_INVISIBLE, true)
            Add(LVar0, 1)
        EndLoop
        Wait(1)
        Set(LVar0, LVarA)
        Set(LVar1, LVarB)
        Loop(LVar1)
            Call(SetNpcFlagBits, LVar0, NPC_FLAG_INVISIBLE, false)
            Add(LVar0, 1)
        EndLoop
        Wait(1)
        Set(LVar0, LVarA)
        Set(LVar1, LVarB)
    EndLoop
    Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
    Call(PlaySoundAt, SOUND_SEQ_FIRE_BAR_DEAD, SOUND_SPACE_DEFAULT, LVar1, LVar2, LVar3)
    Loop(10)
        Call(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        Call(RandInt, 50, LVar4)
        Sub(LVar4, 25)
        Call(RandInt, 30, LVar5)
        Add(LVar1, LVar4)
        Add(LVar2, LVar5)
        PlayEffect(EFFECT_00, LVar1, LVar2, LVar3, 1, 20, 3, 2)
    EndLoop
    IfEq(LVarA, NPC_FireBar_1A)
        IfEq(AF_TRD08_FireBar1_Coins, false)
            Set(AF_TRD08_FireBar1_Coins, true)
            Loop(10)
                Call(MakeItemEntity, ITEM_COIN, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
            EndLoop
        EndIf
    EndIf
    IfEq(LVarA, NPC_FireBar_2A)
        IfEq(AF_TRD08_FireBar2_Coins, false)
            Set(AF_TRD08_FireBar2_Coins, true)
            Loop(10)
                Call(MakeItemEntity, ITEM_COIN, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
            EndLoop
        EndIf
    EndIf
    Call(RemoveEncounter, LVarA)
    Return
    End
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
    Call(EnableNpcShadow, NPC_SELF, false)
    Call(SetNpcFlagBits, NPC_SELF, 0, true)
    Call(EnableNpcShadow, NPC_SELF, true)
    Thread
        Call(RandInt, 5, LVar0)
        Add(LVar0, 1)
        Wait(LVar0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Fire_Brighest_Still)
        Wait(1)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Fire_Brighest_Burn)
    EndThread
    Return
    End
};

EvtScript N(EVS_NpcAI_FireBar_01) = {
    Call(N(FireBarAI_Main), Ref(N(AISettings_FireBar_01)))
    Return
    End
};

EvtScript N(EVS_NpcAI_FireBar_02) = {
    Call(N(FireBarAI_Main), Ref(N(AISettings_FireBar_02)))
    Return
    End
};

NpcSettings N(NpcSettings_FireBar_01) = {
    .defaultAnim = ANIM_Fire_Brighest_Burn,
    .height = 12,
    .radius = 20,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .ai = &N(EVS_NpcAI_FireBar_01),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
};

NpcSettings N(NpcSettings_FireBar_02) = {
    .defaultAnim = ANIM_Fire_Brighest_Burn,
    .height = 12,
    .radius = 20,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .ai = &N(EVS_NpcAI_FireBar_02),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
};

NpcSettings N(NpcSettings_FireBar_Extra) = {
    .defaultAnim = ANIM_Fire_Brighest_Burn,
    .height = 12,
    .radius = 20,
    .otherAI = &N(EVS_NpcAuxAI_00),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
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
