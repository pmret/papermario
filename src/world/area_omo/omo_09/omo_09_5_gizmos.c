#include "omo_09.h"

EvtScript N(EVS_Gizmos_Wheels) = {
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, -360, 100, EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_ha1, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha2, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha3, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha4, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_ha5, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Gizmos_Shutters) = {
    EVT_LABEL(0)
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, 160, 60, EASING_COS_IN_OUT)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m2_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m2_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m3_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m3_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m4_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m4_2, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(MakeLerp, 160, 0, 60, EASING_COS_IN_OUT)
        EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m2_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m2_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m3_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m3_2, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_m4_1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_m4_2, LVar0, 0, 1, 0)
            EVT_WAIT(2)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(2)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Gizmos_Clocks) = {
    EVT_LABEL(0)
        EVT_CALL(MakeLerp, 0, -360, 100, EASING_LINEAR)
        EVT_LABEL(1)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_hari1, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_hari2, LVar0, 0, 0, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

typedef struct MovingBlock {
    /* 0x0 */ s32 colliderID;
    /* 0x4 */ s32 modelID;
    /* 0x8 */ s32 moveDist;
    /* 0xC */ s32 moveDelay;
} MovingBlock; // size = 0x10

MovingBlock N(MovingBlockPlatforms)[] = {
    { COLLIDER_u1, MODEL_u1, 40,  41 },
    { COLLIDER_u2, MODEL_u2, 60,  51 },
    { COLLIDER_u3, MODEL_u3, 70,   1 },
    { COLLIDER_u4, MODEL_u4, 30,  61 },
    { COLLIDER_u5, MODEL_u5, 50,  71 },
    { COLLIDER_u6, MODEL_u6, 70, 101 },
};

API_CALLABLE(N(AwaitPlayerNearPlatforms)) {
    if (gPlayerStatus.pos.x < 850.0f) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Gizmos_MovingBlocks) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_CALL(N(AwaitPlayerNearPlatforms))
    EVT_WAIT(LVar9)
    EVT_CALL(ParentColliderToModel, LVar6, LVar7)
    EVT_LOOP(0)
        EVT_CALL(MakeLerp, 0, LVar8, LVar8, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, LVar7, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, LVar6)
            EVT_CALL(N(AwaitPlayerNearPlatforms))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LOOP(30)
            EVT_CALL(N(AwaitPlayerNearPlatforms))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(MakeLerp, LVar8, 0, LVar8, EASING_COS_IN_OUT)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(TranslateModel, LVar7, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, LVar6)
            EVT_CALL(N(AwaitPlayerNearPlatforms))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_LOOP(30)
            EVT_CALL(N(AwaitPlayerNearPlatforms))
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupGizmos) = {
    EVT_EXEC(N(EVS_Gizmos_Wheels))
    EVT_EXEC(N(EVS_Gizmos_Shutters))
    EVT_EXEC(N(EVS_Gizmos_Clocks))
    EVT_USE_BUF(EVT_PTR(N(MovingBlockPlatforms)))
    EVT_LOOP(ARRAY_COUNT(N(MovingBlockPlatforms)))
        EVT_BUF_READ4(LVar6, LVar7, LVar8, LVar9)
        EVT_EXEC(N(EVS_Gizmos_MovingBlocks))
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
