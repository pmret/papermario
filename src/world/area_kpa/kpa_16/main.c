#include "kpa_16.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kpa_14_2) = EVT_EXIT_WALK(40, kpa_16_ENTRY_0, "kpa_14", kpa_14_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_14_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};

EvtScript N(EVS_TexPan_Steam) = {
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(    0,  400,    0,  800)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o1157, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o1158, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o1159, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o1160, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o1162, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o1163, TEX_PANNER_2)
    Return
    End
};

EvtScript N(EVS_TexPan_Lava) = {
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(-1200,    0, -600,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( 6144,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP( -800,    0, -400,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(    0, 3000,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(    0, 3200,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_5)
        TEX_PAN_PARAMS_STEP(    0, 2800,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o1282, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o1283, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o1284, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o1285, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o1286, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o776, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o782, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o780, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o893, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o895, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o894, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o892, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o1331, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_o1316, TEX_PANNER_4)
    Call(SetTexPanner, MODEL_o1321, TEX_PANNER_5)
    Call(SetTexPanner, MODEL_o1320, TEX_PANNER_5)
    Return
    End
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o197, .pos = {  470.0,   30.0,  -30.0 }},
    { .colliderID = COLLIDER_o202, .pos = {  470.0,   30.0,  -30.0 }},
    { .colliderID = COLLIDER_o785, .pos = {  500.0,  230.0, -140.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    IfEq(GF_KPA16_Defeated_SwitchGuards, TRUE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o958, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Call(EnableGroup, MODEL_after, FALSE)
        Exec(N(EVS_TexPan_Lava))
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o954, COLLIDER_FLAGS_UPPER_MASK)
    Else
        Call(EnableGroup, MODEL_before, FALSE)
        Exec(N(EVS_TexPan_Steam))
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o782, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Exec(N(EVS_EnterMap))
    Exec(N(EVS_SetupMusic))
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Thread
            Wait(2)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o782, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o929, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o930, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o776, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o952, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o954, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliw, SURFACE_TYPE_LAVA)
            Thread
                Call(ResetFromLava, Ref(N(SafeFloorColliders)))
            EndThread
        EndThread
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o952, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};
