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
    SetGroup(EVT_GROUP_EF)
    Call(ParentColliderToModel, LVarB, LVarA)
    SetF(LVar0, Float(0.0))
    SetF(LVarD, Float(-300.0))
    SubF(LVarD, LVarC)
    Label(0)
        SetF(LVar1, LVarC)
        SubF(LVar0, Float(80.0))
        Label(1)
            Call(N(PausePlatformsDuringPound))
            AddF(LVar0, Float(1.5))
            AddF(LVar1, Float(1.5))
            Call(TranslateModel, LVarA, 0, LVar0, 0)
            Call(UpdateColliderTransform, LVarB)
            Wait(1)
            IfLt(LVar1, Float(100.0))
                Goto(1)
            EndIf
        Call(TranslateModel, LVarA, 0, LVarD, 0)
        SetF(LVar0, LVarD)
        SetF(LVarC, Float(-300.0))
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_CreatePlatform1) = {
    Set(LVarA, MODEL_erb)
    Set(LVarB, COLLIDER_1)
    Set(LVarC, 20)
    ExecWait(N(EVS_UpdatePlatform))
    Return
    End
};

EvtScript N(EVS_CreatePlatform2) = {
    Set(LVarA, MODEL_o40)
    Set(LVarB, COLLIDER_3)
    Set(LVarC, -80)
    ExecWait(N(EVS_UpdatePlatform))
    Return
    End
};

EvtScript N(EVS_CreatePlatform3) = {
    Set(LVarA, MODEL_o41)
    Set(LVarB, COLLIDER_4)
    Set(LVarC, -170)
    ExecWait(N(EVS_UpdatePlatform))
    Return
    End
};

EvtScript N(EVS_CreatePlatform4) = {
    Set(LVarA, MODEL_o39)
    Set(LVarB, COLLIDER_2)
    Set(LVarC, -270)
    ExecWait(N(EVS_UpdatePlatform))
    Return
    End
};

EvtScript N(EVS_SetupPlatforms) = {
    Exec(N(EVS_CreatePlatform1))
    Exec(N(EVS_CreatePlatform2))
    Exec(N(EVS_CreatePlatform3))
    Exec(N(EVS_CreatePlatform4))
    Return
    End
};
