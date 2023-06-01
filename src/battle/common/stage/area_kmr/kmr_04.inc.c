#include "battle/battle.h"
#include "mapfs/kmr_bt04_shape.h"

#define NAMESPACE A(kmr_04)

#include "battle/common/stage/lib/MovingClouds.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SET(LVar0, MODEL_g60)
    EVT_SET(LVar2, 0)
    EVT_EXEC(N(EVS_AnimateCloud))
    EVT_SET(LVar0, MODEL_g61)
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
    MODEL_m4,
    MODEL_n2,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt04_shape",
    .hit = "kmr_bt04_hit",
    .bg = "kmr_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
