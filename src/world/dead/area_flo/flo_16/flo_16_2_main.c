#include "flo_16.h"
#include "effects.h"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_00_4) = EVT_EXIT_WALK(60, flo_16_ENTRY_0, "flo_00", flo_00_ENTRY_4);
EvtScript N(EVS_ExitWalk_flo_17_0) = EVT_EXIT_WALK(60, flo_16_ENTRY_1, "flo_17", flo_17_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_00_4)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_17_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o190, .pos = { -310.0,    0.0,    0.0 }},
    { .colliderID = COLLIDER_o191, .pos = {  305.0,  100.0,    0.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupVines))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o174, SURFACE_TYPE_SPIKES)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_o59, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o142, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o58, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o136, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o146, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o143, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o135, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o138, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o139, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o140, TRUE)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_LABEL(0)
        EVT_ADD(LVar0, 140)
        EVT_IF_GT(LVar0, 0x10000)
            EVT_ADD(LVar0, -0x10000)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 1, 0, LVar0, 0)
        EVT_ADD(LVar1, -200)
        EVT_IF_LT(LVar1, 0)
            EVT_ADD(LVar1, 0x10000)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, 2, 0, LVar1, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_EXEC(N(EVS_SetupPillarPuzzle))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(N(SpawnSunEffect))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
