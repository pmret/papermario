#include "isk_08.h"
#include "effects.h"

EvtScript N(EVS_SetupFlames) = {
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -358, -323, 358, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -459, -323, 214, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -358, -453, 358, Float(0.3), LVar0)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, -459, -453, 214, Float(0.3), LVar0)
    Return
    End
};

BombTrigger N(BombPos_Wall) = {
    .pos = { -569.0f, -520.0f, 207.0f },
    .radius = 0.0f
};

EvtScript N(EVS_OnBlast_Wall) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 36, 12, 1, 10, 30)
    Loop(10)
        Call(EnableModel, MODEL_g293, TRUE)
        Wait(1)
        Call(EnableModel, MODEL_g293, FALSE)
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_ISK_BombedWallFrom08, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_HideDestroyedWall) = {
    Call(EnableModel, MODEL_o2012, FALSE)
    Call(EnableModel, MODEL_o2019, FALSE)
    Call(EnableModel, MODEL_o2021, FALSE)
    Call(EnableModel, MODEL_o2018, FALSE)
    Call(EnableModel, MODEL_o2020, FALSE)
    Call(EnableModel, MODEL_o2022, FALSE)
    Call(EnableModel, MODEL_o2023, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2029, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2030, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2032, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_SetupBombableWall) = {
    IfEq(GF_ISK_BombedWallFrom08, FALSE)
        IfEq(GF_ISK_BombedWallFrom10, FALSE)
            BindTrigger(Ref(N(EVS_OnBlast_Wall)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Wall)), 1, 0)
            ExecWait(N(EVS_HideDestroyedWall))
        Else
            Call(EnableModel, MODEL_g293, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
        EndIf
    Else
        Call(EnableModel, MODEL_g293, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
        ExecWait(N(EVS_HideDestroyedWall))
    EndIf
    Return
    End
};
