#include "kpa_04.h"

EvtScript N(EVS_ExitWalk_kpa_03_1) = EVT_EXIT_WALK(60, kpa_04_ENTRY_0, "kpa_03", kpa_03_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_81_3) = EVT_EXIT_WALK(60, kpa_04_ENTRY_1, "kpa_81", kpa_81_ENTRY_3);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_03_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_81_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Exec(N(EVS_SetupStatues))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
