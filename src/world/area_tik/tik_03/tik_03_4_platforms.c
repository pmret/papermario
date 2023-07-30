#include "tik_03.h"

s32 N(PlatformColliders)[] = {
    COLLIDER_1,
    COLLIDER_2,
    COLLIDER_3,
    COLLIDER_4,
};

API_CALLABLE(N(PausePlatformsDuringPound)) {
    PlayerStatus* player = &gPlayerStatus;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(N(PlatformColliders)); i++) {
        if (gCollisionStatus.curFloor != N(PlatformColliders)[i]) {
            continue;
        }
        if ((player->actionState == ACTION_STATE_SPIN_POUND) || (player->actionState == ACTION_STATE_TORNADO_POUND)) {
            return ApiStatus_BLOCK;
        }
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdatePlatform) = {
    EVT_SET_GROUP(EVT_GROUP_EF)
    EVT_CALL(ParentColliderToModel, LVarB, LVarA)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_SETF(LVarD, EVT_FLOAT(-300.0))
    EVT_SUBF(LVarD, LVarC)
    EVT_LABEL(0)
        EVT_SETF(LVar1, LVarC)
        EVT_SUBF(LVar0, EVT_FLOAT(80.0))
        EVT_LABEL(1)
            EVT_CALL(N(PausePlatformsDuringPound))
            EVT_ADDF(LVar0, EVT_FLOAT(1.5))
            EVT_ADDF(LVar1, EVT_FLOAT(1.5))
            EVT_CALL(TranslateModel, LVarA, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, LVarB)
            EVT_WAIT(1)
            EVT_IF_LT(LVar1, EVT_FLOAT(100.0))
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(TranslateModel, LVarA, 0, LVarD, 0)
        EVT_SETF(LVar0, LVarD)
        EVT_SETF(LVarC, EVT_FLOAT(-300.0))
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CreatePlatform1) = {
    EVT_SET(LVarA, MODEL_erb)
    EVT_SET(LVarB, COLLIDER_1)
    EVT_SET(LVarC, 20)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatform))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CreatePlatform2) = {
    EVT_SET(LVarA, MODEL_o40)
    EVT_SET(LVarB, COLLIDER_3)
    EVT_SET(LVarC, -80)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatform))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CreatePlatform3) = {
    EVT_SET(LVarA, MODEL_o41)
    EVT_SET(LVarB, COLLIDER_4)
    EVT_SET(LVarC, -170)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatform))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CreatePlatform4) = {
    EVT_SET(LVarA, MODEL_o39)
    EVT_SET(LVarB, COLLIDER_2)
    EVT_SET(LVarC, -270)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatform))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupPlatforms) = {
    EVT_EXEC(N(EVS_CreatePlatform1))
    EVT_EXEC(N(EVS_CreatePlatform2))
    EVT_EXEC(N(EVS_CreatePlatform3))
    EVT_EXEC(N(EVS_CreatePlatform4))
    EVT_RETURN
    EVT_END
};
