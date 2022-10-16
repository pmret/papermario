#include "iwa_04.h"

EvtScript N(EVS_ExitWalk_iwa_02_2) = EVT_EXIT_WALK(60, iwa_04_ENTRY_0, "iwa_02", iwa_02_ENTRY_2);
EvtScript N(EVS_ExitWalk_sbk_99_0) = EVT_EXIT_WALK(60, iwa_04_ENTRY_1, "sbk_99", sbk_99_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_iwa_02_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_sbk_99_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_RUGGED)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(ParentColliderToModel, COLLIDER_o962, MODEL_o962)
    EVT_CALL(ParentColliderToModel, COLLIDER_o979, MODEL_o979)
    EVT_CALL(ParentColliderToModel, COLLIDER_o980, MODEL_o980)
    EVT_CALL(ParentColliderToModel, COLLIDER_o981, MODEL_o981)
    EVT_CALL(ParentColliderToModel, COLLIDER_o982, MODEL_o982)
    EVT_CALL(ParentColliderToModel, COLLIDER_o983, MODEL_o983)
    EVT_CALL(ParentColliderToModel, COLLIDER_o984, MODEL_o984)
    EVT_CALL(ParentColliderToModel, COLLIDER_o985, MODEL_o985)
    EVT_CALL(ParentColliderToModel, COLLIDER_o992, MODEL_o992)
    EVT_CALL(ParentColliderToModel, COLLIDER_o993, MODEL_o993)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
