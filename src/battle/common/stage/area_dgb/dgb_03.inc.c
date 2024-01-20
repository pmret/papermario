#include "battle/battle.h"
#include "mapfs/dgb_bt03_shape.h"

#define NAMESPACE A(dgb_03)

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

Stage NAMESPACE = {
    .texture = "dgb_tex",
    .shape = "dgb_bt03_shape",
    .hit = "dgb_bt03_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
