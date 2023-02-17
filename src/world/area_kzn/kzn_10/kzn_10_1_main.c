#include "kzn_10.h"

#include "../common/SmokeTexPanners.inc.c"

EvtScript N(EVS_ExitWalk_kzn_09_1) = EVT_EXIT_WALK(60, kzn_10_ENTRY_0, "kzn_09", kzn_09_ENTRY_1);
EvtScript N(EVS_ExitWalk_kzn_11_0) = EVT_EXIT_WALK(60, kzn_10_ENTRY_1, "kzn_11", kzn_11_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_09_1), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_11_0), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(func_8024030C_C7E48C)) {
    if (gPlayerStatus.flags & PS_FLAG_CAMERA_DOESNT_FOLLOW) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_10)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_THREAD
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_EQ(LVar0, kzn_10_ENTRY_0)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -445, -13, 0)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, -445, -13, 0)
        EVT_ELSE
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 425, -246, 0)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 425, -246, 0)
        EVT_END_IF
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_WAIT(2)
        EVT_CALL(N(func_8024030C_C7E48C))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_END_THREAD
    EVT_SET(LVar0, N(EVS_BindExitTriggers))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_1)
    EVT_EXEC(N(EVS_SetupSpinyTromp))
    EVT_SET(LVar0, MODEL_kem1)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeLeft))
    EVT_RETURN
    EVT_END
};
