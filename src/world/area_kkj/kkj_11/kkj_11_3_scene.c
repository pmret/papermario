#include "kkj_11.h"

EvtScript N(EVS_OpenAndCloseDoor) = {
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_OPEN, 0)
    Call(MakeLerp, 0, -120, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_door6, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(40)
    Call(MakeLerp, -120, 0, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_door6, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_ttw, SOUND_BASIC_DOOR_CLOSE, 0)
    Return
    End
};

EvtScript N(EVS_FirstTimeEnterHall) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_PARTNER, LVar0, 10, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 444)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 444)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(1)
    Wait(30)
    Call(UseSettingsFrom, CAM_DEFAULT, -430, 0, 50)
    Call(SetPanTarget, CAM_DEFAULT, -430, 0, 50)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(30)
    Set(AF_KKJ_06, TRUE)
    Exec(N(EVS_OpenAndCloseDoor))
    Wait(10)
    Thread
        Wait(5)
        Call(NpcMoveTo, NPC_PARTNER, -455, 50, 30)
    EndThread
    Call(PlayerMoveTo, -430, 50, 30)
    Call(SetPlayerPos, -430, 0, 50)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Wait(5)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
