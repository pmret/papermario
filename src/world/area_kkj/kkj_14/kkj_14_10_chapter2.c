#include "kkj_14.h"
#include "sprite/player.h"

Vec3f N(TwinkEmergePath)[] = {
    {  110.0,     0.0, -190.0 },
    {  160.0,    70.0, -150.0 },
    {  100.0,    40.0,  -60.0 },
    {   20.0,    70.0, -100.0 },
    {  -60.0,    40.0,  -20.0 },
    {    0.0,    20.0,   30.0 },
};

EvtScript N(EVS_OpenAndCloseDoor_Ch2) = {
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

EvtScript N(EVS_OpenDoor_Ch2) = {
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

EvtScript N(EVS_CloseDoor_Ch2) = {
    Call(MakeLerp, 120, 0, 8, EASING_COS_FAST_OVERSHOOT)
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

EvtScript N(EVS_FocusCam_Door_Ch2) = {
    Call(UseSettingsFrom, CAM_DEFAULT, -330, 0, -30)
    Call(SetPanTarget, CAM_DEFAULT, -330, 0, -30)
    Call(SetCamDistance, CAM_DEFAULT, Float(325.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(-310.0), Float(32.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Return
    End
};

EvtScript N(EVS_Scene_Chapter2) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetMusicTrack, 0, SONG_BOWSER_THEME, 0, 8)
    Call(DisablePartnerAI, 0)
    Call(SetNpcPos, NPC_PARTNER, 110, 0, -190)
    Call(SetNpcYaw, NPC_PARTNER, 270)
    Call(InterpPlayerYaw, 270, 0)
    ExecWait(N(EVS_FocusCam_Door_Ch2))
    Exec(N(EVS_OpenAndCloseDoor_Ch2))
    Wait(10 * DT)
    Call(SetNpcPos, NPC_Bowser, -470, 0, -30)
    Call(SetNpcVar, NPC_Bowser, 0, 1)
    Thread
        Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
        Call(SetNpcSpeed, NPC_Bowser, Float(3.0 / DT))
        Call(NpcMoveTo, NPC_Bowser, -30, 30, 0)
        Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
        Call(SetNpcVar, NPC_Bowser, 0, 0)
    EndThread
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Loop(0)
        Call(GetNpcPos, NPC_Bowser, LVar0, LVar1, LVar2)
        Add(LVar0, 30)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(GetNpcVar, NPC_Bowser, 0, LVar0)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_TalkEyesClosed, 0, MSG_Peach_005C)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Wait(1)
    Call(EndSpeech, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0)
    Call(SetPlayerAnimation, ANIM_Peach2_ArmsCrossedIdle)
    Call(InterpPlayerYaw, 90, 3)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_ArmsCrossedTalk, ANIM_Peach2_ArmsCrossedIdle, 5, MSG_Peach_005D)
    Call(SpeakToPlayer, NPC_Bowser, ANIM_WorldBowser_TalkEyesClosed, ANIM_WorldBowser_TalkEyesClosed, 5, MSG_Peach_005E)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Call(EndSpeech, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 5)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(InterpPlayerYaw, 270, 0)
    Call(InterpNpcYaw, NPC_Bowser, 270, 0)
    ExecWait(N(EVS_FocusCam_Door_Ch2))
    Wait(5 * DT)
    Exec(N(EVS_OpenDoor_Ch2))
    Call(SetMusicTrack, 0, SONG_KAMMY_KOOPA_THEME, 0, 8)
    Call(SetNpcPos, NPC_Kammy, -470, 0, -30)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim03)
    Call(SetNpcSpeed, NPC_Kammy, Float(5.0 / DT))
    Call(NpcMoveTo, NPC_Kammy, -340, -30, 0)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    Wait(10)
    Call(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_005F)
    Call(SetCamDistance, CAM_DEFAULT, 350)
    Call(SetPanTarget, CAM_DEFAULT, -30, 0, -30)
    Call(SetCamPosA, CAM_DEFAULT, -287, 32)
    Wait(5 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim03)
    Call(SetNpcSpeed, NPC_Kammy, Float(5.0 / DT))
    Call(NpcMoveTo, NPC_Kammy, -110, 30, 0)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    Call(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_0060)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0061)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
    Call(NpcMoveTo, NPC_Kammy, -90, 40, 10 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim01)
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_0062)
    Call(GetNpcPos, NPC_Bowser, LVar0, LVar1, LVar2)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Shock)
    Call(NpcJump0, NPC_Bowser, LVar0, LVar1, LVar2, 10 * DT)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Idle)
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0063)
    Call(SpeakToNpc, NPC_Kammy, ANIM_WorldKammy_Anim04, ANIM_WorldKammy_Anim01, 0, NPC_Bowser, MSG_Peach_0064)
    Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_ArmsCrossed)
    Wait(50 * DT)
    Call(SpeakToNpc, NPC_Bowser, ANIM_WorldBowser_Talk, ANIM_WorldBowser_Idle, 0, NPC_Kammy, MSG_Peach_0065)
    Thread
        Call(SetNpcAnimation, NPC_Bowser, ANIM_WorldBowser_Walk)
        Call(SetNpcSpeed, NPC_Bowser, Float(3.0 / DT))
        Call(NpcMoveTo, NPC_Bowser, -470, -30, 0)
    EndThread
    Call(SetNpcVar, NPC_Kammy, 0, 1)
    Thread
        Wait(40 * DT)
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim02)
        Call(SetNpcSpeed, NPC_Kammy, Float(3.0 / DT))
        Call(NpcMoveTo, NPC_Kammy, -470, -30, 0)
        Call(SetNpcVar, NPC_Kammy, 0, 0)
    EndThread
    Thread
        Call(MakeLerp, 350, 400, 100 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetCamDistance, CAM_DEFAULT, LVar0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Loop(0)
        Call(GetNpcPos, NPC_Bowser, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(GetNpcVar, NPC_Kammy, 0, LVar0)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Exec(N(EVS_CloseDoor_Ch2))
    Wait(30 * DT)
    Call(SetMusicTrack, 0, SONG_PRISONER_PEACH_THEME, 0, 8)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetPanTarget, CAM_DEFAULT, 20, 0, 30)
    Wait(3 * DT)
    Thread
        Loop(0)
            Call(GetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
            IfLt(LVar0, -58)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EndThread
    Call(LoadPath, 80 * DT, Ref(N(TwinkEmergePath)), ARRAY_COUNT(N(TwinkEmergePath)), EASING_LINEAR)
    Loop(0)
        Call(GetNextPathPos)
        Call(SetNpcPos, NPC_PARTNER, LVar1, LVar2, LVar3)
        Wait(1)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_RaiseArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Peach_0066)
    Call(SetPlayerAnimation, ANIM_Peach2_LowerArms)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Peach1_Idle)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0067)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_0068)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0069)
    Call(SpeakToPlayer, NPC_PLAYER, ANIM_Peach3_InformalTalk, ANIM_Peach1_Idle, 5, MSG_Peach_006A)
    Exec(N(EVS_SetupMusic))
    Call(ResetCam, CAM_DEFAULT, Float(4.0 / DT))
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
