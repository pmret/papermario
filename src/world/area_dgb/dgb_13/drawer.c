#include "dgb_13.h"

EvtScript N(EVS_OpenLowerDrawer) = {
    Call(MakeLerp, 0, 30, 15, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_b1, 0, 0, LVar0)
        Call(UpdateColliderTransform, COLLIDER_o265)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_CloseLowerDrawer) = {
    Call(MakeLerp, 30, 0, 15, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_b1, 0, 0, LVar0)
        Call(UpdateColliderTransform, COLLIDER_o265)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_OpenUpperDrawer) = {
    Call(MakeLerp, 0, 30, 15, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_b3, 0, 0, LVar0)
        Call(UpdateColliderTransform, COLLIDER_o267)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_CloseUpperDrawer) = {
    Call(MakeLerp, 30, 0, 15, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_b3, 0, 0, LVar0)
        Call(UpdateColliderTransform, COLLIDER_o267)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Interact_LowerDrawer) = {
    IfEq(MV_LowerDrawerOpen, FALSE)
        ExecWait(N(EVS_OpenLowerDrawer))
        Set(MV_LowerDrawerOpen, TRUE)
    Else
        ExecWait(N(EVS_CloseLowerDrawer))
        Set(MV_LowerDrawerOpen, FALSE)
    EndIf
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupDrawers) = {
    Call(ParentColliderToModel, COLLIDER_o265, MODEL_o419)
    BindTrigger(Ref(N(EVS_Interact_LowerDrawer)), TRIGGER_WALL_PRESS_A, COLLIDER_o265, 1, 0)
    Return
    End
};
