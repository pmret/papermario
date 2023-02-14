#include "kpa_13.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kpa_12_1) = EVT_EXIT_WALK(60, kpa_13_ENTRY_0, "kpa_12", kpa_12_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_15_0) = EVT_EXIT_WALK(60, kpa_13_ENTRY_2, "kpa_15", kpa_15_ENTRY_0);
EvtScript N(EVS_ExitWalk_kpa_14_0) = EVT_EXIT_WALK(60, kpa_13_ENTRY_1, "kpa_14", kpa_14_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_12_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_15_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_14_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
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
    EVT_CALL(SetTexPanner, MODEL_o926, 0)
    EVT_CALL(SetTexPanner, MODEL_o927, 0)
    EVT_CALL(SetTexPanner, MODEL_o928, 0)
    EVT_CALL(SetTexPanner, MODEL_o925, 0)
    EVT_RETURN
    EVT_END
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o1043, .pos = {  110.0,   30.0, -150.0 }},
    { .colliderID = COLLIDER_o1047, .pos = {  285.0,   30.0,  -20.0 }},
    { .colliderID = COLLIDER_o1048, .pos = {  500.0,   30.0,  -90.0 }},
    { .colliderID = COLLIDER_o1041, .pos = {  800.0,   30.0, -150.0 }},
    { .colliderID = COLLIDER_o1051, .pos = {  935.0,   30.0,  -20.0 }},
    { .colliderID = COLLIDER_o1040, .pos = { 1150.0,   30.0, -150.0 }},
    { .colliderID = COLLIDER_o1050, .pos = { 1285.0,   30.0, -175.0 }},
    { .colliderID = COLLIDER_o1062, .pos = { 1415.0,   30.0, -175.0 }},
    { .colliderID = COLLIDER_o1064, .pos = { 1515.0,   30.0, -175.0 }},
    { .colliderID = COLLIDER_o1066, .pos = { 1655.0,   30.0, -175.0 }},
    { .colliderID = COLLIDER_o1068, .pos = { 1755.0,   30.0, -175.0 }},
    { .colliderID = COLLIDER_o1042, .pos = { 1860.0,   30.0, -120.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_CALL(EnableGroup, MODEL_after, FALSE)
        EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_before, FALSE)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_EXEC(N(EVS_SetupPlatforms))
    EVT_END_IF
    EVT_IF_EQ(GF_KPA16_ShutOffLava, FALSE)
        EVT_THREAD
            EVT_WAIT(2)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1039, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o805, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1028, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1029, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1030, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1031, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1032, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1033, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1034, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1035, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1036, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1037, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1038, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1074, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1075, SURFACE_TYPE_LAVA)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilin, SURFACE_TYPE_LAVA)
            EVT_THREAD
                EVT_CALL(ResetFromLava, EVT_PTR(N(SafeFloorColliders)))
            EVT_END_THREAD
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
