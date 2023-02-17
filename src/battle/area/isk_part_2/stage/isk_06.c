#include "common.h"
#include "effects.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_2_isk_06

BSS EffectInstance* D_80220760;

API_CALLABLE(func_802189F0_4EFE90) {
    fx_flame(1, -110.0f, 80.0f, -146.0f, 0.3f, &D_80220760);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80218A38_4EFED8) {
    remove_effect(D_80220760);
    return ApiStatus_DONE2;
}

EvtScript N(beforeBattle_80220260) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(func_802189F0_4EFE90)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_802202A8) = {
    EVT_CALL(func_80218A38_4EFED8)
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt06_shape",
    .hit = "isk_bt06_hit",
    .preBattle = &N(beforeBattle_80220260),
    .postBattle = &N(afterBattle_802202A8),
};
