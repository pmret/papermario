#include "battle/battle.h"
#include "mapfs/nok_bt02_shape.h"

#define NAMESPACE A(hos_00)

EvtScript N(EVS_AnimateFlower) = {
    EVT_SET(LVarA, LVar0)
    EVT_LABEL(0)
        EVT_CALL(TranslateModel, LVarA, 0, 2, 0)
        EVT_WAIT(5)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(5)
        EVT_CALL(TranslateModel, LVarA, 0, 2, 0)
        EVT_WAIT(5)
        EVT_CALL(TranslateModel, LVarA, 0, 0, 0)
        EVT_WAIT(5)
        EVT_CALL(RandInt, 30, LVar0)
        EVT_ADD(LVar0, 30)
        EVT_WAIT(LVar0)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_THREAD
        EVT_SET(LVar0, MODEL_h1)
        EVT_EXEC(N(EVS_AnimateFlower))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_h3)
        EVT_EXEC(N(EVS_AnimateFlower))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_h4)
        EVT_EXEC(N(EVS_AnimateFlower))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_h5)
        EVT_EXEC(N(EVS_AnimateFlower))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_h6)
        EVT_EXEC(N(EVS_AnimateFlower))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_h7)
        EVT_EXEC(N(EVS_AnimateFlower))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_h9)
        EVT_EXEC(N(EVS_AnimateFlower))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_h10)
        EVT_EXEC(N(EVS_AnimateFlower))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_h11)
        EVT_EXEC(N(EVS_AnimateFlower))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_h12)
        EVT_EXEC(N(EVS_AnimateFlower))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_hap,
    MODEL_kusa3,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "nok_tex",
    .shape = "nok_bt02_shape",
    .hit = "nok_bt02_hit",
    .bg = "nok_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
