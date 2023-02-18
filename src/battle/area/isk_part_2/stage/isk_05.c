#include "common.h"
#include "effects.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_2_isk_05

BSS EffectInstance* D_80220750;
BSS EffectInstance* D_80220754;

API_CALLABLE(func_80218920_4EFDC0) {
    fx_flame(1, -90.0f, 45.0f, -146.0f, 0.25f, &D_80220750);
    fx_flame(1, 80.0f, 45.0f, -146.0f, 0.25f, &D_80220754);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802189B0_4EFE50) {
    remove_effect(D_80220750);
    remove_effect(D_80220754);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(func_80218920_4EFDC0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_CALL(func_802189B0_4EFE50)
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt05_shape",
    .hit = "isk_bt05_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
