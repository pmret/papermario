#include "kzn_17.h"

#include "world/area_kzn/common/SmokeTexPanners.inc.c"

EvtScript N(EVS_ExitWalk_kzn_11_1) = EVT_EXIT_WALK(60, kzn_17_ENTRY_0, "kzn_11", kzn_11_ENTRY_1);
EvtScript N(EVS_ExitWalk_kzn_18_0) = EVT_EXIT_WALK(60, kzn_17_ENTRY_1, "kzn_18", kzn_18_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kzn_11_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kzn_18_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_17)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_1)
    EVT_EXEC(N(EVS_SetupSpinyTromp))
    EVT_SET(LVar0, MODEL_kem1)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeLeft))
    EVT_SET(LVar0, MODEL_kem2)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeRight))
    EVT_RETURN
    EVT_END
};
