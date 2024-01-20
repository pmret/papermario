#include "common.h"

// Used for clouds moving back and forth in stage backgrounds
// They turn around upon reaching the edge of the stage
// The position at any give time is represented by an angle, with one full
// cycle corresponding to a cycle of the cloud's motion around the stage.

// determines angle of 'patrolling' cloud based on position
API_CALLABLE(N(InterpCloudTransform)) {
    Bytecode* args = script->ptrReadPos;
    f32 interpAngleDeg = evt_get_variable(script, *args++) / 10.0;
    s32 outVarX = *args++;
    s32 outVarY = *args++;
    s32 outVarZ = *args++;
    s32 outVarAngle = *args++;
    f32 interpAngleRad = DEG_TO_RAD(interpAngleDeg);
    f32 posX = sin_rad(interpAngleRad) * 150.0f + 0.0f;
    f32 posY = sin_rad(interpAngleRad * 8.0f) * 10.0f + 0.0f;
    f32 posZ = cos_rad(interpAngleRad) * 150.0f / 20.0f + -50.0f;
    s32 outAngle;

    evt_set_float_variable(script, outVarX, posX);
    evt_set_float_variable(script, outVarY, posY);
    evt_set_float_variable(script, outVarZ, posZ);

    outAngle = 0;
    if (interpAngleDeg > 90.0f && interpAngleDeg < 270.0f) {
        outAngle = 180;
    }
    if ((s32)fabsf(90.0f - interpAngleDeg) < 45) {
        outAngle = 2.0f * (interpAngleDeg - 45.0f);
    }
    if ((s32)fabsf(270.0f - interpAngleDeg) < 45) {
        outAngle = 2.0f * (interpAngleDeg - 225.0f) + 180.0f;
    }
    evt_set_variable(script, outVarAngle, outAngle);

    return ApiStatus_DONE2;
}

// (in) LVar0 : modelID
// (in) LVar2 : motion phase offset
EvtScript N(EVS_AnimateCloud) = {
    Set(LVarA, LVar0)
    Set(LVar7, LVar2)
    Mul(LVar7, 10)
    Label(0)
        Add(LVar7, 4)
        IfGt(LVar7, 3599)
            Sub(LVar7, 3600)
        EndIf
        Call(N(InterpCloudTransform), LVar7, LVar0, LVar1, LVar2, LVar3)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Call(RotateModel, LVarA, LVar3, 0, 1, 0)
        Wait(1)
        Goto(0)
    Return
    End
};

// (in) LVar0 : modelID
// (in) LVar2 : motion phase offset
// (in) LVar3 : offsetY
// (in) LVar4 : offsetZ
EvtScript N(EVS_AnimateCloud_WithOffset2D) = {
    Set(LVarA, LVar0)
    Set(LVarB, LVar3)
    Set(LVarC, LVar4)
    Set(LVar7, LVar2)
    Mul(LVar7, 10)
    Label(0)
        Add(LVar7, 4)
        IfGt(LVar7, 3599)
            Sub(LVar7, 3600)
        EndIf
        Call(N(InterpCloudTransform), LVar7, LVar0, LVar1, LVar2, LVar3)
        AddF(LVar1, LVarB)
        AddF(LVar2, LVarC)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Call(RotateModel, LVarA, LVar3, 0, 1, 0)
        Wait(1)
        Goto(0)
    Return
    End
};

// (in) LVar0 : modelID
// (in) LVar2 : motion phase offset
// (in) LVar3 : offsetX
// (in) LVar4 : offsetY
// (in) LVar4 : offsetZ
EvtScript N(EVS_AnimateCloud_WithOffset3D) = {
    Set(LVarA, LVar0)
    Set(LVarB, LVar3)
    Set(LVarC, LVar4)
    Set(LVarD, LVar5)
    Set(LVar7, LVar2)
    Mul(LVar7, 10)
    Label(0)
        Add(LVar7, 4)
        IfGt(LVar7, 3599)
            Sub(LVar7, 3600)
        EndIf
        Call(N(InterpCloudTransform), LVar7, LVar0, LVar1, LVar2, LVar3)
        AddF(LVar0, LVarB)
        AddF(LVar1, LVarC)
        AddF(LVar2, LVarD)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Call(RotateModel, LVarA, LVar3, 0, 1, 0)
        Wait(1)
        Goto(0)
    Return
    End
};
