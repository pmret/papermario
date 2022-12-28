#include "obk_06.h"

EvtScript N(EVS_ExitWalk_obk_02_2) = EVT_EXIT_WALK(60, obk_06_ENTRY_1, "obk_02", obk_02_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_obk_02_2)), TRIGGER_FLOOR_ABOVE, COLLIDER__deili, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(obk_06_ENTRY_0)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_obk_02_2)), TRIGGER_FLOOR_TOUCH, COLLIDER__deili, 1, 0)
        EVT_CASE_EQ(obk_06_ENTRY_1)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOOS_MANSION)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupBombables))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_RETURN
    EVT_END
};
