#include "kpa_115.h"

#include "world/common/todo/UnkFunc11.inc.c"
#include "world/common/todo/UnkFunc12.inc.c"

EvtScript N(EVS_PushMiddleStatue_Impl) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_LOOP(20)
        EVT_CALL(GetPartnerInUse, LVarA)
        EVT_IF_NE(LVarA, 0)
            EVT_SET(LVar8, -1)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(N(UnkFunc11), LVar9)
        EVT_IF_EQ(LVar0, 0)
            EVT_SET(LVar8, -1)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetPartnerInUse, LVarA)
    EVT_IF_NE(LVarA, 0)
        EVT_SET(LVar8, -1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 100, EVT_FLOAT(0.6))
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_GE(LVar6, LVar7)
            EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_ELSE
            EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_END_IF
        EVT_CALL(SetPlayerActionState, ACTION_STATE_PUSHING_BLOCK)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, LVar0)
        EVT_SET(LVar2, LVar7)
        EVT_SUB(LVar2, LVar6)
        EVT_ADD(LVar1, LVar2)
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
    EVT_CALL(MakeLerp, LVar6, LVar7, 100, EASING_LINEAR)
    EVT_CALL(PlaySoundAtCollider, LVar9, SOUND_LOOP_MOVE_STATUE, SOUND_SPACE_DEFAULT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g20, LVar0, 0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o145)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o143)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o144)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(StopSound, SOUND_LOOP_MOVE_STATUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushMiddleStatue_Impl_FromLeft) = {
    EVT_IF_EQ(GB_KPA115_StatuePosition, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GB_KPA115_StatuePosition, 0)
        EVT_SET(LVar6, 0)
        EVT_SET(LVar7, 50)
        EVT_SET(LVar8, 1)
    EVT_ELSE
        EVT_SET(LVar6, 50)
        EVT_SET(LVar7, 100)
        EVT_SET(LVar8, 1)
    EVT_END_IF
    EVT_SET(LVar9, COLLIDER_o143)
    EVT_EXEC_WAIT(N(EVS_PushMiddleStatue_Impl))
    EVT_IF_NE(LVar8, -1)
        EVT_SET(GB_KPA115_StatuePosition, LVar8)
    EVT_END_IF
    EVT_IF_EQ(GB_KPA115_StatuePosition, 1)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o157, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushMiddleStatue_Impl_FromRight) = {
    EVT_IF_EQ(GB_KPA115_StatuePosition, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GB_KPA115_StatuePosition, 1)
        EVT_SET(LVar6, 50)
        EVT_SET(LVar7, 0)
        EVT_SET(LVar8, 0)
    EVT_ELSE
        EVT_SET(LVar6, 100)
        EVT_SET(LVar7, 50)
        EVT_SET(LVar8, 0)
    EVT_END_IF
    EVT_SET(LVar9, COLLIDER_o144)
    EVT_EXEC_WAIT(N(EVS_PushMiddleStatue_Impl))
    EVT_IF_NE(LVar8, -1)
        EVT_SET(GB_KPA115_StatuePosition, LVar8)
    EVT_END_IF
    EVT_IF_EQ(GB_KPA115_StatuePosition, 0)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o157, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupStatues) = {
    EVT_SWITCH(GB_KPA115_StatuePosition)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(1)
            EVT_CALL(TranslateGroup, MODEL_g20, 50, 0, 0)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o157, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_EQ(2)
            EVT_CALL(TranslateGroup, MODEL_g20, 100, 0, 0)
    EVT_END_SWITCH
    EVT_CALL(ParentColliderToModel, COLLIDER_o145, MODEL_o103)
    EVT_CALL(ParentColliderToModel, COLLIDER_o143, MODEL_o103)
    EVT_CALL(ParentColliderToModel, COLLIDER_o144, MODEL_o103)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PushMiddleStatue_Impl_FromLeft)), TRIGGER_WALL_PUSH, COLLIDER_o143, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PushMiddleStatue_Impl_FromRight)), TRIGGER_WALL_PUSH, COLLIDER_o144, 1, 0)
    EVT_RETURN
    EVT_END
};
