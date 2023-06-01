#include "battle/battle.h"
#include "mapfs/trd_bt03_shape.h"

#define NAMESPACE A(trd_03)

#include "battle/common/stage/lib/MovingClouds.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SET(LVar0, MODEL_g65)
    EVT_SET(LVar2, 0)
    EVT_EXEC(N(EVS_AnimateCloud))
    EVT_SET(LVar0, MODEL_g62)
    EVT_SET(LVar2, 70)
    EVT_SET(LVar3, 175)
    EVT_SET(LVar4, -170)
    EVT_EXEC(N(EVS_AnimateCloud_WithOffset2D))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_saku,
    MODEL_kabe2,
    MODEL_kabe,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt03_shape",
    .hit = "trd_bt03_hit",
    .bg = "nok_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
