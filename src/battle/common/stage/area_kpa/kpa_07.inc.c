#include "battle/battle.h"
#include "mapfs/kpa_bt07_shape.h"

#define NAMESPACE A(kpa_07)

#include "battle/common/stage/lib/TexturePanner.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_SET(LVar0, MODEL_kemu2)
    EVT_SET(LVar1, TEX_PANNER_0)
    EVT_SET(LVar2, -200)
    EVT_SET(LVar3, 0)
    EVT_EXEC(N(EVS_TexturePanMain))
    EVT_SET(LVar0, MODEL_kemu1)
    EVT_SET(LVar1, TEX_PANNER_1)
    EVT_SET(LVar2, -120)
    EVT_SET(LVar3, 0)
    EVT_EXEC(N(EVS_TexturePanMain))
    EVT_SET(LVar0, MODEL_kemu3)
    EVT_SET(LVar1, TEX_PANNER_2)
    EVT_SET(LVar2, -100)
    EVT_SET(LVar3, 0)
    EVT_EXEC(N(EVS_TexturePanMain))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_kemu1,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt07_shape",
    .hit = "kpa_bt07_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
