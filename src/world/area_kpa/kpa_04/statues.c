#include "kpa_04.h"

#include "world/common/todo/UnkFunc11.inc.c"
#include "world/common/todo/UnkFunc12.inc.c"

EvtScript N(EVS_PushStatue_Impl) = {
    Loop(20)
#if !VERSION_JP
        Call(GetPartnerInUse, LVarA)
        IfNe(LVarA, 0)
            Set(LVar9, 0)
            Return
        EndIf
#endif
        Call(N(UnkFunc11), 25)
        IfEq(LVar0, 0)
            Set(LVar9, 0)
            Return
        Else
            Call(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        EndIf
        Wait(1)
    EndLoop
#if !VERSION_JP
    Call(GetPartnerInUse, LVarA)
    IfNe(LVarA, 0)
        Set(LVar9, 0)
        Return
    EndIf
#endif
    Call(DisablePlayerInput, TRUE)
    Call(PlaySoundAtCollider, COLLIDER_o160, SOUND_LOOP_MOVE_STATUE, SOUND_SPACE_DEFAULT)
    Thread
        Call(ShakeCam, CAM_DEFAULT, 0, 100, Float(0.6))
    EndThread
    Thread
        Call(EnableGroup, MODEL_g22, TRUE)
        Call(MakeLerp, 6, 100, 100, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            SetF(LVarA, LVar0)
            MulF(LVarA, Float(0.01))
            Call(ScaleGroup, MODEL_g22, LVarA, 1, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(InterpPlayerYaw, 270, 0)
        Call(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Set(LVar1, LVar0)
#if VERSION_JP
        Add(LVar1, LVarA)
#else
        Add(LVar1, LVarB)
#endif
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
#if VERSION_JP
    Call(MakeLerp, 0, LVarA, 100, EASING_LINEAR)
#else
    Call(MakeLerp, 0, LVarB, 100, EASING_LINEAR)
#endif
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g20, LVar0, 0, 0)
        Call(UpdateColliderTransform, COLLIDER_o160)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(StopSound, SOUND_LOOP_MOVE_STATUE)
    Return
    End
};

EvtScript N(EVS_PushStatue_FromRight) = {
    IfNe(GB_KPA04_StatuePosition, 0)
        Return
    EndIf
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLe(LVar0, 30)
        Return
    EndIf
    IfLe(LVar2, 130)
        Return
    EndIf
    IfGe(LVar2, 170)
        Return
    EndIf
    IfGe(LVar0, 0)
        Set(LVar9, 1)
#if VERSION_JP
        Set(LVarA, -50)
#else
        Set(LVarB, -50)
#endif
        ExecWait(N(EVS_PushStatue_Impl))
    Else
        Set(LVar9, 2)
#if VERSION_JP
        Set(LVarA, 50)
#else
        Set(LVarB, 50)
#endif
        ExecWait(N(EVS_PushStatue_Impl))
    EndIf
    Set(GB_KPA04_StatuePosition, LVar9)
    IfNe(GB_KPA04_StatuePosition, 0)
        Call(EnableModel, MODEL_o187, TRUE)
        Call(EnableModel, MODEL_o180, TRUE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitts, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};

EvtScript N(EVS_SetupStatues) = {
    Call(ParentColliderToModel, COLLIDER_o160, MODEL_o103)
    Switch(GB_KPA04_StatuePosition)
        CaseEq(0)
            BindTrigger(Ref(N(EVS_PushStatue_FromRight)), TRIGGER_WALL_PUSH, COLLIDER_o160, 1, 0)
            Call(EnableGroup, MODEL_g22, FALSE)
        CaseEq(1)
            Call(TranslateGroup, MODEL_g20, -50, 0, 0)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitts, COLLIDER_FLAGS_UPPER_MASK)
        CaseEq(2)
            Call(TranslateGroup, MODEL_g20, 50, 0, 0)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitts, COLLIDER_FLAGS_UPPER_MASK)
    EndSwitch
    Call(UpdateColliderTransform, COLLIDER_o160)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliwtt, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};
