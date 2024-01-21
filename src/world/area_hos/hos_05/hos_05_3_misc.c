#include "hos_05.h"

#include "world/common/atomic/ApplyTint.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(AwaitScriptComplete)) {
    Bytecode* args = script->ptrReadPos;
    s32 waitingScriptID = evt_get_variable(script, *args++);

    if (!does_script_exist(waitingScriptID)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(CastToLocalFloat)) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    script->varTable[idx] = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240690_A2A8D0)) {
    f32 vt2 = script->varTable[2];
    f32 magnitude;
    f32 angle;

    script->varTable[2] = Float(0.0);
    script->varTable[3] = Float(100.0);
    script->varTable[4] = Float(0.0);

    angle = (script->varTable[1] * 180.0f) / PI;
    magnitude = (rand_int(10) / vt2) + 3.0f;

    script->varTable[10] = Float_TO_FIXED(magnitude * cos_rad(angle));
    script->varTable[11] = Float_TO_FIXED(rand_int(15) + 5);
    script->varTable[12] = Float_TO_FIXED(magnitude * sin_rad(angle));
    script->varTable[13] = Float_TO_FIXED((f32)(rand_int(10) + 10) * -0.05);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupStarshipAndWater) = {
    Exec(N(EVS_SetupStarship))
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  100,  -80,  -50,  120)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o33, TEX_PANNER_1)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_C)
        TEX_PAN_PARAMS_STEP(  -80,  140,   80, -100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o34, TEX_PANNER_C)
    Return
    End
};

EvtScript N(D_80246028_A30268) = {
    Call(N(func_80240690_A2A8D0))
    Label(0)
        AddF(LVarB, LVarD)
        AddF(LVar2, LVarA)
        AddF(LVar3, LVarB)
        AddF(LVar4, LVarC)
        Call(TranslateModel, LVar0, LVar2, LVar3, LVar4)
        Call(N(CastToLocalFloat), 6, LVar2)
        Mul(LVar6, LVar6)
        Call(N(CastToLocalFloat), 7, LVar4)
        Mul(LVar7, LVar7)
        Add(LVar6, LVar7)
        IfLt(LVar6, 10000)
            Call(N(CastToLocalFloat), 5, LVar3)
            IfLt(LVar5, 136)
                Call(N(CastToLocalFloat), 5, LVarB)
                IfLt(LVar5, 0)
                    MulF(LVarB, Float(-1.0))
                EndIf
            EndIf
        EndIf
        Call(N(CastToLocalFloat), 5, LVar2)
        Call(N(CastToLocalFloat), 6, LVar3)
        Call(N(CastToLocalFloat), 7, LVar4)
        IfLt(LVar6, 0)
            Return
        EndIf
        IfGt(LVar6, 300)
            Return
        EndIf
        IfLt(LVar5, -300)
            Return
        EndIf
        IfGt(LVar5, 300)
            Return
        EndIf
        IfLt(LVar7, -300)
            Return
        EndIf
        IfGt(LVar7, 600)
            Return
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(D_80246298_A304D8) = {
    Set(LVarF, LVar2)
    Call(GetPlayerPos, LVar2, LVar3, LVar4)
    Call(RandInt, 40, LVar2)
    AddF(LVar2, Float(-20.0))
    AddF(LVar3, Float(-5.0))
    Call(RandInt, 40, LVar4)
    AddF(LVar4, Float(-20.0))
    Call(RandInt, 30, LVar5)
    AddF(LVar5, Float(30.0))
    MulF(LVar5, Float(0.01))
    Label(0)
        AddF(LVar2, 0)
        AddF(LVar3, 0)
        AddF(LVar4, 0)
        MulF(LVar5, Float(0.9))
        Call(TranslateModel, LVar0, LVar2, LVar3, LVar4)
        Call(ScaleModel, LVar0, LVar5, LVar5, LVar5)
        SetF(LVar6, LVar5)
        MulF(LVar6, Float(10.0))
        Call(N(CastToLocalFloat), 6, LVar6)
        IfLt(LVar6, 2)
            Return
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_8024644C) = {
    Set(LVar0, LVar3)
    Set(LVar2, 5)
    Loop(LVar2)
        Call(RandInt, 360, LVar1)
        ExecGetTID(N(D_80246028_A30268), LVar3)
        IfNe(LVar3, 0)
            Call(N(AwaitScriptComplete), LVar3)
        EndIf
    EndLoop
    Label(0)
        Call(RandInt, 360, LVar1)
        ExecGetTID(N(D_80246298_A304D8), LVar3)
        IfNe(LVar3, 0)
            Call(N(AwaitScriptComplete), LVar3)
        EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_80246540) = {
    Set(LVar0, LVar3)
    Label(0)
        Call(RandInt, 360, LVar1)
        ExecGetTID(N(D_80246298_A304D8), LVar3)
        IfNe(LVar3, 0)
            Call(N(AwaitScriptComplete), LVar3)
        EndIf
        Goto(0)
    Return
    End
};
