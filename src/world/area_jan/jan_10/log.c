#include "jan_10.h"
#include "effects.h"
#include "sprite/player.h"

EvtScript N(EVS_SetupLogObjects) = {
    IfEq(GF_JAN10_CreateLogBridge, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o23, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_o79, FALSE)
        Call(EnableModel, MODEL_o76, FALSE)
        Call(TranslateGroup, MODEL_g24, 0, -165, 0)
        Call(TranslateGroup, MODEL_g23, 0, -165, 0)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o11, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o22, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o23, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_o79, TRUE)
        Call(EnableModel, MODEL_o76, TRUE)
        Call(TranslateGroup, MODEL_g24, 0, 10, 0)
        Call(TranslateGroup, MODEL_g23, 0, 10, 0)
        Call(RotateGroup, MODEL_g24, 90, 0, 0, 1)
        Call(RotateGroup, MODEL_g23, 90, 0, 0, 1)
        Call(RotateGroup, MODEL_g24, 90, 0, 1, 0)
        Call(RotateGroup, MODEL_g23, -90, 0, 1, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_LogAnim_RiseUp) = {
    Call(PlaySoundAtCollider, COLLIDER_o11, SOUND_SMACK_TREE, 0)
    Call(MakeLerp, -165, -184, 5, EASING_QUARTIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g24, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g23, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

#include "world/common/todo/UpdateLogShadow.inc.c"

EvtScript N(EVS_LogAnim_FallDown) = {
    Thread
        Wait(17)
        Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
        Call(N(UpdateLogShadow), MODEL_o79, MF_KillLogShadow)
    EndThread
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o11, COLLIDER_FLAGS_UPPER_MASK)
    Call(MakeLerp, -184, 60, 30, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g24, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g23, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(1)
    Call(MakeLerp, 60, 0, 30, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g24, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g23, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(PlaySoundAtCollider, COLLIDER_o11, SOUND_JAN_LOG_LAND, 0)
    PlayEffect(EFFECT_LANDING_DUST, 4, 0, 0, 0, 0)
    Call(ShakeCam, CAM_DEFAULT, 2, 3, 1)
    Return
    End
};

EvtScript N(EVS_LogAnim_FallOver) = {
    Thread
        Wait(50)
        Set(MF_KillLogShadow, TRUE)
    EndThread
    Call(MakeLerp, 0, 90, 60, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g24, 0, 0, 0)
        Call(TranslateGroup, MODEL_g23, 0, 0, 0)
        Call(RotateGroup, MODEL_g24, LVar0, 0, 0, 1)
        Call(RotateGroup, MODEL_g23, LVar0, 0, 0, 1)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Thread
        Call(ShakeCam, CAM_DEFAULT, 2, 3, 1)
    EndThread
    Return
    End
};

EvtScript N(EVS_LogAnim_Split) = {
    Call(PlaySoundAtCollider, COLLIDER_o11, SOUND_JAN_LOG_SPLIT, 0)
    Call(EnableModel, MODEL_o79, TRUE)
    Call(EnableModel, MODEL_o76, TRUE)
    Call(MakeLerp, 0, 90, 30, EASING_COS_FAST_OVERSHOOT)
    Loop(0)
        Call(UpdateLerp)
        Set(LVar2, LVar0)
        DivF(LVar2, 9)
        Call(TranslateGroup, MODEL_g24, 0, LVar2, 0)
        Call(TranslateGroup, MODEL_g23, 0, LVar2, 0)
        Call(RotateGroup, MODEL_g24, 90, 0, 0, 1)
        Call(RotateGroup, MODEL_g23, 90, 0, 0, 1)
        Call(RotateGroup, MODEL_g24, LVar0, 0, 1, 0)
        Call(RotateGroup, MODEL_g23, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Smash_BuriedLog) = {
    Set(GF_JAN10_CreateLogBridge, TRUE)
    Call(DisablePlayerInput, TRUE)
    ExecWait(N(EVS_LogAnim_RiseUp))
    Wait(1)
    ExecWait(N(EVS_LogAnim_FallDown))
    Wait(1)
    ExecWait(N(EVS_LogAnim_FallOver))
    Wait(1)
    ExecWait(N(EVS_LogAnim_Split))
    Wait(1)
    Call(DisablePlayerInput, FALSE)
    Exec(N(EVS_SetupLogObjects))
    Return
    End
};

EvtScript N(EVS_SetupLogs) = {
    IfEq(GF_JAN10_CreateLogBridge, FALSE)
        BindTrigger(Ref(N(EVS_Smash_BuriedLog)), TRIGGER_WALL_HAMMER, COLLIDER_o11, 1, 0)
    EndIf
    Exec(N(EVS_SetupLogObjects))
    Return
    End
};
