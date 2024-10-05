#include "omo_09.h"

EvtScript N(EVS_Gizmos_Wheels) = {
    Label(0)
        Call(MakeLerp, 0, -360, 100, EASING_LINEAR)
        Label(1)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_ha1, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha2, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha3, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha4, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha5, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Gizmos_Shutters) = {
    Label(0)
    Label(0)
        Call(MakeLerp, 0, 160, 60, EASING_COS_IN_OUT)
        Label(1)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_m2_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m2_2, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_m3_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m3_2, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_m4_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m4_2, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
        Call(MakeLerp, 160, 0, 60, EASING_COS_IN_OUT)
        Label(2)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_m2_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m2_2, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_m3_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m3_2, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_m4_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m4_2, LVar0, 0, 1, 0)
            Wait(2)
            IfEq(LVar1, 1)
                Goto(2)
            EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Gizmos_Clocks) = {
    Label(0)
        Call(MakeLerp, 0, -360, 100, EASING_LINEAR)
        Label(1)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_hari1, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_hari2, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
        Goto(0)
    Return
    End
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
    SetGroup(EVT_GROUP_NOT_BATTLE)
    Call(N(AwaitPlayerNearPlatforms))
    Wait(LVar9)
    Call(ParentColliderToModel, LVar6, LVar7)
    Loop(0)
        Call(MakeLerp, 0, LVar8, LVar8, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateModel, LVar7, 0, LVar0, 0)
            Call(UpdateColliderTransform, LVar6)
            Call(N(AwaitPlayerNearPlatforms))
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Loop(30)
            Call(N(AwaitPlayerNearPlatforms))
            Wait(1)
        EndLoop
        Call(MakeLerp, LVar8, 0, LVar8, EASING_COS_IN_OUT)
        Loop(0)
            Call(UpdateLerp)
            Call(TranslateModel, LVar7, 0, LVar0, 0)
            Call(UpdateColliderTransform, LVar6)
            Call(N(AwaitPlayerNearPlatforms))
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Loop(30)
            Call(N(AwaitPlayerNearPlatforms))
            Wait(1)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_SetupGizmos) = {
    Exec(N(EVS_Gizmos_Wheels))
    Exec(N(EVS_Gizmos_Shutters))
    Exec(N(EVS_Gizmos_Clocks))
    UseBuf(Ref(N(MovingBlockPlatforms)))
    Loop(ARRAY_COUNT(N(MovingBlockPlatforms)))
        BufRead4(LVar6, LVar7, LVar8, LVar9)
        Exec(N(EVS_Gizmos_MovingBlocks))
    EndLoop
    Return
    End
};
