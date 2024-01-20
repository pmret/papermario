#include "battle/battle.h"
#include "mapfs/trd_bt03_shape.h"

#define NAMESPACE A(trd_03)

#include "battle/common/stage/lib/MovingClouds.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Set(LVar0, MODEL_g65)
    Set(LVar2, 0)
    Exec(N(EVS_AnimateCloud))
    Set(LVar0, MODEL_g62)
    Set(LVar2, 70)
    Set(LVar3, 175)
    Set(LVar4, -170)
    Exec(N(EVS_AnimateCloud_WithOffset2D))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
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
