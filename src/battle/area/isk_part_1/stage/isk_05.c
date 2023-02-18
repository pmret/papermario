#include "common.h"
#include "effects.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_1_isk_05

BSS EffectInstance* N(D_80224D70);
BSS EffectInstance* N(D_80224D74);

API_CALLABLE(N(CreateTorchFX)) {
    fx_flame(1, -90.0f, 45.0f, -146.0f, 0.25f, &N(D_80224D70));
    fx_flame(1, 80.0f, 45.0f, -146.0f, 0.25f, &N(D_80224D74));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DeleteTorchFX)) {
    remove_effect(N(D_80224D70));
    remove_effect(N(D_80224D74));
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(N(CreateTorchFX))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_CALL(N(DeleteTorchFX))
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
