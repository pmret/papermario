#include "common.h"
#include "effects.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_1_isk_07

BSS EffectInstance* N(D_80224D90);

ApiStatus func_80218AC0_4E3200(Evt* script, s32 isInitialCall) {
    fx_flame(1, 110.0f, 80.0f, -146.0f, 0.3f, &N(D_80224D90));
    return ApiStatus_DONE2;
}

ApiStatus func_80218B08_4E3248(Evt* script, s32 isInitialCall) {
    remove_effect(N(D_80224D90));
    return ApiStatus_DONE2;
}

EvtScript N(beforeBattle_80223C80) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(func_80218AC0_4E3200)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80223CC8) = {
    EVT_CALL(func_80218B08_4E3248)
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt07_shape",
    .hit = "isk_bt07_hit",
    .preBattle = &N(beforeBattle_80223C80),
    .postBattle = &N(afterBattle_80223CC8),
};
