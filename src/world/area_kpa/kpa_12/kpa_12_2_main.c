#include "kpa_12.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kpa_1X_Upper) = {
    SetGroup(EVT_GROUP_1B)
    Call(UseExitHeading, 60, kpa_12_ENTRY_0)
    Exec(ExitWalk)
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Call(GotoMap, Ref("kpa_11"), kpa_11_ENTRY_1)
    Else
        Call(GotoMap, Ref("kpa_10"), kpa_10_ENTRY_1)
    EndIf
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_kpa_1X_Lower) = {
    SetGroup(EVT_GROUP_1B)
    Call(UseExitHeading, 60, kpa_12_ENTRY_2)
    Exec(ExitWalk)
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Call(GotoMap, Ref("kpa_11"), kpa_11_ENTRY_4)
    Else
        Call(GotoMap, Ref("kpa_10"), kpa_10_ENTRY_4)
    EndIf
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_kpa_13_0) = EVT_EXIT_WALK(60, kpa_12_ENTRY_1, "kpa_13", kpa_13_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_1X_Upper)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_1X_Lower)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_13_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
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
    Call(SetTexPanner, MODEL_o319, 0)
    Call(SetTexPanner, MODEL_o555, 0)
    Call(SetTexPanner, MODEL_o516, 0)
    Call(SetTexPanner, MODEL_o526, 0)
    Call(SetTexPanner, MODEL_o557, 0)
    Call(SetTexPanner, MODEL_o558, 0)
    Call(SetTexPanner, MODEL_o513, 0)
    Call(SetTexPanner, MODEL_o561, 0)
    Return
    End
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
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Call(EnableGroup, MODEL_after, FALSE)
        Exec(N(EVS_TexPan_Lava))
    Else
        Call(EnableGroup, MODEL_before, FALSE)
    EndIf
    Exec(N(EVS_SetupMusic))
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Exec(N(EVS_SetupPlatforms))
    EndIf
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Thread
            Wait(2)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o356, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o358, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o359, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o360, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o361, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o362, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o363, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o364, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o365, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o370, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o371, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o419, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o420, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilisw, SURFACE_TYPE_LAVA)
            Thread
                Call(ResetFromLava, Ref(N(SafeFloorColliders)))
            EndThread
        EndThread
    EndIf
    Wait(1)
    Return
    End
};
