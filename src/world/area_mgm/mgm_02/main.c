#include "mgm_02.h"

EvtScript N(EVS_SetupCamera) = {
    Call(UseSettingsFrom, CAM_DEFAULT, -300, -20, 200)
    Call(SetPanTarget, CAM_DEFAULT, 250, -20, 220)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(DisablePlayerInput, TRUE)
    Call(SetPlayerPos, 250, 200, 220)
    Call(SetNpcPos, NPC_PARTNER, 250, 200, 220)
    Call(InterpPlayerYaw, 90, 0)
    Label(10)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfNe(LVar1, -20)
        Wait(1)
        Goto(10)
    EndIf
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Main) = {
    SetUP_CAMERA_NO_LEAD()
    Exec(N(EVS_SetupCamera))
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_Dummy))
    ExecWait(N(EVS_InitializeMinigame))
    Return
    End
};
