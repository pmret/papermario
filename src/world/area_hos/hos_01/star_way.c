#include "hos_01.h"
#include "effects.h"

#include "world/common/EnableCameraFollowPlayerY.inc.c"

#define NAME_SUFFIX _StarWay
#include "world/common/todo/GetFloorCollider.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_Scene_StarWayOpened) = {
    Label(0)
        Call(N(GetFloorCollider_StarWay), LVar0)
        IfNe(LVar0, COLLIDER_o234)
            Wait(1)
            Goto(0)
        EndIf
    Call(DisablePlayerInput, TRUE)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(FacePlayerTowardPoint, -30, -160, 0)
    Wait(15)
    Call(ShowMessageAtScreenPos, MSG_HOS_005C, 160, 40)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, -100)
    Div(LVar0, 2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, 3)
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Call(ShowMessageAtScreenPos, MSG_HOS_005D, 160, 40)
    Call(SetMusicTrack, 0, SONG_STAR_WAY_OPENS, 0, 8)
#if VERSION_PAL
    Wait(30)
#else
    Wait(10)
#endif
    Call(EnableModel, MODEL_power, TRUE)
    Set(MV_StarBeamState, 1)
        Label(10)
        IfNe(MV_StarBeamState, 2)
            Wait(1)
            Goto(10)
        EndIf
    Call(UseSettingsFrom, CAM_DEFAULT, -100, 245, 0)
    Call(SetPanTarget, CAM_DEFAULT, -100, 245, 0)
    Call(SetCamDistance, CAM_DEFAULT, 600)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-11.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.5))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    PlayEffect(EFFECT_75, 0, -30, 250, -160, 1, -1)
    Set(MV_StarBeamFXPtr, LVarF)
    Call(N(func_80240AAC_A1132C), MV_StarBeamFXPtr)
    Call(MakeLerp, 1, 255, 55, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetStarBeamMasterAlpha), MV_StarBeamFXPtr, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(45)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar0, -100)
    Div(LVar0, 2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-9.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10)
    Call(ShowMessageAtScreenPos, MSG_HOS_005E, 160, 40)
    Call(ResetCam, CAM_DEFAULT, Float(5.0))
    Set(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
    Call(SetMusicTrack, 0, SONG_SHOOTING_STAR_SUMMIT, 0, 8)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_AscendStarBeam) = {
    Call(N(func_80240B10_A11390), MV_StarBeamFXPtr)
    Call(UseSettingsFrom, CAM_DEFAULT, -30, 250, -160)
    Call(SetPanTarget, CAM_DEFAULT, -30, 250, -160)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, -30, -160, 0)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetMusicTrack, 0, SONG_STAR_WAY_OPENS, 1, 8)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(1.0))
    Call(NpcJump0, NPC_PARTNER, -30, 250, -170, 15)
    Thread
        Set(LVar2, 90)
        Call(MakeLerp, 1, 90, 60, EASING_QUADRATIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Add(LVar2, LVar0)
            Call(InterpPlayerYaw, LVar2, 0)
            Call(SetNpcRotation, NPC_PARTNER, 0, LVar2, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Loop(0)
            Add(LVar2, LVar0)
            Call(InterpPlayerYaw, LVar2, 0)
            Call(SetNpcRotation, NPC_PARTNER, 0, LVar2, 0)
            Wait(1)
        EndLoop
    EndThread
    Wait(30)
    Call(N(EnableCameraFollowPlayerY))
    Thread
        Label(10)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfLt(LVar1, 430)
            Wait(1)
            Goto(10)
        EndIf
    EndThread
    Call(GetPlayerPos, LVar2, LVar3, LVar4)
    Set(LVar5, LVar4)
    Add(LVar5, -10)
    Call(MakeLerp, LVar3, 700, 90, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(SetPlayerPos, LVar2, LVar0, LVar4)
        Call(SetNpcPos, NPC_PARTNER, LVar2, LVar0, LVar5)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};
