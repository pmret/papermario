#include "pra_18.h"
#include "effects.h"

#include "world/common/enemy/FrostClubba.h"

NpcSettings N(NpcSettings_Clubba) = {
    .height = 70,
    .radius = 60,
    .level = ACTOR_LEVEL_NONE,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_NpcInteract_Clubba_01) = {
    Call(SetSelfVar, 0, 1)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Clubba_02) = {
    Call(SetSelfVar, 0, 1)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Clubba_03) = {
    Call(SetSelfVar, 0, 1)
    Return
    End
};

EvtScript N(EVS_NpcHit_Clubba_01) = {
    Call(SetSelfVar, 0, 2)
    Return
    End
};

EvtScript N(EVS_NpcHit_Clubba_02) = {
    Call(SetSelfVar, 0, 2)
    Return
    End
};

EvtScript N(EVS_NpcHit_Clubba_03) = {
    Call(SetSelfVar, 0, 2)
    Return
    End
};

EvtScript N(EVS_NpcHit_Clubba_01_Aux) = {
    Return
    End
};

EvtScript N(EVS_NpcHit_Clubba_02_Aux) = {
    Return
    End
};

EvtScript N(EVS_NpcHit_Clubba_03_Aux) = {
    Return
    End
};

EvtScript N(EVS_NpcIdle_Clubba_01) = {
    Loop(0)
        Wait(1)
        Call(GetSelfVar, 0, LVar0)
        IfNe(LVar0, 0)
            BreakLoop
        EndIf
        Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        Call(IsPlayerWithin, LVar3, LVar5, 80, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
    EndLoop
    IfNe(LVar0, 2)
        Call(DisablePlayerInput, TRUE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldClubba_Frost_Anim05, ANIM_WorldClubba_Frost_Anim02, 0, MSG_CH7_0150)
        Call(DisablePlayerInput, FALSE)
    EndIf
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Clubba_02) = {
    Loop(0)
        Wait(1)
        Call(GetSelfVar, 0, LVar0)
        IfNe(LVar0, 0)
            BreakLoop
        EndIf
        Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        Call(IsPlayerWithin, LVar3, LVar5, 80, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
    EndLoop
    IfNe(LVar0, 2)
        Call(DisablePlayerInput, TRUE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldClubba_Frost_Anim05, ANIM_WorldClubba_Frost_Anim02, 0, MSG_CH7_0151)
        Call(DisablePlayerInput, FALSE)
    EndIf
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Clubba_03) = {
    Loop(0)
        Wait(1)
        Call(GetSelfVar, 0, LVar0)
        IfNe(LVar0, 0)
            BreakLoop
        EndIf
        Call(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        Call(IsPlayerWithin, LVar3, LVar5, 80, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
    EndLoop
    Call(GetSelfVar, 0, LVar0)
    IfNe(LVar0, 2)
        Call(DisablePlayerInput, TRUE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldClubba_Frost_Anim05, ANIM_WorldClubba_Frost_Anim02, 0, MSG_CH7_0152)
        Call(DisablePlayerInput, FALSE)
    EndIf
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_PlayClubbaDefeatFX) = {
    Wait(20)
    Loop(4)
        Set(LVar0, LVarA)
        Set(LVar1, LVarB)
        Set(LVar2, LVarC)
        Call(RandInt, 50, LVar3)
        Call(RandInt, 50, LVar4)
        Add(LVar0, -15)
        Add(LVar0, LVar3)
        Add(LVar1, LVar4)
        PlayEffect(EFFECT_FIREWORK, 0, LVar0, LVar1, LVar2, Float(0.8), 0)
        Call(PlaySoundAt, SOUND_SEQ_BULLET_BILL_EXPLODE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        Wait(2)
        Set(LVar0, LVarA)
        Set(LVar1, LVarB)
        Set(LVar2, LVarC)
        Call(RandInt, 50, LVar3)
        Call(RandInt, 50, LVar4)
        Add(LVar0, -15)
        Add(LVar0, LVar3)
        Add(LVar1, LVar4)
        PlayEffect(EFFECT_FIREWORK, 0, LVar0, LVar1, LVar2, Float(0.8), 0)
        Call(PlaySoundAt, SOUND_SEQ_BULLET_BILL_EXPLODE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
        Wait(8)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Clubba_01) = {
    Thread
        Call(DisablePlayerInput, TRUE)
        Wait(50)
        Loop(10)
            Wait(2)
            Call(SetGroupVisibility, MODEL_g297, MODEL_GROUP_VISIBLE)
            Wait(2)
            Call(SetGroupVisibility, MODEL_g297, MODEL_GROUP_HIDDEN)
        EndLoop
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1176, COLLIDER_FLAGS_UPPER_MASK)
        Set(GB_PRA18_ClubbasDefeated, 1)
        Call(DisablePlayerInput, FALSE)
    EndThread
    Thread
        Wait(30)
        Set(LVarA, 270)
        Set(LVarB, 20)
        Set(LVarC, -75)
        Exec(N(EVS_PlayClubbaDefeatFX))
    EndThread
    Call(DoNpcDefeat)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Clubba_02) = {
    Thread
        Call(DisablePlayerInput, TRUE)
        Wait(50)
        Loop(10)
            Wait(2)
            Call(SetGroupVisibility, MODEL_g296, MODEL_GROUP_VISIBLE)
            Wait(2)
            Call(SetGroupVisibility, MODEL_g296, MODEL_GROUP_HIDDEN)
        EndLoop
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1175, COLLIDER_FLAGS_UPPER_MASK)
        Set(GB_PRA18_ClubbasDefeated, 2)
        Call(DisablePlayerInput, FALSE)
    EndThread
    Thread
        Wait(30)
        Set(LVarA, 480)
        Set(LVarB, 20)
        Set(LVarC, -75)
        Exec(N(EVS_PlayClubbaDefeatFX))
    EndThread
    Call(DoNpcDefeat)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Clubba_03) = {
    Thread
        Call(DisablePlayerInput, TRUE)
        Wait(50)
        Loop(10)
            Wait(2)
            Call(SetGroupVisibility, MODEL_g298, MODEL_GROUP_VISIBLE)
            Wait(2)
            Call(SetGroupVisibility, MODEL_g298, MODEL_GROUP_HIDDEN)
        EndLoop
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1174, COLLIDER_FLAGS_UPPER_MASK)
        BindTrigger(Ref(N(EVS_ExitDoors_pra_33_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
        Set(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        Call(DisablePlayerInput, FALSE)
    EndThread
    Thread
        Wait(30)
        Set(LVarA, 725)
        Set(LVarB, 20)
        Set(LVarC, -75)
        Exec(N(EVS_PlayClubbaDefeatFX))
    EndThread
    Call(DoNpcDefeat)
    Return
    End
};

EvtScript N(EVS_NpcInit_Clubba_01) = {
    IfGe(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    IfGe(GB_PRA18_ClubbasDefeated, 1)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Clubba_01)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Clubba_01)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Clubba_01)))
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_Clubba_01)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_USE_INSPECT_ICON, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Clubba_02) = {
    IfGe(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    IfGe(GB_PRA18_ClubbasDefeated, 2)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Clubba_02)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Clubba_02)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Clubba_02)))
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_Clubba_02)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_USE_INSPECT_ICON, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Clubba_03) = {
    IfGe(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Clubba_03)))
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Clubba_03)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Clubba_03)))
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_Clubba_03)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_USE_INSPECT_ICON, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Clubba_01_Aux) = {
    IfGe(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    IfGe(GB_PRA18_ClubbasDefeated, 1)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_USE_INSPECT_ICON, TRUE)
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_Clubba_01_Aux)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Clubba_02_Aux) = {
    IfGe(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    IfGe(GB_PRA18_ClubbasDefeated, 2)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_USE_INSPECT_ICON, TRUE)
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_Clubba_02_Aux)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Clubba_03_Aux) = {
    IfGe(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        Call(RemoveNpc, NPC_SELF)
        Return
    EndIf
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_USE_INSPECT_ICON, TRUE)
    Call(BindNpcHit, NPC_SELF, Ref(N(EVS_NpcHit_Clubba_03_Aux)))
    Return
    End
};

#if VERSION_PAL
#define CLUBBA_EXTRA_FLAGS (ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_TOUCH)
#else
#define CLUBBA_EXTRA_FLAGS (0)
#endif

NpcData N(NpcData_Clubba_01)[] = {
    {
        .id = NPC_Clubba_01,
        .pos = { 268.0f, 0.0f, 70.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Clubba_01),
        .settings = &N(NpcSettings_Clubba),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | CLUBBA_EXTRA_FLAGS,
        .drops = NO_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
    },
    {
        .id = NPC_Clubba_01_Aux,
        .pos = { 268.0f, 0.0f, 70.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Clubba_01_Aux),
        .settings = &N(NpcSettings_Clubba),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | CLUBBA_EXTRA_FLAGS,
        .drops = NO_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
    },
};

NpcData N(NpcData_Clubba_02)[] = {
    {
        .id = NPC_Clubba_02,
        .pos = { 490.0f, 0.0f, 70.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Clubba_02),
        .settings = &N(NpcSettings_Clubba),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | CLUBBA_EXTRA_FLAGS,
        .drops = NO_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
    },
    {
        .id = NPC_Clubba_02_Aux,
        .pos = { 490.0f, 0.0f, 70.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Clubba_02_Aux),
        .settings = &N(NpcSettings_Clubba),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | CLUBBA_EXTRA_FLAGS,
        .drops = NO_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
    },
};

NpcData N(NpcData_Clubba_03)[] = {
    {
        .id = NPC_Clubba_03,
        .pos = { 717.0f, 0.0f, 70.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Clubba_03),
        .settings = &N(NpcSettings_Clubba),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_SKIP_BATTLE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | CLUBBA_EXTRA_FLAGS,
        .drops = NO_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
    },
    {
        .id = NPC_Clubba_03_Aux,
        .pos = { 717.0f, 0.0f, 70.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Clubba_03_Aux),
        .settings = &N(NpcSettings_Clubba),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | CLUBBA_EXTRA_FLAGS,
        .drops = NO_DROPS,
        .animations = FROST_CLUBBA_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Clubba_01), BTL_PRA_FORMATION_0B, BTL_PRA_STAGE_02),
    NPC_GROUP(N(NpcData_Clubba_02), BTL_PRA_FORMATION_09, BTL_PRA_STAGE_02),
    NPC_GROUP(N(NpcData_Clubba_03), BTL_PRA_FORMATION_0C, BTL_PRA_STAGE_03),
    {}
};
