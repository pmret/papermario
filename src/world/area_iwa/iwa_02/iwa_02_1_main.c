#include "iwa_02.h"

EvtScript N(EVS_ExitWalk_iwa_01_2) = EVT_EXIT_WALK(60, iwa_02_ENTRY_0, "iwa_01", iwa_01_ENTRY_2);
EvtScript N(EVS_ExitWalk_iwa_01_3) = EVT_EXIT_WALK(60, iwa_02_ENTRY_1, "iwa_01", iwa_01_ENTRY_3);
EvtScript N(EVS_ExitWalk_iwa_04_0) = EVT_EXIT_WALK(60, iwa_02_ENTRY_2, "iwa_04", iwa_04_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_iwa_01_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_iwa_01_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_iwa_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_RUGGED)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(SetMusicTrack, 0, SONG_MT_RUGGED, 0, 8)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};
