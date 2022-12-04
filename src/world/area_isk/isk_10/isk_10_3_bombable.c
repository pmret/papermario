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
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 30, 14, 1, 10, 30)
    EVT_LOOP(10)
        EVT_CALL(EnableModel, MODEL_g328, TRUE)
        EVT_WAIT(1)
        EVT_CALL(EnableModel, MODEL_g328, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_ISK_BombedWallFrom10, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnBlast_LowerWall) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 27, 19, 1, 10, 30)
    EVT_LOOP(10)
        EVT_CALL(EnableModel, MODEL_g327, TRUE)
        EVT_WAIT(1)
        EVT_CALL(EnableModel, MODEL_g327, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_ISK10_BombedWall, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HideDestroyedWall) = {
    EVT_CALL(EnableModel, MODEL_o2029, FALSE)
    EVT_CALL(EnableModel, MODEL_o2030, FALSE)
    EVT_CALL(EnableModel, MODEL_o2031, FALSE)
    EVT_CALL(EnableModel, MODEL_o2032, FALSE)
    EVT_CALL(EnableModel, MODEL_o2033, FALSE)
    EVT_CALL(EnableModel, MODEL_o2034, FALSE)
    EVT_CALL(EnableModel, MODEL_o2035, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2031, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2032, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2034, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBombableWall) = {
    EVT_IF_EQ(GF_ISK_BombedWallFrom08, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnBlast_UpperWall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_UpperWall)), 1, 0)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_g328, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_ISK_BombedWallFrom10, FALSE)
        EVT_IF_EQ(GF_ISK_BombedWallFrom08, FALSE)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnBlast_UpperWall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_UpperWall)), 1, 0)
            EVT_EXEC_WAIT(N(EVS_HideDestroyedWall))
        EVT_ELSE
            EVT_CALL(EnableModel, MODEL_g328, FALSE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_g328, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
        EVT_EXEC_WAIT(N(EVS_HideDestroyedWall))
    EVT_END_IF
    EVT_IF_EQ(GF_ISK10_BombedWall, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnBlast_LowerWall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_LowerWall)), 1, 0)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_g327, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
