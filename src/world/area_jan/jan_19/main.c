#include "jan_19.h"

API_CALLABLE(N(EnableFog)) {
    enable_world_fog();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_jan_18_1) = EVT_EXIT_WALK(60, jan_19_ENTRY_0, "jan_18", jan_18_ENTRY_1);
EvtScript N(EVS_ExitWalk_jan_23_0) = EVT_EXIT_WALK(60, jan_19_ENTRY_1, "jan_23", jan_23_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_jan_18_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_jan_23_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    Call(SetSpriteShading, SHADING_JAN_19)
    Call(SetCamLeadPlayer, CAM_DEFAULT, false)
    EVT_SETUP_CAMERA_DEFAULT()
    ExecWait(N(EVS_MakeEntities))
    Call(N(EnableFog))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    ExecWait(N(EVS_SetupMusic))
    Return
    End
};
