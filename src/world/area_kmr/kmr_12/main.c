#include "kmr_12.h"

EvtScript N(EVS_ExitWalk_kmr_07_1) = EVT_EXIT_WALK(60, kmr_12_ENTRY_0, "kmr_07", kmr_07_ENTRY_1);
EvtScript N(EVS_ExitWalk_kmr_11_0) = EVT_EXIT_WALK(60, kmr_12_ENTRY_1, "kmr_11", kmr_11_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_07_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_11_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_GOOMBA_ROAD)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    BindTrigger(Ref(N(EVS_OnReadBillboard)), TRIGGER_WALL_PRESS_A, COLLIDER_o78, 1, 0)
    Return
    End
};
