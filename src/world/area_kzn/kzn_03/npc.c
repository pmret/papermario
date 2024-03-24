#include "kzn_03.h"

#include "world/common/enemy/SpikeTop.inc.c"
#include "world/common/enemy/PutridPiranha.inc.c"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/npc/Kolorado.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EVT_LETTER_PROMPT(Kolorado, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
    MSG_CH5_00E4, MSG_CH5_00E5, MSG_CH5_00E6, MSG_CH5_00E7,
    ITEM_LETTER_TO_KOLORADO, N(LetterList));

EVT_LETTER_REWARD(Kolorado);

EvtScript N(EVS_NpcIdle_Kolorado) = {
    Call(SetNpcSpeed, NPC_SELF, Float(2.0))
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
    Call(GetNpcPos, NPC_SELF, LVar4, LVar5, LVar6)
    Set(LVar3, LVar4)
    Add(LVar3, -45)
    Set(LVar7, 90)
    Loop(0)
        Set(LVar2, LVar3)
        Set(LVar3, LVar4)
        Set(LVar4, LVar2)
        Call(InterpNpcYaw, NPC_SELF, LVar7, 5)
        Call(MakeLerp, LVar2, LVar3, 45, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcYaw, NPC_SELF, LVar7)
            Call(SetNpcPos, NPC_SELF, LVar0, LVar5, LVar6)
            Wait(1)
            IfGe(GB_StoryProgress, STORY_CH5_SMASHED_ULTRA_BLOCK)
                BreakLoop
            EndIf
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        IfGe(GB_StoryProgress, STORY_CH5_SMASHED_ULTRA_BLOCK)
            BreakLoop
        EndIf
        Add(LVar7, 180)
        IfGe(LVar7, 360)
            Add(LVar7, -360)
        EndIf
    EndLoop
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Wait(10)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetSelfVar, 0, 1)
    Thread
        Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        Call(SetNpcJumpscale, NPC_SELF, Float(2.5))
        Label(5)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 9)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 1)
            Wait(6)
            Goto(5)
        EndIf
    EndThread
    Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Panic, 512, MSG_CH5_00F3)
    Call(SetSelfVar, 0, 0)
    Wait(18)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    IfLt(GB_StoryProgress, STORY_CH5_SMASHED_ULTRA_BLOCK)
        IfEq(GF_KZN03_SpokeWithKolorado, FALSE)
            Call(AdjustCam, CAM_DEFAULT, Float(3.3), 0, 350, Float(15.0), Float(-7.0))
            Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00F1)
            Set(GF_KZN03_SpokeWithKolorado, TRUE)
            Call(ResetCam, CAM_DEFAULT, Float(5.0))
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00F2)
        EndIf
    Else
        Call(SetSelfVar, 0, 1)
        Thread
            Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
            Call(SetNpcJumpscale, NPC_SELF, Float(2.5))
            Label(5)
            Call(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 9)
            Call(GetSelfVar, 0, LVar0)
            IfEq(LVar0, 1)
                Wait(6)
                Goto(5)
            EndIf
        EndThread
        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Panic, 512, MSG_CH5_00F3)
        Call(SetSelfVar, 0, 0)
        Wait(18)
    EndIf
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_LETTER_CHECK(Kolorado)
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_SMASHED_ULTRA_BLOCK)
            IfEq(GF_KZN06_Visited, TRUE)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Kolorado)))
                Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado)))
                Return
            EndIf
        CaseEq(STORY_CH5_SMASHED_ULTRA_BLOCK)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado)))
            Return
    EndSwitch
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_SyncZiplineDummyNPC1) = {
    Loop(0)
        Call(GetModelCenter, MODEL_kassya_koma)
        Call(SetNpcPos, NPC_ZiplineDummy1, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_SyncZiplineDummyNPC2) = {
    Loop(0)
        Call(GetModelCenter, MODEL_kssya2_koma)
        Call(SetNpcPos, NPC_ZiplineDummy2, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_ZiplineDummy) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    Call(SetNpcScale, NPC_SELF, Float(0.3), 1, Float(0.3))
    Return
    End
};

NpcData N(NpcData_PassiveNPCs)[] = {
    {
        .id = NPC_Kolorado,
        .pos = { 392.0f, 470.0f, 218.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Kolorado),
        .settings = &N(NpcSettings_Kolorado),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
    {
        .id = NPC_ZiplineDummy1,
        .pos = { 392.0f, 470.0f, 218.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_ZiplineDummy),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
    {
        .id = NPC_ZiplineDummy2,
        .pos = { 392.0f, 470.0f, 218.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_ZiplineDummy),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
};

NpcData N(NpcData_SpikeTop_01) = {
    .id = NPC_SpikeTop_01,
    .pos = { 140.0f, 670.0f, -20.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 140, 670, -20 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { -50, 670, -25 },
            .detectSize = { 240, 115 },
        }
    },
    .settings = &N(NpcSettings_SpikeTop),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = SPIKE_TOP_DROPS,
    .animations = SPIKE_TOP_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_SpikeTop_02) = {
    .id = NPC_SpikeTop_02,
    .pos = { -200.0f, 670.0f, -35.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -200, 670, -35 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { -50, 670, -25 },
            .detectSize = { 240, 115 },
        }
    },
    .settings = &N(NpcSettings_SpikeTop),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = SPIKE_TOP_DROPS,
    .animations = SPIKE_TOP_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_SpikeTop_03) = {
    .id = NPC_SpikeTop_03,
    .pos = { 30.0f, 20.0f, 320.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 30, 20, 320 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 140, 20, 275 },
            .detectSize = { 180, 95 },
        }
    },
    .settings = &N(NpcSettings_SpikeTop),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = SPIKE_TOP_DROPS,
    .animations = SPIKE_TOP_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_PutridPiranha)[] = {
    {
        .id = NPC_Piranha,
        .pos = { 260.0f, 20.0f, 255.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 260, 20, 255 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 260, 20, 255 },
                .detectSize = { 100, 50 },
            }
        },
        .settings = &N(NpcSettings_PutridPiranha),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = PUTRID_PIRANHA_DROPS,
        .animations = PUTRID_PIRANHA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    PUTRID_PIRANHA_HITBOX(NPC_Piranha_Hitbox),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_PassiveNPCs)),
    NPC_GROUP(N(NpcData_SpikeTop_01), BTL_KZN_FORMATION_08, BTL_KZN_STAGE_01),
    NPC_GROUP(N(NpcData_SpikeTop_02), BTL_KZN_FORMATION_09, BTL_KZN_STAGE_01),
    NPC_GROUP(N(NpcData_SpikeTop_03), BTL_KZN_FORMATION_0A, BTL_KZN_STAGE_01),
    NPC_GROUP(N(NpcData_PutridPiranha), BTL_KZN_FORMATION_13, BTL_KZN_STAGE_01),
    {}
};
