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
    SetGroup(EVT_GROUP_EF)
    Call(ParentColliderToModel, LVarB, LVarA)
    SetF(LVar0, Float(0.0))
    SetF(LVarD, Float(-90.0))
    SubF(LVarD, LVarC)
    Label(0)
        SetF(LVar1, LVarC)
        Label(1)
            Call(N(PausePlatformsDuringPound))
            AddF(LVar0, Float(1.5))
            AddF(LVar1, Float(1.5))
            Call(TranslateModel, LVarA, 0, LVar0, 0)
            Call(UpdateColliderTransform, LVarB)
            Wait(1)
            IfLt(LVar1, Float(310.0))
                Goto(1)
            EndIf
        Call(TranslateModel, LVarA, 0, LVarD, 0)
        SetF(LVar0, LVarD)
        SetF(LVarC, Float(-90.0))
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_CreatePlatform1) = {
    Set(LVarA, MODEL_o32)
    Set(LVarB, COLLIDER_o32)
    Set(LVarC, 110)
    ExecWait(N(EVS_UpdatePlatform))
    Return
    End
};

EvtScript N(EVS_CreatePlatform2) = {
    Set(LVarA, MODEL_o31)
    Set(LVarB, COLLIDER_o31)
    Set(LVarC, 10)
    ExecWait(N(EVS_UpdatePlatform))
    Return
    End
};

EvtScript N(EVS_CreatePlatform3) = {
    Set(LVarA, MODEL_o33)
    Set(LVarB, COLLIDER_o33)
    Set(LVarC, -90)
    ExecWait(N(EVS_UpdatePlatform))
    Return
    End
};

EvtScript N(EVS_CreatePlatform4) = {
    Set(LVarA, MODEL_o34)
    Set(LVarB, COLLIDER_o34)
    Set(LVarC, -190)
    ExecWait(N(EVS_UpdatePlatform))
    Return
    End
};

EvtScript N(EVS_SetupPlatforms) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o48, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_CreatePlatform1))
    Exec(N(EVS_CreatePlatform2))
    Exec(N(EVS_CreatePlatform3))
    Exec(N(EVS_CreatePlatform4))
    Return
    End
};
