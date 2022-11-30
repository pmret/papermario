#include "tik_14.h"
#include "entity.h"
#include "effects.h"

BombTrigger N(BombPos_Wall) = {
    .pos = { 35.0f, 0.0f, 45.0f },
    .radius = 0.0f
};

EvtScript N(EVS_OnBlast_Wall) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 9, 0, 1, 10, 30)
    EVT_LOOP(10)
        EVT_CALL(EnableModel, MODEL_a_kabe, TRUE)
        EVT_WAIT(1)
        EVT_CALL(EnableModel, MODEL_a_kabe, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_TIK14_BombedWall, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_TIK14_BombedWall, TRUE)
        EVT_CALL(EnableModel, MODEL_a_kabe, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tte, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnBlast_Wall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Wall)), 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
