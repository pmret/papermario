#include "dgb_09.h"
#include "effects.h"

BombTrigger N(BombPos_Wall) = {
    .pos = { 300.0f, 0.0f, 88.0f },
    .diameter = 0.0f
};

EvtScript N(EVS_BlastWall) = {
    Wait(2)
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 1, 25, 3, 1, 10, 30)
    Loop(10)
        Call(EnableModel, MODEL_g29, false)
        Call(EnableModel, MODEL_g28, true)
        Wait(1)
        Call(EnableModel, MODEL_g29, true)
        Call(EnableModel, MODEL_g28, false)
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_DGB09_BombedWall, true)
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupBreakable) = {
    IfEq(GF_DGB09_BombedWall, false)
        BindTrigger(Ref(N(EVS_BlastWall)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Wall)), 1, 0)
        Call(EnableModel, MODEL_g29, false)
    Else
        Call(EnableModel, MODEL_g28, false)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};
