#include "kpa_115.h"

EvtScript N(EVS_ExitWalk_kpa_114_1) = EVT_EXIT_WALK(60, kpa_115_ENTRY_0, "kpa_114", kpa_114_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_116_0) = EVT_EXIT_WALK(60, kpa_115_ENTRY_1, "kpa_116", kpa_116_ENTRY_0);
EvtScript N(EVS_ExitWalk_kpa_118_0) = EVT_EXIT_WALK(60, kpa_115_ENTRY_2, "kpa_118", kpa_118_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_114_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_118_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_116_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_SetupStatues))
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};

MAP_RODATA_PAD(1, exits);
