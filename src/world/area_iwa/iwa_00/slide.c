#include "iwa_00.h"

SlideParams N(SlideData) = {
    .heading = 270.0f,
    .maxDescendAccel = 0.4f,
    .launchVel = -0.05f,
    .maxDescendVel = 20.0f,
    .integrator = { 0.0, 0.0, 0.0, 0.0 },
};

API_CALLABLE(N(SetPlayerSliding)) {
    gPlayerStatus.slideParams = script->varTablePtr[0];
    gPlayerStatus.flags |= PS_FLAG_SLIDING;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdateSliding) = {
    Set(LVar0, Ref(N(SlideData)))
    Call(N(SetPlayerSliding))
    Return
    End
};

EvtScript N(EVS_UseSlide) = {
    Call(DisablePlayerInput, true)
    Wait(10)
    Thread
        Call(PlaySoundAtCollider, COLLIDER_st1, SOUND_IWA_SLIDE_GATE, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, 0, 80, 10, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_se1, LVar0, 0, -1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Wait(15)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_st1, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlayerMoveTo, 543, 17, 20)
    Call(DisablePlayerInput, false)
    Wait(100)
    Thread
        Call(PlaySoundAtCollider, COLLIDER_st1, SOUND_IWA_SLIDE_GATE, SOUND_SPACE_DEFAULT)
        Call(MakeLerp, 80, 0, 30, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_se1, LVar0, 0, -1, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_st1, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_BindSlideTriggers) = {
    BindTrigger(Ref(N(EVS_UseSlide)), TRIGGER_WALL_PRESS_A, COLLIDER_st1, 1, 0)
    BindTrigger(Ref(N(EVS_UpdateSliding)), TRIGGER_FLOOR_TOUCH, COLLIDER_suberi01, 1, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_suberi01, SURFACE_TYPE_SLIDE)
    Return
    End
};
