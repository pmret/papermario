#include "battle/battle.h"
#include "mapfs/omo_bt03_shape.h"

#define NAMESPACE A(omo_03)

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Call(SetGroupVisibility, MODEL_g97, MODEL_GROUP_HIDDEN)
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt03_shape",
    .hit = "omo_bt03_hit",
    .bg = "omo_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
