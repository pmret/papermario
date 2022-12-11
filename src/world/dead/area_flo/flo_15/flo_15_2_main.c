#include "flo_15.h"

EvtScript N(EVS_ExitWalk_flo_13_1) = EVT_EXIT_WALK(60, flo_15_ENTRY_0, "flo_13", flo_13_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_13_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, flo_15_ENTRY_1)
        EVT_EXEC(N(EVS_Scene_SunReturns))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g58, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_MonitorFallingStairs))
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
