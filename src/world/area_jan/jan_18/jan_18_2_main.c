#include "jan_18.h"

EvtScript N(EVS_ExitWalk_jan_17_1) = EVT_EXIT_WALK(60, jan_18_ENTRY_0, "jan_17", jan_17_ENTRY_1);
EvtScript N(EVS_ExitWalk_jan_19_0) = EVT_EXIT_WALK(60, jan_18_ENTRY_1, "jan_19", jan_19_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_jan_17_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_jan_19_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    SetUP_CAMERA_DEFAULT()
    ExecWait(N(EVS_MakeEntities))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitse, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitn, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    ExecWait(N(EVS_SetupMusic))
    Return
    End
};
