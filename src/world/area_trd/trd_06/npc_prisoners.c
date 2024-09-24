#include "trd_06.h"
#include "sprite.h"
#include "sprite/player.h"

extern EvtScript N(EVS_PushSong);
extern EvtScript N(EVS_PopSong);
API_CALLABLE(N(LoadPartyImage));

#include "world/common/util/ChangeNpcToPartner.inc.c"

NpcSettings N(NpcSettings_Bobomb) = {
    .height = 23,
    .radius = 20,
    .level = ACTOR_LEVEL_BOB_OMB,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

NpcSettings N(NpcSettings_KoopaTroopa) = {
    .height = 34,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};

EvtScript N(EVS_Bombette_DemonstrateAbility) = {
    Call(SetPanTarget, CAM_DEFAULT, 96, 0, 129)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.6 / DT))
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Thread
        Call(SetNpcAnimation, NPC_PARTNER, ANIM_WorldBombette_Walk)
        Call(SetNpcSpeed, NPC_PARTNER, Float(3.0 / DT))
        Call(NpcMoveTo, NPC_PARTNER, 124, 129, 0)
        Call(GetAngleToPlayer, NPC_PARTNER, LVar0)
        Call(InterpNpcYaw, NPC_PARTNER, LVar0, 5)
    EndThread
    Wait(30 * DT)
    Call(SetPlayerSpeed, Float(3.0 / DT))
    Call(PlayerMoveTo, 96, 129, 0)
    Call(GetAngleToNPC, NPC_PARTNER, LVar0)
    Call(InterpPlayerYaw, LVar0, 5)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00E1)
    Call(DisablePlayerInput, FALSE)
    Call(EnablePartnerAI)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bombette) = {
    Thread
        Call(AdjustCam, CAM_DEFAULT, Float(5.0 / DT), 0, Float(300.0), Float(18.0), Float(-7.0))
    EndThread
    Call(GetAngleToPlayer, NPC_SELF, LVar0)
    IfLt(LVar0, 180)
        Set(LVar1, 27)
    Else
        Set(LVar1, -27)
    EndIf
    Call(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
    Call(GetPlayerPos, LVarA, LVarB, LVarC)
    Sub(LVarA, LVar2)
    IfLt(LVarA, 0)
        Mul(LVarA, -1)
    EndIf
    IfLt(LVarA, 20)
        Add(LVar2, LVar1)
        Call(SetPlayerSpeed, Float(3.0 / DT))
        Call(PlayerMoveTo, LVar2, LVar4, 0)
        Call(PlayerFaceNpc, NPC_Bombette, 3)
    EndIf
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    IfEq(GF_TRD06_Met_Bombette, FALSE)
        Set(GF_TRD06_Met_Bombette, TRUE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00DA)
        Wait(10 * DT)
        Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
        Call(EndSpeech, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Call(ShowChoice, MSG_Choice_000D)
        IfNe(LVar0, 0)
            Call(ContinueSpeech, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00DB)
        EndIf
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00DC)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Call(ShowChoice, MSG_Choice_000D)
        IfNe(LVar0, 0)
            Call(ContinueSpeech, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00DD)
        EndIf
    EndIf
    IfEq(LVar0, 0)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(SetNpcJumpscale, NPC_SELF, Float(0.8))
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 15 * DT)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
        Call(ContinueSpeech, NPC_SELF, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00DE)
        Call(N(ChangeNpcToPartner), NPC_Bombette, PARTNER_BOMBETTE)
        Set(GB_StoryProgress, STORY_CH1_BOMBETTE_JOINED_PARTY)
        Call(N(LoadPartyImage))
        Exec(N(EVS_PushSong))
        Wait(15 * DT)
        Call(ShowMessageAtScreenPos, MSG_Menus_018B, 160, 40)
        Exec(N(EVS_PopSong))
        Wait(10 * DT)
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00DF)
        Wait(1)
        Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
        Wait(15 * DT)
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Wait(25 * DT)
        Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, -45, 30, EMOTER_NPC, 0, 0, 0, 0)
        Wait(40 * DT)
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_WorldBombette_Talk, ANIM_WorldBombette_Idle, 0, MSG_CH1_00E0)
        ExecWait(N(EVS_Bombette_DemonstrateAbility))
    EndIf
    Call(ResetCam, CAM_DEFAULT, Float(5.0 / DT))
    Return
    End
};

EvtScript N(EVS_NpcInit_Bombette) = {
    IfGe(GB_StoryProgress, STORY_CH1_BOMBETTE_JOINED_PARTY)
        Call(RemoveNpc, NPC_SELF)
    Else
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bombette)))
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcIdle_KoopaTroopa) = {
    Label(0)
    Call(GetSelfVar, 0, LVar0)
    Wait(1)
    IfEq(LVar0, 0)
        Goto(0)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_METAL_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 90, 15, EASING_COS_IN_OUT)
    Label(10)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_o93, LVar0, 0, -1, 0)
    Call(RotateModel, MODEL_o94, LVar0, 0, 1, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(SetNpcPos, NPC_Jailer_KoopaTroopa, -350, 0, 0)
    Call(SetNpcPos, NPC_Jailer_Bobomb_01, -370, 0, 0)
    Call(SetNpcPos, NPC_Jailer_Bobomb_02, -390, 0, 0)
    Call(SetNpcSpeed, NPC_Jailer_KoopaTroopa, Float(4.0 / DT))
    Call(SetNpcSpeed, NPC_Jailer_Bobomb_01, Float(4.0 / DT))
    Call(SetNpcSpeed, NPC_Jailer_Bobomb_02, Float(4.0 / DT))
    Call(SetNpcAnimation, NPC_Jailer_KoopaTroopa, ANIM_KoopaTroopa_Run)
    Call(SetNpcAnimation, NPC_Jailer_Bobomb_01, ANIM_Bobomb_Run)
    Call(SetNpcAnimation, NPC_Jailer_Bobomb_02, ANIM_Bobomb_Run)
    Call(SetNpcFlagBits, NPC_Jailer_KoopaTroopa, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Jailer_Bobomb_01, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_Jailer_Bobomb_02, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Thread
        Call(NpcMoveTo, NPC_Jailer_KoopaTroopa, -237, 0, 0)
    EndThread
    Thread
        Wait(10)
        Call(NpcMoveTo, NPC_Jailer_Bobomb_01, -274, 25, 0)
    EndThread
    Wait(15)
    Call(NpcMoveTo, NPC_Jailer_Bobomb_02, -266, -15, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, -260, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, -260, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(SetNpcAnimation, NPC_Jailer_Bobomb_01, ANIM_Bobomb_Idle)
    Call(SetNpcAnimation, NPC_Jailer_Bobomb_02, ANIM_Bobomb_Idle)
    Call(SpeakToPlayer, NPC_Jailer_KoopaTroopa, ANIM_KoopaTroopa_Run, ANIM_KoopaTroopa_Idle, 0, MSG_CH1_00F0)
    Call(SetNpcAnimation, NPC_Jailer_Bobomb_01, ANIM_Bobomb_Run)
    Call(SetNpcAnimation, NPC_Jailer_Bobomb_02, ANIM_Bobomb_Run)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Thread
        Wait(60)
        Call(MakeLerp, 90, 0, 15, EASING_COS_IN_OUT)
        Label(20)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o93, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_o94, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
        Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_METAL_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EndThread
    Thread
        Call(NpcMoveTo, NPC_Jailer_KoopaTroopa, -233, 147, 0)
        Call(NpcMoveTo, NPC_Jailer_KoopaTroopa, -167, 218, 0)
    EndThread
    Thread
        Call(NpcMoveTo, NPC_Jailer_Bobomb_01, -254, 144, 0)
        Call(NpcMoveTo, NPC_Jailer_Bobomb_01, -203, 222, 0)
    EndThread
    Wait(15 * DT)
    Call(NpcMoveTo, NPC_Jailer_Bobomb_02, -265, 0, 0)
    Call(NpcMoveTo, NPC_Jailer_Bobomb_02, -186, 175, 0)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcJumpscale, NPC_Jailer_KoopaTroopa, Float(1.0))
    Call(GetNpcPos, NPC_Jailer_KoopaTroopa, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Jailer_KoopaTroopa, LVar0, LVar1, LVar2, 10 * DT)
    Call(SetNpcAnimation, NPC_Jailer_Bobomb_01, ANIM_Bobomb_Idle)
    Call(SetNpcAnimation, NPC_Jailer_Bobomb_02, ANIM_Bobomb_Idle)
    Call(SpeakToPlayer, NPC_Jailer_KoopaTroopa, ANIM_KoopaTroopa_Run, ANIM_KoopaTroopa_Idle, 0, MSG_CH1_00F1)
    Call(SetNpcAnimation, NPC_Jailer_Bobomb_01, ANIM_Bobomb_Run)
    Call(SetNpcAnimation, NPC_Jailer_Bobomb_02, ANIM_Bobomb_Run)
    Call(DisablePlayerInput, FALSE)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_KoopaTroopa) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(GB_StoryProgress, STORY_CH1_DEFEATED_DUNGEON_GUARDS)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
#if VERSION_JP
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(DisablePlayerInput, TRUE)
            Call(SetPlayerAnimation, ANIM_Mario1_Run)
            Call(PlayerMoveTo, 82, 264, 20)
            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
            Call(SpeakToPlayer, NPC_Jailer_KoopaTroopa, ANIM_KoopaTroopa_Run, ANIM_KoopaTroopa_Idle, 0, MSG_CH1_013A)
            Thread
                Label(10)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Wait(1)
                IfLt(LVar2, 200)
                    Goto(10)
                EndIf
                IfGt(LVar0, -120)
                    Goto(10)
                EndIf
                Call(DisablePlayerInput, TRUE)
                Call(SpeakToPlayer, NPC_Jailer_KoopaTroopa, ANIM_KoopaTroopa_Run, ANIM_KoopaTroopa_Idle, 0, MSG_CH1_013B)
                Call(DisablePlayerInput, FALSE)
                Call(StartBossBattle, SONG_SPECIAL_BATTLE)
            EndThread
            Call(DisablePlayerInput, FALSE)
#endif
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaTroopa) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_KoopaTroopa)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_KoopaTroopa)))
    IfGe(GB_StoryProgress, STORY_CH1_DEFEATED_DUNGEON_GUARDS)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb_Jailer) = {
    IfGe(GB_StoryProgress, STORY_CH1_DEFEATED_DUNGEON_GUARDS)
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bobomb_01) = {
    IfEq(GF_TRD06_BombedWall, FALSE)
        IfEq(AF_TRD_MetPrisoner1, FALSE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_00E4)
            Set(AF_TRD_MetPrisoner1, TRUE)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_00E5)
            Set(AF_TRD_MetPrisoner1, FALSE)
        EndIf
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Red_Talk, ANIM_WorldBobomb_Red_Idle, 0, MSG_CH1_00E6)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bobomb_02) = {
    IfEq(GF_TRD06_BombedWall, FALSE)
        IfEq(AF_TRD_MetPrisoner2, FALSE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_00E7)
            Set(AF_TRD_MetPrisoner2, TRUE)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_00E8)
            Set(AF_TRD_MetPrisoner2, FALSE)
        EndIf
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Blue_Talk, ANIM_WorldBobomb_Blue_Idle, 0, MSG_CH1_00E9)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bobomb_03) = {
    IfEq(GF_TRD06_BombedWall, FALSE)
        IfEq(AF_TRD_MetPrisoner3, FALSE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_00EA)
            Set(AF_TRD_MetPrisoner3, TRUE)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_00EB)
            Set(AF_TRD_MetPrisoner3, FALSE)
        EndIf
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_00EC)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Bobomb_04) = {
    IfEq(GF_TRD06_BombedWall, FALSE)
        IfEq(AF_TRD_MetPrisoner4, FALSE)
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_00ED)
            Set(AF_TRD_MetPrisoner4, TRUE)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_00EE)
            Set(AF_TRD_MetPrisoner4, FALSE)
        EndIf
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldBobomb_Green_Talk, ANIM_WorldBobomb_Green_Idle, 0, MSG_CH1_00EF)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bobomb_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb_02) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bobomb_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb_03) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bobomb_03)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb_04) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Bobomb_04)))
    Return
    End
};

NpcData N(NpcData_Bombette) = {
    .id = NPC_Bombette,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Bombette),
    .settings = &N(NpcSettings_Bobomb),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_WorldBombette_Idle,
        .walk   = ANIM_WorldBombette_Walk,
        .run    = ANIM_WorldBombette_Walk,
        .chase  = ANIM_WorldBombette_Walk,
        .anim_4 = ANIM_WorldBombette_Walk,
        .anim_5 = ANIM_WorldBombette_Walk,
        .death  = ANIM_WorldBombette_Still,
        .hit    = ANIM_WorldBombette_Still,
        .anim_8 = ANIM_WorldBombette_Still,
        .anim_9 = ANIM_WorldBombette_Still,
        .anim_A = ANIM_WorldBombette_Still,
        .anim_B = ANIM_WorldBombette_Still,
        .anim_C = ANIM_WorldBombette_Still,
        .anim_D = ANIM_WorldBombette_Still,
        .anim_E = ANIM_WorldBombette_Still,
        .anim_F = ANIM_WorldBombette_Still,
    },
    .tattle = MSG_NpcTattle_TRD_Bombette,
};

NpcData N(NpcData_Jailers)[] = {
    {
        .id = NPC_Jailer_KoopaTroopa,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoopaTroopa),
        .settings = &N(NpcSettings_KoopaTroopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_MUSHROOM, 5, 0 },
                { ITEM_HONEY_SYRUP, 5, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
        },
        .animations = {
            .idle   = ANIM_KoopaTroopa_Idle,
            .walk   = ANIM_KoopaTroopa_Walk,
            .run    = ANIM_KoopaTroopa_Run,
            .chase  = ANIM_KoopaTroopa_Run,
            .anim_4 = ANIM_KoopaTroopa_Idle,
            .anim_5 = ANIM_KoopaTroopa_Idle,
            .death  = ANIM_KoopaTroopa_Hurt,
            .hit    = ANIM_KoopaTroopa_Hurt,
            .anim_8 = ANIM_KoopaTroopa_ShellEnter,
            .anim_9 = ANIM_KoopaTroopa_ShellSpin,
            .anim_A = ANIM_KoopaTroopa_ShellExit,
            .anim_B = ANIM_KoopaTroopa_Run,
            .anim_C = ANIM_KoopaTroopa_Run,
            .anim_D = ANIM_KoopaTroopa_Run,
            .anim_E = ANIM_KoopaTroopa_Run,
            .anim_F = ANIM_KoopaTroopa_Run,
        },
    },
    {
        .id = NPC_Jailer_Bobomb_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bobomb_Jailer),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Bobomb_Idle,
            .walk   = ANIM_Bobomb_Walk,
            .run    = ANIM_Bobomb_Run,
            .chase  = ANIM_Bobomb_Run,
            .anim_4 = ANIM_Bobomb_Idle,
            .anim_5 = ANIM_Bobomb_Idle,
            .death  = ANIM_Bobomb_Hurt,
            .hit    = ANIM_Bobomb_Hurt,
            .anim_8 = ANIM_Bobomb_Run,
            .anim_9 = ANIM_Bobomb_Run,
            .anim_A = ANIM_Bobomb_Run,
            .anim_B = ANIM_Bobomb_Run,
            .anim_C = ANIM_Bobomb_Run,
            .anim_D = ANIM_Bobomb_Run,
            .anim_E = ANIM_Bobomb_Run,
            .anim_F = ANIM_Bobomb_Run,
        },
    },
    {
        .id = NPC_Jailer_Bobomb_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Bobomb_Jailer),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = {
            .idle   = ANIM_Bobomb_Idle,
            .walk   = ANIM_Bobomb_Walk,
            .run    = ANIM_Bobomb_Run,
            .chase  = ANIM_Bobomb_Run,
            .anim_4 = ANIM_Bobomb_Idle,
            .anim_5 = ANIM_Bobomb_Idle,
            .death  = ANIM_Bobomb_Hurt,
            .hit    = ANIM_Bobomb_Hurt,
            .anim_8 = ANIM_Bobomb_Run,
            .anim_9 = ANIM_Bobomb_Run,
            .anim_A = ANIM_Bobomb_Run,
            .anim_B = ANIM_Bobomb_Run,
            .anim_C = ANIM_Bobomb_Run,
            .anim_D = ANIM_Bobomb_Run,
            .anim_E = ANIM_Bobomb_Run,
            .anim_F = ANIM_Bobomb_Run,
        },
    },
};

NpcData N(NpcData_Inmates)[] = {
    {
        .id = NPC_Bobomb_01,
        .pos = { 25.0f, 0.0f, 127.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Bobomb_01),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_HONEY_SYRUP, 5, 0 },
                { ITEM_FIRE_FLOWER, 5, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 1,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Red_Idle,
            .walk   = ANIM_WorldBobomb_Red_Walk,
            .run    = ANIM_WorldBobomb_Red_Run,
            .chase  = ANIM_WorldBobomb_Red_Run,
            .anim_4 = ANIM_WorldBobomb_Red_Idle,
            .anim_5 = ANIM_WorldBobomb_Red_Idle,
            .death  = ANIM_WorldBobomb_Red_Still,
            .hit    = ANIM_WorldBobomb_Red_Still,
            .anim_8 = ANIM_WorldBobomb_Red_Still,
            .anim_9 = ANIM_WorldBobomb_Red_Still,
            .anim_A = ANIM_WorldBobomb_Red_Still,
            .anim_B = ANIM_WorldBobomb_Red_Still,
            .anim_C = ANIM_WorldBobomb_Red_Still,
            .anim_D = ANIM_WorldBobomb_Red_Still,
            .anim_E = ANIM_WorldBobomb_Red_Still,
            .anim_F = ANIM_WorldBobomb_Red_Still,
        },
        .tattle = MSG_NpcTattle_TRD_BobombA,
    },
    {
        .id = NPC_Bobomb_02,
        .pos = { -30.0f, 0.0f, 130.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Bobomb_02),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_HONEY_SYRUP, 5, 0 },
                { ITEM_FIRE_FLOWER, 5, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 1,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Blue_Idle,
            .walk   = ANIM_WorldBobomb_Blue_Walk,
            .run    = ANIM_WorldBobomb_Blue_Run,
            .chase  = ANIM_WorldBobomb_Blue_Run,
            .anim_4 = ANIM_WorldBobomb_Blue_Idle,
            .anim_5 = ANIM_WorldBobomb_Blue_Idle,
            .death  = ANIM_WorldBobomb_Blue_Still,
            .hit    = ANIM_WorldBobomb_Blue_Still,
            .anim_8 = ANIM_WorldBobomb_Blue_Still,
            .anim_9 = ANIM_WorldBobomb_Blue_Still,
            .anim_A = ANIM_WorldBobomb_Blue_Still,
            .anim_B = ANIM_WorldBobomb_Blue_Still,
            .anim_C = ANIM_WorldBobomb_Blue_Still,
            .anim_D = ANIM_WorldBobomb_Blue_Still,
            .anim_E = ANIM_WorldBobomb_Blue_Still,
            .anim_F = ANIM_WorldBobomb_Blue_Still,
        },
        .tattle = MSG_NpcTattle_TRD_BobombB,
    },
    {
        .id = NPC_Bobomb_03,
        .pos = { -140.0f, 0.0f, -90.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Bobomb_03),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_HONEY_SYRUP, 5, 0 },
                { ITEM_FIRE_FLOWER, 5, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 1,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Green_Idle,
            .walk   = ANIM_WorldBobomb_Green_Walk,
            .run    = ANIM_WorldBobomb_Green_Run,
            .chase  = ANIM_WorldBobomb_Green_Run,
            .anim_4 = ANIM_WorldBobomb_Green_Idle,
            .anim_5 = ANIM_WorldBobomb_Green_Idle,
            .death  = ANIM_WorldBobomb_Green_Still,
            .hit    = ANIM_WorldBobomb_Green_Still,
            .anim_8 = ANIM_WorldBobomb_Green_Still,
            .anim_9 = ANIM_WorldBobomb_Green_Still,
            .anim_A = ANIM_WorldBobomb_Green_Still,
            .anim_B = ANIM_WorldBobomb_Green_Still,
            .anim_C = ANIM_WorldBobomb_Green_Still,
            .anim_D = ANIM_WorldBobomb_Green_Still,
            .anim_E = ANIM_WorldBobomb_Green_Still,
            .anim_F = ANIM_WorldBobomb_Green_Still,
        },
        .tattle = MSG_NpcTattle_TRD_BobombC,
    },
    {
        .id = NPC_Bobomb_04,
        .pos = { -75.0f, 0.0f, -80.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Bobomb_04),
        .settings = &N(NpcSettings_Bobomb),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_FLYING,
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .itemDropChance = 5,
            .itemDrops = {
                { ITEM_HONEY_SYRUP, 5, 0 },
                { ITEM_FIRE_FLOWER, 5, 0 },
            },
            .heartDrops  = STANDARD_HEART_DROPS(2),
            .flowerDrops = STANDARD_FLOWER_DROPS(2),
            .minCoinBonus = 0,
            .maxCoinBonus = 1,
        },
        .animations = {
            .idle   = ANIM_WorldBobomb_Green_Idle,
            .walk   = ANIM_WorldBobomb_Green_Walk,
            .run    = ANIM_WorldBobomb_Green_Run,
            .chase  = ANIM_WorldBobomb_Green_Run,
            .anim_4 = ANIM_WorldBobomb_Green_Idle,
            .anim_5 = ANIM_WorldBobomb_Green_Idle,
            .death  = ANIM_WorldBobomb_Green_Still,
            .hit    = ANIM_WorldBobomb_Green_Still,
            .anim_8 = ANIM_WorldBobomb_Green_Still,
            .anim_9 = ANIM_WorldBobomb_Green_Still,
            .anim_A = ANIM_WorldBobomb_Green_Still,
            .anim_B = ANIM_WorldBobomb_Green_Still,
            .anim_C = ANIM_WorldBobomb_Green_Still,
            .anim_D = ANIM_WorldBobomb_Green_Still,
            .anim_E = ANIM_WorldBobomb_Green_Still,
            .anim_F = ANIM_WorldBobomb_Green_Still,
        },
        .tattle = MSG_NpcTattle_TRD_BobombD,
    },
};

NpcGroupList N(NpcGroup_Prisoners) = {
    NPC_GROUP(N(NpcData_Bombette)),
    NPC_GROUP(N(NpcData_Inmates)),
    NPC_GROUP(N(NpcData_Jailers), BTL_TRD_1_FORMATION_04, BTL_TRD_1_STAGE_0B),
    {}
};
