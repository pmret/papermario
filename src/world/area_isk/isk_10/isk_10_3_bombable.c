#include "isk_10.h"
#include "effects.h"

BombTrigger N(BombPos_UpperWall) = {
    .pos = { -593.0f, -520.0f, 104.0f },
    .radius = 0.0f
};

BombTrigger N(BombPos_LowerWall) = {
    .pos = { -569.0f, -780.0f, -99.0f },
    .radius = 0.0f
};

EvtScript N(EVS_OnBlast_UpperWall) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 30, 14, 1, 10, 30)
    Loop(10)
        Call(EnableModel, MODEL_g328, TRUE)
        Wait(1)
        Call(EnableModel, MODEL_g328, FALSE)
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_ISK_BombedWallFrom10, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_OnBlast_LowerWall) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 27, 19, 1, 10, 30)
    Loop(10)
        Call(EnableModel, MODEL_g327, TRUE)
        Wait(1)
        Call(EnableModel, MODEL_g327, FALSE)
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_ISK10_BombedWall, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_HideDestroyedWall) = {
    Call(EnableModel, MODEL_o2029, FALSE)
    Call(EnableModel, MODEL_o2030, FALSE)
    Call(EnableModel, MODEL_o2031, FALSE)
    Call(EnableModel, MODEL_o2032, FALSE)
    Call(EnableModel, MODEL_o2033, FALSE)
    Call(EnableModel, MODEL_o2034, FALSE)
    Call(EnableModel, MODEL_o2035, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2031, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2032, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2034, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_SetupBombableWall) = {
    IfEq(GF_ISK_BombedWallFrom08, FALSE)
        BindTrigger(Ref(N(EVS_OnBlast_UpperWall)), TRIGGER_POINT_BOMB, Ref(N(BombPos_UpperWall)), 1, 0)
    Else
        Call(EnableModel, MODEL_g328, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfEq(GF_ISK_BombedWallFrom10, FALSE)
        IfEq(GF_ISK_BombedWallFrom08, FALSE)
            BindTrigger(Ref(N(EVS_OnBlast_UpperWall)), TRIGGER_POINT_BOMB, Ref(N(BombPos_UpperWall)), 1, 0)
            ExecWait(N(EVS_HideDestroyedWall))
        Else
            Call(EnableModel, MODEL_g328, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
        EndIf
    Else
        Call(EnableModel, MODEL_g328, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
        ExecWait(N(EVS_HideDestroyedWall))
    EndIf
    IfEq(GF_ISK10_BombedWall, FALSE)
        BindTrigger(Ref(N(EVS_OnBlast_LowerWall)), TRIGGER_POINT_BOMB, Ref(N(BombPos_LowerWall)), 1, 0)
    Else
        Call(EnableModel, MODEL_g327, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};
