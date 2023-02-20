#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_omo3_omo_03b

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt03_shape",
    .hit = "omo_bt03_hit",
    .bg = "omo_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
