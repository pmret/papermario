#include "jan_23.h"
#include "sprite/player.h"

#include "world/common/npc/RaphaelRaven.inc.c"
#include "world/common/npc/Raven.inc.c"

EvtScript N(EVS_Ravens_Converse) = {
    Loop(4)
        Call(SetNpcAnimation, NPC_RaphaelRaven, ANIM_RaphaelRaven_TalkNoFeet)
        Call(InterpNpcYaw, NPC_Raven_01, 90, 1)
        Call(InterpNpcYaw, NPC_Raven_02, 270, 1)
        Call(InterpNpcYaw, NPC_Raven_03, 0, 4)
        Call(InterpNpcYaw, NPC_Raven_04, 90, 1)
        Call(InterpNpcYaw, NPC_Raven_05, 270, 1)
        Wait(20)
        Call(SetNpcAnimation, NPC_RaphaelRaven, ANIM_RaphaelRaven_IdleNoFeet)
        Call(InterpNpcYaw, NPC_Raven_01, 270, 2)
        Call(InterpNpcYaw, NPC_Raven_02, 90, 1)
        Call(InterpNpcYaw, NPC_Raven_03, 0, 1)
        Call(InterpNpcYaw, NPC_Raven_04, 270, 4)
        Call(InterpNpcYaw, NPC_Raven_05, 90, 1)
        Wait(20)
    EndLoop
    Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
    Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
    Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
    Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
    Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Idle)
    Call(InterpNpcYaw, NPC_Raven_01, 0, 1)
    Call(InterpNpcYaw, NPC_Raven_02, 0, 1)
    Call(InterpNpcYaw, NPC_Raven_03, 0, 1)
    Call(InterpNpcYaw, NPC_Raven_04, 0, 1)
    Call(InterpNpcYaw, NPC_Raven_05, 0, 1)
    Return
    End
};

EvtScript N(EVS_Raven1_Descend) = {
    Call(SetNpcRotationPivot, NPC_Raven_01, 50)
    Loop(2)
        Set(LVar3, -30)
        Loop(20)
            Call(SetNpcRotation, NPC_Raven_01, 0, 0, LVar3)
            Add(LVar3, 3)
            Wait(1)
        EndLoop
        Loop(20)
            Call(SetNpcRotation, NPC_Raven_01, 0, 0, LVar3)
            Add(LVar3, -3)
            Wait(1)
        EndLoop
    EndLoop
    Loop(10)
        Call(SetNpcRotation, NPC_Raven_01, 0, 0, LVar3)
        Add(LVar3, 3)
        Wait(1)
    EndLoop
    Call(SetNpcRotationPivot, NPC_Raven_01, 0)
    Return
    End
};

EvtScript N(EVS_Raven2_Descend) = {
    Call(SetNpcRotationPivot, NPC_Raven_02, 60)
    Loop(2)
        Set(LVar3, -30)
        Loop(20)
            Call(SetNpcRotation, NPC_Raven_02, 0, 0, LVar3)
            Add(LVar3, 3)
            Wait(1)
        EndLoop
        Loop(20)
            Call(SetNpcRotation, NPC_Raven_02, 0, 0, LVar3)
            Add(LVar3, -3)
            Wait(1)
        EndLoop
    EndLoop
    Loop(10)
        Call(SetNpcRotation, NPC_Raven_02, 0, 0, LVar3)
        Add(LVar3, 3)
        Wait(1)
    EndLoop
    Call(SetNpcRotationPivot, NPC_Raven_02, 0)
    Return
    End
};

EvtScript N(EVS_Raven3_Descend) = {
    Call(SetNpcRotationPivot, NPC_Raven_03, 50)
    Loop(2)
        Set(LVar3, -30)
        Loop(20)
            Call(SetNpcRotation, NPC_Raven_03, 0, 0, LVar3)
            Add(LVar3, 3)
            Wait(1)
        EndLoop
        Loop(20)
            Call(SetNpcRotation, NPC_Raven_03, 0, 0, LVar3)
            Add(LVar3, -3)
            Wait(1)
        EndLoop
    EndLoop
    Loop(10)
        Call(SetNpcRotation, NPC_Raven_03, 0, 0, LVar3)
        Add(LVar3, 3)
        Wait(1)
    EndLoop
    Call(SetNpcRotationPivot, NPC_Raven_03, 0)
    Return
    End
};

EvtScript N(EVS_Raven4_Descend) = {
    Call(SetNpcRotationPivot, NPC_Raven_04, 60)
    Loop(2)
        Set(LVar3, -30)
        Loop(20)
            Call(SetNpcRotation, NPC_Raven_04, 0, 0, LVar3)
            Add(LVar3, 3)
            Wait(1)
        EndLoop
        Loop(20)
            Call(SetNpcRotation, NPC_Raven_04, 0, 0, LVar3)
            Add(LVar3, -3)
            Wait(1)
        EndLoop
    EndLoop
    Loop(10)
        Call(SetNpcRotation, NPC_Raven_04, 0, 0, LVar3)
        Add(LVar3, 3)
        Wait(1)
    EndLoop
    Call(SetNpcRotationPivot, NPC_Raven_04, 0)
    Return
    End
};

EvtScript N(EVS_Raven5_Descend) = {
    Call(SetNpcRotationPivot, NPC_Raven_05, 50)
    Loop(2)
        Set(LVar3, -30)
        Loop(20)
            Call(SetNpcRotation, NPC_Raven_05, 0, 0, LVar3)
            Add(LVar3, 3)
            Wait(1)
        EndLoop
        Loop(20)
            Call(SetNpcRotation, NPC_Raven_05, 0, 0, LVar3)
            Add(LVar3, -3)
            Wait(1)
        EndLoop
    EndLoop
    Loop(10)
        Call(SetNpcRotation, NPC_Raven_05, 0, 0, LVar3)
        Add(LVar3, 3)
        Wait(1)
    EndLoop
    Call(SetNpcRotationPivot, NPC_Raven_05, 0)
    Return
    End
};

EvtScript N(EVS_Raven1_MoveToMeetingPos) = {
    Wait(10)
    Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Walk)
    Call(SetNpcSpeed, NPC_Raven_01, Float(3.0))
    Call(NpcMoveTo, NPC_Raven_01, 540, 85, 0)
    Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
    Call(InterpNpcYaw, NPC_Raven_01, 0, 1)
    Return
    End
};

EvtScript N(EVS_Raven2_MoveToMeetingPos) = {
    Wait(10)
    Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Walk)
    Call(SetNpcSpeed, NPC_Raven_02, Float(3.0))
    Call(NpcMoveTo, NPC_Raven_02, 560, 132, 0)
    Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
    Call(InterpNpcYaw, NPC_Raven_02, 0, 1)
    Return
    End
};

EvtScript N(EVS_Raven3_MoveToMeetingPos) = {
    Wait(10)
    Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Walk)
    Call(SetNpcSpeed, NPC_Raven_03, Float(3.0))
    Call(NpcMoveTo, NPC_Raven_03, 590, 105, 0)
    Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
    Call(InterpNpcYaw, NPC_Raven_03, 0, 1)
    Return
    End
};

EvtScript N(EVS_Raven4_MoveToMeetingPos) = {
    Wait(10)
    Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Walk)
    Call(SetNpcSpeed, NPC_Raven_04, Float(3.0))
    Call(NpcMoveTo, NPC_Raven_04, 615, 122, 0)
    Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
    Call(InterpNpcYaw, NPC_Raven_04, 0, 1)
    Return
    End
};

EvtScript N(EVS_Raven5_Sweat) = {
    Label(0)
        Call(ShowSweat, NPC_Raven_05, 1, -45, EMOTER_NPC, 0, 0, 0, 0, 20)
        Wait(8)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Raven5_MoveToMeetingPos) = {
    Wait(10)
    ExecGetTID(N(EVS_Raven5_Sweat), LVar9)
    Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Walk)
    Call(SetNpcSpeed, NPC_Raven_05, Float(4.0))
    Call(NpcMoveTo, NPC_Raven_05, 645, 78, 0)
    Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Idle)
    Call(InterpNpcYaw, NPC_Raven_05, 0, 1)
    Wait(15)
    KillThread(LVar9)
    Return
    End
};

EvtScript N(EVS_NpcInteract_RaphaelRaven_Before) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 460)
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Call(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeet, ANIM_RaphaelRaven_IdleNoFeet, 0, MSG_CH5_00DA)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(5 * DT)
    Call(SetPlayerAnimation, ANIM_MarioW2_SpeakUp)
    Wait(35 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeet, ANIM_RaphaelRaven_IdleNoFeet, 5, MSG_CH5_00DB)
    Wait(20 * DT)
    Thread
        Set(MF_Unk_00, FALSE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeetAngry, ANIM_RaphaelRaven_TalkNoFeetAngry, 5, MSG_CH5_00DC)
        Set(MF_Unk_00, TRUE)
    EndThread
    Call(SetMotionBlurParams, 0, 0, 0, 320, 240, 128, 10)
    Call(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeetAngry)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(12.0))
    Loop(5)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_BIG_DRUM_A, SOUND_SPACE_DEFAULT)
        Call(SetCamDistance, CAM_DEFAULT, 310)
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_BIG_DRUM_B, SOUND_SPACE_DEFAULT)
        Call(SetCamDistance, CAM_DEFAULT, 460)
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndLoop
    Call(SetMotionBlurParams, 0, 0, 0, 320, 240, 0, 10)
    Label(2)
        IfEq(MF_Unk_00, FALSE)
            Wait(1)
            Goto(2)
        EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_IdleNoFeet)
    Wait(15 * DT)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Add(LVar1, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 580)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(InterpNpcYaw, NPC_SELF, 90, 1)
    Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Flail)
    Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Flail)
    Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Flail)
    Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Flail)
    Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Flail)
    Call(SetNpcPos, NPC_Raven_01, 800, 450, -20)
    Call(SetNpcPos, NPC_Raven_02, 820, 452, 0)
    Call(SetNpcPos, NPC_Raven_03, 840, 452, 27)
    Call(SetNpcPos, NPC_Raven_04, 830, 452, 56)
    Call(SetNpcPos, NPC_Raven_05, 795, 455, 20)
    Call(EnableNpcShadow, NPC_Raven_01, FALSE)
    Call(EnableNpcShadow, NPC_Raven_02, FALSE)
    Call(EnableNpcShadow, NPC_Raven_03, FALSE)
    Call(EnableNpcShadow, NPC_Raven_04, FALSE)
    Call(EnableNpcShadow, NPC_Raven_05, FALSE)
    Thread
        Exec(N(EVS_Raven1_Descend))
        Call(SetNpcJumpscale, NPC_Raven_01, 0)
        Call(GetNpcPos, NPC_Raven_01, LVar0, LVar1, LVar2)
        Add(LVar0, -120)
        Add(LVar1, -250)
        Add(LVar2, 63)
        Call(PlaySoundAtNpc, NPC_Raven_01, SOUND_RAVEN_FALL_A, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Raven_01, LVar0, LVar1, LVar2, 100)
        Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
        Call(EnableNpcShadow, NPC_Raven_01, TRUE)
        ExecWait(N(EVS_Raven1_MoveToMeetingPos))
    EndThread
    Wait(20)
    Thread
        Exec(N(EVS_Raven2_Descend))
        Call(SetNpcJumpscale, NPC_Raven_02, 0)
        Call(GetNpcPos, NPC_Raven_02, LVar0, LVar1, LVar2)
        Add(LVar0, -120)
        Add(LVar1, -250)
        Add(LVar2, 63)
        Call(PlaySoundAtNpc, NPC_Raven_02, SOUND_RAVEN_FALL_B, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Raven_02, LVar0, LVar1, LVar2, 100)
        Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
        Call(EnableNpcShadow, NPC_Raven_02, TRUE)
        ExecWait(N(EVS_Raven2_MoveToMeetingPos))
    EndThread
    Wait(20)
    Thread
        Call(InterpPlayerYaw, 90, 1)
        Wait(20)
        Set(LVar3, 625)
        Set(LVar5, 220)
        Call(PlayerMoveTo, LVar3, LVar5, 30)
        Call(InterpPlayerYaw, 10, 4)
    EndThread
    Thread
        Exec(N(EVS_Raven3_Descend))
        Call(SetNpcJumpscale, NPC_Raven_03, 0)
        Call(GetNpcPos, NPC_Raven_03, LVar0, LVar1, LVar2)
        Add(LVar0, -100)
        Add(LVar1, -250)
        Add(LVar2, 50)
        Call(PlaySoundAtNpc, NPC_Raven_03, SOUND_RAVEN_FALL_C, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Raven_03, LVar0, LVar1, LVar2, 90)
        Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
        Call(EnableNpcShadow, NPC_Raven_03, TRUE)
        ExecWait(N(EVS_Raven3_MoveToMeetingPos))
    EndThread
    Wait(40)
    Thread
        Exec(N(EVS_Raven4_Descend))
        Call(SetNpcJumpscale, NPC_Raven_04, 0)
        Call(GetNpcPos, NPC_Raven_04, LVar0, LVar1, LVar2)
        Add(LVar0, -100)
        Add(LVar1, -250)
        Add(LVar2, 60)
        Call(PlaySoundAtNpc, NPC_Raven_04, SOUND_RAVEN_FALL_A, SOUND_SPACE_DEFAULT)
        Call(NpcJump0, NPC_Raven_04, LVar0, LVar1, LVar2, 100)
        Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
        Call(EnableNpcShadow, NPC_Raven_04, TRUE)
        ExecWait(N(EVS_Raven4_MoveToMeetingPos))
    EndThread
    Wait(20)
    Exec(N(EVS_Raven5_Descend))
    Call(SetNpcJumpscale, NPC_Raven_05, 0)
    Call(PlaySoundAtNpc, NPC_Raven_05, SOUND_RAVEN_FALL_B, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_Raven_05, 737, 200, 65, 100)
    Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Idle)
    Call(EnableNpcShadow, NPC_Raven_05, TRUE)
    ExecWait(N(EVS_Raven5_MoveToMeetingPos))
    Wait(20)
    Call(InterpPlayerYaw, 350, 4)
    Call(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeet, ANIM_RaphaelRaven_IdleNoFeet, 5, MSG_CH5_00DD)
    Call(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeet, ANIM_RaphaelRaven_IdleNoFeet, 5, MSG_CH5_00DE)
    ExecWait(N(EVS_Ravens_Converse))
    Call(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeet, ANIM_RaphaelRaven_IdleNoFeet, 5, MSG_CH5_00DF)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, 535, 200, 215)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(20 * DT)
    Thread
        Wait(20 * DT)
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
        Wait(15 * DT)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_RAVEN_FALL_A, SOUND_SPACE_DEFAULT)
    EndThread
    Thread
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
        Call(SetNpcJumpscale, NPC_SELF, Float(1.0))
        Call(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Walk)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, -70)
        Add(LVar1, -7)
        Add(LVar2, 175)
        Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 20 * DT)
        Call(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Idle)
        Call(SetNpcJumpscale, NPC_SELF, Float(1.5))
        Call(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Walk)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, -100)
        Add(LVar1, -300)
        Add(LVar2, 175)
        Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 30 * DT)
        Call(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_Idle)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EndThread
    Wait(40 * DT)
    Thread
        Wait(35 * DT)
        Call(PlaySoundAtNpc, NPC_Raven_01, SOUND_RAVEN_FALL_B, SOUND_SPACE_DEFAULT)
    EndThread
    Thread
        Call(SetNpcFlagBits, NPC_Raven_01, NPC_FLAG_GRAVITY, TRUE)
        Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Walk)
        Call(GetNpcPos, NPC_Raven_01, LVar0, LVar1, LVar2)
        Add(LVar0, -40)
        Add(LVar2, 154)
        Call(NpcMoveTo, NPC_Raven_01, LVar0, LVar2, 20 * DT)
        Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
        Call(SetNpcJumpscale, NPC_Raven_01, Float(1.5))
        Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Walk)
        Call(GetNpcPos, NPC_Raven_01, LVar0, LVar1, LVar2)
        Add(LVar0, -20)
        Add(LVar1, -300)
        Add(LVar2, 154)
        Call(NpcJump0, NPC_Raven_01, LVar0, LVar1, LVar2, 30 * DT)
        Call(SetNpcAnimation, NPC_Raven_01, ANIM_Raven_Idle)
        Call(SetNpcPos, NPC_Raven_01, NPC_DISPOSE_LOCATION)
        Call(SetNpcFlagBits, NPC_Raven_01, NPC_FLAG_GRAVITY, FALSE)
    EndThread
    Wait(20 * DT)
    Thread
        Wait(35 * DT)
        Call(PlaySoundAtNpc, NPC_Raven_02, SOUND_RAVEN_FALL_C, SOUND_SPACE_DEFAULT)
    EndThread
    Thread
        Call(SetNpcFlagBits, NPC_Raven_02, NPC_FLAG_GRAVITY, TRUE)
        Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Walk)
        Call(GetNpcPos, NPC_Raven_02, LVar0, LVar1, LVar2)
        Add(LVar0, -55)
        Add(LVar2, 110)
        Call(NpcMoveTo, NPC_Raven_02, LVar0, LVar2, 20 * DT)
        Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
        Call(SetNpcJumpscale, NPC_Raven_02, Float(1.5))
        Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Walk)
        Call(GetNpcPos, NPC_Raven_02, LVar0, LVar1, LVar2)
        Add(LVar0, -40)
        Add(LVar1, -300)
        Add(LVar2, 110)
        Call(NpcJump0, NPC_Raven_02, LVar0, LVar1, LVar2, 30 * DT)
        Call(SetNpcAnimation, NPC_Raven_02, ANIM_Raven_Idle)
        Call(SetNpcPos, NPC_Raven_02, NPC_DISPOSE_LOCATION)
        Call(SetNpcFlagBits, NPC_Raven_02, NPC_FLAG_GRAVITY, FALSE)
    EndThread
    Wait(20 * DT)
    Thread
        Wait(35 * DT)
        Call(PlaySoundAtNpc, NPC_Raven_03, SOUND_RAVEN_FALL_A, SOUND_SPACE_DEFAULT)
    EndThread
    Thread
        Call(SetNpcFlagBits, NPC_Raven_03, NPC_FLAG_GRAVITY, TRUE)
        Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Walk)
        Call(GetNpcPos, NPC_Raven_03, LVar0, LVar1, LVar2)
        Add(LVar0, -75)
        Add(LVar2, 134)
        Call(NpcMoveTo, NPC_Raven_03, LVar0, LVar2, 20 * DT)
        Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
        Call(SetNpcJumpscale, NPC_Raven_03, Float(1.5))
        Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Walk)
        Call(GetNpcPos, NPC_Raven_03, LVar0, LVar1, LVar2)
        Add(LVar0, -70)
        Add(LVar1, -300)
        Add(LVar2, 134)
        Call(NpcJump0, NPC_Raven_03, LVar0, LVar1, LVar2, 30 * DT)
        Call(SetNpcAnimation, NPC_Raven_03, ANIM_Raven_Idle)
        Call(SetNpcPos, NPC_Raven_03, NPC_DISPOSE_LOCATION)
        Call(SetNpcFlagBits, NPC_Raven_03, NPC_FLAG_GRAVITY, FALSE)
    EndThread
    Wait(20 * DT)
    Thread
        Wait(35 * DT)
        Call(PlaySoundAtNpc, NPC_Raven_04, SOUND_RAVEN_FALL_B, SOUND_SPACE_DEFAULT)
    EndThread
    Thread
        Call(SetNpcFlagBits, NPC_Raven_04, NPC_FLAG_GRAVITY, TRUE)
        Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Walk)
        Call(GetNpcPos, NPC_Raven_04, LVar0, LVar1, LVar2)
        Add(LVar0, -110)
        Add(LVar2, 115)
        Call(NpcMoveTo, NPC_Raven_04, LVar0, LVar2, 20 * DT)
        Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
        Call(SetNpcJumpscale, NPC_Raven_04, Float(1.5))
        Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Walk)
        Call(GetNpcPos, NPC_Raven_04, LVar0, LVar1, LVar2)
        Add(LVar0, -110)
        Add(LVar1, -300)
        Add(LVar2, 115)
        Call(NpcJump0, NPC_Raven_04, LVar0, LVar1, LVar2, 30 * DT)
        Call(SetNpcAnimation, NPC_Raven_04, ANIM_Raven_Idle)
        Call(SetNpcPos, NPC_Raven_04, NPC_DISPOSE_LOCATION)
        Call(SetNpcFlagBits, NPC_Raven_04, NPC_FLAG_GRAVITY, FALSE)
    EndThread
    Wait(10 * DT)
    Thread
        Wait(45 * DT)
        Call(PlaySoundAtNpc, NPC_Raven_05, SOUND_RAVEN_FALL_C, SOUND_SPACE_DEFAULT)
    EndThread
    Call(SetNpcFlagBits, NPC_Raven_05, NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Walk)
    Call(GetNpcPos, NPC_Raven_05, LVar0, LVar1, LVar2)
    Add(LVar0, -100)
    Add(LVar2, 161)
    Call(NpcMoveTo, NPC_Raven_05, LVar0, LVar2, 30 * DT)
    Thread
        Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Idle)
        Call(SetNpcJumpscale, NPC_Raven_05, Float(1.5))
        Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Walk)
        Call(GetNpcPos, NPC_Raven_05, LVar0, LVar1, LVar2)
        Add(LVar0, -70)
        Add(LVar1, -500)
        Add(LVar2, 161)
        Call(NpcJump0, NPC_Raven_05, LVar0, LVar1, LVar2, 35 * DT)
        Call(SetNpcAnimation, NPC_Raven_05, ANIM_Raven_Idle)
        Call(SetNpcPos, NPC_Raven_05, NPC_DISPOSE_LOCATION)
        Call(SetNpcFlagBits, NPC_Raven_05, NPC_FLAG_GRAVITY, FALSE)
    EndThread
    Call(SetPanTarget, CAM_DEFAULT, 550, -150, 400)
    Call(SetCamDistance, CAM_DEFAULT, 580)
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-4.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.8 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(15 * DT)
    Call(ResetCam, CAM_DEFAULT, Float(2.0 * DT))
    Set(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInteract_RaphaelRaven_After) = {
    Call(SpeakToPlayer, NPC_SELF, ANIM_RaphaelRaven_TalkNoFeet, ANIM_RaphaelRaven_IdleNoFeet, 0, MSG_CH5_00E0)
    Return
    End
};

EvtScript N(EVS_NpcInit_RaphaelRaven) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_RaphaelRaven_IdleNoFeet)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_RAPHAEL_LEFT_NEST)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_RaphaelRaven_Before)))
        CaseGe(STORY_CH5_ZIP_LINE_READY)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_RaphaelRaven_After)))
        CaseDefault
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Raven_01) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_Raven_02) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_Raven_03) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_Raven_04) = {
    Return
    End
};

EvtScript N(EVS_NpcInit_Raven_05) = {
    Return
    End
};

NpcData N(NpcData_Ravens)[] = {
    {
        .id = NPC_RaphaelRaven,
        .pos = { 590.0f, 210.0f, 0.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_RaphaelRaven),
        .settings = &N(NpcSettings_RaphaelRaven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY,
        .drops = NO_DROPS,
        .animations = RAPHAEL_RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RaphaelRaven,
    },
    {
        .id = NPC_Raven_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven_01),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenA,
    },
    {
        .id = NPC_Raven_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven_02),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
#if VERSION_JP
        .tattle = MSG_NpcTattle_0121,
#endif
    },
    {
        .id = NPC_Raven_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven_03),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenC,
    },
    {
        .id = NPC_Raven_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven_04),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenD,
    },
    {
        .id = NPC_Raven_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven_05),
        .settings = &N(NpcSettings_Raven),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenE,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Ravens)),
    {}
};
