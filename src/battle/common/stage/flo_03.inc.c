#include "battle/battle.h"
#include "mapfs/flo_bt03_shape.h"

#define NAMESPACE A(flo_03)

EvtScript N(EVS_AnimateVines) = {
    EVT_SET(LVarA, LVar0)
    EVT_USE_BUF(LVarA)
    EVT_LOOP(0)
        EVT_BUF_READ1(LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetTexPanner, LVar0, TEX_PANNER_E)
        EVT_BUF_READ1(LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetTexPanner, LVar0, TEX_PANNER_F)
    EVT_END_LOOP
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LABEL(0)
    EVT_LABEL(0)
        EVT_ADD(LVar0, -140)
        EVT_IF_LT(LVar0, 0)
            EVT_ADD(LVar0, 0x10000)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, TEX_PANNER_E, TEX_PANNER_MAIN, LVar0, 0)
        EVT_ADD(LVar1, -200)
        EVT_IF_LT(LVar1, 0)
            EVT_ADD(LVar1, 0x10000)
        EVT_END_IF
        EVT_CALL(SetTexPanOffset, TEX_PANNER_F, TEX_PANNER_MAIN, LVar1, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

#include "common/MakeSun.inc.c"
#include "common/CosInterpMinMax.inc.c"

EvtScript N(EVS_AnimateSmokePuff) = {
    EVT_CALL(EnableModel, LVarF, TRUE)
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
        EVT_CALL(N(CosInterpMinMax), LVarE, LVarA, EVT_FLOAT(0.0), EVT_FLOAT(0.203), 15, 0, 0)
        EVT_ADDF(LVar8, LVarA)
        EVT_SETF(LVar9, LVar7)
        EVT_CALL(N(CosInterpMinMax), LVarE, LVarA, EVT_FLOAT(0.0), EVT_FLOAT(0.203), 20, 0, 90)
        EVT_ADDF(LVar9, LVarA)
        EVT_SETF(LVarA, LVar0)
        EVT_MULF(LVarA, EVT_FLOAT(10.0))
        EVT_CALL(TranslateModel, LVarF, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, LVarF, LVar8, LVar9, 1)
        EVT_CALL(RotateModel, LVarF, LVarA, 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, LVarF, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(VineModels)[] = {
    MODEL_o419,
    MODEL_o420,
    MODEL_o422,
    STAGE_MODEL_LIST_END
};

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_SET(LVar0, N(VineModels))
    EVT_EXEC(N(EVS_AnimateVines))
    EVT_CALL(SetTexPanner, MODEL_piko4, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_piko5, TEX_PANNER_2)
    EVT_CALL(SetTexPanner, MODEL_piko1, TEX_PANNER_3)
    EVT_CALL(SetTexPanner, MODEL_piko2, TEX_PANNER_4)
    EVT_CALL(SetTexPanner, MODEL_piko3, TEX_PANNER_5)
    EVT_CALL(SetTexPanner, MODEL_piko6, TEX_PANNER_6)
    EVT_CALL(SetTexPanner, MODEL_piko7, TEX_PANNER_7)
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
            EVT_MUL(LVar0, 0x4000)
            EVT_SET(LVar1, LVarF)
            EVT_DIV(LVar1, 4)
            EVT_MOD(LVar1, 2)
            EVT_MUL(LVar1, 0x4000)
            EVT_SET(LVar2, LVarF)
            EVT_DIV(LVar2, 5)
            EVT_MOD(LVar2, 2)
            EVT_MUL(LVar2, 0x4000)
            EVT_SET(LVar3, LVarF)
            EVT_DIV(LVar3, 6)
            EVT_MOD(LVar3, 2)
            EVT_MUL(LVar3, 0x4000)
            EVT_SET(LVar4, LVarF)
            EVT_DIV(LVar4, 2)
            EVT_MOD(LVar4, 2)
            EVT_MUL(LVar4, 0x4000)
            EVT_SET(LVar5, LVarF)
            EVT_DIV(LVar5, 8)
            EVT_MOD(LVar5, 2)
            EVT_MUL(LVar5, 0x4000)
            EVT_SET(LVar6, LVarF)
            EVT_DIV(LVar6, 8)
            EVT_MOD(LVar6, 2)
            EVT_MUL(LVar6, 0x8000)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar1, 0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, LVar2, 0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_MAIN, LVar3, 0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_5, TEX_PANNER_MAIN, LVar4, 0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_6, TEX_PANNER_MAIN, LVar5, 0)
            EVT_CALL(SetTexPanOffset, TEX_PANNER_7, TEX_PANNER_MAIN, LVar6, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 0)
        // create 16 smoke models
        EVT_LOOP(16)
            EVT_SET(LVar1, LVar0)
            EVT_ADD(LVar1, CLONED_MODEL(0))
            EVT_ADD(LVar0, 1)
            EVT_CALL(CloneModel, MODEL_o454, LVar1)
            EVT_CALL(EnableModel, LVar1, FALSE)
        EVT_END_LOOP
        // hide the original
        EVT_CALL(EnableModel, MODEL_o454, FALSE)
        // animate them
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
            EVT_SETF(LVar6, EVT_FLOAT(0.296))
            EVT_SETF(LVar7, EVT_FLOAT(0.296))
            EVT_SET(LVarF, LVarE)
            EVT_ADD(LVarF, CLONED_MODEL(0))
            EVT_EXEC(N(EVS_AnimateSmokePuff))
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

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundVineModels)[] = {
    -1,
    MODEL_o411,
    MODEL_o415,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "flo_tex",
    .shape = "flo_bt03_shape",
    .hit = "flo_bt03_hit",
    .bg = "fla_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundVineModels),
};
