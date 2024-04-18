#include "omo_05.h"

EvtScript N(EVS_ExitWalk_omo_17_0) = EVT_EXIT_WALK(60, omo_05_ENTRY_0, "omo_17", omo_17_ENTRY_0);
EvtScript N(EVS_ExitWalk_omo_17_1) = EVT_EXIT_WALK(60, omo_05_ENTRY_1, "omo_17", omo_17_ENTRY_1);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_omo_17_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_omo_17_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili4, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHY_GUYS_TOYBOX)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupGizmos))
    Exec(N(EVS_SetupMusic))
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(SetGroupVisibility, MODEL_popo, MODEL_GROUP_HIDDEN)
    IfGe(GB_StoryProgress, STORY_CH4_GAVE_CAKE_TO_GOURMET_GUY)
        Call(RotateModel, MODEL_o331, 105, 0, 1, 0)
        Call(RotateModel, MODEL_o332, 105, 0, 1, 0)
        Call(RotateModel, MODEL_o333, 105, 0, 1, 0)
        Call(RotateModel, MODEL_o328, 105, 0, 1, 0)
        Call(RotateModel, MODEL_o329, 105, 0, 1, 0)
        Call(RotateModel, MODEL_o330, 105, 0, 1, 0)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt2, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};
