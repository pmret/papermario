#include "flo_18.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_17_1) = EVT_EXIT_WALK(60, flo_18_ENTRY_0, "flo_17", flo_17_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_flo_17_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    Return
    End
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o138, .pos = { -200.0,    0.0,  120.0 }},
    { .colliderID = COLLIDER_o140, .pos = {    0.0,    0.0,  120.0 }},
    { .colliderID = COLLIDER_o142, .pos = {  170.0,    0.0,  120.0 }},
    { .colliderID = NO_COLLIDER }
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, false)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    Exec(N(EVS_SetupFoliage))
    Exec(N(EVS_SetupMachine))
    Exec(N(EVS_SetupMachineDamageReactions))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o44, SURFACE_TYPE_SPIKES)
    Thread
        Call(ResetFromLava, Ref(N(SafeFloorColliders)))
    EndThread
    Call(EnableTexPanning, MODEL_o48, true)
    Call(EnableTexPanning, MODEL_o50, true)
    Call(EnableTexPanning, MODEL_o52, true)
    Call(EnableTexPanning, MODEL_o54, true)
    Call(EnableTexPanning, MODEL_o58, true)
    Call(EnableTexPanning, MODEL_o60, true)
    Call(EnableTexPanning, MODEL_o49, true)
    Call(EnableTexPanning, MODEL_o51, true)
    Call(EnableTexPanning, MODEL_o53, true)
    Call(EnableTexPanning, MODEL_o57, true)
    Call(EnableTexPanning, MODEL_o59, true)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -140,    0,    0,    0)
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
    Call(GetEntryID, LVar0)
    IfEq(LVar0, flo_18_ENTRY_0)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    Else
        Exec(N(EVS_Scene_LakilesterLikesBeingGood))
        Exec(N(EVS_BindExitTriggers))
    EndIf
    ExecWait(N(EVS_SetupMusic))
    IfGe(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Call(N(SpawnSunEffect))
    EndIf
    Return
    End
};
