#include "common.h"
#include "effects.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_1_isk_05

BSS EffectInstance* N(D_80224D70);
BSS EffectInstance* N(D_80224D74);

ApiStatus N(CreateTorchFX)(Evt* script, s32 isInitialCall) {
    fx_flame(1, -90.0f, 45.0f, -146.0f, 0.25f, &N(D_80224D70));
    fx_flame(1, 80.0f, 45.0f, -146.0f, 0.25f, &N(D_80224D74));
    return ApiStatus_DONE2;
}

ApiStatus N(DeleteTorchFX)(Evt* script, s32 isInitialCall) {
    remove_effect(N(D_80224D70));
    remove_effect(N(D_80224D74));
    return ApiStatus_DONE2;
}

EvtScript N(beforeBattle_80223B60) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(N(CreateTorchFX))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80223BA8) = {
    EVT_CALL(N(DeleteTorchFX))
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt05_shape",
    .hit = "isk_bt05_hit",
    .preBattle = &N(beforeBattle_80223B60),
    .postBattle = &N(afterBattle_80223BA8),
};
