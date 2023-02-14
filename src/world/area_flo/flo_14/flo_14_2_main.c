#include "flo_14.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_LEFT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_00_1) = EVT_EXIT_WALK(60, flo_14_ENTRY_0, "flo_00", flo_00_ENTRY_1);
EvtScript N(EVS_ExitWalk_flo_13_0) = EVT_EXIT_WALK(60, flo_14_ENTRY_1, "flo_13", flo_13_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_13_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_00_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o129, .pos = { -500.0,    0.0,  -90.0 }},
    { .colliderID = COLLIDER_o137, .pos = { -510.0,    0.0,    0.0 }},
    { .colliderID = COLLIDER_o155, .pos = { -500.0,    0.0,  110.0 }},
    { .colliderID = COLLIDER_o156, .pos = { -250.0,    0.0,  -90.0 }},
    { .colliderID = COLLIDER_o140, .pos = { -240.0,    0.0,    0.0 }},
    { .colliderID = COLLIDER_o157, .pos = { -250.0,    0.0,  110.0 }},
    { .colliderID = COLLIDER_o151, .pos = {  -50.0,    0.0,   25.0 }},
    { .colliderID = COLLIDER_o152, .pos = {   70.0,   60.0,  -95.0 }},
    { .colliderID = COLLIDER_o153, .pos = {  410.0,   60.0,  -95.0 }},
    { .colliderID = COLLIDER_o154, .pos = {  550.0,    0.0,   50.0 }},
    { .colliderID = COLLIDER_o158, .pos = {  -50.0,    0.0,  110.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_MakeEntities))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o114, SURFACE_TYPE_SPIKES)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_o39, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o41, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o43, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o49, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o51, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o55, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o123, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o125, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o127, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o129, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o131, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o133, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o135, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o40, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o44, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o48, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o52, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o54, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o124, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o126, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o128, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o130, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o132, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o134, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o136, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  140,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP( -200,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_EXEC(N(EVS_SetupBubbles))
    EVT_EXEC(N(EVS_SetupLogBridges))
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
