#include "jan_19.h"

API_CALLABLE(N(EnableFog)) {
    enable_world_fog();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_jan_18_1) = EVT_EXIT_WALK(60, jan_19_ENTRY_0, "jan_18", jan_18_ENTRY_1);
EvtScript N(EVS_ExitWalk_jan_23_0) = EVT_EXIT_WALK(60, jan_19_ENTRY_1, "jan_23", jan_23_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_18_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_23_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    EVT_CALL(SetSpriteShading, SHADING_JAN_19)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_CALL(N(EnableFog))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
