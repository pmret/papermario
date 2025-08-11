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
    Call(ParentColliderToModel, COLLIDER_o2096, MODEL_g332)
    BindTrigger(Ref(N(EVS_OnTouch_BlueSwitchCenter)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2096, 1, 0)
    Call(ParentColliderToModel, COLLIDER_o2099, MODEL_g334)
    BindTrigger(Ref(N(EVS_OnTouch_BlueSwitchMidLeft)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2099, 1, 0)
    Call(ParentColliderToModel, COLLIDER_o2102, MODEL_g335)
    BindTrigger(Ref(N(EVS_OnTouch_BlueSwitchTopLeft)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2102, 1, 0)
    Call(ParentColliderToModel, COLLIDER_o2105, MODEL_g336)
    BindTrigger(Ref(N(EVS_OnTouch_RedSwitch)), TRIGGER_FLOOR_TOUCH, COLLIDER_o2105, 1, 0)
    Return
    End
};

EvtScript N(EVS_OnTouch_BlueSwitchCenter) = {
    Call(IsPlayerOnValidFloor, LVar0)
    IfEq(LVar0, false)
        Return
    EndIf
    Call(DisablePlayerInput, true)
    Call(PlaySoundAtCollider, COLLIDER_o2096, SOUND_FLOOR_SWITCH_DEPRESS, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, -14, 30, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g332, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o2096)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(PlaySoundAtCollider, COLLIDER_o2096, SOUND_FLOOR_SWITCH_ACTIVATE, SOUND_SPACE_DEFAULT)
    Set(AF_ISK09_FlippingBlueStairs, true)
    Label(15)
        Wait(1)
        IfEq(AF_ISK09_FlippingBlueStairs, true)
            Goto(15)
        EndIf
    Call(MakeLerp, -14, 0, 5, EASING_LINEAR)
    Label(20)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g332, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o2096)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
    Call(N(WaitForPlayerTouchingGround), COLLIDER_o2096)
    Return
    End
};

EvtScript N(EVS_OnTouch_BlueSwitchMidLeft) = {
    Call(IsPlayerOnValidFloor, LVar0)
    IfEq(LVar0, false)
        Return
    EndIf
    Call(DisablePlayerInput, true)
    Call(PlaySoundAtCollider, COLLIDER_o2099, SOUND_FLOOR_SWITCH_DEPRESS, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, -14, 30, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g334, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o2099)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(PlaySoundAtCollider, COLLIDER_o2099, SOUND_FLOOR_SWITCH_ACTIVATE, SOUND_SPACE_DEFAULT)
    Set(AF_ISK09_FlippingBlueStairs, true)
    Label(15)
        Wait(1)
        IfEq(AF_ISK09_FlippingBlueStairs, true)
            Goto(15)
        EndIf
    Call(MakeLerp, -14, 0, 5, EASING_LINEAR)
    Label(20)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g334, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o2099)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
    Call(N(WaitForPlayerTouchingGround), COLLIDER_o2099)
    Return
    End
};

EvtScript N(EVS_OnTouch_BlueSwitchTopLeft) = {
    Call(IsPlayerOnValidFloor, LVar0)
    IfEq(LVar0, false)
        Return
    EndIf
    Call(DisablePlayerInput, true)
    Call(PlaySoundAtCollider, COLLIDER_o2102, SOUND_FLOOR_SWITCH_DEPRESS, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, -14, 30, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g335, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o2102)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(PlaySoundAtCollider, COLLIDER_o2102, SOUND_FLOOR_SWITCH_ACTIVATE, SOUND_SPACE_DEFAULT)
    Set(AF_ISK09_FlippingBlueStairs, true)
    Label(15)
        Wait(1)
        IfEq(AF_ISK09_FlippingBlueStairs, true)
            Goto(15)
        EndIf
    Call(MakeLerp, -14, 0, 5, EASING_LINEAR)
    Label(20)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g335, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o2102)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
    Call(N(WaitForPlayerTouchingGround), COLLIDER_o2102)
    Return
    End
};

EvtScript N(EVS_OnTouch_RedSwitch) = {
    Call(IsPlayerOnValidFloor, LVar0)
    IfEq(LVar0, false)
        Return
    EndIf
    Call(DisablePlayerInput, true)
    Call(PlaySoundAtCollider, COLLIDER_o2105, SOUND_FLOOR_SWITCH_DEPRESS, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, -14, 30, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g336, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o2105)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(PlaySoundAtCollider, COLLIDER_o2105, SOUND_FLOOR_SWITCH_ACTIVATE, SOUND_SPACE_DEFAULT)
    Set(AF_ISK09_FlippingRedStairs, true)
    Label(15)
        Wait(1)
        IfEq(AF_ISK09_FlippingRedStairs, true)
            Goto(15)
        EndIf
    Call(MakeLerp, -14, 0, 5, EASING_LINEAR)
    Label(20)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g336, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o2105)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(20)
        EndIf
    Call(N(WaitForPlayerTouchingGround), COLLIDER_o2105)
    Return
    End
};
