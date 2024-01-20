#include "battle/battle.h"
#include "mapfs/trd_bt04_shape.h"

#define NAMESPACE A(trd_04)

#include "battle/common/stage/lib/TexturePanner.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Set(LVar0, MODEL_hikari1)
    Set(LVar1, TEX_PANNER_0)
    Set(LVar2, 40)
    Set(LVar3, 0)
    Exec(N(EVS_TexturePanMain))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
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
