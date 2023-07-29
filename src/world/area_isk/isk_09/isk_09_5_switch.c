#include "isk_09.h"

extern EvtScript N(EVS_OnTouch_BlueSwitchCenter);
extern EvtScript N(EVS_OnTouch_BlueSwitchMidLeft);
extern EvtScript N(EVS_OnTouch_BlueSwitchTopLeft);
extern EvtScript N(EVS_OnTouch_RedSwitch);

API_CALLABLE(N(WaitForPlayerTouchingGround)) {
    Bytecode* args = script->ptrReadPos;
    s32 colliderID = evt_get_variable(script, *args++);
    if (gCollisionStatus.curFloor != colliderID) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_SetupSwitches) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_o2096, MODEL_g332)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouch_BlueSwitchCenter)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2096, 1, 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o2099, MODEL_g334)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouch_BlueSwitchMidLeft)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2099, 1, 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o2102, MODEL_g335)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouch_BlueSwitchTopLeft)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2102, 1, 0)
    EVT_CALL(ParentColliderToModel, COLLIDER_o2105, MODEL_g336)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnTouch_RedSwitch)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2105, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnTouch_BlueSwitchCenter) = {
    EVT_CALL(IsPlayerOnValidFloor, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2096, SOUND_208A, SOUND_SPACE_MODE_0)
    EVT_CALL(MakeLerp, 0, -14, 30, EASING_LINEAR)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g332, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o2096)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2096, SOUND_208B, SOUND_SPACE_MODE_0)
    EVT_SET(AF_ISK09_FlippingBlueStairs, TRUE)
    EVT_LABEL(15)
        EVT_WAIT(1)
        EVT_IF_EQ(AF_ISK09_FlippingBlueStairs, TRUE)
            EVT_GOTO(15)
        EVT_END_IF
    EVT_CALL(MakeLerp, -14, 0, 5, EASING_LINEAR)
    EVT_LABEL(20)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g332, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o2096)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_CALL(N(WaitForPlayerTouchingGround), COLLIDER_o2096)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnTouch_BlueSwitchMidLeft) = {
    EVT_CALL(IsPlayerOnValidFloor, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2099, SOUND_208A, SOUND_SPACE_MODE_0)
    EVT_CALL(MakeLerp, 0, -14, 30, EASING_LINEAR)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g334, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o2099)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2099, SOUND_208B, SOUND_SPACE_MODE_0)
    EVT_SET(AF_ISK09_FlippingBlueStairs, TRUE)
    EVT_LABEL(15)
        EVT_WAIT(1)
        EVT_IF_EQ(AF_ISK09_FlippingBlueStairs, TRUE)
            EVT_GOTO(15)
        EVT_END_IF
    EVT_CALL(MakeLerp, -14, 0, 5, EASING_LINEAR)
    EVT_LABEL(20)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g334, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o2099)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_CALL(N(WaitForPlayerTouchingGround), COLLIDER_o2099)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnTouch_BlueSwitchTopLeft) = {
    EVT_CALL(IsPlayerOnValidFloor, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2102, SOUND_208A, SOUND_SPACE_MODE_0)
    EVT_CALL(MakeLerp, 0, -14, 30, EASING_LINEAR)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g335, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o2102)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2102, SOUND_208B, SOUND_SPACE_MODE_0)
    EVT_SET(AF_ISK09_FlippingBlueStairs, TRUE)
    EVT_LABEL(15)
        EVT_WAIT(1)
        EVT_IF_EQ(AF_ISK09_FlippingBlueStairs, TRUE)
            EVT_GOTO(15)
        EVT_END_IF
    EVT_CALL(MakeLerp, -14, 0, 5, EASING_LINEAR)
    EVT_LABEL(20)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g335, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o2102)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_CALL(N(WaitForPlayerTouchingGround), COLLIDER_o2102)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnTouch_RedSwitch) = {
    EVT_CALL(IsPlayerOnValidFloor, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2105, SOUND_208A, SOUND_SPACE_MODE_0)
    EVT_CALL(MakeLerp, 0, -14, 30, EASING_LINEAR)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g336, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o2105)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o2105, SOUND_208B, SOUND_SPACE_MODE_0)
    EVT_SET(AF_ISK09_FlippingRedStairs, TRUE)
    EVT_LABEL(15)
        EVT_WAIT(1)
        EVT_IF_EQ(AF_ISK09_FlippingRedStairs, TRUE)
            EVT_GOTO(15)
        EVT_END_IF
    EVT_CALL(MakeLerp, -14, 0, 5, EASING_LINEAR)
    EVT_LABEL(20)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_g336, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o2105)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(20)
        EVT_END_IF
    EVT_CALL(N(WaitForPlayerTouchingGround), COLLIDER_o2105)
    EVT_RETURN
    EVT_END
};
