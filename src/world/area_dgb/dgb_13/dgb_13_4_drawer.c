#include "dgb_13.h"

EvtScript N(EVS_OpenLowerDrawer) = {
    EVT_CALL(MakeLerp, 0, 30, 15, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_b1, 0, 0, LVar0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o265)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseLowerDrawer) = {
    EVT_CALL(MakeLerp, 30, 0, 15, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_b1, 0, 0, LVar0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o265)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenUpperDrawer) = {
    EVT_CALL(MakeLerp, 0, 30, 15, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_b3, 0, 0, LVar0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o267)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseUpperDrawer) = {
    EVT_CALL(MakeLerp, 30, 0, 15, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_b3, 0, 0, LVar0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o267)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Interact_LowerDrawer) = {
    EVT_IF_EQ(MV_LowerDrawerOpen, FALSE)
        EVT_EXEC_WAIT(N(EVS_OpenLowerDrawer))
        EVT_SET(MV_LowerDrawerOpen, TRUE)
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_CloseLowerDrawer))
        EVT_SET(MV_LowerDrawerOpen, FALSE)
    EVT_END_IF
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupDrawers) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_o265, MODEL_o419)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Interact_LowerDrawer)), TRIGGER_WALL_PRESS_A, COLLIDER_o265, 1, 0)
    EVT_RETURN
    EVT_END
};
