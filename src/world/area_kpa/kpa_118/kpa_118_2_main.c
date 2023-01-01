#include "kpa_118.h"

EvtScript N(EVS_ExitWalk_kpa_115_2) = EVT_EXIT_WALK(60, kpa_118_ENTRY_0, "kpa_115", kpa_115_ENTRY_2);
EvtScript N(EVS_ExitWalk_kpa_119_0) = EVT_EXIT_WALK(60, kpa_118_ENTRY_1, "kpa_119", kpa_119_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_115_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_119_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
