#include "kpa_81.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Stationary.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,choice);
#include "world/common/complete/NormalItemChoice.inc.c"

EvtScript N(EVS_EnsurePartnerNeutral) = {
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        IfEq(LVar0, PARTNER_BOMBETTE)
            Loop(0)
                Call(GetPartnerInUse, LVar0)
                Wait(1)
                IfEq(LVar0, PARTNER_NONE)
                    BreakLoop
                EndIf
            EndLoop
        Else
            Call(InterruptUsePartner)
            Wait(20)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcIdle_Door) = {
    IfEq(GB_KPA81_BowserDoorState, 2)
        Return
    EndIf
    IfEq(GB_KPA81_BowserDoorState, 1)
        Set(GB_KPA81_BowserDoorState, 2)
        Call(DisablePlayerInput, TRUE)
        Wait(35)
        Call(SetCamType, CAM_DEFAULT, 6, FALSE)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, 109, 0, 202)
        Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
        Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-10.0))
        Call(SetCamDistance, CAM_DEFAULT, Float(500.0))
        Call(SetCamPosA, CAM_DEFAULT, Float(133.0), Float(100.0))
        Call(SetCamPosB, CAM_DEFAULT, Float(216.0), Float(230.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Thread
            Call(SetMusicTrack, 0, SONG_FINAL_BOWSER_BATTLE, 1, 8)
            Wait(150 * DT)
            Call(FadeOutMusic, 0, 250)
            Wait(15 * DT)
            Exec(N(EVS_SetupMusic))
        EndThread
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0008)
        Exec(N(EVS_SetupMusic))
        Call(ResetCam, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    Wait(10)
    Call(DisablePlayerInput, TRUE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerSpeed, Float(2.0 / DT))
    Call(PlayerMoveTo, -115, LVar2, 0)
    Call(SetCamType, CAM_DEFAULT, 6, FALSE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, 109, 0, 202)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-10.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(500.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(133.0), Float(100.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(216.0), Float(230.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Call(SetMusicTrack, 0, SONG_FINAL_BOWSER_BATTLE, 1, 8)
        Wait(150 * DT)
        Call(FadeOutMusic, 0, 250)
        Wait(15 * DT)
        Exec(N(EVS_SetupMusic))
    EndThread
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0000)
    Call(ShowChoice, MSG_Choice_0013)
    IfEq(LVar0, 0)
        Call(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0003)
        Call(ResetCam, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(DisablePlayerInput, FALSE)
        Label(100)
        Wait(1)
        Call(IsPlayerWithin, 120, 150, 30, LVar0)
        IfEq(LVar0, 1)
            Goto(3)
        EndIf
        Add(LVar1, 1)
        IfLe(LVar1, 300 * DT)
            Goto(100)
        EndIf
        Call(DisablePlayerInput, TRUE)
        ExecWait(N(EVS_EnsurePartnerNeutral))
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0004)
        Call(DisablePlayerInput, FALSE)
        Call(AwaitPlayerApproach, 120, 150, 30)
        Goto(2)
    Else
        Call(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0002)
        Call(ResetCam, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(DisablePlayerInput, FALSE)
        Call(AwaitPlayerApproach, 120, 150, 30)
    EndIf
    Label(2)
    Call(DisablePlayerInput, TRUE)
    ExecWait(N(EVS_EnsurePartnerNeutral))
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0001)
    Call(ShowChoice, MSG_Choice_0013)
    IfEq(LVar0, 0)
        Goto(4)
    Else
        Call(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0002)
        Call(DisablePlayerInput, FALSE)
        Call(AwaitPlayerLeave, 120, 150, 30)
        Call(AwaitPlayerApproach, 120, 150, 30)
        Goto(2)
    EndIf
    Label(3)
    Call(DisablePlayerInput, TRUE)
    ExecWait(N(EVS_EnsurePartnerNeutral))
    Thread
        Call(DisablePartnerAI, 0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 10)
        Call(EnablePartnerAI)
    EndThread
    Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0005)
    Goto(5)
    Label(4)
    ExecWait(N(EVS_EnsurePartnerNeutral))
    Thread
        Call(DisablePartnerAI, 0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 10)
        Call(EnablePartnerAI)
    EndThread
    Call(ContinueSpeech, NPC_SELF, ANIM_Toad_Red_Idle, ANIM_Toad_Red_Idle, 0, MSG_CH8_0006)
    Label(5)
    Call(SetCamType, CAM_DEFAULT, 6, FALSE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, 163, -71, 108)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(SetCamPitch, CAM_DEFAULT, Float(20.0), Float(-16.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(500.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(133.0), Float(100.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(216.0), Float(230.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(EnableModel, MODEL_o166, TRUE)
    Thread
        Wait(25)
        Call(EnableModel, MODEL_o165, FALSE)
    EndThread
    Call(PlaySoundAtCollider, COLLIDER_deilitts, SOUND_OPEN_TRAPDOOR, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 90, 30, EASING_COS_SLOW_OVERSHOOT)
    Label(10)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_o165, LVar0, 0, 0, -1)
    Call(RotateModel, MODEL_o167, LVar0, 0, 0, 1)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(SetPlayerAnimation, ANIM_MarioW2_Flail)
    Wait(30 * DT)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetPlayerAnimation, ANIM_MarioW2_PanicStill)
    Wait(10 * DT)
    Call(PlaySoundAtPlayer, SOUND_PLAYER_LONG_FALL, SOUND_SPACE_DEFAULT)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Loop(65)
            Sub(LVar1, 16)
            Call(SetPlayerPos, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        Loop(65)
            Sub(LVar1, 16)
            Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Wait(65)
    Call(DisablePlayerInput, FALSE)
    Set(GB_KPA81_BowserDoorState, 1)
    Call(GotoMap, Ref(N(KPA_17)), kpa_17_ENTRY_0)
    Return
    End
};

EvtScript N(EVS_NpcInit_Door) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Door)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcPos, NPC_SELF, 184, 20, 150)
    Return
    End
};

NpcData N(NpcData_Door) = {
    .id = NPC_Door,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Door),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
    .drops = NO_DROPS,
    .animations = TOAD_RED_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Door), BTL_KMR_1_FORMATION_00, BTL_KMR_1_STAGE_00),
    {}
};
