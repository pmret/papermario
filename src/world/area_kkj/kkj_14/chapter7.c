#include "kkj_14.h"
#include "effects.h"
#include "sprite/player.h"

Vec3f N(TwinkHidePath)[] = {
    {  440.0,    65.0,    0.0 },
    {  420.0,   120.0,  -20.0 },
    {  400.0,    80.0,  -35.0 },
    {  375.0,    80.0,  -50.0 },
    {  375.0,   100.0,  -50.0 },
};

Vec3f N(TwinkAttackPath)[] = {
    {  375.0,   100.0,  -50.0 },
    {  375.0,    80.0,  -50.0 },
    {  390.0,    90.0,   10.0 },
};

EvtScript N(EVS_ApproachPeach) = {
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Sub(LVar0, 26)
        Sub(LVar2, 2)
        Call(SetNpcAnimation, NPC_Ch7_Koopatrol_01, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Ch7_Koopatrol_01, Float(5.0))
        Call(NpcMoveTo, NPC_Ch7_Koopatrol_01, LVar0, 70, 0)
        Call(NpcFacePlayer, NPC_Ch7_Koopatrol_01, 5)
        Call(NpcMoveTo, NPC_Ch7_Koopatrol_01, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_Ch7_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
    EndThread
    Call(SetNpcVar, NPC_Ch7_Koopatrol_02, 0, 1)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 26)
        Add(LVar2, 2)
        Call(SetNpcAnimation, NPC_Ch7_Koopatrol_02, ANIM_WorldKoopatrol_Anim06)
        Call(SetNpcSpeed, NPC_Ch7_Koopatrol_02, Float(5.0))
        Call(NpcMoveTo, NPC_Ch7_Koopatrol_02, LVar0, 70, 0)
        Call(NpcFacePlayer, NPC_Ch7_Koopatrol_02, 5)
        Call(NpcMoveTo, NPC_Ch7_Koopatrol_02, LVar0, LVar2, 0)
        Call(SetNpcAnimation, NPC_Ch7_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
        Call(SetNpcVar, NPC_Ch7_Koopatrol_02, 0, 0)
    EndThread
    Loop(0)
        Wait(1)
        Call(GetNpcVar, NPC_Ch7_Koopatrol_02, 0, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(10)
    Return
    End
};

EvtScript N(EVS_TiePeachUp) = {
    Thread
        Call(SetNpcAnimation, NPC_Ch7_Koopatrol_01, ANIM_WorldKoopatrol_Anim18)
        Call(GetNpcPos, NPC_Ch7_Koopatrol_01, LVar0, LVar1, LVar2)
        Loop(5)
            Loop(5)
                Add(LVar0, 2)
                Call(SetNpcPos, NPC_Ch7_Koopatrol_01, LVar0, LVar1, LVar2)
                Wait(1)
            EndLoop
            Loop(5)
                Sub(LVar0, 2)
                Call(SetNpcPos, NPC_Ch7_Koopatrol_01, LVar0, LVar1, LVar2)
                Wait(1)
            EndLoop
        EndLoop
        Call(SetNpcAnimation, NPC_Ch7_Koopatrol_01, ANIM_WorldKoopatrol_Anim01)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Ch7_Koopatrol_02, ANIM_WorldKoopatrol_Anim18)
        Call(GetNpcPos, NPC_Ch7_Koopatrol_02, LVar0, LVar1, LVar2)
        Loop(5)
            Loop(5)
                Sub(LVar0, 2)
                Call(SetNpcPos, NPC_Ch7_Koopatrol_02, LVar0, LVar1, LVar2)
                Wait(1)
            EndLoop
            Loop(5)
                Add(LVar0, 2)
                Call(SetNpcPos, NPC_Ch7_Koopatrol_02, LVar0, LVar1, LVar2)
                Wait(1)
            EndLoop
        EndLoop
        Call(SetNpcAnimation, NPC_Ch7_Koopatrol_02, ANIM_WorldKoopatrol_Anim01)
    EndThread
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Sub(LVar0, 16)
        Loop(50)
            Call(RandInt, 32, LVar3)
            Call(RandInt, 50, LVar4)
            Add(LVar3, LVar0)
            Add(LVar4, LVar1)
            PlayEffect(EFFECT_WALKING_DUST, 1, LVar3, LVar4, LVar2, 1, 1)
            Wait(1)
        EndLoop
    EndThread
    Call(SetPlayerAnimation, ANIM_Peach2_Gasp)
    Wait(10)
    Thread
        Call(SetPlayerAnimation, ANIM_Peach2_GaspStill)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(ShowMessageAtWorldPos, MSG_Peach_016D, LVar0, LVar1, LVar2)
    EndThread
    Set(LVar0, 0)
    Set(LVar1, 45)
    Loop(20)
        Call(InterpPlayerYaw, LVar0, 0)
        Add(LVar0, LVar1)
        Add(LVar1, 2)
        Wait(1)
    EndLoop
    Call(SetPlayerAnimation, ANIM_Peach2_TiedIdle)
    Loop(20)
        Call(InterpPlayerYaw, LVar0, 0)
        Add(LVar0, LVar1)
        Sub(LVar1, 2)
        Wait(1)
    EndLoop
    Call(InterpPlayerYaw, 270, 0)
    Return
    End
};

EvtScript N(EVS_PickUpPeach) = {
    Thread
        Call(GetNpcPos, NPC_Ch7_Koopatrol_01, LVar0, LVar1, LVar2)
        Call(SetNpcAnimation, NPC_Ch7_Koopatrol_01, ANIM_WorldKoopatrol_Anim12)
        Add(LVar0, 10)
        Call(NpcMoveTo, NPC_Ch7_Koopatrol_01, LVar0, LVar2, 10)
    EndThread
    Thread
        Call(GetNpcPos, NPC_Ch7_Koopatrol_02, LVar0, LVar1, LVar2)
        Call(SetNpcAnimation, NPC_Ch7_Koopatrol_02, ANIM_WorldKoopatrol_Anim12)
        Sub(LVar0, 10)
        Call(NpcMoveTo, NPC_Ch7_Koopatrol_02, LVar0, LVar2, 10)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Wait(1)
    Loop(4)
        Add(LVar1, 2)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(SetPlayerAnimation, ANIM_Peach3_TiedSideways)
    Loop(5)
        Add(LVar1, 4)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_CarryPeachAway) = {
    Call(InterpNpcYaw, NPC_Ch7_Koopatrol_01, 270, 3)
    Wait(10)
    Thread
        Loop(0)
            Call(GetNpcPos, NPC_Ch7_Koopatrol_02, LVar0, LVar1, LVar2)
            Sub(LVar0, 22)
            Add(LVar1, 30)
            Add(LVar2, 2)
            Call(SetPlayerPos, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Ch7_Koopatrol_01, ANIM_WorldKoopatrol_Anim14)
        Call(SetNpcSpeed, NPC_Ch7_Koopatrol_01, Float(5.0))
        Call(NpcMoveTo, NPC_Ch7_Koopatrol_01, 364, 68, 0)
        Call(NpcMoveTo, NPC_Ch7_Koopatrol_01, 84, 68, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Ch7_Koopatrol_02, ANIM_WorldKoopatrol_Anim14)
        Call(SetNpcSpeed, NPC_Ch7_Koopatrol_02, Float(5.0))
        Call(NpcMoveTo, NPC_Ch7_Koopatrol_02, 396, 72, 0)
        Call(NpcMoveTo, NPC_Ch7_Koopatrol_02, 116, 72, 0)
    EndThread
    Return
    End
};

EvtScript N(EVS_OpenAndCloseDoor_Ch7) = {
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_OPEN, 0)
    Call(MakeLerp, 0, 120, 14, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o4, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(40)
    Call(MakeLerp, 120, 0, 8, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o4, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_CLOSE, 0)
    Return
    End
};

EvtScript N(EVS_OpenDoor_Ch7) = {
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_OPEN, 0)
    Call(MakeLerp, 0, 120, 14, EASING_COS_FAST_OVERSHOOT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o4, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_FocusCam_Door_Ch7) = {
    Call(UseSettingsFrom, CAM_DEFAULT, -340, 0, -30)
    Call(SetPanTarget, CAM_DEFAULT, -340, 0, -30)
    Call(SetCamDistance, CAM_DEFAULT, Float(275.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-13.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(-310.0), Float(32.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_FocusCam_Bed) = {
    Call(UseSettingsFrom, CAM_DEFAULT, 380, 30, 10)
    Call(SetPanTarget, CAM_DEFAULT, 380, 30, 10)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_Scene_Chapter7) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    Call(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
    Call(SetNpcPos, NPC_PARTNER, 440, 65, 0)
    Call(SetNpcYaw, NPC_PARTNER, 270)
    Call(RotateModel, MODEL_o83, 80, 0, -1, 0)
    Call(RotateModel, MODEL_o85, 80, 0, 1, 0)
    Call(RotateModel, MODEL_o84, 80, 0, -1, 0)
    Call(RotateModel, MODEL_o86, 80, 0, 1, 0)
    ExecWait(N(EVS_FocusCam_Door_Ch7))
    Wait(30 * DT)
    Exec(N(EVS_OpenAndCloseDoor_Ch7))
    Call(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Walk)
    Call(SetNpcPos, NPC_Ch7_Bowser, -470, 0, -30)
    Call(SetNpcSpeed, NPC_Ch7_Bowser, Float(3.0 / DT))
    Call(NpcMoveTo, NPC_Ch7_Bowser, -290, -30, 0)
    Call(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Idle)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Peach_0161)
    Wait(10 * DT)
    ExecWait(N(EVS_FocusCam_Bed))
    Call(LoadPath, 30 / DT, Ref(N(TwinkHidePath)), ARRAY_COUNT(N(TwinkHidePath)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Sad)
    Call(SetNpcPos, NPC_Ch7_Bowser, 100, 0, 20)
    Call(SetNpcFlagBits, NPC_Ch7_Bowser, NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Walk)
    Call(NpcMoveTo, NPC_Ch7_Bowser, 300, 20, 0)
    Call(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Idle)
    Wait(10 * DT)
    Call(SetCamDistance, CAM_DEFAULT, Float(325.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(5.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Peach_0162)
    Call(InterpPlayerYaw, 90, 5)
    Call(SetPlayerAnimation, ANIM_Peach2_ArmsCrossedIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_0163)
    Call(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, MSG_Peach_0164)
    Call(InterpPlayerYaw, 270, 5)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_0165)
    Call(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_TalkEyesClosed, 5, MSG_Peach_0166)
    Call(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Idle)
    Call(EndSpeech, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_0167)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    ExecWait(N(EVS_FocusCam_Door_Ch7))
    Exec(N(EVS_OpenDoor_Ch7))
    Call(SetNpcAnimation, NPC_Ch7_Kammy, ANIM_WorldKammy_Anim03)
    Call(SetNpcPos, NPC_Ch7_Kammy, -470, 0, -30)
    Call(SetNpcSpeed, NPC_Ch7_Bowser, Float(5.0 / DT))
    Call(NpcMoveTo, NPC_Ch7_Kammy, -340, -30, 0)
    Call(SetNpcAnimation, NPC_Ch7_Kammy, ANIM_WorldKammy_Anim01)
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_Ch7_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Ch7_Bowser, MSG_Peach_0168)
    Call(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Idle)
    Call(SetNpcYaw, NPC_Ch7_Bowser, 270)
    Call(SetNpcYaw, NPC_PARTNER, 270)
    Call(UseSettingsFrom, CAM_DEFAULT, 250, 30, 10)
    Call(SetPanTarget, CAM_DEFAULT, 250, 30, 10)
    Call(SetCamDistance, CAM_DEFAULT, Float(325.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(10 * DT)
    Call(SetNpcPos, NPC_Ch7_Kammy, 50, 0, -10)
    Call(SetNpcAnimation, NPC_Ch7_Kammy, ANIM_WorldKammy_Anim03)
    Call(NpcMoveTo, NPC_Ch7_Kammy, 180, -10, 0)
    Call(SetNpcAnimation, NPC_Ch7_Kammy, ANIM_WorldKammy_Anim01)
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Ch7_Kammy, MSG_Peach_0169)
    Call(SpeakToNpc, NPC_Ch7_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Ch7_Bowser, MSG_Peach_016A)
    Call(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Shock)
    Call(GetNpcPos, NPC_Ch7_Bowser, LVar0, LVar1, LVar2)
    Call(NpcJump0, NPC_Ch7_Bowser, LVar0, LVar1, LVar2, 10 * DT)
    Call(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Idle)
    Call(SpeakToNpc, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Ch7_Kammy, MSG_Peach_016B)
    Wait(10 * DT)
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Call(InterpNpcYaw, NPC_Ch7_Bowser, 270, 10)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, MSG_Peach_016C)
    Wait(10 * DT)
    Call(SetNpcPos, NPC_Ch7_Koopatrol_01, 48, 0, 70)
    Call(SetNpcPos, NPC_Ch7_Koopatrol_02, 100, 0, 70)
    Call(SetNpcFlagBits, NPC_Ch7_Koopatrol_01, NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcFlagBits, NPC_Ch7_Koopatrol_02, NPC_FLAG_GRAVITY, TRUE)
    Wait(10 * DT)
    ExecWait(N(EVS_ApproachPeach))
    ExecWait(N(EVS_TiePeachUp))
    Call(SetNpcAnimation, NPC_PARTNER, ANIM_Twink_Angry)
    Call(LoadPath, 15, Ref(N(TwinkAttackPath)), ARRAY_COUNT(N(TwinkAttackPath)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_TalkAngry, ANIM_Twink_Sad, 5, MSG_Peach_016E)
    Call(SetNpcVar, NPC_Ch7_Bowser, 0, 0)
    Thread
        Call(NpcFlyTo, NPC_PARTNER, 410, 80, 10, 7, 0, EASING_LINEAR)
        Loop(2)
            Call(NpcFlyTo, NPC_PARTNER, 400, 70, 10, 5, 0, EASING_LINEAR)
            PlayEffect(EFFECT_LANDING_DUST, 0, 400, 70, 10, 0)
            Call(NpcFlyTo, NPC_PARTNER, 410, 80, 10, 5, 0, EASING_LINEAR)
        EndLoop
        Call(NpcFlyTo, NPC_PARTNER, 360, 80, 10, 7, 0, EASING_LINEAR)
        Loop(0)
            Call(NpcFlyTo, NPC_PARTNER, 360, 70, 10, 5, 0, EASING_LINEAR)
            PlayEffect(EFFECT_LANDING_DUST, 0, 360, 70, 10, 0)
            Call(NpcFlyTo, NPC_PARTNER, 350, 80, 10, 5, 0, EASING_LINEAR)
            Call(GetNpcVar, NPC_Ch7_Bowser, 0, LVar0)
            IfEq(LVar0, 1)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcVar, NPC_Ch7_Bowser, 0, 2)
    EndThread
    Call(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, MSG_Peach_016F)
    Wait(20)
    Call(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_AngryTalk, ANIM_WorldBowser_Idle, 5, MSG_Peach_0170)
    Call(SetNpcVar, NPC_Ch7_Bowser, 0, 1)
    Loop(0)
        Wait(1)
        Call(GetNpcVar, NPC_Ch7_Bowser, 0, LVar0)
        IfEq(LVar0, 2)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Walk)
    Call(NpcMoveTo, NPC_Ch7_Bowser, 310, 20, 5)
    Call(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Swipe)
    Wait(3)
    Call(InterpPlayerYaw, 90, 0)
    Call(PlaySoundAt, SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_DEFAULT, 350, 80, 10)
    PlayEffect(EFFECT_FIREWORK, 0, 350, 80, 10, 1, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(SetNpcSpeed, NPC_PARTNER, Float(7.5 / DT))
    Call(NpcFlyTo, NPC_PARTNER, 500, 130, 10, 0, 0, EASING_LINEAR)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_TiedIdle, ANIM_Peach2_TiedIdle, 5, MSG_Peach_0171)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Ch7_Bowser, ANIM_WorldBowser_Idle)
    Call(SpeakToPlayer, NPC_Ch7_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5, MSG_Peach_0172)
    Wait(10 * DT)
    ChildThread
        Loop(0)
            Call(NpcFacePlayer, NPC_Ch7_Bowser, 0)
            Wait(1)
        EndLoop
    EndChildThread
    ExecWait(N(EVS_PickUpPeach))
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_TiedSideways, ANIM_Peach3_TiedSideways, 5, MSG_Peach_0173)
    ExecWait(N(EVS_CarryPeachAway))
    Wait(30 * DT)
    ExecWait(N(EVS_EndPeachChapter7))
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
