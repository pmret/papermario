#include "jan_14.h"

EvtScript N(EVS_ExitWalk_jan_15_0) = EVT_EXIT_WALK(60, jan_14_ENTRY_1, "jan_15", jan_15_ENTRY_0);
EvtScript N(EVS_ExitWalk_jan_13_1) = EVT_EXIT_WALK(60, jan_14_ENTRY_0, "jan_13", jan_13_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_13_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_15_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_SetupVines))
    EVT_EXEC(N(EVS_SetupTrees))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilits, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitn, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_CALL(SetMusicTrack, 0, SONG_DEEP_JUNGLE, 0, 8)
    EVT_CALL(PlayAmbientSounds, AMBIENT_JUNGLE)
    EVT_RETURN
    EVT_END
};
