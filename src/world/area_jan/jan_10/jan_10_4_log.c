#include "jan_10.h"
#include "effects.h"
#include "sprite/player.h"

EvtScript N(EVS_SetupLogObjects) = {
    EVT_IF_EQ(GF_JAN10_CreateLogBridge, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o23, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_o79, FALSE)
        EVT_CALL(EnableModel, MODEL_o76, FALSE)
        EVT_CALL(TranslateGroup, MODEL_g24, 0, -165, 0)
        EVT_CALL(TranslateGroup, MODEL_g23, 0, -165, 0)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o11, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o22, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o23, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_o79, TRUE)
        EVT_CALL(EnableModel, MODEL_o76, TRUE)
        EVT_CALL(TranslateGroup, MODEL_g24, 0, 10, 0)
        EVT_CALL(TranslateGroup, MODEL_g23, 0, 10, 0)
        EVT_CALL(RotateGroup, MODEL_g24, 90, 0, 0, 1)
        EVT_CALL(RotateGroup, MODEL_g23, 90, 0, 0, 1)
        EVT_CALL(RotateGroup, MODEL_g24, 90, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_g23, -90, 0, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LogAnim_RiseUp) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o11, SOUND_SMACK_TREE, 0)
    EVT_CALL(MakeLerp, -165, -184, 5, EASING_QUARTIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g24, 0, LVar0, 0)
        EVT_CALL(TranslateGroup, MODEL_g23, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/UpdateLogShadow.inc.c"

EvtScript N(EVS_LogAnim_FallDown) = {
    EVT_THREAD
        EVT_WAIT(17)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
        EVT_CALL(N(UpdateLogShadow), MODEL_o79, MF_KillLogShadow)
    EVT_END_THREAD
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o11, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(MakeLerp, -184, 60, 30, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g24, 0, LVar0, 0)
        EVT_CALL(TranslateGroup, MODEL_g23, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(1)
    EVT_CALL(MakeLerp, 60, 0, 30, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g24, 0, LVar0, 0)
        EVT_CALL(TranslateGroup, MODEL_g23, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o11, SOUND_JAN_LOG_LAND, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 4, 0, 0, 0, 0)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 2, 3, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LogAnim_FallOver) = {
    EVT_THREAD
        EVT_WAIT(50)
        EVT_SET(MF_KillLogShadow, TRUE)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, 90, 60, EASING_CUBIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g24, 0, 0, 0)
        EVT_CALL(TranslateGroup, MODEL_g23, 0, 0, 0)
        EVT_CALL(RotateGroup, MODEL_g24, LVar0, 0, 0, 1)
        EVT_CALL(RotateGroup, MODEL_g23, LVar0, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 2, 3, 1)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LogAnim_Split) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o11, SOUND_JAN_LOG_SPLIT, 0)
    EVT_CALL(EnableModel, MODEL_o79, TRUE)
    EVT_CALL(EnableModel, MODEL_o76, TRUE)
    EVT_CALL(MakeLerp, 0, 90, 30, EASING_COS_FAST_OVERSHOOT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar2, LVar0)
        EVT_DIVF(LVar2, 9)
        EVT_CALL(TranslateGroup, MODEL_g24, 0, LVar2, 0)
        EVT_CALL(TranslateGroup, MODEL_g23, 0, LVar2, 0)
        EVT_CALL(RotateGroup, MODEL_g24, 90, 0, 0, 1)
        EVT_CALL(RotateGroup, MODEL_g23, 90, 0, 0, 1)
        EVT_CALL(RotateGroup, MODEL_g24, LVar0, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_g23, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Smash_BuriedLog) = {
    EVT_SET(GF_JAN10_CreateLogBridge, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(EVS_LogAnim_RiseUp))
    EVT_WAIT(1)
    EVT_EXEC_WAIT(N(EVS_LogAnim_FallDown))
    EVT_WAIT(1)
    EVT_EXEC_WAIT(N(EVS_LogAnim_FallOver))
    EVT_WAIT(1)
    EVT_EXEC_WAIT(N(EVS_LogAnim_Split))
    EVT_WAIT(1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_EXEC(N(EVS_SetupLogObjects))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupLogs) = {
    EVT_IF_EQ(GF_JAN10_CreateLogBridge, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Smash_BuriedLog)), TRIGGER_WALL_HAMMER, COLLIDER_o11, 1, 0)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupLogObjects))
    EVT_RETURN
    EVT_END
};
