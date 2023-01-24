#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/pra_bt01_shape.h"

#define NAMESPACE b_area_pra3_pra_01

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(EnableBattleFloorReflections, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_o383, MODEL_o384, MODEL_o385, 0,
};

Stage NAMESPACE = {
    .texture = "pra_tex",
    .shape = "pra_bt01_shape",
    .hit = "pra_bt01_hit",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
