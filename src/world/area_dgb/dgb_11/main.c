#include "dgb_11.h"

EvtScript N(EVS_ExitDoor_dgb_02_3) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, dgb_11_ENTRY_0)
    Set(LVar1, COLLIDER_deilits)
    Set(LVar2, MODEL_o109)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("dgb_02"), dgb_02_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(dgb_11_ENTRY_0)
            Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
            Set(LVar2, MODEL_o109)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
            Return
        CaseEq(dgb_11_ENTRY_1)
            Call(UseSettingsFrom, CAM_DEFAULT, 500, 0, -100)
            Call(SetPanTarget, CAM_DEFAULT, 500, 0, -100)
            Set(LVar3, 1)
        CaseEq(dgb_11_ENTRY_2)
            Call(UseSettingsFrom, CAM_DEFAULT, 500, 75, -250)
            Call(SetPanTarget, CAM_DEFAULT, 500, 75, -250)
            Set(LVar3, 75)
        CaseEq(dgb_11_ENTRY_3)
            Call(SetZoneEnabled, ZONE_o203, FALSE)
            Call(UseSettingsFrom, CAM_DEFAULT, 375, 0, -175)
            Call(SetPanTarget, CAM_DEFAULT, 375, 0, -175)
            Set(AF_DGB_02, TRUE)
            Set(LVar3, 1)
    EndSwitch
    Call(DisablePlayerInput, TRUE)
    Call(InterpPlayerYaw, 180, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLe(LVar1, LVar3)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    BindTrigger(Ref(N(EVS_ExitDoor_dgb_02_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilits, 1, 0)
    Exec(N(EVS_EnterMap))
    Return
    End
};
