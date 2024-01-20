#include "common.h"

enum {
    FISH_STATE_INIT     = 0,
    FISH_STATE_1        = 1,
    FISH_STATE_2        = 2,
    FISH_STATE_3        = 3,
};

API_CALLABLE(N(UpdateAnimatedFish)) {
    Bytecode* args = script->ptrReadPos;
    #ifdef AVOID_UB
    f32 vt0 = 0.0f;
    f32 vt1 = 0.0f;
    f32 vt2 = 0.0f;
    #else
    f32 vt0;
    f32 vt1;
    f32 vt2;
    #endif
    f32 vt3;
    f32 vt4;
    f32 vt5;
    f32 vt6;
    f32 vt7;

    f64 temp_f20;
    f64 temp_f20_2;
    f64 temp_f20_3;
    f64 temp_f20_4;
    s32 state;

    script->functionTemp[0] = state = evt_get_variable(script, *args++);

    switch (state) {
        case FISH_STATE_INIT:
            vt0 = 142.0f;
            vt1 = 0.0f;
            vt2 = -118.0f;
            script->varTable[3] = 142;
            script->varTable[4] = 0;
            script->varTable[5] = -118;
            script->varTable[6] = 44;
            script->varTable[7] = -118;
            script->varTable[8] = 3;
            script->varTable[9] = 0;
            script->varTable[11] = 0;
            script->functionTemp[0] = FISH_STATE_1;
            break;
        case FISH_STATE_3:
            vt0 = 91.0f;
            vt1 = 0.0f;
            vt2 = -118.0f;
            script->varTable[3] = 91;
            script->varTable[4] = 0;
            script->varTable[5] = -118;
            script->varTable[6] = 91;
            script->varTable[7] = -118;
            script->varTable[8] = 3;
            script->varTable[9] = 0;
            script->varTable[11] = 0;
            script->functionTemp[0] = FISH_STATE_1;
            break;
        case FISH_STATE_1:
            script->varTable[9] += script->varTable[8];
            if (script->varTable[9] > 45) {
                script->varTable[9] = 45;
            }
            vt0 = script->varTable[3];
            vt1 = script->varTable[4];
            vt2 = script->varTable[5];
            vt3 = script->varTable[6];
            vt4 = script->varTable[7];
            temp_f20 = vt0 * (1.0 - sin_rad(DEG_TO_RAD(script->varTable[9])));
            vt0 = (temp_f20 + (vt3 * sin_rad(DEG_TO_RAD(script->varTable[9]))));
            vt1 = vt1 + sin_rad(DEG_TO_RAD(script->varTable[9] * 2)) * 90.0f;
            temp_f20_2 = vt2 * (1.0 - sin_rad(DEG_TO_RAD(script->varTable[9])));
            vt2 = temp_f20_2 + (vt4 * sin_rad(DEG_TO_RAD(script->varTable[9])));
            if (script->varTable[9] == 45) {
                script->varTable[11] = 1;
            }
            break;
        case FISH_STATE_2:
            script->varTable[9] += script->varTable[8];
            if (script->varTable[9] > 90) {
                script->varTable[9] = 90;
            }
            vt0 = script->varTable[3];
            vt1 = script->varTable[4];
            vt2 = script->varTable[5];
            vt3 = script->varTable[6];
            vt4 = script->varTable[7];
            temp_f20_3 = vt0 * (1.0 - sin_rad(DEG_TO_RAD(script->varTable[9])));
            vt0 = (temp_f20_3 + (vt3 * sin_rad(DEG_TO_RAD(script->varTable[9]))));
            vt1 = vt1 + sin_rad(DEG_TO_RAD(script->varTable[9] * 2)) * 90.0f;
            temp_f20_4 = vt2 * (1.0 - sin_rad(DEG_TO_RAD(script->varTable[9])));
            vt2 = temp_f20_4 + (vt4 * sin_rad(DEG_TO_RAD(script->varTable[9])));
            if (script->varTable[9] == 90) {
                script->varTable[11] = 2;
            }
            break;
    }
    script->varTable[0] = vt0;
    script->varTable[1] = vt1;
    script->varTable[2] = vt2;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimateFishModel) = {
    Set(LVarA, LVar0)
    Label(0)
        Call(N(UpdateAnimatedFish), FISH_STATE_INIT)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Call(RotateModel, LVarA, -20, 0, 0, 1)
        Wait(1)
        Loop(0)
            Call(N(UpdateAnimatedFish), FISH_STATE_1)
            Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
            Call(RotateModel, LVarA, -20, 0, 0, 1)
            Wait(1)
            IfEq(LVarB, 1)
                BreakLoop
            EndIf
        EndLoop
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Call(RotateModel, LVarA, -7, 0, 0, 1)
        Wait(5)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Call(RotateModel, LVarA, -27, 0, 0, 1)
        Wait(2)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Call(RotateModel, LVarA, -5, 0, 0, 1)
        Wait(3)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Call(RotateModel, LVarA, -20, 0, 0, 1)
        Wait(5)
        Loop(0)
            Call(N(UpdateAnimatedFish), FISH_STATE_2)
            Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
            Call(RotateModel, LVarA, -20, 0, 0, 1)
            Wait(1)
            IfEq(LVarB, 2)
                BreakLoop
            EndIf
        EndLoop
        Call(RandInt, 80, LVarB)
        Add(LVarB, 30)
        Loop(LVarB)
            Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
            Call(RotateModel, LVarA, -20, 0, 0, 1)
            Wait(1)
        EndLoop
        Call(RandInt, 5, LVar0)
        IfNe(LVar0, 0)
            Goto(0)
        EndIf
        Call(N(UpdateAnimatedFish), FISH_STATE_3)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Call(RotateModel, LVarA, -20, 0, 0, 1)
        Wait(1)
        Loop(0)
            Call(N(UpdateAnimatedFish), FISH_STATE_1)
            Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
            Call(RotateModel, LVarA, -20, 0, 0, 1)
            Wait(1)
            IfEq(LVarB, 1)
                BreakLoop
            EndIf
        EndLoop
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Call(RotateModel, LVarA, -7, 0, 0, 1)
        Wait(5)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Call(RotateModel, LVarA, -27, 0, 0, 1)
        Wait(2)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Call(RotateModel, LVarA, -5, 0, 0, 1)
        Wait(3)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        Call(RotateModel, LVarA, -20, 0, 0, 1)
        Wait(5)
        Loop(0)
            Call(N(UpdateAnimatedFish), FISH_STATE_2)
            Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
            Call(RotateModel, LVarA, -20, 0, 0, 1)
            Wait(1)
            IfEq(LVarB, 2)
                BreakLoop
            EndIf
        EndLoop
        Call(RandInt, 80, LVarB)
        Add(LVarB, 30)
        Loop(LVarB)
            Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
            Call(RotateModel, LVarA, -20, 0, 0, 1)
            Wait(1)
        EndLoop
        Goto(0)
    Return
    End
};

EvtScript N(EVS_AnimateWaveModel) = {
    Set(LVarA, LVar0)
    Loop(0)
        Call(TranslateModel, LVarA, 1, 0, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 1, 0, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 1, -1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 2, -1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 2, -1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 2, -1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 3, -2, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 3, -2, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 3, -3, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 3, -3, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 3, -3, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 3, -2, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 2, -2, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 2, -1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 1, 0, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 1, 1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, 1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, -1, 1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, -1, 1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, -1, 0, 0)
        Wait(2)
        Call(TranslateModel, LVarA, -1, 0, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, 0, 0)
        Wait(2)
    EndLoop
    Return
    End
};

s32 N(DriftBobbingOffsets)[] = {
     0, -1, -1, -2, -2, -3, -5, -8,
    -8, -7, -6, -4, -2, -1,  0,  255,
};

EvtScript N(EVS_AnimateDrifting) = {
    Set(LVarA, LVar0) // modelID
    Set(LVarB, LVar1)
    Set(LVar5, 5)
    UseBuf(Ref(N(DriftBobbingOffsets)))
    Label(0)
        // drift along from left to right
        BufRead1(LVar1)
        IfEq(LVar1, 255)
            UseBuf(Ref(N(DriftBobbingOffsets)))
            BufRead1(LVar1)
        EndIf
        Set(LVar0, LVar5)
        Call(TranslateModel, LVarA, LVar0, LVar1, 0)
        Wait(1)
        Add(LVar5, 1)
        Set(LVarC, LVarB)
        Sub(LVarC, 20)
        IfGt(LVar5, LVarC)
            Goto(1)
        EndIf
        Set(LVar0, LVar5)
        Call(TranslateModel, LVarA, LVar0, LVar1, 0)
        Wait(1)
        Add(LVar5, 1)
        Set(LVarC, LVarB)
        Sub(LVarC, 20)
        IfGt(LVar5, LVarC)
            Goto(1)
        EndIf
        Goto(0)
    Label(1)
        // fall down
        Set(LVar2, 0)
        Loop(20)
            Add(LVar5, 1)
            Sub(LVar1, 2)
            Set(LVar0, LVar5)
            Call(TranslateModel, LVarA, LVar0, LVar1, 0)
            Wait(1)
        EndLoop
        // reset to left side of stage
        Sub(LVar5, 280)
        Set(LVar1, 0)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_AnimateFlotsam) = {
    Set(LVarA, LVar0)
    Loop(0)
        Call(TranslateModel, LVarA, 0, 0, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, 0, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, -1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, -1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, -1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, -1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, -2, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, -2, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, -3, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, -3, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, -3, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, -2, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, -2, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, -1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, 0, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, 1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, 1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, 1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, 1, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, 0, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, 0, 0)
        Wait(2)
        Call(TranslateModel, LVarA, 0, 0, 0)
        Wait(2)
    EndLoop
    Return
    End
};
