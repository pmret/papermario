#include "tik_07.h"

s32 N(PlatformColliders)[] = {
    COLLIDER_o31,
    COLLIDER_o32,
    COLLIDER_o33,
    COLLIDER_o34,
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
    EVT_SETF(LVarD, EVT_FLOAT(-90.0))
    EVT_SUBF(LVarD, LVarC)
    EVT_LABEL(0)
        EVT_SETF(LVar1, LVarC)
        EVT_LABEL(1)
            EVT_CALL(N(PausePlatformsDuringPound))
            EVT_ADDF(LVar0, EVT_FLOAT(1.5))
            EVT_ADDF(LVar1, EVT_FLOAT(1.5))
            EVT_CALL(TranslateModel, LVarA, 0, LVar0, 0)
            EVT_CALL(UpdateColliderTransform, LVarB)
            EVT_WAIT(1)
            EVT_IF_LT(LVar1, EVT_FLOAT(310.0))
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(TranslateModel, LVarA, 0, LVarD, 0)
        EVT_SETF(LVar0, LVarD)
        EVT_SETF(LVarC, EVT_FLOAT(-90.0))
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CreatePlatform1) = {
    EVT_SET(LVarA, MODEL_o32)
    EVT_SET(LVarB, COLLIDER_o32)
    EVT_SET(LVarC, 110)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatform))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CreatePlatform2) = {
    EVT_SET(LVarA, MODEL_o31)
    EVT_SET(LVarB, COLLIDER_o31)
    EVT_SET(LVarC, 10)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatform))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CreatePlatform3) = {
    EVT_SET(LVarA, MODEL_o33)
    EVT_SET(LVarB, COLLIDER_o33)
    EVT_SET(LVarC, -90)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatform))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CreatePlatform4) = {
    EVT_SET(LVarA, MODEL_o34)
    EVT_SET(LVarB, COLLIDER_o34)
    EVT_SET(LVarC, -190)
    EVT_EXEC_WAIT(N(EVS_UpdatePlatform))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupPlatforms) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o48, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_CreatePlatform1))
    EVT_EXEC(N(EVS_CreatePlatform2))
    EVT_EXEC(N(EVS_CreatePlatform3))
    EVT_EXEC(N(EVS_CreatePlatform4))
    EVT_RETURN
    EVT_END
};
