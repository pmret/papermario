#include "isk_04.h"

EvtScript N(EVS_ExitWalk_isk_03_2) = EVT_EXIT_WALK(40, isk_04_ENTRY_0, "isk_03", isk_03_ENTRY_2);
EvtScript N(EVS_ExitWalk_isk_07_1) = EVT_EXIT_WALK(40, isk_04_ENTRY_1, "isk_07", isk_07_ENTRY_1);
EvtScript N(EVS_ExitWalk_isk_06_0) = EVT_EXIT_WALK(40, isk_04_ENTRY_2, "isk_06", isk_06_ENTRY_0);
EvtScript N(EVS_ExitWalk_isk_06_1) = EVT_EXIT_WALK(40, isk_04_ENTRY_3, "isk_06", isk_06_ENTRY_1);
EvtScript N(EVS_ExitWalk_isk_05_0) = EVT_EXIT_WALK(40, isk_04_ENTRY_4, "isk_05", isk_05_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_03_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_07_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_06_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_06_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    EVT_CALL(SetSpriteShading, SHADING_ISK_04)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(GetDemoState, LVar0)
    EVT_IF_NE(LVar0, DEMO_STATE_NONE)
        EVT_EXEC_WAIT(N(EVS_SetupObstructions))
        EVT_EXEC_WAIT(N(EVS_SetupDemo))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupObstructions))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
