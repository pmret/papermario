#include "isk_11.h"

EvtScript N(EVS_ExitWalk_isk_08_3) = EVT_EXIT_WALK(40, isk_11_ENTRY_0, "isk_08", isk_08_ENTRY_3);
EvtScript N(EVS_ExitWalk_isk_12_0) = EVT_EXIT_WALK(40, isk_11_ENTRY_1, "isk_12", isk_12_ENTRY_0);
EvtScript N(EVS_ExitWalk_isk_12_1) = EVT_EXIT_WALK(40, isk_11_ENTRY_2, "isk_12", isk_12_ENTRY_1);
EvtScript N(EVS_ExitWalk_isk_19_0) = EVT_EXIT_WALK(40, isk_11_ENTRY_3, "isk_19", isk_19_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_isk_08_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_isk_12_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_isk_12_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_isk_19_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_DRY_DRY_RUINS)
    Call(SetSpriteShading, SHADING_ISK_11)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.8))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    ExecWait(N(EVS_SetupPuzzle))
    ExecWait(N(EVS_SetupLock))
    IfLt(GB_StoryProgress, STORY_CH2_SOLVED_ARTIFACT_PUZZLE)
        Exec(N(EVS_ManageSecretPassage))
        Call(EnableGroup, MODEL_15, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2222, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2223, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2224, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2225, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2226, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2226, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2227, COLLIDER_FLAGS_UPPER_MASK)
    Else
        Call(EnableGroup, MODEL_g377, FALSE)
        Call(EnableModel, MODEL_o2205, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2087, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2088, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2089, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2090, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2091, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2092, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2186, COLLIDER_FLAGS_UPPER_MASK)
        Call(TranslateModel, MODEL_o2155, 0, -30, 0)
        Call(TranslateModel, MODEL_o2156, 0, -30, 0)
        Call(TranslateModel, MODEL_o2198, 0, -55, 0)
        Call(TranslateModel, MODEL_o2199, 0, -55, 0)
        Call(TranslateModel, MODEL_o2200, 0, -80, 0)
        Call(TranslateModel, MODEL_o2201, 0, -80, 0)
        Call(TranslateModel, MODEL_o2202, 0, -105, 0)
        Call(TranslateModel, MODEL_o2203, 0, -105, 0)
    EndIf
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};
