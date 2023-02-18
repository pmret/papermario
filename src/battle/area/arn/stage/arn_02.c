#include "common.h"
#include "battle/battle.h"
#include "mapfs/arn_bt02_shape.h"

#define NAMESPACE b_area_arn_arn_02

EvtScript N(80227960) = {
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
    EVT_SET(LVar0, 8)
    EVT_EXEC_WAIT(N(80227960))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    -1, MODEL_iwa4, 0,
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
