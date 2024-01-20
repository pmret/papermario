#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/pra_bt02_shape.h"

#define NAMESPACE A(pra_02)

#include "battle/common/stage/lib/TexturePanner.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Call(EnableBattleFloorReflections, TRUE)
    Set(LVar0, MODEL_o412)
    Set(LVar1, TEX_PANNER_0)
    Set(LVar2, 3000)
    Set(LVar3, 0)
    Exec(N(EVS_TexturePanMain))
    Set(LVar0, MODEL_o413)
    Set(LVar1, TEX_PANNER_0)
    Set(LVar2, 3000)
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
    MODEL_o383,
    MODEL_o384,
    MODEL_o385,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "pra_tex",
    .shape = "pra_bt02_shape",
    .hit = "pra_bt02_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
