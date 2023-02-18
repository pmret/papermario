#include "common.h"
#include "battle/battle.h"
#include "mapfs/omo_bt05_shape.h"

#define NAMESPACE b_area_omo_omo_05b

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetGroupVisibility, 35, 0)
    EVT_CALL(SetGroupVisibility, 45, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_mae2, 0,
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
