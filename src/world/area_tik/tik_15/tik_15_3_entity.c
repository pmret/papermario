#include "tik_15.h"
#include "entity.h"
#include "effects.h"

BombTrigger N(BombPos_Wall) = {
    .pos = { -230.0f, -10.0f, 0.0f },
    .radius = 0.0f
};

EvtScript N(EVS_OnBlast_Wall) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 18, 0, 1, 10, 30)
    Loop(10)
        Call(EnableModel, MODEL_a_kabe, TRUE)
        Wait(1)
        Call(EnableModel, MODEL_a_kabe, FALSE)
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_TIK14_BombedWall, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_TIK14_BombedWall, TRUE)
        Call(EnableModel, MODEL_a_kabe, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
    Else
        BindTrigger(Ref(N(EVS_OnBlast_Wall)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Wall)), 1, 0)
    EndIf
    Return
    End
};
