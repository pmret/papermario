#include "dgb_03.h"

#include "world/common/todo/UnkFunc11.inc.c"
#include "world/common/todo/UnkFunc12.inc.c"

EvtScript N(EVS_PushClock_Impl) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_LOOP(20)
        EVT_CALL(GetPartnerInUse, LVarA)
        EVT_IF_NE(LVarA, PARTNER_NONE)
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
    EVT_IF_NE(LVarA, PARTNER_NONE)
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
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o77, SOUND_LOOP_MOVE_STATUE, SOUND_SPACE_DEFAULT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o77, LVar0, 0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o77)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o112)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o113)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(StopSound, SOUND_LOOP_MOVE_STATUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushClockRight) = {
    EVT_IF_NE(GF_DGB03_PushedClock, FALSE)
        EVT_GOTO(90)
    EVT_END_IF
    EVT_SET(LVar6, 0)
    EVT_SET(LVar7, 48)
    EVT_SET(LVar8, 0)
    EVT_SET(LVar9, 27)
    EVT_EXEC_WAIT(N(EVS_PushClock_Impl))
    EVT_LABEL(90)
    EVT_IF_NE(LVar8, -1)
        EVT_SET(GF_DGB03_PushedClockLeft, FALSE)
        EVT_SET(GF_DGB03_PushedClock, TRUE)
        EVT_UNBIND
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PushClockLeft) = {
    EVT_IF_NE(GF_DGB03_PushedClock, FALSE)
        EVT_GOTO(90)
    EVT_END_IF
    EVT_SET(LVar6, 0)
    EVT_SET(LVar7, -48)
    EVT_SET(LVar8, 0)
    EVT_SET(LVar9, 28)
    EVT_EXEC_WAIT(N(EVS_PushClock_Impl))
    EVT_LABEL(90)
    EVT_IF_NE(LVar8, -1)
        EVT_SET(GF_DGB03_PushedClockLeft, TRUE)
        EVT_SET(GF_DGB03_PushedClock, TRUE)
        EVT_UNBIND
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupClock) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_o77, MODEL_o77)
    EVT_CALL(ParentColliderToModel, COLLIDER_o112, MODEL_o77)
    EVT_CALL(ParentColliderToModel, COLLIDER_o113, MODEL_o77)
    EVT_IF_EQ(GF_DGB03_PushedClock, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PushClockRight)), TRIGGER_WALL_PUSH, COLLIDER_o77, 1, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_PushClockLeft)), TRIGGER_WALL_PUSH, COLLIDER_o112, 1, 0)
    EVT_ELSE
        EVT_IF_EQ(GF_DGB03_PushedClockLeft, FALSE)
            EVT_SET(LVar0, 48)
        EVT_ELSE
            EVT_SET(LVar0, -48)
        EVT_END_IF
        EVT_CALL(TranslateModel, MODEL_o77, LVar0, 0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o77)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o112)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o113)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
