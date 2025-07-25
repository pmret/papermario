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
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o12, COLLIDER_FLAGS_UPPER_MASK)
    Call(MakeLerp, 0, 45, 30, EASING_CUBIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        SetF(MV_BushOffsetR, LVar0)
        SetF(MV_BushOffsetL, MV_BushOffsetR)
        MulF(MV_BushOffsetR, Float(1.5))
        MulF(MV_BushOffsetL, -1)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_OnPullVine) = {
    Switch(LVarC)
        CaseEq(VINE_IDX_1)
            Exec(N(EVS_MoveBushes_Separate))
            Exec(N(EVS_MoveBushes))
        CaseEq(VINE_IDX_2)
            Call(GetModelCenter, LVar9)
            Add(LVar0, -20)
            Add(LVar2, 15)
            Call(SetNpcPos, NPC_JungleFuzzy_01, LVar0, 100, LVar2)
            Call(SetNpcFlagBits, NPC_JungleFuzzy_01, NPC_FLAG_GRAVITY | NPC_FLAG_IGNORE_ENTITY_COLLISION, true)
        CaseEq(VINE_IDX_3)
            Call(GetModelCenter, LVar9)
            Add(LVar2, 15)
            Call(MakeItemEntity, ITEM_FIRE_FLOWER, LVar0, 100, LVar2, ITEM_SPAWN_MODE_FALL, GF_JAN14_PullVine_FireFlower)
        CaseEq(VINE_IDX_4)
            Call(GetModelCenter, LVar9)
            Add(LVar0, -20)
            Add(LVar2, 15)
            Call(SetNpcPos, NPC_JungleFuzzy_02, LVar0, 100, LVar2)
            Call(SetNpcFlagBits, NPC_JungleFuzzy_02, NPC_FLAG_GRAVITY | NPC_FLAG_IGNORE_ENTITY_COLLISION, true)
        CaseEq(VINE_IDX_5)
            Call(GetModelCenter, LVar9)
            Add(LVar2, 15)
            Call(MakeItemEntity, ITEM_MUSHROOM, LVar0, 100, LVar2, ITEM_SPAWN_MODE_FALL, GF_JAN14_PullVine_Mushroom)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SetupVines) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o10, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o78, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o79, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o76, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o80, COLLIDER_FLAGS_UPPER_MASK)
    Call(GetEntryID, LVar0)
    IfNe(LVar0, jan_14_ENTRY_1)
        Set(LVarC, VINE_IDX_1)
    Else
        Set(LVarC, VINE_IDX_0)
        Exec(N(EVS_MoveBushes_Separate))
        Exec(N(EVS_MoveBushes))
    EndIf
    Set(LVarF, MODEL_o28)
    Set(MV_PullVineCallback, Ref(N(EVS_OnPullVine)))
    Set(LVarD, MODEL_o8)
    Set(LVarE, MODEL_o9)
    Set(LVar9, MODEL_o57)
    Set(LVarA, MODEL_o58)
    Set(LVarB, MODEL_o59)
    Set(LVar5, 0)
    Exec(N(EVS_PullVine_Manage))
    Set(LVarC, VINE_IDX_2)
    Set(LVarD, MODEL_o78)
    Set(LVarE, MODEL_o79)
    Set(LVar9, MODEL_o61)
    Set(LVarA, MODEL_o62)
    Set(LVarB, MODEL_o63)
    Set(LVar5, 15)
    Exec(N(EVS_PullVine_Manage))
    Set(LVarC, VINE_IDX_3)
    Set(LVarD, MODEL_o77)
    Set(LVarE, MODEL_o76)
    Set(LVar9, MODEL_o65)
    Set(LVarA, MODEL_o67)
    Set(LVarB, MODEL_o2)
    Set(LVar5, 15)
    Exec(N(EVS_PullVine_Manage))
    Set(LVarC, VINE_IDX_4)
    Set(LVarD, MODEL_o81)
    Set(LVarE, MODEL_o80)
    Set(LVar9, MODEL_o69)
    Set(LVarA, MODEL_o70)
    Set(LVarB, MODEL_o71)
    Set(LVar5, 15)
    Exec(N(EVS_PullVine_Manage))
    Set(LVarC, VINE_IDX_5)
    Set(LVarD, MODEL_o82)
    Set(LVarE, MODEL_o83)
    Set(LVar9, MODEL_o75)
    Set(LVarA, MODEL_o73)
    Set(LVarB, MODEL_o2)
    Set(LVar5, 15)
    Exec(N(EVS_PullVine_Manage))
    Return
    End
};
