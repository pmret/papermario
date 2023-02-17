#include "jan_14.h"

enum {
    VINE_IDX_0      = 0,
    VINE_IDX_1      = 1,
    VINE_IDX_2      = 2,
    VINE_IDX_3      = 3,
    VINE_IDX_4      = 4,
    VINE_IDX_5      = 5,
};

#define PULL_VINE_CALLBACK_SCRIPT MV_PullVineCallback
#include "../common/PullVine.inc.c"

#include "../common/MoveBush.inc.c"
#include "../common/MoveBushTemplates.h"

EvtScript N(EVS_MoveBushes_Separate) = EVT_MOVE_BUSHES(COLLIDER_o12,
    MODEL_o40, MODEL_o54, MV_BushOffsetL, MV_BushOffsetR);

EvtScript N(EVS_MoveBushes) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o12, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(MakeLerp, 0, 45, 30, EASING_CUBIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(MV_BushOffsetR, LVar0)
        EVT_SETF(MV_BushOffsetL, MV_BushOffsetR)
        EVT_MULF(MV_BushOffsetR, EVT_FLOAT(1.5))
        EVT_MULF(MV_BushOffsetL, -1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnPullVine) = {
    EVT_SWITCH(LVarC)
        EVT_CASE_EQ(VINE_IDX_1)
            EVT_EXEC(N(EVS_MoveBushes_Separate))
            EVT_EXEC(N(EVS_MoveBushes))
        EVT_CASE_EQ(VINE_IDX_2)
            EVT_CALL(GetModelCenter, LVar9)
            EVT_ADD(LVar0, -20)
            EVT_ADD(LVar2, 15)
            EVT_CALL(SetNpcPos, NPC_JungleFuzzy_01, LVar0, 100, LVar2)
            EVT_CALL(SetNpcFlagBits, NPC_JungleFuzzy_01, NPC_FLAG_GRAVITY | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
        EVT_CASE_EQ(VINE_IDX_3)
            EVT_CALL(GetModelCenter, LVar9)
            EVT_ADD(LVar2, 15)
            EVT_CALL(MakeItemEntity, ITEM_FIRE_FLOWER, LVar0, 100, LVar2, ITEM_SPAWN_MODE_FALL, GF_JAN14_PullVine_FireFlower)
        EVT_CASE_EQ(VINE_IDX_4)
            EVT_CALL(GetModelCenter, LVar9)
            EVT_ADD(LVar0, -20)
            EVT_ADD(LVar2, 15)
            EVT_CALL(SetNpcPos, NPC_JungleFuzzy_02, LVar0, 100, LVar2)
            EVT_CALL(SetNpcFlagBits, NPC_JungleFuzzy_02, NPC_FLAG_GRAVITY | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
        EVT_CASE_EQ(VINE_IDX_5)
            EVT_CALL(GetModelCenter, LVar9)
            EVT_ADD(LVar2, 15)
            EVT_CALL(MakeItemEntity, ITEM_MUSHROOM, LVar0, 100, LVar2, ITEM_SPAWN_MODE_FALL, GF_JAN14_PullVine_Mushroom)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupVines) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o10, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o78, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o79, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o76, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o80, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_NE(LVar0, jan_14_ENTRY_1)
        EVT_SET(LVarC, VINE_IDX_1)
    EVT_ELSE
        EVT_SET(LVarC, VINE_IDX_0)
        EVT_EXEC(N(EVS_MoveBushes_Separate))
        EVT_EXEC(N(EVS_MoveBushes))
    EVT_END_IF
    EVT_SET(LVarF, MODEL_o28)
    EVT_SET(MV_PullVineCallback, EVT_PTR(N(EVS_OnPullVine)))
    EVT_SET(LVarD, MODEL_o8)
    EVT_SET(LVarE, MODEL_o9)
    EVT_SET(LVar9, MODEL_o57)
    EVT_SET(LVarA, MODEL_o58)
    EVT_SET(LVarB, MODEL_o59)
    EVT_SET(LVar5, 0)
    EVT_EXEC(N(EVS_PullVine_Manage))
    EVT_SET(LVarC, VINE_IDX_2)
    EVT_SET(LVarD, MODEL_o78)
    EVT_SET(LVarE, MODEL_o79)
    EVT_SET(LVar9, MODEL_o61)
    EVT_SET(LVarA, MODEL_o62)
    EVT_SET(LVarB, MODEL_o63)
    EVT_SET(LVar5, 15)
    EVT_EXEC(N(EVS_PullVine_Manage))
    EVT_SET(LVarC, VINE_IDX_3)
    EVT_SET(LVarD, MODEL_o77)
    EVT_SET(LVarE, MODEL_o76)
    EVT_SET(LVar9, MODEL_o65)
    EVT_SET(LVarA, MODEL_o67)
    EVT_SET(LVarB, MODEL_o2)
    EVT_SET(LVar5, 15)
    EVT_EXEC(N(EVS_PullVine_Manage))
    EVT_SET(LVarC, VINE_IDX_4)
    EVT_SET(LVarD, MODEL_o81)
    EVT_SET(LVarE, MODEL_o80)
    EVT_SET(LVar9, MODEL_o69)
    EVT_SET(LVarA, MODEL_o70)
    EVT_SET(LVarB, MODEL_o71)
    EVT_SET(LVar5, 15)
    EVT_EXEC(N(EVS_PullVine_Manage))
    EVT_SET(LVarC, VINE_IDX_5)
    EVT_SET(LVarD, MODEL_o82)
    EVT_SET(LVarE, MODEL_o83)
    EVT_SET(LVar9, MODEL_o75)
    EVT_SET(LVarA, MODEL_o73)
    EVT_SET(LVarB, MODEL_o2)
    EVT_SET(LVar5, 15)
    EVT_EXEC(N(EVS_PullVine_Manage))
    EVT_RETURN
    EVT_END
};
