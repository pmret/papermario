#include "kmr_04.h"
#include "effects.h"

NpcSettings N(NpcSettings_JrTroopa) = {
    .height = 32,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

EvtScript N(EVS_NpcAuxAI_Goompa) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcAux_Goompa) = {
    Return
    End
};

#include "world/common/todo/CheckPartnerFlags1000.inc.c"

API_CALLABLE(N(GetPlayerHP)) {
    script->varTable[0] = get_player_data()->curHP;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcAI_Goompa) = {
    Label(1)
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH0_GOOMPA_JOINED_PARTY)
            Loop(0)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                Wait(1)
                IfLe(LVar0, 370)
                    BreakLoop
                EndIf
            EndLoop
            Call(DisablePlayerInput, TRUE)
            Call(func_802CF56C, 0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Add(LVar0, 30)
            Call(SetNpcSpeed, NPC_PARTNER, Float(2.0 / DT))
            Call(NpcMoveTo, LVar0, LVar1, LVar2, 0)
            Wait(5 * DT)
            Call(DisablePartnerAI, 0)
            Call(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_00A9)
            Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
            Call(EnablePartnerAI)
            Wait(10 * DT)
            Call(DisablePlayerInput, FALSE)
            Set(GB_StoryProgress, STORY_CH0_LOOKING_FOR_HAMMER)
        CaseEq(STORY_CH0_FOUND_HAMMER)
            IfEq(AB_KMR_0, 0)
                Label(10)
                Wait(1)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                IfLt(LVar0, 360)
                    Goto(10)
                EndIf
                IfGt(LVar0, 400)
                    Goto(10)
                EndIf
                IfLt(LVar2, -36)
                    Goto(10)
                EndIf
                IfGt(LVar2, 85)
                    Goto(10)
                EndIf
                Call(DisablePlayerInput, TRUE)
                Call(N(CheckPartnerFlags1000))
                Call(DisablePartnerAI, 0)
                Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
                Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Walk)
                Call(SetNpcSpeed, NPC_PARTNER, Float(3.0))
                Call(NpcMoveTo, NPC_PARTNER, 420, 6, 0)
                Thread
                    Wait(3 * DT)
                    Call(PlayerFaceNpc, NPC_PARTNER, 3)
                EndThread
                Call(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_00AC)
                Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
                Wait(10 * DT)
                Thread
                    Call(SetPlayerSpeed, Float(3.0 / DT))
                    Call(PlayerMoveTo, 395, 0, 0)
                    Call(InterpPlayerYaw, 90, 0)
                EndThread
                Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING, TRUE)
                Call(SetNpcSpeed, NPC_PARTNER, Float(6.0))
                Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Run)
                Call(NpcMoveTo, NPC_PARTNER, 582, 6, 0)
                Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Idle)
                Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_FLYING, FALSE)
                Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_GOOMPA_ATTACKED, SOUND_SPACE_DEFAULT)
                Call(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_00AD)
                Wait(10 * DT)
                Thread
                    Set(LVar0, 0)
                    Call(SetNpcRotationPivot, NPC_PARTNER, 10)
                    Loop(60 * DT)
                        Add(LVar0, 53)
                        Call(SetNpcRotation, NPC_PARTNER, 0, 0, LVar0)
                        Call(PlayerFaceNpc, NPC_PARTNER, FALSE)
                        Wait(1)
                    EndLoop
                    Call(SetNpcRotationPivot, NPC_PARTNER, 0)
                    Call(SetNpcRotation, NPC_PARTNER, 0, 0, 0)
                EndThread
                Thread
                    Call(ShakeCam, CAM_DEFAULT, 0, 15 * DT, Float(1.0))
                EndThread
                PlayEffect(EFFECT_DAMAGE_STARS, FX_DAMAGE_STARS_1, 495, 15, 9, 460, 15, 9, 6)
                Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Injured)
                Call(NpcMoveTo, NPC_PARTNER, 250, 6, 60 * DT)
                Call(SetNpcAnimation, NPC_PARTNER, ANIM_Goompa_Injured)
                Call(SetNpcRotation, NPC_PARTNER, 0, 0, 0)
                Thread
                    Loop(20 * DT)
                        Call(SetNpcPos, NPC_PARTNER, 250, 0, 6)
                        Wait(3)
                        Call(SetNpcPos, NPC_PARTNER, 250, 0, 0)
                        Wait(3)
                    EndLoop
                EndThread
                Set(AB_KMR_0, 1)
            EndIf
    EndSwitch
    Wait(1)
    Goto(1)
    Return
    End
};

EvtScript N(EVS_NpcInteract_Goompa) = {
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Goompa) = {
    Return
    End
};

EvtScript N(EVS_NpcIdle_JrTroopa) = {
    Call(func_800445D4, LVar0)
    Switch(LVar0)
        CaseEq(100)
            Label(0)
            Switch(AB_KMR_0)
                CaseEq(1)
                    Exec(N(EVS_SetJrTroopaMusic))
                    Thread
                        Wait(20 * DT)
                        Call(GetPlayerPos, LVar0, LVar1, LVar2)
                        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                        Call(SetPanTarget, CAM_DEFAULT, 430, LVar1, LVar2)
                        Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
                        Call(SetCamPitch, CAM_DEFAULT, Float(17.5), Float(-7.5))
                        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
                        Call(PanToTarget, CAM_DEFAULT, 0, 1)
                        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                    EndThread
                    Call(SetNpcPos, NPC_JrTroopa, 630, 0, 0)
                    Call(EnableNpcShadow, NPC_SELF, TRUE)
                    Wait(1)
                    Call(PlayerFaceNpc, NPC_JrTroopa, 3)
                    Call(SetNpcSpeed, NPC_JrTroopa, Float(3.0 / DT))
                    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_Run)
                    Call(NpcMoveTo, NPC_JrTroopa, 465, 0, 0)
                    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_JrTroopa_PointIdle)
                    Call(PlayerFaceNpc, NPC_JrTroopa, 3)
                    Call(SpeakToPlayer, NPC_JrTroopa, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointIdle, 0, MSG_CH0_00AE)
                    Wait(10 * DT)
                    Thread
                        Call(GetPlayerPos, LVar0, LVar1, LVar2)
                        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
                        Call(SetPanTarget, CAM_DEFAULT, 430, LVar1, LVar2)
                        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
                        Call(PanToTarget, CAM_DEFAULT, 0, 1)
                        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
                        Call(PanToTarget, CAM_DEFAULT, 0, 0)
                    EndThread
                    Call(StartBossBattle, SONG_JR_TROOPA_BATTLE)
            EndSwitch
            Wait(1)
            Goto(0)
        CaseOrEq(101)
        CaseOrEq(102)
        CaseOrEq(3)
        CaseOrEq(103)
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcDefeat_JrTroopa) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
            Call(SetPanTarget, CAM_DEFAULT, 400, LVar1, LVar2)
            Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
            Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.5))
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(WaitForCam, CAM_DEFAULT, Float(1.0))
            Call(PlayerFaceNpc, NPC_SELF, FALSE)
            Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Hurt)
            Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_Hurt, ANIM_JrTroopa_Hurt, 0, MSG_CH0_00B5)
            Call(SetNpcSpeed, NPC_SELF, Float(6.0 / DT))
            Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Run)
            Call(NpcMoveTo, NPC_SELF, 564, 10, 0)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Wait(60 * DT)
            Call(SetNpcPos, NPC_SELF, 564, 0, 10)
            Call(NpcMoveTo, NPC_SELF, 435, 10, 0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointIdle, 0, MSG_CH0_00B6)
            Call(NpcMoveTo, NPC_SELF, 564, 10, 0)
            Call(SetNpcAnimation, NPC_SELF, ANIM_JrTroopa_Idle)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Thread
#if VERSION_PAL
                Call(ResetCam, CAM_DEFAULT, Float(4 * DT))
#else
                Call(ResetCam, CAM_DEFAULT, 4)
#endif
            EndThread
            Exec(N(EVS_SetNormalMusic))
            Set(AB_KMR_0, 0)
            Set(GB_StoryProgress, STORY_CH0_DEFEATED_JR_TROOPA)
            Call(DisablePlayerInput, FALSE)
    EndSwitch
    Return
    End
};

NpcSettings N(NpcSettings_Goompa) = {
    .defaultAnim = ANIM_Goompa_Idle,
    .height = 24,
    .radius = 24,
    .otherAI = &N(EVS_NpcAuxAI_Goompa),
    .onInteract = &N(EVS_NpcInteract_Goompa),
    .ai = &N(EVS_NpcAI_Goompa),
    .aux = &N(EVS_NpcAux_Goompa),
    .onDefeat = &N(EVS_NpcDefeat_Goompa),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION,
};

EvtScript N(EVS_NpcInit_JrTroopa) = {
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_JrTroopa)))
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_JrTroopa)))
    Return
    End
};

NpcData N(NpcData_JrTroopa) = {
    .id = NPC_JrTroopa,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_JrTroopa),
    .settings = &N(NpcSettings_JrTroopa),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
    .drops = NO_DROPS,
    .animations = {
        .idle   = ANIM_JrTroopa_Idle,
        .walk   = ANIM_JrTroopa_Walk,
        .run    = ANIM_JrTroopa_Walk,
        .chase  = ANIM_JrTroopa_Walk,
        .anim_4 = ANIM_JrTroopa_Idle,
        .anim_5 = ANIM_JrTroopa_Idle,
        .death  = ANIM_JrTroopa_Idle,
        .hit    = ANIM_JrTroopa_Idle,
        .anim_8 = ANIM_JrTroopa_Idle,
        .anim_9 = ANIM_JrTroopa_Idle,
        .anim_A = ANIM_JrTroopa_Idle,
        .anim_B = ANIM_JrTroopa_Idle,
        .anim_C = ANIM_JrTroopa_Idle,
        .anim_D = ANIM_JrTroopa_Idle,
        .anim_E = ANIM_JrTroopa_Idle,
        .anim_F = ANIM_JrTroopa_Idle,
    },
};

NpcData N(NpcData_GoombaFamily) = {
    .id = NPC_Goompa,
    .pos = { -58.0f, 0.0f, 130.0f },
    .yaw = 0,
    .settings = &N(NpcSettings_Goompa),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
    .animations = {
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_JrTroopa), BTL_KMR_3_FORMATION_02),
    NPC_GROUP(N(NpcData_GoombaFamily)),
    {}
};
