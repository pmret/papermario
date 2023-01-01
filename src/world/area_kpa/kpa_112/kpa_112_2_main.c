#include "kpa_112.h"
#include "sprite.h"

EvtScript N(EVS_ExitWalk_kpa_111_1) = EVT_EXIT_WALK(40, kpa_112_ENTRY_0, "kpa_111", kpa_111_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_113_0) = EVT_EXIT_WALK(40, kpa_112_ENTRY_1, "kpa_113", kpa_113_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_111_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_113_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
