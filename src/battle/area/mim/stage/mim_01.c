#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_mim_mim_01

#include "common/UnkFogFunc2.inc.c"

EvtScript N(beforeBattle_8021E450) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(N(UnkFogFunc2))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021E47C) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "mim_tex",
    .shape = "mim_bt01_shape",
    .hit = "mim_bt01_hit",
    .preBattle = &N(beforeBattle_8021E450),
    .postBattle = &N(afterBattle_8021E47C),
};
