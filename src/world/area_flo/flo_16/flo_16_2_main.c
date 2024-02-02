#include "flo_16.h"
#include "effects.h"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_00_4) = EVT_EXIT_WALK(60, flo_16_ENTRY_0, "flo_00", flo_00_ENTRY_4);
EvtScript N(EVS_ExitWalk_flo_17_0) = EVT_EXIT_WALK(60, flo_16_ENTRY_1, "flo_17", flo_17_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_flo_00_4)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_flo_17_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o190, .pos = { -310.0,    0.0,    0.0 }},
    { .colliderID = COLLIDER_o191, .pos = {  305.0,  100.0,    0.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupVines))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o174, SURFACE_TYPE_SPIKES)
    Thread
        Call(ResetFromLava, Ref(N(SafeFloorColliders)))
    EndThread
    Call(EnableTexPanning, MODEL_o59, TRUE)
    Call(EnableTexPanning, MODEL_o142, TRUE)
    Call(EnableTexPanning, MODEL_o58, TRUE)
    Call(EnableTexPanning, MODEL_o136, TRUE)
    Call(EnableTexPanning, MODEL_o146, TRUE)
    Call(EnableTexPanning, MODEL_o143, TRUE)
    Call(EnableTexPanning, MODEL_o135, TRUE)
    Call(EnableTexPanning, MODEL_o138, TRUE)
    Call(EnableTexPanning, MODEL_o139, TRUE)
    Call(EnableTexPanning, MODEL_o140, TRUE)
    Thread
        Set(LVar0, 0)
        Set(LVar1, 0)
        Label(0)
        Add(LVar0, 140)
        IfGt(LVar0, 0x10000)
            Add(LVar0, -0x10000)
        EndIf
        Call(SetTexPanOffset, 1, 0, LVar0, 0)
        Add(LVar1, -200)
        IfLt(LVar1, 0)
            Add(LVar1, 0x10000)
        EndIf
        Call(SetTexPanOffset, 2, 0, LVar1, 0)
        Wait(1)
        Goto(0)
    EndThread
    Exec(N(EVS_SetupPillarPuzzle))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    ExecWait(N(EVS_SetupMusic))
    IfGe(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Call(N(SpawnSunEffect))
    EndIf
    Return
    End
};
