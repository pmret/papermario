#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_pra3_pra_03c

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetGroupVisibility, 33, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 38, MODEL_GROUP_HIDDEN)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "pra_tex",
    .shape = "pra_bt03_shape",
    .hit = "pra_bt03_hit",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
};
