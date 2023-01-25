#include "flo_17.h"
#include "effects.h"

#include "../common/FlowerSpawnRegion.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_RIGHT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_flo_16_1) = EVT_EXIT_WALK(60, flo_17_ENTRY_0, "flo_16", flo_16_ENTRY_1);
EvtScript N(EVS_ExitWalk_flo_18_0) = EVT_EXIT_WALK(60, flo_17_ENTRY_1, "flo_18", flo_18_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_16_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_flo_18_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o116, .pos = { -530.0,    0.0, -110.0 }},
    { .colliderID = COLLIDER_o118, .pos = { -540.0,    0.0,  -50.0 }},
    { .colliderID = COLLIDER_o117, .pos = { -530.0,    0.0,   80.0 }},
    { .colliderID = COLLIDER_o121, .pos = { -270.0,    0.0, -120.0 }},
    { .colliderID = COLLIDER_o120, .pos = { -270.0,    0.0, -120.0 }},
    { .colliderID = COLLIDER_o119, .pos = { -270.0,    0.0,   35.0 }},
    { .colliderID = COLLIDER_o124, .pos = { -130.0,    0.0,  -50.0 }},
    { .colliderID = COLLIDER_o123, .pos = { -130.0,    0.0,  -50.0 }},
    { .colliderID = COLLIDER_o122, .pos = { -140.0,    0.0,   75.0 }},
    { .colliderID = COLLIDER_o128, .pos = {  120.0,    0.0,  -50.0 }},
    { .colliderID = COLLIDER_o127, .pos = {  120.0,    0.0,  -50.0 }},
    { .colliderID = COLLIDER_o125, .pos = {  130.0,    0.0,   60.0 }},
    { .colliderID = COLLIDER_o126, .pos = {  120.0,    0.0,  120.0 }},
    { .colliderID = COLLIDER_o132, .pos = {  280.0,    0.0, -110.0 }},
    { .colliderID = COLLIDER_o131, .pos = {  280.0,    0.0, -110.0 }},
    { .colliderID = COLLIDER_o130, .pos = {  270.0,    0.0,  -50.0 }},
    { .colliderID = COLLIDER_o129, .pos = {  280.0,    0.0,   50.0 }},
    { .colliderID = COLLIDER_o134, .pos = {  525.0,    0.0,  -70.0 }},
    { .colliderID = COLLIDER_o133, .pos = {  525.0,    0.0,   50.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupLogBridges))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o116, SURFACE_TYPE_FLOWERS)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o117, SURFACE_TYPE_FLOWERS)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o121, SURFACE_TYPE_FLOWERS)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o124, SURFACE_TYPE_FLOWERS)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o126, SURFACE_TYPE_FLOWERS)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o128, SURFACE_TYPE_FLOWERS)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o129, SURFACE_TYPE_FLOWERS)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o132, SURFACE_TYPE_FLOWERS)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o133, SURFACE_TYPE_FLOWERS)
    EVT_FLOWER_SPAWN_REGION( -736, -137, -522, -118,  0)
    EVT_FLOWER_SPAWN_REGION( -728,   76, -496,  137,  0)
    EVT_FLOWER_SPAWN_REGION( -160, -117,  -92,  -54,  0)
    EVT_FLOWER_SPAWN_REGION(   76, -124,  150,  -55,  0)
    EVT_FLOWER_SPAWN_REGION(  192,   60,  309,  133,  0)
    EVT_FLOWER_SPAWN_REGION(  488,   46,  733,  137,  0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o103, SURFACE_TYPE_SPIKES)
    EVT_THREAD
        EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
    EVT_END_THREAD
    EVT_CALL(EnableTexPanning, MODEL_o34, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o36, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o37, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o40, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o41, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o44, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o45, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o47, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o48, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o51, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o52, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o55, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o23, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o25, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o26, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o29, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o30, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o33, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o35, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o38, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o39, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o42, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o43, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o46, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o49, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o50, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o53, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o54, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o24, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o27, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o28, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o31, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o32, TRUE)
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
