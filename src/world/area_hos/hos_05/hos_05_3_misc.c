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

    script->varTable[2] = EVT_FLOAT(0.0);
    script->varTable[3] = EVT_FLOAT(100.0);
    script->varTable[4] = EVT_FLOAT(0.0);

    angle = (script->varTable[1] * 180.0f) / PI;
    magnitude = (rand_int(10) / vt2) + 3.0f;

    script->varTable[10] = EVT_FLOAT_TO_FIXED(magnitude * cos_rad(angle));
    script->varTable[11] = EVT_FLOAT_TO_FIXED(rand_int(15) + 5);
    script->varTable[12] = EVT_FLOAT_TO_FIXED(magnitude * sin_rad(angle));
    script->varTable[13] = EVT_FLOAT_TO_FIXED((f32)(rand_int(10) + 10) * -0.05);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_SetupStarshipAndWater) = {
    EVT_EXEC(N(EVS_SetupStarship))
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  100,  -80,  -50,  120)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_o33, TEX_PANNER_1)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_C)
        TEX_PAN_PARAMS_STEP(  -80,  140,   80, -100)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_o34, TEX_PANNER_C)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246028_A30268) = {
    EVT_CALL(N(func_80240690_A2A8D0))
    EVT_LABEL(0)
        EVT_ADDF(LVarB, LVarD)
        EVT_ADDF(LVar2, LVarA)
        EVT_ADDF(LVar3, LVarB)
        EVT_ADDF(LVar4, LVarC)
        EVT_CALL(TranslateModel, LVar0, LVar2, LVar3, LVar4)
        EVT_CALL(N(CastToLocalFloat), 6, LVar2)
        EVT_MUL(LVar6, LVar6)
        EVT_CALL(N(CastToLocalFloat), 7, LVar4)
        EVT_MUL(LVar7, LVar7)
        EVT_ADD(LVar6, LVar7)
        EVT_IF_LT(LVar6, 10000)
            EVT_CALL(N(CastToLocalFloat), 5, LVar3)
            EVT_IF_LT(LVar5, 136)
                EVT_CALL(N(CastToLocalFloat), 5, LVarB)
                EVT_IF_LT(LVar5, 0)
                    EVT_MULF(LVarB, EVT_FLOAT(-1.0))
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(N(CastToLocalFloat), 5, LVar2)
        EVT_CALL(N(CastToLocalFloat), 6, LVar3)
        EVT_CALL(N(CastToLocalFloat), 7, LVar4)
        EVT_IF_LT(LVar6, 0)
            EVT_RETURN
        EVT_END_IF
        EVT_IF_GT(LVar6, 300)
            EVT_RETURN
        EVT_END_IF
        EVT_IF_LT(LVar5, -300)
            EVT_RETURN
        EVT_END_IF
        EVT_IF_GT(LVar5, 300)
            EVT_RETURN
        EVT_END_IF
        EVT_IF_LT(LVar7, -300)
            EVT_RETURN
        EVT_END_IF
        EVT_IF_GT(LVar7, 600)
            EVT_RETURN
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246298_A304D8) = {
    EVT_SET(LVarF, LVar2)
    EVT_CALL(GetPlayerPos, LVar2, LVar3, LVar4)
    EVT_CALL(RandInt, 40, LVar2)
    EVT_ADDF(LVar2, EVT_FLOAT(-20.0))
    EVT_ADDF(LVar3, EVT_FLOAT(-5.0))
    EVT_CALL(RandInt, 40, LVar4)
    EVT_ADDF(LVar4, EVT_FLOAT(-20.0))
    EVT_CALL(RandInt, 30, LVar5)
    EVT_ADDF(LVar5, EVT_FLOAT(30.0))
    EVT_MULF(LVar5, EVT_FLOAT(0.01))
    EVT_LABEL(0)
        EVT_ADDF(LVar2, 0)
        EVT_ADDF(LVar3, 0)
        EVT_ADDF(LVar4, 0)
        EVT_MULF(LVar5, EVT_FLOAT(0.9))
        EVT_CALL(TranslateModel, LVar0, LVar2, LVar3, LVar4)
        EVT_CALL(ScaleModel, LVar0, LVar5, LVar5, LVar5)
        EVT_SETF(LVar6, LVar5)
        EVT_MULF(LVar6, EVT_FLOAT(10.0))
        EVT_CALL(N(CastToLocalFloat), 6, LVar6)
        EVT_IF_LT(LVar6, 2)
            EVT_RETURN
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024644C) = {
    EVT_SET(LVar0, LVar3)
    EVT_SET(LVar2, 5)
    EVT_LOOP(LVar2)
        EVT_CALL(RandInt, 360, LVar1)
        EVT_EXEC_GET_TID(N(D_80246028_A30268), LVar3)
        EVT_IF_NE(LVar3, 0)
            EVT_CALL(N(AwaitScriptComplete), LVar3)
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
        EVT_CALL(RandInt, 360, LVar1)
        EVT_EXEC_GET_TID(N(D_80246298_A304D8), LVar3)
        EVT_IF_NE(LVar3, 0)
            EVT_CALL(N(AwaitScriptComplete), LVar3)
        EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80246540) = {
    EVT_SET(LVar0, LVar3)
    EVT_LABEL(0)
        EVT_CALL(RandInt, 360, LVar1)
        EVT_EXEC_GET_TID(N(D_80246298_A304D8), LVar3)
        EVT_IF_NE(LVar3, 0)
            EVT_CALL(N(AwaitScriptComplete), LVar3)
        EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};
