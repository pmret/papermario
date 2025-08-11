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
    BindTrigger(Ref(N(EVS_ExitWalk_flo_13_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_flo_00_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
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
    { .colliderID = NO_COLLIDER }
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    Exec(N(EVS_MakeEntities))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o114, SURFACE_TYPE_SPIKES)
    Thread
        Call(ResetFromLava, Ref(N(SafeFloorColliders)))
    EndThread
    Call(EnableTexPanning, MODEL_o39, true)
    Call(EnableTexPanning, MODEL_o41, true)
    Call(EnableTexPanning, MODEL_o43, true)
    Call(EnableTexPanning, MODEL_o49, true)
    Call(EnableTexPanning, MODEL_o51, true)
    Call(EnableTexPanning, MODEL_o55, true)
    Call(EnableTexPanning, MODEL_o123, true)
    Call(EnableTexPanning, MODEL_o125, true)
    Call(EnableTexPanning, MODEL_o127, true)
    Call(EnableTexPanning, MODEL_o129, true)
    Call(EnableTexPanning, MODEL_o131, true)
    Call(EnableTexPanning, MODEL_o133, true)
    Call(EnableTexPanning, MODEL_o135, true)
    Call(EnableTexPanning, MODEL_o40, true)
    Call(EnableTexPanning, MODEL_o44, true)
    Call(EnableTexPanning, MODEL_o48, true)
    Call(EnableTexPanning, MODEL_o52, true)
    Call(EnableTexPanning, MODEL_o54, true)
    Call(EnableTexPanning, MODEL_o124, true)
    Call(EnableTexPanning, MODEL_o126, true)
    Call(EnableTexPanning, MODEL_o128, true)
    Call(EnableTexPanning, MODEL_o130, true)
    Call(EnableTexPanning, MODEL_o132, true)
    Call(EnableTexPanning, MODEL_o134, true)
    Call(EnableTexPanning, MODEL_o136, true)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  140,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP( -200,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Exec(N(EVS_SetupBubbles))
    Exec(N(EVS_SetupLogBridges))
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
