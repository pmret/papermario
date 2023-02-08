#include "tik_07.h"

#include "world/common/entity/Pipe.inc.c"

EvtScript N(EVS_ExitWalk_tik_04_1) = EVT_EXIT_WALK(60, tik_07_ENTRY_0, "tik_04", tik_04_ENTRY_1);

EvtScript N(EVS_GotoMap_tik_07_2) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_07"), tik_07_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GotoMap_tik_07_1) = {
    EVT_CALL(GotoMap, EVT_PTR("tik_07"), tik_07_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_tik_07_2) = EVT_EXIT_PIPE_VERTICAL(tik_07_ENTRY_1, COLLIDER_dokan_e1, N(EVS_GotoMap_tik_07_2));
EvtScript N(EVS_ExitWalk_tik_07_1) = EVT_EXIT_PIPE_VERTICAL(tik_07_ENTRY_2, COLLIDER_dokan_e2, N(EVS_GotoMap_tik_07_1));

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_04_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_07_2)), TRIGGER_FLOOR_TOUCH, COLLIDER_dokan_e1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_tik_07_1)), TRIGGER_FLOOR_TOUCH, COLLIDER_dokan_e2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_TOAD_TOWN_TUNNELS)
    EVT_CALL(SetSpriteShading, SHADING_TIK_07)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_SetupDrips))
    EVT_EXEC(N(EVS_SetupPlatforms))
    EVT_WAIT(1)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, tik_07_ENTRY_0)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_ELSE
        EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
    EVT_END_IF
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
