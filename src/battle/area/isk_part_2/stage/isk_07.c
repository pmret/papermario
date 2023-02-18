#include "common.h"
#include "effects.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_2_isk_07

BSS EffectInstance* D_80220780;

API_CALLABLE(func_80218AD0_4EFF70) {
    fx_flame(1, 110.0f, 80.0f, -146.0f, 0.3f, &D_80220780);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80218B18_4EFFB8) {
    remove_effect(D_80220780);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(func_80218AD0_4EFF70)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_CALL(func_80218B18_4EFFB8)
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt07_shape",
    .hit = "isk_bt07_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
