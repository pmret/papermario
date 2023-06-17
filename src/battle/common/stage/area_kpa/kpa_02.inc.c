#include "battle/battle.h"
#include "mapfs/kpa_bt02_shape.h"

#define NAMESPACE A(kpa_02)

#include "battle/common/stage/lib/TexturePanner.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_SET(LVar0, MODEL_2)
    EVT_SET(LVar1, TEX_PANNER_1)
    EVT_SET(LVar2, -400)
    EVT_SET(LVar3, -800)
    EVT_EXEC(N(EVS_TexturePanBothU))
    EVT_SET(LVar0, MODEL_4)
    EVT_SET(LVar1, TEX_PANNER_3)
    EVT_SET(LVar2, -400)
    EVT_SET(LVar3, -800)
    EVT_EXEC(N(EVS_TexturePanBothU))
    EVT_SET(LVar0, MODEL_1)
    EVT_SET(LVar1, TEX_PANNER_0)
    EVT_SET(LVar2, -400)
    EVT_SET(LVar3, -800)
    EVT_EXEC(N(EVS_TexturePanBothV))
    EVT_SET(LVar0, MODEL_3)
    EVT_SET(LVar1, TEX_PANNER_2)
    EVT_SET(LVar2, -400)
    EVT_SET(LVar3, -800)
    EVT_EXEC(N(EVS_TexturePanBothV))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_saku,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt02_shape",
    .hit = "kpa_bt02_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
