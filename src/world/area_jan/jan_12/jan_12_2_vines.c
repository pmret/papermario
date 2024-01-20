#include "jan_12.h"

#define PULL_VINE_CALLBACK_SCRIPT MV_PullVineCallback
#include "../common/PullVine.inc.c"

#include "../common/MoveBush.inc.c"
#include "../common/MoveBushTemplates.h"

EvtScript N(EVS_MoveBushes_Separate) = EVT_MOVE_BUSHES(COLLIDER_o12,
    MODEL_o12, MODEL_o26, MV_BushOffsetL, MV_BushOffsetR);

EvtScript N(EVS_Inspect_MoveBushes) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o12, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_MoveBushes_Separate))
    Call(DisablePlayerInput, TRUE)
    Call(MakeLerp, 0, 45, 30, EASING_CUBIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        SetF(MV_BushOffsetR, LVar0)
        SetF(MV_BushOffsetL, MV_BushOffsetR)
        MulF(MV_BushOffsetL, -1)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_OnPullVine) = {
    Call(GetModelCenter, LVar9)
    Add(LVar2, 10)
    Call(MakeItemEntity, ITEM_EGG, LVar0, 100, LVar2, ITEM_SPAWN_MODE_FALL, GF_JAN12_PullVine_Egg2)
    Return
    End
};

EvtScript N(EVS_SetupVines) = {
    BindTrigger(Ref(N(EVS_Inspect_MoveBushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o12, 1, 0)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, jan_12_ENTRY_1)
        Exec(N(EVS_Inspect_MoveBushes))
    EndIf
    Set(MV_PullVineCallback, Ref(N(EVS_OnPullVine)))
    Set(LVarF, MODEL_o47)
    Set(LVarC, 0)
    Set(LVarD, MODEL_o76)
    Set(LVarE, MODEL_o77)
    Set(LVar9, MODEL_o6)
    Set(LVarA, MODEL_o62)
    Set(LVarB, MODEL_o63)
    Set(LVar5, 15)
    Exec(N(EVS_PullVine_Manage))
    Return
    End
};
