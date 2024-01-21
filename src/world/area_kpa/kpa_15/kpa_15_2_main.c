#include "kpa_15.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(D_8024074C_A59ADC) = EVT_EXIT_WALK(40, kpa_15_ENTRY_0, "kpa_13", kpa_13_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(D_8024074C_A59ADC)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    Return
    End
};

EvtScript N(D_802407D4_A59B64) = {
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};

EvtScript N(D_80240800_A59B90) = {
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP( -400,    0, -800,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o811, 0)
    Call(SetTexPanner, MODEL_o813, 0)
    Call(SetTexPanner, MODEL_o814, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    ExecWait(N(EVS_MakeEntities))
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Call(EnableGroup, MODEL_after, FALSE)
        Exec(N(D_80240800_A59B90))
    Else
        Call(EnableGroup, MODEL_before, FALSE)
    EndIf
    Exec(N(D_802407D4_A59B64))
    Exec(N(EVS_SetupMusic))
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Thread
            Wait(2)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o781, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deiliw, SURFACE_TYPE_LAVA)
        EndThread
    EndIf
    Return
    End
};
