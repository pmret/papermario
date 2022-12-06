#include "isk_11.h"

EvtScript N(EVS_ExitWalk_isk_08_3) = EVT_EXIT_WALK(40, isk_11_ENTRY_0, "isk_08", isk_08_ENTRY_3);
EvtScript N(EVS_ExitWalk_isk_12_0) = EVT_EXIT_WALK(40, isk_11_ENTRY_1, "isk_12", isk_12_ENTRY_0);
EvtScript N(EVS_ExitWalk_isk_12_1) = EVT_EXIT_WALK(40, isk_11_ENTRY_2, "isk_12", isk_12_ENTRY_1);
EvtScript N(EVS_ExitWalk_isk_19_0) = EVT_EXIT_WALK(40, isk_11_ENTRY_3, "isk_19", isk_19_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_08_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_12_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_12_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_isk_19_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    EVT_CALL(SetSpriteShading, SHADING_ISK_11)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.8))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC_WAIT(N(EVS_SetupPuzzle))
    EVT_EXEC_WAIT(N(EVS_SetupLock))
    EVT_IF_LT(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
        EVT_EXEC(N(EVS_ManageSecretPassage))
        EVT_CALL(EnableGroup, MODEL_15, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2222, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2223, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2224, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2225, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2226, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2226, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2227, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_g377, FALSE)
        EVT_CALL(EnableModel, MODEL_o2205, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2087, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2088, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2089, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2090, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2091, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2092, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2186, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(TranslateModel, MODEL_o2155, 0, -30, 0)
        EVT_CALL(TranslateModel, MODEL_o2156, 0, -30, 0)
        EVT_CALL(TranslateModel, MODEL_o2198, 0, -55, 0)
        EVT_CALL(TranslateModel, MODEL_o2199, 0, -55, 0)
        EVT_CALL(TranslateModel, MODEL_o2200, 0, -80, 0)
        EVT_CALL(TranslateModel, MODEL_o2201, 0, -80, 0)
        EVT_CALL(TranslateModel, MODEL_o2202, 0, -105, 0)
        EVT_CALL(TranslateModel, MODEL_o2203, 0, -105, 0)
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};