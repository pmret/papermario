#include "kpa_115.h"

EvtScript N(EVS_ExitWalk_kpa_114_1) = EVT_EXIT_WALK(60, kpa_115_ENTRY_0, "kpa_114", kpa_114_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_116_0) = EVT_EXIT_WALK(60, kpa_115_ENTRY_1, "kpa_116", kpa_116_ENTRY_0);
EvtScript N(EVS_ExitWalk_kpa_118_0) = EVT_EXIT_WALK(60, kpa_115_ENTRY_2, "kpa_118", kpa_118_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_114_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_118_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_116_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Exec(N(EVS_SetupStatues))
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};

MAP_RODATA_PAD(1, exits);
