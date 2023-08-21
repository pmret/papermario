#include "kpa_04.h"

#include "world/common/todo/UnkFunc11.inc.c"
#include "world/common/todo/UnkFunc12.inc.c"

EvtScript N(EVS_PushStatue_Impl) = {
    EVT_LOOP(20)
        EVT_CALL(GetPartnerInUse, LVarA)
        EVT_IF_NE(LVarA, 0)
            EVT_SET(LVar9, 0)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(N(UnkFunc11), 25)
        EVT_IF_EQ(LVar0, 0)
            EVT_SET(LVar9, 0)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetPartnerInUse, LVarA)
    EVT_IF_NE(LVarA, 0)
        EVT_SET(LVar9, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o160, SOUND_LOOP_MOVE_STATUE, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 100, EVT_FLOAT(0.6))
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(EnableGroup, MODEL_g22, TRUE)
        EVT_CALL(MakeLerp, 6, 100, 100, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVarA, LVar0)
            EVT_MULF(LVarA, EVT_FLOAT(0.01))
            EVT_CALL(ScaleGroup, MODEL_g22, LVarA, 1, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, LVar0)
        EVT_ADD(LVar1, LVarB)
        EVT_CALL(MakeLerp, LVar0, LVar1, 100, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(UnkFunc12))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, LVarB, 100, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g20, LVar0, 0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o160)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(StopSound, SOUND_LOOP_MOVE_STATUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushStatue_FromRight) = {
    EVT_IF_NE(GB_KPA04_StatuePosition, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LE(LVar0, 30)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LE(LVar2, 130)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(LVar2, 170)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GE(LVar0, 0)
        EVT_SET(LVar9, 1)
        EVT_SET(LVarB, -50)
        EVT_EXEC_WAIT(N(EVS_PushStatue_Impl))
    EVT_ELSE
        EVT_SET(LVar9, 2)
        EVT_SET(LVarB, 50)
        EVT_EXEC_WAIT(N(EVS_PushStatue_Impl))
    EVT_END_IF
    EVT_SET(GB_KPA04_StatuePosition, LVar9)
    EVT_IF_NE(GB_KPA04_StatuePosition, 0)
        EVT_CALL(EnableModel, MODEL_o187, TRUE)
        EVT_CALL(EnableModel, MODEL_o180, TRUE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitts, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupStatues) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_o160, MODEL_o103)
    EVT_SWITCH(GB_KPA04_StatuePosition)
        EVT_CASE_EQ(0)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PushStatue_FromRight)), TRIGGER_WALL_PUSH, COLLIDER_o160, 1, 0)
            EVT_CALL(EnableGroup, MODEL_g22, FALSE)
        EVT_CASE_EQ(1)
            EVT_CALL(TranslateGroup, MODEL_g20, -50, 0, 0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitts, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_EQ(2)
            EVT_CALL(TranslateGroup, MODEL_g20, 50, 0, 0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitts, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_SWITCH
    EVT_CALL(UpdateColliderTransform, COLLIDER_o160)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deiliwtt, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};
