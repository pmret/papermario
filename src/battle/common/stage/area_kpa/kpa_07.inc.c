#include "battle/battle.h"
#include "mapfs/kpa_bt07_shape.h"

#define NAMESPACE A(kpa_07)

#include "battle/common/stage/lib/TexturePanner.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Set(LVar0, MODEL_kemu2)
    Set(LVar1, TEX_PANNER_0)
    Set(LVar2, -200)
    Set(LVar3, 0)
    Exec(N(EVS_TexturePanMain))
    Set(LVar0, MODEL_kemu1)
    Set(LVar1, TEX_PANNER_1)
    Set(LVar2, -120)
    Set(LVar3, 0)
    Exec(N(EVS_TexturePanMain))
    Set(LVar0, MODEL_kemu3)
    Set(LVar1, TEX_PANNER_2)
    Set(LVar2, -100)
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
