#include "obk_02.h"
#include "effects.h"

BombTrigger N(BombPos_Wall) = {
    .pos = { 237.0f, -210.0f, 53.0f },
    .radius = 0.0f
};

EvtScript N(EVS_OnBlast_Wall) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 1, 33, 33, 1, 10, 30)
    Loop(10)
        Call(EnableModel, MODEL_bomu_ato, FALSE)
        Call(EnableModel, MODEL_bom_mae, TRUE)
        Wait(1)
        Call(EnableModel, MODEL_bomu_ato, TRUE)
        Call(EnableModel, MODEL_bom_mae, FALSE)
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt3, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_OBK06_BombedWall, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupBombableWall) = {
    IfEq(GF_OBK06_BombedWall, FALSE)
        BindTrigger(Ref(N(EVS_OnBlast_Wall)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Wall)), 1, 0)
        Call(EnableModel, MODEL_bomu_ato, FALSE)
    Else
        Call(EnableModel, MODEL_bom_mae, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt3, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};
