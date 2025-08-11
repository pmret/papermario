#include "jan_15.h"

#include "world/common/enemy/PutridPiranhaSentinel.inc.c"
#include "world/common/enemy/HeartPlant.inc.c"

EvtScript N(EVS_PutridPiranhas_IdleChomping) = {
    ChildThread
        Loop(0)
            Call(RandInt, 5, LVar0)
            IfNe(LVar0, 0)
                Call(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim01)
                Wait(15)
            Else
                Call(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim05)
                Wait(10)
                Call(SetNpcAnimation, NPC_SELF, ANIM_LargePiranha_Putrid_Anim06)
                Wait(5)
            EndIf
        EndLoop
    EndChildThread
    ChildThread
        Loop(0)
            Call(RandInt, 5, LVar0)
            IfNe(LVar0, 0)
                Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim01)
                Wait(15)
            Else
                Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim05)
                Wait(10)
                Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim06)
                Wait(5)
            EndIf
        EndLoop
    EndChildThread
    Loop(0)
        Call(RandInt, 5, LVar0)
        IfNe(LVar0, 0)
            Call(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim01)
            Wait(15)
        Else
            Call(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim05)
            Wait(10)
            Call(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim06)
            Wait(5)
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_PutridPiranha) = {
    IfEq(GF_JAN15_EncounteredMiniboss, false)
        Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, 34)
            Wait(1)
            Goto(0)
        EndIf
        Call(DisablePlayerInput, true)
        Call(ShowMessageAtScreenPos, MSG_CH5_00BB, 320, 60)
        Set(GF_JAN15_EncounteredMiniboss, true)
        Call(DisablePlayerInput, false)
    EndIf
    ExecGetTID(N(EVS_PutridPiranhas_IdleChomping), LVar9)
    Call(AwaitPlayerApproach, 400, -10, 135)
    Call(DisablePlayerInput, true)
    KillThread(LVar9)
    Wait(15)
    Call(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim01)
    Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim01)
    Call(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim01)
    Thread
        Wait(10)
        Call(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim04)
        Set(LVar0, 0)
        Loop(15)
            Add(LVar0, 24)
            Call(SetNpcRotation, NPC_PutridPiranha_03, 0, LVar0, 0)
            Wait(1)
        EndLoop
        Call(PlaySoundAtNpc, NPC_PutridPiranha_03, SOUND_PIRANHA_SPIN, SOUND_SPACE_DEFAULT)
        Call(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim01)
    EndThread
    Call(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim04)
    Set(LVar0, 0)
    Loop(15)
        Add(LVar0, 24)
        Call(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_SPIN_1, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim01)
    Wait(5)
    Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim04)
    Set(LVar0, 0)
    Loop(15)
        Add(LVar0, 24)
        Call(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(PlaySoundAtNpc, NPC_PutridPiranha_02, SOUND_PIRANHA_SPIN_1, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim01)
    Wait(5)
    Call(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim04)
    Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim04)
    Call(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim04)
    Set(LVar0, 0)
    Loop(12)
        Add(LVar0, 30)
        Call(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_PutridPiranha_03, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_SPIN_2, SOUND_SPACE_DEFAULT)
    Set(LVar0, 0)
    Loop(12)
        Add(LVar0, 30)
        Call(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_PutridPiranha_03, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_SPIN_2, SOUND_SPACE_DEFAULT)
    Set(LVar0, 0)
    Loop(12)
        Add(LVar0, 30)
        Call(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_PutridPiranha_03, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_SPIN_2, SOUND_SPACE_DEFAULT)
    Loop(3)
        Wait(5)
        Call(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_TENSE, SOUND_SPACE_DEFAULT)
    EndLoop
    Call(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim05)
    Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim05)
    Call(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim05)
    Wait(20)
    Call(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim06)
    Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim06)
    Call(SetNpcAnimation, NPC_PutridPiranha_03, ANIM_LargePiranha_Putrid_Anim06)
    Call(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_CHOMP, SOUND_SPACE_DEFAULT)
    Call(DisablePlayerInput, false)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcHit_PutridPiranha) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(GB_StoryProgress, STORY_CH5_DEFEATED_PIRANHAS_MINIBOSS)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_PutridPiranha) = {
    IfLt(GB_StoryProgress, STORY_CH5_DEFEATED_PIRANHAS_MINIBOSS)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_PutridPiranha)))
        Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_PutridPiranha)))
    Else
        Call(SetNpcPos, NPC_PutridPiranha_01, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_PutridPiranha_02, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_PutridPiranha_03, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

NpcData N(NpcData_Piranhas)[] = {
    {
        .id = NPC_PutridPiranha_01,
        .pos = { 365.0f, 0.0f, -45.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_PutridPiranha),
        .settings = &N(NpcSettings_PutridPiranhaSentinel),
        .flags = ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE,
        .drops = PIRANHA_NO_DROPS,
        .animations = PIRANHA_SENTINEL_ANIMS,
    },
    {
        .id = NPC_PutridPiranha_02,
        .pos = { 325.0f, 0.0f, 0.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_PutridPiranhaSentinel),
        .flags = ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE,
        .drops = PIRANHA_NO_DROPS,
        .animations = PIRANHA_SENTINEL_ANIMS,
    },
    {
        .id = NPC_PutridPiranha_03,
        .pos = { 375.0f, 0.0f, 45.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_PutridPiranhaSentinel),
        .flags = ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE,
        .drops = PIRANHA_NO_DROPS,
        .animations = PIRANHA_SENTINEL_ANIMS,
    },
};

NpcData N(NpcData_HeartPlant_01) = {
    .id = NPC_HeartPlant_01,
    .pos = { -183.0f, 0.0f, 47.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_INSPECT_ICON | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcData N(NpcData_HeartPlant_02) = {
    .id = NPC_HeartPlant_02,
    .pos = { -124.0f, 0.0f, 20.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_USE_INSPECT_ICON | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Piranhas), BTL_JAN2_FORMATION_03, BTL_JAN2_STAGE_04),
    NPC_GROUP(N(NpcData_HeartPlant_01)),
    NPC_GROUP(N(NpcData_HeartPlant_02)),
    {}
};
