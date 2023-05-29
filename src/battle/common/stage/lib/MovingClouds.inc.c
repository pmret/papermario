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
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVar7, LVar2)
    EVT_MUL(LVar7, 10)
    EVT_LABEL(0)
        EVT_ADD(LVar7, 4)
        EVT_IF_GT(LVar7, 3599)
            EVT_SUB(LVar7, 3600)
        EVT_END_IF
        EVT_CALL(N(InterpCloudTransform), LVar7, LVar0, LVar1, LVar2, LVar3)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, LVar3, 0, 1, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

// (in) LVar0 : modelID
// (in) LVar2 : motion phase offset
// (in) LVar3 : offsetY
// (in) LVar4 : offsetZ
EvtScript N(EVS_AnimateCloud_WithOffset2D) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar3)
    EVT_SET(LVarC, LVar4)
    EVT_SET(LVar7, LVar2)
    EVT_MUL(LVar7, 10)
    EVT_LABEL(0)
        EVT_ADD(LVar7, 4)
        EVT_IF_GT(LVar7, 3599)
            EVT_SUB(LVar7, 3600)
        EVT_END_IF
        EVT_CALL(N(InterpCloudTransform), LVar7, LVar0, LVar1, LVar2, LVar3)
        EVT_ADDF(LVar1, LVarB)
        EVT_ADDF(LVar2, LVarC)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, LVar3, 0, 1, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

// (in) LVar0 : modelID
// (in) LVar2 : motion phase offset
// (in) LVar3 : offsetX
// (in) LVar4 : offsetY
// (in) LVar4 : offsetZ
EvtScript N(EVS_AnimateCloud_WithOffset3D) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar3)
    EVT_SET(LVarC, LVar4)
    EVT_SET(LVarD, LVar5)
    EVT_SET(LVar7, LVar2)
    EVT_MUL(LVar7, 10)
    EVT_LABEL(0)
        EVT_ADD(LVar7, 4)
        EVT_IF_GT(LVar7, 3599)
            EVT_SUB(LVar7, 3600)
        EVT_END_IF
        EVT_CALL(N(InterpCloudTransform), LVar7, LVar0, LVar1, LVar2, LVar3)
        EVT_ADDF(LVar0, LVarB)
        EVT_ADDF(LVar1, LVarC)
        EVT_ADDF(LVar2, LVarD)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, LVar3, 0, 1, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};
