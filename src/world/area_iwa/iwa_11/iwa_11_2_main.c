#include "iwa_11.h"

API_CALLABLE(N(CheckForSkipInput)) {
    if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_B)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_MonitorSceneSkip) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_ARRIVED_AT_MT_RUGGED)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_CALL(N(CheckForSkipInput))
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(iwa_11_ENTRY_0)
            EVT_CALL(GotoMap, EVT_PTR("iwa_10"), iwa_10_ENTRY_0)
        EVT_CASE_EQ(iwa_11_ENTRY_1)
            EVT_CALL(GotoMap, EVT_PTR("mac_03"), mac_03_ENTRY_1)
    EVT_END_SWITCH
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_RUGGED)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 30, 16, 4096) // uses fov 25 instead of 30
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -5800, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 5700, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliti, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitm, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC_WAIT(N(EVS_InitializeTrainScene))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(iwa_11_ENTRY_0)
            EVT_EXEC(N(EVS_TravelToMtRugged))
        EVT_CASE_EQ(iwa_11_ENTRY_1)
            EVT_EXEC(N(EVS_TravelToToadTown))
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_UpdateSceneryPos))
    EVT_EXEC(N(EVS_MonitorSceneSkip))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
