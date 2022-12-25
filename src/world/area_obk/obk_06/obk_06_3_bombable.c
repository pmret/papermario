#include "obk_06.h"
#include "effects.h"

BombTrigger N(BombPos_Wall) = {
    .pos = { -237.0f, 0.0f, 50.0f },
    .radius = 0.0f
};

EvtScript N(EVS_OnBlast_Wall) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 1, 23, 26, 1, 10, 30)
    EVT_LOOP(10)
        EVT_CALL(EnableModel, MODEL_bom_ato, FALSE)
        EVT_CALL(EnableModel, MODEL_bom1, TRUE)
        EVT_WAIT(1)
        EVT_CALL(EnableModel, MODEL_bom_ato, TRUE)
        EVT_CALL(EnableModel, MODEL_bom1, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_OBK06_BombedWall, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBombables) = {
    EVT_IF_EQ(GF_OBK06_BombedWall, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnBlast_Wall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Wall)), 1, 0)
        EVT_CALL(EnableModel, MODEL_bom_ato, FALSE)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_bom1, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
