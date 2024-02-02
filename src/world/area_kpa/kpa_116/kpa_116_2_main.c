#include "kpa_116.h"

EvtScript N(EVS_ExitWalk_kpa_115_1) = EVT_EXIT_WALK(60, kpa_116_ENTRY_0, "kpa_115", kpa_115_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_117_0) = EVT_EXIT_WALK(60, kpa_116_ENTRY_1, "kpa_117", kpa_117_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_115_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_117_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
