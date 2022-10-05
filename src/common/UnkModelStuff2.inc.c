#include "common.h"

ApiStatus N(UnkFloatFunc005)(Evt* script, s32 isInitialCall) {
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
    s32 temp_s1;

    script->functionTemp[0] = temp_s1 = evt_get_variable(script, *args++);

    switch (temp_s1) {
        case 0:
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
            script->functionTemp[0] = 1;
            break;
        case 3:
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
            script->functionTemp[0] = 1;
            break;
        case 1:
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
        case 2:
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

EvtScript N(script1) = {
    EVT_SET(LVarA, LVar0)
    EVT_LABEL(0)
    EVT_CALL(N(UnkFloatFunc005), 0)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
    EVT_WAIT(1)
    EVT_LOOP(0)
        EVT_CALL(N(UnkFloatFunc005), 1)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVarB, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -7, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -27, 0, 0, 1)
    EVT_WAIT(2)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -5, 0, 0, 1)
    EVT_WAIT(3)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
    EVT_WAIT(5)
    EVT_LOOP(0)
        EVT_CALL(N(UnkFloatFunc005), 2)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVarB, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(RandInt, 80, LVarB)
    EVT_ADD(LVarB, 30)
    EVT_LOOP(LVarB)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(RandInt, 5, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(N(UnkFloatFunc005), 3)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
    EVT_WAIT(1)
    EVT_LOOP(0)
        EVT_CALL(N(UnkFloatFunc005), 1)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVarB, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -7, 0, 0, 1)
    EVT_WAIT(5)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -27, 0, 0, 1)
    EVT_WAIT(2)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -5, 0, 0, 1)
    EVT_WAIT(3)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
    EVT_WAIT(5)
    EVT_LOOP(0)
        EVT_CALL(N(UnkFloatFunc005), 2)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVarB, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(RandInt, 80, LVarB)
    EVT_ADD(LVarB, 30)
    EVT_LOOP(LVarB)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_CALL(RotateModel, LVarA, -20, 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(script2) = {
    EVT_SET(LVarA, LVar0)
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, LVarA, 1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 1, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 3, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 2, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 2, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 1, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, -1, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, -1, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, -1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, -1, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8021CD64)[] = {
     0, -1, -1, -2, -2, -3, -5, -8,
    -8, -7, -6, -4, -2, -1,  0,  255,
};

EvtScript N(script3) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVar5, 5)
    EVT_USE_BUF(EVT_PTR(N(intTable_8021CD64)))
    EVT_LABEL(0)
    EVT_BUF_READ1(LVar1)
    EVT_IF_EQ(LVar1, 255)
        EVT_USE_BUF(EVT_PTR(N(intTable_8021CD64)))
        EVT_BUF_READ1(LVar1)
    EVT_END_IF
    EVT_SET(LVar0, LVar5)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, 0)
    EVT_WAIT(1)
    EVT_ADD(LVar5, 1)
    EVT_SET(LVarC, LVarB)
    EVT_SUB(LVarC, 20)
    EVT_IF_GT(LVar5, LVarC)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_SET(LVar0, LVar5)
    EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, 0)
    EVT_WAIT(1)
    EVT_ADD(LVar5, 1)
    EVT_SET(LVarC, LVarB)
    EVT_SUB(LVarC, 20)
    EVT_IF_GT(LVar5, LVarC)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_GOTO(0)
    EVT_LABEL(1)
    EVT_SET(LVar2, 0)
    EVT_LOOP(20)
        EVT_ADD(LVar5, 1)
        EVT_SUB(LVar1, 2)
        EVT_SET(LVar0, LVar5)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SUB(LVar5, 280)
    EVT_SET(LVar1, 0)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(script4) = {
    EVT_SET(LVarA, LVar0)
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -3, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -2, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, -1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 1, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
