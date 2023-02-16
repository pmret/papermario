#include "kzn_09.h"

EvtScript N(EVS_ExitWalk_kzn_03_2) = EVT_EXIT_WALK(60, kzn_09_ENTRY_0, "kzn_03", kzn_03_ENTRY_2);
EvtScript N(EVS_ExitWalk_kzn_10_0) = EVT_EXIT_WALK(60, kzn_09_ENTRY_1, "kzn_10", kzn_10_ENTRY_0);
EvtScript N(EVS_ExitWalk_kzn_03_4) = EVT_EXIT_WALK(60, kzn_09_ENTRY_2, "kzn_03", kzn_03_ENTRY_4);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_03_2), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_10_0), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_BIND_TRIGGER(N(EVS_ExitWalk_kzn_03_4), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_09)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(SetMusicTrack, 0, SONG_MT_LAVALAVA, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_LAVA_1)
    EVT_SET(LVar0, N(EVS_BindExitTriggers))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_EXEC_WAIT(N(EVS_SetupZipline))
    EVT_RETURN
    EVT_END
};
