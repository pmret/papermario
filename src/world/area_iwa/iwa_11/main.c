#include "iwa_11.h"

API_CALLABLE(N(CheckForSkipInput)) {
    if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_B)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_MonitorSceneSkip) = {
    IfLt(GB_StoryProgress, STORY_CH2_ARRIVED_AT_MT_RUGGED)
        Return
    EndIf
    Call(GetEntryID, LVar0)
    Call(N(CheckForSkipInput))
    Switch(LVar0)
        CaseEq(iwa_11_ENTRY_0)
            Call(GotoMap, Ref("iwa_10"), iwa_10_ENTRY_0)
        CaseEq(iwa_11_ENTRY_1)
            Call(GotoMap, Ref("mac_03"), mac_03_ENTRY_1)
    EndSwitch
    Wait(100)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_RUGGED)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 30, 16, 4096) // uses fov 25 instead of 30
    Call(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamEnabled, CAM_DEFAULT, true)
    Call(SetCamLeadPlayer, CAM_DEFAULT, false)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamPosA, CAM_DEFAULT, -5800, 0)
    Call(SetCamPosB, CAM_DEFAULT, 5700, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliti, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitm, COLLIDER_FLAGS_UPPER_MASK)
    ExecWait(N(EVS_InitializeTrainScene))
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(iwa_11_ENTRY_0)
            Exec(N(EVS_TravelToMtRugged))
        CaseEq(iwa_11_ENTRY_1)
            Exec(N(EVS_TravelToToadTown))
    EndSwitch
    Exec(N(EVS_UpdateSceneryPos))
    Exec(N(EVS_MonitorSceneSkip))
    Exec(N(EVS_SetupMusic))
    Return
    End
};
