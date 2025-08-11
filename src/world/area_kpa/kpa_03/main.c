#include "kpa_03.h"

#include "world/common/atomic/CreateDarkness.inc.c"

EvtScript N(EVS_ExitWalk_kpa_01_1) = EVT_EXIT_WALK(60, kpa_03_ENTRY_0, "kpa_01", kpa_01_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_04_0) = EVT_EXIT_WALK(60, kpa_03_ENTRY_1, "kpa_04", kpa_04_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_01_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
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
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_CreateDarkness))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    Return
    End
};
