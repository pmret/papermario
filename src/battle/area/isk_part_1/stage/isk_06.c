#include "common.h"
#include "effects.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_1_isk_06

BSS EffectInstance* N(D_80224D80);

API_CALLABLE(func_80218A50_4E3190) {
    fx_flame(1, -110.0f, 80.0f, -146.0f, 0.3f, &N(D_80224D80));
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80218A98_4E31D8) {
    remove_effect(N(D_80224D80));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(func_80218A50_4E3190)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_CALL(func_80218A98_4E31D8)
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt06_shape",
    .hit = "isk_bt06_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
