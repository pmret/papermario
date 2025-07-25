#include "omo_11.h"

EvtScript N(EVS_ExitWalk_omo_12_0) = EVT_EXIT_WALK(60, omo_11_ENTRY_0, "omo_12", omo_12_ENTRY_0);
EvtScript N(EVS_ExitWalk_omo_10_0) = EVT_EXIT_WALK(60, omo_11_ENTRY_1, "omo_10", omo_10_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_omo_12_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_omo_10_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupMusic))
    ExecWait(N(EVS_SetupGizmos))
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};
