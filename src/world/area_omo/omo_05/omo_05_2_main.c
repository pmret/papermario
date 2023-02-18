#include "omo_05.h"

EvtScript N(EVS_ExitWalk_omo_17_0) = EVT_EXIT_WALK(60, omo_05_ENTRY_0, "omo_17", omo_17_ENTRY_0);
EvtScript N(EVS_ExitWalk_omo_17_1) = EVT_EXIT_WALK(60, omo_05_ENTRY_1, "omo_17", omo_17_ENTRY_1);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_17_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_omo_17_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili4, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupGizmos))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetGroupVisibility, MODEL_popo, MODEL_GROUP_HIDDEN)
    EVT_IF_GE(GB_StoryProgress, STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
        EVT_CALL(RotateModel, MODEL_o331, 105, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o332, 105, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o333, 105, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o328, 105, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o329, 105, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o330, 105, 0, 1, 0)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
