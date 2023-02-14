#include "kpa_12.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kpa_1X_Upper) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, kpa_12_ENTRY_0)
    EVT_EXEC(ExitWalk)
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_CALL(GotoMap, EVT_PTR("kpa_11"), kpa_11_ENTRY_1)
    EVT_ELSE
        EVT_CALL(GotoMap, EVT_PTR("kpa_10"), kpa_10_ENTRY_1)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_kpa_1X_Lower) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(UseExitHeading, 60, kpa_12_ENTRY_2)
    EVT_EXEC(ExitWalk)
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_CALL(GotoMap, EVT_PTR("kpa_11"), kpa_11_ENTRY_4)
    EVT_ELSE
        EVT_CALL(GotoMap, EVT_PTR("kpa_10"), kpa_10_ENTRY_4)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_kpa_13_0) = EVT_EXIT_WALK(60, kpa_12_ENTRY_1, "kpa_13", kpa_13_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_1X_Upper)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_1X_Lower)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_13_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Lava) = {
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP( -400,    0, -800,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_o319, 0)
    EVT_CALL(SetTexPanner, MODEL_o555, 0)
    EVT_CALL(SetTexPanner, MODEL_o516, 0)
    EVT_CALL(SetTexPanner, MODEL_o526, 0)
    EVT_CALL(SetTexPanner, MODEL_o557, 0)
    EVT_CALL(SetTexPanner, MODEL_o558, 0)
    EVT_CALL(SetTexPanner, MODEL_o513, 0)
    EVT_CALL(SetTexPanner, MODEL_o561, 0)
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o179, .pos = {  100.0,   30.0, -150.0 }},
    { .colliderID = COLLIDER_o171, .pos = {  245.0,   30.0, -150.0 }},
    { .colliderID = COLLIDER_o174, .pos = {  400.0,   30.0, -150.0 }},
    { .colliderID = COLLIDER_o175, .pos = {  700.0,   30.0, -150.0 }},
    { .colliderID = COLLIDER_o144, .pos = {  855.0,   30.0, -100.0 }},
    { .colliderID = COLLIDER_o305, .pos = { 1445.0,   30.0, -135.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_CALL(EnableGroup, MODEL_after, FALSE)
        EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_before, FALSE)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_EXEC(N(EVS_SetupPlatforms))
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_THREAD
            EVT_WAIT(2)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o356, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o358, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o359, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o360, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o361, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o362, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o363, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o364, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o365, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o370, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o371, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o419, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o420, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilisw, SURFACE_TYPE_LAVA)
            EVT_THREAD
                EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
            EVT_END_THREAD
        EVT_END_THREAD
    EVT_END_IF
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
