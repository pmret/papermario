#include "flo_18.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_17_1) = EVT_EXIT_WALK(60, flo_18_ENTRY_0, "flo_17", flo_17_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_17_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o138, .pos = { -200.0,    0.0,  120.0 }},
    { .colliderID = COLLIDER_o140, .pos = {    0.0,    0.0,  120.0 }},
    { .colliderID = COLLIDER_o142, .pos = {  170.0,    0.0,  120.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_SetupFoliage))
    EVT_EXEC(N(EVS_SetupMachine))
    EVT_EXEC(N(EVS_SetupMachineDamageReactions))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o44, SURFACE_TYPE_SPIKES)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_o48, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o50, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o52, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o54, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o58, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o60, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o49, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o51, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o53, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o57, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o59, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -140,    0,    0,    0)
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
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, flo_18_ENTRY_0)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_ELSE
        EVT_EXEC(N(EVS_Scene_LakilesterLikesBeingGood))
        EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(N(SpawnSunEffect))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
