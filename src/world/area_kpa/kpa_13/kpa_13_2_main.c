#include "kpa_13.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kpa_12_1) = EVT_EXIT_WALK(60, kpa_13_ENTRY_0, "kpa_12", kpa_12_ENTRY_1);
EvtScript N(EVS_ExitWalk_kpa_15_0) = EVT_EXIT_WALK(60, kpa_13_ENTRY_2, "kpa_15", kpa_15_ENTRY_0);
EvtScript N(EVS_ExitWalk_kpa_14_0) = EVT_EXIT_WALK(60, kpa_13_ENTRY_1, "kpa_14", kpa_14_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_12_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_15_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_14_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_TexPan_Lava) = {
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP( -400,    0, -800,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o926, 0)
    Call(SetTexPanner, MODEL_o927, 0)
    Call(SetTexPanner, MODEL_o928, 0)
    Call(SetTexPanner, MODEL_o925, 0)
    Return
    End
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
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    ExecWait(N(EVS_MakeEntities))
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Call(EnableGroup, MODEL_after, FALSE)
        Exec(N(EVS_TexPan_Lava))
    Else
        Call(EnableGroup, MODEL_before, FALSE)
    EndIf
    Exec(N(EVS_SetupMusic))
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Wait(1)
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Exec(N(EVS_SetupPlatforms))
    EndIf
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Thread
            Wait(2)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1039, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o805, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1028, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1029, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1030, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1031, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1032, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1033, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1034, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1035, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1036, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1037, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1038, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1074, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o1075, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilin, SURFACE_TYPE_LAVA)
            Thread
                Call(ResetFromLava, Ref(N(SafeFloorColliders)))
            EndThread
        EndThread
    EndIf
    Return
    End
};
