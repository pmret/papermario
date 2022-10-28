#include "kmr_12.h"

EvtScript N(EVS_ExitWalk_kmr_07_1) = EVT_EXIT_WALK(60, kmr_12_ENTRY_0, "kmr_07", kmr_07_ENTRY_1);
EvtScript N(EVS_ExitWalk_kmr_11_0) = EVT_EXIT_WALK(60, kmr_12_ENTRY_1, "kmr_11", kmr_11_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kmr_07_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kmr_11_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_GOOMBA_ROAD)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnReadBillboard)), TRIGGER_WALL_PRESS_A, COLLIDER_o78, 1, 0)
    EVT_RETURN
    EVT_END
};
