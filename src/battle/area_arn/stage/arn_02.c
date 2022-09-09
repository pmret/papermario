#include "common.h"
#include "battle/battle.h"
#include "mapfs/arn_bt02_shape.h"

#define NAMESPACE b_area_arn_arn_02

EvtScript N(80227960) = {
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_SET(LocalVar(0), 0)
    EVT_LABEL(0)
    EVT_ADD(LocalVar(0), 1)
    EVT_IF_GT(LocalVar(0), 359)
        EVT_SUB(LocalVar(0), 360)
    EVT_END_IF
    EVT_CALL(RotateModel, LocalVar(10), LocalVar(0), 0, 0, 1)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_80227A0C) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_SET(LocalVar(0), 8)
    EVT_EXEC_WAIT(N(80227960))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80227A48) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80227A58)[] = {
    -1, MODEL_iwa4, 0,
};

Stage NAMESPACE = {
    .texture = "arn_tex",
    .shape = "arn_bt02_shape",
    .hit = "arn_bt02_hit",
    .bg = "arn_bg",
    .preBattle = &N(beforeBattle_80227A0C),
    .postBattle = &N(afterBattle_80227A48),
    .foregroundModelList = N(foregroundModelList_80227A58),
};
