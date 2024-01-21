#include "kpa_90.h"

EvtScript N(EVS_ExitWalk_kpa_91_0) = EVT_EXIT_WALK(60, kpa_90_ENTRY_1, "kpa_91", kpa_91_ENTRY_0);
EvtScript N(EVS_ExitWalk_kpa_32_1) = EVT_EXIT_WALK(60, kpa_90_ENTRY_0, "kpa_32", kpa_32_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_91_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_32_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
