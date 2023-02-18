#include "common.h"
#include "battle/battle.h"
#include "mapfs/omo_bt05_shape.h"

#define NAMESPACE b_area_omo3_omo_05

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetGroupVisibility, 24, MODEL_GROUP_HIDDEN)
    EVT_CALL(SetGroupVisibility, 28, MODEL_GROUP_HIDDEN)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_itigo, MODEL_kisya, 0,
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt05_shape",
    .hit = "omo_bt05_hit",
    .bg = "omo_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
