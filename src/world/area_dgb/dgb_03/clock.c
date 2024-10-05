#include "dgb_03.h"

#include "world/common/todo/UnkFunc11.inc.c"
#include "world/common/todo/UnkFunc12.inc.c"

EvtScript N(EVS_PushClock_Impl) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Loop(20)
        Call(GetPartnerInUse, LVarA)
        IfNe(LVarA, PARTNER_NONE)
            Set(LVar8, -1)
            Return
        EndIf
        Call(N(UnkFunc11), LVar9)
        IfEq(LVar0, 0)
            Set(LVar8, -1)
            Return
        Else
            Call(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        EndIf
        Wait(1)
    EndLoop
    Call(GetPartnerInUse, LVarA)
    IfNe(LVarA, PARTNER_NONE)
        Set(LVar8, -1)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 100, Float(0.6))
    EndThread
    Thread
        IfGe(LVar6, LVar7)
            Call(InterpPlayerYaw, 270, 0)
        Else
            Call(InterpPlayerYaw, 90, 0)
        EndIf
        Call(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Set(LVar1, LVar0)
        Set(LVar2, LVar7)
        Sub(LVar2, LVar6)
        Add(LVar1, LVar2)
        Call(MakeLerp, LVar0, LVar1, 100, EASING_LINEAR)
        Loop(0)
            Call(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
            Call(UpdateLerp)
            Call(N(UnkFunc12))
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetPlayerActionState, ACTION_STATE_IDLE)
        Call(DisablePlayerInput, FALSE)
    EndThread
    Call(MakeLerp, LVar6, LVar7, 100, EASING_LINEAR)
    Call(PlaySoundAtCollider, COLLIDER_o77, SOUND_LOOP_MOVE_STATUE, SOUND_SPACE_DEFAULT)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o77, LVar0, 0, 0)
        Call(UpdateColliderTransform, COLLIDER_o77)
        Call(UpdateColliderTransform, COLLIDER_o112)
        Call(UpdateColliderTransform, COLLIDER_o113)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(StopSound, SOUND_LOOP_MOVE_STATUE)
    Return
    End
};

EvtScript N(EVS_PushClockRight) = {
    IfNe(GF_DGB03_PushedClock, FALSE)
        Goto(90)
    EndIf
    Set(LVar6, 0)
    Set(LVar7, 48)
    Set(LVar8, 0)
    Set(LVar9, 27)
    ExecWait(N(EVS_PushClock_Impl))
    Label(90)
    IfNe(LVar8, -1)
        Set(GF_DGB03_PushedClockLeft, FALSE)
        Set(GF_DGB03_PushedClock, TRUE)
        Unbind
    EndIf
    Return
    End
};

EvtScript N(EVS_PushClockLeft) = {
    IfNe(GF_DGB03_PushedClock, FALSE)
        Goto(90)
    EndIf
    Set(LVar6, 0)
    Set(LVar7, -48)
    Set(LVar8, 0)
    Set(LVar9, 28)
    ExecWait(N(EVS_PushClock_Impl))
    Label(90)
    IfNe(LVar8, -1)
        Set(GF_DGB03_PushedClockLeft, TRUE)
        Set(GF_DGB03_PushedClock, TRUE)
        Unbind
    EndIf
    Return
    End
};

EvtScript N(EVS_SetupClock) = {
    Call(ParentColliderToModel, COLLIDER_o77, MODEL_o77)
    Call(ParentColliderToModel, COLLIDER_o112, MODEL_o77)
    Call(ParentColliderToModel, COLLIDER_o113, MODEL_o77)
    IfEq(GF_DGB03_PushedClock, FALSE)
        BindTrigger(Ref(N(EVS_PushClockRight)), TRIGGER_WALL_PUSH, COLLIDER_o77, 1, 0)
        BindTrigger(Ref(N(EVS_PushClockLeft)), TRIGGER_WALL_PUSH, COLLIDER_o112, 1, 0)
    Else
        IfEq(GF_DGB03_PushedClockLeft, FALSE)
            Set(LVar0, 48)
        Else
            Set(LVar0, -48)
        EndIf
        Call(TranslateModel, MODEL_o77, LVar0, 0, 0)
        Call(UpdateColliderTransform, COLLIDER_o77)
        Call(UpdateColliderTransform, COLLIDER_o112)
        Call(UpdateColliderTransform, COLLIDER_o113)
    EndIf
    Return
    End
};
