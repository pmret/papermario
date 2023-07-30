#include "isk_07.h"

extern EvtScript N(EVS_OnTouch_StairSwitch);

API_CALLABLE(N(WaitForPlayerTouchingGround)) {
    if (gCollisionStatus.curFloor == COLLIDER_o2022) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

EvtScript N(EVS_SetupSwitch) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_o2022, MODEL_g313)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouch_StairSwitch)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2022, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnTouch_StairSwitch) = {
    EVT_CALL(IsPlayerOnValidFloor, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2022, SOUND_208A, SOUND_SPACE_MODE_0)
    EVT_CALL(MakeLerp, 0, -14, 30, EASING_LINEAR)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g313, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o2022)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2022, SOUND_208B, SOUND_SPACE_MODE_0)
    EVT_SET(AF_ISK07_FlippingRedStairs, TRUE)
    EVT_LABEL(15)
    EVT_WAIT(1)
        EVT_IF_EQ(AF_ISK07_FlippingRedStairs, TRUE)
            EVT_GOTO(15)
        EVT_END_IF
    EVT_CALL(MakeLerp, -14, 0, 5, EASING_LINEAR)
    EVT_LABEL(20)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g313, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o2022)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_CALL(N(WaitForPlayerTouchingGround))
    EVT_RETURN
    EVT_END
};
