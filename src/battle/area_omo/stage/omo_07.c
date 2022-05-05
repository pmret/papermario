#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_omo_omo_07

EvtScript N(beforeBattle_8022F8B0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8022F8EC) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt07_shape",
    .hit = "omo_bt07_hit",
    .preBattle = &N(beforeBattle_8022F8B0),
    .postBattle = &N(afterBattle_8022F8EC),
};
