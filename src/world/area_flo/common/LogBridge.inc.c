#include "common.h"

API_CALLABLE(N(GetFloorBelowLog)) {
    evt_set_variable(script, *script->ptrReadPos, gCollisionStatus.floorBelow);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_LogBridge) = {
    EVT_LOOP(0)
        EVT_CALL(N(GetFloorBelowLog), LVar0)
        EVT_IF_EQ(LVar0, LVar4)
            EVT_CALL(GetPlayerActionState, LVar0)
            EVT_IF_NE(LVar0, ACTION_STATE_HIT_LAVA)
                EVT_IF_EQ(LVar8, 0)
                    EVT_THREAD
                        EVT_CALL(GetModelCenter, LVar5)
                        EVT_CALL(PlaySoundAt, SOUND_FLO_LOG_OPEN, SOUND_PARAM_QUIET | SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_END_THREAD
                EVT_END_IF
                EVT_IF_LT(LVar7, 90)
                    EVT_IF_EQ(LVar7, 0)
                        EVT_WAIT(5)
                        EVT_SET(LVar8, 6)
                        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar9, COLLIDER_FLAGS_UPPER_MASK)
                    EVT_END_IF
                    EVT_ADD(LVar8, 1)
                    EVT_ADD(LVar7, LVar8)
                EVT_END_IF
                EVT_GOTO(50)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_NE(LVar7, 0)
            EVT_SUB(LVar8, 1)
            EVT_ADD(LVar7, LVar8)
            EVT_IF_LE(LVar7, 0)
                EVT_SET(LVar8, 0)
                EVT_SET(LVar7, 0)
                EVT_THREAD
                    EVT_CALL(GetModelCenter, LVar5)
                    EVT_CALL(PlaySoundAt, SOUND_FLO_LOG_CLOSE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
                EVT_END_THREAD
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, LVar9, COLLIDER_FLAGS_UPPER_MASK)
            EVT_END_IF
        EVT_END_IF
        EVT_LABEL(50)
        EVT_IF_GE(LVar7, 90)
            EVT_SET(LVar8, -1)
            EVT_SET(LVar7, 90)
        EVT_END_IF
        EVT_CALL(RotateModel, LVar5, LVar7, -1, 0, 0)
        EVT_CALL(RotateModel, LVar6, LVar7, -1, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

#define EVT_MAKE_LOG_BRIDGE(collider, roofCollider, outsideModel, insideModel, rotAngleVar, rotVelocityVar) \
    EVT_SET(LVar4, collider) \
    EVT_SET(LVar5, outsideModel) \
    EVT_SET(LVar6, insideModel) \
    EVT_SET(LVar7, rotAngleVar) \
    EVT_SET(LVar8, rotVelocityVar) \
    EVT_SET(LVar9, roofCollider) \
    EVT_EXEC(N(EVS_LogBridge))
