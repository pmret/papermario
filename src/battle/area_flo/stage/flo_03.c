#include "common.h"
#include "battle/battle.h"
#include "mapfs/flo_bt03_shape.h"

#define NAMESPACE b_area_flo_flo_03

EvtScript N(80232A30) = {
    EVT_SET(LVarA, LVar0)
    EVT_USE_BUF(LVarA)
    EVT_LOOP(0)
        EVT_BUF_READ1(LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetTexPanner, LVar0, 14)
        EVT_BUF_READ1(LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetTexPanner, LVar0, 15)
    EVT_END_LOOP
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LABEL(0)
    EVT_LABEL(0)
    EVT_ADD(LVar0, -140)
    EVT_IF_LT(LVar0, 0)
        EVT_ADD(LVar0, 65536)
    EVT_END_IF
    EVT_CALL(SetTexPanOffset, 14, 0, LVar0, 0)
    EVT_ADD(LVar1, -200)
    EVT_IF_LT(LVar1, 0)
        EVT_ADD(LVar1, 65536)
    EVT_END_IF
    EVT_CALL(SetTexPanOffset, 15, 0, LVar1, 0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

#include "common/MakeSun.inc.c"

#include "common/CosInterpMinMax.inc.c"

EvtScript N(80232C48) = {
    EVT_CALL(EnableModel, LVarF, 1)
    EVT_SET(LVarE, 159)
    EVT_LOOP(LVarE)
        EVT_ADDF(LVar3, 0)
        EVT_ADDF(LVar4, EVT_FLOAT(0.0))
        EVT_SETF(LVar5, EVT_FLOAT(0.01))
        EVT_ADDF(LVar0, LVar3)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_MULF(LVar6, EVT_FLOAT(1.01))
        EVT_ADDF(LVar7, EVT_FLOAT(0.01))
        EVT_SETF(LVar8, LVar6)
        EVT_CALL(N(CosInterpMinMax), LVarE, LVarA, EVT_FLOAT(0.0), EVT_FLOAT(0.203125), 15, 0, 0)
        EVT_ADDF(LVar8, LVarA)
        EVT_SETF(LVar9, LVar7)
        EVT_CALL(N(CosInterpMinMax), LVarE, LVarA, EVT_FLOAT(0.0), EVT_FLOAT(0.203125), 20, 0, 90)
        EVT_ADDF(LVar9, LVarA)
        EVT_SETF(LVarA, LVar0)
        EVT_MULF(LVarA, EVT_FLOAT(10.0))
        EVT_CALL(TranslateModel, LVarF, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, LVarF, LVar8, LVar9, 1)
        EVT_CALL(RotateModel, LVarF, LVarA, 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, LVarF, 0)
    EVT_RETURN
    EVT_END
};

s32 N(modelList)[] = {
    MODEL_o419, MODEL_o420, MODEL_o422, 0,
};

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_SET(LVar0, N(modelList))
    EVT_EXEC(N(80232A30))
    EVT_CALL(SetTexPanner, 36, 1)
    EVT_CALL(SetTexPanner, 37, 2)
    EVT_CALL(SetTexPanner, 38, 3)
    EVT_CALL(SetTexPanner, 39, 4)
    EVT_CALL(SetTexPanner, 40, 5)
    EVT_CALL(SetTexPanner, 41, 6)
    EVT_CALL(SetTexPanner, 42, 7)
    EVT_THREAD
        EVT_SET(LVarE, 1)
        EVT_SET(LVarF, 0)
        EVT_LOOP(0)
            EVT_ADDF(LVarF, LVarE)
            EVT_IF_GE(LVarF, 1080)
                EVT_SET(LVarF, 0)
            EVT_END_IF
            EVT_SET(LVar0, LVarF)
            EVT_DIV(LVar0, 9)
            EVT_MOD(LVar0, 2)
            EVT_MUL(LVar0, 16384)
            EVT_SET(LVar1, LVarF)
            EVT_DIV(LVar1, 4)
            EVT_MOD(LVar1, 2)
            EVT_MUL(LVar1, 16384)
            EVT_SET(LVar2, LVarF)
            EVT_DIV(LVar2, 5)
            EVT_MOD(LVar2, 2)
            EVT_MUL(LVar2, 16384)
            EVT_SET(LVar3, LVarF)
            EVT_DIV(LVar3, 6)
            EVT_MOD(LVar3, 2)
            EVT_MUL(LVar3, 16384)
            EVT_SET(LVar4, LVarF)
            EVT_DIV(LVar4, 2)
            EVT_MOD(LVar4, 2)
            EVT_MUL(LVar4, 16384)
            EVT_SET(LVar5, LVarF)
            EVT_DIV(LVar5, 8)
            EVT_MOD(LVar5, 2)
            EVT_MUL(LVar5, 16384)
            EVT_SET(LVar6, LVarF)
            EVT_DIV(LVar6, 8)
            EVT_MOD(LVar6, 2)
            EVT_MUL(LVar6, 32768)
            EVT_CALL(SetTexPanOffset, 1, 0, LVar0, 0)
            EVT_CALL(SetTexPanOffset, 2, 0, LVar1, 0)
            EVT_CALL(SetTexPanOffset, 3, 0, LVar2, 0)
            EVT_CALL(SetTexPanOffset, 4, 0, LVar3, 0)
            EVT_CALL(SetTexPanOffset, 5, 0, LVar4, 0)
            EVT_CALL(SetTexPanOffset, 6, 0, LVar5, 0)
            EVT_CALL(SetTexPanOffset, 7, 0, LVar6, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(16)
            EVT_SET(LVar1, LVar0)
            EVT_ADD(LVar1, 10000)
            EVT_ADD(LVar0, 1)
            EVT_CALL(CloneModel, 44, LVar1)
            EVT_CALL(EnableModel, LVar1, 0)
        EVT_END_LOOP
        EVT_CALL(EnableModel, 44, 0)
        EVT_SET(LVarE, 0)
        EVT_LOOP(0)
            EVT_SETF(LVar0, EVT_FLOAT(106.0))
            EVT_SETF(LVar1, EVT_FLOAT(94.0))
            EVT_SETF(LVar2, EVT_FLOAT(-91.0))
            EVT_CALL(RandInt, 100, LVar3)
            EVT_ADDF(LVar3, -50)
            EVT_DIVF(LVar3, EVT_FLOAT(200.0))
            EVT_SETF(LVar4, EVT_FLOAT(1.0))
            EVT_SETF(LVar5, 0)
            EVT_SETF(LVar6, EVT_FLOAT(0.296875))
            EVT_SETF(LVar7, EVT_FLOAT(0.296875))
            EVT_SET(LVarF, LVarE)
            EVT_ADD(LVarF, 10000)
            EVT_EXEC(N(80232C48))
            EVT_ADD(LVarE, 1)
            EVT_IF_GE(LVarE, 16)
                EVT_SET(LVarE, 0)
            EVT_END_IF
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_EXEC_WAIT(N(MakeSun))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    -1, MODEL_o411, MODEL_o415, 0,
};

Stage NAMESPACE = {
    .texture = "flo_tex",
    .shape = "flo_bt03_shape",
    .hit = "flo_bt03_hit",
    .bg = "fla_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
