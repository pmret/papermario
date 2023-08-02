#include "iwa_01.h"

API_CALLABLE(N(SetPlayerSliding)) {
    gPlayerStatus.slideParams = script->varTablePtr[0];
    gPlayerStatus.flags |= PS_FLAG_SLIDING;
    return ApiStatus_DONE2;
}

SlideParams N(SlideData1) = {
    .heading = 90.0f,
    .maxDescendAccel = 0.5f,
    .launchVel = -0.5f,
    .maxDescendVel = 16.0f,
    .integrator = { 0.0, 0.0, 0.0, 0.0 },
};

SlideParams N(SlideData2) = {
    .heading = 270.0f,
    .maxDescendAccel = 0.5f,
    .launchVel = -0.18f,
    .maxDescendVel = 18.0f,
    .integrator = { 10.9716, -0.34, 0.003, -0.012 },
};

EvtScript N(EVS_UpdateSliding1) = {
    EVT_SET(LVar0, EVT_PTR(N(SlideData1)))
    EVT_CALL(N(SetPlayerSliding))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateSliding2) = {
    EVT_SET(LVar0, EVT_PTR(N(SlideData2)))
    EVT_CALL(N(SetPlayerSliding))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSlide1) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_st1, SOUND_20A2, SOUND_SPACE_MODE_0)
        EVT_CALL(MakeLerp, 0, -80, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_se1, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_st1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlayerMoveTo, -440, 60, 30)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_WAIT(100)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_st1, SOUND_20A2, SOUND_SPACE_MODE_0)
        EVT_CALL(MakeLerp, -80, 0, 30, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_se1, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_st1, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSlide2) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_st2, SOUND_20A2, SOUND_SPACE_MODE_0)
        EVT_CALL(MakeLerp, 0, 80, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_se2, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_st2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlayerMoveTo, 543, 50, 20)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_WAIT(100)
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, COLLIDER_st2, SOUND_20A2, SOUND_SPACE_MODE_0)
        EVT_CALL(MakeLerp, 80, 0, 30, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_se2, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_st2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindSlideTriggers1) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseSlide1)), TRIGGER_WALL_PRESS_A, COLLIDER_st1, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UpdateSliding1)), TRIGGER_FLOOR_TOUCH, COLLIDER_suberi1, 1, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_suberi1, SURFACE_TYPE_SLIDE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindSlideTriggers2) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseSlide2)), TRIGGER_WALL_PRESS_A, COLLIDER_st2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UpdateSliding2)), TRIGGER_FLOOR_TOUCH, COLLIDER_suberi01, 1, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_suberi01, SURFACE_TYPE_SLIDE)
    EVT_RETURN
    EVT_END
};
