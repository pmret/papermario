#include "kzn_11.h"

#include "world/common/enemy/LavaBubble.inc.c"

#include "sprite/npc/Fire.h"
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
        IfEq(AF_KZN11_FireBar1_Coins, false)
            Set(AF_KZN11_FireBar1_Coins, true)
            Loop(10)
                Call(MakeItemEntity, ITEM_COIN, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
            EndLoop
        EndIf
    EndIf
    IfEq(LVarA, NPC_FireBar_2A)
        IfEq(AF_KZN11_FireBar2_Coins, false)
            Set(AF_KZN11_FireBar2_Coins, true)
            Loop(10)
                Call(MakeItemEntity, ITEM_COIN, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0)
            EndLoop
        EndIf
    EndIf
    IfEq(LVarA, NPC_FireBar_3A)
        IfEq(AF_KZN11_FireBar3_Coins, false)
            Set(AF_KZN11_FireBar3_Coins, true)
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
    .centerPos = { -300, 20, 15 },
    .rotRate = 8,
    .firstNpc = NPC_FireBar_1A,
    .npcCount = 4,
    .callback = N(FireBarAI_Callback),
};

FireBarAISettings N(AISettings_FireBar_02) = {
    .centerPos = { 0, 20, 15 },
    .rotRate = -8,
    .firstNpc = NPC_FireBar_2A,
    .npcCount = 4,
    .callback = N(FireBarAI_Callback),
};

FireBarAISettings N(AISettings_FireBar_03) = {
    .centerPos = { 325, 20, 15 },
    .rotRate = -8,
    .firstNpc = NPC_FireBar_3A,
    .npcCount = 4,
    .callback = N(FireBarAI_Callback),
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

EvtScript N(EVS_NpcAI_FireBar_03) = {
    Call(N(FireBarAI_Main), Ref(N(AISettings_FireBar_03)))
    Return
    End
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
    .radius = 20,
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

NpcData N(NpcData_Bubble_01) = {
    .id = NPC_Bubble_01,
    .pos = { -150.0f, 50.0f, 10.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -150, 50, 10 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -150, 50, 10 },
            .detectSize = { 150 },
        }
    },
    .settings = &N(NpcSettings_LavaBubble),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = LAVA_BUBBLE_DROPS,
    .animations = LAVA_BUBBLE_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Bubble_02) = {
    .id = NPC_Bubble_02,
    .pos = { 150.0f, 50.0f, 10.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 150, 50, 10 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 150, 50, 10 },
            .detectSize = { 150 },
        }
    },
    .settings = &N(NpcSettings_LavaBubble),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = LAVA_BUBBLE_DROPS,
    .animations = LAVA_BUBBLE_ANIMS,
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
