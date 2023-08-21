#include "common.h"

EvtScript N(EVS_UseGate) = {
    EVT_THREAD
        EVT_CALL(PlaySoundAtCollider, LVar9, SOUND_FOREST_GATE_OPEN, SOUND_SPACE_DEFAULT)
        EVT_WAIT(19)
        EVT_CALL(PlaySoundAtCollider, LVar9, SOUND_FOREST_GATE_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_SWITCH(AB_MIM_1)
        EVT_CASE_EQ(0)
            EVT_THREAD
                EVT_CALL(MakeLerp, 10, 90, 10, EASING_QUADRATIC_IN)
                EVT_LABEL(10)
                EVT_CALL(UpdateLerp)
                EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
                EVT_CALL(UpdateColliderTransform, LVar9)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(10)
                EVT_END_IF
            EVT_END_THREAD
            EVT_WAIT(15)
            EVT_THREAD
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, LVar7)
                EVT_ADD(LVar2, LVar8)
                EVT_CALL(PlayerMoveTo, LVar0, LVar2, 15)
            EVT_END_THREAD
            EVT_SET(LVar1, 1)
            EVT_EXEC(N(EVS_SetGateCameraZones))
            EVT_CALL(MakeLerp, 90, 360, 30, EASING_LINEAR)
            EVT_LABEL(20)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
            EVT_CALL(UpdateColliderTransform, LVar9)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(20)
            EVT_END_IF
            EVT_EXEC(N(EVS_ResetGates))
            EVT_SET(AB_MIM_1, 1)
            EVT_SET(GF_MIM_ChoosingPath, TRUE)
        EVT_CASE_EQ(1)
            EVT_THREAD
                EVT_CALL(MakeLerp, 360, 270, 10, EASING_QUADRATIC_IN)
                EVT_LABEL(30)
                EVT_CALL(UpdateLerp)
                EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
                EVT_CALL(UpdateColliderTransform, LVar9)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(30)
                EVT_END_IF
            EVT_END_THREAD
            EVT_WAIT(15)
            EVT_THREAD
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_SUB(LVar0, LVar7)
                EVT_SUB(LVar2, LVar8)
                EVT_CALL(PlayerMoveTo, LVar0, LVar2, 15)
            EVT_END_THREAD
            EVT_SET(LVar1, 2)
            EVT_EXEC(N(EVS_SetGateCameraZones))
            EVT_CALL(MakeLerp, 270, -10, 30, EASING_LINEAR)
            EVT_LABEL(40)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
            EVT_CALL(UpdateColliderTransform, LVar9)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(40)
            EVT_END_IF
            EVT_SET(AB_MIM_1, 2)
        EVT_CASE_EQ(2)
            EVT_THREAD
                EVT_CALL(MakeLerp, -10, 90, 10, EASING_QUADRATIC_IN)
                EVT_LABEL(50)
                EVT_CALL(UpdateLerp)
                EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
                EVT_CALL(UpdateColliderTransform, LVar9)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(50)
                EVT_END_IF
            EVT_END_THREAD
            EVT_WAIT(15)
            EVT_THREAD
                EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, LVar7)
                EVT_ADD(LVar2, LVar8)
                EVT_CALL(PlayerMoveTo, LVar0, LVar2, 15)
            EVT_END_THREAD
            EVT_SET(LVar1, 1)
            EVT_EXEC(N(EVS_SetGateCameraZones))
            EVT_CALL(MakeLerp, 90, 360, 30, EASING_LINEAR)
            EVT_LABEL(60)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, LVarA, LVar0, 0, 1, 0)
            EVT_CALL(UpdateColliderTransform, LVar9)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(60)
            EVT_END_IF
            EVT_EXEC(N(EVS_ResetGates))
            EVT_SET(AB_MIM_1, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
