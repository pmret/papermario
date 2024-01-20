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
    Call(ParentColliderToModel, COLLIDER_o2022, MODEL_g313)
    BindTrigger(Ref(N(EVS_OnTouch_StairSwitch)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2022, 1, 0)
    Return
    End
};

EvtScript N(EVS_OnTouch_StairSwitch) = {
    Call(IsPlayerOnValidFloor, LVar0)
    IfEq(LVar0, FALSE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(PlaySoundAtCollider, COLLIDER_o2022, SOUND_FLOOR_SWITCH_DEPRESS, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, -14, 30, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g313, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o2022)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(PlaySoundAtCollider, COLLIDER_o2022, SOUND_FLOOR_SWITCH_ACTIVATE, SOUND_SPACE_DEFAULT)
    Set(AF_ISK07_FlippingRedStairs, TRUE)
    Label(15)
    Wait(1)
        IfEq(AF_ISK07_FlippingRedStairs, TRUE)
            Goto(15)
        EndIf
    Call(MakeLerp, -14, 0, 5, EASING_LINEAR)
    Label(20)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g313, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o2022)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
    Call(N(WaitForPlayerTouchingGround))
    Return
    End
};
