#include "common.h"
#include "effects.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_1_isk_08

BSS EffectInstance* N(D_80224DB0);

API_CALLABLE(func_80218BA0_4E32E0) {
    fx_flame(1, 0, 72.0f, -146.0, 0.3f, &N(D_80224DB0));
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80218BE8_4E3328) {
    remove_effect(N(D_80224DB0));
    return ApiStatus_DONE2;
}

EvtScript N(beforeBattle_80223FE0) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(func_80218BA0_4E32E0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80224028) = {
    EVT_CALL(func_80218BE8_4E3328)
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt08_shape",
    .hit = "isk_bt08_hit",
    .preBattle = &N(beforeBattle_80223FE0),
    .postBattle = &N(afterBattle_80224028),
};
