#include "sam_05.h"
#include "effects.h"

EvtScript N(EVS_ExitWalk_sam_04_1) = EVT_EXIT_WALK(60, sam_05_ENTRY_0, "sam_04", sam_04_ENTRY_1);
EvtScript N(EVS_ExitWalk_sam_06_0) = EVT_EXIT_WALK(60, sam_05_ENTRY_1, "sam_06", sam_06_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_sam_04_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_sam_06_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHIVER_SNOWFIELD)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    IfLt(GB_StoryProgress, STORY_CH7_DEFEATED_MONSTAR)
        Call(MakeNpcs, FALSE, Ref(N(BeforeNPCs)))
    Else
        Call(MakeNpcs, FALSE, Ref(N(AfterNPCs)))
    EndIf
    ExecWait(N(EVS_MakeEntities))
    ExecWait(N(EVS_SetupMusic))
    PlayEffect(EFFECT_SNOWFALL, 0, 120)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_ground, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o55, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o59, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o60, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilie, SURFACE_TYPE_SNOW)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliw, SURFACE_TYPE_SNOW)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    Return
    End
};
