#include "common.h"
#include "effects.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_2_isk_07

BSS EffectInstance* D_80220780;

ApiStatus func_80218AD0_4EFF70(Evt* script, s32 isInitialCall) {
    fx_flame(1, 110.0f, 80.0f, -146.0f, 0.3f, &D_80220780);
    return ApiStatus_DONE2;
}

ApiStatus func_80218B18_4EFFB8(Evt* script, s32 isInitialCall) {
    remove_effect(D_80220780);
    return ApiStatus_DONE2;
}

EvtScript N(beforeBattle_80220390) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(func_80218AD0_4EFF70)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_802203D8) = {
    EVT_CALL(func_80218B18_4EFFB8)
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt07_shape",
    .hit = "isk_bt07_hit",
    .preBattle = &N(beforeBattle_80220390),
    .postBattle = &N(afterBattle_802203D8),
};
