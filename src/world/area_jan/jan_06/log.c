#include "jan_06.h"
#include "effects.h"
#include "sprite/player.h"

EvtScript N(EVS_SetupLogObjects) = {
    IfEq(GF_JAN06_CreateLogBridge, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o169, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_o95, FALSE)
        Call(EnableModel, MODEL_o96, FALSE)
        Call(TranslateGroup, MODEL_g20, 0, -150, 0)
        Call(TranslateGroup, MODEL_g21, 0, -150, 0)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o167, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o168, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o169, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_o95, TRUE)
        Call(EnableModel, MODEL_o96, TRUE)
        Call(TranslateGroup, MODEL_g20, 0, 10, 0)
        Call(TranslateGroup, MODEL_g21, 0, 10, 0)
        Call(RotateGroup, MODEL_g20, -90, 0, 0, 1)
        Call(RotateGroup, MODEL_g21, -90, 0, 0, 1)
        Call(RotateGroup, MODEL_g20, 90, 0, 1, 0)
        Call(RotateGroup, MODEL_g21, -90, 0, 1, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_LogAnim_RiseUp) = {
    Call(PlaySoundAtCollider, COLLIDER_o167, SOUND_SMACK_TREE, 0)
    Call(MakeLerp, -150, -169, 5, EASING_QUARTIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g20, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g21, 0, LVar0, 0)
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
        Call(N(UpdateLogShadow), 130, MF_KillLogShadow)
    EndThread
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o167, COLLIDER_FLAGS_UPPER_MASK)
    Call(MakeLerp, -169, 60, 30, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g20, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g21, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(1)
    Call(MakeLerp, 60, 0, 30, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g20, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g21, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(PlaySoundAtCollider, COLLIDER_o167, SOUND_JAN_LOG_LAND, 0)
    PlayEffect(EFFECT_LANDING_DUST, 4, -100, 0, 60, 0)
    Call(ShakeCam, CAM_DEFAULT, 2, 3, 1)
    Return
    End
};

EvtScript N(EVS_LogAnim_FallOver) = {
    Thread
        Wait(50)
        Set(MF_KillLogShadow, TRUE)
    EndThread
    Call(MakeLerp, 0, -90, 60, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g20, 0, 0, 0)
        Call(TranslateGroup, MODEL_g21, 0, 0, 0)
        Call(RotateGroup, MODEL_g20, LVar0, 0, 0, 1)
        Call(RotateGroup, MODEL_g21, LVar0, 0, 0, 1)
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
    Call(PlaySoundAtCollider, COLLIDER_o167, SOUND_JAN_LOG_SPLIT, 0)
    Call(EnableModel, MODEL_o95, TRUE)
    Call(EnableModel, MODEL_o96, TRUE)
    Call(MakeLerp, 0, 90, 30, EASING_COS_FAST_OVERSHOOT)
    Loop(0)
        Call(UpdateLerp)
        Set(LVar2, LVar0)
        DivF(LVar2, 9)
        Call(TranslateGroup, MODEL_g20, 0, LVar2, 0)
        Call(TranslateGroup, MODEL_g21, 0, LVar2, 0)
        Call(RotateGroup, MODEL_g20, -90, 0, 0, 1)
        Call(RotateGroup, MODEL_g21, -90, 0, 0, 1)
        Call(RotateGroup, MODEL_g20, LVar0, 0, 1, 0)
        Call(RotateGroup, MODEL_g21, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Smash_BuriedLog) = {
    Set(GF_JAN06_CreateLogBridge, TRUE)
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
    IfEq(GF_JAN06_CreateLogBridge, FALSE)
        BindTrigger(Ref(N(EVS_Smash_BuriedLog)), TRIGGER_WALL_HAMMER, COLLIDER_o167, 1, 0)
    EndIf
    Exec(N(EVS_SetupLogObjects))
    Return
    End
};
