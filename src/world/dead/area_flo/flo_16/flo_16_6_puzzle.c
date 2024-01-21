#include "flo_16.h"

API_CALLABLE(N(CheckForPoundInput)) {
    script->varTable[0] = FALSE;
    if (gPlayerStatus.actionState == ACTION_STATE_SPIN_POUND || gPlayerStatus.actionState == ACTION_STATE_TORNADO_POUND) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnTouch_RedPillar) = {
    Call(N(CheckForPoundInput))
    IfEq(LVar0, FALSE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    IfEq(AF_FLO_RaisedRedPillar, FALSE)
        Set(LVar5, 0)
        Set(LVar6, 50)
        Set(LVar7, 0)
        Set(LVar8, 180)
        Set(AF_FLO_RaisedRedPillar, TRUE)
    Else
        Set(LVar5, 50)
        Set(LVar6, 0)
        Set(LVar7, 180)
        Set(LVar8, 0)
        Set(AF_FLO_RaisedRedPillar, FALSE)
    EndIf
    Wait(15)
    Call(PlaySound, SOUND_FLO_MOVE_PILLAR)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(0.8))
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.2))
    EndThread
    Call(MakeLerp, LVar5, LVar6, 30, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g81, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g82, 0, LVar0, 0)
        Call(TranslateModel, MODEL_g85, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g86, 0, LVar0, 0)
        Call(RotateGroup, MODEL_g82, LVar7, 1, 0, 0)
        Call(RotateGroup, MODEL_g86, LVar7, 1, 0, 0)
        Call(UpdateColliderTransform, COLLIDER_o242)
        Call(UpdateColliderTransform, COLLIDER_o250)
        Call(UpdateColliderTransform, COLLIDER_o244)
        Call(UpdateColliderTransform, COLLIDER_o252)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, FALSE)
    Wait(10)
    Call(MakeLerp, LVar7, LVar8, 15, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g81, 0, LVar6, 0)
        Call(TranslateGroup, MODEL_g82, 0, LVar6, 0)
        Call(TranslateModel, MODEL_g85, 0, LVar6, 0)
        Call(TranslateGroup, MODEL_g86, 0, LVar6, 0)
        Call(RotateGroup, MODEL_g82, LVar0, 1, 0, 0)
        Call(RotateGroup, MODEL_g86, LVar0, 1, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_OnTouch_GreenPillar) = {
    Call(N(CheckForPoundInput))
    IfEq(LVar0, FALSE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    IfEq(AF_FLO_RaisedGreenPillar, FALSE)
        Set(LVar5, 0)
        Set(LVar6, 50)
        Set(LVar7, 0)
        Set(LVar8, 180)
        Set(AF_FLO_RaisedGreenPillar, TRUE)
    Else
        Set(LVar5, 50)
        Set(LVar6, 0)
        Set(LVar7, 180)
        Set(LVar8, 0)
        Set(AF_FLO_RaisedGreenPillar, FALSE)
    EndIf
    Wait(15)
    Call(PlaySound, SOUND_FLO_MOVE_PILLAR)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(0.8))
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.2))
    EndThread
    Call(MakeLerp, LVar5, LVar6, 30, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g83, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g84, 0, LVar0, 0)
        Call(TranslateModel, MODEL_g87, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g88, 0, LVar0, 0)
        Call(TranslateModel, MODEL_g91, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g92, 0, LVar0, 0)
        Call(RotateGroup, MODEL_g84, LVar7, 1, 0, 0)
        Call(RotateGroup, MODEL_g88, LVar7, 1, 0, 0)
        Call(RotateGroup, MODEL_g92, LVar7, 1, 0, 0)
        Call(UpdateColliderTransform, COLLIDER_o243)
        Call(UpdateColliderTransform, COLLIDER_o251)
        Call(UpdateColliderTransform, COLLIDER_o245)
        Call(UpdateColliderTransform, COLLIDER_o253)
        Call(UpdateColliderTransform, COLLIDER_o247)
        Call(UpdateColliderTransform, COLLIDER_o255)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, FALSE)
    Wait(10)
    Call(MakeLerp, LVar7, LVar8, 15, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g83, 0, LVar6, 0)
        Call(TranslateGroup, MODEL_g84, 0, LVar6, 0)
        Call(TranslateModel, MODEL_g87, 0, LVar6, 0)
        Call(TranslateGroup, MODEL_g88, 0, LVar6, 0)
        Call(TranslateModel, MODEL_g91, 0, LVar6, 0)
        Call(TranslateGroup, MODEL_g92, 0, LVar6, 0)
        Call(RotateGroup, MODEL_g84, LVar0, 1, 0, 0)
        Call(RotateGroup, MODEL_g88, LVar0, 1, 0, 0)
        Call(RotateGroup, MODEL_g92, LVar0, 1, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_OnTouch_PurplePillar) = {
    Call(N(CheckForPoundInput))
    IfEq(LVar0, FALSE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    IfEq(AF_FLO_LoweredPurplePillar, FALSE)
        Set(LVar5, 0)
        Set(LVar6, -50)
        Set(LVar7, 0)
        Set(LVar8, 180)
        Set(AF_FLO_LoweredPurplePillar, TRUE)
    Else
        Set(LVar5, -50)
        Set(LVar6, 0)
        Set(LVar7, 180)
        Set(LVar8, 0)
        Set(AF_FLO_LoweredPurplePillar, FALSE)
    EndIf
    Wait(15)
    Call(PlaySound, SOUND_FLO_MOVE_PILLAR)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 30, Float(0.8))
        Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(0.2))
    EndThread
    Call(MakeLerp, LVar5, LVar6, 30, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g89, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g90, 0, LVar0, 0)
        Call(TranslateModel, MODEL_g93, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g94, 0, LVar0, 0)
        Call(RotateGroup, MODEL_g90, LVar7, 1, 0, 0)
        Call(RotateGroup, MODEL_g94, LVar7, 1, 0, 0)
        Call(UpdateColliderTransform, COLLIDER_o246)
        Call(UpdateColliderTransform, COLLIDER_o254)
        Call(UpdateColliderTransform, COLLIDER_o248)
        Call(UpdateColliderTransform, COLLIDER_o256)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, FALSE)
    Wait(10)
    Call(MakeLerp, LVar7, LVar8, 15, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_g89, 0, LVar6, 0)
        Call(TranslateGroup, MODEL_g90, 0, LVar6, 0)
        Call(TranslateModel, MODEL_g93, 0, LVar6, 0)
        Call(TranslateGroup, MODEL_g94, 0, LVar6, 0)
        Call(RotateGroup, MODEL_g90, LVar0, 1, 0, 0)
        Call(RotateGroup, MODEL_g94, LVar0, 1, 0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_SetupPillarPuzzle) = {
    Set(AF_FLO_RaisedRedPillar, FALSE)
    Set(AF_FLO_RaisedGreenPillar, FALSE)
    Set(AF_FLO_LoweredPurplePillar, FALSE)
    Call(ParentColliderToModel, COLLIDER_o242, MODEL_g81)
    Call(ParentColliderToModel, COLLIDER_o250, MODEL_g81)
    Call(ParentColliderToModel, COLLIDER_o243, MODEL_g83)
    Call(ParentColliderToModel, COLLIDER_o251, MODEL_g83)
    Call(ParentColliderToModel, COLLIDER_o244, MODEL_g85)
    Call(ParentColliderToModel, COLLIDER_o252, MODEL_g85)
    Call(ParentColliderToModel, COLLIDER_o245, MODEL_g87)
    Call(ParentColliderToModel, COLLIDER_o253, MODEL_g87)
    Call(ParentColliderToModel, COLLIDER_o246, MODEL_g89)
    Call(ParentColliderToModel, COLLIDER_o254, MODEL_g89)
    Call(ParentColliderToModel, COLLIDER_o247, MODEL_g91)
    Call(ParentColliderToModel, COLLIDER_o255, MODEL_g91)
    Call(ParentColliderToModel, COLLIDER_o248, MODEL_g93)
    Call(ParentColliderToModel, COLLIDER_o256, MODEL_g93)
    BindTrigger(Ref(N(EVS_OnTouch_RedPillar)), TRIGGER_FLOOR_TOUCH, COLLIDER_o242, 1, 0)
    BindTrigger(Ref(N(EVS_OnTouch_GreenPillar)), TRIGGER_FLOOR_TOUCH, COLLIDER_o243, 1, 0)
    BindTrigger(Ref(N(EVS_OnTouch_RedPillar)), TRIGGER_FLOOR_TOUCH, COLLIDER_o244, 1, 0)
    BindTrigger(Ref(N(EVS_OnTouch_GreenPillar)), TRIGGER_FLOOR_TOUCH, COLLIDER_o245, 1, 0)
    BindTrigger(Ref(N(EVS_OnTouch_PurplePillar)), TRIGGER_FLOOR_TOUCH, COLLIDER_o246, 1, 0)
    BindTrigger(Ref(N(EVS_OnTouch_GreenPillar)), TRIGGER_FLOOR_TOUCH, COLLIDER_o247, 1, 0)
    BindTrigger(Ref(N(EVS_OnTouch_PurplePillar)), TRIGGER_FLOOR_TOUCH, COLLIDER_o248, 1, 0)
    Return
    End
};
