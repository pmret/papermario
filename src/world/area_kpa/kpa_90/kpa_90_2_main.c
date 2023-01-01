#include "kpa_90.h"

EvtScript N(EVS_ExitWalk_kpa_91_0) = EVT_EXIT_WALK(60, kpa_90_ENTRY_1, "kpa_91", kpa_91_ENTRY_0);
EvtScript N(EVS_ExitWalk_kpa_32_1) = EVT_EXIT_WALK(60, kpa_90_ENTRY_0, "kpa_32", kpa_32_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_91_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_32_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
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
