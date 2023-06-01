#include "battle/battle.h"
#include "mapfs/arn_bt02_shape.h"

#define NAMESPACE A(arn_02)

EvtScript N(EVS_RotateWindmill) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVar0, 0)
    EVT_LABEL(0)
        EVT_ADD(LVar0, 1)
        EVT_IF_GT(LVar0, 359)
            EVT_SUB(LVar0, 360)
        EVT_END_IF
        EVT_CALL(RotateModel, LVarA, LVar0, 0, 0, 1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SET(LVar0, MODEL_o332)
    EVT_EXEC_WAIT(N(EVS_RotateWindmill))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    -1,
    MODEL_iwa4,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "arn_tex",
    .shape = "arn_bt02_shape",
    .hit = "arn_bt02_hit",
    .bg = "arn_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
