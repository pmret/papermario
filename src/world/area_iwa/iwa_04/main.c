#include "iwa_04.h"

EvtScript N(EVS_ExitWalk_iwa_02_2) = EVT_EXIT_WALK(60, iwa_04_ENTRY_0, "iwa_02", iwa_02_ENTRY_2);
EvtScript N(EVS_ExitWalk_sbk_99_0) = EVT_EXIT_WALK(60, iwa_04_ENTRY_1, "sbk_99", sbk_99_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_iwa_02_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sbk_99_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_RUGGED)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, true, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Call(ParentColliderToModel, COLLIDER_o962, MODEL_o962)
    Call(ParentColliderToModel, COLLIDER_o979, MODEL_o979)
    Call(ParentColliderToModel, COLLIDER_o980, MODEL_o980)
    Call(ParentColliderToModel, COLLIDER_o981, MODEL_o981)
    Call(ParentColliderToModel, COLLIDER_o982, MODEL_o982)
    Call(ParentColliderToModel, COLLIDER_o983, MODEL_o983)
    Call(ParentColliderToModel, COLLIDER_o984, MODEL_o984)
    Call(ParentColliderToModel, COLLIDER_o985, MODEL_o985)
    Call(ParentColliderToModel, COLLIDER_o992, MODEL_o992)
    Call(ParentColliderToModel, COLLIDER_o993, MODEL_o993)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};
