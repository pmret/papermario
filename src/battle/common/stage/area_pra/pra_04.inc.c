#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/pra_bt04_shape.h"

#define NAMESPACE A(pra_04)

#include "battle/common/stage/lib/TexturePanner.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_SET(LVar0, MODEL_kira1)
    EVT_SET(LVar1, TEX_PANNER_0)
    EVT_SET(LVar2, 3000)
    EVT_SET(LVar3, 0)
    EVT_EXEC(N(EVS_TexturePanMain))
    EVT_SET(LVar0, MODEL_kira2)
    EVT_SET(LVar1, TEX_PANNER_1)
    EVT_SET(LVar2, 3000)
    EVT_SET(LVar3, 0)
    EVT_EXEC(N(EVS_TexturePanMain))
    EVT_CALL(EnableBattleFloorReflections, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "pra_tex",
    .shape = "pra_bt04_shape",
    .hit = "pra_bt04_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
