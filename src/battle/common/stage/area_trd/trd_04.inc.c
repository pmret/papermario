#include "battle/battle.h"
#include "mapfs/trd_bt04_shape.h"

#define NAMESPACE A(trd_04)

#include "battle/common/stage/lib/TexturePanner.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_SET(LVar0, MODEL_hikari1)
    EVT_SET(LVar1, TEX_PANNER_0)
    EVT_SET(LVar2, 40)
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
    MODEL_hikari1,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt04_shape",
    .hit = "trd_bt04_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
