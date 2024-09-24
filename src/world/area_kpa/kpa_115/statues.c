#include "kpa_115.h"

#include "world/common/todo/UnkFunc11.inc.c"
#include "world/common/todo/UnkFunc12.inc.c"

EvtScript N(EVS_PushMiddleStatue_Impl) = {
#if !VERSION_JP
    SetGroup(EVT_GROUP_00)
#endif
    Loop(20)
#if !VERSION_JP
        Call(GetPartnerInUse, LVarA)
        IfNe(LVarA, 0)
            Set(LVar8, -1)
            Return
        EndIf
#endif
        Call(N(UnkFunc11), LVar9)
        IfEq(LVar0, 0)
            Set(LVar8, -1)
            Return
        Else
            Call(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        EndIf
        Wait(1)
    EndLoop
#if !VERSION_JP
    Call(GetPartnerInUse, LVarA)
    IfNe(LVarA, 0)
        Set(LVar8, -1)
        Return
    EndIf
#endif
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
    Call(PlaySoundAtCollider, LVar9, SOUND_LOOP_MOVE_STATUE, SOUND_SPACE_DEFAULT)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g20, LVar0, 0, 0)
        Call(UpdateColliderTransform, COLLIDER_o145)
        Call(UpdateColliderTransform, COLLIDER_o143)
        Call(UpdateColliderTransform, COLLIDER_o144)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(StopSound, SOUND_LOOP_MOVE_STATUE)
    Return
    End
};

EvtScript N(EVS_PushMiddleStatue_Impl_FromLeft) = {
    IfEq(GB_KPA115_StatuePosition, 1)
        Return
    EndIf
    IfEq(GB_KPA115_StatuePosition, 0)
        Set(LVar6, 0)
        Set(LVar7, 50)
        Set(LVar8, 1)
    Else
        Set(LVar6, 50)
        Set(LVar7, 100)
        Set(LVar8, 1)
    EndIf
    Set(LVar9, COLLIDER_o143)
    ExecWait(N(EVS_PushMiddleStatue_Impl))
    IfNe(LVar8, -1)
        Set(GB_KPA115_StatuePosition, LVar8)
    EndIf
    IfEq(GB_KPA115_StatuePosition, 1)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o157, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};

EvtScript N(EVS_PushMiddleStatue_Impl_FromRight) = {
    IfEq(GB_KPA115_StatuePosition, 0)
        Return
    EndIf
    IfEq(GB_KPA115_StatuePosition, 1)
        Set(LVar6, 50)
        Set(LVar7, 0)
        Set(LVar8, 0)
    Else
        Set(LVar6, 100)
        Set(LVar7, 50)
        Set(LVar8, 0)
    EndIf
    Set(LVar9, COLLIDER_o144)
    ExecWait(N(EVS_PushMiddleStatue_Impl))
    IfNe(LVar8, -1)
        Set(GB_KPA115_StatuePosition, LVar8)
    EndIf
    IfEq(GB_KPA115_StatuePosition, 0)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o157, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};

EvtScript N(EVS_SetupStatues) = {
    Switch(GB_KPA115_StatuePosition)
        CaseEq(0)
        CaseEq(1)
            Call(TranslateGroup, MODEL_g20, 50, 0, 0)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o157, COLLIDER_FLAGS_UPPER_MASK)
        CaseEq(2)
            Call(TranslateGroup, MODEL_g20, 100, 0, 0)
    EndSwitch
    Call(ParentColliderToModel, COLLIDER_o145, MODEL_o103)
    Call(ParentColliderToModel, COLLIDER_o143, MODEL_o103)
    Call(ParentColliderToModel, COLLIDER_o144, MODEL_o103)
    BindTrigger(Ref(N(EVS_PushMiddleStatue_Impl_FromLeft)), TRIGGER_WALL_PUSH, COLLIDER_o143, 1, 0)
    BindTrigger(Ref(N(EVS_PushMiddleStatue_Impl_FromRight)), TRIGGER_WALL_PUSH, COLLIDER_o144, 1, 0)
    Return
    End
};
