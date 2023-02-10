#include "jan_12.h"

#define PULL_VINE_CALLBACK_SCRIPT MV_PullVineCallback
#include "../common/PullVine.inc.c"

#include "../common/MoveBush.inc.c"
#include "../common/MoveBushTemplates.h"

EvtScript N(EVS_MoveBushes_Separate) = EVT_MOVE_BUSHES(COLLIDER_o12,
    MODEL_o12, MODEL_o26, MV_BushOffsetL, MV_BushOffsetR);

EvtScript N(EVS_Inspect_MoveBushes) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o12, COLLIDER_FLAGS_UPPER_MASK)
    EVT_EXEC(N(EVS_MoveBushes_Separate))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(MakeLerp, 0, 45, 30, EASING_CUBIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(MV_BushOffsetR, LVar0)
        EVT_SETF(MV_BushOffsetL, MV_BushOffsetR)
        EVT_MULF(MV_BushOffsetL, -1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnPullVine) = {
    EVT_CALL(GetModelCenter, LVar9)
    EVT_ADD(LVar2, 10)
    EVT_CALL(MakeItemEntity, ITEM_EGG, LVar0, 100, LVar2, ITEM_SPAWN_MODE_FALL, GF_JAN12_PullVine_Egg2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupVines) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_Inspect_MoveBushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o12, 1, 0)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, jan_12_ENTRY_1)
        EVT_EXEC(N(EVS_Inspect_MoveBushes))
    EVT_END_IF
    EVT_SET(MV_PullVineCallback, EVT_PTR(N(EVS_OnPullVine)))
    EVT_SET(LVarF, MODEL_o47)
    EVT_SET(LVarC, 0)
    EVT_SET(LVarD, MODEL_o76)
    EVT_SET(LVarE, MODEL_o77)
    EVT_SET(LVar9, MODEL_o6)
    EVT_SET(LVarA, MODEL_o62)
    EVT_SET(LVarB, MODEL_o63)
    EVT_SET(LVar5, 15)
    EVT_EXEC(N(EVS_PullVine_Manage))
    EVT_RETURN
    EVT_END
};
