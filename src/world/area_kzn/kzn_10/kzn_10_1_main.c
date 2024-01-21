#include "kzn_10.h"

#include "../common/SmokeTexPanners.inc.c"

EvtScript N(EVS_ExitWalk_kzn_09_1) = EVT_EXIT_WALK(60, kzn_10_ENTRY_0, "kzn_09", kzn_09_ENTRY_1);
EvtScript N(EVS_ExitWalk_kzn_11_0) = EVT_EXIT_WALK(60, kzn_10_ENTRY_1, "kzn_11", kzn_11_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(N(EVS_ExitWalk_kzn_09_1), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(N(EVS_ExitWalk_kzn_11_0), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    Return
    End
};

API_CALLABLE(N(func_8024030C_C7E48C)) {
    if (gPlayerStatus.flags & PS_FLAG_CAMERA_DOESNT_FOLLOW) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    Call(SetSpriteShading, SHADING_KZN_10)
    SetUP_CAMERA_DEFAULT()
    Thread
        Call(GetEntryID, LVar0)
        IfEq(LVar0, kzn_10_ENTRY_0)
            Call(UseSettingsFrom, CAM_DEFAULT, -445, -13, 0)
            Call(SetPanTarget, CAM_DEFAULT, -445, -13, 0)
        Else
            Call(UseSettingsFrom, CAM_DEFAULT, 425, -246, 0)
            Call(SetPanTarget, CAM_DEFAULT, 425, -246, 0)
        EndIf
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Wait(2)
        Call(N(func_8024030C_C7E48C))
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
    EndThread
    Set(LVar0, N(EVS_BindExitTriggers))
    Exec(EnterWalk)
    Wait(1)
    Call(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    Call(PlayAmbientSounds, AMBIENT_LAVA_1)
    Exec(N(EVS_SetupSpinyTromp))
    Set(LVar0, MODEL_kem1)
    Exec(N(EVS_StartTexPanner_SmokeLeft))
    Return
    End
};
