#include "dgb_09.h"
#include "effects.h"

BombTrigger N(BombPos_Wall) = {
    .pos = { 300.0f, 0.0f, 88.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BlastWall) = {
    EVT_WAIT(2)
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 1, 25, 3, 1, 10, 30)
    EVT_LOOP(10)
        EVT_CALL(EnableModel, MODEL_g29, FALSE)
        EVT_CALL(EnableModel, MODEL_g28, TRUE)
        EVT_WAIT(1)
        EVT_CALL(EnableModel, MODEL_g29, TRUE)
        EVT_CALL(EnableModel, MODEL_g28, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_DGB09_BombedWall, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBreakable) = {
    EVT_IF_EQ(GF_DGB09_BombedWall, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_BlastWall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Wall)), 1, 0)
        EVT_CALL(EnableModel, MODEL_g29, FALSE)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_g28, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
