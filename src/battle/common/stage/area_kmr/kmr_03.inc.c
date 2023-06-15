#include "battle/battle.h"
#include "mapfs/kmr_bt03_shape.h"

#define NAMESPACE A(kmr_03)

#include "battle/common/stage/lib/MovingClouds.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SET(LVar0, MODEL_g59)
    EVT_SET(LVar2, 0)
    EVT_EXEC(N(EVS_AnimateCloud))
    EVT_SET(LVar0, MODEL_g60)
    EVT_SET(LVar2, 70)
    EVT_EXEC(N(EVS_AnimateCloud))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_n2,
    MODEL_m4,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt03_shape",
    .hit = "kmr_bt03_hit",
    .bg = "kmr_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
