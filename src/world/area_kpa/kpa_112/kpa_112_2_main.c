#include "kpa_112.h"
#include "sprite.h"

EvtScript N(EVS_ExitWalk_kpa_111_1) = EVT_EXIT_WALK(40, kpa_112_ENTRY_0, "kpa_111", kpa_111_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_113_0) = EVT_EXIT_WALK(40, kpa_112_ENTRY_1, "kpa_113", kpa_113_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_111_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_113_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Exec(N(EVS_SetupMusic))
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};
